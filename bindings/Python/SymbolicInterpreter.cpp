// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Python bindings for symbolic execution via PythonPolicy.
// Delegates value operations to a Python object, falling back to concrete
// computation when the Python policy doesn't implement a method or returns
// NotImplemented.

#include "SymbolicInterpreter.h"

#include <multiplier/IR/Interpret/InterpreterLoop.h>
#include <multiplier/IR/Interpret/ConcreteOps.h>
#include <multiplier/IR/Interpret/ConcreteMemory.h>
#include <multiplier/IR/Interpret/Value.h>
#include <multiplier/IR/Function.h>

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>

#include "Binding.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc99-extensions"
#pragma GCC diagnostic ignored "-Wunused-function"

namespace mx {

using namespace ir::interpret;
using ir::OpCode;
using ir::CastOp;
using ir::ConstOp;
using ir::BitwiseOp;
using ir::FloatOp;
using ir::MemOp;

// ===========================================================================
// Value <-> Python conversion (duplicated from Interpreter.cpp since the
// originals live in an anonymous namespace)
// ===========================================================================

namespace {

PyObject *value_to_python(const Value &v) {
  if (auto *s = std::get_if<ScalarValue>(&v)) {
    return PyLong_FromLongLong(s->as_i64());
  }
  if (auto *p = std::get_if<Pointer>(&v)) {
    uint64_t addr = concrete_address(*p);
    return Py_BuildValue("(sK)", "ptr", addr);
  }
  if (std::holds_alternative<NullPtr>(v)) {
    Py_RETURN_NONE;
  }
  // Undefined -> None.
  Py_RETURN_NONE;
}

Value python_to_value(PyObject *obj) {
  if (obj == nullptr || obj == Py_None) {
    return NullPtr{};
  }
  if (PyLong_Check(obj)) {
    int64_t v = PyLong_AsLongLong(obj);
    if (v == -1 && PyErr_Occurred()) {
      PyErr_Clear();
      uint64_t uv = PyLong_AsUnsignedLongLong(obj);
      if (uv == static_cast<uint64_t>(-1) && PyErr_Occurred()) {
        PyErr_Clear();
        return Undefined{};
      }
      return make_int(static_cast<int64_t>(uv));
    }
    return make_int(v);
  }
  if (PyFloat_Check(obj)) {
    double v = PyFloat_AsDouble(obj);
    return make_float(v);
  }
  if (PyTuple_Check(obj) && PyTuple_Size(obj) == 2) {
    PyObject *tag = PyTuple_GetItem(obj, 0);
    if (tag && PyUnicode_Check(tag)) {
      const char *s = PyUnicode_AsUTF8(tag);
      if (s && std::strcmp(s, "ptr") == 0) {
        PyObject *addr_obj = PyTuple_GetItem(obj, 1);
        uint64_t addr = PyLong_AsUnsignedLongLong(addr_obj);
        return make_ptr(addr);
      }
    }
  }
  return Undefined{};
}

// Wrapper struct layouts — must match the anonymous-namespace structs
// in Interpreter.cpp exactly so we can reinterpret_cast PyObjects.

struct ConcreteMemoryWrapper {
  PyObject_HEAD
  ConcreteMemory *memory;
};

struct InterpreterStateWrapper {
  PyObject_HEAD
  InterpreterState<Value> *state;
};

}  // namespace

// ===========================================================================
// PythonPolicy — construction
// ===========================================================================

PythonPolicy::PythonPolicy(PyObject *py_policy, ConcreteMemory &memory,
                           FunctionResolver func_resolver,
                           GlobalResolver global_resolver)
    : py_policy_(py_policy),
      memory_(memory),
      func_resolver_(std::move(func_resolver)),
      global_resolver_(std::move(global_resolver)) {}

PythonPolicy::~PythonPolicy() {
  Py_XDECREF(cached_binary_op_);
  Py_XDECREF(cached_unary_op_);
  Py_XDECREF(cached_compare_);
  Py_XDECREF(cached_cast_);
  Py_XDECREF(cached_is_true_);
  Py_XDECREF(cached_resolve_branch_);
}

// Look up a method on the Python policy object, caching the result.
// Returns the bound method (borrowed reference) or nullptr if the method
// doesn't exist.  Uses Py_None as the sentinel for "looked up, not found".
PyObject *PythonPolicy::lookup_method(PyObject *&cache, const char *name) {
  if (!cache) {
    PyObject *method = PyObject_GetAttrString(py_policy_.Get(), name);
    if (method) {
      cache = method;  // new ref from GetAttrString; we own it
    } else {
      PyErr_Clear();
      cache = Py_None;
      Py_INCREF(Py_None);
    }
  }
  return (cache != Py_None) ? cache : nullptr;
}

// ===========================================================================
// Concrete-only helpers (duplicated from ConcretePolicy — private static)
// ===========================================================================

uint64_t PythonPolicy::extract_address(const Value &val) {
  if (auto *p = as_pointer(val)) {
    return concrete_address(*p);
  }
  if (auto *s = std::get_if<ScalarValue>(&val)) {
    return s->bits;
  }
  return 0;
}

bool PythonPolicy::has_concrete_address(const Value &val) {
  if (auto *p = as_pointer(val)) {
    return is_concrete(*p);
  }
  return std::holds_alternative<ScalarValue>(val);
}

void PythonPolicy::write_value_to_mem(uint64_t address, const Value &val,
                                      size_t size) {
  // Pointers are just integers — extract raw bits from any Value variant.
  uint64_t bits = 0;
  if (auto *ptr = as_pointer(val)) {
    bits = concrete_address(*ptr);
  } else if (auto *s = std::get_if<ScalarValue>(&val)) {
    bits = s->bits;
    if (s->width == 4) {
      // float32 stored in low 32 bits
      size = std::min(size, size_t{4});
    }
  }
  // NullPtr and Undefined both write zero.
  memory_.write(address, &bits,
                static_cast<uint32_t>(std::min(size, sizeof(bits))));
}

Value PythonPolicy::read_value_from_mem(uint64_t address, size_t size,
                                        bool is_float) {
  if (is_float) {
    if (size == 4) {
      float f = 0;
      memory_.read(address, &f, 4);
      return make_float32(f);
    }
    double d = 0;
    memory_.read(address, &d, 8);
    return make_float(d);
  }
  int64_t v = 0;
  memory_.read(address, &v,
               static_cast<uint32_t>(std::min(size, sizeof(v))));
  switch (size) {
    case 1: v = static_cast<int64_t>(static_cast<int8_t>(v)); break;
    case 2: v = static_cast<int64_t>(static_cast<int16_t>(v)); break;
    case 4: v = static_cast<int64_t>(static_cast<int32_t>(v)); break;
    default: break;
  }
  return make_int(v);
}

// ===========================================================================
// 1. Value construction — always concrete
// ===========================================================================

Value PythonPolicy::make_const(ConstOp op, int64_t signed_val,
                               uint64_t unsigned_val) {
  return concrete_make_const(op, signed_val, unsigned_val);
}

Value PythonPolicy::make_null_ptr(void) { return NullPtr{}; }

// ===========================================================================
// 2. Arithmetic / logic — delegates to Python if available
// ===========================================================================

Value PythonPolicy::binary_op(OpCode op, const Value &lhs, const Value &rhs) {
  if (PyObject *method = lookup_method(cached_binary_op_, "binary_op")) {
    PyObject *py_lhs = value_to_python(lhs);
    PyObject *py_rhs = value_to_python(rhs);
    PyObject *result = PyObject_CallFunction(
        method, "iOO", static_cast<int>(op), py_lhs, py_rhs);
    Py_XDECREF(py_lhs);
    Py_XDECREF(py_rhs);
    if (result && result != Py_NotImplemented) {
      Value v = python_to_value(result);
      Py_DECREF(result);
      return v;
    }
    Py_XDECREF(result);
    PyErr_Clear();
  }
  return concrete_binary_op(op, lhs, rhs);
}

Value PythonPolicy::unary_op(OpCode op, const Value &operand) {
  if (PyObject *method = lookup_method(cached_unary_op_, "unary_op")) {
    PyObject *py_operand = value_to_python(operand);
    PyObject *result = PyObject_CallFunction(
        method, "iO", static_cast<int>(op), py_operand);
    Py_XDECREF(py_operand);
    if (result && result != Py_NotImplemented) {
      Value v = python_to_value(result);
      Py_DECREF(result);
      return v;
    }
    Py_XDECREF(result);
    PyErr_Clear();
  }
  return concrete_unary_op(op, operand);
}

Value PythonPolicy::compare(OpCode op, const Value &lhs, const Value &rhs) {
  if (PyObject *method = lookup_method(cached_compare_, "compare")) {
    PyObject *py_lhs = value_to_python(lhs);
    PyObject *py_rhs = value_to_python(rhs);
    PyObject *result = PyObject_CallFunction(
        method, "iOO", static_cast<int>(op), py_lhs, py_rhs);
    Py_XDECREF(py_lhs);
    Py_XDECREF(py_rhs);
    if (result && result != Py_NotImplemented) {
      Value v = python_to_value(result);
      Py_DECREF(result);
      return v;
    }
    Py_XDECREF(result);
    PyErr_Clear();
  }
  return concrete_compare(op, lhs, rhs);
}

Value PythonPolicy::cast(CastOp op, const Value &operand) {
  if (PyObject *method = lookup_method(cached_cast_, "cast")) {
    PyObject *py_operand = value_to_python(operand);
    PyObject *result = PyObject_CallFunction(
        method, "iO", static_cast<int>(op), py_operand);
    Py_XDECREF(py_operand);
    if (result && result != Py_NotImplemented) {
      Value v = python_to_value(result);
      Py_DECREF(result);
      return v;
    }
    Py_XDECREF(result);
    PyErr_Clear();
  }
  return concrete_cast(op, operand);
}

Value PythonPolicy::ptr_add(const Value &base, const Value &index,
                            int64_t element_size) {
  return concrete_ptr_add(base, index, element_size);
}

Value PythonPolicy::ptr_diff(const Value &lhs, const Value &rhs,
                             int64_t element_size) {
  return concrete_ptr_diff(lhs, rhs, element_size);
}

Value PythonPolicy::ptr_offset(const Value &base, int64_t byte_offset) {
  return concrete_ptr_offset(base, byte_offset);
}

Value PythonPolicy::select(const Value &cond, const Value &if_true,
                           const Value &if_false) {
  return concrete_select(cond, if_true, if_false);
}

Value PythonPolicy::bitwise_intrinsic(OpCode width_op, BitwiseOp sub,
                                      const Value &val, const Value &val2) {
  return concrete_bitwise_intrinsic(width_op, sub, val, val2);
}

Value PythonPolicy::float_intrinsic(FloatOp sub,
                                    const std::vector<Value> &operands) {
  return concrete_float_intrinsic(sub, operands);
}

// ===========================================================================
// 3. Truth test — delegates to Python if available
// ===========================================================================

std::optional<bool> PythonPolicy::is_true(const Value &val) {
  if (PyObject *method = lookup_method(cached_is_true_, "is_true")) {
    PyObject *py_val = value_to_python(val);
    PyObject *result = PyObject_CallFunction(method, "O", py_val);
    Py_XDECREF(py_val);
    if (result && result != Py_NotImplemented) {
      if (result == Py_None) {
        Py_DECREF(result);
        return std::nullopt;  // Python says "I don't know".
      }
      bool truth = PyObject_IsTrue(result);
      Py_DECREF(result);
      return truth;
    }
    Py_XDECREF(result);
    PyErr_Clear();
  }
  return concrete_is_true(val);
}

// ===========================================================================
// 4. Memory — concrete implementation (identical to ConcretePolicy)
// ===========================================================================

Value PythonPolicy::mem_allocate(PythonScheduler &, uint64_t size_bytes,
                                 uint64_t align_bytes) {
  return make_ptr(memory_.allocate(size_bytes, align_bytes));
}

void PythonPolicy::mem_free(PythonScheduler &, const Value &address) {
  if (has_concrete_address(address)) {
    memory_.free(extract_address(address));
  }
}

bool PythonPolicy::mem_read(PythonScheduler &, const Value &addr,
                            const MemAccessHint &hint, Value &result) {
  if (!has_concrete_address(addr)) {
    result = Undefined{};
    return true;
  }
  result = read_value_from_mem(extract_address(addr), hint.size_bytes,
                               hint.is_float);
  return true;
}

bool PythonPolicy::mem_write(PythonScheduler &, const Value &addr,
                             const Value &val, const MemAccessHint &hint) {
  if (!has_concrete_address(addr)) return true;
  write_value_to_mem(extract_address(addr), val, hint.size_bytes);
  return true;
}

bool PythonPolicy::mem_bulk_op(PythonScheduler &, MemOp sub,
                               const std::vector<Value> &ops,
                               const MemoryInst &mi, Value &result) {
  result = make_undef();
  using MO = ir::MemOp;

  switch (sub) {
    case MO::MEMSET: {
      if (ops.size() >= 3) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p) && as_int(ops[2]) > 0) {
          memory_.memset(concrete_address(*p),
                         static_cast<uint8_t>(as_int(ops[1])),
                         static_cast<uint32_t>(as_int(ops[2])));
        }
      }
      result = ops.empty() ? make_undef() : ops[0];
      break;
    }
    case MO::MEMCPY:
    case MO::MEMMOVE: {
      if (ops.size() >= 3) {
        auto *dp = as_pointer(ops[0]);
        int64_t len = as_int(ops[2]);
        if (dp && is_concrete(*dp) && len > 0) {
          auto *sp = as_pointer(ops[1]);
          if (sp && is_concrete(*sp)) {
            memory_.memcpy(concrete_address(*dp), concrete_address(*sp),
                           static_cast<uint32_t>(len));
          } else if (auto *sv = std::get_if<ScalarValue>(&ops[1])) {
            memory_.write(concrete_address(*dp), &sv->bits,
                          static_cast<uint32_t>(
                              std::min(static_cast<size_t>(len),
                                       sizeof(sv->bits))));
          }
        }
      }
      result = ops.empty() ? make_undef() : ops[0];
      break;
    }
    case MO::BZERO: {
      if (ops.size() >= 2) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p) && as_int(ops[1]) > 0) {
          memory_.memset(concrete_address(*p), 0,
                         static_cast<uint32_t>(as_int(ops[1])));
        }
      }
      result = ops.empty() ? make_undef() : ops[0];
      break;
    }
    case MO::STRLEN: {
      if (ops.size() >= 1) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p)) {
          uint64_t addr = concrete_address(*p);
          size_t len = 0;
          uint8_t byte = 0;
          while (true) {
            memory_.read(addr + len, &byte, 1);
            if (byte == 0) break;
            ++len;
          }
          result = make_int(static_cast<int64_t>(len));
        }
      }
      break;
    }
    case MO::STRNLEN: {
      if (ops.size() >= 2) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p)) {
          uint64_t addr = concrete_address(*p);
          size_t maxlen = static_cast<size_t>(as_int(ops[1]));
          size_t len = 0;
          uint8_t byte = 0;
          while (len < maxlen) {
            memory_.read(addr + len, &byte, 1);
            if (byte == 0) break;
            ++len;
          }
          result = make_int(static_cast<int64_t>(len));
        }
      }
      break;
    }
    case MO::STRCMP: {
      if (ops.size() >= 2) {
        auto *p0 = as_pointer(ops[0]);
        auto *p1 = as_pointer(ops[1]);
        if (p0 && p1 && is_concrete(*p0) && is_concrete(*p1)) {
          uint64_t a0 = concrete_address(*p0);
          uint64_t a1 = concrete_address(*p1);
          int cmp = 0;
          for (size_t i = 0; ; ++i) {
            uint8_t c0 = 0, c1 = 0;
            memory_.read(a0 + i, &c0, 1);
            memory_.read(a1 + i, &c1, 1);
            if (c0 != c1) { cmp = (c0 < c1) ? -1 : 1; break; }
            if (c0 == 0) break;
          }
          result = make_int(cmp);
        }
      }
      break;
    }
    case MO::STRNCMP: {
      if (ops.size() >= 3) {
        auto *p0 = as_pointer(ops[0]);
        auto *p1 = as_pointer(ops[1]);
        if (p0 && p1 && is_concrete(*p0) && is_concrete(*p1)) {
          uint64_t a0 = concrete_address(*p0);
          uint64_t a1 = concrete_address(*p1);
          size_t n = static_cast<size_t>(as_int(ops[2]));
          int cmp = 0;
          for (size_t i = 0; i < n; ++i) {
            uint8_t c0 = 0, c1 = 0;
            memory_.read(a0 + i, &c0, 1);
            memory_.read(a1 + i, &c1, 1);
            if (c0 != c1) { cmp = (c0 < c1) ? -1 : 1; break; }
            if (c0 == 0) break;
          }
          result = make_int(cmp);
        }
      }
      break;
    }
    case MO::MEMCMP: {
      if (ops.size() >= 3) {
        auto *p0 = as_pointer(ops[0]);
        auto *p1 = as_pointer(ops[1]);
        if (p0 && p1 && is_concrete(*p0) && is_concrete(*p1)) {
          size_t len = static_cast<size_t>(as_int(ops[2]));
          std::vector<uint8_t> buf0(len, 0), buf1(len, 0);
          memory_.read(concrete_address(*p0), buf0.data(),
                       static_cast<uint32_t>(len));
          memory_.read(concrete_address(*p1), buf1.data(),
                       static_cast<uint32_t>(len));
          result = make_int(std::memcmp(buf0.data(), buf1.data(), len));
        }
      }
      break;
    }
    case MO::MEMCHR: {
      if (ops.size() >= 3) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p)) {
          uint64_t addr = concrete_address(*p);
          size_t len = static_cast<size_t>(as_int(ops[2]));
          uint8_t needle = static_cast<uint8_t>(as_int(ops[1]));
          for (size_t i = 0; i < len; ++i) {
            uint8_t byte = 0;
            memory_.read(addr + i, &byte, 1);
            if (byte == needle) {
              result = make_ptr(addr + i);
              break;
            }
          }
        }
      }
      break;
    }
    case MO::STRCHR: {
      if (ops.size() >= 2) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p)) {
          uint64_t addr = concrete_address(*p);
          uint8_t needle = static_cast<uint8_t>(as_int(ops[1]));
          bool found = false;
          for (size_t i = 0; ; ++i) {
            uint8_t byte = 0;
            memory_.read(addr + i, &byte, 1);
            if (byte == needle) {
              result = make_ptr(addr + i);
              found = true;
              break;
            }
            if (byte == 0) break;
          }
          if (!found) {
            if (needle == 0) {
              for (size_t i = 0; ; ++i) {
                uint8_t byte = 0;
                memory_.read(addr + i, &byte, 1);
                if (byte == 0) {
                  result = make_ptr(addr + i);
                  found = true;
                  break;
                }
              }
            }
            if (!found) result = make_null();
          }
        }
      }
      break;
    }
    case MO::STRRCHR: {
      if (ops.size() >= 2) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p)) {
          uint64_t addr = concrete_address(*p);
          uint8_t needle = static_cast<uint8_t>(as_int(ops[1]));
          int64_t last_pos = -1;
          for (size_t i = 0; ; ++i) {
            uint8_t byte = 0;
            memory_.read(addr + i, &byte, 1);
            if (byte == needle) last_pos = static_cast<int64_t>(i);
            if (byte == 0) break;
          }
          result = (last_pos >= 0)
              ? make_ptr(addr + static_cast<uint64_t>(last_pos))
              : make_null();
        }
      }
      break;
    }
    case MO::STRSTR: {
      if (ops.size() >= 2) {
        auto *p0 = as_pointer(ops[0]);
        auto *p1 = as_pointer(ops[1]);
        if (p0 && p1 && is_concrete(*p0) && is_concrete(*p1)) {
          uint64_t ha = concrete_address(*p0);
          uint64_t na = concrete_address(*p1);
          std::string haystack, needle_str;
          for (size_t i = 0; ; ++i) {
            uint8_t b = 0; memory_.read(ha + i, &b, 1);
            if (b == 0) break;
            haystack.push_back(static_cast<char>(b));
          }
          for (size_t i = 0; ; ++i) {
            uint8_t b = 0; memory_.read(na + i, &b, 1);
            if (b == 0) break;
            needle_str.push_back(static_cast<char>(b));
          }
          if (needle_str.empty()) {
            result = ops[0];
          } else {
            auto pos = haystack.find(needle_str);
            result = (pos != std::string::npos)
                ? make_ptr(ha + pos) : make_null();
          }
        }
      }
      break;
    }
    case MO::STRCPY: {
      if (ops.size() >= 2) {
        auto *dp = as_pointer(ops[0]);
        auto *sp = as_pointer(ops[1]);
        if (dp && sp && is_concrete(*dp) && is_concrete(*sp)) {
          uint64_t da = concrete_address(*dp), sa = concrete_address(*sp);
          for (size_t i = 0; ; ++i) {
            uint8_t c = 0; memory_.read(sa + i, &c, 1);
            memory_.write(da + i, &c, 1);
            if (c == 0) break;
          }
        }
      }
      result = ops.empty() ? make_undef() : ops[0];
      break;
    }
    case MO::STRNCPY: {
      if (ops.size() >= 3) {
        auto *dp = as_pointer(ops[0]);
        auto *sp = as_pointer(ops[1]);
        if (dp && sp && is_concrete(*dp) && is_concrete(*sp)) {
          uint64_t da = concrete_address(*dp), sa = concrete_address(*sp);
          size_t n = static_cast<size_t>(as_int(ops[2]));
          bool hit_null = false;
          for (size_t i = 0; i < n; ++i) {
            uint8_t c = 0;
            if (!hit_null) {
              memory_.read(sa + i, &c, 1);
              if (c == 0) hit_null = true;
            }
            memory_.write(da + i, &c, 1);
          }
        }
      }
      result = ops.empty() ? make_undef() : ops[0];
      break;
    }
    case MO::STRCAT: {
      if (ops.size() >= 2) {
        auto *dp = as_pointer(ops[0]);
        auto *sp = as_pointer(ops[1]);
        if (dp && sp && is_concrete(*dp) && is_concrete(*sp)) {
          uint64_t da = concrete_address(*dp), sa = concrete_address(*sp);
          size_t dlen = 0;
          uint8_t byte = 0;
          while (true) {
            memory_.read(da + dlen, &byte, 1);
            if (byte == 0) break;
            ++dlen;
          }
          for (size_t i = 0; ; ++i) {
            uint8_t c = 0; memory_.read(sa + i, &c, 1);
            memory_.write(da + dlen + i, &c, 1);
            if (c == 0) break;
          }
        }
      }
      result = ops.empty() ? make_undef() : ops[0];
      break;
    }
    case MO::STRNCAT: {
      if (ops.size() >= 3) {
        auto *dp = as_pointer(ops[0]);
        auto *sp = as_pointer(ops[1]);
        if (dp && sp && is_concrete(*dp) && is_concrete(*sp)) {
          uint64_t da = concrete_address(*dp), sa = concrete_address(*sp);
          size_t n = static_cast<size_t>(as_int(ops[2]));
          size_t dlen = 0;
          uint8_t byte = 0;
          while (true) {
            memory_.read(da + dlen, &byte, 1);
            if (byte == 0) break;
            ++dlen;
          }
          size_t i = 0;
          for (; i < n; ++i) {
            uint8_t c = 0; memory_.read(sa + i, &c, 1);
            if (c == 0) break;
            memory_.write(da + dlen + i, &c, 1);
          }
          uint8_t nul = 0; memory_.write(da + dlen + i, &nul, 1);
        }
      }
      result = ops.empty() ? make_undef() : ops[0];
      break;
    }
    case MO::STPCPY: {
      if (ops.size() >= 2) {
        auto *dp = as_pointer(ops[0]);
        auto *sp = as_pointer(ops[1]);
        if (dp && sp && is_concrete(*dp) && is_concrete(*sp)) {
          uint64_t da = concrete_address(*dp), sa = concrete_address(*sp);
          size_t i = 0;
          for (; ; ++i) {
            uint8_t c = 0; memory_.read(sa + i, &c, 1);
            memory_.write(da + i, &c, 1);
            if (c == 0) break;
          }
          result = make_ptr(da + i);
        }
      }
      break;
    }
    case MO::STPNCPY: {
      if (ops.size() >= 3) {
        auto *dp = as_pointer(ops[0]);
        auto *sp = as_pointer(ops[1]);
        if (dp && sp && is_concrete(*dp) && is_concrete(*sp)) {
          uint64_t da = concrete_address(*dp), sa = concrete_address(*sp);
          size_t n = static_cast<size_t>(as_int(ops[2]));
          bool hit_null = false;
          size_t null_pos = n;
          for (size_t i = 0; i < n; ++i) {
            uint8_t c = 0;
            if (!hit_null) {
              memory_.read(sa + i, &c, 1);
              if (c == 0) { hit_null = true; null_pos = i; }
            }
            memory_.write(da + i, &c, 1);
          }
          result = make_ptr(da + null_pos);
        }
      }
      break;
    }
    case MO::STRTOI32: case MO::STRTOI64:
    case MO::STRTOU32: case MO::STRTOU64:
    case MO::STRTOF32: case MO::STRTOF64: {
      if (ops.size() >= 1) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p)) {
          uint64_t addr = concrete_address(*p);
          std::string str;
          for (size_t i = 0; ; ++i) {
            uint8_t b = 0; memory_.read(addr + i, &b, 1);
            if (b == 0) break;
            str.push_back(static_cast<char>(b));
          }
          switch (sub) {
            case MO::STRTOI32: result = make_int(static_cast<int64_t>(std::strtol(str.c_str(), nullptr, 10))); break;
            case MO::STRTOI64: result = make_int(static_cast<int64_t>(std::strtoll(str.c_str(), nullptr, 10))); break;
            case MO::STRTOU32: result = make_int(static_cast<int64_t>(std::strtoul(str.c_str(), nullptr, 10))); break;
            case MO::STRTOU64: result = make_int(static_cast<int64_t>(std::strtoull(str.c_str(), nullptr, 10))); break;
            case MO::STRTOF32: result = make_float(static_cast<double>(std::strtof(str.c_str(), nullptr))); break;
            case MO::STRTOF64: result = make_float(std::strtod(str.c_str(), nullptr)); break;
            default: break;
          }
        }
      }
      break;
    }
    case MO::BIT_READ_LE: case MO::BIT_READ_BE: {
      if (ops.size() >= 1) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p)) {
          uint64_t addr = concrete_address(*p);
          uint32_t bo = mi.bit_offset();
          uint32_t bw = mi.bit_width();
          uint32_t first_byte = bo / 8;
          uint32_t last_byte = (bo + bw - 1) / 8;
          uint32_t num_bytes = last_byte - first_byte + 1;
          std::vector<uint8_t> buf(num_bytes, 0);
          memory_.read(addr + first_byte, buf.data(), num_bytes);
          uint64_t raw = 0;
          if (sub == MO::BIT_READ_LE) {
            for (uint32_t i = 0; i < num_bytes; ++i)
              raw |= static_cast<uint64_t>(buf[i]) << (i * 8);
            raw >>= (bo % 8);
          } else {
            for (uint32_t i = 0; i < num_bytes; ++i)
              raw = (raw << 8) | buf[i];
            uint32_t top_bits = num_bytes * 8;
            uint32_t shift = top_bits - (bo % 8) - bw;
            raw >>= shift;
          }
          uint64_t mask = (bw >= 64) ? ~uint64_t{0}
                                     : ((uint64_t{1} << bw) - 1);
          raw &= mask;
          result = make_int(static_cast<int64_t>(raw));
        }
      }
      break;
    }
    case MO::BIT_WRITE_LE: case MO::BIT_WRITE_BE: {
      if (ops.size() >= 2) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p)) {
          uint64_t addr = concrete_address(*p);
          uint32_t bo = mi.bit_offset();
          uint32_t bw = mi.bit_width();
          uint64_t val = static_cast<uint64_t>(as_int(ops[1]));
          uint64_t mask = (bw >= 64) ? ~uint64_t{0}
                                     : ((uint64_t{1} << bw) - 1);
          val &= mask;
          uint32_t first_byte = bo / 8;
          uint32_t last_byte = (bo + bw - 1) / 8;
          uint32_t num_bytes = last_byte - first_byte + 1;
          std::vector<uint8_t> buf(num_bytes, 0);
          memory_.read(addr + first_byte, buf.data(), num_bytes);
          if (sub == MO::BIT_WRITE_LE) {
            uint64_t raw = 0;
            for (uint32_t i = 0; i < num_bytes; ++i)
              raw |= static_cast<uint64_t>(buf[i]) << (i * 8);
            uint32_t shift = bo % 8;
            raw &= ~(mask << shift);
            raw |= (val << shift);
            for (uint32_t i = 0; i < num_bytes; ++i)
              buf[i] = static_cast<uint8_t>(raw >> (i * 8));
          } else {
            uint64_t raw = 0;
            for (uint32_t i = 0; i < num_bytes; ++i)
              raw = (raw << 8) | buf[i];
            uint32_t top_bits = num_bytes * 8;
            uint32_t shift = top_bits - (bo % 8) - bw;
            raw &= ~(mask << shift);
            raw |= (val << shift);
            for (uint32_t i = 0; i < num_bytes; ++i)
              buf[num_bytes - 1 - i] = static_cast<uint8_t>(raw >> (i * 8));
          }
          memory_.write(addr + first_byte, buf.data(), num_bytes);
        }
      }
      break;
    }
    case MO::CONSUME_VA_PARAM:
      break;
    default:
      if (ir::IsCmpxchg(sub)) {
        result = make_undef();
      }
      break;
  }
  return true;
}

