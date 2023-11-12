// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Analysis/Taint.h>

#include <cassert>
#include <multiplier/Entities/ArraySubscriptExpr.h>
#include <multiplier/Entities/BinaryOperator.h>
#include <multiplier/Entities/BinaryOperatorKind.h>
#include <multiplier/Entities/CallExpr.h>
#include <multiplier/Entities/CastExpr.h>
#include <multiplier/Entities/CompoundAssignOperator.h>
#include <multiplier/Entities/ConditionalOperator.h>
#include <multiplier/Entities/DeclKind.h>
#include <multiplier/Entities/DeclRefExpr.h>
#include <multiplier/Entities/DeclStmt.h>
#include <multiplier/Entities/Designator.h>
#include <multiplier/Entities/DoStmt.h>
#include <multiplier/Entities/ForStmt.h>
#include <multiplier/Entities/FunctionDecl.h>
#include <multiplier/Entities/IfStmt.h>
#include <multiplier/Entities/MacroExpansion.h>
#include <multiplier/Entities/MemberExpr.h>
#include <multiplier/Entities/ParenExpr.h>
#include <multiplier/Entities/ParmVarDecl.h>
#include <multiplier/Entities/StmtKind.h>
#include <multiplier/Entities/SwitchStmt.h>
#include <multiplier/Entities/UnaryOperator.h>
#include <multiplier/Entities/UnaryOperatorKind.h>
#include <multiplier/Entities/VarDecl.h>
#include <multiplier/Entities/WhileStmt.h>
#include <multiplier/Index.h>
#include <ostream>
#include <sstream>
#include <unordered_set>

#include "../Types.h"
#include "../Util.h"

