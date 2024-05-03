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

#include <multiplier/AST/Linkage.h>
#include <multiplier/AST/TypeKind.h>
#include <multiplier/AST/Visibility.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Reference;
class File;
class Token;
class TokenRange;
class Type;
class TypeImpl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT Type {
 public:
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
  friend class TypeImpl;
  friend class ir::Operation;
  friend class ir::Value;

  std::shared_ptr<const TypeImpl> impl;
  static std::shared_ptr<EntityProvider> entity_provider_of(const Index &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const Fragment &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const File &);
 public:
  Type(Type &&) noexcept = default;
  Type(const Type &) = default;
  Type &operator=(Type &&) noexcept = default;
  Type &operator=(const Type &) = default;

  inline bool operator==(const Type &rhs) const noexcept {
    return id().Pack() == rhs.id().Pack();
  }

  /* implicit */ inline Type(std::shared_ptr<const TypeImpl> impl_)
      : impl(std::move(impl_)) {}

  constexpr inline static EntityCategory static_category(void) {
    return EntityCategory::TYPE;
  }

  PackedTypeId id(void) const;

  TokenRange tokens(void) const;

 public:
  static gap::generator<Type> in(const Index &index, std::span<const TypeKind> kinds);
  static gap::generator<Type> in(const Index &index);
  static gap::generator<Type> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<Type> by_id(const Index &, EntityId);

  inline static std::optional<Type> from(const Type &self) {
    return self;
  }

  inline static std::optional<Type> from(const std::optional<Type> &self) {
    return self;
  }

  static std::optional<Type> from(const Reference &r);
  static std::optional<Type> from(const VariantEntity &e);
  static std::optional<Type> from(const TokenContext &t);

  Type desugared_type(void) const;
  Type canonical_type(void) const;
  bool is_qualified(void) const;
  Type unqualified_type(void) const;
  std::optional<uint64_t> size_in_bits(void) const;
  std::optional<uint64_t> alignment(void) const;
  bool accepts_obj_c_type_parameters(void) const;
  bool can_decay_to_pointer_type(void) const;
  bool can_have_nullability(void) const;
  bool contains_errors(void) const;
  bool contains_unexpanded_parameter_pack(void) const;
  Linkage linkage(void) const;
  TypeKind kind(void) const;
  Type unqualified_desugared_type(void) const;
  Visibility visibility(void) const;
  bool is_sizeless_vector_type(void) const;
  bool is_unresolved_type(void) const;
};

#endif
} // namespace mx
