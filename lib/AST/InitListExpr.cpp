// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/InitListExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/FieldDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueStmt.h>

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
    if (auto base = index.statement(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<InitListExpr> InitListExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kInitListExprDerivedKinds[] = {
    InitListExpr::static_kind(),
};

}  // namespace

std::optional<InitListExpr> InitListExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case InitListExpr::static_kind():
      return reinterpret_cast<const InitListExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<InitListExpr> InitListExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kInitListExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<InitListExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<InitListExpr> InitListExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kInitListExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<InitListExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<InitListExpr> InitListExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kInitListExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<InitListExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<InitListExpr> InitListExpr::from(const Reference &r) {
  return InitListExpr::from(r.as_statement());
}

std::optional<InitListExpr> InitListExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<InitListExpr> InitListExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<Expr> InitListExpr::array_filler(void) const {
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

std::optional<FieldDecl> InitListExpr::initialized_field_in_union(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal38();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FieldDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token InitListExpr::l_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

Token InitListExpr::r_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

std::optional<InitListExpr> InitListExpr::semantic_form(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal41();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return InitListExpr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<InitListExpr> InitListExpr::syntactic_form(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal42();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return InitListExpr::from_base(std::move(eptr));
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

bool InitListExpr::has_designated_initializer(void) const {
  return impl->reader.getVal91();
}

unsigned InitListExpr::num_initializers(void) const {
  return impl->reader.getVal15().size();
}

std::optional<Expr> InitListExpr::nth_initializer(unsigned n) const {
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

gap::generator<Expr> InitListExpr::initializers(void) const & {
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

bool InitListExpr::is_explicit(void) const {
  return impl->reader.getVal92();
}

bool InitListExpr::is_semantic_form(void) const {
  return impl->reader.getVal93();
}

bool InitListExpr::is_string_literal_initializer(void) const {
  return impl->reader.getVal94();
}

bool InitListExpr::is_syntactic_form(void) const {
  return impl->reader.getVal96();
}

std::optional<bool> InitListExpr::is_transparent(void) const {
  if (!impl->reader.getVal99()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal98());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
