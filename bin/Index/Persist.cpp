// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Persist.h"

#include <algorithm>
#include <capnp/common.h>
#include <capnp/message.h>
#include <fstream>
#include <glog/logging.h>
#include <llvm/Support/JSON.h>
#include <multiplier/AST.h>
#include <multiplier/RPC.capnp.h>
#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <sstream>
#include <utility>

#include "Codegen.h"
#include "Compress.h"
#include "Context.h"
#include "EntityMapper.h"
#include "ProgressBar.h"
#include "TokenTree.h"
#include "Util.h"

namespace indexer {
namespace {

using SubstitutionBuilder = mx::rpc::MacroSubstitution::Builder;

using SubstitutionListBuilder =
    capnp::List<mx::rpc::MacroSubstitution, capnp::Kind::STRUCT>::Builder;

using TokenKindListBuilder =
    capnp::List<uint16_t, ::capnp::Kind::PRIMITIVE>::Builder;

using TokenOffsetListBuilder =
    capnp::List<uint32_t, ::capnp::Kind::PRIMITIVE>::Builder;

using TokenIdListBuilder =
    capnp::List<uint64_t, ::capnp::Kind::PRIMITIVE>::Builder;

template <typename Tok>
static void AccumulateTokenData(std::string &data, const Tok &tok) {
  llvm::StringRef tok_data = tok.Data();
  if (llvm::json::isUTF8(tok_data)) {
    data.insert(data.end(), tok_data.begin(), tok_data.end());

  } else {
    data += llvm::json::fixUTF8(tok_data);
  }
}

// Count the number of substitutions in a token tree. We need to pre-initialize
// the total size of lists in Cap'n Proto, and so we need to know how many
// substitutions we'll want to store when serializing a fragment, as the
// serialized fragments contain the macro substitution tree (e.g. to help us
// print out the "unparsed", i.e. original, code of a fragment).
//
// This also initializes the macro token ids in the right order.
static void CountSubstitutions(EntityMapper &em, TokenTree tt,
                               std::vector<TokenTree> &todo,
                               unsigned &num_subs, unsigned &num_toks) {

  for (auto node : tt) {
    if (auto sub = node.MaybeSubstitution()) {
      auto [kind, lhs, rhs] = std::move(sub.value());

      ++num_subs;

      CountSubstitutions(em, std::move(lhs), todo, num_subs, num_toks);
      todo.emplace_back(std::move(rhs));

    } else if (auto sub_tree = node.MaybeSubTree()) {
      auto [kind, lhs] = std::move(sub_tree.value());

      ++num_subs;

      CountSubstitutions(em, std::move(lhs), todo, num_subs, num_toks);

    } else {
      mx::MacroTokenId id;
      id.fragment_id = em.fragment.fragment_id;
      id.offset = num_toks++;

      auto pt = node.Token();
      auto mt = node.MacroToken();
      auto ft = node.FileToken();

      if (!pt && mt) {
        pt = mt->ParsedLocation();
      }
      if (!ft && pt) {
        ft = pt->FileLocation();
      }
      if (!ft && mt) {
        ft = mt->FileLocation();
      }

      if (pt) {
        id.kind = TokenKindFromPasta(*pt);
      } else if (ft) {
        id.kind = TokenKindFromPasta(*ft);
      } else if (mt) {
        id.kind = TokenKindFromPasta(*mt);
      } else {
        LOG(FATAL)
            << "Missing file/parsed/macro token";
      }

      // Map it in.
      mx::RawEntityId eid = mx::EntityId(id).Pack();

      if (pt) {
        em.entity_ids.emplace(pt->RawToken(), eid);
      }
    }
  }
}

static mx::RawEntityId DerivedTokenId(
    EntityMapper &em, const pasta::FileToken &tok) {
  return em.EntityId(tok);
}

static mx::RawEntityId DerivedTokenId(
    EntityMapper &em, const pasta::Token &tok) {
  mx::RawEntityId eid = mx::kInvalidEntityId;
  if (std::optional<pasta::Token> derived_tok = tok.DerivedLocation()) {
    eid = em.EntityId(derived_tok.value());
  }

  if (eid != mx::kInvalidEntityId) {
    return eid;
  }

  if (std::optional<pasta::FileToken> file_tok = tok.FileLocation()) {
    return DerivedTokenId(em, file_tok.value());
  }

  return mx::kInvalidEntityId;
}

// Figure out the lines of `file` spanned by `tt`. We use this to help us
// populate an index (persistent set) of `<file_id, line_num, frag_id>` triples.
// This index helps us go from matches (e.g. RE2) in files to matches in
// fragments.
static void FindFileRange(const pasta::TokenRange &tokens, uint64_t min_index,
                          uint64_t max_index, const pasta::File &file,
                          pasta::FileToken *min, pasta::FileToken *max) {

  int ignore = 0;
  for (auto i = min_index; i <= max_index; ++i) {
    pasta::Token tok = tokens[i];
    switch (tok.Role()) {
      case pasta::TokenRole::kBeginOfFileMarker:
        ++ignore;
        continue;

      case pasta::TokenRole::kEndOfFileMarker:
        --ignore;
        continue;

      default:
        continue;

      case pasta::TokenRole::kFileToken:
      case pasta::TokenRole::kInitialMacroUseToken:
        DCHECK_LE(0, ignore);
        if (ignore) {
          continue;
        } else {
          break;
        }
    }

    auto ft = tok.FileLocation();
    if (!ft) {
      continue;
    }

    if (ft->RawFile() != file.RawFile()) {
      continue;
    }
    if (ft->Index() < min->Index()) {
      *min = *ft;
    }
    if (ft->Index() > max->Index()) {
      *max = *ft;
    }
  }
}

// Persist the tokens of a fragment.
template <typename Pred>
static void PersistTokens(EntityMapper &em, const pasta::TokenRange &tokens,
                          uint64_t begin_index, uint64_t end_index,
                          std::string &utf8_fragment_data,
                          TokenIdListBuilder &dtb, TokenKindListBuilder &tkb,
                          TokenOffsetListBuilder &tob, TokenIdListBuilder aib,
                          unsigned &next_tok_offset, Pred pred) {
  // Encode the token kinds and the offsets of token data. We can't be certain
  // that the file is in UTF-8, so we re-build the contents on a per-token
  // basis, because that's the only way to guarantee token offsets in the
  // presence of UTF-8 issues.
  for (auto i = begin_index; i <= end_index; ++i) {
    pasta::Token tok = tokens[i];
    if (!pred(tok)) {
      continue;
    }

    dtb.set(next_tok_offset, DerivedTokenId(em, tok));
    tkb.set(next_tok_offset, static_cast<uint16_t>(TokenKindFromPasta(tok)));
    tob.set(next_tok_offset, static_cast<uint32_t>(utf8_fragment_data.size()));
    aib.set(next_tok_offset, em.EntityId(tok));

    AccumulateTokenData(utf8_fragment_data, tok);

    // Space-separate every token.
    //
    // NOTE(pag): This means that `PackedFragmentImpl::NthTokenData` needs
    //            to account for this additional space.
    //
    // NOTE(pag): This means parsed tokens, even if empty, will have unique
    //            data pointers.
    utf8_fragment_data.push_back(' ');

    ++next_tok_offset;
  }
}

// If we fail to build a token tree, then we can still save out quite a bunch
// of macro info.
static void BackupPersistMacroTokens(
    EntityMapper &em, const pasta::TokenRange &tokens, uint64_t begin_index,
    uint64_t end_index, mx::rpc::Fragment::Builder &fb) {

  // First, count how many macro tokens we have, and initialize the macro
  // tokens entity IDs.
  unsigned num_parsed_tokens = 0u;
  for (auto i = begin_index; i <= end_index; ++i) {
    pasta::Token tok = tokens[i];
    if (IsParsedToken(tok)) {
      ++num_parsed_tokens;
    }
  }

  unsigned num_tokens = num_parsed_tokens;
  unsigned num_macro_tokens = 0u;
  for (auto i = begin_index; i <= end_index; ++i) {
    pasta::Token tok = tokens[i];
    switch (tok.Role()) {
      case pasta::TokenRole::kInitialMacroUseToken:
      case pasta::TokenRole::kIntermediateMacroExpansionToken:
        break;
      default:
        continue;
    }

    mx::MacroTokenId id;
    id.fragment_id = em.fragment.fragment_id;
    id.kind = TokenKindFromPasta(tok);
    id.offset = num_tokens;

    // Map it in.
    mx::RawEntityId eid = mx::EntityId(id).Pack();
    em.entity_ids.emplace(tok.RawToken(), eid);

    ++num_macro_tokens;
    ++num_tokens;
  }

  std::string utf8_fragment_data;

  SubstitutionListBuilder sb = fb.initSubstitutions(1u);
  TokenIdListBuilder dtb = fb.initDerivedTokenIds(num_tokens);
  TokenKindListBuilder tkb = fb.initTokenKinds(num_tokens);
  TokenOffsetListBuilder tob = fb.initTokenOffsets(num_tokens + 1u);

  unsigned next_token_index = 0u;
  unsigned next_substitution_index = 0u;
  SubstitutionBuilder pp_sub = sb[next_substitution_index++];
  pp_sub.setKind(static_cast<uint8_t>(
      mx::MacroSubstitutionKind::PREPROCESSED_CODE));

  PersistTokens(em, tokens, begin_index, end_index, utf8_fragment_data,
                dtb, tkb, tob, pp_sub.initAfterIds(num_parsed_tokens),
                next_token_index, IsParsedToken);
  CHECK_EQ(next_token_index, num_parsed_tokens);

  pp_sub.setFirstAfterTokenOffset(0u);
  pp_sub.setAfterLastAfterTokenOffset(num_parsed_tokens);
  pp_sub.setFirstBeforeTokenOffset(num_parsed_tokens);
  pp_sub.setAfterLastAfterTokenOffset(num_tokens);

  PersistTokens(em, tokens, begin_index, end_index, utf8_fragment_data,
                dtb, tkb, tob, pp_sub.initBeforeIds(num_macro_tokens),
                next_token_index,
                [] (const pasta::Token &tok) -> bool {
                  switch (tok.Role()) {
                    case pasta::TokenRole::kInitialMacroUseToken:
                    case pasta::TokenRole::kIntermediateMacroExpansionToken:
                      return true;
                    default:
                      return false;
                  }
                });

  CHECK_EQ(next_token_index, num_tokens);

  // Make sure that we add a final ending offset for token data.
  tob.set(next_token_index, static_cast<unsigned>(utf8_fragment_data.size()));
  utf8_fragment_data.push_back('\0');

  fb.setTokenData(utf8_fragment_data);
}

struct PersistTokenTreeWork {
  SubstitutionBuilder sb;
  TokenIdListBuilder nib;
  TokenTree tree;

