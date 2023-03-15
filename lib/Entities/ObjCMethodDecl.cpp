// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCMethodDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/ImplicitParamDecl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/ObjCInterfaceDecl.h>
#include <multiplier/Entities/ObjCPropertyDecl.h>
#include <multiplier/Entities/ParmVarDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Fragment.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCMethodDecl> ObjCMethodDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCMethodDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCMethodDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCMethodDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCMethodDecl> ObjCMethodDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCMethodDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCMethodDecl> ObjCMethodDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCMethodDecl> ObjCMethodDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCMethodDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCMethodDecl> ObjCMethodDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCMethodDecl::contains(const Decl &decl) {
  for (auto &parent : ObjCMethodDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ObjCMethodDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCMethodDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<ObjCMethodDecl> ObjCMethodDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCMethodDecl> dr = ObjCMethodDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ObjCMethodDecl> ObjCMethodDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ObjCMethodDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kObjCMethodDeclDerivedKinds[] = {
    ObjCMethodDecl::static_kind(),
};

std::optional<ObjCMethodDecl> ObjCMethodDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCMethodDecl::static_kind():
      return reinterpret_cast<const ObjCMethodDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCMethodDecl> ObjCMethodDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kObjCMethodDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCMethodDecl> e = ObjCMethodDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCMethodDecl> ObjCMethodDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCMethodDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCMethodDecl> e = ObjCMethodDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCMethodDecl> ObjCMethodDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCMethodDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCMethodDecl> e = ObjCMethodDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCMethodDecl> ObjCMethodDecl::from(const Reference &r) {
  return ObjCMethodDecl::from(r.as_declaration());
}

std::optional<ObjCMethodDecl> ObjCMethodDecl::from(const TokenContext &t) {
  return ObjCMethodDecl::from(t.as_declaration());
}

bool ObjCMethodDecl::defined_in_ns_object(void) const {
  return impl->reader.getVal70();
}

ObjCPropertyDecl ObjCMethodDecl::find_property_declaration(void) const {
  RawEntityId eid = impl->reader.getVal52();
  return ObjCPropertyDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

ObjCInterfaceDecl ObjCMethodDecl::class_interface(void) const {
  RawEntityId eid = impl->reader.getVal53();
  return ObjCInterfaceDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

ImplicitParamDecl ObjCMethodDecl::command_declaration(void) const {
  RawEntityId eid = impl->reader.getVal54();
  return ImplicitParamDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Token ObjCMethodDecl::declarator_end_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal62());
}

ObjCMethodDeclImplementationControl ObjCMethodDecl::implementation_control(void) const {
  return static_cast<ObjCMethodDeclImplementationControl>(impl->reader.getVal74());
}

ObjCMethodFamily ObjCMethodDecl::method_family(void) const {
  return static_cast<ObjCMethodFamily>(impl->reader.getVal79());
}

DeclObjCDeclQualifier ObjCMethodDecl::obj_c_decl_qualifier(void) const {
  return static_cast<DeclObjCDeclQualifier>(impl->reader.getVal81());
}

Type ObjCMethodDecl::return_type(void) const {
  RawEntityId eid = impl->reader.getVal63();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

TokenRange ObjCMethodDecl::return_type_source_range(void) const {
  auto &ep = impl->ep;
  auto fragment = ep->FragmentFor(ep, impl->fragment_id);
  return fragment->TokenRangeFor(fragment, impl->reader.getVal64(), impl->reader.getVal73());
}

Token ObjCMethodDecl::selector_start_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal75());
}

ImplicitParamDecl ObjCMethodDecl::self_declaration(void) const {
  RawEntityId eid = impl->reader.getVal76();
  return ImplicitParamDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

bool ObjCMethodDecl::has_parameter_destroyed_in_callee(void) const {
  return impl->reader.getVal71();
}

bool ObjCMethodDecl::has_redeclaration(void) const {
  return impl->reader.getVal72();
}

bool ObjCMethodDecl::has_related_result_type(void) const {
  return impl->reader.getVal88();
}

bool ObjCMethodDecl::has_skipped_body(void) const {
  return impl->reader.getVal89();
}

bool ObjCMethodDecl::is_class_method(void) const {
  return impl->reader.getVal90();
}

bool ObjCMethodDecl::is_defined(void) const {
  return impl->reader.getVal91();
}

bool ObjCMethodDecl::is_designated_initializer_for_the_interface(void) const {
  return impl->reader.getVal92();
}

bool ObjCMethodDecl::is_direct_method(void) const {
  return impl->reader.getVal93();
}

bool ObjCMethodDecl::is_instance_method(void) const {
  return impl->reader.getVal94();
}

bool ObjCMethodDecl::is_optional(void) const {
  return impl->reader.getVal95();
}

bool ObjCMethodDecl::is_overriding(void) const {
  return impl->reader.getVal96();
}

bool ObjCMethodDecl::is_property_accessor(void) const {
  return impl->reader.getVal97();
}

bool ObjCMethodDecl::is_redeclaration(void) const {
  return impl->reader.getVal98();
}

bool ObjCMethodDecl::is_synthesized_accessor_stub(void) const {
  return impl->reader.getVal99();
}

bool ObjCMethodDecl::is_this_declaration_a_definition(void) const {
  return impl->reader.getVal100();
}

bool ObjCMethodDecl::is_this_declaration_a_designated_initializer(void) const {
  return impl->reader.getVal101();
}

bool ObjCMethodDecl::is_variadic(void) const {
  return impl->reader.getVal102();
}

unsigned ObjCMethodDecl::num_parameters(void) const {
  return impl->reader.getVal47().size();
}

std::optional<ParmVarDecl> ObjCMethodDecl::nth_parameter(unsigned n) const {
  auto list = impl->reader.getVal47();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ParmVarDecl::from(Decl(std::move(e)));
}

gap::generator<ParmVarDecl> ObjCMethodDecl::parameters(void) const & {
  auto list = impl->reader.getVal47();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d47 = ep->DeclFor(ep, v)) {
      if (auto e = ParmVarDecl::from(Decl(std::move(d47)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned ObjCMethodDecl::num_selector_tokens(void) const {
  return impl->reader.getVal48().size();
}

std::optional<Token> ObjCMethodDecl::nth_selector_token(unsigned n) const {
  auto list = impl->reader.getVal48();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TokenFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Token(std::move(e));
}

gap::generator<Token> ObjCMethodDecl::selector_tokens(void) const & {
  auto list = impl->reader.getVal48();
  EntityProvider::Ptr ep = impl->ep;
  auto fragment = ep->FragmentFor(ep, impl->fragment_id);
  if (!fragment) {
    assert(false);
    co_return;
  }
  auto tok_reader = fragment->ParsedTokenReader(fragment);
  for (auto v : list) {
    EntityId id(v);
    if (auto t48 = ep->TokenFor(ep, tok_reader, v)) {
      co_yield t48;
    }
  }
  co_return;
}

gap::generator<Decl> ObjCMethodDecl::declarations_in_context(void) const & {
  EntityProvider::Ptr ep = impl->ep;
  auto list = impl->reader.getVal58();
  for (auto v : list) {
    if (auto eptr = ep->DeclFor(ep, v)) {
      co_yield std::move(eptr);
    }
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
