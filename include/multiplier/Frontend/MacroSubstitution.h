// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/Frontend/Macro.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class File;
class Macro;
class MacroSubstitution;
class Token;
class TokenRange;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT MacroSubstitution : public Macro {
 private:
  friend class FragmentImpl;
  friend class Macro;
 public:
  static gap::generator<MacroSubstitution> in(const Index &index);
  static gap::generator<MacroSubstitution> in(const Fragment &frag);
  static gap::generator<MacroSubstitution> in(const File &file);
  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::SUBSTITUTION;
  }

  static gap::generator<MacroSubstitution> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<MacroSubstitution> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<MacroSubstitution> by_id(const Index &, EntityId);

  static std::optional<MacroSubstitution> from_base(const Macro &parent);
  inline static std::optional<MacroSubstitution> from(const Macro &parent) {
    return from_base(parent);
  }
  static std::optional<MacroSubstitution> from(const std::optional<Macro> &parent);
  static std::optional<MacroSubstitution> from(const Reference &r);
  static std::optional<MacroSubstitution> from(const VariantEntity &e);
  static std::optional<MacroSubstitution> from(const TokenContext &t);

  gap::generator<PreprocessedEntity> replacement_children(void) const &;
  Token first_fully_substituted_token(void) const;
  Token last_fully_substituted_token(void) const;
  Token name_or_operator(void) const;
  TokenRange parsed_tokens(void) const;

};

static_assert(sizeof(MacroSubstitution) == sizeof(Macro));

#endif
} // namespace mx
