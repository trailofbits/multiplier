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
#include <multiplier/AST.h>

DEFINE_uint64(fragment_id, 0, "ID of the fragment to print");

static std::string TokData(mx::Token tok) {
  std::stringstream ss;
  for (auto ch : tok.data()) {
    switch (ch) {
      case '<': ss << "&lt;"; break;
      case '>': ss << "&gt;"; break;
      case '"': ss << "&quot;"; break;
      case '\'': ss << "&apos;"; break;
      case '\r': ss << " "; break;
      case '\n': ss << " "; break;
      case '&': ss << "&amp;"; break;
      default: ss << ch; break;
    }
  }
  return ss.str();
}

static void PrintToken(std::ostream &os, const mx::TokenRange &file_toks,
                       const char *prefix, mx::RawEntityId parent_id,
                       const mx::Token &tok) {

  auto id = tok.id().Pack();
  auto dt = tok.derived_token();

//  // Every parsed token is derived from a macro token id, so we want to be
//  // able to show the connection from file tokens to parsed tokens, so we need
//  // to skip one step.
//  if (std::holds_alternative<mx::ParsedTokenId>(tok.id().Unpack())) {
//    assert(dt.has_value());
//    os << "ct0:t" << dt->id().Pack() << " -> " << prefix << parent_id
//       << ":t" << id << ";\n";
//    return;
//  }

  if (!dt) {
    return;
  }

  mx::EntityId dt_id = dt.id();
  if (file_toks.index_of(dt)) {
    os << "ft0:t" << dt_id.Pack() << " -> " << prefix << parent_id
       << ":t" << id << ";\n";

  } else if (auto m = mx::Macro::containing(dt)) {
    const char *pred_prefix = "m";
    switch (m->kind()) {
      case mx::MacroKind::SUBSTITUTION:
      case mx::MacroKind::EXPANSION:
      case mx::MacroKind::STRINGIFY:
      case mx::MacroKind::CONCATENATE:
      case mx::MacroKind::VA_OPT:
        pred_prefix = "b";
        break;
      default:
        break;
    }

    if (auto sub = mx::MacroSubstitution::from(m.value())) {
      for (const mx::MacroOrToken node : sub->replacement_children()) {
        if (std::holds_alternative<mx::Token>(node)) {
          if (std::get<mx::Token>(node) == dt) {
            pred_prefix = "a";
            break;
          }
        }
      }
    }

    os << pred_prefix << m->id().Pack() << ":t" << dt_id.Pack()
       << " -> " << prefix << parent_id << ":t" << id << ";\n";

  // No containing macro, but it's part of a fragment, which means it's a top-
  // level macro token.
  } else if (auto m = mx::Fragment::containing(dt)) {
    os << "ct0:t" << dt_id.Pack() << " -> " << prefix << parent_id
       << ":t" << id << ";\n";

  // It must be a file token related to a different fragment.
  } else {

  }
}

static void PrintMacro(std::ostream &os, const mx::TokenRange &file_toks,
                       const mx::Macro &macro);

