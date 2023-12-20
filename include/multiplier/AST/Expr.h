// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ExprDependence.h>
#include <multiplier/AST/ExprObjectKind.h>
#include <multiplier/AST/ExprValueKind.h>
#include <multiplier/AST/ValueStmt.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class FieldDecl;
class ObjCPropertyRefExpr;
class Stmt;
class Token;
class Type;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT Expr : public ValueStmt {
 private:
  friend class FragmentImpl;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<Expr> in(const Index &index);
  static gap::generator<Expr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<Expr> by_id(const Index &, EntityId);
  static gap::generator<Expr> in(const Fragment &frag);
  static gap::generator<Expr> in(const File &file);

  static std::optional<Expr> from(const ir::Operation &op);
  static gap::generator<std::pair<Expr, ir::Operation>> in(const Compilation &tu);
  static gap::generator<Expr> containing(const Decl &decl);
  static gap::generator<Expr> containing(const std::optional<Decl> &decl);

  static gap::generator<Expr> containing(const Stmt &stmt);
  static gap::generator<Expr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<Expr> from_base(const Stmt &parent);
  inline static std::optional<Expr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<Expr> from(const std::optional<Stmt> &parent);
  static std::optional<Expr> from(const Reference &r);
  static std::optional<Expr> from(const VariantEntity &e);
  static std::optional<Expr> from(const TokenContext &t);

  bool has_side_effects(void) const;
  Expr ignore_casts(void) const;
  Expr ignore_conversion_operator_single_step(void) const;
  Expr ignore_implicit_casts(void) const;
  Expr ignore_implicit(void) const;
  Expr ignore_implicit_as_written(void) const;
  Expr ignore_parenthesis_base_casts(void) const;
  Expr ignore_parenthesis_casts(void) const;
  Expr ignore_parenthesis_implicit_casts(void) const;
  Expr ignore_parenthesis_l_value_casts(void) const;
  Expr ignore_parenthesis_noop_casts(void) const;
  Expr ignore_parentheses(void) const;
  Expr ignore_unless_spelled_in_source(void) const;
  bool contains_errors(void) const;
  bool contains_unexpanded_parameter_pack(void) const;
  ExprDependence dependence(void) const;
  Token expression_token(void) const;
  std::optional<ObjCPropertyRefExpr> obj_c_property(void) const;
  ExprObjectKind object_kind(void) const;
  std::optional<Decl> referenced_declaration_of_callee(void) const;
  std::optional<FieldDecl> source_bit_field(void) const;
  std::optional<Type> type(void) const;
  ExprValueKind value_kind(void) const;
  bool has_non_trivial_call(void) const;
  bool is_default_argument(void) const;
  bool is_gl_value(void) const;
  bool is_implicit_cxx_this(void) const;
  bool is_instantiation_dependent(void) const;
  std::optional<bool> is_integer_constant_expression(void) const;
  std::optional<bool> is_known_to_have_boolean_value(void) const;
  bool is_l_value(void) const;
  bool is_objcgc_candidate(void) const;
  bool is_obj_c_self_expression(void) const;
  bool is_ordinary_or_bit_field_object(void) const;
  bool is_pr_value(void) const;
  std::optional<bool> is_read_if_discarded_in_c_plus_plus11(void) const;
  bool is_type_dependent(void) const;
  bool is_value_dependent(void) const;
  bool is_x_value(void) const;
  bool refers_to_bit_field(void) const;
  bool refers_to_global_register_variable(void) const;
  bool refers_to_matrix_element(void) const;
  bool refers_to_vector_element(void) const;
};

static_assert(sizeof(Expr) == sizeof(ValueStmt));

#endif
} // namespace mx
