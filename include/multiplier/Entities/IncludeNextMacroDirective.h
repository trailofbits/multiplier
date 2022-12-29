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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "IncludeLikeMacroDirective.h"
#include "MacroKind.h"

namespace mx {
class IncludeLikeMacroDirective;
class IncludeNextMacroDirective;
class Macro;
class MacroDirective;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using IncludeNextMacroDirectiveRange = DerivedEntityRange<MacroIterator, IncludeNextMacroDirective>;
using IncludeNextMacroDirectiveContainingMacroRange = DerivedEntityRange<ParentMacroIteratorImpl<Macro>, IncludeNextMacroDirective>;

class IncludeNextMacroDirective : public IncludeLikeMacroDirective {
 private:
  friend class FragmentImpl;
  friend class IncludeLikeMacroDirective;
  friend class MacroDirective;
  friend class Macro;
 public:
  inline static IncludeNextMacroDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::INCLUDE_NEXT_DIRECTIVE;
  }

  static IncludeNextMacroDirectiveContainingMacroRange containing(const Macro &macro);
  bool contains(const Macro &macro);

  static IncludeNextMacroDirectiveContainingMacroRange containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<IncludeNextMacroDirective> from(const IncludeLikeMacroDirective &parent);

  inline static std::optional<IncludeNextMacroDirective> from(const std::optional<IncludeLikeMacroDirective> &parent) {
    if (parent) {
      return IncludeNextMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<IncludeNextMacroDirective> from(const MacroDirective &parent);

  inline static std::optional<IncludeNextMacroDirective> from(const std::optional<MacroDirective> &parent) {
    if (parent) {
      return IncludeNextMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<IncludeNextMacroDirective> from(const Macro &parent);

  inline static std::optional<IncludeNextMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return IncludeNextMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(IncludeNextMacroDirective) == sizeof(IncludeLikeMacroDirective));

#endif
} // namespace mx
