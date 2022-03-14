// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "TokenizeFile.h"

#include <algorithm>
#include <capnp/message.h>
#include <glog/logging.h>
#include <kj/string-tree.h>
#include <multiplier/Token.h>

#include <fstream>
#include <utility>

namespace indexer {

TokenizeFileAction::~TokenizeFileAction(void) {}

TokenizeFileAction::TokenizeFileAction(
    std::shared_ptr<IndexingContext> context_,
    mx::FileId file_id_, pasta::File file_)
    : context(std::move(context_)),
      file_id(file_id_),
      file(std::move(file_)) {}

// Build and index the AST.
void TokenizeFileAction::Run(mx::Executor exe, mx::WorkerId worker_id) {
  mx::ProgressBarWork progress_tracker(context->tokenizer_progress.get());

  auto path = file.Path().generic_string();
  auto maybe_contents = file.Data();
  if (!maybe_contents.Succeeded()) {
    LOG(ERROR)
        << "Unable to read contents of file " << path
        << ": " << maybe_contents.TakeError().message();
    return;
  }

  auto pasta_file_tokens = file.Tokens();
  auto file_tokens = mx::TokenList::Create(pasta_file_tokens);

  // PASTA file token lists have an `eof` token at the end; we strip it.
  CHECK_EQ(file_tokens.Size() + 1u, pasta_file_tokens.Size());



  (void) file_id;

  auto maybe_tokens = file_tokens.Pack();
  if (!maybe_tokens.Succeeded()) {
    LOG(ERROR)
        << "Unable to compress tokens from file '"
        << file.Path().generic_string() << "': " << maybe_tokens.TakeError();
    return;
  }

//  // Warn if our compression doesn't actually compress things.
//  LOG_IF(WARNING, file_tokens.Data().size() <= builder.totalSize())
//      << "Raw data needs " << file_tokens.Data().size()
//      << " bytes, compressed flatbuffer needs "
//      << fbb.GetSize() << " bytes";

  context->PutFileTokens(file_id, maybe_tokens.TakeValue());
}

}  // namespace indexer
