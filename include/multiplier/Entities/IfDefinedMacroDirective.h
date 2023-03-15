// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ConditionalMacroDirective.h"

namespace mx {
class EntityProvider;
class Index;
class ConditionalMacroDirective;
class IfDefinedMacroDirective;
class Macro;
class MacroDirective;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class IfDefinedMacroDirective : public ConditionalMacroDirective {
 private:
  friend class FragmentImpl;
  friend class ConditionalMacroDirective;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<IfDefinedMacroDirective> in(const Fragment &frag);
  static gap::generator<IfDefinedMacroDirective> in(const File &file);

  static gap::generator<IfDefinedMacroDirective> in(const Index &index);
  static std::optional<IfDefinedMacroDirective> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::IF_DEFINED_DIRECTIVE;
  }

  static gap::generator<IfDefinedMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<IfDefinedMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<IfDefinedMacroDirective> from(const Macro &parent);

  inline static std::optional<IfDefinedMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return IfDefinedMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<IfDefinedMacroDirective> from(const Reference &r);
  static std::optional<IfDefinedMacroDirective> from(const TokenContext &t);

};

static_assert(sizeof(IfDefinedMacroDirective) == sizeof(ConditionalMacroDirective));

#endif
} // namespace mx
