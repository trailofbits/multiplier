// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <capnp/common.h>
#include <capnp/message.h>
#include <capnp/serialize.h>
#include <fstream>
#include <glog/logging.h>
#include <iostream>
#include <kj/io.h>
#include <unordered_set>

#include <multiplier/AST.h>
#include <multiplier/AST.capnp.h>
#include <multiplier/Database.h>
#include <multiplier/RPC.capnp.h>
#include <multiplier/Types.h>
#include <multiplier/Entities/TokenKind.h>

#include <pasta/AST/AST.h>
#include <pasta/AST/Printer.h>

#include "EntityMapper.h"
#include "Hash.h"
#include "Context.h"
#include "PASTA.h"
#include "PendingFragment.h"
#include "TypeMapper.h"

namespace indexer {

extern void SerializeType(const pasta::Type &entity,
                          const PendingFragment &pf,
                          mx::RawEntityId type_index,
                          mx::ast::Type::Builder builder);

// Find the entity ID of the declaration that is most related to a particular
// token.
extern mx::RawEntityId RelatedEntityIdToToken(
    const EntityMapper &em, const pasta::PrintedToken &printed_tok,
    const std::optional<pasta::Token> &parsed_tok);

// The implementation of PersistTokenContexts is same as for parsed tokens. Some
// of the checks here are redundant for printed token. Move to the specialized
// implementation for printed tokens
extern void PersistTokenContexts(
    const EntityMapper &em, const pasta::PrintedTokenRange &parsed_tokens,
    mx::rpc::Type::Builder &fb);

namespace {

// Persist the printed tokens in the fragment builder if not
// creating Token tree for printed tokens
static void PersistPrintedTokens(
    EntityMapper &em, mx::rpc::Type::Builder &fb,
    const pasta::PrintedTokenRange &range, const mx::TypeId type_id) {

  std::string utf8_fragment_data;
  (void)em;

  unsigned num_parsed_tokens = static_cast<unsigned>(range.size());
  unsigned num_tokens = num_parsed_tokens;
  auto tk = fb.initTokenKinds(num_tokens);
  auto to = fb.initTokenOffsets(num_tokens + 1u);
  auto re = fb.initRelatedEntityId(num_tokens);
  mx::EntityOffset i = 0u;

  mx::TypeTokenId token_id;
  token_id.type_id = type_id.type_id;
  token_id.type_kind = type_id.kind;

  // Serialize the tokens.
  for (pasta::PrintedToken tok : range) {
    token_id.kind = TokenKindFromPasta(tok);
    token_id.offset = i;

    to.set(i, static_cast<unsigned>(utf8_fragment_data.size()));
    tk.set(i, static_cast<uint16_t>(token_id.kind));
    re.set(i, RelatedEntityIdToToken(em, tok, tok.DerivedLocation()));

    AccumulateTokenData<pasta::PrintedToken>(utf8_fragment_data, tok);
    ++i;
    
    // When persisting the types, some lookups will find tokens, e.g. `...`
    // in a `FunctionProtoType` for a variadic function. These will reference
    // parsed locations, but we want to arrange for them to instead reference
    // the type tokens.
    //
    // NOTE(pag): It's possible that we'll see duplicates. This generally is
    //            the result of type deduplication. For example, with
    //            elaborated types in particular, we would could have:
    //
    //                struct FOO *()(struct FOO *)
    //
    //            And the we'd see the same derived token for `struct` twice.
    if (std::optional<pasta::Token> pt = tok.DerivedLocation()) {
      em.token_tree_ids.emplace(pt->RawToken(), mx::EntityId(token_id));
    }
  }

  to.set(i, static_cast<unsigned>(utf8_fragment_data.size()));
  fb.setTokenData(utf8_fragment_data);
}

} // namespace

void GlobalIndexingState::PersistTypes(
    const pasta::AST &, NameMangler &, EntityMapper &em,
    const PendingFragment &pf) {

  for (const pasta::Type &type : pf.types_to_serialize) {
    em.ResetForFragment();

    ProgressBarWork type_progress_tracker(type_progress);

    TypePrintingPolicy pp;
    pasta::PrintedTokenRange token_range =
        pasta::PrintedTokenRange::Create(type, pp);

    mx::PackedTypeId ptid = em.tm.TypeId(type);
    mx::TypeId tid = ptid.Unpack();

    capnp::MallocMessageBuilder message;
    mx::rpc::Type::Builder fb = message.initRoot<mx::rpc::Type>();

    auto tb = fb.initType();
    PersistPrintedTokens(em, fb, token_range, tid);
    PersistTokenContexts(em, token_range, fb);

    (void) SerializeType(type, pf, tid.type_id, tb);

    database.AddAsync(
        mx::EntityRecord{ptid.Pack(), GetSerializedData(message)});
  }
}

}  // namespace indexer
