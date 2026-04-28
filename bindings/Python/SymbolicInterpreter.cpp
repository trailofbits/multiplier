// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "SymbolicInterpreter.h"

#include <multiplier/IR/Interpret/InterpreterLoop.h>
#include <multiplier/IR/Interpret/ConcreteOps.h>
#include <multiplier/IR/Interpret/ConcreteMemory.h>
#include <multiplier/IR/Interpret/Value.h>
#include <multiplier/IR/Function.h>

#include <cassert>
#include <cstring>

#include "Binding.h"
#include "Interpreter.h"

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
// Value <-> Python helpers (for concrete fallback inside policy methods)
// ===========================================================================

namespace {

PyObject *value_to_python(const Value &v) {
  return PyLong_FromLongLong(v.i64);
}

Value python_to_value(PyObject *obj) {
  if (obj == nullptr || obj == Py_None) {
    return make_uint(0);
  }
  if (PyFloat_Check(obj)) {
    return make_float(PyFloat_AsDouble(obj));
  }
  if (PyLong_Check(obj)) {
    int64_t v = PyLong_AsLongLong(obj);
    if (v == -1 && PyErr_Occurred()) {
      PyErr_Clear();
      uint64_t uv = PyLong_AsUnsignedLongLong(obj);
      if (uv == static_cast<uint64_t>(-1) && PyErr_Occurred()) {
        PyErr_Clear();
        return make_uint(0);
      }
      return make_int(static_cast<int64_t>(uv));
    }
    return make_int(v);
  }
  if (PyTuple_Check(obj) && PyTuple_Size(obj) == 2) {
    PyObject *tag = PyTuple_GetItem(obj, 0);
    if (tag && PyUnicode_Check(tag)) {
      const char *s = PyUnicode_AsUTF8(tag);
      if (s && std::strcmp(s, "ptr") == 0) {
        return make_uint(PyLong_AsUnsignedLongLong(PyTuple_GetItem(obj, 1)));
      }
    }
  }
  return make_uint(0);
}

// Convert concrete Value -> SharedPyPtr (for concrete fallback results).
SharedPyPtr value_to_shared(const Value &v) {
  PyObject *obj = value_to_python(v);
  SharedPyPtr result(obj);
  Py_XDECREF(obj);  // SharedPyPtr constructor INCREFed
  return result;
}

// PyFloat -> Value. When the consumer expects f32 form (low 32 bits hold
// the f32 bit pattern), narrow through float; otherwise produce f64 form.
// Non-float inputs (PyLong bit pattern) pass through unchanged because
// integers carry their bits in u64 already.
Value python_to_value_f32_aware(PyObject *obj, bool needs_f32) {
  if (needs_f32 && PyFloat_Check(obj)) {
    return make_float32(static_cast<float>(PyFloat_AsDouble(obj)));
  }
  if (obj == nullptr || obj == Py_None) return make_uint(0);
  if (PyFloat_Check(obj)) return make_float(PyFloat_AsDouble(obj));
  if (PyLong_Check(obj)) {
    int64_t v = PyLong_AsLongLong(obj);
    if (v == -1 && PyErr_Occurred()) {
      PyErr_Clear();
      uint64_t uv = PyLong_AsUnsignedLongLong(obj);
      if (uv == static_cast<uint64_t>(-1) && PyErr_Occurred()) {
        PyErr_Clear();
        return make_uint(0);
      }
      return make_int(static_cast<int64_t>(uv));
    }
    return make_int(v);
  }
  if (PyTuple_Check(obj) && PyTuple_Size(obj) == 2) {
    PyObject *tag = PyTuple_GetItem(obj, 0);
    if (tag && PyUnicode_Check(tag)) {
      const char *s = PyUnicode_AsUTF8(tag);
      if (s && std::strcmp(s, "ptr") == 0) {
        return make_uint(PyLong_AsUnsignedLongLong(PyTuple_GetItem(obj, 1)));
      }
    }
  }
  return make_uint(0);
}

// Float-tagged conversion: produce a PyFloat from the bit pattern. Used
// at type-aware boundaries (memory loads, float arithmetic results) where
// the caller knows the value should surface as a Python float.
SharedPyPtr float_value_to_shared(const Value &v, uint32_t size) {
  double d;
  if (size <= 4) {
    uint32_t bits = static_cast<uint32_t>(v.u64);
    float f;
    std::memcpy(&f, &bits, sizeof(f));
    d = static_cast<double>(f);
  } else {
    std::memcpy(&d, &v.u64, sizeof(d));
  }
  PyObject *obj = PyFloat_FromDouble(d);
  SharedPyPtr result(obj);
  Py_XDECREF(obj);
  return result;
}

// Check if a SharedPyPtr holds a ("ptr", addr) tuple.
std::optional<uint64_t> extract_ptr_tuple(PyObject *obj) {
  if (!obj || !PyTuple_Check(obj) || PyTuple_Size(obj) != 2) return std::nullopt;
  PyObject *tag = PyTuple_GetItem(obj, 0);
  if (!tag || !PyUnicode_Check(tag)) return std::nullopt;
  const char *s = PyUnicode_AsUTF8(tag);
  if (!s || std::strcmp(s, "ptr") != 0) return std::nullopt;
  PyObject *addr_obj = PyTuple_GetItem(obj, 1);
  return PyLong_AsUnsignedLongLong(addr_obj);
}

// Wrapper struct layouts — must match Interpreter.cpp exactly.
struct ConcreteMemoryWrapper {
  PyObject_HEAD
  ConcreteMemory *memory;
};

// Must match InterpreterStateWrapper in Interpreter.cpp.
//
// `symbolic_state` is a strong reference to a PyObject whose payload is a
// `SymbolicState` — see Sharable<SymbolicState, PyObjectRC>. A null
// pointer means the symbolic arm has not been initialized yet.
struct InterpreterStateWrapper {
  PyObject_HEAD
  InterpreterState<Value> *state;
  ::PyObject *symbolic_state;
};

// Extract the embedded SymbolicState from the wrapper's symbolic_state
// PyObject. Returns nullptr if the symbolic arm is uninitialized.
inline SymbolicState *symbolic_state_of(InterpreterStateWrapper *sw) {
  if (!sw || !sw->symbolic_state) return nullptr;
  return reinterpret_cast<PyWrapperFor<SymbolicState> *>(
      sw->symbolic_state)->data;
}

// Drop any existing symbolic state PyObject on `sw` and install a freshly
// constructed one. Returns a reference to the new state for the caller
// to mutate via interp_init_state. The wrapper holds the only strong
// reference; continuations that survive a re-init keep their own.
inline SymbolicState &install_fresh_symbolic_state(
    InterpreterStateWrapper *sw) {
  auto fresh = make_sharable<SymbolicState>();
  Py_XDECREF(sw->symbolic_state);
  sw->symbolic_state = fresh.release();
  return *reinterpret_cast<PyWrapperFor<SymbolicState> *>(
      sw->symbolic_state)->data;
}

// ===========================================================================
// SymbolicState PyTypeObject — the storage for InterpreterState<SharedPyPtr,
// PyObjectRC>. Registered as a hidden private type; never instantiated
// directly from Python. Continuations and the wrapper's `symbolic_state`
// slot hold strong references to instances of this type.
// ===========================================================================

static PyTypeObject SymbolicStatePyType;

static void SymbolicStateType_dealloc(PyObject *self) {
  auto *o = reinterpret_cast<PyWrapperFor<SymbolicState> *>(self);
  if (o->data) {
    o->data->~SymbolicState();
    o->data = nullptr;
  }
  PyObject_Free(self);
}

}  // namespace

}  // namespace mx

