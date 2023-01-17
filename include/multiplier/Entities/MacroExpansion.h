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
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "MacroKind.h"
#include "MacroSubstitution.h"
#include "MacroUseSelector.h"

namespace mx {
class DefineMacroDirective;
class Macro;
class MacroArgument;
class MacroExpansion;
class MacroSubstitution;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MacroExpansion : public MacroSubstitution {
 private:
  friend class FragmentImpl;
  friend class MacroSubstitution;
  friend class Macro;
 public:
  inline static gap::generator<MacroExpansion> in(const Fragment &frag) {
    for (auto m : in_internal(frag)) {
      if (auto d = from(m)) {
        co_yield *d;
      }
    }
  }

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::EXPANSION;
  }

  static gap::generator<MacroExpansion> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<MacroExpansion> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<MacroExpansion> from(const MacroSubstitution &parent);

  inline static std::optional<MacroExpansion> from(const std::optional<MacroSubstitution> &parent) {
    if (parent) {
      return MacroExpansion::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MacroExpansion> from(const Macro &parent);

  inline static std::optional<MacroExpansion> from(const std::optional<Macro> &parent) {
    if (parent) {
      return MacroExpansion::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<DefineMacroDirective> definition(void) const;
  std::vector<MacroArgument> arguments(void) const;
};

static_assert(sizeof(MacroExpansion) == sizeof(MacroSubstitution));

#endif
} // namespace mx
