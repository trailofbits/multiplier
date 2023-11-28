// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Frontend/IfNotDefinedMacroDirective.h>
#include <multiplier/Frontend/ConditionalMacroDirective.h>
#include <multiplier/Frontend/Macro.h>
#include <multiplier/Frontend/MacroDirective.h>

#include "../EntityProvider.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<IfNotDefinedMacroDirective> IfNotDefinedMacroDirective::containing(const Macro &macro) {
  for (auto impl = macro.parent(); impl; impl = impl->parent()) {
    if (auto d = IfNotDefinedMacroDirective::from(*impl)) {
      co_yield *d;
    }
  }
}

bool IfNotDefinedMacroDirective::contains(const Macro &macro) {
  auto id_ = id();
  for (auto &parent : IfNotDefinedMacroDirective::containing(macro)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

bool IfNotDefinedMacroDirective::contains(const Token &token) {
  auto id_ = id();
  for (auto &parent : IfNotDefinedMacroDirective::containing(token)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<IfNotDefinedMacroDirective> IfNotDefinedMacroDirective::containing(const Token &token) {
  for (auto m : Macro::containing_internal(token)) {
    if (auto d = IfNotDefinedMacroDirective::from(m)) {
      co_yield *d;
    }
  }
}

std::optional<IfNotDefinedMacroDirective> IfNotDefinedMacroDirective::by_id(const Index &index, EntityId eid) {
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

std::optional<IfNotDefinedMacroDirective> IfNotDefinedMacroDirective::from(const std::optional<Macro> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const MacroKind kIfNotDefinedMacroDirectiveDerivedKinds[] = {
    IfNotDefinedMacroDirective::static_kind(),
};

}  // namespace

std::optional<IfNotDefinedMacroDirective> IfNotDefinedMacroDirective::from_base(const Macro &parent) {
  switch (parent.kind()) {
    case IfNotDefinedMacroDirective::static_kind():
      return reinterpret_cast<const IfNotDefinedMacroDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<IfNotDefinedMacroDirective> IfNotDefinedMacroDirective::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (MacroKind k : kIfNotDefinedMacroDirectiveDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      if (std::optional<IfNotDefinedMacroDirective> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<IfNotDefinedMacroDirective> IfNotDefinedMacroDirective::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kIfNotDefinedMacroDirectiveDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      if (std::optional<IfNotDefinedMacroDirective> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<IfNotDefinedMacroDirective> IfNotDefinedMacroDirective::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (MacroKind k : kIfNotDefinedMacroDirectiveDerivedKinds) {
      for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
        if (std::optional<IfNotDefinedMacroDirective> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<IfNotDefinedMacroDirective> IfNotDefinedMacroDirective::from(const Reference &r) {
  return IfNotDefinedMacroDirective::from(r.as_macro());
}

std::optional<IfNotDefinedMacroDirective> IfNotDefinedMacroDirective::from(const VariantEntity &e) {
  if (!std::holds_alternative<Macro>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Macro>(e));
}

std::optional<IfNotDefinedMacroDirective> IfNotDefinedMacroDirective::from(const TokenContext &t) {
  if (auto base = t.as_macro()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
