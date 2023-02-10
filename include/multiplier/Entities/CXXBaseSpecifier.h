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

#include "AccessSpecifier.h"
#include "PseudoKind.h"
#include "TagTypeKind.h"

namespace mx {
class CXXBaseSpecifier;
class CXXBaseSpecifierImpl;
class Reference;
class Token;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXBaseSpecifier {
 protected:
  friend class Attr;
  friend class Decl;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class Macro;
  friend class Reference;
  friend class Stmt;
  friend class TokenContext;
  friend class Type;
  friend class CXXBaseSpecifierImpl;
  std::shared_ptr<const CXXBaseSpecifierImpl> impl;
  inline static const std::shared_ptr<EntityProvider> &entity_provider_of(const Index &);
  inline static const std::shared_ptr<EntityProvider> &entity_provider_of(const Fragment &);
  inline static const std::shared_ptr<EntityProvider> &entity_provider_of(const File &);
 public:
  CXXBaseSpecifier(CXXBaseSpecifier &&) noexcept = default;
  CXXBaseSpecifier(const CXXBaseSpecifier &) = default;
  CXXBaseSpecifier &operator=(CXXBaseSpecifier &&) noexcept = default;
  CXXBaseSpecifier &operator=(const CXXBaseSpecifier &) = default;

  inline std::strong_ordering operator<=>(const CXXBaseSpecifier &rhs) const { return id() <=> rhs.id(); }

  /* implicit */ inline CXXBaseSpecifier(std::shared_ptr<const CXXBaseSpecifierImpl> impl_)
      : impl(std::move(impl_)) {}

  constexpr inline static EntityCategory static_category(void) {
    return EntityCategory::CXX_BASE_SPECIFIER;
  }

  PackedCXXBaseSpecifierId id(void) const;
  gap::generator<Reference> references(void) const;

  inline static std::optional<CXXBaseSpecifier> from(const CXXBaseSpecifier &self) {
    return self;
  }

  inline static std::optional<CXXBaseSpecifier> from(const std::optional<CXXBaseSpecifier> &self) {
    return self;
  }

  inline static std::optional<CXXBaseSpecifier> from(const Reference &r) {
    return r.as_cxx_base_specifier();
  }

  inline static std::optional<CXXBaseSpecifier> from(const TokenContext &t) {
    return t.as_cxx_base_specifier();
  }

  TokenRange tokens(void) const;
  Token base_type_token(void) const;
  bool is_virtual(void) const;
  TagTypeKind base_kind(void) const;
  bool is_pack_expansion(void) const;
  bool constructors_are_inherited(void) const;
  Token ellipsis_token(void) const;
  AccessSpecifier semantic_access_specifier(void) const;
  AccessSpecifier lexical_access_specifier(void) const;
  Type base_type(void) const;
};

#endif
} // namespace mx
