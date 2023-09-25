// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>

#include "Index.h"
#include <multiplier/AST.h>

DEFINE_uint64(entity_id, 0, "ID of the entity to print the call hierarchy of");
DEFINE_uint64(reachable_from_entity_id, 0, "ID of the entity from which `--entity_id` must be reachable");

using Edge = std::pair<mx::PackedDeclId, mx::PackedDeclId>;
static std::map<Edge, unsigned> edge_weights;
static std::map<mx::PackedDeclId, std::vector<mx::PackedDeclId>> back_edges;

static std::unordered_set<mx::PackedDeclId> entities;

static unsigned max_edge_weight = 0u;

static bool is_root = true;

static void PrintCallGraph(mx::Decl entity);
static void PrintCallGraphEdge(const mx::Decl &from_entity, mx::Decl to_entity);
static void PrintCallGraphEdge(const mx::Decl &from_entity, mx::Stmt entity);
static void PrintCallGraph(mx::Stmt entity);

void PrintCallGraphEdge(const mx::Decl &from_entity, mx::Decl to_entity) {
  auto from_id = from_entity.id();
  auto to_id = to_entity.id();
  auto edge_key = Edge(from_id, to_id);

  auto &edge_weight = edge_weights[edge_key];
  if (!edge_weight && FLAGS_reachable_from_entity_id) {
    back_edges[to_id].push_back(from_id);
  }
  edge_weight += 1u;
  max_edge_weight = std::max(max_edge_weight, edge_weight);

  PrintCallGraph(to_entity);
}

void PrintCallGraphEdge(const mx::Decl &from_entity, mx::Stmt entity) {
  auto decls = mx::Decl::containing(entity);
  auto decl = decls.begin();
  if (decl != decls.end()) {
    PrintCallGraphEdge(from_entity, decl->canonical_declaration());
  }  
}

void PrintCallGraph(mx::Decl entity) {
  mx::PackedDeclId id = entity.id();
  
  if (auto [it, added] = entities.insert(id); !added) {
    return;  // Seen it before.
  }

  std::cout << "  e" << id;
  auto has_detail = false;
  if (auto named = mx::NamedDecl::from(entity)) {
    std::cout << " [label=\"" << named->name() << "\"";
    has_detail = true;
  }
  
  // Color the requested node.
  if (is_root) {
    if (!has_detail) {
      std::cout << " [";
      has_detail = true;
    } else {
      std::cout << ' ';
    }
    std::cout << "color=\"blue\"";
    is_root = false;
  }

  if (has_detail) {
    std::cout << ']';
  }
  std::cout << ";\n";

  auto decls = mx::Decl::containing(entity);
  auto decl = decls.begin();
  if (decl != decls.end()) {
    PrintCallGraphEdge(entity, decl->canonical_declaration());
  } else {
    for (mx::Reference ref : entity.references()) {
      if (auto ref_stmt = ref.as_statement()) {
        PrintCallGraphEdge(entity, *ref_stmt);

      } else if (auto ref_decl = ref.as_declaration()) {
        PrintCallGraphEdge(entity, *ref_decl);
      }
    }
  }
}

void PrintCallGraph(mx::Stmt entity) {
  auto decls = mx::Decl::containing(entity);
  auto decl = decls.begin();
  if (decl != decls.end()) {
    PrintCallGraph(decl->canonical_declaration());
  }
}

int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] [--reachable_from_entity_id ID] --entity_id ID\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample();

  std::cout
      << "digraph {\n"
      << "  node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";

  auto maybe_entity = index.entity(FLAGS_entity_id);
  if (std::holds_alternative<mx::Decl>(maybe_entity)) {
    PrintCallGraph(std::get<mx::Decl>(maybe_entity).canonical_declaration());

  } else if (std::holds_alternative<mx::Stmt>(maybe_entity)) {
    PrintCallGraph(std::get<mx::Stmt>(maybe_entity));

  } else if (std::holds_alternative<mx::Token>(maybe_entity)) {
    mx::Token token = std::get<mx::Token>(maybe_entity);
    auto stmts = mx::Stmt::containing(token);
    auto decls = mx::Decl::containing(token);
    auto stmt = stmts.begin();
    auto decl = decls.begin();
    if (stmt != stmts.end()) {
      PrintCallGraph(*stmt);

    } else if (decl != decls.end()) {
      PrintCallGraph(decl->canonical_declaration());
    }

  } else {
    std::cerr << "Invalid declaration id " << FLAGS_entity_id << std::endl;
    return EXIT_FAILURE;
  }

  std::set<Edge> reaching_edges;

  // Find a restriction of the edges of the graph that are transitively
  // reachable from `--reachable_from_entity_id`.
  if (FLAGS_reachable_from_entity_id) {
    auto maybe_reach_entity = index.entity(FLAGS_reachable_from_entity_id);
    if (!std::holds_alternative<mx::Decl>(maybe_reach_entity)) {
      std::cerr
          << "Invalid reaching declaration id "
          << FLAGS_reachable_from_entity_id << std::endl;
      return EXIT_FAILURE;
    }

    mx::Decl reach_entity =
        std::get<mx::Decl>(maybe_reach_entity).canonical_declaration();

    std::vector<mx::PackedDeclId> next_reaching_edges;
    std::vector<mx::PackedDeclId> curr_reaching_edges;
    next_reaching_edges.emplace_back(reach_entity.id());

    while (!next_reaching_edges.empty()) {
      curr_reaching_edges.swap(next_reaching_edges);
      next_reaching_edges.clear();

      for (mx::PackedDeclId to_id : curr_reaching_edges) {
        for (mx::PackedDeclId from_id : back_edges[to_id]) {
          Edge key(from_id, to_id);
          if (reaching_edges.emplace(key).second) {
            next_reaching_edges.push_back(from_id);
          }
        }
      }
    }
  }

  auto mx = double(max_edge_weight);
  for (auto [edge_key, edge_weight] : edge_weights) {
    if (FLAGS_reachable_from_entity_id && !reaching_edges.count(edge_key)) {
      continue;
    }

    auto w = static_cast<unsigned>((double(edge_weight) / mx) * 10) + 1u;
    std::cout
        << "  e" << edge_key.second << " -> e" << edge_key.first
        << " [weight=" << w << "];\n";
  }

  std::cout << "}\n";

  return EXIT_SUCCESS;
}
