// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXNullPtrLiteralExpr.h>

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

gap::generator<CXXNullPtrLiteralExpr> CXXNullPtrLiteralExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXNullPtrLiteralExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXNullPtrLiteralExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXNullPtrLiteralExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXNullPtrLiteralExpr> CXXNullPtrLiteralExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXNullPtrLiteralExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXNullPtrLiteralExpr> CXXNullPtrLiteralExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXNullPtrLiteralExpr> CXXNullPtrLiteralExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXNullPtrLiteralExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXNullPtrLiteralExpr> CXXNullPtrLiteralExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXNullPtrLiteralExpr::contains(const Decl &decl) {
  for (auto &parent : CXXNullPtrLiteralExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXNullPtrLiteralExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXNullPtrLiteralExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXNullPtrLiteralExpr> CXXNullPtrLiteralExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CXXNullPtrLiteralExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCXXNullPtrLiteralExprDerivedKinds[] = {
    CXXNullPtrLiteralExpr::static_kind(),
};

std::optional<CXXNullPtrLiteralExpr> CXXNullPtrLiteralExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXNullPtrLiteralExpr::static_kind():
      return reinterpret_cast<const CXXNullPtrLiteralExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXNullPtrLiteralExpr> CXXNullPtrLiteralExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXNullPtrLiteralExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXNullPtrLiteralExpr> e = CXXNullPtrLiteralExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXNullPtrLiteralExpr> CXXNullPtrLiteralExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXNullPtrLiteralExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXNullPtrLiteralExpr> e = CXXNullPtrLiteralExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXNullPtrLiteralExpr> CXXNullPtrLiteralExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXNullPtrLiteralExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXNullPtrLiteralExpr> e = CXXNullPtrLiteralExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXNullPtrLiteralExpr> CXXNullPtrLiteralExpr::from(const Reference &r) {
  return CXXNullPtrLiteralExpr::from(r.as_statement());
}

std::optional<CXXNullPtrLiteralExpr> CXXNullPtrLiteralExpr::from(const TokenContext &t) {
  return CXXNullPtrLiteralExpr::from(t.as_statement());
}

Token CXXNullPtrLiteralExpr::token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal37());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
