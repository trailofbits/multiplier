// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Hand-written Python bindings for the IR interpreter.
// Exposes ConcretePolicy-based interpretation via init_state/step and
// the polymorphic Continuation/StepOutcome model.

#include <multiplier/IR/Interpret/Interpreter.h>
#include <multiplier/IR/Interpret/InterpreterLoop.h>
#include <multiplier/IR/Interpret/ConcretePolicy.h>
#include <multiplier/IR/Interpret/ConcreteMemory.h>
#include <multiplier/IR/Interpret/Continuation.h>
#include <multiplier/IR/Interpret/Policy.h>
#include <multiplier/IR/Interpret/SharablePy.h>
#include <multiplier/IR/Interpret/Value.h>
#include <multiplier/IR/Function.h>

#include <cassert>
#include <cstring>

#include "Binding.h"
#include "Error.h"
#include "Interpreter.h"
#include "SymbolicInterpreter.h"

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

// ===========================================================================
// Value <-> Python conversion
// ===========================================================================

namespace {

PyObject *value_to_python(const Value &v) {
  // Pointers are just integers now. Return as plain Python int.
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
    // Legacy ("ptr", addr) tuple — treat as integer.
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

}  // namespace

// ===========================================================================
// Python wrapper types
// ===========================================================================

namespace {

struct ConcreteMemoryWrapper {
  PyObject_HEAD
  ConcreteMemory *memory;
};

struct ConcretePolicyWrapper {
  PyObject_HEAD
  ConcretePolicy *policy;
};

// `state` and `symbolic_state` are strong references to PyObjects whose
// payloads are `ConcreteState` and `SymbolicState` respectively (both
// PyObjectRC instantiations of `InterpreterState`). Continuations from
// either arm hold `PyRef<...>` so the inner state outlives the wrapper
// when needed. A null pointer means that arm is uninitialized.
struct InterpreterStateWrapper {
  PyObject_HEAD
  ::PyObject *state;
  ::PyObject *symbolic_state;
};

// Forward declarations of the private state PyTypes.
static PyTypeObject ConcreteStatePyType;

// PyConcreteScheduler — drains a single StepOutcome for the concrete
// Python arm. Mirrors NoOpScheduler but holds PyObjectRC continuations
// so they participate in normal Python reference counting.
struct PyConcreteScheduler
    : ir::interpret::Scheduler<PyConcreteScheduler, Value> {
  ir::interpret::StepOutcome<Value, ir::interpret::PyObjectRC> outcome;

  void emit_fork(const ConcreteState &,
                 std::function<void(ConcreteState &, void *)>) {}
  void emit_error(const ConcreteState &, std::string_view) {}

  void on_completed(Value return_value,
                    ir::interpret::ref_t<ConcreteState> state) {
    outcome.terminal = ir::interpret::TerminalResult<
        Value, ir::interpret::PyObjectRC>{
        ir::interpret::TerminalKind::COMPLETED,
        std::move(return_value), {}, std::move(state)};
  }

  void on_errored(ir::interpret::ErrorKind kind,
                  ir::interpret::ref_t<ConcreteState> state) {
    outcome.terminal = ir::interpret::TerminalResult<
        Value, ir::interpret::PyObjectRC>{
        ir::interpret::TerminalKind::ERRORED, {}, kind, std::move(state)};
  }

  void on_branch(Value condition, RawEntityId cond_eid,
                 IRBlock true_block, IRBlock false_block,
                 Value false_val, Value true_val,
                 ir::interpret::ref_t<ConcreteState> state) {
    outcome.continuations.emplace_back(
        std::make_unique<ir::interpret::BranchContinuation<
            Value, ir::interpret::PyObjectRC>>(
            std::move(state), std::move(condition), cond_eid,
            true_block, false_block,
            std::move(false_val), std::move(true_val)));
  }
};

// Extract the embedded ConcreteState from a wrapper's `state` PyObject.
// Returns nullptr if the concrete arm is uninitialized.
inline ConcreteState *concrete_state_of(InterpreterStateWrapper *sw) {
  if (!sw || !sw->state) return nullptr;
  return reinterpret_cast<
      ir::interpret::PyWrapperFor<ConcreteState> *>(sw->state)->data;
}

// Drop any existing concrete state PyObject on `sw` and install a freshly
// constructed one.
inline ConcreteState &install_fresh_concrete_state(
    InterpreterStateWrapper *sw) {
  auto fresh = ir::interpret::make_sharable<ConcreteState>();
  Py_XDECREF(sw->state);
  sw->state = fresh.release();
  return *concrete_state_of(sw);
}

// Forward declarations.
static PyTypeObject ConcreteMemoryType;
static PyTypeObject ConcretePolicyType;
static PyTypeObject InterpreterStateType;

// --- ConcreteState (private PyTypeObject) ---

static void ConcreteStatePyType_dealloc(PyObject *self) {
  auto *o = reinterpret_cast<
      ir::interpret::PyWrapperFor<ConcreteState> *>(self);
  if (o->data) {
    o->data->~ConcreteState();
    o->data = nullptr;
  }
  PyObject_Free(self);
}

// --- ConcreteMemory ---

static void ConcreteMemoryWrapper_dealloc(ConcreteMemoryWrapper *self) {
  delete self->memory;
  Py_TYPE(self)->tp_free(reinterpret_cast<PyObject *>(self));
}

static int ConcreteMemoryWrapper_init(ConcreteMemoryWrapper *self,
                                       PyObject *args, PyObject *) {
  uint8_t addr_width = 8;
  uint64_t base_addr = 0x10000;
  if (!PyArg_ParseTuple(args, "|bK", &addr_width, &base_addr)) {
    return -1;
  }
  self->memory = new ConcreteMemory(addr_width, base_addr);
  return 0;
}

static PyObject *ConcreteMemoryWrapper_read_bytes(
    ConcreteMemoryWrapper *self, PyObject *args) {
  uint64_t addr;
  uint32_t size;
  if (!PyArg_ParseTuple(args, "KI", &addr, &size)) return nullptr;

  std::vector<uint8_t> buf(size, 0);
  if (!self->memory->read(addr, buf.data(), size)) {
    PyErr_SetString(PyExc_RuntimeError, "Memory read failed");
    return nullptr;
  }
  return PyBytes_FromStringAndSize(
      reinterpret_cast<const char *>(buf.data()),
      static_cast<Py_ssize_t>(size));
}

static PyObject *ConcreteMemoryWrapper_write_bytes(
    ConcreteMemoryWrapper *self, PyObject *args) {
  uint64_t addr;
  Py_buffer buf;
  if (!PyArg_ParseTuple(args, "Ky*", &addr, &buf)) return nullptr;

  bool ok = self->memory->write(
      addr, buf.buf, static_cast<uint32_t>(buf.len));
  PyBuffer_Release(&buf);
  if (!ok) {
    PyErr_SetString(PyExc_RuntimeError, "Memory write failed");
    return nullptr;
  }
  Py_RETURN_NONE;
}

static PyObject *ConcreteMemoryWrapper_allocate(
    ConcreteMemoryWrapper *self, PyObject *args) {
  uint64_t size, align = 8;
  if (!PyArg_ParseTuple(args, "K|K", &size, &align)) return nullptr;
  uint64_t addr = self->memory->allocate(size, align);
  return PyLong_FromUnsignedLongLong(addr);
}

static PyObject *ConcreteMemoryWrapper_place_at(
    ConcreteMemoryWrapper *self, PyObject *args) {
  uint64_t addr, size, align = 8;
  if (!PyArg_ParseTuple(args, "KK|K", &addr, &size, &align)) return nullptr;
  bool ok = self->memory->place_at(addr, size, align);
  return PyBool_FromLong(ok ? 1 : 0);
}

static PyObject *ConcreteMemoryWrapper_free(
    ConcreteMemoryWrapper *self, PyObject *args) {
  uint64_t addr;
  if (!PyArg_ParseTuple(args, "K", &addr)) return nullptr;
  self->memory->free(addr);
  Py_RETURN_NONE;
}

static PyObject *ConcreteMemoryWrapper_fork(
    ConcreteMemoryWrapper *self, PyObject *) {
  auto forked = self->memory->fork();
  auto *wrapper = PyObject_New(ConcreteMemoryWrapper, &ConcreteMemoryType);
  if (!wrapper) return nullptr;
  wrapper->memory = static_cast<ConcreteMemory *>(forked.release());
  return reinterpret_cast<PyObject *>(wrapper);
}

static PyObject *ConcreteMemoryWrapper_read_bits(
    ConcreteMemoryWrapper *self, PyObject *args) {
  uint64_t addr;
  uint32_t bit_offset, bit_width;
  if (!PyArg_ParseTuple(args, "KII", &addr, &bit_offset, &bit_width))
    return nullptr;
  uint32_t first_byte = bit_offset / 8;
  uint32_t last_byte = (bit_offset + bit_width - 1) / 8;
  uint32_t num_bytes = last_byte - first_byte + 1;
  std::vector<uint8_t> buf(num_bytes, 0);
  self->memory->read(addr + first_byte, buf.data(), num_bytes);
  uint64_t raw = 0;
  for (uint32_t i = 0; i < num_bytes; ++i)
    raw |= static_cast<uint64_t>(buf[i]) << (i * 8);
  raw >>= (bit_offset % 8);
  raw &= (bit_width >= 64) ? ~0ULL : ((1ULL << bit_width) - 1);
  return PyLong_FromUnsignedLongLong(raw);
}

static PyObject *ConcreteMemoryWrapper_write_bits(
    ConcreteMemoryWrapper *self, PyObject *args) {
  uint64_t addr;
  uint32_t bit_offset, bit_width;
  uint64_t value;
  if (!PyArg_ParseTuple(args, "KIIK", &addr, &bit_offset, &bit_width, &value))
    return nullptr;
  uint64_t mask = (bit_width >= 64) ? ~0ULL : ((1ULL << bit_width) - 1);
  value &= mask;
  uint32_t first_byte = bit_offset / 8;
  uint32_t last_byte = (bit_offset + bit_width - 1) / 8;
  uint32_t num_bytes = last_byte - first_byte + 1;
  std::vector<uint8_t> buf(num_bytes, 0);
  self->memory->read(addr + first_byte, buf.data(), num_bytes);
  uint64_t raw = 0;
  for (uint32_t i = 0; i < num_bytes; ++i)
    raw |= static_cast<uint64_t>(buf[i]) << (i * 8);
  uint32_t shift = bit_offset % 8;
  raw &= ~(mask << shift);
  raw |= (value << shift);
  for (uint32_t i = 0; i < num_bytes; ++i)
    buf[i] = static_cast<uint8_t>(raw >> (i * 8));
  self->memory->write(addr + first_byte, buf.data(), num_bytes);
  Py_RETURN_NONE;
}

static PyMethodDef ConcreteMemoryWrapper_methods[] = {
  {"read_bytes", (PyCFunction)ConcreteMemoryWrapper_read_bytes,
   METH_VARARGS, "read_bytes(addr, size) -> bytes"},
  {"write_bytes", (PyCFunction)ConcreteMemoryWrapper_write_bytes,
   METH_VARARGS, "write_bytes(addr, data)"},
  {"read_bits", (PyCFunction)ConcreteMemoryWrapper_read_bits,
   METH_VARARGS, "read_bits(addr, bit_offset, bit_width) -> int"},
  {"write_bits", (PyCFunction)ConcreteMemoryWrapper_write_bits,
   METH_VARARGS, "write_bits(addr, bit_offset, bit_width, value)"},
  {"allocate", (PyCFunction)ConcreteMemoryWrapper_allocate,
   METH_VARARGS, "allocate(size[, align]) -> int"},
  {"place_at", (PyCFunction)ConcreteMemoryWrapper_place_at,
   METH_VARARGS, "place_at(addr, size[, align]) -> bool — pre-allocate "
   "a region at a chosen address; returns False on overlap or "
   "misalignment"},
  {"free", (PyCFunction)ConcreteMemoryWrapper_free,
   METH_VARARGS, "free(addr)"},
  {"fork", (PyCFunction)ConcreteMemoryWrapper_fork,
   METH_NOARGS, "fork() -> ConcreteMemory (deep copy)"},
  {nullptr}
};

// --- ConcretePolicy ---

static void ConcretePolicyWrapper_dealloc(ConcretePolicyWrapper *self) {
  delete self->policy;
  Py_TYPE(self)->tp_free(reinterpret_cast<PyObject *>(self));
}

static int ConcretePolicyWrapper_init(ConcretePolicyWrapper *self,
                                       PyObject *args, PyObject *) {
  PyObject *memory_obj;
  PyObject *func_resolver_obj = Py_None;
  PyObject *global_resolver_obj = Py_None;
  if (!PyArg_ParseTuple(args, "O|OO", &memory_obj,
                         &func_resolver_obj, &global_resolver_obj)) {
    return -1;
  }

  auto *mw = reinterpret_cast<ConcreteMemoryWrapper *>(memory_obj);

  FunctionResolver func_resolver;
  if (func_resolver_obj != Py_None && PyCallable_Check(func_resolver_obj)) {
    SharedPyPtr fr(func_resolver_obj);
    func_resolver = [fr](RawEntityId eid) -> std::optional<IRFunction> {
      SharedPyPtr ret(PyObject_CallFunction(fr.Get(), "(K)", eid));
      if (!ret || ret.Get() == Py_None) {
        PyErr_Clear();
        return std::nullopt;
      }
      return from_python<IRFunction>(ret.Get());
    };
  }

  GlobalResolver global_resolver;
  if (global_resolver_obj != Py_None &&
      PyCallable_Check(global_resolver_obj)) {
    SharedPyPtr gr(global_resolver_obj);
    global_resolver = [gr](RawEntityId eid) -> std::optional<GlobalInfo> {
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

  self->policy = new ConcretePolicy(*mw->memory, std::move(func_resolver),
                                     std::move(global_resolver));
  return 0;
}

// --- InterpreterState ---

static void InterpreterStateWrapper_dealloc(InterpreterStateWrapper *self) {
  Py_XDECREF(self->state);
  Py_XDECREF(self->symbolic_state);
  Py_TYPE(self)->tp_free(reinterpret_cast<PyObject *>(self));
}

static int InterpreterStateWrapper_init(
    InterpreterStateWrapper *self, PyObject *, PyObject *) {
  // Both arms are allocated lazily on first use — `init_state` installs
  // whichever arm matches its policy argument.
  self->state = nullptr;
  self->symbolic_state = nullptr;
  return 0;
}

static PyObject *InterpreterStateWrapper_get_steps(
    InterpreterStateWrapper *self, void *) {
  if (auto *c = concrete_state_of(self)) {
    return PyLong_FromUnsignedLongLong(c->steps);
  }
  if (self->symbolic_state) {
    auto *symbolic = reinterpret_cast<
        ir::interpret::PyWrapperFor<SymbolicState> *>(
        self->symbolic_state)->data;
    if (symbolic) return PyLong_FromUnsignedLongLong(symbolic->steps);
  }
  return PyLong_FromUnsignedLongLong(0);
}

static PyObject *InterpreterStateWrapper_get_empty(
    InterpreterStateWrapper *self, void *) {
  if (auto *c = concrete_state_of(self)) {
    return PyBool_FromLong(c->call_stack.empty());
  }
  if (self->symbolic_state) {
    auto *symbolic = reinterpret_cast<
        ir::interpret::PyWrapperFor<SymbolicState> *>(
        self->symbolic_state)->data;
    if (symbolic) return PyBool_FromLong(symbolic->call_stack.empty());
  }
  return PyBool_FromLong(1);
}

static PyObject *InterpreterStateWrapper_get_depth(
    InterpreterStateWrapper *self, void *) {
  if (auto *c = concrete_state_of(self)) {
    return PyLong_FromSize_t(c->call_stack.depth());
  }
  if (self->symbolic_state) {
    auto *symbolic = reinterpret_cast<
        ir::interpret::PyWrapperFor<SymbolicState> *>(
        self->symbolic_state)->data;
    if (symbolic) return PyLong_FromSize_t(symbolic->call_stack.depth());
  }
  return PyLong_FromSize_t(0);
}

static PyGetSetDef InterpreterStateWrapper_getset[] = {
  {"steps", (getter)InterpreterStateWrapper_get_steps, nullptr,
   "Instruction step count", nullptr},
  {"empty", (getter)InterpreterStateWrapper_get_empty, nullptr,
   "True if call stack is empty", nullptr},
  {"depth", (getter)InterpreterStateWrapper_get_depth, nullptr,
   "Call stack depth", nullptr},
  {nullptr}
};

// --- Free functions: init_state, step ---
//
// Unified entry points.  The second argument determines the dispatch:
//   ConcretePolicy  -> concrete path
//   ConcreteMemory  -> symbolic path (third arg is the Python policy object)

static PyObject *py_init_state(PyObject *, PyObject *args) {
  Py_ssize_t nargs = PyTuple_Size(args);
  if (nargs < 3) {
    PyErr_SetString(PyExc_TypeError,
                    "init_state requires at least 3 arguments");
    return nullptr;
  }

  PyObject *state_obj = PyTuple_GetItem(args, 0);
  PyObject *second    = PyTuple_GetItem(args, 1);

  if (Py_TYPE(second) == &ConcretePolicyType) {
    // Concrete: init_state(state, policy, func[, args])
    PyObject *func_obj = PyTuple_GetItem(args, 2);
    PyObject *args_list = (nargs >= 4) ? PyTuple_GetItem(args, 3) : nullptr;

    auto *sw = reinterpret_cast<InterpreterStateWrapper *>(state_obj);
    auto *pw = reinterpret_cast<ConcretePolicyWrapper *>(second);
    auto func = from_python<IRFunction>(func_obj);
    if (!func) {
      PyErr_SetString(PyExc_TypeError, "Expected IRFunction");
      return nullptr;
    }

    std::vector<Value> c_args;
    if (args_list && PyList_Check(args_list)) {
      for (Py_ssize_t i = 0; i < PyList_Size(args_list); ++i) {
        c_args.push_back(python_to_value(PyList_GetItem(args_list, i)));
      }
    }

    auto &concrete = install_fresh_concrete_state(sw);
    PyConcreteScheduler sched;
    ir::interpret::interp_init_state<
        ir::interpret::ConcretePolicy, PyConcreteScheduler, Value>(
        *pw->policy, sched, concrete, *func, c_args);
    Py_RETURN_NONE;

  } else if (Py_TYPE(second) == &ConcreteMemoryType) {
    // Symbolic: init_state(state, memory, policy, func[, args
    //                      [, func_resolver[, global_resolver]]])
    if (nargs < 4) {
      PyErr_SetString(PyExc_TypeError,
          "Symbolic init_state requires at least 4 arguments: "
          "init_state(state, memory, policy, func[, args"
          "[, func_resolver[, global_resolver]]])");
      return nullptr;
    }
    PyObject *py_policy = PyTuple_GetItem(args, 2);
    PyObject *func_obj  = PyTuple_GetItem(args, 3);
    PyObject *args_list = (nargs >= 5) ? PyTuple_GetItem(args, 4) : nullptr;
    PyObject *func_resolver = (nargs >= 6) ? PyTuple_GetItem(args, 5) : Py_None;
    PyObject *global_resolver = (nargs >= 7) ? PyTuple_GetItem(args, 6) : Py_None;
    PyObject *func_addr_resolver =
        (nargs >= 8) ? PyTuple_GetItem(args, 7) : Py_None;
    return SymbolicInitState(state_obj, second, py_policy, func_obj,
                             args_list, func_resolver, global_resolver,
                             func_addr_resolver);
  }

  PyErr_SetString(PyExc_TypeError,
      "Second argument must be ConcretePolicy or ConcreteMemory");
  return nullptr;
}

// Concrete-path step result — translates the StepOutcome's terminal
// (completed / errored) or suspension shape into the Python dict the
// existing harness expects.
static PyObject *build_result_dict(
    const ir::interpret::StepOutcome<Value, ir::interpret::PyObjectRC>
        &outcome) {
  PyObject *result_dict = PyDict_New();
  if (!result_dict) return nullptr;

  PyObject *result_tuple;
  if (outcome.terminal) {
    auto &term = *outcome.terminal;
    if (term.kind == TerminalKind::COMPLETED) {
      PyObject *py_val = value_to_python(term.return_value);
      result_tuple = Py_BuildValue("(sN)", "completed", py_val);
    } else {
      result_tuple = Py_BuildValue("(si)", "error",
                                   static_cast<int>(term.error_kind));
    }
  } else if (!outcome.continuations.empty()) {
    auto &cont = *outcome.continuations.front();
    PyObject *desc = PyUnicode_FromString(cont.describe().c_str());
    result_tuple = Py_BuildValue("(sN)", "suspended", desc);
  } else {
    result_tuple = Py_BuildValue("(s)", "suspended");
  }
  PyDict_SetItemString(result_dict, "result", result_tuple);
  Py_XDECREF(result_tuple);

  PyObject *empty_forks = PyList_New(0);
  PyDict_SetItemString(result_dict, "forks", empty_forks);
  Py_DECREF(empty_forks);

  return result_dict;
}

static PyObject *py_step(PyObject *, PyObject *args) {
  Py_ssize_t nargs = PyTuple_Size(args);
  if (nargs < 2) {
    PyErr_SetString(PyExc_TypeError,
                    "step requires at least 2 arguments");
    return nullptr;
  }

  PyObject *state_obj = PyTuple_GetItem(args, 0);
  PyObject *second    = PyTuple_GetItem(args, 1);

  if (Py_TYPE(second) == &ConcretePolicyType) {
    // Concrete: step(state, policy[, max_steps])
    uint64_t max_steps = 1;
    if (nargs >= 3) {
      max_steps = PyLong_AsUnsignedLongLong(PyTuple_GetItem(args, 2));
      if (PyErr_Occurred()) return nullptr;
    }

    auto *sw = reinterpret_cast<InterpreterStateWrapper *>(state_obj);
    auto *pw = reinterpret_cast<ConcretePolicyWrapper *>(second);

    auto *concrete = concrete_state_of(sw);
    if (!concrete) {
      PyErr_SetString(PyExc_RuntimeError,
          "step: concrete state not initialized — call init_state first");
      return nullptr;
    }

    PyConcreteScheduler sched;
    bool budget_hit = ir::interpret::interp_step<
        ir::interpret::ConcretePolicy, PyConcreteScheduler, Value>(
        *pw->policy, sched, *concrete, max_steps);
    sched.outcome.budget_exhausted = budget_hit;
    sched.outcome.steps = concrete->steps;

    if (sched.outcome.terminal || !sched.outcome.continuations.empty()) {
      return build_result_dict(sched.outcome);
    }

    if (budget_hit) {
      PyObject *result_dict = PyDict_New();
      if (!result_dict) return nullptr;
      PyObject *budget_tuple = Py_BuildValue(
          "(sK)", "budget", concrete->steps);
      PyDict_SetItemString(result_dict, "result", budget_tuple);
      Py_XDECREF(budget_tuple);
      PyObject *empty_forks = PyList_New(0);
      PyDict_SetItemString(result_dict, "forks", empty_forks);
      Py_DECREF(empty_forks);
      return result_dict;
    }

    Py_RETURN_NONE;

  } else if (Py_TYPE(second) == &ConcreteMemoryType) {
    // Symbolic: step(state, memory, policy[, max_steps
    //               [, func_resolver[, global_resolver]]])
    if (nargs < 3) {
      PyErr_SetString(PyExc_TypeError,
          "Symbolic step requires at least 3 arguments: "
          "step(state, memory, policy[, max_steps"
          "[, func_resolver[, global_resolver]]])");
      return nullptr;
    }
    PyObject *py_policy = PyTuple_GetItem(args, 2);
    uint64_t max_steps = 1;
    if (nargs >= 4) {
      max_steps = PyLong_AsUnsignedLongLong(PyTuple_GetItem(args, 3));
      if (PyErr_Occurred()) return nullptr;
    }
    PyObject *func_resolver = (nargs >= 5) ? PyTuple_GetItem(args, 4) : Py_None;
    PyObject *global_resolver = (nargs >= 6) ? PyTuple_GetItem(args, 5) : Py_None;
    PyObject *func_addr_resolver =
        (nargs >= 7) ? PyTuple_GetItem(args, 6) : Py_None;
    return SymbolicStep(state_obj, second, py_policy, max_steps,
                        func_resolver, global_resolver,
                        func_addr_resolver);
  }

  PyErr_SetString(PyExc_TypeError,
      "Second argument must be ConcretePolicy or ConcreteMemory");
  return nullptr;
}

// Resume a state suspended on a symbolic address by writing a chosen
// concrete pointer into the suspended op's address-operand cache slot.
// The state's symbolic_state must already carry the snapshot's
// work_stack (with the suspended item re-pushed) — that's how
// `with_address_impl` constructs the snapshot before emitting the
// MemAddrContinuation.
//
//   resume_addr(state, address_eid, concrete_addr)
static PyObject *py_resume_addr(PyObject *, PyObject *args) {
  PyObject *state_obj;
  uint64_t address_eid;
  uint64_t chosen_addr;
  if (!PyArg_ParseTuple(args, "OKK", &state_obj, &address_eid,
                         &chosen_addr)) {
    return nullptr;
  }
  if (Py_TYPE(state_obj) != &InterpreterStateType) {
    PyErr_SetString(PyExc_TypeError, "Expected InterpreterState");
    return nullptr;
  }
  auto *sw = reinterpret_cast<InterpreterStateWrapper *>(state_obj);
  auto *symbolic = sw->symbolic_state
      ? reinterpret_cast<ir::interpret::PyWrapperFor<SymbolicState> *>(
            sw->symbolic_state)->data
      : nullptr;
  if (!symbolic || symbolic->call_stack.empty()) {
    PyErr_SetString(PyExc_RuntimeError,
                    "resume_addr: symbolic state has no live call frame");
    return nullptr;
  }
  PyObject *ptr_tuple = Py_BuildValue("(sK)", "ptr", chosen_addr);
  if (!ptr_tuple) return nullptr;
  SharedPyPtr ptr_val(ptr_tuple);
  Py_DECREF(ptr_tuple);
  symbolic->call_stack.top().values[address_eid] = ptr_val;
  Py_RETURN_NONE;
}

// Resume a state suspended on a symbolic address by writing an arbitrary
// Python value (e.g. a z3 expression) into the suspended op's
// address-operand cache slot. Sibling of `resume_addr` for the
// symbolic-address path opened by Phase 6's `SplitByRegion` /
// `ConstrainTo` decisions.
//
//   resume_addr_symbolic(state, address_eid, py_value)
static PyObject *py_resume_addr_symbolic(PyObject *, PyObject *args) {
  PyObject *state_obj;
  uint64_t address_eid;
  PyObject *py_value;
  if (!PyArg_ParseTuple(args, "OKO", &state_obj, &address_eid, &py_value)) {
    return nullptr;
  }
  if (Py_TYPE(state_obj) != &InterpreterStateType) {
    PyErr_SetString(PyExc_TypeError, "Expected InterpreterState");
    return nullptr;
  }
  auto *sw = reinterpret_cast<InterpreterStateWrapper *>(state_obj);
  auto *symbolic = sw->symbolic_state
      ? reinterpret_cast<ir::interpret::PyWrapperFor<SymbolicState> *>(
            sw->symbolic_state)->data
      : nullptr;
  if (!symbolic || symbolic->call_stack.empty()) {
    PyErr_SetString(PyExc_RuntimeError,
                    "resume_addr_symbolic: symbolic state has no live "
                    "call frame");
    return nullptr;
  }
  symbolic->call_stack.top().values[address_eid] = SharedPyPtr(py_value);
  Py_RETURN_NONE;
}

// Read the cached Python value at a given operand entity-id from the
// live call frame. Returns None when the slot has not been populated.
// Used by Phase 6 P6.0 to validate `resume_addr_symbolic`'s round-trip
// (and otherwise useful for diagnosing resumption state).
//
//   get_value_at(state, eid)
static PyObject *py_get_value_at(PyObject *, PyObject *args) {
  PyObject *state_obj;
  uint64_t eid;
  if (!PyArg_ParseTuple(args, "OK", &state_obj, &eid)) return nullptr;
  if (Py_TYPE(state_obj) != &InterpreterStateType) {
    PyErr_SetString(PyExc_TypeError, "Expected InterpreterState");
    return nullptr;
  }
  auto *sw = reinterpret_cast<InterpreterStateWrapper *>(state_obj);
  auto *symbolic = sw->symbolic_state
      ? reinterpret_cast<ir::interpret::PyWrapperFor<SymbolicState> *>(
            sw->symbolic_state)->data
      : nullptr;
  if (!symbolic || symbolic->call_stack.empty()) {
    Py_RETURN_NONE;
  }
  auto &values = symbolic->call_stack.top().values;
  auto it = values.find(eid);
  if (it == values.end() || !it->second.Get()) {
    Py_RETURN_NONE;
  }
  PyObject *obj = it->second.Get();
  Py_INCREF(obj);
  return obj;
}

static PyObject *py_clone_state(PyObject *, PyObject *args) {
  PyObject *state_obj;
  if (!PyArg_ParseTuple(args, "O", &state_obj)) return nullptr;

  if (Py_TYPE(state_obj) != &InterpreterStateType) {
    PyErr_SetString(PyExc_TypeError, "Expected InterpreterState");
    return nullptr;
  }

  auto *sw = reinterpret_cast<InterpreterStateWrapper *>(state_obj);

  // Clone the symbolic state if it exists, otherwise clone concrete.
  if (sw->symbolic_state) {
    auto *symbolic = reinterpret_cast<
        ir::interpret::PyWrapperFor<SymbolicState> *>(
        sw->symbolic_state)->data;
    return MakeSymbolicStateWrapper(symbolic->clone());
  }

  // Concrete clone.
  if (auto *concrete = concrete_state_of(sw)) {
    auto *wrapper = PyObject_New(InterpreterStateWrapper, &InterpreterStateType);
    if (!wrapper) return nullptr;
    wrapper->state = concrete->clone().release();
    wrapper->symbolic_state = nullptr;
    return reinterpret_cast<PyObject *>(wrapper);
  }

  // Both arms are uninitialized — return a fresh empty wrapper.
  auto *wrapper = PyObject_New(InterpreterStateWrapper, &InterpreterStateType);
  if (!wrapper) return nullptr;
  wrapper->state = nullptr;
  wrapper->symbolic_state = nullptr;
  return reinterpret_cast<PyObject *>(wrapper);
}

// init_state_frame: use pre-allocated parameter/return addresses (from CallFrame).
// init_state_frame(state, memory, policy, func, param_addrs, return_addr
//                  [, func_resolver[, global_resolver]])
static PyObject *py_init_state_frame(PyObject *, PyObject *args) {
  Py_ssize_t nargs = PyTuple_Size(args);
  if (nargs < 6) {
    PyErr_SetString(PyExc_TypeError,
        "init_state_frame requires at least 6 arguments: "
        "init_state_frame(state, memory, policy, func, "
        "param_addrs, return_addr"
        "[, func_resolver[, global_resolver]])");
    return nullptr;
  }

  PyObject *state_obj   = PyTuple_GetItem(args, 0);
  PyObject *memory_obj  = PyTuple_GetItem(args, 1);
  PyObject *py_policy   = PyTuple_GetItem(args, 2);
  PyObject *func_obj    = PyTuple_GetItem(args, 3);
  PyObject *param_addrs = PyTuple_GetItem(args, 4);
  PyObject *return_addr = PyTuple_GetItem(args, 5);
  PyObject *func_resolver =
      (nargs >= 7) ? PyTuple_GetItem(args, 6) : Py_None;
  PyObject *global_resolver =
      (nargs >= 8) ? PyTuple_GetItem(args, 7) : Py_None;
  PyObject *func_addr_resolver =
      (nargs >= 9) ? PyTuple_GetItem(args, 8) : Py_None;

  if (Py_TYPE(memory_obj) != &ConcreteMemoryType) {
    PyErr_SetString(PyExc_TypeError,
        "Second argument must be ConcreteMemory");
    return nullptr;
  }

  return SymbolicInitStateFrame(state_obj, memory_obj, py_policy, func_obj,
                                param_addrs, return_addr,
                                func_resolver, global_resolver,
                                func_addr_resolver);
}

// init_state_at: mid-block entry for under-constrained symbolic execution.
// init_state_at(state, memory, py_policy, func, block, param_addrs,
//               return_addr, value_seed
//               [, func_resolver[, global_resolver]])
//
// `value_seed` is a dict {eid_int: value} that pre-populates the chosen
// block's live-in values, bypassing the normal predecessor-driven
// computation.
static PyObject *py_init_state_at(PyObject *, PyObject *args) {
  Py_ssize_t nargs = PyTuple_Size(args);
  if (nargs < 8) {
    PyErr_SetString(PyExc_TypeError,
        "init_state_at requires at least 8 arguments: "
        "init_state_at(state, memory, py_policy, func, block, "
        "param_addrs, return_addr, value_seed"
        "[, func_resolver[, global_resolver]])");
    return nullptr;
  }

  PyObject *state_obj    = PyTuple_GetItem(args, 0);
  PyObject *memory_obj   = PyTuple_GetItem(args, 1);
  PyObject *py_policy    = PyTuple_GetItem(args, 2);
  PyObject *func_obj     = PyTuple_GetItem(args, 3);
  PyObject *block_obj    = PyTuple_GetItem(args, 4);
  PyObject *param_addrs  = PyTuple_GetItem(args, 5);
  PyObject *return_addr  = PyTuple_GetItem(args, 6);
  PyObject *value_seed   = PyTuple_GetItem(args, 7);
  PyObject *func_resolver =
      (nargs >= 9) ? PyTuple_GetItem(args, 8) : Py_None;
  PyObject *global_resolver =
      (nargs >= 10) ? PyTuple_GetItem(args, 9) : Py_None;
  PyObject *func_addr_resolver =
      (nargs >= 11) ? PyTuple_GetItem(args, 10) : Py_None;

  if (Py_TYPE(memory_obj) != &ConcreteMemoryType) {
    PyErr_SetString(PyExc_TypeError,
        "Second argument must be ConcreteMemory");
    return nullptr;
  }

  return SymbolicInitStateAt(state_obj, memory_obj, py_policy, func_obj,
                             block_obj, param_addrs, return_addr,
                             value_seed, func_resolver, global_resolver,
                             func_addr_resolver);
}

// Module methods.
static PyMethodDef InterpreterMethods[] = {
  {"init_state", py_init_state, METH_VARARGS,
   "Initialize interpreter state.\n"
   "  Concrete: init_state(state, policy, func[, args])\n"
   "  Symbolic: init_state(state, memory, py_policy, func"
   "[, args[, func_resolver[, global_resolver]]])"},
  {"init_state_frame", py_init_state_frame, METH_VARARGS,
   "Initialize interpreter state with pre-allocated addresses.\n"
   "  init_state_frame(state, memory, policy, func, "
   "param_addrs, return_addr"
   "[, func_resolver[, global_resolver]])"},
  {"init_state_at", py_init_state_at, METH_VARARGS,
   "Initialize interpreter state for mid-block (under-constrained) "
   "entry.\n"
   "  init_state_at(state, memory, py_policy, func, block, "
   "param_addrs, return_addr, value_seed"
   "[, func_resolver[, global_resolver]])"},
  {"step", py_step, METH_VARARGS,
   "Execute interpreter steps.  Returns dict with 'result' and 'forks'.\n"
   "  Concrete: step(state, policy[, max_steps])\n"
   "  Symbolic: step(state, memory, py_policy"
   "[, max_steps[, func_resolver[, global_resolver]]])"},
  {"clone_state", py_clone_state, METH_VARARGS,
   "clone_state(state) -> state (deep copy for forking)"},
  {"resume_addr", py_resume_addr, METH_VARARGS,
   "resume_addr(state, address_eid, concrete_addr)\n"
   "  Specialize a memory-address suspension by binding the address "
   "operand to the chosen concrete pointer."},
  {"resume_addr_symbolic", py_resume_addr_symbolic, METH_VARARGS,
   "resume_addr_symbolic(state, address_eid, py_value)\n"
   "  Symbolic-address sibling of resume_addr: writes an arbitrary "
   "Python value (typically a z3 expression) into the suspended op's "
   "address-operand cache slot."},
  {"get_value_at", py_get_value_at, METH_VARARGS,
   "get_value_at(state, eid) -> Python value\n"
   "  Read the cached value at an operand entity-id from the live "
   "call frame; None if not populated."},
  {nullptr}
};

}  // namespace

}  // namespace mx

namespace mx::ir::interpret {

template <>
::PyTypeObject &Sharable<mx::ConcreteState, PyObjectRC>::PyType(void) noexcept {
  return mx::ConcreteStatePyType;
}

}  // namespace mx::ir::interpret

namespace mx {

PyObject *MakeSymbolicStateWrapper(
    ir::interpret::ref_t<SymbolicState> state) {
  auto *wrapper = PyObject_New(InterpreterStateWrapper, &InterpreterStateType);
  if (!wrapper) return nullptr;
  wrapper->state = nullptr;
  wrapper->symbolic_state = state.release();
  return reinterpret_cast<PyObject *>(wrapper);
}

// ===========================================================================
// Module loader (called from Module.cpp)
// ===========================================================================

bool LoadInterpreterModule(BorrowedPyObject *ir_module) {
  static PyModuleDef interpModuleDef = {
    PyModuleDef_HEAD_INIT,
    "interpret",
    "IR interpreter bindings",
    -1,
    InterpreterMethods,
  };

  PyObject *interp_module = PyModule_Create(&interpModuleDef);
  if (!interp_module) return false;

  // InterpreterState
  InterpreterStateType = {PyVarObject_HEAD_INIT(nullptr, 0)};
  InterpreterStateType.tp_name = "multiplier.ir.interpret.InterpreterState";
  InterpreterStateType.tp_basicsize = sizeof(InterpreterStateWrapper);
  InterpreterStateType.tp_dealloc =
      (destructor)InterpreterStateWrapper_dealloc;
  InterpreterStateType.tp_flags = Py_TPFLAGS_DEFAULT;
  InterpreterStateType.tp_doc = "Interpreter state (call stack, globals)";
  InterpreterStateType.tp_getset = InterpreterStateWrapper_getset;
  InterpreterStateType.tp_init = (initproc)InterpreterStateWrapper_init;
  InterpreterStateType.tp_alloc = PyType_GenericAlloc;
  InterpreterStateType.tp_new = PyType_GenericNew;
  if (PyType_Ready(&InterpreterStateType) < 0) return false;
  Py_INCREF(&InterpreterStateType);
  PyModule_AddObject(interp_module, "InterpreterState",
                     reinterpret_cast<PyObject *>(&InterpreterStateType));

  // ConcreteMemory
  ConcreteMemoryType = {PyVarObject_HEAD_INIT(nullptr, 0)};
  ConcreteMemoryType.tp_name = "multiplier.ir.interpret.ConcreteMemory";
  ConcreteMemoryType.tp_basicsize = sizeof(ConcreteMemoryWrapper);
  ConcreteMemoryType.tp_dealloc = (destructor)ConcreteMemoryWrapper_dealloc;
  ConcreteMemoryType.tp_flags = Py_TPFLAGS_DEFAULT;
  ConcreteMemoryType.tp_doc = "Concrete bump-allocator memory";
  ConcreteMemoryType.tp_methods = ConcreteMemoryWrapper_methods;
  ConcreteMemoryType.tp_init = (initproc)ConcreteMemoryWrapper_init;
  ConcreteMemoryType.tp_alloc = PyType_GenericAlloc;
  ConcreteMemoryType.tp_new = PyType_GenericNew;
  if (PyType_Ready(&ConcreteMemoryType) < 0) return false;
  Py_INCREF(&ConcreteMemoryType);
  PyModule_AddObject(interp_module, "ConcreteMemory",
                     reinterpret_cast<PyObject *>(&ConcreteMemoryType));

  // ConcretePolicy
  ConcretePolicyType = {PyVarObject_HEAD_INIT(nullptr, 0)};
  ConcretePolicyType.tp_name = "multiplier.ir.interpret.ConcretePolicy";
  ConcretePolicyType.tp_basicsize = sizeof(ConcretePolicyWrapper);
  ConcretePolicyType.tp_dealloc = (destructor)ConcretePolicyWrapper_dealloc;
  ConcretePolicyType.tp_flags = Py_TPFLAGS_DEFAULT;
  ConcretePolicyType.tp_doc =
      "Concrete interpreter policy (value ops + resolution)";
  ConcretePolicyType.tp_init = (initproc)ConcretePolicyWrapper_init;
  ConcretePolicyType.tp_alloc = PyType_GenericAlloc;
  ConcretePolicyType.tp_new = PyType_GenericNew;
  if (PyType_Ready(&ConcretePolicyType) < 0) return false;
  Py_INCREF(&ConcretePolicyType);
  PyModule_AddObject(interp_module, "ConcretePolicy",
                     reinterpret_cast<PyObject *>(&ConcretePolicyType));

  // ConcreteState (private — backs PyObjectRC concrete interpreter state).
  ConcreteStatePyType = {PyVarObject_HEAD_INIT(nullptr, 0)};
  ConcreteStatePyType.tp_name =
      "multiplier.ir.interpret._ConcreteState";
  ConcreteStatePyType.tp_basicsize =
      sizeof(ir::interpret::PyWrapperFor<ConcreteState>);
  ConcreteStatePyType.tp_dealloc = ConcreteStatePyType_dealloc;
  ConcreteStatePyType.tp_flags = Py_TPFLAGS_DEFAULT;
  ConcreteStatePyType.tp_doc =
      "Internal concrete interpreter state (PyObjectRC payload)";
  if (PyType_Ready(&ConcreteStatePyType) < 0) return false;
  Py_INCREF(&ConcreteStatePyType);
  PyModule_AddObject(interp_module, "_ConcreteState",
                     reinterpret_cast<PyObject *>(&ConcreteStatePyType));

  // SymbolicState (private — backs PyObjectRC interpreter state).
  if (!LoadSymbolicStateType(interp_module)) return false;

  // Add interpret submodule to ir module.
  if (PyModule_AddObject(ir_module, "interpret", interp_module) < 0) {
    Py_DECREF(interp_module);
    return false;
  }

  return true;
}

#pragma GCC diagnostic pop
}  // namespace mx
