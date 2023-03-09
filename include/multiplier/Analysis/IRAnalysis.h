// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gap/core/generator.hpp>
#include <multiplier/Analysis/Taint.h>
#include <multiplier/SourceIR.h>
#include <multiplier/Index.h>

namespace mlir {
class Operation;
class Value;
} // namespace mlir

namespace mx {
namespace iranalysis {

class TaintEdge;
class TaintTrackingCondition;
class TaintTrackingSink;
class TaintTrackingStep;

using TaintTrackingResult = std::variant<TaintTrackingStep, TaintTrackingSink,
                                         TaintTrackingCondition>;
using TaintTrackingResults = gap::generator<TaintTrackingResult>;

class TaintTracker {
 private:
  class Impl;
  friend class Impl;

  std::shared_ptr<Impl> impl;

  TaintTracker(void) = delete;

 public:
  TaintTracker(const Index &);

  // Taint the declaration or statement associated with an existing taint
  // tracking edge.
  TaintTrackingResults add_source(const TaintEdge &) &;

  // Taint the operation associated with an existing taint tracking edge
  TaintTrackingResults add_source(const mlir::Operation *) &;

  // Taint the Value associated with an existing taint tracking edge
  TaintTrackingResults add_source(const mlir::Value &) &;
};

class TaintEdge {
 protected:
  friend class TaintTrackingSink;
  friend class TaintTrackingStep;

  const mlir::Operation *op;

  inline TaintEdge(const mlir::Operation *op_)
      : op(op_) {}

 public:

  inline const mlir::Operation *as_operation(void) const noexcept {
    return op;
  }

  inline VariantEntity as_variant(mx::SourceIR &ir) const noexcept {
    return ir.entity_for(op);
  }

};

enum class TaintTrackingSinkKind {
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

class TaintTrackingSink final : public TaintEdge {
 private:
  friend class TaintTracker;
  friend class TaintTrackerImpl;

  std::string message_;
  TaintTrackingSinkKind kind_;

  TaintTrackingSink(void) = delete;

  inline TaintTrackingSink(
      const mlir::Operation *op_, std::string message__,
      TaintTrackingSinkKind kind__)
      : TaintEdge(std::move(op_)),
        message_(std::move(message__)),
        kind_(kind__){}

 public:

  inline const std::string &message(void) const & noexcept {
    return message_;
  }

  inline std::string message(void) const && noexcept {
    return std::move(message_);
  }

  inline TaintTrackingSinkKind kind(void) const & noexcept {
    return kind_;
  }

};

class TaintTrackingCondition final : public TaintEdge {
 private:
  friend class TaintTracker;
  friend class TaintTrackerImpl;

  using TaintEdge::TaintEdge;
};

enum class TaintTrackingStepKind {
  NORMAL,
  ARGUMENT_TO_PARAMETER,
  RETURN_TO_FUNCTION,
  YIELD_TO_PARENT,
  FUNCTION_TO_CALL,
  ARRAY_ELEMENT_ACCESS
};

class TaintTrackingStep : public TaintEdge {
 private:
  friend class TaintTracker;
  friend class TaintTrackerImpl;

  TaintTrackingStepKind kind_;

  inline TaintTrackingStep(
      const mlir::Operation *op_,
      TaintTrackingStepKind kind__=TaintTrackingStepKind::NORMAL)
      : TaintEdge(std::move(op_)), kind_(kind__) {}

 public:
  inline TaintTrackingStepKind kind(void) const & noexcept {
    return kind_;
  }
};

} // namespace iranalysis
} // namespace mx
