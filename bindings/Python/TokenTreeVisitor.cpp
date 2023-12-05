// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Frontend/MacroSubstitution.h>
#include <multiplier/Frontend/TokenTree.h>
#include <multiplier/Fragment.h>

#include <cassert>
#include <new>

#include "Binding.h"
#include "Error.h"
#include "TokenTreeVisitor.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc99-extensions"
#pragma GCC diagnostic ignored "-Wunused-function"
namespace mx {
namespace {

using T = ::mx::TokenTreeVisitor;

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

static PyTypeObject gTypeDef;
static PyTypeObject *gType = nullptr;
static PyTypeObject *InitType(void) noexcept;

static PyMethodDef gMethods[] = {
  {
    "should_expand",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::MacroSubstitution>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->should_expand(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'should_expand'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::TokenTreeVisitor::should_expand"),
  },
  {
    "choose",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = PythonBinding<std::vector<mx::Fragment>>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->choose(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'choose'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::TokenTreeVisitor::choose"),
  },
  {}  // Sentinel.
};

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &gTypeDef;
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.frontend.TokenTreeVisitor";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::::TokenTreeVisitor");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = PyObject_HashNotImplemented;
  tp->tp_richcompare = nullptr;
  tp->tp_iter = nullptr;
  tp->tp_methods = gMethods;
  tp->tp_getset = nullptr;
  tp->tp_base = &PyBaseObject_Type;
  tp->tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args, BorrowedPyObject *kwargs) -> int {
    if (kwargs && (!PyMapping_Check(kwargs) || PyMapping_Size(kwargs))) {
      PyErrorStreamer(PyExc_TypeError)
          << "'TokenTreeVisitor.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args) || PySequence_Size(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'TokenTreeVisitor.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    obj->data = new (obj->backing_storage) T;
    
    return 0;
  };
  tp->tp_alloc = PyType_GenericAlloc;
  tp->tp_new = PyType_GenericNew;

  if (0 != PyType_Ready(tp)) {
    return nullptr;
  }

  return tp;
}

}  // namespace

ProxyTokenTreeVisitor::~ProxyTokenTreeVisitor(void) {}

// Return `true` if the input substitution should be expanded or not.
bool ProxyTokenTreeVisitor::should_expand(
    const MacroSubstitution &sub) const {

  SharedPyPtr sub_obj(::mx::to_python<MacroSubstitution>(sub));
  SharedPyPtr ret(PyObject_CallMethod(
      obj, "should_expand", "(N)", sub_obj.Get()));

  if (ret == nullptr) {
    assert(false);
    return false;
  }

  if (auto bool_ret = ::mx::from_python<bool>(ret)) {
    return bool_ret.value();
  }

  assert(false);
  return TokenTreeVisitor::should_expand(sub);
}

// Choose which fragment to show.
Fragment ProxyTokenTreeVisitor::choose(
    const std::vector<Fragment> &fragments) const {

  SharedPyPtr frags_list(::mx::to_python<std::vector<Fragment>>(fragments));
  SharedPyPtr ret(PyObject_CallMethod(
      obj, "choose", "(N)", frags_list.Get()));

  if (!ret) {
    assert(false);
    return TokenTreeVisitor::choose(fragments);
  }

  if (auto frag_reg = ::mx::from_python<::mx::Fragment>(ret)) {
    return frag_reg.value();
  }

  assert(false);
  return TokenTreeVisitor::choose(fragments);
}

std::optional<ProxyTokenTreeVisitor> PythonBinding<ProxyTokenTreeVisitor>::from_python(
    BorrowedPyObject *obj) noexcept {
  if (!obj) {
    return std::nullopt;
  }

  if (!PyObject_IsInstance(obj, reinterpret_cast<::PyObject *>(gType))) {
    return std::nullopt;
  }

  return ProxyTokenTreeVisitor(obj);
}

bool PythonBinding<ProxyTokenTreeVisitor>::load(BorrowedPyObject *module) noexcept {
  if (!gType) {
    gType = InitType();
    if (!gType) {
      return false;
    }
  }

  auto tp_obj = reinterpret_cast<BorrowedPyObject *>(gType);
  if (0 != PyModule_AddObjectRef(module, "TokenTreeVisitor", tp_obj)) {
    return false;
  }

  return true;
}

#pragma GCC diagnostic pop
}  // namespace mx
