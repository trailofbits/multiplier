// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CapturedStmt.h>

#include <multiplier/Entities/CapturedDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/RecordDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CapturedStmt> CapturedStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CapturedStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CapturedStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CapturedStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CapturedStmt> CapturedStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CapturedStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CapturedStmt> CapturedStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CapturedStmt> CapturedStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CapturedStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CapturedStmt> CapturedStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CapturedStmt::contains(const Decl &decl) {
  for (auto &parent : CapturedStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CapturedStmt::contains(const Stmt &stmt) {
  for (auto &parent : CapturedStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CapturedStmt> CapturedStmt::by_id(const Index &index, EntityId eid) {
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

std::optional<CapturedStmt> CapturedStmt::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kCapturedStmtDerivedKinds[] = {
    CapturedStmt::static_kind(),
};

}  // namespace

std::optional<CapturedStmt> CapturedStmt::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case CapturedStmt::static_kind():
      return reinterpret_cast<const CapturedStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CapturedStmt> CapturedStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCapturedStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CapturedStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CapturedStmt> CapturedStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCapturedStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CapturedStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CapturedStmt> CapturedStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCapturedStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CapturedStmt> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CapturedStmt> CapturedStmt::from(const Reference &r) {
  return CapturedStmt::from(r.as_statement());
}

std::optional<CapturedStmt> CapturedStmt::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<CapturedStmt> CapturedStmt::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

CapturedDecl CapturedStmt::captured_declaration(void) const {
  RawEntityId eid = impl->reader.getVal9();
  return CapturedDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

RecordDecl CapturedStmt::captured_record_declaration(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return RecordDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

CapturedRegionKind CapturedStmt::captured_region_kind(void) const {
  return static_cast<CapturedRegionKind>(impl->reader.getVal56());
}

Stmt CapturedStmt::captured_statement(void) const {
  RawEntityId eid = impl->reader.getVal11();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
