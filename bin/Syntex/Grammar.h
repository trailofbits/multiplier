// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <filesystem>
#include <string>
#include <utility>
#include "AST.h"
#include "Lexer.h"

namespace mx {
class Fragment;

enum class DeclKind : unsigned char;
enum class StmtKind : unsigned char;
enum class TokenKind : unsigned short;
enum class TypeKind : unsigned char;

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
  NonTerminal(mx::TypeKind k);
  NonTerminal(mx::TokenKind k);

  bool operator==(const NonTerminal& other) const {
    return val == other.val;
  }
};

std::ostream& operator<<(std::ostream& os, const NonTerminal& nt);

// Right-hand side / body of a production rule in a grammar, followed by the
// head of the production. E.g. if a production is `A -> B C` then this stores
// `B C A`.
class Rule {
 private:
  friend class Grammar;
  friend class GrammarImpl;

  Rule(const Rule &that) = delete;
  Rule &operator=(const Rule &) = delete;

 public:
  Rule()
      : begin(nullptr),
        end(nullptr) {}

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

  const size_t Count() const {
    return end - begin - 1;
  }

  const NonTerminal& Result() const {
    return end[-1];
  }

  uint64_t Hash(void) const;

  NonTerminal *begin{nullptr};
  NonTerminal *end{nullptr};
};

std::ostream& operator<<(std::ostream& os, const Rule& rule);

class Grammar {
 private:
  Grammar(void) = delete;

  std::shared_ptr<GrammarImpl> impl;

 public:
  ~Grammar(void);

  explicit Grammar(std::filesystem::path grammar_dir);

  // Determine the kind of an identifier based on its spelling
  mx::TokenKind ClassifyIdent(std::string_view& spelling) const;

  // Find all productions beginning with the specified non-terminal
  std::vector<Rule> MatchProductions(const NonTerminal& start_nt) const;

  // Import a fragment into the grammar. This extends the persisted grammar with
  // the features from this fragment.
  void Import(const mx::Fragment &fragment);
};

// Produce all possible parses given a grammar and a set of tokens
void Parse(const Grammar& grammar, const std::vector<Token>& tokens);

}  // namespace syntex
