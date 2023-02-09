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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

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
class OMPDeclareReductionDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<OMPDeclareReductionDecl> in(const Fragment &frag);
  static gap::generator<OMPDeclareReductionDecl> in(const Index &index);
  static gap::generator<OMPDeclareReductionDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<OMPDeclareReductionDecl> by(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OMP_DECLARE_REDUCTION;
  }

  static gap::generator<OMPDeclareReductionDecl> containing(const Decl &decl);
  static gap::generator<OMPDeclareReductionDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPDeclareReductionDecl> containing(const Stmt &stmt);
  static gap::generator<OMPDeclareReductionDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<OMPDeclareReductionDecl> redeclarations(void) const;
  inline static std::optional<OMPDeclareReductionDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<OMPDeclareReductionDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

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
  gap::generator<Decl> declarations_in_context(void) const;
};

static_assert(sizeof(OMPDeclareReductionDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
