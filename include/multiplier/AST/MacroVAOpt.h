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
class MacroVAOpt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MacroVAOpt : public Macro {
 private:
  friend class FragmentImpl;
  friend class Macro;
 public:
  static gap::generator<MacroVAOpt> in(const Fragment &frag);
  static gap::generator<MacroVAOpt> in(const File &file);

  static gap::generator<MacroVAOpt> in(const Index &index);
  static std::optional<MacroVAOpt> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::VA_OPT;
  }

  static gap::generator<MacroVAOpt> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<MacroVAOpt> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<MacroVAOpt> from_base(const Macro &parent);
  inline static std::optional<MacroVAOpt> from(const Macro &parent) {
    return from_base(parent);
  }
  static std::optional<MacroVAOpt> from(const std::optional<Macro> &parent);
  static std::optional<MacroVAOpt> from(const Reference &r);
  static std::optional<MacroVAOpt> from(const VariantEntity &e);
  static std::optional<MacroVAOpt> from(const TokenContext &t);

  bool contents_are_elided(void) const;
};

static_assert(sizeof(MacroVAOpt) == sizeof(Macro));

#endif
} // namespace mx
