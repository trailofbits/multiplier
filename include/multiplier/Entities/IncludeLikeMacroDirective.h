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

#include "MacroDirective.h"
#include "MacroKind.h"

namespace mx {
class File;
class IncludeLikeMacroDirective;
class Macro;
class MacroDirective;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class IncludeLikeMacroDirective : public MacroDirective {
 private:
  friend class FragmentImpl;
  friend class MacroDirective;
  friend class Macro;
 public:
  inline static gap::generator<IncludeLikeMacroDirective> in(const Fragment &frag) {
    for (auto m : in_internal(frag)) {
      if (auto d = from(m)) {
        co_yield *d;
      }
    }
  }

  static gap::generator<IncludeLikeMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<IncludeLikeMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<IncludeLikeMacroDirective> from(const MacroDirective &parent);

  inline static std::optional<IncludeLikeMacroDirective> from(const std::optional<MacroDirective> &parent) {
    if (parent) {
      return IncludeLikeMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<IncludeLikeMacroDirective> from(const Macro &parent);

  inline static std::optional<IncludeLikeMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return IncludeLikeMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<File> included_file(void) const;
};

static_assert(sizeof(IncludeLikeMacroDirective) == sizeof(MacroDirective));

#endif
} // namespace mx
