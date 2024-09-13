// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Frontend/ElseIfDefinedMacroDirective.h>
#include <multiplier/Frontend/ConditionalMacroDirective.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/Frontend/Macro.h>
#include <multiplier/Frontend/MacroDirective.h>

#include "../EntityProvider.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const MacroKind kElseIfDefinedMacroDirectiveDerivedKinds[] = {
    ElseIfDefinedMacroDirective::static_kind(),
};
}  // namespace

gap::generator<ElseIfDefinedMacroDirective> ElseIfDefinedMacroDirective::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (MacroKind k : kElseIfDefinedMacroDirectiveDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      if (std::optional<ElseIfDefinedMacroDirective> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ElseIfDefinedMacroDirective> ElseIfDefinedMacroDirective::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (MacroKind k : kElseIfDefinedMacroDirectiveDerivedKinds) {
      for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
        if (std::optional<ElseIfDefinedMacroDirective> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<ElseIfDefinedMacroDirective> ElseIfDefinedMacroDirective::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kElseIfDefinedMacroDirectiveDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      if (std::optional<ElseIfDefinedMacroDirective> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ElseIfDefinedMacroDirective> ElseIfDefinedMacroDirective::containing(const Macro &macro) {
  for (auto impl = macro.parent(); impl; impl = impl->parent()) {
    if (auto d = ElseIfDefinedMacroDirective::from(*impl)) {
      co_yield *d;
    }
  }
}

bool ElseIfDefinedMacroDirective::contains(const Macro &macro) {
  auto id_ = id();
  for (auto &parent : ElseIfDefinedMacroDirective::containing(macro)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

bool ElseIfDefinedMacroDirective::contains(const Token &token) {
  auto id_ = id();
  for (auto &parent : ElseIfDefinedMacroDirective::containing(token)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ElseIfDefinedMacroDirective> ElseIfDefinedMacroDirective::containing(const Token &token) {
  for (auto m : Macro::containing_internal(token)) {
    if (auto d = ElseIfDefinedMacroDirective::from(m)) {
      co_yield *d;
    }
  }
}

std::optional<ElseIfDefinedMacroDirective> ElseIfDefinedMacroDirective::by_id(const Index &index, EntityId eid) {
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

std::optional<ElseIfDefinedMacroDirective> ElseIfDefinedMacroDirective::from(const std::optional<Macro> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ElseIfDefinedMacroDirective> ElseIfDefinedMacroDirective::from_base(const Macro &parent) {
  switch (parent.kind()) {
    case ElseIfDefinedMacroDirective::static_kind():
      return reinterpret_cast<const ElseIfDefinedMacroDirective &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<ElseIfDefinedMacroDirective> ElseIfDefinedMacroDirective::from(const Reference &r) {
  return ElseIfDefinedMacroDirective::from(r.as_macro());
}

std::optional<ElseIfDefinedMacroDirective> ElseIfDefinedMacroDirective::from(const VariantEntity &e) {
  if (!std::holds_alternative<Macro>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Macro>(e));
}

std::optional<ElseIfDefinedMacroDirective> ElseIfDefinedMacroDirective::from(const TokenContext &t) {
  if (auto base = t.as_macro()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
