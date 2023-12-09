// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Frontend/Macro.h>
#include <multiplier/Reference.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/Frontend/Token.h>

#include "../EntityProvider.h"
#include "../File.h"
#include "../Fragment.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

std::shared_ptr<EntityProvider> Macro::entity_provider_of(const Index &index_) {
  return index_.impl;
}

std::shared_ptr<EntityProvider> Macro::entity_provider_of(const Fragment &frag_) {
  return frag_.impl->ep;
}

std::shared_ptr<EntityProvider> Macro::entity_provider_of(const File &file_) {
  return file_.impl->ep;
}

gap::generator<Macro> Macro::containing(const Macro &macro) {
  for (auto impl = macro.parent(); impl; impl = impl->parent()) {
    if (auto d = Macro::from(*impl)) {
      co_yield *d;
    }
  }
}

bool Macro::contains(const Macro &macro) {
  auto id_ = id();
  for (auto &parent : Macro::containing(macro)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

bool Macro::contains(const Token &token) {
  auto id_ = id();
  for (auto &parent : Macro::containing(token)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<Macro> Macro::containing(const Token &token) {
  for (auto m : Macro::containing_internal(token)) {
    if (auto d = Macro::from(m)) {
      co_yield *d;
    }
  }
}

std::optional<Macro> Macro::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<MacroId>(vid)) {
    index.macro(eid.Pack());
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

gap::generator<Macro> Macro::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (MacroImplPtr eptr : ep->MacrosFor(ep)) {
    co_yield Macro(std::move(eptr));
  }
}

gap::generator<Macro> Macro::in(const Index &index, std::span<const MacroKind> kinds) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (MacroKind k : kinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      co_yield Macro(std::move(eptr));
    }
  }
}

gap::generator<Macro> Macro::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, frag_id)) {
      co_yield Macro(std::move(eptr));
    }
  }
}

gap::generator<Macro> Macro::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroImplPtr eptr : ep->MacrosFor(ep, frag_id)) {
    co_yield Macro(std::move(eptr));
  }
}

gap::generator<Macro> Macro::in(const Fragment &frag, std::span<const MacroKind> kinds) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      co_yield Macro(std::move(eptr));
    }
  }
}

gap::generator<Macro> Macro::in(const File &file, std::span<const MacroKind> kinds) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (MacroKind k : kinds) {
      for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
        co_yield Macro(std::move(eptr));
      }
    }
  }
}

std::optional<Macro> Macro::from(const Reference &r) {
  return r.as_macro();
}

std::optional<Macro> Macro::from(const VariantEntity &e) {
  if (!std::holds_alternative<Macro>(e)) {
    return std::nullopt;
  }
  return std::get<Macro>(e);
}

std::optional<Macro> Macro::from(const TokenContext &t) {
  return t.as_macro();
}

MacroKind Macro::kind(void) const {
  return static_cast<MacroKind>(impl->reader.getVal0());
}

std::optional<Macro> Macro::parent(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal1();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->MacroFor(impl->ep, eid)) {
      return Macro(std::move(eptr));
    }
  }
  return std::nullopt;
}

gap::generator<MacroOrToken> Macro::children(void) const & {
  Index index(impl->ep);
  auto list = impl->reader.getVal2();
  for (auto v : list) {
    VariantEntity e = index.entity(EntityId(v));
    if (std::holds_alternative<Macro>(e)) {
      co_yield std::move(std::get<Macro>(e));
    } else if (std::holds_alternative<Token>(e)) {
      co_yield std::move(std::get<Token>(e));
    } else {
      assert(false);
    }
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
