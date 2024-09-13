// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdlib>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <multiplier/AST/CallExpr.h>
#include <multiplier/AST/DeclRefExpr.h>
#include <multiplier/AST/FunctionDecl.h>
#include <multiplier/AST/FieldDecl.h>
#include <multiplier/AST/MemberExpr.h>
#include <multiplier/AST/PointerType.h>
#include <multiplier/AST/RecordDecl.h>
#include <multiplier/AST/RecordType.h>
#include <multiplier/AST/UnaryExprOrTypeTraitExpr.h>
#include <multiplier/AST/UnaryOperator.h>
#include <sstream>

#include "Index.h"

DECLARE_bool(help);
DECLARE_string(db);

static void RenderCopyResults(
    const mx::CallExpr &call, const mx::RecordDecl &record,
    const mx::FieldDecl &field, uint64_t record_size) {

  mx::Fragment record_fragment = mx::Fragment::containing(field);
  mx::Fragment call_fragment = mx::Fragment::containing(call);

  std::optional<mx::File> record_file = mx::File::containing(record_fragment);
  std::optional<mx::File> call_file = mx::File::containing(call_fragment);

  std::cout
      << "Record location: " << file_paths[record_file->id()].generic_string() << '\n'
      << "Record file ID: " << record_file->id() << '\n'
      << "Record ID: " << record.id() << '\n'
      << "Record size: " << record_size << '\n'
      << "Field ID: " << field.id() << '\n'
      << "Copy call ID: " << call.id() << '\n'
      << "Copy location: " << file_paths[call_file->id()].generic_string() << '\n'
      << "Copy file ID: " << call_file->id() << '\n'
      << "Record:\n";

  RenderFragment(std::cout, record_fragment, FileTokenIdsFor(field.tokens()),
                 "\t", true);
  std::cout
      << "\n\n"
      << "Call:";

  RenderFragment(std::cout, call_fragment, FileTokenIdsFor(call.tokens()),
                 "\t", true);
  std::cout << "\n\n";
}

static std::optional<mx::ValueDecl> DeclarationFrom(const mx::Expr &expr) {
  if (auto decl_ref = mx::DeclRefExpr::from(expr)) {
    return decl_ref->declaration();
  }

  if (auto member_ref = mx::MemberExpr::from(expr)) {
    return member_ref->member_declaration();
  }

  return std::nullopt;
}

static std::optional<mx::RecordType> CopiedRecord(
    const mx::UnaryExprOrTypeTraitExpr &utt_expr) {

  // `sizeof(struct foo)`.
  if (auto sized_type = utt_expr.argument_type()) {
    return mx::RecordType::from(
        sized_type->canonical_type().unqualified_type());
  }

  auto sized_expr = utt_expr.argument_expression();
  if (!sized_expr) {
    return std::nullopt;
  }

  // `sizeof(foo)` where we have `struct bar foo;`.
  auto base_expr = sized_expr->ignore_parenthesis_casts();
  auto decl = DeclarationFrom(base_expr);
  if (decl) {
    return mx::RecordType::from(decl->type().unqualified_type());
  }

  // `sizeof(*foo)` where we have `struct bar *foo;`.
  auto unary_op = mx::UnaryOperator::from(base_expr);
  if (!unary_op || unary_op->opcode() != mx::UnaryOperatorKind::DEREF) {
    return std::nullopt;
  }

  base_expr = unary_op->sub_expression().ignore_parenthesis_casts();
  decl = DeclarationFrom(base_expr);
  if (!decl) {
    return std::nullopt;    
  }

  auto ptr_type = mx::PointerType::from(decl->type().unqualified_type());
  if (!ptr_type) {
    return std::nullopt;    
  }

  return mx::RecordType::from(
      ptr_type->pointee_type().unqualified_type().canonical_type());
}

static void WithCopyToUser(mx::FunctionDecl copy_from_user) {
  for (mx::Stmt stmt : copy_from_user.callers()) {
    auto call_expr = mx::CallExpr::from(stmt);
    if (!call_expr) {
      continue;
    }

    if (call_expr->num_arguments() != 3u) {
      continue;
    }

    auto size_arg = call_expr->nth_argument(2u);
    if (!size_arg) {
      continue;
    }

    auto utt_size_arg = mx::UnaryExprOrTypeTraitExpr::from(
        size_arg->ignore_casts());
    if (!utt_size_arg) {
      continue;
    }

    auto record_type = CopiedRecord(utt_size_arg.value());
    if (!record_type) {
      continue;
    }

    auto record_decl = mx::RecordDecl::from(
        record_type->declaration().definition());
    if (!record_decl) {
      continue;
    }

    auto record_size = record_decl->size();
    if (!record_size) {
      continue;
    }

    for (mx::FieldDecl field_decl : record_decl->fields()) {
      auto field_offset = field_decl.offset_in_bits();
      if (!field_offset || field_offset.value() != record_size.value() * 8u) {
        continue;
      }

      RenderCopyResults(call_expr.value(), record_decl.value(), field_decl,
                        record_size.value());
    }
  }
}

int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db file]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index index = InitExample(true);

  for (auto ent : index.query_entities("copy_from_user")) {
    auto nd = std::get_if<mx::NamedDecl>(&ent);
    if (!nd) {
      continue;
    }

    auto func = mx::FunctionDecl::from(*nd);
    if (!func || func->name() != "copy_from_user" ||
        !func->is_definition() || func->num_parameters() != 3u) {
      continue;
    }

    WithCopyToUser(std::move(func.value()));
    return EXIT_SUCCESS;
  }

  std::cerr << "Unable to locate `copy_from_user`.";
  return EXIT_FAILURE;
}
