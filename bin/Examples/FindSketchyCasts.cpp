// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <multiplier/AST.h>
#include <sstream>

#include <multiplier/Analysis/TypecastAnalysis.h>

#include "Index.h"
#include "multiplier/Entities/CastExpr.h"
#include "multiplier/Types.h"

DEFINE_bool(show_implicit, false, "Show implicit casts?");
DEFINE_bool(show_explicit, false, "Show explicit casts?");
DEFINE_bool(show_sign_changing, false, "Show sign-changing casts?");
DEFINE_bool(show_sign_down_cast, false, "Show sign down-casts? E.g. int to short.");
DEFINE_bool(show_sign_changing_down_cast, false, "Show sign-changing downcasts.");

enum class CastBehavior {
  Sketchy,
  SignDowncast,
  SignChange,
  SignChangingDowncast,
  NoBehavior,
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
    const mx::CallExpr &call_expr,
    mx::CastExpr &cast_expr, mx::CastState &state,
    CastBehavior kind,
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
      << "\nEntity ID: " << cast_expr.id()
      << "\nKind: " << kOuts.at(kind) << " ("
      << mx::EnumeratorName(state.type_before_conversion().kind())
      << " to "
      << mx::EnumeratorName(state.type_after_conversion().kind())
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
  if (line_stmt.id() != cast_expr.id()) {
    auto unhighlight_toks = FileTokenIdsFor(cast_expr.tokens());
    std::erase_if(highlight_toks, [&unhighlight_toks] (mx::RawEntityId id) {
      return unhighlight_toks.count(id);
    });
  }

  RenderFragment(std::cout, fragment, highlight_toks, "\t", true);
  std::cout << "\n\n";
}

/*
// Filter by implicit/explicit, and only give us back integral casts.

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
*/

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

  mx::Index index = InitExample(true);
  mx::TypecastAnalysis analyzer;

  // Target analysis over all CallExprs, which may have argument CastExprs
  std::unordered_set<mx::PackedStmtId> seen;
  for (const mx::CallExpr call : mx::CallExpr::in(index)) {
    if (seen.contains(call.id())) {
      continue;
    }
    seen.insert(call.id());

    // for each CallExpr reference point, traverse its tree for any casting behavior
    mx::CastStateMap instances = analyzer.cast_instances(call);
    if (instances.empty()) {
      continue;
    }

    // Check arguments for any casting before the call
    for (auto iter : instances) {
      auto [cast_id, cast_state] = iter;

      // sanity-check to make sure we're doing casts in calls
      auto is_in_call = cast_state.is_part_of_call_arg();
      if (!is_in_call) {
        continue;
      }

      // might have some other casting semantic we don't care about
      auto is_implicit = cast_state.is_implicit_cast();
      if (!is_implicit) {
        continue;
      }

      // Filter by implicit/explicit, and only give us back integral casts.
      if (!FLAGS_show_implicit && *is_implicit) {
        continue;
      }
      if (!FLAGS_show_explicit && !*is_implicit) {
        continue;
      }

      // check if sign change exists
      auto cast_sign_change = cast_state.sign_change();

      // Checks whether any arguments passed the provided call expression are used
      // as an implicit cast with a signed change, ie. from an unsigned long to a signed int
      // For example, consider:
      //
      // foo(int a);
      // bar(size_t b) { foo(b); }
      //
      // This was motivated by the PHP vulnerability described here, and is an
      // attempt to identify more instances of the vulnerable code pattern:
      // https://pwning.systems/posts/php_filter_var_shenanigans/
      CastBehavior behavior = [&](auto cast_state) {
        if (cast_state.width_cast() == mx::CastTypeWidth::DOWNCAST &&
            cast_sign_change == mx::CastSignChange::C_UNSIGNED_TO_SIGNED) {
          return CastBehavior::Sketchy;
        }

        // ie. long long -> int
        if (FLAGS_show_sign_down_cast) {
          if (cast_state.width_cast() == mx::CastTypeWidth::DOWNCAST &&
              cast_sign_change == mx::CastSignChange::NO_SIGN_CHANGE) {
            return CastBehavior::SignDowncast;
          }
        }

        // ie. unsigned long long -> long long
        if (FLAGS_show_sign_changing) {
          if (cast_state.width_cast() == mx::CastTypeWidth::NO_WIDTH_CHANGE &&
              cast_sign_change != mx::CastSignChange::NO_SIGN_CHANGE) {
            return CastBehavior::SignChange;
          }
        }
        return CastBehavior::NoBehavior;
      }(cast_state);

      if (behavior != CastBehavior::NoBehavior) {
        if (auto cast_expr = mx::CastExpr::by_id(index, cast_id)) {
          PrettifyCallResults(call, *cast_expr, cast_state, behavior);
        }
      }
    }

    // TODO: check if return also has a sketchy downcast
  }

  return EXIT_SUCCESS;
}
