// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/Frontend/Macro.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class File;
class Macro;
class MacroArgument;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT MacroArgument : public Macro {
 private:
  friend class FragmentImpl;
  friend class Macro;
 public:
  static gap::generator<MacroArgument> in(const Index &index);
  static gap::generator<MacroArgument> in(const Fragment &frag);
  static gap::generator<MacroArgument> in(const File &file);
  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::ARGUMENT;
  }

  static gap::generator<MacroArgument> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<MacroArgument> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<MacroArgument> by_id(const Index &, EntityId);

  static std::optional<MacroArgument> from_base(const Macro &parent);
  inline static std::optional<MacroArgument> from(const Macro &parent) {
    return from_base(parent);
  }
  static std::optional<MacroArgument> from(const std::optional<Macro> &parent);
  static std::optional<MacroArgument> from(const Reference &r);
  static std::optional<MacroArgument> from(const VariantEntity &e);
  static std::optional<MacroArgument> from(const TokenContext &t);

  bool is_variadic(void) const;
  uint32_t index(void) const;
};

static_assert(sizeof(MacroArgument) == sizeof(Macro));

#endif
} // namespace mx
