// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wgnu-include-next"
#include_next <Python.h>
#pragma GCC diagnostic pop

#include <optional>

namespace mx {

using BorrowedPyObject = ::PyObject;
using SharedPyObject = ::PyObject;

template <typename T>
[[gnu::noinline, gnu::flatten]]
SharedPyObject *to_python(T) noexcept;

template <typename T>
[[gnu::noinline, gnu::flatten]]
std::optional<T> from_python(BorrowedPyObject *obj) noexcept;

}  // namespace mx
