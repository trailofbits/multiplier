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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "MacroDirective.h"
#include "MacroKind.h"

namespace mx {
class Macro;
class MacroDirective;
class PragmaMacroDirective;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class PragmaMacroDirective : public MacroDirective {
 private:
  friend class FragmentImpl;
  friend class MacroDirective;
  friend class Macro;
 public:
  inline static gap::generator<PragmaMacroDirective> in(const Fragment &frag) {
    for(auto m : in_internal(frag)) {
      if(auto d = from(m)) {
        co_yield *d;
      }
    }
  }

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::PRAGMA_DIRECTIVE;
  }

  static gap::generator<PragmaMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<PragmaMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<PragmaMacroDirective> from(const MacroDirective &parent);

  inline static std::optional<PragmaMacroDirective> from(const std::optional<MacroDirective> &parent) {
    if (parent) {
      return PragmaMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<PragmaMacroDirective> from(const Macro &parent);

  inline static std::optional<PragmaMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return PragmaMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(PragmaMacroDirective) == sizeof(MacroDirective));

#endif
} // namespace mx
