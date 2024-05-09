// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/VarTemplateSpecializationDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/DeclaratorDecl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/TemplateArgument.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/ValueDecl.h>
#include <multiplier/AST/VarDecl.h>
#include <multiplier/AST/VarTemplateDecl.h>
#include <multiplier/AST/VarTemplatePartialSpecializationDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kVarTemplateSpecializationDeclDerivedKinds[] = {
    VarTemplateSpecializationDecl::static_kind(),
    VarTemplatePartialSpecializationDecl::static_kind(),
};
}  // namespace

gap::generator<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = VarTemplateSpecializationDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool VarTemplateSpecializationDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : VarTemplateSpecializationDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<VarTemplateSpecializationDecl, ir::Operation>> VarTemplateSpecializationDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kVarTemplateSpecializationDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<VarTemplateSpecializationDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = VarTemplateSpecializationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = VarTemplateSpecializationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool VarTemplateSpecializationDecl::contains(const Decl &decl) {
  for (auto &parent : VarTemplateSpecializationDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool VarTemplateSpecializationDecl::contains(const Stmt &stmt) {
  for (auto &parent : VarTemplateSpecializationDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

VarTemplateSpecializationDecl VarTemplateSpecializationDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (VarTemplateSpecializationDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<VarTemplateSpecializationDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case VarTemplateSpecializationDecl::static_kind():
    case VarTemplatePartialSpecializationDecl::static_kind():
      return reinterpret_cast<const VarTemplateSpecializationDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kVarTemplateSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<VarTemplateSpecializationDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kVarTemplateSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<VarTemplateSpecializationDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kVarTemplateSpecializationDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<VarTemplateSpecializationDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::from(const Reference &r) {
  return VarTemplateSpecializationDecl::from(r.as_declaration());
}

std::optional<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token VarTemplateSpecializationDecl::extern_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal114());
}

TemplateSpecializationKind VarTemplateSpecializationDecl::specialization_kind(void) const {
  return static_cast<TemplateSpecializationKind>(impl->reader.getVal118());
}

VarTemplateDecl VarTemplateSpecializationDecl::specialized_template(void) const {
  RawEntityId eid = impl->reader.getVal115();
  return VarTemplateDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

unsigned VarTemplateSpecializationDecl::num_template_arguments(void) const {
  return impl->reader.getVal41().size();
}

std::optional<TemplateArgument> VarTemplateSpecializationDecl::nth_template_argument(unsigned n) const {
  auto list = impl->reader.getVal41();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TemplateArgumentFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return TemplateArgument(std::move(e));
}

gap::generator<TemplateArgument> VarTemplateSpecializationDecl::template_arguments(void) const & {
  auto list = impl->reader.getVal41();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d41 = ep->TemplateArgumentFor(ep, v)) {
      co_yield TemplateArgument(std::move(d41));
    }
  }
  co_return;
}

unsigned VarTemplateSpecializationDecl::num_template_instantiation_arguments(void) const {
  return impl->reader.getVal51().size();
}

std::optional<TemplateArgument> VarTemplateSpecializationDecl::nth_template_instantiation_argument(unsigned n) const {
  auto list = impl->reader.getVal51();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TemplateArgumentFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return TemplateArgument(std::move(e));
}

gap::generator<TemplateArgument> VarTemplateSpecializationDecl::template_instantiation_arguments(void) const & {
  auto list = impl->reader.getVal51();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d51 = ep->TemplateArgumentFor(ep, v)) {
      co_yield TemplateArgument(std::move(d51));
    }
  }
  co_return;
}

Token VarTemplateSpecializationDecl::template_keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal116());
}

std::optional<Type> VarTemplateSpecializationDecl::type_as_written(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal117();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool VarTemplateSpecializationDecl::is_class_scope_explicit_specialization(void) const {
  return impl->reader.getVal121();
}

bool VarTemplateSpecializationDecl::is_explicit_instantiation_or_specialization(void) const {
  return impl->reader.getVal122();
}

bool VarTemplateSpecializationDecl::is_explicit_specialization(void) const {
  return impl->reader.getVal123();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
