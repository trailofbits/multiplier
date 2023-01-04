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
class OMPExecutableDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPExecutableDirectiveRange = DerivedEntityRange<StmtIterator, OMPExecutableDirective>;
using OMPExecutableDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPExecutableDirective>;
using OMPExecutableDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPExecutableDirective>;

class OMPExecutableDirective : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static OMPExecutableDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPExecutableDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPExecutableDirective::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  static OMPExecutableDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPExecutableDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPExecutableDirective> from(const TokenContext &c);
  static std::optional<OMPExecutableDirective> from(const Stmt &parent);

  inline static std::optional<OMPExecutableDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPExecutableDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Stmt associated_statement(void) const;
  CapturedStmt innermost_captured_statement(void) const;
  Stmt raw_statement(void) const;
  Stmt structured_block(void) const;
  bool has_associated_statement(void) const;
  bool is_standalone_directive(void) const;
};

static_assert(sizeof(OMPExecutableDirective) == sizeof(Stmt));

#endif
} // namespace mx
