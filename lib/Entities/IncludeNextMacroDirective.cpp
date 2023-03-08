// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/IncludeNextMacroDirective.h>

#include <multiplier/Entities/IncludeLikeMacroDirective.h>
#include <multiplier/Entities/Macro.h>
#include <multiplier/Entities/MacroDirective.h>

#include "../API.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<IncludeNextMacroDirective> IncludeNextMacroDirective::containing(const Macro &macro) {
  for (auto impl = macro.parent(); impl; impl = impl->parent()) {
    if (auto d = IncludeNextMacroDirective::from(*impl)) {
      co_yield *d;
    }
  }
}

bool IncludeNextMacroDirective::contains(const Macro &macro) {
  auto id_ = id();
  for (auto &parent : IncludeNextMacroDirective::containing(macro)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

bool IncludeNextMacroDirective::contains(const Token &token) {
  auto id_ = id();
  for (auto &parent : IncludeNextMacroDirective::containing(token)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<IncludeNextMacroDirective> IncludeNextMacroDirective::containing(const Token &token) {
  for (auto m : Macro::containing_internal(token)) {
    if (auto d = IncludeNextMacroDirective::from(m)) {
      co_yield *d;
    }
  }
}

std::optional<IncludeNextMacroDirective> IncludeNextMacroDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<MacroId>(vid)) {
    return IncludeNextMacroDirective::from(index.macro(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const MacroKind kIncludeNextMacroDirectiveDerivedKinds[] = {
    IncludeNextMacroDirective::static_kind(),
};

std::optional<IncludeNextMacroDirective> IncludeNextMacroDirective::from(const Macro &parent) {
  switch (parent.kind()) {
    case IncludeNextMacroDirective::static_kind():
      return reinterpret_cast<const IncludeNextMacroDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<IncludeNextMacroDirective> IncludeNextMacroDirective::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (MacroKind k : kIncludeNextMacroDirectiveDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      if (std::optional<IncludeNextMacroDirective> e = IncludeNextMacroDirective::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<IncludeNextMacroDirective> IncludeNextMacroDirective::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kIncludeNextMacroDirectiveDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      if (std::optional<IncludeNextMacroDirective> e = IncludeNextMacroDirective::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<IncludeNextMacroDirective> IncludeNextMacroDirective::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (MacroKind k : kIncludeNextMacroDirectiveDerivedKinds) {
      for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
        if (std::optional<IncludeNextMacroDirective> e = IncludeNextMacroDirective::from(Macro(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<IncludeNextMacroDirective> IncludeNextMacroDirective::from(const Reference &r) {
  return IncludeNextMacroDirective::from(r.as_macro());
}

std::optional<IncludeNextMacroDirective> IncludeNextMacroDirective::from(const TokenContext &t) {
  return IncludeNextMacroDirective::from(t.as_macro());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
