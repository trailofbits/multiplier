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
class ElseIfDefinedMacroDirective;
class IncludeLikeMacroDirective;
class Macro;
class MacroDirective;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ElseIfDefinedMacroDirectiveRange = DerivedEntityRange<MacroIterator, ElseIfDefinedMacroDirective>;
using ElseIfDefinedMacroDirectiveContainingMacroRange = DerivedEntityRange<ParentMacroIteratorImpl<Macro>, ElseIfDefinedMacroDirective>;

class ElseIfDefinedMacroDirective : public IncludeLikeMacroDirective {
 private:
  friend class FragmentImpl;
  friend class IncludeLikeMacroDirective;
  friend class MacroDirective;
  friend class Macro;
 public:
  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::ELSE_IF_DEFINED_DIRECTIVE;
  }

  static ElseIfDefinedMacroDirectiveContainingMacroRange containing(const Macro &macro);
  bool contains(const Macro &macro);

  static ElseIfDefinedMacroDirectiveContainingMacroRange containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<ElseIfDefinedMacroDirective> from(const IncludeLikeMacroDirective &parent);

  inline static std::optional<ElseIfDefinedMacroDirective> from(const std::optional<IncludeLikeMacroDirective> &parent) {
    if (parent) {
      return ElseIfDefinedMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ElseIfDefinedMacroDirective> from(const MacroDirective &parent);

  inline static std::optional<ElseIfDefinedMacroDirective> from(const std::optional<MacroDirective> &parent) {
    if (parent) {
      return ElseIfDefinedMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ElseIfDefinedMacroDirective> from(const Macro &parent);

  inline static std::optional<ElseIfDefinedMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return ElseIfDefinedMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(ElseIfDefinedMacroDirective) == sizeof(IncludeLikeMacroDirective));

#endif
} // namespace mx
