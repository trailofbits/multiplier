// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/Attr.h>
#include <multiplier/Reference.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/Frontend/Token.h>

#include "../EntityProvider.h"
#include "../File.h"
#include "../Fragment.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

std::shared_ptr<EntityProvider> Attr::entity_provider_of(const Index &index_) {
  return index_.impl;
}

std::shared_ptr<EntityProvider> Attr::entity_provider_of(const Fragment &frag_) {
  return frag_.impl->ep;
}

std::shared_ptr<EntityProvider> Attr::entity_provider_of(const File &file_) {
  return file_.impl->ep;
}

gap::generator<Attr> Attr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = Attr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool Attr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : Attr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<Attr> Attr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    index.attribute(eid.Pack());
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

gap::generator<Attr> Attr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrImplPtr eptr : ep->AttrsFor(ep)) {
    co_yield Attr(std::move(eptr));
  }
}

gap::generator<Attr> Attr::in(const Index &index, std::span<const AttrKind> kinds) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      co_yield Attr(std::move(eptr));
    }
  }
}

gap::generator<Attr> Attr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, frag_id)) {
      co_yield Attr(std::move(eptr));
    }
  }
}

gap::generator<Attr> Attr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrImplPtr eptr : ep->AttrsFor(ep, frag_id)) {
    co_yield Attr(std::move(eptr));
  }
}

gap::generator<Attr> Attr::in(const Fragment &frag, std::span<const AttrKind> kinds) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      co_yield Attr(std::move(eptr));
    }
  }
}

gap::generator<Attr> Attr::in(const File &file, std::span<const AttrKind> kinds) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        co_yield Attr(std::move(eptr));
      }
    }
  }
}

std::optional<Attr> Attr::from(const Reference &r) {
  return r.as_attribute();
}

std::optional<Attr> Attr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Attr>(e)) {
    return std::nullopt;
  }
  return std::get<Attr>(e);
}

std::optional<Attr> Attr::from(const TokenContext &t) {
  return t.as_attribute();
}

Token Attr::token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal0());
}

bool Attr::is_implicit(void) const {
  return impl->reader.getVal1();
}

bool Attr::is_inherited(void) const {
  return impl->reader.getVal2();
}

bool Attr::is_late_parsed(void) const {
  return impl->reader.getVal3();
}

bool Attr::is_pack_expansion(void) const {
  return impl->reader.getVal4();
}

AttrKind Attr::kind(void) const {
  return static_cast<AttrKind>(impl->reader.getVal5());
}

TokenRange Attr::tokens(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal6(), impl->reader.getVal7());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
