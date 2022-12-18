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
class MacroStringify;
class MacroSubstitution;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using MacroStringifyRange = DerivedEntityRange<MacroIterator, MacroStringify>;
using MacroStringifyContainingMacroRange = DerivedEntityRange<ParentMacroIteratorImpl<Macro>, MacroStringify>;

class MacroStringify : public MacroSubstitution {
 private:
  friend class FragmentImpl;
  friend class MacroSubstitution;
  friend class Macro;
 public:
  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::STRINGIFY;
  }

  static MacroStringifyContainingMacroRange containing(const Macro &macro);
  bool contains(const Macro &macro);

  static MacroStringifyContainingMacroRange containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<MacroStringify> from(const MacroSubstitution &parent);

  inline static std::optional<MacroStringify> from(const std::optional<MacroSubstitution> &parent) {
    if (parent) {
      return MacroStringify::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MacroStringify> from(const Macro &parent);

  inline static std::optional<MacroStringify> from(const std::optional<Macro> &parent) {
    if (parent) {
      return MacroStringify::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(MacroStringify) == sizeof(MacroSubstitution));

#endif
} // namespace mx
