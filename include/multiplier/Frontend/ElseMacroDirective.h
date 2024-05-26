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
class ElseMacroDirective;
class File;
class Macro;
class MacroDirective;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ElseMacroDirective : public ConditionalMacroDirective {
 private:
  friend class FragmentImpl;
  friend class ConditionalMacroDirective;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<ElseMacroDirective> in(const Index &index);
  static gap::generator<ElseMacroDirective> in(const Fragment &frag);
  static gap::generator<ElseMacroDirective> in(const File &file);
  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::ELSE_DIRECTIVE;
  }

  static gap::generator<ElseMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<ElseMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<ElseMacroDirective> by_id(const Index &, EntityId);

  static std::optional<ElseMacroDirective> from_base(const Macro &parent);
  inline static std::optional<ElseMacroDirective> from(const Macro &parent) {
    return from_base(parent);
  }
  static std::optional<ElseMacroDirective> from(const std::optional<Macro> &parent);
  static std::optional<ElseMacroDirective> from(const Reference &r);
  static std::optional<ElseMacroDirective> from(const VariantEntity &e);
  static std::optional<ElseMacroDirective> from(const TokenContext &t);

};

static_assert(sizeof(ElseMacroDirective) == sizeof(ConditionalMacroDirective));

#endif
} // namespace mx
