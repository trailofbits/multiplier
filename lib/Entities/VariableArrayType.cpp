// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/VariableArrayType.h>

#include <multiplier/Entities/ArrayType.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Fragment.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<VariableArrayType> VariableArrayType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = VariableArrayType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool VariableArrayType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : VariableArrayType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<VariableArrayType> VariableArrayType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return VariableArrayType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kVariableArrayTypeDerivedKinds[] = {
    VariableArrayType::static_kind(),
};

std::optional<VariableArrayType> VariableArrayType::from(const Type &parent) {
  switch (parent.kind()) {
    case VariableArrayType::static_kind():
      return reinterpret_cast<const VariableArrayType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<VariableArrayType> VariableArrayType::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (TypeKind k : kVariableArrayTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<VariableArrayType> e = VariableArrayType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VariableArrayType> VariableArrayType::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kVariableArrayTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<VariableArrayType> e = VariableArrayType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VariableArrayType> VariableArrayType::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kVariableArrayTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<VariableArrayType> e = VariableArrayType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Type VariableArrayType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal229();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

TokenRange VariableArrayType::brackets_range(void) const {
  auto &ep = impl->ep;
  auto fragment = ep->FragmentFor(ep, impl->fragment_id);
  return fragment->TokenRangeFor(fragment, impl->reader.getVal234(), impl->reader.getVal263());
}

Token VariableArrayType::l_bracket_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal265());
}

Token VariableArrayType::r_bracket_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal266());
}

Expr VariableArrayType::size_expression(void) const {
  RawEntityId eid = impl->reader.getVal271();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

bool VariableArrayType::is_sugared(void) const {
  return impl->reader.getVal230();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
