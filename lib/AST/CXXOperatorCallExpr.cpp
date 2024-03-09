// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXOperatorCallExpr.h>
#include <multiplier/AST/CallExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
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
static const StmtKind kCXXOperatorCallExprDerivedKinds[] = {
    CXXOperatorCallExpr::static_kind(),
};
}  // namespace

gap::generator<CXXOperatorCallExpr> CXXOperatorCallExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXOperatorCallExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXOperatorCallExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXOperatorCallExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<CXXOperatorCallExpr> CXXOperatorCallExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<CXXOperatorCallExpr, ir::Operation>> CXXOperatorCallExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kCXXOperatorCallExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<CXXOperatorCallExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<CXXOperatorCallExpr> CXXOperatorCallExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXOperatorCallExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXOperatorCallExpr> CXXOperatorCallExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXOperatorCallExpr> CXXOperatorCallExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXOperatorCallExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXOperatorCallExpr> CXXOperatorCallExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXOperatorCallExpr::contains(const Decl &decl) {
  for (auto &parent : CXXOperatorCallExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXOperatorCallExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXOperatorCallExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXOperatorCallExpr> CXXOperatorCallExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<CXXOperatorCallExpr> CXXOperatorCallExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<CXXOperatorCallExpr> CXXOperatorCallExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXOperatorCallExpr::static_kind():
      return reinterpret_cast<const CXXOperatorCallExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXOperatorCallExpr> CXXOperatorCallExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXOperatorCallExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXOperatorCallExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXOperatorCallExpr> CXXOperatorCallExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXOperatorCallExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXOperatorCallExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXOperatorCallExpr> CXXOperatorCallExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXOperatorCallExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXOperatorCallExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXOperatorCallExpr> CXXOperatorCallExpr::from(const Reference &r) {
  return CXXOperatorCallExpr::from(r.as_statement());
}

std::optional<CXXOperatorCallExpr> CXXOperatorCallExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<CXXOperatorCallExpr> CXXOperatorCallExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

OverloadedOperatorKind CXXOperatorCallExpr::operator_(void) const {
  return static_cast<OverloadedOperatorKind>(impl->reader.getVal92());
}

Token CXXOperatorCallExpr::operator_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal42());
}

bool CXXOperatorCallExpr::is_assignment_operation(void) const {
  return impl->reader.getVal91();
}

bool CXXOperatorCallExpr::is_comparison_operation(void) const {
  return impl->reader.getVal93();
}

bool CXXOperatorCallExpr::is_infix_binary_operation(void) const {
  return impl->reader.getVal94();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