namespace mx::ir::interpret {

template <>
::PyTypeObject &Sharable<mx::SymbolicState, PyObjectRC>::PyType(void) noexcept {
  return mx::SymbolicStatePyType;
}

}  // namespace mx::ir::interpret

namespace mx {

bool LoadSymbolicStateType(::PyObject *interp_module) {
  SymbolicStatePyType = {PyVarObject_HEAD_INIT(nullptr, 0)};
  SymbolicStatePyType.tp_name =
      "multiplier.ir.interpret._SymbolicState";
  SymbolicStatePyType.tp_basicsize = sizeof(PyWrapperFor<SymbolicState>);
  SymbolicStatePyType.tp_dealloc = SymbolicStateType_dealloc;
  SymbolicStatePyType.tp_flags = Py_TPFLAGS_DEFAULT;
  SymbolicStatePyType.tp_doc =
      "Internal symbolic interpreter state (PyObjectRC payload)";
  if (PyType_Ready(&SymbolicStatePyType) < 0) return false;
  Py_INCREF(&SymbolicStatePyType);
  return PyModule_AddObject(
      interp_module, "_SymbolicState",
      reinterpret_cast<PyObject *>(&SymbolicStatePyType)) == 0;
}

// ===========================================================================
// PythonPolicy — construction
// ===========================================================================

PythonPolicy::PythonPolicy(PyObject *py_policy, ConcreteMemory &memory,
                           FunctionResolver func_resolver,
                           GlobalResolver global_resolver,
                           FunctionAddressResolver func_addr_resolver)
    : py_policy_(py_policy),
      memory_(memory),
      func_resolver_(std::move(func_resolver)),
      global_resolver_(std::move(global_resolver)),
      func_addr_resolver_(std::move(func_addr_resolver)) {}

PythonPolicy::~PythonPolicy() {
  Py_XDECREF(cached_make_const_);
  Py_XDECREF(cached_binary_op_);
  Py_XDECREF(cached_unary_op_);
  Py_XDECREF(cached_compare_);
  Py_XDECREF(cached_cast_);
  Py_XDECREF(cached_is_true_);
  Py_XDECREF(cached_resolve_branch_);
  Py_XDECREF(cached_resolve_call_);
  Py_XDECREF(cached_mem_read_);
  Py_XDECREF(cached_mem_write_);
  Py_XDECREF(cached_ptr_add_);
  Py_XDECREF(cached_ptr_diff_);
  Py_XDECREF(cached_ptr_offset_);
  Py_XDECREF(cached_symbolic_load_);
  Py_XDECREF(cached_symbolic_store_);
  Py_XDECREF(cached_on_enter_block_);
  Py_XDECREF(cached_on_instruction_);
  Py_XDECREF(pending_exc_type_);
  Py_XDECREF(pending_exc_value_);
  Py_XDECREF(pending_exc_tb_);
}

PyObject *PythonPolicy::lookup_method(PyObject *&cache, const char *name) {
  if (!cache) {
    PyObject *method = PyObject_GetAttrString(py_policy_.Get(), name);
    if (method) {
      cache = method;
    } else {
      PyErr_Clear();
      cache = Py_None;
      Py_INCREF(Py_None);
    }
  }
  return (cache != Py_None) ? cache : nullptr;
}

// ===========================================================================
// 0. Value extraction / construction
// ===========================================================================

std::optional<uint64_t> PythonPolicy::extract_address(const SharedPyPtr &val) {
  if (auto a = extract_ptr_tuple(val.Get())) return a;
  // A bare PyLong is also a concrete address — it's what
  // `value_to_python` produces for a pointer loaded out of a slot
  // (the C-level `Value` carries no "pointer-ness" tag, so the slot
  // load surfaces as an int). Treating only `("ptr", N)` tuples as
  // concrete sent every loaded-pointer dereference through the
  // symbolic-suspension path, which the default address strategy
  // collapsed to zero.
  PyObject *obj = val.Get();
  if (obj && PyLong_Check(obj) && !PyBool_Check(obj)) {
    uint64_t v = PyLong_AsUnsignedLongLong(obj);
    if (v == static_cast<uint64_t>(-1) && PyErr_Occurred()) {
      PyErr_Clear();
      return std::nullopt;
    }
    return v;
  }
  return std::nullopt;
}

int64_t PythonPolicy::extract_int(const SharedPyPtr &val) {
  PyObject *obj = val.Get();
  if (obj && PyLong_Check(obj)) return PyLong_AsLongLong(obj);
  return 0;
}

uint64_t PythonPolicy::extract_uint(const SharedPyPtr &val) {
  PyObject *obj = val.Get();
  if (obj && PyLong_Check(obj)) return PyLong_AsUnsignedLongLong(obj);
  return 0;
}

SharedPyPtr PythonPolicy::make_literal_int(int64_t v, uint8_t) {
  PyObject *obj = PyLong_FromLongLong(v);
  SharedPyPtr result(obj);
  Py_XDECREF(obj);
  return result;
}

SharedPyPtr PythonPolicy::make_literal_ptr(uint64_t addr) {
  PyObject *obj = Py_BuildValue("(sK)", "ptr", addr);
  SharedPyPtr result(obj);
  Py_XDECREF(obj);
  return result;
}

SharedPyPtr PythonPolicy::make_default() {
  return SharedPyPtr(Py_None);
}

bool PythonPolicy::has_address(const SharedPyPtr &val) {
  return extract_ptr_tuple(val.Get()).has_value();
}

// ===========================================================================
// 1. Value construction
// ===========================================================================

SharedPyPtr PythonPolicy::make_const(ConstOp op, int64_t signed_val,
                                      uint64_t unsigned_val) {
  if (PyObject *method = lookup_method(cached_make_const_, "make_const")) {
    PyObject *result = PyObject_CallFunction(
        method, "ilK", static_cast<int>(op), signed_val, unsigned_val);
    if (result && result != Py_NotImplemented) {
      SharedPyPtr v(result);
      Py_DECREF(result);
      return v;
    }
    Py_XDECREF(result);
    PyErr_Clear();
  }
  return value_to_shared(concrete_make_const(op, signed_val, unsigned_val));
}

SharedPyPtr PythonPolicy::make_null_ptr(void) {
  return SharedPyPtr(Py_None);
}

// ===========================================================================
// 2. Arithmetic / logic
// ===========================================================================

SharedPyPtr PythonPolicy::binary_op(OpCode op, const SharedPyPtr &lhs,
                                     const SharedPyPtr &rhs) {
  if (PyObject *method = lookup_method(cached_binary_op_, "binary_op")) {
    PyObject *result = PyObject_CallFunction(
        method, "iOO", static_cast<int>(op), lhs.Get(), rhs.Get());
    if (result && result != Py_NotImplemented) {
      SharedPyPtr v(result);
      Py_DECREF(result);
      return v;
    }
    Py_XDECREF(result);
    PyErr_Clear();
  }
  bool is_float_arith = ir::IsFloatArithmetic(op);
  bool is_float_cmp = ir::IsFloatComparison(op);
  bool needs_f32 = (is_float_arith || is_float_cmp) &&
                   (static_cast<unsigned>(op) % 2 == 1);
  Value lv = python_to_value_f32_aware(lhs.Get(), needs_f32);
  Value rv = python_to_value_f32_aware(rhs.Get(), needs_f32);
  Value v = concrete_binary_op(op, lv, rv);
  if (is_float_arith) {
    return float_value_to_shared(v, needs_f32 ? 4u : 8u);
  }
  return value_to_shared(v);
}

SharedPyPtr PythonPolicy::unary_op(OpCode op, const SharedPyPtr &operand) {
  if (PyObject *method = lookup_method(cached_unary_op_, "unary_op")) {
    PyObject *result = PyObject_CallFunction(
        method, "iO", static_cast<int>(op), operand.Get());
    if (result && result != Py_NotImplemented) {
      SharedPyPtr v(result);
      Py_DECREF(result);
      return v;
    }
    Py_XDECREF(result);
    PyErr_Clear();
  }
  bool is_float_arith = ir::IsFloatArithmetic(op);
  bool needs_f32 = is_float_arith &&
                   (static_cast<unsigned>(op) % 2 == 1);
  Value v = concrete_unary_op(
      op, python_to_value_f32_aware(operand.Get(), needs_f32));
  if (is_float_arith) {
    return float_value_to_shared(v, needs_f32 ? 4u : 8u);
  }
  return value_to_shared(v);
}

SharedPyPtr PythonPolicy::compare(OpCode op, const SharedPyPtr &lhs,
                                   const SharedPyPtr &rhs) {
  if (PyObject *method = lookup_method(cached_compare_, "compare")) {
    PyObject *result = PyObject_CallFunction(
        method, "iOO", static_cast<int>(op), lhs.Get(), rhs.Get());
    if (result && result != Py_NotImplemented) {
      SharedPyPtr v(result);
      Py_DECREF(result);
      return v;
    }
    Py_XDECREF(result);
    PyErr_Clear();
  }
  bool needs_f32 = ir::IsFloatComparison(op) &&
                   (static_cast<unsigned>(op) % 2 == 1);
  Value lv = python_to_value_f32_aware(lhs.Get(), needs_f32);
  Value rv = python_to_value_f32_aware(rhs.Get(), needs_f32);
  return value_to_shared(concrete_compare(op, lv, rv));
}

SharedPyPtr PythonPolicy::cast(CastOp op, const SharedPyPtr &operand) {
  if (PyObject *method = lookup_method(cached_cast_, "cast")) {
    PyObject *result = PyObject_CallFunction(
        method, "iO", static_cast<int>(op), operand.Get());
    if (result && result != Py_NotImplemented) {
      SharedPyPtr v(result);
      Py_DECREF(result);
      return v;
    }
    Py_XDECREF(result);
    PyErr_Clear();
  }
  // Casts from f32 require the input to be in f32 form (low 32 bits).
  bool input_is_f32 = (op == CastOp::F32_TO_F64) ||
                      (op >= CastOp::F32_TO_SI8 && op <= CastOp::F32_TO_SI64) ||
                      (op >= CastOp::F32_TO_UI8 && op <= CastOp::F32_TO_UI64);
  Value v = concrete_cast(
      op, python_to_value_f32_aware(operand.Get(), input_is_f32));
  bool produces_float = ir::IsIntToFloat(op) ||
                        op == CastOp::F32_TO_F64 ||
                        op == CastOp::F64_TO_F32;
  if (produces_float) {
    bool is_f32 = (op == CastOp::F64_TO_F32) || ir::IsToFloat32(op);
    return float_value_to_shared(v, is_f32 ? 4u : 8u);
  }
  return value_to_shared(v);
}

SharedPyPtr PythonPolicy::ptr_add(const SharedPyPtr &base,
                                   const SharedPyPtr &index,
                                   int64_t element_size) {
  if (PyObject *method = lookup_method(cached_ptr_add_, "ptr_add")) {
    PyObject *result = PyObject_CallFunction(
        method, "OOL", base.Get(), index.Get(),
        static_cast<long long>(element_size));
    if (result && result != Py_NotImplemented) {
      SharedPyPtr v(result);
      Py_DECREF(result);
      return v;
    }
    Py_XDECREF(result);
    PyErr_Clear();
  }
  // ptr_add yields a pointer; preserve the ("ptr", N) tagging so
  // downstream `extract_address` can recover it. value_to_shared loses
  // the tag (it always returns a PyLong), which would force callers
  // through the symbolic-address suspension path with a default
  // strategy that resolves to 0 and corrupts later memory ops.
  Value v = concrete_ptr_add(
      python_to_value(base.Get()), python_to_value(index.Get()), element_size);
  return make_literal_ptr(v.u64);
}

SharedPyPtr PythonPolicy::ptr_diff(const SharedPyPtr &lhs,
                                    const SharedPyPtr &rhs,
                                    int64_t element_size) {
  if (PyObject *method = lookup_method(cached_ptr_diff_, "ptr_diff")) {
    PyObject *result = PyObject_CallFunction(
        method, "OOL", lhs.Get(), rhs.Get(),
        static_cast<long long>(element_size));
    if (result && result != Py_NotImplemented) {
      SharedPyPtr v(result);
      Py_DECREF(result);
      return v;
    }
    Py_XDECREF(result);
    PyErr_Clear();
  }
  return value_to_shared(concrete_ptr_diff(
      python_to_value(lhs.Get()), python_to_value(rhs.Get()), element_size));
}

SharedPyPtr PythonPolicy::ptr_offset(const SharedPyPtr &base,
                                      int64_t byte_offset) {
  if (PyObject *method = lookup_method(cached_ptr_offset_, "ptr_offset")) {
    PyObject *result = PyObject_CallFunction(
        method, "OL", base.Get(),
        static_cast<long long>(byte_offset));
    if (result && result != Py_NotImplemented) {
      SharedPyPtr v(result);
      Py_DECREF(result);
      return v;
    }
    Py_XDECREF(result);
    PyErr_Clear();
  }
  // GEP_FIELD's result is a pointer — see the ptr_add comment.
  Value v = concrete_ptr_offset(python_to_value(base.Get()), byte_offset);
  return make_literal_ptr(v.u64);
}

SharedPyPtr PythonPolicy::select(const SharedPyPtr &cond,
                                  const SharedPyPtr &if_true,
                                  const SharedPyPtr &if_false) {
  return value_to_shared(concrete_select(
      python_to_value(cond.Get()), python_to_value(if_true.Get()),
      python_to_value(if_false.Get())));
}

SharedPyPtr PythonPolicy::bitwise_intrinsic(OpCode width_op, BitwiseOp sub,
                                             const SharedPyPtr &val,
                                             const SharedPyPtr &val2) {
  return value_to_shared(concrete_bitwise_intrinsic(
      width_op, sub, python_to_value(val.Get()), python_to_value(val2.Get())));
}

SharedPyPtr PythonPolicy::float_intrinsic(
    FloatOp sub, const std::vector<SharedPyPtr> &operands) {
  // Per FloatOp layout: even index = f32, odd = f64.
  bool is_f32 = (static_cast<unsigned>(sub) % 2 == 0);
  std::vector<Value> concrete_ops;
  concrete_ops.reserve(operands.size());
  for (auto &op : operands) {
    concrete_ops.push_back(python_to_value_f32_aware(op.Get(), is_f32));
  }
  Value v = concrete_float_intrinsic(sub, concrete_ops);
  // ISNAN/ISINF/ISFINITE/SIGNBIT return bool — surface as Python int.
  using enum FloatOp;
  bool returns_bool = (sub == ISNAN_32 || sub == ISNAN_64 ||
                       sub == ISINF_32 || sub == ISINF_64 ||
                       sub == ISFINITE_32 || sub == ISFINITE_64 ||
                       sub == SIGNBIT_32 || sub == SIGNBIT_64);
  if (returns_bool) {
    return value_to_shared(v);
  }
  return float_value_to_shared(v, is_f32 ? 4u : 8u);
}

// ===========================================================================
// 3. Truth test
// ===========================================================================

std::optional<bool> PythonPolicy::is_true(const SharedPyPtr &val) {
  if (PyObject *method = lookup_method(cached_is_true_, "is_true")) {
    PyObject *result = PyObject_CallFunction(method, "O", val.Get());
    if (result && result != Py_NotImplemented) {
      if (result == Py_None) {
        Py_DECREF(result);
        return std::nullopt;
      }
      bool truth = PyObject_IsTrue(result);
      Py_DECREF(result);
      return truth;
    }
    Py_XDECREF(result);
    PyErr_Clear();
  }
  return concrete_is_true(python_to_value(val.Get()));
}

// ===========================================================================
// 4. Memory
// ===========================================================================

SharedPyPtr PythonPolicy::mem_allocate(PythonScheduler &, uint64_t size_bytes,
                                        uint64_t align_bytes) {
  return make_literal_ptr(memory_.allocate(size_bytes, align_bytes));
}

void PythonPolicy::mem_free(PythonScheduler &, const SharedPyPtr &address) {
  if (auto addr = extract_address(address)) {
    memory_.free(*addr);
  }
}

bool PythonPolicy::mem_read(PythonScheduler &, const SharedPyPtr &addr,
                             const MemAccessHint &hint, SharedPyPtr &result) {
  if (PyObject *method = lookup_method(cached_mem_read_, "mem_read")) {
    PyObject *py_result = PyObject_CallFunction(
        method, "OIi", addr.Get(), hint.size_bytes,
        static_cast<int>(hint.is_float));
    if (py_result && py_result != Py_NotImplemented) {
      result = SharedPyPtr(py_result);
      Py_DECREF(py_result);
      return true;
    }
    Py_XDECREF(py_result);
    PyErr_Clear();
  }

  // Concrete fallback.
  auto a = extract_address(addr);
  if (!a) {
    result = make_default();
    return true;
  }
  Value v = concrete_read_from_mem(memory_, *a, hint.size_bytes, hint.is_float);
  result = hint.is_float ? float_value_to_shared(v, hint.size_bytes)
                         : value_to_shared(v);
  return true;
}

bool PythonPolicy::mem_write(PythonScheduler &, const SharedPyPtr &addr,
                              const SharedPyPtr &val,
                              const MemAccessHint &hint) {
  if (PyObject *method = lookup_method(cached_mem_write_, "mem_write")) {
    PyObject *py_result = PyObject_CallFunction(
        method, "OOIi", addr.Get(), val.Get(), hint.size_bytes,
        static_cast<int>(hint.is_float));
    if (py_result && py_result != Py_NotImplemented) {
      Py_DECREF(py_result);
      return true;
    }
    Py_XDECREF(py_result);
    PyErr_Clear();
  }

  // Concrete fallback.
  auto a = extract_address(addr);
  if (!a) return true;
  concrete_write_to_mem(memory_, *a, python_to_value(val.Get()),
                        hint.size_bytes, hint.is_float);
  return true;
}

// Phase 8a: symbolic-LOAD dispatch. The substrate consults this before
// falling through to `with_address`'s suspension path. Python returns a
// resolved value (typically a z3 Select against the region overlay) when
// it can claim the access; NotImplemented (or Py_None) means "fall
// through to the existing suspension path."
bool PythonPolicy::exec_symbolic_load_impl(PythonScheduler &,
                                            const SharedPyPtr &addr,
                                            const MemAccessHint &hint,
                                            SharedPyPtr &result) {
  PyObject *method = lookup_method(cached_symbolic_load_, "symbolic_load");
  if (!method) return false;
  PyObject *py_result = PyObject_CallFunction(
      method, "OIi", addr.Get(), hint.size_bytes,
      static_cast<int>(hint.is_float));
  if (py_result && py_result != Py_NotImplemented && py_result != Py_None) {
    result = SharedPyPtr(py_result);
    Py_DECREF(py_result);
    return true;
  }
  Py_XDECREF(py_result);
  PyErr_Clear();
  return false;
}

bool PythonPolicy::exec_symbolic_store_impl(PythonScheduler &,
                                             const SharedPyPtr &addr,
                                             const SharedPyPtr &val,
                                             const MemAccessHint &hint) {
  PyObject *method = lookup_method(cached_symbolic_store_, "symbolic_store");
  if (!method) return false;
  PyObject *py_result = PyObject_CallFunction(
      method, "OOIi", addr.Get(), val.Get(), hint.size_bytes,
      static_cast<int>(hint.is_float));
  if (py_result && py_result != Py_NotImplemented) {
    Py_DECREF(py_result);
    return true;
  }
  Py_XDECREF(py_result);
  PyErr_Clear();
  return false;
}

bool PythonPolicy::mem_bulk_op(PythonScheduler &, MemOp sub,
                                const std::vector<SharedPyPtr> &ops,
                                const MemoryInst &mi, SharedPyPtr &result) {
  std::vector<Value> concrete_ops;
  concrete_ops.reserve(ops.size());
  for (auto &op : ops) concrete_ops.push_back(python_to_value(op.Get()));
  Value concrete_result;
  bool alive = concrete_mem_bulk_op(memory_, sub, concrete_ops, mi,
                                     concrete_result);
  result = value_to_shared(concrete_result);
  return alive;
}

void PythonPolicy::mem_poison(const SharedPyPtr &addr) {
  if (auto a = extract_address(addr)) memory_.poison(*a);
}

void PythonPolicy::mem_unpoison(const SharedPyPtr &addr) {
  if (auto a = extract_address(addr)) memory_.unpoison(*a);
}

bool PythonPolicy::is_undefined(const SharedPyPtr &val) {
  PyObject *obj = val.Get();
  return obj == nullptr || obj == Py_None;
}

// Phase 8d: per-block-enter notification.
//
// Invoked at the top of every `enter_block` regardless of how the block
// was reached (initial entry, branch resolution, switch dispatch,
// implicit goto). Lets analysts observe block visits beyond just
// branch transitions, which the renderer in `Path.dot_cfg` consumes.
void PythonPolicy::on_enter_block_impl(const IRBlock &block) {
  PyObject *method = lookup_method(cached_on_enter_block_, "on_enter_block");
  if (!method) return;
  auto block_eid = EntityId(block.id()).Pack();
  PyObject *result = PyObject_CallFunction(method, "K",
      static_cast<unsigned long long>(block_eid));
  Py_XDECREF(result);
  if (PyErr_Occurred()) PyErr_Clear();
}

// Per-instruction observer hook.
void PythonPolicy::on_instruction_impl_inner(const IRInstruction &inst) {
  PyObject *method = lookup_method(cached_on_instruction_, "on_instruction");
  if (!method) return;
  PyObject *inst_obj = ::mx::to_python<IRInstruction>(inst);
  if (!inst_obj) { PyErr_Clear(); return; }
  PyObject *result = PyObject_CallFunction(method, "N", inst_obj);
  Py_XDECREF(result);
  if (PyErr_Occurred()) PyErr_Clear();
}

// ===========================================================================
// 5. Resolution
// ===========================================================================

bool PythonPolicy::resolve_branch(PythonScheduler &,
                                   const SharedPyPtr &condition,
                                   IRBlock true_block, IRBlock false_block,
                                   IRBlock &chosen_block) {
  if (PyObject *method = lookup_method(cached_resolve_branch_,
                                       "resolve_branch")) {
    auto true_eid = EntityId(true_block.id()).Pack();
    auto false_eid = EntityId(false_block.id()).Pack();
    PyObject *result = PyObject_CallFunction(
        method, "OKK", condition.Get(), true_eid, false_eid);
    if (result && result != Py_NotImplemented) {
      if (result == Py_None) {
        Py_DECREF(result);
        return false;
      }
      if (PyObject_IsTrue(result)) {
        Py_DECREF(result);
        chosen_block = true_block;
        return true;
      }
      Py_DECREF(result);
      chosen_block = false_block;
      return true;
    }
    Py_XDECREF(result);
    PyErr_Clear();
  }
  chosen_block = true_block;
  return true;
}

bool PythonPolicy::resolve_call(PythonScheduler &,
                                 const IRInstruction &,
                                 RawEntityId target_eid,
                                 RawEntityId indirect_target_eid,
                                 const std::vector<SharedPyPtr> &arguments,
                                 bool is_indirect,
                                 CallResolution<SharedPyPtr> &resolution) {
  // Try Python policy first.
  if (PyObject *method = lookup_method(cached_resolve_call_, "resolve_call")) {
    PyObject *args_list = PyList_New(
        static_cast<Py_ssize_t>(arguments.size()));
    for (size_t i = 0; i < arguments.size(); ++i) {
      PyObject *arg = arguments[i].Get();
      Py_INCREF(arg);
      PyList_SET_ITEM(args_list, static_cast<Py_ssize_t>(i), arg);
    }

    PyObject *result = PyObject_CallFunction(
        method, "KKOi", target_eid, indirect_target_eid,
        args_list, static_cast<int>(is_indirect));
    Py_DECREF(args_list);

    if (!result) {
      // Python exception from the intercept handler — capture it so
      // abort_requested() fires and SymbolicStep can re-raise it.
      capture_exception();
      return false;
    }
    if (result != Py_NotImplemented && result != Py_None) {
      // Parse ("skip", return_value) or ("model", return_value).
      if (PyTuple_Check(result) && PyTuple_Size(result) == 2) {
        PyObject *tag = PyTuple_GetItem(result, 0);
        PyObject *val = PyTuple_GetItem(result, 1);
        if (tag && PyUnicode_Check(tag)) {
          const char *action = PyUnicode_AsUTF8(tag);
          if (action && std::strcmp(action, "skip") == 0) {
            resolution.action = CallAction::SKIP;
            if (val && val != Py_None) {
              resolution.return_value = SharedPyPtr(val);
            } else {
              resolution.return_value = make_default();
            }
            Py_DECREF(result);
            return true;
          }
          if (action && std::strcmp(action, "model") == 0) {
            resolution.action = CallAction::MODEL;
            if (val && val != Py_None) {
              resolution.return_value = SharedPyPtr(val);
            } else {
              resolution.return_value = make_default();
            }
            Py_DECREF(result);
            return true;
          }
        }
      }
      Py_DECREF(result);
    } else {
      Py_DECREF(result);
    }
  }

  // Fall through to C++ func_resolver_.
  if (func_resolver_) {
    for (auto eid : {target_eid, indirect_target_eid}) {
      if (eid != kInvalidEntityId) {
        if (auto ir = func_resolver_(eid)) {
          resolution.action = CallAction::INLINE;
          resolution.return_value = make_default();
          resolution.callee_ir = *std::move(ir);
          return true;
        }
      }
    }
  }
  resolution.action = CallAction::SKIP;
  resolution.return_value = make_default();
  return true;
}

bool PythonPolicy::resolve_global(PythonScheduler &,
                                   RawEntityId entity_id,
                                   GlobalResolution &resolution) {
  if (global_resolver_) {
    if (auto info = global_resolver_(entity_id)) {
      resolution.info = *std::move(info);
      return true;
    }
  }
  resolution = GlobalResolution{};
  return true;
}

// ===========================================================================
// Symbolic dispatch helpers
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
    // Phase 9: optional 5th element is an address_hint (None or int).
    if (PyTuple_Size(ret.Get()) >= 5) {
      PyObject *hint_obj = PyTuple_GetItem(ret.Get(), 4);
      if (hint_obj && hint_obj != Py_None) {
        uint64_t hint = PyLong_AsUnsignedLongLong(hint_obj);
        if (!PyErr_Occurred()) {
          info.address_hint = hint;
        } else {
          PyErr_Clear();
        }
      }
    }
    return info;
  };
}

