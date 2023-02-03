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

#include "MacroDirective.h"
#include "MacroKind.h"

namespace mx {
class DefineMacroDirective;
class Macro;
class MacroDirective;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DefineMacroDirective : public MacroDirective {
 private:
  friend class FragmentImpl;
  friend class MacroDirective;
  friend class Macro;
 public:
  inline static gap::generator<DefineMacroDirective> in(const Fragment &frag) {
    for (auto m : in_internal(frag)) {
      if (auto d = from(m)) {
        co_yield *d;
      }
    }
  }

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::DEFINE_DIRECTIVE;
  }

  static gap::generator<DefineMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<DefineMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<DefineMacroDirective> from(const MacroDirective &parent);

  inline static std::optional<DefineMacroDirective> from(const std::optional<MacroDirective> &parent) {
    if (parent) {
      return DefineMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DefineMacroDirective> from(const Macro &parent);

  inline static std::optional<DefineMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return DefineMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token name(void) const;
  gap::generator<MacroOrToken> body(void) const;
  unsigned num_explicit_parameters(void) const;
  bool is_variadic(void) const;
  bool is_function_like(void) const;
  gap::generator<MacroOrToken> parameters(void) const;
};

static_assert(sizeof(DefineMacroDirective) == sizeof(MacroDirective));

#endif
} // namespace mx
