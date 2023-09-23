// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/Decl.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/ExternalSourceSymbolAttr.h>
#include <multiplier/Entities/File.h>
#include <multiplier/Entities/Fragment.h>
#include <multiplier/Entities/Index.h>
#include <multiplier/Entities/Reference.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateDecl.h>
#include <multiplier/Entities/TemplateParameterList.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../File.h"
#include "../Fragment.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

bool Decl::is_definition(void) const {
  return impl->reader.getVal2();
}

std::optional<Decl> Decl::parent_declaration(void) const {
  if (auto id = impl->reader.getVal0(); id != kInvalidEntityId) {
    if (auto eptr = impl->ep->DeclFor(impl->ep, id)) {
      return Decl(std::move(eptr));
    }
    assert(false);
  }
  return std::nullopt;
}

std::optional<Stmt> Decl::parent_statement(void) const {
  if (auto id = impl->reader.getVal1(); id != kInvalidEntityId) {
    if (auto eptr = impl->ep->StmtFor(impl->ep, id)) {
      return Stmt(std::move(eptr));
    }
    assert(false);
  }
  return std::nullopt;
}
std::shared_ptr<EntityProvider> Decl::entity_provider_of(const Index &index_) {
  return index_.impl;
}

std::shared_ptr<EntityProvider> Decl::entity_provider_of(const Fragment &frag_) {
  return frag_.impl->ep;
}

std::shared_ptr<EntityProvider> Decl::entity_provider_of(const File &file_) {
  return file_.impl->ep;
}

gap::generator<Decl> Decl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = Decl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool Decl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : Decl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<Decl> Decl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = Decl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<Decl> Decl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<Decl> Decl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = Decl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<Decl> Decl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool Decl::contains(const Decl &decl) {
  for (auto &parent : Decl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool Decl::contains(const Stmt &stmt) {
  for (auto &parent : Decl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<Decl> Decl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    index.declaration(eid.Pack());
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

gap::generator<Decl> Decl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclImplPtr eptr : ep->DeclsFor(ep)) {
    if (std::optional<Decl> e = Decl::from(Decl(std::move(eptr)))) {
      co_yield std::move(e.value());
    }
  }
}

gap::generator<Decl> Decl::in(const Index &index, std::span<DeclKind> kinds) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      co_yield Decl(std::move(eptr));
    }
  }
}

gap::generator<Decl> Decl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, frag_id)) {
      if (std::optional<Decl> e = Decl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<Decl> Decl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclImplPtr eptr : ep->DeclsFor(ep, frag_id)) {
    if (std::optional<Decl> e = Decl::from(Decl(std::move(eptr)))) {
      co_yield std::move(e.value());
    }
  }
}

gap::generator<Decl> Decl::in(const Fragment &frag, std::span<DeclKind> kinds) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      co_yield Decl(std::move(eptr));
    }
  }
}

gap::generator<Decl> Decl::in(const File &file, std::span<DeclKind> kinds) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        co_yield Decl(std::move(eptr));
      }
    }
  }
}

std::optional<Decl> Decl::from(const Reference &r) {
  return r.as_declaration();
}

std::optional<Decl> Decl::from(const TokenContext &t) {
  return t.as_declaration();
}

unsigned Decl::num_attributes(void) const {
  return impl->reader.getVal3().size();
}

std::optional<Attr> Decl::nth_attribute(unsigned n) const {
  auto list = impl->reader.getVal3();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->AttrFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Attr(std::move(e));
}

gap::generator<Attr> Decl::attributes(void) const & {
  auto list = impl->reader.getVal3();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d3 = ep->AttrFor(ep, v)) {
      co_yield Attr(std::move(d3));
    }
  }
  co_return;
}

AccessSpecifier Decl::access(void) const {
  return static_cast<AccessSpecifier>(impl->reader.getVal4());
}

AvailabilityResult Decl::availability(void) const {
  return static_cast<AvailabilityResult>(impl->reader.getVal5());
}

