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
class Macro;
class MacroVAOptArgument;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MacroVAOptArgument : public Macro {
 private:
  friend class FragmentImpl;
  friend class Macro;
 public:
  static gap::generator<MacroVAOptArgument> in(const Fragment &frag);
  static gap::generator<MacroVAOptArgument> in(const File &file);

  static gap::generator<MacroVAOptArgument> in(const Index &index);
  static std::optional<MacroVAOptArgument> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::VA_OPT_ARGUMENT;
  }

  static gap::generator<MacroVAOptArgument> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<MacroVAOptArgument> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<MacroVAOptArgument> from(const Macro &parent);

  inline static std::optional<MacroVAOptArgument> from(const std::optional<Macro> &parent) {
    if (parent) {
      return MacroVAOptArgument::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MacroVAOptArgument> from(const Reference &r);
  static std::optional<MacroVAOptArgument> from(const TokenContext &t);

};

static_assert(sizeof(MacroVAOptArgument) == sizeof(Macro));

#endif
} // namespace mx
