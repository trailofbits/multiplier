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

#include "Hash.h"
#include "Context.h"
#include "PASTA.h"
#include "TypeFragment.h"
#include "TypeMapper.h"

namespace indexer {

extern void SerializeTypes(mx::DatabaseWriter &database,
                           const pasta::Type &entity,
                           const EntityMapper &em,
                           mx::RawEntityId fragment_index);

namespace {

// Persist the printed tokens in the fragment builder if not
// creating Token tree for printed tokens
static void PersistPrintedTokens(
    EntityMapper &em, mx::rpc::Fragment::Builder &fb,
    const pasta::PrintedTokenRange &range) {

  std::string utf8_fragment_data;
  (void)em;

  unsigned num_parsed_tokens = static_cast<unsigned>(range.size());
  unsigned num_tokens = num_parsed_tokens;
  auto tk = fb.initTokenKinds(num_tokens);
  auto to = fb.initTokenOffsets(num_tokens + 1u);
  auto dt = fb.initDerivedTokenIds(num_tokens);
  auto re = fb.initRelatedEntityId(num_tokens);
  auto pto2i = fb.initParsedTokenOffsetToIndex(num_parsed_tokens);
  auto mti2po = fb.initMacroTokenIndexToParsedTokenOffset(num_tokens);
  auto mti2mi = fb.initMacroTokenIndexToMacroId(num_tokens);
  auto i = 0u;

  // Serialize the tokens.
  while (i < range.size()) {
    const pasta::PrintedToken &tok = range[i];
    pto2i.set(i, i);  // Map printed token to index
    to.set(i, static_cast<unsigned>(utf8_fragment_data.size()));
    tk.set(i, static_cast<uint16_t>(TokenKindFromPasta(tok)));

    // No macro token maps to the printed token. Set it to invalid entity id
    mti2po.set(i, num_tokens);
    mti2mi.set(i, mx::kInvalidEntityId); // No valid map for printed token to containing token
    dt.set(i, mx::kInvalidEntityId);  // No valid derived token id for printed tokens
    re.set(i, mx::kInvalidEntityId);  // No valid related token id for printed tokens

    AccumulateTokenData<pasta::PrintedToken>(utf8_fragment_data, tok);
    ++i;
  }

  to.set(i, static_cast<unsigned>(utf8_fragment_data.size()));
  fb.setTokenData(utf8_fragment_data);
}

// The implementation of PersistTokenContexts is same as for parsed tokens. Some
// of the checks here are redundant for printed token. Move to the specialized
// implementation for printed tokens

static void PersistTokenContexts(
    EntityMapper &em, const pasta::PrintedTokenRange &printed_tokens,
    mx::rpc::Fragment::Builder &fb) {

  using DeclContextSet = std::unordered_set<pasta::TokenContext>;
  std::map<mx::RawEntityId, DeclContextSet> contexts;

  // First, collect only the relevant contexts for this fragment. Group them by
  // entity ID, as we store the context list inline inside of the entities.
  unsigned num_tokens = 0u;
  for (const pasta::PrintedToken &tok : printed_tokens) {
    ++num_tokens;

    for (auto context = tok.Context(); context; context = context->Parent()) {

      pasta::TokenContext c = context.value();
      if (auto alias_context = c.Aliasee()) {
        c = std::move(alias_context.value());
      }

#define ADD_ENTITY_TO_CONTEXT(type_name, lower_name) \
    if (auto lower_name ## _ = pasta::type_name::From(c)) { \
      const mx::RawEntityId eid = em.EntityId(*lower_name ## _); \
      if (eid != mx::kInvalidEntityId) { \
        contexts[eid].insert(context.value()); \
      } \
      continue; \
    }

      FOR_EACH_ENTITY_CATEGORY(ADD_ENTITY_TO_CONTEXT)
#undef ADD_ENTITY_TO_CONTEXT

    }
  }

  struct PendingTokenContext {
    mx::RawEntityId entity_id{mx::kInvalidEntityId};
    bool is_alias{false};
    unsigned offset{0};
    unsigned alias_offset{0};
  };

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
      PendingTokenContext &info = pending_contexts[context];
      info = tpl;  // Copy the template.

      // Adjust the kind to be an aliasee.
      if (context.Aliasee()) {
        info.is_alias = true;
      }

      info.offset = num_contexts++;
    }
  }

  // Now resolve the aliasee targets, if any. Token contexts and their aliases
  // will end up in the same entity-specific lists. This is because the entity
  // in which the context resides will tell us its type.
  for (const auto &entry : contexts) {
    for (const pasta::TokenContext &context : entry.second) {
      auto pc_it = pending_contexts.find(context);
      if (pc_it == pending_contexts.end()) {
        continue;  // E.g. translation unit contexts.
      }

      PendingTokenContext &info = pc_it->second;
      CHECK_NE(info.entity_id, mx::kInvalidEntityId);

      if (!info.is_alias) {
        DCHECK(!context.Aliasee());
        continue;
      }

      auto alias_context = context.Aliasee();
      CHECK(alias_context.has_value());

      PendingTokenContext &alias_info = pending_contexts[alias_context.value()];
      CHECK_EQ(info.entity_id, alias_info.entity_id);
      CHECK_NE(info.offset, alias_info.offset);
      CHECK_LT(alias_info.offset, num_contexts);
      info.alias_offset = alias_info.offset;
    }
  }

