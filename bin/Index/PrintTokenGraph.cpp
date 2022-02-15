// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "PrintTokenGraph.h"

#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>
#include <sstream>
#include <string>
#include <unordered_set>

namespace indexer {
namespace {

static std::string TokData(pasta::Token tok) {
  std::stringstream ss;
  for (auto ch : tok.Data()) {
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

}  // namespace

// Print a token context graph (provenance of tokens in the AST) for the
// inclusive range `[begin_index, end_index]` as a DOT digraph to `os`.
void PrintTokenGraph(const pasta::TokenRange &tokens, uint64_t begin_index,
                     uint64_t end_index, std::ostream &os) {
  if (begin_index > end_index || end_index > tokens.size()) {
    return;
  }

  os
      << "digraph {\n"
      << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n"
      << "tokens [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\"><TR>";

  std::unordered_set<pasta::TokenContext> contexts;

  for (auto i = begin_index; i <= end_index; ++i) {
    pasta::Token tok = tokens[i];
    for (auto context = tok.Context(); context; context = context->Parent()) {
      contexts.insert(context.value());
    }

    os
        << "<TD port=\"t" << tok.Index() << "\">" << TokData(tok) << "</TD>";
  }

  os << "</TR></TABLE>>];\n";

  for (const auto &context : contexts) {
    auto bgcolor = "";
    std::string_view kind_name = context.KindName();
    switch (context.Kind()) {
      case pasta::TokenContextKind::kInvalid:
        bgcolor = " bgcolor=\"red\"";
        kind_name = "?Invalid?";
        break;
      case pasta::TokenContextKind::kStmt:
        bgcolor = " bgcolor=\"aquamarine\"";
        kind_name = pasta::Stmt::From(context)->KindName();
        break;
      case pasta::TokenContextKind::kDecl:
        bgcolor = " bgcolor=\"antiquewhite\"";
        kind_name = pasta::Decl::From(context)->KindName();
        break;
      case pasta::TokenContextKind::kType:
        bgcolor = " bgcolor=\"cadetblue1\"";
        kind_name = pasta::Type::From(context)->KindName();
        break;
      case pasta::TokenContextKind::kTemplateParameterList:
        bgcolor = " bgcolor=\"chartreuse1\"";
        kind_name = "TemplateParameterList";
        break;
      case pasta::TokenContextKind::kTemplateArgument:
        bgcolor = " bgcolor=\"chocolate1\"";
        kind_name = "TemplateArgument";
        break;
      case pasta::TokenContextKind::kTypeConstraint:
        bgcolor = " bgcolor=\"deepskyblue2\"";
        kind_name = "TypeConstraint";
        break;
      case pasta::TokenContextKind::kAttr:
        bgcolor = " bgcolor=\"goldenrod1\"";
        kind_name = "Attr";
        break;
      case pasta::TokenContextKind::kString:
        bgcolor = " bgcolor=\"gainsboro\"";
        kind_name = reinterpret_cast<const char *>(context.Data());
        break;
      case pasta::TokenContextKind::kAlias:
        assert(false);
        bgcolor = " bgcolor=\"deepskyblue3\"";
        kind_name = "Alias";
        break;
      case pasta::TokenContextKind::kAST:
        bgcolor = " bgcolor=\"white\"";
        break;
    }

    os
        << "c" << context.Index()
        << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\"><TR><TD"
        << bgcolor << ">";

    os << kind_name;

    os
        << "</TD></TR></TABLE>>];\n";

    if (auto parent_context = context.Parent()) {
      os
          << "c"  << context.Index() << " -> c" << parent_context->Index()
          << ";\n";
    }


    if (auto alias_context = context.Aliasee()) {
      os
          << "c" << context.Index() << " -> c" << alias_context->Index()
          << " [style=dashed];\n";
    }
  }

  for (auto i = begin_index; i <= end_index; ++i) {
    pasta::Token tok = tokens[i];
    if (auto context = tok.Context()) {
      os
          << "tokens:t" << tok.Index() << " -> c" << context->Index() << ";\n";
    }
  }

  os << "}\n";
}

}  // namespace indexer
