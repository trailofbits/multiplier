// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdlib>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <multiplier/Entities/FieldDecl.h>
#include <multiplier/Entities/RecordDecl.h>
#include <multiplier/Entities/RecordType.h>
#include <sstream>
#include <csignal>
#include <csetjmp>

#include "Index.h"

DECLARE_bool(help);
DECLARE_string(db);

static bool gHasJumpBuf = false;
static sigjmp_buf gJumpBuf;

static void HandleSegfault(int) {
  if (gHasJumpBuf) {
    gHasJumpBuf = false;
    siglongjmp(gJumpBuf, 1);
  } else {
    abort();
  }
}

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
    << " [--db file]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  signal(SIGSEGV, HandleSegfault);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index index = InitExample(true);

  std::unordered_set<mx::PackedDeclId> self_referencing;
  std::unordered_set<mx::PackedDeclId> next_self_referencing;
  std::unordered_set<mx::PackedDeclId> seen;

  int level = 0;

  std::optional<mx::Type> pointee_type;
  std::optional<mx::RecordType> record_type;
  std::optional<mx::RecordDecl> record;

  // Identify directly self-linking structures, e.g. `list_head`.
  for (mx::FieldDecl field : mx::FieldDecl::in(index)) {
    pointee_type = field.type().pointee_type();
    if (!pointee_type) {
      continue;
    }

    gHasJumpBuf = false;
    if (!sigsetjmp(gJumpBuf, 1)) {
      gHasJumpBuf = true;

      record_type = mx::RecordType::from(pointee_type->desugared_type());
      if (!record_type) {
        continue;
      }

      record = mx::RecordDecl::from(field.parent_declaration());
      if (!record) {
        continue;
      }

      if (*record != record_type->declaration()) {
        continue;
      }

      gHasJumpBuf = false;

    } else {
      continue;  // Crash.
    }

    RenderField(record.value(), field, level);

    seen.insert(field.id());
    self_referencing.insert(record->id());
  }

  std::optional<mx::TagDecl> byval_record;

  // Identify indirectly self-linking structures, e.g. users of `list_head`.
  for (size_t prev_size = 0u; prev_size < self_referencing.size(); ) {
    prev_size = self_referencing.size();
    ++level;

    for (mx::FieldDecl field : mx::FieldDecl::in(index)) {
      if (seen.contains(field.id())) {
        continue;
      }

      gHasJumpBuf = false;
      if (!sigsetjmp(gJumpBuf, 1)) {
        gHasJumpBuf = true;

        record_type = mx::RecordType::from(field.type().desugared_type());
        if (!record_type) {
          continue;
        }

        byval_record = record_type->declaration();
        if (!self_referencing.contains(byval_record->id())) {
          continue;
        }

        record = mx::RecordDecl::from(field.parent_declaration());
        if (!record) {
          continue;
        }
      } else {
        continue;  // Crash.
      }

      RenderField(record.value(), field, level);

      seen.insert(field.id());
      next_self_referencing.insert(record->id());
    }

    self_referencing.insert(next_self_referencing.begin(),
                            next_self_referencing.end());
    next_self_referencing.clear();
  }

  return EXIT_SUCCESS;
}