FunctionAddressResolver make_func_addr_resolver(PyObject *obj) {
  if (!obj || obj == Py_None || !PyCallable_Check(obj)) return {};
  SharedPyPtr fr(obj);
  return [fr](RawEntityId eid) -> std::optional<uint64_t> {
    SharedPyPtr ret(PyObject_CallFunction(fr.Get(), "(K)", eid));
    if (!ret || ret.Get() == Py_None) {
      PyErr_Clear();
      return std::nullopt;
    }
    uint64_t addr = PyLong_AsUnsignedLongLong(ret.Get());
    if (PyErr_Occurred()) {
      PyErr_Clear();
      return std::nullopt;
    }
    return addr;
  };
}

}  // namespace

PyObject *SymbolicInitState(PyObject *state_obj, PyObject *memory_obj,
                            PyObject *py_policy, PyObject *func_obj,
                            PyObject *args_list,
                            PyObject *func_resolver_obj,
                            PyObject *global_resolver_obj,
                            PyObject *func_addr_resolver_obj) {
  auto *sw = reinterpret_cast<InterpreterStateWrapper *>(state_obj);
  auto *mw = reinterpret_cast<ConcreteMemoryWrapper *>(memory_obj);

  auto func = from_python<IRFunction>(func_obj);
  if (!func) {
    PyErr_SetString(PyExc_TypeError, "Expected IRFunction");
    return nullptr;
  }

  // Wrap Python args as SharedPyPtr directly.
  std::vector<SharedPyPtr> c_args;
  if (args_list && args_list != Py_None && PyList_Check(args_list)) {
    for (Py_ssize_t i = 0; i < PyList_Size(args_list); ++i) {
      c_args.emplace_back(PyList_GetItem(args_list, i));
    }
  }

  PythonPolicy policy(py_policy, *mw->memory,
                       make_func_resolver(func_resolver_obj),
                       make_global_resolver(global_resolver_obj),
                       make_func_addr_resolver(func_addr_resolver_obj));
  PythonScheduler sched;

  auto &symbolic = install_fresh_symbolic_state(sw);
  interp_init_state<PythonPolicy, PythonScheduler, SharedPyPtr>(
      policy, sched, symbolic, *func, c_args);

  Py_RETURN_NONE;
}

