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

namespace mx {
class ConditionalMacroDirective;
class IfMacroDirective;
class Macro;
class MacroDirective;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class IfMacroDirective : public ConditionalMacroDirective {
 private:
  friend class FragmentImpl;
  friend class ConditionalMacroDirective;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<IfMacroDirective> in(const Fragment &frag);
  static gap::generator<IfMacroDirective> in(const File &file);

  static gap::generator<IfMacroDirective> in(const Index &index);
  static std::optional<IfMacroDirective> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::IF_DIRECTIVE;
  }

  static gap::generator<IfMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<IfMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<IfMacroDirective> from(const Macro &parent);

  inline static std::optional<IfMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return IfMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<IfMacroDirective> from(const Reference &r) {
    return IfMacroDirective::from(r.as_macro());
  }

  inline static std::optional<IfMacroDirective> from(const TokenContext &t) {
    return IfMacroDirective::from(t.as_macro());
  }

};

static_assert(sizeof(IfMacroDirective) == sizeof(ConditionalMacroDirective));

#endif
} // namespace mx
