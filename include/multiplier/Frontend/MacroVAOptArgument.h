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
class MacroVAOptArgument;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT MacroVAOptArgument : public Macro {
 private:
  friend class FragmentImpl;
  friend class Macro;
 public:
  static gap::generator<MacroVAOptArgument> in(const Index &index);
  static gap::generator<MacroVAOptArgument> in(const Fragment &frag);
  static gap::generator<MacroVAOptArgument> in(const File &file);
  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::VA_OPT_ARGUMENT;
  }

  static gap::generator<MacroVAOptArgument> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<MacroVAOptArgument> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<MacroVAOptArgument> by_id(const Index &, EntityId);

  static std::optional<MacroVAOptArgument> from_base(const Macro &parent);
  inline static std::optional<MacroVAOptArgument> from(const Macro &parent) {
    return from_base(parent);
  }
  static std::optional<MacroVAOptArgument> from(const std::optional<Macro> &parent);
  static std::optional<MacroVAOptArgument> from(const Reference &r);
  static std::optional<MacroVAOptArgument> from(const VariantEntity &e);
  static std::optional<MacroVAOptArgument> from(const TokenContext &t);

};

static_assert(sizeof(MacroVAOptArgument) == sizeof(Macro));

#endif
} // namespace mx
