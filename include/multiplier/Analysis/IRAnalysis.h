// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gap/core/generator.hpp>
#include <multiplier/SourceIR.h>
#include <multiplier/Index.h>

namespace mlir {
class Operation;
class Value;
} // namespace mlir

namespace mx {

#define MX_FOR_EACH_OPERATION_KIND(m) \
    m("hl.addressof", address_of, ADDRESS_OF) \
    m("hl.assign", assign, ASSIGN) \
    m("hl.call", call, CALL) \
    m("hl.cmp", cmp, CMP) \
    m("hl.cond.yield", cond_yield, COND_YIELD)\
    m("hl.deref", deref, DEREF) \
    m("hl.indirect_call", indirect_call, INDIRECT_CALL) \
    m("hl.return", return_, RETURN) \
    m("hl.sizeof", size_of, SIZE_OF) \
    m("hl.subscript", subscript, SUBSCRIPT) \
    m("hl.unrechable", unrechable, UNREACHABLE) \
    m("hl.value.yield", value_yield, VALUE_YIELD)

enum class OperationKind {
#define MX_ENUM_DEFINE(dial, name, kind) kind,

  MX_FOR_EACH_OPERATION_KIND(MX_ENUM_DEFINE)
  OTHER,
};


class DependencyTrackingEdge;
class DependencyTrackingCondition;
class DependencyTrackingSink;
class DependencyTrackingStep;

using DependencyTrackingResult = std::variant<DependencyTrackingStep,
    DependencyTrackingSink, DependencyTrackingCondition>;
using DependencyTrackingResults = gap::generator<DependencyTrackingResult>;

class DependencyAnalysisImpl;

class DependencyAnalysis {
 private:
  friend class DependencyAnalysisImpl;

  DependencyAnalysis(void) = delete;

 public:
  DependencyAnalysis(const Index &);

  // Add DependencyTrackingEdge as one of the dependents source and do the
  // taint propagation to get next edge.
  DependencyTrackingResults dependents(const DependencyTrackingEdge &) &;

  // Add mlir::Operation as one of the dependents source and do the
  // taint propagation to get next edge.
  DependencyTrackingResults dependents(MLIROperationPtr) &;

  // Add mlir::Value as one of the dependents source and do the
  // taint propagation to get next edge.
  DependencyTrackingResults dependents(MLIRValuePtr) &;
};

class DependencyTrackingEdge {
 protected:
  friend class DependencyTrackingSink;
  friend class DependencyTrackingStep;

  MLIROperationPtr op;

  inline DependencyTrackingEdge(MLIROperationPtr op_)
      : op(std::move(op_)) {}

 public:

  inline MLIROperationPtr as_operation(void) const noexcept {
    return op;
  }

  inline VariantEntity as_variant(const mx::SourceIR &ir) const noexcept {
    return ir.entity_for(op);
  }
};

enum class DependencySinkKind {
  UNHANDLED_ADDRESS_OF,
  UNHANDLED_SIZEOF_OF,
  UNHANDLED_REFERENCE,
  UNHANDLED_ASSIGNMENT,
  UNCONTROLLED_ARRAY_INDEX,
  UNCONTROLLED_INDIRECT_MEMBER,
  UNCONTROLLED_POINTER,
  RETURN_TO_NOWHERE,
  UNMATCHED_ARGUMENT,
  VARIADIC_ARGUMENT,
  CONDITIONAL_EXPRESSION,
  CONDITIONAL_BRANCH
};

class DependencyTrackingSink final : public DependencyTrackingEdge {
 private:
  friend class DependencyAnalysis;

  std::string message_;
  DependencySinkKind kind_;

  DependencyTrackingSink(void) = delete;

  inline DependencyTrackingSink(
      MLIROperationPtr op_, std::string message__, DependencySinkKind kind__)
      : DependencyTrackingEdge(std::move(op_)),
        message_(std::move(message__)),
        kind_(kind__){}

 public:

  inline const std::string &message(void) const & noexcept {
    return message_;
  }

  inline std::string message(void) const && noexcept {
    return std::move(message_);
  }

  inline DependencySinkKind kind(void) const & noexcept {
    return kind_;
  }

};

class DependencyTrackingCondition final : public DependencyTrackingEdge {
 private:
  friend class DependencyAnalysis;

  using DependencyTrackingEdge::DependencyTrackingEdge;
};

enum class DependencyStepKind {
  NORMAL,
  ARGUMENT_TO_PARAMETER,
  RETURN_TO_FUNCTION,
  YIELD_TO_PARENT,
  FUNCTION_TO_CALL,
  ARRAY_ELEMENT_ACCESS
};

class DependencyTrackingStep : public DependencyTrackingEdge {
 private:
  friend class DependencyAnalysis;

  DependencyStepKind kind_;

  inline DependencyTrackingStep(
      MLIROperationPtr op_,
      DependencyStepKind kind__=DependencyStepKind::NORMAL)
      : DependencyTrackingEdge(std::move(op_)), kind_(kind__) {}

 public:
  inline DependencyStepKind kind(void) const & noexcept {
    return kind_;
  }
};

} // namespace mx
