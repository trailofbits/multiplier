// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXBaseSpecifier.h>
#include "../Reference.h"
#include <multiplier/AST/CXXRecordDecl.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>

#include "../EntityProvider.h"
#include "../File.h"
#include "../Fragment.h"
#include "../CXXBaseSpecifier.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

std::optional<Decl> CXXBaseSpecifier::parent_declaration(void) const {
  if (auto id = impl->reader.getVal0(); id != kInvalidEntityId) {
    if (auto eptr = impl->ep->DeclFor(impl->ep, id)) {
      return Decl(std::move(eptr));
    }
    assert(false);
  }
  return std::nullopt;
}

std::optional<uint64_t> CXXBaseSpecifier::offset_in_bits(void) const {
  if (impl->reader.getVal2()) {
    return impl->reader.getVal1();
  } else {
    return std::nullopt;
  }
}

std::shared_ptr<EntityProvider> CXXBaseSpecifier::entity_provider_of(const Index &index_) {
  return index_.impl;
}

std::shared_ptr<EntityProvider> CXXBaseSpecifier::entity_provider_of(const Fragment &frag_) {
  return frag_.impl->ep;
}

std::shared_ptr<EntityProvider> CXXBaseSpecifier::entity_provider_of(const File &file_) {
  return file_.impl->ep;
}

gap::generator<CXXBaseSpecifier> CXXBaseSpecifier::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (CXXBaseSpecifierImplPtr eptr : ep->CXXBaseSpecifiersFor(ep)) {
    co_yield CXXBaseSpecifier(std::move(eptr));
  }
}

gap::generator<CXXBaseSpecifier> CXXBaseSpecifier::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (CXXBaseSpecifierImplPtr eptr : ep->CXXBaseSpecifiersFor(ep, frag_id)) {
      co_yield CXXBaseSpecifier(std::move(eptr));
    }
  }
}

gap::generator<CXXBaseSpecifier> CXXBaseSpecifier::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (CXXBaseSpecifierImplPtr eptr : ep->CXXBaseSpecifiersFor(ep, frag_id)) {
    co_yield CXXBaseSpecifier(std::move(eptr));
  }
}

gap::generator<CXXBaseSpecifier> CXXBaseSpecifier::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXBaseSpecifier::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXBaseSpecifier::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXBaseSpecifier::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<CXXBaseSpecifier> CXXBaseSpecifier::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<CXXBaseSpecifierId>(vid)) {
    return index.cxx_base_specifier(eid.Pack());
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<CXXBaseSpecifier> CXXBaseSpecifier::from(const Reference &r) {
  return r.as_cxx_base_specifier();
}

std::optional<CXXBaseSpecifier> CXXBaseSpecifier::from(const VariantEntity &e) {
  if (!std::holds_alternative<CXXBaseSpecifier>(e)) {
    return std::nullopt;
  }
  return std::get<CXXBaseSpecifier>(e);
}

std::optional<CXXBaseSpecifier> CXXBaseSpecifier::from(const TokenContext &t) {
  return t.as_cxx_base_specifier();
}

TokenRange CXXBaseSpecifier::tokens(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal4(), impl->reader.getVal5());
}

Token CXXBaseSpecifier::base_type_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal6());
}

Token CXXBaseSpecifier::ellipsis_token(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal7();
    if (eid == kInvalidEntityId) {
      return Token();
    }
    return impl->ep->TokenFor(impl->ep, eid);
  }
  return Token();
}

bool CXXBaseSpecifier::is_virtual(void) const {
  return impl->reader.getVal8();
}

bool CXXBaseSpecifier::is_pack_expansion(void) const {
  return impl->reader.getVal9();
}

bool CXXBaseSpecifier::constructors_are_inherited(void) const {
  return impl->reader.getVal10();
}

TagTypeKind CXXBaseSpecifier::base_kind(void) const {
  return static_cast<TagTypeKind>(impl->reader.getVal11());
}

AccessSpecifier CXXBaseSpecifier::semantic_access_specifier(void) const {
  return static_cast<AccessSpecifier>(impl->reader.getVal12());
}

AccessSpecifier CXXBaseSpecifier::lexical_access_specifier(void) const {
  return static_cast<AccessSpecifier>(impl->reader.getVal13());
}

Type CXXBaseSpecifier::base_type(void) const {
  RawEntityId eid = impl->reader.getVal14();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<CXXRecordDecl> CXXBaseSpecifier::base_class(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal15();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return CXXRecordDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
