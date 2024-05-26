// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXCtorInitializer.h>
#include "../Reference.h"
#include <multiplier/AST/FieldDecl.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/IndirectFieldDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>

#include "../EntityProvider.h"
#include "../File.h"
#include "../Fragment.h"
#include "../CXXCtorInitializer.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

std::optional<Decl> CXXCtorInitializer::parent_declaration(void) const {
  if (auto id = impl->reader.getVal0(); id != kInvalidEntityId) {
    if (auto eptr = impl->ep->DeclFor(impl->ep, id)) {
      return Decl(std::move(eptr));
    }
    assert(false);
  }
  return std::nullopt;
}

std::shared_ptr<EntityProvider> CXXCtorInitializer::entity_provider_of(const Index &index_) {
  return index_.impl;
}

std::shared_ptr<EntityProvider> CXXCtorInitializer::entity_provider_of(const Fragment &frag_) {
  return frag_.impl->ep;
}

std::shared_ptr<EntityProvider> CXXCtorInitializer::entity_provider_of(const File &file_) {
  return file_.impl->ep;
}

gap::generator<CXXCtorInitializer> CXXCtorInitializer::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (CXXCtorInitializerImplPtr eptr : ep->CXXCtorInitializersFor(ep)) {
    co_yield CXXCtorInitializer(std::move(eptr));
  }
}

gap::generator<CXXCtorInitializer> CXXCtorInitializer::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (CXXCtorInitializerImplPtr eptr : ep->CXXCtorInitializersFor(ep, frag_id)) {
      co_yield CXXCtorInitializer(std::move(eptr));
    }
  }
}

gap::generator<CXXCtorInitializer> CXXCtorInitializer::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (CXXCtorInitializerImplPtr eptr : ep->CXXCtorInitializersFor(ep, frag_id)) {
    co_yield CXXCtorInitializer(std::move(eptr));
  }
}

gap::generator<CXXCtorInitializer> CXXCtorInitializer::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXCtorInitializer::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXCtorInitializer::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXCtorInitializer::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<CXXCtorInitializer> CXXCtorInitializer::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<CXXCtorInitializerId>(vid)) {
    return index.cxx_ctor_initializer(eid.Pack());
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<CXXCtorInitializer> CXXCtorInitializer::from(const Reference &r) {
  return r.as_cxx_ctor_initializer();
}

std::optional<CXXCtorInitializer> CXXCtorInitializer::from(const VariantEntity &e) {
  if (!std::holds_alternative<CXXCtorInitializer>(e)) {
    return std::nullopt;
  }
  return std::get<CXXCtorInitializer>(e);
}

std::optional<CXXCtorInitializer> CXXCtorInitializer::from(const TokenContext &t) {
  return t.as_cxx_ctor_initializer();
}

bool CXXCtorInitializer::is_base_initializer(void) const {
  return impl->reader.getVal1();
}

bool CXXCtorInitializer::is_member_initializer(void) const {
  return impl->reader.getVal2();
}

bool CXXCtorInitializer::is_any_member_initializer(void) const {
  return impl->reader.getVal3();
}

bool CXXCtorInitializer::is_indirect_member_initializer(void) const {
  return impl->reader.getVal4();
}

bool CXXCtorInitializer::is_in_class_member_initializer(void) const {
  return impl->reader.getVal5();
}

bool CXXCtorInitializer::is_delegating_initializer(void) const {
  return impl->reader.getVal6();
}

bool CXXCtorInitializer::is_pack_expansion(void) const {
  return impl->reader.getVal7();
}

std::optional<bool> CXXCtorInitializer::is_base_virtual(void) const {
  if (!impl->reader.getVal9()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal8());
  }
  return std::nullopt;
}

std::optional<FieldDecl> CXXCtorInitializer::member(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal10();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FieldDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<FieldDecl> CXXCtorInitializer::any_member(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal11();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FieldDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<IndirectFieldDecl> CXXCtorInitializer::indirect_member(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal12();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return IndirectFieldDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<Stmt> CXXCtorInitializer::initializer(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal13();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Stmt(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token CXXCtorInitializer::ellipsis_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal14());
}

Token CXXCtorInitializer::member_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal15());
}

Token CXXCtorInitializer::left_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal16());
}

Token CXXCtorInitializer::right_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal17());
}

TokenRange CXXCtorInitializer::tokens(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal18(), impl->reader.getVal19());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
