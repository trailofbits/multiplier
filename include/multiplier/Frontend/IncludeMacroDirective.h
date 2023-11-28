// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/Frontend/IncludeLikeMacroDirective.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class IncludeLikeMacroDirective;
class IncludeMacroDirective;
class Macro;
class MacroDirective;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class IncludeMacroDirective : public IncludeLikeMacroDirective {
 private:
  friend class FragmentImpl;
  friend class IncludeLikeMacroDirective;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<IncludeMacroDirective> in(const Fragment &frag);
  static gap::generator<IncludeMacroDirective> in(const File &file);

  static gap::generator<IncludeMacroDirective> in(const Index &index);
  static std::optional<IncludeMacroDirective> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::INCLUDE_DIRECTIVE;
  }

  static gap::generator<IncludeMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<IncludeMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<IncludeMacroDirective> from_base(const Macro &parent);
  inline static std::optional<IncludeMacroDirective> from(const Macro &parent) {
    return from_base(parent);
  }
  static std::optional<IncludeMacroDirective> from(const std::optional<Macro> &parent);
  static std::optional<IncludeMacroDirective> from(const Reference &r);
  static std::optional<IncludeMacroDirective> from(const VariantEntity &e);
  static std::optional<IncludeMacroDirective> from(const TokenContext &t);

};

static_assert(sizeof(IncludeMacroDirective) == sizeof(IncludeLikeMacroDirective));

#endif
} // namespace mx
