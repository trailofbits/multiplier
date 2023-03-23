// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/RequiresExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/ParmVarDecl.h>
#include <multiplier/Entities/RequiresExprBodyDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

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
    if (parent == *this) { return true; }
  }
  return false;
}

bool RequiresExpr::contains(const Stmt &stmt) {
  for (auto &parent : RequiresExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<RequiresExpr> RequiresExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return RequiresExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kRequiresExprDerivedKinds[] = {
    RequiresExpr::static_kind(),
};

std::optional<RequiresExpr> RequiresExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case RequiresExpr::static_kind():
      return reinterpret_cast<const RequiresExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<RequiresExpr> RequiresExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kRequiresExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<RequiresExpr> e = RequiresExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<RequiresExpr> RequiresExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kRequiresExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<RequiresExpr> e = RequiresExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<RequiresExpr> RequiresExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kRequiresExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<RequiresExpr> e = RequiresExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<RequiresExpr> RequiresExpr::from(const Reference &r) {
  return RequiresExpr::from(r.as_statement());
}

std::optional<RequiresExpr> RequiresExpr::from(const TokenContext &t) {
  return RequiresExpr::from(t.as_statement());
}

RequiresExprBodyDecl RequiresExpr::body(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return RequiresExprBodyDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

unsigned RequiresExpr::num_local_parameters(void) const {
  return impl->reader.getVal15().size();
}

std::optional<ParmVarDecl> RequiresExpr::nth_local_parameter(unsigned n) const {
  auto list = impl->reader.getVal15();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ParmVarDecl::from(Decl(std::move(e)));
}

gap::generator<ParmVarDecl> RequiresExpr::local_parameters(void) const & {
  auto list = impl->reader.getVal15();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->DeclFor(ep, v)) {
      if (auto e = ParmVarDecl::from(Decl(std::move(d15)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

Token RequiresExpr::r_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

Token RequiresExpr::requires_keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

bool RequiresExpr::is_satisfied(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
