// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/Frontend/MacroDirective.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class File;
class Macro;
class MacroDirective;
class PragmaMacroDirective;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT PragmaMacroDirective : public MacroDirective {
 private:
  friend class FragmentImpl;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<PragmaMacroDirective> in(const Index &index);
  static gap::generator<PragmaMacroDirective> in(const Fragment &frag);
  static gap::generator<PragmaMacroDirective> in(const File &file);
  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::PRAGMA_DIRECTIVE;
  }

  static gap::generator<PragmaMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<PragmaMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<PragmaMacroDirective> by_id(const Index &, EntityId);

  static std::optional<PragmaMacroDirective> from_base(const Macro &parent);
  inline static std::optional<PragmaMacroDirective> from(const Macro &parent) {
    return from_base(parent);
  }
  static std::optional<PragmaMacroDirective> from(const std::optional<Macro> &parent);
  static std::optional<PragmaMacroDirective> from(const Reference &r);
  static std::optional<PragmaMacroDirective> from(const VariantEntity &e);
  static std::optional<PragmaMacroDirective> from(const TokenContext &t);

};

static_assert(sizeof(PragmaMacroDirective) == sizeof(MacroDirective));

#endif
} // namespace mx
