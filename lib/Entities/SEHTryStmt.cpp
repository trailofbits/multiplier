// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/SEHTryStmt.h>

#include <multiplier/Entities/CompoundStmt.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/SEHExceptStmt.h>
#include <multiplier/Entities/SEHFinallyStmt.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<SEHTryStmt> SEHTryStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = SEHTryStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool SEHTryStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : SEHTryStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<SEHTryStmt> SEHTryStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = SEHTryStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<SEHTryStmt> SEHTryStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<SEHTryStmt> SEHTryStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = SEHTryStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<SEHTryStmt> SEHTryStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool SEHTryStmt::contains(const Decl &decl) {
  for (auto &parent : SEHTryStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool SEHTryStmt::contains(const Stmt &stmt) {
  for (auto &parent : SEHTryStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<SEHTryStmt> SEHTryStmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return SEHTryStmt::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kSEHTryStmtDerivedKinds[] = {
    SEHTryStmt::static_kind(),
};

std::optional<SEHTryStmt> SEHTryStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case SEHTryStmt::static_kind():
      return reinterpret_cast<const SEHTryStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<SEHTryStmt> SEHTryStmt::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kSEHTryStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<SEHTryStmt> e = SEHTryStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SEHTryStmt> SEHTryStmt::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kSEHTryStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<SEHTryStmt> e = SEHTryStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SEHTryStmt> SEHTryStmt::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kSEHTryStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<SEHTryStmt> e = SEHTryStmt::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<SEHTryStmt> SEHTryStmt::from(const Reference &r) {
  return SEHTryStmt::from(r.as_statement());
}

std::optional<SEHTryStmt> SEHTryStmt::from(const TokenContext &t) {
  return SEHTryStmt::from(t.as_statement());
}

SEHExceptStmt SEHTryStmt::except_handler(void) const {
  RawEntityId eid = impl->reader.getVal9();
  return SEHExceptStmt::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

SEHFinallyStmt SEHTryStmt::finally_handler(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return SEHFinallyStmt::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Stmt SEHTryStmt::handler(void) const {
  RawEntityId eid = impl->reader.getVal11();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

bool SEHTryStmt::is_cxx_try(void) const {
  return impl->reader.getVal12();
}

CompoundStmt SEHTryStmt::try_block(void) const {
  RawEntityId eid = impl->reader.getVal13();
  return CompoundStmt::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token SEHTryStmt::try_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal14());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
