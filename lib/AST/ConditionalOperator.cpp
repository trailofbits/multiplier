// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ConditionalOperator.h>
#include <multiplier/AST/AbstractConditionalOperator.h>
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
static const StmtKind kConditionalOperatorDerivedKinds[] = {
    ConditionalOperator::static_kind(),
};
}  // namespace

gap::generator<ConditionalOperator> ConditionalOperator::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kConditionalOperatorDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ConditionalOperator> e = from_base(std::move(eptr))) {
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
        if (std::optional<ConditionalOperator> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<ConditionalOperator> ConditionalOperator::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kConditionalOperatorDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ConditionalOperator> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

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

std::optional<ConditionalOperator> ConditionalOperator::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<ConditionalOperator, ir::Operation>> ConditionalOperator::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kConditionalOperatorDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<ConditionalOperator, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
    if (auto base = index.statement(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<ConditionalOperator> ConditionalOperator::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ConditionalOperator> ConditionalOperator::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case ConditionalOperator::static_kind():
      return reinterpret_cast<const ConditionalOperator &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<ConditionalOperator> ConditionalOperator::from(const Reference &r) {
  return ConditionalOperator::from(r.as_statement());
}

std::optional<ConditionalOperator> ConditionalOperator::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<ConditionalOperator> ConditionalOperator::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Expr ConditionalOperator::lhs(void) const {
  RawEntityId eid = impl->reader.getVal43();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr ConditionalOperator::rhs(void) const {
  RawEntityId eid = impl->reader.getVal44();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
