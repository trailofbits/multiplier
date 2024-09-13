// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Frontend/MacroSubstitution.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/Frontend/Macro.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/Frontend/MacroConcatenate.h>
#include <multiplier/Frontend/MacroExpansion.h>
#include <multiplier/Frontend/MacroParameterSubstitution.h>
#include <multiplier/Frontend/MacroStringify.h>

#include "../EntityProvider.h"
#include "../Fragment.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const MacroKind kMacroSubstitutionDerivedKinds[] = {
    MacroSubstitution::static_kind(),
    MacroParameterSubstitution::static_kind(),
    MacroExpansion::static_kind(),
    MacroStringify::static_kind(),
    MacroConcatenate::static_kind(),
};
}  // namespace

gap::generator<MacroSubstitution> MacroSubstitution::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (MacroKind k : kMacroSubstitutionDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      if (std::optional<MacroSubstitution> e = from_base(std::move(eptr))) {
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
        if (std::optional<MacroSubstitution> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<MacroSubstitution> MacroSubstitution::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kMacroSubstitutionDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      if (std::optional<MacroSubstitution> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

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
    if (auto base = index.macro(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<MacroSubstitution> MacroSubstitution::from(const std::optional<Macro> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<MacroSubstitution> MacroSubstitution::from_base(const Macro &parent) {
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

std::optional<MacroSubstitution> MacroSubstitution::from(const Reference &r) {
  return MacroSubstitution::from(r.as_macro());
}

std::optional<MacroSubstitution> MacroSubstitution::from(const VariantEntity &e) {
  if (!std::holds_alternative<Macro>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Macro>(e));
}

std::optional<MacroSubstitution> MacroSubstitution::from(const TokenContext &t) {
  if (auto base = t.as_macro()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

gap::generator<PreprocessedEntity> MacroSubstitution::replacement_children(void) const & {
  Index index(impl->ep);
  auto list = impl->reader.getVal4();
  for (auto v : list) {
    VariantEntity e = index.entity(EntityId(v));
    if (std::holds_alternative<Macro>(e)) {
      co_yield std::move(std::get<Macro>(e));
    } else if (std::holds_alternative<Token>(e)) {
      co_yield std::move(std::get<Token>(e));
    } else if (std::holds_alternative<Fragment>(e)) {
      co_yield std::move(std::get<Fragment>(e));
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
