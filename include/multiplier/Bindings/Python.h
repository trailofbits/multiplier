// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <gap/core/generator.hpp>
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
struct FromPythonReturnType {
  using Type = T;
};

template <typename T>
struct FromPythonReturnType<std::span<T>> {
  using Type = std::vector<T>;
};

template <typename T>
struct FromPythonReturnType<std::span<const T>> {
  using Type = std::vector<T>;
};

template <>
struct FromPythonReturnType<std::string_view> {
  using Type = std::string;
};

// Convert an object of type `T` to a new reference to a Python object.
template <typename T>
[[gnu::noinline]]
MX_EXPORT SharedPyObject *to_python(T) noexcept;


// Given an object of type `T`, call `T::generator_method()`, producing a
// generator of type `gap::generator<V>`, and wrap this in a Python object.
template <typename T, typename V>
[[gnu::noinline]]
MX_EXPORT SharedPyObject *generator_to_python(
    T val, gap::generator<V> (T::*generator_method)(void) const) noexcept;

// Given an object of type `T`, call `T::generator_method()`, producing a
// generator of type `gap::generator<V>`, and wrap this in a Python object.
template <typename T, typename V>
[[gnu::noinline]]
MX_EXPORT SharedPyObject *generator_to_python(
    T val, gap::generator<V> (T::*generator_method)(void) const &) noexcept;

// Given an object of type `T`, call `T::generator_method()`, producing a
// generator of type `gap::generator<V>`, and wrap this in a Python object.
template <typename T, typename V>
[[gnu::noinline]]
MX_EXPORT SharedPyObject *generator_to_python(
    T val, gap::generator<V> (T::*generator_method)(void) const & noexcept) noexcept;

// Convert a borrowed reference to a Python object, and try to convert it to
// a value of type `T`.
template <typename T>
[[gnu::noinline]]
MX_EXPORT std::optional<typename FromPythonReturnType<T>::Type>
from_python(BorrowedPyObject *obj) noexcept;

}  // namespace mx
