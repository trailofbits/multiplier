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

  } else if (std::holds_alternative<mx::TypeId>(vid)) {
    auto eid = std::get<mx::TypeId>(vid);
    return {mx::EnumeratorName(eid.kind), "cadetblue1"};

  } else if (std::holds_alternative<mx::FragmentTokenId>(vid)) {
    auto eid = std::get<mx::FragmentTokenId>(vid);
    return {mx::EnumeratorName(eid.kind), "deepskyblue3"};

  } else if (std::holds_alternative<mx::FileTokenId>(vid)) {
    auto eid = std::get<mx::FileTokenId>(vid);
    return {mx::EnumeratorName(eid.kind), "deepskyblue3"};

  } else if (std::holds_alternative<mx::AttributeId>(vid)) {
    auto eid = std::get<mx::AttributeId>(vid);
    return {mx::EnumeratorName(eid.kind), "antiquewhite3"};

  } else if (std::holds_alternative<mx::DesignatorId>(vid)) {
    auto eid = std::get<mx::DesignatorId>(vid);
    return {"Designator", "chartreuse3"};
  
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

  std::map<mx::RawEntityId, std::set<UseEdge>> user_uses;
  std::map<mx::RawEntityId, unsigned> work_list;
  std::map<mx::RawEntityId, unsigned> next_work_list;

  auto with_user = [&] (mx::RawEntityId user_id, UseEdge edge, unsigned path_len) {
    user_uses[user_id].insert(edge);
    auto &next_path_len = next_work_list[user_id];
    next_path_len = std::max(path_len - 1u, next_path_len);
  };

  auto with_use = [&] (mx::RawEntityId used_id, auto &&use, unsigned path_len) {
    for (auto sel : use.all_selectors()) {
      if (!use.has_selector(sel)) {
        continue;
      }

      UseEdge edge(used_id, mx::EnumeratorName(sel));
      if (auto user_decl = use.as_declaration()) {
        with_user(user_decl->id(), edge, path_len);
      } else if (auto user_stmt = use.as_statement()) {
        with_user(user_stmt->id(), edge, path_len);
      } else if (auto user_type = use.as_type()) {
        with_user(user_type->id(), edge, path_len);
      } else if (auto user_attr = use.as_attribute()) {
        with_user(user_attr->id(), edge, path_len);
      }
    }
  };

  next_work_list[FLAGS_entity_id] = FLAGS_length;

  while (!next_work_list.empty()) {
    work_list.clear();
    work_list.swap(next_work_list);
    for (auto [user_id, path_len] : work_list) {

      // Make sure every ID will have a node.
      (void) user_uses[user_id];

      if (!path_len) {
        continue;
      }

      mx::VariantEntity ent = index.entity(user_id);
      if (std::holds_alternative<mx::Decl>(ent)) {
        for (auto use : std::get<mx::Decl>(ent).uses()) {
          with_use(user_id, use, path_len);
        }

      } else if (std::holds_alternative<mx::Stmt>(ent)) {
        for (auto use : std::get<mx::Stmt>(ent).uses()) {
          with_use(user_id, use, path_len);
        }

      } else if (std::holds_alternative<mx::Type>(ent)) {
        if (!FLAGS_ignore_types) {
          for (auto use : std::get<mx::Type>(ent).uses()) {
            with_use(user_id, use, path_len);
          }
        }

      } else if (std::holds_alternative<mx::Token>(ent)) {
        for (auto use : std::get<mx::Token>(ent).uses()) {
          with_use(user_id, use, path_len);
        }

      } else if (std::holds_alternative<mx::Attr>(ent)) {
        for (auto use : std::get<mx::Attr>(ent).uses()) {
          with_use(user_id, use, path_len);
        }
      }
    }
  }

  std::cout
      << "digraph {\n"
      << "  node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";

  std::map<mx::RawEntityId, std::vector<const char *>> grouped_uses;

  for (auto [user_id, uses] : user_uses) {
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
