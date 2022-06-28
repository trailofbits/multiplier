// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "WeggliSearchAction.h"

#include <capnp/message.h>
#include <capnp/serialize.h>
#include <glog/logging.h>
#include <kj/async-io.h>
#include <kj/debug.h>
#include <kj/exception.h>
#include <kj/string.h>

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

#include "Context.h"
#include "Compress.h"
#include "Util.h"

namespace indexer {

void WeggliSearchAction::QuerySyntaxInFile(mx::RawEntityId file_id) {

  // Get the contents of the file. We may fail, which is OK, and generally
  // implies a bad file id. There can be small gaps in the file ID space, which
  // otherwise mostly occupies the range `[1, N)`.
  auto maybe_contents = context->GetSerializedFile(file_id);
  if (!maybe_contents) {
    return;  // Bad file ID. This is expected for the way we get them.
  }

  WithUncompressedMessageImpl(
      "file", maybe_contents.value(),
      [=] (capnp::MessageReader &reader) {
    mx::rpc::File::Reader file = reader.getRoot<mx::rpc::File>();
    std::string_view file_contents(file.getData().cStr(),
                                   file.getData().size());

    eol_offset_to_line_num.clear();
    for (mx::rpc::UpperBound::Reader ubr : file.getEolOffsets()) {
      eol_offset_to_line_num.emplace(ubr.getOffset(), ubr.getVal());
    }

    query_tree.ForEachMatch(
        file_contents,
        [=] (const mx::WeggliMatchData &match) -> bool {
          unsigned prev_line = 0;
          for (auto i = match.begin_offset; i < match.end_offset; ++i) {
            auto line_it = eol_offset_to_line_num.upper_bound(i);
            if (line_it != eol_offset_to_line_num.end()) {
              auto line = line_it->second;
              if (line != prev_line) {
                prev_line = line;
                std::lock_guard<std::mutex> locker(context->line_results_lock);
                context->line_results.emplace(file_id, line);
              }
            }
          }
          return true;
        });
  });
}

WeggliSearchAction::~WeggliSearchAction(void) {}

WeggliSearchAction::WeggliSearchAction(
    std::shared_ptr<SearchingContext> context_,
    std::string syntax, bool is_cpp)
    : context(std::move(context_)),
      query_tree(std::move(syntax), is_cpp) {}

void WeggliSearchAction::Run(mx::Executor, mx::WorkerId) {
  if (!query_tree.IsValid()) {
    DLOG(ERROR)
        << "Query is not valid";
    return;
  }

  while (true) {
    mx::RawEntityId file_id = context->local_next_file_id.fetch_add(1ull);
    if (file_id >= context->server_context.next_file_id.load()) {
      break;
    }
    QuerySyntaxInFile(file_id);
  }
}

} // namespace indexer
