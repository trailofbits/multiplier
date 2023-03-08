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

#include "ValueStmt.h"

namespace mx {
class Attr;
class AttributedStmt;
class Decl;
class Stmt;
class Token;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AttributedStmt : public ValueStmt {
 private:
  friend class FragmentImpl;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<AttributedStmt> in(const Fragment &frag);
  static gap::generator<AttributedStmt> in(const File &file);
  static gap::generator<AttributedStmt> in(const Index &index);
  static gap::generator<AttributedStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AttributedStmt> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::ATTRIBUTED_STMT;
  }

  static gap::generator<AttributedStmt> containing(const Decl &decl);
  static gap::generator<AttributedStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<AttributedStmt> containing(const Stmt &stmt);
  static gap::generator<AttributedStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<AttributedStmt> from(const Stmt &parent);

  inline static std::optional<AttributedStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return AttributedStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<AttributedStmt> from(const Reference &r) {
    return AttributedStmt::from(r.as_statement());
  }

  inline static std::optional<AttributedStmt> from(const TokenContext &t) {
    return AttributedStmt::from(t.as_statement());
  }

  Token attribute_token(void) const;
  std::optional<Attr> nth_attribute(unsigned n) const;
  unsigned num_attributes(void) const;
  gap::generator<Attr> attributes(void) const &;
  Stmt sub_statement(void) const;
};

static_assert(sizeof(AttributedStmt) == sizeof(ValueStmt));

#endif
} // namespace mx
