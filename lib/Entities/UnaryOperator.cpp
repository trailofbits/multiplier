// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/UnaryOperator.h>

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

gap::generator<UnaryOperator> UnaryOperator::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UnaryOperator::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UnaryOperator::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UnaryOperator::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<UnaryOperator> UnaryOperator::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = UnaryOperator::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnaryOperator> UnaryOperator::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<UnaryOperator> UnaryOperator::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = UnaryOperator::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnaryOperator> UnaryOperator::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool UnaryOperator::contains(const Decl &decl) {
  for (auto &parent : UnaryOperator::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool UnaryOperator::contains(const Stmt &stmt) {
  for (auto &parent : UnaryOperator::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<UnaryOperator> UnaryOperator::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return UnaryOperator::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kUnaryOperatorDerivedKinds[] = {
    UnaryOperator::static_kind(),
};

std::optional<UnaryOperator> UnaryOperator::from(const Stmt &parent) {
  switch (parent.kind()) {
    case UnaryOperator::static_kind():
      return reinterpret_cast<const UnaryOperator &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<UnaryOperator> UnaryOperator::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kUnaryOperatorDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<UnaryOperator> e = UnaryOperator::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnaryOperator> UnaryOperator::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kUnaryOperatorDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<UnaryOperator> e = UnaryOperator::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnaryOperator> UnaryOperator::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kUnaryOperatorDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<UnaryOperator> e = UnaryOperator::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<UnaryOperator> UnaryOperator::from(const Reference &r) {
  return UnaryOperator::from(r.as_statement());
}

std::optional<UnaryOperator> UnaryOperator::from(const TokenContext &t) {
  return UnaryOperator::from(t.as_statement());
}

bool UnaryOperator::can_overflow(void) const {
  return impl->reader.getVal89();
}

UnaryOperatorKind UnaryOperator::opcode(void) const {
  return static_cast<UnaryOperatorKind>(impl->reader.getVal94());
}

Token UnaryOperator::operator_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

Expr UnaryOperator::sub_expression(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

bool UnaryOperator::has_stored_fp_features(void) const {
  return impl->reader.getVal90();
}

bool UnaryOperator::is_arithmetic_operation(void) const {
  return impl->reader.getVal91();
}

bool UnaryOperator::is_decrement_operation(void) const {
  return impl->reader.getVal92();
}

bool UnaryOperator::is_increment_decrement_operation(void) const {
  return impl->reader.getVal93();
}

bool UnaryOperator::is_increment_operation(void) const {
  return impl->reader.getVal95();
}

bool UnaryOperator::is_postfix(void) const {
  return impl->reader.getVal97();
}

bool UnaryOperator::is_prefix(void) const {
  return impl->reader.getVal98();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
