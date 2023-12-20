// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ClassTemplateSpecializationDecl.h>
#include <multiplier/AST/CXXRecordDecl.h>
#include <multiplier/AST/ClassTemplateDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/RecordDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/TagDecl.h>
#include <multiplier/AST/TemplateArgument.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/TypeDecl.h>
#include <multiplier/AST/ClassTemplatePartialSpecializationDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kClassTemplateSpecializationDeclDerivedKinds[] = {
    ClassTemplateSpecializationDecl::static_kind(),
    ClassTemplatePartialSpecializationDecl::static_kind(),
};
}  // namespace

gap::generator<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ClassTemplateSpecializationDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ClassTemplateSpecializationDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ClassTemplateSpecializationDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<ClassTemplateSpecializationDecl, ir::Operation>> ClassTemplateSpecializationDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kClassTemplateSpecializationDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<ClassTemplateSpecializationDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ClassTemplateSpecializationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ClassTemplateSpecializationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ClassTemplateSpecializationDecl::contains(const Decl &decl) {
  for (auto &parent : ClassTemplateSpecializationDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ClassTemplateSpecializationDecl::contains(const Stmt &stmt) {
  for (auto &parent : ClassTemplateSpecializationDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ClassTemplateSpecializationDecl ClassTemplateSpecializationDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ClassTemplateSpecializationDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ClassTemplateSpecializationDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case ClassTemplateSpecializationDecl::static_kind():
    case ClassTemplatePartialSpecializationDecl::static_kind():
      return reinterpret_cast<const ClassTemplateSpecializationDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kClassTemplateSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ClassTemplateSpecializationDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kClassTemplateSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ClassTemplateSpecializationDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kClassTemplateSpecializationDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ClassTemplateSpecializationDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::from(const Reference &r) {
  return ClassTemplateSpecializationDecl::from(r.as_declaration());
}

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token ClassTemplateSpecializationDecl::extern_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal143());
}

Token ClassTemplateSpecializationDecl::point_of_instantiation(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal144());
}

TemplateSpecializationKind ClassTemplateSpecializationDecl::specialization_kind(void) const {
  return static_cast<TemplateSpecializationKind>(impl->reader.getVal93());
}

ClassTemplateDecl ClassTemplateSpecializationDecl::specialized_template(void) const {
  RawEntityId eid = impl->reader.getVal167();
  return ClassTemplateDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

unsigned ClassTemplateSpecializationDecl::num_template_arguments(void) const {
  return impl->reader.getVal352().size();
}

std::optional<TemplateArgument> ClassTemplateSpecializationDecl::nth_template_argument(unsigned n) const {
  auto list = impl->reader.getVal352();
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

gap::generator<TemplateArgument> ClassTemplateSpecializationDecl::template_arguments(void) const & {
  auto list = impl->reader.getVal352();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d352 = ep->TemplateArgumentFor(ep, v)) {
      co_yield TemplateArgument(std::move(d352));
    }
  }
  co_return;
}

unsigned ClassTemplateSpecializationDecl::num_template_instantiation_arguments(void) const {
  return impl->reader.getVal353().size();
}

std::optional<TemplateArgument> ClassTemplateSpecializationDecl::nth_template_instantiation_argument(unsigned n) const {
  auto list = impl->reader.getVal353();
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

gap::generator<TemplateArgument> ClassTemplateSpecializationDecl::template_instantiation_arguments(void) const & {
  auto list = impl->reader.getVal353();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d353 = ep->TemplateArgumentFor(ep, v)) {
      co_yield TemplateArgument(std::move(d353));
    }
  }
  co_return;
}

Token ClassTemplateSpecializationDecl::template_keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal169());
}

std::optional<Type> ClassTemplateSpecializationDecl::type_as_written(void) const {
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

bool ClassTemplateSpecializationDecl::is_class_scope_explicit_specialization(void) const {
  return impl->reader.getVal354();
}

bool ClassTemplateSpecializationDecl::is_explicit_instantiation_or_specialization(void) const {
  return impl->reader.getVal355();
}

bool ClassTemplateSpecializationDecl::is_explicit_specialization(void) const {
  return impl->reader.getVal356();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
