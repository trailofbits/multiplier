// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/PredefinedExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/StringLiteral.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<PredefinedExpr> PredefinedExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = PredefinedExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool PredefinedExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : PredefinedExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<PredefinedExpr> PredefinedExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = PredefinedExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<PredefinedExpr> PredefinedExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<PredefinedExpr> PredefinedExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = PredefinedExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<PredefinedExpr> PredefinedExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool PredefinedExpr::contains(const Decl &decl) {
  for (auto &parent : PredefinedExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool PredefinedExpr::contains(const Stmt &stmt) {
  for (auto &parent : PredefinedExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<PredefinedExpr> PredefinedExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return PredefinedExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kPredefinedExprDerivedKinds[] = {
    PredefinedExpr::static_kind(),
};

std::optional<PredefinedExpr> PredefinedExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case PredefinedExpr::static_kind():
      return reinterpret_cast<const PredefinedExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<PredefinedExpr> PredefinedExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kPredefinedExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<PredefinedExpr> e = PredefinedExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<PredefinedExpr> PredefinedExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kPredefinedExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<PredefinedExpr> e = PredefinedExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<PredefinedExpr> PredefinedExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kPredefinedExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<PredefinedExpr> e = PredefinedExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

StringLiteral PredefinedExpr::function_name(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return StringLiteral::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

PredefinedExprIdentKind PredefinedExpr::identifier_kind(void) const {
  return static_cast<PredefinedExprIdentKind>(impl->reader.getVal93());
}

std::string_view PredefinedExpr::identifier_kind_name(void) const {
  capnp::Text::Reader data = impl->reader.getVal60();
  return std::string_view(data.cStr(), data.size());
}

Token PredefinedExpr::token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
