// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/FieldDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/DeclaratorDecl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueDecl.h>
#include <multiplier/AST/VariableArrayType.h>
#include <multiplier/AST/ObjCAtDefsFieldDecl.h>
#include <multiplier/AST/ObjCIvarDecl.h>

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
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (FieldDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<FieldDecl> FieldDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<FieldDecl> FieldDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<FieldDecl> dr = from_base(r)) {
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
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<FieldDecl> FieldDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const DeclKind kFieldDeclDerivedKinds[] = {
    FieldDecl::static_kind(),
    ObjCAtDefsFieldDecl::static_kind(),
    ObjCIvarDecl::static_kind(),
};

}  // namespace

std::optional<FieldDecl> FieldDecl::from_base(const Decl &parent) {
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
      if (std::optional<FieldDecl> e = from_base(std::move(eptr))) {
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
      if (std::optional<FieldDecl> e = from_base(std::move(eptr))) {
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
        if (std::optional<FieldDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<FieldDecl> FieldDecl::from(const Reference &r) {
  return FieldDecl::from(r.as_declaration());
}

std::optional<FieldDecl> FieldDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<FieldDecl> FieldDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<Expr> FieldDecl::bit_width(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal79();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<VariableArrayType> FieldDecl::captured_vla_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal81();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return VariableArrayType::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

InClassInitStyle FieldDecl::in_class_initializer_style(void) const {
  return static_cast<InClassInitStyle>(impl->reader.getVal80());
}

std::optional<Expr> FieldDecl::in_class_initializer(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal82();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool FieldDecl::has_captured_vla_type(void) const {
  return impl->reader.getVal76();
}

bool FieldDecl::has_in_class_initializer(void) const {
  return impl->reader.getVal77();
}

bool FieldDecl::has_non_null_in_class_initializer(void) const {
  return impl->reader.getVal94();
}

bool FieldDecl::is_anonymous_struct_or_union(void) const {
  return impl->reader.getVal95();
}

bool FieldDecl::is_bit_field(void) const {
  return impl->reader.getVal96();
}

bool FieldDecl::is_mutable(void) const {
  return impl->reader.getVal97();
}

bool FieldDecl::is_potentially_overlapping(void) const {
  return impl->reader.getVal98();
}

bool FieldDecl::is_unnamed_bitfield(void) const {
  return impl->reader.getVal99();
}

bool FieldDecl::is_zero_length_bit_field(void) const {
  return impl->reader.getVal100();
}

bool FieldDecl::is_zero_size(void) const {
  return impl->reader.getVal101();
}

std::optional<uint64_t> FieldDecl::offset_in_bits(void) const {
  if (!impl->reader.getVal102()) {
    return std::nullopt;
  } else {
    return static_cast<uint64_t>(impl->reader.getVal83());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
