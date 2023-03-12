// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Analysis/IRAnalysis.h>

#include <iostream>
#include <sstream>
#include <unordered_set>

#ifdef MX_ENABLE_SOURCEIR
#include <mlir/IR/Dialect.h>
#include <mlir/IR/MLIRContext.h>
#include <mlir/Parser/Parser.h>

namespace mx {
namespace {

static inline OperationKind ClassifyOperation(std::string name) {
#define CLASSIFY_DIALECT(d, _, kind) \
  if (name == d) { \
    return OperationKind::kind; \
  }
MX_FOR_EACH_OPERATION_KIND(CLASSIFY_DIALECT);

  // Fallback to it if none of the dialect name matches
  return OperationKind::OTHER;
}

static inline OperationKind getOperationKind(const mlir::Operation *op) {
  std::string name_as_string;
  auto name = const_cast<mlir::Operation*>(op)->getName();
  llvm::raw_string_ostream ss(name_as_string);
  name.print(ss);
  return ClassifyOperation(name_as_string);
}

std::string OperationToString(const mlir::Operation *op) {
  std::string op_as_string;
  llvm::raw_string_ostream ss(op_as_string);
  const_cast<mlir::Operation*>(op)->print(ss);
  return op_as_string;
}

} // namespace

class DependencyAnalysis::Impl final
    : public std::enable_shared_from_this<DependencyAnalysis::Impl> {
 public:

  Index index;

  inline Impl(const Index &index_)
      : index(index_) {}

  DependencyTrackingResults AcceptOperation(const mlir::Operation *op);

  DependencyTrackingResults AcceptValue(const mlir::Value &val);

  gap::generator<const mlir::Operation*> FindUses(const mlir::Operation *op);

  DependencyTrackingResults TaintOperation(
      const mlir::Operation *user, const mlir::Operation *tainted);

  DependencyTrackingResults TaintOperationResults(const mlir::Operation *op);

  DependencyTrackingResults TaintCallArgument(
      const mlir::Operation *op, const mlir::Operation *tainted);

  DependencyTrackingResults TaintReturn(const mlir::Operation *op);

  DependencyTrackingResults TaintValueYield(const mlir::Operation *op);

  DependencyTrackingResults TaintCondYield(
      const mlir::Operation *op, const mlir::Operation *tainted);

  DependencyTrackingResults TaintMemDref(
      const mlir::Operation *op, const mlir::Operation *tainted);

  DependencyTrackingResults TaintAddressOf(const mlir::Operation *op);

  DependencyTrackingResults TaintSizeOf(const mlir::Operation *op);

  DependencyTrackingResults TaintArraySubscript(
      const mlir::Operation *op, const mlir::Operation *tainted);

  DependencyTrackingResults Taints(const mlir::Operation *op) {
    co_yield DependencyTrackingStep(op);
  }

  DependencyTrackingResults NoTaints(void) {
    co_return;
  }
};

gap::generator<const mlir::Operation*> DependencyAnalysis::Impl::FindUses(const mlir::Operation *op) {
  for (auto &uses : (const_cast<mlir::Operation*>(op))->getUses()) {
    co_yield const_cast<const mlir::Operation*>(uses.getOwner());
  }
}

DependencyTrackingResults DependencyAnalysis::Impl::TaintCallArgument(
    const mlir::Operation *op, const mlir::Operation *tainted) {
  for (auto iter = const_cast<mlir::Operation*>(op)->operand_begin();
      iter != const_cast<mlir::Operation*>(op)->operand_end(); iter++) {
    auto param = (*iter).getDefiningOp();
    if (param == tainted) {
      co_yield DependencyTrackingStep(op);
    }
  }
}

DependencyTrackingResults DependencyAnalysis::Impl::TaintReturn(const mlir::Operation *op) {
  co_yield DependencyTrackingStep(op, DependencyStepKind::RETURN_TO_FUNCTION);
}


DependencyTrackingResults DependencyAnalysis::Impl::TaintValueYield(const mlir::Operation *op) {
  co_yield DependencyTrackingStep(op, DependencyStepKind::YIELD_TO_PARENT);
}

DependencyTrackingResults DependencyAnalysis::Impl::TaintCondYield(
    const mlir::Operation *op, const mlir::Operation *) {
  co_yield DependencyTrackingCondition(op);
}

DependencyTrackingResults DependencyAnalysis::Impl::TaintMemDref(
    const mlir::Operation *op, const mlir::Operation *tainted) {
  std::stringstream ss;
  std::string op_string = OperationToString(op);
  ss << "Memory access through tainted member: "
     << op_string << '.';
  co_yield DependencyTrackingSink(
      std::move(op), ss.str(),
      DependencySinkKind::UNCONTROLLED_INDIRECT_MEMBER);
}

DependencyTrackingResults DependencyAnalysis::Impl::TaintAddressOf(const mlir::Operation *op) {
  std::stringstream ss;
  std::string op_string = OperationToString(op);
  ss << "Unhandled address of on tainted value: "
     << op_string << '.';
  co_yield DependencyTrackingSink(
      std::move(op), ss.str(),
      DependencySinkKind::UNHANDLED_ADDRESS_OF);
}

DependencyTrackingResults DependencyAnalysis::Impl::TaintSizeOf(const mlir::Operation *op) {
  std::stringstream ss;
  std::string op_string = OperationToString(op);
  ss << "Unhandled size of on tainted value: "
     << op_string << '.';
  co_yield DependencyTrackingSink(
      std::move(op), ss.str(),
      DependencySinkKind::UNHANDLED_SIZEOF_OF);
}

DependencyTrackingResults DependencyAnalysis::Impl::TaintArraySubscript(
    const mlir::Operation *op, const mlir::Operation *tainted) {
  auto num_operands = const_cast<mlir::Operation*>(op)->getNumOperands();
  if (num_operands > 1) {
    auto opnd = const_cast<mlir::Operation*>(op)->getOperand(0);
    if (opnd.getDefiningOp() == tainted) {
      co_yield DependencyTrackingStep(op, DependencyStepKind::ARRAY_ELEMENT_ACCESS);
      co_return;
    }
  }
  std::stringstream ss;
  ss << "Memory access through tainted array index: "
     <<  OperationToString(op) << '.';
  co_yield DependencyTrackingSink(
      std::move(op), ss.str(),
      DependencySinkKind::UNCONTROLLED_ARRAY_INDEX);
}


DependencyTrackingResults DependencyAnalysis::Impl::TaintOperation(
    const mlir::Operation *user, const mlir::Operation *tainted) {
    auto type = getOperationKind(user);
    switch(type) {
      case OperationKind::ADDRESS_OF:
        return TaintAddressOf(user);
      case OperationKind::CALL:
      case OperationKind::INDIRECT_CALL:
        return TaintCallArgument(user, tainted);
      case OperationKind::COND_YIELD:
        return TaintCondYield(user, tainted);
      case OperationKind::DEREF:
        return TaintMemDref(user, tainted);
      case OperationKind::RETURN:
        return TaintReturn(user);
      case OperationKind::SIZE_OF:
        return TaintSizeOf(user);
      case OperationKind::SUBSCRIPT:
        return TaintArraySubscript(user, tainted);
      case  OperationKind::UNREACHABLE:
        return NoTaints();
      case OperationKind::VALUE_YIELD:
        return TaintValueYield(user);
      default:
        return Taints(user);
    }
}

DependencyTrackingResults DependencyAnalysis::Impl::AcceptOperation(const mlir::Operation *op) {
  for (auto iter = const_cast<mlir::Operation*>(op)->use_begin();
      iter != const_cast<mlir::Operation*>(op)->use_end(); iter++) {
    for (DependencyTrackingResult res :  TaintOperation(iter->getOwner(), op)) {
      co_yield res;
    }
  }
}

DependencyAnalysis::DependencyAnalysis(const Index &index)
    : impl(std::make_shared<Impl>(index)) {}

DependencyTrackingResults DependencyAnalysis::add_dependecy_source(const mlir::Operation *op) &{
  return impl->AcceptOperation(op);
}

DependencyTrackingResults DependencyAnalysis::add_dependecy_source(const mlir::Value &val) &{
  return impl->AcceptOperation(val.getDefiningOp());
}

DependencyTrackingResults DependencyAnalysis::add_dependecy_source(const DependencyTrackingEdge &edge) &{
  if (auto op = edge.as_operation()) {
    return impl->AcceptOperation(op);
  }
  return impl->NoTaints();
}

} // namespace mx

#else

namespace mx {

class DependencyAnalysis::Impl final
    : public std::enable_shared_from_this<DependencyAnalysis::Impl> {
 public:

  Index index;

  inline Impl(const Index &index_)
      : index(index_) {}

  DependencyTrackingResults NoTaints(void) {
    co_return;
  }
};

DependencyAnalysis::DependencyAnalysis(const Index &index)
    : impl(std::make_shared<Impl>(index)) {}

DependencyTrackingResults DependencyAnalysis::add_dependecy_source(const mlir::Operation *) &{
  return impl->NoTaints();
}

DependencyTrackingResults DependencyAnalysis::add_dependecy_source(const mlir::Value &) &{
  return impl->NoTaints();
}

DependencyTrackingResults DependencyAnalysis::add_dependecy_source(const DependencyTrackingEdge &) &{
  return impl->NoTaints();
}

} // namespace mx
#endif

