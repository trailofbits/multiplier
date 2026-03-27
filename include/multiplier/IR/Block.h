// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../Compiler.h"
#include "../Types.h"
#include <memory>

namespace mx {

class IRBlockImpl;
using IRBlockImplPtr = std::shared_ptr<const IRBlockImpl>;

class MX_EXPORT IRBlock {
 private:
  friend class EntityProvider;
  friend class Index;
  IRBlockImplPtr impl;

 public:
  IRBlock(void) = default;
  explicit IRBlock(IRBlockImplPtr impl_)
      : impl(std::move(impl_)) {}

  EntityId id(void) const { return EntityId(); }  // TODO
};

}  // namespace mx
