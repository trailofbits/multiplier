// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MacroExpansion.h>

#include <multiplier/Entities/DefineMacroDirective.h>
#include <multiplier/Entities/Macro.h>
#include <multiplier/Entities/MacroArgument.h>
#include <multiplier/Entities/MacroSubstitution.h>

#include "../EntityProvider.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

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
    return MacroExpansion::from(index.macro(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const MacroKind kMacroExpansionDerivedKinds[] = {
    MacroExpansion::static_kind(),
};

std::optional<MacroExpansion> MacroExpansion::from(const Macro &parent) {
  switch (parent.kind()) {
    case MacroExpansion::static_kind():
      return reinterpret_cast<const MacroExpansion &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<MacroExpansion> MacroExpansion::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (MacroKind k : kMacroExpansionDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      if (std::optional<MacroExpansion> e = MacroExpansion::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MacroExpansion> MacroExpansion::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kMacroExpansionDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      if (std::optional<MacroExpansion> e = MacroExpansion::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MacroExpansion> MacroExpansion::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (MacroKind k : kMacroExpansionDerivedKinds) {
      for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
        if (std::optional<MacroExpansion> e = MacroExpansion::from(Macro(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<MacroExpansion> MacroExpansion::from(const Reference &r) {
  return MacroExpansion::from(r.as_macro());
}

std::optional<MacroExpansion> MacroExpansion::from(const TokenContext &t) {
  return MacroExpansion::from(t.as_macro());
}

gap::generator<MacroOrToken> MacroExpansion::intermediate_children(void) const & {
  Index index(impl->ep);
  auto list = impl->reader.getVal6();
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
    RawEntityId eid = impl->reader.getVal5();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->MacroFor(impl->ep, eid)) {
      return DefineMacroDirective::from(Macro(std::move(eptr)));
    }
  }
  return std::nullopt;
}

unsigned MacroExpansion::num_arguments(void) const {
  return impl->reader.getVal7().size();
}

std::optional<MacroArgument> MacroExpansion::nth_argument(unsigned n) const {
  auto list = impl->reader.getVal7();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->MacroFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return MacroArgument::from(Macro(std::move(e)));
}

gap::generator<MacroArgument> MacroExpansion::arguments(void) const & {
  auto list = impl->reader.getVal7();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d7 = ep->MacroFor(ep, v)) {
      if (auto e = MacroArgument::from(Macro(std::move(d7)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
