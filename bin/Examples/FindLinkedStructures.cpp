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
#include <unordered_set>

#include "Index.h"
#include "multiplier/Types.h"

#define FILTER_OFFSET_PLACEHOLDER "TYPE:4"

DECLARE_bool(help);
DECLARE_string(db);

DEFINE_bool(names_only, false,
            "Output only the record name, not the entire implementation");

// Record size filtering
DEFINE_uint64(min_size, 0u, "Minimum size of record to filter on");
DEFINE_uint64(max_size, UINT64_MAX, "Maximum size of record to filter on");

// Record property filtering
// NOTE: --filter_elastic will also honor --max_size, but this will not
// represent the true size of discovered target structs
DEFINE_bool(filter_elastic, false, "Filter on elastic records");
DEFINE_bool(filter_self_referencing, false,
            "Filter on self-referencing records");

// TODO: filter on exact/fuzzy name
// TODO: filter on exact/fuzzy path

// Field property filtering (TODO: allow for multiple)
DEFINE_string(filter_offset_type, FILTER_OFFSET_PLACEHOLDER,
              "Filter on records with a specific type at an exact offset (in "
              "the format TYPE:4)");

enum FieldType {
  Elastic,
  DirectSelfReferencing,
  IndirectSelfReferencing,
  CustomFilter,
};

//
using HighlightedFields = std::unordered_map<mx::PackedDeclId, FieldType>;

// maps a RecordDecl to a set of significant child fields
using SelfReferenceMap =
    std::unordered_map<mx::PackedDeclId, std::unordered_set<mx::PackedDeclId>>;

static void RenderRecord(const mx::RecordDecl &record) {
  auto fragment = mx::Fragment::containing(record);
  std::cout << "Frag ID: " << fragment.id() << "\nStructure ID: " << record.id()
            << "\nStructure Size: " << *record.size() << "\n";

  RenderFragment(std::cout, fragment, record.tokens(), "\t", true);
  std::cout << "\n\n";
}

static int FieldTypeColor(const FieldType &field_type) {
  unsigned ascii_color;
  switch (field_type) {
  case Elastic:
    ascii_color = 43;
    break;
  case DirectSelfReferencing:
    ascii_color = 44;
    break;
  case IndirectSelfReferencing:
    ascii_color = 45;
    break;
  case CustomFilter:
    ascii_color = 46;
    break;
  default:
    break;
  }
  return ascii_color;
}

static void RenderRecordHighlightedFields(const mx::Index index,
                                          const mx::RecordDecl &record,
                                          HighlightedFields &field_map) {
  auto fragment = mx::Fragment::containing(record);
  auto frag_tokens = fragment.file_tokens();
  std::cout << "Frag ID: " << fragment.id() << "\nStructure ID: " << record.id()
            << "\nStructure Size: " << *record.size()
            << "\nNumber of Highlighted Fields: " << field_map.size() << "\n\n";

  // populate map with field tokens and the color to highlight with
  std::unordered_map<mx::EntityId, unsigned> highlights;
  for (const auto &[field_id, field_type] : field_map) {
    auto field = mx::FieldDecl::by_id(index, field_id);
    if (!field)
      continue;

    auto colored_range = field->tokens().file_tokens();
    for (auto token : colored_range) {
      highlights.emplace(token.id(), FieldTypeColor(field_type));
    }
  }

  // render record with highlighted structs
  for (auto tok : frag_tokens) {
    auto highligted_tok = highlights.find(tok.id());
    if (highligted_tok != highlights.end()) {
      std::cout << "\u001b[" << highligted_tok->second << "m\033[1m"
                << tok.data() << "\033[0m";
    } else {
      std::cout << tok.data();
    }
  }
  std::cout << "\n\n";
}

static void GetInitialSelfReferences(mx::Index &index,
                                     SelfReferenceMap &self_refs) {
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

    // field type matches parent record type
    if (record != record_type->declaration()) {
      continue;
    }
    self_refs[record->id()].insert(field.id());
  }
}

static bool GetIndirectSelfReferences(const mx::RecordDecl &record,
                                      SelfReferenceMap &self_refs,
                                      HighlightedFields &field_map) {
  bool found = false;
  for (mx::FieldDecl field : record.fields()) {

    // skip if already to be highlighted
    if (field_map.contains(field.id())) {
      continue;
    }

    auto record_type = mx::RecordType::from(field.type().desugared_type());
    if (!record_type) {
      continue;
    }

    auto byval_record = record_type->declaration();
    if (self_refs.contains(byval_record.id())) {
      field_map[field.id()] = IndirectSelfReferencing;
      found = true;
    }
  }
  return found;
}

