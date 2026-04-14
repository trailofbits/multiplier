// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/Block.h>

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
using T = mx::IRBlock;

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
  if (tp < &(gTypes[1]) || tp >= &(gTypes[2])) {
    return std::nullopt;
  }

  return *T_cast(obj);
}

template <>
SharedPyObject *PythonBinding<T>::to_python(T val) noexcept {
  auto ret = gType->tp_alloc(gType, 0);
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
  if (0 != PyModule_AddObjectRef(module, "IRBlock", tp_obj)) {
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
    PyDoc_STR("Wrapper for mx::IRBlock::id"),
    nullptr,
  },
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyMethodDef gMethods[] = {
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[1]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ir.IRBlock";
  tp->tp_flags = Py_TPFLAGS_DEFAULT;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::::IRBlock");
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
          << "'IRBlock.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'IRBlock.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    while (num_args == 0) {
      obj->data = new (obj->backing_storage) IRBlock();
      return 0;
    }

    PyErrorStreamer(PyExc_TypeError)
        << "Invalid arguments to 'IRBlock.__init__'";
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
