// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MacroSubstitution.h>

#include <multiplier/Entities/Macro.h>
#include <multiplier/Entities/MacroConcatenate.h>
#include <multiplier/Entities/MacroExpansion.h>
#include <multiplier/Entities/MacroParameterSubstitution.h>
#include <multiplier/Entities/MacroStringify.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<MacroSubstitution> MacroSubstitution::containing(const Macro &macro) {
  for (auto impl = macro.parent(); impl; impl = impl->parent()) {
    if (auto d = MacroSubstitution::from(*impl)) {
      co_yield *d;
    }
  }
}

bool MacroSubstitution::contains(const Macro &macro) {
  auto id_ = id();
  for (auto &parent : MacroSubstitution::containing(macro)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

bool MacroSubstitution::contains(const Token &token) {
  auto id_ = id();
  for (auto &parent : MacroSubstitution::containing(token)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<MacroSubstitution> MacroSubstitution::containing(const Token &token) {
  for (auto m : Macro::containing_internal(token)) {
    if (auto d = MacroSubstitution::from(m)) {
      co_yield *d;
    }
  }
}

std::optional<MacroSubstitution> MacroSubstitution::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<MacroId>(vid)) {
    return MacroSubstitution::from(index.macro(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const MacroKind kMacroSubstitutionDerivedKinds[] = {
    MacroSubstitution::static_kind(),
    MacroParameterSubstitution::static_kind(),
    MacroExpansion::static_kind(),
    MacroStringify::static_kind(),
    MacroConcatenate::static_kind(),
};

std::optional<MacroSubstitution> MacroSubstitution::from(const Macro &parent) {
  switch (parent.kind()) {
    case MacroSubstitution::static_kind():
    case MacroParameterSubstitution::static_kind():
    case MacroExpansion::static_kind():
    case MacroStringify::static_kind():
    case MacroConcatenate::static_kind():
      return reinterpret_cast<const MacroSubstitution &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<MacroSubstitution> MacroSubstitution::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (MacroKind k : kMacroSubstitutionDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      if (std::optional<MacroSubstitution> e = MacroSubstitution::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MacroSubstitution> MacroSubstitution::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kMacroSubstitutionDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      if (std::optional<MacroSubstitution> e = MacroSubstitution::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MacroSubstitution> MacroSubstitution::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (MacroKind k : kMacroSubstitutionDerivedKinds) {
      for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
        if (std::optional<MacroSubstitution> e = MacroSubstitution::from(Macro(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<MacroSubstitution> MacroSubstitution::from(const Reference &r) {
  return MacroSubstitution::from(r.as_macro());
}

std::optional<MacroSubstitution> MacroSubstitution::from(const TokenContext &t) {
  return MacroSubstitution::from(t.as_macro());
}

gap::generator<MacroOrToken> MacroSubstitution::replacement_children(void) const & {
  Index index(impl->ep);
  auto list = impl->reader.getVal4();
  for (auto v : list) {
    VariantEntity e = index.entity(EntityId(v));
    if (std::holds_alternative<Macro>(e)) {
      co_yield std::move(std::get<Macro>(e));
    } else if (std::holds_alternative<Token>(e)) {
      co_yield std::move(std::get<Token>(e));
    } else {
      assert(false);
    }
  }
}

Token MacroSubstitution::first_fully_substituted_token(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal5();
    if (eid == kInvalidEntityId) {
      return Token();
    }
    return impl->ep->TokenFor(impl->ep, eid);
  }
  return Token();
}

Token MacroSubstitution::last_fully_substituted_token(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal6();
    if (eid == kInvalidEntityId) {
      return Token();
    }
    return impl->ep->TokenFor(impl->ep, eid);
  }
  return Token();
}

Token MacroSubstitution::name_or_operator(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal7();
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
