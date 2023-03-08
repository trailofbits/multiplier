// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Macro.h"

namespace mx {
class Macro;
class MacroConcatenate;
class MacroExpansion;
class MacroStringify;
class MacroSubstitution;
class MacroVAOpt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MacroSubstitution : public Macro {
 private:
  friend class FragmentImpl;
  friend class Macro;
 public:
  static gap::generator<MacroSubstitution> in(const Fragment &frag);
  static gap::generator<MacroSubstitution> in(const File &file);

  static gap::generator<MacroSubstitution> in(const Index &index);
  static std::optional<MacroSubstitution> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::SUBSTITUTION;
  }

  static gap::generator<MacroSubstitution> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<MacroSubstitution> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<MacroSubstitution> from(const Macro &parent);

  inline static std::optional<MacroSubstitution> from(const std::optional<Macro> &parent) {
    if (parent) {
      return MacroSubstitution::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<MacroSubstitution> from(const Reference &r) {
    return MacroSubstitution::from(r.as_macro());
  }

  inline static std::optional<MacroSubstitution> from(const TokenContext &t) {
    return MacroSubstitution::from(t.as_macro());
  }

  gap::generator<MacroOrToken> replacement_children(void) const &;
};

static_assert(sizeof(MacroSubstitution) == sizeof(Macro));

#endif
} // namespace mx
