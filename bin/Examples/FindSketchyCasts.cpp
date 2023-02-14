// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <sstream>

#include "Index.h"
#include <multiplier/AST.h>

DEFINE_uint64(fragment_id, 0, "ID of the fragment from which to check for call expressions with implicit integer casts");
DEFINE_uint64(file_id, 0, "ID of the file from which to check for call expressions with implicit integer casts");
DEFINE_uint64(entity_id, 0, "ID of the entity from which to check for uses in call expressions with implicit integer casts");
DEFINE_bool(show_locations, false, "Show the locations of users?");
DEFINE_bool(highlight_use, false, "Highlight the use within its fragment?");
DEFINE_bool(show_implicit, false, "Show implicit casts?");
DEFINE_bool(show_explicit, false, "Show explicit casts?");
DEFINE_bool(show_sign_changing, false, "Show sign-changing casts?");
DEFINE_bool(show_sign_down_cast, false, "Show sign down-casts? E.g. int to short.");

static constexpr mx::BuiltinTypeKind kSketchyKinds[][2] = {
    {mx::BuiltinTypeKind::U_LONG_LONG, mx::BuiltinTypeKind::INT},
    {mx::BuiltinTypeKind::U_LONG_LONG, mx::BuiltinTypeKind::SHORT},
    {mx::BuiltinTypeKind::U_LONG_LONG, mx::BuiltinTypeKind::S_CHAR},

    {mx::BuiltinTypeKind::U_LONG, mx::BuiltinTypeKind::INT},
    {mx::BuiltinTypeKind::U_LONG, mx::BuiltinTypeKind::SHORT},
    {mx::BuiltinTypeKind::U_LONG, mx::BuiltinTypeKind::S_CHAR},

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

// Should we skip a result, e.g. froma `sizeof(blah)`.
static bool ShouldSkip(const mx::Expr expr) {
  if (auto lit = mx::IntegerLiteral::from(expr)) {
    return !lit->token().data().starts_with('-');

  // E.g. `sizeof`, `alignof`, etc.
  } else if (mx::UnaryExprOrTypeTraitExpr::from(expr)) {
    return true;

  } else {
    return false;
  }
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
static void CheckCallForImplicitCast(const mx::CallExpr call_expr) {
  auto arg_num = 0u;
  for (mx::Expr argument : call_expr.arguments()) {
    ++arg_num;

    if (std::optional<mx::CastExpr> cast_expr = mx::CastExpr::from(argument)) {
      if (cast_expr->cast_kind() != mx::CastKind::INTEGRAL_CAST) {
        continue;
      }

      if (auto implicit = mx::ImplicitCastExpr::from(argument)) {
        if (!FLAGS_show_implicit &&
            !(FLAGS_show_explicit && implicit->is_part_of_explicit_cast())) {
          continue;
        }
      } else if (mx::ExplicitCastExpr::from(argument)) {
        if (!FLAGS_show_explicit) {
          continue;
        }
      } else {
        continue;
      }

      mx::Type source_type =
          cast_expr->sub_expression().type()->canonical_type();
      std::optional<mx::Type> dest_type = cast_expr->type();

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

      const char *kind = "None";

      // Check to see if we found a sketchy downcast.
      for (auto [from_kind, to_kind] : kSketchyKinds) {
        if (source_type_kind == from_kind && dest_type_kind == to_kind) {
          kind = "Sketchy";
          goto found;
        }
      }

      if (FLAGS_show_sign_down_cast) {
        for (auto [from_kind, to_kind] : kSignDownCastKinds) {
          if (source_type_kind == from_kind && dest_type_kind == to_kind) {
            kind = "Sign down-cast";
            goto found;
          }
        }
      }

      if (FLAGS_show_sign_changing) {
        for (auto [from_kind, to_kind] : kSignChangingKinds) {
          if (source_type_kind == from_kind && dest_type_kind == to_kind) {
            kind = "Sign change";
            goto found;
          }
        }
      }

      // Didn't find.
      continue;

    found:

      if (std::optional<mx::Expr> expr = mx::Expr::from(cast_expr)) {
        if (ShouldSkip(expr->ignore_casts())) {
          continue;
        }
      }

      mx::Fragment fragment = mx::Fragment::containing(call_expr);
      auto file = mx::File::containing(fragment);

      if (FLAGS_show_locations && file) {
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
          << "\nEntity ID: " << cast_expr->id()
          << "\nKind: " << kind << " ("
          << mx::EnumeratorName(source_type_kind)
          << " to "
          << mx::EnumeratorName(dest_type_kind)
          << ")\nCall:";

      RenderTokens(std::cout, call_expr.tokens(), cast_expr->tokens(), "\t", true);

      if (FLAGS_highlight_use) {
        std::cout << "\n\n";

        // Print out a declaration of the function.
        if (std::optional<mx::FunctionDecl> callee = call_expr.direct_callee()) {
          std::cout << "Declaration:";
          bool printed = false;
          for (mx::FunctionDecl redecl : callee->redeclarations()) {
            if (!redecl.is_definition()) {
              mx::TokenRange param_toks;
              if (auto param = redecl.nth_parameter(arg_num - 1u)) {
                param_toks = param->tokens();
              }
              RenderFragment(std::cout, mx::Fragment::containing(redecl),
                             param_toks, "\t", true);
              printed = true;
              break;
            }
          }

          if (!printed) {
            mx::TokenRange param_toks;
            if (auto param = callee->nth_parameter(arg_num - 1u)) {
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
          }
          std::cout << "\n\nUse:";
        }

        if (auto toks = call_expr.tokens()) {
          RenderFragment(std::cout, fragment, toks, "\t", true);
        }
        std::cout << std::endl;
      }
      std::cout << '\n';
    }
  }
}


static void CheckCallRetForImplicitCast(const mx::CallExpr call_expr, Expr return_value) {
  // TODO
}


static void FindSketchyUsesOfFragment(const mx::Fragment fragment) {
  for (mx::Stmt stmt : mx::Stmt::in(fragment)) {
    auto kind = stmt.kind();

    // type var = call();
    if (kind == mx::StmtKind::DECL_STMT) {
      auto decl_stmt = mx::DeclStmt::from(stmt);

      // in most cases there should only be one declaration
      for (mx::Decl decl : decl_stmt->declarations()) {

        std::optional<mx::VarDecl> var_decl = mx::VarDecl::from(decl);
        if (!var_decl) {
          continue;
        }

        std::optional<mx::Expr> initializer = var_decl->initializer();
        if (!initializer) {
          continue;
        }

        std::cout << initializer->tokens().data() << std::endl;
      }

    // var = call(); or var += call();
    } else if (kind == mx::StmtKind::BINARY_OPERATOR) {
      auto binop = mx::BinaryOperator::from(stmt);

      // ensure we're only analyzing assignments to calls
      std::optional<mx::CallExpr> call_expr = mx::CallExpr::from(binop->rhs());
      if (!call_expr) {
        continue;
      }

      // grab variable assignment
      mx::Expr lhs = binop->lhs();

      // check for implicit casts through parameters
      //CheckCallForImplicitCast(call_expr);

      // check for implicit casts in return value
      //CheckCallRetForImplicitCast(lhs, call_expr);
    }
  }
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] [--fragment_id ID | --file_id ID | --entity_id ID]\n"
    << " [--show_locations] [--highlight_use]\n"
    << " [--show_implicit] [--show_explicit]\n"
    << " [--show_sign_changing] [--show_sign_down_cast]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (!FLAGS_show_implicit && !FLAGS_show_explicit) {
    std::cerr << "One or both of --show_implicit or --show_explicit should be used\n";
    return EXIT_FAILURE;
  }

  mx::Index index = InitExample(FLAGS_show_locations);

  if (FLAGS_entity_id) {
    auto maybe_entity = index.entity(FLAGS_entity_id);
    if (!std::holds_alternative<mx::Decl>(maybe_entity)) {
      std::cerr << "Invalid decl id " << FLAGS_entity_id << std::endl;
      return EXIT_FAILURE;
    }

    mx::Decl decl = std::get<mx::Decl>(maybe_entity);
    for (mx::Reference ref : decl.references()) {
      for (mx::CallExpr call_expr :
               mx::CallExpr::containing(ref.as_statement())) {
        CheckCallForImplicitCast(call_expr);
      }
    }

  } else if (FLAGS_fragment_id) {
    auto fragment = index.fragment(FLAGS_fragment_id);
    if (!fragment) {
      std::cerr << "Invalid fragment id " << FLAGS_fragment_id << std::endl;
      return EXIT_FAILURE;
    }
    FindSketchyUsesOfFragment(std::move(*fragment));

  } else if (FLAGS_file_id) {
    auto file = index.file(FLAGS_file_id);
    if (!file) {
      std::cerr << "Invalid file id " << FLAGS_file_id << std::endl;
      return EXIT_FAILURE;
    }
    for (mx::Fragment fragment : file->fragments()) {
      FindSketchyUsesOfFragment(std::move(fragment));
    }

  } else {
    for (mx::File file : index.files()) {
      for (mx::Fragment fragment : file.fragments()) {
        FindSketchyUsesOfFragment(std::move(fragment));
      }
    }
  }

  return EXIT_SUCCESS;
}
