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

static inline OperationKind ClassifyOperation(llvm::StringRef name) {
#define CLASSIFY_DIALECT(d, _, kind) \
  if (name == d) { \
    return OperationKind::kind; \
  }
MX_FOR_EACH_OPERATION_KIND(CLASSIFY_DIALECT);

  // Fallback to it if none of the dialect name matches
  return OperationKind::OTHER;
}

std::string OperationToString(const mlir::Operation *op) {
  std::string op_as_string;
  llvm::raw_string_ostream ss(op_as_string);
  const_cast<mlir::Operation*>(op)->print(ss);
  return op_as_string;
}

} // namespace

class DependencyAnalysisImpl final {
 public:

  std::shared_ptr<const mlir::Operation> module;

  inline DependencyAnalysisImpl(const std::shared_ptr<const mlir::Operation> &module_)
      : module(module_) {}

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

  DependencyTrackingResults Taints(const mlir::Operation *op_ptr) {
    co_yield DependencyTrackingStep(MLIROperationPtr(module, op_ptr));
  }

  static DependencyTrackingResults NoTaints(void) {
    co_return;
  }
};

gap::generator<const mlir::Operation *> DependencyAnalysisImpl::FindUses(
    const mlir::Operation *op) {
  for (auto &uses : (const_cast<mlir::Operation*>(op))->getUses()) {
    co_yield const_cast<const mlir::Operation*>(uses.getOwner());
  }
}

DependencyTrackingResults DependencyAnalysisImpl::TaintCallArgument(
    const mlir::Operation *op, const mlir::Operation *tainted) {
  bool found_tainted_param = false;
  for (auto iter = const_cast<mlir::Operation *>(op)->operand_begin();
      iter != const_cast<mlir::Operation *>(op)->operand_end(); iter++) {
    const mlir::Operation *param = (*iter).getDefiningOp();
    if (param == tainted) {
      found_tainted_param = true;
      // NOTE: if the tainted operation will match one of the operand params, it
      //       will pass the check and get the next dependency tracking steps.
      //       The next step will have the mlir::Operation associated with the
      //       call instruction since it is the owner of the operand value.
      co_yield DependencyTrackingStep(
          MLIROperationPtr(module, op), DependencyStepKind::ARGUMENT_TO_PARAMETER);
    }
  }

  if (!found_tainted_param) {
    std::stringstream ss;
    ss << "Can't find callee(s) tainted argument of call: "
       << OperationToString(op) << '.';
    co_yield DependencyTrackingSink(
        MLIROperationPtr(module, op), ss.str(),
        DependencySinkKind::UNMATCHED_ARGUMENT);
  }
}

DependencyTrackingResults DependencyAnalysisImpl::TaintReturn(
    const mlir::Operation *op) {
  co_yield DependencyTrackingStep(
      MLIROperationPtr(module, op), DependencyStepKind::RETURN_TO_FUNCTION);
}


DependencyTrackingResults DependencyAnalysisImpl::TaintValueYield(
    const mlir::Operation *op) {
  co_yield DependencyTrackingStep(
      MLIROperationPtr(module, op), DependencyStepKind::YIELD_TO_PARENT);
}

DependencyTrackingResults DependencyAnalysisImpl::TaintCondYield(
    const mlir::Operation *op, const mlir::Operation *) {
  std::stringstream ss;
  ss << "Tainted conditional yield: "
     << OperationToString(op) << '.';
  co_yield DependencyTrackingSink(
      MLIROperationPtr(module, op), ss.str(),
      DependencySinkKind::CONDITIONAL_BRANCH);
}

DependencyTrackingResults DependencyAnalysisImpl::TaintMemDref(
    const mlir::Operation *op, const mlir::Operation *tainted) {
  std::stringstream ss;
  ss << "Memory access through tainted member: "
     << OperationToString(op) << '.';
  co_yield DependencyTrackingSink(
      MLIROperationPtr(module, op), ss.str(),
      DependencySinkKind::UNCONTROLLED_INDIRECT_MEMBER);
}

