// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

//
// Example utility that uses syntex predicates to locate float to integer casts
//

#include <cassert>
#include <iostream>
#include <sstream>

#include <gflags/gflags.h>
#include <glog/logging.h>

#include <multiplier/Entities/BuiltinType.h>
#include <multiplier/Entities/DeclRefExpr.h>
#include <multiplier/Entities/IntegerLiteral.h>
#include <multiplier/Entities/ValueDecl.h>
#include <multiplier/Entities/VarDecl.h>
#include <multiplier/Index.h>
#include <multiplier/Syntex.h>

#define ANSI_RED    "\x1b[1;31m"
#define ANSI_RESET  "\x1b[1;0m"

DECLARE_bool(help);
DEFINE_string(db, "", "Path to Multiplier database.");
DEFINE_bool(long_is_32_bits, false, "Is 'long' a 32-bit type?");

static std::optional<unsigned> IntegralTypeWidth(const mx::Type &type) {
  auto builtin_type = mx::BuiltinType::from(type);
  if (!builtin_type) {
    return std::nullopt;
  }

  switch (builtin_type->builtin_kind()) {
    case mx::BuiltinTypeKind::S_CHAR:
    case mx::BuiltinTypeKind::CHARACTER_U:
    case mx::BuiltinTypeKind::CHARACTER_S:
    case mx::BuiltinTypeKind::BOOLEAN:
    case mx::BuiltinTypeKind::CHAR8:
    case mx::BuiltinTypeKind::U_CHAR:
      return 8u;
    case mx::BuiltinTypeKind::W_CHAR_S:
    case mx::BuiltinTypeKind::W_CHAR_U:
    case mx::BuiltinTypeKind::CHAR16:
    case mx::BuiltinTypeKind::SHORT:
    case mx::BuiltinTypeKind::U_SHORT:
      return 16u;
    case mx::BuiltinTypeKind::CHAR32:
    case mx::BuiltinTypeKind::INT:
    case mx::BuiltinTypeKind::U_INT:
      return 32u;
    case mx::BuiltinTypeKind::U_LONG:
    case mx::BuiltinTypeKind::LONG:
      return FLAGS_long_is_32_bits ? 32u : 64u;
    case mx::BuiltinTypeKind::U_LONG_LONG:
    case mx::BuiltinTypeKind::LONG_LONG:
      return 64u;
    case mx::BuiltinTypeKind::U_INT128:
    case mx::BuiltinTypeKind::INT128:
      return 128u;
    default:
      return std::nullopt;
  }
}

static std::optional<unsigned> IntegralTypeWidth(const mx::ValueDecl &decl) {
  return IntegralTypeWidth(decl.type());
}

static void HighlightMatch(std::ostream &os, mx::syntex::Match m) {
  auto ref = mx::DeclRefExpr::from(std::get<mx::Stmt>(m.MetavarMatch(0).Entity()));
  if (!ref) {
    return;
  }

  auto var = mx::VarDecl::from(ref->referenced_declaration());
  if (!var) {
    return;
  }

  auto type_size = IntegralTypeWidth(var.value());
  if (!type_size) {
    return;
  }

  auto lit = mx::IntegerLiteral::from(
      std::get<mx::Stmt>(m.MetavarMatch(1).Entity()));
  if (!lit) {
    return;
  }

  auto lit_data = lit->token().data();

  // Strip off the suffixes of things like `0ull`.
  while (lit_data.ends_with('u') || lit_data.ends_with('U') ||
         lit_data.ends_with('l') || lit_data.ends_with('L') ||
         lit_data.ends_with(' ')) {
    lit_data = lit_data.substr(0, lit_data.size() - 1u);
  }

  int64_t lit_val{-1};

  std::stringstream ss;
  ss << lit_data;
  ss >> lit_val;

  if (0 >= lit_val) {
    return;
  }

  if (type_size.value() > static_cast<uint64_t>(lit_val)) {
    return;
  }

  auto builtin_type = mx::BuiltinType::from(var->type());
  os << "File ID: " << mx::File::containing(m.Fragment()).id() << '\n'
     << "Fragment ID: " << m.Fragment().id().Pack() << '\n'
     << "Token ID: " << m.FirstTokenId() << '\n'
     << "Literal value: " << lit_val << '\n'
     << "Type size: " << type_size.value() << '\n'
     << "Type kind: " << mx::EnumeratorName(builtin_type->builtin_kind())
     << "\nExpression:";

  for (mx::Token tok : m.TokenRange()) {
    os << ' ' << tok.data();
  }

  os << "\n\n";
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  if (FLAGS_db.empty()) {
    std::cerr << "Need to specify a database using --db" << std::endl;
    return EXIT_FAILURE;
  }

  // Setup index and grammar

  mx::Index index = mx::EntityProvider::in_memory_cache(
                      mx::EntityProvider::from_database(FLAGS_db));
  mx::syntex::Grammar grammar(index, FLAGS_db);

  // Setup query

  mx::syntex::ParsedQuery parsed_query(grammar, "$var:DECL_REF_EXPR << $num:INTEGER_LITERAL");
  if (!parsed_query.IsValid()) {
    return EXIT_FAILURE;
  }

  // Match fragments

  parsed_query.ForEachMatch([] (mx::syntex::Match match) {
    HighlightMatch(std::cout, std::move(match));
    return true;
  });

  return EXIT_SUCCESS;
}
