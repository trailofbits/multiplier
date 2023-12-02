// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCGCAttrSpelling.h>
#include <multiplier/Iterator.h>

#include "Binding.h"
#include "Error.h"
#include "Types.h"

namespace mx {
namespace {
using T = mx::ObjCGCAttrSpelling;
}  // namespace

namespace {
static PyTypeObject *gType = nullptr;
}  // namespace

template <>
PyTypeObject *PythonBinding<T>::type(void) noexcept {
  return gType;
}

template <>
SharedPyObject *PythonBinding<T>::to_python(T val) noexcept {
  return PyObject_GetAttrString(reinterpret_cast<BorrowedPyObject *>(gType),
                                EnumeratorName(val));
}

template <>
std::optional<T> PythonBinding<T>::from_python(BorrowedPyObject *obj) noexcept {
  if (!obj) {
    return std::nullopt;
  }

  if (Py_TYPE(obj) != gType) {
    return std::nullopt;
  }

  auto long_val = PyObject_GetAttrString(obj, "value");
  if (!long_val) {
    PyErr_Clear();
    return std::nullopt;
  }

  if (!PyLong_Check(long_val)) {
    Py_DECREF(long_val);
    return std::nullopt;
  }

  int did_overflow = 0;
  const auto ret = static_cast<T>(
      PyLong_AsLongLongAndOverflow(obj, &did_overflow));
  if (did_overflow) {
    Py_DECREF(long_val);
    return std::nullopt;
  }

  return ret;
}

template <>
bool PythonBinding<T>::load(BorrowedPyObject *module) noexcept {
  const char * const enum_name = EnumerationName(T{});
  bool created = false;

  if (!gType) {
    auto enum_module = PyImport_ImportModule("enum");
    if (!enum_module) {
      return false;
    }

    auto int_enum = PyObject_GetAttrString(enum_module, "IntEnum");
    Py_DECREF(enum_module);
    if (!int_enum) {
      return false;
    }

    auto enum_meta = PyObject_Type(int_enum);
    auto prepare = PyObject_GetAttrString(enum_meta, "__prepare__");
    if (!prepare) {
      Py_DECREF(enum_meta);
      Py_DECREF(int_enum);
      return false;
    }

    // Get the `enum._EnumDict` for what we're making.
    auto ns_dict = PyObject_CallFunction(prepare, "s(N)", enum_name, int_enum);
    Py_DECREF(prepare);
    if (!ns_dict) {
      Py_DECREF(enum_meta);
      Py_DECREF(int_enum);
      return false;
    }

    // Assign each enumerator.
    for (T val : EnumerationRange<T>()) {
      auto iname = PyUnicode_FromString(EnumeratorName(val));
      auto ival = PyLong_FromUnsignedLongLong(static_cast<uint64_t>(val));
      if (ival) {
        if (!PyObject_SetItem(ns_dict, iname, ival)) {
          continue;
        }
        Py_DECREF(ival);
      }

      Py_DECREF(ns_dict);
      Py_DECREF(enum_meta);
      Py_DECREF(int_enum);
      return false;
    }

    // Create the type.
    auto enum_class = PyObject_CallFunction(
        enum_meta, "s(N)N", enum_name, int_enum, ns_dict);
    Py_DECREF(ns_dict);
    Py_DECREF(enum_meta);
    Py_DECREF(int_enum);

    if (!enum_class) {
      return false;
    }

    if (!PyType_Check(enum_class)) {
      Py_DECREF(enum_class);

      PyErrorStreamer(PyExc_ImportError)
          << "Created enum class for enumerator '" << enum_name
          << "' is not a python type";
      return false;
    }

    gType = reinterpret_cast<PyTypeObject *>(enum_class);
    created = true;
  }

  auto tp_obj = reinterpret_cast<BorrowedPyObject *>(gType);
  if (0 != PyModule_AddObjectRef(module, enum_name, tp_obj)) {
    return false;
  }

  if (created) {
    Py_DECREF(tp_obj);
  }

  return true;
}

}  // namespace mx