// Helper to test if a type matches at a field offset for a target struct
static bool MatchTypeAndOffset(const mx::RecordDecl &record,
                               std::string type_to_match, int offset_to_match,
                               HighlightedFields &field_map) {
  for (mx::FieldDecl field : record.fields()) {
    auto field_type = field.type().desugared_type();
    std::string_view field_name = field_type.tokens().data();
    auto offset_in_bits = field.offset_in_bits();
    if (!offset_in_bits)
      return false;

    if (field_name == type_to_match && offset_to_match == offset_in_bits) {
      field_map[field.id()] = CustomFilter;
      return true;
    }
  }
  return false;
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss << "Usage: " << argv[0] << " [--db DATABASE]"
     << " [--name_only]"
     << " [--max_size MAX_SIZE]"
     << " [--min_size MIN_SIZE]"
     << " [--filter_elastic]"
     << " [--filter_self_referencing]"
     << " [--filter_offset_type TYPE:OFFSET]";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  // validate size check range
  if (FLAGS_min_size > FLAGS_max_size) {
    std::cerr << "ERROR: min_size > max_size" << std::endl;
    return EXIT_FAILURE;
  }

  // parse offset filtering expression
  std::string type_to_match = "";
  int offset_to_match = -1;
  if (FLAGS_filter_offset_type != FILTER_OFFSET_PLACEHOLDER) {

    // split at delimiter
    size_t pos = FLAGS_filter_offset_type.find(":");
    if (pos == std::string::npos) {
      std::cerr << "Invalid format: delimiter not found" << std::endl;
      return EXIT_FAILURE;
    }

    // parse the type to match before the delimiter
    type_to_match = FLAGS_filter_offset_type.substr(0, pos);

    // parse the integer after the delimiter
    std::string secondPart = FLAGS_filter_offset_type.substr(pos + 1);
    std::stringstream strstream(secondPart);
    strstream >> offset_to_match;
  }

  mx::Index index = InitExample(true);
  std::unordered_set<mx::PackedDeclId> seen_records;
  SelfReferenceMap self_reference_uses;

  // do an initial run to get all self-referencing records to later help
  // determine if a target struct is has a field reference to it
  if (FLAGS_filter_self_referencing) {
    GetInitialSelfReferences(index, self_reference_uses);
  }

  for (const mx::RecordDecl record_decl : mx::RecordDecl::in(index)) {

    // sanity: deal with repeats
    if (seen_records.contains(record_decl.id()))
      continue;
    seen_records.insert(record_decl.id());

    // sanity: skip forward declarations and anonymous structs
    auto _record = record_decl.definition();
    if (!_record)
      continue;

    const mx::RecordDecl record = *_record;
    if (record.size() == 0 || record.name() == "")
      continue;

    // size range check will take precedence in filtering
    if (FLAGS_max_size != UINT64_MAX || FLAGS_min_size != 0) {
      if (auto size = record.size()) {
        uint64_t actual_size = *size;
        if (!(actual_size >= FLAGS_min_size && actual_size <= FLAGS_max_size)) {
          continue;
        }
      }
    }

    HighlightedFields highlighted_fields;

    // Match on a field type and an offset if set
    if (FLAGS_filter_offset_type != FILTER_OFFSET_PLACEHOLDER) {

      // remove spaces when matching with tokens (TODO: is this necessary?)
      type_to_match.erase(
          std::remove(type_to_match.begin(), type_to_match.end(), ' '),
          type_to_match.end());

      bool matched = MatchTypeAndOffset(record_decl, type_to_match,
                                        offset_to_match, highlighted_fields);
      if (!matched)
        continue;
    }

    // Flexible/elastic array members must always be the last field
    // TODO: elastic structs that DONT have an explicit flexible field should
    // also be found with some more static analysis
    bool is_flexible = record.has_flexible_array_member();
    if (FLAGS_filter_elastic && is_flexible) {
      auto num_fields = record.num_fields() - 1;
      auto last_field = record.nth_field(num_fields);
      if (!last_field)
        continue;

      // NOTE: record.has_flexible_array_member() isn't entirely accurate, so do
      // an additional check
      // if (!last_field->is_zero_size())
      //  continue;

      highlighted_fields[last_field->id()] = Elastic;
    } else if (FLAGS_filter_elastic && !is_flexible) {
      continue;
    }

    // Grab potentially multiple fields that are self-referencing from initial
    // run
    if (FLAGS_filter_self_referencing) {
      bool found_self_referencing = false;

      // our record itself is directly self-referencing
      if (self_reference_uses.contains(record.id())) {
        for (auto field_id : self_reference_uses[record.id()]) {
          highlighted_fields[field_id] = DirectSelfReferencing;
        }
        found_self_referencing = true;
      }

      // our current target's fields contains other self-referencing records
      found_self_referencing = GetIndirectSelfReferences(
          record, self_reference_uses, highlighted_fields);

      // skip outputting this
      if (!found_self_referencing)
        continue;
    }

    if (FLAGS_names_only) {
      std::cout << record.name() << std::endl;
      continue;
    }

    // Just output struct definition with no field highlighting if no filters
    // applied
    if (highlighted_fields.empty()) {
      RenderRecord(record);

      // Otherwise render the struct with all significant fields highlighted
    } else {
      RenderRecordHighlightedFields(index, record, highlighted_fields);
    }
  }
  return EXIT_SUCCESS;
}
