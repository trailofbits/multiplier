// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/DeductionCandidate.h>
#include <multiplier/AST/FunctionDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CXXConstructorDecl;
class CXXDeductionGuideDecl;
class Decl;
class DeclaratorDecl;
class FunctionDecl;
class NamedDecl;
class Stmt;
class TemplateDecl;
class Token;
class ValueDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXDeductionGuideDecl : public FunctionDecl {
 private:
  friend class FragmentImpl;
  friend class FunctionDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<CXXDeductionGuideDecl> in(const Index &index);
  static gap::generator<CXXDeductionGuideDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXDeductionGuideDecl> by_id(const Index &, EntityId);
  static gap::generator<CXXDeductionGuideDecl> in(const Fragment &frag);
  static gap::generator<CXXDeductionGuideDecl> in(const File &file);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CXX_DEDUCTION_GUIDE;
  }

  static gap::generator<CXXDeductionGuideDecl> containing(const Decl &decl);
  static gap::generator<CXXDeductionGuideDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXDeductionGuideDecl> containing(const Stmt &stmt);
  static gap::generator<CXXDeductionGuideDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  CXXDeductionGuideDecl canonical_declaration(void) const;
  std::optional<CXXDeductionGuideDecl> definition(void) const;
  gap::generator<CXXDeductionGuideDecl> redeclarations(void) const &;
  static std::optional<CXXDeductionGuideDecl> from_base(const Decl &parent);
  inline static std::optional<CXXDeductionGuideDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<CXXDeductionGuideDecl> from(const std::optional<Decl> &parent);
  static std::optional<CXXDeductionGuideDecl> from(const Reference &r);
  static std::optional<CXXDeductionGuideDecl> from(const VariantEntity &e);
  static std::optional<CXXDeductionGuideDecl> from(const TokenContext &t);

  CXXConstructorDecl corresponding_constructor(void) const;
  TemplateDecl deduced_template(void) const;
  DeductionCandidate deduction_candidate_kind(void) const;
  bool is_explicit(void) const;
};

static_assert(sizeof(CXXDeductionGuideDecl) == sizeof(FunctionDecl));

#endif
} // namespace mx
