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
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class Stmt;
class SwitchCase;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SwitchCase : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<SwitchCase> in(const Fragment &frag);
  static gap::generator<SwitchCase> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static gap::generator<StmtKind> derived_kinds(void);
  static gap::generator<SwitchCase> containing(const Decl &decl);
  static gap::generator<SwitchCase> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<SwitchCase> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<SwitchCase> from(const TokenContext &t) {
    return from(t.as_statement());
  }

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
