// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!
// Exception: to_python is manually patched to dispatch to the most-derived
// IR instruction subtype (the generator only knows the val.kind()/static_kind()
// AST pattern; IRInstruction uses opcode-based from() dispatch instead).
// Re-apply this patch if the generator is ever rerun.

#include <multiplier/IR/Instruction.h>
#include <multiplier/IR/InstructionKinds.h>

#include <multiplier/AST.h>
#include <multiplier/Fragment.h>
#include <multiplier/Frontend.h>
#include <multiplier/Index.h>
#include <multiplier/Re2.h>

#include <cassert>
#include <new>

#include "Binding.h"
#include "Error.h"
#include "Types.h"


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc99-extensions"
#pragma GCC diagnostic ignored "-Wunused-function"
namespace {
using T = mx::IRInstruction;

struct O final : public ::PyObject {

  // When initialized, points to `backing_storage`.
  T *data{nullptr};

  // Aligned storage for `T`. Pointed to by `data`.
  alignas(alignof(T)) char backing_storage[sizeof(T)];  
};

inline static O *O_cast(void *obj) noexcept {
  return reinterpret_cast<O *>(obj);
}

inline static const O *O_cast(const void *obj) noexcept {
  return reinterpret_cast<const O *>(obj);
}

inline static T *T_cast(void *obj) noexcept {
  return O_cast(obj)->data;
}

inline static const T *T_cast(const void *obj) noexcept {
  return O_cast(obj)->data;
}

}  // namespace
namespace mx {

namespace {
static PyTypeObject *gType = nullptr;
}  // namespace

template <>
PyTypeObject *PythonBinding<T>::type(void) noexcept {
  return gType;
}

template <>
std::optional<T> PythonBinding<T>::from_python(BorrowedPyObject *obj) noexcept {
  if (!obj) {
    return std::nullopt;
  }

  PyTypeObject * const tp = Py_TYPE(obj);
  if (tp < &(gTypes[3]) || tp >= &(gTypes[44])) {
    return std::nullopt;
  }

  return *T_cast(obj);
}

template <>
SharedPyObject *PythonBinding<T>::to_python(T val) noexcept {
  using _op = ir::OpCode;
  const auto op = val.opcode();
  PyTypeObject *tp;

  if (op == _op::CONST) {
    tp = &(gTypes[4]);
  } else if (op == _op::ALLOCA) {
    if      (LocalAllocaInst::from(val))   tp = &(gTypes[6]);
    else if (ArgAllocaInst::from(val))     tp = &(gTypes[7]);
    else if (ReturnAllocaInst::from(val))  tp = &(gTypes[8]);
    else if (DynamicAllocaInst::from(val)) tp = &(gTypes[9]);
    else                                    tp = &(gTypes[5]);
  } else if (op == _op::MEMORY) {
    tp = ConsumeVAParamInst::from(val) ? &(gTypes[37]) : &(gTypes[10]);
  } else if (op == _op::PTR_DIFF_32 || op == _op::PTR_DIFF_64) {
    tp = &(gTypes[13]);
  } else if (op >= _op::BITWISE_8 && op <= _op::BITWISE_64) {
    tp = &(gTypes[27]);
  } else if (op >= _op::ABS_8 && op <= _op::ABS_64) {
    tp = &(gTypes[16]);
  } else if (op == _op::LOGICAL_AND || op == _op::LOGICAL_OR) {
    tp = &(gTypes[14]);
  } else if (op == _op::LOGICAL_NOT) {
    tp = &(gTypes[16]);
  } else if (op == _op::CAST) {
    tp = &(gTypes[17]);
  } else if (op == _op::CALL) {
    tp = &(gTypes[18]);
  } else if (op == _op::READ_MODIFY_WRITE) {
    tp = &(gTypes[19]);
  } else if (op == _op::LAST_VALUE) {
    tp = &(gTypes[20]);
  } else if (op == _op::SELECT) {
    tp = &(gTypes[21]);
  } else if (op == _op::PARAM_PTR_32 || op == _op::PARAM_PTR_64) {
    tp = &(gTypes[22]);
  } else if (op == _op::GLOBAL_PTR_32 || op == _op::GLOBAL_PTR_64) {
    tp = &(gTypes[23]);
  } else if (op == _op::THREAD_LOCAL_PTR_32 || op == _op::THREAD_LOCAL_PTR_64) {
    tp = &(gTypes[24]);
  } else if (op == _op::FUNC_PTR_32 || op == _op::FUNC_PTR_64) {
    tp = &(gTypes[25]);
  } else if (op == _op::RETURN_PTR_32 || op == _op::RETURN_PTR_64) {
    tp = &(gTypes[26]);
  } else if (op == _op::FLOAT) {
    tp = &(gTypes[28]);
  } else if (op == _op::FRAME_PTR_32 || op == _op::FRAME_PTR_64) {
    tp = &(gTypes[29]);
  } else if (op == _op::RETURN_ADDRESS_32 || op == _op::RETURN_ADDRESS_64) {
    tp = &(gTypes[30]);
  } else if (op == _op::UNDEFINED) {
    tp = &(gTypes[31]);
  } else if (op == _op::ENTER_SCOPE) {
    tp = &(gTypes[32]);
  } else if (op == _op::EXIT_SCOPE) {
    tp = &(gTypes[33]);
  } else if (op == _op::VA_START) {
    tp = &(gTypes[34]);
  } else if (op == _op::VA_END) {
    tp = &(gTypes[35]);
  } else if (op == _op::VA_COPY) {
    tp = &(gTypes[36]);
  } else if (op == _op::RET) {
    tp = &(gTypes[38]);
  } else if (op == _op::GOTO || op == _op::IMPLICIT_GOTO ||
             op == _op::BREAK || op == _op::CONTINUE ||
             op == _op::FALLTHROUGH || op == _op::IMPLICIT_FALLTHROUGH) {
    tp = &(gTypes[39]);
  } else if (op == _op::COND_BRANCH) {
    tp = &(gTypes[40]);
  } else if (op == _op::SWITCH) {
    tp = &(gTypes[41]);
  } else if (op == _op::UNREACHABLE || op == _op::IMPLICIT_UNREACHABLE) {
    tp = &(gTypes[42]);
  } else if (op == _op::UNKNOWN) {
    tp = &(gTypes[43]);
  } else if (op == _op::PTR_ADD_32 || op == _op::PTR_ADD_64) {
    tp = &(gTypes[12]);
  } else if (op == _op::GEP_FIELD_32 || op == _op::GEP_FIELD_64) {
    tp = &(gTypes[11]);
  } else if ((op >= _op::FCMP_EQ_32 && op <= _op::FCMP_GE_64) ||
             (op >= _op::CMP_EQ_8  && op <= _op::UCMP_GE_64)) {
    tp = &(gTypes[15]);
  } else if ((op >= _op::FADD_32 && op <= _op::FREM_64) ||
             (op >= _op::ADD_8   && op <= _op::SHR_64)) {
    tp = &(gTypes[14]);
  } else if (op == _op::FNEG_32 || op == _op::FNEG_64 ||
             (op >= _op::NEG_8 && op <= _op::BIT_NOT_64)) {
    tp = &(gTypes[16]);
  } else {
    tp = gType;
  }

  auto ret = tp->tp_alloc(tp, 0);
  if (auto obj = O_cast(ret)) {
    obj->data = new (obj->backing_storage) T(std::move(val));
  }
  return ret;
}

namespace {
static PyTypeObject *InitType(void) noexcept;
}  // namespace

template <>
bool PythonBinding<T>::load(BorrowedPyObject *module) noexcept {
  if (!gType) {
    gType = InitType();
    if (!gType) {
      return false;
    }
  }

  auto tp_obj = reinterpret_cast<BorrowedPyObject *>(gType);
  if (0 != PyModule_AddObjectRef(module, "IRInstruction", tp_obj)) {
    return false;
  }

  return true;
}

namespace {
static PyGetSetDef gProperties[] = {
  {
    "id",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->id());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::IRInstruction::id"),
    nullptr,
  },
  {
    "opcode",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->opcode());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::IRInstruction::opcode"),
    nullptr,
  },
  {
    "operands",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::generator_to_python(*T_cast(self), &T::operands);
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::IRInstruction::operands"),
    nullptr,
  },
  {
    "num_operands",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_operands());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::IRInstruction::num_operands"),
    nullptr,
  },
  {
    "parent_instruction",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->parent_instruction());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::IRInstruction::parent_instruction"),
    nullptr,
  },
  {
    "is_root",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_root());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::IRInstruction::is_root"),
    nullptr,
  },
  {
    "users",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::generator_to_python(*T_cast(self), &T::users);
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::IRInstruction::users"),
    nullptr,
  },
  {
    "num_users",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_users());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::IRInstruction::num_users"),
    nullptr,
  },
  {
    "source_statement",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->source_statement());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::IRInstruction::source_statement"),
    nullptr,
  },
  {
    "source_entity_id",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->source_entity_id());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::IRInstruction::source_entity_id"),
    nullptr,
  },
  {
    "parent_block",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->parent_block());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::IRInstruction::parent_block"),
    nullptr,
  },
  {
    "is_terminator",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_terminator());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::IRInstruction::is_terminator"),
    nullptr,
  },
  {
    "is_conditionally_executed",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_conditionally_executed());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::IRInstruction::is_conditionally_executed"),
    nullptr,
  },
  {
    "name",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->name());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::IRInstruction::name"),
    nullptr,
  },
  {
    "ref_string",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ref_string());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::IRInstruction::ref_string"),
    nullptr,
  },
  {
    "to_string",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->to_string());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::IRInstruction::to_string"),
    nullptr,
  },
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyMethodDef gMethods[] = {
  {
    "nth_operand",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          T *obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<uint32_t>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nth_operand(std::move(arg_0.value())));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nth_operand'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::IRInstruction::nth_operand"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[3]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ir.IRInstruction";
  tp->tp_flags = Py_TPFLAGS_DEFAULT;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::::IRInstruction");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = [] (BorrowedPyObject *obj) -> Py_hash_t {
    return static_cast<Py_hash_t>(EntityId(T_cast(obj)->id()).Pack());
  };
  tp->tp_richcompare = nullptr;
  tp->tp_iter = nullptr;
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = PythonBinding<VariantEntity>::type();
  tp->tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args, BorrowedPyObject *kwargs) -> int {
    if (kwargs && (!PyMapping_Check(kwargs) || PyMapping_Size(kwargs))) {
      PyErrorStreamer(PyExc_TypeError)
          << "'IRInstruction.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'IRInstruction.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    while (num_args == 0) {
      obj->data = new (obj->backing_storage) IRInstruction();
      return 0;
    }

    PyErrorStreamer(PyExc_TypeError)
        << "Invalid arguments to 'IRInstruction.__init__'";
    return -1;

  };
  tp->tp_alloc = PyType_GenericAlloc;
  tp->tp_new = PyType_GenericNew;

  if (0 != PyType_Ready(tp)) {
    return nullptr;
  }

  return tp;
}

}  // namespace

#pragma GCC diagnostic pop
}  // namespace mx
