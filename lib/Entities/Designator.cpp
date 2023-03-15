// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/Designator.h>

#include <multiplier/Entities/FieldDecl.h>
#include <multiplier/Entities/File.h>
#include <multiplier/Entities/Fragment.h>
#include <multiplier/Entities/Reference.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../File.h"
#include "../Fragment.h"
#include "../Designator.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

std::shared_ptr<EntityProvider> Designator::entity_provider_of(const Index &index_) {
  return index_.impl;
}

std::shared_ptr<EntityProvider> Designator::entity_provider_of(const Fragment &frag_) {
  return frag_.impl->ep;
}

std::shared_ptr<EntityProvider> Designator::entity_provider_of(const File &file_) {
  return file_.impl->ep;
}

std::optional<Designator> Designator::from(const Reference &r) {
  return r.as_designator();
}

std::optional<Designator> Designator::from(const TokenContext &t) {
  return t.as_designator();
}

bool Designator::is_field_designator(void) const {
  return impl->reader.getVal0();
}

bool Designator::is_array_designator(void) const {
  return impl->reader.getVal1();
}

bool Designator::is_array_range_designator(void) const {
  return impl->reader.getVal2();
}

std::optional<FieldDecl> Designator::field(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal3();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FieldDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

TokenRange Designator::tokens(void) const {
  auto &ep = impl->ep;
  auto fragment = ep->FragmentFor(ep, impl->fragment_id);
  return fragment->TokenRangeFor(fragment, impl->reader.getVal4(), impl->reader.getVal5());
}

Token Designator::dot_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal6());
}

Token Designator::field_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal7());
}

Token Designator::left_bracket_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal8());
}

Token Designator::right_bracket_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal9());
}

Token Designator::ellipsis_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal10());
}

std::optional<unsigned> Designator::first_expression_index(void) const {
  if (!impl->reader.getVal12()) {
    return std::nullopt;
  } else {
    return static_cast<unsigned>(impl->reader.getVal11());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
