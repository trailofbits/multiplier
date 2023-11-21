// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXAddrspaceCastExpr.h>

#include <multiplier/AST/CXXNamedCastExpr.h>
#include <multiplier/AST/CastExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/ExplicitCastExpr.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/Token.h>
#include <multiplier/AST/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXAddrspaceCastExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXAddrspaceCastExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXAddrspaceCastExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXAddrspaceCastExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXAddrspaceCastExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXAddrspaceCastExpr::contains(const Decl &decl) {
  for (auto &parent : CXXAddrspaceCastExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXAddrspaceCastExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXAddrspaceCastExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kCXXAddrspaceCastExprDerivedKinds[] = {
    CXXAddrspaceCastExpr::static_kind(),
};

}  // namespace

std::optional<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXAddrspaceCastExpr::static_kind():
      return reinterpret_cast<const CXXAddrspaceCastExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXAddrspaceCastExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXAddrspaceCastExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXAddrspaceCastExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXAddrspaceCastExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXAddrspaceCastExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXAddrspaceCastExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::from(const Reference &r) {
  return CXXAddrspaceCastExpr::from(r.as_statement());
}

std::optional<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
