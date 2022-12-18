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

#include "StmtKind.h"
#include "ValueStmt.h"

namespace mx {
class LabelDecl;
class LabelStmt;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using LabelStmtRange = DerivedEntityRange<StmtIterator, LabelStmt>;
using LabelStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, LabelStmt>;
using LabelStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, LabelStmt>;

class LabelStmt : public ValueStmt {
 private:
  friend class FragmentImpl;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static LabelStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static LabelStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : LabelStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::LABEL_STMT;
  }

  static LabelStmtContainingStmtRange containing(const Decl &decl);
  static LabelStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<LabelStmt> from(const TokenContext &c);
  static std::optional<LabelStmt> from(const ValueStmt &parent);

  inline static std::optional<LabelStmt> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return LabelStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<LabelStmt> from(const Stmt &parent);

  inline static std::optional<LabelStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return LabelStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  LabelDecl declaration(void) const;
  Token identifier_token(void) const;
  std::string_view name(void) const;
  Stmt sub_statement(void) const;
  bool is_side_entry(void) const;
};

static_assert(sizeof(LabelStmt) == sizeof(ValueStmt));

#endif
} // namespace mx
