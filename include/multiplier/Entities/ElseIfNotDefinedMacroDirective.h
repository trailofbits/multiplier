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

#include "ConditionalMacroDirective.h"
#include "MacroKind.h"

namespace mx {
class ConditionalMacroDirective;
class ElseIfNotDefinedMacroDirective;
class Macro;
class MacroDirective;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ElseIfNotDefinedMacroDirective : public ConditionalMacroDirective {
 private:
  friend class FragmentImpl;
  friend class ConditionalMacroDirective;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<ElseIfNotDefinedMacroDirective> in(const Fragment &frag);

  static gap::generator<ElseIfNotDefinedMacroDirective> in(const Index &index);
  std::optional<ElseIfNotDefinedMacroDirective> by(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::ELSE_IF_NOT_DEFINED_DIRECTIVE;
  }

  static gap::generator<ElseIfNotDefinedMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<ElseIfNotDefinedMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  inline static std::optional<ElseIfNotDefinedMacroDirective> from(const Reference &r) {
    return from(r.as_macro());
  }

  inline static std::optional<ElseIfNotDefinedMacroDirective> from(const TokenContext &t) {
    return from(t.as_macro());
  }

  static std::optional<ElseIfNotDefinedMacroDirective> from(const ConditionalMacroDirective &parent);

  inline static std::optional<ElseIfNotDefinedMacroDirective> from(const std::optional<ConditionalMacroDirective> &parent) {
    if (parent) {
      return ElseIfNotDefinedMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ElseIfNotDefinedMacroDirective> from(const MacroDirective &parent);

  inline static std::optional<ElseIfNotDefinedMacroDirective> from(const std::optional<MacroDirective> &parent) {
    if (parent) {
      return ElseIfNotDefinedMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ElseIfNotDefinedMacroDirective> from(const Macro &parent);

  inline static std::optional<ElseIfNotDefinedMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return ElseIfNotDefinedMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(ElseIfNotDefinedMacroDirective) == sizeof(ConditionalMacroDirective));

#endif
} // namespace mx
