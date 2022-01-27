// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "TokenizeFile.h"

#include <algorithm>
#include <glog/logging.h>
#include <multiplier/Datalog.h>
#include <multiplier/Token.h>

#include "Context.h"

#include <fstream>

namespace indexer {
#if DCHECK_IS_ON()
namespace {

// Do some sanity checking on the token list compression to make sure we
// don't introduce issues right away.
static bool CheckTokenLists(
    const std::string &file_path, mx::TokenList file_tokens,
    const mx::CompressedTokenList *compressed_tokens) {
  auto maybe_uncompressed = mx::TokenList::Create(compressed_tokens);
  if (maybe_uncompressed.Succeeded()) {
    auto uncompressed_file_tokens = maybe_uncompressed.TakeValue();
    auto orig_num_toks = file_tokens.Size();
    auto new_num_toks = uncompressed_file_tokens.Size();
    if (orig_num_toks != new_num_toks) {
      LOG(ERROR)
          << "Uncompressed token list for file " << file_path << " has "
          << orig_num_toks << " tokens, but compressed token list only has "
          << new_num_toks << " tokens";
      return false;
    }

    if (!std::equal(file_tokens.begin(), file_tokens.end(),
                      uncompressed_file_tokens.begin(),
                      uncompressed_file_tokens.end())) {

      LOG(ERROR)
          << "One or more of the tokens in the file " << file_path
          << " does not match corresponding tokens from the uncompressed "
             "token list";
      return false;
    }

    return true;
  } else {
    LOG(ERROR)
        << "Unable to uncompress just-created compressed file token list: "
        << maybe_uncompressed.TakeError();
    return false;
  }
}

}  // namespace
#endif  // DCHECK_IS_ON()

TokenizeFileAction::~TokenizeFileAction(void) {}

TokenizeFileAction::TokenizeFileAction(std::shared_ptr<Context> context_,
                                       pasta::File file_)
    : context(std::move(context_)),
      progress(context->tokenizer_progress),
      file(std::move(file_)) {}

// Build and index the AST.
void TokenizeFileAction::Run(mx::Executor exe, mx::WorkerId worker_id) {
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
  CHECK_EQ(file_tokens.Size(), pasta_file_tokens.Size());

  flatbuffers::FlatBufferBuilder fbb;
  auto maybe_offset = file_tokens.Compress(fbb);
  if (maybe_offset.Succeeded()) {
    fbb.Finish(maybe_offset.TakeValue());

    // Warn if our compression doesn't actually compress things.
    LOG_IF(WARNING, file_tokens.Data().size() <= fbb.GetSize())
        << "Raw data needs " << file_tokens.Data().size()
        << " bytes, compressed flatbuffer needs "
        << fbb.GetSize() << " bytes";

#if DCHECK_IS_ON()
    auto compressed_tokens = flatbuffers::GetRoot<mx::CompressedTokenList>(
        fbb.GetBufferPointer());
    if (!CheckTokenLists(path, file_tokens, compressed_tokens)) {
      return;
    }
#endif

  } else {
    LOG(ERROR)
        << "Error serializing token list for file " << path << ": "
        << maybe_offset.TakeError();
    return;
  }
}

}  // namespace indexer