DependencyTrackingResults DependencyAnalysisImpl::TaintAddressOf(
    const mlir::Operation *op) {
  std::stringstream ss;
  ss << "Unhandled address of on tainted value: "
     << OperationToString(op) << '.';
  co_yield DependencyTrackingSink(
      MLIROperationPtr(module, op), ss.str(),
      DependencySinkKind::UNHANDLED_ADDRESS_OF);
}

DependencyTrackingResults DependencyAnalysisImpl::TaintSizeOf(
    const mlir::Operation *op) {
  std::stringstream ss;
  ss << "Unhandled size of on tainted value: "
     << OperationToString(op) << '.';
  co_yield DependencyTrackingSink(
      MLIROperationPtr(module, op), ss.str(),
      DependencySinkKind::UNHANDLED_SIZEOF_OF);
}

DependencyTrackingResults DependencyAnalysisImpl::TaintArraySubscript(
    const mlir::Operation *op, const mlir::Operation *tainted) {
  auto num_operands = const_cast<mlir::Operation*>(op)->getNumOperands();
  if (num_operands > 1) {
    auto opnd = const_cast<mlir::Operation*>(op)->getOperand(0);
    if (opnd.getDefiningOp() == tainted) {
      co_yield DependencyTrackingStep(MLIROperationPtr(module, op),
                                      DependencyStepKind::ARRAY_ELEMENT_ACCESS);
      co_return;
    }
  }
  std::stringstream ss;
  ss << "Memory access through tainted array index: "
     <<  OperationToString(op) << '.';

  co_yield DependencyTrackingSink(
      MLIROperationPtr(module, op), ss.str(),
      DependencySinkKind::UNCONTROLLED_ARRAY_INDEX);
}


DependencyTrackingResults DependencyAnalysisImpl::TaintOperation(
    const mlir::Operation *user, const mlir::Operation *tainted) {
    auto type = ClassifyOperation(
        const_cast<mlir::Operation*>(user)->getName().getStringRef());
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

DependencyTrackingResults DependencyAnalysisImpl::AcceptOperation(
    const mlir::Operation *op) {
  for (auto iter = const_cast<mlir::Operation *>(op)->use_begin();
      iter != const_cast<mlir::Operation *>(op)->use_end(); iter++) {
    for (DependencyTrackingResult res :  TaintOperation(iter->getOwner(), op)) {
      co_yield res;
    }
  }
}

DependencyAnalysis::DependencyAnalysis(const Index &) {}

// Add mlir::Operation as one of the dependents source and do the
// taint propagation to get next edge.
DependencyTrackingResults DependencyAnalysis::dependents(
    MLIROperationPtr op) & {
  DependencyAnalysisImpl impl(op);
  return impl.AcceptOperation(op.get());
}

DependencyTrackingResults DependencyAnalysis::dependents(
    MLIRValuePtr val) & {
  const mlir::Operation *op_ptr = val->getDefiningOp();
  std::shared_ptr<const mlir::Operation> op(std::move(val), op_ptr);
  DependencyAnalysisImpl impl(op);
  return impl.AcceptOperation(op.get());
}

DependencyTrackingResults DependencyAnalysis::dependents(
    const DependencyTrackingEdge &edge) & {
  if (auto op = edge.as_operation()) {
    DependencyAnalysisImpl impl(op);
    return impl.AcceptOperation(op.get());
  }
  return DependencyAnalysisImpl::NoTaints();
}

} // namespace mx

#else

namespace mx {

class DependencyAnalysisImpl final {
 public:

  std::shared_ptr<const void> module;

  inline DependencyAnalysisImpl(const std::shared_ptr<const void> &module_)
      : module(module_) {}

  static DependencyTrackingResults NoTaints(void) {
    co_return;
  }
};

DependencyAnalysis::DependencyAnalysis(const Index &) {}

DependencyTrackingResults DependencyAnalysis::dependents(MLIROperationPtr) & {
  return DependencyAnalysisImpl::NoTaints();
}

DependencyTrackingResults DependencyAnalysis::dependents(MLIRValuePtr) & {
  return DependencyAnalysisImpl::NoTaints();
}

DependencyTrackingResults DependencyAnalysis::dependents(
    const DependencyTrackingEdge &) & {
  return DependencyAnalysisImpl::NoTaints();
}

} // namespace mx
#endif