PyObject *SymbolicInitStateFrame(PyObject *state_obj, PyObject *memory_obj,
                                 PyObject *py_policy, PyObject *func_obj,
                                 PyObject *param_addrs_list,
                                 PyObject *return_addr_obj,
                                 PyObject *func_resolver_obj,
                                 PyObject *global_resolver_obj,
                                 PyObject *func_addr_resolver_obj) {
  auto *sw = reinterpret_cast<InterpreterStateWrapper *>(state_obj);
  auto *mw = reinterpret_cast<ConcreteMemoryWrapper *>(memory_obj);

  auto func = from_python<IRFunction>(func_obj);
  if (!func) {
    PyErr_SetString(PyExc_TypeError, "Expected IRFunction");
    return nullptr;
  }

  // Extract pre-allocated parameter addresses.
  std::vector<uint64_t> param_addrs;
  if (param_addrs_list && param_addrs_list != Py_None &&
      PyList_Check(param_addrs_list)) {
    for (Py_ssize_t i = 0; i < PyList_Size(param_addrs_list); ++i) {
      PyObject *item = PyList_GetItem(param_addrs_list, i);
      param_addrs.push_back(PyLong_AsUnsignedLongLong(item));
      if (PyErr_Occurred()) return nullptr;
    }
  }

  // Extract optional return address.
  std::optional<uint64_t> return_addr;
  if (return_addr_obj && return_addr_obj != Py_None) {
    return_addr = PyLong_AsUnsignedLongLong(return_addr_obj);
    if (PyErr_Occurred()) return nullptr;
  }

  PythonPolicy policy(py_policy, *mw->memory,
                       make_func_resolver(func_resolver_obj),
                       make_global_resolver(global_resolver_obj),
                       make_func_addr_resolver(func_addr_resolver_obj));
  PythonScheduler sched;

  auto &symbolic = install_fresh_symbolic_state(sw);
  interp_init_state_prealloc<PythonPolicy, PythonScheduler, SharedPyPtr>(
      policy, sched, symbolic, *func, param_addrs, return_addr);

  Py_RETURN_NONE;
}

