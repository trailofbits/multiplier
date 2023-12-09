// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXReinterpretCastExpr.h>
#include <multiplier/AST/CXXNamedCastExpr.h>
#include <multiplier/AST/CastExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/ExplicitCastExpr.h>
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
static const StmtKind kCXXReinterpretCastExprDerivedKinds[] = {
    CXXReinterpretCastExpr::static_kind(),
};
}  // namespace

gap::generator<CXXReinterpretCastExpr> CXXReinterpretCastExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXReinterpretCastExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXReinterpretCastExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXReinterpretCastExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<CXXReinterpretCastExpr> CXXReinterpretCastExpr::from(const ir::hl::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<CXXReinterpretCastExpr, ir::hl::Operation>> CXXReinterpretCastExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::hl::Operation> res : Stmt::in(tu, kCXXReinterpretCastExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<CXXReinterpretCastExpr, ir::hl::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<CXXReinterpretCastExpr> CXXReinterpretCastExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXReinterpretCastExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXReinterpretCastExpr> CXXReinterpretCastExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXReinterpretCastExpr> CXXReinterpretCastExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXReinterpretCastExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXReinterpretCastExpr> CXXReinterpretCastExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXReinterpretCastExpr::contains(const Decl &decl) {
  for (auto &parent : CXXReinterpretCastExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXReinterpretCastExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXReinterpretCastExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXReinterpretCastExpr> CXXReinterpretCastExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<CXXReinterpretCastExpr> CXXReinterpretCastExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<CXXReinterpretCastExpr> CXXReinterpretCastExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXReinterpretCastExpr::static_kind():
      return reinterpret_cast<const CXXReinterpretCastExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXReinterpretCastExpr> CXXReinterpretCastExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXReinterpretCastExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXReinterpretCastExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXReinterpretCastExpr> CXXReinterpretCastExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXReinterpretCastExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXReinterpretCastExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXReinterpretCastExpr> CXXReinterpretCastExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXReinterpretCastExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXReinterpretCastExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXReinterpretCastExpr> CXXReinterpretCastExpr::from(const Reference &r) {
  return CXXReinterpretCastExpr::from(r.as_statement());
}

std::optional<CXXReinterpretCastExpr> CXXReinterpretCastExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<CXXReinterpretCastExpr> CXXReinterpretCastExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
