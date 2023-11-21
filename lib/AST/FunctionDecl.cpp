// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/FunctionDecl.h>

#include <multiplier/AST/CXXConstructorDecl.h>
#include <multiplier/AST/CXXConversionDecl.h>
#include <multiplier/AST/CXXDeductionGuideDecl.h>
#include <multiplier/AST/CXXDestructorDecl.h>
#include <multiplier/AST/CXXMethodDecl.h>
#include <multiplier/AST/CallExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/DeclaratorDecl.h>
#include <multiplier/AST/FunctionTemplateDecl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/ParmVarDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/ValueDecl.h>

#include "../EntityProvider.h"
#include "../Fragment.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<FunctionDecl> FunctionDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = FunctionDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool FunctionDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : FunctionDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<FunctionDecl> FunctionDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = FunctionDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<FunctionDecl> FunctionDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<FunctionDecl> FunctionDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = FunctionDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<FunctionDecl> FunctionDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool FunctionDecl::contains(const Decl &decl) {
  for (auto &parent : FunctionDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool FunctionDecl::contains(const Stmt &stmt) {
  for (auto &parent : FunctionDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

FunctionDecl FunctionDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (FunctionDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<FunctionDecl> FunctionDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<FunctionDecl> FunctionDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<FunctionDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<FunctionDecl> FunctionDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<FunctionDecl> FunctionDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const DeclKind kFunctionDeclDerivedKinds[] = {
    FunctionDecl::static_kind(),
    CXXDeductionGuideDecl::static_kind(),
    CXXMethodDecl::static_kind(),
    CXXConstructorDecl::static_kind(),
    CXXConversionDecl::static_kind(),
    CXXDestructorDecl::static_kind(),
};

}  // namespace

std::optional<FunctionDecl> FunctionDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case FunctionDecl::static_kind():
    case CXXDeductionGuideDecl::static_kind():
    case CXXMethodDecl::static_kind():
    case CXXConstructorDecl::static_kind():
    case CXXConversionDecl::static_kind():
    case CXXDestructorDecl::static_kind():
      return reinterpret_cast<const FunctionDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<FunctionDecl> FunctionDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kFunctionDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<FunctionDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FunctionDecl> FunctionDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kFunctionDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<FunctionDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FunctionDecl> FunctionDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kFunctionDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<FunctionDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<FunctionDecl> FunctionDecl::from(const Reference &r) {
  return FunctionDecl::from(r.as_declaration());
}

std::optional<FunctionDecl> FunctionDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<FunctionDecl> FunctionDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

bool FunctionDecl::body_contains_immediate_escalating_expressions(void) const {
  return impl->reader.getVal76();
}

bool FunctionDecl::friend_constraint_refers_to_enclosing_template(void) const {
  return impl->reader.getVal77();
}

bool FunctionDecl::uses_fp_intrin(void) const {
  return impl->reader.getVal94();
}

std::optional<bool> FunctionDecl::does_declaration_force_externally_visible_definition(void) const {
  if (!impl->reader.getVal96()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal95());
  }
  return std::nullopt;
}

bool FunctionDecl::does_this_declaration_have_a_body(void) const {
  return impl->reader.getVal97();
}

Type FunctionDecl::call_result_type(void) const {
  RawEntityId eid = impl->reader.getVal79();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

ConstexprSpecKind FunctionDecl::constexpr_kind(void) const {
  return static_cast<ConstexprSpecKind>(impl->reader.getVal80());
}

Type FunctionDecl::declared_return_type(void) const {
  RawEntityId eid = impl->reader.getVal81();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Token FunctionDecl::default_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal82());
}

std::optional<FunctionTemplateDecl> FunctionDecl::described_function_template(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal83();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FunctionTemplateDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token FunctionDecl::ellipsis_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal84());
}

TokenRange FunctionDecl::exception_spec_tokens(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal86(), impl->reader.getVal91());
}

ExceptionSpecificationType FunctionDecl::exception_spec_type(void) const {
  return static_cast<ExceptionSpecificationType>(impl->reader.getVal85());
}

