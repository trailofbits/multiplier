
#include "RegexSearchAction.h"

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

#include <re2/re2.h>


#include "Context.h"
#include "Compress.h"
#include "Util.h"

namespace indexer {

void RegexSearchAction::FillFileContents(mx::FileId file_id) {

  file_contents.clear();
  auto maybe_contents = context->GetSerializedFile(file_id);
  if (!maybe_contents) {
    return;  // Bad file ID. This is expected for the way we get them.
  }

  file_contents.reserve(maybe_contents->size());

  WithUncompressedMessageImpl(
      "file", maybe_contents.value(),
      [this] (capnp::MessageReader &reader) {
    auto file = reader.getRoot<mx::rpc::File>();
    for (auto tokens : file.getTokens()) {
      capnp::Text::Reader data_reader = tokens.getData();
      auto tok_begin = data_reader.cStr();
      auto tok_end = &(tok_begin[data_reader.size()]);
      file_contents.insert(file_contents.end(), tok_begin, tok_end);
    }
  });
}

void RegexSearchAction::FileOffsetToLine() {
  // Create an upper-bounding map of byte offsets to line numbers.
  offset_to_line_num.clear();
  auto line = 1;
  auto offset = 0;
  for (auto ch : file_contents) {
    ++offset;
    if ('\n' == ch) {
      offset_to_line_num.emplace(offset, line);
      ++line;
    }
  }
}

void RegexSearchAction::QueryExprInFile(mx::FileId file_id) {

  // Get the contents of the file. We may fail, which is OK, and generally
  // implies a bad file id. There can be small gaps in the file ID space, which
  // otherwise mostly occupies the range `[1, N)`.

  FillFileContents(file_id);
  if (file_contents.empty()) {
    DLOG(INFO) << "File with id " << file_id << " is empty or doesn't exist";
    return;
  }

  LOG(INFO) << "Looking for regex matches in file with id " << file_id;

  FileOffsetToLine();

  regex.ForEachMatch(
      file_contents,
      [this, file_id] (const std::string&, unsigned begin, unsigned end) -> bool {
        unsigned prev_line = 0;
        for (auto i = begin; i < end; ++i) {
          auto line_it = offset_to_line_num.upper_bound(i);
          if (line_it != offset_to_line_num.end()) {
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
}

RegexSearchAction::~RegexSearchAction(void) {}

RegexSearchAction::RegexSearchAction(
    std::shared_ptr<SearchingContext> context_,
    std::string_view pattern)
    : context(std::move(context_)),
      regex(pattern) {}

void RegexSearchAction::Run(mx::Executor, mx::WorkerId) {
  if (!regex.IsValid()) {
    DLOG(ERROR)
        << "Regex expression is not valid";
    return;
  }

  while (true) {
    mx::FileId file_id = context->local_next_file_id.fetch_add(1ull);
    if (file_id >= context->server_context.next_file_id.load()) {
      break;
    }
    QueryExprInFile(file_id);
  }
}

}