PyObject *SymbolicInitStateAt(PyObject *state_obj, PyObject *memory_obj,
                              PyObject *py_policy, PyObject *func_obj,
                              PyObject *block_obj,
                              PyObject *param_addrs_list,
                              PyObject *return_addr_obj,
                              PyObject *value_seed_dict,
                              PyObject *func_resolver_obj,
                              PyObject *global_resolver_obj,
                              PyObject *func_addr_resolver_obj) {
  auto *sw = reinterpret_cast<InterpreterStateWrapper *>(state_obj);
  auto *mw = reinterpret_cast<ConcreteMemoryWrapper *>(memory_obj);

  auto func = from_python<IRFunction>(func_obj);
  if (!func) {
    PyErr_SetString(PyExc_TypeError, "Expected IRFunction for func");
    return nullptr;
  }

  auto block = from_python<IRBlock>(block_obj);
  if (!block) {
    PyErr_SetString(PyExc_TypeError, "Expected IRBlock for block");
    return nullptr;
  }

  std::vector<uint64_t> param_addrs;
  if (param_addrs_list && param_addrs_list != Py_None &&
      PyList_Check(param_addrs_list)) {
    for (Py_ssize_t i = 0; i < PyList_Size(param_addrs_list); ++i) {
      PyObject *item = PyList_GetItem(param_addrs_list, i);
      param_addrs.push_back(PyLong_AsUnsignedLongLong(item));
      if (PyErr_Occurred()) return nullptr;
    }
  }

  std::optional<uint64_t> return_addr;
  if (return_addr_obj && return_addr_obj != Py_None) {
    return_addr = PyLong_AsUnsignedLongLong(return_addr_obj);
    if (PyErr_Occurred()) return nullptr;
  }

  // Build the value seed: {eid_int: python_value}. Each Python value is
  // wrapped as a SharedPyPtr so it lives as long as the interpreter
  // state needs it.
  std::unordered_map<RawEntityId, SharedPyPtr> value_seed;
  if (value_seed_dict && value_seed_dict != Py_None &&
      PyDict_Check(value_seed_dict)) {
    PyObject *key, *val;
    Py_ssize_t pos = 0;
    while (PyDict_Next(value_seed_dict, &pos, &key, &val)) {
      uint64_t eid = PyLong_AsUnsignedLongLong(key);
      if (PyErr_Occurred()) return nullptr;
      value_seed.emplace(static_cast<RawEntityId>(eid), SharedPyPtr(val));
    }
  }

  PythonPolicy policy(py_policy, *mw->memory,
                       make_func_resolver(func_resolver_obj),
                       make_global_resolver(global_resolver_obj),
                       make_func_addr_resolver(func_addr_resolver_obj));
  PythonScheduler sched;

  auto &symbolic = install_fresh_symbolic_state(sw);
  interp_init_state_at<PythonPolicy, PythonScheduler, SharedPyPtr>(
      policy, sched, symbolic, *func, *block, param_addrs, return_addr,
      value_seed);

  Py_RETURN_NONE;
}

