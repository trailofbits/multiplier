// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "TokenizeFile.h"

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
#include <utility>

#include "Context.h"
#include "Util.h"

namespace indexer {

void TokenizeFile(IndexingContext &context, mx::FileId file_id,
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

  context.PutFileTokens(file_id, capnp::messageToFlatArray(message));
}

}  // namespace indexer
