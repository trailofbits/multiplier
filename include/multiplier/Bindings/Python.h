// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <vector>

#include "../Compiler.h"

typedef struct _object PyObject;

namespace mx {

using BorrowedPyObject = ::PyObject;
using SharedPyObject = ::PyObject;

template <typename T>
struct FromPythonReturnTypeImpl {
  using Type = std::optional<T>;
};

template <typename T>
struct FromPythonReturnTypeImpl<std::span<T>> {
  using Type = std::optional<std::vector<T>>;
};

template <typename T>
struct FromPythonReturnTypeImpl<std::span<const T>> {
  using Type = std::optional<std::vector<T>>;
};

template <>
struct FromPythonReturnTypeImpl<std::string_view> {
  using Type = std::optional<std::string>;
};

template <typename T>
using FromPythonReturnType = typename FromPythonReturnTypeImpl<T>::Type;

// Convert an object of type `T` to a new reference to a Python object.
template <typename T>
[[gnu::noinline]]
MX_EXPORT SharedPyObject *to_python(T) noexcept;

// Convert a borrowed reference to a Python object, and try to convert it to
// a value of type `T`.
template <typename T>
[[gnu::noinline]]
MX_EXPORT FromPythonReturnType<T> from_python(BorrowedPyObject *obj) noexcept;

}  // namespace mx
