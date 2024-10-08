// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Frontend/MacroParameter.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/Frontend/Macro.h>
#include <multiplier/Frontend/Token.h>

#include "../EntityProvider.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const MacroKind kMacroParameterDerivedKinds[] = {
    MacroParameter::static_kind(),
};
}  // namespace

gap::generator<MacroParameter> MacroParameter::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (MacroKind k : kMacroParameterDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      if (std::optional<MacroParameter> e = from_base(std::move(eptr))) {
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
        if (std::optional<MacroParameter> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<MacroParameter> MacroParameter::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kMacroParameterDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      if (std::optional<MacroParameter> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

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
    if (auto base = index.macro(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<MacroParameter> MacroParameter::from(const std::optional<Macro> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<MacroParameter> MacroParameter::from_base(const Macro &parent) {
  switch (parent.kind()) {
    case MacroParameter::static_kind():
      return reinterpret_cast<const MacroParameter &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<MacroParameter> MacroParameter::from(const Reference &r) {
  return MacroParameter::from(r.as_macro());
}

std::optional<MacroParameter> MacroParameter::from(const VariantEntity &e) {
  if (!std::holds_alternative<Macro>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Macro>(e));
}

std::optional<MacroParameter> MacroParameter::from(const TokenContext &t) {
  if (auto base = t.as_macro()) {
    return from_base(base.value());
  }
  return std::nullopt;
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

uint32_t MacroParameter::index(void) const {
  return impl->reader.getVal12();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
