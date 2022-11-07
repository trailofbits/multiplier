// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/AST.h>
#include <cassert>
#include <iostream>

namespace mx {
namespace syntex {

//
// NodeKind: Core class of Syntex, represents the following things:
//  - An entry in a grammar rule
//  - Kind of node in a multiplier AST
//  - Kind of node in a query AST
//

class NodeKind {
private:
  unsigned short val;

  NodeKind(unsigned short val_) : val(val_) {}

public:
  static NodeKind Any() {
    return NodeKind(UpperLimit());
  }

  NodeKind(mx::DeclKind kind)
      : val(static_cast<unsigned short>(kind)) {}

  NodeKind(mx::StmtKind kind)
      : val(static_cast<unsigned short>(kind)
            + mx::NumEnumerators(mx::DeclKind{})) {}

  NodeKind(mx::TokenKind kind)
      : val(static_cast<unsigned short>(kind)
            + mx::NumEnumerators(mx::DeclKind{})
            + mx::NumEnumerators(mx::StmtKind{})) {}

  template<typename T>
  auto Visit(T visitor) const {
    if (val < mx::NumEnumerators(mx::DeclKind{})) {
      return visitor(static_cast<mx::DeclKind>(val));
    } else if (val < mx::NumEnumerators(mx::DeclKind{})
                     + mx::NumEnumerators(mx::StmtKind{})) {
      return visitor(static_cast<mx::StmtKind>(val
                                        - mx::NumEnumerators(mx::DeclKind{})));
    } else if (val < UpperLimit()) {
      return visitor(static_cast<mx::TokenKind>(val
                                         - mx::NumEnumerators(mx::DeclKind{})
                                         - mx::NumEnumerators(mx::StmtKind{})));
    } else {
      return visitor();
    }
  }

  bool IsToken() const  {
    return val >= mx::NumEnumerators(mx::DeclKind{})
                  + mx::NumEnumerators(mx::StmtKind{});
  }

  mx::TokenKind AsToken() const {
    assert(IsToken());
    return static_cast<mx::TokenKind>(val
                                      - mx::NumEnumerators(mx::DeclKind{})
                                      - mx::NumEnumerators(mx::StmtKind{}));
  }

  bool operator==(const NodeKind &other) const {
    return val == other.val;
  }

  static NodeKind Deserialize(unsigned short val) {
    return val;
  }

  unsigned short Serialize() const {
    return val;
  }

  static constexpr unsigned short UpperLimit() {
    return mx::NumEnumerators(mx::DeclKind{})
            + mx::NumEnumerators(mx::StmtKind{})
            + mx::NumEnumerators(mx::TokenKind{});
  }
};

//
// This template (and deduction guide) allows for the easy generation of nice
// looking visitors from a set of lambdas. See the operator<< implementation
// below as an example usecase.
//

template<typename ... F>
struct Visitor : F ... {
  using F::operator() ...;
};

template<class... F> Visitor(F...) -> Visitor<F...>;

//
// Pretty print a NodeKind to an output stream
//

inline std::ostream& operator<<(std::ostream &os, const NodeKind &kind) {
  kind.Visit(Visitor {
    [&] (mx::DeclKind kind)  { os << "DeclKind::" << EnumeratorName(kind);   },
    [&] (mx::StmtKind kind)  { os << "StmtKind::" << EnumeratorName(kind);   },
    [&] (mx::TokenKind kind) { os << "TokenKind::" << EnumeratorName(kind);  },
    [&] ()                   { os << "NodeKind::Any";                        },
  });
  return os;
}

}  // namespace syntex
}  // namespace mx

namespace std {

template<>
struct hash<mx::syntex::NodeKind> {
  size_t operator()(const mx::syntex::NodeKind &kind) const {
    return kind.Serialize();
  }
};

}  // namespace std