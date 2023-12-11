// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/Builtin/Attribute.h>

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
using T = mx::ir::builtin::Attribute;

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
  if (tp < &(gTypes[836]) || tp >= &(gTypes[859])) {
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

    case mx::ir::builtin::TypedAttr::static_kind():
      tp = &(gTypes[837]);
      break;

    case mx::ir::builtin::ElementsAttr::static_kind():
      tp = &(gTypes[838]);
      break;

    case mx::ir::builtin::AffineMapAttr::static_kind():
      tp = &(gTypes[839]);
      break;

    case mx::ir::builtin::ArrayAttr::static_kind():
      tp = &(gTypes[840]);
      break;

    case mx::ir::builtin::DenseArrayAttr::static_kind():
      tp = &(gTypes[841]);
      break;

    case mx::ir::builtin::DenseIntOrFPElementsAttr::static_kind():
      tp = &(gTypes[842]);
      break;

    case mx::ir::builtin::DenseResourceElementsAttr::static_kind():
      tp = &(gTypes[843]);
      break;

    case mx::ir::builtin::DenseStringElementsAttr::static_kind():
      tp = &(gTypes[844]);
      break;

    case mx::ir::builtin::DictionaryAttr::static_kind():
      tp = &(gTypes[845]);
      break;

    case mx::ir::builtin::FloatAttr::static_kind():
      tp = &(gTypes[846]);
      break;

    case mx::ir::builtin::IntegerAttr::static_kind():
      tp = &(gTypes[847]);
      break;

    case mx::ir::builtin::IntegerSetAttr::static_kind():
      tp = &(gTypes[848]);
      break;

    case mx::ir::builtin::OpaqueAttr::static_kind():
      tp = &(gTypes[849]);
      break;

    case mx::ir::builtin::SparseElementsAttr::static_kind():
      tp = &(gTypes[850]);
      break;

    case mx::ir::builtin::StringAttr::static_kind():
      tp = &(gTypes[851]);
      break;

    case mx::ir::builtin::SymbolRefAttr::static_kind():
      tp = &(gTypes[852]);
      break;

    case mx::ir::builtin::TypeAttr::static_kind():
      tp = &(gTypes[853]);
      break;

    case mx::ir::builtin::UnitAttr::static_kind():
      tp = &(gTypes[854]);
      break;

    case mx::ir::builtin::StridedLayoutAttr::static_kind():
      tp = &(gTypes[855]);
      break;

    case mx::ir::builtin::BoolAttr::static_kind():
      tp = &(gTypes[856]);
      break;

    case mx::ir::builtin::FlatSymbolRefAttr::static_kind():
      tp = &(gTypes[857]);
      break;

    case mx::ir::builtin::DenseIntElementsAttr::static_kind():
      tp = &(gTypes[858]);
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
    PyDoc_STR("Wrapper for mx::ir::builtin::Attribute::from"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[836]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ir.builtin.Attribute";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::ir::builtin::::Attribute");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = gTypes[835].tp_hash;
  tp->tp_richcompare = gTypes[835].tp_richcompare;
  tp->tp_iter = nullptr;
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = &(gTypes[835]);
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
