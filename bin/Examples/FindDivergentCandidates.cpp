// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <sstream>

#include "Index.h"

DEFINE_uint64(file_id, 0, "ID of the file from which to check for potential candidates of divergent representations");
DEFINE_uint64(fragment_id, 0, "ID of the fragment from which to check for potential candidates of divergent representations");
DEFINE_bool(show_locations, false, "Show the locations of candidates?");

static bool IsVarDeclInLoop(const mx::VarDecl var) {
  auto parent_stmt = var.parent_statement();
  while (parent_stmt) {
    if (parent_stmt->kind() == mx::StmtKind::FOR_STMT || 
        parent_stmt->kind() == mx::StmtKind::WHILE_STMT ||
        parent_stmt->kind() == mx::StmtKind::DO_STMT) {
      return true;
    }
    parent_stmt = parent_stmt->parent_statement();
  }
  return false;
}

static void FindDivergentCandidates(const mx::Fragment fragment) {
  /* 
    Get all statements in a fragment, iterate through them.
    For reach statement,
    - Determine if statement is a loop. If not, continue.
    - Determine whether a variable is incremented in fragment. If not, continue.
    - For each incremented variable, 
      + Determine if it is defined/declared outside of the loop statement. If 
        not, continue.
      + Determine if it is used to index into an array.
      + Determine if it is used elsewhere outside of the loop.
  */
  for (mx::Stmt stmt : mx::Stmt::in(fragment)) {
    /* Determine whether a statement is a loop. */
    mx::StmtKind kind = stmt.kind();
    if (kind != mx::StmtKind::FOR_STMT &&
        kind != mx::StmtKind::WHILE_STMT &&
        kind != mx::StmtKind::DO_STMT) {
      continue;
    }

    /* Determine whether a variable is incremented in the loop. */
    for (mx::Stmt child : stmt.children()) {
      if (child.kind() != mx::StmtKind::UNARY_OPERATOR) { continue; }
      if (auto unary_op = mx::UnaryOperator::from(child)) {
        mx::UnaryOperatorKind operator_kind = unary_op->opcode();
        switch (operator_kind) {
          case mx::UnaryOperatorKind::POST_DEC:
          case mx::UnaryOperatorKind::PRE_DEC:
          case mx::UnaryOperatorKind::POST_INCREMENT:
          case mx::UnaryOperatorKind::PRE_INCREMENT:
            break;
          default:
            continue;
            break;
        }
        /* Determine whether the variable is declared outside the loop. */
        mx::Expr sub_expr = unary_op->sub_expression();
        if (auto decl_ref = mx::DeclRefExpr::from(sub_expr)) {
          mx::ValueDecl decl = decl_ref->declaration();
          if (stmt.contains(decl.token())) {
            continue;
          }
          
          /* 
            Determine whether the variable is used to index into an array, and
            whether it is used elsewhere outside the loop.
           */
          bool mem_access = false;
          bool used_out_of_loop = false;
          mx::ArraySubscriptExpr *example_mem_access;
          mx::Stmt *outside_loop_use;

          for (const mx::Reference ref : decl.references()) {
            mx::Stmt ref_stmt = ref.statement();
            if (auto parent = ref_stmt.parent_statement()) { 
              if (parent->kind() == mx::StmtKind::IMPLICIT_CAST_EXPR) {
                // Might be None 
                // TODO: Check
                parent = parent->parent_statement();
              }
              if (auto array_access = mx::ArraySubscriptExpr::from(parent)) {
                // TODO: Did I just throw in a use-after-free for good luck?
                example_mem_access = &(*array_access);
                mem_access = true;
                continue;
              }
              if (!stmt.contains(*parent)) {
                // TODO: Did I just throw in a use-after-free for good luck?
                outside_loop_use = &(*parent);
                used_out_of_loop = true;
              }
            }
          }
          if (mem_access && used_out_of_loop) {
            // Found a candidate - let's print stuff about it.
            std::cout << "-------------------" << std::endl;
            std::cout << "candidate decl: " << decl.tokens().data() << std::endl;
            std::cout 
                  << "increment/decrement inside loop: "
                  << unary_op->tokens().data() 
                  << std::endl;
            std::cout
                  << "memory access: "
                  << example_mem_access->tokens().data()
                  << std::endl;
            std::cout
                  << "example use outside loop: "
                  << outside_loop_use->tokens().data()
                  << std::endl;
          }
        }
      }

    }
  } 
  return;
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT] [--file_id ID]\n";
    
  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample(FLAGS_show_locations);

  if (FLAGS_fragment_id) {
    auto fragment = index.fragment(FLAGS_fragment_id);
    if (!fragment) {
      std::cerr << "Invalid fragment id " << FLAGS_fragment_id << std::endl;
      return EXIT_FAILURE;
    }
    FindDivergentCandidates(std::move(*fragment));
  } else if (FLAGS_file_id) {
    auto file = index.file(FLAGS_file_id);
    if (!file) {
      std::cerr << "Invalid file id " << FLAGS_file_id << std::endl;
      return EXIT_FAILURE;
    }
    for (mx::Fragment fragment : mx::Fragment::in(*file)) {
      FindDivergentCandidates(std::move(fragment));
    }
  } else {
    for (mx::File file : mx::File::in(index)) {
      for (mx::Fragment fragment : mx::Fragment::in(file)) {
        FindDivergentCandidates(std::move(fragment));
      }
    }
  }

  return EXIT_SUCCESS;
}