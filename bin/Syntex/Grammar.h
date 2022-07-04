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
  std::variant<std::monostate,
                mx::DeclKind,
                mx::StmtKind,
                mx::TypeKind,
                mx::TokenKind> data;

  NonTerminal() {}
  NonTerminal(mx::DeclKind k) : data(k) {}
  NonTerminal(mx::StmtKind k) : data(k) {}
  NonTerminal(mx::TypeKind k) : data(k) {}
  NonTerminal(mx::TokenKind k) : data(k) {}

  bool operator==(const NonTerminal& other) const {
    return data == other.data;
  }
};

std::ostream& operator<<(std::ostream& os, const NonTerminal& nt);

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
