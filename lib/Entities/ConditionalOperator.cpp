// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ConditionalOperator.h>

#include <multiplier/Entities/AbstractConditionalOperator.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ConditionalOperator> ConditionalOperator::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ConditionalOperator::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ConditionalOperator::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ConditionalOperator::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ConditionalOperator> ConditionalOperator::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ConditionalOperator::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ConditionalOperator> ConditionalOperator::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ConditionalOperator> ConditionalOperator::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ConditionalOperator::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ConditionalOperator> ConditionalOperator::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ConditionalOperator::contains(const Decl &decl) {
  for (auto &parent : ConditionalOperator::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ConditionalOperator::contains(const Stmt &stmt) {
  for (auto &parent : ConditionalOperator::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ConditionalOperator> ConditionalOperator::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ConditionalOperator::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kConditionalOperatorDerivedKinds[] = {
    ConditionalOperator::static_kind(),
};

std::optional<ConditionalOperator> ConditionalOperator::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ConditionalOperator::static_kind():
      return reinterpret_cast<const ConditionalOperator &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ConditionalOperator> ConditionalOperator::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kConditionalOperatorDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ConditionalOperator> e = ConditionalOperator::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ConditionalOperator> ConditionalOperator::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kConditionalOperatorDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ConditionalOperator> e = ConditionalOperator::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ConditionalOperator> ConditionalOperator::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kConditionalOperatorDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ConditionalOperator> e = ConditionalOperator::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ConditionalOperator> ConditionalOperator::from(const Reference &r) {
  return ConditionalOperator::from(r.as_statement());
}

std::optional<ConditionalOperator> ConditionalOperator::from(const TokenContext &t) {
  return ConditionalOperator::from(t.as_statement());
}

Expr ConditionalOperator::lhs(void) const {
  RawEntityId eid = impl->reader.getVal42();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr ConditionalOperator::rhs(void) const {
  RawEntityId eid = impl->reader.getVal43();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
