// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <gap/core/generator.hpp>
#include <memory>
#include <string>
#include <string_view>

#include "Entity.h"

namespace mx {

class Index;
class EntityProvider;
class Reference;
class ReferenceKindImpl;

using OpaqueImplPtr = std::shared_ptr<const void>;
using ReferenceKindImplPtr = std::shared_ptr<const ReferenceKindImpl>;
using WeakReferenceKindImplPtr = std::weak_ptr<const ReferenceKindImpl>;

enum class BuiltinReferenceKind {
  USE,  // Default value as some kind of uses.
  ADDRESS_OF,
  ASSIGNED_TO,
  ASSIGNEMENT,
  CALLS,
  CALL_ARGUMENT,
  USED_BY,
  DEREFERENCE,
  ENUMERATIONS,
  EXPANSION_OF,
  INCLUSION,
  INITIALZATION,
  CONDITIONAL_TEST,
  TYPE_CASTS,
  STATEMENT_USES,
  TYPE_TRAIT_USES,
};

inline static const char *EnumerationName(BuiltinReferenceKind) {
  return "BuiltinReferenceKind";
}

const char *EnumeratorName(BuiltinReferenceKind);

inline static constexpr unsigned NumEnumerators(BuiltinReferenceKind) {
  return 16;
}

class ReferenceKind {
 private:
  friend class Reference;
  friend class ReferenceKindImpl;

  ReferenceKindImplPtr impl;

  ReferenceKind(void) = delete;

  /* implicit */ inline ReferenceKind(ReferenceKindImplPtr impl_)
      : impl(std::move(impl_)) {}

 public:

  // Get or create a reference kind.
  static ReferenceKind get(const Index &, std::string_view name);

  // Is this a built-in reference kind?
  std::optional<BuiltinReferenceKind> builtin_reference_kind(void) const noexcept;

  // The name of this reference kind.
  const std::string &kind(void) const & noexcept;

  // The name of this reference kind.
  std::string kind(void) const && noexcept;
};

class Reference {
 private:
  OpaqueImplPtr impl;
  // The reference context will have entity id of referrer
  // that references the entity of interest.
  RawEntityId context_id;
  RawEntityId from_id;
  RawEntityId kind_id;

#define MX_FRIEND(type_name, lower_name, enum_name, category) \
    friend class type_name;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND)
#undef MX_FRIEND

  Reference(void) = delete;

  // Add a reference between two entities.
  static bool add(const ReferenceKind &kind, RawEntityId from_id,
                  RawEntityId to_id, RawEntityId context_id, int);

 public:

  inline explicit Reference(OpaqueImplPtr impl_,
                            RawEntityId context_id_,
                            RawEntityId from_id_,
                            RawEntityId kind_id_)
      : impl(std::move(impl_)),
        context_id(context_id_),
        from_id(from_id_),
        kind_id(kind_id_) {}

  // The context id will be same or ancestor of `from_id`. The default
  // value will be same as `from_id`.
  inline static bool add(const ReferenceKind &kind, EntityId from_id_,
                         EntityId to_id_, EntityId context_id_) {
    return add(kind, from_id_.Pack(), to_id_.Pack(), context_id_.Pack(), 0);
  }

  EntityCategory category(void) const noexcept;

  // Is this a built-in reference kind?
  inline std::optional<BuiltinReferenceKind>
  builtin_reference_kind(void) const noexcept {
    if (kind_id >= NumEnumerators(BuiltinReferenceKind{})) {
      return std::nullopt;
    }
    return static_cast<BuiltinReferenceKind>(kind_id);
  }

  // The ID of the referenced entity.
  inline EntityId referenced_entity_id(void) const noexcept {
    return from_id;
  }

  // Return the kind of this reference.
  ReferenceKind kind(void) const noexcept;

  // The contextual entity associated with this reference.
  VariantEntity context(void) const noexcept;

  // Generate all references to some kind of entity.
  static gap::generator<Reference> to(const VariantEntity &entity);

  // Return this reference as a `VariantEntity`.
  VariantEntity as_variant(void) const noexcept;

#define MX_DECLARE_REF_GETTER(type_name, lower_name, enum_name, category) \
    std::optional<type_name> as_ ## lower_name (void) const noexcept;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_REF_GETTER,
                              MX_DECLARE_REF_GETTER,
                              MX_DECLARE_REF_GETTER,
                              MX_DECLARE_REF_GETTER,
                              MX_DECLARE_REF_GETTER,
                              MX_DECLARE_REF_GETTER,
                              MX_DECLARE_REF_GETTER)
#undef MX_DECLARE_REF_GETTER

  // Implemented in `Index.h`.
  template <typename T>
  inline std::optional<T> as(void) const noexcept;
};

}  // namespace mx
