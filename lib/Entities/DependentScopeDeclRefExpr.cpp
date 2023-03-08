// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DependentScopeDeclRefExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<DependentScopeDeclRefExpr> DependentScopeDeclRefExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DependentScopeDeclRefExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DependentScopeDeclRefExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DependentScopeDeclRefExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<DependentScopeDeclRefExpr> DependentScopeDeclRefExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = DependentScopeDeclRefExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<DependentScopeDeclRefExpr> DependentScopeDeclRefExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<DependentScopeDeclRefExpr> DependentScopeDeclRefExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = DependentScopeDeclRefExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<DependentScopeDeclRefExpr> DependentScopeDeclRefExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool DependentScopeDeclRefExpr::contains(const Decl &decl) {
  for (auto &parent : DependentScopeDeclRefExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool DependentScopeDeclRefExpr::contains(const Stmt &stmt) {
  for (auto &parent : DependentScopeDeclRefExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<DependentScopeDeclRefExpr> DependentScopeDeclRefExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return DependentScopeDeclRefExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kDependentScopeDeclRefExprDerivedKinds[] = {
    DependentScopeDeclRefExpr::static_kind(),
};

std::optional<DependentScopeDeclRefExpr> DependentScopeDeclRefExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case DependentScopeDeclRefExpr::static_kind():
      return reinterpret_cast<const DependentScopeDeclRefExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DependentScopeDeclRefExpr> DependentScopeDeclRefExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kDependentScopeDeclRefExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<DependentScopeDeclRefExpr> e = DependentScopeDeclRefExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DependentScopeDeclRefExpr> DependentScopeDeclRefExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kDependentScopeDeclRefExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<DependentScopeDeclRefExpr> e = DependentScopeDeclRefExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DependentScopeDeclRefExpr> DependentScopeDeclRefExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kDependentScopeDeclRefExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<DependentScopeDeclRefExpr> e = DependentScopeDeclRefExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Token DependentScopeDeclRefExpr::l_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

Token DependentScopeDeclRefExpr::r_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

Token DependentScopeDeclRefExpr::template_keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

bool DependentScopeDeclRefExpr::has_explicit_template_arguments(void) const {
  return impl->reader.getVal88();
}

bool DependentScopeDeclRefExpr::has_template_keyword(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
