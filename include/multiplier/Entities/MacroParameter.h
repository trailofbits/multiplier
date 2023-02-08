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
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Macro.h"
#include "MacroKind.h"

namespace mx {
class Macro;
class MacroParameter;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MacroParameter : public Macro {
 private:
  friend class FragmentImpl;
  friend class Macro;
 public:
  static gap::generator<MacroParameter> in(const Fragment &frag);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::PARAMETER;
  }

  static gap::generator<MacroKind> derived_kinds(void);
  static gap::generator<MacroParameter> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<MacroParameter> containing(const Token &token);
  bool contains(const Token &token);

  inline static std::optional<MacroParameter> from(const Reference &r) {
    return from(r.as_macro());
  }

  inline static std::optional<MacroParameter> from(const TokenContext &t) {
    return from(t.as_macro());
  }

  static std::optional<MacroParameter> from(const Macro &parent);

  inline static std::optional<MacroParameter> from(const std::optional<Macro> &parent) {
    if (parent) {
      return MacroParameter::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token variadic_dots(void) const;
  Token name(void) const;
  unsigned index(void) const;
};

static_assert(sizeof(MacroParameter) == sizeof(Macro));

#endif
} // namespace mx
