// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/HighLevel/Attribute.h>

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
using T = mx::ir::hl::Attribute;

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
  if (tp < &(gTypes[938]) || tp >= &(gTypes[984])) {
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

    case mx::ir::hl::AnnotationAttr::static_kind():
      tp = &(gTypes[939]);
      break;

    case mx::ir::hl::FormatAttr::static_kind():
      tp = &(gTypes[940]);
      break;

    case mx::ir::hl::SectionAttr::static_kind():
      tp = &(gTypes[941]);
      break;

    case mx::ir::hl::AliasAttr::static_kind():
      tp = &(gTypes[942]);
      break;

    case mx::ir::hl::ErrorAttr::static_kind():
      tp = &(gTypes[943]);
      break;

    case mx::ir::hl::CountedByAttr::static_kind():
      tp = &(gTypes[944]);
      break;

    case mx::ir::hl::CleanupAttr::static_kind():
      tp = &(gTypes[945]);
      break;

    case mx::ir::hl::AlignedAttr::static_kind():
      tp = &(gTypes[946]);
      break;

    case mx::ir::hl::AlwaysInlineAttr::static_kind():
      tp = &(gTypes[947]);
      break;

    case mx::ir::hl::NoInlineAttr::static_kind():
      tp = &(gTypes[948]);
      break;

    case mx::ir::hl::ConstAttr::static_kind():
      tp = &(gTypes[949]);
      break;

    case mx::ir::hl::LoaderUninitializedAttr::static_kind():
      tp = &(gTypes[950]);
      break;

    case mx::ir::hl::NoInstrumentFunctionAttr::static_kind():
      tp = &(gTypes[951]);
      break;

    case mx::ir::hl::PackedAttr::static_kind():
      tp = &(gTypes[952]);
      break;

    case mx::ir::hl::PureAttr::static_kind():
      tp = &(gTypes[953]);
      break;

    case mx::ir::hl::WarnUnusedResultAttr::static_kind():
      tp = &(gTypes[954]);
      break;

    case mx::ir::hl::RestrictAttr::static_kind():
      tp = &(gTypes[955]);
      break;

    case mx::ir::hl::NoThrowAttr::static_kind():
      tp = &(gTypes[956]);
      break;

    case mx::ir::hl::NonNullAttr::static_kind():
      tp = &(gTypes[957]);
      break;

    case mx::ir::hl::LeafAttr::static_kind():
      tp = &(gTypes[958]);
      break;

    case mx::ir::hl::ColdAttr::static_kind():
      tp = &(gTypes[959]);
      break;

    case mx::ir::hl::TransparentUnionAttr::static_kind():
      tp = &(gTypes[960]);
      break;

    case mx::ir::hl::ReturnsTwiceAttr::static_kind():
      tp = &(gTypes[961]);
      break;

    case mx::ir::hl::MayAliasAttr::static_kind():
      tp = &(gTypes[962]);
      break;

    case mx::ir::hl::UnusedAttr::static_kind():
      tp = &(gTypes[963]);
      break;

    case mx::ir::hl::UsedAttr::static_kind():
      tp = &(gTypes[964]);
      break;

    case mx::ir::hl::GNUInlineAttr::static_kind():
      tp = &(gTypes[965]);
      break;

    case mx::ir::hl::NoCfCheckAttr::static_kind():
      tp = &(gTypes[966]);
      break;

    case mx::ir::hl::AvailableOnlyInDefaultEvalMethodAttr::static_kind():
      tp = &(gTypes[967]);
      break;

    case mx::ir::hl::AvailabilityAttrAttr::static_kind():
      tp = &(gTypes[968]);
      break;

    case mx::ir::hl::FallthroughAttr::static_kind():
      tp = &(gTypes[969]);
      break;

    case mx::ir::hl::NoProfileInstrumentFunctionAttr::static_kind():
      tp = &(gTypes[970]);
      break;

    case mx::ir::hl::AsmLabelAttr::static_kind():
      tp = &(gTypes[971]);
      break;

    case mx::ir::hl::ModeAttr::static_kind():
      tp = &(gTypes[972]);
      break;

    case mx::ir::hl::BuiltinAttr::static_kind():
      tp = &(gTypes[973]);
      break;

    case mx::ir::hl::AllocAlignAttr::static_kind():
      tp = &(gTypes[974]);
      break;

    case mx::ir::hl::AllocSizeAttr::static_kind():
      tp = &(gTypes[975]);
      break;

    case mx::ir::hl::DeprecatedAttr::static_kind():
      tp = &(gTypes[976]);
      break;

    case mx::ir::hl::MaxFieldAlignmentAttr::static_kind():
      tp = &(gTypes[977]);
      break;

    case mx::ir::hl::VisibilityAttr::static_kind():
      tp = &(gTypes[978]);
      break;

    case mx::ir::hl::AssumeAlignedAttr::static_kind():
      tp = &(gTypes[979]);
      break;

    case mx::ir::hl::CVQualifiersAttr::static_kind():
      tp = &(gTypes[980]);
      break;

    case mx::ir::hl::UCVQualifiersAttr::static_kind():
      tp = &(gTypes[981]);
      break;

    case mx::ir::hl::CVRQualifiersAttr::static_kind():
      tp = &(gTypes[982]);
      break;

    case mx::ir::hl::OffsetOfNodeAttr::static_kind():
      tp = &(gTypes[983]);
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
  if (0 != PyModule_AddObjectRef(module, "Attribute", tp_obj)) {
    return false;
  }

  return true;
}

namespace {
static PyGetSetDef gProperties[] = {
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyMethodDef gMethods[] = {
  {
    "FROM",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::ir::Attribute>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'FROM'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::ir::hl::Attribute::from"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[938]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ir.highlevel.Attribute";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::ir::hl::::Attribute");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = gTypes[867].tp_hash;
  tp->tp_richcompare = gTypes[867].tp_richcompare;
  tp->tp_iter = nullptr;
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = &(gTypes[867]);
  tp->tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args, BorrowedPyObject *kwargs) -> int {
    if (kwargs && (!PyMapping_Check(kwargs) || PyMapping_Size(kwargs))) {
      PyErrorStreamer(PyExc_TypeError)
          << "'Attribute.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'Attribute.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    (void) obj;
    (void) num_args;
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'Attribute' cannot be directly instantiated";
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
