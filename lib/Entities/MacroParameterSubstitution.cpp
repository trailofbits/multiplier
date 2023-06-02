// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MacroParameterSubstitution.h>

#include <multiplier/Entities/Macro.h>
#include <multiplier/Entities/MacroParameter.h>
#include <multiplier/Entities/MacroSubstitution.h>

#include "../EntityProvider.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<MacroParameterSubstitution> MacroParameterSubstitution::containing(const Macro &macro) {
  for (auto impl = macro.parent(); impl; impl = impl->parent()) {
    if (auto d = MacroParameterSubstitution::from(*impl)) {
      co_yield *d;
    }
  }
}

bool MacroParameterSubstitution::contains(const Macro &macro) {
  auto id_ = id();
  for (auto &parent : MacroParameterSubstitution::containing(macro)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

bool MacroParameterSubstitution::contains(const Token &token) {
  auto id_ = id();
  for (auto &parent : MacroParameterSubstitution::containing(token)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<MacroParameterSubstitution> MacroParameterSubstitution::containing(const Token &token) {
  for (auto m : Macro::containing_internal(token)) {
    if (auto d = MacroParameterSubstitution::from(m)) {
      co_yield *d;
    }
  }
}

std::optional<MacroParameterSubstitution> MacroParameterSubstitution::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<MacroId>(vid)) {
    return MacroParameterSubstitution::from(index.macro(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const MacroKind kMacroParameterSubstitutionDerivedKinds[] = {
    MacroParameterSubstitution::static_kind(),
};

std::optional<MacroParameterSubstitution> MacroParameterSubstitution::from(const Macro &parent) {
  switch (parent.kind()) {
    case MacroParameterSubstitution::static_kind():
      return reinterpret_cast<const MacroParameterSubstitution &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<MacroParameterSubstitution> MacroParameterSubstitution::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (MacroKind k : kMacroParameterSubstitutionDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      if (std::optional<MacroParameterSubstitution> e = MacroParameterSubstitution::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MacroParameterSubstitution> MacroParameterSubstitution::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kMacroParameterSubstitutionDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      if (std::optional<MacroParameterSubstitution> e = MacroParameterSubstitution::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MacroParameterSubstitution> MacroParameterSubstitution::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (MacroKind k : kMacroParameterSubstitutionDerivedKinds) {
      for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
        if (std::optional<MacroParameterSubstitution> e = MacroParameterSubstitution::from(Macro(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<MacroParameterSubstitution> MacroParameterSubstitution::from(const Reference &r) {
  return MacroParameterSubstitution::from(r.as_macro());
}

std::optional<MacroParameterSubstitution> MacroParameterSubstitution::from(const TokenContext &t) {
  return MacroParameterSubstitution::from(t.as_macro());
}

MacroParameter MacroParameterSubstitution::parameter(void) const {
  RawEntityId eid = impl->reader.getVal9();
  return MacroParameter::from(Macro(impl->ep->MacroFor(impl->ep, eid))).value();
}

Token MacroParameterSubstitution::parameter_use(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal12());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
