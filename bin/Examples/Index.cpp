// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iomanip>
#include <multiplier/AST.h>
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
      mx::EntityProvider::in_memory_cache(
          mx::EntityProvider::from_database(FLAGS_db)));

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

    // Ascend the macros, finding the top used macro.
    std::optional<mx::Macro> last_macro;
    for (mx::Macro macro : mx::Macro::containing(tok)) {
      last_macro.reset();
      last_macro.emplace(std::move(macro));
    }

    // If we aren't in a macro, then find the relevant file token.
    if (!last_macro) {
      if (auto file_tok = tok.file_token()) {
        token_ids.insert(file_tok.id().Pack());
      }
      continue;
    }

    macros.push_back(std::move(*last_macro));

    // Drill down, finding the file tokens used in the top macro use, its
    // arguments, etc.
    while (!macros.empty()) {
      mx::Macro macro = macros.back();
      macros.pop_back();
      for (mx::MacroOrToken use : macro.children()) {
        if (std::holds_alternative<mx::Token>(use)) {
          if (auto use_file_tok = std::get<mx::Token>(use).file_token()) {
            token_ids.insert(use_file_tok.id().Pack());
          }
        } else if (std::holds_alternative<mx::Macro>(use)) {
          macros.push_back(std::move(std::get<mx::Macro>(use)));
        }
      }
    }
  }
  return token_ids;
}

void RenderFragment(std::ostream &os, const mx::Fragment &fragment,
                    std::unordered_set<mx::RawEntityId> highlight_token_ids,
                    std::string indent, bool print_line_numbers) {

  auto location = fragment.file_tokens().begin()->location(location_cache);
  unsigned line_number = 0;
  if (!location) {
    print_line_numbers = false;
  } else {
    line_number = location->first;
  }

  std::stringstream ss;
  std::string sep = indent;

  for (mx::Token file_tok : fragment.file_tokens()) {
    if (highlight_token_ids.count(file_tok.id().Pack())) {
      HighlightToken(ss, file_tok);
    } else {
      PrintToken(ss, file_tok);
    }
  }

  auto render_line_number = print_line_numbers;

  if (print_line_numbers) {
    auto file = mx::File::containing(fragment);
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

void RenderFragment(std::ostream &os, const mx::Fragment &fragment,
                    const mx::TokenRange &entity_tokens,
                    std::string indent, bool print_line_numbers) {
  RenderFragment(os, fragment, FileTokenIdsFor(entity_tokens), indent,
                 print_line_numbers);
}
