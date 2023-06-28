// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CompoundStmt.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CompoundStmt> CompoundStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CompoundStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CompoundStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CompoundStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CompoundStmt> CompoundStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CompoundStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CompoundStmt> CompoundStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CompoundStmt> CompoundStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CompoundStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CompoundStmt> CompoundStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CompoundStmt::contains(const Decl &decl) {
  for (auto &parent : CompoundStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CompoundStmt::contains(const Stmt &stmt) {
  for (auto &parent : CompoundStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CompoundStmt> CompoundStmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CompoundStmt::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCompoundStmtDerivedKinds[] = {
    CompoundStmt::static_kind(),
};

std::optional<CompoundStmt> CompoundStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CompoundStmt::static_kind():
      return reinterpret_cast<const CompoundStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CompoundStmt> CompoundStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCompoundStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CompoundStmt> e = CompoundStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CompoundStmt> CompoundStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCompoundStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CompoundStmt> e = CompoundStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CompoundStmt> CompoundStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCompoundStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CompoundStmt> e = CompoundStmt::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CompoundStmt> CompoundStmt::from(const Reference &r) {
  return CompoundStmt::from(r.as_statement());
}

std::optional<CompoundStmt> CompoundStmt::from(const TokenContext &t) {
  return CompoundStmt::from(t.as_statement());
}

Token CompoundStmt::left_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal10());
}

Token CompoundStmt::right_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal11());
}

std::optional<Stmt> CompoundStmt::statement_expression_result(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal12();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Stmt(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool CompoundStmt::has_stored_fp_features(void) const {
  return impl->reader.getVal13();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
