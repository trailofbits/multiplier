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
class EndIfMacroDirective;
class IncludeLikeMacroDirective;
class Macro;
class MacroDirective;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using EndIfMacroDirectiveRange = DerivedEntityRange<MacroIterator, EndIfMacroDirective>;
using EndIfMacroDirectiveContainingMacroRange = DerivedEntityRange<ParentMacroIteratorImpl<Macro>, EndIfMacroDirective>;

class EndIfMacroDirective : public IncludeLikeMacroDirective {
 private:
  friend class FragmentImpl;
  friend class IncludeLikeMacroDirective;
  friend class MacroDirective;
  friend class Macro;
 public:
  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::END_IF_DIRECTIVE;
  }

  static EndIfMacroDirectiveContainingMacroRange containing(const Macro &macro);
  bool contains(const Macro &macro);

  static EndIfMacroDirectiveContainingMacroRange containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<EndIfMacroDirective> from(const IncludeLikeMacroDirective &parent);

  inline static std::optional<EndIfMacroDirective> from(const std::optional<IncludeLikeMacroDirective> &parent) {
    if (parent) {
      return EndIfMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<EndIfMacroDirective> from(const MacroDirective &parent);

  inline static std::optional<EndIfMacroDirective> from(const std::optional<MacroDirective> &parent) {
    if (parent) {
      return EndIfMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<EndIfMacroDirective> from(const Macro &parent);

  inline static std::optional<EndIfMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return EndIfMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(EndIfMacroDirective) == sizeof(IncludeLikeMacroDirective));

#endif
} // namespace mx
