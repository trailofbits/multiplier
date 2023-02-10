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
class IfNotDefinedMacroDirective;
class Macro;
class MacroDirective;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class IfNotDefinedMacroDirective : public ConditionalMacroDirective {
 private:
  friend class FragmentImpl;
  friend class ConditionalMacroDirective;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<IfNotDefinedMacroDirective> in(const Fragment &frag);
  static gap::generator<IfNotDefinedMacroDirective> in(const File &file);

  static gap::generator<IfNotDefinedMacroDirective> in(const Index &index);
  static std::optional<IfNotDefinedMacroDirective> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::IF_NOT_DEFINED_DIRECTIVE;
  }

  static gap::generator<IfNotDefinedMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<IfNotDefinedMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<IfNotDefinedMacroDirective> from(const Macro &parent);

  inline static std::optional<IfNotDefinedMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return IfNotDefinedMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<IfNotDefinedMacroDirective> from(const Reference &r) {
    return IfNotDefinedMacroDirective::from(r.as_macro());
  }

  inline static std::optional<IfNotDefinedMacroDirective> from(const TokenContext &t) {
    return IfNotDefinedMacroDirective::from(t.as_macro());
  }

};

static_assert(sizeof(IfNotDefinedMacroDirective) == sizeof(ConditionalMacroDirective));

#endif
} // namespace mx
