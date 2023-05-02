// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/AbstractConditionalOperator.h>

#include <multiplier/Entities/BinaryConditionalOperator.h>
#include <multiplier/Entities/ConditionalOperator.h>
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

gap::generator<AbstractConditionalOperator> AbstractConditionalOperator::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = AbstractConditionalOperator::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool AbstractConditionalOperator::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : AbstractConditionalOperator::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<AbstractConditionalOperator> AbstractConditionalOperator::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = AbstractConditionalOperator::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<AbstractConditionalOperator> AbstractConditionalOperator::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<AbstractConditionalOperator> AbstractConditionalOperator::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = AbstractConditionalOperator::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<AbstractConditionalOperator> AbstractConditionalOperator::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool AbstractConditionalOperator::contains(const Decl &decl) {
  for (auto &parent : AbstractConditionalOperator::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool AbstractConditionalOperator::contains(const Stmt &stmt) {
  for (auto &parent : AbstractConditionalOperator::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<AbstractConditionalOperator> AbstractConditionalOperator::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return AbstractConditionalOperator::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kAbstractConditionalOperatorDerivedKinds[] = {
    BinaryConditionalOperator::static_kind(),
    ConditionalOperator::static_kind(),
};

std::optional<AbstractConditionalOperator> AbstractConditionalOperator::from(const Stmt &parent) {
  switch (parent.kind()) {
    case BinaryConditionalOperator::static_kind():
    case ConditionalOperator::static_kind():
      return reinterpret_cast<const AbstractConditionalOperator &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<AbstractConditionalOperator> AbstractConditionalOperator::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kAbstractConditionalOperatorDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<AbstractConditionalOperator> e = AbstractConditionalOperator::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AbstractConditionalOperator> AbstractConditionalOperator::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kAbstractConditionalOperatorDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<AbstractConditionalOperator> e = AbstractConditionalOperator::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AbstractConditionalOperator> AbstractConditionalOperator::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kAbstractConditionalOperatorDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<AbstractConditionalOperator> e = AbstractConditionalOperator::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<AbstractConditionalOperator> AbstractConditionalOperator::from(const Reference &r) {
  return AbstractConditionalOperator::from(r.as_statement());
}

std::optional<AbstractConditionalOperator> AbstractConditionalOperator::from(const TokenContext &t) {
  return AbstractConditionalOperator::from(t.as_statement());
}

Token AbstractConditionalOperator::colon_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

Expr AbstractConditionalOperator::condition(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr AbstractConditionalOperator::false_expression(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token AbstractConditionalOperator::question_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal41());
}

Expr AbstractConditionalOperator::true_expression(void) const {
  RawEntityId eid = impl->reader.getVal42();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
