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
#include "OMPDeclareReductionDeclInitKind.h"
#include "ValueDecl.h"

namespace mx {
class Decl;
class Expr;
class NamedDecl;
class OMPDeclareReductionDecl;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPDeclareReductionDeclRange = DerivedEntityRange<DeclIterator, OMPDeclareReductionDecl>;
using OMPDeclareReductionDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPDeclareReductionDecl>;
using OMPDeclareReductionDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, OMPDeclareReductionDecl>;

class OMPDeclareReductionDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static OMPDeclareReductionDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPDeclareReductionDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPDeclareReductionDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OMP_DECLARE_REDUCTION;
  }

  static OMPDeclareReductionDeclContainingDeclRange containing(const Decl &decl);
  static OMPDeclareReductionDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPDeclareReductionDecl> from(const TokenContext &c);
  static std::optional<OMPDeclareReductionDecl> from(const ValueDecl &parent);

  inline static std::optional<OMPDeclareReductionDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return OMPDeclareReductionDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPDeclareReductionDecl> from(const NamedDecl &parent);

  inline static std::optional<OMPDeclareReductionDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return OMPDeclareReductionDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPDeclareReductionDecl> from(const Decl &parent);

  inline static std::optional<OMPDeclareReductionDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return OMPDeclareReductionDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr combiner(void) const;
  Expr combiner_in(void) const;
  Expr combiner_out(void) const;
  Expr initializer_original(void) const;
  Expr initializer_private(void) const;
  Expr initializer(void) const;
  OMPDeclareReductionDeclInitKind initializer_kind(void) const;
  std::vector<Decl> declarations_in_context(void) const;
};

static_assert(sizeof(OMPDeclareReductionDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
