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

#include "../EntityProvider.h"
#include "../File.h"
#include "../Fragment.h"
#include "../Designator.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

std::optional<Decl> Designator::parent_declaration(void) const {
  if (auto id = impl->reader.getVal0(); id != kInvalidEntityId) {
    if (auto eptr = impl->ep->DeclFor(impl->ep, id)) {
      return Decl(std::move(eptr));
    }
    assert(false);
  }
  return std::nullopt;
}

std::optional<Stmt> Designator::parent_statement(void) const {
  if (auto id = impl->reader.getVal1(); id != kInvalidEntityId) {
    if (auto eptr = impl->ep->StmtFor(impl->ep, id)) {
      return Stmt(std::move(eptr));
    }
    assert(false);
  }
  return std::nullopt;
}

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

std::optional<Designator> Designator::from(const VariantEntity &e) {
  if (!std::holds_alternative<Designator>(e)) {
    return std::nullopt;
  }
  return std::get<Designator>(e);
}

std::optional<Designator> Designator::from(const TokenContext &t) {
  return t.as_designator();
}

bool Designator::is_field_designator(void) const {
  return impl->reader.getVal2();
}

bool Designator::is_array_designator(void) const {
  return impl->reader.getVal3();
}

bool Designator::is_array_range_designator(void) const {
  return impl->reader.getVal4();
}

std::optional<FieldDecl> Designator::field(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal5();
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
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal6(), impl->reader.getVal7());
}

Token Designator::dot_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal8());
}

Token Designator::field_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal9());
}

Token Designator::left_bracket_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal10());
}

Token Designator::right_bracket_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal11());
}

Token Designator::ellipsis_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal12());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
