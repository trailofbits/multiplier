// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MemRef/Operation.h>

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
using T = mx::ir::memref::Operation;

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
  if (tp < &(gTypes[1251]) || tp >= &(gTypes[1283])) {
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

    case mx::ir::memref::AssumeAlignmentOp::static_kind():
      tp = &(gTypes[1252]);
      break;

    case mx::ir::memref::AtomicRMWOp::static_kind():
      tp = &(gTypes[1253]);
      break;

    case mx::ir::memref::AtomicYieldOp::static_kind():
      tp = &(gTypes[1254]);
      break;

    case mx::ir::memref::CopyOp::static_kind():
      tp = &(gTypes[1255]);
      break;

    case mx::ir::memref::GenericAtomicRMWOp::static_kind():
      tp = &(gTypes[1256]);
      break;

    case mx::ir::memref::LoadOp::static_kind():
      tp = &(gTypes[1257]);
      break;

    case mx::ir::memref::AllocOp::static_kind():
      tp = &(gTypes[1258]);
      break;

    case mx::ir::memref::AllocaOp::static_kind():
      tp = &(gTypes[1259]);
      break;

    case mx::ir::memref::AllocaScopeOp::static_kind():
      tp = &(gTypes[1260]);
      break;

    case mx::ir::memref::AllocaScopeReturnOp::static_kind():
      tp = &(gTypes[1261]);
      break;

    case mx::ir::memref::CastOp::static_kind():
      tp = &(gTypes[1262]);
      break;

    case mx::ir::memref::CollapseShapeOp::static_kind():
      tp = &(gTypes[1263]);
      break;

    case mx::ir::memref::DeallocOp::static_kind():
      tp = &(gTypes[1264]);
      break;

    case mx::ir::memref::DimOp::static_kind():
      tp = &(gTypes[1265]);
      break;

    case mx::ir::memref::DMAStartOp::static_kind():
      tp = &(gTypes[1266]);
      break;

    case mx::ir::memref::DMAWaitOp::static_kind():
      tp = &(gTypes[1267]);
      break;

    case mx::ir::memref::ExpandShapeOp::static_kind():
      tp = &(gTypes[1268]);
      break;

    case mx::ir::memref::ExtractAlignedPointerAsIndexOp::static_kind():
      tp = &(gTypes[1269]);
      break;

    case mx::ir::memref::ExtractStridedMetadataOp::static_kind():
      tp = &(gTypes[1270]);
      break;

    case mx::ir::memref::GetGlobalOp::static_kind():
      tp = &(gTypes[1271]);
      break;

    case mx::ir::memref::GlobalOp::static_kind():
      tp = &(gTypes[1272]);
      break;

    case mx::ir::memref::MemorySpaceCastOp::static_kind():
      tp = &(gTypes[1273]);
      break;

    case mx::ir::memref::PrefetchOp::static_kind():
      tp = &(gTypes[1274]);
      break;

    case mx::ir::memref::RankOp::static_kind():
      tp = &(gTypes[1275]);
      break;

    case mx::ir::memref::ReallocOp::static_kind():
      tp = &(gTypes[1276]);
      break;

    case mx::ir::memref::ReinterpretCastOp::static_kind():
      tp = &(gTypes[1277]);
      break;

    case mx::ir::memref::ReshapeOp::static_kind():
      tp = &(gTypes[1278]);
      break;

    case mx::ir::memref::StoreOp::static_kind():
      tp = &(gTypes[1279]);
      break;

    case mx::ir::memref::TransposeOp::static_kind():
      tp = &(gTypes[1280]);
      break;

    case mx::ir::memref::ViewOp::static_kind():
      tp = &(gTypes[1281]);
      break;

    case mx::ir::memref::SubViewOp::static_kind():
      tp = &(gTypes[1282]);
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
  if (0 != PyModule_AddObjectRef(module, "Operation", tp_obj)) {
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
            auto arg_0 = ::mx::from_python<mx::ir::Operation>(args[0]);
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
    PyDoc_STR("Wrapper for mx::ir::memref::Operation::from"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[1251]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ir.memref.Operation";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::ir::memref::::Operation");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = gTypes[998].tp_hash;
  tp->tp_richcompare = gTypes[998].tp_richcompare;
  tp->tp_iter = nullptr;
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = &(gTypes[998]);
  tp->tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args, BorrowedPyObject *kwargs) -> int {
    if (kwargs && (!PyMapping_Check(kwargs) || PyMapping_Size(kwargs))) {
      PyErrorStreamer(PyExc_TypeError)
          << "'Operation.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'Operation.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    (void) obj;
    (void) num_args;
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'Operation' cannot be directly instantiated";
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
