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
class Macro;
class MacroDirective;
class UndefineMacroDirective;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using UndefineMacroDirectiveRange = DerivedEntityRange<MacroIterator, UndefineMacroDirective>;
using UndefineMacroDirectiveContainingMacroRange = DerivedEntityRange<ParentMacroIteratorImpl<Macro>, UndefineMacroDirective>;

class UndefineMacroDirective : public MacroDirective {
 private:
  friend class FragmentImpl;
  friend class MacroDirective;
  friend class Macro;
 public:
  inline static UndefineMacroDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::UNDEFINE_DIRECTIVE;
  }

  static UndefineMacroDirectiveContainingMacroRange containing(const Macro &macro);
  bool contains(const Macro &macro);

  static UndefineMacroDirectiveContainingMacroRange containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<UndefineMacroDirective> from(const MacroDirective &parent);

  inline static std::optional<UndefineMacroDirective> from(const std::optional<MacroDirective> &parent) {
    if (parent) {
      return UndefineMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UndefineMacroDirective> from(const Macro &parent);

  inline static std::optional<UndefineMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return UndefineMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(UndefineMacroDirective) == sizeof(MacroDirective));

#endif
} // namespace mx
