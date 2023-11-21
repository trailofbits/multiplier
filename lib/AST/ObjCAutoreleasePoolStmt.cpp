// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCAutoreleasePoolStmt.h>

#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/Token.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCAutoreleasePoolStmt> ObjCAutoreleasePoolStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCAutoreleasePoolStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCAutoreleasePoolStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCAutoreleasePoolStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCAutoreleasePoolStmt> ObjCAutoreleasePoolStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCAutoreleasePoolStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCAutoreleasePoolStmt> ObjCAutoreleasePoolStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCAutoreleasePoolStmt> ObjCAutoreleasePoolStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCAutoreleasePoolStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCAutoreleasePoolStmt> ObjCAutoreleasePoolStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCAutoreleasePoolStmt::contains(const Decl &decl) {
  for (auto &parent : ObjCAutoreleasePoolStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCAutoreleasePoolStmt::contains(const Stmt &stmt) {
  for (auto &parent : ObjCAutoreleasePoolStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ObjCAutoreleasePoolStmt> ObjCAutoreleasePoolStmt::by_id(const Index &index, EntityId eid) {
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

std::optional<ObjCAutoreleasePoolStmt> ObjCAutoreleasePoolStmt::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kObjCAutoreleasePoolStmtDerivedKinds[] = {
    ObjCAutoreleasePoolStmt::static_kind(),
};

}  // namespace

std::optional<ObjCAutoreleasePoolStmt> ObjCAutoreleasePoolStmt::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCAutoreleasePoolStmt::static_kind():
      return reinterpret_cast<const ObjCAutoreleasePoolStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCAutoreleasePoolStmt> ObjCAutoreleasePoolStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kObjCAutoreleasePoolStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCAutoreleasePoolStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCAutoreleasePoolStmt> ObjCAutoreleasePoolStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCAutoreleasePoolStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCAutoreleasePoolStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCAutoreleasePoolStmt> ObjCAutoreleasePoolStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCAutoreleasePoolStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCAutoreleasePoolStmt> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCAutoreleasePoolStmt> ObjCAutoreleasePoolStmt::from(const Reference &r) {
  return ObjCAutoreleasePoolStmt::from(r.as_statement());
}

std::optional<ObjCAutoreleasePoolStmt> ObjCAutoreleasePoolStmt::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<ObjCAutoreleasePoolStmt> ObjCAutoreleasePoolStmt::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token ObjCAutoreleasePoolStmt::at_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal9());
}

Stmt ObjCAutoreleasePoolStmt::sub_statement(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
