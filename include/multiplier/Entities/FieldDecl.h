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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "DeclKind.h"
#include "DeclaratorDecl.h"
#include "InClassInitStyle.h"
#include "StmtUseSelector.h"
#include "TypeUseSelector.h"

namespace mx {
class Decl;
class DeclaratorDecl;
class Expr;
class FieldDecl;
class NamedDecl;
class ValueDecl;
class VariableArrayType;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class FieldDecl : public DeclaratorDecl {
 private:
  friend class FragmentImpl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<FieldDecl> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<FieldDecl> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : FieldDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::FIELD;
  }

  static gap::generator<FieldDecl> containing(const Decl &decl);
  static gap::generator<FieldDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<FieldDecl> from(const TokenContext &c);
  static std::optional<FieldDecl> from(const DeclaratorDecl &parent);

  inline static std::optional<FieldDecl> from(const std::optional<DeclaratorDecl> &parent) {
    if (parent) {
      return FieldDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FieldDecl> from(const ValueDecl &parent);

  inline static std::optional<FieldDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return FieldDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FieldDecl> from(const NamedDecl &parent);

  inline static std::optional<FieldDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return FieldDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FieldDecl> from(const Decl &parent);

  inline static std::optional<FieldDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return FieldDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Expr> bit_width(void) const;
  std::optional<VariableArrayType> captured_vla_type(void) const;
  InClassInitStyle in_class_initializer_style(void) const;
  std::optional<Expr> in_class_initializer(void) const;
  bool has_captured_vla_type(void) const;
  bool has_in_class_initializer(void) const;
  bool is_anonymous_struct_or_union(void) const;
  bool is_bit_field(void) const;
  bool is_mutable(void) const;
  bool is_unnamed_bitfield(void) const;
  bool is_zero_length_bit_field(void) const;
  bool is_zero_size(void) const;
};

static_assert(sizeof(FieldDecl) == sizeof(DeclaratorDecl));

#endif
} // namespace mx
