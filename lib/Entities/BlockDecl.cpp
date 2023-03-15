// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/BlockDecl.h>

#include <multiplier/Entities/CompoundStmt.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/ParmVarDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<BlockDecl> BlockDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = BlockDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool BlockDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : BlockDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<BlockDecl> BlockDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = BlockDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<BlockDecl> BlockDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<BlockDecl> BlockDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = BlockDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<BlockDecl> BlockDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool BlockDecl::contains(const Decl &decl) {
  for (auto &parent : BlockDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool BlockDecl::contains(const Stmt &stmt) {
  for (auto &parent : BlockDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<BlockDecl> BlockDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<BlockDecl> dr = BlockDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<BlockDecl> BlockDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return BlockDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kBlockDeclDerivedKinds[] = {
    BlockDecl::static_kind(),
};

std::optional<BlockDecl> BlockDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case BlockDecl::static_kind():
      return reinterpret_cast<const BlockDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<BlockDecl> BlockDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kBlockDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<BlockDecl> e = BlockDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BlockDecl> BlockDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kBlockDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<BlockDecl> e = BlockDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BlockDecl> BlockDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kBlockDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<BlockDecl> e = BlockDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<BlockDecl> BlockDecl::from(const Reference &r) {
  return BlockDecl::from(r.as_declaration());
}

std::optional<BlockDecl> BlockDecl::from(const TokenContext &t) {
  return BlockDecl::from(t.as_declaration());
}

bool BlockDecl::block_missing_return_type(void) const {
  return impl->reader.getVal46();
}

bool BlockDecl::can_avoid_copy_to_heap(void) const {
  return impl->reader.getVal49();
}

bool BlockDecl::captures_cxx_this(void) const {
  return impl->reader.getVal50();
}

bool BlockDecl::does_not_escape(void) const {
  return impl->reader.getVal51();
}

std::optional<Decl> BlockDecl::block_mangling_context_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal45();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return Decl(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token BlockDecl::caret_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal52());
}

CompoundStmt BlockDecl::compound_body(void) const {
  RawEntityId eid = impl->reader.getVal53();
  return CompoundStmt::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Type BlockDecl::signature_as_written(void) const {
  RawEntityId eid = impl->reader.getVal54();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool BlockDecl::has_captures(void) const {
  return impl->reader.getVal55();
}

bool BlockDecl::is_conversion_from_lambda(void) const {
  return impl->reader.getVal56();
}

bool BlockDecl::is_variadic(void) const {
  return impl->reader.getVal57();
}

unsigned BlockDecl::num_parameters(void) const {
  return impl->reader.getVal47().size();
}

std::optional<ParmVarDecl> BlockDecl::nth_parameter(unsigned n) const {
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

gap::generator<ParmVarDecl> BlockDecl::parameters(void) const & {
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

unsigned BlockDecl::num_parameter_declarations(void) const {
  return impl->reader.getVal48().size();
}

std::optional<ParmVarDecl> BlockDecl::nth_parameter_declaration(unsigned n) const {
  auto list = impl->reader.getVal48();
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

gap::generator<ParmVarDecl> BlockDecl::parameter_declarations(void) const & {
  auto list = impl->reader.getVal48();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d48 = ep->DeclFor(ep, v)) {
      if (auto e = ParmVarDecl::from(Decl(std::move(d48)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

gap::generator<Decl> BlockDecl::declarations_in_context(void) const & {
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
