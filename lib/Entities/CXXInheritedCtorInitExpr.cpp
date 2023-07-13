// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXInheritedCtorInitExpr.h>

#include <multiplier/Entities/CXXConstructorDecl.h>
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

gap::generator<CXXInheritedCtorInitExpr> CXXInheritedCtorInitExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXInheritedCtorInitExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXInheritedCtorInitExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXInheritedCtorInitExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXInheritedCtorInitExpr> CXXInheritedCtorInitExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXInheritedCtorInitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXInheritedCtorInitExpr> CXXInheritedCtorInitExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXInheritedCtorInitExpr> CXXInheritedCtorInitExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXInheritedCtorInitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXInheritedCtorInitExpr> CXXInheritedCtorInitExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXInheritedCtorInitExpr::contains(const Decl &decl) {
  for (auto &parent : CXXInheritedCtorInitExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXInheritedCtorInitExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXInheritedCtorInitExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXInheritedCtorInitExpr> CXXInheritedCtorInitExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CXXInheritedCtorInitExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCXXInheritedCtorInitExprDerivedKinds[] = {
    CXXInheritedCtorInitExpr::static_kind(),
};

std::optional<CXXInheritedCtorInitExpr> CXXInheritedCtorInitExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXInheritedCtorInitExpr::static_kind():
      return reinterpret_cast<const CXXInheritedCtorInitExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXInheritedCtorInitExpr> CXXInheritedCtorInitExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXInheritedCtorInitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXInheritedCtorInitExpr> e = CXXInheritedCtorInitExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXInheritedCtorInitExpr> CXXInheritedCtorInitExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXInheritedCtorInitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXInheritedCtorInitExpr> e = CXXInheritedCtorInitExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXInheritedCtorInitExpr> CXXInheritedCtorInitExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXInheritedCtorInitExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXInheritedCtorInitExpr> e = CXXInheritedCtorInitExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXInheritedCtorInitExpr> CXXInheritedCtorInitExpr::from(const Reference &r) {
  return CXXInheritedCtorInitExpr::from(r.as_statement());
}

std::optional<CXXInheritedCtorInitExpr> CXXInheritedCtorInitExpr::from(const TokenContext &t) {
  return CXXInheritedCtorInitExpr::from(t.as_statement());
}

bool CXXInheritedCtorInitExpr::constructs_virtual_base(void) const {
  return impl->reader.getVal89();
}

CXXConstructExprConstructionKind CXXInheritedCtorInitExpr::construction_kind(void) const {
  return static_cast<CXXConstructExprConstructionKind>(impl->reader.getVal94());
}

CXXConstructorDecl CXXInheritedCtorInitExpr::constructor(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return CXXConstructorDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Token CXXInheritedCtorInitExpr::token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

bool CXXInheritedCtorInitExpr::inherited_from_virtual_base(void) const {
  return impl->reader.getVal90();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
