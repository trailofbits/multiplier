// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <sstream>

#include "Index.h"

DEFINE_uint64(fragment_id, 0, "ID of the fragment to print");

static std::string TokData(mx::Token tok) {
  std::stringstream ss;
  for (auto ch : tok.data()) {
    switch (ch) {
      case '<': ss << "&lt;"; break;
      case '>': ss << "&gt;"; break;
      case '"': ss << "&quot;"; break;
      case '\'': ss << "&apos;"; break;
      case '\n': ss << " "; break;
      case '&': ss << "&amp;"; break;
      default: ss << ch; break;
    }
  }
  return ss.str();
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT] --fragment_id ID\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample();
  
  auto fragment = index.fragment({FLAGS_fragment_id});
  if (!fragment) {
    std::cerr << "Invalid fragment id " << FLAGS_fragment_id << std::endl;
    return EXIT_FAILURE;
  }

  auto &os = std::cout;
  os
      << "digraph {\n"
      << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";

  os
      << "tokens"
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\"><TR>";


  std::unordered_map<unsigned, mx::TokenContext> contexts;

  auto i = 0u;
  for (mx::Token tok : mx::Token::in(*fragment)) {
    for (auto context = mx::TokenContext::of(tok); context;
         context = context->parent()) {
      contexts.emplace(context->id(), context.value());
    }

    os
        << "<TD port=\"t" << (i++) << "\">" << TokData(tok) << "</TD>";
  }

  os << "</TR></TABLE>>];\n";

  for (const auto &entry : contexts) {
    const mx::TokenContext &context = entry.second;
    auto bgcolor = "";
    auto kind_name = "";

    if (auto stmt = context.as_statement()) {
      bgcolor = " bgcolor=\"aquamarine\"";
      kind_name = mx::EnumeratorName(stmt->kind());

    } else if (auto decl = context.as_declaration()) {
      bgcolor = " bgcolor=\"antiquewhite\"";
      kind_name = mx::EnumeratorName(decl->kind());

    } else if (auto type = context.as_type()) {
      bgcolor = " bgcolor=\"cadetblue1\"";
      kind_name = mx::EnumeratorName(type->kind());

    } else if (context.is_alias()) {
      bgcolor = " bgcolor=\"deepskyblue3\"";

    } else {
      assert(false);
    }

    os
        << "c" << context.id()
        << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" "
        << "border=\"1\"><TR><TD" << bgcolor << ">";

    os << kind_name;

    os
        << "</TD></TR></TABLE>>];\n";

    if (auto parent_context = context.parent()) {
      os
          << "c" << context.id() << " -> c" << parent_context->id() << ";\n";
    }

    if (auto alias_context = context.aliasee()) {
      os
          << "c" << context.id() << " -> c" << alias_context->id()
          << " [style=dashed];\n";
    }
  }

  i = 0u;
  for (mx::Token tok : mx::Token::in(*fragment)) {
    if (auto context = mx::TokenContext::of(tok)) {
      os
          << "tokens:t" << (i++) << " -> c" << context->id() << ";\n";
    }
  }

  os << "}\n";

  for (mx::Token token : mx::Token::in(*fragment)) {

  }

  return EXIT_SUCCESS;
}
