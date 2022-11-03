// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>

#include <map>
#include <set>
#include <utility>
#include <variant>

#include "Index.h"
#include <multiplier/AST.h>

DEFINE_uint64(entity_id, 0, "ID of the entity to print the uses of");
DEFINE_uint32(length, 2, "Length of paths to print");

using UseEdge = std::pair<mx::RawEntityId, const char *>;

static std::pair<const char *, const char *>
KindAndColor(mx::RawEntityId id) {
  mx::VariantId vid = mx::EntityId(id).Unpack();
  if (std::holds_alternative<mx::DeclarationId>(vid)) {
    auto eid = std::get<mx::DeclarationId>(vid);
    return {mx::EnumeratorName(eid.kind), "antiquewhite"};

  } else if (std::holds_alternative<mx::StatementId>(vid)) {
    auto eid = std::get<mx::StatementId>(vid);
    return {mx::EnumeratorName(eid.kind), "aquamarine"};
  
  } else {
    return {"Other", "darkseagreen2"};
  }
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] --entity_id ID [--length N]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample(false);

  std::map<mx::RawEntityId, std::set<UseEdge>> user_references;
  std::map<mx::RawEntityId, unsigned> work_list;
  std::map<mx::RawEntityId, unsigned> next_work_list;

  next_work_list[FLAGS_entity_id] = FLAGS_length;

  auto add_edge = [&] (mx::RawEntityId from_id, mx::RawEntityId to_id,
                       const char *kind, unsigned path_len) {
    user_references[from_id].emplace(to_id, kind);

    auto &next_path_len = next_work_list[from_id];
    next_path_len = std::max(path_len - 1u, next_path_len);
  };

  auto add_back_edge = [&] (mx::RawEntityId from_id, mx::RawEntityId to_id,
                            const char *kind, unsigned path_len) {
    user_references[to_id].emplace(from_id, kind);

    auto &next_path_len = next_work_list[from_id];
    next_path_len = std::max(path_len - 1u, next_path_len);
  };

  while (!next_work_list.empty()) {
    work_list.clear();
    work_list.swap(next_work_list);
    for (auto [user_id, path_len] : work_list) {

      // Make sure every ID will have a node.
      (void) user_references[user_id];

      if (!path_len) {
        continue;
      }

      mx::VariantEntity ent = index.entity(user_id);
      if (std::holds_alternative<mx::Decl>(ent)) {
        mx::Decl decl = std::get<mx::Decl>(ent);

        for (mx::Reference ref : decl.references()) {
          add_edge(ref.statement().id(), user_id, "reference", path_len);
        }

        if (auto parent_decl = decl.parent_declaration()) {
          add_back_edge(parent_decl->id(), user_id, "parent", path_len);
        }

        if (auto parent_stmt = decl.parent_statement()) {
          add_back_edge(parent_stmt->id(), user_id, "parent", path_len);
        }

      } else if (std::holds_alternative<mx::Stmt>(ent)) {
        mx::Stmt stmt = std::get<mx::Stmt>(ent);

        if (auto dre = mx::DeclRefExpr::from(stmt)) {
          add_back_edge(dre->declaration().id(), user_id, "declaration",
                        path_len);
        }

        if (auto parent_decl = stmt.parent_declaration()) {
          add_back_edge(parent_decl->id(), user_id, "parent", path_len);
        }

        if (auto parent_stmt = stmt.parent_statement()) {
          add_back_edge(parent_stmt->id(), user_id, "parent", path_len);
        }
      }
    }
  }

  std::cout
      << "digraph {\n"
      << "  node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";

  std::map<mx::RawEntityId, std::vector<const char *>> grouped_uses;

  for (auto [user_id, uses] : user_references) {
    auto [kind, color] = KindAndColor(user_id);
    if (FLAGS_entity_id == user_id) {
      color = "red";
    }
    std::cout
        << "e" << user_id
        << " [label=<<TABLE border=\"1\" cellpadding=\"1\" cellspacing=\"0\" bgcolor=\""
        << color << "\"><TR><TD>" << user_id << "</TD></TR><TR><TD>"
        << kind << "</TD></TR></TABLE>>];\n";


    grouped_uses.clear();
    for (auto [used_id, use_kind] : uses) {
      grouped_uses[used_id].push_back(use_kind);
    }

    for (const auto &[used_id, use_kinds] : grouped_uses) {
      std::cout << "e" << user_id << " -> e" << used_id << " [label=<";
      auto sep = "";
      for (const char *use_kind : use_kinds) {
        std::cout << sep << use_kind;
        sep = "<BR />";
      }
      std::cout << ">];\n";
    }
  }

  std::cout << "}\n";

  return EXIT_SUCCESS;
}