void PythonPolicy::mem_poison(const Value &addr) {
  if (has_concrete_address(addr)) {
    memory_.poison(extract_address(addr));
  }
}

void PythonPolicy::mem_unpoison(const Value &addr) {
  if (has_concrete_address(addr)) {
    memory_.unpoison(extract_address(addr));
  }
}

bool PythonPolicy::is_undefined(const Value &val) {
  return std::holds_alternative<Undefined>(val);
}

// ===========================================================================
// 5. Resolution
// ===========================================================================

bool PythonPolicy::resolve_branch(PythonScheduler &sched,
                                  const Value &condition,
                                  IRBlock true_block, IRBlock false_block,
                                  IRBlock &chosen_block) {
  if (PyObject *method = lookup_method(cached_resolve_branch_,
                                       "resolve_branch")) {
    PyObject *py_cond = value_to_python(condition);
    auto true_eid = EntityId(true_block.id()).Pack();
    auto false_eid = EntityId(false_block.id()).Pack();
    PyObject *result = PyObject_CallFunction(
        method, "OKK", py_cond, true_eid, false_eid);
    Py_XDECREF(py_cond);
    if (result && result != Py_NotImplemented) {
      if (result == Py_None) {
        // Python says "fork both paths". Return false so the caller
        // (decide_cond_branch) emits a branch Continuation with a
        // state snapshot. The Python explorer can resume both paths
        // from that snapshot.
        Py_DECREF(result);
        return false;
      }
      if (PyObject_IsTrue(result)) {
        Py_DECREF(result);
        chosen_block = true_block;
        return true;
      }
      // Python returned False -> take false branch.
      Py_DECREF(result);
      chosen_block = false_block;
      return true;
    }
    Py_XDECREF(result);
    PyErr_Clear();
  }
  // Default: take true path (same as ConcretePolicy).
  chosen_block = true_block;
  return true;
}

