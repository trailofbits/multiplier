// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OMPThreadPrivateDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/OMPDeclarativeDirectiveDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kOMPThreadPrivateDeclDerivedKinds[] = {
    OMPThreadPrivateDecl::static_kind(),
};
}  // namespace

gap::generator<OMPThreadPrivateDecl> OMPThreadPrivateDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPThreadPrivateDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPThreadPrivateDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPThreadPrivateDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<OMPThreadPrivateDecl> OMPThreadPrivateDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<OMPThreadPrivateDecl, ir::Operation>> OMPThreadPrivateDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kOMPThreadPrivateDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<OMPThreadPrivateDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<OMPThreadPrivateDecl> OMPThreadPrivateDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = OMPThreadPrivateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPThreadPrivateDecl> OMPThreadPrivateDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPThreadPrivateDecl> OMPThreadPrivateDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = OMPThreadPrivateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPThreadPrivateDecl> OMPThreadPrivateDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPThreadPrivateDecl::contains(const Decl &decl) {
  for (auto &parent : OMPThreadPrivateDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPThreadPrivateDecl::contains(const Stmt &stmt) {
  for (auto &parent : OMPThreadPrivateDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

OMPThreadPrivateDecl OMPThreadPrivateDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (OMPThreadPrivateDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<OMPThreadPrivateDecl> OMPThreadPrivateDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<OMPThreadPrivateDecl> OMPThreadPrivateDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<OMPThreadPrivateDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<OMPThreadPrivateDecl> OMPThreadPrivateDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<OMPThreadPrivateDecl> OMPThreadPrivateDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<OMPThreadPrivateDecl> OMPThreadPrivateDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case OMPThreadPrivateDecl::static_kind():
      return reinterpret_cast<const OMPThreadPrivateDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPThreadPrivateDecl> OMPThreadPrivateDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kOMPThreadPrivateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<OMPThreadPrivateDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPThreadPrivateDecl> OMPThreadPrivateDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kOMPThreadPrivateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<OMPThreadPrivateDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPThreadPrivateDecl> OMPThreadPrivateDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kOMPThreadPrivateDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<OMPThreadPrivateDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPThreadPrivateDecl> OMPThreadPrivateDecl::from(const Reference &r) {
  return OMPThreadPrivateDecl::from(r.as_declaration());
}

std::optional<OMPThreadPrivateDecl> OMPThreadPrivateDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<OMPThreadPrivateDecl> OMPThreadPrivateDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

unsigned OMPThreadPrivateDecl::num_varlists(void) const {
  return impl->reader.getVal40().size();
}

std::optional<Expr> OMPThreadPrivateDecl::nth_varlist(unsigned n) const {
  auto list = impl->reader.getVal40();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from_base(std::move(e));
}

gap::generator<Expr> OMPThreadPrivateDecl::varlists(void) const & {
  auto list = impl->reader.getVal40();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d40 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from_base(std::move(d40))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
