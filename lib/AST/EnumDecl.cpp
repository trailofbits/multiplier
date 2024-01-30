// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/EnumDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/EnumConstantDecl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/TagDecl.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/TypeDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Fragment.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kEnumDeclDerivedKinds[] = {
    EnumDecl::static_kind(),
};
}  // namespace

gap::generator<EnumDecl> EnumDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = EnumDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool EnumDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : EnumDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<EnumDecl> EnumDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<EnumDecl, ir::Operation>> EnumDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kEnumDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<EnumDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<EnumDecl> EnumDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = EnumDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<EnumDecl> EnumDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<EnumDecl> EnumDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = EnumDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<EnumDecl> EnumDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool EnumDecl::contains(const Decl &decl) {
  for (auto &parent : EnumDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool EnumDecl::contains(const Stmt &stmt) {
  for (auto &parent : EnumDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

EnumDecl EnumDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (EnumDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<EnumDecl> EnumDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<EnumDecl> EnumDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<EnumDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<EnumDecl> EnumDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<EnumDecl> EnumDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<EnumDecl> EnumDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case EnumDecl::static_kind():
      return reinterpret_cast<const EnumDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<EnumDecl> EnumDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kEnumDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<EnumDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<EnumDecl> EnumDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kEnumDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<EnumDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<EnumDecl> EnumDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kEnumDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<EnumDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<EnumDecl> EnumDecl::from(const Reference &r) {
  return EnumDecl::from(r.as_declaration());
}

std::optional<EnumDecl> EnumDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<EnumDecl> EnumDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

unsigned EnumDecl::num_enumerators(void) const {
  return impl->reader.getVal62().size();
}

std::optional<EnumConstantDecl> EnumDecl::nth_enumerator(unsigned n) const {
  auto list = impl->reader.getVal62();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return EnumConstantDecl::from_base(std::move(e));
}

gap::generator<EnumConstantDecl> EnumDecl::enumerators(void) const & {
  auto list = impl->reader.getVal62();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d62 = ep->DeclFor(ep, v)) {
      if (auto e = EnumConstantDecl::from_base(std::move(d62))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

std::optional<EnumDecl> EnumDecl::instantiated_from_member_enum(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal79();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return EnumDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<Type> EnumDecl::integer_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal80();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

TokenRange EnumDecl::integer_type_range(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal82(), impl->reader.getVal83());
}

std::optional<uint32_t> EnumDecl::odr_hash(void) const {
  if (!impl->reader.getVal105()) {
    return std::nullopt;
  } else {
    return static_cast<uint32_t>(impl->reader.getVal143());
  }
  return std::nullopt;
}

std::optional<Type> EnumDecl::promotion_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal84();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<EnumDecl> EnumDecl::template_instantiation_pattern(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal85();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return EnumDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

TemplateSpecializationKind EnumDecl::template_specialization_kind(void) const {
  return static_cast<TemplateSpecializationKind>(impl->reader.getVal86());
}

bool EnumDecl::is_closed(void) const {
  return impl->reader.getVal106();
}

bool EnumDecl::is_closed_flag(void) const {
  return impl->reader.getVal107();
}

bool EnumDecl::is_closed_non_flag(void) const {
  return impl->reader.getVal108();
}

bool EnumDecl::is_complete(void) const {
  return impl->reader.getVal109();
}

bool EnumDecl::is_fixed(void) const {
  return impl->reader.getVal110();
}

bool EnumDecl::is_scoped(void) const {
  return impl->reader.getVal111();
}

bool EnumDecl::is_scoped_using_class_tag(void) const {
  return impl->reader.getVal112();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
