// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "AST.h"
#include "Grammar.h"
#include <multiplier/Syntex.h>
#include <iostream>
#include <fstream>

namespace mx {
namespace syntex {

GrammarImpl::GrammarImpl(const mx::Index &index_, std::filesystem::path db_path_)
  : index(index_), db_path(db_path_)
{
  {
    sqlite::Connection db(db_path);
    DeserializeRules(db);
    DeserializeTokens(db);
  }

  for (auto file : mx::File::in(index)) {
    for (auto fragment_id : file.fragment_ids()) {
      Import(fragment_id);
    }
  }
}

GrammarImpl::~GrammarImpl()
{
  sqlite::Connection db(db_path);
  SerializeRules(db);
  SerializeTokens(db);
}

// Import a fragment into the grammar.
void GrammarImpl::Import(mx::RawEntityId fragment_id)
{
  auto fragment = index.fragment(fragment_id).value();
  auto ast = AST::Build(fragment);

/*

  // Debug graphs
  std::stringstream name;
  name << "dot/ast_" << fragment.id() << ".dot";
  std::fstream fs(name.str(), std::fstream::out | std::fstream::trunc);
  ast.PrintDOT(fs);
  fs.close();

*/
  Import(ast);

}

void GrammarImpl::Import(const AST &ast)
{
  std::vector<const ASTNode *> nodes(ast.RootNodes());

  // Make a production rule for every node and its children.
  while (!nodes.empty()) {
    const ASTNode *node = nodes.back();
    nodes.pop_back();

    if (node->Kind().IsToken()) {
      // This is a token kind node, and represents a terminal. We want to map
      // the contents of the token to the actual kind of the token.

      tokens.insert({ node->Spelling(), node->Kind().AsToken() });
    } else {
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

      auto &child_vector = node->ChildVector();
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
      GrammarLeaves *leaves = &root;
      for (const ASTNode *child : child_vector) {
        leaves = &leaves->operator[](child->Kind()).leaves;
      }
      // Save pointer to rule head
      GrammarNode *head = &leaves->operator[](node->Kind());

      // Avoid creating cyclic CFGs
      bool allow_production = true;

      if (child_vector.size() == 1) {
        std::vector<NodeKind> queue = { node->Kind() };
        while (!queue.empty()) {
          auto nt = queue.back();
          queue.pop_back();

          // Check if we can reach our own left corner
          if (nt == child_vector[0]->Kind()) {
            allow_production = false;
            break;
          }

          // Queue result of matching trivial productions
          auto it = root.find(nt);
          if (it != root.end()) {
            for (auto &[left, rest] : it->second.leaves) {
              if (rest.is_production) {
                queue.push_back(left);
              }
            }
          }
        }
      }

      // Mark the head as a production if appropriate
      head->is_production = allow_production;
    }
  }
}

template<typename F>
static void IterateRulesRecursive(const GrammarLeaves &leaves,
                                  std::vector<NodeKind> &stack,
                                  F cb)
{
  for (const auto &[left, rest] : leaves) {
    if (rest.is_production) {
      cb(stack, left);
    }
    stack.push_back(left);
    IterateRulesRecursive(rest.leaves, stack, cb);
    stack.pop_back();
  }
}

void GrammarImpl::DebugRules(std::ostream &os)
{
  std::vector<NodeKind> stack;
  IterateRulesRecursive(root, stack, [&] (const std::vector<NodeKind> &body, NodeKind head) {
    for (NodeKind kind : body) {
      os << kind << " ";
    }
    os << "-> " << head << "\n";
  });
}

// NOTE: this is a simplistic serialization format

inline void verify(bool condition) {
  if (!condition) {
    assert(false);
    abort();
  }
}

static constexpr const char *grammar_root_schema =
  "CREATE TABLE IF NOT EXISTS "
  "'mx::syntex::GrammarRoot'(kind, node, PRIMARY KEY(kind))";

static constexpr const char *grammar_nodes_schema =
  "CREATE TABLE IF NOT EXISTS "
  "'mx::syntex::GrammarNodes'(id, is_production, PRIMARY KEY(id))";

static constexpr const char *grammar_children_schema =
  "CREATE TABLE IF NOT EXISTS "
  "'mx::syntex::GrammarChildren'(parent, kind, child, PRIMARY KEY(parent, kind))";

void GrammarImpl::SerializeRules(sqlite::Connection& db)
{
  sqlite::Transaction tx(db);
  std::scoped_lock<sqlite::Transaction> lock(tx);

  db.Execute(grammar_root_schema);
  db.Execute("DELETE FROM 'mx::syntex::GrammarRoot'");
  db.Execute(grammar_root_schema);
  db.Execute("DELETE FROM 'mx::syntex::GrammarNodes'");
  db.Execute(grammar_children_schema);
  db.Execute("DELETE FROM 'mx::syntex::GrammarChildren'");

  auto root_stmt = db.Prepare(
    "INSERT OR REPLACE INTO "
    "'mx::syntex::GrammarRoot'(kind, node) VALUES (?1, ?2)");
  auto node_stmt = db.Prepare(
    "INSERT OR REPLACE INTO "
    "'mx::syntex::GrammarNodes'(id, is_production) VALUES (?1, ?2)");
  auto child_stmt = db.Prepare(
    "INSERT OR REPLACE INTO "
    "'mx::syntex::GrammarChildren'(parent, kind, child) VALUES (?1, ?2, ?3)");
  std::vector<const GrammarNode *> to_insert;

  auto GetId = [](const GrammarNode* node) {
    return static_cast<std::uint64_t>(reinterpret_cast<std::uintptr_t>(node));
  };

  for(auto &[kind, node] : root) {
    auto kind_value = kind.Serialize();
    root_stmt->BindValues(kind_value, GetId(&node));
    root_stmt->Execute();
    to_insert.push_back(&node);
  }

  while(!to_insert.empty()) {
    auto node = to_insert.back();
    to_insert.pop_back();

    for(auto &[kind, child] : node->leaves) {
      to_insert.push_back(&child);
      child_stmt->BindValues(GetId(node), kind.Serialize(), GetId(&child));
      child_stmt->Execute();
    }

    node_stmt->BindValues(GetId(node), int{node->is_production});
    node_stmt->Execute();
  }
}

void GrammarImpl::DeserializeRules(sqlite::Connection& db)
{
  db.Execute(grammar_root_schema);
  db.Execute(grammar_nodes_schema);
  db.Execute(grammar_children_schema);
  auto root_stmt = db.Prepare(
    "SELECT node, kind, is_production FROM 'mx::syntex::GrammarRoot' "
    "JOIN 'mx::syntex::GrammarNodes' ON id = node");
  auto children_stmt = db.Prepare(
    "SELECT child, kind, is_production FROM 'mx::syntex::GrammarChildren' "
    "JOIN 'mx::syntex::GrammarNodes' ON id = child "
    "WHERE parent = ?1");
  std::vector<std::pair<std::uint64_t, GrammarNode*>> to_load;
  while(root_stmt->ExecuteStep()) {
    std::uint64_t id;
    unsigned short kind;
    int is_production;
    auto res = root_stmt->GetResult();
    res.Columns(id, kind, is_production);
    auto &node = root[NodeKind::Deserialize(kind)];
    node.is_production = is_production;
    to_load.emplace_back(id, &node);
  }

  while(!to_load.empty()) {
    auto pair = to_load.back();
    to_load.pop_back();
    auto id = std::get<0>(pair);
    auto &node = *std::get<1>(pair);

    children_stmt->BindValues(id);
    while(children_stmt->ExecuteStep()) {
      std::uint64_t child_id;
      unsigned short kind;
      int is_production;
      auto res = children_stmt->GetResult();
      res.Columns(child_id, kind, is_production);
      auto &child_node = node.leaves[NodeKind::Deserialize(kind)];
      child_node.is_production = is_production;
      to_load.emplace_back(child_id, &child_node);
    }
  }
}

static constexpr const char* tokens_schema =
  "CREATE TABLE IF NOT EXISTS 'mx::syntex::Tokens'(spelling, kind, PRIMARY KEY(spelling))";

void GrammarImpl::SerializeTokens(sqlite::Connection& db)
{
  db.Execute(tokens_schema);
  auto stmt = db.Prepare(
    "INSERT OR IGNORE INTO 'mx::syntex::Tokens'(spelling, kind) VALUES (?1, ?2)");
  for (auto &[spelling, kind] : tokens) {
    stmt->BindValues(spelling, static_cast<unsigned short>(kind));
    stmt->Execute();
  }
}

void GrammarImpl::DeserializeTokens(sqlite::Connection& db)
{
  db.Execute(tokens_schema);
  auto stmt = db.Prepare("SELECT spelling, kind FROM 'mx::syntex::Tokens'");
  while(stmt->ExecuteStep()) {
    std::string spelling;
    unsigned short kind;
    auto res = stmt->GetResult();
    res.Columns(spelling, kind);
    tokens[spelling] = static_cast<mx::TokenKind>(kind);
  }
}

// Determine the kind of an identifier based on its spelling
std::optional<mx::TokenKind> GrammarImpl::TokenKindOf(std::string_view spelling) const {
  auto it = tokens.find(std::string(spelling));
  if (it != tokens.end()) {
    return it->second;
  }
  return std::nullopt;
}

Grammar::Grammar(const mx::Index &index, std::filesystem::path grammar_dir)
  : impl(std::make_shared<GrammarImpl>(index, grammar_dir)) {}

}  // namespace syntex
}  // namespace mx