// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/FieldDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DeclaratorDecl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/ObjCAtDefsFieldDecl.h>
#include <multiplier/Entities/ObjCIvarDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueDecl.h>
#include <multiplier/Entities/VariableArrayType.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<FieldDecl> FieldDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = FieldDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool FieldDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : FieldDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<FieldDecl> FieldDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = FieldDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<FieldDecl> FieldDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<FieldDecl> FieldDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = FieldDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<FieldDecl> FieldDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool FieldDecl::contains(const Decl &decl) {
  for (auto &parent : FieldDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool FieldDecl::contains(const Stmt &stmt) {
  for (auto &parent : FieldDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

FieldDecl FieldDecl::canonical_declaration(void) const {
  if (auto canon = FieldDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (FieldDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<FieldDecl> FieldDecl::definition(void) const {
  return FieldDecl::from(this->Decl::definition());
}

gap::generator<FieldDecl> FieldDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<FieldDecl> dr = FieldDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<FieldDecl> FieldDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return FieldDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kFieldDeclDerivedKinds[] = {
    FieldDecl::static_kind(),
    ObjCAtDefsFieldDecl::static_kind(),
    ObjCIvarDecl::static_kind(),
};

std::optional<FieldDecl> FieldDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case FieldDecl::static_kind():
    case ObjCAtDefsFieldDecl::static_kind():
    case ObjCIvarDecl::static_kind():
      return reinterpret_cast<const FieldDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<FieldDecl> FieldDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kFieldDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<FieldDecl> e = FieldDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FieldDecl> FieldDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kFieldDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<FieldDecl> e = FieldDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FieldDecl> FieldDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kFieldDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<FieldDecl> e = FieldDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<FieldDecl> FieldDecl::from(const Reference &r) {
  return FieldDecl::from(r.as_declaration());
}

std::optional<FieldDecl> FieldDecl::from(const TokenContext &t) {
  return FieldDecl::from(t.as_declaration());
}

std::optional<Expr> FieldDecl::bit_width(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal77();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

std::optional<VariableArrayType> FieldDecl::captured_vla_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal79();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return VariableArrayType::from(Type(std::move(eptr)));
    }
  }
  return std::nullopt;
}

InClassInitStyle FieldDecl::in_class_initializer_style(void) const {
  return static_cast<InClassInitStyle>(impl->reader.getVal78());
}

std::optional<Expr> FieldDecl::in_class_initializer(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal80();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

bool FieldDecl::has_captured_vla_type(void) const {
  return impl->reader.getVal74();
}

bool FieldDecl::has_in_class_initializer(void) const {
  return impl->reader.getVal75();
}

bool FieldDecl::is_anonymous_struct_or_union(void) const {
  return impl->reader.getVal92();
}

bool FieldDecl::is_bit_field(void) const {
  return impl->reader.getVal93();
}

bool FieldDecl::is_mutable(void) const {
  return impl->reader.getVal94();
}

bool FieldDecl::is_unnamed_bitfield(void) const {
  return impl->reader.getVal95();
}

bool FieldDecl::is_zero_length_bit_field(void) const {
  return impl->reader.getVal96();
}

bool FieldDecl::is_zero_size(void) const {
  return impl->reader.getVal97();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
