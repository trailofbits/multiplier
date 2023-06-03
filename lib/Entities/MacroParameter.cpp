// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MacroParameter.h>

#include <multiplier/Entities/Macro.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<MacroParameter> MacroParameter::containing(const Macro &macro) {
  for (auto impl = macro.parent(); impl; impl = impl->parent()) {
    if (auto d = MacroParameter::from(*impl)) {
      co_yield *d;
    }
  }
}

bool MacroParameter::contains(const Macro &macro) {
  auto id_ = id();
  for (auto &parent : MacroParameter::containing(macro)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

bool MacroParameter::contains(const Token &token) {
  auto id_ = id();
  for (auto &parent : MacroParameter::containing(token)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<MacroParameter> MacroParameter::containing(const Token &token) {
  for (auto m : Macro::containing_internal(token)) {
    if (auto d = MacroParameter::from(m)) {
      co_yield *d;
    }
  }
}

std::optional<MacroParameter> MacroParameter::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<MacroId>(vid)) {
    return MacroParameter::from(index.macro(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const MacroKind kMacroParameterDerivedKinds[] = {
    MacroParameter::static_kind(),
};

std::optional<MacroParameter> MacroParameter::from(const Macro &parent) {
  switch (parent.kind()) {
    case MacroParameter::static_kind():
      return reinterpret_cast<const MacroParameter &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<MacroParameter> MacroParameter::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (MacroKind k : kMacroParameterDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      if (std::optional<MacroParameter> e = MacroParameter::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MacroParameter> MacroParameter::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kMacroParameterDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      if (std::optional<MacroParameter> e = MacroParameter::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MacroParameter> MacroParameter::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (MacroKind k : kMacroParameterDerivedKinds) {
      for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
        if (std::optional<MacroParameter> e = MacroParameter::from(Macro(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<MacroParameter> MacroParameter::from(const Reference &r) {
  return MacroParameter::from(r.as_macro());
}

std::optional<MacroParameter> MacroParameter::from(const TokenContext &t) {
  return MacroParameter::from(t.as_macro());
}

Token MacroParameter::variadic_dots(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal5();
    if (eid == kInvalidEntityId) {
      return Token();
    }
    return impl->ep->TokenFor(impl->ep, eid);
  }
  return Token();
}

Token MacroParameter::name(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal6();
    if (eid == kInvalidEntityId) {
      return Token();
    }
    return impl->ep->TokenFor(impl->ep, eid);
  }
  return Token();
}

unsigned MacroParameter::index(void) const {
  return impl->reader.getVal11();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
