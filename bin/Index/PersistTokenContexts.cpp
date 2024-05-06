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

// Find the entity id of `canon_decl` that resides in the current fragment
// on which the serializer is operating. Token contexts from PASTA store the
// canonical (typically first) declaration, but we generally want the version
// of the declaration that is inside of the fragment itself, so here we go from
// canonical back to specific.
//
// TODO(pag): Eventually, we should change the serialized representation of
//            token contexts to store full 64-bit entity IDs. Right now, they
//            store offsets of things in the fragments, hence the actual need
//            to go canonical->specific in the first place, and why a failure to
//            do so results in `kInvalidEntityId` instead of just falling back
//            on the ID of the canonical decl.
static mx::RawEntityId IdOfRedeclInFragment(
    const EntityMapper &em, mx::RawEntityId frag_index,
    const pasta::Decl &canon_decl) {

  mx::RawEntityId eid = em.EntityId(canon_decl);
  auto ret_id = eid;
  auto decl_id = mx::EntityId(eid).Extract<mx::DeclId>();
  if (!decl_id) {
    return mx::kInvalidEntityId;
  }

  // Don't scan redeclarations if we don't have to.
  if (decl_id->fragment_id == frag_index) {
    return eid;
  }

  for (pasta::Decl redecl : canon_decl.Redeclarations()) {
    eid = em.EntityId(redecl);
    decl_id = mx::EntityId(eid).Extract<mx::DeclId>();

    // Note: Redecls of the canonical decl can be in the different
    //       fragment. In such case move to next redecls. An example
    //       could be a friend class:
    //          class __attribute__((__visibility__("default"))) A;
    //          class B {
    //            friend class __attribute__((__visibility__("default"))) A;
    //          };
    if (!decl_id) {
      continue;
    }

    // If we come across a definition, then reference it if we're not able
    // to reference a redecl that's in the right fragment.
    if (IsDefinition(redecl)) {
      ret_id = eid;
    }

    if (decl_id->fragment_id == frag_index) {
      return eid;
    }
  }

  return ret_id;
}

struct PendingTokenContext {
  mx::RawEntityId entity_id{mx::kInvalidEntityId};
  bool is_alias{false};
  unsigned offset{0};
  unsigned alias_offset{0};
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

  TokenContextSaver(const EntityMapper &em_,
                    const pasta::PrintedTokenRange &tokens_,
                    mx::RawEntityId fragment_index_)
      : em(em_),
        tokens(tokens_),
        fragment_index(fragment_index_) {}

  unsigned CollectContextsFromTokens(void);
  unsigned ConvertContextsToPendingContexts(void);
  void ResolveAliases(void);

  template <typename ContextListBuilder, typename OffsetListBuilder>
  void Persist(ContextListBuilder tcb_list, OffsetListBuilder tco_list);
};

// First, collect only the relevant contexts for this fragment. Group them by
// entity ID, as we store the context list inline inside of the entities.
unsigned TokenContextSaver::CollectContextsFromTokens(void) {
  auto num_tokens = 0u;
  for (pasta::PrintedToken tok : tokens) {
    ++num_tokens;

    for (pasta::TokenContext context : TokenContexts(tok)) {
      auto unaliased_context = UnaliasedContext(context);

      // NOTE(pag): PASTA stored the canonical decl in the decl context, so
      //            it's not likely to be in the current fragment.
      if (fragment_index && context.Kind() == pasta::TokenContextKind::kDecl) {
        if (auto decl = pasta::Decl::From(unaliased_context)) {
          const mx::RawEntityId eid =
              IdOfRedeclInFragment(em, fragment_index, *decl);
          if (eid != mx::kInvalidEntityId) {
            contexts[eid].insert(context);
          }
        }
      }

#define ADD_ENTITY_TO_CONTEXT(type_name, lower_name) \
      if (auto lower_name ## _ = pasta::type_name::From(unaliased_context)) { \
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

      // Adjust the kind to be an aliasee.
      if (remapped_context.Aliasee()) {
        info.is_alias = true;
      }

      info.offset = num_contexts++;
    }
  }
  return num_contexts;
}

// Now resolve the aliasee targets, if any. Token contexts and their aliases
// will end up in the same entity-specific lists. This is because the entity
// in which the context resides will tell us its type.
void TokenContextSaver::ResolveAliases(void) {
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
// me the SwitchStmt containing this token." Token contexts aren't pure linked
// lists, though; there are special "alias" nodes that tend to link you further
// down the lists, and so that takes some special handling.
template <typename ContextListBuilder, typename OffsetListBuilder>
void TokenContextSaver::Persist(ContextListBuilder tcb_list,
                                OffsetListBuilder tco_list) {

  std::vector<bool> already_created;
  already_created.resize(num_contexts);

  // Finally, serialize the contexts.
  auto num_tokens = 0u;
  for (pasta::PrintedToken tok : tokens) {

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
}

}  // namespace

void PersistTokenContexts(
    const EntityMapper &em, const pasta::PrintedTokenRange &parsed_tokens,
    mx::RawEntityId frag_index, mx::rpc::Fragment::Builder &fb) {

  TokenContextSaver tcs(em, parsed_tokens, frag_index);
  auto num_tokens = tcs.CollectContextsFromTokens();
  auto num_contexts = tcs.ConvertContextsToPendingContexts();
  tcs.ResolveAliases();
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
  tcs.ResolveAliases();
  tcs.Persist(fb.initTypeTokenContexts(num_contexts),
              fb.initTypeTokenContextOffsets(num_tokens));
}

}  // namespace indexer