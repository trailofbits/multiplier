// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "ArgumentFilter.h"

#include <charconv>
#include <fstream>
#include <sstream>

namespace indexer {

std::optional<std::string>
ArgumentFilter::LoadFromFile(const std::filesystem::path &path) {
  std::ifstream file(path);
  if (!file.is_open()) {
    return "Could not open argument filter config: " + path.string();
  }

  std::string line;
  unsigned line_num = 0;

  while (std::getline(file, line)) {
    ++line_num;

    // Strip leading whitespace.
    auto start = line.find_first_not_of(" \t");
    if (start == std::string::npos) {
      continue;  // Empty line.
    }

    // Skip comments.
    if (line[start] == '#') {
      continue;
    }

    // Parse: <match_type> <pattern> [<num_values>]
    std::istringstream ss(line.substr(start));
    std::string match_str;
    std::string pattern;
    std::string num_str;

    ss >> match_str >> pattern;
    if (match_str.empty() || pattern.empty()) {
      return path.string() + ":" + std::to_string(line_num) +
             ": expected '<match_type> <pattern> [<num_values>]'";
    }

    MatchType match;
    if (match_str == "exact") {
      match = MatchType::kExact;
    } else if (match_str == "prefix") {
      match = MatchType::kPrefix;
    } else if (match_str == "contains") {
      match = MatchType::kContains;
    } else {
      return path.string() + ":" + std::to_string(line_num) +
             ": unknown match type '" + match_str +
             "'; expected 'exact', 'prefix', or 'contains'";
    }

    int num_following = 0;
    ss >> num_str;
    if (!num_str.empty()) {
      bool lenient = false;
      std::string_view digits = num_str;

      // ~N means lenient: skip following args only if they don't look like
      // flags (don't start with '-').
      if (digits.front() == '~') {
        lenient = true;
        digits.remove_prefix(1);
      }

      auto [ptr, ec] = std::from_chars(
          digits.data(), digits.data() + digits.size(), num_following);
      if (ec != std::errc{} || ptr != digits.data() + digits.size()) {
        return path.string() + ":" + std::to_string(line_num) +
               ": invalid num_values '" + num_str + "'";
      }

      if (lenient) {
        num_following = -num_following;
      }
    }

    rules.push_back({match, std::move(pattern), num_following});
  }

  return std::nullopt;
}

std::optional<int>
ArgumentFilter::ShouldSkip(std::string_view arg) const {
  for (const Rule &rule : rules) {
    bool matched = false;
    switch (rule.match) {
      case MatchType::kExact:
        matched = (arg == rule.pattern);
        break;
      case MatchType::kPrefix:
        matched = arg.starts_with(rule.pattern);
        break;
      case MatchType::kContains:
        matched = (arg.find(rule.pattern) != std::string_view::npos);
        break;
    }
    if (matched) {
      return rule.num_following;
    }
  }
  return std::nullopt;
}

}  // namespace indexer
