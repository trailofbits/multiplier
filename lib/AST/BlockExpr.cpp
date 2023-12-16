// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/BlockExpr.h>
#include <multiplier/AST/BlockDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/FunctionProtoType.h>
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
static const StmtKind kBlockExprDerivedKinds[] = {
    BlockExpr::static_kind(),
};
}  // namespace

gap::generator<BlockExpr> BlockExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = BlockExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool BlockExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : BlockExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

#ifndef MX_DISABLE_VAST
std::optional<BlockExpr> BlockExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<BlockExpr, ir::Operation>> BlockExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kBlockExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<BlockExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

#endif  // MX_DISABLE_VAST

gap::generator<BlockExpr> BlockExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = BlockExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<BlockExpr> BlockExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<BlockExpr> BlockExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = BlockExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<BlockExpr> BlockExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool BlockExpr::contains(const Decl &decl) {
  for (auto &parent : BlockExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool BlockExpr::contains(const Stmt &stmt) {
  for (auto &parent : BlockExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<BlockExpr> BlockExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<BlockExpr> BlockExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<BlockExpr> BlockExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case BlockExpr::static_kind():
      return reinterpret_cast<const BlockExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<BlockExpr> BlockExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kBlockExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<BlockExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BlockExpr> BlockExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kBlockExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<BlockExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BlockExpr> BlockExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kBlockExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<BlockExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<BlockExpr> BlockExpr::from(const Reference &r) {
  return BlockExpr::from(r.as_statement());
}

std::optional<BlockExpr> BlockExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<BlockExpr> BlockExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

BlockDecl BlockExpr::block_declaration(void) const {
  RawEntityId eid = impl->reader.getVal37();
  return BlockDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Stmt BlockExpr::body(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

Token BlockExpr::caret_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

FunctionProtoType BlockExpr::function_type(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return FunctionProtoType::from_base(impl->ep->TypeFor(impl->ep, eid)).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
