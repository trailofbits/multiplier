// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "DeclKind.h"
#include "FunctionDecl.h"

namespace mx {
class CXXConstructorDecl;
class CXXDeductionGuideDecl;
class Decl;
class DeclaratorDecl;
class FunctionDecl;
class NamedDecl;
class ParmVarDecl;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXDeductionGuideDeclRange = DerivedEntityRange<DeclIterator, CXXDeductionGuideDecl>;
using CXXDeductionGuideDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXDeductionGuideDecl>;
using CXXDeductionGuideDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, CXXDeductionGuideDecl>;

class CXXDeductionGuideDecl : public FunctionDecl {
 private:
  friend class FragmentImpl;
  friend class FunctionDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static CXXDeductionGuideDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXDeductionGuideDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CXXDeductionGuideDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CXX_DEDUCTION_GUIDE;
  }

  static CXXDeductionGuideDeclContainingDeclRange containing(const Decl &decl);
  static CXXDeductionGuideDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXDeductionGuideDecl> from(const TokenContext &c);
  static std::optional<CXXDeductionGuideDecl> from(const FunctionDecl &parent);

  inline static std::optional<CXXDeductionGuideDecl> from(const std::optional<FunctionDecl> &parent) {
    if (parent) {
      return CXXDeductionGuideDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDeductionGuideDecl> from(const DeclaratorDecl &parent);

  inline static std::optional<CXXDeductionGuideDecl> from(const std::optional<DeclaratorDecl> &parent) {
    if (parent) {
      return CXXDeductionGuideDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDeductionGuideDecl> from(const ValueDecl &parent);

  inline static std::optional<CXXDeductionGuideDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return CXXDeductionGuideDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDeductionGuideDecl> from(const NamedDecl &parent);

  inline static std::optional<CXXDeductionGuideDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return CXXDeductionGuideDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDeductionGuideDecl> from(const Decl &parent);

  inline static std::optional<CXXDeductionGuideDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return CXXDeductionGuideDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  CXXConstructorDecl corresponding_constructor(void) const;
  bool is_copy_deduction_candidate(void) const;
  bool is_explicit(void) const;
  std::vector<ParmVarDecl> parameter_declarations(void) const;
};

static_assert(sizeof(CXXDeductionGuideDecl) == sizeof(FunctionDecl));

#endif
} // namespace mx
