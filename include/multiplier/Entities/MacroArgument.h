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

#include "Macro.h"
#include "MacroKind.h"

namespace mx {
class Macro;
class MacroArgument;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using MacroArgumentRange = DerivedEntityRange<MacroIterator, MacroArgument>;
using MacroArgumentContainingMacroRange = DerivedEntityRange<ParentMacroIteratorImpl<Macro>, MacroArgument>;

class MacroArgument : public Macro {
 private:
  friend class FragmentImpl;
  friend class Macro;
 public:
  inline static MacroArgumentRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::ARGUMENT;
  }

  static MacroArgumentContainingMacroRange containing(const Macro &macro);
  bool contains(const Macro &macro);

  static MacroArgumentContainingMacroRange containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<MacroArgument> from(const Macro &parent);

  inline static std::optional<MacroArgument> from(const std::optional<Macro> &parent) {
    if (parent) {
      return MacroArgument::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool is_variadic(void) const;
  unsigned index(void) const;
};

static_assert(sizeof(MacroArgument) == sizeof(Macro));

#endif
} // namespace mx
