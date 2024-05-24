// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/DeclRefExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/Frontend/File.h>
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
static const StmtKind kDeclRefExprDerivedKinds[] = {
    DeclRefExpr::static_kind(),
};
}  // namespace

gap::generator<DeclRefExpr> DeclRefExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kDeclRefExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<DeclRefExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DeclRefExpr> DeclRefExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kDeclRefExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<DeclRefExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<DeclRefExpr> DeclRefExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kDeclRefExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<DeclRefExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

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

std::optional<DeclRefExpr> DeclRefExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<DeclRefExpr, ir::Operation>> DeclRefExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kDeclRefExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<DeclRefExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
    if (auto base = index.statement(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<DeclRefExpr> DeclRefExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<DeclRefExpr> DeclRefExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case DeclRefExpr::static_kind():
      return reinterpret_cast<const DeclRefExpr &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<DeclRefExpr> DeclRefExpr::from(const Reference &r) {
  return DeclRefExpr::from(r.as_statement());
}

std::optional<DeclRefExpr> DeclRefExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<DeclRefExpr> DeclRefExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

ValueDecl DeclRefExpr::declaration(void) const {
  RawEntityId eid = impl->reader.getVal37();
  return ValueDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Token DeclRefExpr::l_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

Token DeclRefExpr::r_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

Token DeclRefExpr::template_keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

bool DeclRefExpr::had_multiple_candidates(void) const {
  return impl->reader.getVal84();
}

bool DeclRefExpr::has_explicit_template_arguments(void) const {
  return impl->reader.getVal85();
}

bool DeclRefExpr::has_qualifier(void) const {
  return impl->reader.getVal86();
}

bool DeclRefExpr::is_captured_by_copy_in_lambda_with_explicit_object_parameter(void) const {
  return impl->reader.getVal87();
}

bool DeclRefExpr::is_immediate_escalating(void) const {
  return impl->reader.getVal88();
}

NonOdrUseReason DeclRefExpr::is_non_odr_use(void) const {
  return static_cast<NonOdrUseReason>(impl->reader.getVal89());
}

bool DeclRefExpr::refers_to_enclosing_variable_or_capture(void) const {
  return impl->reader.getVal90();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
