// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MacroVAOpt.h>

#include <multiplier/Entities/Macro.h>

#include "../EntityProvider.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<MacroVAOpt> MacroVAOpt::containing(const Macro &macro) {
  for (auto impl = macro.parent(); impl; impl = impl->parent()) {
    if (auto d = MacroVAOpt::from(*impl)) {
      co_yield *d;
    }
  }
}

bool MacroVAOpt::contains(const Macro &macro) {
  auto id_ = id();
  for (auto &parent : MacroVAOpt::containing(macro)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

bool MacroVAOpt::contains(const Token &token) {
  auto id_ = id();
  for (auto &parent : MacroVAOpt::containing(token)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<MacroVAOpt> MacroVAOpt::containing(const Token &token) {
  for (auto m : Macro::containing_internal(token)) {
    if (auto d = MacroVAOpt::from(m)) {
      co_yield *d;
    }
  }
}

std::optional<MacroVAOpt> MacroVAOpt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<MacroId>(vid)) {
    return MacroVAOpt::from(index.macro(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const MacroKind kMacroVAOptDerivedKinds[] = {
    MacroVAOpt::static_kind(),
};

std::optional<MacroVAOpt> MacroVAOpt::from(const Macro &parent) {
  switch (parent.kind()) {
    case MacroVAOpt::static_kind():
      return reinterpret_cast<const MacroVAOpt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<MacroVAOpt> MacroVAOpt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (MacroKind k : kMacroVAOptDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      if (std::optional<MacroVAOpt> e = MacroVAOpt::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MacroVAOpt> MacroVAOpt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kMacroVAOptDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      if (std::optional<MacroVAOpt> e = MacroVAOpt::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MacroVAOpt> MacroVAOpt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (MacroKind k : kMacroVAOptDerivedKinds) {
      for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
        if (std::optional<MacroVAOpt> e = MacroVAOpt::from(Macro(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<MacroVAOpt> MacroVAOpt::from(const Reference &r) {
  return MacroVAOpt::from(r.as_macro());
}

std::optional<MacroVAOpt> MacroVAOpt::from(const TokenContext &t) {
  return MacroVAOpt::from(t.as_macro());
}

bool MacroVAOpt::contents_are_elided(void) const {
  return impl->reader.getVal3();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
