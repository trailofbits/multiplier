// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MemberPointerType.h>

#include <multiplier/Entities/CXXRecordDecl.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<MemberPointerType> MemberPointerType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = MemberPointerType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool MemberPointerType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : MemberPointerType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<MemberPointerType> MemberPointerType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return MemberPointerType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kMemberPointerTypeDerivedKinds[] = {
    MemberPointerType::static_kind(),
};

std::optional<MemberPointerType> MemberPointerType::from(const Type &parent) {
  switch (parent.kind()) {
    case MemberPointerType::static_kind():
      return reinterpret_cast<const MemberPointerType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<MemberPointerType> MemberPointerType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kMemberPointerTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<MemberPointerType> e = MemberPointerType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<MemberPointerType> MemberPointerType::from(const Reference &r) {
  return MemberPointerType::from(r.as_type());
}

std::optional<MemberPointerType> MemberPointerType::from(const TokenContext &t) {
  return MemberPointerType::from(t.as_type());
}

Type MemberPointerType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal18();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type MemberPointerType::class_(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

CXXRecordDecl MemberPointerType::most_recent_cxx_record_declaration(void) const {
  RawEntityId eid = impl->reader.getVal25();
  return CXXRecordDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Type MemberPointerType::pointee_type(void) const {
  RawEntityId eid = impl->reader.getVal26();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool MemberPointerType::is_member_data_pointer(void) const {
  return impl->reader.getVal20();
}

bool MemberPointerType::is_member_function_pointer(void) const {
  return impl->reader.getVal21();
}

bool MemberPointerType::is_sugared(void) const {
  return impl->reader.getVal22();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
