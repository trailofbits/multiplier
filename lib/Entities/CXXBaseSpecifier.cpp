// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXBaseSpecifier.h>

#include <multiplier/Entities/File.h>
#include <multiplier/Entities/Fragment.h>
#include <multiplier/Entities/Reference.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

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

std::shared_ptr<EntityProvider> CXXBaseSpecifier::entity_provider_of(const Index &index_) {
  return index_.impl;
}

std::shared_ptr<EntityProvider> CXXBaseSpecifier::entity_provider_of(const Fragment &frag_) {
  return frag_.impl->ep;
}

std::shared_ptr<EntityProvider> CXXBaseSpecifier::entity_provider_of(const File &file_) {
  return file_.impl->ep;
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
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal1(), impl->reader.getVal2());
}

Token CXXBaseSpecifier::base_type_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal3());
}

bool CXXBaseSpecifier::is_virtual(void) const {
  return impl->reader.getVal4();
}

TagTypeKind CXXBaseSpecifier::base_kind(void) const {
  return static_cast<TagTypeKind>(impl->reader.getVal5());
}

bool CXXBaseSpecifier::is_pack_expansion(void) const {
  return impl->reader.getVal6();
}

bool CXXBaseSpecifier::constructors_are_inherited(void) const {
  return impl->reader.getVal7();
}

Token CXXBaseSpecifier::ellipsis_token(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal8();
    if (eid == kInvalidEntityId) {
      return Token();
    }
    return impl->ep->TokenFor(impl->ep, eid);
  }
  return Token();
}

AccessSpecifier CXXBaseSpecifier::semantic_access_specifier(void) const {
  return static_cast<AccessSpecifier>(impl->reader.getVal9());
}

AccessSpecifier CXXBaseSpecifier::lexical_access_specifier(void) const {
  return static_cast<AccessSpecifier>(impl->reader.getVal10());
}

Type CXXBaseSpecifier::base_type(void) const {
  RawEntityId eid = impl->reader.getVal11();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
