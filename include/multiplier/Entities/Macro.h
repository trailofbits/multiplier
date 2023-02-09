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

#include "MacroKind.h"

namespace mx {
class Macro;
class MacroImpl;
class Reference;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using MacroOrToken = std::variant<Macro, Token>;
class Macro {
 protected:
  friend class Attr;
  friend class Decl;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class Reference;
  friend class Stmt;
  friend class TokenContext;
  friend class Type;
  friend class MacroImpl;
  std::shared_ptr<const MacroImpl> impl;
  inline static const std::shared_ptr<EntityProvider> &entity_provider_of(const Index &);
  inline static const std::shared_ptr<EntityProvider> &entity_provider_of(const Fragment &);
 public:
  Macro(Macro &&) noexcept = default;
  Macro(const Macro &) = default;
  Macro &operator=(Macro &&) noexcept = default;
  Macro &operator=(const Macro &) = default;

  /* implicit */ inline Macro(std::shared_ptr<const MacroImpl> impl_)
      : impl(std::move(impl_)) {}

  constexpr inline static EntityCategory static_category(void) {
    return EntityCategory::MACRO;
  }

  PackedMacroId id(void) const;
  gap::generator<Reference> references(void) const;

 protected:
  static gap::generator<Macro> containing_internal(const Token &token);

 public:
  static gap::generator<Macro> in(const Fragment &frag, std::span<MacroKind> kinds);
  static gap::generator<Macro> in(const Index &index, std::span<MacroKind> kinds);
  static gap::generator<Macro> in(const Fragment &frag);

  static gap::generator<Macro> in(const Index &index);
  static std::optional<Macro> by_id(const Index &, EntityId);

  static gap::generator<Macro> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<Macro> containing(const Token &token);
  bool contains(const Token &token);

  inline static std::optional<Macro> from(const Macro &self) {
    return self;
  }

  inline static std::optional<Macro> from(const std::optional<Macro> &self) {
    return self;
  }

  inline static std::optional<Macro> from(const Reference &r) {
    return r.as_macro();
  }

  inline static std::optional<Macro> from(const TokenContext &t) {
    return t.as_macro();
  }

  MacroKind kind(void) const;
  std::optional<Macro> parent(void) const;
  gap::generator<MacroOrToken> children(void) const;
};

#endif
} // namespace mx
