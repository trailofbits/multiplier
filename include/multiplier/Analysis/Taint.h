// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gap/core/generator.hpp>
#include <optional>
#include <memory>
#include <multiplier/Compilation.h>
#include <multiplier/AST/Attr.h>
#include <multiplier/AST/CallExpr.h>
#include <multiplier/AST/CXXBaseSpecifier.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/DefineMacroDirective.h>
#include <multiplier/AST/Designator.h>
#include <multiplier/AST/Macro.h>
#include <multiplier/AST/ParmVarDecl.h>
#include <multiplier/AST/ReturnStmt.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/TemplateArgument.h>
#include <multiplier/AST/TemplateParameterList.h>
#include <multiplier/AST/Type.h>
#include <multiplier/File.h>
#include <multiplier/Fragment.h>
#include <multiplier/Token.h>
#include <string>

#include "../Entity.h"

namespace mx {

class DefineMacroDirective;
class Index;
class TaintTracker;
class TaintTrackerImpl;
class TaintTrackingSink;
class TaintTrackingStep;

using TaintTrackingResult = std::variant<TaintTrackingStep,
                                         TaintTrackingSink>;
using TaintTrackingResults = gap::generator<TaintTrackingResult>;

// An edge in a taint tracking graph.
class TraintTrackingEdge {
 protected:
  friend class TaintTrackingSink;
  friend class TaintTrackingStep;

  RawEntityId entity_id;
  VariantEntity entity;

  inline TraintTrackingEdge(Decl entity_)
      : entity_id(entity_.id().Pack()),
        entity(std::move(entity_))  {}

  inline TraintTrackingEdge(Stmt entity_)
      : entity_id(entity_.id().Pack()),
        entity(std::move(entity_)) {}

 public:

  inline EntityId id(void) const noexcept {
    return entity_id;
  }

  inline VariantEntity as_variant(void) const noexcept {
    return entity;
  }

  std::optional<Decl> as_declaration(void) const noexcept;
  std::optional<Stmt> as_statement(void) const noexcept;

  inline bool operator==(const TraintTrackingEdge &that) const noexcept {
    return entity_id == that.entity_id;
  }
};

// The driver for a taint tracking analysis. Executes a single step of taint
// tracking.
class TaintTracker {
 private:
  friend class TaintTracker;
  friend class TaintTrackerImpl;

  std::shared_ptr<TaintTrackerImpl> impl;

  TaintTracker(void) = delete;

 public:
  TaintTracker(const Index &);

  // Taint the declaration or statement.
  TaintTrackingResults add_source(const VariantEntity &entity) &;

  // Taint the declaration or statement associated with an existing taint
  // tracking edge.
  TaintTrackingResults add_source(const TraintTrackingEdge &) &;

  // Go find the statements or declarations associated with the expansion of a
  // macro, and taint those.
  TaintTrackingResults add_source(DefineMacroDirective def) &;

  // Treat all uses of the declaration `decl` as tainted, and generate the next
  // step of taint propagation.
  TaintTrackingResults add_source(Decl decl) &;

  // Treat the value `stmt`, if it is a value, as tainted, and generate the
  // next step of tainting.
  TaintTrackingResults add_source(Stmt stmt) &;
};

enum class TaintTrackingSinkKind {
  UNHANDLED_ADDRESS_OF,
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

// The stopping point for the taint tracker, where it isn't able to evaluate
// its condition further, or where the sink condition is accepted.
class TaintTrackingSink final : public TraintTrackingEdge {
 private:
  friend class TaintTracker;
  friend class TaintTrackerImpl;

  std::string message_;
  TaintTrackingSinkKind kind_;

  TaintTrackingSink(void) = delete;

  inline TaintTrackingSink(Decl entity_, std::string message__,
                           TaintTrackingSinkKind kind__)
      : TraintTrackingEdge(std::move(entity_)),
        message_(std::move(message__)),
        kind_(kind__) {}

  inline TaintTrackingSink(Stmt entity_, std::string message__,
                           TaintTrackingSinkKind kind__)
      : TraintTrackingEdge(std::move(entity_)),
        message_(std::move(message__)),
        kind_(kind__) {}

 public:

  inline const std::string &message(void) const & noexcept {
    return message_;
  }

  inline std::string message(void) const && noexcept {
    return std::move(message_);
  }

  inline TaintTrackingSinkKind kind(void) const noexcept {
    return kind_;
  }
};

enum class TaintTrackingStepKind {
  NORMAL,
  ARGUMENT_TO_PARAMETER,
  RETURN_TO_FUNCTION,
  FUNCTION_TO_CALL,
  ASSIGNMENT_TO_DECLARATION,
  STATEMENT_IN_MACRO_EXPANSION,
  DECLARATION_IN_MACRO_EXPANSION
};

// A taint propagation step that was taken from source node to destination
// node.
class TaintTrackingStep final : public TraintTrackingEdge {
 protected:
  friend class TaintTracker;
  friend class TaintTrackerImpl;

  TaintTrackingStepKind kind_;

  inline TaintTrackingStep(
      Decl entity_,
      TaintTrackingStepKind kind__=TaintTrackingStepKind::NORMAL)
      : TraintTrackingEdge(std::move(entity_)),
        kind_(kind__) {}

  inline TaintTrackingStep(
      Stmt entity_,
      TaintTrackingStepKind kind__=TaintTrackingStepKind::NORMAL)
      : TraintTrackingEdge(std::move(entity_)),
        kind_(kind__) {}

 public:

  inline TaintTrackingStepKind kind(void) const noexcept {
    return kind_;
  }
};

}  // namespace mx
