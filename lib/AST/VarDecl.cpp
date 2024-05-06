// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/VarDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/DeclaratorDecl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueDecl.h>
#include <multiplier/AST/VarTemplateDecl.h>
#include <multiplier/AST/DecompositionDecl.h>
#include <multiplier/AST/ImplicitParamDecl.h>
#include <multiplier/AST/OMPCapturedExprDecl.h>
#include <multiplier/AST/ParmVarDecl.h>
#include <multiplier/AST/VarTemplatePartialSpecializationDecl.h>
#include <multiplier/AST/VarTemplateSpecializationDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kVarDeclDerivedKinds[] = {
    VarDecl::static_kind(),
    VarTemplateSpecializationDecl::static_kind(),
    DecompositionDecl::static_kind(),
    ImplicitParamDecl::static_kind(),
    OMPCapturedExprDecl::static_kind(),
    ParmVarDecl::static_kind(),
    VarTemplatePartialSpecializationDecl::static_kind(),
};
}  // namespace

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

std::optional<VarDecl> VarDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<VarDecl, ir::Operation>> VarDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kVarDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<VarDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
    if (*this == parent) { return true; }
  }
  return false;
}

bool VarDecl::contains(const Stmt &stmt) {
  for (auto &parent : VarDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

VarDecl VarDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (VarDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<VarDecl> VarDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<VarDecl> VarDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<VarDecl> dr = from_base(r)) {
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
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<VarDecl> VarDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<VarDecl> VarDecl::from_base(const Decl &parent) {
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
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kVarDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<VarDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VarDecl> VarDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kVarDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<VarDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VarDecl> VarDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kVarDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<VarDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<VarDecl> VarDecl::from(const Reference &r) {
  return VarDecl::from(r.as_declaration());
}

std::optional<VarDecl> VarDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<VarDecl> VarDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<VarDecl> VarDecl::acting_definition(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal69();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return VarDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<VarTemplateDecl> VarDecl::described_variable_template(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal71();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return VarTemplateDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<Expr> VarDecl::initializer(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal72();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

VarDeclInitializationStyle VarDecl::initializer_style(void) const {
  return static_cast<VarDeclInitializationStyle>(impl->reader.getVal70());
}

std::optional<VarDecl> VarDecl::initializing_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal73();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return VarDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

LanguageLinkage VarDecl::language_linkage(void) const {
  return static_cast<LanguageLinkage>(impl->reader.getVal74());
}

Token VarDecl::point_of_instantiation(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal75());
}

StorageClass VarDecl::storage_class(void) const {
  return static_cast<StorageClass>(impl->reader.getVal76());
}

StorageDuration VarDecl::storage_duration(void) const {
  return static_cast<StorageDuration>(impl->reader.getVal77());
}

VarDeclTLSKind VarDecl::tls_kind(void) const {
  return static_cast<VarDeclTLSKind>(impl->reader.getVal78());
}

ThreadStorageClassSpecifier VarDecl::tsc_spec(void) const {
  return static_cast<ThreadStorageClassSpecifier>(impl->reader.getVal79());
}

std::optional<VarDecl> VarDecl::template_instantiation_pattern(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal80();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return VarDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

TemplateSpecializationKind VarDecl::template_specialization_kind(void) const {
  return static_cast<TemplateSpecializationKind>(impl->reader.getVal81());
}

TemplateSpecializationKind VarDecl::template_specialization_kind_for_instantiation(void) const {
  return static_cast<TemplateSpecializationKind>(impl->reader.getVal82());
}

bool VarDecl::has_constant_initialization(void) const {
  return impl->reader.getVal66();
}

bool VarDecl::has_dependent_alignment(void) const {
  return impl->reader.getVal67();
}

bool VarDecl::has_external_storage(void) const {
  return impl->reader.getVal83();
}

std::optional<bool> VarDecl::has_flexible_array_initializer(void) const {
  if (!impl->reader.getVal85()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal84());
  }
  return std::nullopt;
}

bool VarDecl::has_global_storage(void) const {
  return impl->reader.getVal86();
}

bool VarDecl::has_initializer(void) const {
  return impl->reader.getVal87();
}

bool VarDecl::has_local_storage(void) const {
  return impl->reader.getVal88();
}

bool VarDecl::is_arc_pseudo_strong(void) const {
  return impl->reader.getVal89();
}

bool VarDecl::is_cxx_for_range_declaration(void) const {
  return impl->reader.getVal90();
}

bool VarDecl::is_constexpr(void) const {
  return impl->reader.getVal91();
}

bool VarDecl::is_direct_initializer(void) const {
  return impl->reader.getVal92();
}

bool VarDecl::is_escaping_byref(void) const {
  return impl->reader.getVal93();
}

bool VarDecl::is_exception_variable(void) const {
  return impl->reader.getVal94();
}

bool VarDecl::is_extern_c(void) const {
  return impl->reader.getVal95();
}

bool VarDecl::is_file_variable_declaration(void) const {
  return impl->reader.getVal96();
}

bool VarDecl::is_function_or_method_variable_declaration(void) const {
  return impl->reader.getVal97();
}

bool VarDecl::is_in_extern_c_context(void) const {
  return impl->reader.getVal98();
}

bool VarDecl::is_in_extern_cxx_context(void) const {
  return impl->reader.getVal99();
}

bool VarDecl::is_inline(void) const {
  return impl->reader.getVal100();
}

bool VarDecl::is_inline_specified(void) const {
  return impl->reader.getVal101();
}

bool VarDecl::is_known_to_be_defined(void) const {
  return impl->reader.getVal102();
}

bool VarDecl::is_local_variable_declaration(void) const {
  return impl->reader.getVal103();
}

bool VarDecl::is_local_variable_declaration_or_parm(void) const {
  return impl->reader.getVal104();
}

bool VarDecl::is_nrvo_variable(void) const {
  return impl->reader.getVal105();
}

bool VarDecl::is_no_destroy(void) const {
  return impl->reader.getVal106();
}

bool VarDecl::is_non_escaping_byref(void) const {
  return impl->reader.getVal107();
}

bool VarDecl::is_obj_c_for_declaration(void) const {
  return impl->reader.getVal108();
}

bool VarDecl::is_previous_declaration_in_same_block_scope(void) const {
  return impl->reader.getVal109();
}

bool VarDecl::is_static_data_member(void) const {
  return impl->reader.getVal110();
}

bool VarDecl::is_static_local(void) const {
  return impl->reader.getVal111();
}

bool VarDecl::is_this_declaration_a_demoted_definition(void) const {
  return impl->reader.getVal112();
}

bool VarDecl::is_usable_in_constant_expressions(void) const {
  return impl->reader.getVal113();
}

bool VarDecl::might_be_usable_in_constant_expressions(void) const {
  return impl->reader.getVal114();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
