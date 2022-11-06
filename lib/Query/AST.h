// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "NodeKind.h"

#include <deque>
#include <vector>
#include <string>
#include <multiplier/Index.h>

//
// AST: In-memory tree representation of a multiplier fragment
//

namespace pasta {
class TokenRange;
}

namespace mx {
namespace syntex {

class ASTNode {
public:
  friend class AST;

  mutable const ASTNode *prev {nullptr};

  ASTNode(NodeKind kind,
          mx::VariantEntity entity,
          mx::TokenRange token_range);

  ASTNode(mx::TokenKind kind,
          mx::VariantEntity entity,
          mx::TokenRange token_range,
          std::string spelling);

  ~ASTNode();

  NodeKind Kind() const {
    return kind;
  }

  const std::vector<const ASTNode *> &ChildVector() const {
    assert(!kind.IsToken());
    return child_vector;
  };

  const mx::VariantEntity &Entity() const {
    return entity;
  }

  const mx::TokenRange &TokenRange() const {
    return token_range;
  }

  const std::string &Spelling() const {
    assert(kind.IsToken());
    return spelling;
  }

private:
  NodeKind kind;
  mx::VariantEntity entity;
  mx::TokenRange token_range;

  union {
    mutable std::vector<const ASTNode *> child_vector;
    std::string spelling;
  };
};


// An AST.
class AST {
private:
  friend class ASTNode;

  // Allocation arena for AST nodes
  std::deque<ASTNode> nodes;

  // Nodes at the root of the AST
  std::vector<const ASTNode *> root;

  // Nodes of the same kind are linked together in a chain
  // This is the root of the chain for each kind
  std::vector<const ASTNode *> index;

  AST() {
    index.resize(NodeKind::UpperLimit());
  }

public:
  // All nodes
  const std::deque<ASTNode> &AllNodes() const {
    return nodes;
  }

  // Nodes at the root of this AST
  const std::vector<const ASTNode *> &RootNodes(void) const {
    return root;
  }

  // Get indexed node of kind
  const ASTNode *WithKind(NodeKind kind) const {
    return index[kind.Serialize()];
  }

  // Build an AST from a multiplier fragment
  static AST Build(const mx::Fragment &fragment);

  // NOTE: this actually lives in the PASTA grammar builder's cpp file
  // do not call from anything else
  static AST Build(const pasta::TokenRange &tokens);

#ifndef NDEBUG
  void PrintDOT(std::ostream &os) const;
#endif
};

}  // namespace syntex
}  // namespace mx