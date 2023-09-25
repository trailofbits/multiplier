// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <multiplier/AST.h>
#include <sstream>

#include "Index.h"

DEFINE_bool(show_implicit, false, "Show implicit casts?");
DEFINE_bool(show_explicit, false, "Show explicit casts?");
DEFINE_bool(show_sign_changing, false, "Show sign-changing casts?");
DEFINE_bool(show_sign_down_cast, false, "Show sign down-casts? E.g. int to short.");
DEFINE_bool(show_sign_changing_down_cast, false, "Show sign-changing downcasts.");

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

static constexpr mx::BuiltinTypeKind kSignDownCastKinds[][2] = {
    {mx::BuiltinTypeKind::LONG_LONG, mx::BuiltinTypeKind::INT},
    {mx::BuiltinTypeKind::LONG_LONG, mx::BuiltinTypeKind::SHORT},
    {mx::BuiltinTypeKind::LONG_LONG, mx::BuiltinTypeKind::S_CHAR},

    {mx::BuiltinTypeKind::LONG, mx::BuiltinTypeKind::INT},
    {mx::BuiltinTypeKind::LONG, mx::BuiltinTypeKind::SHORT},
    {mx::BuiltinTypeKind::LONG, mx::BuiltinTypeKind::S_CHAR},

    {mx::BuiltinTypeKind::INT, mx::BuiltinTypeKind::SHORT},
    {mx::BuiltinTypeKind::INT, mx::BuiltinTypeKind::S_CHAR},

    {mx::BuiltinTypeKind::SHORT, mx::BuiltinTypeKind::S_CHAR},
};

static constexpr mx::BuiltinTypeKind kSignChangingKinds[][2] = {
    {mx::BuiltinTypeKind::U_LONG_LONG, mx::BuiltinTypeKind::LONG_LONG},
    {mx::BuiltinTypeKind::LONG_LONG, mx::BuiltinTypeKind::U_LONG_LONG},
    {mx::BuiltinTypeKind::U_LONG_LONG, mx::BuiltinTypeKind::LONG},
    {mx::BuiltinTypeKind::LONG, mx::BuiltinTypeKind::U_LONG_LONG},
    {mx::BuiltinTypeKind::U_LONG, mx::BuiltinTypeKind::LONG_LONG},
    {mx::BuiltinTypeKind::LONG_LONG, mx::BuiltinTypeKind::U_LONG},
    {mx::BuiltinTypeKind::U_LONG, mx::BuiltinTypeKind::LONG},
    {mx::BuiltinTypeKind::LONG, mx::BuiltinTypeKind::U_LONG},
    {mx::BuiltinTypeKind::U_INT, mx::BuiltinTypeKind::INT},
    {mx::BuiltinTypeKind::INT, mx::BuiltinTypeKind::U_INT},
    {mx::BuiltinTypeKind::U_SHORT, mx::BuiltinTypeKind::SHORT},
    {mx::BuiltinTypeKind::SHORT, mx::BuiltinTypeKind::U_SHORT},
    {mx::BuiltinTypeKind::U_CHAR, mx::BuiltinTypeKind::S_CHAR},
    {mx::BuiltinTypeKind::S_CHAR, mx::BuiltinTypeKind::U_CHAR},
};

enum class CastBehavior {
  Sketchy,
  SignDowncast,
  SignChange,
  SignChangingDowncast
};

static const std::map<CastBehavior, std::string> kOuts {
  {CastBehavior::Sketchy, "Sketchy"},
  {CastBehavior::SignDowncast, "Sign downcast"},
  {CastBehavior::SignChange, "Sign change"},
  {CastBehavior::SignChangingDowncast, "Sign-changing downcast"},
};

// Should we skip a result, e.g. froma `sizeof(blah)`.
static bool IsIgnorableCallArgument(const mx::Expr &expr) {
  if (auto lit = mx::IntegerLiteral::from(expr)) {
    return !lit->token().data().starts_with('-');

  // E.g. `sizeof`, `alignof`, etc.
  } else if (mx::UnaryExprOrTypeTraitExpr::from(expr)) {
    return true;

  } else {
    return false;
  }
}

