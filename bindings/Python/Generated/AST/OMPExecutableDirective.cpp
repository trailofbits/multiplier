// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OMPExecutableDirective.h>

#include <multiplier/AST.h>
#include <multiplier/Fragment.h>
#include <multiplier/Frontend.h>
#include <multiplier/Index.h>
#include <multiplier/IR.h>
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
using T = mx::OMPExecutableDirective;

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
  if (tp < &(gTypes[461]) || tp >= &(gTypes[536])) {
    return std::nullopt;
  }

  return *T_cast(obj);
}

template <>
SharedPyObject *PythonBinding<T>::to_python(T val) noexcept {
  PyTypeObject *tp = nullptr;
  switch (val.kind()) {
    default:
      assert(false);
      tp = gType;
      break;

    case mx::OMPErrorDirective::static_kind():
      tp = &(gTypes[462]);
      break;

    case mx::OMPDispatchDirective::static_kind():
      tp = &(gTypes[463]);
      break;

    case mx::OMPDepobjDirective::static_kind():
      tp = &(gTypes[464]);
      break;

    case mx::OMPCriticalDirective::static_kind():
      tp = &(gTypes[465]);
      break;

    case mx::OMPCancellationPointDirective::static_kind():
      tp = &(gTypes[466]);
      break;

    case mx::OMPCancelDirective::static_kind():
      tp = &(gTypes[467]);
      break;

    case mx::OMPBarrierDirective::static_kind():
      tp = &(gTypes[468]);
      break;

    case mx::OMPAtomicDirective::static_kind():
      tp = &(gTypes[469]);
      break;

    case mx::OMPTeamsDirective::static_kind():
      tp = &(gTypes[470]);
      break;

    case mx::OMPTaskyieldDirective::static_kind():
      tp = &(gTypes[471]);
      break;

    case mx::OMPTaskwaitDirective::static_kind():
      tp = &(gTypes[472]);
      break;

    case mx::OMPTaskgroupDirective::static_kind():
      tp = &(gTypes[473]);
      break;

    case mx::OMPTaskDirective::static_kind():
      tp = &(gTypes[474]);
      break;

    case mx::OMPTargetUpdateDirective::static_kind():
      tp = &(gTypes[475]);
      break;

    case mx::OMPTargetTeamsDirective::static_kind():
      tp = &(gTypes[476]);
      break;

    case mx::OMPTargetParallelDirective::static_kind():
      tp = &(gTypes[477]);
      break;

    case mx::OMPTargetExitDataDirective::static_kind():
      tp = &(gTypes[478]);
      break;

    case mx::OMPTargetEnterDataDirective::static_kind():
      tp = &(gTypes[479]);
      break;

    case mx::OMPTargetDirective::static_kind():
      tp = &(gTypes[480]);
      break;

    case mx::OMPTargetDataDirective::static_kind():
      tp = &(gTypes[481]);
      break;

    case mx::OMPSingleDirective::static_kind():
      tp = &(gTypes[482]);
      break;

    case mx::OMPSectionsDirective::static_kind():
      tp = &(gTypes[483]);
      break;

    case mx::OMPSectionDirective::static_kind():
      tp = &(gTypes[484]);
      break;

    case mx::OMPScanDirective::static_kind():
      tp = &(gTypes[485]);
      break;

    case mx::OMPParallelSectionsDirective::static_kind():
      tp = &(gTypes[486]);
      break;

    case mx::OMPParallelMasterDirective::static_kind():
      tp = &(gTypes[487]);
      break;

    case mx::OMPParallelMaskedDirective::static_kind():
      tp = &(gTypes[488]);
      break;

    case mx::OMPParallelDirective::static_kind():
      tp = &(gTypes[489]);
      break;

    case mx::OMPOrderedDirective::static_kind():
      tp = &(gTypes[490]);
      break;

    case mx::OMPMetaDirective::static_kind():
      tp = &(gTypes[491]);
      break;

    case mx::OMPMasterDirective::static_kind():
      tp = &(gTypes[492]);
      break;

    case mx::OMPMaskedDirective::static_kind():
      tp = &(gTypes[493]);
      break;

    case mx::OMPUnrollDirective::static_kind():
      tp = &(gTypes[496]);
      break;

    case mx::OMPTileDirective::static_kind():
      tp = &(gTypes[497]);
      break;

    case mx::OMPGenericLoopDirective::static_kind():
      tp = &(gTypes[499]);
      break;

    case mx::OMPForSimdDirective::static_kind():
      tp = &(gTypes[500]);
      break;

    case mx::OMPForDirective::static_kind():
      tp = &(gTypes[501]);
      break;

    case mx::OMPDistributeSimdDirective::static_kind():
      tp = &(gTypes[502]);
      break;

    case mx::OMPDistributeParallelForSimdDirective::static_kind():
      tp = &(gTypes[503]);
      break;

    case mx::OMPDistributeParallelForDirective::static_kind():
      tp = &(gTypes[504]);
      break;

    case mx::OMPDistributeDirective::static_kind():
      tp = &(gTypes[505]);
      break;

    case mx::OMPTeamsGenericLoopDirective::static_kind():
      tp = &(gTypes[506]);
      break;

    case mx::OMPTeamsDistributeSimdDirective::static_kind():
      tp = &(gTypes[507]);
      break;

    case mx::OMPTeamsDistributeParallelForSimdDirective::static_kind():
      tp = &(gTypes[508]);
      break;

    case mx::OMPTeamsDistributeParallelForDirective::static_kind():
      tp = &(gTypes[509]);
      break;

    case mx::OMPTeamsDistributeDirective::static_kind():
      tp = &(gTypes[510]);
      break;

    case mx::OMPTaskLoopSimdDirective::static_kind():
      tp = &(gTypes[511]);
      break;

    case mx::OMPTaskLoopDirective::static_kind():
      tp = &(gTypes[512]);
      break;

    case mx::OMPTargetTeamsGenericLoopDirective::static_kind():
      tp = &(gTypes[513]);
      break;

    case mx::OMPTargetTeamsDistributeSimdDirective::static_kind():
      tp = &(gTypes[514]);
      break;

    case mx::OMPTargetTeamsDistributeParallelForSimdDirective::static_kind():
      tp = &(gTypes[515]);
      break;

    case mx::OMPTargetTeamsDistributeParallelForDirective::static_kind():
      tp = &(gTypes[516]);
      break;

    case mx::OMPTargetTeamsDistributeDirective::static_kind():
      tp = &(gTypes[517]);
      break;

    case mx::OMPTargetSimdDirective::static_kind():
      tp = &(gTypes[518]);
      break;

    case mx::OMPTargetParallelGenericLoopDirective::static_kind():
      tp = &(gTypes[519]);
      break;

    case mx::OMPTargetParallelForSimdDirective::static_kind():
      tp = &(gTypes[520]);
      break;

    case mx::OMPTargetParallelForDirective::static_kind():
      tp = &(gTypes[521]);
      break;

    case mx::OMPSimdDirective::static_kind():
      tp = &(gTypes[522]);
      break;

    case mx::OMPParallelMasterTaskLoopSimdDirective::static_kind():
      tp = &(gTypes[523]);
      break;

    case mx::OMPParallelMasterTaskLoopDirective::static_kind():
      tp = &(gTypes[524]);
      break;

    case mx::OMPParallelMaskedTaskLoopSimdDirective::static_kind():
      tp = &(gTypes[525]);
      break;

    case mx::OMPParallelMaskedTaskLoopDirective::static_kind():
      tp = &(gTypes[526]);
      break;

    case mx::OMPParallelGenericLoopDirective::static_kind():
      tp = &(gTypes[527]);
      break;

    case mx::OMPParallelForSimdDirective::static_kind():
      tp = &(gTypes[528]);
      break;

    case mx::OMPParallelForDirective::static_kind():
      tp = &(gTypes[529]);
      break;

    case mx::OMPMasterTaskLoopSimdDirective::static_kind():
      tp = &(gTypes[530]);
      break;

    case mx::OMPMasterTaskLoopDirective::static_kind():
      tp = &(gTypes[531]);
      break;

    case mx::OMPMaskedTaskLoopSimdDirective::static_kind():
      tp = &(gTypes[532]);
      break;

    case mx::OMPMaskedTaskLoopDirective::static_kind():
      tp = &(gTypes[533]);
      break;

    case mx::OMPInteropDirective::static_kind():
      tp = &(gTypes[534]);
      break;

    case mx::OMPFlushDirective::static_kind():
      tp = &(gTypes[535]);
      break;

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
  if (0 != PyModule_AddObjectRef(module, "OMPExecutableDirective", tp_obj)) {
    return false;
  }

  return true;
}

namespace {
static PyMethodDef gMethods[] = {
  {
    "IN",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Index>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->in(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Fragment>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->in(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::File>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->in(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'IN'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::OMPExecutableDirective::in"),
  },
  {
    "containing",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Token>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Decl>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<std::optional<mx::Decl>>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Stmt>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<std::optional<mx::Stmt>>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'containing'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::OMPExecutableDirective::containing"),
  },
  {
    "by_id",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 2) {
            auto arg_0 = PythonBinding<mx::Index>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = PythonBinding<mx::EntityId>::from_python(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(obj->by_id(arg_0.value(), arg_1.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'by_id'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::OMPExecutableDirective::by_id"),
  },
  {
    "from_base",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Stmt>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from_base(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'from_base'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::OMPExecutableDirective::from_base"),
  },
  {
    "FROM",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Stmt>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<std::optional<mx::Stmt>>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Reference>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<std::variant<std::monostate, mx::Fragment, mx::Decl, mx::Stmt, mx::Attr, mx::Macro, mx::Type, mx::File, mx::Token, mx::TemplateArgument, mx::TemplateParameterList, mx::CXXBaseSpecifier, mx::Designator, mx::Compilation>>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::TokenContext>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'FROM'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::OMPExecutableDirective::from"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyGetSetDef gProperties[] = {
  {
    "associated_statement",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->associated_statement());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPExecutableDirective::associated_statement"),
    nullptr,
  },
  {
    "innermost_captured_statement",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->innermost_captured_statement());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPExecutableDirective::innermost_captured_statement"),
    nullptr,
  },
  {
    "raw_statement",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->raw_statement());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPExecutableDirective::raw_statement"),
    nullptr,
  },
  {
    "structured_block",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->structured_block());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPExecutableDirective::structured_block"),
    nullptr,
  },
  {
    "has_associated_statement",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_associated_statement());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPExecutableDirective::has_associated_statement"),
    nullptr,
  },
  {
    "is_standalone_directive",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_standalone_directive());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPExecutableDirective::is_standalone_directive"),
    nullptr,
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[461]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ast.OMPExecutableDirective";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::::OMPExecutableDirective");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = gTypes[448].tp_hash;
  tp->tp_richcompare = nullptr;
  tp->tp_iter = nullptr;
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = &(gTypes[448]);
  tp->tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args, BorrowedPyObject *kwargs) -> int {
    if (kwargs && (!PyMapping_Check(kwargs) || PyMapping_Size(kwargs))) {
      PyErrorStreamer(PyExc_TypeError)
          << "'OMPExecutableDirective.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'OMPExecutableDirective.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    (void) obj;
    (void) num_args;
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'OMPExecutableDirective' cannot be directly instantiated";
    return -1;

  };
  tp->tp_alloc = PyType_GenericAlloc;
  tp->tp_new = nullptr;

  if (0 != PyType_Ready(tp)) {
    return nullptr;
  }

  return tp;
}

}  // namespace

#pragma GCC diagnostic pop
}  // namespace mx
