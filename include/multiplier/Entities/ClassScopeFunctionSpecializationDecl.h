// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Decl.h"

namespace mx {
class EntityProvider;
class Index;
class CXXMethodDecl;
class ClassScopeFunctionSpecializationDecl;
class Decl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ClassScopeFunctionSpecializationDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<ClassScopeFunctionSpecializationDecl> in(const Index &index);
  static gap::generator<ClassScopeFunctionSpecializationDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ClassScopeFunctionSpecializationDecl> by_id(const Index &, EntityId);
  static gap::generator<ClassScopeFunctionSpecializationDecl> in(const Fragment &frag);
  static gap::generator<ClassScopeFunctionSpecializationDecl> in(const File &file);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CLASS_SCOPE_FUNCTION_SPECIALIZATION;
  }

  static gap::generator<ClassScopeFunctionSpecializationDecl> containing(const Decl &decl);
  static gap::generator<ClassScopeFunctionSpecializationDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ClassScopeFunctionSpecializationDecl> containing(const Stmt &stmt);
  static gap::generator<ClassScopeFunctionSpecializationDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ClassScopeFunctionSpecializationDecl canonical_declaration(void) const;
  std::optional<ClassScopeFunctionSpecializationDecl> definition(void) const;
  gap::generator<ClassScopeFunctionSpecializationDecl> redeclarations(void) const &;
  static std::optional<ClassScopeFunctionSpecializationDecl> from(const Decl &parent);

  inline static std::optional<ClassScopeFunctionSpecializationDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ClassScopeFunctionSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ClassScopeFunctionSpecializationDecl> from(const Reference &r);
  static std::optional<ClassScopeFunctionSpecializationDecl> from(const TokenContext &t);

  CXXMethodDecl specialization(void) const;
  bool has_explicit_template_arguments(void) const;
};

static_assert(sizeof(ClassScopeFunctionSpecializationDecl) == sizeof(Decl));

#endif
} // namespace mx
