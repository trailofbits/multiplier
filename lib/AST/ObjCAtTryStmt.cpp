// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCAtTryStmt.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/ObjCAtCatchStmt.h>
#include <multiplier/AST/ObjCAtFinallyStmt.h>
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
static const StmtKind kObjCAtTryStmtDerivedKinds[] = {
    ObjCAtTryStmt::static_kind(),
};
}  // namespace

gap::generator<ObjCAtTryStmt> ObjCAtTryStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kObjCAtTryStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCAtTryStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCAtTryStmt> ObjCAtTryStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCAtTryStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCAtTryStmt> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<ObjCAtTryStmt> ObjCAtTryStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCAtTryStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCAtTryStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCAtTryStmt> ObjCAtTryStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCAtTryStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCAtTryStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCAtTryStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ObjCAtTryStmt> ObjCAtTryStmt::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<ObjCAtTryStmt, ir::Operation>> ObjCAtTryStmt::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kObjCAtTryStmtDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<ObjCAtTryStmt, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<ObjCAtTryStmt> ObjCAtTryStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCAtTryStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCAtTryStmt> ObjCAtTryStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCAtTryStmt> ObjCAtTryStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCAtTryStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCAtTryStmt> ObjCAtTryStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCAtTryStmt::contains(const Decl &decl) {
  for (auto &parent : ObjCAtTryStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCAtTryStmt::contains(const Stmt &stmt) {
  for (auto &parent : ObjCAtTryStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ObjCAtTryStmt> ObjCAtTryStmt::by_id(const Index &index, EntityId eid) {
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

std::optional<ObjCAtTryStmt> ObjCAtTryStmt::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ObjCAtTryStmt> ObjCAtTryStmt::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCAtTryStmt::static_kind():
      return reinterpret_cast<const ObjCAtTryStmt &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<ObjCAtTryStmt> ObjCAtTryStmt::from(const Reference &r) {
  return ObjCAtTryStmt::from(r.as_statement());
}

std::optional<ObjCAtTryStmt> ObjCAtTryStmt::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<ObjCAtTryStmt> ObjCAtTryStmt::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token ObjCAtTryStmt::at_try_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal9());
}

ObjCAtFinallyStmt ObjCAtTryStmt::finally_statement(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return ObjCAtFinallyStmt::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Stmt ObjCAtTryStmt::try_body(void) const {
  RawEntityId eid = impl->reader.getVal11();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

unsigned ObjCAtTryStmt::num_catch_statements(void) const {
  return impl->reader.getVal15().size();
}

std::optional<ObjCAtCatchStmt> ObjCAtTryStmt::nth_catch_statement(unsigned n) const {
  auto list = impl->reader.getVal15();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCAtCatchStmt::from_base(std::move(e));
}

gap::generator<ObjCAtCatchStmt> ObjCAtTryStmt::catch_statements(void) const & {
  auto list = impl->reader.getVal15();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->StmtFor(ep, v)) {
      if (auto e = ObjCAtCatchStmt::from_base(std::move(d15))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
