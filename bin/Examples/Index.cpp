// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iomanip>
#include <sstream>

#include "Index.h"
#include <multiplier/AST.h>

DECLARE_bool(help);
DEFINE_string(db, "", "Database file");

std::unordered_map<mx::RawEntityId, std::filesystem::path> file_paths;
mx::FileLocationCache location_cache;

mx::Index InitExample(bool fill_locations) {
  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    exit(EXIT_FAILURE);
  }

  mx::Index index(mx::EntityProvider::from_database(FLAGS_db));

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

bool ContainsHighlightedTokens(mx::MacroSubstitutionList nodes,
                               const mx::TokenRange &entity_tokens) {
  for (auto node : nodes) {
    if (std::holds_alternative<mx::Token>(node)) {
      if (entity_tokens.index_of(std::get<mx::Token>(node))) {
        return true;
      }
    } else if (auto after = std::get<mx::MacroSubstitution>(node).after()) {
      if (ContainsHighlightedTokens(*after, entity_tokens)) {
        return true;
      }
    }
  }
  return false;
}

// TODO(pag): This whole thing is broken, because you can't ask top-down if a
//            parsed token is inside of a substitution; you can only ask if a
//            token derived from a parsed token is in the right range.
void PrintUnparsedTokens(std::ostream &os, mx::MacroSubstitutionList nodes,
                         const mx::TokenRange &entity_tokens,
                         bool force_highlight) {
  for (auto node : nodes) {
    if (std::holds_alternative<mx::Token>(node)) {
      auto token = std::get<mx::Token>(node);
      if (force_highlight || entity_tokens.index_of(token)) {
        HighlightToken(os, std::move(token));
      } else {
        PrintToken(os, std::move(token));
      }
    } else {
      auto sub = std::get<mx::MacroSubstitution>(node);
      auto sub_force_highlight = force_highlight;
      if (!sub_force_highlight) {
        if (auto after = sub.after()) {
          sub_force_highlight = ContainsHighlightedTokens(
              *after, entity_tokens);
        }
      }
      PrintUnparsedTokens(os, sub.before(), entity_tokens, sub_force_highlight);
    }
  }
}

void RenderFragment(std::ostream &os, const mx::Fragment &fragment,
                    const mx::TokenRange &entity_tokens,
                    std::string indent, bool print_line_numbers) {
  auto location = fragment.file_tokens().begin()->location(location_cache);
  if (!location) {
    return;
  }

  auto line_number = location->first;
  std::stringstream ss;
  std::string sep = indent;
  if (auto pp_code = fragment.preprocessed_code()) {
    PrintUnparsedTokens(ss, pp_code->before(), entity_tokens);
  } else {
    // TODO(pag): Do this.
  }
  auto render_line_number = print_line_numbers;

  if (print_line_numbers) {
    os
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
