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
#include "TokenUseSelector.h"

namespace mx {
class DefineMacroDirective;
class Macro;
class MacroDirective;
class MacroReferenceRange;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DefineMacroDirectiveRange = DerivedEntityRange<MacroIterator, DefineMacroDirective>;
using DefineMacroDirectiveContainingMacroRange = DerivedEntityRange<ParentMacroIteratorImpl<Macro>, DefineMacroDirective>;

class DefineMacroDirective : public MacroDirective {
 private:
  friend class FragmentImpl;
  friend class MacroDirective;
  friend class Macro;
 public:
  inline static DefineMacroDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::DEFINE_DIRECTIVE;
  }

  static DefineMacroDirectiveContainingMacroRange containing(const Macro &macro);
  bool contains(const Macro &macro);

  static DefineMacroDirectiveContainingMacroRange containing(const Token &token);
  bool contains(const Token &token);

  MacroReferenceRange references(void) const;

  static std::optional<DefineMacroDirective> from(const MacroDirective &parent);

  inline static std::optional<DefineMacroDirective> from(const std::optional<MacroDirective> &parent) {
    if (parent) {
      return DefineMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DefineMacroDirective> from(const Macro &parent);

  inline static std::optional<DefineMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return DefineMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token name(void) const;
  std::vector<MacroOrToken> body(void) const;
  unsigned num_explicit_parameters(void) const;
  bool is_variadic(void) const;
  bool is_function_like(void) const;
  std::vector<MacroOrToken> parameters(void) const;
};

static_assert(sizeof(DefineMacroDirective) == sizeof(MacroDirective));

#endif
} // namespace mx
