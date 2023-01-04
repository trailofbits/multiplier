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

#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class CompoundStmt;
class MSDependentExistsStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using MSDependentExistsStmtRange = DerivedEntityRange<StmtIterator, MSDependentExistsStmt>;
using MSDependentExistsStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, MSDependentExistsStmt>;
using MSDependentExistsStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, MSDependentExistsStmt>;

class MSDependentExistsStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static MSDependentExistsStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static MSDependentExistsStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : MSDependentExistsStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::MS_DEPENDENT_EXISTS_STMT;
  }

  static MSDependentExistsStmtContainingStmtRange containing(const Decl &decl);
  static MSDependentExistsStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<MSDependentExistsStmt> from(const TokenContext &c);
  static std::optional<MSDependentExistsStmt> from(const Stmt &parent);

  inline static std::optional<MSDependentExistsStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return MSDependentExistsStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token keyword_token(void) const;
  CompoundStmt sub_statement(void) const;
  bool is_if_exists(void) const;
  bool is_if_not_exists(void) const;
};

static_assert(sizeof(MSDependentExistsStmt) == sizeof(Stmt));

#endif
} // namespace mx
