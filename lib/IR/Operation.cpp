// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/Operation.h>

#include <mlir/IR/Block.h>
#include <mlir/IR/Operation.h>
#include <mlir/IR/OperationSupport.h>
#include <mlir/IR/Region.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Value.h>

#include <unordered_map>

#include "Operation.h"

namespace mx::ir {

// Return the ID of this operation.
PackedOperationId Operation::id(void) const noexcept {
  auto eid = op_->getLoc().cast<mlir::OpaqueLoc>().getUnderlyingLocation();
  return EntityId(eid).Extract<::mx::OperationId>().value();
}

std::string_view Operation::kind_name(void) const noexcept {
  switch (kind_) {
    case OperationKind::UNKNOWN: break;
#define MAP_OP_NAME(name, kind, type) \
    case kind: return name;

  MX_IR_FOR_EACH_MLIR_OP(MAP_OP_NAME, MAP_OP_NAME, MAP_OP_NAME, MAP_OP_NAME,
                         MAP_OP_NAME, MAP_OP_NAME, MAP_OP_NAME, MAP_OP_NAME,
                         MAP_OP_NAME)
#undef MAP_OP_NAME
  }

  // Fall back on the actual operation name, as given by MLIR.
  llvm::StringRef name = op_->getName().getStringRef();
  return std::string_view(name.data(), name.size());
}

std::optional<Operation> Operation::producing(const Value &val) {
  if (mlir::Operation *op = mlir::Value(val.impl_.value).getDefiningOp()) {
    return Operation(val.module_, op);
  } else {
    return std::nullopt;
  }
}

Operation Operation::containing(const Region &region) {
  return Operation(region.module_, region.region_->getParentOp());
}

Operation Operation::containing(const Block &block) {
  return Operation(block.module_, block.block_->getParentOp());
}

// Operations can have zero or more operands.
unsigned Operation::num_operands(void) const noexcept {
  return op_->getNumOperands();
}

std::optional<Operand> Operation::nth_operand(unsigned i) const noexcept {
  if (i < op_->getNumOperands()) {
    mlir::OpOperand &op = op_->getOpOperands()[i];
    return Operand(module_, &op);
  }
  return std::nullopt;
}

gap::generator<Operand> Operation::operands(void) const & noexcept {
  for (mlir::OpOperand &op : op_->getOpOperands()) {
    co_yield Operand(module_, &op);
  }
}

unsigned Operation::num_results(void) const noexcept {
  return op_->getNumResults();
}

std::optional<Result> Operation::nth_result(unsigned i) const noexcept {
  if (i < op_->getNumResults()) {
    return Result(module_,
                  reinterpret_cast<mlir::detail::OpResultImpl *>(
                      mlir::OpResult(op_->getResult(i)).getAsOpaquePointer()));
  }
  return std::nullopt;
}

gap::generator<Result> Operation::results(void) const & noexcept {
  for (mlir::OpResult res : op_->getResults()) {
    co_yield Result(module_,
                    reinterpret_cast<mlir::detail::OpResultImpl *>(
                        res.getAsOpaquePointer()));
  }
}

// Operations can have zero or more nested regions. Regions allow one to
// model sequential control-flow and concurrent data-flow graphs of
// computation.
unsigned Operation::num_regions(void) const noexcept {
  return op_->getNumRegions();
}

std::optional<Region> Operation::nth_region(unsigned i) const noexcept {
  if (i < op_->getNumRegions()) {
    mlir::Region &region = op_->getRegion(i);
    return Region(module_, &region);
  }
  return std::nullopt;
}

gap::generator<Region> Operation::regions(void) const & noexcept {
  for (mlir::Region &region : op_->getRegions()) {
    co_yield Region(module_, &region);
  }
}

// If an operation has only one region, the return that region.
std::optional<Region> Operation::only_region(void) const noexcept {
  if (1u == op_->getNumRegions()) {
    mlir::Region &region = op_->getRegion(0u);
    return Region(module_, &region);
  }
  return std::nullopt;
}

// If an operation has only one region, then visit those blocks.
gap::generator<Block> Operation::only_region_blocks(void) const & noexcept {
  if (1u == op_->getNumRegions()) {
    mlir::Region &region = op_->getRegion(0u);
    for (mlir::Block &block : region.getBlocks()) {
      co_yield Block(module_, &block);
    }
  }
}

gap::generator<Operand> Operation::uses(void) const & noexcept {
  for (mlir::OpResult res : op_->getResults()) {
    for (mlir::OpOperand &use : res.getUses()) {
      co_yield Operand(module_, &use);
    }
  }
}

// If an operation produces a single result, then this gives us the result.
std::optional<Result> Result::of(const Operation &op) {
  if (op.op_->getNumResults() == 1u) {
    return Result(op.module_,
                  reinterpret_cast<mlir::detail::OpResultImpl *>(
                      op.op_->getResult(0u).getAsOpaquePointer()));
  }
  return std::nullopt;
}

// Try to down-cast a `Value` to a `Result`.
std::optional<Result> Result::from(const Value &val) {
  if (mlir::Value(val.impl_.value).isa<mlir::OpResult>()) {
    return Result(val.module_, val.impl_.result);
  }
  return std::nullopt;
}

// Return the operation producing this result.
Operation Result::operation(void) const noexcept {
  return Operation(module_, mlir::OpResult(impl_.result).getDefiningOp());
}

// Index of this result in its operation's result list.
unsigned Result::index(void) const noexcept {
  return mlir::OpResult(impl_.result).getResultNumber();
}

// The operation containing this operand.
Operation Operand::operation(void) const noexcept {
  return Operation(module_, op_->getOwner());
}

// The index of this operand within its owner operation's operand list.
unsigned Operand::index(void) const noexcept {
  return op_->getOperandNumber();
}

// Value associated with this operand. This could be a block argument, or
// the result of another operation.
Value Operand::value(void) const noexcept {
  return Value(module_, op_->get().getAsOpaquePointer());
}

}  // namespace mx::ir
