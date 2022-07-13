// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cassert>
#include <deque>
#include <string>
#include <variant>
#include <vector>

namespace mx {
class Decl;
class Fragment;
class Stmt;
class Token;
class Type;
enum class DeclKind : unsigned char;
enum class StmtKind : unsigned char;
enum class TokenKind : unsigned short;
enum class TypeKind : unsigned char;
}  // namespace mx

namespace syntex {

class AST;
class Parser;

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

class ASTNode {
 public:
  friend class AST;

  using ChildVector = std::vector<const ASTNode *>;

  ASTNode();
  ASTNode(const mx::Decl &decl);
  ASTNode(const mx::Stmt &stmt);
  ASTNode(const mx::Type &type);
  ASTNode(const mx::Token &token);

  ASTNode(mx::DeclKind k, ChildVector child_vector);
  ASTNode(mx::StmtKind k, ChildVector child_vector);
  ASTNode(mx::TypeKind k, ChildVector child_vector);
  ASTNode(mx::TokenKind k, std::string spelling);

  const enum Kind : unsigned short {
    kFragment,
    kDeclKind,
    kStmtKind,
    kTypeKind,
    kTokenKind,
  } kind;

  // Underlying value of a `mx::DeclKind`, `mx::StmtKind`, or `mx::TokenKind`.
  unsigned short kind_val;

  mutable std::variant<std::string, ChildVector> data;

  // Next node sharing the same `kind` and `kind_val` in the AST. This is
  // useful when unifying two parses, i.e. a fragment parse, created with
  // `AST::Build(fragment)`, and a parse of a syntax query. We can start with
  // nodes in the query, and then try to unify them top-down with nodes in the
  // fragment parse by jumping into the middle of the fragment parse to the
  // correct spot.
  const ASTNode *prev_of_kind{nullptr};

  bool operator==(const ASTNode &that) const noexcept;
};


std::ostream& operator<<(std::ostream& os, const NonTerminal& nt);

static NonTerminal NodeToNonTerminal(const ASTNode *node) {
  switch (node->kind) {
    default:
    case ASTNode::kFragment:
      assert(false);
      abort();
      break;
    case ASTNode::kDeclKind:
      return NonTerminal(static_cast<mx::DeclKind>(node->kind_val));
    case ASTNode::kStmtKind:
      return NonTerminal(static_cast<mx::StmtKind>(node->kind_val));
    case ASTNode::kTypeKind:
      return NonTerminal(static_cast<mx::TypeKind>(node->kind_val));
    case ASTNode::kTokenKind:
      return NonTerminal(static_cast<mx::TokenKind>(node->kind_val));
  }
}

/*

static bool NodeIsComma(const ASTNode *node) {
  return node->kind == ASTNode::kTokenKind &&
         node->kind_val == static_cast<unsigned short>(mx::TokenKind::COMMA);
}

static bool NodeIsSemicolon(const ASTNode *node) {
  return node->kind == ASTNode::kTokenKind &&
         node->kind_val == static_cast<unsigned short>(mx::TokenKind::SEMI);
}

*/

// An AST.
class AST {
 private:
  friend class ASTNode;
  friend class Parser;

  std::deque<ASTNode> nodes;
  std::vector<const ASTNode *> index;

  AST(void);

 public:
  static AST Build(const mx::Fragment &fragment);

  const ASTNode *ConstructNode();
  const ASTNode *ConstructNode(mx::DeclKind k, ASTNode::ChildVector child_vector);
  const ASTNode *ConstructNode(mx::StmtKind k, ASTNode::ChildVector child_vector);
  const ASTNode *ConstructNode(mx::TypeKind k, ASTNode::ChildVector child_vector);
  const ASTNode *ConstructNode(mx::TokenKind k, std::string spelling);

  inline const ASTNode *Root(void) const noexcept {
    return &(nodes.front());
  }

  // Used to "hop into" the middle of the
  const ASTNode *LastNodeOfKind(mx::DeclKind kind);
  const ASTNode *LastNodeOfKind(mx::StmtKind kind);
  const ASTNode *LastNodeOfKind(mx::TypeKind kind);
  const ASTNode *LastNodeOfKind(mx::TokenKind kind);

  void PrintDOT(std::ostream &os) const;
};

}  // namespace syntex