// Helper to test for sketchy type downcasts
std::optional<CastBehavior> ProfileCastBehavior(
    mx::BuiltinTypeKind source_type_kind, mx::BuiltinTypeKind dest_type_kind) {
  for (auto [from_kind, to_kind] : kSketchyKinds) {
    if (source_type_kind == from_kind && dest_type_kind == to_kind) {
      return CastBehavior::Sketchy;
    }
  }

  if (FLAGS_show_sign_down_cast) {
    for (auto [from_kind, to_kind] : kSignDownCastKinds) {
      if (source_type_kind == from_kind && dest_type_kind == to_kind) {
        return CastBehavior::SignDowncast;
      }
    }
  }

  if (FLAGS_show_sign_changing) {
    for (auto [from_kind, to_kind] : kSignChangingKinds) {
      if (source_type_kind == from_kind && dest_type_kind == to_kind) {
        return CastBehavior::SignChange;
      }
    }
  }

  if (FLAGS_show_sign_changing_down_cast) {
    auto from_kind_signed = source_type_kind;
    auto from_kind_unsigned = source_type_kind;
    auto found = false;
    for (auto [from_kind, to_kind] : kSignChangingKinds) {
      if (source_type_kind == from_kind && dest_type_kind == to_kind) {
        from_kind_signed = from_kind;
        from_kind_unsigned = to_kind;
        found = true;
        break;
      }
    }

    if (found) {
      for (auto [from_kind, to_kind] : kSignDownCastKinds) {
        if (source_type_kind == from_kind || dest_type_kind != to_kind) {
          continue;
        }

        if (from_kind_signed == from_kind || from_kind_unsigned == from_kind) {
          return CastBehavior::SignChangingDowncast;
        }
      }
    }
  }

  return std::nullopt;
}

// Find the statement that value represents the current line of code.
static mx::Stmt FindLine(mx::Stmt prev_stmt) {
  // Find implicit casts with the return value
  for (mx::Stmt stmt : mx::Stmt::containing(prev_stmt)) {
    switch (stmt.kind()) {

      // Don't ascend too far up the statement parentage.
      case mx::StmtKind::CASE_STMT:
      case mx::StmtKind::DEFAULT_STMT:
      case mx::StmtKind::LABEL_STMT:
      case mx::StmtKind::COMPOUND_STMT:
      case mx::StmtKind::SWITCH_STMT:
      case mx::StmtKind::DO_STMT:
      case mx::StmtKind::WHILE_STMT:
      case mx::StmtKind::FOR_STMT:
      case mx::StmtKind::IF_STMT:
      case mx::StmtKind::CXX_TRY_STMT:
      case mx::StmtKind::CXX_FOR_RANGE_STMT:
      case mx::StmtKind::CXX_CATCH_STMT:
      case mx::StmtKind::COROUTINE_BODY_STMT:  // Not sure what this is.
        return prev_stmt;

      case mx::StmtKind::DECL_STMT:
        return stmt;

      default:
        prev_stmt = stmt;
        break;
    }
  }
  return prev_stmt;
}

// Output prettified results for the offending call. Tokens for the originating
// expression should be generated separately in the appropriate heuristic.
static void PrettifyCallResults(
    const mx::CallExpr &call_expr, const mx::Stmt &use,
    CastBehavior kind, mx::BuiltinTypeKind source_type_kind,
    mx::BuiltinTypeKind dest_type_kind,
    std::optional<unsigned> arg_index=std::nullopt) {

  mx::Fragment fragment = mx::Fragment::containing(call_expr);
  auto file = mx::File::containing(fragment);

  if (file) {
    std::cout << "Location: " << file_paths[file->id()].generic_string();
    if (auto tok = call_expr.tokens()[0]) {
      if (auto line_col = tok.location(location_cache)) {
        std::cout << ':' << line_col->first << ':' << line_col->second;
      }
    }
    std::cout << '\n';
  }

  if (file) {
    std::cout
        << "File ID: " << file->id() << '\n';
  }

  std::cout
      << "Frag ID: " << fragment.id()
      << "\nEntity ID: " << use.id()
      << "\nKind: " << kOuts.at(kind) << " ("
      << mx::EnumeratorName(source_type_kind)
      << " to "
      << mx::EnumeratorName(dest_type_kind)
      << ")\nCall: " << call_expr.tokens().file_tokens().data() << "\n";


  // Print out a declaration of the function.
  if (std::optional<mx::FunctionDecl> callee = call_expr.direct_callee();
      callee && !callee->is_implicit()) {
    std::cout << "Declaration:";
    if (callee->is_definition()) {
      for (mx::FunctionDecl redecl : callee->redeclarations()) {
        if (!redecl.is_definition()) {
          callee.reset();
          callee.emplace(std::move(redecl));
          break;
        }
      }
    }

    mx::TokenRange param_toks;
    if (auto param = callee->nth_parameter(*arg_index);
        param && arg_index) {
      param_toks = param->tokens();
    }

    std::stringstream ss;
    RenderFragment(ss, mx::Fragment::containing(*callee),
                   param_toks, "\t", true);
    for (char c : ss.str()) {
      if (c == '{') {
        break;
      } else {
        std::cout << c;
      }
    }
    std::cout << "\n";
  }

  std::cout
      << "Use:";

  // Try to highlight all tokens but the use.
  auto line_stmt = FindLine(call_expr);
  auto highlight_toks = FileTokenIdsFor(line_stmt.tokens());
  if (line_stmt.id() != use.id()) {
    auto unhighlight_toks = FileTokenIdsFor(use.tokens());
    std::erase_if(highlight_toks, [&unhighlight_toks] (mx::RawEntityId id) {
      return unhighlight_toks.count(id);
    });
  }

  RenderFragment(std::cout, fragment, highlight_toks, "\t", true);
  std::cout << "\n\n";
}

