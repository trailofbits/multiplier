// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Macro.h"

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

static gap::generator<Token> GenerateTokens(const Macro &macro) {
  for (mx::MacroOrToken use : macro.children()) {
    if (std::holds_alternative<mx::Token>(use)) {
      co_yield std::get<Token>(use);
    } else if (std::holds_alternative<Macro>(use)) {
      for (auto tok : GenerateTokens(std::get<Macro>(use))) {
        co_yield tok;
      }
    }
  }
}

}  // namespace

gap::generator<Token> Macro::tokens_covering_use(void) const & {
  if (auto p = parent()) {
    return p->tokens_covering_use();
  } else {
    return GenerateTokens(*this);
  }
}

}  // namespace mx
