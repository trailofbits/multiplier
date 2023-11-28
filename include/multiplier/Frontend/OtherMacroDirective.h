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
class OtherMacroDirective;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OtherMacroDirective : public MacroDirective {
 private:
  friend class FragmentImpl;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<OtherMacroDirective> in(const Fragment &frag);
  static gap::generator<OtherMacroDirective> in(const File &file);

  static gap::generator<OtherMacroDirective> in(const Index &index);
  static std::optional<OtherMacroDirective> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::OTHER_DIRECTIVE;
  }

  static gap::generator<OtherMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<OtherMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<OtherMacroDirective> from_base(const Macro &parent);
  inline static std::optional<OtherMacroDirective> from(const Macro &parent) {
    return from_base(parent);
  }
  static std::optional<OtherMacroDirective> from(const std::optional<Macro> &parent);
  static std::optional<OtherMacroDirective> from(const Reference &r);
  static std::optional<OtherMacroDirective> from(const VariantEntity &e);
  static std::optional<OtherMacroDirective> from(const TokenContext &t);

};

static_assert(sizeof(OtherMacroDirective) == sizeof(MacroDirective));

#endif
} // namespace mx
