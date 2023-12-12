// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXMethodDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/DeclaratorDecl.h>
#include <multiplier/AST/FunctionDecl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/ValueDecl.h>
#include <multiplier/AST/CXXConstructorDecl.h>
#include <multiplier/AST/CXXConversionDecl.h>
#include <multiplier/AST/CXXDestructorDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kCXXMethodDeclDerivedKinds[] = {
    CXXMethodDecl::static_kind(),
    CXXConstructorDecl::static_kind(),
    CXXConversionDecl::static_kind(),
    CXXDestructorDecl::static_kind(),
};
}  // namespace

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

#ifndef MX_DISABLE_VAST
std::optional<CXXMethodDecl> CXXMethodDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<CXXMethodDecl, ir::Operation>> CXXMethodDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kCXXMethodDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<CXXMethodDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

#endif  // MX_DISABLE_VAST

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
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (CXXMethodDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<CXXMethodDecl> CXXMethodDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<CXXMethodDecl> CXXMethodDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<CXXMethodDecl> dr = from_base(r)) {
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
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<CXXMethodDecl> CXXMethodDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<CXXMethodDecl> CXXMethodDecl::from_base(const Decl &parent) {
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
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kCXXMethodDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<CXXMethodDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXMethodDecl> CXXMethodDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kCXXMethodDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<CXXMethodDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXMethodDecl> CXXMethodDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kCXXMethodDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<CXXMethodDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXMethodDecl> CXXMethodDecl::from(const Reference &r) {
  return CXXMethodDecl::from(r.as_declaration());
}

std::optional<CXXMethodDecl> CXXMethodDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<CXXMethodDecl> CXXMethodDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

RefQualifierKind CXXMethodDecl::reference_qualifier(void) const {
  return static_cast<RefQualifierKind>(impl->reader.getVal168());
}

std::optional<Type> CXXMethodDecl::this_object_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal169();
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
    RawEntityId eid = impl->reader.getVal170();
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
  return impl->reader.getVal171();
}

bool CXXMethodDecl::is_const(void) const {
  return impl->reader.getVal172();
}

bool CXXMethodDecl::is_copy_assignment_operator(void) const {
  return impl->reader.getVal173();
}

bool CXXMethodDecl::is_instance(void) const {
  return impl->reader.getVal174();
}

bool CXXMethodDecl::is_lambda_static_invoker(void) const {
  return impl->reader.getVal175();
}

bool CXXMethodDecl::is_move_assignment_operator(void) const {
  return impl->reader.getVal176();
}

bool CXXMethodDecl::is_virtual(void) const {
  return impl->reader.getVal177();
}

bool CXXMethodDecl::is_volatile(void) const {
  return impl->reader.getVal178();
}

unsigned CXXMethodDecl::num_overridden_methods(void) const {
  return impl->reader.getVal179().size();
}

std::optional<CXXMethodDecl> CXXMethodDecl::nth_overridden_method(unsigned n) const {
  auto list = impl->reader.getVal179();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return CXXMethodDecl::from_base(std::move(e));
}

gap::generator<CXXMethodDecl> CXXMethodDecl::overridden_methods(void) const & {
  auto list = impl->reader.getVal179();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d179 = ep->DeclFor(ep, v)) {
      if (auto e = CXXMethodDecl::from_base(std::move(d179))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
