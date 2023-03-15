// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "MacroSubstitution.h"

namespace mx {
class EntityProvider;
class Index;
class Macro;
class MacroSubstitution;
class MacroVAOpt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MacroVAOpt : public MacroSubstitution {
 private:
  friend class FragmentImpl;
  friend class MacroSubstitution;
  friend class Macro;
 public:
  static gap::generator<MacroVAOpt> in(const Fragment &frag);
  static gap::generator<MacroVAOpt> in(const File &file);

  static gap::generator<MacroVAOpt> in(const Index &index);
  static std::optional<MacroVAOpt> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::VA_OPT;
  }

  static gap::generator<MacroVAOpt> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<MacroVAOpt> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<MacroVAOpt> from(const Macro &parent);

  inline static std::optional<MacroVAOpt> from(const std::optional<Macro> &parent) {
    if (parent) {
      return MacroVAOpt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MacroVAOpt> from(const Reference &r);
  static std::optional<MacroVAOpt> from(const TokenContext &t);

};

static_assert(sizeof(MacroVAOpt) == sizeof(MacroSubstitution));

#endif
} // namespace mx