bool PythonPolicy::resolve_call(PythonScheduler &,
                                const IRInstruction &,
                                RawEntityId target_eid,
                                RawEntityId indirect_target_eid,
                                const std::vector<Value> &,
                                bool, CallResolution &resolution) {
  if (func_resolver_) {
    for (auto eid : {target_eid, indirect_target_eid}) {
      if (eid != kInvalidEntityId) {
        if (auto ir = func_resolver_(eid)) {
          resolution = CallResolution{
              .action = CallAction::INLINE,
              .return_value = Undefined{},
              .callee_ir = *std::move(ir)};
          return true;
        }
      }
    }
  }
  resolution = CallResolution{.action = CallAction::SKIP,
                              .return_value = Undefined{}};
  return true;
}

bool PythonPolicy::resolve_global(PythonScheduler &,
                                  RawEntityId entity_id,
                                  GlobalResolution &resolution) {
  if (global_resolver_) {
    if (auto info = global_resolver_(entity_id)) {
      resolution = GlobalResolution{.info = *std::move(info)};
      return true;
    }
  }
  resolution = GlobalResolution{};
  return true;
}

// ===========================================================================
// Symbolic dispatch helpers (called from unified init_state/step)
// ===========================================================================

namespace {

FunctionResolver make_func_resolver(PyObject *obj) {
  if (!obj || obj == Py_None || !PyCallable_Check(obj)) return {};
  SharedPyPtr fr(obj);
  return [fr](RawEntityId eid) -> std::optional<IRFunction> {
    SharedPyPtr ret(PyObject_CallFunction(fr.Get(), "(K)", eid));
    if (!ret || ret.Get() == Py_None) {
      PyErr_Clear();
      return std::nullopt;
    }
    return from_python<IRFunction>(ret.Get());
  };
}

GlobalResolver make_global_resolver(PyObject *obj) {
  if (!obj || obj == Py_None || !PyCallable_Check(obj)) return {};
  SharedPyPtr gr(obj);
  return [gr](RawEntityId eid) -> std::optional<GlobalInfo> {
    SharedPyPtr ret(PyObject_CallFunction(gr.Get(), "(K)", eid));
    if (!ret || ret.Get() == Py_None) {
      PyErr_Clear();
      return std::nullopt;
    }
    if (!PyTuple_Check(ret.Get()) || PyTuple_Size(ret.Get()) < 3) {
      return std::nullopt;
    }
    GlobalInfo info;
    info.canonical_eid = PyLong_AsUnsignedLongLong(
        PyTuple_GetItem(ret.Get(), 0));
    info.size = static_cast<uint32_t>(
        PyLong_AsUnsignedLong(PyTuple_GetItem(ret.Get(), 1)));
    info.align = static_cast<uint32_t>(
        PyLong_AsUnsignedLong(PyTuple_GetItem(ret.Get(), 2)));
    if (PyTuple_Size(ret.Get()) >= 4) {
      PyObject *init_obj = PyTuple_GetItem(ret.Get(), 3);
      if (init_obj != Py_None) {
        auto ir = from_python<IRFunction>(init_obj);
        if (ir) info.initializer = *ir;
      }
    }
    return info;
  };
}

PyObject *fork_to_python(const PythonScheduler::Fork &fork) {
  PyObject *dict = PyDict_New();
  if (!dict) return nullptr;
  auto *transition_copy = new Transition(fork.transition);
  PyObject *capsule = PyCapsule_New(
      transition_copy, "transition",
      [](PyObject *cap) {
        auto *t = static_cast<Transition *>(
            PyCapsule_GetPointer(cap, "transition"));
        delete t;
      });
  PyDict_SetItemString(dict, "transition", capsule);
  Py_XDECREF(capsule);
  return dict;
}

PyObject *continuation_to_python(const Continuation &cont) {
  if (cont.is_terminal()) {
    if (cont.kind() == Continuation::COMPLETED) {
      PyObject *py_val = value_to_python(cont.return_value());
      return Py_BuildValue("(sN)", "completed", py_val);
    }
    return Py_BuildValue("(si)", "error",
                         static_cast<int>(cont.error()));
  }
  return Py_BuildValue("(si)", "suspended",
                       static_cast<int>(cont.kind()));
}

}  // namespace

