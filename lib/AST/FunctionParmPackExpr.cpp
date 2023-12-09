// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/FunctionParmPackExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueStmt.h>
#include <multiplier/AST/VarDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kFunctionParmPackExprDerivedKinds[] = {
    FunctionParmPackExpr::static_kind(),
};
}  // namespace

gap::generator<FunctionParmPackExpr> FunctionParmPackExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = FunctionParmPackExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool FunctionParmPackExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : FunctionParmPackExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<FunctionParmPackExpr> FunctionParmPackExpr::from(const ir::hl::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<FunctionParmPackExpr, ir::hl::Operation>> FunctionParmPackExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::hl::Operation> res : Stmt::in(tu, kFunctionParmPackExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<FunctionParmPackExpr, ir::hl::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<FunctionParmPackExpr> FunctionParmPackExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = FunctionParmPackExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<FunctionParmPackExpr> FunctionParmPackExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<FunctionParmPackExpr> FunctionParmPackExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = FunctionParmPackExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<FunctionParmPackExpr> FunctionParmPackExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool FunctionParmPackExpr::contains(const Decl &decl) {
  for (auto &parent : FunctionParmPackExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool FunctionParmPackExpr::contains(const Stmt &stmt) {
  for (auto &parent : FunctionParmPackExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<FunctionParmPackExpr> FunctionParmPackExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<FunctionParmPackExpr> FunctionParmPackExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<FunctionParmPackExpr> FunctionParmPackExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case FunctionParmPackExpr::static_kind():
      return reinterpret_cast<const FunctionParmPackExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<FunctionParmPackExpr> FunctionParmPackExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kFunctionParmPackExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<FunctionParmPackExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FunctionParmPackExpr> FunctionParmPackExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kFunctionParmPackExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<FunctionParmPackExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FunctionParmPackExpr> FunctionParmPackExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kFunctionParmPackExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<FunctionParmPackExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<FunctionParmPackExpr> FunctionParmPackExpr::from(const Reference &r) {
  return FunctionParmPackExpr::from(r.as_statement());
}

std::optional<FunctionParmPackExpr> FunctionParmPackExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<FunctionParmPackExpr> FunctionParmPackExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

VarDecl FunctionParmPackExpr::parameter_pack(void) const {
  RawEntityId eid = impl->reader.getVal37();
  return VarDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Token FunctionParmPackExpr::parameter_pack_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

unsigned FunctionParmPackExpr::num_expansions(void) const {
  return impl->reader.getVal15().size();
}

std::optional<VarDecl> FunctionParmPackExpr::nth_expansion(unsigned n) const {
  auto list = impl->reader.getVal15();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return VarDecl::from_base(std::move(e));
}

gap::generator<VarDecl> FunctionParmPackExpr::expansions(void) const & {
  auto list = impl->reader.getVal15();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->DeclFor(ep, v)) {
      if (auto e = VarDecl::from_base(std::move(d15))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
