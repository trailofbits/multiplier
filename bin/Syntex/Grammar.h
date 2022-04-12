// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <filesystem>
#include <string>
#include <utility>

namespace mx {
class Fragment;

enum class DeclKind : unsigned short;
enum class StmtKind : unsigned short;
enum class TokenKind : unsigned short;

}  // namespace mx
namespace syntex {

class Grammar;
class GrammarImpl;

struct Terminal {
  std::string data;
};

struct NonTerminal {
  unsigned short val{0};

  NonTerminal(void) = default;
  NonTerminal(mx::DeclKind k);
  NonTerminal(mx::StmtKind k);
  NonTerminal(mx::TokenKind k);
};

// Right-hand side / body of a production rule in a grammar, followed by the
// head of the production. E.g. if a production is `A -> B C` then this stores
// `B C A`.
class Rule {
 private:
  friend class Grammar;
  friend class GrammarImpl;

  Rule(const Rule &) = delete;
  Rule &operator=(const Rule &) = delete;

 public:
  inline Rule(size_t size)
      : begin(new NonTerminal[size]),
        end(&(begin[size])) {}

  ~Rule(void);

  inline Rule(Rule &&that) noexcept
      : begin(that.begin),
        end(that.end) {
    that.begin = nullptr;
    that.end = nullptr;
  }

  inline Rule &operator=(Rule &&that) noexcept {
    Rule self(std::forward<Rule>(that));
    std::swap(begin, self.begin);
    std::swap(end, self.end);
    return *this;
  }

  uint64_t Hash(void) const;

  NonTerminal *begin{nullptr};
  NonTerminal *end{nullptr};
};

class Grammar {
 private:
  Grammar(void) = delete;

  std::shared_ptr<GrammarImpl> impl;

 public:
  ~Grammar(void);

  explicit Grammar(std::filesystem::path grammar_dir);

  // Import a fragment into the grammar. This extends the persisted grammar with
  // the features from this fragment.
  void Import(const mx::Fragment &fragment);
};

}  // namespace syntex
