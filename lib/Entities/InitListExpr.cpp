// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/InitListExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/FieldDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<InitListExpr> InitListExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = InitListExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool InitListExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : InitListExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<InitListExpr> InitListExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = InitListExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<InitListExpr> InitListExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<InitListExpr> InitListExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = InitListExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<InitListExpr> InitListExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool InitListExpr::contains(const Decl &decl) {
  for (auto &parent : InitListExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool InitListExpr::contains(const Stmt &stmt) {
  for (auto &parent : InitListExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<InitListExpr> InitListExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return InitListExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kInitListExprDerivedKinds[] = {
    InitListExpr::static_kind(),
};

std::optional<InitListExpr> InitListExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case InitListExpr::static_kind():
      return reinterpret_cast<const InitListExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<InitListExpr> InitListExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kInitListExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<InitListExpr> e = InitListExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<InitListExpr> InitListExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kInitListExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<InitListExpr> e = InitListExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<InitListExpr> InitListExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kInitListExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<InitListExpr> e = InitListExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<InitListExpr> InitListExpr::from(const Reference &r) {
  return InitListExpr::from(r.as_statement());
}

std::optional<InitListExpr> InitListExpr::from(const TokenContext &t) {
  return InitListExpr::from(t.as_statement());
}

std::optional<Expr> InitListExpr::array_filler(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal38();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

std::optional<FieldDecl> InitListExpr::initialized_field_in_union(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal39();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FieldDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

Token InitListExpr::l_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

Token InitListExpr::r_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal41());
}

std::optional<InitListExpr> InitListExpr::semantic_form(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal42();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return InitListExpr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

std::optional<InitListExpr> InitListExpr::syntactic_form(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal43();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return InitListExpr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

bool InitListExpr::had_array_range_designator(void) const {
  return impl->reader.getVal89();
}

bool InitListExpr::has_array_filler(void) const {
  return impl->reader.getVal90();
}

unsigned InitListExpr::num_initializers(void) const {
  return impl->reader.getVal15().size();
}

std::optional<Expr> InitListExpr::nth_initializer(unsigned n) const {
  auto list = impl->reader.getVal15();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from(Stmt(std::move(e)));
}

gap::generator<Expr> InitListExpr::initializers(void) const & {
  auto list = impl->reader.getVal15();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from(Stmt(std::move(d15)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

bool InitListExpr::is_explicit(void) const {
  return impl->reader.getVal91();
}

bool InitListExpr::is_semantic_form(void) const {
  return impl->reader.getVal92();
}

bool InitListExpr::is_string_literal_initializer(void) const {
  return impl->reader.getVal93();
}

bool InitListExpr::is_syntactic_form(void) const {
  return impl->reader.getVal95();
}

std::optional<bool> InitListExpr::is_transparent(void) const {
  if (!impl->reader.getVal98()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal97());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
