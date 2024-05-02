// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/FunctionDecl.h>
#include <multiplier/AST/RefQualifierKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CXXMethodDecl;
class Decl;
class DeclaratorDecl;
class FunctionDecl;
class NamedDecl;
class Stmt;
class Token;
class Type;
class ValueDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CXXMethodDecl : public FunctionDecl {
 private:
  friend class FragmentImpl;
  friend class FunctionDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<CXXMethodDecl> in(const Index &index);
  static gap::generator<CXXMethodDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXMethodDecl> by_id(const Index &, EntityId);
  static gap::generator<CXXMethodDecl> in(const Fragment &frag);
  static gap::generator<CXXMethodDecl> in(const File &file);

  static std::optional<CXXMethodDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<CXXMethodDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CXX_METHOD;
  }

  static gap::generator<CXXMethodDecl> containing(const Decl &decl);
  static gap::generator<CXXMethodDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXMethodDecl> containing(const Stmt &stmt);
  static gap::generator<CXXMethodDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  CXXMethodDecl canonical_declaration(void) const;
  std::optional<CXXMethodDecl> definition(void) const;
  gap::generator<CXXMethodDecl> redeclarations(void) const &;
  static std::optional<CXXMethodDecl> from_base(const Decl &parent);
  inline static std::optional<CXXMethodDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<CXXMethodDecl> from(const std::optional<Decl> &parent);
  static std::optional<CXXMethodDecl> from(const Reference &r);
  static std::optional<CXXMethodDecl> from(const VariantEntity &e);
  static std::optional<CXXMethodDecl> from(const TokenContext &t);

  Type function_object_parameter_reference_type(void) const;
  Type function_object_parameter_type(void) const;
  RefQualifierKind reference_qualifier(void) const;
  std::optional<Type> this_type(void) const;
  bool has_inline_body(void) const;
  bool is_const(void) const;
  bool is_copy_assignment_operator(void) const;
  bool is_explicit_object_member_function(void) const;
  bool is_implicit_object_member_function(void) const;
  bool is_instance(void) const;
  bool is_lambda_static_invoker(void) const;
  bool is_move_assignment_operator(void) const;
  bool is_virtual(void) const;
  bool is_volatile(void) const;
  std::optional<CXXMethodDecl> nth_overridden_method(unsigned n) const;
  unsigned num_overridden_methods(void) const;
  gap::generator<CXXMethodDecl> overridden_methods(void) const &;
  // List of methods that can override this method.
  gap::generator<CXXMethodDecl> overridden_by_methods(void) const &;
  gap::generator<CXXMethodDecl> transitive_overridden_by_methods(void) const &;
};

static_assert(sizeof(CXXMethodDecl) == sizeof(FunctionDecl));

#endif
} // namespace mx
