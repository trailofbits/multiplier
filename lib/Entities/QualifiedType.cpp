// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/QualifiedType.h>

#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<QualifiedType> QualifiedType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = QualifiedType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool QualifiedType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : QualifiedType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<QualifiedType> QualifiedType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return QualifiedType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kQualifiedTypeDerivedKinds[] = {
    QualifiedType::static_kind(),
};

std::optional<QualifiedType> QualifiedType::from(const Type &parent) {
  switch (parent.kind()) {
    case QualifiedType::static_kind():
      return reinterpret_cast<const QualifiedType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<QualifiedType> QualifiedType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kQualifiedTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<QualifiedType> e = QualifiedType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<QualifiedType> QualifiedType::from(const Reference &r) {
  return QualifiedType::from(r.as_type());
}

std::optional<QualifiedType> QualifiedType::from(const TokenContext &t) {
  return QualifiedType::from(t.as_type());
}

LangAS QualifiedType::address_space(void) const {
  return static_cast<LangAS>(impl->reader.getVal238());
}

Type QualifiedType::atomic_unqualified_type(void) const {
  RawEntityId eid = impl->reader.getVal229();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool QualifiedType::has_address_space(void) const {
  return impl->reader.getVal231();
}

bool QualifiedType::has_non_trivial_obj_c_lifetime(void) const {
  return impl->reader.getVal232();
}

bool QualifiedType::has_non_trivial_to_primitive_copy_c_union(void) const {
  return impl->reader.getVal233();
}

bool QualifiedType::has_non_trivial_to_primitive_default_initialize_c_union(void) const {
  return impl->reader.getVal239();
}

bool QualifiedType::has_non_trivial_to_primitive_destruct_c_union(void) const {
  return impl->reader.getVal240();
}

bool QualifiedType::has_qualifiers(void) const {
  return impl->reader.getVal241();
}

bool QualifiedType::has_strong_or_weak_obj_c_lifetime(void) const {
  return impl->reader.getVal242();
}

bool QualifiedType::is_c_forbidden_l_value_type(void) const {
  return impl->reader.getVal243();
}

bool QualifiedType::is_cxx11_pod_type(void) const {
  return impl->reader.getVal244();
}

bool QualifiedType::is_cxx98_pod_type(void) const {
  return impl->reader.getVal245();
}

bool QualifiedType::is_canonical(void) const {
  return impl->reader.getVal246();
}

bool QualifiedType::is_canonical_as_parameter(void) const {
  return impl->reader.getVal247();
}

bool QualifiedType::is_const_qualified(void) const {
  return impl->reader.getVal248();
}

bool QualifiedType::is_constant(void) const {
  return impl->reader.getVal249();
}

bool QualifiedType::is_local_const_qualified(void) const {
  return impl->reader.getVal250();
}

bool QualifiedType::is_local_restrict_qualified(void) const {
  return impl->reader.getVal251();
}

bool QualifiedType::is_local_volatile_qualified(void) const {
  return impl->reader.getVal252();
}

bool QualifiedType::is_non_weak_in_mrr_with_obj_c_weak(void) const {
  return impl->reader.getVal253();
}

bool QualifiedType::is_null(void) const {
  return impl->reader.getVal254();
}

bool QualifiedType::is_obj_cgc_strong(void) const {
  return impl->reader.getVal255();
}

bool QualifiedType::is_obj_cgc_weak(void) const {
  return impl->reader.getVal256();
}

bool QualifiedType::is_pod_type(void) const {
  return impl->reader.getVal257();
}

bool QualifiedType::is_referenceable(void) const {
  return impl->reader.getVal258();
}

bool QualifiedType::is_restrict_qualified(void) const {
  return impl->reader.getVal259();
}

bool QualifiedType::is_trivial_type(void) const {
  return impl->reader.getVal260();
}

bool QualifiedType::is_trivially_copyable_type(void) const {
  return impl->reader.getVal261();
}

bool QualifiedType::is_trivially_relocatable_type(void) const {
  return impl->reader.getVal262();
}

bool QualifiedType::is_volatile_qualified(void) const {
  return impl->reader.getVal263();
}

bool QualifiedType::may_be_dynamic_class(void) const {
  return impl->reader.getVal264();
}

bool QualifiedType::may_be_not_dynamic_class(void) const {
  return impl->reader.getVal265();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
