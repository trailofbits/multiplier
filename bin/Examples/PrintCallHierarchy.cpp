// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdlib>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <iomanip>
#include <multiplier/API.h>
#include <sstream>
#include <vector>

DECLARE_bool(help);
DEFINE_string(host, "localhost", "Hostname of mx-server. Use 'unix' for a UNIX domain socket.");
DEFINE_string(port, "50051", "Port of mx-server. Use a path and 'unix' for the host for a UNIX domain socket.");
DEFINE_uint64(entity_id, 0, "ID of the entity to print the call hierarchy of");

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

static void PrintCallHierarchy(mx::Decl entity, SeenEntityList &seen,
                               unsigned depth);
static void PrintCallHierarchy(mx::Stmt entity, SeenEntityList &seen,
                               unsigned depth);

static void Indent(std::ostream &os, unsigned depth) {
  for (auto i = 0u; i < depth; ++i) {
    os << "  ";
  }
}

void PrintCallHierarchy(mx::Decl entity, SeenEntityList &seen,
                        unsigned depth) {
  SeenEntityTracker enter_entity(seen, entity);
  if (!enter_entity) {
    return;
  }

  Indent(std::cout, depth);
    
  mx::Fragment fragment = mx::Fragment::containing(entity);
  mx::File file = mx::File::containing(fragment);

  if (auto named = mx::NamedDecl::from(entity)) {
    std::cout << std::left << std::setw(16) << named->name() << '\t';
  }

  std::cout
      << std::left << std::setw(16) << file.id()
      << std::left << std::setw(16) << fragment.id()
      << std::left << std::setw(16) << entity.id()
      << std::left << std::setw(16) << mx::EnumeratorName(entity.kind());

  std::cout << '\n';

  if (enter_entity.IsCycle()) {
    return;
  } else if (auto decl = mx::Decl::containing(entity)) {
    PrintCallHierarchy(decl.value(), seen, depth + 1u);
  } else {
    for (const mx::Reference &ref : entity.references()) {
      PrintCallHierarchy(ref, seen, depth + 1u);
    }
  }
}

void PrintCallHierarchy(mx::Stmt entity, SeenEntityList &seen,
                        unsigned depth) {
  SeenEntityTracker enter_entity(seen, entity);
  if (!enter_entity) {
    return;
  }

  if (auto decl = mx::Decl::containing(entity)) {
    PrintCallHierarchy(decl.value(), seen, depth);
  }
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT] --entity_id ID\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index index(mx::EntityProvider::from_remote(
      FLAGS_host, FLAGS_port));

  SeenEntityList seen;

  auto maybe_entity = index.entity(FLAGS_entity_id);
  if (std::holds_alternative<mx::Decl>(maybe_entity)) {
    mx::Decl decl = std::get<mx::Decl>(maybe_entity);
    PrintCallHierarchy(std::move(decl), seen, 0u);

  } else if (std::holds_alternative<mx::Stmt>(maybe_entity)) {
    mx::Stmt stmt = std::get<mx::Stmt>(maybe_entity);
    PrintCallHierarchy(std::move(stmt), seen, 0u);

  } else {
    std::cerr << "Invalid declaration id " << FLAGS_entity_id << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