PyObject *SymbolicInitState(PyObject *state_obj, PyObject *memory_obj,
                            PyObject *py_policy, PyObject *func_obj,
                            PyObject *args_list,
                            PyObject *func_resolver_obj,
                            PyObject *global_resolver_obj) {
  auto *sw = reinterpret_cast<InterpreterStateWrapper *>(state_obj);
  auto *mw = reinterpret_cast<ConcreteMemoryWrapper *>(memory_obj);

  auto func = from_python<IRFunction>(func_obj);
  if (!func) {
    PyErr_SetString(PyExc_TypeError, "Expected IRFunction");
    return nullptr;
  }

  std::vector<Value> c_args;
  if (args_list && args_list != Py_None && PyList_Check(args_list)) {
    for (Py_ssize_t i = 0; i < PyList_Size(args_list); ++i) {
      c_args.push_back(python_to_value(PyList_GetItem(args_list, i)));
    }
  }

  PythonPolicy policy(py_policy, *mw->memory,
                       make_func_resolver(func_resolver_obj),
                       make_global_resolver(global_resolver_obj));
  PythonScheduler sched;

  interp_init_state<PythonPolicy, PythonScheduler, Value>(
      policy, sched, *sw->state, *func, c_args);

  Py_RETURN_NONE;
}

