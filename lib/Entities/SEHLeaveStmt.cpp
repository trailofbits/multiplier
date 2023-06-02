// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/SEHLeaveStmt.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<SEHLeaveStmt> SEHLeaveStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = SEHLeaveStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool SEHLeaveStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : SEHLeaveStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<SEHLeaveStmt> SEHLeaveStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = SEHLeaveStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<SEHLeaveStmt> SEHLeaveStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<SEHLeaveStmt> SEHLeaveStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = SEHLeaveStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<SEHLeaveStmt> SEHLeaveStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool SEHLeaveStmt::contains(const Decl &decl) {
  for (auto &parent : SEHLeaveStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool SEHLeaveStmt::contains(const Stmt &stmt) {
  for (auto &parent : SEHLeaveStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<SEHLeaveStmt> SEHLeaveStmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return SEHLeaveStmt::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kSEHLeaveStmtDerivedKinds[] = {
    SEHLeaveStmt::static_kind(),
};

std::optional<SEHLeaveStmt> SEHLeaveStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case SEHLeaveStmt::static_kind():
      return reinterpret_cast<const SEHLeaveStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<SEHLeaveStmt> SEHLeaveStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kSEHLeaveStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<SEHLeaveStmt> e = SEHLeaveStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SEHLeaveStmt> SEHLeaveStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kSEHLeaveStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<SEHLeaveStmt> e = SEHLeaveStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SEHLeaveStmt> SEHLeaveStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kSEHLeaveStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<SEHLeaveStmt> e = SEHLeaveStmt::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<SEHLeaveStmt> SEHLeaveStmt::from(const Reference &r) {
  return SEHLeaveStmt::from(r.as_statement());
}

std::optional<SEHLeaveStmt> SEHLeaveStmt::from(const TokenContext &t) {
  return SEHLeaveStmt::from(t.as_statement());
}

Token SEHLeaveStmt::leave_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal12());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
