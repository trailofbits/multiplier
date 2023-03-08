// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/AddrLabelExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/LabelDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<AddrLabelExpr> AddrLabelExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = AddrLabelExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool AddrLabelExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : AddrLabelExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<AddrLabelExpr> AddrLabelExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = AddrLabelExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<AddrLabelExpr> AddrLabelExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<AddrLabelExpr> AddrLabelExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = AddrLabelExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<AddrLabelExpr> AddrLabelExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool AddrLabelExpr::contains(const Decl &decl) {
  for (auto &parent : AddrLabelExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool AddrLabelExpr::contains(const Stmt &stmt) {
  for (auto &parent : AddrLabelExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<AddrLabelExpr> AddrLabelExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return AddrLabelExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kAddrLabelExprDerivedKinds[] = {
    AddrLabelExpr::static_kind(),
};

std::optional<AddrLabelExpr> AddrLabelExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case AddrLabelExpr::static_kind():
      return reinterpret_cast<const AddrLabelExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<AddrLabelExpr> AddrLabelExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kAddrLabelExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<AddrLabelExpr> e = AddrLabelExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AddrLabelExpr> AddrLabelExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kAddrLabelExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<AddrLabelExpr> e = AddrLabelExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AddrLabelExpr> AddrLabelExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kAddrLabelExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<AddrLabelExpr> e = AddrLabelExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<AddrLabelExpr> AddrLabelExpr::from(const Reference &r) {
  return AddrLabelExpr::from(r.as_statement());
}

std::optional<AddrLabelExpr> AddrLabelExpr::from(const TokenContext &t) {
  return AddrLabelExpr::from(t.as_statement());
}

Token AddrLabelExpr::amp_amp_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

LabelDecl AddrLabelExpr::label(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return LabelDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Token AddrLabelExpr::label_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
