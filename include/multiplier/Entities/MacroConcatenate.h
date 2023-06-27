// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "MacroSubstitution.h"

namespace mx {
class EntityProvider;
class Index;
class Macro;
class MacroConcatenate;
class MacroSubstitution;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MacroConcatenate : public MacroSubstitution {
 private:
  friend class FragmentImpl;
  friend class MacroSubstitution;
  friend class Macro;
 public:
  static gap::generator<MacroConcatenate> in(const Fragment &frag);
  static gap::generator<MacroConcatenate> in(const File &file);

  static gap::generator<MacroConcatenate> in(const Index &index);
  static std::optional<MacroConcatenate> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::CONCATENATE;
  }

  static gap::generator<MacroConcatenate> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<MacroConcatenate> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<MacroConcatenate> from(const Macro &parent);

  inline static std::optional<MacroConcatenate> from(const std::optional<Macro> &parent) {
    if (parent) {
      return MacroConcatenate::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MacroConcatenate> from(const Reference &r);
  static std::optional<MacroConcatenate> from(const TokenContext &t);

  Token pasted_token(void) const;
};

static_assert(sizeof(MacroConcatenate) == sizeof(MacroSubstitution));

#endif
} // namespace mx
