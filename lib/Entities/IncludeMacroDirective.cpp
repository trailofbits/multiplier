// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/IncludeMacroDirective.h>

#include <multiplier/Entities/IncludeLikeMacroDirective.h>
#include <multiplier/Entities/Macro.h>
#include <multiplier/Entities/MacroDirective.h>

#include "../EntityProvider.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<IncludeMacroDirective> IncludeMacroDirective::containing(const Macro &macro) {
  for (auto impl = macro.parent(); impl; impl = impl->parent()) {
    if (auto d = IncludeMacroDirective::from(*impl)) {
      co_yield *d;
    }
  }
}

bool IncludeMacroDirective::contains(const Macro &macro) {
  auto id_ = id();
  for (auto &parent : IncludeMacroDirective::containing(macro)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

bool IncludeMacroDirective::contains(const Token &token) {
  auto id_ = id();
  for (auto &parent : IncludeMacroDirective::containing(token)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<IncludeMacroDirective> IncludeMacroDirective::containing(const Token &token) {
  for (auto m : Macro::containing_internal(token)) {
    if (auto d = IncludeMacroDirective::from(m)) {
      co_yield *d;
    }
  }
}

std::optional<IncludeMacroDirective> IncludeMacroDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<MacroId>(vid)) {
    return IncludeMacroDirective::from(index.macro(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const MacroKind kIncludeMacroDirectiveDerivedKinds[] = {
    IncludeMacroDirective::static_kind(),
};

std::optional<IncludeMacroDirective> IncludeMacroDirective::from(const Macro &parent) {
  switch (parent.kind()) {
    case IncludeMacroDirective::static_kind():
      return reinterpret_cast<const IncludeMacroDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<IncludeMacroDirective> IncludeMacroDirective::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (MacroKind k : kIncludeMacroDirectiveDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      if (std::optional<IncludeMacroDirective> e = IncludeMacroDirective::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<IncludeMacroDirective> IncludeMacroDirective::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kIncludeMacroDirectiveDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      if (std::optional<IncludeMacroDirective> e = IncludeMacroDirective::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<IncludeMacroDirective> IncludeMacroDirective::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (MacroKind k : kIncludeMacroDirectiveDerivedKinds) {
      for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
        if (std::optional<IncludeMacroDirective> e = IncludeMacroDirective::from(Macro(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<IncludeMacroDirective> IncludeMacroDirective::from(const Reference &r) {
  return IncludeMacroDirective::from(r.as_macro());
}

std::optional<IncludeMacroDirective> IncludeMacroDirective::from(const TokenContext &t) {
  return IncludeMacroDirective::from(t.as_macro());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
