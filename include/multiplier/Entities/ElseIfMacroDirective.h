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

#include "MacroDirective.h"
#include "MacroKind.h"

namespace mx {
class ElseIfMacroDirective;
class Macro;
class MacroDirective;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ElseIfMacroDirectiveRange = DerivedEntityRange<MacroIterator, ElseIfMacroDirective>;
using ElseIfMacroDirectiveContainingMacroRange = DerivedEntityRange<ParentMacroIteratorImpl<Macro>, ElseIfMacroDirective>;

class ElseIfMacroDirective : public MacroDirective {
 private:
  friend class FragmentImpl;
  friend class MacroDirective;
  friend class Macro;
 public:
  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::ELSE_IF_DIRECTIVE;
  }

  static ElseIfMacroDirectiveContainingMacroRange containing(const Macro &macro);
  bool contains(const Macro &macro);

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

static_assert(sizeof(ElseIfMacroDirective) == sizeof(MacroDirective));

#endif
} // namespace mx
