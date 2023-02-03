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

#include "ConditionalMacroDirective.h"
#include "MacroKind.h"

namespace mx {
class ConditionalMacroDirective;
class ElseMacroDirective;
class Macro;
class MacroDirective;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ElseMacroDirective : public ConditionalMacroDirective {
 private:
  friend class FragmentImpl;
  friend class ConditionalMacroDirective;
  friend class MacroDirective;
  friend class Macro;
 public:
  inline static gap::generator<ElseMacroDirective> in(const Fragment &frag) {
    for (auto m : in_internal(frag)) {
      if (auto d = from(m)) {
        co_yield *d;
      }
    }
  }

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::ELSE_DIRECTIVE;
  }

  static gap::generator<ElseMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<ElseMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<ElseMacroDirective> from(const ConditionalMacroDirective &parent);

  inline static std::optional<ElseMacroDirective> from(const std::optional<ConditionalMacroDirective> &parent) {
    if (parent) {
      return ElseMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ElseMacroDirective> from(const MacroDirective &parent);

  inline static std::optional<ElseMacroDirective> from(const std::optional<MacroDirective> &parent) {
    if (parent) {
      return ElseMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ElseMacroDirective> from(const Macro &parent);

  inline static std::optional<ElseMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return ElseMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(ElseMacroDirective) == sizeof(ConditionalMacroDirective));

#endif
} // namespace mx
