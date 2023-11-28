// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <Python.h>

#include <optional>

namespace mx {

using BorrowedPyObject = ::PyObject;
using SharedPyObject = ::PyObject;

template <typename T>
struct PyObject : public ::PyObject {
 public:
  // The type of this python object.
  static PyTypeObject * const type;

  // When initialized, points to `backing_storage`.
  T *data{nullptr};

  // Load this type into its parent module.
  static bool load(BorrowedPyObject *module) noexcept;

  // Return the Python type associated with `T`.
  static PyTypeObject *classify_type(const T &val) noexcept;

  // Convert a python object to its unwrapped form.
  static std::optional<T> from_python(const BorrowedPyObject *obj) noexcept;

  // Wrap a value of type `T` as a python object.
  static SharedPyObject *to_python(const T &val) noexcept;
};

}  // namespace mx
