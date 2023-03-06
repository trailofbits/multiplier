// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXDefaultInitExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/FieldDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CXXDefaultInitExpr> CXXDefaultInitExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXDefaultInitExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXDefaultInitExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXDefaultInitExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXDefaultInitExpr> CXXDefaultInitExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXDefaultInitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXDefaultInitExpr> CXXDefaultInitExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXDefaultInitExpr> CXXDefaultInitExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXDefaultInitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXDefaultInitExpr> CXXDefaultInitExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXDefaultInitExpr::contains(const Decl &decl) {
  for (auto &parent : CXXDefaultInitExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool CXXDefaultInitExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXDefaultInitExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<CXXDefaultInitExpr> CXXDefaultInitExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CXXDefaultInitExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCXXDefaultInitExprDerivedKinds[] = {
    CXXDefaultInitExpr::static_kind(),
};

std::optional<CXXDefaultInitExpr> CXXDefaultInitExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXDefaultInitExpr::static_kind():
      return reinterpret_cast<const CXXDefaultInitExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXDefaultInitExpr> CXXDefaultInitExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kCXXDefaultInitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXDefaultInitExpr> e = CXXDefaultInitExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXDefaultInitExpr> CXXDefaultInitExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXDefaultInitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXDefaultInitExpr> e = CXXDefaultInitExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXDefaultInitExpr> CXXDefaultInitExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXDefaultInitExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXDefaultInitExpr> e = CXXDefaultInitExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<Expr> CXXDefaultInitExpr::expression(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal38();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

FieldDecl CXXDefaultInitExpr::field(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return FieldDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Token CXXDefaultInitExpr::used_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
