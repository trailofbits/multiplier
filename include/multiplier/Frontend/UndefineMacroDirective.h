// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/Frontend/MacroDirective.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Macro;
class MacroDirective;
class UndefineMacroDirective;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UndefineMacroDirective : public MacroDirective {
 private:
  friend class FragmentImpl;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<UndefineMacroDirective> in(const Fragment &frag);
  static gap::generator<UndefineMacroDirective> in(const File &file);

  static gap::generator<UndefineMacroDirective> in(const Index &index);
  static std::optional<UndefineMacroDirective> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::UNDEFINE_DIRECTIVE;
  }

  static gap::generator<UndefineMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<UndefineMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<UndefineMacroDirective> from_base(const Macro &parent);
  inline static std::optional<UndefineMacroDirective> from(const Macro &parent) {
    return from_base(parent);
  }
  static std::optional<UndefineMacroDirective> from(const std::optional<Macro> &parent);
  static std::optional<UndefineMacroDirective> from(const Reference &r);
  static std::optional<UndefineMacroDirective> from(const VariantEntity &e);
  static std::optional<UndefineMacroDirective> from(const TokenContext &t);

};

static_assert(sizeof(UndefineMacroDirective) == sizeof(MacroDirective));

#endif
} // namespace mx
