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

#include "ConditionalMacroDirective.h"
#include "MacroKind.h"

namespace mx {
class ConditionalMacroDirective;
class ElseIfMacroDirective;
class Macro;
class MacroDirective;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ElseIfMacroDirective : public ConditionalMacroDirective {
 private:
  friend class FragmentImpl;
  friend class ConditionalMacroDirective;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<ElseIfMacroDirective> in(const Fragment &frag);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::ELSE_IF_DIRECTIVE;
  }

  static gap::generator<ElseIfMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<ElseIfMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  inline static std::optional<ElseIfMacroDirective> from(const Reference &r) {
    return from(r.as_macro());
  }

  inline static std::optional<ElseIfMacroDirective> from(const TokenContext &t) {
    return from(t.as_macro());
  }

  static std::optional<ElseIfMacroDirective> from(const ConditionalMacroDirective &parent);

  inline static std::optional<ElseIfMacroDirective> from(const std::optional<ConditionalMacroDirective> &parent) {
    if (parent) {
      return ElseIfMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ElseIfMacroDirective> from(const MacroDirective &parent);

  inline static std::optional<ElseIfMacroDirective> from(const std::optional<MacroDirective> &parent) {
    if (parent) {
      return ElseIfMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ElseIfMacroDirective> from(const Macro &parent);

  inline static std::optional<ElseIfMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return ElseIfMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(ElseIfMacroDirective) == sizeof(ConditionalMacroDirective));

#endif
} // namespace mx
