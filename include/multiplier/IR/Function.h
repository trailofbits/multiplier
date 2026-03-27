// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../Compiler.h"
#include "../Types.h"
#include <memory>

namespace mx {

class IRFunctionImpl;
using IRFunctionImplPtr = std::shared_ptr<const IRFunctionImpl>;

class MX_EXPORT IRFunction {
 private:
  friend class EntityProvider;
  friend class Index;
  IRFunctionImplPtr impl;

 public:
  IRFunction(void) = default;
  explicit IRFunction(IRFunctionImplPtr impl_)
      : impl(std::move(impl_)) {}

  EntityId id(void) const { return EntityId(); }  // TODO
};

}  // namespace mx
