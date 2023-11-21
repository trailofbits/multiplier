// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ElseIfNotDefinedMacroDirective.h>

#include <multiplier/Entities/ConditionalMacroDirective.h>
#include <multiplier/Entities/Macro.h>
#include <multiplier/Entities/MacroDirective.h>

#include "../EntityProvider.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ElseIfNotDefinedMacroDirective> ElseIfNotDefinedMacroDirective::containing(const Macro &macro) {
  for (auto impl = macro.parent(); impl; impl = impl->parent()) {
    if (auto d = ElseIfNotDefinedMacroDirective::from(*impl)) {
      co_yield *d;
    }
  }
}

bool ElseIfNotDefinedMacroDirective::contains(const Macro &macro) {
  auto id_ = id();
  for (auto &parent : ElseIfNotDefinedMacroDirective::containing(macro)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

bool ElseIfNotDefinedMacroDirective::contains(const Token &token) {
  auto id_ = id();
  for (auto &parent : ElseIfNotDefinedMacroDirective::containing(token)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ElseIfNotDefinedMacroDirective> ElseIfNotDefinedMacroDirective::containing(const Token &token) {
  for (auto m : Macro::containing_internal(token)) {
    if (auto d = ElseIfNotDefinedMacroDirective::from(m)) {
      co_yield *d;
    }
  }
}

std::optional<ElseIfNotDefinedMacroDirective> ElseIfNotDefinedMacroDirective::by_id(const Index &index, EntityId eid) {
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

std::optional<ElseIfNotDefinedMacroDirective> ElseIfNotDefinedMacroDirective::from(const std::optional<Macro> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const MacroKind kElseIfNotDefinedMacroDirectiveDerivedKinds[] = {
    ElseIfNotDefinedMacroDirective::static_kind(),
};

}  // namespace

std::optional<ElseIfNotDefinedMacroDirective> ElseIfNotDefinedMacroDirective::from_base(const Macro &parent) {
  switch (parent.kind()) {
    case ElseIfNotDefinedMacroDirective::static_kind():
      return reinterpret_cast<const ElseIfNotDefinedMacroDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ElseIfNotDefinedMacroDirective> ElseIfNotDefinedMacroDirective::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (MacroKind k : kElseIfNotDefinedMacroDirectiveDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      if (std::optional<ElseIfNotDefinedMacroDirective> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ElseIfNotDefinedMacroDirective> ElseIfNotDefinedMacroDirective::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kElseIfNotDefinedMacroDirectiveDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      if (std::optional<ElseIfNotDefinedMacroDirective> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ElseIfNotDefinedMacroDirective> ElseIfNotDefinedMacroDirective::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (MacroKind k : kElseIfNotDefinedMacroDirectiveDerivedKinds) {
      for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
        if (std::optional<ElseIfNotDefinedMacroDirective> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ElseIfNotDefinedMacroDirective> ElseIfNotDefinedMacroDirective::from(const Reference &r) {
  return ElseIfNotDefinedMacroDirective::from(r.as_macro());
}

std::optional<ElseIfNotDefinedMacroDirective> ElseIfNotDefinedMacroDirective::from(const VariantEntity &e) {
  if (!std::holds_alternative<Macro>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Macro>(e));
}

std::optional<ElseIfNotDefinedMacroDirective> ElseIfNotDefinedMacroDirective::from(const TokenContext &t) {
  if (auto base = t.as_macro()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
