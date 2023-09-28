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
class ReferenceContextImpl;

using OpaqueImplPtr = std::shared_ptr<const void>;
using ReferenceKindImplPtr = std::shared_ptr<const ReferenceKindImpl>;
using WeakReferenceKindImplPtr = std::weak_ptr<const ReferenceKindImpl>;
using ReferenceContextImplPtr = std::shared_ptr<const ReferenceContextImpl>;

enum class BuiltinReferenceKind {
  USE = 0,    // default value as some kind of uses
  ADDRESS_OF,
  ASSIGNED_TO,
  ASSIGNEMENT,
  CALLS,
  CALL_ARGUMENT,
  DEFINITIONS,
  DECLARATIONS,
  USED_BY,
  DEREFERENCE,
  ENUMERATIONS,
  FUNCTIONS,
  EXPANSION_OF,
  INCLUSION,
  INITIALZATION,
  CONDITIONAL_TEST,
  TOP_LEVEL_ENTITIES,
  TYPES,
  TYPE_CASTS,
  VARIABLES,
  LOCAL_VARIABLES,
  GLOBAL_VARIABLES,
  THREAD_LOCAL_VARIABLES,
  STATIC_LOCAL_VARIABLES,
  PARAMETER_VARIABLES,
  STATEMENT_USES,
  TYPE_TRAIT_USES,
};

inline static const char *EnumerationName(BuiltinReferenceKind) {
  return "BuiltinReferenceKind";
}

inline static constexpr unsigned NumEnumerators(BuiltinReferenceKind) {
  return 26;
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

  // Was this reference added by the code?
  bool is_explicit_code_reference(void) const noexcept;

  // The name of this reference kind.
  const std::string &kind(void) const & noexcept;

  // The name of this reference kind.
  std::string kind(void) const && noexcept;
};

class ReferenceContext {
 private:
  ReferenceContextImplPtr impl;

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

 public:
  ReferenceContext(void) = delete;

  inline explicit ReferenceContext(ReferenceContextImplPtr impl_)
      : impl(std::move(impl_)) {}


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
};

class Reference {
 private:
  OpaqueImplPtr impl;
  // The reference context will have entity id of referrer
  // that references the entity of interest.
  ReferenceContextImplPtr context_;
  RawEntityId eid;
  EntityCategory category_;
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

  inline explicit Reference(OpaqueImplPtr impl_, ReferenceContextImplPtr context__,
                            RawEntityId eid_, EntityCategory category__, RawEntityId kind_id_)
      : impl(std::move(impl_)),
        context_(std::move(context__)),
        eid(eid_),
        category_(category__),
        kind_id(kind_id_) {}

  // Add a reference between two entities.
  static bool add(const ReferenceKind &kind, RawEntityId from_id,
                  RawEntityId to_id, RawEntityId context_id, int);

 public:
  // The context id will be same or ancestor of `from_id`. The default
  // value will be same as `from_id`.
  inline static bool add(const ReferenceKind &kind, EntityId from_id,
                         EntityId to_id, EntityId context_id) {
    return add(kind, from_id.Pack(), to_id.Pack(), context_id.Pack(), 0);
  }

  inline EntityCategory category(void) const noexcept {
    return category_;
  }

  // Was this reference added by the indexer?
  inline bool is_explicit_code_reference(void) const noexcept {
    return !kind_id;
  }

  // The ID of the referenced entity.
  inline EntityId referenced_entity_id(void) const noexcept {
    return eid;
  }

  // Return the kind of this reference.
  ReferenceKind kind(void) const noexcept;

  std::optional<ReferenceContext> context(void) const noexcept;

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
