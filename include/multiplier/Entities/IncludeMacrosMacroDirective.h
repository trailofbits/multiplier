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
class IncludeMacrosMacroDirective;
class Macro;
class MacroDirective;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class IncludeMacrosMacroDirective : public IncludeLikeMacroDirective {
 private:
  friend class FragmentImpl;
  friend class IncludeLikeMacroDirective;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<IncludeMacrosMacroDirective> in(const Fragment &frag);

  static gap::generator<IncludeMacrosMacroDirective> in(const Index &index);
  static std::optional<IncludeMacrosMacroDirective> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::INCLUDE_MACROS_DIRECTIVE;
  }

  static gap::generator<IncludeMacrosMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<IncludeMacrosMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  inline static std::optional<IncludeMacrosMacroDirective> from(const Reference &r) {
    return from(r.as_macro());
  }

  inline static std::optional<IncludeMacrosMacroDirective> from(const TokenContext &t) {
    return from(t.as_macro());
  }

  static std::optional<IncludeMacrosMacroDirective> from(const IncludeLikeMacroDirective &parent);

  inline static std::optional<IncludeMacrosMacroDirective> from(const std::optional<IncludeLikeMacroDirective> &parent) {
    if (parent) {
      return IncludeMacrosMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<IncludeMacrosMacroDirective> from(const MacroDirective &parent);

  inline static std::optional<IncludeMacrosMacroDirective> from(const std::optional<MacroDirective> &parent) {
    if (parent) {
      return IncludeMacrosMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<IncludeMacrosMacroDirective> from(const Macro &parent);

  inline static std::optional<IncludeMacrosMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return IncludeMacrosMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(IncludeMacrosMacroDirective) == sizeof(IncludeLikeMacroDirective));

#endif
} // namespace mx
