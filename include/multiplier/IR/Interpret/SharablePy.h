// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.
//
// PyObjectRC arm of `Sharable<T, Policy>`. Lives in its own header so the
// CLI can include `Sharable.h` without pulling in <Python.h>.
//
// `PyRef<T>` is the templated SharedPyPtr — owning Python reference whose
// underlying object is a `PyWrapperFor<T>` (a PyObject head + aligned
// storage for T). `make_sharable<T>(args...)` allocates the PyObject,
// placement-news T into the storage, and threads the back-pointer.

#pragma once

#include <Python.h>

#include "Sharable.h"

#include <new>
#include <type_traits>
#include <utility>

namespace mx::ir::interpret {

// ---------------------------------------------------------------------------
// PyWrapperFor<T> — PyObject layout for PyObjectRC-policy T.
//
// `data` is the live pointer (set after placement-new succeeds); the
// backing storage is aligned for T. T itself does NOT need PyObject as
// its first member — the PyObject header lives in this wrapper.
// ---------------------------------------------------------------------------

template <typename T>
struct PyWrapperFor : public ::PyObject {
  T *data{nullptr};
  alignas(alignof(T)) char backing_storage[sizeof(T)];
};

// ---------------------------------------------------------------------------
// PyRef<T> — owning, refcounted Python reference whose underlying type
// is `PyWrapperFor<T>`. Mirrors `SharedPyPtr` but T-aware.
// ---------------------------------------------------------------------------

template <typename T>
class PyRef final {
 public:
  PyRef(void) noexcept = default;

  ~PyRef(void) noexcept { Py_XDECREF(obj_); }

  // Take ownership of an existing strong reference (no INCREF).
  static PyRef adopt(::PyObject *obj) noexcept {
    PyRef ref;
    ref.obj_ = obj;
    return ref;
  }

  // Borrow + INCREF.
  static PyRef wrap(::PyObject *obj) noexcept {
    Py_XINCREF(obj);
    return adopt(obj);
  }

  PyRef(const PyRef &that) noexcept : obj_(that.obj_) { Py_XINCREF(obj_); }

  PyRef(PyRef &&that) noexcept : obj_(that.obj_) { that.obj_ = nullptr; }

  PyRef &operator=(const PyRef &that) noexcept {
    if (this != &that) {
      ::PyObject *old = obj_;
      obj_ = that.obj_;
      Py_XINCREF(obj_);
      Py_XDECREF(old);
    }
    return *this;
  }

  PyRef &operator=(PyRef &&that) noexcept {
    if (this != &that) {
      Py_XDECREF(obj_);
      obj_ = that.obj_;
      that.obj_ = nullptr;
    }
    return *this;
  }

  T *get(void) const noexcept {
    return obj_ ? reinterpret_cast<PyWrapperFor<T> *>(obj_)->data : nullptr;
  }

  ::PyObject *raw(void) const noexcept { return obj_; }

  // Transfer ownership: returns the strong reference and clears this
  // PyRef. The caller must DECREF when done.
  ::PyObject *release(void) noexcept {
    ::PyObject *ret = obj_;
    obj_ = nullptr;
    return ret;
  }

  T &operator*(void) const noexcept { return *get(); }
  T *operator->(void) const noexcept { return get(); }

  explicit operator bool(void) const noexcept { return obj_ != nullptr; }

 private:
  ::PyObject *obj_{nullptr};
};

// ---------------------------------------------------------------------------
// Sharable<T, PyObjectRC> — pure marker carrying ref_type, the
// enclosing-PyObject back-pointer, and a per-instantiation PyType()
// accessor. PyType() is declared here and defined out-of-line per
// instantiation, in the binding library that owns the PyTypeObject.
// ---------------------------------------------------------------------------

template <typename T>
class Sharable<T, PyObjectRC> {
 public:
  using policy_t = PyObjectRC;
  using ref_type = PyRef<T>;

  // Set by make_sharable after PyObject_New + placement-new.
  ::PyObject *enclosing_pyobject{nullptr};

  ref_type ref_from_this(void) noexcept {
    Py_INCREF(enclosing_pyobject);
    return ref_type::adopt(enclosing_pyobject);
  }

  // Per-instantiation accessor — defined by the binding library.
  static ::PyTypeObject &PyType(void) noexcept;
};

// ---------------------------------------------------------------------------
// make_sharable<T>(args...) — PyObjectRC overload.
//
// Allocates the PyObject head + aligned storage in one PyObject_New,
// placement-news T(args...) into the backing storage, threads the
// back-pointer, and returns an owning PyRef<T>. Exception-safe: on a
// throw from T's constructor, the just-allocated PyObject is freed
// before the exception propagates.
// ---------------------------------------------------------------------------

template <typename T, typename... Args>
std::enable_if_t<std::is_same_v<typename T::policy_t, PyObjectRC>, ref_t<T>>
make_sharable(Args &&...args) {
  static_assert(
      std::is_base_of_v<Sharable<T, PyObjectRC>, T>,
      "T must inherit Sharable<T, PyObjectRC>");

  using O = PyWrapperFor<T>;
  // Cache the PyTypeObject pointer in a local — `Sharable<T, PyObjectRC>`
  // expanded inline into a macro splits on the comma between template
  // args, breaking PyObject_New's parser.
  ::PyTypeObject *type = &Sharable<T, PyObjectRC>::PyType();
  O *wrapper = PyObject_New(O, type);
  if (!wrapper) {
    return ref_t<T>{};
  }
  wrapper->data = nullptr;
  try {
    wrapper->data = new (wrapper->backing_storage)
        T(std::forward<Args>(args)...);
    wrapper->data->enclosing_pyobject =
        reinterpret_cast<::PyObject *>(wrapper);
  } catch (...) {
    PyObject_Free(wrapper);
    throw;
  }
  return ref_t<T>::adopt(reinterpret_cast<::PyObject *>(wrapper));
}

}  // namespace mx::ir::interpret
