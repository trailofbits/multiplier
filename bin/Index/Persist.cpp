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
#include <multiplier/AST.h>
#include <multiplier/ProgressBar.h>
#include <multiplier/RPC.capnp.h>
#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <sstream>
#include <utility>

#include "Compress.h"
#include "Context.h"
#include "TokenTree.h"
#include "Util.h"

namespace indexer {
namespace {

static void CountSubstitutions(TokenTree tt, unsigned &num_subs) {
  for (auto node : tt) {
    if (auto sub = node.Substitution()) {
      auto [kind, lhs, rhs] = std::move(sub.value());
      CountSubstitutions(std::move(lhs), num_subs);
      CountSubstitutions(std::move(rhs), num_subs);
      ++num_subs;
    }
  }
}

// Figure out the lines of `file` spanned by `tt`.
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
    } else if (auto sub = node.Substitution()) {
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

static void PersistTokenTree(EntitySerializer &serializer,
                             SubstitutionListBuilder &subs_builder,
                             TokenListBuilder toks_builder,
                             TokenTree tree, mx::FragmentId fragment_id,
                             unsigned &next_sub_offset) {
  unsigned i =0;
  for (TokenTreeNode node : tree) {
    if (std::optional<pasta::Token> pt = node.Token()) {
      toks_builder.set(i++, serializer.EntityId(pt.value()));

    } else if (std::optional<pasta::FileToken> ft = node.FileToken()) {
      toks_builder.set(i++, serializer.EntityId(ft.value()));

    } else if (auto sub = node.Substitution()) {
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
      PersistTokenTree(serializer, subs_builder,
                       next_sub.initBeforeTokens(num_nodes_lhs), std::move(lhs),
                       fragment_id, next_sub_offset);

      unsigned num_nodes_rhs = rhs.NumNodes();
      PersistTokenTree(serializer, subs_builder,
                       next_sub.initAfterTokens(num_nodes_rhs), std::move(rhs),
                       fragment_id, next_sub_offset);
    }
  }
}

static void PersistTokens(EntitySerializer &serializer,
                          uint64_t begin_index, uint64_t end_index,
                          FragmentBuilder &builder) {
  auto num_toks = static_cast<unsigned>(
      (end_index - begin_index) + 1u);
  auto tok_builder = builder.initTokens(num_toks);
  for (auto i = begin_index; i <= end_index; ++i) {
    serializer.Serialize(
        tok_builder[static_cast<unsigned>(i - begin_index)],
        serializer.range[i]);
  }
}

static void PersistTokenContexts(EntitySerializer &serializer,
                                 uint64_t begin_index, uint64_t end_index,
                                 FragmentBuilder &builder) {

  using DeclContextSet = std::unordered_set<pasta::TokenContext>;
  std::unordered_map<uint64_t, DeclContextSet> contexts;

  // First, collect only the relevant contexts for this fragment. Group them by
  // entity ID, as we store the context list inline inside of the entities.
  for (auto i = begin_index; i <= end_index; ++i) {
    for (auto context = serializer.range[i].Context();
         context; context = context->Parent()) {

      auto c = *context;
      if (auto alias_context = context->Aliasee()) {
        c = *alias_context;
      }

      if (auto decl = pasta::Decl::From(c)) {
        if (auto eid = serializer.EntityId(*decl);
            eid != mx::kInvalidEntityId) {
          contexts[eid].insert(*context);
        }

      } else if (auto stmt = pasta::Stmt::From(c)) {
        if (auto eid = serializer.EntityId(*stmt);
            eid != mx::kInvalidEntityId) {
          contexts[eid].insert(*context);
        }
      }

      // TODO(pag): Types!
    }
  }

  struct PendingTokenContext {
    enum Kind {
      kInvalid,
      kDecl,
      kDeclAlias,
      kStmt,
      kStmtAlias,
    } kind{kInvalid};

    uint64_t entity_id{0};
    unsigned index{0};
    unsigned offset{0};
    unsigned alias_offset{0};
  };

  std::unordered_map<pasta::TokenContext, PendingTokenContext>
      pending_contexts;

  unsigned num_tokens = static_cast<unsigned>(end_index - begin_index + 1u);
  unsigned num_contexts = num_tokens;

  // Figure out the kinds of the contexts (stmt, decl), the index into the
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
      if (id.fragment_id != serializer.code_id) {
        continue;  // E.g. translation unit.
      }

      tpl.index = id.offset;
      tpl.kind = PendingTokenContext::kDecl;

    // Statements.
    } else if (std::holds_alternative<mx::StatementId>(vid)) {
      mx::StatementId id = std::get<mx::StatementId>(vid);
      if (id.fragment_id != serializer.code_id) {
        continue;  // Not sure how but oh well.
      }

      tpl.index = id.offset;
      tpl.kind = PendingTokenContext::kStmt;

    } else {
      LOG(FATAL)
          << "Unsupported entity kind";
    }

    // Then, specialize this template for each context we encounter.
    for (const pasta::TokenContext &context : entity_contexts) {
      PendingTokenContext &info = pending_contexts[context];
      CHECK(info.kind == PendingTokenContext::kInvalid);
      info = tpl;  // Copy the template.
      CHECK(info.kind != PendingTokenContext::kInvalid);

      // Adjust the kind to be an aliasee.
      if (context.Aliasee()) {
        info.kind = static_cast<PendingTokenContext::Kind>(
            static_cast<int>(tpl.kind) + 1);
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
      CHECK(info.kind != PendingTokenContext::kInvalid);

      if (auto alias_context = context.Aliasee()) {
        PendingTokenContext &alias_info = pending_contexts[*alias_context];
        CHECK(alias_info.kind != PendingTokenContext::kInvalid);
        CHECK_EQ(info.index, alias_info.index);
        CHECK_NE(info.offset, alias_info.offset);
        info.alias_offset = alias_info.offset;
      }
    }
  }

  // Allocate as many token contexts as there are parsed tokens.
  CHECK_LE(begin_index, end_index);
  auto tc_list = builder.initTokenContexts(num_contexts);

  // Finally, serialize the contexts.
  auto j = 0u;
  for (auto i = begin_index; i <= end_index; ++i) {

    std::optional<mx::rpc::TokenContext::Builder> tcb;
    tcb.emplace(tc_list[j++]);

    for (auto context = serializer.range[i].Context();
         context; context = context->Parent()) {

      pasta::TokenContext c = *context;
      auto pc_it = pending_contexts.find(c);
      if (pc_it == pending_contexts.end()) {
        continue;  // E.g. translation unit contexts.
      }

      const PendingTokenContext &info = pc_it->second;

      CHECK_GE(info.offset, num_tokens);

      tcb->setParentOffset(info.offset);
      tcb->setAliasOffset(info.alias_offset);

      // Low bit of the index tells us this is present.
      switch (info.kind) {
        case PendingTokenContext::kDecl:
          CHECK_EQ(info.alias_offset, 0);
          tcb->setParentIndexAndKind((info.index << 3u) | 1u);  // 001
          break;
        case PendingTokenContext::kDeclAlias:
          tcb->setParentIndexAndKind((info.index << 3u) | 3u);  // 011
          break;
        case PendingTokenContext::kStmt:
          CHECK_EQ(info.alias_offset, 0);
          tcb->setParentIndexAndKind((info.index << 3u) | 5u);  // 101
          break;
        case PendingTokenContext::kStmtAlias:
          tcb->setParentIndexAndKind((info.index << 3u) | 7u);  // 111
          break;
        default:
          LOG(FATAL)
              << "Unsupported context kind";
      }

      // Set up the next link in the chain.
      tcb.reset();
      tcb.emplace(tc_list[info.offset]);
    }
  }
}

}  // namespace

