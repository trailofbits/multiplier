// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Macro.h"

namespace mx {
class EntityProvider;
class Index;
class Macro;
class MacroParameter;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MacroParameter : public Macro {
 private:
  friend class FragmentImpl;
  friend class Macro;
 public:
  static gap::generator<MacroParameter> in(const Fragment &frag);
  static gap::generator<MacroParameter> in(const File &file);

  static gap::generator<MacroParameter> in(const Index &index);
  static std::optional<MacroParameter> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::PARAMETER;
  }

  static gap::generator<MacroParameter> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<MacroParameter> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<MacroParameter> from(const Macro &parent);

  inline static std::optional<MacroParameter> from(const std::optional<Macro> &parent) {
    if (parent) {
      return MacroParameter::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MacroParameter> from(const Reference &r);
  static std::optional<MacroParameter> from(const TokenContext &t);

  Token variadic_dots(void) const;
  Token name(void) const;
  unsigned index(void) const;
};

static_assert(sizeof(MacroParameter) == sizeof(Macro));

#endif
} // namespace mx
