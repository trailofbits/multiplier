// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <deque>
#include <iosfwd>
#include <string>
#include <variant>
#include <vector>
#include <optional>

namespace mx {
class Decl;
class Fragment;
class Stmt;
class Token;
enum class DeclKind : unsigned short;
enum class StmtKind : unsigned short;
enum class TokenKind : unsigned short;
}  // namespace mx
namespace syntex {

class AST;

class ASTNode {
 private:
  friend class AST;

  ASTNode(void) = delete;

 public:
  using ChildVector = std::vector<const ASTNode *>;

  const enum Kind : unsigned short {
    kFragment,
    kDeclKind,
    kStmtKind,
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

  ASTNode(const mx::Fragment &fragment);
  ASTNode(const mx::Decl &decl);
  ASTNode(const mx::Stmt &stmt);
  ASTNode(const mx::Token &token);

  bool operator==(const ASTNode &that) const noexcept;
};

// An AST.
class AST {
 private:
  friend class ASTNode;

  std::deque<ASTNode> nodes;
  std::vector<const ASTNode *> index;

  AST(void);

 public:
  static AST Build(mx::Fragment fragment);

  inline const ASTNode *Root(void) const noexcept {
    return &(nodes.front());
  }

  // Used to "hop into" the middle of the
  const ASTNode *LastNodeOfKind(mx::DeclKind kind);
  const ASTNode *LastNodeOfKind(mx::StmtKind kind);
  const ASTNode *LastNodeOfKind(mx::TokenKind kind);

  void PrintDOT(std::ostream &os) const;
};

}  // namespace syntex
