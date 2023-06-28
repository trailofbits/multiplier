// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/NullStmt.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<NullStmt> NullStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = NullStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool NullStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : NullStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<NullStmt> NullStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = NullStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<NullStmt> NullStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<NullStmt> NullStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = NullStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<NullStmt> NullStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool NullStmt::contains(const Decl &decl) {
  for (auto &parent : NullStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool NullStmt::contains(const Stmt &stmt) {
  for (auto &parent : NullStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<NullStmt> NullStmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return NullStmt::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kNullStmtDerivedKinds[] = {
    NullStmt::static_kind(),
};

std::optional<NullStmt> NullStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case NullStmt::static_kind():
      return reinterpret_cast<const NullStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<NullStmt> NullStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kNullStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<NullStmt> e = NullStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<NullStmt> NullStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kNullStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<NullStmt> e = NullStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<NullStmt> NullStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kNullStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<NullStmt> e = NullStmt::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<NullStmt> NullStmt::from(const Reference &r) {
  return NullStmt::from(r.as_statement());
}

std::optional<NullStmt> NullStmt::from(const TokenContext &t) {
  return NullStmt::from(t.as_statement());
}

Token NullStmt::semi_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal10());
}

bool NullStmt::has_leading_empty_macro(void) const {
  return impl->reader.getVal13();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
