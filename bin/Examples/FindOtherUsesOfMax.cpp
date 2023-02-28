// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <multiplier/Analysis/Taint.h>
#include <multiplier/Entities/BinaryOperator.h>
#include <multiplier/Entities/CastExpr.h>
#include <multiplier/Entities/DeclKind.h>
#include <multiplier/Entities/DefineMacroDirective.h>
#include <multiplier/Entities/FunctionDecl.h>
#include <multiplier/Entities/MacroExpansion.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/ParenExpr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/StmtKind.h>
#include <multiplier/Entities/ValueDecl.h>
#include <multiplier/Reference.h>
#include <multiplier/Token.h>
#include <sstream>
#include <unordered_map>

#include "Index.h"

DEFINE_bool(exact, false, "Whether or not the name must match exactly.");
DEFINE_string(name, "MAX", "Name of the macro or part of the macro to find.");

static void PrintNext(mx::TaintTracker &tracker,
                      mx::TaintTrackingResult res,
                      int depth) {
  for (auto i = 0; i < depth; ++i) {
    std::cout << "  ";
  }
  if (std::holds_alternative<mx::TaintTrackingStep>(res)) {
    const mx::TaintTrackingStep &step = std::get<mx::TaintTrackingStep>(res);

    if (std::optional<mx::Stmt> stmt = step.as_statement()) {
      std::cout << mx::EnumeratorName(stmt->kind()) << ' ' << stmt->id()
                << ": ";
      for (mx::Token tok : stmt->tokens().file_tokens()) {
        for (char ch : tok.data()) {
          if (ch == '\n') {
            std::cout << ' ';
          } else {
            std::cout << ch;
          }
        }
      }

    } else if (std::optional<mx::Decl> decl = step.as_declaration()) {
      std::cout << mx::EnumeratorName(decl->kind()) << ' ' << decl->id();
      if (auto nd = mx::NamedDecl::from(decl)) {
        std::cout << ' ';
        for (mx::FunctionDecl func : mx::FunctionDecl::containing(decl)) {
          std::cout << func.name() << "::";
          break;
        }
        std::cout << nd->name();
      }
    }

    if (!step.is_new()) {
      std::cout << " <repeat>\n";
    } else {
      std::cout << '\n';

      for (mx::TaintTrackingResult next_res : tracker.add_source(step)) {
        PrintNext(tracker, std::move(next_res), depth + 1);
      }
    }

  } else if (std::holds_alternative<mx::TaintTrackingSink>(res)) {
    std::cout << std::get<mx::TaintTrackingSink>(res).message() << '\n';
  }
}

static std::optional<mx::Decl> FindReferencedDecl(mx::Stmt stmt) {
  switch (stmt.kind()) {
    case mx::StmtKind::UNARY_OPERATOR:  // E.g. `*foo = taint;`.
    case mx::StmtKind::ARRAY_SUBSCRIPT_EXPR:  // E.g. `foo[index] = taint;`.
      return std::nullopt;

    case mx::StmtKind::MEMBER_EXPR:  // E.g. `foo->bar = taint;`.
    case mx::StmtKind::DECL_REF_EXPR:  // E.g. `foo = taint;`.
      return stmt.referenced_declaration();

    case mx::StmtKind::BUILTIN_BIT_CAST_EXPR:
    case mx::StmtKind::C_STYLE_CAST_EXPR:
    case mx::StmtKind::CXX_FUNCTIONAL_CAST_EXPR:
    case mx::StmtKind::CXX_ADDRSPACE_CAST_EXPR:
    case mx::StmtKind::CXX_CONST_CAST_EXPR:
    case mx::StmtKind::CXX_DYNAMIC_CAST_EXPR:
    case mx::StmtKind::CXX_REINTERPRET_CAST_EXPR:
    case mx::StmtKind::CXX_STATIC_CAST_EXPR:
    case mx::StmtKind::OBJ_C_BRIDGED_CAST_EXPR:
    case mx::StmtKind::IMPLICIT_CAST_EXPR:
    default:
      if (auto ce = mx::CastExpr::from(stmt)) {
        return FindReferencedDecl(ce->sub_expression());
      } else if (auto pe = mx::ParenExpr::from(stmt)) {
        return FindReferencedDecl(pe->sub_expression());
      } else if (auto bo = mx::BinaryOperator::from(stmt)) {
        if (bo->opcode() == mx::BinaryOperatorKind::COMMA) {
          return FindReferencedDecl(bo->rhs());
        }
        if (auto lhs_decl = FindReferencedDecl(bo->lhs())) {
          return lhs_decl;
        }
        if (auto rhs_decl = FindReferencedDecl(bo->lhs())) {
          return rhs_decl;
        }
      }
      return std::nullopt;
  }
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] [--entity_id ID | --entity_name NAME]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample();
  mx::TaintTracker tracker(index);

  for (mx::NamedEntity named : index.query_entities(FLAGS_name)) {
    if (!std::holds_alternative<mx::DefineMacroDirective>(named)) {
      continue;
    }

    const auto &def = std::get<mx::DefineMacroDirective>(named);
    if (FLAGS_exact && FLAGS_name != def.name().data()) {
      continue;
    }

    for (mx::Reference ref : def.references()) {
      auto m = ref.as_macro();
      if (!m) {
        continue;
      }

      auto exp = mx::MacroExpansion::from(m);
      if (!exp) {
        continue;
      }

      for (mx::Token tok : exp->expansion_tokens()) {
        for (mx::BinaryOperator op : mx::BinaryOperator::containing(tok)) {
          std::cout << "=== " << op.tokens().file_tokens().data() << " ===\n";
          if (auto decl = FindReferencedDecl(op.lhs())) {
            std::cout << "=== " << mx::EnumeratorName(decl->kind()) << ' '
                      << decl->id() << " ===\n";
            for (mx::TaintTrackingResult res : tracker.add_source(decl.value())) {
              PrintNext(tracker, std::move(res), 0);
            }
            std::cout << "\n\n";
          }
          break;
        }
      }
    }
  }


  return EXIT_SUCCESS;
}
