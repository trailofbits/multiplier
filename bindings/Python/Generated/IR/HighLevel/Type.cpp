// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/HighLevel/Type.h>

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
using T = mx::ir::hl::Type;

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
  if (tp < &(gTypes[1471]) || tp >= &(gTypes[1504])) {
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

    case mx::ir::hl::RecordType::static_kind():
      tp = &(gTypes[1472]);
      break;

    case mx::ir::hl::EnumType::static_kind():
      tp = &(gTypes[1473]);
      break;

    case mx::ir::hl::TypedefType::static_kind():
      tp = &(gTypes[1474]);
      break;

    case mx::ir::hl::ElaboratedType::static_kind():
      tp = &(gTypes[1475]);
      break;

    case mx::ir::hl::LabelType::static_kind():
      tp = &(gTypes[1476]);
      break;

    case mx::ir::hl::ParenType::static_kind():
      tp = &(gTypes[1477]);
      break;

    case mx::ir::hl::LValueType::static_kind():
      tp = &(gTypes[1478]);
      break;

    case mx::ir::hl::RValueType::static_kind():
      tp = &(gTypes[1479]);
      break;

    case mx::ir::hl::VoidType::static_kind():
      tp = &(gTypes[1480]);
      break;

    case mx::ir::hl::BoolType::static_kind():
      tp = &(gTypes[1481]);
      break;

    case mx::ir::hl::CharType::static_kind():
      tp = &(gTypes[1482]);
      break;

    case mx::ir::hl::ShortType::static_kind():
      tp = &(gTypes[1483]);
      break;

    case mx::ir::hl::IntType::static_kind():
      tp = &(gTypes[1484]);
      break;

    case mx::ir::hl::LongType::static_kind():
      tp = &(gTypes[1485]);
      break;

    case mx::ir::hl::LongLongType::static_kind():
      tp = &(gTypes[1486]);
      break;

    case mx::ir::hl::Int128Type::static_kind():
      tp = &(gTypes[1487]);
      break;

    case mx::ir::hl::HalfType::static_kind():
      tp = &(gTypes[1488]);
      break;

    case mx::ir::hl::BFloat16Type::static_kind():
      tp = &(gTypes[1489]);
      break;

    case mx::ir::hl::FloatType::static_kind():
      tp = &(gTypes[1490]);
      break;

    case mx::ir::hl::DoubleType::static_kind():
      tp = &(gTypes[1491]);
      break;

    case mx::ir::hl::LongDoubleType::static_kind():
      tp = &(gTypes[1492]);
      break;

    case mx::ir::hl::Float128Type::static_kind():
      tp = &(gTypes[1493]);
      break;

    case mx::ir::hl::ComplexType::static_kind():
      tp = &(gTypes[1494]);
      break;

    case mx::ir::hl::PointerType::static_kind():
      tp = &(gTypes[1495]);
      break;

    case mx::ir::hl::ArrayType::static_kind():
      tp = &(gTypes[1496]);
      break;

    case mx::ir::hl::VectorType::static_kind():
      tp = &(gTypes[1497]);
      break;

    case mx::ir::hl::DecayedType::static_kind():
      tp = &(gTypes[1498]);
      break;

    case mx::ir::hl::AttributedType::static_kind():
      tp = &(gTypes[1499]);
      break;

    case mx::ir::hl::AdjustedType::static_kind():
      tp = &(gTypes[1500]);
      break;

    case mx::ir::hl::ReferenceType::static_kind():
      tp = &(gTypes[1501]);
      break;

    case mx::ir::hl::TypeOfExprType::static_kind():
      tp = &(gTypes[1502]);
      break;

    case mx::ir::hl::TypeOfTypeType::static_kind():
      tp = &(gTypes[1503]);
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
  if (0 != PyModule_AddObjectRef(module, "Type", tp_obj)) {
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
            auto arg_0 = ::mx::from_python<mx::ir::Type>(args[0]);
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
    PyDoc_STR("Wrapper for mx::ir::hl::Type::from"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[1471]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ir.highlevel.Type";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::ir::hl::::Type");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = gTypes[1436].tp_hash;
  tp->tp_richcompare = gTypes[1436].tp_richcompare;
  tp->tp_iter = nullptr;
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = &(gTypes[1436]);
  tp->tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args, BorrowedPyObject *kwargs) -> int {
    if (kwargs && (!PyMapping_Check(kwargs) || PyMapping_Size(kwargs))) {
      PyErrorStreamer(PyExc_TypeError)
          << "'Type.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'Type.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    (void) obj;
    (void) num_args;
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'Type' cannot be directly instantiated";
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
