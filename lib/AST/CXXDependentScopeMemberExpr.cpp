// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXDependentScopeMemberExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/ValueStmt.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kCXXDependentScopeMemberExprDerivedKinds[] = {
    CXXDependentScopeMemberExpr::static_kind(),
};
}  // namespace

gap::generator<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXDependentScopeMemberExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXDependentScopeMemberExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXDependentScopeMemberExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<CXXDependentScopeMemberExpr, ir::Operation>> CXXDependentScopeMemberExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kCXXDependentScopeMemberExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<CXXDependentScopeMemberExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXDependentScopeMemberExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXDependentScopeMemberExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXDependentScopeMemberExpr::contains(const Decl &decl) {
  for (auto &parent : CXXDependentScopeMemberExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXDependentScopeMemberExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXDependentScopeMemberExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    if (auto base = index.statement(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXDependentScopeMemberExpr::static_kind():
      return reinterpret_cast<const CXXDependentScopeMemberExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXDependentScopeMemberExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXDependentScopeMemberExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXDependentScopeMemberExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXDependentScopeMemberExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXDependentScopeMemberExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXDependentScopeMemberExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::from(const Reference &r) {
  return CXXDependentScopeMemberExpr::from(r.as_statement());
}

std::optional<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<Expr> CXXDependentScopeMemberExpr::base(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal37();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

Type CXXDependentScopeMemberExpr::base_type(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<NamedDecl> CXXDependentScopeMemberExpr::first_qualifier_found_in_scope(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal39();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return NamedDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token CXXDependentScopeMemberExpr::l_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

Token CXXDependentScopeMemberExpr::member_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal41());
}

Token CXXDependentScopeMemberExpr::operator_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal42());
}

Token CXXDependentScopeMemberExpr::r_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal43());
}

Token CXXDependentScopeMemberExpr::template_keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal44());
}

bool CXXDependentScopeMemberExpr::has_explicit_template_arguments(void) const {
  return impl->reader.getVal84();
}

bool CXXDependentScopeMemberExpr::has_template_keyword(void) const {
  return impl->reader.getVal85();
}

bool CXXDependentScopeMemberExpr::is_arrow(void) const {
  return impl->reader.getVal86();
}

bool CXXDependentScopeMemberExpr::is_implicit_access(void) const {
  return impl->reader.getVal87();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
