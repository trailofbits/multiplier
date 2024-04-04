// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXRecordDecl.h>
#include <multiplier/AST/CXXBaseSpecifier.h>
#include <multiplier/AST/CXXConstructorDecl.h>
#include <multiplier/AST/CXXDestructorDecl.h>
#include <multiplier/AST/CXXMethodDecl.h>
#include <multiplier/AST/ClassTemplateDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/FriendDecl.h>
#include <multiplier/AST/FunctionDecl.h>
#include <multiplier/AST/FunctionTemplateDecl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/RecordDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/TagDecl.h>
#include <multiplier/AST/TemplateParameterList.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/TypeDecl.h>
#include <multiplier/AST/ClassTemplatePartialSpecializationDecl.h>
#include <multiplier/AST/ClassTemplateSpecializationDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kCXXRecordDeclDerivedKinds[] = {
    CXXRecordDecl::static_kind(),
    ClassTemplateSpecializationDecl::static_kind(),
    ClassTemplatePartialSpecializationDecl::static_kind(),
};
}  // namespace

gap::generator<CXXRecordDecl> CXXRecordDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXRecordDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXRecordDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXRecordDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<CXXRecordDecl> CXXRecordDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<CXXRecordDecl, ir::Operation>> CXXRecordDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kCXXRecordDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<CXXRecordDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<CXXRecordDecl> CXXRecordDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = CXXRecordDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXRecordDecl> CXXRecordDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXRecordDecl> CXXRecordDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = CXXRecordDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXRecordDecl> CXXRecordDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXRecordDecl::contains(const Decl &decl) {
  for (auto &parent : CXXRecordDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXRecordDecl::contains(const Stmt &stmt) {
  for (auto &parent : CXXRecordDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

CXXRecordDecl CXXRecordDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (CXXRecordDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<CXXRecordDecl> CXXRecordDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<CXXRecordDecl> CXXRecordDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<CXXRecordDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<CXXRecordDecl> CXXRecordDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<CXXRecordDecl> CXXRecordDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<CXXRecordDecl> CXXRecordDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case CXXRecordDecl::static_kind():
    case ClassTemplateSpecializationDecl::static_kind():
    case ClassTemplatePartialSpecializationDecl::static_kind():
      return reinterpret_cast<const CXXRecordDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXRecordDecl> CXXRecordDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kCXXRecordDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<CXXRecordDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXRecordDecl> CXXRecordDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kCXXRecordDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<CXXRecordDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXRecordDecl> CXXRecordDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kCXXRecordDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<CXXRecordDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXRecordDecl> CXXRecordDecl::from(const Reference &r) {
  return CXXRecordDecl::from(r.as_declaration());
}

std::optional<CXXRecordDecl> CXXRecordDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<CXXRecordDecl> CXXRecordDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::allow_const_default_initializer(void) const {
  if (!impl->reader.getVal133()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal132());
  }
  return std::nullopt;
}

std::optional<std::vector<CXXBaseSpecifier>> CXXRecordDecl::bases(void) const {
  if (!impl->reader.getVal134()) {
    return std::nullopt;
  }
  auto list = impl->reader.getVal173();
  std::vector<CXXBaseSpecifier> vec;
  vec.reserve(list.size());
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d173 = ep->CXXBaseSpecifierFor(ep, v)) {
      vec.emplace_back(std::move(d173));
    }
  }
  return vec;
}

std::optional<MSInheritanceModel> CXXRecordDecl::inheritance_model(void) const {
  if (!impl->reader.getVal135()) {
    return std::nullopt;
  } else {
    return static_cast<MSInheritanceModel>(impl->reader.getVal86());
  }
  return std::nullopt;
}

unsigned CXXRecordDecl::num_constructors(void) const {
  return impl->reader.getVal178().size();
}

std::optional<CXXConstructorDecl> CXXRecordDecl::nth_constructor(unsigned n) const {
  auto list = impl->reader.getVal178();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return CXXConstructorDecl::from_base(std::move(e));
}

gap::generator<CXXConstructorDecl> CXXRecordDecl::constructors(void) const & {
  auto list = impl->reader.getVal178();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d178 = ep->DeclFor(ep, v)) {
      if (auto e = CXXConstructorDecl::from_base(std::move(d178))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

std::optional<std::vector<FriendDecl>> CXXRecordDecl::friends(void) const {
  if (!impl->reader.getVal136()) {
    return std::nullopt;
  }
  auto list = impl->reader.getVal182();
  std::vector<FriendDecl> vec;
  vec.reserve(list.size());
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d182 = ep->DeclFor(ep, v)) {
      if (auto e = FriendDecl::from_base(std::move(d182))) {
        vec.emplace_back(std::move(*e));
      }
    }
  }
  return vec;
}

std::optional<FunctionTemplateDecl> CXXRecordDecl::dependent_lambda_call_operator(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal82();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FunctionTemplateDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<ClassTemplateDecl> CXXRecordDecl::described_class_template(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal83();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return ClassTemplateDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<CXXDestructorDecl> CXXRecordDecl::destructor(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal85();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return CXXDestructorDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<TemplateParameterList> CXXRecordDecl::generic_lambda_template_parameter_list(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal90();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TemplateParameterListFor(impl->ep, eid)) {
      return TemplateParameterList(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<CXXRecordDecl> CXXRecordDecl::instantiated_from_member_class(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal125();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return CXXRecordDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<CXXMethodDecl> CXXRecordDecl::lambda_call_operator(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal126();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return CXXMethodDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<LambdaCaptureDefault> CXXRecordDecl::lambda_capture_default(void) const {
  if (!impl->reader.getVal137()) {
    return std::nullopt;
  } else {
    return static_cast<LambdaCaptureDefault>(impl->reader.getVal87());
  }
  return std::nullopt;
}

std::optional<Decl> CXXRecordDecl::lambda_context_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal127();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return Decl(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<std::vector<NamedDecl>> CXXRecordDecl::lambda_explicit_template_parameters(void) const {
  if (!impl->reader.getVal140()) {
    return std::nullopt;
  }
  auto list = impl->reader.getVal183();
  std::vector<NamedDecl> vec;
  vec.reserve(list.size());
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d183 = ep->DeclFor(ep, v)) {
      if (auto e = NamedDecl::from_base(std::move(d183))) {
        vec.emplace_back(std::move(*e));
      }
    }
  }
  return vec;
}

std::optional<uint32_t> CXXRecordDecl::lambda_mangling_number(void) const {
  if (!impl->reader.getVal141()) {
    return std::nullopt;
  } else {
    return static_cast<uint32_t>(impl->reader.getVal184());
  }
  return std::nullopt;
}

std::optional<CXXMethodDecl> CXXRecordDecl::lambda_static_invoker(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal129();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return CXXMethodDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<MSInheritanceModel> CXXRecordDecl::ms_inheritance_model(void) const {
  if (!impl->reader.getVal142()) {
    return std::nullopt;
  } else {
    return static_cast<MSInheritanceModel>(impl->reader.getVal88());
  }
  return std::nullopt;
}

MSVtorDispMode CXXRecordDecl::ms_vtor_disp_mode(void) const {
  return static_cast<MSVtorDispMode>(impl->reader.getVal89());
}

std::optional<CXXRecordDecl> CXXRecordDecl::template_instantiation_pattern(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal130();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return CXXRecordDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

TemplateSpecializationKind CXXRecordDecl::template_specialization_kind(void) const {
  return static_cast<TemplateSpecializationKind>(impl->reader.getVal91());
}

std::optional<bool> CXXRecordDecl::has_any_dependent_bases(void) const {
  if (!impl->reader.getVal144()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal143());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_constexpr_default_constructor(void) const {
  if (!impl->reader.getVal146()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal145());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_constexpr_destructor(void) const {
  if (!impl->reader.getVal148()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal147());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_constexpr_non_copy_move_constructor(void) const {
  if (!impl->reader.getVal150()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal149());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_copy_assignment_with_const_parameter(void) const {
  if (!impl->reader.getVal152()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal151());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_copy_constructor_with_const_parameter(void) const {
  if (!impl->reader.getVal154()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal153());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_default_constructor(void) const {
  if (!impl->reader.getVal156()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal155());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_definition(void) const {
  if (!impl->reader.getVal158()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal157());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_direct_fields(void) const {
  if (!impl->reader.getVal160()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal159());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_friends(void) const {
  if (!impl->reader.getVal166()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal165());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_in_class_initializer(void) const {
  if (!impl->reader.getVal168()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal167());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_inherited_assignment(void) const {
  if (!impl->reader.getVal170()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal169());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_inherited_constructor(void) const {
  if (!impl->reader.getVal172()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal171());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_initializer_method(void) const {
  if (!impl->reader.getVal177()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal176());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_irrelevant_destructor(void) const {
  if (!impl->reader.getVal180()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal179());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_known_lambda_internal_linkage(void) const {
  if (!impl->reader.getVal185()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal181());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_move_assignment(void) const {
  if (!impl->reader.getVal187()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal186());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_move_constructor(void) const {
  if (!impl->reader.getVal189()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal188());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_mutable_fields(void) const {
  if (!impl->reader.getVal191()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal190());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_non_literal_type_fields_or_bases(void) const {
  if (!impl->reader.getVal193()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal192());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_non_trivial_copy_assignment(void) const {
  if (!impl->reader.getVal195()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal194());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_non_trivial_copy_constructor(void) const {
  if (!impl->reader.getVal197()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal196());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_non_trivial_copy_constructor_for_call(void) const {
  if (!impl->reader.getVal199()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal198());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_non_trivial_default_constructor(void) const {
  if (!impl->reader.getVal201()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal200());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_non_trivial_destructor(void) const {
  if (!impl->reader.getVal203()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal202());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_non_trivial_destructor_for_call(void) const {
  if (!impl->reader.getVal205()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal204());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_non_trivial_move_assignment(void) const {
  if (!impl->reader.getVal207()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal206());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_non_trivial_move_constructor(void) const {
  if (!impl->reader.getVal209()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal208());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_non_trivial_move_constructor_for_call(void) const {
  if (!impl->reader.getVal211()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal210());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_private_fields(void) const {
  if (!impl->reader.getVal213()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal212());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_protected_fields(void) const {
  if (!impl->reader.getVal215()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal214());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_simple_copy_assignment(void) const {
  if (!impl->reader.getVal217()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal216());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_simple_copy_constructor(void) const {
  if (!impl->reader.getVal219()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal218());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_simple_destructor(void) const {
  if (!impl->reader.getVal221()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal220());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_simple_move_assignment(void) const {
  if (!impl->reader.getVal223()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal222());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_simple_move_constructor(void) const {
  if (!impl->reader.getVal225()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal224());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_trivial_copy_assignment(void) const {
  if (!impl->reader.getVal227()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal226());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_trivial_copy_constructor(void) const {
  if (!impl->reader.getVal229()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal228());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_trivial_copy_constructor_for_call(void) const {
  if (!impl->reader.getVal231()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal230());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_trivial_default_constructor(void) const {
  if (!impl->reader.getVal233()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal232());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_trivial_destructor(void) const {
  if (!impl->reader.getVal235()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal234());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_trivial_destructor_for_call(void) const {
  if (!impl->reader.getVal237()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal236());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_trivial_move_assignment(void) const {
  if (!impl->reader.getVal239()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal238());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_trivial_move_constructor(void) const {
  if (!impl->reader.getVal241()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal240());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_trivial_move_constructor_for_call(void) const {
  if (!impl->reader.getVal243()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal242());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_uninitialized_reference_member(void) const {
  if (!impl->reader.getVal245()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal244());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_user_declared_constructor(void) const {
  if (!impl->reader.getVal247()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal246());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_user_declared_copy_assignment(void) const {
  if (!impl->reader.getVal249()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal248());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_user_declared_copy_constructor(void) const {
  if (!impl->reader.getVal251()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal250());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_user_declared_destructor(void) const {
  if (!impl->reader.getVal253()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal252());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_user_declared_move_assignment(void) const {
  if (!impl->reader.getVal255()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal254());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_user_declared_move_constructor(void) const {
  if (!impl->reader.getVal257()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal256());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_user_declared_move_operation(void) const {
  if (!impl->reader.getVal259()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal258());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_user_provided_default_constructor(void) const {
  if (!impl->reader.getVal261()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal260());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_variant_members(void) const {
  if (!impl->reader.getVal263()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal262());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::implicit_copy_assignment_has_const_parameter(void) const {
  if (!impl->reader.getVal265()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal264());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::implicit_copy_constructor_has_const_parameter(void) const {
  if (!impl->reader.getVal267()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal266());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::is_abstract(void) const {
  if (!impl->reader.getVal269()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal268());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::is_aggregate(void) const {
  if (!impl->reader.getVal271()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal270());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::is_any_destructor_no_return(void) const {
  if (!impl->reader.getVal273()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal272());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::is_c_like(void) const {
  if (!impl->reader.getVal275()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal274());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::is_cxx11_standard_layout(void) const {
  if (!impl->reader.getVal277()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal276());
  }
  return std::nullopt;
}

bool CXXRecordDecl::is_dependent_lambda(void) const {
  return impl->reader.getVal278();
}

std::optional<bool> CXXRecordDecl::is_dynamic_class(void) const {
  if (!impl->reader.getVal280()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal279());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::is_effectively_final(void) const {
  if (!impl->reader.getVal282()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal281());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::is_empty(void) const {
  if (!impl->reader.getVal284()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal283());
  }
  return std::nullopt;
}

bool CXXRecordDecl::is_generic_lambda(void) const {
  return impl->reader.getVal285();
}

std::optional<bool> CXXRecordDecl::is_interface_like(void) const {
  if (!impl->reader.getVal287()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal286());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::is_literal(void) const {
  if (!impl->reader.getVal289()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal288());
  }
  return std::nullopt;
}

std::optional<FunctionDecl> CXXRecordDecl::is_local_class(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal138();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FunctionDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool CXXRecordDecl::is_never_dependent_lambda(void) const {
  return impl->reader.getVal290();
}

std::optional<bool> CXXRecordDecl::is_pod(void) const {
  if (!impl->reader.getVal292()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal291());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::is_polymorphic(void) const {
  if (!impl->reader.getVal294()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal293());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::is_standard_layout(void) const {
  if (!impl->reader.getVal296()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal295());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::is_structural(void) const {
  if (!impl->reader.getVal298()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal297());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::is_trivial(void) const {
  if (!impl->reader.getVal300()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal299());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::is_trivially_copyable(void) const {
  if (!impl->reader.getVal302()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal301());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::lambda_is_default_constructible_and_assignable(void) const {
  if (!impl->reader.getVal304()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal303());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::may_be_abstract(void) const {
  if (!impl->reader.getVal306()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal305());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::may_be_dynamic_class(void) const {
  if (!impl->reader.getVal308()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal307());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::may_be_non_dynamic_class(void) const {
  if (!impl->reader.getVal310()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal309());
  }
  return std::nullopt;
}

std::optional<std::vector<CXXMethodDecl>> CXXRecordDecl::methods(void) const {
  if (!impl->reader.getVal312()) {
    return std::nullopt;
  }
  auto list = impl->reader.getVal311();
  std::vector<CXXMethodDecl> vec;
  vec.reserve(list.size());
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d311 = ep->DeclFor(ep, v)) {
      if (auto e = CXXMethodDecl::from_base(std::move(d311))) {
        vec.emplace_back(std::move(*e));
      }
    }
  }
  return vec;
}

std::optional<bool> CXXRecordDecl::needs_implicit_copy_assignment(void) const {
  if (!impl->reader.getVal314()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal313());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::needs_implicit_copy_constructor(void) const {
  if (!impl->reader.getVal316()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal315());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::needs_implicit_default_constructor(void) const {
  if (!impl->reader.getVal318()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal317());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::needs_implicit_destructor(void) const {
  if (!impl->reader.getVal320()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal319());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::needs_implicit_move_assignment(void) const {
  if (!impl->reader.getVal322()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal321());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::needs_implicit_move_constructor(void) const {
  if (!impl->reader.getVal324()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal323());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::needs_overload_resolution_for_copy_assignment(void) const {
  if (!impl->reader.getVal326()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal325());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::needs_overload_resolution_for_copy_constructor(void) const {
  if (!impl->reader.getVal328()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal327());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::needs_overload_resolution_for_destructor(void) const {
  if (!impl->reader.getVal330()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal329());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::needs_overload_resolution_for_move_assignment(void) const {
  if (!impl->reader.getVal332()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal331());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::needs_overload_resolution_for_move_constructor(void) const {
  if (!impl->reader.getVal334()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal333());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::null_field_offset_is_zero(void) const {
  if (!impl->reader.getVal336()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal335());
  }
  return std::nullopt;
}

std::optional<std::vector<CXXBaseSpecifier>> CXXRecordDecl::virtual_bases(void) const {
  if (!impl->reader.getVal338()) {
    return std::nullopt;
  }
  auto list = impl->reader.getVal337();
  std::vector<CXXBaseSpecifier> vec;
  vec.reserve(list.size());
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d337 = ep->CXXBaseSpecifierFor(ep, v)) {
      vec.emplace_back(std::move(d337));
    }
  }
  return vec;
}

std::optional<uint64_t> CXXRecordDecl::size_without_virtual_bases(void) const {
  if (!impl->reader.getVal339()) {
    return std::nullopt;
  } else {
    return static_cast<uint64_t>(impl->reader.getVal139());
  }
  return std::nullopt;
}

std::optional<CXXRecordDecl> CXXRecordDecl::primary_base(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal161();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return CXXRecordDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_own_virtual_function_table_pointer(void) const {
  if (!impl->reader.getVal341()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal340());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_extendable_virtual_function_table_pointer(void) const {
  if (!impl->reader.getVal343()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal342());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_virtual_base_table_pointer(void) const {
  if (!impl->reader.getVal345()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal344());
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::has_own_virtual_base_table_pointer(void) const {
  if (!impl->reader.getVal347()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal346());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
