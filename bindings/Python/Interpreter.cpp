// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Hand-written Python bindings for the IR interpreter.
// Exposes ConcretePolicy-based interpretation via init_state/step and
// the Continuation/Scheduler model.

#include <multiplier/IR/Interpret/Interpreter.h>
#include <multiplier/IR/Interpret/ConcretePolicy.h>
#include <multiplier/IR/Interpret/ConcreteMemory.h>
#include <multiplier/IR/Interpret/Value.h>
#include <multiplier/IR/Interpret/Suspension.h>
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

static PyObject *gUndefSentinel = nullptr;

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
  if (gUndefSentinel) {
    Py_INCREF(gUndefSentinel);
    return gUndefSentinel;
  }
  Py_RETURN_NONE;
}

Value python_to_value(PyObject *obj) {
  if (obj == nullptr || obj == Py_None) {
    return NullPtr{};
  }
  if (gUndefSentinel && obj == gUndefSentinel) {
    return Undefined{};
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

struct InterpreterStateWrapper {
  PyObject_HEAD
  InterpreterState<Value> *state;
};

// Forward declarations.
static PyTypeObject ConcreteMemoryType;
static PyTypeObject ConcretePolicyType;
static PyTypeObject InterpreterStateType;

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
  delete self->state;
  Py_TYPE(self)->tp_free(reinterpret_cast<PyObject *>(self));
}

static int InterpreterStateWrapper_init(
    InterpreterStateWrapper *self, PyObject *, PyObject *) {
  self->state = new InterpreterState<Value>();
  return 0;
}

static PyObject *InterpreterStateWrapper_get_steps(
    InterpreterStateWrapper *self, void *) {
  return PyLong_FromUnsignedLongLong(self->state->steps);
}

static PyObject *InterpreterStateWrapper_get_empty(
    InterpreterStateWrapper *self, void *) {
  return PyBool_FromLong(self->state->call_stack.empty());
}

static PyObject *InterpreterStateWrapper_get_depth(
    InterpreterStateWrapper *self, void *) {
  return PyLong_FromSize_t(self->state->call_stack.depth());
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

    pw->policy->init_state(*sw->state, *func, c_args);
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
    return SymbolicInitState(state_obj, second, py_policy, func_obj,
                             args_list, func_resolver, global_resolver);
  }

  PyErr_SetString(PyExc_TypeError,
      "Second argument must be ConcretePolicy or ConcreteMemory");
  return nullptr;
}

static PyObject *build_result_dict(const Continuation &cont) {
  PyObject *result_dict = PyDict_New();
  if (!result_dict) return nullptr;

  PyObject *result_tuple;
  if (cont.is_terminal()) {
    if (cont.kind() == Continuation::COMPLETED) {
      PyObject *py_val = value_to_python(cont.return_value());
      result_tuple = Py_BuildValue("(sN)", "completed", py_val);
    } else {
      result_tuple = Py_BuildValue("(si)", "error",
                                   static_cast<int>(cont.error()));
    }
  } else {
    result_tuple = Py_BuildValue("(si)", "suspended",
                                 static_cast<int>(cont.kind()));
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

    NoOpScheduler sched;
    bool budget_hit = pw->policy->step(*sw->state, sched, max_steps);

    if (sched.result.has_value()) {
      return build_result_dict(sched.result.value());
    }

    if (budget_hit) {
      PyObject *result_dict = PyDict_New();
      if (!result_dict) return nullptr;
      PyObject *budget_tuple = Py_BuildValue(
          "(sK)", "budget", sw->state->steps);
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
    return SymbolicStep(state_obj, second, py_policy, max_steps,
                        func_resolver, global_resolver);
  }

  PyErr_SetString(PyExc_TypeError,
      "Second argument must be ConcretePolicy or ConcreteMemory");
  return nullptr;
}

// Module methods.
static PyMethodDef InterpreterMethods[] = {
  {"init_state", py_init_state, METH_VARARGS,
   "Initialize interpreter state.\n"
   "  Concrete: init_state(state, policy, func[, args])\n"
   "  Symbolic: init_state(state, memory, py_policy, func"
   "[, args[, func_resolver[, global_resolver]]])"},
  {"step", py_step, METH_VARARGS,
   "Execute interpreter steps.  Returns dict with 'result' and 'forks'.\n"
   "  Concrete: step(state, policy[, max_steps])\n"
   "  Symbolic: step(state, memory, py_policy"
   "[, max_steps[, func_resolver[, global_resolver]]])"},
  {nullptr}
};

}  // namespace

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

  // Create the Undefined sentinel.
  gUndefSentinel = PyObject_CallObject(
      reinterpret_cast<PyObject *>(&PyBaseObject_Type), nullptr);
  if (!gUndefSentinel) return false;
  PyModule_AddObject(interp_module, "UNDEFINED", gUndefSentinel);
  Py_INCREF(gUndefSentinel);

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

  // Continuation kind constants.
  PyModule_AddIntConstant(interp_module, "CONT_BRANCH",
                          static_cast<int>(Continuation::BRANCH));
  PyModule_AddIntConstant(interp_module, "CONT_CALL",
                          static_cast<int>(Continuation::CALL));
  PyModule_AddIntConstant(interp_module, "CONT_GLOBAL",
                          static_cast<int>(Continuation::GLOBAL));
  PyModule_AddIntConstant(interp_module, "CONT_COMPLETED",
                          static_cast<int>(Continuation::COMPLETED));
  PyModule_AddIntConstant(interp_module, "CONT_ERRORED",
                          static_cast<int>(Continuation::ERRORED));

  // Add interpret submodule to ir module.
  if (PyModule_AddObject(ir_module, "interpret", interp_module) < 0) {
    Py_DECREF(interp_module);
    return false;
  }

  return true;
}

#pragma GCC diagnostic pop
}  // namespace mx
