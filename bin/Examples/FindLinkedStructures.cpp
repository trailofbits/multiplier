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

#define FILTER_OFFSET_PLACEHOLDER "TYPE:4"

DECLARE_bool(help);
DECLARE_string(db);
DECLARE_bool(names_only);
DEFINE_uint64(max_size, 0u, "Minimum size of record to filter on");
DEFINE_uint64(min_size, 0u, "Maximum size of record to filter on");

// Record filtering
// NOTE: --filter_elastic will also honor --max_size, but this will not represent the true size of discovered target structs
DEFINE_bool(filter_elastic, false, "Filter on elastic records");
DEFINE_bool(filter_self_referencing, false, "Filter on self-referencing records");

// Field filtering (TODO: allow for multiple)
DEFINE_string(filter_offset_type, FILTER_OFFSET_PLACEHOLDER, "Filter on records with a specific type at an offset (in the format TYPE:4)");

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

static void GetSelfReferences(const mx::RecordDecl &record) {
  std::unordered_set<mx::PackedDeclId> seen;
  std::unordered_set<mx::PackedDeclId> self_referencing;

  int level = 0;

  // First pass: identify all directly self-linking / singly linked fields
  for (mx::FieldDecl field : record.fields()) {
    auto pointer_type = mx::PointerType::from(field.type());
    if (!pointer_type) {
      continue;
    }

    auto pointee_type = pointer_type->pointee_type();
    auto record_type = mx::RecordType::from(pointee_type.desugared_type());
    if (!record_type) {
      continue;
    }

    if (record != record_type->declaration()) {
      continue;
    }

    RenderField(record, field, level);
    seen.insert(field.id());
    self_referencing.insert(record.id());
  }

  // Second pass: indirectly self-linking structures, e.g. users of `list_head`.
  for (size_t prev_size = 0u; prev_size < self_referencing.size(); ) {
    prev_size = self_referencing.size();
    ++level;

    for (mx::FieldDecl field : record.fields()) {
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
      //next_self_referencing.insert(record->id());
    }
  }
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE]"
    << " [--max_size MAX_SIZE]"
    << " [--min_size MIN_SIZE]"
    << " [--filter_elastic]"
    << " [--filter_self_referencing]";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  if (FLAGS_min_size > FLAGS_max_size) {
    std::cerr << "ERROR: min_size > max_size" << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index index = InitExample(true);

  for (const mx::RecordDecl record_decl : mx::RecordDecl::in(index)) {
    
    // size range check will take precedence in filtering
    if (FLAGS_max_size != 0 || FLAGS_min_size != 0) {
      if (auto size = record_decl.size()) {
        if (!(*size >= FLAGS_min_size && *size <= FLAGS_max_size)) {
          continue;
        }
      }
    }

    // Flexible/elastic array members must always be the last field
    // TODO: elastic structs that DONT have an explicit flexible field should also be found with some more static analysis
    if (FLAGS_filter_elastic && record_decl.has_flexible_array_member()) {
      auto num_fields = record_decl.num_fields() - 1;
      auto last_field = record_decl.nth_field(num_fields);
      if (!last_field)
        goto self_reference;

      // NOTE: record_decl.has_flexible_array_member() isn't entirely accurate, so do an additional check
      //if (!last_field->is_zero_size())
      //  goto self_reference;

      RenderField(record_decl, *last_field, 0);
    }

self_reference:

    if (FLAGS_filter_self_referencing) {
      GetSelfReferences(record_decl);
    }
  }
  return EXIT_SUCCESS;
}
