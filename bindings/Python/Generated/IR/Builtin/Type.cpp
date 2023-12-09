// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/Builtin/Type.h>

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
using T = mx::ir::builtin::Type;

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
  if (tp < &(gTypes[1367]) || tp >= &(gTypes[1394])) {
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

    case mx::ir::builtin::ShapedType::static_kind():
      tp = &(gTypes[1368]);
      break;

    case mx::ir::builtin::FloatType::static_kind():
      tp = &(gTypes[1369]);
      break;

    case mx::ir::builtin::BFloat16Type::static_kind():
      tp = &(gTypes[1370]);
      break;

    case mx::ir::builtin::ComplexType::static_kind():
      tp = &(gTypes[1371]);
      break;

    case mx::ir::builtin::Float8E4M3B11FNUZType::static_kind():
      tp = &(gTypes[1372]);
      break;

    case mx::ir::builtin::Float8E4M3FNType::static_kind():
      tp = &(gTypes[1373]);
      break;

    case mx::ir::builtin::Float8E4M3FNUZType::static_kind():
      tp = &(gTypes[1374]);
      break;

    case mx::ir::builtin::Float8E5M2Type::static_kind():
      tp = &(gTypes[1375]);
      break;

    case mx::ir::builtin::Float8E5M2FNUZType::static_kind():
      tp = &(gTypes[1376]);
      break;

    case mx::ir::builtin::Float16Type::static_kind():
      tp = &(gTypes[1377]);
      break;

    case mx::ir::builtin::Float32Type::static_kind():
      tp = &(gTypes[1378]);
      break;

    case mx::ir::builtin::Float64Type::static_kind():
      tp = &(gTypes[1379]);
      break;

    case mx::ir::builtin::Float80Type::static_kind():
      tp = &(gTypes[1380]);
      break;

    case mx::ir::builtin::Float128Type::static_kind():
      tp = &(gTypes[1381]);
      break;

    case mx::ir::builtin::FloatTF32Type::static_kind():
      tp = &(gTypes[1382]);
      break;

    case mx::ir::builtin::FunctionType::static_kind():
      tp = &(gTypes[1383]);
      break;

    case mx::ir::builtin::IndexType::static_kind():
      tp = &(gTypes[1384]);
      break;

    case mx::ir::builtin::IntegerType::static_kind():
      tp = &(gTypes[1385]);
      break;

    case mx::ir::builtin::MemRefType::static_kind():
      tp = &(gTypes[1386]);
      break;

    case mx::ir::builtin::NoneType::static_kind():
      tp = &(gTypes[1387]);
      break;

    case mx::ir::builtin::OpaqueType::static_kind():
      tp = &(gTypes[1388]);
      break;

    case mx::ir::builtin::RankedTensorType::static_kind():
      tp = &(gTypes[1389]);
      break;

    case mx::ir::builtin::TupleType::static_kind():
      tp = &(gTypes[1390]);
      break;

    case mx::ir::builtin::UnrankedMemRefType::static_kind():
      tp = &(gTypes[1391]);
      break;

    case mx::ir::builtin::UnrankedTensorType::static_kind():
      tp = &(gTypes[1392]);
      break;

    case mx::ir::builtin::VectorType::static_kind():
      tp = &(gTypes[1393]);
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
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::ir::Type>::from_python(args[0]);
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
    PyDoc_STR("Wrapper for mx::ir::builtin::Type::from"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[1367]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ir.builtin.Type";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::ir::builtin::::Type");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = gTypes[1366].tp_hash;
  tp->tp_richcompare = nullptr;
  tp->tp_iter = nullptr;
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = &(gTypes[1366]);
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
