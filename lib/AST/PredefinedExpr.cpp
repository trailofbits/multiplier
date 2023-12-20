// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/PredefinedExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/StringLiteral.h>
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
static const StmtKind kPredefinedExprDerivedKinds[] = {
    PredefinedExpr::static_kind(),
};
}  // namespace

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

std::optional<PredefinedExpr> PredefinedExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<PredefinedExpr, ir::Operation>> PredefinedExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kPredefinedExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<PredefinedExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
    if (*this == parent) { return true; }
  }
  return false;
}

bool PredefinedExpr::contains(const Stmt &stmt) {
  for (auto &parent : PredefinedExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<PredefinedExpr> PredefinedExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<PredefinedExpr> PredefinedExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<PredefinedExpr> PredefinedExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case PredefinedExpr::static_kind():
      return reinterpret_cast<const PredefinedExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<PredefinedExpr> PredefinedExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kPredefinedExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<PredefinedExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<PredefinedExpr> PredefinedExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kPredefinedExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<PredefinedExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<PredefinedExpr> PredefinedExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kPredefinedExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<PredefinedExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<PredefinedExpr> PredefinedExpr::from(const Reference &r) {
  return PredefinedExpr::from(r.as_statement());
}

std::optional<PredefinedExpr> PredefinedExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<PredefinedExpr> PredefinedExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

StringLiteral PredefinedExpr::function_name(void) const {
  RawEntityId eid = impl->reader.getVal37();
  return StringLiteral::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

PredefinedExprIdentKind PredefinedExpr::identifier_kind(void) const {
  return static_cast<PredefinedExprIdentKind>(impl->reader.getVal95());
}

std::string_view PredefinedExpr::identifier_kind_name(void) const {
  capnp::Text::Reader data = impl->reader.getVal60();
  return std::string_view(data.cStr(), data.size());
}

Token PredefinedExpr::token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

bool PredefinedExpr::is_transparent(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
