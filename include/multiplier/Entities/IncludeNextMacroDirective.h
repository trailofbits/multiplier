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

#include "IncludeLikeMacroDirective.h"
#include "MacroKind.h"

namespace mx {
class IncludeLikeMacroDirective;
class IncludeNextMacroDirective;
class Macro;
class MacroDirective;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class IncludeNextMacroDirective : public IncludeLikeMacroDirective {
 private:
  friend class FragmentImpl;
  friend class IncludeLikeMacroDirective;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<IncludeNextMacroDirective> in(const Fragment &frag);
  static gap::generator<IncludeNextMacroDirective> in(const File &file);

  static gap::generator<IncludeNextMacroDirective> in(const Index &index);
  static std::optional<IncludeNextMacroDirective> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::INCLUDE_NEXT_DIRECTIVE;
  }

  static gap::generator<IncludeNextMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<IncludeNextMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<IncludeNextMacroDirective> from(const Macro &parent);

  inline static std::optional<IncludeNextMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return IncludeNextMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<IncludeNextMacroDirective> from(const Reference &r) {
    return IncludeNextMacroDirective::from(r.as_macro());
  }

  inline static std::optional<IncludeNextMacroDirective> from(const TokenContext &t) {
    return IncludeNextMacroDirective::from(t.as_macro());
  }

};

static_assert(sizeof(IncludeNextMacroDirective) == sizeof(IncludeLikeMacroDirective));

#endif
} // namespace mx
