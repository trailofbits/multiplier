// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <optional>

#include "../Compiler.h"

typedef struct _object PyObject;

namespace mx {

using BorrowedPyObject = ::PyObject;
using SharedPyObject = ::PyObject;

// Convert an object of type `T` to a new reference to a Python object.
template <typename T>
[[gnu::noinline]]
MX_EXPORT SharedPyObject *to_python(T) noexcept;

// Convert a borrowed reference to a Python object, and try to convert it to
// a value of type `T`.
template <typename T>
[[gnu::noinline]]
MX_EXPORT std::optional<T> from_python(BorrowedPyObject *obj) noexcept;

// Return a new reference to the loaded `multiplier` module, if any.
MX_EXPORT SharedPyObject *python_module(void) noexcept;

}  // namespace mx
