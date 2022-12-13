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

#include "DeclUseSelector.h"
#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class Decl;
class DeclStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DeclStmtRange = DerivedEntityRange<StmtIterator, DeclStmt>;
using DeclStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, DeclStmt>;
using DeclStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, DeclStmt>;

class DeclStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static DeclStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DeclStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : DeclStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DECL_STMT;
  }

  static DeclStmtContainingStmtRange containing(const Decl &decl);
  static DeclStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<DeclStmt> from(const TokenContext &c);
  static std::optional<DeclStmt> from(const Stmt &parent);

  inline static std::optional<DeclStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return DeclStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<Decl> declarations(void) const;
  std::optional<Decl> single_declaration(void) const;
  bool is_single_declaration(void) const;
};

static_assert(sizeof(DeclStmt) == sizeof(Stmt));

#endif
} // namespace mx
