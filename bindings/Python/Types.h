// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <Python.h>

namespace mx {

// Size is defined in the auto-generated `Types.cpp` file. We put all auto-
// generated types into a single array so that we can easily do the equivalent
// of `PyObject_IsInstance` checks. We don't allow extension of most of our
// wrapped types, so these ranges allow us to be precise.
extern PyTypeObject gTypes[];

}  // namespace mx
