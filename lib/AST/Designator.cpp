// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/Designator.h>
#include "../Reference.h"
#include <multiplier/AST/FieldDecl.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/Frontend/Token.h>

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

gap::generator<Designator> Designator::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DesignatorImplPtr eptr : ep->DesignatorsFor(ep)) {
    co_yield Designator(std::move(eptr));
  }
}

gap::generator<Designator> Designator::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DesignatorImplPtr eptr : ep->DesignatorsFor(ep, frag_id)) {
      co_yield Designator(std::move(eptr));
    }
  }
}

gap::generator<Designator> Designator::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DesignatorImplPtr eptr : ep->DesignatorsFor(ep, frag_id)) {
    co_yield Designator(std::move(eptr));
  }
}

gap::generator<Designator> Designator::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = Designator::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool Designator::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : Designator::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<Designator> Designator::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DesignatorId>(vid)) {
    return index.designator(eid.Pack());
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
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
      return FieldDecl::from_base(std::move(eptr));
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
