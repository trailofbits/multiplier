// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCAvailabilityCheckExpr.h>
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
static const StmtKind kObjCAvailabilityCheckExprDerivedKinds[] = {
    ObjCAvailabilityCheckExpr::static_kind(),
};
}  // namespace

gap::generator<ObjCAvailabilityCheckExpr> ObjCAvailabilityCheckExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCAvailabilityCheckExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCAvailabilityCheckExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCAvailabilityCheckExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ObjCAvailabilityCheckExpr> ObjCAvailabilityCheckExpr::from(const ir::hl::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<ObjCAvailabilityCheckExpr, ir::hl::Operation>> ObjCAvailabilityCheckExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::hl::Operation> res : Stmt::in(tu, kObjCAvailabilityCheckExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<ObjCAvailabilityCheckExpr, ir::hl::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<ObjCAvailabilityCheckExpr> ObjCAvailabilityCheckExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCAvailabilityCheckExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCAvailabilityCheckExpr> ObjCAvailabilityCheckExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCAvailabilityCheckExpr> ObjCAvailabilityCheckExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCAvailabilityCheckExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCAvailabilityCheckExpr> ObjCAvailabilityCheckExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCAvailabilityCheckExpr::contains(const Decl &decl) {
  for (auto &parent : ObjCAvailabilityCheckExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCAvailabilityCheckExpr::contains(const Stmt &stmt) {
  for (auto &parent : ObjCAvailabilityCheckExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ObjCAvailabilityCheckExpr> ObjCAvailabilityCheckExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<ObjCAvailabilityCheckExpr> ObjCAvailabilityCheckExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ObjCAvailabilityCheckExpr> ObjCAvailabilityCheckExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCAvailabilityCheckExpr::static_kind():
      return reinterpret_cast<const ObjCAvailabilityCheckExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCAvailabilityCheckExpr> ObjCAvailabilityCheckExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kObjCAvailabilityCheckExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCAvailabilityCheckExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCAvailabilityCheckExpr> ObjCAvailabilityCheckExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCAvailabilityCheckExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCAvailabilityCheckExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCAvailabilityCheckExpr> ObjCAvailabilityCheckExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCAvailabilityCheckExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCAvailabilityCheckExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCAvailabilityCheckExpr> ObjCAvailabilityCheckExpr::from(const Reference &r) {
  return ObjCAvailabilityCheckExpr::from(r.as_statement());
}

std::optional<ObjCAvailabilityCheckExpr> ObjCAvailabilityCheckExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<ObjCAvailabilityCheckExpr> ObjCAvailabilityCheckExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

bool ObjCAvailabilityCheckExpr::has_version(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