std::optional<FunctionDecl> FunctionDecl::instantiated_from_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal128();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FunctionDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<FunctionDecl> FunctionDecl::instantiated_from_member_function(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal129();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FunctionDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

LanguageLinkage FunctionDecl::language_linkage(void) const {
  return static_cast<LanguageLinkage>(impl->reader.getVal87());
}

MultiVersionKind FunctionDecl::multi_version_kind(void) const {
  return static_cast<MultiVersionKind>(impl->reader.getVal88());
}

std::optional<uint32_t> FunctionDecl::odr_hash(void) const {
  if (!impl->reader.getVal98()) {
    return std::nullopt;
  } else {
    return static_cast<uint32_t>(impl->reader.getVal142());
  }
  return std::nullopt;
}

OverloadedOperatorKind FunctionDecl::overloaded_operator(void) const {
  return static_cast<OverloadedOperatorKind>(impl->reader.getVal89());
}

TokenRange FunctionDecl::parameters_tokens(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal130(), impl->reader.getVal132());
}

Token FunctionDecl::point_of_instantiation(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal133());
}

std::optional<FunctionTemplateDecl> FunctionDecl::primary_template(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal141();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FunctionTemplateDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

Type FunctionDecl::return_type(void) const {
  RawEntityId eid = impl->reader.getVal143();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

StorageClass FunctionDecl::storage_class(void) const {
  return static_cast<StorageClass>(impl->reader.getVal90());
}

std::optional<FunctionDecl> FunctionDecl::template_instantiation_pattern(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal144();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FunctionDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

TemplateSpecializationKind FunctionDecl::template_specialization_kind(void) const {
  return static_cast<TemplateSpecializationKind>(impl->reader.getVal92());
}

TemplateSpecializationKind FunctionDecl::template_specialization_kind_for_instantiation(void) const {
  return static_cast<TemplateSpecializationKind>(impl->reader.getVal93());
}

FunctionDeclTemplatedKind FunctionDecl::templated_kind(void) const {
  return static_cast<FunctionDeclTemplatedKind>(impl->reader.getVal131());
}

bool FunctionDecl::has_implicit_return_zero(void) const {
  return impl->reader.getVal99();
}

bool FunctionDecl::has_inherited_prototype(void) const {
  return impl->reader.getVal100();
}

bool FunctionDecl::has_one_parameter_or_default_arguments(void) const {
  return impl->reader.getVal101();
}

bool FunctionDecl::has_prototype(void) const {
  return impl->reader.getVal102();
}

bool FunctionDecl::has_skipped_body(void) const {
  return impl->reader.getVal103();
}

bool FunctionDecl::has_trivial_body(void) const {
  return impl->reader.getVal104();
}

bool FunctionDecl::has_written_prototype(void) const {
  return impl->reader.getVal105();
}

bool FunctionDecl::instantiation_is_pending(void) const {
  return impl->reader.getVal106();
}

bool FunctionDecl::is_cpu_dispatch_multi_version(void) const {
  return impl->reader.getVal107();
}

bool FunctionDecl::is_cpu_specific_multi_version(void) const {
  return impl->reader.getVal108();
}

bool FunctionDecl::is_consteval(void) const {
  return impl->reader.getVal109();
}

bool FunctionDecl::is_constexpr(void) const {
  return impl->reader.getVal110();
}

bool FunctionDecl::is_constexpr_specified(void) const {
  return impl->reader.getVal111();
}

bool FunctionDecl::is_defaulted(void) const {
  return impl->reader.getVal112();
}

bool FunctionDecl::is_deleted(void) const {
  return impl->reader.getVal113();
}

bool FunctionDecl::is_deleted_as_written(void) const {
  return impl->reader.getVal114();
}

bool FunctionDecl::is_destroying_operator_delete(void) const {
  return impl->reader.getVal115();
}

bool FunctionDecl::is_explicitly_defaulted(void) const {
  return impl->reader.getVal116();
}

bool FunctionDecl::is_extern_c(void) const {
  return impl->reader.getVal117();
}

bool FunctionDecl::is_function_template_specialization(void) const {
  return impl->reader.getVal118();
}

bool FunctionDecl::is_global(void) const {
  return impl->reader.getVal119();
}

bool FunctionDecl::is_immediate_escalating(void) const {
  return impl->reader.getVal120();
}

bool FunctionDecl::is_immediate_function(void) const {
  return impl->reader.getVal121();
}

bool FunctionDecl::is_implicitly_instantiable(void) const {
  return impl->reader.getVal122();
}

bool FunctionDecl::is_in_extern_c_context(void) const {
  return impl->reader.getVal123();
}

bool FunctionDecl::is_in_extern_cxx_context(void) const {
  return impl->reader.getVal124();
}

bool FunctionDecl::is_ineligible_or_not_selected(void) const {
  return impl->reader.getVal125();
}

bool FunctionDecl::is_inline_builtin_declaration(void) const {
  return impl->reader.getVal126();
}

std::optional<bool> FunctionDecl::is_inline_definition_externally_visible(void) const {
  if (!impl->reader.getVal134()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal127());
  }
  return std::nullopt;
}

bool FunctionDecl::is_inline_specified(void) const {
  return impl->reader.getVal135();
}

bool FunctionDecl::is_inlined(void) const {
  return impl->reader.getVal136();
}

bool FunctionDecl::is_late_template_parsed(void) const {
  return impl->reader.getVal137();
}

std::optional<bool> FunctionDecl::is_ms_extern_inline(void) const {
  if (!impl->reader.getVal139()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal138());
  }
  return std::nullopt;
}

bool FunctionDecl::is_msvcrt_entry_point(void) const {
  return impl->reader.getVal140();
}

bool FunctionDecl::is_main(void) const {
  return impl->reader.getVal145();
}

bool FunctionDecl::is_member_like_constrained_friend(void) const {
  return impl->reader.getVal146();
}

bool FunctionDecl::is_multi_version(void) const {
  return impl->reader.getVal147();
}

bool FunctionDecl::is_no_return(void) const {
  return impl->reader.getVal148();
}

bool FunctionDecl::is_overloaded_operator(void) const {
  return impl->reader.getVal149();
}

bool FunctionDecl::is_pure(void) const {
  return impl->reader.getVal150();
}

bool FunctionDecl::is_replaceable_global_allocation_function(void) const {
  return impl->reader.getVal151();
}

std::optional<bool> FunctionDecl::is_reserved_global_placement_operator(void) const {
  if (!impl->reader.getVal153()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal152());
  }
  return std::nullopt;
}