static void PrintSub(std::ostream &os, const mx::TokenRange &file_toks,
                     const mx::MacroSubstitution &macro) {
  auto nodes = macro.children();
  auto after_nodes = macro.replacement_children();
  auto id = macro.id().Pack();
  os
      << "m" << id
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\" bgcolor=\"azure2\"><TR>"
      << "<TD>" << mx::EnumeratorName(macro.kind()) << "</TD></TR></TABLE>>];"
      << "m" << id << " -> b" << id << " [label=\"before\"];\n"
      << "m" << id << " -> a" << id << " [label=\"after\"];\n"
      << "b" << id
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\"><TR>";

  if (nodes.empty()) {
    os << "<TD></TD>";
  }
  for (const mx::MacroOrToken &node : nodes) {
    if (std::holds_alternative<mx::Token>(node)) {
      const mx::Token &mt = std::get<mx::Token>(node);
      os << "<TD port=\"t" << mt.id().Pack() << "\">" << TokData(mt) << "</TD>";
    } else if (std::holds_alternative<mx::Macro>(node)) {
      const mx::Macro &m = std::get<mx::Macro>(node);
      os << "<TD port=\"m" << m.id().Pack() << "\"> </TD>";
    }
  }

  os
      << "</TR></TABLE>>];\n"
      << "a" << id
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\"><TR>";

  if (after_nodes.empty()) {
    os << "<TD></TD>";
  }

  for (const mx::MacroOrToken &node : after_nodes) {
    if (std::holds_alternative<mx::Token>(node)) {
      const mx::Token &mt = std::get<mx::Token>(node);
      os << "<TD port=\"t" << mt.id().Pack() << "\">" << TokData(mt) << "</TD>";
    } else if (std::holds_alternative<mx::Macro>(node)) {
      const mx::Macro &m = std::get<mx::Macro>(node);
      os << "<TD port=\"m" << m.id().Pack() << "\"> </TD>";
    }
  }

  os << "</TR></TABLE>>];\n";

  for (const mx::MacroOrToken &node : nodes) {
    if (std::holds_alternative<mx::Token>(node)) {
      PrintToken(os, file_toks, "b", id, std::get<mx::Token>(node));
    } else if (std::holds_alternative<mx::Macro>(node)) {
      const mx::Macro &m = std::get<mx::Macro>(node);
      auto sub_id = m.id().Pack();
      os << "b" << id << ":m" << sub_id << " -> m" << sub_id << ";\n";
      PrintMacro(os, file_toks, m);
    }
  }

  for (const mx::MacroOrToken &node : after_nodes) {
    if (std::holds_alternative<mx::Token>(node)) {
      PrintToken(os, file_toks, "a", id, std::get<mx::Token>(node));
    } else if (std::holds_alternative<mx::Macro>(node)) {
      const mx::Macro &m = std::get<mx::Macro>(node);
      auto sub_id = m.id().Pack();
      os << "a" << id << ":m" << sub_id << " -> m" << sub_id << ";\n";
      PrintMacro(os, file_toks, m);
    }
  }
}

void PrintMacro(std::ostream &os, const mx::TokenRange &file_toks,
                const mx::Macro &macro) {

  if (auto sub = mx::MacroSubstitution::from(macro)) {
    PrintSub(os, file_toks, sub.value());
    return;
  }

  auto nodes = macro.children();
  auto id = macro.id().Pack();
  os
      << "m" << id
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\"><TR>"
      << "<TD bgcolor=\"darkseagreen2\">" << mx::EnumeratorName(macro.kind()) << "</TD>";

  for (const mx::MacroOrToken &node : nodes) {
    if (std::holds_alternative<mx::Token>(node)) {
      const mx::Token &mt = std::get<mx::Token>(node);
      os << "<TD port=\"t" << mt.id().Pack() << "\">" << TokData(mt) << "</TD>";
    } else if (std::holds_alternative<mx::Macro>(node)) {
      const mx::Macro &m = std::get<mx::Macro>(node);
      os << "<TD port=\"m" << m.id().Pack() << "\"> </TD>";
    }
  }
  os << "</TR></TABLE>>];\n";

  for (const mx::MacroOrToken &node : nodes) {
    if (std::holds_alternative<mx::Token>(node)) {
      PrintToken(os, file_toks, "m", id, std::get<mx::Token>(node));
    } else if (std::holds_alternative<mx::Macro>(node)) {
      const mx::Macro &m = std::get<mx::Macro>(node);
      auto sub_id = m.id().Pack();
      os << "m" << id << ":m" << sub_id << " -> m" << sub_id << ";\n";
      PrintMacro(os, file_toks, m);
    }
  }
}


extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] --fragment_id ID\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample();

  std::optional<mx::Fragment> fragment = index.fragment(FLAGS_fragment_id);
  if (!fragment) {
    mx::VariantEntity var_ent = index.entity(FLAGS_fragment_id);
    if (std::holds_alternative<mx::Fragment>(var_ent)) {
      fragment = std::get<mx::Fragment>(var_ent);
    }
  }

  if (!fragment) {
    std::cerr << "Invalid fragment id " << FLAGS_fragment_id << std::endl;
    return EXIT_FAILURE;
  }

  auto file = mx::File::containing(fragment.value());
  if (!file) {
    std::cerr
        << "Fragment " << FLAGS_fragment_id
        << " does not reside in a file." << std::endl;
    return EXIT_FAILURE;
  }


  mx::TokenRange file_toks = fragment->file_tokens();
  mx::TokenRange parsed_toks = fragment->parsed_tokens();
  std::vector<mx::MacroOrToken> code = fragment->preprocessed_code();

  auto &os = std::cout;
  os
      << "digraph {\n"
      << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n"
      << "ft0  [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\"><TR>"
      << "<TD bgcolor=\"aquamarine2\">FILE</TD>";


  for (mx::Token tok : file_toks) {
    os << "<TD port=\"t" << tok.id().Pack() << "\">" << TokData(tok) << "</TD>";
  }

  os
      << "</TR></TABLE>>];\n"
      << "ct0  [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\"><TR>"
      << "<TD bgcolor=\"beige\">PRE_PROCESSED</TD>";

  for (const mx::MacroOrToken &node : code) {
    if (std::holds_alternative<mx::Macro>(node)) {
      const mx::Macro &macro = std::get<mx::Macro>(node);
      os << "<TD port=\"m" << macro.id().Pack() << "\"> </TD>";

    } else if (std::holds_alternative<mx::Token>(node)) {
      const mx::Token &tok = std::get<mx::Token>(node);
      os << "<TD port=\"t" << tok.id().Pack() << "\">" << TokData(tok) << "</TD>";
    }
  }

  os << "</TR></TABLE>>];\n";

  for (const mx::MacroOrToken &node : code) {
    if (std::holds_alternative<mx::Token>(node)) {
      PrintToken(os, file_toks, "ct", 0, std::get<mx::Token>(node));
    } else if (std::holds_alternative<mx::Macro>(node)) {
      const mx::Macro &macro = std::get<mx::Macro>(node);
      auto id = macro.id().Pack();
      os << "ct0:m" << id << " -> m" << id << ";\n";
      PrintMacro(os, file_toks, macro);
    }
  }

  std::unordered_map<unsigned, mx::TokenContext> contexts;
  for (mx::Token tok : parsed_toks) {
    for (auto context = tok.context(); context; context = context->parent()) {
      contexts.emplace(context->index_in_fragment(), context.value());
    }

    PrintToken(os, file_toks, "pt", 0, tok);
  }

  os << "pt0 [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\"><TR>"
     << "<TD bgcolor=\"cornsilk2\">PARSED</TD>";
  for (mx::Token tok : parsed_toks) {
    os << "<TD port=\"t" << tok.id().Pack() << "\">" << TokData(tok) << "</TD>";
  }
  if (parsed_toks.empty()) {
    os << "<TD color=\"red\">no parsed tokens</TD>";
  }

  os
      << "</TR></TABLE>>];\n";

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

    } else if (auto attr = context.as_attribute()) {
      bgcolor = " bgcolor=\"cornflowerblue\"";
      kind_name = mx::EnumeratorName(attr->kind());

    } else if (context.is_alias()) {
      bgcolor = " bgcolor=\"deepskyblue3\"";

    } else {
      assert(false);
    }

    os
        << "c" << context.index_in_fragment()
        << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" "
        << "border=\"1\"><TR><TD" << bgcolor << ">";

    os << kind_name;

    os
        << "</TD></TR></TABLE>>];\n";

    if (auto parent_context = context.parent()) {
      os
          << "c" << context.index_in_fragment() << " -> c" << parent_context->index_in_fragment() << ";\n";
    }

    if (auto alias_context = context.aliasee()) {
      os
          << "c" << context.index_in_fragment() << " -> c" << alias_context->index_in_fragment()
          << " [style=dashed];\n";
    }
  }

  for (const mx::Token &tok : parsed_toks) {
    if (auto context = tok.context()) {
      os
          << "pt0:t" << tok.id().Pack()
          << " -> c" << context->index_in_fragment() << ";\n";
    }
  }

  os
      << "}\n";
  return EXIT_SUCCESS;
}
