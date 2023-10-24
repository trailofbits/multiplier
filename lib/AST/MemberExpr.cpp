// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/MemberExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueDecl.h>
#include <multiplier/AST/ValueStmt.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kMemberExprDerivedKinds[] = {
    MemberExpr::static_kind(),
};
}  // namespace

gap::generator<MemberExpr> MemberExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = MemberExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool MemberExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : MemberExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<MemberExpr> MemberExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<MemberExpr, ir::Operation>> MemberExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kMemberExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<MemberExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<MemberExpr> MemberExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = MemberExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<MemberExpr> MemberExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<MemberExpr> MemberExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = MemberExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<MemberExpr> MemberExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool MemberExpr::contains(const Decl &decl) {
  for (auto &parent : MemberExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool MemberExpr::contains(const Stmt &stmt) {
  for (auto &parent : MemberExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<MemberExpr> MemberExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<MemberExpr> MemberExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<MemberExpr> MemberExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case MemberExpr::static_kind():
      return reinterpret_cast<const MemberExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<MemberExpr> MemberExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kMemberExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<MemberExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MemberExpr> MemberExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kMemberExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<MemberExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MemberExpr> MemberExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kMemberExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<MemberExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<MemberExpr> MemberExpr::from(const Reference &r) {
  return MemberExpr::from(r.as_statement());
}

std::optional<MemberExpr> MemberExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<MemberExpr> MemberExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Expr MemberExpr::base(void) const {
  RawEntityId eid = impl->reader.getVal37();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Token MemberExpr::l_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

ValueDecl MemberExpr::member_declaration(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return ValueDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Token MemberExpr::member_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

Token MemberExpr::operator_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal41());
}

Token MemberExpr::r_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal42());
}

Token MemberExpr::template_keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal43());
}

bool MemberExpr::had_multiple_candidates(void) const {
<<<<<<< HEAD
  return impl->reader.getVal84();
}

bool MemberExpr::has_explicit_template_arguments(void) const {
  return impl->reader.getVal85();
}

bool MemberExpr::has_qualifier(void) const {
  return impl->reader.getVal86();
}

bool MemberExpr::has_template_keyword(void) const {
  return impl->reader.getVal87();
}

bool MemberExpr::is_arrow(void) const {
  return impl->reader.getVal88();
}

bool MemberExpr::is_implicit_access(void) const {
  return impl->reader.getVal89();
}

NonOdrUseReason MemberExpr::is_non_odr_use(void) const {
  return static_cast<NonOdrUseReason>(impl->reader.getVal90());
=======
  return impl->reader.getVal86();
}

bool MemberExpr::has_explicit_template_arguments(void) const {
  return impl->reader.getVal87();
}

bool MemberExpr::has_qualifier(void) const {
  return impl->reader.getVal88();
}

bool MemberExpr::has_template_keyword(void) const {
  return impl->reader.getVal89();
}

bool MemberExpr::is_arrow(void) const {
  return impl->reader.getVal90();
}

bool MemberExpr::is_implicit_access(void) const {
  return impl->reader.getVal91();
}

NonOdrUseReason MemberExpr::is_non_odr_use(void) const {
  return static_cast<NonOdrUseReason>(impl->reader.getVal92());
>>>>>>> 5d49e713d (Intial changes to fix root fragment for function template)
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
