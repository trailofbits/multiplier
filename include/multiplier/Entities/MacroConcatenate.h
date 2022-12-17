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

#include "MacroKind.h"
#include "MacroSubstitution.h"

namespace mx {
class Macro;
class MacroConcatenate;
class MacroSubstitution;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using MacroConcatenateRange = DerivedEntityRange<MacroIterator, MacroConcatenate>;
using MacroConcatenateContainingMacroRange = DerivedEntityRange<ParentMacroIteratorImpl<Macro>, MacroConcatenate>;

class MacroConcatenate : public MacroSubstitution {
 private:
  friend class FragmentImpl;
  friend class MacroSubstitution;
  friend class Macro;
 public:
  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::CONCATENATE;
  }

  static MacroConcatenateContainingMacroRange containing(const Macro &macro);
  bool contains(const Macro &macro);

  static std::optional<MacroConcatenate> from(const MacroSubstitution &parent);

  inline static std::optional<MacroConcatenate> from(const std::optional<MacroSubstitution> &parent) {
    if (parent) {
      return MacroConcatenate::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MacroConcatenate> from(const Macro &parent);

  inline static std::optional<MacroConcatenate> from(const std::optional<Macro> &parent) {
    if (parent) {
      return MacroConcatenate::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(MacroConcatenate) == sizeof(MacroSubstitution));

#endif
} // namespace mx
