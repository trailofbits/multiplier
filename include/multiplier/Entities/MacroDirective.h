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

#include "Macro.h"
#include "MacroKind.h"

namespace mx {
class Macro;
class MacroDirective;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MacroDirective : public Macro {
 private:
  friend class FragmentImpl;
  friend class Macro;
 public:
  inline static gap::generator<MacroDirective> in(const Fragment &frag) {
    for (auto m : in_internal(frag)) {
      if (auto d = from(m)) {
        co_yield *d;
      }
    }
  }

  static gap::generator<MacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<MacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<MacroDirective> from(const Macro &parent);

  inline static std::optional<MacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return MacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token hash(void) const;
  Token directive_name(void) const;
};

static_assert(sizeof(MacroDirective) == sizeof(Macro));

#endif
} // namespace mx
