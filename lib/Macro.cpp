// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Macro.h"

#include <multiplier/Frontend/MacroSubstitution.h>
#include <multiplier/Index.h>

#include "Fragment.h"
#include "Reference.h"
#include "Types.h"

namespace mx {

MacroImpl::MacroImpl(FragmentImplPtr frag_,
                     ast::Macro::Reader reader_,
                     RawEntityId id_)
    : FragmentEntityImpl<ast::Macro>(std::move(frag_), kj::mv(reader_)),
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

namespace {

static gap::generator<Token> GenerateUseTokens(
    const Macro *scope, gap::generator<PreprocessedEntity> *gen) {

  for (PreprocessedEntity use : *gen) {
    if (std::holds_alternative<mx::Token>(use)) {
      co_yield std::get<Token>(use);

    } else if (std::holds_alternative<Macro>(use)) {
      for (auto tok : std::get<Macro>(use).generate_use_tokens()) {
        co_yield tok;
      }

    } else if (std::holds_alternative<Fragment>(use)) {
      auto nested_gen = std::get<Fragment>(use).preprocessed_code();
      for (auto tok : GenerateUseTokens(scope, &nested_gen)) {
        co_yield tok;
      }
    }
  }

  asm volatile ("" ::"m"(scope):"memory");
}

static gap::generator<Token> GenerateExpansionTokens(
    const Macro *scope, gap::generator<PreprocessedEntity> *gen) {
  for (PreprocessedEntity use : *gen) {
    if (std::holds_alternative<mx::Token>(use)) {
      co_yield std::get<Token>(use);

    } else if (std::holds_alternative<Macro>(use)) {
      for (auto tok : std::get<Macro>(use).generate_expansion_tokens()) {
        co_yield tok;
      }
    } else if (std::holds_alternative<Fragment>(use)) {
      auto nested_gen = std::get<Fragment>(use).preprocessed_code();
      for (auto tok : GenerateExpansionTokens(scope, &nested_gen)) {
        co_yield tok;
      }
    }
  }
  asm volatile ("" ::"m"(scope):"memory");
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
  auto nested_gen = children();
  for (Token tok : GenerateUseTokens(this, &nested_gen)) {
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
  for (Token tok : generate_expansion_tokens()) {
    reader->Append(std::move(tok.impl), tok.offset);
    ++num_toks;
  }
  return TokenRange(std::move(reader), 0u, num_toks);
}

gap::generator<Token> Macro::generate_use_tokens(void) const & {
  auto nested_gen = children();
  for (auto tok : GenerateUseTokens(this, &nested_gen)) {
    co_yield tok;
  }
}

// Find the tokens the expansion tokens that are actually parsed.
gap::generator<Token> Macro::generate_expansion_tokens(void) const & {
  if (auto sub = MacroSubstitution::from(*this)) {
    auto nested_gen = sub->replacement_children();
    for (auto tok : GenerateExpansionTokens(this, &nested_gen)) {
      co_yield tok;
    }
  } else {
    auto nested_gen = children();
    for (auto tok : GenerateExpansionTokens(this, &nested_gen)) {
      co_yield tok;
    }
  }
}

}  // namespace mx
