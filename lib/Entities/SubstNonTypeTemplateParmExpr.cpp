// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/SubstNonTypeTemplateParmExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/NonTypeTemplateParmDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<SubstNonTypeTemplateParmExpr> SubstNonTypeTemplateParmExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = SubstNonTypeTemplateParmExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool SubstNonTypeTemplateParmExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : SubstNonTypeTemplateParmExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<SubstNonTypeTemplateParmExpr> SubstNonTypeTemplateParmExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = SubstNonTypeTemplateParmExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<SubstNonTypeTemplateParmExpr> SubstNonTypeTemplateParmExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<SubstNonTypeTemplateParmExpr> SubstNonTypeTemplateParmExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = SubstNonTypeTemplateParmExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<SubstNonTypeTemplateParmExpr> SubstNonTypeTemplateParmExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool SubstNonTypeTemplateParmExpr::contains(const Decl &decl) {
  for (auto &parent : SubstNonTypeTemplateParmExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool SubstNonTypeTemplateParmExpr::contains(const Stmt &stmt) {
  for (auto &parent : SubstNonTypeTemplateParmExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<SubstNonTypeTemplateParmExpr> SubstNonTypeTemplateParmExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return SubstNonTypeTemplateParmExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kSubstNonTypeTemplateParmExprDerivedKinds[] = {
    SubstNonTypeTemplateParmExpr::static_kind(),
};

std::optional<SubstNonTypeTemplateParmExpr> SubstNonTypeTemplateParmExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case SubstNonTypeTemplateParmExpr::static_kind():
      return reinterpret_cast<const SubstNonTypeTemplateParmExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<SubstNonTypeTemplateParmExpr> SubstNonTypeTemplateParmExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kSubstNonTypeTemplateParmExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<SubstNonTypeTemplateParmExpr> e = SubstNonTypeTemplateParmExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SubstNonTypeTemplateParmExpr> SubstNonTypeTemplateParmExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kSubstNonTypeTemplateParmExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<SubstNonTypeTemplateParmExpr> e = SubstNonTypeTemplateParmExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SubstNonTypeTemplateParmExpr> SubstNonTypeTemplateParmExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kSubstNonTypeTemplateParmExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<SubstNonTypeTemplateParmExpr> e = SubstNonTypeTemplateParmExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<SubstNonTypeTemplateParmExpr> SubstNonTypeTemplateParmExpr::from(const Reference &r) {
  return SubstNonTypeTemplateParmExpr::from(r.as_statement());
}

std::optional<SubstNonTypeTemplateParmExpr> SubstNonTypeTemplateParmExpr::from(const TokenContext &t) {
  return SubstNonTypeTemplateParmExpr::from(t.as_statement());
}

Token SubstNonTypeTemplateParmExpr::name_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

NonTypeTemplateParmDecl SubstNonTypeTemplateParmExpr::parameter(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return NonTypeTemplateParmDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Type SubstNonTypeTemplateParmExpr::parameter_type(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Expr SubstNonTypeTemplateParmExpr::replacement(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

bool SubstNonTypeTemplateParmExpr::is_reference_parameter(void) const {
  return impl->reader.getVal88();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
