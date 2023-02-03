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

#include "DeclKind.h"
#include "NamedDecl.h"

namespace mx {
class Decl;
class LabelDecl;
class LabelStmt;
class NamedDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class LabelDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<LabelDecl> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<LabelDecl> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : LabelDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::LABEL;
  }

  static gap::generator<LabelDecl> containing(const Decl &decl);
  static gap::generator<LabelDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<LabelDecl> from(const TokenContext &c);
  static std::optional<LabelDecl> from(const NamedDecl &parent);

  inline static std::optional<LabelDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return LabelDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<LabelDecl> from(const Decl &parent);

  inline static std::optional<LabelDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return LabelDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view ms_assembly_label(void) const;
  LabelStmt statement(void) const;
  bool is_gnu_local(void) const;
  bool is_ms_assembly_label(void) const;
  bool is_resolved_ms_assembly_label(void) const;
};

static_assert(sizeof(LabelDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
