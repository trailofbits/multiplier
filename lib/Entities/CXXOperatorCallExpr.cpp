// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXOperatorCallExpr.h>

#include <multiplier/Entities/CallExpr.h>
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

gap::generator<CXXOperatorCallExpr> CXXOperatorCallExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXOperatorCallExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXOperatorCallExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXOperatorCallExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXOperatorCallExpr> CXXOperatorCallExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXOperatorCallExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXOperatorCallExpr> CXXOperatorCallExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXOperatorCallExpr> CXXOperatorCallExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXOperatorCallExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXOperatorCallExpr> CXXOperatorCallExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXOperatorCallExpr::contains(const Decl &decl) {
  for (auto &parent : CXXOperatorCallExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXOperatorCallExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXOperatorCallExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXOperatorCallExpr> CXXOperatorCallExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CXXOperatorCallExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCXXOperatorCallExprDerivedKinds[] = {
    CXXOperatorCallExpr::static_kind(),
};

std::optional<CXXOperatorCallExpr> CXXOperatorCallExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXOperatorCallExpr::static_kind():
      return reinterpret_cast<const CXXOperatorCallExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXOperatorCallExpr> CXXOperatorCallExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXOperatorCallExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXOperatorCallExpr> e = CXXOperatorCallExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXOperatorCallExpr> CXXOperatorCallExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXOperatorCallExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXOperatorCallExpr> e = CXXOperatorCallExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXOperatorCallExpr> CXXOperatorCallExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXOperatorCallExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXOperatorCallExpr> e = CXXOperatorCallExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXOperatorCallExpr> CXXOperatorCallExpr::from(const Reference &r) {
  return CXXOperatorCallExpr::from(r.as_statement());
}

std::optional<CXXOperatorCallExpr> CXXOperatorCallExpr::from(const TokenContext &t) {
  return CXXOperatorCallExpr::from(t.as_statement());
}

OverloadedOperatorKind CXXOperatorCallExpr::operator_(void) const {
  return static_cast<OverloadedOperatorKind>(impl->reader.getVal96());
}

Token CXXOperatorCallExpr::operator_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal44());
}

bool CXXOperatorCallExpr::is_assignment_operation(void) const {
  return impl->reader.getVal97();
}

bool CXXOperatorCallExpr::is_comparison_operation(void) const {
  return impl->reader.getVal98();
}

bool CXXOperatorCallExpr::is_infix_binary_operation(void) const {
  return impl->reader.getVal99();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
