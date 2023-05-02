// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DependentSizedMatrixType.h>

#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/MatrixType.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<DependentSizedMatrixType> DependentSizedMatrixType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DependentSizedMatrixType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DependentSizedMatrixType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DependentSizedMatrixType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<DependentSizedMatrixType> DependentSizedMatrixType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return DependentSizedMatrixType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kDependentSizedMatrixTypeDerivedKinds[] = {
    DependentSizedMatrixType::static_kind(),
};

std::optional<DependentSizedMatrixType> DependentSizedMatrixType::from(const Type &parent) {
  switch (parent.kind()) {
    case DependentSizedMatrixType::static_kind():
      return reinterpret_cast<const DependentSizedMatrixType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DependentSizedMatrixType> DependentSizedMatrixType::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (TypeKind k : kDependentSizedMatrixTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<DependentSizedMatrixType> e = DependentSizedMatrixType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DependentSizedMatrixType> DependentSizedMatrixType::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kDependentSizedMatrixTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<DependentSizedMatrixType> e = DependentSizedMatrixType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DependentSizedMatrixType> DependentSizedMatrixType::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kDependentSizedMatrixTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<DependentSizedMatrixType> e = DependentSizedMatrixType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<DependentSizedMatrixType> DependentSizedMatrixType::from(const Reference &r) {
  return DependentSizedMatrixType::from(r.as_type());
}

std::optional<DependentSizedMatrixType> DependentSizedMatrixType::from(const TokenContext &t) {
  return DependentSizedMatrixType::from(t.as_type());
}

Token DependentSizedMatrixType::attribute_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal236());
}

Expr DependentSizedMatrixType::column_expression(void) const {
  RawEntityId eid = impl->reader.getVal237();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr DependentSizedMatrixType::row_expression(void) const {
  RawEntityId eid = impl->reader.getVal267();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
