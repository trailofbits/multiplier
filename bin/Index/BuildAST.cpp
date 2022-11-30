// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "BuildAST.h"

#include <algorithm>
#include <cassert>
#include <fstream>
#include <glog/logging.h>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>
#include <multiplier/NodeKind.h>

namespace indexer {

static void SerializeAST(mx::Fragment fragment, ServerContext &ctx) {
  auto &ast = ctx->ast;
  std::unordered_map<unsigned, std::uint64_t> ctx_to_node_id;

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
    ctx->spelling_to_token_kind.Set(tok.data(), tok.kind());

    // Start with the token node
    mx::ASTNode node{};
    node.kind = mx::SyntexNodeKind{tok.kind()}.Serialize();
    node.entity = tok.id();
    node.spelling = std::string(tok.data().data(), tok.data().size());
    node.prev = ast.GetNodeInIndex(fragment.id(), node.kind);
    std::optional<std::uint64_t> node_id = ast.AddNode(node);
    ast.SetNodeInIndex(fragment.id(), node.kind, *node_id);

    for (auto ctx = mx::TokenContext::of(tok); ctx; ctx = ctx->parent()) {
      auto it = ctx_to_node_id.find(ctx->id());

      // Add to parent node's children if it already exists

      if (it != ctx_to_node_id.end()) {
        ast.AddChild(it->second, *node_id);
        node_id = std::nullopt;
        break;
      }

      // Otherwise we need to create a new parent node

      if (auto decl = mx::Decl::from(*ctx)) {
        mx::ASTNode parent{};
        parent.kind = mx::SyntexNodeKind{decl->kind()}.Serialize();
        parent.entity = decl->id();
        parent.prev = ast.GetNodeInIndex(fragment.id(), parent.kind);
        auto parent_id = ast.AddNode(parent);
        // Add it to the index
        ast.SetNodeInIndex(fragment.id(), parent.kind, parent_id);
        ctx_to_node_id[ctx->id()] = parent_id;
        ast.AddChild(parent_id, *node_id);
        node_id = parent_id;
        continue;
      }

      if (auto stmt = mx::Stmt::from(*ctx)) {
        mx::ASTNode parent{};
        parent.kind = mx::SyntexNodeKind{stmt->kind()}.Serialize();
        parent.entity = stmt->id();
        parent.prev = ast.GetNodeInIndex(fragment.id(), parent.kind);
        auto parent_id = ast.AddNode(parent);
        // Add it to the index
        ast.SetNodeInIndex(fragment.id(), parent.kind, parent_id);
        ctx_to_node_id[ctx->id()] = parent_id;
        ast.AddChild(parent_id, *node_id);
        node_id = parent_id;
        continue;
      }
    }

    // If we didn't add the token to a pre-existing parent, add it to the root

    if (node_id.has_value()) {
      ast.AddNodeToRoot(fragment.id(), *node_id);
    }
  }
}

static void ImportGrammar(mx::Fragment fragment, ServerContext& ctx) {
  auto &ast = ctx->ast;
  auto &grammar = ctx->grammar;
  auto nodes = ast.Root(fragment.id());

  // Make a production rule for every node and its children.
  while (!nodes.empty()) {
    auto node_id = nodes.back();
    nodes.pop_back();

    auto node = ast.GetNode(node_id);
    auto node_kind = mx::SyntexNodeKind::Deserialize(node.kind);

    if (!node_kind.IsToken()) {
      // This is an internal or root node. E.g. given the following:
      //
      //                A
      //              / | \
      //             B  C  D
      //
      // We want to make a rule of the form `B C D A`, i.e. if you match `B C D`
      // then you have matched an `A`. This "backward" syntax enables us to prefix
      // scan for left corners (`B` in this case) and find all rules starting with
      // `B`.

      auto child_vector = ast.GetChildren(node_id);
      assert(child_vector.size() >= 1);

      // FIXME: do something else with long grammar rules. PHP has
      // some generated initializer lists with 100s of elements that
      // blows up our stack when serializing a grammar.
      if (child_vector.size() > 100) {
        continue;
      }

      // Add the child nodes to the work list.
      nodes.insert(nodes.end(), child_vector.begin(), child_vector.end());

      // Walk the trie
      std::uint64_t leaves_id = 0;
      for (auto child_id : child_vector) {
        auto child = ast.GetNode(child_id);
        leaves_id = grammar.GetChild(leaves_id, child.kind);
      }
      // Save pointer to rule head
      auto head_id = grammar.GetChild(leaves_id, node.kind);

      // Avoid creating cyclic CFGs
      bool allow_production = true;

      if (child_vector.size() == 1) {
        std::vector<unsigned short> queue = { node.kind };
        while (!queue.empty()) {
          auto nt = queue.back();
          queue.pop_back();

          // Check if we can reach our own left corner
          auto child = ast.GetNode(child_vector[0]);
          if (nt == child.kind) {
            allow_production = false;
            break;
          }

          // Queue result of matching trivial productions
          for(auto [left, rest] : grammar.GetChildLeaves(0, nt)) {
            auto node = grammar.GetNode(rest);
            if(node.is_production) {
              queue.push_back(left);
            }
          }
        }
      }

      // Mark the head as a production if appropriate
      grammar.UpdateNode(head_id, {allow_production});
    }
  }
}

void BuildAST(mx::Index index, ServerContext &context) {
  for(auto file : mx::File::in(index)) {
    for(auto fragment : mx::Fragment::in(file)) {
      sqlite::Transaction tx(context.db);
      std::scoped_lock<sqlite::Transaction> lock(tx);
      SerializeAST(fragment, context);
      ImportGrammar(fragment, context);
    }
  }
}
}  // namespace indexer