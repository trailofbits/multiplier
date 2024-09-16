// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/GNUNullExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/Frontend/File.h>
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
static const StmtKind kGNUNullExprDerivedKinds[] = {
    GNUNullExpr::static_kind(),
};
}  // namespace

gap::generator<GNUNullExpr> GNUNullExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kGNUNullExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<GNUNullExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<GNUNullExpr> GNUNullExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kGNUNullExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<GNUNullExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<GNUNullExpr> GNUNullExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kGNUNullExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<GNUNullExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<GNUNullExpr> GNUNullExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = GNUNullExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool GNUNullExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : GNUNullExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<GNUNullExpr> GNUNullExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<GNUNullExpr, ir::Operation>> GNUNullExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kGNUNullExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<GNUNullExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<GNUNullExpr> GNUNullExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = GNUNullExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<GNUNullExpr> GNUNullExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<GNUNullExpr> GNUNullExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = GNUNullExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<GNUNullExpr> GNUNullExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool GNUNullExpr::contains(const Decl &decl) {
  for (auto &parent : GNUNullExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool GNUNullExpr::contains(const Stmt &stmt) {
  for (auto &parent : GNUNullExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<GNUNullExpr> GNUNullExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<GNUNullExpr> GNUNullExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<GNUNullExpr> GNUNullExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case GNUNullExpr::static_kind():
      return reinterpret_cast<const GNUNullExpr &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<GNUNullExpr> GNUNullExpr::from(const Reference &r) {
  return GNUNullExpr::from(r.as_statement());
}

std::optional<GNUNullExpr> GNUNullExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<GNUNullExpr> GNUNullExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token GNUNullExpr::token_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
