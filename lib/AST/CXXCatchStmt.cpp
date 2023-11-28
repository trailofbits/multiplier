// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXCatchStmt.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/VarDecl.h>

#include "../EntityProvider.h"
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
    if (auto base = index.statement(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<CXXCatchStmt> CXXCatchStmt::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kCXXCatchStmtDerivedKinds[] = {
    CXXCatchStmt::static_kind(),
};

}  // namespace

std::optional<CXXCatchStmt> CXXCatchStmt::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXCatchStmt::static_kind():
      return reinterpret_cast<const CXXCatchStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXCatchStmt> CXXCatchStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXCatchStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXCatchStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXCatchStmt> CXXCatchStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXCatchStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXCatchStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXCatchStmt> CXXCatchStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXCatchStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXCatchStmt> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXCatchStmt> CXXCatchStmt::from(const Reference &r) {
  return CXXCatchStmt::from(r.as_statement());
}

std::optional<CXXCatchStmt> CXXCatchStmt::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<CXXCatchStmt> CXXCatchStmt::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
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
      return VarDecl::from_base(std::move(eptr));
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
