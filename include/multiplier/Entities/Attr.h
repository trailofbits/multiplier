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

#include <compare>

#include "AttrKind.h"

namespace mx {
class Attr;
class AttrImpl;
class File;
class Fragment;
class Index;
class Reference;
class SourceIR;
class Token;
class TokenRange;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class Attr {
 protected:
  friend class Decl;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class Macro;
  friend class Reference;
  friend class SourceIR;
  friend class Stmt;
  friend class TokenContext;
  friend class Type;
  friend class AttrImpl;
  std::shared_ptr<const AttrImpl> impl;
  static std::shared_ptr<EntityProvider> entity_provider_of(const Index &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const Fragment &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const File &);
 public:
  Attr(Attr &&) noexcept = default;
  Attr(const Attr &) = default;
  Attr &operator=(Attr &&) noexcept = default;
  Attr &operator=(const Attr &) = default;

  friend inline std::strong_ordering operator<=>(const Attr &lhs, const Attr &rhs) noexcept {
    return lhs.id().Pack() <=> rhs.id().Pack();
  }

  bool operator==(const Attr &) const noexcept = default;
  bool operator!=(const Attr &) const noexcept = default;

  /* implicit */ inline Attr(std::shared_ptr<const AttrImpl> impl_)
      : impl(std::move(impl_)) {}

  constexpr inline static EntityCategory static_category(void) {
    return EntityCategory::ATTRIBUTE;
  }

  PackedAttrId id(void) const;
  gap::generator<Reference> references(void) const &;

 public:
  static gap::generator<Attr> in(const Fragment &frag, std::span<AttrKind> kinds);
  static gap::generator<Attr> in(const File &file, std::span<AttrKind> kinds);
  static gap::generator<Attr> in(const Index &index, std::span<AttrKind> kinds);
  static gap::generator<Attr> in(const Fragment &frag);
  static gap::generator<Attr> in(const File &file);
  static gap::generator<Attr> in(const Index &index);
  static gap::generator<Attr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<Attr> by_id(const Index &, EntityId);

  inline static std::optional<Attr> from(const Attr &self) {
    return self;
  }

  inline static std::optional<Attr> from(const std::optional<Attr> &self) {
    return self;
  }

  inline static std::optional<Attr> from(const Reference &r) {
    return r.as_attribute();
  }

  inline static std::optional<Attr> from(const TokenContext &t) {
    return t.as_attribute();
  }

  Token token(void) const;
  bool is_implicit(void) const;
  bool is_inherited(void) const;
  bool is_late_parsed(void) const;
  bool is_pack_expansion(void) const;
  AttrKind kind(void) const;
  TokenRange tokens(void) const;
};

#endif
} // namespace mx
