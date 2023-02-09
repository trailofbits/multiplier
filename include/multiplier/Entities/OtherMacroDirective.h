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

#include "MacroDirective.h"
#include "MacroKind.h"

namespace mx {
class Macro;
class MacroDirective;
class OtherMacroDirective;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OtherMacroDirective : public MacroDirective {
 private:
  friend class FragmentImpl;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<OtherMacroDirective> in(const Fragment &frag);

  static gap::generator<OtherMacroDirective> in(const Index &index);
  std::optional<OtherMacroDirective> by(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::OTHER_DIRECTIVE;
  }

  static gap::generator<OtherMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<OtherMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  inline static std::optional<OtherMacroDirective> from(const Reference &r) {
    return from(r.as_macro());
  }

  inline static std::optional<OtherMacroDirective> from(const TokenContext &t) {
    return from(t.as_macro());
  }

  static std::optional<OtherMacroDirective> from(const MacroDirective &parent);

  inline static std::optional<OtherMacroDirective> from(const std::optional<MacroDirective> &parent) {
    if (parent) {
      return OtherMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OtherMacroDirective> from(const Macro &parent);

  inline static std::optional<OtherMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return OtherMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OtherMacroDirective) == sizeof(MacroDirective));

#endif
} // namespace mx
