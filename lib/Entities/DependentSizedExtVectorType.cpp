// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DependentSizedExtVectorType.h>

#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<DependentSizedExtVectorType> DependentSizedExtVectorType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DependentSizedExtVectorType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DependentSizedExtVectorType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DependentSizedExtVectorType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<DependentSizedExtVectorType> DependentSizedExtVectorType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return DependentSizedExtVectorType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kDependentSizedExtVectorTypeDerivedKinds[] = {
    DependentSizedExtVectorType::static_kind(),
};

std::optional<DependentSizedExtVectorType> DependentSizedExtVectorType::from(const Type &parent) {
  switch (parent.kind()) {
    case DependentSizedExtVectorType::static_kind():
      return reinterpret_cast<const DependentSizedExtVectorType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DependentSizedExtVectorType> DependentSizedExtVectorType::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (TypeKind k : kDependentSizedExtVectorTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<DependentSizedExtVectorType> e = DependentSizedExtVectorType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DependentSizedExtVectorType> DependentSizedExtVectorType::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kDependentSizedExtVectorTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<DependentSizedExtVectorType> e = DependentSizedExtVectorType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DependentSizedExtVectorType> DependentSizedExtVectorType::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kDependentSizedExtVectorTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<DependentSizedExtVectorType> e = DependentSizedExtVectorType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Type DependentSizedExtVectorType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal228();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Token DependentSizedExtVectorType::attribute_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal229());
}

Type DependentSizedExtVectorType::element_type(void) const {
  RawEntityId eid = impl->reader.getVal234();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Expr DependentSizedExtVectorType::size_expression(void) const {
  RawEntityId eid = impl->reader.getVal262();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

bool DependentSizedExtVectorType::is_sugared(void) const {
  return impl->reader.getVal230();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
