// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXUnresolvedConstructExpr.h>
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
static const StmtKind kCXXUnresolvedConstructExprDerivedKinds[] = {
    CXXUnresolvedConstructExpr::static_kind(),
};
}  // namespace

gap::generator<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXUnresolvedConstructExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXUnresolvedConstructExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXUnresolvedConstructExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXUnresolvedConstructExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXUnresolvedConstructExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXUnresolvedConstructExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXUnresolvedConstructExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXUnresolvedConstructExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXUnresolvedConstructExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<CXXUnresolvedConstructExpr, ir::Operation>> CXXUnresolvedConstructExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kCXXUnresolvedConstructExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<CXXUnresolvedConstructExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXUnresolvedConstructExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXUnresolvedConstructExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXUnresolvedConstructExpr::contains(const Decl &decl) {
  for (auto &parent : CXXUnresolvedConstructExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXUnresolvedConstructExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXUnresolvedConstructExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXUnresolvedConstructExpr::static_kind():
      return reinterpret_cast<const CXXUnresolvedConstructExpr &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::from(const Reference &r) {
  return CXXUnresolvedConstructExpr::from(r.as_statement());
}

std::optional<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

unsigned CXXUnresolvedConstructExpr::num_arguments(void) const {
  return impl->reader.getVal15().size();
}

std::optional<Expr> CXXUnresolvedConstructExpr::nth_argument(unsigned n) const {
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

gap::generator<Expr> CXXUnresolvedConstructExpr::arguments(void) const & {
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

Token CXXUnresolvedConstructExpr::l_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal37());
}

Token CXXUnresolvedConstructExpr::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

Type CXXUnresolvedConstructExpr::type_as_written(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool CXXUnresolvedConstructExpr::is_list_initialization(void) const {
  return impl->reader.getVal83();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
