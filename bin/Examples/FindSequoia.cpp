// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <sstream>
#include <vector>

#include <multiplier/Analysis/Taint.h>
#include <multiplier/Entities/BuiltinType.h>
#include <multiplier/Entities/CallExpr.h>
#include <multiplier/Entities/CastKind.h>
#include <multiplier/Entities/ImplicitCastExpr.h>
#include <multiplier/Entities/StmtKind.h>

#include "Index.h"

DEFINE_uint32(max_depth, 1000u, "Maximum path length depth for tainting");

static constexpr mx::BuiltinTypeKind kSketchyKinds[][2] = {
    {mx::BuiltinTypeKind::U_LONG_LONG, mx::BuiltinTypeKind::INT},
    {mx::BuiltinTypeKind::U_LONG_LONG, mx::BuiltinTypeKind::SHORT},
    {mx::BuiltinTypeKind::U_LONG_LONG, mx::BuiltinTypeKind::S_CHAR},

    {mx::BuiltinTypeKind::U_LONG, mx::BuiltinTypeKind::INT},
    {mx::BuiltinTypeKind::U_LONG, mx::BuiltinTypeKind::SHORT},
    {mx::BuiltinTypeKind::U_LONG, mx::BuiltinTypeKind::S_CHAR},
    {mx::BuiltinTypeKind::U_LONG, mx::BuiltinTypeKind::U_CHAR},

    {mx::BuiltinTypeKind::U_INT, mx::BuiltinTypeKind::SHORT},
    {mx::BuiltinTypeKind::U_INT, mx::BuiltinTypeKind::S_CHAR},

    {mx::BuiltinTypeKind::U_SHORT, mx::BuiltinTypeKind::S_CHAR},
};

// Should we skip a result, e.g. froma `sizeof(blah)`.
static bool IsIgnorableCallArgument(const mx::Expr &expr) {
  switch (expr.kind()) {
    case mx::StmtKind::INTEGER_LITERAL:
    case mx::StmtKind::UNARY_EXPR_OR_TYPE_TRAIT_EXPR:
      return true;
    default:
      return false;
  }
}

static bool IsSketchy(const mx::CastExpr &cast) {
  mx::Type source_type = cast.sub_expression().type()->canonical_type();
  std::optional<mx::Type> maybe_dest_type = cast.type();

  if (!maybe_dest_type) {
    return false;
  }

  mx::Type dest_type = maybe_dest_type->canonical_type();

  // Make sure the source and dest types are builtins.
  std::optional<mx::BuiltinType> source_builtin =
      mx::BuiltinType::from(source_type);
  std::optional<mx::BuiltinType> dest_builtin =
      mx::BuiltinType::from(dest_type);
  if (!source_builtin || !dest_builtin) {
    return false;
  }

  mx::BuiltinTypeKind source_type_kind = source_builtin->builtin_kind();
  mx::BuiltinTypeKind dest_type_kind = dest_builtin->builtin_kind();

  for (auto [from_kind, to_kind] : kSketchyKinds) {
    if (source_type_kind == from_kind && dest_type_kind == to_kind) {
      return true;
    }
  }

  return false;
}

static void ProcessResult(mx::TaintTracker &tt,
                          const mx::ImplicitCastExpr &ice,
                          mx::TaintTrackingResult res,
                          unsigned depth) {
  if (depth > FLAGS_max_depth) {
    return;
  }

  if (auto step = std::get_if<mx::TaintTrackingStep>(&res)) {
    for (mx::TaintTrackingResult next_res : tt.add_source(*step)) {
      ProcessResult(tt, ice, std::move(next_res), depth + 1u);
    }

  } else if (auto sink = std::get_if<mx::TaintTrackingSink>(&res)) {
    switch (sink->kind()) {
      case mx::TaintTrackingSinkKind::UNCONTROLLED_ARRAY_INDEX:
      case mx::TaintTrackingSinkKind::UNCONTROLLED_INDIRECT_MEMBER:
      case mx::TaintTrackingSinkKind::UNCONTROLLED_POINTER:
        std::cerr << ice.id() << " reaches " << sink->id() << " after "
                  << depth << " steps\n";
        break;
      default:
        break;
    }
  }
}

int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] --fragment_id ID\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample(true);

  mx::TaintTracker tt(index);

  for (mx::CallExpr call : mx::CallExpr::in(index)) {
    for (mx::Expr arg : call.arguments()) {
      auto maybe_ice = mx::ImplicitCastExpr::from(arg);
      if (!maybe_ice) {
        continue;
      }

      mx::ImplicitCastExpr ice = std::move(maybe_ice.value());

      if (ice.cast_kind() != mx::CastKind::INTEGRAL_CAST ||
          IsIgnorableCallArgument(ice) || !IsSketchy(ice)) {
        continue;
      }

      for (mx::TaintTrackingResult res : tt.add_source(ice)) {
        ProcessResult(tt, ice, std::move(res), 0u);
      }
    }
  }

  return EXIT_SUCCESS;
}
