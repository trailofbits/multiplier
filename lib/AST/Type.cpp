// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/Type.h>
#include "../Reference.h"
#include <multiplier/Frontend/File.h>
#include <multiplier/Frontend/Token.h>

#include "../EntityProvider.h"
#include "../File.h"
#include "../Fragment.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

std::shared_ptr<EntityProvider> Type::entity_provider_of(const Index &index_) {
  return index_.impl;
}

std::shared_ptr<EntityProvider> Type::entity_provider_of(const Fragment &frag_) {
  return frag_.impl->ep;
}

std::shared_ptr<EntityProvider> Type::entity_provider_of(const File &file_) {
  return file_.impl->ep;
}

gap::generator<Type> Type::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = Type::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool Type::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : Type::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<Type> Type::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return index.type(eid.Pack());
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

gap::generator<Type> Type::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeImplPtr eptr : ep->TypesFor(ep)) {
    co_yield Type(std::move(eptr));
  }
}

gap::generator<Type> Type::in(const Index &index, std::span<const TypeKind> kinds) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      co_yield Type(std::move(eptr));
    }
  }
}

std::optional<Type> Type::from(const Reference &r) {
  return r.as_type();
}

std::optional<Type> Type::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return std::get<Type>(e);
}

std::optional<Type> Type::from(const TokenContext &t) {
  return t.as_type();
}

Type Type::desugared_type(void) const {
  RawEntityId eid = impl->reader.getVal0();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type Type::canonical_type(void) const {
  RawEntityId eid = impl->reader.getVal1();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool Type::is_qualified(void) const {
  return impl->reader.getVal2();
}

Type Type::unqualified_type(void) const {
  RawEntityId eid = impl->reader.getVal3();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<uint64_t> Type::size_in_bits(void) const {
  if (!impl->reader.getVal5()) {
    return std::nullopt;
  } else {
    return static_cast<uint64_t>(impl->reader.getVal4());
  }
  return std::nullopt;
}

std::optional<uint64_t> Type::alignment(void) const {
  if (!impl->reader.getVal7()) {
    return std::nullopt;
  } else {
    return static_cast<uint64_t>(impl->reader.getVal6());
  }
  return std::nullopt;
}

bool Type::accepts_obj_c_type_parameters(void) const {
  return impl->reader.getVal8();
}

bool Type::can_decay_to_pointer_type(void) const {
  return impl->reader.getVal9();
}

bool Type::can_have_nullability(void) const {
  return impl->reader.getVal10();
}

bool Type::contains_errors(void) const {
  return impl->reader.getVal11();
}

bool Type::contains_unexpanded_parameter_pack(void) const {
  return impl->reader.getVal12();
}

Linkage Type::linkage(void) const {
  return static_cast<Linkage>(impl->reader.getVal13());
}

TypeKind Type::kind(void) const {
  return static_cast<TypeKind>(impl->reader.getVal14());
}

Type Type::unqualified_desugared_type(void) const {
  RawEntityId eid = impl->reader.getVal15();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Visibility Type::visibility(void) const {
  return static_cast<Visibility>(impl->reader.getVal16());
}

bool Type::is_sizeless_vector_type(void) const {
  return impl->reader.getVal17();
}

bool Type::is_unresolved_type(void) const {
  return impl->reader.getVal18();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
