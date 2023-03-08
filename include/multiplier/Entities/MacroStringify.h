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
class MacroStringify;
class MacroSubstitution;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MacroStringify : public MacroSubstitution {
 private:
  friend class FragmentImpl;
  friend class MacroSubstitution;
  friend class Macro;
 public:
  static gap::generator<MacroStringify> in(const Fragment &frag);
  static gap::generator<MacroStringify> in(const File &file);

  static gap::generator<MacroStringify> in(const Index &index);
  static std::optional<MacroStringify> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::STRINGIFY;
  }

  static gap::generator<MacroStringify> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<MacroStringify> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<MacroStringify> from(const Macro &parent);

  inline static std::optional<MacroStringify> from(const std::optional<Macro> &parent) {
    if (parent) {
      return MacroStringify::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MacroStringify> from(const Reference &r);
  static std::optional<MacroStringify> from(const TokenContext &t);

};

static_assert(sizeof(MacroStringify) == sizeof(MacroSubstitution));

#endif
} // namespace mx
