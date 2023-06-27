// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "MacroDirective.h"

namespace mx {
class EntityProvider;
class Index;
class DefineMacroDirective;
class Macro;
class MacroDirective;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DefineMacroDirective : public MacroDirective {
 private:
  friend class FragmentImpl;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<DefineMacroDirective> in(const Fragment &frag);
  static gap::generator<DefineMacroDirective> in(const File &file);

  static gap::generator<DefineMacroDirective> in(const Index &index);
  static std::optional<DefineMacroDirective> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::DEFINE_DIRECTIVE;
  }

  static gap::generator<DefineMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<DefineMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<DefineMacroDirective> from(const Macro &parent);

  inline static std::optional<DefineMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return DefineMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DefineMacroDirective> from(const Reference &r);
  static std::optional<DefineMacroDirective> from(const TokenContext &t);

  Token name(void) const;
  gap::generator<MacroOrToken> body(void) const &;
  bool is_variadic(void) const;
  bool is_function_like(void) const;
  gap::generator<MacroOrToken> parameters(void) const &;
};

static_assert(sizeof(DefineMacroDirective) == sizeof(MacroDirective));

#endif
} // namespace mx
