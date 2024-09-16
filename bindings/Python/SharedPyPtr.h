// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <Python.h>

namespace mx {

// An RAII wrapper around a python pointer.
class SharedPyPtr final {
 private:
  SharedPyPtr(void) = delete;

  ::PyObject *obj;

 public:

  inline ~SharedPyPtr(void) {
    Py_XDECREF(obj);
  }

  inline explicit SharedPyPtr(::PyObject *obj_)
      : obj(obj_) {
    Py_XINCREF(obj);
  }

  inline SharedPyPtr(SharedPyPtr &&that) noexcept
      : obj(that.obj) {
    that.obj = nullptr;
  }

  inline SharedPyPtr(const SharedPyPtr &that) noexcept
      : obj(that.obj) {
    Py_XINCREF(obj);
  }

  inline SharedPyPtr &operator=(SharedPyPtr &&that) noexcept {
    SharedPyPtr other(std::move(that));
    Py_XDECREF(obj);
    obj = nullptr;
    std::swap(obj, other.obj);
    return *this;
  }

  inline SharedPyPtr &operator=(const SharedPyPtr &that) noexcept {
    SharedPyPtr other(that);
    std::swap(obj, other.obj);
    return *this;
  }

  inline bool operator==(const std::nullptr_t) const noexcept {
    return obj == nullptr;
  }

  inline bool operator!=(const std::nullptr_t) const noexcept {
    return obj != nullptr;
  }

  inline bool operator!(void) const noexcept {
    return !obj;
  }

  inline ::PyObject *Get(void) const noexcept {
    return obj;
  }

  inline operator ::PyObject *(void) const noexcept {
    return obj;
  }

  inline ::PyObject *Release(void) noexcept {
    auto ret = obj;
    obj = nullptr;
    return ret;
  }
};

}  // namespace mx
