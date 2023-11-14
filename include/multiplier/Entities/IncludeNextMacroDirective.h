// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "IncludeLikeMacroDirective.h"

namespace mx {
class EntityProvider;
class Index;
class IncludeLikeMacroDirective;
class IncludeNextMacroDirective;
class Macro;
class MacroDirective;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class IncludeNextMacroDirective : public IncludeLikeMacroDirective {
 private:
  friend class FragmentImpl;
  friend class IncludeLikeMacroDirective;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<IncludeNextMacroDirective> in(const Fragment &frag);
  static gap::generator<IncludeNextMacroDirective> in(const File &file);

  static gap::generator<IncludeNextMacroDirective> in(const Index &index);
  static std::optional<IncludeNextMacroDirective> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::INCLUDE_NEXT_DIRECTIVE;
  }

  static gap::generator<IncludeNextMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<IncludeNextMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<IncludeNextMacroDirective> from_base(const Macro &parent);
  inline static std::optional<IncludeNextMacroDirective> from(const Macro &parent) {
    return from_base(parent);
  }
  static std::optional<IncludeNextMacroDirective> from(const std::optional<Macro> &parent);
  static std::optional<IncludeNextMacroDirective> from(const Reference &r);
  static std::optional<IncludeNextMacroDirective> from(const VariantEntity &e);
  static std::optional<IncludeNextMacroDirective> from(const TokenContext &t);

};

static_assert(sizeof(IncludeNextMacroDirective) == sizeof(IncludeLikeMacroDirective));

#endif
} // namespace mx
