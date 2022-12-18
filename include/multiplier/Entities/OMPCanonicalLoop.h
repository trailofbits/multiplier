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
class CapturedStmt;
class DeclRefExpr;
class OMPCanonicalLoop;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPCanonicalLoopRange = DerivedEntityRange<StmtIterator, OMPCanonicalLoop>;
using OMPCanonicalLoopContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPCanonicalLoop>;
using OMPCanonicalLoopContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPCanonicalLoop>;

class OMPCanonicalLoop : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static OMPCanonicalLoopRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPCanonicalLoopContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPCanonicalLoop::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_CANONICAL_LOOP;
  }

  static OMPCanonicalLoopContainingStmtRange containing(const Decl &decl);
  static OMPCanonicalLoopContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPCanonicalLoop> from(const TokenContext &c);
  static std::optional<OMPCanonicalLoop> from(const Stmt &parent);

  inline static std::optional<OMPCanonicalLoop> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPCanonicalLoop::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  CapturedStmt distance_func(void) const;
  Stmt loop_statement(void) const;
  CapturedStmt loop_variable_func(void) const;
  DeclRefExpr loop_variable_reference(void) const;
};

static_assert(sizeof(OMPCanonicalLoop) == sizeof(Stmt));

#endif
} // namespace mx
