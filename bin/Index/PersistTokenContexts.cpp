// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <glog/logging.h>
#include <map>
#include <multiplier/AST.capnp.h>
#include <multiplier/RPC.capnp.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "EntityMapper.h"
#include "PendingFragment.h"

namespace indexer {
namespace {

struct PendingTokenContext {
  mx::RawEntityId entity_id{mx::kInvalidEntityId};
  unsigned offset{0};
};

using DeclContextSet = std::unordered_set<pasta::TokenContext>;

class TokenContextSaver {
 private:
  const EntityMapper &em;
  const pasta::PrintedTokenRange &tokens;
  const mx::RawEntityId fragment_index;
  
  std::map<mx::RawEntityId, DeclContextSet> contexts;

  // NOTE(pag): The `TypeMapper` "compresses" out some types via desugaring,
  //            so there will be redundant entries that we'll want to get
  //            rid of.
  std::unordered_map<pasta::TokenContext, pasta::TokenContext>
      remapped_contexts;

  std::unordered_map<pasta::TokenContext, PendingTokenContext>
      pending_contexts;

  unsigned num_contexts{0u};

 public:

  bool TokenIsInFragment(const pasta::PrintedToken &tok) const {
    if (!fragment_index) {
      return true;  // We're persisting type tokens.
    }

    auto pid = mx::EntityId(em.EntityId(tok)).Extract<mx::ParsedTokenId>();
    return pid && pid->fragment_id == fragment_index;
  }

  TokenContextSaver(const EntityMapper &em_,
                    const pasta::PrintedTokenRange &tokens_,
                    mx::RawEntityId fragment_index_)
      : em(em_),
        tokens(tokens_),
        fragment_index(fragment_index_) {}

  unsigned CollectContextsFromTokens(void);
  unsigned ConvertContextsToPendingContexts(void);

  template <typename ContextListBuilder, typename OffsetListBuilder>
  void Persist(ContextListBuilder tcb_list, OffsetListBuilder tco_list);
};

// First, collect only the relevant contexts for this fragment. Group them by
// entity ID, as we store the context list inline inside of the entities.
unsigned TokenContextSaver::CollectContextsFromTokens(void) {
  auto num_tokens = 0u;
  for (pasta::PrintedToken tok : tokens) {

    // Don't save token contexts for tokens that are part of a nested fragment.
    if (!TokenIsInFragment(tok)) {
      continue;
    }

    ++num_tokens;

    for (pasta::TokenContext context : TokenContexts(tok)) {
#define ADD_ENTITY_TO_CONTEXT(type_name, lower_name) \
      if (auto lower_name ## _ = pasta::type_name::From(context)) { \
        const mx::RawEntityId eid = em.EntityId(*lower_name ## _); \
        if (eid != mx::kInvalidEntityId) { \
          contexts[eid].insert(context); \
        } \
        continue; \
      }

      FOR_EACH_ENTITY_CATEGORY(ADD_ENTITY_TO_CONTEXT)
#undef ADD_ENTITY_TO_CONTEXT
    }
  }
  return num_tokens;
}

// Figure out the kinds of the contexts (stmt, decl, type), the index into the
// respective entity list in the serialized fragment where the contexts will
// be placed, the offset at which each context will reside within an entity-
// specific list, etc.
unsigned TokenContextSaver::ConvertContextsToPendingContexts(void) {
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
      info.offset = num_contexts++;
    }
  }
  return num_contexts;
}

// Persist the token contexts. The token contexts are a kind of inverted tree,
// e.g.
//
//        int       foo       =         0       ;
//         |         |        |         |       |
//     BuiltinType   |        |     IntLiteral  /
//          \  .--<--'  .--<--' .---<---' .----'
//           \ | .--<---' .--<--'  .--<---'
//            \|/  .---<--'  .--<--'
//           VarDecl <---<---'
//
// They tell us the provenance or relation of a particular token to the AST that
// represents the code containing that token. You can, in theory, follow a
// linked list from a token all the way up to the root of an AST. We want to
// serialize these because they allow us to make queries in our API, e.g. "give
// me the SwitchStmt containing this token."
template <typename ContextListBuilder, typename OffsetListBuilder>
void TokenContextSaver::Persist(ContextListBuilder tcb_list,
                                OffsetListBuilder tco_list) {

  std::vector<bool> already_created;
  already_created.resize(num_contexts);

  // Finally, serialize the contexts.
  auto num_tokens = 0u;
  for (pasta::PrintedToken tok : tokens) {

    if (!TokenIsInFragment(tok)) {
      continue;
    }

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
    }

    ++num_tokens;
  }
}

}  // namespace

void PersistTokenContexts(const PendingFragment &pf,
                          mx::rpc::Fragment::Builder &fb) {

  TokenContextSaver tcs(pf.em, pf.parsed_tokens, pf.fragment_index);

#ifndef NDEBUG
  for (auto tok : pf.parsed_tokens) {
    CHECK_EQ(tcs.TokenIsInFragment(tok),
             !pf.token_to_nested_fragment.contains(RawEntity(tok)));
  }
#endif

  auto num_tokens = tcs.CollectContextsFromTokens();
  CHECK_EQ(pf.num_parsed_tokens, num_tokens);
  auto num_contexts = tcs.ConvertContextsToPendingContexts();
  tcs.Persist(fb.initParsedTokenContexts(num_contexts),
              fb.initParsedTokenContextOffsets(num_tokens));
}

// The implementation of PersistTokenContexts is same as for parsed tokens. Some
// of the checks here are redundant for printed token. Move to the specialized
// implementation for printed tokens
void PersistTokenContexts(
    const EntityMapper &em, const pasta::PrintedTokenRange &parsed_tokens,
    mx::rpc::Type::Builder &fb) {

  TokenContextSaver tcs(em, parsed_tokens, 0u);
  auto num_tokens = tcs.CollectContextsFromTokens();
  auto num_contexts = tcs.ConvertContextsToPendingContexts();
  tcs.Persist(fb.initTypeTokenContexts(num_contexts),
              fb.initTypeTokenContextOffsets(num_tokens));
}

}  // namespace indexer