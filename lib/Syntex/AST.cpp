// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Private.h"

namespace syntex {

std::ostream& operator<<(std::ostream& os, const NodeKind& nt) {
    nt.Visit(Visitor {
            [&] (mx::DeclKind kind)  { os << "DeclKind::" << EnumeratorName(kind);   },
            [&] (mx::StmtKind kind)  { os << "StmtKind::" << EnumeratorName(kind);   },
            [&] (mx::TypeKind kind)  { os << "TypeKind::" << EnumeratorName(kind);   },
            [&] (mx::TokenKind kind) { os << "TokenKind::" << EnumeratorName(kind);  },
    });
    return os;
}

ASTNode::ASTNode(NodeKind kind_, std::vector<const ASTNode *> child_vector_)
: kind(kind_), child_vector(std::move(child_vector_)) {}

ASTNode::ASTNode(mx::TokenKind kind_, std::string spelling)
    : kind(kind_), spelling(std::move(spelling)) {}

ASTNode::~ASTNode() {
  // Destruct correct union variant
  if (kind.IsToken()) {
    spelling.std::string::~string();
  } else {
    child_vector.std::vector<const ASTNode *>::~vector();
  }
}

bool ASTNode::operator==(const ASTNode &that) const noexcept {
  if (kind != that.kind) {
    return false;
  }

  if (kind.IsToken()) {
    return spelling == that.spelling;
  } else {
    if (child_vector.size() != that.child_vector.size()) {
      return false;
    }
    for (auto i = 0u; i < child_vector.size(); ++i) {
      if (*child_vector[i] != *that.child_vector[i]) {
        return false;
      }
    }
  }

  return true;
}

AST::AST(void) {
  index.resize(mx::NumEnumerators(mx::DeclKind{}) +
               mx::NumEnumerators(mx::StmtKind{}) +
               mx::NumEnumerators(mx::TypeKind{}) +
               mx::NumEnumerators(mx::TokenKind{}));
}

const ASTNode *AST::LastNodeOfKind(NodeKind kind) {
  return index[kind.Serialize()];
}

const ASTNode *AST::ConstructNode(NodeKind kind, std::vector<const ASTNode *> child_vector)
{
  assert(!kind.IsToken());
  ASTNode *ptr = &nodes.emplace_back(kind, std::move(child_vector));
  auto kind_val = kind.Serialize();
  ptr->prev_of_kind = index[kind_val];
  index[kind_val] = ptr;
  return ptr;
}

const ASTNode *AST::ConstructNode(mx::TokenKind kind, std::string spelling)
{
  ASTNode *ptr = &nodes.emplace_back(kind, std::move(spelling));
  auto kind_val = ptr->kind.Serialize();
  ptr->prev_of_kind = index[kind_val];
  index[kind_val] = ptr;
  return ptr;
}

AST AST::Build(const mx::Fragment &fragment) {
  AST self;

  std::vector<mx::TokenContext> contexts;

  for (mx::Token tok : mx::Token::in(fragment)) {
    // Skip whitespaces
    switch (tok.kind()) {
      case mx::TokenKind::UNKNOWN:
      case mx::TokenKind::WHITESPACE:
      case mx::TokenKind::COMMENT:
        continue;
      default:
        if (tok.data().empty()) {
          continue;
        }
        break;
    }


    contexts.clear();
    for (auto c = mx::TokenContext::of(tok); c; c = c->parent()) {
      if (!c->is_alias()) {
        contexts.emplace_back(*c);
      }
    }

    auto *curr_children = &self.root;

    for (auto it = contexts.rbegin(), end = contexts.rend(); it != end; ++it) {
      // NOTE: always overwritten, just need some random initializer
      // to keep C++ happy
      NodeKind kind(mx::TokenKind::UNKNOWN);

      if (auto decl = mx::Decl::from(*it)) {
        // Declarations.
        kind = NodeKind(decl->kind());
      } else if (auto stmt = mx::Stmt::from(*it)) {
        // Statements.
        switch (stmt->kind()) {
          case mx::StmtKind::IMPLICIT_CAST_EXPR:
          case mx::StmtKind::DECL_REF_EXPR:
            continue;  // Skip these; they are spam.
          default:
            kind = NodeKind(stmt->kind());
            break;
        }
      } else if (auto type = mx::Type::from(*it)) {
        // Types.
        kind = NodeKind(type->kind());
      } else {
        continue;
      }

      if (curr_children->empty() || curr_children->back()->kind != kind) {
        // Need to add a new branch or the last thing doesn't match.
        auto next = self.ConstructNode(kind, {});
        curr_children->push_back(next);
        curr_children = &next->child_vector;
      } else {
        // The last thing matches, use it.
        curr_children = &curr_children->back()->child_vector;
      }
    }

    // Add the token.
    curr_children->push_back(self.ConstructNode(
      tok.kind(), std::string(tok.data().data(), tok.data().size())));
  }

  return self;
}

#ifndef NDEBUG

namespace {

static std::string Data(const std::string &data) {
  std::stringstream ss;
  for (auto ch : data) {
    switch (ch) {
      // To keep xdot happy
      case '[': ss << " &#91;"; break;
      case ']': ss << "&#93;"; break;
      // HTML escapes
      case '<': ss << "&lt;"; break;
      case '>': ss << "&gt;"; break;
      case '"': ss << "&quot;"; break;
      case '\'': ss << "&apos;"; break;
      case '\n': ss << "<BR>"; break;
      case '&': ss << "&amp;"; break;
      case '\t': ss << "&nbsp; "; break;
      case '\r': break;
      default: ss << ch; break;
    }
  }
  return ss.str();
}

}  // namespace

void AST::PrintDOT(std::ostream &os) const {
  os << "digraph {\n"
     << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";

  // Root node
  os << "root [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" "
     << "border=\"1\"><TR><TD bgcolor=\"darksalmon\"> </TD></TR></TABLE>>];\n";
  for (const ASTNode *child : root) {
    os << "root -> x" << std::hex << reinterpret_cast<uintptr_t>(child)
       << std::dec << ";\n";
  }

  for (const ASTNode &node : nodes) {
    os << "x" << std::hex << reinterpret_cast<uintptr_t>(&node) << std::dec
       << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" "
       << "border=\"1\"><TR><TD";


    auto PrintChildren = [&] () {
      for (const ASTNode *child : node.child_vector) {
        os << "x" << std::hex << reinterpret_cast<uintptr_t>(&node)
           << " -> x" << std::hex << reinterpret_cast<uintptr_t>(child)
           << std::dec << ";\n";
      }
    };

    node.kind.Visit(Visitor {
      [&] (mx::DeclKind kind)  {
        os
          << " bgcolor=\"aquamarine\">"
          << mx::EnumeratorName(kind)
          << "</TD></TR></TABLE>>];\n";
        PrintChildren();
      },
      [&] (mx::StmtKind kind) {
        os
          << " bgcolor=\"darkolivegreen3\">"
          << mx::EnumeratorName(kind)
          << "</TD></TR></TABLE>>];\n";
        PrintChildren();
      },
      [&] (mx::TypeKind kind) {
        os
          << " bgcolor=\"goldenrod\">"
          << mx::EnumeratorName(kind)
          << "</TD></TR></TABLE>>];\n";
        PrintChildren();
      },
      [&] (mx::TokenKind kind) {
        os
          << " bgcolor=\"cornsilk2\">"
          << mx::EnumeratorName(kind)
          << "</TD></TR><TR><TD bgcolor=\"antiquewhite\">"
          << Data(node.spelling)
          << "</TD></TR></TABLE>>];\n";
      },
    });
  }

  os << "}\n";
}

#endif

}  // namespace syntex
