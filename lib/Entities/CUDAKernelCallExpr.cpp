// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CUDAKernelCallExpr.h>

#include <multiplier/Entities/CallExpr.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CUDAKernelCallExpr> CUDAKernelCallExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CUDAKernelCallExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CUDAKernelCallExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CUDAKernelCallExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CUDAKernelCallExpr> CUDAKernelCallExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CUDAKernelCallExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CUDAKernelCallExpr> CUDAKernelCallExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CUDAKernelCallExpr> CUDAKernelCallExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CUDAKernelCallExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CUDAKernelCallExpr> CUDAKernelCallExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CUDAKernelCallExpr::contains(const Decl &decl) {
  for (auto &parent : CUDAKernelCallExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CUDAKernelCallExpr::contains(const Stmt &stmt) {
  for (auto &parent : CUDAKernelCallExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CUDAKernelCallExpr> CUDAKernelCallExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CUDAKernelCallExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCUDAKernelCallExprDerivedKinds[] = {
    CUDAKernelCallExpr::static_kind(),
};

std::optional<CUDAKernelCallExpr> CUDAKernelCallExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CUDAKernelCallExpr::static_kind():
      return reinterpret_cast<const CUDAKernelCallExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CUDAKernelCallExpr> CUDAKernelCallExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kCUDAKernelCallExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CUDAKernelCallExpr> e = CUDAKernelCallExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CUDAKernelCallExpr> CUDAKernelCallExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCUDAKernelCallExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CUDAKernelCallExpr> e = CUDAKernelCallExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CUDAKernelCallExpr> CUDAKernelCallExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCUDAKernelCallExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CUDAKernelCallExpr> e = CUDAKernelCallExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CUDAKernelCallExpr> CUDAKernelCallExpr::from(const Reference &r) {
  return CUDAKernelCallExpr::from(r.as_statement());
}

std::optional<CUDAKernelCallExpr> CUDAKernelCallExpr::from(const TokenContext &t) {
  return CUDAKernelCallExpr::from(t.as_statement());
}

CallExpr CUDAKernelCallExpr::config(void) const {
  RawEntityId eid = impl->reader.getVal44();
  return CallExpr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
