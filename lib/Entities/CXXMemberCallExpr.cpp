// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXMemberCallExpr.h>

#include <multiplier/Entities/CXXMethodDecl.h>
#include <multiplier/Entities/CXXRecordDecl.h>
#include <multiplier/Entities/CallExpr.h>
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

gap::generator<CXXMemberCallExpr> CXXMemberCallExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXMemberCallExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXMemberCallExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXMemberCallExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXMemberCallExpr> CXXMemberCallExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXMemberCallExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXMemberCallExpr> CXXMemberCallExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXMemberCallExpr> CXXMemberCallExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXMemberCallExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXMemberCallExpr> CXXMemberCallExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXMemberCallExpr::contains(const Decl &decl) {
  for (auto &parent : CXXMemberCallExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXMemberCallExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXMemberCallExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXMemberCallExpr> CXXMemberCallExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CXXMemberCallExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCXXMemberCallExprDerivedKinds[] = {
    CXXMemberCallExpr::static_kind(),
};

std::optional<CXXMemberCallExpr> CXXMemberCallExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXMemberCallExpr::static_kind():
      return reinterpret_cast<const CXXMemberCallExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXMemberCallExpr> CXXMemberCallExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXMemberCallExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXMemberCallExpr> e = CXXMemberCallExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXMemberCallExpr> CXXMemberCallExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXMemberCallExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXMemberCallExpr> e = CXXMemberCallExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXMemberCallExpr> CXXMemberCallExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXMemberCallExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXMemberCallExpr> e = CXXMemberCallExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXMemberCallExpr> CXXMemberCallExpr::from(const Reference &r) {
  return CXXMemberCallExpr::from(r.as_statement());
}

std::optional<CXXMemberCallExpr> CXXMemberCallExpr::from(const TokenContext &t) {
  return CXXMemberCallExpr::from(t.as_statement());
}

Expr CXXMemberCallExpr::implicit_object_argument(void) const {
  RawEntityId eid = impl->reader.getVal44();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

std::optional<CXXMethodDecl> CXXMemberCallExpr::method_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal45();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return CXXMethodDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

Type CXXMemberCallExpr::object_type(void) const {
  RawEntityId eid = impl->reader.getVal46();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

CXXRecordDecl CXXMemberCallExpr::record_declaration(void) const {
  RawEntityId eid = impl->reader.getVal47();
  return CXXRecordDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
