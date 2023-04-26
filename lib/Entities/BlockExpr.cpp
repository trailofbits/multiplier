// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/BlockExpr.h>

#include <multiplier/Entities/BlockDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/FunctionProtoType.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

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
    return BlockExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kBlockExprDerivedKinds[] = {
    BlockExpr::static_kind(),
};

std::optional<BlockExpr> BlockExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case BlockExpr::static_kind():
      return reinterpret_cast<const BlockExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<BlockExpr> BlockExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kBlockExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<BlockExpr> e = BlockExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BlockExpr> BlockExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kBlockExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<BlockExpr> e = BlockExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BlockExpr> BlockExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kBlockExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<BlockExpr> e = BlockExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<BlockExpr> BlockExpr::from(const Reference &r) {
  return BlockExpr::from(r.as_statement());
}

std::optional<BlockExpr> BlockExpr::from(const TokenContext &t) {
  return BlockExpr::from(t.as_statement());
}

BlockDecl BlockExpr::block_declaration(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return BlockDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Stmt BlockExpr::body(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

Token BlockExpr::caret_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

FunctionProtoType BlockExpr::function_type(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return FunctionProtoType::from(Type(impl->ep->TypeFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
