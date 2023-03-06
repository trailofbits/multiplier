// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCObjectPointerType.h>

#include <multiplier/Entities/ObjCInterfaceDecl.h>
#include <multiplier/Entities/ObjCInterfaceType.h>
#include <multiplier/Entities/ObjCObjectType.h>
#include <multiplier/Entities/ObjCProtocolDecl.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCObjectPointerType> ObjCObjectPointerType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCObjectPointerType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCObjectPointerType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCObjectPointerType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ObjCObjectPointerType> ObjCObjectPointerType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return ObjCObjectPointerType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kObjCObjectPointerTypeDerivedKinds[] = {
    ObjCObjectPointerType::static_kind(),
};

std::optional<ObjCObjectPointerType> ObjCObjectPointerType::from(const Type &parent) {
  switch (parent.kind()) {
    case ObjCObjectPointerType::static_kind():
      return reinterpret_cast<const ObjCObjectPointerType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCObjectPointerType> ObjCObjectPointerType::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (TypeKind k : kObjCObjectPointerTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<ObjCObjectPointerType> e = ObjCObjectPointerType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCObjectPointerType> ObjCObjectPointerType::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kObjCObjectPointerTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<ObjCObjectPointerType> e = ObjCObjectPointerType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCObjectPointerType> ObjCObjectPointerType::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kObjCObjectPointerTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<ObjCObjectPointerType> e = ObjCObjectPointerType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Type ObjCObjectPointerType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal291();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

ObjCInterfaceDecl ObjCObjectPointerType::interface_declaration(void) const {
  RawEntityId eid = impl->reader.getVal292();
  return ObjCInterfaceDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

ObjCInterfaceType ObjCObjectPointerType::interface_type(void) const {
  RawEntityId eid = impl->reader.getVal297();
  return ObjCInterfaceType::from(Type(impl->ep->TypeFor(impl->ep, eid))).value();
}

ObjCObjectType ObjCObjectPointerType::object_type(void) const {
  RawEntityId eid = impl->reader.getVal299();
  return ObjCObjectType::from(Type(impl->ep->TypeFor(impl->ep, eid))).value();
}

Type ObjCObjectPointerType::super_class_type(void) const {
  RawEntityId eid = impl->reader.getVal312();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<Type> ObjCObjectPointerType::nth_type_argument(unsigned n) const {
  auto list = impl->reader.getVal296();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TypeFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Type(std::move(e));
}

gap::generator<Type> ObjCObjectPointerType::type_arguments(void) const & {
  auto list = impl->reader.getVal296();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d296 = ep->TypeFor(ep, v)) {
      co_yield Type(std::move(d296));
    }
  }
  co_return;
}

gap::generator<Type> ObjCObjectPointerType::type_arguments_as_written(void) const & {
  auto list = impl->reader.getVal300();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d300 = ep->TypeFor(ep, v)) {
      co_yield Type(std::move(d300));
    }
  }
  co_return;
}

bool ObjCObjectPointerType::is_kind_of_type(void) const {
  return impl->reader.getVal293();
}

bool ObjCObjectPointerType::is_obj_c_id_or_class_type(void) const {
  return impl->reader.getVal294();
}

bool ObjCObjectPointerType::is_specialized(void) const {
  return impl->reader.getVal295();
}

bool ObjCObjectPointerType::is_specialized_as_written(void) const {
  return impl->reader.getVal301();
}

bool ObjCObjectPointerType::is_sugared(void) const {
  return impl->reader.getVal302();
}

bool ObjCObjectPointerType::is_unspecialized(void) const {
  return impl->reader.getVal303();
}

bool ObjCObjectPointerType::is_unspecialized_as_written(void) const {
  return impl->reader.getVal304();
}

std::optional<ObjCProtocolDecl> ObjCObjectPointerType::nth_qualifier(unsigned n) const {
  auto list = impl->reader.getVal314();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCProtocolDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCProtocolDecl> ObjCObjectPointerType::qualifiers(void) const & {
  auto list = impl->reader.getVal314();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d314 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCProtocolDecl::from(Decl(std::move(d314)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

ObjCObjectPointerType ObjCObjectPointerType::strip_obj_c_kind_of_type_and_qualifiers(void) const {
  RawEntityId eid = impl->reader.getVal313();
  return ObjCObjectPointerType::from(Type(impl->ep->TypeFor(impl->ep, eid))).value();
}

std::optional<ObjCProtocolDecl> ObjCObjectPointerType::nth_protocol(unsigned n) const {
  auto list = impl->reader.getVal315();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCProtocolDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCProtocolDecl> ObjCObjectPointerType::protocols(void) const & {
  auto list = impl->reader.getVal315();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d315 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCProtocolDecl::from(Decl(std::move(d315)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
