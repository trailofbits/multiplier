// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/SizeOfPackExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateArgument.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<SizeOfPackExpr> SizeOfPackExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = SizeOfPackExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool SizeOfPackExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : SizeOfPackExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<SizeOfPackExpr> SizeOfPackExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = SizeOfPackExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<SizeOfPackExpr> SizeOfPackExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<SizeOfPackExpr> SizeOfPackExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = SizeOfPackExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<SizeOfPackExpr> SizeOfPackExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool SizeOfPackExpr::contains(const Decl &decl) {
  for (auto &parent : SizeOfPackExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool SizeOfPackExpr::contains(const Stmt &stmt) {
  for (auto &parent : SizeOfPackExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<SizeOfPackExpr> SizeOfPackExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return SizeOfPackExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kSizeOfPackExprDerivedKinds[] = {
    SizeOfPackExpr::static_kind(),
};

std::optional<SizeOfPackExpr> SizeOfPackExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case SizeOfPackExpr::static_kind():
      return reinterpret_cast<const SizeOfPackExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<SizeOfPackExpr> SizeOfPackExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kSizeOfPackExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<SizeOfPackExpr> e = SizeOfPackExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SizeOfPackExpr> SizeOfPackExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kSizeOfPackExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<SizeOfPackExpr> e = SizeOfPackExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SizeOfPackExpr> SizeOfPackExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kSizeOfPackExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<SizeOfPackExpr> e = SizeOfPackExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<SizeOfPackExpr> SizeOfPackExpr::from(const Reference &r) {
  return SizeOfPackExpr::from(r.as_statement());
}

std::optional<SizeOfPackExpr> SizeOfPackExpr::from(const TokenContext &t) {
  return SizeOfPackExpr::from(t.as_statement());
}

Token SizeOfPackExpr::operator_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

NamedDecl SizeOfPackExpr::pack(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return NamedDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

std::optional<unsigned> SizeOfPackExpr::pack_length(void) const {
  if (!impl->reader.getVal89()) {
    return std::nullopt;
  } else {
    return static_cast<unsigned>(impl->reader.getVal105());
  }
  return std::nullopt;
}

Token SizeOfPackExpr::pack_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

std::optional<std::vector<TemplateArgument>> SizeOfPackExpr::partial_arguments(void) const {
  if (!impl->reader.getVal90()) {
    return std::nullopt;
  }
  auto list = impl->reader.getVal15();
  std::vector<TemplateArgument> vec;
  vec.reserve(list.size());
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->TemplateArgumentFor(ep, v)) {
      vec.emplace_back(std::move(d15));
    }
  }
  return vec;
}

Token SizeOfPackExpr::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal41());
}

bool SizeOfPackExpr::is_partially_substituted(void) const {
  return impl->reader.getVal91();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
