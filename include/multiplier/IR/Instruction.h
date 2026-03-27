// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../Compiler.h"
#include "../Types.h"
#include <memory>

namespace mx {

class IRInstructionImpl;
using IRInstructionImplPtr = std::shared_ptr<const IRInstructionImpl>;

class MX_EXPORT IRInstruction {
 private:
  friend class EntityProvider;
  friend class Index;
  IRInstructionImplPtr impl;

 public:
  IRInstruction(void) = default;
  explicit IRInstruction(IRInstructionImplPtr impl_)
      : impl(std::move(impl_)) {}

  EntityId id(void) const { return EntityId(); }  // TODO
};

}  // namespace mx
