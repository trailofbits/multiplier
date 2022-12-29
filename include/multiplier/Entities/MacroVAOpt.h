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
class MacroSubstitution;
class MacroVAOpt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using MacroVAOptRange = DerivedEntityRange<MacroIterator, MacroVAOpt>;
using MacroVAOptContainingMacroRange = DerivedEntityRange<ParentMacroIteratorImpl<Macro>, MacroVAOpt>;

class MacroVAOpt : public MacroSubstitution {
 private:
  friend class FragmentImpl;
  friend class MacroSubstitution;
  friend class Macro;
 public:
  inline static MacroVAOptRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::VA_OPT;
  }

  static MacroVAOptContainingMacroRange containing(const Macro &macro);
  bool contains(const Macro &macro);

  static MacroVAOptContainingMacroRange containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<MacroVAOpt> from(const MacroSubstitution &parent);

  inline static std::optional<MacroVAOpt> from(const std::optional<MacroSubstitution> &parent) {
    if (parent) {
      return MacroVAOpt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MacroVAOpt> from(const Macro &parent);

  inline static std::optional<MacroVAOpt> from(const std::optional<Macro> &parent) {
    if (parent) {
      return MacroVAOpt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(MacroVAOpt) == sizeof(MacroSubstitution));

#endif
} // namespace mx
