// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdlib>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <multiplier/Entities/FieldDecl.h>
#include <multiplier/Entities/PointerType.h>
#include <multiplier/Entities/RecordDecl.h>
#include <multiplier/Entities/RecordType.h>
#include <sstream>

#include "Index.h"

DECLARE_bool(help);
DECLARE_string(db);

static void RenderField(const mx::RecordDecl &record,
                        const mx::FieldDecl &field,
                        int level) {
  auto fragment = mx::Fragment::containing(record);

  std::cout
      << "Frag ID: " << fragment.id()
      << "\nStructure ID: " << record.id()
      << "\nField ID: " << field.id()
      << "\nLevel of indirection: " << level << "\n";
  RenderFragment(std::cout, fragment, field.tokens(), "\t", true);
  std::cout << "\n\n";
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE]"

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index index = InitExample(true);

  std::unordered_set<mx::PackedDeclId> self_referencing;
  std::unordered_set<mx::PackedDeclId> seen;

  int level = 0;

  // Identify directly self-linking structures, e.g. `list_head`.
  for (mx::FieldDecl field : mx::FieldDecl::in(index)) {
    auto pointer_type = mx::PointerType::from(field.type());
    if (!pointer_type) {
      continue;
    }

    auto pointee_type = pointer_type->pointee_type();
    auto record_type = mx::RecordType::from(pointee_type.desugared_type());
    if (!record_type) {
      continue;
    }

    auto record = mx::RecordDecl::from(field.parent_declaration());
    if (!record) {
      continue;
    }

    if (*record != record_type->declaration()) {
      continue;
    }

    RenderField(record.value(), field, level);

    seen.insert(field.id());
    self_referencing.insert(record->id());
  }

  // Identify indirectly self-linking structures, e.g. users of `list_head`.
  for (size_t prev_size = 0u; prev_size < self_referencing.size(); ) {
    prev_size = self_referencing.size();
    ++level;

    std::unordered_set<mx::PackedDeclId> next_self_referencing;

    for (mx::FieldDecl field : mx::FieldDecl::in(index)) {
      if (seen.contains(field.id())) {
        continue;
      }

      auto record_type = mx::RecordType::from(field.type().desugared_type());
      if (!record_type) {
        continue;
      }

      auto byval_record = record_type->declaration();
      if (!self_referencing.contains(byval_record.id())) {
        continue;
      }

      auto record = mx::RecordDecl::from(field.parent_declaration());
      if (!record) {
        continue;
      }

      RenderField(record.value(), field, level);

      seen.insert(field.id());
      next_self_referencing.insert(record->id());
    }

    self_referencing.insert(next_self_referencing.begin(),
                            next_self_referencing.end());
  }

  return EXIT_SUCCESS;
}
