// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Persist.h"

#include <algorithm>
#include <capnp/common.h>
#include <capnp/message.h>
#include <capnp/serialize.h>
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

#include "Context.h"
#include "TokenTree.h"
#include "Util.h"

namespace indexer {

void PersistFile(IndexingContext &context, mx::FileId file_id,
                 std::string file_hash, pasta::File file) {
  mx::ProgressBarWork progress_tracker(context.tokenizer_progress.get());
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
    mx::ast::Token::Builder ftb = tsb[static_cast<unsigned>(ft.Index())];
    ftb.setKind(static_cast<mx::ast::TokenKind>(TokenKindFromPasta(ft)));
    ftb.setData(tok_data);
  }

  context.PutSerializedFile(file_id, capnp::messageToFlatArray(message));
}

static void CountSubstitutions(TokenTree tt, unsigned *num_subs) {
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
                          unsigned *num_subs) {
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
      ++*num_subs;
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

void PersistFragment(IndexingContext &context, EntitySerializer &serializer,
                     CodeChunk code_chunk) {

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
  FindFileRange(token_tree, file, &min_token, &max_token, &num_substitutions);

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

  serializer.SerializeCodeEntities(std::move(code_chunk),
                                   builder.initEntities());

  unsigned next_substitution_index = 0u;
  SubstitutionListBuilder substitutions_builder =
      builder.initTokenSubstitutions(num_substitutions);
  PersistTokenTree(
      serializer,
      substitutions_builder,
      builder.initTokens(token_tree.NumNodes()),
      std::move(token_tree),
      code_chunk.fragment_id,
      next_substitution_index);
  CHECK_EQ(next_substitution_index, num_substitutions);

  context.PutSerializedFragment(code_id, capnp::messageToFlatArray(message));
}

}  // namespace indexer