namespace mx {

class TaintTrackerImpl final
    : public std::enable_shared_from_this<TaintTrackerImpl> {
 public:

  Index index;

  inline TaintTrackerImpl(const Index &index_)
      : index(index_) {}

  TaintTrackingResults AcceptDecl(Decl decl);

  TaintTrackingResults AcceptReturn(Stmt stmt);
  TaintTrackingResults AcceptStmt(Stmt stmt);
  TaintTrackingResults AcceptDeclStmt(Stmt stmt);

  TaintTrackingResults TaintConditionalOperator(
      Stmt child, ConditionalOperator parent);
  TaintTrackingResults TaintBinaryOperator(
      Stmt child, BinaryOperator parent);
  TaintTrackingResults TaintUnaryOperator(
      Stmt child, UnaryOperator parent);
  TaintTrackingResults TaintArraySubscript(
      Stmt child, ArraySubscriptExpr parent);
  TaintTrackingResults TaintCallArgument(
      Stmt child, CallExpr parent);
  TaintTrackingResults TaintStmt(Stmt stmt);
  TaintTrackingResults TaintCondition(Stmt stmt);
  TaintTrackingResults NoTaints(void);

  TaintTrackingResults TaintAssignedValue(Stmt lhs, Stmt rhs);
  TaintTrackingResults TaintValue(ValueDecl val);
};

std::optional<Decl> TraintTrackingEdge::as_declaration(void) const noexcept {
  if (!std::holds_alternative<Decl>(entity)) {
    return std::nullopt;
  } else {
    assert(CategoryFromEntityId(entity_id) == EntityCategory::DECLARATION);
    return std::get<Decl>(entity);
  }
}

std::optional<Stmt> TraintTrackingEdge::as_statement(void) const noexcept {
  if (!std::holds_alternative<Stmt>(entity)) {
    return std::nullopt;
  } else {
    assert(CategoryFromEntityId(entity_id) == EntityCategory::STATEMENT);
    return std::get<Stmt>(entity);
  }
}

TaintTracker::TaintTracker(const Index &index)
    : impl(std::make_shared<TaintTrackerImpl>(index)) {}

// Taint the declaration or statement.
TaintTrackingResults TaintTracker::add_source(const VariantEntity &entity) & {
  if (std::holds_alternative<Decl>(entity)) {
    for (TaintTrackingResult res :
             impl->AcceptDecl(std::move(std::get<Decl>(entity)))) {
      co_yield res;
    }

  } else if (std::holds_alternative<Stmt>(entity)) {
    for (TaintTrackingResult res :
             impl->AcceptStmt(std::move(std::get<Stmt>(entity)))) {
      co_yield res;
    }
  } else {
    co_return;
  }
}

// Taint the declaration or statement associated with an existing taint
// tracking edge.
TaintTrackingResults TaintTracker::add_source(
    const TraintTrackingEdge &edge) & {
  if (auto stmt = edge.as_statement()) {
    for (TaintTrackingResult res : impl->AcceptStmt(std::move(stmt.value()))) {
      co_yield res;
    }
  } else if (auto decl = edge.as_declaration()) {
    for (TaintTrackingResult res : impl->AcceptDecl(std::move(decl.value()))) {
      co_yield res;
    }
  } else {
    co_return;
  }
}

// Go find the statements or declarations associated with the expansion of a
// macro, and taint those.
TaintTrackingResults TaintTracker::add_source(
    DefineMacroDirective def) & {

  for (Reference ref : mx::Reference::to(def)) {
    std::optional<MacroExpansion> exp = MacroExpansion::from(ref.as_macro());
    if (!exp) {
      continue;
    }

    auto added = false;
    for (Token tok : exp->expansion_tokens()) {
      for (Stmt stmt : Stmt::containing(tok)) {
        co_yield TaintTrackingStep(
            std::move(stmt),
            TaintTrackingStepKind::STATEMENT_IN_MACRO_EXPANSION);
        added = true;
        break;
      }

      if (added) {
        break;
      }

      for (Decl decl : Decl::containing(tok)) {
        co_yield TaintTrackingStep(
            std::move(decl),
            TaintTrackingStepKind::DECLARATION_IN_MACRO_EXPANSION);
        added = true;
        break;
      }

      if (added) {
        break;
      }
    }
  }
}

// Treat all uses of the declaration `decl` as tainted, and generate the next
// step of taint propagation.
TaintTrackingResults TaintTracker::add_source(Decl decl) & {
  return impl->AcceptDecl(std::move(decl));
}

// Treat the value `stmt`, if it is a value, as tainted, and generate the
// next step of tainting.
TaintTrackingResults TaintTracker::add_source(Stmt stmt) & {
  return impl->AcceptStmt(std::move(stmt));
}

// Given that `decl` is tainted, go and taint all references to it.
TaintTrackingResults TaintTrackerImpl::AcceptDecl(Decl decl) {
  if (auto val = ValueDecl::from(decl)) {
    for (TaintTrackingResult res : TaintValue(std::move(val.value()))) {
      co_yield res;
    }
  }
}

static bool ParentLooksUsed(const Stmt &stmt) {
  auto parent = stmt.parent_statement();
  return parent && !IsNonValueStatement(parent->kind());
}

static char StatementToString(
    std::stringstream &os, const Stmt &stmt) {
  char last_ch = '\0';
  auto i = 0u;
  for (Token tok : stmt.tokens().file_tokens()) {
    for (char ch : tok.data()) {
      if (i++) {
        os << last_ch;
      }
      if (ch == '\n') {
        last_ch = ' ';
      } else {
        last_ch = ch;
      }
    }
  }
  return last_ch;
}

TaintTrackingResults TaintTrackerImpl::NoTaints(void) {
  co_return;
}

TaintTrackingResults TaintTrackerImpl::TaintStmt(Stmt stmt) {
  // If it looks like this array subscript is used, then go and yield this
  // node to taint the parent.
  if (ParentLooksUsed(stmt)) {
    co_yield TaintTrackingStep(std::move(stmt));
  }
}

TaintTrackingResults TaintTrackerImpl::TaintCondition(Stmt stmt) {
  std::stringstream ss;
  ss << "Tainted conditional branch.";
  co_yield TaintTrackingSink(
      std::move(stmt), ss.str(), TaintTrackingSinkKind::CONDITIONAL_BRANCH);
}

TaintTrackingResults TaintTrackerImpl::TaintArraySubscript(
    Stmt child, ArraySubscriptExpr parent) {

  if (child == parent.index()) {
    std::stringstream ss;
    ss << "Memory access through tainted array index: "
       << StatementToString(ss, child) << '.';
    co_yield TaintTrackingSink(parent, ss.str(),
                               TaintTrackingSinkKind::UNCONTROLLED_ARRAY_INDEX);
  }

  for (TaintTrackingResult res : TaintStmt(std::move(parent))) {
    co_yield res;
  }
}

static bool IsAssignment(BinaryOperatorKind kind) {
  switch (kind) {
    // Something like `parent = child;`. Here we return `true` to tell the
    // caller that taint propagation has happened (as if the left-hand side is
    // tainted, then it's likely some decl that is tainted, and so we're already
    // visiting all of its uses). The `true` tells the caller "don't ascend any
    // further when looking for taint propagation."
    case BinaryOperatorKind::ASSIGN:
    case BinaryOperatorKind::MUL_ASSIGN:
    case BinaryOperatorKind::DIV_ASSIGN:
    case BinaryOperatorKind::REM_ASSIGN:
    case BinaryOperatorKind::ADD_ASSIGN:
    case BinaryOperatorKind::SUB_ASSIGN:
    case BinaryOperatorKind::SHL_ASSIGN:
    case BinaryOperatorKind::SHR_ASSIGN:
    case BinaryOperatorKind::AND_ASSIGN:
    case BinaryOperatorKind::XOR_ASSIGN:
    case BinaryOperatorKind::OR_ASSIGN:
      return true;
    default:
      return false;
  }
}

static bool IsAssignment(const Stmt &stmt) {
  if (auto bin = BinaryOperator::from(stmt)) {
    return IsAssignment(bin->opcode());
  } else {
    return false;
  }
}

TaintTrackingResults TaintTrackerImpl::TaintConditionalOperator(
    Stmt child, ConditionalOperator parent) {
  if (parent.condition() == child) {
    std::stringstream ss;
    ss << "Tainted conditional select: "
       << StatementToString(ss, child) << '.';
    co_yield TaintTrackingSink(
        std::move(parent), ss.str(),
        TaintTrackingSinkKind::CONDITIONAL_EXPRESSION);

  } else if (ParentLooksUsed(parent)) {
    co_yield TaintTrackingStep(std::move(parent));
  }
}

TaintTrackingResults TaintTrackerImpl::TaintBinaryOperator(
    Stmt child, BinaryOperator parent) {

  switch (BinaryOperatorKind kind = parent.opcode()) {

    // Something like `parent->*child` or `parent.*child`.
    case BinaryOperatorKind::POINTER_MEMORY_D:
    case BinaryOperatorKind::POINTER_MEMORY_I:
      if (parent.rhs() == child) {
        std::stringstream ss;
        ss << "Memory access through tainted member: "
           << StatementToString(ss, child) << '.';
        co_yield TaintTrackingSink(
            std::move(parent), ss.str(),
            TaintTrackingSinkKind::UNCONTROLLED_INDIRECT_MEMBER);
      }
      break;

    // If the left-hand side of a comma operator is tainted, then we ignore it
    // because its value is the right-hand side.
    case BinaryOperatorKind::COMMA:
      if (parent.lhs() == child) {
        co_return;
      }
      break;

    default:
      if (IsAssignment(kind) && parent.rhs() == child) {
        for (TaintTrackingResult step : TaintAssignedValue(
                                            parent.lhs(), child)) {
          co_yield step;
        }
      }
      break;
  }

  // Something like `foo + taint_source`. Here we want to propagate upwards.
  if (ParentLooksUsed(parent)) {
    co_yield TaintTrackingStep(std::move(parent));
  }
}

TaintTrackingResults TaintTrackerImpl::TaintUnaryOperator(
    Stmt child, UnaryOperator parent) {
  switch (parent.opcode()) {
    case UnaryOperatorKind::DEREF: {
      std::stringstream ss;
      ss << "Memory access through tainted pointer: "
         << StatementToString(ss, child) << '.';
      co_yield TaintTrackingSink(parent, ss.str(),
                                 TaintTrackingSinkKind::UNCONTROLLED_POINTER);
      break;
    }

    case UnaryOperatorKind::ADDRESS_OF: {
      std::stringstream ss;
      ss << "Unhandled address of on tainted value: "
         << StatementToString(ss, child) << '.';
      co_yield TaintTrackingSink(parent, ss.str(),
                                 TaintTrackingSinkKind::UNHANDLED_ADDRESS_OF);
      co_return;
    }

    // Tell the caller to keep ascending to the parent statement to treat it
    // as tainted.
    default:
      break;
  }

  if (ParentLooksUsed(parent)) {
    co_yield TaintTrackingStep(std::move(parent));
  }
}

// Propagate the taint from a return statement to the function containing
// the return.
TaintTrackingResults TaintTrackerImpl::AcceptReturn(Stmt stmt) {
  for (FunctionDecl func : FunctionDecl::containing(stmt)) {
    co_yield TaintTrackingStep(
        std::move(func),
        TaintTrackingStepKind::RETURN_TO_FUNCTION);
    co_return;
  }

  co_yield TaintTrackingSink(
      std::move(stmt), "Could not find function containing return statement",
      TaintTrackingSinkKind::RETURN_TO_NOWHERE);
}

static std::optional<unsigned> MatchArgumentToParameter(
    const CallExpr &call, const Stmt &taint_source, const FunctionDecl &func,
    std::optional<ParmVarDecl> &param_out) {

  // Go try to match the argument to a parameter.
  auto arg_num = 0u;
  for (Expr arg : call.arguments()) {
    if (arg != taint_source) {
      ++arg_num;
      continue;
    }

    // TODO(pag): Taint `va_arg` macro use when variadic arguments are used.
    param_out.reset();
    param_out = func.nth_parameter(arg_num);
    return arg_num;
  }

  return std::nullopt;
}

static gap::generator<FunctionDecl> FindAssignedFunctionsBU(
    Reference ref, std::unordered_set<RawEntityId> &seen);

static gap::generator<FunctionDecl> FindAssignedFunctionsTD(
    Stmt stmt, std::unordered_set<RawEntityId> &seen) {
  switch (stmt.kind()) {
    case StmtKind::DECL_REF_EXPR:
      // TODO
      break;
    case StmtKind::MEMBER_EXPR:
      for (Reference ref :
               mx::Reference::to(MemberExpr::from(stmt)->member_declaration())) {
        for (FunctionDecl func : FindAssignedFunctionsBU(
                                     std::move(ref), seen)) {
          co_yield func;
        }
      }
      break;
    default:
      break;
  }

  // TODO
}

// Assuming that `stmt` is something on the left-hand side of an assignment,
// try to find what functions are assigned to the right-hand sides of the
// assignment.
static gap::generator<FunctionDecl> FindAssignedFunctionsBU(
    Stmt stmt, std::unordered_set<RawEntityId> &seen) {
  if (IsNonValueStatement(stmt.kind())) {
    co_return;
  }

  if (IsAssignment(stmt)) {
    auto bin = BinaryOperator::from(stmt);
    for (FunctionDecl func : FindAssignedFunctionsTD(bin->ignore_casts(),
                                                     seen)) {
      co_yield func;
    }
  } else if (auto parent = stmt.parent_statement()) {
    for (FunctionDecl func : FindAssignedFunctionsBU(
                                 std::move(parent.value()), seen)) {
      co_yield func;
    }
  }
}

gap::generator<FunctionDecl> FindAssignedFunctionsBU(
    Reference ref, std::unordered_set<RawEntityId> &seen) {
  if (!seen.insert(ref.referenced_entity_id().Pack()).second) {
    co_return;
  }

  if (std::optional<Stmt> stmt = ref.as_statement()) {
    for (FunctionDecl func : FindAssignedFunctionsBU(stmt.value(), seen)) {
      co_yield func;
    }

  } else if (std::optional<Designator> des = ref.as_designator()) {
    (void) des;  // TODO!!
  }
}

static gap::generator<FunctionDecl> CalledFunctions(
    const CallExpr &call, std::unordered_set<RawEntityId> &seen) {

  if (std::optional<FunctionDecl> dc = call.direct_callee()) {
    co_yield dc.value();
    co_return;
  }

  std::optional<Decl> callee = call.callee_declaration();
  if (!callee) {
    co_return;
  }

  for (Reference ref : mx::Reference::to(callee.value())) {
    for (FunctionDecl func : FindAssignedFunctionsBU(std::move(ref), seen)) {
      co_yield func;
    }
  }
}

// Given that `child` is a tainted argument to the call `parent`, try to
// propagate the taint to a parameter of the called function.
TaintTrackingResults TaintTrackerImpl::TaintCallArgument(
    Stmt child, CallExpr parent) {

  bool matched = false;
  std::unordered_set<RawEntityId> seen_through_call;
  for (FunctionDecl func : CalledFunctions(parent, seen_through_call)) {
    if (!seen_through_call.insert(func.id().Pack()).second) {
      continue;
    }

    // Try to match the argument to a parameter.
    std::optional<ParmVarDecl> param;
    std::optional<unsigned> arg_num = MatchArgumentToParameter(
        parent, child, func, param);
    if (!arg_num) {
      continue;
    }

    matched = true;
    if (param) {
      co_yield TaintTrackingStep(
          param->canonical_declaration(),
          TaintTrackingStepKind::ARGUMENT_TO_PARAMETER);

    } else {
      TaintTrackingSinkKind kind = TaintTrackingSinkKind::UNMATCHED_ARGUMENT;
      std::stringstream ss;
      ss << "Can't match statement to function call parameter: "
         << StatementToString(ss, child);
      if (func.is_variadic()) {
        if (arg_num.value() >= func.num_parameters()) {
          kind = TaintTrackingSinkKind::VARIADIC_ARGUMENT;
          ss << "; function '" << func.name() << "' is variadic";
        }
      }
      ss << '.';
      co_yield TaintTrackingSink(child, ss.str(), kind);
    }
  }

  if (!matched) {
    std::stringstream ss;
    ss << "Can't find callee(s) tainted argument of call: "
       << StatementToString(ss, child) << '.';
    co_yield TaintTrackingSink(child, ss.str(),
                               TaintTrackingSinkKind::UNMATCHED_ARGUMENT);
  }
}

TaintTrackingResults TaintTrackerImpl::AcceptDeclStmt(Stmt stmt) {
  for (Decl d : DeclStmt::from(stmt)->declarations()) {
    for (TaintTrackingResult res : AcceptDecl(std::move(d))) {
      co_yield res;
    }
  }
}

// Given that `stmt` is tainted, go and try to figure out how it is used, and
// generate the next taint from there.
TaintTrackingResults TaintTrackerImpl::AcceptStmt(Stmt stmt) {

  StmtKind kind = stmt.kind();
  switch (kind) {

    // Propagate taint from the return to the containing function.
    case StmtKind::RETURN_STMT:
    case StmtKind::CORETURN_STMT:
    case StmtKind::COYIELD_EXPR:
      return AcceptReturn(std::move(stmt));

    case StmtKind::DECL_STMT:
      return AcceptDeclStmt(std::move(stmt));

    default:
      if (IsNonValueStatement(kind)) {
        return NoTaints();
      }
      break;
  }

  auto parent = stmt.parent_statement();
  if (!parent) {
    return NoTaints();
  }

  kind = parent->kind();
  switch (kind) {
    // Something like `parent[stmt]`.
    case StmtKind::ARRAY_SUBSCRIPT_EXPR:
      return TaintArraySubscript(
          std::move(stmt),
          std::move(ArraySubscriptExpr::from(parent).value()));

    // Something like `foo->bar = taint_source;`.
    case StmtKind::COMPOUND_ASSIGN_OPERATOR:
    case StmtKind::BINARY_OPERATOR:
      return TaintBinaryOperator(
          std::move(stmt),
          std::move(BinaryOperator::from(parent).value()));

    case StmtKind::UNARY_OPERATOR:
      return TaintUnaryOperator(
          std::move(stmt),
          std::move(UnaryOperator::from(parent).value()));

    // Propagate taint from the return to the containing function.
    case StmtKind::RETURN_STMT:
    case StmtKind::CORETURN_STMT:
    case StmtKind::COYIELD_EXPR:
      return AcceptReturn(std::move(parent.value()));

    // Propagates through an assignment to a declaration.
    case StmtKind::DECL_STMT:
      for (Decl d : DeclStmt::from(parent)->declarations()) {
        if (std::optional<VarDecl> vd = VarDecl::from(d)) {
          if (std::optional<Expr> init = vd->initializer();
              init && init.value() == stmt) {
            return AcceptDecl(std::move(d));
          }
        }
      }
      return NoTaints();

    case StmtKind::DECL_REF_EXPR:
      assert(false);  // Shouldn't have children.
      break;

    case StmtKind::CONDITIONAL_OPERATOR: {
      return TaintConditionalOperator(
          std::move(stmt),
          ConditionalOperator::from(parent).value());
      break;
    }

    case StmtKind::SWITCH_STMT: {
      auto switch_ = SwitchStmt::from(parent).value();
      if (switch_.condition() == stmt) {
        return TaintCondition(std::move(parent.value()));
      }
      break;
    }
    case StmtKind::DO_STMT: {
      auto do_ = DoStmt::from(parent).value();
      if (do_.condition() == stmt) {
        return TaintCondition(std::move(parent.value()));
      }
      break;
    }
    case StmtKind::WHILE_STMT: {
      auto while_ = WhileStmt::from(parent).value();
      if (while_.condition() == stmt) {
        return TaintCondition(std::move(parent.value()));
      }
      break;
    }
    case StmtKind::FOR_STMT: {
      auto for_ = ForStmt::from(parent).value();
      if (for_.condition() == stmt) {
        return TaintCondition(std::move(parent.value()));
      }
      break;
    }
    case StmtKind::IF_STMT: {
      auto if_ = IfStmt::from(parent).value();
      if (if_.condition() == stmt) {
        return TaintCondition(std::move(parent.value()));
      }
      break;
    }

    case StmtKind::CALL_EXPR: {
      auto call = CallExpr::from(parent).value();
      if (call.callee() != stmt) {
        return TaintCallArgument(std::move(stmt), std::move(call));
      }
      [[clang::fallthrough]];
    }

    // Not sure.
    case StmtKind::PAREN_EXPR:
    default:
      return TaintStmt(std::move(parent.value()));
  }
  return NoTaints();
}

// Given that the value `val` is tainted, go and find all of its uses, then
// taint those.
TaintTrackingResults TaintTrackerImpl::TaintValue(ValueDecl val) {
  auto is_func = FunctionDecl::from(val).has_value();
  for (Reference ref : mx::Reference::to(val)) {
    if (std::optional<Stmt> stmt = ref.as_statement()) {
      TaintTrackingStepKind kind = TaintTrackingStepKind::NORMAL;
      if (is_func) {
        for (CallExpr call : CallExpr::containing(stmt.value())) {
          if (call.direct_callee() == val) {
            kind = TaintTrackingStepKind::FUNCTION_TO_CALL;
          }
          break;
        }
      }
      co_yield TaintTrackingStep(std::move(stmt.value()), kind);
    } else {
      std::stringstream ss;
      ss << "Ignoring other reference to declaration " << val.id().Pack();
      co_yield TaintTrackingSink(
          val, ss.str(), TaintTrackingSinkKind::UNHANDLED_REFERENCE);
    }
  }
}

static std::optional<Decl> FindAssignedDecl(Stmt lhs) {
  switch (lhs.kind()) {
    case StmtKind::UNARY_OPERATOR:  // E.g. `*foo = taint;`.
    case StmtKind::ARRAY_SUBSCRIPT_EXPR:  // E.g. `foo[index] = taint;`.
      return std::nullopt;

    case StmtKind::MEMBER_EXPR:  // E.g. `foo->bar = taint;`.
    case StmtKind::DECL_REF_EXPR:  // E.g. `foo = taint;`.
      return lhs.referenced_declaration();

    case StmtKind::BUILTIN_BIT_CAST_EXPR:
    case StmtKind::C_STYLE_CAST_EXPR:
    case StmtKind::CXX_FUNCTIONAL_CAST_EXPR:
    case StmtKind::CXX_ADDRSPACE_CAST_EXPR:
    case StmtKind::CXX_CONST_CAST_EXPR:
    case StmtKind::CXX_DYNAMIC_CAST_EXPR:
    case StmtKind::CXX_REINTERPRET_CAST_EXPR:
    case StmtKind::CXX_STATIC_CAST_EXPR:
    case StmtKind::OBJ_C_BRIDGED_CAST_EXPR:
    case StmtKind::IMPLICIT_CAST_EXPR:
    case StmtKind::PAREN_EXPR:
    default:
      if (auto ce = CastExpr::from(lhs)) {
        return FindAssignedDecl(ce->sub_expression());
      } else if (auto pe = ParenExpr::from(lhs)) {
        return FindAssignedDecl(pe->sub_expression());
      } else if (auto bo = BinaryOperator::from(lhs)) {
        if (bo->opcode() == BinaryOperatorKind::COMMA) {
          return FindAssignedDecl(bo->rhs());
        }
      }
      return std::nullopt;
  }
}

// Try to taint `lhs` given that `rhs` is tainted.
TaintTrackingResults
TaintTrackerImpl::TaintAssignedValue(Stmt lhs, Stmt rhs) {
  std::stringstream ss;

  std::optional<Decl> decl = FindAssignedDecl(lhs);
  if (decl) {
    co_yield TaintTrackingStep(
        std::move(decl.value()),
        TaintTrackingStepKind::ASSIGNMENT_TO_DECLARATION);
    co_return;
  }

  ss << "Can't propagate taint through unhandled assignment: "
     << StatementToString(ss, rhs) << '.';
  co_yield TaintTrackingSink(std::move(rhs), ss.str(),
                             TaintTrackingSinkKind::UNHANDLED_ASSIGNMENT);
}

}  // namespace mx
