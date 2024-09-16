// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/Frontend/ConditionalMacroDirective.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class ConditionalMacroDirective;
class File;
class IfNotDefinedMacroDirective;
class Macro;
class MacroDirective;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT IfNotDefinedMacroDirective : public ConditionalMacroDirective {
 private:
  friend class FragmentImpl;
  friend class ConditionalMacroDirective;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<IfNotDefinedMacroDirective> in(const Index &index);
  static gap::generator<IfNotDefinedMacroDirective> in(const Fragment &frag);
  static gap::generator<IfNotDefinedMacroDirective> in(const File &file);
  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::IF_NOT_DEFINED_DIRECTIVE;
  }

  static gap::generator<IfNotDefinedMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<IfNotDefinedMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<IfNotDefinedMacroDirective> by_id(const Index &, EntityId);

  static std::optional<IfNotDefinedMacroDirective> from_base(const Macro &parent);
  inline static std::optional<IfNotDefinedMacroDirective> from(const Macro &parent) {
    return from_base(parent);
  }
  static std::optional<IfNotDefinedMacroDirective> from(const std::optional<Macro> &parent);
  static std::optional<IfNotDefinedMacroDirective> from(const Reference &r);
  static std::optional<IfNotDefinedMacroDirective> from(const VariantEntity &e);
  static std::optional<IfNotDefinedMacroDirective> from(const TokenContext &t);

};

static_assert(sizeof(IfNotDefinedMacroDirective) == sizeof(ConditionalMacroDirective));

#endif
} // namespace mx
