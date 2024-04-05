// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OverloadExpr.h>
#include <multiplier/AST/CXXRecordDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueStmt.h>
#include <multiplier/AST/UnresolvedLookupExpr.h>
#include <multiplier/AST/UnresolvedMemberExpr.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kOverloadExprDerivedKinds[] = {
    UnresolvedLookupExpr::static_kind(),
    UnresolvedMemberExpr::static_kind(),
};
}  // namespace

gap::generator<OverloadExpr> OverloadExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OverloadExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OverloadExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OverloadExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<OverloadExpr> OverloadExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<OverloadExpr, ir::Operation>> OverloadExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kOverloadExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<OverloadExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<OverloadExpr> OverloadExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OverloadExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OverloadExpr> OverloadExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OverloadExpr> OverloadExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OverloadExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OverloadExpr> OverloadExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OverloadExpr::contains(const Decl &decl) {
  for (auto &parent : OverloadExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OverloadExpr::contains(const Stmt &stmt) {
  for (auto &parent : OverloadExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<OverloadExpr> OverloadExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<OverloadExpr> OverloadExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<OverloadExpr> OverloadExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case UnresolvedLookupExpr::static_kind():
    case UnresolvedMemberExpr::static_kind():
      return reinterpret_cast<const OverloadExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OverloadExpr> OverloadExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kOverloadExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OverloadExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OverloadExpr> OverloadExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOverloadExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OverloadExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OverloadExpr> OverloadExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOverloadExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OverloadExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OverloadExpr> OverloadExpr::from(const Reference &r) {
  return OverloadExpr::from(r.as_statement());
}

std::optional<OverloadExpr> OverloadExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<OverloadExpr> OverloadExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

unsigned OverloadExpr::num_declarations(void) const {
  return impl->reader.getVal15().size();
}

std::optional<NamedDecl> OverloadExpr::nth_declaration(unsigned n) const {
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
  return NamedDecl::from_base(std::move(e));
}

gap::generator<NamedDecl> OverloadExpr::declarations(void) const & {
  auto list = impl->reader.getVal15();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->DeclFor(ep, v)) {
      if (auto e = NamedDecl::from_base(std::move(d15))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

Token OverloadExpr::l_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal37());
}

Token OverloadExpr::name_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

std::optional<CXXRecordDecl> OverloadExpr::naming_class(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal39();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return CXXRecordDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token OverloadExpr::r_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

Token OverloadExpr::template_keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal41());
}

bool OverloadExpr::has_explicit_template_arguments(void) const {
  return impl->reader.getVal84();
}

bool OverloadExpr::has_template_keyword(void) const {
  return impl->reader.getVal85();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
