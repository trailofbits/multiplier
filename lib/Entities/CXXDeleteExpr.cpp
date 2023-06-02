// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXDeleteExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/FunctionDecl.h>
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

gap::generator<CXXDeleteExpr> CXXDeleteExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXDeleteExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXDeleteExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXDeleteExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXDeleteExpr> CXXDeleteExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXDeleteExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXDeleteExpr> CXXDeleteExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXDeleteExpr> CXXDeleteExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXDeleteExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXDeleteExpr> CXXDeleteExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXDeleteExpr::contains(const Decl &decl) {
  for (auto &parent : CXXDeleteExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXDeleteExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXDeleteExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXDeleteExpr> CXXDeleteExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CXXDeleteExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCXXDeleteExprDerivedKinds[] = {
    CXXDeleteExpr::static_kind(),
};

std::optional<CXXDeleteExpr> CXXDeleteExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXDeleteExpr::static_kind():
      return reinterpret_cast<const CXXDeleteExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXDeleteExpr> CXXDeleteExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXDeleteExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXDeleteExpr> e = CXXDeleteExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXDeleteExpr> CXXDeleteExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXDeleteExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXDeleteExpr> e = CXXDeleteExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXDeleteExpr> CXXDeleteExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXDeleteExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXDeleteExpr> e = CXXDeleteExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXDeleteExpr> CXXDeleteExpr::from(const Reference &r) {
  return CXXDeleteExpr::from(r.as_statement());
}

std::optional<CXXDeleteExpr> CXXDeleteExpr::from(const TokenContext &t) {
  return CXXDeleteExpr::from(t.as_statement());
}

bool CXXDeleteExpr::does_usual_array_delete_want_size(void) const {
  return impl->reader.getVal92();
}

Expr CXXDeleteExpr::argument(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Type CXXDeleteExpr::destroyed_type(void) const {
  RawEntityId eid = impl->reader.getVal42();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

FunctionDecl CXXDeleteExpr::operator_delete(void) const {
  RawEntityId eid = impl->reader.getVal43();
  return FunctionDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

bool CXXDeleteExpr::is_array_form(void) const {
  return impl->reader.getVal93();
}

bool CXXDeleteExpr::is_array_form_as_written(void) const {
  return impl->reader.getVal94();
}

bool CXXDeleteExpr::is_global_delete(void) const {
  return impl->reader.getVal95();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
