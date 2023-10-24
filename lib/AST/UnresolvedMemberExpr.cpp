// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/UnresolvedMemberExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/OverloadExpr.h>
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
static const StmtKind kUnresolvedMemberExprDerivedKinds[] = {
    UnresolvedMemberExpr::static_kind(),
};
}  // namespace

gap::generator<UnresolvedMemberExpr> UnresolvedMemberExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UnresolvedMemberExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UnresolvedMemberExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UnresolvedMemberExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<UnresolvedMemberExpr> UnresolvedMemberExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<UnresolvedMemberExpr, ir::Operation>> UnresolvedMemberExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kUnresolvedMemberExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<UnresolvedMemberExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<UnresolvedMemberExpr> UnresolvedMemberExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = UnresolvedMemberExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnresolvedMemberExpr> UnresolvedMemberExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<UnresolvedMemberExpr> UnresolvedMemberExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = UnresolvedMemberExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnresolvedMemberExpr> UnresolvedMemberExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool UnresolvedMemberExpr::contains(const Decl &decl) {
  for (auto &parent : UnresolvedMemberExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool UnresolvedMemberExpr::contains(const Stmt &stmt) {
  for (auto &parent : UnresolvedMemberExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<UnresolvedMemberExpr> UnresolvedMemberExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<UnresolvedMemberExpr> UnresolvedMemberExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<UnresolvedMemberExpr> UnresolvedMemberExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case UnresolvedMemberExpr::static_kind():
      return reinterpret_cast<const UnresolvedMemberExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<UnresolvedMemberExpr> UnresolvedMemberExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kUnresolvedMemberExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<UnresolvedMemberExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnresolvedMemberExpr> UnresolvedMemberExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kUnresolvedMemberExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<UnresolvedMemberExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnresolvedMemberExpr> UnresolvedMemberExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kUnresolvedMemberExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<UnresolvedMemberExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<UnresolvedMemberExpr> UnresolvedMemberExpr::from(const Reference &r) {
  return UnresolvedMemberExpr::from(r.as_statement());
}

std::optional<UnresolvedMemberExpr> UnresolvedMemberExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<UnresolvedMemberExpr> UnresolvedMemberExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Type UnresolvedMemberExpr::base_type(void) const {
  RawEntityId eid = impl->reader.getVal42();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Token UnresolvedMemberExpr::member_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal43());
}

Token UnresolvedMemberExpr::operator_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal44());
}

bool UnresolvedMemberExpr::has_unresolved_using(void) const {
  return impl->reader.getVal88();
}

bool UnresolvedMemberExpr::is_arrow(void) const {
  return impl->reader.getVal89();
}

bool UnresolvedMemberExpr::is_implicit_access(void) const {
  return impl->reader.getVal90();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
