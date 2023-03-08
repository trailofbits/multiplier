// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/GotoStmt.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/LabelDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<GotoStmt> GotoStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = GotoStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool GotoStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : GotoStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<GotoStmt> GotoStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = GotoStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<GotoStmt> GotoStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<GotoStmt> GotoStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = GotoStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<GotoStmt> GotoStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool GotoStmt::contains(const Decl &decl) {
  for (auto &parent : GotoStmt::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool GotoStmt::contains(const Stmt &stmt) {
  for (auto &parent : GotoStmt::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<GotoStmt> GotoStmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return GotoStmt::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kGotoStmtDerivedKinds[] = {
    GotoStmt::static_kind(),
};

std::optional<GotoStmt> GotoStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case GotoStmt::static_kind():
      return reinterpret_cast<const GotoStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<GotoStmt> GotoStmt::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kGotoStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<GotoStmt> e = GotoStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<GotoStmt> GotoStmt::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kGotoStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<GotoStmt> e = GotoStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<GotoStmt> GotoStmt::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kGotoStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<GotoStmt> e = GotoStmt::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<GotoStmt> GotoStmt::from(const Reference &r) {
  return GotoStmt::from(r.as_statement());
}

std::optional<GotoStmt> GotoStmt::from(const TokenContext &t) {
  return GotoStmt::from(t.as_statement());
}

Token GotoStmt::goto_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal9());
}

LabelDecl GotoStmt::label(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return LabelDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Token GotoStmt::label_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal11());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
