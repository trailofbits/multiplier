// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../Compiler.h"
#include "../Types.h"
#include "BlockKind.h"
#include <memory>
#include <optional>
#include <gap/coro/generator.hpp>

namespace mx {

class IRFunction;
class IRInstruction;
class IRStructure;
class IRBlockImpl;
using IRBlockImplPtr = std::shared_ptr<const IRBlockImpl>;

class MX_EXPORT IRBlock {
 private:
  friend class EntityProvider;
  friend class Index;
  friend class IRFunction;
  friend class IRInstruction;
  IRBlockImplPtr impl;

 public:
  IRBlock(void) = default;
  explicit IRBlock(IRBlockImplPtr impl_)
      : impl(std::move(impl_)) {}

  EntityId id(void) const;
  ir::BlockKind kind(void) const;

  // Parent structure in the nesting hierarchy.
  std::optional<IRStructure> parent_structure(void) const;

  // Parent function (walks structure chain to root).
  std::optional<IRFunction> parent_function(void) const;

  // All instructions in post-order (children before parents).
  gap::generator<IRInstruction> all_instructions(void) const &;

  // Top-level instructions only (parentOffset == 0).
  gap::generator<IRInstruction> instructions(void) const &;

  // CFG.
  gap::generator<IRBlock> successors(void) const &;
  gap::generator<IRBlock> predecessors(void) const &;

  // Dominators.
  std::optional<IRBlock> immediate_dominator(void) const;
  std::optional<IRBlock> immediate_post_dominator(void) const;
  gap::generator<IRBlock> dominators(void) const &;
  gap::generator<IRBlock> post_dominators(void) const &;
  bool dominates(const IRBlock &other) const;

};

}  // namespace mx
