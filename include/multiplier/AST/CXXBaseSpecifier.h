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

#include <multiplier/AST/AccessSpecifier.h>
#include <multiplier/AST/PseudoKind.h>
#include <multiplier/AST/TagTypeKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Reference;
class CXXBaseSpecifier;
class CXXBaseSpecifierImpl;
class CXXRecordDecl;
class File;
class Token;
class TokenRange;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CXXBaseSpecifier {
 public:
  std::optional<Decl> parent_declaration(void) const;
std::optional<uint64_t> offset_in_bits(void) const;
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
  friend class ir::Operation;
  friend class ir::Value;

  std::shared_ptr<const CXXBaseSpecifierImpl> impl;
  static std::shared_ptr<EntityProvider> entity_provider_of(const Index &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const Fragment &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const File &);
 public:
  CXXBaseSpecifier(CXXBaseSpecifier &&) noexcept = default;
  CXXBaseSpecifier(const CXXBaseSpecifier &) = default;
  CXXBaseSpecifier &operator=(CXXBaseSpecifier &&) noexcept = default;
  CXXBaseSpecifier &operator=(const CXXBaseSpecifier &) = default;

  inline bool operator==(const CXXBaseSpecifier &rhs) const noexcept {
    return id().Pack() == rhs.id().Pack();
  }

  /* implicit */ inline CXXBaseSpecifier(std::shared_ptr<const CXXBaseSpecifierImpl> impl_)
      : impl(std::move(impl_)) {}

  constexpr inline static EntityCategory static_category(void) {
    return EntityCategory::CXX_BASE_SPECIFIER;
  }

  PackedCXXBaseSpecifierId id(void) const;

  static gap::generator<CXXBaseSpecifier> in(const Index &index);
  static gap::generator<CXXBaseSpecifier> in(const Fragment &frag);
  static gap::generator<CXXBaseSpecifier> in(const File &file);
  static gap::generator<CXXBaseSpecifier> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<CXXBaseSpecifier> by_id(const Index &, EntityId);

  inline static std::optional<CXXBaseSpecifier> from(const CXXBaseSpecifier &self) {
    return self;
  }

  inline static std::optional<CXXBaseSpecifier> from(const std::optional<CXXBaseSpecifier> &self) {
    return self;
  }

  static std::optional<CXXBaseSpecifier> from(const Reference &r);
  static std::optional<CXXBaseSpecifier> from(const VariantEntity &e);
  static std::optional<CXXBaseSpecifier> from(const TokenContext &t);

  TokenRange tokens(void) const;
  Token base_type_token(void) const;
  Token ellipsis_token(void) const;
  bool is_virtual(void) const;
  bool is_pack_expansion(void) const;
  bool constructors_are_inherited(void) const;
  TagTypeKind base_kind(void) const;
  AccessSpecifier semantic_access_specifier(void) const;
  AccessSpecifier lexical_access_specifier(void) const;
  Type base_type(void) const;
  std::optional<CXXRecordDecl> base_class(void) const;
};

#endif
} // namespace mx
