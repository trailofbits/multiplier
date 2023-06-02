// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Macro.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class Macro;
class MacroConcatenate;
class MacroExpansion;
class MacroParameterSubstitution;
class MacroStringify;
class MacroSubstitution;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MacroSubstitution : public Macro {
 private:
  friend class FragmentImpl;
  friend class Macro;
 public:
  static gap::generator<MacroSubstitution> in(const Fragment &frag);
  static gap::generator<MacroSubstitution> in(const File &file);

  static gap::generator<MacroSubstitution> in(const Index &index);
  static std::optional<MacroSubstitution> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::SUBSTITUTION;
  }

  static gap::generator<MacroSubstitution> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<MacroSubstitution> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<MacroSubstitution> from(const Macro &parent);

  inline static std::optional<MacroSubstitution> from(const std::optional<Macro> &parent) {
    if (parent) {
      return MacroSubstitution::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MacroSubstitution> from(const Reference &r);
  static std::optional<MacroSubstitution> from(const TokenContext &t);

  gap::generator<MacroOrToken> replacement_children(void) const &;
  Token first_fully_substituted_token(void) const;
  Token last_fully_substituted_token(void) const;
  std::optional<Stmt> covered_stmt(void) const;
  std::optional<Decl> covered_decl(void) const;
};

static_assert(sizeof(MacroSubstitution) == sizeof(Macro));

#endif
} // namespace mx
