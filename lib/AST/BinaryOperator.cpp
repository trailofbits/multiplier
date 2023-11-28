// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/BinaryOperator.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueStmt.h>
#include <multiplier/AST/CompoundAssignOperator.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<BinaryOperator> BinaryOperator::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = BinaryOperator::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool BinaryOperator::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : BinaryOperator::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<BinaryOperator> BinaryOperator::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = BinaryOperator::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<BinaryOperator> BinaryOperator::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<BinaryOperator> BinaryOperator::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = BinaryOperator::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<BinaryOperator> BinaryOperator::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool BinaryOperator::contains(const Decl &decl) {
  for (auto &parent : BinaryOperator::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool BinaryOperator::contains(const Stmt &stmt) {
  for (auto &parent : BinaryOperator::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<BinaryOperator> BinaryOperator::by_id(const Index &index, EntityId eid) {
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

std::optional<BinaryOperator> BinaryOperator::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kBinaryOperatorDerivedKinds[] = {
    BinaryOperator::static_kind(),
    CompoundAssignOperator::static_kind(),
};

}  // namespace

std::optional<BinaryOperator> BinaryOperator::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case BinaryOperator::static_kind():
    case CompoundAssignOperator::static_kind():
      return reinterpret_cast<const BinaryOperator &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<BinaryOperator> BinaryOperator::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kBinaryOperatorDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<BinaryOperator> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BinaryOperator> BinaryOperator::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kBinaryOperatorDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<BinaryOperator> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BinaryOperator> BinaryOperator::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kBinaryOperatorDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<BinaryOperator> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<BinaryOperator> BinaryOperator::from(const Reference &r) {
  return BinaryOperator::from(r.as_statement());
}

std::optional<BinaryOperator> BinaryOperator::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<BinaryOperator> BinaryOperator::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Expr BinaryOperator::lhs(void) const {
  RawEntityId eid = impl->reader.getVal37();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

BinaryOperatorKind BinaryOperator::opcode(void) const {
  return static_cast<BinaryOperatorKind>(impl->reader.getVal95());
}

std::string_view BinaryOperator::opcode_string(void) const {
  capnp::Text::Reader data = impl->reader.getVal60();
  return std::string_view(data.cStr(), data.size());
}

Token BinaryOperator::operator_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

Expr BinaryOperator::rhs(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

bool BinaryOperator::has_stored_fp_features(void) const {
  return impl->reader.getVal89();
}

bool BinaryOperator::is_additive_operation(void) const {
  return impl->reader.getVal90();
}

bool BinaryOperator::is_assignment_operation(void) const {
  return impl->reader.getVal91();
}

bool BinaryOperator::is_bitwise_operation(void) const {
  return impl->reader.getVal92();
}

bool BinaryOperator::is_comma_operation(void) const {
  return impl->reader.getVal93();
}

bool BinaryOperator::is_comparison_operation(void) const {
  return impl->reader.getVal94();
}

bool BinaryOperator::is_compound_assignment_operation(void) const {
  return impl->reader.getVal96();
}

bool BinaryOperator::is_equality_operation(void) const {
  return impl->reader.getVal98();
}

bool BinaryOperator::is_logical_operation(void) const {
  return impl->reader.getVal99();
}

bool BinaryOperator::is_multiplicative_operation(void) const {
  return impl->reader.getVal100();
}

bool BinaryOperator::is_pointer_memory_operation(void) const {
  return impl->reader.getVal101();
}

bool BinaryOperator::is_relational_operation(void) const {
  return impl->reader.getVal102();
}

bool BinaryOperator::is_shift_assign_operation(void) const {
  return impl->reader.getVal103();
}

bool BinaryOperator::is_shift_operation(void) const {
  return impl->reader.getVal104();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx