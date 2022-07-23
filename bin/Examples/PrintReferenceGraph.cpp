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

DEFINE_uint64(entity_id, 0, "ID of the entity to print the uses of");
DEFINE_bool(highlight_user, false, "Should we print the fragment with the user highlighted?");
DEFINE_uint32(length, 2, "Length of paths to print");
DEFINE_bool(ignore_types, false, "Should we skip types? They can add a lot of stuff.");

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
    << " [--host HOST] [--port PORT] --entity_id ID [--length N]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample(false);

  std::map<mx::RawEntityId, std::set<mx::RawEntityId>> user_references;
  std::map<mx::RawEntityId, unsigned> work_list;
  std::map<mx::RawEntityId, unsigned> next_work_list;

  next_work_list[FLAGS_entity_id] = FLAGS_length;

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
        for (mx::Reference ref : std::get<mx::Decl>(ent).references()) {
          mx::Stmt ref_stmt = ref.statement();
          user_references[ref_stmt.id()].insert(user_id);

          auto &next_path_len = next_work_list[ref_stmt.id()];
          next_path_len = std::max(path_len - 1u, next_path_len);
        }

      } else if (std::holds_alternative<mx::Stmt>(ent)) {
        if (auto dre = mx::DeclRefExpr::from(std::get<mx::Stmt>(ent))) {
          auto decl = dre->declaration();
          user_references[decl.id()].insert(user_id);

          auto &next_path_len = next_work_list[decl.id()];
          next_path_len = std::max(path_len - 1u, next_path_len);
        }
      }
    }
  }

  std::cout
      << "digraph {\n"
      << "  node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";

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

    for (auto used_id : uses) {
      std::cout << "e" << user_id << " -> e" << used_id << ";\n";
    }
  }

  std::cout << "}\n";

  return EXIT_SUCCESS;
}
