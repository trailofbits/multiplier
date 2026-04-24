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
  if (auto *s = std::get_if<ScalarValue>(&v)) {
    if (s->is_float) {
      double d = (s->width == 4) ? static_cast<double>(s->as_f32())
                                 : s->as_f64();
      return PyFloat_FromDouble(d);
    }
    return PyLong_FromLongLong(s->as_i64());
  }
  if (auto *p = std::get_if<Pointer>(&v)) {
    uint64_t addr = concrete_address(*p);
    return Py_BuildValue("(sK)", "ptr", addr);
  }
  if (is_null(v)) {
    Py_RETURN_NONE;
  }
  Py_RETURN_NONE;
}

Value python_to_value(PyObject *obj) {
  if (obj == nullptr || obj == Py_None) {
    return Pointer(0);
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
    return make_float(PyFloat_AsDouble(obj));
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

// Convert concrete Value -> SharedPyPtr (for concrete fallback results).
SharedPyPtr value_to_shared(const Value &v) {
  PyObject *obj = value_to_python(v);
  SharedPyPtr result(obj);
  Py_XDECREF(obj);  // SharedPyPtr constructor INCREFed
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
struct InterpreterStateWrapper {
  PyObject_HEAD
  InterpreterState<Value> *state;
  InterpreterState<SharedPyPtr> *symbolic_state;
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
  Py_XDECREF(cached_make_const_);
  Py_XDECREF(cached_binary_op_);
  Py_XDECREF(cached_unary_op_);
  Py_XDECREF(cached_compare_);
  Py_XDECREF(cached_cast_);
  Py_XDECREF(cached_is_true_);
  Py_XDECREF(cached_resolve_branch_);
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
  return extract_ptr_tuple(val.Get());
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
  return value_to_shared(concrete_binary_op(
      op, python_to_value(lhs.Get()), python_to_value(rhs.Get())));
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
  return value_to_shared(concrete_unary_op(op, python_to_value(operand.Get())));
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
  return value_to_shared(concrete_compare(
      op, python_to_value(lhs.Get()), python_to_value(rhs.Get())));
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
  return value_to_shared(concrete_cast(op, python_to_value(operand.Get())));
}

SharedPyPtr PythonPolicy::ptr_add(const SharedPyPtr &base,
                                   const SharedPyPtr &index,
                                   int64_t element_size) {
  return value_to_shared(concrete_ptr_add(
      python_to_value(base.Get()), python_to_value(index.Get()), element_size));
}

SharedPyPtr PythonPolicy::ptr_diff(const SharedPyPtr &lhs,
                                    const SharedPyPtr &rhs,
                                    int64_t element_size) {
  return value_to_shared(concrete_ptr_diff(
      python_to_value(lhs.Get()), python_to_value(rhs.Get()), element_size));
}

SharedPyPtr PythonPolicy::ptr_offset(const SharedPyPtr &base,
                                      int64_t byte_offset) {
  return value_to_shared(concrete_ptr_offset(
      python_to_value(base.Get()), byte_offset));
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
  std::vector<Value> concrete_ops;
  concrete_ops.reserve(operands.size());
  for (auto &op : operands) concrete_ops.push_back(python_to_value(op.Get()));
  return value_to_shared(concrete_float_intrinsic(sub, concrete_ops));
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
  auto a = extract_address(addr);
  if (!a) {
    result = make_default();
    return true;
  }
  result = value_to_shared(concrete_read_from_mem(memory_, *a,
                                                   hint.size_bytes,
                                                   hint.is_float));
  return true;
}

bool PythonPolicy::mem_write(PythonScheduler &, const SharedPyPtr &addr,
                              const SharedPyPtr &val,
                              const MemAccessHint &hint) {
  auto a = extract_address(addr);
  if (!a) return true;
  concrete_write_to_mem(memory_, *a, python_to_value(val.Get()),
                        hint.size_bytes);
  return true;
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
                                 const std::vector<SharedPyPtr> &,
                                 bool,
                                 CallResolution<SharedPyPtr> &resolution) {
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
    return info;
  };
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

  // Wrap Python args as SharedPyPtr directly.
  std::vector<SharedPyPtr> c_args;
  if (args_list && args_list != Py_None && PyList_Check(args_list)) {
    for (Py_ssize_t i = 0; i < PyList_Size(args_list); ++i) {
      c_args.emplace_back(PyList_GetItem(args_list, i));
    }
  }

  PythonPolicy policy(py_policy, *mw->memory,
                       make_func_resolver(func_resolver_obj),
                       make_global_resolver(global_resolver_obj));
  PythonScheduler sched;

  interp_init_state<PythonPolicy, PythonScheduler, SharedPyPtr>(
      policy, sched, *sw->symbolic_state, *func, c_args);

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

  bool budget_hit = interp_step<PythonPolicy, PythonScheduler, SharedPyPtr>(
      policy, sched, *sw->symbolic_state, max_steps);

  PyObject *result_dict = PyDict_New();
  if (!result_dict) return nullptr;

  switch (sched.result_kind) {
    case PythonScheduler::COMPLETED: {
      PyObject *py_val = sched.return_value.Get();
      if (!py_val) py_val = Py_None;
      PyObject *result_tuple = Py_BuildValue("(sO)", "completed", py_val);
      PyDict_SetItemString(result_dict, "result", result_tuple);
      Py_XDECREF(result_tuple);
      break;
    }
    case PythonScheduler::ERRORED: {
      PyObject *result_tuple = Py_BuildValue(
          "(si)", "error", static_cast<int>(sched.error_kind));
      PyDict_SetItemString(result_dict, "result", result_tuple);
      Py_XDECREF(result_tuple);
      break;
    }
    case PythonScheduler::BRANCH: {
      PyObject *result_tuple = Py_BuildValue("(si)", "suspended", 0);
      PyDict_SetItemString(result_dict, "result", result_tuple);
      Py_XDECREF(result_tuple);
      break;
    }
    case PythonScheduler::NONE: {
      if (budget_hit) {
        PyObject *budget_tuple = Py_BuildValue(
            "(sK)", "budget", sw->symbolic_state->steps);
        PyDict_SetItemString(result_dict, "result", budget_tuple);
        Py_XDECREF(budget_tuple);
      } else {
        PyDict_SetItemString(result_dict, "result", Py_None);
      }
      break;
    }
  }

  PyObject *forks_list = PyList_New(
      static_cast<Py_ssize_t>(sched.forks.size()));
  for (size_t i = 0; i < sched.forks.size(); ++i) {
    PyObject *dict = PyDict_New();
    PyList_SET_ITEM(forks_list, static_cast<Py_ssize_t>(i), dict);
  }
  PyDict_SetItemString(result_dict, "forks", forks_list);
  Py_DECREF(forks_list);

  return result_dict;
}

#pragma GCC diagnostic pop
}  // namespace mx
