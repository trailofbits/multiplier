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
class DefineMacroDirective;
class ElseIfDefinedMacroDirective;
class ElseIfMacroDirective;
class ElseIfNotDefinedMacroDirective;
class ElseMacroDirective;
class EndIfMacroDirective;
class IfDefinedMacroDirective;
class IfMacroDirective;
class IfNotDefinedMacroDirective;
class ImportMacroDirective;
class IncludeMacroDirective;
class IncludeMacrosMacroDirective;
class IncludeNextMacroDirective;
class Macro;
class MacroDirective;
class OtherMacroDirective;
class PragmaMacroDirective;
class Token;
class UndefineMacroDirective;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MacroDirective : public Macro {
 private:
  friend class FragmentImpl;
  friend class Macro;
 public:
  static gap::generator<MacroDirective> in(const Fragment &frag);
  static gap::generator<MacroDirective> in(const File &file);

  static gap::generator<MacroDirective> in(const Index &index);
  static std::optional<MacroDirective> by_id(const Index &, EntityId);

  static gap::generator<MacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<MacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<MacroDirective> from(const Macro &parent);

  inline static std::optional<MacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return MacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MacroDirective> from(const Reference &r);
  static std::optional<MacroDirective> from(const TokenContext &t);

  Token hash(void) const;
  Token directive_name(void) const;
};

static_assert(sizeof(MacroDirective) == sizeof(Macro));

#endif
} // namespace mx
