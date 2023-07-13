// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXParenListInitExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/FieldDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CXXParenListInitExpr> CXXParenListInitExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXParenListInitExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXParenListInitExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXParenListInitExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXParenListInitExpr> CXXParenListInitExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXParenListInitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXParenListInitExpr> CXXParenListInitExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXParenListInitExpr> CXXParenListInitExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXParenListInitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXParenListInitExpr> CXXParenListInitExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXParenListInitExpr::contains(const Decl &decl) {
  for (auto &parent : CXXParenListInitExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXParenListInitExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXParenListInitExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXParenListInitExpr> CXXParenListInitExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CXXParenListInitExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCXXParenListInitExprDerivedKinds[] = {
    CXXParenListInitExpr::static_kind(),
};

std::optional<CXXParenListInitExpr> CXXParenListInitExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXParenListInitExpr::static_kind():
      return reinterpret_cast<const CXXParenListInitExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXParenListInitExpr> CXXParenListInitExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXParenListInitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXParenListInitExpr> e = CXXParenListInitExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXParenListInitExpr> CXXParenListInitExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXParenListInitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXParenListInitExpr> e = CXXParenListInitExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXParenListInitExpr> CXXParenListInitExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXParenListInitExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXParenListInitExpr> e = CXXParenListInitExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXParenListInitExpr> CXXParenListInitExpr::from(const Reference &r) {
  return CXXParenListInitExpr::from(r.as_statement());
}

std::optional<CXXParenListInitExpr> CXXParenListInitExpr::from(const TokenContext &t) {
  return CXXParenListInitExpr::from(t.as_statement());
}

Expr CXXParenListInitExpr::array_filler(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token CXXParenListInitExpr::initializer_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

FieldDecl CXXParenListInitExpr::initialized_field_in_union(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return FieldDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
