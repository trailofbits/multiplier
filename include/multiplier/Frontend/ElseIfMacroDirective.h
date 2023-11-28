// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/Frontend/ConditionalMacroDirective.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class ConditionalMacroDirective;
class ElseIfMacroDirective;
class Macro;
class MacroDirective;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ElseIfMacroDirective : public ConditionalMacroDirective {
 private:
  friend class FragmentImpl;
  friend class ConditionalMacroDirective;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<ElseIfMacroDirective> in(const Fragment &frag);
  static gap::generator<ElseIfMacroDirective> in(const File &file);

  static gap::generator<ElseIfMacroDirective> in(const Index &index);
  static std::optional<ElseIfMacroDirective> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::ELSE_IF_DIRECTIVE;
  }

  static gap::generator<ElseIfMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<ElseIfMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<ElseIfMacroDirective> from_base(const Macro &parent);
  inline static std::optional<ElseIfMacroDirective> from(const Macro &parent) {
    return from_base(parent);
  }
  static std::optional<ElseIfMacroDirective> from(const std::optional<Macro> &parent);
  static std::optional<ElseIfMacroDirective> from(const Reference &r);
  static std::optional<ElseIfMacroDirective> from(const VariantEntity &e);
  static std::optional<ElseIfMacroDirective> from(const TokenContext &t);

};

static_assert(sizeof(ElseIfMacroDirective) == sizeof(ConditionalMacroDirective));

#endif
} // namespace mx