PyObject *SymbolicStep(PyObject *state_obj, PyObject *memory_obj,
                       PyObject *py_policy, uint64_t max_steps,
                       PyObject *func_resolver_obj,
                       PyObject *global_resolver_obj,
                       PyObject *func_addr_resolver_obj) {
  auto *sw = reinterpret_cast<InterpreterStateWrapper *>(state_obj);
  auto *mw = reinterpret_cast<ConcreteMemoryWrapper *>(memory_obj);

  auto *symbolic = symbolic_state_of(sw);
  if (!symbolic) {
    PyErr_SetString(PyExc_RuntimeError,
        "step: symbolic state not initialized — call init_state first");
    return nullptr;
  }

  PythonPolicy policy(py_policy, *mw->memory,
                       make_func_resolver(func_resolver_obj),
                       make_global_resolver(global_resolver_obj),
                       make_func_addr_resolver(func_addr_resolver_obj));
  PythonScheduler sched;

  bool budget_hit = interp_step<PythonPolicy, PythonScheduler, SharedPyPtr>(
      policy, sched, *symbolic, max_steps);

  if (policy.has_pending_exception()) {
    return policy.raise_pending_exception();
  }

  sched.outcome.budget_exhausted = budget_hit;
  sched.outcome.steps = symbolic->steps;

  PyObject *result_dict = PyDict_New();
  if (!result_dict) return nullptr;

  // Terminal outcomes take precedence over continuations.
  if (sched.outcome.terminal) {
    auto &term = *sched.outcome.terminal;
    if (term.kind == TerminalKind::COMPLETED) {
      PyObject *py_val = term.return_value.Get();
      if (!py_val) py_val = Py_None;
      PyObject *result_tuple = Py_BuildValue("(sO)", "completed", py_val);
      PyDict_SetItemString(result_dict, "result", result_tuple);
      Py_XDECREF(result_tuple);
    } else {
      PyObject *result_tuple = Py_BuildValue(
          "(si)", "error", static_cast<int>(term.error_kind));
      PyDict_SetItemString(result_dict, "result", result_tuple);
      Py_XDECREF(result_tuple);
    }
  } else if (!sched.outcome.continuations.empty()) {
    auto *first = sched.outcome.continuations.front().get();
    if (auto *bc = dynamic_cast<BranchContinuation<SharedPyPtr, PyObjectRC> *>(first)) {
      PyObject *cond_obj = bc->condition().Get();
      if (!cond_obj) cond_obj = Py_None;
      uint64_t tb_eid = EntityId(bc->true_block().id()).Pack();
      uint64_t fb_eid = EntityId(bc->false_block().id()).Pack();
      PyObject *result_tuple = Py_BuildValue(
          "(sOKK)", "branch", cond_obj, tb_eid, fb_eid);
      PyDict_SetItemString(result_dict, "result", result_tuple);
      Py_XDECREF(result_tuple);
    } else if (auto *mc = dynamic_cast<MemAddrContinuation<SharedPyPtr, PyObjectRC> *>(first)) {
      PyObject *addr_obj = mc->symbolic_address().Get();
      if (!addr_obj) addr_obj = Py_None;
      const char *sub_kind;
      if (mc->is_call_target()) {
        sub_kind = "call-addr";  // Phase 9: symbolic indirect-call callee
      } else if (mc->is_write()) {
        sub_kind = "store-addr";
      } else {
        sub_kind = "load-addr";
      }
      PyObject *result_tuple = Py_BuildValue(
          "(ssOKIN)", "suspended",
          sub_kind,
          addr_obj,
          static_cast<uint64_t>(mc->address_eid()),
          static_cast<unsigned int>(mc->size_bytes()),
          PyBool_FromLong(mc->is_write() ? 1 : 0));
      PyDict_SetItemString(result_dict, "result", result_tuple);
      Py_XDECREF(result_tuple);
    } else {
      PyObject *desc = PyUnicode_FromString(first->describe().c_str());
      PyObject *result_tuple = Py_BuildValue("(sO)", "suspended", desc);
      PyDict_SetItemString(result_dict, "result", result_tuple);
      Py_XDECREF(result_tuple);
      Py_XDECREF(desc);
    }
  } else {
    if (sched.outcome.budget_exhausted) {
      PyObject *budget_tuple = Py_BuildValue(
          "(sK)", "budget", sched.outcome.steps);
      PyDict_SetItemString(result_dict, "result", budget_tuple);
      Py_XDECREF(budget_tuple);
    } else {
      PyDict_SetItemString(result_dict, "result", Py_None);
    }
  }

  // Build forks list by enumerating each continuation. Branches walk
  // their `next()` enumeration ({false, true}); each Resumption already
  // carries a clone with cond_eid bound and DECIDE_COND_BRANCH re-pushed
  // — stepping it dispatches the right edge. Memory-address suspensions
  // produce a single fork holding the snapshot — the driver picks
  // concrete addresses and calls `resume_addr` on each clone.
  PyObject *forks_list = PyList_New(0);
  for (auto &cont : sched.outcome.continuations) {
    if (auto *bc = dynamic_cast<BranchContinuation<SharedPyPtr, PyObjectRC> *>(cont.get())) {
      while (auto resumption = bc->next()) {
        // resumption->state is already a fresh PyRef<SymbolicState>;
        // hand it to the wrapper, which steals the strong ref.
        PyObject *state_obj = MakeSymbolicStateWrapper(
            std::move(resumption->state));
        PyObject *dict = PyDict_New();
        PyDict_SetItemString(dict, "state", state_obj);
        Py_DECREF(state_obj);
        PyObject *dir_str = PyUnicode_FromString(resumption->label.c_str());
        PyDict_SetItemString(dict, "direction", dir_str);
        Py_DECREF(dir_str);
        PyList_Append(forks_list, dict);
        Py_DECREF(dict);
      }
    } else if (auto *mc = dynamic_cast<MemAddrContinuation<SharedPyPtr, PyObjectRC> *>(cont.get())) {
      auto snap = mc->snapshot();
      if (!snap) continue;
      // Clone the snapshot so the driver can mutate (resume_addr) without
      // disturbing the original continuation's snapshot reference.
      PyObject *state_obj = MakeSymbolicStateWrapper(snap->clone());
      PyObject *dict = PyDict_New();
      PyDict_SetItemString(dict, "state", state_obj);
      Py_XDECREF(state_obj);
      PyObject *kind_str = PyUnicode_FromString(
          mc->is_write() ? "store-addr" : "load-addr");
      PyDict_SetItemString(dict, "kind", kind_str);
      Py_DECREF(kind_str);
      PyObject *addr_obj = mc->symbolic_address().Get();
      if (!addr_obj) addr_obj = Py_None;
      Py_INCREF(addr_obj);
      PyDict_SetItemString(dict, "address", addr_obj);
      Py_DECREF(addr_obj);
      PyObject *eid_obj = PyLong_FromUnsignedLongLong(mc->address_eid());
      PyDict_SetItemString(dict, "address_eid", eid_obj);
      Py_DECREF(eid_obj);
      PyObject *size_obj = PyLong_FromUnsignedLong(mc->size_bytes());
      PyDict_SetItemString(dict, "size", size_obj);
      Py_DECREF(size_obj);
      PyObject *iw_obj = PyBool_FromLong(mc->is_write() ? 1 : 0);
      PyDict_SetItemString(dict, "is_write", iw_obj);
      Py_DECREF(iw_obj);
      PyList_Append(forks_list, dict);
      Py_DECREF(dict);
    }
  }
  PyDict_SetItemString(result_dict, "forks", forks_list);
  Py_DECREF(forks_list);

  return result_dict;
}

#pragma GCC diagnostic pop
}  // namespace mx
