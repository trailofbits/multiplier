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

std::optional<CXXBaseSpecifier> CXXBaseSpecifier::from(const TokenContext &t) {
  return t.as_cxx_base_specifier();
}

TokenRange CXXBaseSpecifier::tokens(void) const {
  auto &ep = impl->ep;
  auto fragment = ep->FragmentFor(ep, impl->fragment_id);
  return fragment->TokenRangeFor(fragment, impl->reader.getVal0(), impl->reader.getVal1());
}

Token CXXBaseSpecifier::base_type_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal2());
}

bool CXXBaseSpecifier::is_virtual(void) const {
  return impl->reader.getVal3();
}

TagTypeKind CXXBaseSpecifier::base_kind(void) const {
  return static_cast<TagTypeKind>(impl->reader.getVal4());
}

bool CXXBaseSpecifier::is_pack_expansion(void) const {
  return impl->reader.getVal5();
}

bool CXXBaseSpecifier::constructors_are_inherited(void) const {
  return impl->reader.getVal6();
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

AccessSpecifier CXXBaseSpecifier::semantic_access_specifier(void) const {
  return static_cast<AccessSpecifier>(impl->reader.getVal8());
}

AccessSpecifier CXXBaseSpecifier::lexical_access_specifier(void) const {
  return static_cast<AccessSpecifier>(impl->reader.getVal9());
}

Type CXXBaseSpecifier::base_type(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
