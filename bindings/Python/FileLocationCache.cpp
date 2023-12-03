// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Binding.h"

#include <multiplier/Frontend/File.h>

#include "Error.h"

namespace mx {
namespace {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc99-extensions"

using T = FileLocationCache;

struct O final : public ::PyObject {

  // When initialized, points to `backing_storage`.
  T *data{nullptr};

  // Aligned storage for `T`. Pointed to by `data`.
  alignas(alignof(T)) char backing_storage[sizeof(T)];  
};

static PyTypeObject gTypeDef = {
  .tp_name = "multiplier.frontend.FileLocationCache",
  .tp_hash = PyObject_HashNotImplemented,
  .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,
  .tp_doc = PyDoc_STR("Cache of files to pre-computed line/column number locations."),
  .tp_base = &PyBaseObject_Type,
  .tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args,
                 BorrowedPyObject *kwargs) -> int {
    if (args) {
      if (!PySequence_Check(args)) {
        PyErrorStreamer(PyExc_TypeError)
            << "Invalid positional arguments passed to 'FileLocationCache.__init__'";
        return -1;
      }

      if (PySequence_Size(args)) {
        PyErrorStreamer(PyExc_TypeError)
            << "FileLocationCache.__init__' does not take any positional arguments";
        return -1;
      }
    }

    FileLocationConfiguration config;

    if (kwargs && PyMapping_Check(kwargs)) {
      auto tab_width = PyMapping_GetItemString(kwargs, "tab_width");
      PyErr_Clear();

      auto use_tab_stops = PyMapping_GetItemString(kwargs, "use_tab_stops");
      PyErr_Clear();

      Py_ssize_t count = int(!!tab_width) + int(!!use_tab_stops);
      if (count != PyMapping_Size(kwargs)) {
        Py_XDECREF(use_tab_stops);
        Py_XDECREF(tab_width);

        PyErrorStreamer(PyExc_TypeError)
            << "'FileLocationCache.__init__' only takes in the 'tab_width' "
               "and 'use_tab_stops' keyword arguments";
        return -1;
      }

      if (tab_width) {
        auto val = PythonBinding<unsigned>::from_python(tab_width);
        if (!val) {
          Py_XDECREF(use_tab_stops);
          Py_DECREF(tab_width);
          PyErrorStreamer(PyExc_TypeError)
               << "'tab_width' keyword argument to 'FileLocationCache.__init__'"
                  " must be an integer";
        }

        if (val.value() > 128u) {
          Py_XDECREF(use_tab_stops);
          Py_DECREF(tab_width);
          PyErrorStreamer(PyExc_TypeError)
               << "'tab_width' keyword argument to 'FileLocationCache.__init__'"
                  " must not exceed 128.";
        }

        config.tab_width = val.value();
      }

      if (use_tab_stops) {
        if (!PyBool_Check(use_tab_stops)) {
          Py_XDECREF(tab_width);
          Py_DECREF(use_tab_stops);
        }
        config.use_tab_stops = use_tab_stops == Py_True;
      }

      Py_XDECREF(use_tab_stops);
      Py_XDECREF(tab_width);
    }

    // Initialize the cache.
    auto obj = reinterpret_cast<O *>(self);
    obj->data = new (obj->backing_storage) T(config);

    return 0;
  },
  .tp_alloc = PyType_GenericAlloc,
  .tp_new = PyType_GenericNew,
};

static PyTypeObject *gType = nullptr;

#pragma GCC diagnostic pop
}  // namespace

template <>
PyTypeObject *PythonBinding<FileLocationCache>::type(void) noexcept {
  return gType;
}

template <>
std::optional<FileLocationCache> PythonBinding<FileLocationCache>::from_python(
    BorrowedPyObject *obj) noexcept {

  if (!obj || Py_TYPE(obj) != gType) {
    return std::nullopt;
  }

  return *(reinterpret_cast<O *>(obj)->data);
}

template <>
SharedPyObject *PythonBinding<FileLocationCache>::to_python(
    FileLocationCache val) noexcept {
  auto ret = gType->tp_alloc(gType, 0);
  if (auto obj = reinterpret_cast<O *>(ret)) {
    obj->data = new (obj->backing_storage) T(std::move(val));
  }
  return ret;
}

template <>
bool PythonBinding<FileLocationCache>::load(BorrowedPyObject *module) noexcept {
  if (!gType) {
    if (0 != PyType_Ready(&gTypeDef)) {
      return false;
    }
    gType = &gTypeDef;
  }

  auto tp_obj = reinterpret_cast<BorrowedPyObject *>(gType);
  if (0 != PyModule_AddObjectRef(module, "FileLocationCache", tp_obj)) {
    return false;
  }

  return true;
}

}  // namespace mx
