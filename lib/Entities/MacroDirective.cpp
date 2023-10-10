// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MacroDirective.h>

#include <multiplier/Entities/DefineMacroDirective.h>
#include <multiplier/Entities/ElseIfDefinedMacroDirective.h>
#include <multiplier/Entities/ElseIfMacroDirective.h>
#include <multiplier/Entities/ElseIfNotDefinedMacroDirective.h>
#include <multiplier/Entities/ElseMacroDirective.h>
#include <multiplier/Entities/EndIfMacroDirective.h>
#include <multiplier/Entities/IfDefinedMacroDirective.h>
#include <multiplier/Entities/IfMacroDirective.h>
#include <multiplier/Entities/IfNotDefinedMacroDirective.h>
#include <multiplier/Entities/ImportMacroDirective.h>
#include <multiplier/Entities/IncludeMacroDirective.h>
#include <multiplier/Entities/IncludeMacrosMacroDirective.h>
#include <multiplier/Entities/IncludeNextMacroDirective.h>
#include <multiplier/Entities/Macro.h>
#include <multiplier/Entities/OtherMacroDirective.h>
#include <multiplier/Entities/PragmaMacroDirective.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/UndefineMacroDirective.h>

#include "../EntityProvider.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<MacroDirective> MacroDirective::containing(const Macro &macro) {
  for (auto impl = macro.parent(); impl; impl = impl->parent()) {
    if (auto d = MacroDirective::from(*impl)) {
      co_yield *d;
    }
  }
}

bool MacroDirective::contains(const Macro &macro) {
  auto id_ = id();
  for (auto &parent : MacroDirective::containing(macro)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

bool MacroDirective::contains(const Token &token) {
  auto id_ = id();
  for (auto &parent : MacroDirective::containing(token)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<MacroDirective> MacroDirective::containing(const Token &token) {
  for (auto m : Macro::containing_internal(token)) {
    if (auto d = MacroDirective::from(m)) {
      co_yield *d;
    }
  }
}

std::optional<MacroDirective> MacroDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<MacroId>(vid)) {
    return MacroDirective::from(index.macro(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const MacroKind kMacroDirectiveDerivedKinds[] = {
    OtherMacroDirective::static_kind(),
    UndefineMacroDirective::static_kind(),
    PragmaMacroDirective::static_kind(),
    DefineMacroDirective::static_kind(),
    IncludeMacroDirective::static_kind(),
    IncludeNextMacroDirective::static_kind(),
    IncludeMacrosMacroDirective::static_kind(),
    ImportMacroDirective::static_kind(),
    IfMacroDirective::static_kind(),
    IfDefinedMacroDirective::static_kind(),
    IfNotDefinedMacroDirective::static_kind(),
    ElseIfMacroDirective::static_kind(),
    ElseIfDefinedMacroDirective::static_kind(),
    ElseIfNotDefinedMacroDirective::static_kind(),
    ElseMacroDirective::static_kind(),
    EndIfMacroDirective::static_kind(),
};

std::optional<MacroDirective> MacroDirective::from(const Macro &parent) {
  switch (parent.kind()) {
    case OtherMacroDirective::static_kind():
    case UndefineMacroDirective::static_kind():
    case PragmaMacroDirective::static_kind():
    case DefineMacroDirective::static_kind():
    case IncludeMacroDirective::static_kind():
    case IncludeNextMacroDirective::static_kind():
    case IncludeMacrosMacroDirective::static_kind():
    case ImportMacroDirective::static_kind():
    case IfMacroDirective::static_kind():
    case IfDefinedMacroDirective::static_kind():
    case IfNotDefinedMacroDirective::static_kind():
    case ElseIfMacroDirective::static_kind():
    case ElseIfDefinedMacroDirective::static_kind():
    case ElseIfNotDefinedMacroDirective::static_kind():
    case ElseMacroDirective::static_kind():
    case EndIfMacroDirective::static_kind():
      return reinterpret_cast<const MacroDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<MacroDirective> MacroDirective::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (MacroKind k : kMacroDirectiveDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      if (std::optional<MacroDirective> e = MacroDirective::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MacroDirective> MacroDirective::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kMacroDirectiveDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      if (std::optional<MacroDirective> e = MacroDirective::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MacroDirective> MacroDirective::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (MacroKind k : kMacroDirectiveDerivedKinds) {
      for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
        if (std::optional<MacroDirective> e = MacroDirective::from(Macro(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<MacroDirective> MacroDirective::from(const Reference &r) {
  return MacroDirective::from(r.as_macro());
}

std::optional<MacroDirective> MacroDirective::from(const TokenContext &t) {
  return MacroDirective::from(t.as_macro());
}

Token MacroDirective::hash(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal5());
}

Token MacroDirective::directive_name(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal6();
    if (eid == kInvalidEntityId) {
      return Token();
    }
    return impl->ep->TokenFor(impl->ep, eid);
  }
  return Token();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
