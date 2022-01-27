// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "TokenizeFile.h"

#include <glog/logging.h>
#include <multiplier/Datalog.h>
#include <multiplier/Token.h>

#include "Context.h"

#include <fstream>

namespace indexer {

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

  auto file_tokens = mx::TokenList::Create(file.Tokens());

  flatbuffers::FlatBufferBuilder fbb;
  auto maybe_offset = file_tokens.Compress(fbb);
  if (maybe_offset.Succeeded()) {
    fbb.Finish(maybe_offset.TakeValue());
//    LOG(INFO)
//        << "Raw data needs " << file_tokens.Data().size()
//        << " bytes, compressed flatbuffer needs "
//        << fbb.GetSize() << " bytes";

    auto compressed = flatbuffers::GetRoot<mx::CompressedTokenList>(
        fbb.GetBufferPointer());

    auto maybe_uncompressed = mx::TokenList::Create(compressed);
    if (maybe_uncompressed.Succeeded()) {
      auto tl = maybe_uncompressed.TakeValue();
//      LOG(INFO)
//          << "Uncompressed raw data needs " << tl.Data().size()
//          << " bytes and original needs " << file_tokens.Data().size();

      static std::atomic<int> x;
      if (tl.Data() != file_tokens.Data()) {
//        LOG(ERROR)
//            << "Error! Uncompressed data is different!";
        auto i = std::to_string(x.fetch_add(1));
        std::ofstream fs("/tmp/diff/" + i + ".orig");
        fs << file_tokens.Data();

        std::ofstream fs2("/tmp/diff/" + i + ".decom");
        fs2 << tl.Data();
      }

    } else {
      LOG(FATAL)
          << maybe_uncompressed.TakeError();
    }

  } else {
    LOG(FATAL)
        << "Error serializing token list for file " << path << ": "
        << maybe_offset.TakeError();
  }
}

}  // namespace indexer
