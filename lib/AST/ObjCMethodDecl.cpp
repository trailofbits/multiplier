// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCMethodDecl.h>
#include "../Reference.h"
#include <multiplier/AST/Decl.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/ImplicitParamDecl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/ObjCInterfaceDecl.h>
#include <multiplier/AST/ObjCPropertyDecl.h>
#include <multiplier/AST/ParmVarDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Fragment.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kObjCMethodDeclDerivedKinds[] = {
    ObjCMethodDecl::static_kind(),
};
}  // namespace

gap::generator<ObjCMethodDecl> ObjCMethodDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kObjCMethodDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCMethodDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCMethodDecl> ObjCMethodDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCMethodDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCMethodDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<ObjCMethodDecl> ObjCMethodDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCMethodDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCMethodDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

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

std::optional<ObjCMethodDecl> ObjCMethodDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<ObjCMethodDecl, ir::Operation>> ObjCMethodDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kObjCMethodDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<ObjCMethodDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCMethodDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCMethodDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ObjCMethodDecl ObjCMethodDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ObjCMethodDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ObjCMethodDecl> ObjCMethodDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<ObjCMethodDecl> ObjCMethodDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCMethodDecl> dr = from_base(r)) {
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
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<ObjCMethodDecl> ObjCMethodDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ObjCMethodDecl> ObjCMethodDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCMethodDecl::static_kind():
      return reinterpret_cast<const ObjCMethodDecl &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<ObjCMethodDecl> ObjCMethodDecl::from(const Reference &r) {
  return ObjCMethodDecl::from(r.as_declaration());
}

std::optional<ObjCMethodDecl> ObjCMethodDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<ObjCMethodDecl> ObjCMethodDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

bool ObjCMethodDecl::defined_in_ns_object(void) const {
  return impl->reader.getVal63();
}

ObjCPropertyDecl ObjCMethodDecl::find_property_declaration(void) const {
  RawEntityId eid = impl->reader.getVal45();
  return ObjCPropertyDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

ObjCInterfaceDecl ObjCMethodDecl::class_interface(void) const {
  RawEntityId eid = impl->reader.getVal46();
  return ObjCInterfaceDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

ImplicitParamDecl ObjCMethodDecl::command_declaration(void) const {
  RawEntityId eid = impl->reader.getVal47();
  return ImplicitParamDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Token ObjCMethodDecl::declarator_end_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal55());
}

ObjCImplementationControl ObjCMethodDecl::implementation_control(void) const {
  return static_cast<ObjCImplementationControl>(impl->reader.getVal69());
}

ObjCMethodFamily ObjCMethodDecl::method_family(void) const {
  return static_cast<ObjCMethodFamily>(impl->reader.getVal73());
}

DeclObjCDeclQualifier ObjCMethodDecl::obj_c_decl_qualifier(void) const {
  return static_cast<DeclObjCDeclQualifier>(impl->reader.getVal74());
}

Type ObjCMethodDecl::return_type(void) const {
  RawEntityId eid = impl->reader.getVal56();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

TokenRange ObjCMethodDecl::return_type_tokens(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal57(), impl->reader.getVal67());
}

Token ObjCMethodDecl::selector_start_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal68());
}

ImplicitParamDecl ObjCMethodDecl::self_declaration(void) const {
  RawEntityId eid = impl->reader.getVal70();
  return ImplicitParamDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

bool ObjCMethodDecl::has_parameter_destroyed_in_callee(void) const {
  return impl->reader.getVal64();
}

bool ObjCMethodDecl::has_redeclaration(void) const {
  return impl->reader.getVal65();
}

bool ObjCMethodDecl::has_related_result_type(void) const {
  return impl->reader.getVal66();
}

bool ObjCMethodDecl::has_skipped_body(void) const {
  return impl->reader.getVal78();
}

bool ObjCMethodDecl::is_class_method(void) const {
  return impl->reader.getVal79();
}

bool ObjCMethodDecl::is_defined(void) const {
  return impl->reader.getVal80();
}

bool ObjCMethodDecl::is_designated_initializer_for_the_interface(void) const {
  return impl->reader.getVal81();
}

bool ObjCMethodDecl::is_direct_method(void) const {
  return impl->reader.getVal82();
}

bool ObjCMethodDecl::is_instance_method(void) const {
  return impl->reader.getVal83();
}

bool ObjCMethodDecl::is_optional(void) const {
  return impl->reader.getVal84();
}

bool ObjCMethodDecl::is_overriding(void) const {
  return impl->reader.getVal85();
}

bool ObjCMethodDecl::is_property_accessor(void) const {
  return impl->reader.getVal86();
}

bool ObjCMethodDecl::is_redeclaration(void) const {
  return impl->reader.getVal87();
}

bool ObjCMethodDecl::is_synthesized_accessor_stub(void) const {
  return impl->reader.getVal88();
}

bool ObjCMethodDecl::is_this_declaration_a_definition(void) const {
  return impl->reader.getVal89();
}

bool ObjCMethodDecl::is_this_declaration_a_designated_initializer(void) const {
  return impl->reader.getVal90();
}

bool ObjCMethodDecl::is_variadic(void) const {
  return impl->reader.getVal91();
}

unsigned ObjCMethodDecl::num_parameters(void) const {
  return impl->reader.getVal40().size();
}

std::optional<ParmVarDecl> ObjCMethodDecl::nth_parameter(unsigned n) const {
  auto list = impl->reader.getVal40();
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

gap::generator<ParmVarDecl> ObjCMethodDecl::parameters(void) const & {
  auto list = impl->reader.getVal40();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d40 = ep->DeclFor(ep, v)) {
      if (auto e = ParmVarDecl::from_base(std::move(d40))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned ObjCMethodDecl::num_selector_tokens(void) const {
  return impl->reader.getVal41().size();
}

std::optional<Token> ObjCMethodDecl::nth_selector_token(unsigned n) const {
  auto list = impl->reader.getVal41();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TokenFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Token(std::move(e));
}

gap::generator<Token> ObjCMethodDecl::selector_tokens(void) const & {
  auto list = impl->reader.getVal41();
  EntityProviderPtr ep = impl->ep;
  auto fragment = ep->FragmentFor(ep, impl->fragment_id);
  if (!fragment) {
    assert(false);
    co_return;
  }
  auto tok_reader = fragment->ParsedTokenReader(fragment);
  for (auto v : list) {
    EntityId id(v);
    if (auto t41 = ep->TokenFor(ep, tok_reader, v)) {
      co_yield t41;
    }
  }
  co_return;
}

gap::generator<Decl> ObjCMethodDecl::contained_declarations(void) const & {
  return BuiltinDeclReferences<Decl>(
      impl->ep, id().Pack(), BuiltinReferenceKind::CONTAINS,
      EntityProvider::kReferenceFrom, false  /* redecls */);
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
