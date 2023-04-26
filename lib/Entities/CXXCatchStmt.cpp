// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXCatchStmt.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/VarDecl.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CXXCatchStmt> CXXCatchStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXCatchStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXCatchStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXCatchStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXCatchStmt> CXXCatchStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXCatchStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXCatchStmt> CXXCatchStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXCatchStmt> CXXCatchStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXCatchStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXCatchStmt> CXXCatchStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXCatchStmt::contains(const Decl &decl) {
  for (auto &parent : CXXCatchStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXCatchStmt::contains(const Stmt &stmt) {
  for (auto &parent : CXXCatchStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXCatchStmt> CXXCatchStmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CXXCatchStmt::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCXXCatchStmtDerivedKinds[] = {
    CXXCatchStmt::static_kind(),
};

std::optional<CXXCatchStmt> CXXCatchStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXCatchStmt::static_kind():
      return reinterpret_cast<const CXXCatchStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXCatchStmt> CXXCatchStmt::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kCXXCatchStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXCatchStmt> e = CXXCatchStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXCatchStmt> CXXCatchStmt::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXCatchStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXCatchStmt> e = CXXCatchStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXCatchStmt> CXXCatchStmt::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXCatchStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXCatchStmt> e = CXXCatchStmt::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXCatchStmt> CXXCatchStmt::from(const Reference &r) {
  return CXXCatchStmt::from(r.as_statement());
}

std::optional<CXXCatchStmt> CXXCatchStmt::from(const TokenContext &t) {
  return CXXCatchStmt::from(t.as_statement());
}

Token CXXCatchStmt::catch_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal9());
}

Type CXXCatchStmt::caught_type(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<VarDecl> CXXCatchStmt::exception_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal11();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return VarDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

Stmt CXXCatchStmt::handler_block(void) const {
  RawEntityId eid = impl->reader.getVal13();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
