// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "FunctionDecl.h"
#include "RefQualifierKind.h"

namespace mx {
class EntityProvider;
class Index;
class CXXConstructorDecl;
class CXXConversionDecl;
class CXXDestructorDecl;
class CXXMethodDecl;
class Decl;
class DeclaratorDecl;
class FunctionDecl;
class NamedDecl;
class Stmt;
class Token;
class Type;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXMethodDecl : public FunctionDecl {
 private:
  friend class FragmentImpl;
  friend class FunctionDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<CXXMethodDecl> in(const Fragment &frag);
  static gap::generator<CXXMethodDecl> in(const File &file);
  static gap::generator<CXXMethodDecl> in(const Index &index);
  static gap::generator<CXXMethodDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXMethodDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CXX_METHOD;
  }

  static gap::generator<CXXMethodDecl> containing(const Decl &decl);
  static gap::generator<CXXMethodDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXMethodDecl> containing(const Stmt &stmt);
  static gap::generator<CXXMethodDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<CXXMethodDecl> redeclarations(void) const &;
  static std::optional<CXXMethodDecl> from(const Decl &parent);

  inline static std::optional<CXXMethodDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return CXXMethodDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXMethodDecl> from(const Reference &r);
  static std::optional<CXXMethodDecl> from(const TokenContext &t);

  RefQualifierKind reference_qualifier(void) const;
  std::optional<Type> this_object_type(void) const;
  std::optional<Type> this_type(void) const;
  bool has_inline_body(void) const;
  bool is_const(void) const;
  bool is_copy_assignment_operator(void) const;
  bool is_instance(void) const;
  bool is_lambda_static_invoker(void) const;
  bool is_move_assignment_operator(void) const;
  bool is_virtual(void) const;
  bool is_volatile(void) const;
  std::optional<CXXMethodDecl> nth_overridden_method(unsigned n) const;
  unsigned num_overridden_methods(void) const;
  gap::generator<CXXMethodDecl> overridden_methods(void) const &;
};

static_assert(sizeof(CXXMethodDecl) == sizeof(FunctionDecl));

#endif
} // namespace mx
