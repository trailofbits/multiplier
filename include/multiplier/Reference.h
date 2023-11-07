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

  RawEntityId id(void) const noexcept;

 public:

  // Get a reference kind for a builtin kind.
  static ReferenceKind get(const Index &, BuiltinReferenceKind kind);

  // Get or create a reference kind.
  static ReferenceKind get(const Index &, std::string_view name);

  // Is this a built-in reference kind?
  std::optional<BuiltinReferenceKind> builtin_reference_kind(void) const noexcept;

  // The name of this reference kind.
  std::string_view kind(void) const & noexcept;

  // The name of this reference kind.
  std::string kind(void) const && noexcept;
};

// A reference is an arbitrarily named/kinded relation between two entities,
// inducing a directed graph. Normally, the edges between entities are via
// built-in method calls on entity objects. These methods are generally derived
// from the PASTA API / Clang API, by way of the indexer serializing
// ASTs. References, however, enable more semantic relationships between
// entities to be expressed. By default, the indexer fills in several built-in
// references, e.g. between callers and callees. Most of these correspond to
// explicit references that appear in the code itself. Users, however, can
// use the reference API to augment the built-in graph, e.g. expressing patterns
// such as function pointer de-virtualization, by introducing their own
// reference edges using built-in kinds, or by creating entirely custom
// reference kinds for the sake of analysis result persistence.
//
// Although references are logically a `(from, kind, to)` triple, we store an
// additional `context` field. By default, `context` matches `from`. However,
// sometimes it differs. When it does, it's good to think about it as providing
// *visual* context for `from`, and thus is should be an entity that is a
// parent of `from`.
class Reference {
 private:
  OpaqueImplPtr impl;
  // The reference context will have entity id of referrer that references the
  // entity of interest.
  RawEntityId context_id;
  RawEntityId entity_id;
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
  static bool add_impl(RawEntityId kind_id, RawEntityId from_id,
                       RawEntityId to_id, RawEntityId context_id);

  inline static RawEntityId reference_kind_id(RawEntityId kind_id) noexcept {
    return kind_id;
  }

  inline static RawEntityId reference_kind_id(
      const ReferenceKind &kind) noexcept {
    return kind.id();
  }

 public:

  inline explicit Reference(OpaqueImplPtr impl_,
                            RawEntityId context_id_,
                            RawEntityId entity_id_,
                            RawEntityId kind_id_)
      : impl(std::move(impl_)),
        context_id(context_id_),
        entity_id(entity_id_),
        kind_id(kind_id_) {}

  static bool add(const ReferenceKind &kind, const VariantEntity &from,
                  const VariantEntity &to);

  static bool add(const ReferenceKind &kind, const VariantEntity &from,
                  const VariantEntity &to, const VariantEntity &context);

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
    return entity_id;
  }

  // Return the kind of this reference.
  ReferenceKind kind(void) const noexcept;

  // The contextual entity associated with this reference.
  VariantEntity context(void) const noexcept;

  // Generate all references from some kind of entity.
  static gap::generator<Reference> from(const VariantEntity &entity);

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
