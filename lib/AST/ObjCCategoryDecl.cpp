// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCCategoryDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/ObjCCategoryImplDecl.h>
#include <multiplier/AST/ObjCContainerDecl.h>
#include <multiplier/AST/ObjCInterfaceDecl.h>
#include <multiplier/AST/ObjCIvarDecl.h>
#include <multiplier/AST/ObjCProtocolDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Fragment.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kObjCCategoryDeclDerivedKinds[] = {
    ObjCCategoryDecl::static_kind(),
};
}  // namespace

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

std::optional<ObjCCategoryDecl> ObjCCategoryDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<ObjCCategoryDecl, ir::Operation>> ObjCCategoryDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kObjCCategoryDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<ObjCCategoryDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCCategoryDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCCategoryDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ObjCCategoryDecl ObjCCategoryDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ObjCCategoryDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ObjCCategoryDecl> ObjCCategoryDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<ObjCCategoryDecl> ObjCCategoryDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCCategoryDecl> dr = from_base(r)) {
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
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<ObjCCategoryDecl> ObjCCategoryDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ObjCCategoryDecl> ObjCCategoryDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCCategoryDecl::static_kind():
      return reinterpret_cast<const ObjCCategoryDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCCategoryDecl> ObjCCategoryDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kObjCCategoryDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCCategoryDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCCategoryDecl> ObjCCategoryDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCCategoryDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCCategoryDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCCategoryDecl> ObjCCategoryDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCCategoryDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCCategoryDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCCategoryDecl> ObjCCategoryDecl::from(const Reference &r) {
  return ObjCCategoryDecl::from(r.as_declaration());
}

std::optional<ObjCCategoryDecl> ObjCCategoryDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<ObjCCategoryDecl> ObjCCategoryDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

bool ObjCCategoryDecl::is_class_extension(void) const {
  return impl->reader.getVal75();
}

Token ObjCCategoryDecl::category_name_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal66());
}

ObjCInterfaceDecl ObjCCategoryDecl::class_interface(void) const {
  RawEntityId eid = impl->reader.getVal67();
  return ObjCInterfaceDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

ObjCCategoryImplDecl ObjCCategoryDecl::implementation(void) const {
  RawEntityId eid = impl->reader.getVal68();
  return ObjCCategoryImplDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Token ObjCCategoryDecl::instance_variable_l_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal79());
}

Token ObjCCategoryDecl::instance_variable_r_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal80());
}

ObjCCategoryDecl ObjCCategoryDecl::next_class_category(void) const {
  RawEntityId eid = impl->reader.getVal82();
  return ObjCCategoryDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

unsigned ObjCCategoryDecl::num_instance_variables(void) const {
  return impl->reader.getVal316().size();
}

std::optional<ObjCIvarDecl> ObjCCategoryDecl::nth_instance_variable(unsigned n) const {
  auto list = impl->reader.getVal316();
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

gap::generator<ObjCIvarDecl> ObjCCategoryDecl::instance_variables(void) const & {
  auto list = impl->reader.getVal316();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d316 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCIvarDecl::from_base(std::move(d316))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned ObjCCategoryDecl::num_protocol_tokens(void) const {
  return impl->reader.getVal342().size();
}

std::optional<Token> ObjCCategoryDecl::nth_protocol_token(unsigned n) const {
  auto list = impl->reader.getVal342();
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

gap::generator<Token> ObjCCategoryDecl::protocol_tokens(void) const & {
  auto list = impl->reader.getVal342();
  EntityProviderPtr ep = impl->ep;
  auto fragment = ep->FragmentFor(ep, impl->fragment_id);
  if (!fragment) {
    assert(false);
    co_return;
  }
  auto tok_reader = fragment->ParsedTokenReader(fragment);
  for (auto v : list) {
    EntityId id(v);
    if (auto t342 = ep->TokenFor(ep, tok_reader, v)) {
      co_yield t342;
    }
  }
  co_return;
}

unsigned ObjCCategoryDecl::num_protocols(void) const {
  return impl->reader.getVal353().size();
}

std::optional<ObjCProtocolDecl> ObjCCategoryDecl::nth_protocol(unsigned n) const {
  auto list = impl->reader.getVal353();
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

gap::generator<ObjCProtocolDecl> ObjCCategoryDecl::protocols(void) const & {
  auto list = impl->reader.getVal353();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d353 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCProtocolDecl::from_base(std::move(d353))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
