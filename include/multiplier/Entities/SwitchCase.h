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
#include "StmtUseSelector.h"

namespace mx {
class Stmt;
class SwitchCase;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using SwitchCaseRange = DerivedEntityRange<StmtIterator, SwitchCase>;
using SwitchCaseContainingTokenRange = DerivedEntityRange<TokenContextIterator, SwitchCase>;
using SwitchCaseContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, SwitchCase>;

class SwitchCase : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static SwitchCaseRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SwitchCaseContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : SwitchCase::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  static SwitchCaseContainingStmtRange containing(const Decl &decl);
  static SwitchCaseContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<SwitchCase> from(const TokenContext &c);
  static std::optional<SwitchCase> from(const Stmt &parent);

  inline static std::optional<SwitchCase> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return SwitchCase::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token colon_token(void) const;
  Token keyword_token(void) const;
  std::optional<SwitchCase> next_switch_case(void) const;
  Stmt sub_statement(void) const;
};

static_assert(sizeof(SwitchCase) == sizeof(Stmt));

#endif
} // namespace mx
