// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Stub binding for IRStructure — will be replaced by bootstrap regeneration.

#include <multiplier/IR/Structure.h>

#include <multiplier/AST.h>
#include <multiplier/Fragment.h>
#include <multiplier/Frontend.h>
#include <multiplier/Index.h>
#include <multiplier/Re2.h>

#include <cassert>
#include <new>

#include "Binding.h"
#include "Error.h"
#include "Types.h"

namespace mx {

namespace {
using T = mx::IRStructure;
}  // namespace

template <>
PyTypeObject *PythonBinding<T>::type(void) noexcept {
  // TODO: assign proper gTypes slot after bootstrap regeneration.
  return PythonBinding<VariantEntity>::type();
}

template <>
std::optional<T> PythonBinding<T>::from_python(BorrowedPyObject *) noexcept {
  // IRStructure cannot be created from Python yet.
  return std::nullopt;
}

template <>
SharedPyObject *PythonBinding<T>::to_python(T val) noexcept {
  // Convert to VariantEntity and use that binding.
  return ::mx::to_python(VariantEntity(std::move(val)));
}

template <>
bool PythonBinding<T>::load(BorrowedPyObject *) noexcept {
  // Will be registered after bootstrap regeneration.
  return true;
}

}  // namespace mx
