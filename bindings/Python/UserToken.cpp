// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Binding.h"

#include <multiplier/Index.h>

#include "Error.h"

namespace mx {
namespace {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc99-extensions"

using T = UserToken;

struct O final : public ::PyObject {

  // When initialized, points to `backing_storage`.
  T *data{nullptr};

  // Aligned storage for `T`. Pointed to by `data`.
  alignas(alignof(T)) char backing_storage[sizeof(T)];  
};

static PyTypeObject gTypeDef = {
  .tp_basicsize = sizeof(O),
  .tp_itemsize = 0,
  .tp_name = "multiplier.frontend.UserToken",
  .tp_hash = PyObject_HashNotImplemented,
  .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,
  .tp_doc = PyDoc_STR("Sketch of a user-defined token, which can be used in TokenRange.create."),
  .tp_base = &PyBaseObject_Type,
  .tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args,
                 BorrowedPyObject *kwargs) -> int {
    if (args && (!PySequence_Check(args) || PySequence_Size(args))) {
      PyErrorStreamer(PyExc_TypeError)
          << "'UserToken.__init__' does not take any positional arguments";
      return -1;
    }

    if (!kwargs || !PyMapping_Check(kwargs) || !PyMapping_Size(kwargs)) {
      PyErrorStreamer(PyExc_TypeError)
          << "'UserToken.__init__' requires at least one keyword argument";
      return -1;
    }

    SharedPyPtr kind(PyMapping_GetItemString(kwargs, "kind"));
    PyErr_Clear();

    SharedPyPtr category(PyMapping_GetItemString(kwargs, "category"));
    PyErr_Clear();

    SharedPyPtr data(PyMapping_GetItemString(kwargs, "data"));
    PyErr_Clear();

    SharedPyPtr related_entity(PyMapping_GetItemString(kwargs, "related_entity"));
    PyErr_Clear();

    Py_ssize_t num_args = !!kind + !!category + !!data + !!related_entity;
    if (num_args != PyMapping_Size(kwargs)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Extraneous keyword arguments passed to 'UserToken.__init__'; "
             "only 'kind', 'category', 'data', and 'related_entity' are "
             "accepted";
      return -1;
    }

    // Initialize the token.
    auto obj = reinterpret_cast<O *>(self);
    obj->data = new (obj->backing_storage) T;

    if (kind && kind != Py_None) {
      auto tk = ::mx::from_python<mx::TokenKind>(kind);
      if (!tk) {
        PyErrorStreamer(PyExc_TypeError)
            << "Value to 'kind' argument of 'UserToken.__init__' must have "
               "type 'multiplier.frontend.TokenKind'.";
        return -1;
      }

      obj->data->kind = tk.value();
    }

    if (category && category != Py_None) {
      auto tc = ::mx::from_python<mx::TokenCategory>(category);
      if (!tc) {
        PyErrorStreamer(PyExc_TypeError)
            << "Value to 'category' argument of 'UserToken.__init__' must have "
               "type 'multiplier.frontend.TokenCategory'.";
        return -1;
      }

      obj->data->category = tc.value();
    }

    if (data && data != Py_None) {
      auto d = ::mx::from_python<std::string>(data);
      if (!d) {
        PyErrorStreamer(PyExc_TypeError)
            << "Value to 'data' argument of 'UserToken.__init__' must have "
               "type 'str'.";
        return -1;
      }

      obj->data->data = std::move(d.value());
    }

    if (related_entity && related_entity != Py_None) {
      auto re = ::mx::from_python<VariantEntity>(related_entity);
      if (!re) {
        PyErrorStreamer(PyExc_TypeError)
            << "Value to 'related_entity' argument of 'UserToken.__init__' must have "
               "type 'Entity'.";
        return -1;
      }

      obj->data->related_entity = std::move(re.value());
    }

    return 0;
  },
  .tp_alloc = PyType_GenericAlloc,
  .tp_new = PyType_GenericNew,
};

static PyTypeObject *gType = nullptr;

#pragma GCC diagnostic pop
}  // namespace

template <>
PyTypeObject *PythonBinding<T>::type(void) noexcept {
  return gType;
}

template <> std::optional<T> PythonBinding<T>::from_python(
    BorrowedPyObject *obj) noexcept {

  if (!obj || Py_TYPE(obj) != gType) {
    return std::nullopt;
  }

  return *(reinterpret_cast<O *>(obj)->data);
}

template <>
::mx::SharedPyObject *PythonBinding<T>::to_python(T val) noexcept {
  auto ret = gType->tp_alloc(gType, 0);
  if (auto obj = reinterpret_cast<O *>(ret)) {
    obj->data = new (obj->backing_storage) T(std::move(val));
  }
  return ret;
}

template <>
bool PythonBinding<T>::load(BorrowedPyObject *module) noexcept {
  if (!gType) {
    if (0 != PyType_Ready(&gTypeDef)) {
      return false;
    }
    gType = &gTypeDef;
  }

  auto tp_obj = reinterpret_cast<BorrowedPyObject *>(gType);
  if (0 != PyModule_AddObjectRef(module, "UserToken", tp_obj)) {
    return false;
  }

  return true;
}

}  // namespace mx
