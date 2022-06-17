// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <sstream>

#include "Index.h"

DEFINE_uint64(fragment_id, 0, "ID of the fragment from which to check for call expressions with implicit integer casts");
DEFINE_uint64(file_id, 0, "ID of the file from which to check for call expressions with implicit integer casts");
DEFINE_uint64(entity_id, 0, "ID of the entity from which to check for uses in call expressions with implicit integer casts");
DEFINE_bool(show_locations, false, "Show the locations of users?");

// Checks whether any arguments passed the provided call expression are used
// as an implicit cast, specifically, from an unsigned long to a signed int
// (TODO: generalize the casts we care about). For example, consider:
//
// foo(int a);
// bar(size_t b) { foo(b); }
//
// CheckCallForImplicitCast will identify that the foo(b) call expression has
// an implicit cast from an unsigned long to a signed int.
//
// This was motivated by the PHP vulnerability described here, and is an
// attempt to identify more instances of the vulnerable code pattern:
// https://pwning.systems/posts/php_filter_var_shenanigans/
static void CheckCallForImplicitCast(const mx::CallExpr call_expr) {
  for (auto argument : call_expr.arguments()) {
    if (auto cast_expr = mx::ImplicitCastExpr::from(argument)) {
      if (cast_expr->is_part_of_explicit_cast() ||
          cast_expr->cast_kind() != mx::CastKind::INTEGRAL_CAST) {
        continue;
      }
      auto source_type = cast_expr->sub_expression().type()->canonical_type();
      auto dest_type = cast_expr->type();

      auto source_builtin = mx::BuiltinType::from(source_type);
      auto dest_builtin = mx::BuiltinType::from(dest_type);
      if (!source_builtin || !dest_builtin) {
        continue;
      }

      auto source_type_kind = source_builtin->builtin_kind();
      auto dest_type_kind = dest_builtin->builtin_kind();

      // TODO(wunused): generalize the sketchy casts we care about.
      if (source_type_kind != mx::BuiltinTypeKind::U_LONG ||
          dest_type_kind != mx::BuiltinTypeKind::INT) {
        continue;
      }

      mx::Fragment fragment = mx::Fragment::containing(call_expr);
      mx::File file = mx::File::containing(fragment);

      if (FLAGS_show_locations) {
        auto file = mx::File::containing(mx::Fragment::containing(call_expr));
        std::cout << file_paths[file.id()].generic_string();
        if (auto tok = call_expr.tokens()[0]) {
          if (auto line_col = tok.location(location_cache)) {
            std::cout << ':' << line_col->first << ':' << line_col->second;
          }
        }
        std::cout << std::endl;
      }

      std::cout
          << "file ID: " << file.id() << '\t'
          << "frag ID: " << fragment.id() << '\t'
          << "entity ID: " << cast_expr->id() << '\t'
          << mx::EnumeratorName(source_builtin->builtin_kind())
          << " -> "
          << mx::EnumeratorName(dest_builtin->builtin_kind()) << '\t'
          << cast_expr->tokens().data()
          << std::endl;

      if (FLAGS_show_locations) {
        std::cout << std::endl;
        if (auto toks = call_expr.tokens()) {
          RenderFragment(std::cout, fragment, toks, "\t", true);
        }
        std::cout << std::endl;
      }
    }
  }
}

static void FindSketchyUsesOfFragment(const mx::Fragment fragment) {
  for (mx::CallExpr call_expr : mx::CallExpr::in(fragment)) {
    CheckCallForImplicitCast(call_expr);
  }
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT] [--fragment_id ID | --file_id ID]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample(FLAGS_show_locations);

  if (FLAGS_entity_id) {
    auto maybe_entity = index.entity(FLAGS_entity_id);
    if (!std::holds_alternative<mx::Decl>(maybe_entity)) {
      std::cerr << "Invalid decl id " << FLAGS_entity_id << std::endl;
      return EXIT_FAILURE;
    }

    mx::Decl decl = std::get<mx::Decl>(maybe_entity);
    for (const mx::Reference ref : decl.references()) {
      const mx::Stmt ref_stmt = ref.statement();
      for (const mx::CallExpr &call_expr : mx::CallExpr::containing(ref_stmt)) {
        CheckCallForImplicitCast(call_expr);
      }
    }

  } else if (FLAGS_fragment_id) {
    auto fragment = index.fragment({FLAGS_fragment_id});
    if (!fragment) {
      std::cerr << "Invalid fragment id " << FLAGS_fragment_id << std::endl;
      return EXIT_FAILURE;
    }
    FindSketchyUsesOfFragment(std::move(*fragment));

  } else if (FLAGS_file_id) {
    auto file = index.file({FLAGS_file_id});
    if (!file) {
      std::cerr << "Invalid file id " << FLAGS_file_id << std::endl;
      return EXIT_FAILURE;
    }
    for (mx::Fragment fragment : mx::Fragment::in(*file)) {
      FindSketchyUsesOfFragment(std::move(fragment));
    }

  } else {
    for (mx::File file : mx::File::in(index)) {
      for (mx::Fragment fragment : mx::Fragment::in(file)) {
        FindSketchyUsesOfFragment(std::move(fragment));
      }
    }
  }

  return EXIT_SUCCESS;
}
