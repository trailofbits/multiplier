// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ExprWithCleanups.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/FullExpr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ExprWithCleanups> ExprWithCleanups::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ExprWithCleanups::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ExprWithCleanups::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ExprWithCleanups::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ExprWithCleanups> ExprWithCleanups::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ExprWithCleanups::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ExprWithCleanups> ExprWithCleanups::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ExprWithCleanups> ExprWithCleanups::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ExprWithCleanups::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ExprWithCleanups> ExprWithCleanups::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ExprWithCleanups::contains(const Decl &decl) {
  for (auto &parent : ExprWithCleanups::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ExprWithCleanups::contains(const Stmt &stmt) {
  for (auto &parent : ExprWithCleanups::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<ExprWithCleanups> ExprWithCleanups::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ExprWithCleanups::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kExprWithCleanupsDerivedKinds[] = {
    ExprWithCleanups::static_kind(),
};

std::optional<ExprWithCleanups> ExprWithCleanups::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ExprWithCleanups::static_kind():
      return reinterpret_cast<const ExprWithCleanups &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ExprWithCleanups> ExprWithCleanups::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kExprWithCleanupsDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ExprWithCleanups> e = ExprWithCleanups::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ExprWithCleanups> ExprWithCleanups::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kExprWithCleanupsDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ExprWithCleanups> e = ExprWithCleanups::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ExprWithCleanups> ExprWithCleanups::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kExprWithCleanupsDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ExprWithCleanups> e = ExprWithCleanups::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ExprWithCleanups> ExprWithCleanups::from(const Reference &r) {
  return ExprWithCleanups::from(r.as_statement());
}

std::optional<ExprWithCleanups> ExprWithCleanups::from(const TokenContext &t) {
  return ExprWithCleanups::from(t.as_statement());
}

bool ExprWithCleanups::cleanups_have_side_effects(void) const {
  return impl->reader.getVal88();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
