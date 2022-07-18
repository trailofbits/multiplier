// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cassert>
#include <deque>
#include <string>
#include <vector>
#include <multiplier/AST.h>
#include <multiplier/Index.h>

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

class NonTerminal {
private:
  unsigned short val;

  NonTerminal(unsigned short val_) : val(val_) {}

public:
  NonTerminal(mx::DeclKind kind)
    : val(static_cast<unsigned short>(kind)) {}

  NonTerminal(mx::StmtKind kind)
    : val(static_cast<unsigned short>(kind)
        + mx::NumEnumerators(mx::DeclKind{})) {}

  NonTerminal(mx::TypeKind kind)
    : val(static_cast<unsigned short>(kind)
        + mx::NumEnumerators(mx::DeclKind{})
        + mx::NumEnumerators(mx::StmtKind{})) {}

  NonTerminal(mx::TokenKind kind)
    : val(static_cast<unsigned short>(kind)
        + mx::NumEnumerators(mx::DeclKind{})
        + mx::NumEnumerators(mx::StmtKind{})
        + mx::NumEnumerators(mx::TypeKind{})) {}

  template<typename T>
  void Visit(T visitor) const {
    if (val < mx::NumEnumerators(mx::DeclKind{})) {
      visitor(static_cast<mx::DeclKind>(val));
    } else if (val < mx::NumEnumerators(mx::DeclKind{})
                      + mx::NumEnumerators(mx::StmtKind{})) {
      visitor(static_cast<mx::StmtKind>(val
              - mx::NumEnumerators(mx::DeclKind{})));
    } else if (val < mx::NumEnumerators(mx::DeclKind{})
                      + mx::NumEnumerators(mx::StmtKind{})
                      + mx::NumEnumerators(mx::TypeKind{})) {
      visitor(static_cast<mx::TypeKind>(val
              - mx::NumEnumerators(mx::DeclKind{})
              - mx::NumEnumerators(mx::StmtKind{})));
    } else {
      visitor(static_cast<mx::TokenKind>(val
              - mx::NumEnumerators(mx::DeclKind{})
              - mx::NumEnumerators(mx::StmtKind{})
              - mx::NumEnumerators(mx::TypeKind{})));
    }
  }

  bool IsToken() const  {
    return val >= mx::NumEnumerators(mx::DeclKind{})
                + mx::NumEnumerators(mx::StmtKind{})
                + mx::NumEnumerators(mx::TypeKind{});
  }

  mx::TokenKind AsToken() const {
    assert(IsToken());
    return static_cast<mx::TokenKind>(val
                - mx::NumEnumerators(mx::DeclKind{})
                - mx::NumEnumerators(mx::StmtKind{})
                - mx::NumEnumerators(mx::TypeKind{}));
  }

  bool operator==(const NonTerminal &other) const {
    return val == other.val;
  }

  static NonTerminal Deserialize(unsigned short val) {
    return val;
  }

  unsigned short Serialize() const {
    return val;
  }
};

std::ostream& operator<<(std::ostream &, const NonTerminal &);

template<typename ... F>
struct Visitor : F ... {
    using F::operator() ...;
};

template<class... F> Visitor(F...) -> Visitor<F...>;


class ASTNode {
 public:
  friend class AST;

  // Next node sharing the same `kind` in the AST. This is
  // useful when unifying two parses, i.e. a fragment parse, created with
  // `AST::Build(fragment)`, and a parse of a syntax query. We can start with
  // nodes in the query, and then try to unify them top-down with nodes in the
  // fragment parse by jumping into the middle of the fragment parse to the
  // correct spot.
  const ASTNode *prev_of_kind{nullptr};

  ASTNode(NonTerminal kind, std::vector<const ASTNode *> child_vector);
  ASTNode(mx::TokenKind kind, std::string spelling);

  ~ASTNode();

  const NonTerminal Kind() const {
    return kind;
  }

  const std::vector<const ASTNode *> &ChildVector() const {
    assert(!kind.IsToken());
    return child_vector;
  };

  const std::string &Spelling() const {
    assert(kind.IsToken());
    return spelling;
  }

  bool operator==(const ASTNode &that) const noexcept;

 private:
  NonTerminal kind;

  union {
    mutable std::vector<const ASTNode *> child_vector;
    std::string spelling;
  };
};


// An AST.
class AST {
 private:
  friend class ASTNode;
  friend class Parser;

  std::deque<ASTNode> nodes;
  std::vector<const ASTNode *> index;
  std::vector<const ASTNode *> root;

  AST(void);

 public:
  // Used to "hop into" the middle of the
  const ASTNode *LastNodeOfKind(NonTerminal kind);

  const ASTNode *ConstructNode(NonTerminal kind, std::vector<const ASTNode *> child_vector);
  const ASTNode *ConstructNode(mx::TokenKind k, std::string spelling);

  const std::vector<const ASTNode *> &Root(void) const {
    return root;
  }

  // Build an AST from a multiplier fragment
  static AST Build(const mx::Fragment &fragment);

  void PrintDOT(std::ostream &os) const;
};

}  // namespace syntex