void PersistFile(IndexingContext &context, mx::FileId file_id,
                 std::string file_hash, pasta::File file) {
  auto file_tokens = file.Tokens();

  capnp::MallocMessageBuilder message;
  auto fb = message.initRoot<mx::rpc::File>();
  fb.setId(file_id);
  fb.setHash(file_hash);
  auto tsb = fb.initTokens(static_cast<unsigned>(file_tokens.Size()));
  std::string tok_data;
  for (pasta::FileToken ft : file_tokens) {
    tok_data.clear();
    tok_data.insert(tok_data.end(), ft.Data().begin(), ft.Data().end());
    mx::rpc::Token::Builder ftb = tsb[static_cast<unsigned>(ft.Index())];
    ftb.setKind(static_cast<unsigned short>(TokenKindFromPasta(ft)));
    ftb.setData(tok_data);
  }

  context.PutSerializedFile(file_id, CompressedMessage("file", message));
}

void PersistFragment(IndexingContext &context, EntitySerializer &serializer,
                     PendingFragment code_chunk) {

  const mx::FragmentId code_id = code_chunk.fragment_id;
  const pasta::Decl &leader_decl = code_chunk.decls[0];
  mx::Result<TokenTree, std::string> maybe_tt = TokenTree::Create(
      serializer.range, code_chunk.begin_index, code_chunk.end_index);
  if (!maybe_tt.Succeeded()) {
    auto main_file_path =
        pasta::AST::From(leader_decl).MainFile().Path().generic_string();
    LOG(ERROR)
        << maybe_tt.TakeError() << " for top-level declaration "
        << DeclToString(leader_decl)
        << PrefixedLocation(leader_decl, " at or near ")
        << " on main job file " << main_file_path;
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

  mx::FileId file_id = serializer.FileId(file);
  context.PutFragmentLineCoverage(file_id, code_id, min_token.Line(),
                                  max_token.Line());

  capnp::MallocMessageBuilder message;
  mx::rpc::Fragment::Builder builder = message.initRoot<mx::rpc::Fragment>();
  builder.setCodeId(code_chunk.fragment_id);
  builder.setFileTokenId(serializer.EntityId(min_token));
  builder.setFirstLine(min_token.Line());
  builder.setLastLine(max_token.Line());

  auto num_tlds = static_cast<unsigned>(code_chunk.decls.size());
  auto tlds = builder.initTopLevelDeclarations(num_tlds);
  for (auto i = 0u; i < num_tlds; ++i) {
    tlds.set(i, serializer.EntityId(code_chunk.decls[i]));
  }

  const auto begin_index = code_chunk.begin_index;
  const auto end_index = code_chunk.end_index;

  serializer.SerializeCodeEntities(std::move(code_chunk), builder);

  PersistTokens(serializer, begin_index, end_index, builder);
  PersistTokenContexts(serializer, begin_index, end_index, builder);

  DCHECK_GT(builder.getTokens().size(), 0u);
  DCHECK_GE(builder.getTokenContexts().size(), builder.getTokens().size());

  unsigned next_substitution_index = 0u;
  SubstitutionListBuilder substitutions_builder =
      builder.initTokenSubstitutions(num_substitutions);
  PersistTokenTree(
      serializer,
      substitutions_builder,
      builder.initUnparsedTokens(token_tree.NumNodes()),
      std::move(token_tree),
      code_chunk.fragment_id,
      next_substitution_index);
  CHECK_EQ(next_substitution_index, num_substitutions);

  context.PutSerializedFragment(
      code_id, CompressedMessage("fragment", message));
}

}  // namespace indexer
