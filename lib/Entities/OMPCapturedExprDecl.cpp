// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPCapturedExprDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DeclaratorDecl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueDecl.h>
#include <multiplier/Entities/VarDecl.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OMPCapturedExprDecl> OMPCapturedExprDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPCapturedExprDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPCapturedExprDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPCapturedExprDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPCapturedExprDecl> OMPCapturedExprDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = OMPCapturedExprDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPCapturedExprDecl> OMPCapturedExprDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPCapturedExprDecl> OMPCapturedExprDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = OMPCapturedExprDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPCapturedExprDecl> OMPCapturedExprDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPCapturedExprDecl::contains(const Decl &decl) {
  for (auto &parent : OMPCapturedExprDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool OMPCapturedExprDecl::contains(const Stmt &stmt) {
  for (auto &parent : OMPCapturedExprDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<OMPCapturedExprDecl> OMPCapturedExprDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<OMPCapturedExprDecl> dr = OMPCapturedExprDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<OMPCapturedExprDecl> OMPCapturedExprDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return OMPCapturedExprDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kOMPCapturedExprDeclDerivedKinds[] = {
    OMPCapturedExprDecl::static_kind(),
};

std::optional<OMPCapturedExprDecl> OMPCapturedExprDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case OMPCapturedExprDecl::static_kind():
      return reinterpret_cast<const OMPCapturedExprDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPCapturedExprDecl> OMPCapturedExprDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kOMPCapturedExprDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<OMPCapturedExprDecl> e = OMPCapturedExprDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPCapturedExprDecl> OMPCapturedExprDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kOMPCapturedExprDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<OMPCapturedExprDecl> e = OMPCapturedExprDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPCapturedExprDecl> OMPCapturedExprDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kOMPCapturedExprDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<OMPCapturedExprDecl> e = OMPCapturedExprDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx