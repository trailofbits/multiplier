// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DeclRefExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueDecl.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<DeclRefExpr> DeclRefExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DeclRefExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DeclRefExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DeclRefExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<DeclRefExpr> DeclRefExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = DeclRefExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<DeclRefExpr> DeclRefExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<DeclRefExpr> DeclRefExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = DeclRefExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<DeclRefExpr> DeclRefExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool DeclRefExpr::contains(const Decl &decl) {
  for (auto &parent : DeclRefExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool DeclRefExpr::contains(const Stmt &stmt) {
  for (auto &parent : DeclRefExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<DeclRefExpr> DeclRefExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return DeclRefExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kDeclRefExprDerivedKinds[] = {
    DeclRefExpr::static_kind(),
};

std::optional<DeclRefExpr> DeclRefExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case DeclRefExpr::static_kind():
      return reinterpret_cast<const DeclRefExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DeclRefExpr> DeclRefExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kDeclRefExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<DeclRefExpr> e = DeclRefExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DeclRefExpr> DeclRefExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kDeclRefExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<DeclRefExpr> e = DeclRefExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DeclRefExpr> DeclRefExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kDeclRefExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<DeclRefExpr> e = DeclRefExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<DeclRefExpr> DeclRefExpr::from(const Reference &r) {
  return DeclRefExpr::from(r.as_statement());
}

std::optional<DeclRefExpr> DeclRefExpr::from(const TokenContext &t) {
  return DeclRefExpr::from(t.as_statement());
}

ValueDecl DeclRefExpr::declaration(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return ValueDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

NamedDecl DeclRefExpr::found_declaration(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return NamedDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Token DeclRefExpr::l_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

Token DeclRefExpr::r_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal41());
}

Token DeclRefExpr::template_keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal42());
}

bool DeclRefExpr::had_multiple_candidates(void) const {
  return impl->reader.getVal89();
}

bool DeclRefExpr::has_explicit_template_arguments(void) const {
  return impl->reader.getVal90();
}

bool DeclRefExpr::has_qualifier(void) const {
  return impl->reader.getVal91();
}

bool DeclRefExpr::has_template_keyword_and_arguments_info(void) const {
  return impl->reader.getVal92();
}

bool DeclRefExpr::has_template_keyword(void) const {
  return impl->reader.getVal93();
}

NonOdrUseReason DeclRefExpr::is_non_odr_use(void) const {
  return static_cast<NonOdrUseReason>(impl->reader.getVal94());
}

bool DeclRefExpr::refers_to_enclosing_variable_or_capture(void) const {
  return impl->reader.getVal95();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
