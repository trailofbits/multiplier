// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <iostream>
#include <sstream>
#include <unordered_set>

#include <mlir/IR/Dialect.h>
#include <mlir/IR/MLIRContext.h>
#include <mlir/Parser/Parser.h>
#include <multiplier/Analysis/IRAnalysis.h>

#include "../Types.h"

namespace mx {
namespace iranalysis {
namespace {

enum class OperationType {
  ADDRESSOF_EXPR,
  CALL_EXPR,
  CMP_EXPR,
  COND_YIELD,
  MEM_DEREF,
  RETURN,
  SIZEOF_EXPR,
  SUBSCRIPT_EXPR,
  UNREACHABLE,
  VALUE_YIELD,
  OTHERS,
};

static inline OperationType OperationMap(std::string name) {
  if (name == "hl.addressof") {
    return OperationType::ADDRESSOF_EXPR;
  } else if (name == "hl.call"
      || name == "hl.indirect_call") {
    return OperationType::CALL_EXPR;
  } else if (name == "hl.cmp") {
    return  OperationType::CMP_EXPR;
  } else if (name == "hl.cond.yield") {
    return  OperationType::COND_YIELD;
  } else if (name == "hl.deref") {
    return  OperationType::MEM_DEREF;
  } else if (name == "hl.return") {
    return  OperationType::RETURN;
  } else if (name == "hl.sizeof") {
    return  OperationType::SIZEOF_EXPR;
  } else if (name == "hl.subscript") {
    return  OperationType::SUBSCRIPT_EXPR;
  } else if (name == "hl.unrechable") {
    return  OperationType::UNREACHABLE;
  } else if (name == "hl.value.yield") {
    return  OperationType::VALUE_YIELD;
  } else {
    return OperationType::OTHERS;
  }
}

static inline OperationType getOperationType(const mlir::Operation *op) {
  std::string name_as_string;
  auto name = const_cast<mlir::Operation*>(op)->getName();
  llvm::raw_string_ostream ss(name_as_string);
  name.print(ss);
  return OperationMap(name_as_string);
}

std::string OperationToString(const mlir::Operation *op) {
  std::string op_as_string;
  llvm::raw_string_ostream ss(op_as_string);
  const_cast<mlir::Operation*>(op)->print(ss);
  return op_as_string;
}

} // namespace

class TaintTracker::Impl final
    : public std::enable_shared_from_this<TaintTracker::Impl> {
 public:

  Index index;
  std::unordered_set<RawEntityId> seen;

  inline Impl(const Index &index_)
      : index(index_) {}

  TaintTrackingResults AcceptOperation(const mlir::Operation *op);

  TaintTrackingResults AcceptValue(const mlir::Value &val);

  gap::generator<const mlir::Operation*> FindUses(const mlir::Operation *op);

  TaintTrackingResults TaintOperation(
      const mlir::Operation *user, const mlir::Operation *tainted);

  TaintTrackingResults TaintOperationResults(const mlir::Operation *op);

  TaintTrackingResults TaintCallArgument(
      const mlir::Operation *op, const mlir::Operation *tainted);

  TaintTrackingResults TaintReturn(const mlir::Operation *op);

  TaintTrackingResults TaintValueYield(const mlir::Operation *op);

  TaintTrackingResults TaintCondYield(
      const mlir::Operation *op, const mlir::Operation *tainted);

  TaintTrackingResults TaintMemDref(
      const mlir::Operation *op, const mlir::Operation *tainted);

  TaintTrackingResults TaintAddressOf(const mlir::Operation *op);

  TaintTrackingResults TaintSizeOf(const mlir::Operation *op);

  TaintTrackingResults TaintArraySubscript(
      const mlir::Operation *op, const mlir::Operation *tainted);

  TaintTrackingResults Taints(const mlir::Operation *op) {
    co_yield TaintTrackingStep(op);
  }

  TaintTrackingResults NoTaints(void) {
    co_return;
  }
};

gap::generator<const mlir::Operation*> TaintTracker::Impl::FindUses(const mlir::Operation *op) {
  for (auto &uses : (const_cast<mlir::Operation*>(op))->getUses()) {
    co_yield const_cast<const mlir::Operation*>(uses.getOwner());
  }
}

TaintTrackingResults TaintTracker::Impl::TaintCallArgument(
    const mlir::Operation *op, const mlir::Operation *tainted) {
  for (auto iter = const_cast<mlir::Operation*>(op)->operand_begin();
      iter != const_cast<mlir::Operation*>(op)->operand_end(); iter++) {
    auto param = (*iter).getDefiningOp();
    if (param == tainted) {
      co_yield TaintTrackingStep(op);
    }
  }
}

TaintTrackingResults TaintTracker::Impl::TaintReturn(const mlir::Operation *op) {
  co_yield TaintTrackingStep(op, TaintTrackingStepKind::RETURN_TO_FUNCTION);
}


TaintTrackingResults TaintTracker::Impl::TaintValueYield(const mlir::Operation *op) {
  co_yield TaintTrackingStep(op, TaintTrackingStepKind::YIELD_TO_PARENT);
}

TaintTrackingResults TaintTracker::Impl::TaintCondYield(
    const mlir::Operation *op, const mlir::Operation *) {
  co_yield TaintTrackingCondition(op);
}

TaintTrackingResults TaintTracker::Impl::TaintMemDref(
    const mlir::Operation *op, const mlir::Operation *tainted) {
  std::stringstream ss;
  std::string op_string = OperationToString(op);
  ss << "Memory access through tainted member: "
     << op_string << '.';
  co_yield TaintTrackingSink(
      std::move(op), ss.str(),
      TaintTrackingSinkKind::UNCONTROLLED_INDIRECT_MEMBER);
}

TaintTrackingResults TaintTracker::Impl::TaintAddressOf(const mlir::Operation *op) {
  std::stringstream ss;
  std::string op_string = OperationToString(op);
  ss << "Unhandled address of on tainted value: "
     << op_string << '.';
  co_yield TaintTrackingSink(
      std::move(op), ss.str(),
      TaintTrackingSinkKind::UNHANDLED_ADDRESS_OF);
}

TaintTrackingResults TaintTracker::Impl::TaintSizeOf(const mlir::Operation *op) {
  std::stringstream ss;
  std::string op_string = OperationToString(op);
  ss << "Unhandled size of on tainted value: "
     << op_string << '.';
  co_yield TaintTrackingSink(
      std::move(op), ss.str(),
      TaintTrackingSinkKind::UNHANDLED_SIZEOF_OF);
}

TaintTrackingResults TaintTracker::Impl::TaintArraySubscript(
    const mlir::Operation *op, const mlir::Operation *tainted) {
  auto num_operands = const_cast<mlir::Operation*>(op)->getNumOperands();
  if (num_operands > 1) {
    auto opnd = const_cast<mlir::Operation*>(op)->getOperand(0);
    if (opnd.getDefiningOp() == tainted) {
      co_yield TaintTrackingStep(op, TaintTrackingStepKind::ARRAY_ELEMENT_ACCESS);
      co_return;
    }
  }
  std::stringstream ss;
  ss << "Memory access through tainted array index: "
     <<  OperationToString(op) << '.';
  co_yield TaintTrackingSink(
      std::move(op), ss.str(),
      TaintTrackingSinkKind::UNCONTROLLED_ARRAY_INDEX);
}


TaintTrackingResults TaintTracker::Impl::TaintOperation(
    const mlir::Operation *user, const mlir::Operation *tainted) {
    auto type = getOperationType(user);
    switch(type) {
      case OperationType::ADDRESSOF_EXPR:
        return TaintAddressOf(user);
      case OperationType::CALL_EXPR:
        return TaintCallArgument(user, tainted);
      case OperationType::COND_YIELD:
        return TaintCondYield(user, tainted);
      case OperationType::MEM_DEREF:
        return TaintMemDref(user, tainted);
      case OperationType::RETURN:
        return TaintReturn(user);
      case OperationType::SIZEOF_EXPR:
        return TaintSizeOf(user);
      case OperationType::SUBSCRIPT_EXPR:
        return TaintArraySubscript(user, tainted);
      case  OperationType::UNREACHABLE:
        return NoTaints();
      case OperationType::VALUE_YIELD:
        return TaintValueYield(user);
      default:
        return Taints(user);
    }
}

TaintTrackingResults TaintTracker::Impl::AcceptOperation(const mlir::Operation *op) {
  for (auto iter = const_cast<mlir::Operation*>(op)->use_begin();
      iter != const_cast<mlir::Operation*>(op)->use_end(); iter++) {
    for (TaintTrackingResult res :  TaintOperation(iter->getOwner(), op)) {
      co_yield res;
    }
  }
}

TaintTracker::TaintTracker(const Index &index)
    : impl(std::make_shared<Impl>(index)) {}

TaintTrackingResults TaintTracker::add_source(const mlir::Operation *op) &{
  return impl->AcceptOperation(op);
}

TaintTrackingResults TaintTracker::add_source(const mlir::Value &val) &{
  return impl->AcceptOperation(val.getDefiningOp());
}

TaintTrackingResults TaintTracker::add_source(const TaintEdge &edge) &{
  if (auto op = edge.as_operation()) {
    return impl->AcceptOperation(op);
  }
  return impl->NoTaints();
}

} // namespace ir
} // namespace mx

