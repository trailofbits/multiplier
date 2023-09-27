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

// The implementation of PersistTokenContexts is same as for parsed tokens. Some
// of the checks here are redundant for printed token. Move to the specialized
// implementation for printed tokens
static void PersistTokenContexts(
    EntityMapper &em, const pasta::PrintedTokenRange &parsed_tokens,
    mx::rpc::Type::Builder &fb) {

  using DeclContextSet = std::unordered_set<pasta::TokenContext>;
  std::map<mx::RawEntityId, DeclContextSet> contexts;

  // First, collect only the relevant contexts for this fragment. Group them by
  // entity ID, as we store the context list inline inside of the entities.
  unsigned num_tokens = 0u;
  for (pasta::PrintedToken tok : parsed_tokens) {
    ++num_tokens;

    for (pasta::TokenContext c : TokenContexts(tok)) {
      // What context to use for references.
      auto ref_c = c;
      if (auto alias_context = c.Aliasee()) {
        ref_c = std::move(alias_context.value());
      }

      if (false) {

#define ADD_ENTITY_TO_CONTEXT(type_name, lower_name) \
    } else if (auto lower_name ## _ = pasta::type_name::From(ref_c)) { \
      const mx::RawEntityId eid = em.EntityId(*lower_name ## _); \
      if (eid != mx::kInvalidEntityId) { \
        contexts[eid].insert(c); \
      }

      FOR_EACH_ENTITY_CATEGORY(ADD_ENTITY_TO_CONTEXT)
#undef ADD_ENTITY_TO_CONTEXT

      }
    }
  }

  struct PendingTokenContext {
    mx::RawEntityId entity_id{mx::kInvalidEntityId};
    bool is_alias{false};
    unsigned offset{0};
    unsigned alias_offset{0};
  };

  // NOTE(pag): The `TypeMapper` "compresses" out some types via desugaring,
  //            so there will be redundant entries that we'll want to get
  //            rid of.
  std::unordered_map<pasta::TokenContext, pasta::TokenContext>
      remapped_contexts;

  std::unordered_map<pasta::TokenContext, PendingTokenContext>
      pending_contexts;

  unsigned num_contexts = 0;

  // Figure out the kinds of the contexts (stmt, decl, type), the index into the
  // respective entity list in the serialized fragment where the contexts will
  // be placed, the offset at which each context will reside within an entity-
  // specific list, etc.
  for (const auto &entry : contexts) {
    const DeclContextSet &entity_contexts = entry.second;

    // First, make a "template" of the context info, based on the entity kind
    // and fragment info.
    PendingTokenContext tpl;
    tpl.entity_id = entry.first;

    // Then, specialize this template for each context we encounter.
    for (const pasta::TokenContext &context : entity_contexts) {

      // Detect type compression.
      pasta::TokenContext remapped_context = context;
      for (auto pc = context.Parent(); pc; pc = pc->Parent()) {
        if (entity_contexts.contains(pc.value())) {
          remapped_context = pc.value();
        }
      }

      remapped_contexts.emplace(context, remapped_context);

      PendingTokenContext &info = pending_contexts[remapped_context];
      info = tpl;  // Copy the template.

      // Adjust the kind to be an aliasee.
      if (remapped_context.Aliasee()) {
        info.is_alias = true;
      }

      info.offset = num_contexts++;
    }
  }

  // Now resolve the aliasee targets, if any. Token contexts and their aliases
  // will end up in the same entity-specific lists. This is because the entity
  // in which the context resides will tell us its type.
  for (const auto &entry : contexts) {
    for (const pasta::TokenContext &orig_context : entry.second) {

      auto remap_it = remapped_contexts.find(orig_context);
      if (remap_it == remapped_contexts.end()) {
        continue;
      }

      const pasta::TokenContext &context = remap_it->second;
      if (context != orig_context) {
        continue;
      }

      auto pc_it = pending_contexts.find(context);
      if (pc_it == pending_contexts.end()) {
        continue;  // E.g. translation unit contexts.
      }

      PendingTokenContext &info = pc_it->second;
      CHECK_NE(info.entity_id, mx::kInvalidEntityId);

      auto orig_alias_context = context.Aliasee();
      if (!info.is_alias) {
        DCHECK(!orig_alias_context.has_value());
        continue;
      }

      CHECK(orig_alias_context.has_value());

      remap_it = remapped_contexts.find(orig_alias_context.value());
      CHECK(remap_it != remapped_contexts.end());

      const pasta::TokenContext &alias_context = remap_it->second;
      PendingTokenContext &alias_info = pending_contexts[alias_context];
      CHECK_EQ(info.entity_id, alias_info.entity_id);
      CHECK_NE(info.offset, alias_info.offset);
      CHECK_LT(alias_info.offset, num_contexts);
      info.alias_offset = alias_info.offset;
    }
  }

  // Allocate as many token contexts as there are parsed tokens.
  auto tcb_list = fb.initTypeTokenContexts(num_contexts);
  auto tco_list = fb.initTypeTokenContextOffsets(num_tokens);

  std::vector<bool> already_created;
  already_created.resize(num_contexts);

  // Finally, serialize the contexts.
  num_tokens = 0u;
  for (pasta::PrintedToken tok : parsed_tokens) {

    // `0` is an invalid value. A low bit of `1` means "present".
    tco_list.set(num_tokens, 0u);

    std::optional<mx::rpc::TokenContext::Builder> tcb;
    for (auto orig_context = tok.Context(); orig_context;
         orig_context = orig_context->Parent()) {

      auto remap_it = remapped_contexts.find(orig_context.value());
      if (remap_it == remapped_contexts.end()) {
        continue;
      }

      const pasta::TokenContext &c = remap_it->second;
      if (c != orig_context.value()) {
        continue;  // It was compressed out; skip it.
      }

      auto pc_it = pending_contexts.find(c);
      if (pc_it == pending_contexts.end()) {
        continue;  // E.g. translation unit contexts, attributes.
      }

      const PendingTokenContext &info = pc_it->second;

      CHECK_LT(info.offset, num_contexts);
      if (!tcb) {
        tco_list.set(num_tokens, (info.offset << 1u) | 1u);
      } else {
        tcb->setParentIndex((info.offset << 1u) | 1u);
      }

      CHECK_NE(info.entity_id, mx::kInvalidEntityId);

      // Don't double-build the same token contexts.
      if (already_created[info.offset]) {
        break;
      }
      already_created[info.offset] = true;

      tcb.reset();
      tcb.emplace(tcb_list[info.offset]);
      tcb->setEntityId(info.entity_id);
      tcb->setParentIndex(0u);

      if (info.is_alias) {
        CHECK_LT(info.alias_offset, num_contexts);
        tcb->setAliasIndex((info.alias_offset << 1u) | 1u);
      } else {
        tcb->setAliasIndex(0u);
      }
    }

    ++num_tokens;
  }

  DCHECK_GT(fb.getTokenKinds().size(), 0u);
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
