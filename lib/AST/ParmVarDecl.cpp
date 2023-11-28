// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ParmVarDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/DeclaratorDecl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/ValueDecl.h>
#include <multiplier/AST/VarDecl.h>

#include "../EntityProvider.h"
#include "../Fragment.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ParmVarDecl> ParmVarDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ParmVarDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ParmVarDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ParmVarDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ParmVarDecl> ParmVarDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ParmVarDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ParmVarDecl> ParmVarDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ParmVarDecl> ParmVarDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ParmVarDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ParmVarDecl> ParmVarDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ParmVarDecl::contains(const Decl &decl) {
  for (auto &parent : ParmVarDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ParmVarDecl::contains(const Stmt &stmt) {
  for (auto &parent : ParmVarDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ParmVarDecl ParmVarDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ParmVarDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ParmVarDecl> ParmVarDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<ParmVarDecl> ParmVarDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ParmVarDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ParmVarDecl> ParmVarDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<ParmVarDecl> ParmVarDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const DeclKind kParmVarDeclDerivedKinds[] = {
    ParmVarDecl::static_kind(),
};

}  // namespace

std::optional<ParmVarDecl> ParmVarDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case ParmVarDecl::static_kind():
      return reinterpret_cast<const ParmVarDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ParmVarDecl> ParmVarDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kParmVarDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ParmVarDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ParmVarDecl> ParmVarDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kParmVarDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ParmVarDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ParmVarDecl> ParmVarDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kParmVarDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ParmVarDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ParmVarDecl> ParmVarDecl::from(const Reference &r) {
  return ParmVarDecl::from(r.as_declaration());
}

std::optional<ParmVarDecl> ParmVarDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<ParmVarDecl> ParmVarDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<Expr> ParmVarDecl::default_argument(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal128();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

TokenRange ParmVarDecl::default_argument_range(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal129(), impl->reader.getVal130());
}

DeclObjCDeclQualifier ParmVarDecl::obj_c_decl_qualifier(void) const {
  return static_cast<DeclObjCDeclQualifier>(impl->reader.getVal131());
}

Type ParmVarDecl::original_type(void) const {
  RawEntityId eid = impl->reader.getVal132();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<Expr> ParmVarDecl::uninstantiated_default_argument(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal133();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool ParmVarDecl::has_default_argument(void) const {
  return impl->reader.getVal134();
}

bool ParmVarDecl::has_inherited_default_argument(void) const {
  return impl->reader.getVal135();
}

bool ParmVarDecl::has_uninstantiated_default_argument(void) const {
  return impl->reader.getVal136();
}

bool ParmVarDecl::has_unparsed_default_argument(void) const {
  return impl->reader.getVal137();
}

bool ParmVarDecl::is_destroyed_in_callee(void) const {
  return impl->reader.getVal138();
}

bool ParmVarDecl::is_knr_promoted(void) const {
  return impl->reader.getVal139();
}

bool ParmVarDecl::is_obj_c_method_parameter(void) const {
  return impl->reader.getVal140();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
