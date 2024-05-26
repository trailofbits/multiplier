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

#include <multiplier/AST/PseudoKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Reference;
class CXXCtorInitializer;
class CXXCtorInitializerImpl;
class FieldDecl;
class File;
class IndirectFieldDecl;
class Stmt;
class Token;
class TokenRange;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CXXCtorInitializer {
 public:
  std::optional<Decl> parent_declaration(void) const;
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
  friend class CXXCtorInitializerImpl;
  friend class ir::Operation;
  friend class ir::Value;

  std::shared_ptr<const CXXCtorInitializerImpl> impl;
  static std::shared_ptr<EntityProvider> entity_provider_of(const Index &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const Fragment &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const File &);
 public:
  CXXCtorInitializer(CXXCtorInitializer &&) noexcept = default;
  CXXCtorInitializer(const CXXCtorInitializer &) = default;
  CXXCtorInitializer &operator=(CXXCtorInitializer &&) noexcept = default;
  CXXCtorInitializer &operator=(const CXXCtorInitializer &) = default;

  inline bool operator==(const CXXCtorInitializer &rhs) const noexcept {
    return id().Pack() == rhs.id().Pack();
  }

  /* implicit */ inline CXXCtorInitializer(std::shared_ptr<const CXXCtorInitializerImpl> impl_)
      : impl(std::move(impl_)) {}

  constexpr inline static EntityCategory static_category(void) {
    return EntityCategory::CXX_CTOR_INITIALIZER;
  }

  PackedCXXCtorInitializerId id(void) const;

  static gap::generator<CXXCtorInitializer> in(const Index &index);
  static gap::generator<CXXCtorInitializer> in(const Fragment &frag);
  static gap::generator<CXXCtorInitializer> in(const File &file);
  static gap::generator<CXXCtorInitializer> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<CXXCtorInitializer> by_id(const Index &, EntityId);

  inline static std::optional<CXXCtorInitializer> from(const CXXCtorInitializer &self) {
    return self;
  }

  inline static std::optional<CXXCtorInitializer> from(const std::optional<CXXCtorInitializer> &self) {
    return self;
  }

  static std::optional<CXXCtorInitializer> from(const Reference &r);
  static std::optional<CXXCtorInitializer> from(const VariantEntity &e);
  static std::optional<CXXCtorInitializer> from(const TokenContext &t);

  bool is_base_initializer(void) const;
  bool is_member_initializer(void) const;
  bool is_any_member_initializer(void) const;
  bool is_indirect_member_initializer(void) const;
  bool is_in_class_member_initializer(void) const;
  bool is_delegating_initializer(void) const;
  bool is_pack_expansion(void) const;
  std::optional<bool> is_base_virtual(void) const;
  std::optional<FieldDecl> member(void) const;
  std::optional<FieldDecl> any_member(void) const;
  std::optional<IndirectFieldDecl> indirect_member(void) const;
  std::optional<Stmt> initializer(void) const;
  Token ellipsis_token(void) const;
  Token member_token(void) const;
  Token left_angle_token(void) const;
  Token right_angle_token(void) const;
  TokenRange tokens(void) const;
};

#endif
} // namespace mx
