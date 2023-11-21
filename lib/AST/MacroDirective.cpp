// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/MacroDirective.h>

#include <multiplier/AST/DefineMacroDirective.h>
#include <multiplier/AST/ElseIfDefinedMacroDirective.h>
#include <multiplier/AST/ElseIfMacroDirective.h>
#include <multiplier/AST/ElseIfNotDefinedMacroDirective.h>
#include <multiplier/AST/ElseMacroDirective.h>
#include <multiplier/AST/EndIfMacroDirective.h>
#include <multiplier/AST/IfDefinedMacroDirective.h>
#include <multiplier/AST/IfMacroDirective.h>
#include <multiplier/AST/IfNotDefinedMacroDirective.h>
#include <multiplier/AST/ImportMacroDirective.h>
#include <multiplier/AST/IncludeMacroDirective.h>
#include <multiplier/AST/IncludeMacrosMacroDirective.h>
#include <multiplier/AST/IncludeNextMacroDirective.h>
#include <multiplier/AST/Macro.h>
#include <multiplier/AST/OtherMacroDirective.h>
#include <multiplier/AST/PragmaMacroDirective.h>
#include <multiplier/AST/Token.h>
#include <multiplier/AST/UndefineMacroDirective.h>

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
    if (auto base = index.macro(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<MacroDirective> MacroDirective::from(const std::optional<Macro> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
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

}  // namespace

std::optional<MacroDirective> MacroDirective::from_base(const Macro &parent) {
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
      if (std::optional<MacroDirective> e = from_base(std::move(eptr))) {
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
      if (std::optional<MacroDirective> e = from_base(std::move(eptr))) {
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
        if (std::optional<MacroDirective> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<MacroDirective> MacroDirective::from(const Reference &r) {
  return MacroDirective::from(r.as_macro());
}

std::optional<MacroDirective> MacroDirective::from(const VariantEntity &e) {
  if (!std::holds_alternative<Macro>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Macro>(e));
}

std::optional<MacroDirective> MacroDirective::from(const TokenContext &t) {
  if (auto base = t.as_macro()) {
    return from_base(base.value());
  }
  return std::nullopt;
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
