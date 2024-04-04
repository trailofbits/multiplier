// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXConstructorDecl.h>
#include <multiplier/AST/CXXCtorInitializer.h>
#include <multiplier/AST/CXXMethodDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/DeclaratorDecl.h>
#include <multiplier/AST/FunctionDecl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kCXXConstructorDeclDerivedKinds[] = {
    CXXConstructorDecl::static_kind(),
};
}  // namespace

gap::generator<CXXConstructorDecl> CXXConstructorDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXConstructorDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXConstructorDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXConstructorDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<CXXConstructorDecl, ir::Operation>> CXXConstructorDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kCXXConstructorDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<CXXConstructorDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<CXXConstructorDecl> CXXConstructorDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = CXXConstructorDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXConstructorDecl> CXXConstructorDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXConstructorDecl> CXXConstructorDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = CXXConstructorDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXConstructorDecl> CXXConstructorDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXConstructorDecl::contains(const Decl &decl) {
  for (auto &parent : CXXConstructorDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXConstructorDecl::contains(const Stmt &stmt) {
  for (auto &parent : CXXConstructorDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

CXXConstructorDecl CXXConstructorDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (CXXConstructorDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<CXXConstructorDecl> CXXConstructorDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<CXXConstructorDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<CXXConstructorDecl> CXXConstructorDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case CXXConstructorDecl::static_kind():
      return reinterpret_cast<const CXXConstructorDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXConstructorDecl> CXXConstructorDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kCXXConstructorDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<CXXConstructorDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXConstructorDecl> CXXConstructorDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kCXXConstructorDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<CXXConstructorDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXConstructorDecl> CXXConstructorDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kCXXConstructorDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<CXXConstructorDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::from(const Reference &r) {
  return CXXConstructorDecl::from(r.as_declaration());
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::target_constructor(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal174();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return CXXConstructorDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

unsigned CXXConstructorDecl::num_initializers(void) const {
  return impl->reader.getVal178().size();
}

std::optional<CXXCtorInitializer> CXXConstructorDecl::nth_initializer(unsigned n) const {
  auto list = impl->reader.getVal178();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->CXXCtorInitializerFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return CXXCtorInitializer(std::move(e));
}

gap::generator<CXXCtorInitializer> CXXConstructorDecl::initializers(void) const & {
  auto list = impl->reader.getVal178();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d178 = ep->CXXCtorInitializerFor(ep, v)) {
      co_yield CXXCtorInitializer(std::move(d178));
    }
  }
  co_return;
}

bool CXXConstructorDecl::is_default_constructor(void) const {
  return impl->reader.getVal176();
}

bool CXXConstructorDecl::is_delegating_constructor(void) const {
  return impl->reader.getVal177();
}

bool CXXConstructorDecl::is_explicit(void) const {
  return impl->reader.getVal179();
}

bool CXXConstructorDecl::is_inheriting_constructor(void) const {
  return impl->reader.getVal180();
}

bool CXXConstructorDecl::is_specialization_copying_object(void) const {
  return impl->reader.getVal181();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
