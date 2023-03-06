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

namespace mx {
class IncludeLikeMacroDirective;
class IncludeMacroDirective;
class Macro;
class MacroDirective;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class IncludeMacroDirective : public IncludeLikeMacroDirective {
 private:
  friend class FragmentImpl;
  friend class IncludeLikeMacroDirective;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<IncludeMacroDirective> in(const Fragment &frag);
  static gap::generator<IncludeMacroDirective> in(const File &file);

  static gap::generator<IncludeMacroDirective> in(const Index &index);
  static std::optional<IncludeMacroDirective> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::INCLUDE_DIRECTIVE;
  }

  static gap::generator<IncludeMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<IncludeMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<IncludeMacroDirective> from(const Macro &parent);

  inline static std::optional<IncludeMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return IncludeMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<IncludeMacroDirective> from(const Reference &r) {
    return IncludeMacroDirective::from(r.as_macro());
  }

  inline static std::optional<IncludeMacroDirective> from(const TokenContext &t) {
    return IncludeMacroDirective::from(t.as_macro());
  }

};

static_assert(sizeof(IncludeMacroDirective) == sizeof(IncludeLikeMacroDirective));

#endif
} // namespace mx
