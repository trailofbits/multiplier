// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/UnaryExprOrTypeTraitExpr.h>

#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<UnaryExprOrTypeTraitExpr> UnaryExprOrTypeTraitExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UnaryExprOrTypeTraitExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UnaryExprOrTypeTraitExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UnaryExprOrTypeTraitExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<UnaryExprOrTypeTraitExpr> UnaryExprOrTypeTraitExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = UnaryExprOrTypeTraitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnaryExprOrTypeTraitExpr> UnaryExprOrTypeTraitExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<UnaryExprOrTypeTraitExpr> UnaryExprOrTypeTraitExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = UnaryExprOrTypeTraitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnaryExprOrTypeTraitExpr> UnaryExprOrTypeTraitExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool UnaryExprOrTypeTraitExpr::contains(const Decl &decl) {
  for (auto &parent : UnaryExprOrTypeTraitExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool UnaryExprOrTypeTraitExpr::contains(const Stmt &stmt) {
  for (auto &parent : UnaryExprOrTypeTraitExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<UnaryExprOrTypeTraitExpr> UnaryExprOrTypeTraitExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<UnaryExprOrTypeTraitExpr> UnaryExprOrTypeTraitExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kUnaryExprOrTypeTraitExprDerivedKinds[] = {
    UnaryExprOrTypeTraitExpr::static_kind(),
};

}  // namespace

std::optional<UnaryExprOrTypeTraitExpr> UnaryExprOrTypeTraitExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case UnaryExprOrTypeTraitExpr::static_kind():
      return reinterpret_cast<const UnaryExprOrTypeTraitExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<UnaryExprOrTypeTraitExpr> UnaryExprOrTypeTraitExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kUnaryExprOrTypeTraitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<UnaryExprOrTypeTraitExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnaryExprOrTypeTraitExpr> UnaryExprOrTypeTraitExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kUnaryExprOrTypeTraitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<UnaryExprOrTypeTraitExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnaryExprOrTypeTraitExpr> UnaryExprOrTypeTraitExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kUnaryExprOrTypeTraitExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<UnaryExprOrTypeTraitExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<UnaryExprOrTypeTraitExpr> UnaryExprOrTypeTraitExpr::from(const Reference &r) {
  return UnaryExprOrTypeTraitExpr::from(r.as_statement());
}

std::optional<UnaryExprOrTypeTraitExpr> UnaryExprOrTypeTraitExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<UnaryExprOrTypeTraitExpr> UnaryExprOrTypeTraitExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<Expr> UnaryExprOrTypeTraitExpr::argument_expression(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal37();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<Type> UnaryExprOrTypeTraitExpr::argument_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal38();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

UnaryExprOrTypeTrait UnaryExprOrTypeTraitExpr::keyword_kind(void) const {
  return static_cast<UnaryExprOrTypeTrait>(impl->reader.getVal95());
}

Token UnaryExprOrTypeTraitExpr::operator_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

Token UnaryExprOrTypeTraitExpr::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

Type UnaryExprOrTypeTraitExpr::type_of_argument(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool UnaryExprOrTypeTraitExpr::is_argument_type(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
