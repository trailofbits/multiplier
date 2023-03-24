// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCCategoryDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/ObjCCategoryImplDecl.h>
#include <multiplier/Entities/ObjCContainerDecl.h>
#include <multiplier/Entities/ObjCInterfaceDecl.h>
#include <multiplier/Entities/ObjCIvarDecl.h>
#include <multiplier/Entities/ObjCProtocolDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Fragment.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCCategoryDecl> ObjCCategoryDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCCategoryDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCCategoryDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCCategoryDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCCategoryDecl> ObjCCategoryDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCCategoryDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCCategoryDecl> ObjCCategoryDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCCategoryDecl> ObjCCategoryDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCCategoryDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCCategoryDecl> ObjCCategoryDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCCategoryDecl::contains(const Decl &decl) {
  for (auto &parent : ObjCCategoryDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ObjCCategoryDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCCategoryDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<ObjCCategoryDecl> ObjCCategoryDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCCategoryDecl> dr = ObjCCategoryDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ObjCCategoryDecl> ObjCCategoryDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ObjCCategoryDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kObjCCategoryDeclDerivedKinds[] = {
    ObjCCategoryDecl::static_kind(),
};

std::optional<ObjCCategoryDecl> ObjCCategoryDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCCategoryDecl::static_kind():
      return reinterpret_cast<const ObjCCategoryDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCCategoryDecl> ObjCCategoryDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kObjCCategoryDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCCategoryDecl> e = ObjCCategoryDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCCategoryDecl> ObjCCategoryDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCCategoryDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCCategoryDecl> e = ObjCCategoryDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCCategoryDecl> ObjCCategoryDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCCategoryDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCCategoryDecl> e = ObjCCategoryDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCCategoryDecl> ObjCCategoryDecl::from(const Reference &r) {
  return ObjCCategoryDecl::from(r.as_declaration());
}

std::optional<ObjCCategoryDecl> ObjCCategoryDecl::from(const TokenContext &t) {
  return ObjCCategoryDecl::from(t.as_declaration());
}

bool ObjCCategoryDecl::is_class_extension(void) const {
  return impl->reader.getVal72();
}

Token ObjCCategoryDecl::category_name_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal64());
}

ObjCInterfaceDecl ObjCCategoryDecl::class_interface(void) const {
  RawEntityId eid = impl->reader.getVal65();
  return ObjCInterfaceDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

ObjCCategoryImplDecl ObjCCategoryDecl::implementation(void) const {
  RawEntityId eid = impl->reader.getVal66();
  return ObjCCategoryImplDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Token ObjCCategoryDecl::instance_variable_l_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal76());
}

Token ObjCCategoryDecl::instance_variable_r_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal78());
}

ObjCCategoryDecl ObjCCategoryDecl::next_class_category(void) const {
  RawEntityId eid = impl->reader.getVal79();
  return ObjCCategoryDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

unsigned ObjCCategoryDecl::num_instance_variables(void) const {
  return impl->reader.getVal312().size();
}

std::optional<ObjCIvarDecl> ObjCCategoryDecl::nth_instance_variable(unsigned n) const {
  auto list = impl->reader.getVal312();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCIvarDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCIvarDecl> ObjCCategoryDecl::instance_variables(void) const & {
  auto list = impl->reader.getVal312();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d312 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCIvarDecl::from(Decl(std::move(d312)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned ObjCCategoryDecl::num_protocol_tokens(void) const {
  return impl->reader.getVal338().size();
}

std::optional<Token> ObjCCategoryDecl::nth_protocol_token(unsigned n) const {
  auto list = impl->reader.getVal338();
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

gap::generator<Token> ObjCCategoryDecl::protocol_tokens(void) const & {
  auto list = impl->reader.getVal338();
  EntityProvider::Ptr ep = impl->ep;
  auto fragment = ep->FragmentFor(ep, impl->fragment_id);
  if (!fragment) {
    assert(false);
    co_return;
  }
  auto tok_reader = fragment->ParsedTokenReader(fragment);
  for (auto v : list) {
    EntityId id(v);
    if (auto t338 = ep->TokenFor(ep, tok_reader, v)) {
      co_yield t338;
    }
  }
  co_return;
}

unsigned ObjCCategoryDecl::num_protocols(void) const {
  return impl->reader.getVal340().size();
}

std::optional<ObjCProtocolDecl> ObjCCategoryDecl::nth_protocol(unsigned n) const {
  auto list = impl->reader.getVal340();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCProtocolDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCProtocolDecl> ObjCCategoryDecl::protocols(void) const & {
  auto list = impl->reader.getVal340();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d340 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCProtocolDecl::from(Decl(std::move(d340)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
