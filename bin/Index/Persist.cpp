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
#include <kj/string-tree.h>
#include <llvm/Support/JSON.h>
#include <multiplier/AST.h>
#include <multiplier/ProgressBar.h>
#include <multiplier/RPC.capnp.h>
#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <sstream>
#include <utility>

#include "Codegen.h"
#include "Compress.h"
#include "Context.h"
#include "EntityMapper.h"
#include "TokenTree.h"
#include "Util.h"

namespace indexer {
namespace {

// Count the number of substitutions in a token tree. We need to pre-initialize
// the total size of lists in Cap'n Proto, and so we need to know how many
// substitutions we'll want to store when serializing a fragment, as the
// serialized fragments contain the macro substitution tree (e.g. to help us
// print out the "unparsed", i.e. original, code of a fragment).
static void CountSubstitutions(TokenTree tt, unsigned &num_subs) {
  for (auto node : tt) {
    if (auto sub = node.MaybeSubstitution()) {
      auto [kind, lhs, rhs] = std::move(sub.value());
      CountSubstitutions(std::move(lhs), num_subs);
      CountSubstitutions(std::move(rhs), num_subs);
      ++num_subs;
    }
  }
}

// Figure out the lines of `file` spanned by `tt`. We use this to help us
// populate an index (persistent set) of `<file_id, line_num, frag_id>` triples.
// This index helps us go from matches (e.g. RE2) in files to matches in
// fragments.
static void FindFileRange(TokenTree tt, const pasta::File &file,
                          pasta::FileToken *min, pasta::FileToken *max,
                          unsigned &num_subs) {
  if (tt.File() != file) {
    return;
  }

  for (auto node : tt) {
    if (auto ft = node.FileToken()) {
      DCHECK(pasta::File::Containing(*ft) == file);
      if (ft->Index() < min->Index()) {
        *min = *ft;
      }
      if (ft->Index() > max->Index()) {
        *max = *ft;
      }
    } else if (auto sub = node.MaybeSubstitution()) {
      auto [kind, lhs, rhs] = std::move(sub.value());
      FindFileRange(std::move(lhs), file, min, max, num_subs);
      CountSubstitutions(std::move(rhs), num_subs);
      ++num_subs;
    }
  }
}

using SubstitutionListBuilder =
    capnp::List<mx::rpc::TokenSubstitution, capnp::Kind::STRUCT>::Builder;

using TokenListBuilder =
    capnp::List<uint64_t, ::capnp::Kind::PRIMITIVE>::Builder;

// Persist the token tree, which is a tree of substitutions, i.e. before/after
// macro use/expansion, or x-macro file inclusion.
static void PersistTokenTree(EntityMapper &em,
                             SubstitutionListBuilder &subs_builder,
                             TokenListBuilder toks_builder,
                             TokenTree tree, mx::RawEntityId fragment_id,
                             unsigned &next_sub_offset) {
  unsigned i =0;
  for (TokenTreeNode node : tree) {
    if (std::optional<pasta::Token> pt = node.Token()) {
      toks_builder.set(i++, em.EntityId(pt.value()));

    } else if (std::optional<pasta::FileToken> ft = node.FileToken()) {
      toks_builder.set(i++, em.EntityId(ft.value()));

    } else if (auto sub = node.MaybeSubstitution()) {
      auto [kind, lhs, rhs] = std::move(sub.value());
      mx::TokenSubstitutionId sub_id;
      sub_id.fragment_id = fragment_id;
      sub_id.kind = kind;
      sub_id.offset = next_sub_offset;
      mx::EntityId id(sub_id);
      toks_builder.set(i++, id);

      mx::rpc::TokenSubstitution::Builder next_sub =
          subs_builder[next_sub_offset++];

      unsigned num_nodes_lhs = lhs.NumNodes();
      PersistTokenTree(em, subs_builder,
                       next_sub.initBeforeTokens(num_nodes_lhs), std::move(lhs),
                       fragment_id, next_sub_offset);

      unsigned num_nodes_rhs = rhs.NumNodes();
      PersistTokenTree(em, subs_builder,
                       next_sub.initAfterTokens(num_nodes_rhs), std::move(rhs),
                       fragment_id, next_sub_offset);
    }
  }
}

// Persist the tokens of a fragment.
static void PersistTokens(EntityMapper &em, const pasta::TokenRange &tokens,
                          uint64_t begin_index, uint64_t end_index,
                          mx::rpc::Fragment::Builder &fb) {
  auto num_tokens = static_cast<unsigned>(
      (end_index - begin_index) + 1u);

  unsigned token_data_size = 0u;
  for (auto i = begin_index; i <= end_index; ++i) {
    pasta::Token tok = tokens[i];
    token_data_size += static_cast<unsigned>(tok.Data().size());
    token_data_size += 1u;
  }

  std::string utf8_fragment_data;
  utf8_fragment_data.reserve(token_data_size);

  // Encode the token kinds and the offsets of token data. We can't be certain
  // that the file is in UTF-8, so we re-build the contents on a per-token
  // basis, because that's the only way to guarantee token offsets in the
  // presence of UTF-8 issues.
  auto ftb = fb.initFileTokenIds(num_tokens);
  auto tkb = fb.initTokenKinds(num_tokens);
  auto tob = fb.initTokenOffsets(num_tokens + 1u);
  auto j = 0u;
  for (auto i = begin_index; i <= end_index; ++i, ++j) {

    pasta::Token tok = tokens[i];
    if (auto file_tok = tok.FileLocation()) {
      ftb.set(j, em.EntityId(*file_tok));
    } else {
      ftb.set(j, mx::kInvalidEntityId);
    }

    tkb.set(j, static_cast<unsigned short>(TokenKindFromPasta(tok)));
    tob.set(j, static_cast<unsigned>(utf8_fragment_data.size()));

    llvm::StringRef tok_data = tok.Data();
    if (llvm::json::isUTF8(tok_data)) {
      utf8_fragment_data.insert(utf8_fragment_data.end(),
                                tok_data.begin(), tok_data.end());

    } else {
      utf8_fragment_data += llvm::json::fixUTF8(tok_data);
    }

    // Space-separate every token.
    //
    // NOTE(pag): This means that `PackedFragmentImpl::NthTokenData` needs
    //            to account for this additional space.
    utf8_fragment_data.push_back(' ');
  }

  tob.set(j, static_cast<unsigned>(utf8_fragment_data.size()));

  // Cap'n Proto requires that `Text`-typed data is UTF-8.
  fb.setParsedTokenData(utf8_fragment_data);
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
  for (auto i = begin_index; i <= end_index; ++i) {
    for (auto context = tokens[i].Context();
         context; context = context->Parent()) {

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

  unsigned num_tokens = static_cast<unsigned>(end_index - begin_index + 1u);
  unsigned num_contexts = 0;

  // Figure out the kinds of the contexts (stmt, decl, type), the index into the
  // respective entity list in the serialized fragment where the contexts will
  // be placed, the offset at which each context will reside within an entity-
  // specific list, etc.
  for (const auto &entry : contexts) {
    mx::VariantId vid = mx::EntityId(entry.first).Unpack();
    const DeclContextSet &entity_contexts = entry.second;

    // First, make a "template" of the context info, based on the entity kind
    // and fragment info.
    PendingTokenContext tpl;
    tpl.entity_id = entry.first;

    // Declarations.
    if (std::holds_alternative<mx::DeclarationId>(vid)) {
      mx::DeclarationId id = std::get<mx::DeclarationId>(vid);
      if (id.fragment_id != frag_id) {
        continue;  // E.g. translation unit.
      }

    // Statements.
    } else if (std::holds_alternative<mx::StatementId>(vid)) {
      mx::StatementId id = std::get<mx::StatementId>(vid);
      if (id.fragment_id != frag_id) {
        continue;  // Not sure how but oh well.
      }

    // Types.
    } else if (std::holds_alternative<mx::TypeId>(vid)) {
      mx::TypeId id = std::get<mx::TypeId>(vid);
      if (id.fragment_id != frag_id) {
        continue;  // Not sure how but oh well.
      }

    } else {
      LOG(FATAL)
          << "Unsupported entity kind";
    }

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
  for (auto i = begin_index; i <= end_index; ++i) {

    std::optional<mx::rpc::TokenContext::Builder> tcb;
    bool has_context = false;
    pasta::Token tok = tokens[i];
    for (auto context = tok.Context(); context; context = context->Parent()) {

      pasta::TokenContext c = *context;
      auto pc_it = pending_contexts.find(c);
      if (pc_it == pending_contexts.end()) {
        continue;  // E.g. translation unit contexts, attributes.
      }

      const PendingTokenContext &info = pc_it->second;

      if (!tcb) {
        has_context = true;
        tco_list.set(static_cast<unsigned>(i - begin_index),
                     (info.offset << 1u) | 1u);
      } else {
        assert(has_context);
        tcb->setParentIndex((info.offset << 1u) | 1u);
      }

      CHECK_NE(info.entity_id, mx::kInvalidEntityId);

      tcb.reset();
      tcb.emplace(tcb_list[info.offset]);
      tcb->setEntityId(info.entity_id);

      if (info.is_alias) {
        tcb->setAliasIndex((info.alias_offset << 1u) | 1u);
      }
    }

    // Didn't get any contexts for this token.
    if (!has_context) {
      tco_list.set(static_cast<unsigned>(i - begin_index), 0u);
    }
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
void PersistFile(IndexingContext &context, mx::RawEntityId file_id,
                 std::string file_hash, pasta::File file) {
  auto file_tokens = file.Tokens();
  auto maybe_file_data = file.Data();
  LOG_IF(FATAL, !maybe_file_data.Succeeded())
      << "No data for file " << file.Path().generic_string()
      << ": " << maybe_file_data.TakeError();

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

    llvm::StringRef tok_data = ft.Data();
    if (llvm::json::isUTF8(tok_data)) {
      utf8_file_data.insert(utf8_file_data.end(),
                            tok_data.begin(), tok_data.end());

    } else {
      utf8_file_data += llvm::json::fixUTF8(tok_data);
    }

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
  for (auto [eol_offset, line_num] : eol_offset_to_line_num) {
    mx::rpc::UpperBound::Builder ubb = ublb[i++];
    ubb.setOffset(eol_offset);
    ubb.setVal(line_num);
  }

  context.PutSerializedFile(file_id, CompressedMessage("file", message));
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
void PersistFragment(IndexingContext &context, pasta::AST &ast, NameMangler &mangler,
                     EntityIdMap &entity_ids, FileIdMap &file_ids,
                     const pasta::TokenRange &tokens,
                     PendingFragment frag, mx::WorkerId worker_id) {

  capnp::MallocMessageBuilder message;
  mx::rpc::Fragment::Builder fb = message.initRoot<mx::rpc::Fragment>();

  // Identify all of the declarations, statements, types, and pseudo-entities,
  // and build lists of the entities to serialize.
  frag.Build(entity_ids, file_ids, tokens);

  EntityMapper em(entity_ids, file_ids, frag);

  // Figure out parentage/inheritance between the entities.
  frag.LabelParents(em);

  // Serialize all discovered entities.
  frag.Serialize(em, fb);

  const mx::RawEntityId fragment_id = frag.fragment_id;
  const pasta::Decl &leader_decl = frag.decls[0];
  const uint64_t begin_index = frag.begin_index;
  const uint64_t end_index = frag.end_index;

  // Derive the macro substitution tree.
  mx::Result<TokenTree, std::string> maybe_tt = TokenTree::Create(
      tokens, frag.begin_index, frag.end_index);
  if (!maybe_tt.Succeeded()) {
    auto main_file_path =
        pasta::AST::From(leader_decl).MainFile().Path().generic_string();
    LOG(ERROR)
        << maybe_tt.TakeError() << " for top-level declaration "
        << DeclToString(leader_decl)
        << PrefixedLocation(leader_decl, " at or near ")
        << " on main job file " << main_file_path;
    return;
  }

  TokenTree token_tree = maybe_tt.TakeValue();

  unsigned num_substitutions{0u};

  // Figure out the lines spanned by this code fragment.
  //
  // TODO(pag): Handle sub-ranges for x-macros? Probably should have something
  //            more robust that handles discontinuous ranges, just in case.
  pasta::File file = token_tree.File();
  pasta::FileTokenRange file_tokens = file.Tokens();
  pasta::FileToken min_token = file_tokens[file_tokens.Size() - 1u];
  pasta::FileToken max_token = file_tokens[0];
  FindFileRange(token_tree, file, &min_token, &max_token, num_substitutions);

  mx::RawEntityId file_id = em.FileId(file);
  fb.setId(fragment_id);
  fb.setFirstFileTokenId(em.EntityId(min_token));
  fb.setLastFileTokenId(em.EntityId(max_token));

  // Generate source IR before saving the fragments to the persistent
  // storage.
  fb.setMlir(ConvertToSourceIR(context, fragment_id, frag.decls));

  auto num_tlds = static_cast<unsigned>(frag.decls.size());
  auto tlds = fb.initTopLevelDeclarations(num_tlds);
  for (auto i = 0u; i < num_tlds; ++i) {
    tlds.set(i, em.EntityId(frag.decls[i]));
  }

  PersistTokens(em, tokens, begin_index, end_index, fb);
  PersistTokenContexts(em, tokens, fragment_id, begin_index, end_index, fb);

  DCHECK_GT(fb.getTokenKinds().size(), 0u);

  unsigned next_substitution_index = 0u;
  SubstitutionListBuilder substitutions_builder =
      fb.initTokenSubstitutions(num_substitutions);
  PersistTokenTree(
      em,
      substitutions_builder,
      fb.initUnparsedTokens(token_tree.NumNodes()),
      std::move(token_tree),
      frag.fragment_id,
      next_substitution_index);
  CHECK_EQ(next_substitution_index, num_substitutions);

  context.PutFragmentLineCoverage(file_id, fragment_id, min_token.Line(),
                                  max_token.Line());

  frag.LinkDeclarations(context, em, mangler);
  frag.LinkReferences(context, em);
  frag.FindDeclarationUses(context, fb);

  context.PutSerializedFragment(
      fragment_id, CompressedMessage("fragment", message));

  frag.PersistDeclarationSymbols(context, em, ast, worker_id);
}

}  // namespace indexer
