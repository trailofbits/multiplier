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

class Reference {
 private:
  OpaqueImplPtr impl;
  RawEntityId eid;
  EntityCategory category_;
  RawEntityId kind_id;

#define MX_FRIEND(type_name, lower_name, enum_name, category) \
    friend class type_name;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND)
#undef MX_FRIEND

  Reference(void) = delete;

  inline explicit Reference(OpaqueImplPtr impl_, RawEntityId eid_,
                            EntityCategory category__, RawEntityId kind_id_)
      : impl(std::move(impl_)),
        eid(eid_),
        category_(category__),
        kind_id(kind_id_) {}

  // Add a reference between two entities.
  static bool add(const ReferenceKind &kind, RawEntityId from_id,
                  RawEntityId to_id, int);

 public:

  template <typename T, typename U>
  inline static bool add(const ReferenceKind &kind, SpecificEntityId<T> from_id,
                         SpecificEntityId<U> to_id) {
    return add(kind, from_id.Pack(), to_id.Pack(), 0);
  }

  template <typename T>
  inline static bool add(const ReferenceKind &kind, SpecificEntityId<T> from_id,
                         EntityId to_id) {
    return add(kind, from_id.Pack(), to_id.Pack(), 0);
  }

  template <typename T>
  inline static bool add(const ReferenceKind &kind, EntityId from_id,
                         SpecificEntityId<T> to_id) {
    return add(kind, from_id.Pack(), to_id.Pack(), 0);
  }

  inline static bool add(const ReferenceKind &kind, EntityId from_id,
                         EntityId to_id) {
    return add(kind, from_id.Pack(), to_id.Pack(), 0);
  }

  inline EntityCategory category(void) const noexcept {
    return category_;
  }

  // Was this reference added by the indexer?
  inline bool is_explicit_code_reference(void) const noexcept {
    return !kind_id;
  }

  // Return the kind of this reference.
  ReferenceKind kind(void) const noexcept;

  // Return this reference as a `VariantEntity`.
  VariantEntity as_variant(void) const noexcept;

#define MX_DECLARE_REF_GETTER(type_name, lower_name, enum_name, category) \
    std::optional<type_name> as_ ## lower_name (void) const noexcept;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_REF_GETTER,
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
