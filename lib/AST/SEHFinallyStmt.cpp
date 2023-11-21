// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SEHFinallyStmt.h>

#include <multiplier/AST/CompoundStmt.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/Token.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<SEHFinallyStmt> SEHFinallyStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = SEHFinallyStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool SEHFinallyStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : SEHFinallyStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<SEHFinallyStmt> SEHFinallyStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = SEHFinallyStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<SEHFinallyStmt> SEHFinallyStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<SEHFinallyStmt> SEHFinallyStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = SEHFinallyStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<SEHFinallyStmt> SEHFinallyStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool SEHFinallyStmt::contains(const Decl &decl) {
  for (auto &parent : SEHFinallyStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool SEHFinallyStmt::contains(const Stmt &stmt) {
  for (auto &parent : SEHFinallyStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<SEHFinallyStmt> SEHFinallyStmt::by_id(const Index &index, EntityId eid) {
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

std::optional<SEHFinallyStmt> SEHFinallyStmt::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kSEHFinallyStmtDerivedKinds[] = {
    SEHFinallyStmt::static_kind(),
};

}  // namespace

std::optional<SEHFinallyStmt> SEHFinallyStmt::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case SEHFinallyStmt::static_kind():
      return reinterpret_cast<const SEHFinallyStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<SEHFinallyStmt> SEHFinallyStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kSEHFinallyStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<SEHFinallyStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SEHFinallyStmt> SEHFinallyStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kSEHFinallyStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<SEHFinallyStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SEHFinallyStmt> SEHFinallyStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kSEHFinallyStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<SEHFinallyStmt> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<SEHFinallyStmt> SEHFinallyStmt::from(const Reference &r) {
  return SEHFinallyStmt::from(r.as_statement());
}

std::optional<SEHFinallyStmt> SEHFinallyStmt::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<SEHFinallyStmt> SEHFinallyStmt::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

CompoundStmt SEHFinallyStmt::block(void) const {
  RawEntityId eid = impl->reader.getVal9();
  return CompoundStmt::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Token SEHFinallyStmt::finally_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal10());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
