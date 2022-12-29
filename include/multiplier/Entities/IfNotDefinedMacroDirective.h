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

#include "ConditionalMacroDirective.h"
#include "MacroKind.h"

namespace mx {
class ConditionalMacroDirective;
class IfNotDefinedMacroDirective;
class Macro;
class MacroDirective;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using IfNotDefinedMacroDirectiveRange = DerivedEntityRange<MacroIterator, IfNotDefinedMacroDirective>;
using IfNotDefinedMacroDirectiveContainingMacroRange = DerivedEntityRange<ParentMacroIteratorImpl<Macro>, IfNotDefinedMacroDirective>;

class IfNotDefinedMacroDirective : public ConditionalMacroDirective {
 private:
  friend class FragmentImpl;
  friend class ConditionalMacroDirective;
  friend class MacroDirective;
  friend class Macro;
 public:
  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::IF_NOT_DEFINED_DIRECTIVE;
  }

  static IfNotDefinedMacroDirectiveContainingMacroRange containing(const Macro &macro);
  bool contains(const Macro &macro);

  static IfNotDefinedMacroDirectiveContainingMacroRange containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<IfNotDefinedMacroDirective> from(const ConditionalMacroDirective &parent);

  inline static std::optional<IfNotDefinedMacroDirective> from(const std::optional<ConditionalMacroDirective> &parent) {
    if (parent) {
      return IfNotDefinedMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<IfNotDefinedMacroDirective> from(const MacroDirective &parent);

  inline static std::optional<IfNotDefinedMacroDirective> from(const std::optional<MacroDirective> &parent) {
    if (parent) {
      return IfNotDefinedMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<IfNotDefinedMacroDirective> from(const Macro &parent);

  inline static std::optional<IfNotDefinedMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return IfNotDefinedMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(IfNotDefinedMacroDirective) == sizeof(ConditionalMacroDirective));

#endif
} // namespace mx
