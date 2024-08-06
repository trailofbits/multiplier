// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/Operation.h>

#include <cassert>
#include <mlir/IR/Block.h>
#include <mlir/IR/Operation.h>
#include <mlir/IR/OperationSupport.h>
#include <mlir/IR/Region.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/HighLevel/Operation.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Value.h>
#include <unordered_map>
#include <vast/Util/Symbols.hpp>
#include <vast/Util/Terminator.hpp>

#include "Operation.h"

namespace mx::ir {
namespace {

static const std::string_view kEmptySymbolName("");

}  // namespace

bool OperationIdsMatch(mlir::Operation *a, mlir::Operation *b) {
  auto a_eid = a->getLoc().cast<mlir::OpaqueLoc>().getUnderlyingLocation();
  auto b_eid = b->getLoc().cast<mlir::OpaqueLoc>().getUnderlyingLocation();
  if (a_eid != b_eid) {
    return false;
  }

  return a_eid != kInvalidEntityId;
}

Operation::Operation(std::shared_ptr<const SourceIRImpl> module,
                     mlir::Operation *opaque,
                     OperationKind kind)
    : module_(std::move(module)),
      op_(opaque),
      kind_(kind) {
  assert(op_ != nullptr);        
}

// Return the ID of this operation.
EntityId Operation::id(void) const noexcept {
  auto eid = op_->getLoc().cast<mlir::OpaqueLoc>().getUnderlyingLocation();
  return EntityId(eid).Extract<::mx::OperationId>().value();
}

bool Operation::operator==(const Operation &that) const noexcept {
  if (underlying_operation() == that.underlying_operation()) {
    return true;
  }

  if (module_ == that.module_) {
    return false;
  }

  return OperationIdsMatch(op_, that.op_);
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

// Returns `true` whether or not this operation is a terminator.
bool Operation::is_terminator(void) const noexcept {
  return vast::is_terminator(op_) ||
         vast::core::is_soft_terminator(op_);
}

// Return the previous and next operations in the current `Block`.
std::optional<Operation> Operation::previous(void) const noexcept {
  if (auto prev_op = op_->getNextNode()) {
    return Operation(module_, prev_op);
  }
  return std::nullopt;
}

std::optional<Operation> Operation::next(void) const noexcept {
  if (auto next_op = op_->getNextNode()) {
    return Operation(module_, next_op);
  }
  return std::nullopt;
}

// Return the name of this operation's symbol, if any.
std::optional<Symbol> Operation::defined_symbol(void) const noexcept {
  if (mlir::dyn_cast<vast::util::vast_symbol_interface>(op_)) {
    return Symbol(module_, op_, kind_);
  }

  if (mlir::dyn_cast<vast::util::mlir_symbol_interface>(op_)) {
    return Symbol(module_, op_, kind_);
  }

  return std::nullopt;
}

// Return the operation defining a symbol.
Operation Operation::defining(const Symbol &symbol) {
  return symbol.operation();
}

// Dump this operation.
void Operation::dump(void) const {
  return op_->dump();
}

// If an operation defines a symbol then return it.
std::optional<Symbol> Symbol::from(const Operation &op) {
  return op.defined_symbol();
}

// The operation defining this symbol.
Operation Symbol::operation(void) const noexcept {
  return Operation(module_, op_, kind_);
}

namespace hl {

std::optional<RefOp> RefOp::from(const ::mx::ir::Operation &op) {
  switch (op.kind()) {
    case OperationKind::HL_REF:
    case OperationKind::HL_FUNCREF:
    case OperationKind::HL_GLOBREF:
    case OperationKind::HL_ENUMREF:
      return reinterpret_cast<const RefOp &>(op);
    default:
      return std::nullopt;
  }
}

std::optional<Symbol> RefOp::referenced_symbol(void) const noexcept {

  // if (mlir::isa<vast::hl::DeclRefOp>(uop) ||
  //     mlir::isa<vast::hl::FuncRefOp>(uop) ||
  //     mlir::isa<vast::hl::GlobalRefOp>(uop) ||
  //     mlir::isa<vast::hl::EnumRefOp>(uop)) {
  //   return RefOp();
  // }

  switch (kind()) {
    case OperationKind::HL_REF: {
      auto decl_ref = reinterpret_cast<const DeclRefOp &>(*this);
      if (auto op = Operation::producing(decl_ref.decl())) {
        return op->defined_symbol();
      }
      break;
    }
    case OperationKind::HL_FUNCREF:
      if (auto func_ref = mlir::dyn_cast<vast::hl::FuncRefOp>(op_)) {
        (void) func_ref;
      }
      break;
    case OperationKind::HL_GLOBREF:
      if (auto global_ref = mlir::dyn_cast<vast::hl::GlobalRefOp>(op_)) {
        (void) global_ref;
      }
      break;
    case OperationKind::HL_ENUMREF:
      if (auto enum_ref = mlir::dyn_cast<vast::hl::EnumRefOp>(op_)) {
        (void) enum_ref;
      }
      break;
    default:
      break;
  }
  return std::nullopt;
}

}  // namespace hl

// References to this symbol.
gap::generator<Operation> Symbol::references(void) const & noexcept {
  if (auto vast_symbol = mlir::dyn_cast<vast::util::vast_symbol_interface>(op_)) {
    for (auto user : vast_symbol->getUsers()) {
      co_yield Operation(module_, user);
    }

  } else if (auto mlir_symbol = mlir::dyn_cast<vast::util::mlir_symbol_interface >(op_)) {
    auto stab = mlir::SymbolTable::getNearestSymbolTable(op_);
    if (auto users = mlir_symbol.getSymbolUses(stab)) {
      for (auto use : *users) {
        co_yield Operation(module_, use.getUser());
      }
    }

  } else {
    co_return;
  }
}

// Name of this symbol.
std::string_view Symbol::name(void) const noexcept {
  if (auto vast_symbol = mlir::dyn_cast<vast::util::vast_symbol_interface>(op_)) {
    auto name = vast::util::symbol_name(vast_symbol);
    return std::string_view(name.data(), name.size());
  }

  if (auto mlir_symbol = mlir::dyn_cast<vast::util::mlir_symbol_interface>(op_)) {
    auto name = vast::util::symbol_name(mlir_symbol);
    return std::string_view(name.data(), name.size());
  }

  assert(false);
  return kEmptySymbolName;
}

bool Symbol::operator==(const Symbol &that) const noexcept {
  if (underlying_operation() == that.underlying_operation()) {
    return true;
  }

  if (module_ == that.module_) {
    return false;
  }

  return OperationIdsMatch(op_, that.op_);
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

bool Result::operator==(const Result &that) const noexcept {
  if (underlying_value() == that.underlying_value()) {
    return true;
  }

  if (module_ == that.module_) {
    return false;
  }

  if (index() != that.index()) {
    return false;
  }

  return OperationIdsMatch(mlir::OpResult(impl_.result).getDefiningOp(),
                           mlir::OpResult(that.impl_.result).getDefiningOp());
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

bool Operand::operator==(const Operand &that) const noexcept {
  if (underlying_operand() == that.underlying_operand()) {
    return true;
  }

  if (module_ == that.module_) {
    return false;
  }

  if (index() != that.index()) {
    return false;
  }

  return OperationIdsMatch(op_->getOwner(), that.op_->getOwner());
}

}  // namespace mx::ir
