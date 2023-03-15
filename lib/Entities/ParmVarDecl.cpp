// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ParmVarDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DeclaratorDecl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/ValueDecl.h>
#include <multiplier/Entities/VarDecl.h>

#include "../API.h"
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
    if (parent == *this) { return true; }
  }
  return false;
}

bool ParmVarDecl::contains(const Stmt &stmt) {
  for (auto &parent : ParmVarDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<ParmVarDecl> ParmVarDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ParmVarDecl> dr = ParmVarDecl::from(r)) {
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
    return ParmVarDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kParmVarDeclDerivedKinds[] = {
    ParmVarDecl::static_kind(),
};

std::optional<ParmVarDecl> ParmVarDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ParmVarDecl::static_kind():
      return reinterpret_cast<const ParmVarDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ParmVarDecl> ParmVarDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kParmVarDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ParmVarDecl> e = ParmVarDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ParmVarDecl> ParmVarDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kParmVarDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ParmVarDecl> e = ParmVarDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ParmVarDecl> ParmVarDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kParmVarDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ParmVarDecl> e = ParmVarDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ParmVarDecl> ParmVarDecl::from(const Reference &r) {
  return ParmVarDecl::from(r.as_declaration());
}

std::optional<ParmVarDecl> ParmVarDecl::from(const TokenContext &t) {
  return ParmVarDecl::from(t.as_declaration());
}

std::optional<Expr> ParmVarDecl::default_argument(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal123();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

TokenRange ParmVarDecl::default_argument_range(void) const {
  auto &ep = impl->ep;
  auto fragment = ep->FragmentFor(ep, impl->fragment_id);
  return fragment->TokenRangeFor(fragment, impl->reader.getVal124(), impl->reader.getVal125());
}

DeclObjCDeclQualifier ParmVarDecl::obj_c_decl_qualifier(void) const {
  return static_cast<DeclObjCDeclQualifier>(impl->reader.getVal126());
}

Type ParmVarDecl::original_type(void) const {
  RawEntityId eid = impl->reader.getVal127();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<Expr> ParmVarDecl::uninstantiated_default_argument(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal128();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

bool ParmVarDecl::has_default_argument(void) const {
  return impl->reader.getVal129();
}

bool ParmVarDecl::has_inherited_default_argument(void) const {
  return impl->reader.getVal130();
}

bool ParmVarDecl::has_uninstantiated_default_argument(void) const {
  return impl->reader.getVal131();
}

bool ParmVarDecl::has_unparsed_default_argument(void) const {
  return impl->reader.getVal132();
}

bool ParmVarDecl::is_destroyed_in_callee(void) const {
  return impl->reader.getVal133();
}

bool ParmVarDecl::is_knr_promoted(void) const {
  return impl->reader.getVal134();
}

bool ParmVarDecl::is_obj_c_method_parameter(void) const {
  return impl->reader.getVal135();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
