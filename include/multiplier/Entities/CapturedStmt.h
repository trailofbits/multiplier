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

#include "CapturedRegionKind.h"
#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class CapturedDecl;
class CapturedStmt;
class RecordDecl;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CapturedStmtRange = DerivedEntityRange<StmtIterator, CapturedStmt>;
using CapturedStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, CapturedStmt>;
using CapturedStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CapturedStmt>;

class CapturedStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static CapturedStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CapturedStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CapturedStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CAPTURED_STMT;
  }

  static CapturedStmtContainingStmtRange containing(const Decl &decl);
  static CapturedStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CapturedStmt> from(const TokenContext &c);
  static std::optional<CapturedStmt> from(const Stmt &parent);

  inline static std::optional<CapturedStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CapturedStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  CapturedDecl captured_declaration(void) const;
  RecordDecl captured_record_declaration(void) const;
  CapturedRegionKind captured_region_kind(void) const;
  Stmt captured_statement(void) const;
};

static_assert(sizeof(CapturedStmt) == sizeof(Stmt));

#endif
} // namespace mx
