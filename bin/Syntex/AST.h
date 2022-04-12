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

  unsigned short kind_val;

  mutable std::variant<std::string, ChildVector> data;

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

 public:
  static AST Build(mx::Fragment fragment);

  inline const ASTNode *Root(void) const noexcept {
    return &(nodes.front());
  }

  void PrintDOT(std::ostream &os) const;
};

}  // namespace syntex
