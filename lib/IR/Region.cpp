// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/Region.h>

#include <cassert>

#include <mlir/IR/Block.h>
#include <mlir/IR/Operation.h>
#include <mlir/IR/Region.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Operation.h>

#include "SourceIR.h"

namespace mx::ir {

const char *EnumeratorName(BasicBlockOrder val) {
  switch (val) {
    case BasicBlockOrder::PRE_ORDER: return "PRE_ORDER";
    case BasicBlockOrder::POST_ORDER: return "POST_ORDER";
    default: return "<invalid>";
  }
}

Region::Region(std::shared_ptr<const SourceIRImpl> module,
               mlir::Region *region)
    : module_(std::move(module)),
      region_(region) {
  assert(region_ != nullptr);
}

Region Region::containing(const Block &block) {
  return Region(block.module_, block.block_->getParent());
}

// In general, all operations are contained inside a region, except the
// module operation.
std::optional<Region> Region::containing(const Operation &op) {
  if (mlir::Region *region = op.op_->getParentRegion()) {
    return Region(op.module_, region);
  }
  return std::nullopt;
}

unsigned Region::num_blocks(void) const noexcept {
  return static_cast<unsigned>(region_->getBlocks().size());
}

std::optional<Block> Region::nth_block(unsigned i) const noexcept {
  for (mlir::Block &block : region_->getBlocks()) {
    if (!i) {
      return Block(module_, &block);
    }

    --i;
  }

  return std::nullopt;
}

gap::generator<Block> Region::blocks(void) const & noexcept {
  for (mlir::Block &block : region_->getBlocks()) {
    co_yield Block(module_, &block);
  }
}

gap::generator<Block> Region::reverse_blocks(void) const & noexcept {
  auto &blocks = region_->getBlocks();
  for (auto it = blocks.rbegin(), end = blocks.rend(); it != end; ++it) {
    co_yield Block(module_, &*it);
  }
}

Block Region::entry_block(void) const noexcept {
  return Block(module_, &(region_->front()));
}

unsigned Region::num_entry_block_arguments(void) const noexcept {
  return static_cast<unsigned>(region_->front().getArguments().size());
}

std::optional<Argument>
Region::nth_entry_block_argument(unsigned i) const noexcept {
  if (auto args = region_->front().getArguments(); i < args.size()) {
    return Argument(
        module_,
        reinterpret_cast<mlir::detail::BlockArgumentImpl *>(
            args[i].getAsOpaquePointer()));
  }
  return std::nullopt;
}

gap::generator<Argument>
Region::entry_block_arguments(void) const & noexcept {
  for (mlir::BlockArgument arg : region_->front().getArguments()) {
    co_yield Argument(
        module_,
        reinterpret_cast<mlir::detail::BlockArgumentImpl *>(
            arg.getAsOpaquePointer()));
  }
}

bool Region::operator==(const Region &that) const noexcept {
  if (underlying_region() == that.underlying_region()) {
    return true;
  }

  if (module_ == that.module_) {
    return false;
  }

  if (region_->getRegionNumber() != that.region_->getRegionNumber()) {
    return false;
  }

  return OperationIdsMatch(region_->getParentOp(), that.region_->getParentOp());
}

}  // namespace mx::ir