  // Allocate as many token contexts as there are parsed tokens.
  auto tcb_list = fb.initParsedTokenContexts(num_contexts);
  auto tco_list = fb.initParsedTokenContextOffsets(num_tokens);

  // Finally, serialize the contexts.
  num_tokens = 0u;
  for (const pasta::PrintedToken &tok : printed_tokens) {
    tco_list.set(num_tokens, 0u);

    std::optional<mx::rpc::TokenContext::Builder> tcb;
    for (auto context = tok.Context(); context; context = context->Parent()) {

      pasta::TokenContext c = *context;
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


void PendingFragmentType::Uses(const pasta::Decl &entity) {
  if (IsSerializableDecl(entity)) {
    decls_in_use.emplace_back(entity);
  }
}

void PendingFragmentType::Uses(const pasta::Stmt &entity) {
  stmts_in_use.emplace_back(entity);
}

void PendingFragmentType::Uses(const pasta::Type &entity) {
  types_in_use.emplace_back(entity);
}

void PendingFragmentType::Uses(const pasta::Attr &entity) {
  attrs_in_use.emplace_back(entity);
}

static void SerializeTypeEntity(
    mx::DatabaseWriter &database, const pasta::Type &entity,
    const PendingFragmentType &tf, const EntityMapper &em) {
  mx::RawEntityId eid = em.EntityId(entity);
  SerializeTypes(database, entity, em, tf.fragment_index);
  EntityBuilder<mx::ast::Type> storage;
  database.AddAsync(
      mx::EntityRecord{eid, GetSerializedData(storage.message)});
}

// Create list of fragments for the new types recovered from the
// pending fragment.
static std::vector<PendingFragmentType> CreateFragments(
    TypeMapper &tm, const pasta::AST &ast, std::vector<pasta::Type> types) {

  std::vector<PendingFragmentType> type_fragments;
  type_fragments.reserve(types.size());

  for (const pasta::Type &type : types) {
    pasta::PrintedTokenRange tok_range = pasta::PrintedTokenRange::Create(type);

    PendingFragmentType tf(tm.FragmentId(type));

    tf.top_level_types.emplace_back(type);
    tf.num_top_level_types = 1u;

    // Pending fragment of types operates on printed token; The begin
    // and end indices are updated accordingly
    tf.file_location = {};

    tf.begin_index = 0u;
    tf.end_index = static_cast<unsigned>(tok_range.size());

    type_fragments.emplace_back(std::move(tf));
  }

  (void)ast;
  return type_fragments;
}


void GlobalIndexingState::PersistTypes(const pasta::AST &ast, NameMangler &mangler,
                                       EntityMapper &em, PendingFragment &pf) {

  // Create fragments from the list of types found in the pending fragments
  auto type_fragments = CreateFragments(em.tm, ast, pf.types_to_serialize);

  // Iterate through the type fragments and build the serialized messages for
  // the fragments.
  for (PendingFragmentType &tf : type_fragments) {
    capnp::MallocMessageBuilder message;
    mx::rpc::Fragment::Builder fb = message.initRoot<mx::rpc::Fragment>();

    // Set the fragment if for the fragment
    fb.setId(tf.fragment_id.Pack());

    auto tlds = fb.initTopLevelDeclarations(
        static_cast<unsigned int>(tf.num_top_level_types));

    for (auto i = 0u; i < tf.num_top_level_types; ++i) {
      auto &entity = tf.top_level_types[i];
      tlds.set(i, em.EntityId(entity));
    }

    // Add a check here to make sure there is only one top-level
    // type in type fragment.
    CHECK_EQ(tf.num_top_level_types, 1u);

    auto &entity = tf.top_level_types[0];
    auto tok_range = pasta::PrintedTokenRange::Create(entity);

    // Identify all of the declarations, statements, types, and pseudo-entities,
    // and build lists of the entities to serialize.
    // BuildFragmentForType(tf, tok_range);

    // Serialize the type entity to create an entry for the type in entity table
    SerializeTypeEntity(database, entity, tf, em);

    // HACK(remove me): Create a map of fragment to file record so that
    //                  fragment appears in the list
    // database.AddAsync(
    //    mx::FragmentFileRecord{tf.fragment_id, pf.file_location->file_id});


    // Check if the file location is valid;
    if (tf.file_location) {
      fb.setFirstFileTokenId(tf.file_location->first_file_token_id.Pack());
      fb.setLastFileTokenId(tf.file_location->last_file_token_id.Pack());

      // Associate the fragment with the file.
      database.AddAsync(
          mx::FragmentFileRecord{tf.fragment_id, tf.file_location->file_id});

      database.AddAsync(
          mx::FragmentFileRangeRecord{
        tf.fragment_id,
        tf.file_location->first_file_token_id,
        tf.file_location->last_file_token_id});
    }

    PersistPrintedTokens(em, fb, tok_range);
    PersistTokenContexts(em, tok_range, fb);

    database.AddAsync(
        mx::EntityRecord{tf.fragment_id.Pack(), GetSerializedData(message)});
  }
  (void)mangler;
}

}


