// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SEHTryStmt.h>
#include <multiplier/AST/CompoundStmt.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/SEHExceptStmt.h>
#include <multiplier/AST/SEHFinallyStmt.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kSEHTryStmtDerivedKinds[] = {
    SEHTryStmt::static_kind(),
};
}  // namespace

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

std::optional<SEHTryStmt> SEHTryStmt::from(const ir::hl::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<SEHTryStmt, ir::hl::Operation>> SEHTryStmt::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::hl::Operation> res : Stmt::in(tu, kSEHTryStmtDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<SEHTryStmt, ir::hl::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
    if (auto base = index.statement(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<SEHTryStmt> SEHTryStmt::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<SEHTryStmt> SEHTryStmt::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case SEHTryStmt::static_kind():
      return reinterpret_cast<const SEHTryStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<SEHTryStmt> SEHTryStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kSEHTryStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<SEHTryStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SEHTryStmt> SEHTryStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kSEHTryStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<SEHTryStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SEHTryStmt> SEHTryStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kSEHTryStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<SEHTryStmt> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<SEHTryStmt> SEHTryStmt::from(const Reference &r) {
  return SEHTryStmt::from(r.as_statement());
}

std::optional<SEHTryStmt> SEHTryStmt::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<SEHTryStmt> SEHTryStmt::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

SEHExceptStmt SEHTryStmt::except_handler(void) const {
  RawEntityId eid = impl->reader.getVal9();
  return SEHExceptStmt::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

SEHFinallyStmt SEHTryStmt::finally_handler(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return SEHFinallyStmt::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
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
  return CompoundStmt::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Token SEHTryStmt::try_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal14());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
