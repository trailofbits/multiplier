// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/Frontend/Macro.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class File;
class Macro;
class MacroDirective;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT MacroDirective : public Macro {
 private:
  friend class FragmentImpl;
  friend class Macro;
 public:
  static gap::generator<MacroDirective> in(const Index &index);
  static gap::generator<MacroDirective> in(const Fragment &frag);
  static gap::generator<MacroDirective> in(const File &file);
  static gap::generator<MacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<MacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<MacroDirective> by_id(const Index &, EntityId);

  static std::optional<MacroDirective> from_base(const Macro &parent);
  inline static std::optional<MacroDirective> from(const Macro &parent) {
    return from_base(parent);
  }
  static std::optional<MacroDirective> from(const std::optional<Macro> &parent);
  static std::optional<MacroDirective> from(const Reference &r);
  static std::optional<MacroDirective> from(const VariantEntity &e);
  static std::optional<MacroDirective> from(const TokenContext &t);

  Token hash(void) const;
  Token directive_name(void) const;
};

static_assert(sizeof(MacroDirective) == sizeof(Macro));

#endif
} // namespace mx
