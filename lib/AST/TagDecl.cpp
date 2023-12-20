// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TagDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/TemplateParameterList.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/TypeDecl.h>
#include <multiplier/AST/TypedefNameDecl.h>
#include <multiplier/AST/CXXRecordDecl.h>
#include <multiplier/AST/ClassTemplatePartialSpecializationDecl.h>
#include <multiplier/AST/ClassTemplateSpecializationDecl.h>
#include <multiplier/AST/EnumDecl.h>
#include <multiplier/AST/RecordDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Fragment.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kTagDeclDerivedKinds[] = {
    EnumDecl::static_kind(),
    RecordDecl::static_kind(),
    CXXRecordDecl::static_kind(),
    ClassTemplateSpecializationDecl::static_kind(),
    ClassTemplatePartialSpecializationDecl::static_kind(),
};
}  // namespace

gap::generator<TagDecl> TagDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TagDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TagDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TagDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<TagDecl> TagDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<TagDecl, ir::Operation>> TagDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kTagDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<TagDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<TagDecl> TagDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TagDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TagDecl> TagDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<TagDecl> TagDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TagDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TagDecl> TagDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool TagDecl::contains(const Decl &decl) {
  for (auto &parent : TagDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool TagDecl::contains(const Stmt &stmt) {
  for (auto &parent : TagDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

TagDecl TagDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (TagDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<TagDecl> TagDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<TagDecl> TagDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<TagDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<TagDecl> TagDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<TagDecl> TagDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<TagDecl> TagDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case EnumDecl::static_kind():
    case RecordDecl::static_kind():
    case CXXRecordDecl::static_kind():
    case ClassTemplateSpecializationDecl::static_kind():
    case ClassTemplatePartialSpecializationDecl::static_kind():
      return reinterpret_cast<const TagDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TagDecl> TagDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kTagDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<TagDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TagDecl> TagDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kTagDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<TagDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TagDecl> TagDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kTagDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<TagDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<TagDecl> TagDecl::from(const Reference &r) {
  return TagDecl::from(r.as_declaration());
}

std::optional<TagDecl> TagDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<TagDecl> TagDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

TokenRange TagDecl::brace_range(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal57(), impl->reader.getVal58());
}

Token TagDecl::first_inner_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal66());
}

Token TagDecl::first_outer_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal67());
}

TagTypeKind TagDecl::tag_kind(void) const {
  return static_cast<TagTypeKind>(impl->reader.getVal80());
}

std::optional<TypedefNameDecl> TagDecl::typedef_name_for_anonymous_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal68();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return TypedefNameDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool TagDecl::has_name_for_linkage(void) const {
  return impl->reader.getVal74();
}

bool TagDecl::is_being_defined(void) const {
  return impl->reader.getVal75();
}

bool TagDecl::is_class(void) const {
  return impl->reader.getVal76();
}

bool TagDecl::is_complete_definition(void) const {
  return impl->reader.getVal77();
}

bool TagDecl::is_complete_definition_required(void) const {
  return impl->reader.getVal94();
}

bool TagDecl::is_dependent_type(void) const {
  return impl->reader.getVal95();
}

bool TagDecl::is_enum(void) const {
  return impl->reader.getVal96();
}

bool TagDecl::is_free_standing(void) const {
  return impl->reader.getVal97();
}

bool TagDecl::is_interface(void) const {
  return impl->reader.getVal98();
}

bool TagDecl::is_struct(void) const {
  return impl->reader.getVal99();
}

bool TagDecl::is_this_declaration_a_definition(void) const {
  return impl->reader.getVal100();
}

bool TagDecl::is_this_declaration_a_demoted_definition(void) const {
  return impl->reader.getVal101();
}

bool TagDecl::is_union(void) const {
  return impl->reader.getVal102();
}

bool TagDecl::may_have_out_of_date_definition(void) const {
  return impl->reader.getVal103();
}

unsigned TagDecl::num_template_parameter_lists(void) const {
  return impl->reader.getVal51().size();
}

std::optional<TemplateParameterList> TagDecl::nth_template_parameter_list(unsigned n) const {
  auto list = impl->reader.getVal51();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TemplateParameterListFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return TemplateParameterList(std::move(e));
}

gap::generator<TemplateParameterList> TagDecl::template_parameter_lists(void) const & {
  auto list = impl->reader.getVal51();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d51 = ep->TemplateParameterListFor(ep, v)) {
      co_yield TemplateParameterList(std::move(d51));
    }
  }
  co_return;
}

gap::generator<Decl> TagDecl::declarations_in_context(void) const & {
  EntityProviderPtr ep = impl->ep;
  auto list = impl->reader.getVal52();
  for (auto v : list) {
    if (auto eptr = ep->DeclFor(ep, v)) {
      co_yield std::move(eptr);
    }
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
