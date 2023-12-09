// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Frontend/MacroExpansion.h>
#include <multiplier/Frontend/DefineMacroDirective.h>
#include <multiplier/Frontend/Macro.h>
#include <multiplier/Frontend/MacroArgument.h>
#include <multiplier/Frontend/MacroSubstitution.h>

#include "../EntityProvider.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const MacroKind kMacroExpansionDerivedKinds[] = {
    MacroExpansion::static_kind(),
};
}  // namespace

gap::generator<MacroExpansion> MacroExpansion::containing(const Macro &macro) {
  for (auto impl = macro.parent(); impl; impl = impl->parent()) {
    if (auto d = MacroExpansion::from(*impl)) {
      co_yield *d;
    }
  }
}

bool MacroExpansion::contains(const Macro &macro) {
  auto id_ = id();
  for (auto &parent : MacroExpansion::containing(macro)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

bool MacroExpansion::contains(const Token &token) {
  auto id_ = id();
  for (auto &parent : MacroExpansion::containing(token)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<MacroExpansion> MacroExpansion::containing(const Token &token) {
  for (auto m : Macro::containing_internal(token)) {
    if (auto d = MacroExpansion::from(m)) {
      co_yield *d;
    }
  }
}

std::optional<MacroExpansion> MacroExpansion::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<MacroId>(vid)) {
    if (auto base = index.macro(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<MacroExpansion> MacroExpansion::from(const std::optional<Macro> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<MacroExpansion> MacroExpansion::from_base(const Macro &parent) {
  switch (parent.kind()) {
    case MacroExpansion::static_kind():
      return reinterpret_cast<const MacroExpansion &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<MacroExpansion> MacroExpansion::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (MacroKind k : kMacroExpansionDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      if (std::optional<MacroExpansion> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MacroExpansion> MacroExpansion::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kMacroExpansionDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      if (std::optional<MacroExpansion> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MacroExpansion> MacroExpansion::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (MacroKind k : kMacroExpansionDerivedKinds) {
      for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
        if (std::optional<MacroExpansion> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<MacroExpansion> MacroExpansion::from(const Reference &r) {
  return MacroExpansion::from(r.as_macro());
}

std::optional<MacroExpansion> MacroExpansion::from(const VariantEntity &e) {
  if (!std::holds_alternative<Macro>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Macro>(e));
}

std::optional<MacroExpansion> MacroExpansion::from(const TokenContext &t) {
  if (auto base = t.as_macro()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

gap::generator<MacroOrToken> MacroExpansion::intermediate_children(void) const & {
  Index index(impl->ep);
  auto list = impl->reader.getVal9();
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

std::optional<DefineMacroDirective> MacroExpansion::definition(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal8();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->MacroFor(impl->ep, eid)) {
      return DefineMacroDirective::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

unsigned MacroExpansion::num_arguments(void) const {
  return impl->reader.getVal10().size();
}

std::optional<MacroArgument> MacroExpansion::nth_argument(unsigned n) const {
  auto list = impl->reader.getVal10();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->MacroFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return MacroArgument::from_base(std::move(e));
}

gap::generator<MacroArgument> MacroExpansion::arguments(void) const & {
  auto list = impl->reader.getVal10();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d10 = ep->MacroFor(ep, v)) {
      if (auto e = MacroArgument::from_base(std::move(d10))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