  PersistTokenTreeWork(void) = delete;

  inline explicit PersistTokenTreeWork(SubstitutionBuilder sb_,
                                       TokenIdListBuilder nib_,
                                       TokenTree tree_)
      : sb(std::move(sb_)),
        nib(std::move(nib_)),
        tree(std::move(tree_)) {}
};

// Persist the token tree, which is a tree of substitutions, i.e. before/after
// macro use/expansion, or x-macro file inclusion.
//
// NOTE(pag): The usage of `todo` is slightly subtle. We want to recursively
//            process all `before` sides of token trees before we ever process
//            any `after` sides.
static void PersistTokenTree(EntityMapper &em,
                             std::string &utf8_macro_data,
                             SubstitutionListBuilder &subs_builder,
                             TokenIdListBuilder &dtb,
                             TokenKindListBuilder &tkb,
                             TokenOffsetListBuilder &tob,
                             PersistTokenTreeWork work,
                             std::vector<PersistTokenTreeWork> &todo,
                             unsigned &next_tok_offset,
                             unsigned &next_sub_offset) {
  unsigned i = 0u;

  work.sb.setFirstAfterTokenOffset(next_tok_offset);
  for (TokenTreeNode node : work.tree) {

    // This is a substitution of two sub-trees.
    if (auto sub = node.MaybeSubstitution()) {
      auto [kind, lhs, rhs] = std::move(sub.value());
      mx::MacroSubstitutionId sub_id;
      sub_id.fragment_id = em.fragment.fragment_id;

      // If we can't isolate / locate this macro expansion to a specific
      // definition site, then reinterpret this macro as a substitution.
      if (kind == mx::MacroSubstitutionKind::MACRO &&
          (!lhs.MacroDefinition() ||
           !lhs.MacroDefinition()->Name().FileLocation())) {
        sub_id.kind = mx::MacroSubstitutionKind::SUBSTITUTE;
      } else {
        sub_id.kind = kind;
      }

      sub_id.offset = next_sub_offset;
      mx::RawEntityId eid = mx::EntityId(sub_id).Pack();
      work.nib.set(i++, eid);

      SubstitutionBuilder next_sub = subs_builder[next_sub_offset++];
      next_sub.setKind(static_cast<uint8_t>(kind));

      auto num_children = lhs.NumNodes();
      PersistTokenTreeWork now(next_sub, next_sub.initBeforeIds(num_children),
                               std::move(lhs));

      next_sub.setFirstBeforeTokenOffset(next_tok_offset);
      PersistTokenTree(em, utf8_macro_data, subs_builder, dtb, tkb, tob,
                       std::move(now), todo, next_tok_offset, next_sub_offset);
      next_sub.setAfterFirstBeforeTokenOffset(next_tok_offset);

      num_children = rhs.NumNodes();
      todo.emplace_back(next_sub, next_sub.initAfterIds(num_children),
                        std::move(rhs));

    // This is a sub-tree.
    } else if (auto st = node.MaybeSubTree()) {
      auto [kind, lhs] = std::move(st.value());
      mx::MacroSubstitutionId sub_id;
      sub_id.fragment_id = em.fragment.fragment_id;
      sub_id.kind = kind;
      sub_id.offset = next_sub_offset;
      mx::RawEntityId eid = mx::EntityId(sub_id).Pack();
      work.nib.set(i++, eid);

      mx::rpc::MacroSubstitution::Builder next_sub =
          subs_builder[next_sub_offset++];
      next_sub.setKind(static_cast<uint8_t>(kind));

      auto num_children = lhs.NumNodes();
      PersistTokenTreeWork now(next_sub, next_sub.initBeforeIds(num_children),
                               std::move(lhs));

      next_sub.setFirstBeforeTokenOffset(next_tok_offset);
      PersistTokenTree(em, utf8_macro_data, subs_builder, dtb, tkb, tob,
                       std::move(now), todo, next_tok_offset, next_sub_offset);
      next_sub.setAfterFirstBeforeTokenOffset(next_tok_offset);
      next_sub.initAfterIds(0);

    } else {
      // This is a parsed token.
      std::optional<pasta::Token> pt = node.Token();
      std::optional<pasta::FileToken> ft = node.FileToken();
      std::optional<pasta::MacroToken> mt = node.MacroToken();
      if (!pt && mt) {
        pt = mt->ParsedLocation();
      }
      if (!ft && pt) {
        ft = pt->FileLocation();
      }
      if (!ft && mt) {
        ft = mt->FileLocation();
      }

      // Figure out the derived token id.
      mx::RawEntityId eid = mx::kInvalidEntityId;
      if (pt) {
        eid = DerivedTokenId(em, *pt);
      }

      if (eid == mx::kInvalidEntityId && ft) {
        eid = em.EntityId(*ft);
      }

      dtb.set(next_tok_offset, eid);
      tob.set(next_tok_offset, static_cast<uint32_t>(utf8_macro_data.size()));

      mx::TokenKind kind = mx::TokenKind::UNKNOWN;
      if (pt) {
        AccumulateTokenData(utf8_macro_data, *pt);
        kind = TokenKindFromPasta(*pt);
      } else if (ft) {
        AccumulateTokenData(utf8_macro_data, *ft);
        kind = TokenKindFromPasta(*ft);
      } else if (mt) {
        AccumulateTokenData(utf8_macro_data, *mt);
        kind = TokenKindFromPasta(*mt);
      }

      tkb.set(next_tok_offset, static_cast<uint16_t>(kind));

      // Recreate it; it should match what we did in `CountSubstitutions`.
      mx::MacroTokenId id;
      id.fragment_id = em.fragment.fragment_id;
      id.offset = next_tok_offset;
      id.kind = kind;
      eid = mx::EntityId(id).Pack();
      work.nib.set(i++, eid);

      ++next_tok_offset;
    }
  }

  work.sb.setAfterLastAfterTokenOffset(next_tok_offset);
}

// Persist the token tree, which is a tree of substitutions, i.e. before/after
// macro use/expansion, or x-macro file inclusion.
//
// The first N tokens are the original parsed tokens. After that, all tokens
// are macro tokens. The top-level substitution points to the macro code in
// before IDs, and the
static void PersistTokenTree(EntityMapper &em, mx::rpc::Fragment::Builder &fb,
                             TokenTree tt, const pasta::TokenRange &tokens,
                             uint64_t begin_index, uint64_t end_index) {

  unsigned num_parsed_tokens = 0u;
  unsigned token_data_size = 0u;
  for (auto i = begin_index; i <= end_index; ++i) {
    pasta::Token tok = tokens[i];
    if (IsParsedToken(tok)) {
      ++num_parsed_tokens;
      DCHECK(em.entity_ids.count(tok.RawToken()));

      token_data_size += static_cast<unsigned>(tok.Data().size());
      token_data_size += 1u;
    }
  }

  // Reserve space for token data.
  std::string utf8_fragment_data;
  utf8_fragment_data.reserve(token_data_size * 2u);

  // The kind applies to `lhs` (before).
  mx::MacroSubstitutionId id;
  id.fragment_id = em.fragment.fragment_id;
  id.kind = mx::MacroSubstitutionKind::PREPROCESSED_CODE;
  id.offset = 0u;
  em.entity_ids.emplace(tt.RawNode(), mx::EntityId(id).Pack());

  unsigned num_substitutions = 1u;  // For top-level one (id above).
  unsigned num_macro_tokens = num_parsed_tokens;

  // Count the number to tokens and substitutions. This has to be done in
  // the same order that we serialize things in, as we rely on our computations
  // of the IDs of things matching up.
  std::vector<TokenTree> count_todo;
  count_todo.emplace_back(tt);
  for (auto i = 0u; i < count_todo.size(); ++i) {
    CountSubstitutions(em, std::move(count_todo[i]), count_todo,
                       num_substitutions, num_macro_tokens);
  }

  SubstitutionListBuilder sb = fb.initSubstitutions(num_substitutions);
  TokenIdListBuilder dtb = fb.initDerivedTokenIds(num_macro_tokens);
  TokenKindListBuilder tkb = fb.initTokenKinds(num_macro_tokens);
  TokenOffsetListBuilder tob = fb.initTokenOffsets(num_macro_tokens + 1u);

  unsigned next_token_index = 0u;
  unsigned next_substitution_index = 0u;
  SubstitutionBuilder pp_sub = sb[next_substitution_index++];
  pp_sub.setKind(static_cast<uint8_t>(
      mx::MacroSubstitutionKind::PREPROCESSED_CODE));

  PersistTokens(em, tokens, begin_index, end_index, utf8_fragment_data,
                dtb, tkb, tob, pp_sub.initAfterIds(num_parsed_tokens),
                next_token_index, IsParsedToken);
  CHECK_EQ(next_token_index, num_parsed_tokens);

  std::vector<PersistTokenTreeWork> persist_todo;
  persist_todo.emplace_back(pp_sub, pp_sub.initBeforeIds(tt.NumNodes()), tt);
  for (auto i = 0u; i < persist_todo.size(); ++i) {
    PersistTokenTree(
        em, utf8_fragment_data, sb, dtb, tkb, tob, std::move(persist_todo[i]),
        persist_todo, next_token_index, next_substitution_index);
  }

  // These will be backward, because they apply to the top-level thing, and the
  // expansion info brought about by `persist_todo[0]` is really all of the
  // "before" for things.
  pp_sub.setFirstBeforeTokenOffset(pp_sub.getFirstAfterTokenOffset());
  pp_sub.setAfterLastAfterTokenOffset(pp_sub.getAfterLastAfterTokenOffset());

  pp_sub.setFirstAfterTokenOffset(0u);
  pp_sub.setAfterLastAfterTokenOffset(num_parsed_tokens);

  // Make sure that we add a final ending offset for token data.
  CHECK_EQ(next_token_index, num_macro_tokens);
  tob.set(next_token_index, static_cast<unsigned>(utf8_fragment_data.size()));
  utf8_fragment_data.push_back('\0');

  fb.setTokenData(utf8_fragment_data);
}

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
static uint64_t IdOfRedeclInFragment(EntityMapper &em, mx::RawEntityId frag_id,
                                     pasta::Decl canon_decl) {
  for (pasta::Decl redecl : canon_decl.Redeclarations()) {
    mx::EntityId eid = em.EntityId(redecl);
    if (eid == mx::kInvalidEntityId) {
      continue;
    }
    mx::VariantId vid = eid.Unpack();
    CHECK(std::holds_alternative<mx::DeclarationId>(vid));
    mx::DeclarationId id = std::get<mx::DeclarationId>(vid);
    if (id.fragment_id == frag_id) {
      return eid;
    }
  }

  return em.EntityId(canon_decl);
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
static void PersistTokenContexts(
    EntityMapper &em, const pasta::TokenRange &tokens,
    mx::RawEntityId frag_id, uint64_t begin_index, uint64_t end_index,
    mx::rpc::Fragment::Builder &fb) {

  using DeclContextSet = std::unordered_set<pasta::TokenContext>;
  std::map<mx::RawEntityId, DeclContextSet> contexts;

  // First, collect only the relevant contexts for this fragment. Group them by
  // entity ID, as we store the context list inline inside of the entities.
  unsigned num_tokens = 0u;
  for (auto i = begin_index; i <= end_index; ++i) {
    pasta::Token tok = tokens[i];
    if (!IsParsedToken(tok)) {
      continue;
    }

    ++num_tokens;

    for (auto context = tok.Context(); context; context = context->Parent()) {

      pasta::TokenContext c = context.value();
      if (auto alias_context = c.Aliasee()) {
        c = std::move(alias_context.value());
      }

      // NOTE(pag): PASTA stored the canonical decl in the decl context, so
      //            it's not likely to be in the current fragment.
      if (auto decl = pasta::Decl::From(c)) {
        const mx::RawEntityId eid = IdOfRedeclInFragment(em, frag_id, *decl);
        if (eid != mx::kInvalidEntityId) {
          contexts[eid].insert(context.value());
        }

      } else if (auto stmt = pasta::Stmt::From(c)) {
        const mx::RawEntityId eid = em.EntityId(*stmt);
        if (eid != mx::kInvalidEntityId) {
          contexts[eid].insert(context.value());
        }

      } else if (auto type = pasta::Type::From(c)) {
        const mx::RawEntityId eid = em.EntityId(*type);
        if (eid != mx::kInvalidEntityId) {
          contexts[eid].insert(context.value());
        }

      } else if (auto attr = pasta::Attr::From(c)) {
        const mx::RawEntityId eid = em.EntityId(*attr);
        if (eid != mx::kInvalidEntityId) {
          contexts[eid].insert(context.value());
        }
      
      } else if (auto designator = pasta::Designator::From(c)) {
        const uint32_t offset = em.PseudoId(*designator);
        mx::DesignatorId did;
        did.fragment_id = frag_id;
        did.offset = offset;
        const mx::RawEntityId eid = mx::EntityId(did);
        if (eid != mx::kInvalidEntityId) {
          contexts[eid].insert(context.value());
        }
      }
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
  CHECK_LE(begin_index, end_index);
  auto tcb_list = fb.initTokenContexts(num_contexts);
  auto tco_list = fb.initTokenContextOffsets(num_tokens);

  // Finally, serialize the contexts.
  num_tokens = 0u;
  for (auto i = begin_index; i <= end_index; ++i) {
    pasta::Token tok = tokens[i];
    if (!IsParsedToken(tok)) {
      continue;
    }

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
}

}  // namespace

// Persist a file. Our representation includes stuff not in the file to enable
// us to improve performance of common operations, like search. That is, we
// could store a file as a list of tokens, where each token has its own data;
// however, we want to able to run regular expression searches over files, and
// so it's convenient to not have to reconstruct the file data from the tokens
// for every such query. Similarly, we often want to map from matches in files
// to matches in fragments, and so we create and persist a mapping of file
// offsets to line numbers here to help us with those translations later.
void PersistFile(WorkerId worker_id, GlobalIndexingState &context,
                 mx::RawEntityId file_id, std::string file_hash,
                 pasta::File file) {

  auto maybe_file_data = file.Data();
  LOG_IF(FATAL, !maybe_file_data.Succeeded())
      << "No data for file " << file.Path().generic_string()
      << ": " << maybe_file_data.TakeError();

  pasta::FileTokenRange file_tokens = file.Tokens();
  std::string_view file_data = maybe_file_data.TakeValue();
  capnp::MallocMessageBuilder message;
  mx::rpc::File::Builder fb = message.initRoot<mx::rpc::File>();
  fb.setId(file_id);
  fb.setHash(file_hash);

  std::string utf8_file_data;
  utf8_file_data.reserve(file_data.size());

  // Encode the token kinds and the offsets of token data. We can't be certain
  // that the file is in UTF-8, so we re-build the contents on a per-token
  // basis, because that's the only way to guarantee token offsets in the
  // presence of UTF-8 issues.
  auto num_tokens = static_cast<unsigned>(file_tokens.Size());
  auto tkb = fb.initTokenKinds(num_tokens);
  auto tob = fb.initTokenOffsets(num_tokens + 1u);
  auto i = 0u;
  for (pasta::FileToken ft : file_tokens) {
    tkb.set(i, static_cast<unsigned short>(TokenKindFromPasta(ft)));
    tob.set(i, static_cast<unsigned>(utf8_file_data.size()));
    AccumulateTokenData(utf8_file_data, ft);
    i += 1u;
  }
  tob.set(i, static_cast<unsigned>(utf8_file_data.size()));

  // Cap'n Proto requires that `Text`-typed data is UTF-8.
  fb.setData(utf8_file_data);

  // Build up and serialize a mapping of offsets of the last byte in a line to
  // line numbers. This mapping is used during regular expression matches and
  // Weggli matches over file contents to help us map to fragments whose code
  // is derived from those files.
  std::map<unsigned, unsigned> eol_offset_to_line_num;
  auto line = 1u;
  auto offset = 0u;
  for (char ch : file_data) {
    ++offset;
    if ('\n' == ch) {
      eol_offset_to_line_num.emplace(offset, line);
      ++line;
    }
  }

  i = 0u;
  auto ublb = fb.initEolOffsets(static_cast<unsigned>(
      eol_offset_to_line_num.size()));
  for (auto eol_offset_line_num : eol_offset_to_line_num) {
    mx::rpc::UpperBound::Builder ubb = ublb[i++];
    ubb.setOffset(eol_offset_line_num.first);
    ubb.setVal(eol_offset_line_num.second);
  }

  context.PutSerializedFile(worker_id, file_id,
                            CompressedMessage("file", message));
}

// Return the file containing this fragment.
static std::optional<pasta::File> FragmentFile(const pasta::TokenRange &tokens,
                                               const PendingFragment &frag) {
  for (auto i = frag.begin_index; i <= frag.end_index; ++i) {
    auto file_tok = tokens[i].FileLocation();
    if (file_tok) {
      return pasta::File::Containing(file_tok.value());
    }
  }

  return std::nullopt;
}

// Persist a fragment. A fragment is Multiplier's "unit of granularity" of
// deduplication and indexing. It roughly corresponds to a sequence of one-or-
// more syntactically overlapping "top-level declarations." For us, a top-level
// declaration is one that only nested inside of a namespace, a linkage
// specifier, a translation unit, etc. Thus, things like global variables,
// functions, and classes are all top-level declarations. These things tend to
// contain lots of other declarations/statements, and those all get lumped into
// and persisted a TLD's fragment.
//
// Fragments separate out their lists of persistent entities. This enables some
// downstream benefits. For example, all declarations are persisted in a
// separate list from all statements. This allows us to more easily jump into
// the middle of the "sub-AST" persisted in a fragment. For example, if we want
// to find all `VarDecl`s, we can iterate the list of declarations, check the
// decl kinds, and then yield only the discovered `VarDecl`s. No recursive
// visitor needed!
//
// Fragments also store things like the macro substitution tree, and parsed
// tokens associated with the covered declarations/statements. This is partially
// because our serialized decls/stmts/etc. reference these tokens, and partially
// so that we can do things like print out fragments, or chunks thereof.
void PersistFragment(WorkerId worker_id, GlobalIndexingState &context,
                     pasta::AST &ast, NameMangler &mangler,
                     EntityIdMap &entity_ids, FileIdMap &file_ids,
                     const pasta::TokenRange &tokens, PendingFragment frag) {

  const mx::RawEntityId fragment_id = frag.fragment_id;
  const uint64_t begin_index = frag.begin_index;
  const uint64_t end_index = frag.end_index;

  auto maybe_file = FragmentFile(tokens, frag);
  if (!maybe_file) {
    auto main_file_path = ast.MainFile().Path().generic_string();
    if (!frag.top_level_decls.empty()) {
      const pasta::Decl &leader_decl = frag.top_level_decls.front();
      LOG(ERROR)
          << "Unable to locate file containing "
          << DeclToString(leader_decl)
          << PrefixedLocation(leader_decl, " at or near ")
          << " on main job file " << main_file_path;
    } else {
      LOG(ERROR)
          << "Unable to locate file containing macros on main job file "
          << main_file_path;
    }
    return;
  }

  capnp::MallocMessageBuilder message;
  mx::rpc::Fragment::Builder fb = message.initRoot<mx::rpc::Fragment>();

  // Identify all of the declarations, statements, types, and pseudo-entities,
  // and build lists of the entities to serialize.
  frag.Build(entity_ids, tokens);

  EntityMapper em(entity_ids, file_ids, frag);

  // Figure out parentage/inheritance between the entities.
  frag.LabelParents(em);

  // Serialize all discovered entities.
  frag.Serialize(em, fb);

  // Figure out the lines spanned by this code fragment.
  //
  // TODO(pag): Handle sub-ranges for x-macros? Probably should have something
  //            more robust that handles discontinuous ranges, just in case.
  pasta::File file = std::move(maybe_file.value());
  pasta::FileTokenRange file_tokens = file.Tokens();
  pasta::FileToken min_token = file_tokens[file_tokens.Size() - 1u];
  pasta::FileToken max_token = file_tokens[0];
  FindFileRange(tokens, begin_index, end_index, file, &min_token, &max_token);

  mx::RawEntityId file_id = em.FileId(file);
  fb.setId(fragment_id);
  fb.setFirstFileTokenId(em.EntityId(min_token));
  fb.setLastFileTokenId(em.EntityId(max_token));

  // Generate source IR before saving the fragments to the persistent
  // storage.
  fb.setMlir(context.codegen.GenerateSourceIRFromTLDs(
      fragment_id, em, frag.top_level_decls,
      frag.num_top_level_declarations));

  auto tlds = fb.initTopLevelDeclarations(frag.num_top_level_declarations);
  for (auto i = 0u; i < frag.num_top_level_declarations; ++i) {
    tlds.set(i, em.EntityId(frag.top_level_decls[i]));
  }

  // Derive the macro substitution tree. Failing to build the tree is an error
  // condition, but we can't let it stop us from actually serializing the
  // fragment or its data.
  bool is_fallback_token_tree = false;

  std::stringstream tok_tree_err;
  std::optional<TokenTree> maybe_tt = TokenTree::Create(
      tokens, begin_index, end_index, tok_tree_err, is_fallback_token_tree);
  if (!maybe_tt) {
    if (!frag.top_level_decls.empty()) {
      const pasta::Decl &leader_decl = frag.top_level_decls.front();
      LOG(ERROR)
          << tok_tree_err.str() << " for top-level declaration "
          << DeclToString(leader_decl)
          << PrefixedLocation(leader_decl, " at or near ")
          << " on main job file "
          << ast.MainFile().Path().generic_string();
    } else {
      LOG(ERROR)
          << tok_tree_err.str() << " for macros on main job file "
          << ast.MainFile().Path().generic_string();
    }

    fb.setHadSubstitutionError(true);

    // Try to create a simpler, fallback token tree.
    maybe_tt = TokenTree::Create(
        tokens, begin_index, end_index, tok_tree_err,
        is_fallback_token_tree  /* fallback */);

  } else {
    fb.setHadSubstitutionError(false);
  }

  // If we don't have the normal or the backup token tree, then do a best
  // effort saving of macro tokens. Don't bother organizing them into
  // substitutions because that will just replicate logic from the token
  // tree.
  if (!maybe_tt) {
    BackupPersistMacroTokens(em, tokens, begin_index, end_index, fb);

  // We have a token tree, or possibly a fallback token tree. The fallback
  // token trees aren't as nice because they lack whitespace.
  } else {
    PersistTokenTree(em, fb, std::move(maybe_tt.value()), tokens, begin_index,
                     end_index);
  }

  PersistTokenContexts(em, tokens, fragment_id, begin_index, end_index, fb);

  DCHECK_GT(fb.getTokenKinds().size(), 0u);

  context.PutFragmentLineCoverage(worker_id, file_id, fragment_id,
                                  min_token.Line(), max_token.Line());

  frag.LinkDeclarations(worker_id, context, em, mangler);
  frag.LinkReferences(worker_id, context, em);
  frag.FindDeclarationUses(worker_id, context, fb);

  context.PutSerializedFragment(
      worker_id, fragment_id, CompressedMessage("fragment", message));

  frag.PersistDeclarationSymbols(worker_id, context, em);
}

}  // namespace indexer
