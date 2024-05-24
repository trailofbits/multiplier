// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <compare>
#include <cstdint>
#include <filesystem>
#include <gap/coro/generator.hpp>
#include <memory>
#include <optional>
#include <span>
#include <vector>

#include "../Compiler.h"
#include "../Entity.h"
#include "../Iterator.h"
#include "../Frontend/TokenContext.h"

#include <multiplier/Frontend/MacroKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Reference;
class File;
class Macro;
class MacroImpl;
class Token;
class TokenRange;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using PreprocessedEntity = std::variant<Macro, Token, Fragment>;
class MX_EXPORT Macro {
 public:
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
  friend class ir::Operation;
  friend class ir::Value;

  std::shared_ptr<const MacroImpl> impl;
  static std::shared_ptr<EntityProvider> entity_provider_of(const Index &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const Fragment &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const File &);
 public:
  Macro(Macro &&) noexcept = default;
  Macro(const Macro &) = default;
  Macro &operator=(Macro &&) noexcept = default;
  Macro &operator=(const Macro &) = default;

  inline bool operator==(const Macro &rhs) const noexcept {
    return id().Pack() == rhs.id().Pack();
  }

  /* implicit */ inline Macro(std::shared_ptr<const MacroImpl> impl_)
      : impl(std::move(impl_)) {}

  constexpr inline static EntityCategory static_category(void) {
    return EntityCategory::MACRO;
  }

  PackedMacroId id(void) const;

 protected:
  static gap::generator<Macro> containing_internal(const Token &token);

 public:
  Macro root(void) const &;
  TokenRange use_tokens(void) const &;
  gap::generator<Token> generate_use_tokens(void) const &;
  TokenRange expansion_tokens(void) const &;
  gap::generator<Token> generate_expansion_tokens(void) const &;

  static gap::generator<Macro> in(const Index &index);
  static gap::generator<Macro> in(const Fragment &frag);
  static gap::generator<Macro> in(const File &file);
  static gap::generator<Macro> in(const Index &index, std::span<const MacroKind> kinds);
  static gap::generator<Macro> in(const Fragment &frag, std::span<const MacroKind> kinds);
  static gap::generator<Macro> in(const File &file, std::span<const MacroKind> kinds);
  static gap::generator<Macro> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<Macro> containing(const Token &token);
  bool contains(const Token &token);

  static std::optional<Macro> by_id(const Index &, EntityId);

  inline static std::optional<Macro> from(const Macro &self) {
    return self;
  }

  inline static std::optional<Macro> from(const std::optional<Macro> &self) {
    return self;
  }

  static std::optional<Macro> from(const Reference &r);
  static std::optional<Macro> from(const VariantEntity &e);
  static std::optional<Macro> from(const TokenContext &t);

  MacroKind kind(void) const;
  std::optional<Macro> parent(void) const;
  gap::generator<PreprocessedEntity> children(void) const &;
};

#endif
} // namespace mx
