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

#include "CXXMethodDecl.h"
#include "DeclKind.h"
#include "DeclUseSelector.h"
#include "StmtUseSelector.h"

namespace mx {
class CXXDestructorDecl;
class CXXMethodDecl;
class Decl;
class DeclaratorDecl;
class Expr;
class FunctionDecl;
class NamedDecl;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXDestructorDeclRange = DerivedEntityRange<DeclIterator, CXXDestructorDecl>;
using CXXDestructorDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXDestructorDecl>;
using CXXDestructorDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, CXXDestructorDecl>;

class CXXDestructorDecl : public CXXMethodDecl {
 private:
  friend class FragmentImpl;
  friend class CXXMethodDecl;
  friend class FunctionDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static CXXDestructorDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXDestructorDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : CXXDestructorDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CXX_DESTRUCTOR;
  }

  static CXXDestructorDeclContainingDeclRange containing(const Decl &decl);
  static CXXDestructorDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXDestructorDecl> from(const TokenContext &c);
  static std::optional<CXXDestructorDecl> from(const CXXMethodDecl &parent);

  inline static std::optional<CXXDestructorDecl> from(const std::optional<CXXMethodDecl> &parent) {
    if (parent) {
      return CXXDestructorDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDestructorDecl> from(const FunctionDecl &parent);

  inline static std::optional<CXXDestructorDecl> from(const std::optional<FunctionDecl> &parent) {
    if (parent) {
      return CXXDestructorDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDestructorDecl> from(const DeclaratorDecl &parent);

  inline static std::optional<CXXDestructorDecl> from(const std::optional<DeclaratorDecl> &parent) {
    if (parent) {
      return CXXDestructorDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDestructorDecl> from(const ValueDecl &parent);

  inline static std::optional<CXXDestructorDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return CXXDestructorDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDestructorDecl> from(const NamedDecl &parent);

  inline static std::optional<CXXDestructorDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return CXXDestructorDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDestructorDecl> from(const Decl &parent);

  inline static std::optional<CXXDestructorDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return CXXDestructorDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<FunctionDecl> operator_delete(void) const;
  std::optional<Expr> operator_delete_this_argument(void) const;
};

static_assert(sizeof(CXXDestructorDecl) == sizeof(CXXMethodDecl));

#endif
} // namespace mx
