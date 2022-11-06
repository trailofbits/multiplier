// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <sstream>

#include "AST.h"

#include <absl/container/flat_hash_map.h>

namespace mx {
namespace syntex {

ASTNode::ASTNode(NodeKind kind_,
                 mx::VariantEntity entity_,
                 mx::TokenRange token_range_)
  : kind(kind_),
    entity(std::move(entity_)),
    token_range(std::move(token_range_)),
    child_vector()
  {}

ASTNode::ASTNode(mx::TokenKind kind_,
                 mx::VariantEntity entity_,
                 mx::TokenRange token_range_,
                 std::string spelling)
  : kind(kind_),
    entity(std::move(entity_)),
    token_range(std::move(token_range_)),
    spelling(std::move(spelling))
  {}

ASTNode::~ASTNode() {
  // Destruct correct union variant
  if (kind.IsToken()) {
    spelling.std::string::~string();
  } else {
    child_vector.std::vector<const ASTNode *>::~vector();
  }
}

AST AST::Build(const mx::Fragment &fragment) {
  AST self;
  absl::flat_hash_map<unsigned, ASTNode *> ctx_to_node;

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


    // Start with the token node
    ASTNode *node = &self.nodes.emplace_back(
      tok.kind(), tok, tok, std::string(tok.data().data(), tok.data().size()));
    node->prev = self.index[node->Kind().Serialize()];
    self.index[node->Kind().Serialize()] = node;

    for (auto ctx = mx::TokenContext::of(tok); ctx; ctx = ctx->parent()) {
      auto it = ctx_to_node.find(ctx->id());

      // Add to parent node's children if it already exists

      if (it != ctx_to_node.end()) {
        it->second->child_vector.push_back(node);
        node = nullptr;
        break;
      }

      // Otherwise we need to create a new parent node

      if (auto decl = mx::Decl::from(*ctx)) {
        ASTNode *parent = &self.nodes.emplace_back(decl->kind(), *decl, decl->tokens());
        // Add it to the index
        parent->prev = self.index[parent->Kind().Serialize()];
        self.index[parent->Kind().Serialize()] = parent;
        ctx_to_node[ctx->id()] = parent;
        parent->child_vector.push_back(node);
        node = parent;
        continue;
      }

      if (auto stmt = mx::Stmt::from(*ctx)) {
        ASTNode *parent = &self.nodes.emplace_back(stmt->kind(), *stmt, stmt->tokens());
        parent->prev = self.index[parent->Kind().Serialize()];
        self.index[parent->Kind().Serialize()] = parent;
        ctx_to_node[ctx->id()] = parent;
        parent->child_vector.push_back(node);
        node = parent;
        continue;
      }
    }

    // If we didn't add the token to a pre-existing parent, add it to the root

    if (node != nullptr) {
      self.root.push_back(node);
    }
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
      [&] (mx::DeclKind kind) {
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
      [&] (mx::TokenKind kind) {
        os
          << " bgcolor=\"cornsilk2\">"
          << mx::EnumeratorName(kind)
          << "</TD></TR><TR><TD bgcolor=\"antiquewhite\">"
          << Data(node.spelling)
          << "</TD></TR></TABLE>>];\n";
      },
      [&] () {
        assert(false);
        abort();
      },
    });
  }

  os << "}\n";
}

#endif

}  // namespace syntex
}  // namespace mx