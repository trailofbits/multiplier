// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXDestructorDecl.h>

#include <multiplier/Entities/CXXMethodDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DeclaratorDecl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/FunctionDecl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueDecl.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CXXDestructorDecl> CXXDestructorDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXDestructorDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXDestructorDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXDestructorDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXDestructorDecl> CXXDestructorDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = CXXDestructorDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXDestructorDecl> CXXDestructorDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXDestructorDecl> CXXDestructorDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = CXXDestructorDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXDestructorDecl> CXXDestructorDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXDestructorDecl::contains(const Decl &decl) {
  for (auto &parent : CXXDestructorDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXDestructorDecl::contains(const Stmt &stmt) {
  for (auto &parent : CXXDestructorDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

CXXDestructorDecl CXXDestructorDecl::canonical_declaration(void) const {
  if (auto canon = CXXDestructorDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (CXXDestructorDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<CXXDestructorDecl> CXXDestructorDecl::definition(void) const {
  return CXXDestructorDecl::from(this->Decl::definition());
}

gap::generator<CXXDestructorDecl> CXXDestructorDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<CXXDestructorDecl> dr = CXXDestructorDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<CXXDestructorDecl> CXXDestructorDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return CXXDestructorDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kCXXDestructorDeclDerivedKinds[] = {
    CXXDestructorDecl::static_kind(),
};

std::optional<CXXDestructorDecl> CXXDestructorDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case CXXDestructorDecl::static_kind():
      return reinterpret_cast<const CXXDestructorDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXDestructorDecl> CXXDestructorDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kCXXDestructorDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<CXXDestructorDecl> e = CXXDestructorDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXDestructorDecl> CXXDestructorDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kCXXDestructorDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<CXXDestructorDecl> e = CXXDestructorDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXDestructorDecl> CXXDestructorDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kCXXDestructorDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<CXXDestructorDecl> e = CXXDestructorDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXDestructorDecl> CXXDestructorDecl::from(const Reference &r) {
  return CXXDestructorDecl::from(r.as_declaration());
}

std::optional<CXXDestructorDecl> CXXDestructorDecl::from(const TokenContext &t) {
  return CXXDestructorDecl::from(t.as_declaration());
}

std::optional<FunctionDecl> CXXDestructorDecl::operator_delete(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal179();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FunctionDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

std::optional<Expr> CXXDestructorDecl::operator_delete_this_argument(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal180();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
