// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Frontend/MacroStringify.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/Frontend/Macro.h>
#include <multiplier/Frontend/MacroSubstitution.h>

#include "../EntityProvider.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const MacroKind kMacroStringifyDerivedKinds[] = {
    MacroStringify::static_kind(),
};
}  // namespace

gap::generator<MacroStringify> MacroStringify::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (MacroKind k : kMacroStringifyDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      if (std::optional<MacroStringify> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MacroStringify> MacroStringify::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (MacroKind k : kMacroStringifyDerivedKinds) {
      for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
        if (std::optional<MacroStringify> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<MacroStringify> MacroStringify::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kMacroStringifyDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      if (std::optional<MacroStringify> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MacroStringify> MacroStringify::containing(const Macro &macro) {
  for (auto impl = macro.parent(); impl; impl = impl->parent()) {
    if (auto d = MacroStringify::from(*impl)) {
      co_yield *d;
    }
  }
}

bool MacroStringify::contains(const Macro &macro) {
  auto id_ = id();
  for (auto &parent : MacroStringify::containing(macro)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

bool MacroStringify::contains(const Token &token) {
  auto id_ = id();
  for (auto &parent : MacroStringify::containing(token)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<MacroStringify> MacroStringify::containing(const Token &token) {
  for (auto m : Macro::containing_internal(token)) {
    if (auto d = MacroStringify::from(m)) {
      co_yield *d;
    }
  }
}

std::optional<MacroStringify> MacroStringify::by_id(const Index &index, EntityId eid) {
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

std::optional<MacroStringify> MacroStringify::from(const std::optional<Macro> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<MacroStringify> MacroStringify::from_base(const Macro &parent) {
  switch (parent.kind()) {
    case MacroStringify::static_kind():
      return reinterpret_cast<const MacroStringify &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<MacroStringify> MacroStringify::from(const Reference &r) {
  return MacroStringify::from(r.as_macro());
}

std::optional<MacroStringify> MacroStringify::from(const VariantEntity &e) {
  if (!std::holds_alternative<Macro>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Macro>(e));
}

std::optional<MacroStringify> MacroStringify::from(const TokenContext &t) {
  if (auto base = t.as_macro()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token MacroStringify::stringified_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal8());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
