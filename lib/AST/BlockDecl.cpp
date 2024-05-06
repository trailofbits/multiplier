// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/BlockDecl.h>
#include "../Reference.h"
#include <multiplier/AST/CompoundStmt.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/ParmVarDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kBlockDeclDerivedKinds[] = {
    BlockDecl::static_kind(),
};
}  // namespace

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

std::optional<BlockDecl> BlockDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<BlockDecl, ir::Operation>> BlockDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kBlockDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<BlockDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
    if (*this == parent) { return true; }
  }
  return false;
}

bool BlockDecl::contains(const Stmt &stmt) {
  for (auto &parent : BlockDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

BlockDecl BlockDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (BlockDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<BlockDecl> BlockDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<BlockDecl> BlockDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<BlockDecl> dr = from_base(r)) {
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
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<BlockDecl> BlockDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<BlockDecl> BlockDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case BlockDecl::static_kind():
      return reinterpret_cast<const BlockDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<BlockDecl> BlockDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kBlockDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<BlockDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BlockDecl> BlockDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kBlockDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<BlockDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BlockDecl> BlockDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kBlockDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<BlockDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<BlockDecl> BlockDecl::from(const Reference &r) {
  return BlockDecl::from(r.as_declaration());
}

std::optional<BlockDecl> BlockDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<BlockDecl> BlockDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

bool BlockDecl::block_missing_return_type(void) const {
  return impl->reader.getVal39();
}

bool BlockDecl::can_avoid_copy_to_heap(void) const {
  return impl->reader.getVal42();
}

bool BlockDecl::captures_cxx_this(void) const {
  return impl->reader.getVal43();
}

bool BlockDecl::does_not_escape(void) const {
  return impl->reader.getVal44();
}

std::optional<Decl> BlockDecl::block_mangling_context_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal38();
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
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal45());
}

CompoundStmt BlockDecl::compound_body(void) const {
  RawEntityId eid = impl->reader.getVal46();
  return CompoundStmt::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Type BlockDecl::signature_as_written(void) const {
  RawEntityId eid = impl->reader.getVal47();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool BlockDecl::has_captures(void) const {
  return impl->reader.getVal48();
}

bool BlockDecl::is_conversion_from_lambda(void) const {
  return impl->reader.getVal49();
}

bool BlockDecl::is_variadic(void) const {
  return impl->reader.getVal50();
}

unsigned BlockDecl::num_parameters(void) const {
  return impl->reader.getVal40().size();
}

std::optional<ParmVarDecl> BlockDecl::nth_parameter(unsigned n) const {
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

gap::generator<ParmVarDecl> BlockDecl::parameters(void) const & {
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

unsigned BlockDecl::num_parameter_declarations(void) const {
  return impl->reader.getVal41().size();
}

std::optional<ParmVarDecl> BlockDecl::nth_parameter_declaration(unsigned n) const {
  auto list = impl->reader.getVal41();
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

gap::generator<ParmVarDecl> BlockDecl::parameter_declarations(void) const & {
  auto list = impl->reader.getVal41();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d41 = ep->DeclFor(ep, v)) {
      if (auto e = ParmVarDecl::from_base(std::move(d41))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

gap::generator<Decl> BlockDecl::contained_declarations(void) const & {
  return BuiltinDeclReferences<Decl>(
      impl->ep, id().Pack(), BuiltinReferenceKind::CONTAINS,
      EntityProvider::kReferenceFrom);
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
