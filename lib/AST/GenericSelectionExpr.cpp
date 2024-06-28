// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/GenericSelectionExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/Frontend/File.h>
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
static const StmtKind kGenericSelectionExprDerivedKinds[] = {
    GenericSelectionExpr::static_kind(),
};
}  // namespace

gap::generator<GenericSelectionExpr> GenericSelectionExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kGenericSelectionExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<GenericSelectionExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<GenericSelectionExpr> GenericSelectionExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kGenericSelectionExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<GenericSelectionExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<GenericSelectionExpr> GenericSelectionExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kGenericSelectionExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<GenericSelectionExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<GenericSelectionExpr> GenericSelectionExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = GenericSelectionExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool GenericSelectionExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : GenericSelectionExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<GenericSelectionExpr> GenericSelectionExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<GenericSelectionExpr, ir::Operation>> GenericSelectionExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kGenericSelectionExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<GenericSelectionExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<GenericSelectionExpr> GenericSelectionExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = GenericSelectionExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<GenericSelectionExpr> GenericSelectionExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<GenericSelectionExpr> GenericSelectionExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = GenericSelectionExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<GenericSelectionExpr> GenericSelectionExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool GenericSelectionExpr::contains(const Decl &decl) {
  for (auto &parent : GenericSelectionExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool GenericSelectionExpr::contains(const Stmt &stmt) {
  for (auto &parent : GenericSelectionExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<GenericSelectionExpr> GenericSelectionExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<GenericSelectionExpr> GenericSelectionExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<GenericSelectionExpr> GenericSelectionExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case GenericSelectionExpr::static_kind():
      return reinterpret_cast<const GenericSelectionExpr &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<GenericSelectionExpr> GenericSelectionExpr::from(const Reference &r) {
  return GenericSelectionExpr::from(r.as_statement());
}

std::optional<GenericSelectionExpr> GenericSelectionExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<GenericSelectionExpr> GenericSelectionExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

unsigned GenericSelectionExpr::num_association_expressions(void) const {
  return impl->reader.getVal15().size();
}

std::optional<Expr> GenericSelectionExpr::nth_association_expression(unsigned n) const {
  auto list = impl->reader.getVal15();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from_base(std::move(e));
}

gap::generator<Expr> GenericSelectionExpr::association_expressions(void) const & {
  auto list = impl->reader.getVal15();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from_base(std::move(d15))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

std::optional<Expr> GenericSelectionExpr::controlling_expression(void) const {
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

std::optional<Type> GenericSelectionExpr::controlling_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal38();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token GenericSelectionExpr::default_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

Token GenericSelectionExpr::generic_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

Token GenericSelectionExpr::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal41());
}

std::optional<Expr> GenericSelectionExpr::result_expression(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal42();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool GenericSelectionExpr::is_expression_predicate(void) const {
  return impl->reader.getVal85();
}

bool GenericSelectionExpr::is_result_dependent(void) const {
  return impl->reader.getVal86();
}

bool GenericSelectionExpr::is_type_predicate(void) const {
  return impl->reader.getVal87();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
