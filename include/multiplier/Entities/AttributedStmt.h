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

#include "StmtKind.h"
#include "ValueStmt.h"

namespace mx {
class Attr;
class AttributedStmt;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using AttributedStmtRange = DerivedEntityRange<StmtIterator, AttributedStmt>;
using AttributedStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, AttributedStmt>;
using AttributedStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, AttributedStmt>;

class AttributedStmt : public ValueStmt {
 private:
  friend class FragmentImpl;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static AttributedStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AttributedStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : AttributedStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::ATTRIBUTED_STMT;
  }

  static AttributedStmtContainingStmtRange containing(const Decl &decl);
  static AttributedStmtContainingStmtRange containing(const Stmt &stmt);

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
  std::vector<Attr> attributes(void) const;
  Stmt sub_statement(void) const;
};

static_assert(sizeof(AttributedStmt) == sizeof(ValueStmt));

#endif
} // namespace mx
