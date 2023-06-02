// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TypeTraitExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<TypeTraitExpr> TypeTraitExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TypeTraitExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TypeTraitExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TypeTraitExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<TypeTraitExpr> TypeTraitExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = TypeTraitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TypeTraitExpr> TypeTraitExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<TypeTraitExpr> TypeTraitExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = TypeTraitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TypeTraitExpr> TypeTraitExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool TypeTraitExpr::contains(const Decl &decl) {
  for (auto &parent : TypeTraitExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool TypeTraitExpr::contains(const Stmt &stmt) {
  for (auto &parent : TypeTraitExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<TypeTraitExpr> TypeTraitExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return TypeTraitExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kTypeTraitExprDerivedKinds[] = {
    TypeTraitExpr::static_kind(),
};

std::optional<TypeTraitExpr> TypeTraitExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case TypeTraitExpr::static_kind():
      return reinterpret_cast<const TypeTraitExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TypeTraitExpr> TypeTraitExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kTypeTraitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<TypeTraitExpr> e = TypeTraitExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TypeTraitExpr> TypeTraitExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kTypeTraitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<TypeTraitExpr> e = TypeTraitExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TypeTraitExpr> TypeTraitExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kTypeTraitExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<TypeTraitExpr> e = TypeTraitExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<TypeTraitExpr> TypeTraitExpr::from(const Reference &r) {
  return TypeTraitExpr::from(r.as_statement());
}

std::optional<TypeTraitExpr> TypeTraitExpr::from(const TokenContext &t) {
  return TypeTraitExpr::from(t.as_statement());
}

TypeTrait TypeTraitExpr::trait(void) const {
  return static_cast<TypeTrait>(impl->reader.getVal97());
}

std::optional<bool> TypeTraitExpr::value(void) const {
  if (!impl->reader.getVal93()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal92());
  }
  return std::nullopt;
}

unsigned TypeTraitExpr::num_arguments(void) const {
  return impl->reader.getVal18().size();
}

std::optional<Type> TypeTraitExpr::nth_argument(unsigned n) const {
  auto list = impl->reader.getVal18();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TypeFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Type(std::move(e));
}

gap::generator<Type> TypeTraitExpr::arguments(void) const & {
  auto list = impl->reader.getVal18();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d18 = ep->TypeFor(ep, v)) {
      co_yield Type(std::move(d18));
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
