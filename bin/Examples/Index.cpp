// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iomanip>
#include <multiplier/AST.h>
#include <multiplier/Frontend/TokenTree.h>
#include <sstream>
#include <unordered_set>

#include "Index.h"

DECLARE_bool(help);
DEFINE_string(db, "", "Database file");

std::unordered_map<mx::PackedFileId, std::filesystem::path> file_paths;
mx::FileLocationCache location_cache;

mx::Index InitExample(bool fill_locations) {
  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    exit(EXIT_FAILURE);
  }

  mx::Index index(
      mx::Index::in_memory_cache(
          mx::Index::from_database(FLAGS_db)));

  if (fill_locations) {
    for (auto [path, id] : index.file_paths()) {
      file_paths.emplace(id, std::move(path));
    }
  }

  return index;
}

void HighlightToken(std::ostream &os, mx::Token token) {
  os << "\u001b[35m\033[1m" << token.data() << "\033[0m";
}

void PrintToken(std::ostream &os, mx::Token token) {
  os << token.data(); 
}

// Collect the file tokens associated with `entity_tokens`.
std::unordered_set<mx::RawEntityId> FileTokenIdsFor(
    const mx::TokenRange &entity_tokens) {
  std::unordered_set<mx::RawEntityId> token_ids;
  std::vector<mx::Macro> macros;
  for (mx::Token tok : entity_tokens) {
    for (mx::Token file_tok : mx::TokenRange(tok).file_tokens()) {
      token_ids.insert(file_tok.id().Pack());
    }
  }
  return token_ids;
}

void RenderTokens(std::ostream &os, const mx::TokenRange &tokens_,
                  std::unordered_set<mx::RawEntityId> highlight_token_ids,
                  std::string indent, bool print_line_numbers) {
  mx::TokenRange tokens = tokens_.file_tokens();
  if (tokens.empty()) {
    return;
  }

  std::stringstream ss;
  auto location = tokens.begin()->location(location_cache);
  unsigned line_number = 0;
  if (!location) {
    print_line_numbers = false;
  } else {
    line_number = location->first;
    for (auto i = 1u; i < location->second; ++i) {
      ss << ' ';
    }
  }

  std::string sep = indent;

  for (mx::Token file_tok : tokens) {
    if (highlight_token_ids.count(file_tok.id().Pack())) {
      HighlightToken(ss, file_tok);
    } else {
      PrintToken(ss, file_tok);
    }
  }

  auto render_line_number = print_line_numbers;

  if (print_line_numbers) {
    auto file = mx::File::containing(tokens);
    os
        << '\n' << sep << "         " << file_paths[file->id()].generic_string()
        << '\n' << sep << "         +---------------------------------------------\n";
  }

  for (auto ch : ss.str()) {
    os << sep;
    if (render_line_number) {
      os << std::setfill(' ') << std::setw(8) << (line_number++) << " | ";
      render_line_number = false;
    }
    if (ch == '\n') {
      sep = "\n" + indent;
      render_line_number = print_line_numbers;
    } else {
      os << ch;
      sep.clear();
    }
  }
}

void RenderTokens(std::ostream &os, const mx::TokenRange &tokens,
                  const mx::TokenRange &entity_tokens,
                  std::string indent, bool print_line_numbers) {
  return RenderTokens(os, tokens, FileTokenIdsFor(entity_tokens),
                      std::move(indent), print_line_numbers);
}

void RenderFragment(std::ostream &os, const mx::Fragment &fragment,
                    std::unordered_set<mx::RawEntityId> highlight_token_ids,
                    std::string indent, bool print_line_numbers) {
  return RenderTokens(os, fragment.file_tokens(), std::move(highlight_token_ids),
                      std::move(indent), print_line_numbers);
}

void RenderFragment(std::ostream &os, const mx::Fragment &fragment,
                    const mx::TokenRange &entity_tokens,
                    std::string indent, bool print_line_numbers) {
  return RenderTokens(os, fragment.file_tokens(),
                      FileTokenIdsFor(entity_tokens),
                      std::move(indent), print_line_numbers);
}
