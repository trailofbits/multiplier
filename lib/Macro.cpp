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
  EntityProviderPtr ep = TokenReader::EntityProviderFor(token);
  if (!ep) {
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
  MacroImplPtr eptr = ep->MacroFor(ep, mid);
  if (!eptr) {
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
  const EntityProviderPtr &ep = impl->ep;
  for (auto [ref_id, ref_kind] : ep->References(ep, id().Pack())) {
    if (auto [eptr, category] = ReferencedEntity(ep, ref_id); eptr) {
      co_yield Reference(std::move(eptr), ref_id, category, ref_kind);
    }
  }
}

namespace {

static gap::generator<Token> GenerateUseTokens(Macro macro) {
  for (MacroOrToken use : macro.children()) {
    if (std::holds_alternative<mx::Token>(use)) {
      co_yield std::get<Token>(use);
    } else if (std::holds_alternative<Macro>(use)) {
      for (auto tok : GenerateUseTokens(std::move(std::get<Macro>(use)))) {
        co_yield tok;
      }
    }
  }
}

static gap::generator<Token> GenerateExpansionTokensFromMacro(Macro macro);

static gap::generator<Token> GenerateExpansionTokensFromUse(
    MacroOrToken use) {
  if (std::holds_alternative<mx::Token>(use)) {
    co_yield std::get<Token>(use);
  } else if (std::holds_alternative<Macro>(use)) {
    for (Token pt : GenerateExpansionTokensFromMacro(
                        std::move(std::get<Macro>(use)))) {
      co_yield pt;
    }
  }
}

gap::generator<Token> GenerateExpansionTokensFromMacro(Macro macro) {
  if (auto sub = MacroSubstitution::from(macro)) {
    for (MacroOrToken use : sub->replacement_children()) {
      for (Token tok : GenerateExpansionTokensFromUse(std::move(use))) {
        co_yield tok;
      }
    }
  } else {
    for (MacroOrToken use : macro.children()) {
      for (Token tok : GenerateExpansionTokensFromUse(std::move(use))) {
        co_yield tok;
      }
    }
  }
}

}  // namespace


Macro Macro::root(void) const & {
  if (std::optional<Macro> p = parent()) {
    return p->root();
  } else {
    return *this;
  }
}

TokenRange Macro::use_tokens(void) const & {
  auto frag = impl->ep->FragmentFor(impl->ep, impl->fragment_id);
  if (!frag) {
    assert(false);
    return TokenRange();
  }

  std::shared_ptr<CustomTokenReader> reader =
      std::make_shared<CustomTokenReader>(std::move(frag));
  EntityOffset num_toks = 0u;
  for (Token tok : GenerateUseTokens(*this)) {
    reader->Append(std::move(tok.impl), tok.offset);
    ++num_toks;
  }

  assert(reader->token_ids.size() == num_toks);
  assert(reader->data_offset.size() == (num_toks + 1u));

  return TokenRange(std::move(reader), 0u, num_toks);
}

// Find the tokens the expansion tokens that are actually parsed.
TokenRange Macro::expansion_tokens(void) const & {
  auto frag = impl->ep->FragmentFor(impl->ep, impl->fragment_id);
  if (!frag) {
    assert(false);
    return TokenRange();
  }

  auto reader = std::make_shared<CustomTokenReader>(std::move(frag));
  EntityOffset num_toks = 0u;
  for (Token tok : GenerateExpansionTokensFromMacro(*this)) {
    reader->Append(std::move(tok.impl), tok.offset);
    ++num_toks;
  }
  return TokenRange(std::move(reader), 0u, num_toks);
}

gap::generator<Token> Macro::generate_use_tokens(void) const & {
  return GenerateUseTokens(*this);
}

// Find the tokens the expansion tokens that are actually parsed.
gap::generator<Token> Macro::generate_expansion_tokens(void) const & {
  return GenerateExpansionTokensFromMacro(*this);
}

}  // namespace mx
