// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXMethodDecl.h>

#include <multiplier/Entities/CXXConstructorDecl.h>
#include <multiplier/Entities/CXXConversionDecl.h>
#include <multiplier/Entities/CXXDestructorDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DeclaratorDecl.h>
#include <multiplier/Entities/FunctionDecl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/ValueDecl.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CXXMethodDecl> CXXMethodDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXMethodDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXMethodDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXMethodDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXMethodDecl> CXXMethodDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = CXXMethodDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXMethodDecl> CXXMethodDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXMethodDecl> CXXMethodDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = CXXMethodDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXMethodDecl> CXXMethodDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXMethodDecl::contains(const Decl &decl) {
  for (auto &parent : CXXMethodDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXMethodDecl::contains(const Stmt &stmt) {
  for (auto &parent : CXXMethodDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

CXXMethodDecl CXXMethodDecl::canonical_declaration(void) const {
  if (auto canon = CXXMethodDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (CXXMethodDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<CXXMethodDecl> CXXMethodDecl::definition(void) const {
  return CXXMethodDecl::from(this->Decl::definition());
}

gap::generator<CXXMethodDecl> CXXMethodDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<CXXMethodDecl> dr = CXXMethodDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<CXXMethodDecl> CXXMethodDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return CXXMethodDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kCXXMethodDeclDerivedKinds[] = {
    CXXMethodDecl::static_kind(),
    CXXConstructorDecl::static_kind(),
    CXXConversionDecl::static_kind(),
    CXXDestructorDecl::static_kind(),
};

std::optional<CXXMethodDecl> CXXMethodDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case CXXMethodDecl::static_kind():
    case CXXConstructorDecl::static_kind():
    case CXXConversionDecl::static_kind():
    case CXXDestructorDecl::static_kind():
      return reinterpret_cast<const CXXMethodDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXMethodDecl> CXXMethodDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kCXXMethodDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<CXXMethodDecl> e = CXXMethodDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXMethodDecl> CXXMethodDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kCXXMethodDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<CXXMethodDecl> e = CXXMethodDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXMethodDecl> CXXMethodDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kCXXMethodDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<CXXMethodDecl> e = CXXMethodDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXMethodDecl> CXXMethodDecl::from(const Reference &r) {
  return CXXMethodDecl::from(r.as_declaration());
}

std::optional<CXXMethodDecl> CXXMethodDecl::from(const TokenContext &t) {
  return CXXMethodDecl::from(t.as_declaration());
}

RefQualifierKind CXXMethodDecl::reference_qualifier(void) const {
  return static_cast<RefQualifierKind>(impl->reader.getVal164());
}

std::optional<Type> CXXMethodDecl::this_object_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal165();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<Type> CXXMethodDecl::this_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal166();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool CXXMethodDecl::has_inline_body(void) const {
  return impl->reader.getVal167();
}

bool CXXMethodDecl::is_const(void) const {
  return impl->reader.getVal168();
}

bool CXXMethodDecl::is_copy_assignment_operator(void) const {
  return impl->reader.getVal169();
}

bool CXXMethodDecl::is_instance(void) const {
  return impl->reader.getVal170();
}

bool CXXMethodDecl::is_lambda_static_invoker(void) const {
  return impl->reader.getVal171();
}

bool CXXMethodDecl::is_move_assignment_operator(void) const {
  return impl->reader.getVal172();
}

bool CXXMethodDecl::is_virtual(void) const {
  return impl->reader.getVal173();
}

bool CXXMethodDecl::is_volatile(void) const {
  return impl->reader.getVal174();
}

unsigned CXXMethodDecl::num_overridden_methods(void) const {
  return impl->reader.getVal175().size();
}

std::optional<CXXMethodDecl> CXXMethodDecl::nth_overridden_method(unsigned n) const {
  auto list = impl->reader.getVal175();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return CXXMethodDecl::from(Decl(std::move(e)));
}

gap::generator<CXXMethodDecl> CXXMethodDecl::overridden_methods(void) const & {
  auto list = impl->reader.getVal175();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d175 = ep->DeclFor(ep, v)) {
      if (auto e = CXXMethodDecl::from(Decl(std::move(d175)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
