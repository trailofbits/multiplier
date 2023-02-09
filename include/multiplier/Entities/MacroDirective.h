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
  static gap::generator<MacroDirective> in(const Fragment &frag);

  static gap::generator<MacroDirective> in(const Index &index);
  static std::optional<MacroDirective> by_id(const Index &, EntityId);

  static gap::generator<MacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<MacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  inline static std::optional<MacroDirective> from(const Reference &r) {
    return from(r.as_macro());
  }

  inline static std::optional<MacroDirective> from(const TokenContext &t) {
    return from(t.as_macro());
  }

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
