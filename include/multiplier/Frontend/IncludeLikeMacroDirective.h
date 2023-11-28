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
class IncludeLikeMacroDirective;
class Macro;
class MacroDirective;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class IncludeLikeMacroDirective : public MacroDirective {
 private:
  friend class FragmentImpl;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<IncludeLikeMacroDirective> in(const Fragment &frag);
  static gap::generator<IncludeLikeMacroDirective> in(const File &file);

  static gap::generator<IncludeLikeMacroDirective> in(const Index &index);
  static std::optional<IncludeLikeMacroDirective> by_id(const Index &, EntityId);

  static gap::generator<IncludeLikeMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<IncludeLikeMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<IncludeLikeMacroDirective> from_base(const Macro &parent);
  inline static std::optional<IncludeLikeMacroDirective> from(const Macro &parent) {
    return from_base(parent);
  }
  static std::optional<IncludeLikeMacroDirective> from(const std::optional<Macro> &parent);
  static std::optional<IncludeLikeMacroDirective> from(const Reference &r);
  static std::optional<IncludeLikeMacroDirective> from(const VariantEntity &e);
  static std::optional<IncludeLikeMacroDirective> from(const TokenContext &t);

  std::optional<File> included_file(void) const;
};

static_assert(sizeof(IncludeLikeMacroDirective) == sizeof(MacroDirective));

#endif
} // namespace mx