std::optional<Attr> Decl::defining_attribute(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal6();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->AttrFor(impl->ep, eid)) {
      return Attr(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<TemplateDecl> Decl::described_template(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal7();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return TemplateDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

std::optional<TemplateParameterList> Decl::described_template_parameters(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal8();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TemplateParameterListFor(impl->ep, eid)) {
      return TemplateParameterList(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<ExternalSourceSymbolAttr> Decl::external_source_symbol_attribute(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal9();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->AttrFor(impl->ep, eid)) {
      return ExternalSourceSymbolAttr::from(Attr(std::move(eptr)));
    }
  }
  return std::nullopt;
}

DeclFriendObjectKind Decl::friend_object_kind(void) const {
  return static_cast<DeclFriendObjectKind>(impl->reader.getVal10());
}

std::optional<uint32_t> Decl::max_alignment(void) const {
  if (!impl->reader.getVal12()) {
    return std::nullopt;
  } else {
    return static_cast<uint32_t>(impl->reader.getVal11());
  }
  return std::nullopt;
}

DeclModuleOwnershipKind Decl::module_ownership_kind(void) const {
  return static_cast<DeclModuleOwnershipKind>(impl->reader.getVal13());
}

std::optional<Decl> Decl::non_closure_context(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal14();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return Decl(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool Decl::has_attributes(void) const {
  return impl->reader.getVal15();
}

bool Decl::has_owning_module(void) const {
  return impl->reader.getVal16();
}

bool Decl::has_tag_identifier_namespace(void) const {
  return impl->reader.getVal17();
}

bool Decl::is_defined_outside_function_or_method(void) const {
  return impl->reader.getVal18();
}

bool Decl::is_deprecated(void) const {
  return impl->reader.getVal19();
}

bool Decl::is_discarded_in_global_module_fragment(void) const {
  return impl->reader.getVal20();
}

bool Decl::is_file_context_declaration(void) const {
  return impl->reader.getVal21();
}

bool Decl::is_function_or_function_template(void) const {
  return impl->reader.getVal22();
}

bool Decl::is_function_pointer_type(void) const {
  return impl->reader.getVal23();
}

bool Decl::is_implicit(void) const {
  return impl->reader.getVal24();
}

bool Decl::is_in_anonymous_namespace(void) const {
  return impl->reader.getVal25();
}

bool Decl::is_in_another_module_unit(void) const {
  return impl->reader.getVal26();
}

bool Decl::is_in_export_declaration_context(void) const {
  return impl->reader.getVal27();
}

std::optional<bool> Decl::is_in_local_scope_for_instantiation(void) const {
  if (!impl->reader.getVal29()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal28());
  }
  return std::nullopt;
}

bool Decl::is_in_std_namespace(void) const {
  return impl->reader.getVal30();
}

bool Decl::is_invalid_declaration(void) const {
  return impl->reader.getVal31();
}

bool Decl::is_invisible_outside_the_owning_module(void) const {
  return impl->reader.getVal32();
}

bool Decl::is_local_extern_declaration(void) const {
  return impl->reader.getVal33();
}

bool Decl::is_module_private(void) const {
  return impl->reader.getVal34();
}

bool Decl::is_out_of_line(void) const {
  return impl->reader.getVal35();
}

bool Decl::is_parameter_pack(void) const {
  return impl->reader.getVal36();
}

bool Decl::is_reachable(void) const {
  return impl->reader.getVal37();
}

bool Decl::is_template_declaration(void) const {
  return impl->reader.getVal38();
}

bool Decl::is_template_parameter(void) const {
  return impl->reader.getVal39();
}

bool Decl::is_template_parameter_pack(void) const {
  return impl->reader.getVal40();
}

bool Decl::is_templated(void) const {
  return impl->reader.getVal41();
}

bool Decl::is_this_declaration_referenced(void) const {
  return impl->reader.getVal42();
}

bool Decl::is_top_level_declaration_in_obj_c_container(void) const {
  return impl->reader.getVal43();
}

bool Decl::is_unavailable(void) const {
  return impl->reader.getVal44();
}

bool Decl::is_unconditionally_visible(void) const {
  return impl->reader.getVal45();
}

bool Decl::is_weak_imported(void) const {
  return impl->reader.getVal46();
}

DeclKind Decl::kind(void) const {
  return static_cast<DeclKind>(impl->reader.getVal47());
}

DeclCategory Decl::category(void) const {
  return static_cast<DeclCategory>(impl->reader.getVal48());
}

Token Decl::token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal49());
}

TokenRange Decl::tokens(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal50(), impl->reader.getVal51());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
