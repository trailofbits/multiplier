// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/IfMacroDirective.h>

#include <multiplier/Entities/ConditionalMacroDirective.h>
#include <multiplier/Entities/Macro.h>
#include <multiplier/Entities/MacroDirective.h>

#include "../EntityProvider.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<IfMacroDirective> IfMacroDirective::containing(const Macro &macro) {
  for (auto impl = macro.parent(); impl; impl = impl->parent()) {
    if (auto d = IfMacroDirective::from(*impl)) {
      co_yield *d;
    }
  }
}

bool IfMacroDirective::contains(const Macro &macro) {
  auto id_ = id();
  for (auto &parent : IfMacroDirective::containing(macro)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

bool IfMacroDirective::contains(const Token &token) {
  auto id_ = id();
  for (auto &parent : IfMacroDirective::containing(token)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<IfMacroDirective> IfMacroDirective::containing(const Token &token) {
  for (auto m : Macro::containing_internal(token)) {
    if (auto d = IfMacroDirective::from(m)) {
      co_yield *d;
    }
  }
}

std::optional<IfMacroDirective> IfMacroDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<MacroId>(vid)) {
    return IfMacroDirective::from(index.macro(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const MacroKind kIfMacroDirectiveDerivedKinds[] = {
    IfMacroDirective::static_kind(),
};

std::optional<IfMacroDirective> IfMacroDirective::from(const Macro &parent) {
  switch (parent.kind()) {
    case IfMacroDirective::static_kind():
      return reinterpret_cast<const IfMacroDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<IfMacroDirective> IfMacroDirective::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (MacroKind k : kIfMacroDirectiveDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      if (std::optional<IfMacroDirective> e = IfMacroDirective::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<IfMacroDirective> IfMacroDirective::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kIfMacroDirectiveDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      if (std::optional<IfMacroDirective> e = IfMacroDirective::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<IfMacroDirective> IfMacroDirective::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (MacroKind k : kIfMacroDirectiveDerivedKinds) {
      for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
        if (std::optional<IfMacroDirective> e = IfMacroDirective::from(Macro(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<IfMacroDirective> IfMacroDirective::from(const Reference &r) {
  return IfMacroDirective::from(r.as_macro());
}

std::optional<IfMacroDirective> IfMacroDirective::from(const TokenContext &t) {
  return IfMacroDirective::from(t.as_macro());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
