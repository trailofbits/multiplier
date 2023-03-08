// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/VarDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DeclaratorDecl.h>
#include <multiplier/Entities/DecompositionDecl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/ImplicitParamDecl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/OMPCapturedExprDecl.h>
#include <multiplier/Entities/ParmVarDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueDecl.h>
#include <multiplier/Entities/VarTemplateDecl.h>
#include <multiplier/Entities/VarTemplatePartialSpecializationDecl.h>
#include <multiplier/Entities/VarTemplateSpecializationDecl.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<VarDecl> VarDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = VarDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool VarDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : VarDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<VarDecl> VarDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = VarDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<VarDecl> VarDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<VarDecl> VarDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = VarDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<VarDecl> VarDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool VarDecl::contains(const Decl &decl) {
  for (auto &parent : VarDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool VarDecl::contains(const Stmt &stmt) {
  for (auto &parent : VarDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<VarDecl> VarDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<VarDecl> dr = VarDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<VarDecl> VarDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return VarDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kVarDeclDerivedKinds[] = {
    VarDecl::static_kind(),
    VarTemplateSpecializationDecl::static_kind(),
    DecompositionDecl::static_kind(),
    ImplicitParamDecl::static_kind(),
    OMPCapturedExprDecl::static_kind(),
    ParmVarDecl::static_kind(),
    VarTemplatePartialSpecializationDecl::static_kind(),
};

std::optional<VarDecl> VarDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case VarDecl::static_kind():
    case VarTemplateSpecializationDecl::static_kind():
    case DecompositionDecl::static_kind():
    case ImplicitParamDecl::static_kind():
    case OMPCapturedExprDecl::static_kind():
    case ParmVarDecl::static_kind():
    case VarTemplatePartialSpecializationDecl::static_kind():
      return reinterpret_cast<const VarDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<VarDecl> VarDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kVarDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<VarDecl> e = VarDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VarDecl> VarDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kVarDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<VarDecl> e = VarDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VarDecl> VarDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kVarDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<VarDecl> e = VarDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<VarDecl> VarDecl::acting_definition(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal73();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return VarDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

std::optional<VarTemplateDecl> VarDecl::described_variable_template(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal75();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return VarTemplateDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

std::optional<Expr> VarDecl::initializer(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal76();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

VarDeclInitializationStyle VarDecl::initializer_style(void) const {
  return static_cast<VarDeclInitializationStyle>(impl->reader.getVal74());
}

std::optional<VarDecl> VarDecl::initializing_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal77();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return VarDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

std::optional<VarDecl> VarDecl::instantiated_from_static_data_member(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal78();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return VarDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

LanguageLinkage VarDecl::language_linkage(void) const {
  return static_cast<LanguageLinkage>(impl->reader.getVal79());
}

Token VarDecl::point_of_instantiation(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal80());
}

StorageClass VarDecl::storage_class(void) const {
  return static_cast<StorageClass>(impl->reader.getVal81());
}

StorageDuration VarDecl::storage_duration(void) const {
  return static_cast<StorageDuration>(impl->reader.getVal82());
}

VarDeclTLSKind VarDecl::tls_kind(void) const {
  return static_cast<VarDeclTLSKind>(impl->reader.getVal83());
}

ThreadStorageClassSpecifier VarDecl::tsc_spec(void) const {
  return static_cast<ThreadStorageClassSpecifier>(impl->reader.getVal84());
}

std::optional<VarDecl> VarDecl::template_instantiation_pattern(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal85();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return VarDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

TemplateSpecializationKind VarDecl::template_specialization_kind(void) const {
  return static_cast<TemplateSpecializationKind>(impl->reader.getVal86());
}

TemplateSpecializationKind VarDecl::template_specialization_kind_for_instantiation(void) const {
  return static_cast<TemplateSpecializationKind>(impl->reader.getVal87());
}

bool VarDecl::has_constant_initialization(void) const {
  return impl->reader.getVal71();
}

bool VarDecl::has_dependent_alignment(void) const {
  return impl->reader.getVal72();
}

bool VarDecl::has_external_storage(void) const {
  return impl->reader.getVal88();
}

std::optional<bool> VarDecl::has_flexible_array_initializer(void) const {
  if (!impl->reader.getVal90()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal89());
  }
  return std::nullopt;
}

bool VarDecl::has_global_storage(void) const {
  return impl->reader.getVal91();
}

std::optional<bool> VarDecl::has_ice_initializer(void) const {
  if (!impl->reader.getVal93()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal92());
  }
  return std::nullopt;
}

bool VarDecl::has_initializer(void) const {
  return impl->reader.getVal94();
}

bool VarDecl::has_local_storage(void) const {
  return impl->reader.getVal95();
}

bool VarDecl::is_arc_pseudo_strong(void) const {
  return impl->reader.getVal96();
}

bool VarDecl::is_cxx_for_range_declaration(void) const {
  return impl->reader.getVal97();
}

bool VarDecl::is_constexpr(void) const {
  return impl->reader.getVal98();
}

bool VarDecl::is_direct_initializer(void) const {
  return impl->reader.getVal99();
}

bool VarDecl::is_escaping_byref(void) const {
  return impl->reader.getVal100();
}

bool VarDecl::is_exception_variable(void) const {
  return impl->reader.getVal101();
}

bool VarDecl::is_extern_c(void) const {
  return impl->reader.getVal102();
}

bool VarDecl::is_file_variable_declaration(void) const {
  return impl->reader.getVal103();
}

bool VarDecl::is_function_or_method_variable_declaration(void) const {
  return impl->reader.getVal104();
}

bool VarDecl::is_in_extern_c_context(void) const {
  return impl->reader.getVal105();
}

bool VarDecl::is_in_extern_cxx_context(void) const {
  return impl->reader.getVal106();
}

bool VarDecl::is_initializer_capture(void) const {
  return impl->reader.getVal107();
}

bool VarDecl::is_inline(void) const {
  return impl->reader.getVal108();
}

bool VarDecl::is_inline_specified(void) const {
  return impl->reader.getVal109();
}

bool VarDecl::is_known_to_be_defined(void) const {
  return impl->reader.getVal110();
}

bool VarDecl::is_local_variable_declaration(void) const {
  return impl->reader.getVal111();
}

bool VarDecl::is_local_variable_declaration_or_parm(void) const {
  return impl->reader.getVal112();
}

bool VarDecl::is_nrvo_variable(void) const {
  return impl->reader.getVal113();
}

bool VarDecl::is_no_destroy(void) const {
  return impl->reader.getVal114();
}

bool VarDecl::is_non_escaping_byref(void) const {
  return impl->reader.getVal115();
}

bool VarDecl::is_obj_c_for_declaration(void) const {
  return impl->reader.getVal116();
}

bool VarDecl::is_previous_declaration_in_same_block_scope(void) const {
  return impl->reader.getVal117();
}

bool VarDecl::is_static_data_member(void) const {
  return impl->reader.getVal118();
}

bool VarDecl::is_static_local(void) const {
  return impl->reader.getVal119();
}

bool VarDecl::is_this_declaration_a_demoted_definition(void) const {
  return impl->reader.getVal120();
}

bool VarDecl::is_usable_in_constant_expressions(void) const {
  return impl->reader.getVal121();
}

bool VarDecl::might_be_usable_in_constant_expressions(void) const {
  return impl->reader.getVal122();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
