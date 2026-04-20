// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <filesystem>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace indexer {

// Filters compiler arguments based on pattern rules loaded from a config file.
//
// Each rule specifies a match type (exact, prefix, or contains), a pattern
// string, and how many following arguments to also skip. Rules are checked in
// order; the first match wins.
class ArgumentFilter {
 public:
  ArgumentFilter(void) = default;

  // Load rules from a config file, appending them to any existing rules.
  // Returns an error message on failure, or std::nullopt on success.
  std::optional<std::string> LoadFromFile(const std::filesystem::path &path);

  // Check if an argument should be skipped. Returns the number of following
  // arguments to also skip (0 means skip only this argument), or std::nullopt
  // if the argument should be kept.
  //
  // When the returned value is negative, its absolute value is the number of
  // following arguments to skip, but only if they don't start with '-'. This
  // handles malformed compilation databases where a "value" slot actually
  // contains the next flag.
  std::optional<int> ShouldSkip(std::string_view arg) const;

  // Returns true if no rules have been loaded.
  bool Empty(void) const { return rules.empty(); }

 private:
  enum class MatchType : uint8_t {
    kExact,
    kPrefix,
    kContains,
  };

  struct Rule {
    MatchType match;
    std::string pattern;

    // Positive: unconditionally skip this many following args.
    // Negative: skip |n| following args only if they don't start with '-'.
    // Zero: skip only the matched argument itself.
    int num_following;
  };

  std::vector<Rule> rules;
};

}  // namespace indexer
