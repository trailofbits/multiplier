// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cassert>
#include <unordered_map>
#include <vector>

#include "AST.h"
#include "Grammar.h"

namespace syntex {

//
// Parser item
//

class Item {
 private:
  const NonTerminal *cur, *end;
  std::vector<const ASTNode *> child_vector;

  Item(const NonTerminal *cur_, const NonTerminal *end_)
    : cur(cur_),
      end(end_) {}

 public:

  Item(const Rule& rule)
    : cur(&rule.non_terminals.front()),
      end(&rule.non_terminals.back()) {}

  bool AtEnd() const {
    return cur == end;
  }

  const NonTerminal& Cur() const {
    return *cur;
  }

  Item Forward(const ASTNode *child) {
    assert(cur < end);
    Item new_item(cur + 1, end);
    new_item.child_vector.insert(
      new_item.child_vector.end(),
      child_vector.begin(),
      child_vector.end());
    new_item.child_vector.push_back(child);
    return new_item;
  }

  const ASTNode *ResultingNode(AST& ast) {
    if (std::holds_alternative<mx::DeclKind>(cur->data)) {
      return ast.ConstructNode(std::get<mx::DeclKind>(cur->data), child_vector);
    } else if (std::holds_alternative<mx::StmtKind>(cur->data)) {
      return ast.ConstructNode(std::get<mx::StmtKind>(cur->data), child_vector);
    } else if (std::holds_alternative<mx::TypeKind>(cur->data)) {
      return ast.ConstructNode(std::get<mx::TypeKind>(cur->data), child_vector);
    } else {
      assert(false);
    }
  }
};

//
// Parsed fragment
//

struct Fragment {
  const ASTNode *node;
  size_t next;

  Fragment(const ASTNode *node_, size_t next_)
    : node(node_), next(next_) {}
};

//
// Wrapper around parsing functions
//

class Parser {
private:
  // Grammar to be processed
  const Grammar &m_grammar;

  // Input string
  std::string_view m_input;

  // Resulting AST
  AST m_ast;

  // Partial parses for each source location
  std::unordered_map<size_t, std::vector<Fragment>> m_parses;

  void MatchRule(std::vector<Fragment> &result, Item item, size_t position);

  void MatchPrefix(std::vector<Fragment> &result, Fragment frag);

  const std::vector<Fragment> &ParsesAtIndex(size_t index);

public:
  Parser(const Grammar &grammar, std::string_view input);

  void Parse();
};

void Parse(const Grammar &grammar, std::string_view query);

} // namespace syntex
