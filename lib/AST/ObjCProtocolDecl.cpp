// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCProtocolDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/ObjCContainerDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>

#include "../EntityProvider.h"
#include "../Fragment.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCProtocolDecl> ObjCProtocolDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCProtocolDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCProtocolDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCProtocolDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCProtocolDecl> ObjCProtocolDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCProtocolDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCProtocolDecl> ObjCProtocolDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCProtocolDecl> ObjCProtocolDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCProtocolDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCProtocolDecl> ObjCProtocolDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCProtocolDecl::contains(const Decl &decl) {
  for (auto &parent : ObjCProtocolDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCProtocolDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCProtocolDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ObjCProtocolDecl ObjCProtocolDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ObjCProtocolDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ObjCProtocolDecl> ObjCProtocolDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<ObjCProtocolDecl> ObjCProtocolDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCProtocolDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ObjCProtocolDecl> ObjCProtocolDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<ObjCProtocolDecl> ObjCProtocolDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const DeclKind kObjCProtocolDeclDerivedKinds[] = {
    ObjCProtocolDecl::static_kind(),
};

}  // namespace

std::optional<ObjCProtocolDecl> ObjCProtocolDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCProtocolDecl::static_kind():
      return reinterpret_cast<const ObjCProtocolDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCProtocolDecl> ObjCProtocolDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kObjCProtocolDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCProtocolDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCProtocolDecl> ObjCProtocolDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCProtocolDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCProtocolDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCProtocolDecl> ObjCProtocolDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCProtocolDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCProtocolDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCProtocolDecl> ObjCProtocolDecl::from(const Reference &r) {
  return ObjCProtocolDecl::from(r.as_declaration());
}

std::optional<ObjCProtocolDecl> ObjCProtocolDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<ObjCProtocolDecl> ObjCProtocolDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::string_view ObjCProtocolDecl::obj_c_runtime_name_as_string(void) const {
  capnp::Text::Reader data = impl->reader.getVal73();
  return std::string_view(data.cStr(), data.size());
}

bool ObjCProtocolDecl::has_definition(void) const {
  return impl->reader.getVal74();
}

bool ObjCProtocolDecl::is_non_runtime_protocol(void) const {
  return impl->reader.getVal75();
}

bool ObjCProtocolDecl::is_this_declaration_a_definition(void) const {
  return impl->reader.getVal76();
}

unsigned ObjCProtocolDecl::num_protocol_tokens(void) const {
  return impl->reader.getVal315().size();
}

std::optional<Token> ObjCProtocolDecl::nth_protocol_token(unsigned n) const {
  auto list = impl->reader.getVal315();
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

gap::generator<Token> ObjCProtocolDecl::protocol_tokens(void) const & {
  auto list = impl->reader.getVal315();
  EntityProviderPtr ep = impl->ep;
  auto fragment = ep->FragmentFor(ep, impl->fragment_id);
  if (!fragment) {
    assert(false);
    co_return;
  }
  auto tok_reader = fragment->ParsedTokenReader(fragment);
  for (auto v : list) {
    EntityId id(v);
    if (auto t315 = ep->TokenFor(ep, tok_reader, v)) {
      co_yield t315;
    }
  }
  co_return;
}

unsigned ObjCProtocolDecl::num_protocols(void) const {
  return impl->reader.getVal341().size();
}

std::optional<ObjCProtocolDecl> ObjCProtocolDecl::nth_protocol(unsigned n) const {
  auto list = impl->reader.getVal341();
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

gap::generator<ObjCProtocolDecl> ObjCProtocolDecl::protocols(void) const & {
  auto list = impl->reader.getVal341();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d341 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCProtocolDecl::from_base(std::move(d341))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
