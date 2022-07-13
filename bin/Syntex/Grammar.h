// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <filesystem>
#include <string>
#include <utility>
#include <optional>

#include "AST.h"
#include "BloomFilter.h"

namespace mx {
  using RawEntityId = uint64_t;
}

namespace syntex {

class Grammar;
class GrammarImpl;

struct Terminal {
  std::string data;
};

// Right-hand side / body of a production rule in a grammar, followed by the
// head of the production. E.g. if a production is `A -> B C` then this stores
// `B C A`.

struct Rule {
  std::vector<NonTerminal> non_terminals;

  // For serialization
  Rule() {}

  // Actual constructor
  Rule(std::vector<NonTerminal> non_terminals_)
      : non_terminals(non_terminals_) {}

  uint64_t Hash(void) const;
};

std::ostream& operator<<(std::ostream& os, const Rule &rule);

class Grammar {
 private:
  Grammar(void) = delete;

  std::shared_ptr<GrammarImpl> impl;

 public:
  ~Grammar(void);

  explicit Grammar(std::filesystem::path grammar_dir);

  // Determine the kind of an identifier based on its spelling
  std::optional<mx::TokenKind> ClassifyIdent(std::string_view spelling) const;

  // Find all productions beginning with the specified non-terminal
  std::vector<Rule> MatchProductions(const NonTerminal& start_nt) const;

  // Find all fragments that likely contain a set of features
  std::vector<mx::RawEntityId> LikelyFragments(const SmallBloomFilter &desired_features) const;

  // Import a fragment into the grammar. This extends the persisted grammar with
  // the features from this fragment.
  void Import(const mx::Fragment &fragment);
};

}  // namespace syntex