bool FunctionDecl::is_static(void) const {
  return impl->reader.getVal154();
}

bool FunctionDecl::is_target_clones_multi_version(void) const {
  return impl->reader.getVal155();
}

bool FunctionDecl::is_target_multi_version(void) const {
  return impl->reader.getVal156();
}

bool FunctionDecl::is_template_instantiation(void) const {
  return impl->reader.getVal157();
}

bool FunctionDecl::is_this_declaration_a_definition(void) const {
  return impl->reader.getVal158();
}

bool FunctionDecl::is_this_declaration_instantiated_from_a_friend_definition(void) const {
  return impl->reader.getVal159();
}

bool FunctionDecl::is_trivial(void) const {
  return impl->reader.getVal160();
}

bool FunctionDecl::is_trivial_for_call(void) const {
  return impl->reader.getVal161();
}

bool FunctionDecl::is_user_provided(void) const {
  return impl->reader.getVal162();
}

bool FunctionDecl::is_variadic(void) const {
  return impl->reader.getVal163();
}

bool FunctionDecl::is_virtual_as_written(void) const {
  return impl->reader.getVal164();
}

unsigned FunctionDecl::num_parameters(void) const {
  return impl->reader.getVal52().size();
}

std::optional<ParmVarDecl> FunctionDecl::nth_parameter(unsigned n) const {
  auto list = impl->reader.getVal52();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ParmVarDecl::from_base(std::move(e));
}

gap::generator<ParmVarDecl> FunctionDecl::parameters(void) const & {
  auto list = impl->reader.getVal52();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d52 = ep->DeclFor(ep, v)) {
      if (auto e = ParmVarDecl::from_base(std::move(d52))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

bool FunctionDecl::uses_seh_try(void) const {
  return impl->reader.getVal165();
}

bool FunctionDecl::will_have_body(void) const {
  return impl->reader.getVal166();
}

std::optional<Stmt> FunctionDecl::body(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal167();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Stmt(std::move(eptr));
    }
  }
  return std::nullopt;
}

gap::generator<Decl> FunctionDecl::declarations_in_context(void) const & {
  EntityProviderPtr ep = impl->ep;
  auto list = impl->reader.getVal62();
  for (auto v : list) {
    if (auto eptr = ep->DeclFor(ep, v)) {
      co_yield std::move(eptr);
    }
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