// Filter by implicit/explicit, and only give us back integral casts.
static bool IsInterestingCast(const std::optional<mx::CastExpr> &cast) {
  if (!cast || cast->cast_kind() != mx::CastKind::INTEGRAL_CAST) {
    return false;
  }

  if (auto implicit = mx::ImplicitCastExpr::from(*cast)) {
    if (!FLAGS_show_implicit &&
        !(FLAGS_show_explicit && implicit->is_part_of_explicit_cast())) {
      return false;
    }
  } else if (mx::ExplicitCastExpr::from(*cast)) {
    if (!FLAGS_show_explicit) {
      return false;
    }
  } else {
    return false;
  }
  return true;
}

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
static void FindSketchyArgumentCasts(const mx::CallExpr &call_expr) {
  auto arg_num = 0u;
  for (mx::Expr argument : call_expr.arguments()) {
    ++arg_num;

    std::optional<mx::CastExpr> cast_expr = mx::CastExpr::from(argument);
    if (!IsInterestingCast(cast_expr) ||
        IsIgnorableCallArgument(cast_expr->ignore_casts())) {
      continue;
    }

    mx::Type source_type =
        cast_expr->sub_expression().type()->canonical_type();
    std::optional<mx::Type> maybe_dest_type = cast_expr->type();

    if (!maybe_dest_type) {
      continue;
    }

    mx::Type dest_type = maybe_dest_type->canonical_type();

    // Make sure the source and dest types are builtins.
    std::optional<mx::BuiltinType> source_builtin =
        mx::BuiltinType::from(source_type);
    std::optional<mx::BuiltinType> dest_builtin =
        mx::BuiltinType::from(dest_type);
    if (!source_builtin || !dest_builtin) {
      continue;
    }

    mx::BuiltinTypeKind source_type_kind = source_builtin->builtin_kind();
    mx::BuiltinTypeKind dest_type_kind = dest_builtin->builtin_kind();

    std::optional<CastBehavior> cast_behavior = ProfileCastBehavior(
        source_type_kind, dest_type_kind);
    if (!cast_behavior) {
      continue;
    }

    PrettifyCallResults(call_expr, *cast_expr, *cast_behavior, source_type_kind,
                        dest_type_kind, arg_num - 1u);
  }
}

// Given a call expression and the parsed type of the parent assignment/declaration statement,
// perform the same sketchy downcasting check.
static void CheckCallRetForImplicitCast(const mx::CallExpr &call_expr,
                                        const mx::CastExpr &cast_expr) {
  mx::Type call_type = call_expr.call_return_type().canonical_type();
  mx::Type cast_type = cast_expr.type()->canonical_type();

  std::optional<mx::BuiltinType> call_builtin = mx::BuiltinType::from(call_type);
  std::optional<mx::BuiltinType> return_builtin = mx::BuiltinType::from(cast_type);
  if (!call_builtin || !return_builtin) {
    return;
  }

  mx::BuiltinTypeKind source_type_kind = call_builtin->builtin_kind();
  mx::BuiltinTypeKind dest_type_kind = return_builtin->builtin_kind();

  if (auto cast_behavior = ProfileCastBehavior(source_type_kind,
                                               dest_type_kind)) {
    PrettifyCallResults(call_expr, cast_expr, *cast_behavior,
                        source_type_kind, dest_type_kind);
  }
}

static void FindSketchyReturnValueCasts(const mx::CallExpr &call) {
  if (auto cast_expr = mx::CastExpr::from(call.parent_statement())) {
    if (IsInterestingCast(cast_expr)) {
      CheckCallRetForImplicitCast(call, *cast_expr);
    }
  }
}

int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE]\n"
    << " [--show_implicit] [--show_explicit]\n"
    << " [--show_sign_changing] [--show_sign_down_cast] [--show_sign_changing_down_cast]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (!FLAGS_show_implicit && !FLAGS_show_explicit) {
    std::cerr << "One or both of --show_implicit or --show_explicit should be used\n";
    return EXIT_FAILURE;
  }

  for (mx::CallExpr call : mx::CallExpr::in(InitExample(true))) {
    FindSketchyArgumentCasts(call);
    FindSketchyReturnValueCasts(call);
  }

  return EXIT_SUCCESS;
}
