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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "IncludeLikeMacroDirective.h"

namespace mx {
class ImportMacroDirective;
class IncludeLikeMacroDirective;
class Macro;
class MacroDirective;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ImportMacroDirective : public IncludeLikeMacroDirective {
 private:
  friend class FragmentImpl;
  friend class IncludeLikeMacroDirective;
  friend class MacroDirective;
  friend class Macro;
 public:
  static gap::generator<ImportMacroDirective> in(const Fragment &frag);
  static gap::generator<ImportMacroDirective> in(const File &file);

  static gap::generator<ImportMacroDirective> in(const Index &index);
  static std::optional<ImportMacroDirective> by_id(const Index &, EntityId);

  inline static constexpr MacroKind static_kind(void) {
    return MacroKind::IMPORT_DIRECTIVE;
  }

  static gap::generator<ImportMacroDirective> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<ImportMacroDirective> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<ImportMacroDirective> from(const Macro &parent);

  inline static std::optional<ImportMacroDirective> from(const std::optional<Macro> &parent) {
    if (parent) {
      return ImportMacroDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ImportMacroDirective> from(const Reference &r) {
    return ImportMacroDirective::from(r.as_macro());
  }

  inline static std::optional<ImportMacroDirective> from(const TokenContext &t) {
    return ImportMacroDirective::from(t.as_macro());
  }

};

static_assert(sizeof(ImportMacroDirective) == sizeof(IncludeLikeMacroDirective));

#endif
} // namespace mx
