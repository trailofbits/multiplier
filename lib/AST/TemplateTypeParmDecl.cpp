// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TemplateTypeParmDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/TypeDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kTemplateTypeParmDeclDerivedKinds[] = {
    TemplateTypeParmDecl::static_kind(),
};
}  // namespace

gap::generator<TemplateTypeParmDecl> TemplateTypeParmDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TemplateTypeParmDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TemplateTypeParmDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TemplateTypeParmDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<TemplateTypeParmDecl> TemplateTypeParmDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<TemplateTypeParmDecl, ir::Operation>> TemplateTypeParmDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kTemplateTypeParmDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<TemplateTypeParmDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<TemplateTypeParmDecl> TemplateTypeParmDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TemplateTypeParmDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TemplateTypeParmDecl> TemplateTypeParmDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<TemplateTypeParmDecl> TemplateTypeParmDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TemplateTypeParmDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TemplateTypeParmDecl> TemplateTypeParmDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool TemplateTypeParmDecl::contains(const Decl &decl) {
  for (auto &parent : TemplateTypeParmDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool TemplateTypeParmDecl::contains(const Stmt &stmt) {
  for (auto &parent : TemplateTypeParmDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

TemplateTypeParmDecl TemplateTypeParmDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (TemplateTypeParmDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<TemplateTypeParmDecl> TemplateTypeParmDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<TemplateTypeParmDecl> TemplateTypeParmDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<TemplateTypeParmDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<TemplateTypeParmDecl> TemplateTypeParmDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<TemplateTypeParmDecl> TemplateTypeParmDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<TemplateTypeParmDecl> TemplateTypeParmDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case TemplateTypeParmDecl::static_kind():
      return reinterpret_cast<const TemplateTypeParmDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TemplateTypeParmDecl> TemplateTypeParmDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kTemplateTypeParmDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<TemplateTypeParmDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TemplateTypeParmDecl> TemplateTypeParmDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kTemplateTypeParmDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<TemplateTypeParmDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TemplateTypeParmDecl> TemplateTypeParmDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kTemplateTypeParmDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<TemplateTypeParmDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<TemplateTypeParmDecl> TemplateTypeParmDecl::from(const Reference &r) {
  return TemplateTypeParmDecl::from(r.as_declaration());
}

std::optional<TemplateTypeParmDecl> TemplateTypeParmDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<TemplateTypeParmDecl> TemplateTypeParmDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

bool TemplateTypeParmDecl::default_argument_was_inherited(void) const {
  return impl->reader.getVal74();
}

std::optional<Type> TemplateTypeParmDecl::default_argument(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal56();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<Type> TemplateTypeParmDecl::default_argument_info(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal57();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token TemplateTypeParmDecl::default_argument_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal65());
}

bool TemplateTypeParmDecl::has_default_argument(void) const {
  return impl->reader.getVal75();
}

bool TemplateTypeParmDecl::has_type_constraint(void) const {
  return impl->reader.getVal76();
}

bool TemplateTypeParmDecl::is_expanded_parameter_pack(void) const {
  return impl->reader.getVal77();
}

bool TemplateTypeParmDecl::is_pack_expansion(void) const {
  return impl->reader.getVal93();
}

bool TemplateTypeParmDecl::was_declared_with_typename(void) const {
  return impl->reader.getVal94();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
