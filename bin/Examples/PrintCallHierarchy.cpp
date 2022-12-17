// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iomanip>
#include <sstream>
#include <vector>

#include "Index.h"
#include <multiplier/AST.h>

DEFINE_uint64(entity_id, 0, "ID of the entity to print the call hierarchy of");
DEFINE_bool(show_locations, false, "Show the file locations of the entities");

using SeenEntityList = std::vector<mx::RawEntityId>;

struct SeenEntityTracker {
 private:
  SeenEntityList &seen;
  const size_t size;
  const mx::RawEntityId eid;
  const size_t count;

 public:
  template <typename E>
  SeenEntityTracker(SeenEntityList &seen_, const E &entity)
      : seen(seen_),
        size(seen.size()),
        eid(entity.id()),
        count(std::count(seen.begin(), seen.end(), entity.id())) {
    seen.push_back(eid);        
  }

  operator bool (void) const noexcept {
    return count <= 1u;
  }

  bool IsCycle(void) {
    return count == 1u;
  }

  ~SeenEntityTracker(void) {
    seen.resize(size);
  }
};

SeenEntityList seen;

static void PrintCallHierarchy(mx::Decl entity, unsigned depth);
static void PrintCallHierarchy(mx::Stmt entity, unsigned depth);

static void Indent(std::ostream &os, unsigned depth) {
  for (auto i = 0u; i < depth; ++i) {
    os << "  ";
  }
}

void PrintCallHierarchy(mx::Decl entity, unsigned depth) {
  SeenEntityTracker enter_entity(seen, entity);
  if (!enter_entity) {
    return;
  }

  Indent(std::cout, depth);
    
  mx::Fragment fragment = mx::Fragment::containing(entity);
  auto file = mx::File::containing(fragment);

  if (auto named = mx::NamedDecl::from(entity)) {
    std::cout << named->name() << '\t';
  }

  std::cout
      << (file ? file->id().Pack() : mx::kInvalidEntityId) << '\t'
      << fragment.id() << '\t'
      << entity.id() << '\t'
      << mx::EnumeratorName(entity.kind());

  if (FLAGS_show_locations && file) {
    std::cout << '\t' << file_paths[file->id()].generic_string();
    if (auto tok = entity.token()) {
      if (auto line_col = tok.location(location_cache)) {
        std::cout << '\t' << line_col->first << '\t' << line_col->second;
      }
    }
  }

  std::cout << '\n';

  if (enter_entity.IsCycle()) {
    return;
  } else if (auto decl = mx::Decl::containing(entity)) {
    PrintCallHierarchy(decl.value(), depth + 1u);
  } else {
    for (const mx::Reference &ref : entity.references()) {
      PrintCallHierarchy(ref, depth + 1u);
    }
  }
}

void PrintCallHierarchy(mx::Stmt entity, unsigned depth) {
  SeenEntityTracker enter_entity(seen, entity);
  if (!enter_entity) {
    return;
  }

  if (auto decl = mx::Decl::containing(entity)) {
    PrintCallHierarchy(decl.value(), depth);
  }
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] --entity_id ID\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample(FLAGS_show_locations);

  auto maybe_entity = index.entity(FLAGS_entity_id);
  if (std::holds_alternative<mx::Decl>(maybe_entity)) {
    mx::Decl decl = std::get<mx::Decl>(maybe_entity);
    PrintCallHierarchy(std::move(decl), 0u);

  } else if (std::holds_alternative<mx::Stmt>(maybe_entity)) {
    mx::Stmt stmt = std::get<mx::Stmt>(maybe_entity);
    PrintCallHierarchy(std::move(stmt), 0u);

  } else if (std::holds_alternative<mx::Token>(maybe_entity)) {
    mx::Token token = std::get<mx::Token>(maybe_entity);
    if (auto stmt = mx::Stmt::containing(token)) {
      PrintCallHierarchy(stmt.value(), 0u);

    } else if (auto decl = mx::Decl::containing(token)) {
      PrintCallHierarchy(decl.value(), 0u);
    }

  } else {
    std::cerr << "Invalid declaration id " << FLAGS_entity_id << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
