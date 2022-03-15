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
#include <multiplier/RPC.capnp.h>
#include <utility>

namespace indexer {

TokenizeFileAction::~TokenizeFileAction(void) {}

TokenizeFileAction::TokenizeFileAction(
    std::shared_ptr<IndexingContext> context_,
    mx::FileId file_id_, std::string file_hash_, pasta::File file_)
    : context(std::move(context_)),
      file_id(file_id_),
      file_hash(std::move(file_hash_)),
      file(std::move(file_)) {}

// Build and index the AST.
void TokenizeFileAction::Run(mx::Executor exe, mx::WorkerId worker_id) {
  mx::ProgressBarWork progress_tracker(context->tokenizer_progress.get());
  auto file_tokens = file.Tokens();

  capnp::MallocMessageBuilder message;
  auto fb = message.initRoot<mx::rpc::File>();
  fb.setId(file_id);
  fb.setHash(file_hash);
  auto tsb = fb.initTokens(static_cast<unsigned>(file_tokens.Size()));
  for (pasta::FileToken ft : file_tokens) {
    mx::ast::FileToken::Builder ftb = tsb[static_cast<unsigned>(ft.Index())];
    ftb.setKind(static_cast<mx::ast::TokenKind>(mx::FromPasta(ft.Kind())));
    ftb.setPreProcessorKeywordKind(static_cast<mx::ast::PPKeywordKind>(
        mx::FromPasta(ft.PreProcessorKeywordKind())));
    ftb.setObjectiveCAtKeywordKind(static_cast<mx::ast::ObjCKeywordKind>(
        mx::FromPasta(ft.ObjectiveCAtKeywordKind())));
    ftb.setLine(ft.Line());
    ftb.setColumn(ft.Column());
    ftb.setData(kj::StringPtr(ft.Data().data(), ft.Data().size()));
  }

  context->PutFileTokens(file_id, capnp::messageToFlatArray(message));
}

}  // namespace indexer
