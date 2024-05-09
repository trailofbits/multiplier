// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/QualifiedType.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kQualifiedTypeDerivedKinds[] = {
    QualifiedType::static_kind(),
};
}  // namespace

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
    if (auto base = index.type(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<QualifiedType> QualifiedType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<QualifiedType> QualifiedType::from_base(const Type &parent) {
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
      if (std::optional<QualifiedType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<QualifiedType> QualifiedType::from(const Reference &r) {
  return QualifiedType::from(r.as_type());
}

std::optional<QualifiedType> QualifiedType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<QualifiedType> QualifiedType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

LangAS QualifiedType::address_space(void) const {
  return static_cast<LangAS>(impl->reader.getVal27());
}

Type QualifiedType::atomic_unqualified_type(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool QualifiedType::has_address_space(void) const {
  return impl->reader.getVal20();
}

bool QualifiedType::has_non_trivial_obj_c_lifetime(void) const {
  return impl->reader.getVal21();
}

bool QualifiedType::has_non_trivial_to_primitive_copy_c_union(void) const {
  return impl->reader.getVal22();
}

bool QualifiedType::has_non_trivial_to_primitive_default_initialize_c_union(void) const {
  return impl->reader.getVal28();
}

bool QualifiedType::has_non_trivial_to_primitive_destruct_c_union(void) const {
  return impl->reader.getVal29();
}

bool QualifiedType::has_qualifiers(void) const {
  return impl->reader.getVal30();
}

bool QualifiedType::has_strong_or_weak_obj_c_lifetime(void) const {
  return impl->reader.getVal31();
}

bool QualifiedType::is_c_forbidden_l_value_type(void) const {
  return impl->reader.getVal32();
}

bool QualifiedType::is_cxx11_pod_type(void) const {
  return impl->reader.getVal33();
}

bool QualifiedType::is_cxx98_pod_type(void) const {
  return impl->reader.getVal34();
}

bool QualifiedType::is_canonical(void) const {
  return impl->reader.getVal35();
}

bool QualifiedType::is_canonical_as_parameter(void) const {
  return impl->reader.getVal36();
}

bool QualifiedType::is_const_qualified(void) const {
  return impl->reader.getVal37();
}

bool QualifiedType::is_constant(void) const {
  return impl->reader.getVal38();
}

bool QualifiedType::is_local_const_qualified(void) const {
  return impl->reader.getVal39();
}

bool QualifiedType::is_local_restrict_qualified(void) const {
  return impl->reader.getVal40();
}

bool QualifiedType::is_local_volatile_qualified(void) const {
  return impl->reader.getVal41();
}

bool QualifiedType::is_non_weak_in_mrr_with_obj_c_weak(void) const {
  return impl->reader.getVal42();
}

bool QualifiedType::is_null(void) const {
  return impl->reader.getVal43();
}

bool QualifiedType::is_obj_cgc_strong(void) const {
  return impl->reader.getVal44();
}

bool QualifiedType::is_obj_cgc_weak(void) const {
  return impl->reader.getVal45();
}

bool QualifiedType::is_pod_type(void) const {
  return impl->reader.getVal46();
}

bool QualifiedType::is_referenceable(void) const {
  return impl->reader.getVal47();
}

bool QualifiedType::is_restrict_qualified(void) const {
  return impl->reader.getVal48();
}

bool QualifiedType::is_trivial_type(void) const {
  return impl->reader.getVal49();
}

bool QualifiedType::is_trivially_copy_constructible_type(void) const {
  return impl->reader.getVal50();
}

bool QualifiedType::is_trivially_copyable_type(void) const {
  return impl->reader.getVal51();
}

bool QualifiedType::is_trivially_equality_comparable_type(void) const {
  return impl->reader.getVal52();
}

bool QualifiedType::is_trivially_relocatable_type(void) const {
  return impl->reader.getVal53();
}

bool QualifiedType::is_volatile_qualified(void) const {
  return impl->reader.getVal54();
}

bool QualifiedType::is_web_assembly_funcref_type(void) const {
  return impl->reader.getVal55();
}

bool QualifiedType::is_web_assembly_reference_type(void) const {
  return impl->reader.getVal56();
}

bool QualifiedType::may_be_dynamic_class(void) const {
  return impl->reader.getVal57();
}

bool QualifiedType::may_be_not_dynamic_class(void) const {
  return impl->reader.getVal58();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
