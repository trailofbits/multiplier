// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MacroVAOptArgument.h>

#include <multiplier/Entities/Macro.h>

#include "../API.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<MacroVAOptArgument> MacroVAOptArgument::containing(const Macro &macro) {
  for (auto impl = macro.parent(); impl; impl = impl->parent()) {
    if (auto d = MacroVAOptArgument::from(*impl)) {
      co_yield *d;
    }
  }
}

bool MacroVAOptArgument::contains(const Macro &macro) {
  auto id_ = id();
  for (auto &parent : MacroVAOptArgument::containing(macro)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

bool MacroVAOptArgument::contains(const Token &token) {
  auto id_ = id();
  for (auto &parent : MacroVAOptArgument::containing(token)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<MacroVAOptArgument> MacroVAOptArgument::containing(const Token &token) {
  for (auto m : Macro::containing_internal(token)) {
    if (auto d = MacroVAOptArgument::from(m)) {
      co_yield *d;
    }
  }
}

std::optional<MacroVAOptArgument> MacroVAOptArgument::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<MacroId>(vid)) {
    return MacroVAOptArgument::from(index.macro(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const MacroKind kMacroVAOptArgumentDerivedKinds[] = {
    MacroVAOptArgument::static_kind(),
};

std::optional<MacroVAOptArgument> MacroVAOptArgument::from(const Macro &parent) {
  switch (parent.kind()) {
    case MacroVAOptArgument::static_kind():
      return reinterpret_cast<const MacroVAOptArgument &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<MacroVAOptArgument> MacroVAOptArgument::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (MacroKind k : kMacroVAOptArgumentDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      if (std::optional<MacroVAOptArgument> e = MacroVAOptArgument::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MacroVAOptArgument> MacroVAOptArgument::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kMacroVAOptArgumentDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      if (std::optional<MacroVAOptArgument> e = MacroVAOptArgument::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MacroVAOptArgument> MacroVAOptArgument::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (MacroKind k : kMacroVAOptArgumentDerivedKinds) {
      for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
        if (std::optional<MacroVAOptArgument> e = MacroVAOptArgument::from(Macro(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
