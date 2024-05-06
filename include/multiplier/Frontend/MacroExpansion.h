// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/Frontend/MacroSubstitution.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class DefineMacroDirective;
class Macro;
class MacroArgument;
class MacroExpansion;
class MacroSubstitution;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT MacroExpansion : public MacroSubstitution {
 private:
  friend class FragmentImpl;
  friend class MacroSubstitution;
  friend class Macro;
 public:
  static gap::generator<MacroExpansion> in(const Fragment &frag);
  static gap::generator<MacroExpansion> in(const File &file);

  static gap::generator<MacroExpansion> in(const Index &index);
  static std::optional<MacroExpansion> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::EXPANSION;
  }

  static gap::generator<MacroExpansion> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<MacroExpansion> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<MacroExpansion> from_base(const Macro &parent);
  inline static std::optional<MacroExpansion> from(const Macro &parent) {
    return from_base(parent);
  }
  static std::optional<MacroExpansion> from(const std::optional<Macro> &parent);
  static std::optional<MacroExpansion> from(const Reference &r);
  static std::optional<MacroExpansion> from(const VariantEntity &e);
  static std::optional<MacroExpansion> from(const TokenContext &t);

  gap::generator<PreprocessedEntity> intermediate_children(void) const &;
  std::optional<DefineMacroDirective> definition(void) const;
  std::optional<MacroArgument> nth_argument(unsigned n) const;
  unsigned num_arguments(void) const;
  gap::generator<MacroArgument> arguments(void) const &;
};

static_assert(sizeof(MacroExpansion) == sizeof(MacroSubstitution));

#endif
} // namespace mx
