// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCInterfaceDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/ObjCCategoryDecl.h>
#include <multiplier/AST/ObjCContainerDecl.h>
#include <multiplier/AST/ObjCImplementationDecl.h>
#include <multiplier/AST/ObjCIvarDecl.h>
#include <multiplier/AST/ObjCProtocolDecl.h>
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
static const DeclKind kObjCInterfaceDeclDerivedKinds[] = {
    ObjCInterfaceDecl::static_kind(),
};
}  // namespace

gap::generator<ObjCInterfaceDecl> ObjCInterfaceDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCInterfaceDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCInterfaceDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCInterfaceDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ObjCInterfaceDecl> ObjCInterfaceDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<ObjCInterfaceDecl, ir::Operation>> ObjCInterfaceDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kObjCInterfaceDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<ObjCInterfaceDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<ObjCInterfaceDecl> ObjCInterfaceDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCInterfaceDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCInterfaceDecl> ObjCInterfaceDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCInterfaceDecl> ObjCInterfaceDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCInterfaceDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCInterfaceDecl> ObjCInterfaceDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCInterfaceDecl::contains(const Decl &decl) {
  for (auto &parent : ObjCInterfaceDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCInterfaceDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCInterfaceDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ObjCInterfaceDecl ObjCInterfaceDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ObjCInterfaceDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ObjCInterfaceDecl> ObjCInterfaceDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<ObjCInterfaceDecl> ObjCInterfaceDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCInterfaceDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ObjCInterfaceDecl> ObjCInterfaceDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<ObjCInterfaceDecl> ObjCInterfaceDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ObjCInterfaceDecl> ObjCInterfaceDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCInterfaceDecl::static_kind():
      return reinterpret_cast<const ObjCInterfaceDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCInterfaceDecl> ObjCInterfaceDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kObjCInterfaceDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCInterfaceDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCInterfaceDecl> ObjCInterfaceDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCInterfaceDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCInterfaceDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCInterfaceDecl> ObjCInterfaceDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCInterfaceDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCInterfaceDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCInterfaceDecl> ObjCInterfaceDecl::from(const Reference &r) {
  return ObjCInterfaceDecl::from(r.as_declaration());
}

std::optional<ObjCInterfaceDecl> ObjCInterfaceDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<ObjCInterfaceDecl> ObjCInterfaceDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

unsigned ObjCInterfaceDecl::num_all_referenced_protocols(void) const {
<<<<<<< HEAD
  return impl->reader.getVal191().size();
}

std::optional<ObjCProtocolDecl> ObjCInterfaceDecl::nth_all_referenced_protocol(unsigned n) const {
  auto list = impl->reader.getVal191();
=======
  return impl->reader.getVal313().size();
}

std::optional<ObjCProtocolDecl> ObjCInterfaceDecl::nth_all_referenced_protocol(unsigned n) const {
  auto list = impl->reader.getVal313();
>>>>>>> 5d49e713d (Intial changes to fix root fragment for function template)
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCProtocolDecl::from_base(std::move(e));
}

gap::generator<ObjCProtocolDecl> ObjCInterfaceDecl::all_referenced_protocols(void) const & {
<<<<<<< HEAD
  auto list = impl->reader.getVal191();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d191 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCProtocolDecl::from_base(std::move(d191))) {
=======
  auto list = impl->reader.getVal313();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d313 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCProtocolDecl::from_base(std::move(d313))) {
>>>>>>> 5d49e713d (Intial changes to fix root fragment for function template)
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

bool ObjCInterfaceDecl::declares_or_inherits_designated_initializers(void) const {
  return impl->reader.getVal74();
}

Token ObjCInterfaceDecl::end_of_definition_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal65());
}

ObjCImplementationDecl ObjCInterfaceDecl::implementation(void) const {
  RawEntityId eid = impl->reader.getVal66();
  return ObjCImplementationDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

std::string_view ObjCInterfaceDecl::obj_c_runtime_name_as_string(void) const {
  capnp::Text::Reader data = impl->reader.getVal73();
  return std::string_view(data.cStr(), data.size());
}

std::optional<ObjCInterfaceDecl> ObjCInterfaceDecl::super_class(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal67();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return ObjCInterfaceDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token ObjCInterfaceDecl::super_class_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal78());
}

std::optional<Type> ObjCInterfaceDecl::super_class_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal79();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

Type ObjCInterfaceDecl::type_for_declaration(void) const {
  RawEntityId eid = impl->reader.getVal81();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool ObjCInterfaceDecl::has_definition(void) const {
  return impl->reader.getVal75();
}

bool ObjCInterfaceDecl::has_designated_initializers(void) const {
  return impl->reader.getVal76();
}

bool ObjCInterfaceDecl::is_arc_weakref_unavailable(void) const {
  return impl->reader.getVal77();
}

bool ObjCInterfaceDecl::is_implicit_interface_declaration(void) const {
  return impl->reader.getVal94();
}

ObjCInterfaceDecl ObjCInterfaceDecl::is_obj_c_requires_property_definitions(void) const {
  RawEntityId eid = impl->reader.getVal82();
  return ObjCInterfaceDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

bool ObjCInterfaceDecl::is_this_declaration_a_definition(void) const {
  return impl->reader.getVal95();
}

unsigned ObjCInterfaceDecl::num_instance_variables(void) const {
<<<<<<< HEAD
  return impl->reader.getVal314().size();
}

std::optional<ObjCIvarDecl> ObjCInterfaceDecl::nth_instance_variable(unsigned n) const {
  auto list = impl->reader.getVal314();
=======
  return impl->reader.getVal339().size();
}

std::optional<ObjCIvarDecl> ObjCInterfaceDecl::nth_instance_variable(unsigned n) const {
  auto list = impl->reader.getVal339();
>>>>>>> 5d49e713d (Intial changes to fix root fragment for function template)
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCIvarDecl::from_base(std::move(e));
}

gap::generator<ObjCIvarDecl> ObjCInterfaceDecl::instance_variables(void) const & {
<<<<<<< HEAD
  auto list = impl->reader.getVal314();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d314 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCIvarDecl::from_base(std::move(d314))) {
=======
  auto list = impl->reader.getVal339();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d339 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCIvarDecl::from_base(std::move(d339))) {
>>>>>>> 5d49e713d (Intial changes to fix root fragment for function template)
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned ObjCInterfaceDecl::num_known_categories(void) const {
<<<<<<< HEAD
  return impl->reader.getVal340().size();
}

std::optional<ObjCCategoryDecl> ObjCInterfaceDecl::nth_known_categorie(unsigned n) const {
  auto list = impl->reader.getVal340();
=======
  return impl->reader.getVal350().size();
}

std::optional<ObjCCategoryDecl> ObjCInterfaceDecl::nth_known_categorie(unsigned n) const {
  auto list = impl->reader.getVal350();
>>>>>>> 5d49e713d (Intial changes to fix root fragment for function template)
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCCategoryDecl::from_base(std::move(e));
}

gap::generator<ObjCCategoryDecl> ObjCInterfaceDecl::known_categories(void) const & {
<<<<<<< HEAD
  auto list = impl->reader.getVal340();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d340 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCCategoryDecl::from_base(std::move(d340))) {
=======
  auto list = impl->reader.getVal350();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d350 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCCategoryDecl::from_base(std::move(d350))) {
>>>>>>> 5d49e713d (Intial changes to fix root fragment for function template)
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned ObjCInterfaceDecl::num_known_extensions(void) const {
  return impl->reader.getVal351().size();
}

std::optional<ObjCCategoryDecl> ObjCInterfaceDecl::nth_known_extension(unsigned n) const {
  auto list = impl->reader.getVal351();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCCategoryDecl::from_base(std::move(e));
}

gap::generator<ObjCCategoryDecl> ObjCInterfaceDecl::known_extensions(void) const & {
  auto list = impl->reader.getVal351();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d351 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCCategoryDecl::from_base(std::move(d351))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned ObjCInterfaceDecl::num_protocol_tokens(void) const {
<<<<<<< HEAD
  return impl->reader.getVal352().size();
}

std::optional<Token> ObjCInterfaceDecl::nth_protocol_token(unsigned n) const {
  auto list = impl->reader.getVal352();
=======
  return impl->reader.getVal358().size();
}

std::optional<Token> ObjCInterfaceDecl::nth_protocol_token(unsigned n) const {
  auto list = impl->reader.getVal358();
>>>>>>> 5d49e713d (Intial changes to fix root fragment for function template)
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

gap::generator<Token> ObjCInterfaceDecl::protocol_tokens(void) const & {
<<<<<<< HEAD
  auto list = impl->reader.getVal352();
=======
  auto list = impl->reader.getVal358();
>>>>>>> 5d49e713d (Intial changes to fix root fragment for function template)
  EntityProviderPtr ep = impl->ep;
  auto fragment = ep->FragmentFor(ep, impl->fragment_id);
  if (!fragment) {
    assert(false);
    co_return;
  }
  auto tok_reader = fragment->ParsedTokenReader(fragment);
  for (auto v : list) {
    EntityId id(v);
<<<<<<< HEAD
    if (auto t352 = ep->TokenFor(ep, tok_reader, v)) {
      co_yield t352;
=======
    if (auto t358 = ep->TokenFor(ep, tok_reader, v)) {
      co_yield t358;
>>>>>>> 5d49e713d (Intial changes to fix root fragment for function template)
    }
  }
  co_return;
}

unsigned ObjCInterfaceDecl::num_protocols(void) const {
<<<<<<< HEAD
  return impl->reader.getVal360().size();
}

std::optional<ObjCProtocolDecl> ObjCInterfaceDecl::nth_protocol(unsigned n) const {
  auto list = impl->reader.getVal360();
=======
  return impl->reader.getVal359().size();
}

std::optional<ObjCProtocolDecl> ObjCInterfaceDecl::nth_protocol(unsigned n) const {
  auto list = impl->reader.getVal359();
>>>>>>> 5d49e713d (Intial changes to fix root fragment for function template)
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCProtocolDecl::from_base(std::move(e));
}

gap::generator<ObjCProtocolDecl> ObjCInterfaceDecl::protocols(void) const & {
<<<<<<< HEAD
  auto list = impl->reader.getVal360();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d360 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCProtocolDecl::from_base(std::move(d360))) {
=======
  auto list = impl->reader.getVal359();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d359 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCProtocolDecl::from_base(std::move(d359))) {
>>>>>>> 5d49e713d (Intial changes to fix root fragment for function template)
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned ObjCInterfaceDecl::num_visible_categories(void) const {
<<<<<<< HEAD
  return impl->reader.getVal361().size();
}

std::optional<ObjCCategoryDecl> ObjCInterfaceDecl::nth_visible_categorie(unsigned n) const {
  auto list = impl->reader.getVal361();
=======
  return impl->reader.getVal360().size();
}

std::optional<ObjCCategoryDecl> ObjCInterfaceDecl::nth_visible_categorie(unsigned n) const {
  auto list = impl->reader.getVal360();
>>>>>>> 5d49e713d (Intial changes to fix root fragment for function template)
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCCategoryDecl::from_base(std::move(e));
}

gap::generator<ObjCCategoryDecl> ObjCInterfaceDecl::visible_categories(void) const & {
<<<<<<< HEAD
  auto list = impl->reader.getVal361();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d361 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCCategoryDecl::from_base(std::move(d361))) {
=======
  auto list = impl->reader.getVal360();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d360 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCCategoryDecl::from_base(std::move(d360))) {
>>>>>>> 5d49e713d (Intial changes to fix root fragment for function template)
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned ObjCInterfaceDecl::num_visible_extensions(void) const {
<<<<<<< HEAD
  return impl->reader.getVal362().size();
}

std::optional<ObjCCategoryDecl> ObjCInterfaceDecl::nth_visible_extension(unsigned n) const {
  auto list = impl->reader.getVal362();
=======
  return impl->reader.getVal361().size();
}

std::optional<ObjCCategoryDecl> ObjCInterfaceDecl::nth_visible_extension(unsigned n) const {
  auto list = impl->reader.getVal361();
>>>>>>> 5d49e713d (Intial changes to fix root fragment for function template)
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCCategoryDecl::from_base(std::move(e));
}

gap::generator<ObjCCategoryDecl> ObjCInterfaceDecl::visible_extensions(void) const & {
<<<<<<< HEAD
  auto list = impl->reader.getVal362();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d362 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCCategoryDecl::from_base(std::move(d362))) {
=======
  auto list = impl->reader.getVal361();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d361 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCCategoryDecl::from_base(std::move(d361))) {
>>>>>>> 5d49e713d (Intial changes to fix root fragment for function template)
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
