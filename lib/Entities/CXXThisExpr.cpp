// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXThisExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CXXThisExpr> CXXThisExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXThisExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXThisExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXThisExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXThisExpr> CXXThisExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXThisExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXThisExpr> CXXThisExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXThisExpr> CXXThisExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXThisExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXThisExpr> CXXThisExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXThisExpr::contains(const Decl &decl) {
  for (auto &parent : CXXThisExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXThisExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXThisExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXThisExpr> CXXThisExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    if (auto base = index.statement(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<CXXThisExpr> CXXThisExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kCXXThisExprDerivedKinds[] = {
    CXXThisExpr::static_kind(),
};

}  // namespace

std::optional<CXXThisExpr> CXXThisExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXThisExpr::static_kind():
      return reinterpret_cast<const CXXThisExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXThisExpr> CXXThisExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXThisExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXThisExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXThisExpr> CXXThisExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXThisExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXThisExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXThisExpr> CXXThisExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXThisExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXThisExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXThisExpr> CXXThisExpr::from(const Reference &r) {
  return CXXThisExpr::from(r.as_statement());
}

std::optional<CXXThisExpr> CXXThisExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<CXXThisExpr> CXXThisExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token CXXThisExpr::token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal37());
}

bool CXXThisExpr::is_implicit(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