PyObject *SymbolicStep(PyObject *state_obj, PyObject *memory_obj,
                       PyObject *py_policy, uint64_t max_steps,
                       PyObject *func_resolver_obj,
                       PyObject *global_resolver_obj) {
  auto *sw = reinterpret_cast<InterpreterStateWrapper *>(state_obj);
  auto *mw = reinterpret_cast<ConcreteMemoryWrapper *>(memory_obj);

  PythonPolicy policy(py_policy, *mw->memory,
                       make_func_resolver(func_resolver_obj),
                       make_global_resolver(global_resolver_obj));
  PythonScheduler sched;

  bool budget_hit = interp_step<PythonPolicy, PythonScheduler, Value>(
      policy, sched, *sw->state, max_steps);

  PyObject *result_dict = PyDict_New();
  if (!result_dict) return nullptr;

  if (sched.result.has_value()) {
    PyObject *cont = continuation_to_python(sched.result.value());
    PyDict_SetItemString(result_dict, "result", cont);
    Py_XDECREF(cont);
  } else if (budget_hit) {
    PyObject *budget_tuple = Py_BuildValue(
        "(sK)", "budget", sw->state->steps);
    PyDict_SetItemString(result_dict, "result", budget_tuple);
    Py_XDECREF(budget_tuple);
  } else {
    PyDict_SetItemString(result_dict, "result", Py_None);
  }

  PyObject *forks_list = PyList_New(
      static_cast<Py_ssize_t>(sched.forks.size()));
  for (size_t i = 0; i < sched.forks.size(); ++i) {
    PyList_SET_ITEM(forks_list, static_cast<Py_ssize_t>(i),
                    fork_to_python(sched.forks[i]));
  }
  PyDict_SetItemString(result_dict, "forks", forks_list);
  Py_DECREF(forks_list);

  return result_dict;
}

#pragma GCC diagnostic pop
}  // namespace mx
