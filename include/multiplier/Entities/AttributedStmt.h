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

#include "StmtKind.h"
#include "ValueStmt.h"

namespace mx {
class Attr;
class AttributedStmt;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AttributedStmt : public ValueStmt {
 private:
  friend class FragmentImpl;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<AttributedStmt> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<AttributedStmt> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : AttributedStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::ATTRIBUTED_STMT;
  }

  static gap::generator<AttributedStmt> containing(const Decl &decl);
  static gap::generator<AttributedStmt> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<AttributedStmt> from(const TokenContext &c);
  static std::optional<AttributedStmt> from(const ValueStmt &parent);

  inline static std::optional<AttributedStmt> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return AttributedStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AttributedStmt> from(const Stmt &parent);

  inline static std::optional<AttributedStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return AttributedStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token attribute_token(void) const;
  std::optional<Attr> nth_attribute(unsigned n) const;
  gap::generator<Attr> attributes(void) const;
  Stmt sub_statement(void) const;
};

static_assert(sizeof(AttributedStmt) == sizeof(ValueStmt));

#endif
} // namespace mx
