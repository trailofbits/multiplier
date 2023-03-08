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

#include "LangAS.h"
#include "Type.h"

namespace mx {
class QualifiedType;
class Token;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class QualifiedType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<QualifiedType> in(const Fragment &frag);
  static gap::generator<QualifiedType> in(const File &file);
  static gap::generator<QualifiedType> in(const Index &index);
  static gap::generator<QualifiedType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<QualifiedType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::QUALIFIED;
  }

  static std::optional<QualifiedType> from(const Type &parent);

  inline static std::optional<QualifiedType> from(const std::optional<Type> &parent) {
    if (parent) {
      return QualifiedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<QualifiedType> from(const Reference &r) {
    return QualifiedType::from(r.as_type());
  }

  inline static std::optional<QualifiedType> from(const TokenContext &t) {
    return QualifiedType::from(t.as_type());
  }

  LangAS address_space(void) const;
  Type atomic_unqualified_type(void) const;
  bool has_address_space(void) const;
  bool has_non_trivial_obj_c_lifetime(void) const;
  bool has_non_trivial_to_primitive_copy_c_union(void) const;
  bool has_non_trivial_to_primitive_default_initialize_c_union(void) const;
  bool has_non_trivial_to_primitive_destruct_c_union(void) const;
  bool has_qualifiers(void) const;
  bool has_strong_or_weak_obj_c_lifetime(void) const;
  bool is_c_forbidden_l_value_type(void) const;
  bool is_cxx11_pod_type(void) const;
  bool is_cxx98_pod_type(void) const;
  bool is_canonical(void) const;
  bool is_canonical_as_parameter(void) const;
  bool is_const_qualified(void) const;
  bool is_constant(void) const;
  bool is_local_const_qualified(void) const;
  bool is_local_restrict_qualified(void) const;
  bool is_local_volatile_qualified(void) const;
  bool is_non_weak_in_mrr_with_obj_c_weak(void) const;
  bool is_null(void) const;
  bool is_obj_cgc_strong(void) const;
  bool is_obj_cgc_weak(void) const;
  bool is_pod_type(void) const;
  bool is_restrict_qualified(void) const;
  bool is_trivial_type(void) const;
  bool is_trivially_copyable_type(void) const;
  bool is_trivially_relocatable_type(void) const;
  bool is_volatile_qualified(void) const;
  bool may_be_dynamic_class(void) const;
  bool may_be_not_dynamic_class(void) const;
};

static_assert(sizeof(QualifiedType) == sizeof(Type));

#endif
} // namespace mx
