// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXStdInitializerListExpr.h>

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

gap::generator<CXXStdInitializerListExpr> CXXStdInitializerListExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXStdInitializerListExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXStdInitializerListExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXStdInitializerListExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXStdInitializerListExpr> CXXStdInitializerListExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXStdInitializerListExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXStdInitializerListExpr> CXXStdInitializerListExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXStdInitializerListExpr> CXXStdInitializerListExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXStdInitializerListExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXStdInitializerListExpr> CXXStdInitializerListExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXStdInitializerListExpr::contains(const Decl &decl) {
  for (auto &parent : CXXStdInitializerListExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXStdInitializerListExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXStdInitializerListExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXStdInitializerListExpr> CXXStdInitializerListExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CXXStdInitializerListExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCXXStdInitializerListExprDerivedKinds[] = {
    CXXStdInitializerListExpr::static_kind(),
};

std::optional<CXXStdInitializerListExpr> CXXStdInitializerListExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXStdInitializerListExpr::static_kind():
      return reinterpret_cast<const CXXStdInitializerListExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXStdInitializerListExpr> CXXStdInitializerListExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kCXXStdInitializerListExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXStdInitializerListExpr> e = CXXStdInitializerListExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXStdInitializerListExpr> CXXStdInitializerListExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXStdInitializerListExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXStdInitializerListExpr> e = CXXStdInitializerListExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXStdInitializerListExpr> CXXStdInitializerListExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXStdInitializerListExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXStdInitializerListExpr> e = CXXStdInitializerListExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXStdInitializerListExpr> CXXStdInitializerListExpr::from(const Reference &r) {
  return CXXStdInitializerListExpr::from(r.as_statement());
}

std::optional<CXXStdInitializerListExpr> CXXStdInitializerListExpr::from(const TokenContext &t) {
  return CXXStdInitializerListExpr::from(t.as_statement());
}

Expr CXXStdInitializerListExpr::sub_expression(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
