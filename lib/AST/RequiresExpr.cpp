// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/RequiresExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/ParmVarDecl.h>
#include <multiplier/AST/RequiresExprBodyDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueStmt.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kRequiresExprDerivedKinds[] = {
    RequiresExpr::static_kind(),
};
}  // namespace

gap::generator<RequiresExpr> RequiresExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = RequiresExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool RequiresExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : RequiresExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

#ifndef MX_DISABLE_VAST
std::optional<RequiresExpr> RequiresExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<RequiresExpr, ir::Operation>> RequiresExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kRequiresExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<RequiresExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

#endif  // MX_DISABLE_VAST

gap::generator<RequiresExpr> RequiresExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = RequiresExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<RequiresExpr> RequiresExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<RequiresExpr> RequiresExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = RequiresExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<RequiresExpr> RequiresExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool RequiresExpr::contains(const Decl &decl) {
  for (auto &parent : RequiresExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool RequiresExpr::contains(const Stmt &stmt) {
  for (auto &parent : RequiresExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<RequiresExpr> RequiresExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<RequiresExpr> RequiresExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<RequiresExpr> RequiresExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case RequiresExpr::static_kind():
      return reinterpret_cast<const RequiresExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<RequiresExpr> RequiresExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kRequiresExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<RequiresExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<RequiresExpr> RequiresExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kRequiresExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<RequiresExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<RequiresExpr> RequiresExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kRequiresExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<RequiresExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<RequiresExpr> RequiresExpr::from(const Reference &r) {
  return RequiresExpr::from(r.as_statement());
}

std::optional<RequiresExpr> RequiresExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<RequiresExpr> RequiresExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

RequiresExprBodyDecl RequiresExpr::body(void) const {
  RawEntityId eid = impl->reader.getVal37();
  return RequiresExprBodyDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

unsigned RequiresExpr::num_local_parameters(void) const {
  return impl->reader.getVal15().size();
}

std::optional<ParmVarDecl> RequiresExpr::nth_local_parameter(unsigned n) const {
  auto list = impl->reader.getVal15();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ParmVarDecl::from_base(std::move(e));
}

gap::generator<ParmVarDecl> RequiresExpr::local_parameters(void) const & {
  auto list = impl->reader.getVal15();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->DeclFor(ep, v)) {
      if (auto e = ParmVarDecl::from_base(std::move(d15))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

Token RequiresExpr::r_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

Token RequiresExpr::requires_keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

bool RequiresExpr::is_satisfied(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
