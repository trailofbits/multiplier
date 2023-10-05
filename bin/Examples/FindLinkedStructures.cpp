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
#include "multiplier/Types.h"

#define FILTER_OFFSET_PLACEHOLDER "TYPE:4"

DECLARE_bool(help);
DECLARE_string(db);

DEFINE_bool(names_only, false, "Output only the record name, not the entire implementation");
DEFINE_uint64(max_size, 0u, "Minimum size of record to filter on");
DEFINE_uint64(min_size, 0u, "Maximum size of record to filter on");

// Record filtering
// NOTE: --filter_elastic will also honor --max_size, but this will not represent the true size of discovered target structs
DEFINE_bool(filter_elastic, false, "Filter on elastic records");
DEFINE_bool(filter_self_referencing, false, "Filter on self-referencing records");

// Field filtering (TODO: allow for multiple)
DEFINE_string(filter_offset_type, FILTER_OFFSET_PLACEHOLDER, "Filter on records with a specific type at an offset (in the format TYPE:4)");

enum FieldType {
  Elastic,
  SinglySelfReferencing,
  DoublySelfReferencing,
  CustomFilter,
};

using FieldMap = std::unordered_map<mx::PackedDeclId, FieldType>;

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

static void RenderRecord(const mx::RecordDecl &record, FieldMap &field_map) {
  auto fragment = mx::Fragment::containing(record);
  std::cout
      << "Frag ID: " << fragment.id()
      << "\nStructure ID: " << record.id() << "\n";
  RenderFragment(std::cout, fragment, record.tokens(), "\t", true);
  std::cout << "\n\n";
}

static void RenderRecordHighlightedFields(const mx::Index index, const mx::RecordDecl &record, FieldMap &field_map) {
  auto fragment = mx::Fragment::containing(record);
  auto frag_tokens = fragment.file_tokens();

  // populate map with field tokens and the color to highlight with =
  std::unordered_map<unsigned, mx::TokenRange> highlights;
  for (const auto &[field_id, field_type] : field_map) {
    auto field = mx::FieldDecl::by_id(index, field_id);
    if (!field)
      continue;

    unsigned ascii_color;
    switch (field_type) {
    case Elastic:
      ascii_color = 43;
      break;
    case SinglySelfReferencing:
      ascii_color = 44;
      break;
    case DoublySelfReferencing:
      ascii_color = 45;
      break;
    case CustomFilter:
      ascii_color = 46;
      break;
    default:
      break;
    }
    highlights[ascii_color] = field->tokens().file_tokens();
  }

  // render record with highlighted structs
  for (auto tok: frag_tokens) {
    auto found = false;
    for (const auto &[ascii_color, colored_range] : highlights) {
      if (colored_range.index_of(tok)) {
        std::cout << "\u001b[" << ascii_color << "m\033[1m" << tok.data() << "\033[0m";
        found = true;
        break;
      }
    }
    if (!found) {
      std::cout << tok.data();
    }
  }
}

static void GetSelfReferences(const mx::RecordDecl &record, FieldMap &field_map) {
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

    field_map[field.id()] = SinglySelfReferencing;
    seen.insert(field.id());
    self_referencing.insert(field.id());
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

      field_map[field.id()] = DoublySelfReferencing;
      seen.insert(field.id());
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

  std::string typ;
  unsigned int starting_offset;
  if (FLAGS_filter_offset_type != "") {
    std::istringstream ss(FLAGS_filter_offset_type);
    std::getline(ss, typ, ':');
    ss >> starting_offset;
  }

  mx::Index index = InitExample(true);

  for (const mx::RecordDecl record_decl : mx::RecordDecl::in(index)) {

    FieldMap current_field_map;

    // size range check will take precedence in filtering
    if (FLAGS_max_size != 0 || FLAGS_min_size != 0) {
      if (auto size = record_decl.size()) {
        uint64_t actual_size = *size;
        if (!(actual_size >= FLAGS_min_size && actual_size <= FLAGS_max_size)) {
          continue;
        }
      }
    }

    // Match on a field type and an offset
    if (FLAGS_filter_offset_type != "") {

    }

    // Flexible/elastic array members must always be the last field
    // TODO: elastic structs that DONT have an explicit flexible field should also be found with some more static analysis
    bool is_flexible = record_decl.has_flexible_array_member();
    if (FLAGS_filter_elastic && is_flexible) {
      auto num_fields = record_decl.num_fields() - 1;
      auto last_field = record_decl.nth_field(num_fields);
      if (!last_field)
        continue;

      // NOTE: record_decl.has_flexible_array_member() isn't entirely accurate, so do an additional check
      //if (!last_field->is_zero_size())
      //  continue;

      current_field_map[last_field->id()] = Elastic;
    } else if (FLAGS_filter_elastic && !is_flexible) {
      continue;
    }

    // Grab potentially multiple fields that are self-referencing
    if (FLAGS_filter_self_referencing) {
      GetSelfReferences(record_decl, current_field_map);
    }

    if (FLAGS_names_only) {
      std::cout << record_decl.name() << std::endl;
      continue;
    }

    // Just output struct definition with no field highlighting if no filters applied
    if (current_field_map.empty()) {
      RenderRecord(record_decl, current_field_map);

    // TODO: Otherwise render the struct with all significant fields highlighted
    } else {
      RenderRecordHighlightedFields(index, record_decl, current_field_map);
    }
  }
  return EXIT_SUCCESS;
}
