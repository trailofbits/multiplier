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

  capnp::MallocMessageBuilder message;
  mx::rpc::Fragment::Builder builder = message.initRoot<mx::rpc::Fragment>();
  builder.setCodeId(code_chunk.fragment_id);

  auto num_tlds = static_cast<unsigned>(code_chunk.decls.size());
  auto tlds = builder.initTopLevelDeclarations(num_tlds);
  for (auto i = 0u; i < num_tlds; ++i) {
    tlds.set(i, serializer.EntityId(code_chunk.decls[i]));
  }
  serializer.SerializeCodeEntities(std::move(code_chunk),
                                   builder.initEntities());

  context.PutSerializedFragment(code_id, capnp::messageToFlatArray(message));
}

}  // namespace indexer
