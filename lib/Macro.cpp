// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Macro.h"

#include <multiplier/Entities/MacroSubstitution.h>
#include <multiplier/Index.h>

#include "Fragment.h"
#include "Reference.h"
#include "Types.h"

namespace mx {
namespace {

static thread_local RawEntityIdList tIgnoredRedecls;

}  // namespace

MacroImpl::MacroImpl(std::shared_ptr<EntityProvider> ep_,
                     kj::Array<capnp::word> data_,
                     RawEntityId id_)
    : EntityImpl<ast::Macro>(std::move(ep_), kj::mv(data_)),
      fragment_id(FragmentIdFromEntityId(id_).value()),
      offset(FragmentOffsetFromEntityId(id_).value()) {}

SpecificEntityId<MacroId> Macro::id(void) const {
  MacroId eid;
  eid.fragment_id = impl->fragment_id.Unpack().fragment_id;
  eid.kind = kind();
  eid.offset = impl->offset;
  return eid;
}

gap::generator<Macro> Macro::containing_internal(const Token &token) {
  auto frag = token.impl->OwningFragment();
  if (!frag) {
    co_return;
  }

  EntityId eid = token.impl->NthContainingMacroId(token.offset);
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
    co_return;

  } else if (!std::holds_alternative<MacroId>(vid)) {
    assert(false);
    co_return;
  }

  MacroId mid = std::get<MacroId>(vid);
  MacroImplPtr eptr = frag->ep->MacroFor(frag->ep, mid);
  if (!eptr || mid.fragment_id != frag->fragment_id) {
    assert(false);
    co_return;
  }

  std::optional<Macro> macro;
  for (macro.emplace(std::move(eptr)); macro; macro = macro->parent()) {
    co_yield *macro;
  }
}

// References to this macro definition.
gap::generator<Reference> Macro::references(void) const & {
  const EntityProvider::Ptr &ep = impl->ep;
  for (auto [ref_id, ref_kind] : ep->References(ep, id().Pack())) {
    if (auto [eptr, category] = ReferencedEntity(ep, ref_id); eptr) {
      co_yield Reference(std::move(eptr), ref_id, category, ref_kind);
    }
  }
}

namespace {

static gap::generator<Token> GenerateUseTokens(const Macro &macro) {
  for (mx::MacroOrToken use : macro.children()) {
    if (std::holds_alternative<mx::Token>(use)) {
      co_yield std::get<Token>(use);
    } else if (std::holds_alternative<Macro>(use)) {
      for (auto tok : GenerateUseTokens(std::get<Macro>(use))) {
        co_yield tok;
      }
    }
  }
}

static gap::generator<Token> GenerateExpansionTokens(Macro macro);

static gap::generator<Token> GenerateExpansionTokens(
    gap::generator<MacroOrToken> gen) {
  for (mx::MacroOrToken use : gen) {
    if (std::holds_alternative<mx::Token>(use)) {
      if (auto pt = std::get<Token>(use).parsed_token()) {
        co_yield pt;
      }
    } else if (std::holds_alternative<Macro>(use)) {
      for (Token pt : GenerateExpansionTokens(
                          std::move(std::get<Macro>(use)))) {
        co_yield pt;
      }
    }
  }
}

gap::generator<Token> GenerateExpansionTokens(Macro macro) {
  if (auto sub = MacroSubstitution::from(macro)) {
    return GenerateExpansionTokens(sub->replacement_children());
  } else {
    return GenerateExpansionTokens(macro.children());
  }
}

}  // namespace

gap::generator<Token> Macro::use_tokens(void) const & {
  if (auto p = parent()) {
    return p->use_tokens();
  } else {
    return GenerateUseTokens(*this);
  }
}

// Find the tokens the expansion tokens that are actually parsed.
gap::generator<Token> Macro::expansion_tokens(void) const & {
  if (auto p = parent()) {
    return p->expansion_tokens();
  } else {
    return GenerateExpansionTokens(*this);
  }
}

}  // namespace mx
