// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "TokenTree.h"

#include <cassert>
#include <deque>
#include <glog/logging.h>
#include <map>
#include <multiplier/Frontend/MacroKind.h>
#include <multiplier/Types.h>
#include <mutex>
#include <optional>
#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Forward.h>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Token.h>
#include <pasta/Util/File.h>
#include <sstream>
#include <unordered_map>
#include <vector>

#include <iostream>

#include "PASTA.h"
#include "Util.h"

// #define D(...) __VA_ARGS__
#ifndef D
# define D(...)
#endif

#define TT_STR_(x) #x
#define TT_STR(x) TT_STR_(x)
#define TT_ASSERT(cond) \
  if (!(cond)) { \
    assert(false); \
    throw "Failed assertion " #cond " at " __FILE__ ":" TT_STR(__LINE__) ; \
  }

namespace indexer {
namespace {

static std::mutex gPrintDOTLock;

}  // namespace

struct TokenInfo {
  std::optional<pasta::Token> parsed_tok;
  std::optional<pasta::PrintedToken> printed_tok;
  std::optional<pasta::MacroToken> macro_tok;
  Substitution *parent{nullptr};
  TokenInfo *next{nullptr};
};

using SubstitutionNode = std::variant<TokenInfo *, Substitution *>;

class SubstitutionNodeList : public std::vector<SubstitutionNode> {
 public:
  // Did we have some kind of error when processing this list of nodes?
  mutable bool has_error{false};
};

// Represents a token substitution. This can be due to a macro expansion, or
// due to an X-macro file inclusion (i.e. where an include is nested inside
// of a declaration, and then the included file expands macros).
class Substitution {
 public:

  using Node = SubstitutionNode;
  using NodeList = SubstitutionNodeList;

  mx::MacroKind kind;

  // Associated macro node. If this is non-`nullopt` then the `EntityMapper`
  // uses `macro.RawMacro()` for the entity ID of the token tree.
  std::optional<pasta::Macro> macro;

  // Child nodes, prior to any kind of expansion or substitution.
  NodeList before;

  // Body of the macro.
  NodeList body;

  // Child node, after expansion or substitution. `HasExpansion()` tells us
  // if we should look in here.
  NodeList after;

  Substitution *parent{nullptr};

  TokenInfo *first_parsed_token{nullptr};
  TokenInfo *last_parsed_token{nullptr};

  bool HasExpansion(void) const noexcept;

  // Is this node dead?
  bool is_dead{false};

  explicit Substitution(mx::MacroKind kind_)
      : kind(kind_) {}

  void Print(std::ostream &os) const;
  void PrintDOT(std::ostream &os, bool first=true) const;
};

class TokenTreeImpl {
 public:
  bool has_error{false};

  // Backing storage for token info. Not necessarily all allocated tokens will
  // be used, but this is an upper bound on them. `deque` for pointer stability.
  std::deque<TokenInfo> tokens_alloc;

  // Backing storage for substitutions.
  std::deque<Substitution> substitutions_alloc;

  // Macro bodies.
  std::unordered_map<const void *, Substitution *> macro_body;

  // Macro tokens that are also final parsed tokens.
  std::unordered_map<const void *, TokenInfo *> final_toks;

  D( std::string indent; )

  // Collect a mapping of substitutions containing parsed tokens, along with
  // those parsed tokens in the order that we see them.
  void FindParsedTokens(
      Substitution *sub,
      std::unordered_map<Substitution *, std::vector<TokenInfo *>> &sub_tokens);

  // Possible rebuild the tree knowing that the `printed_range` tokens are the
  // ones that we want to present. This happens when `printed_range` is derived
  // from a template specialization.
  Substitution *RebuildTree(Substitution *original_root,
                            const pasta::TokenRange &range,
                            const pasta::PrintedTokenRange &printed_range,
                            const pasta::Decl &top_level_decl,
                            std::ostream &err);

  Substitution *RebuildSubTree(
      Substitution *sub, Substitution::NodeList *parent_node_list,
      const pasta::TokenRange &range,
      const pasta::PrintedTokenRange &printed_range,
      const pasta::Decl &top_level_decl,
      const std::unordered_map<Substitution *, std::vector<TokenInfo *>> &parsed_tokens,
      TokenInfo *&prev_parsed_token, unsigned &next_printed_index,
      std::ostream &err);

  // Figure out if `node->after` looks like a macro argument pre-expansion of
  // `node`, and if so, return `node->after.before.front()`, i.e. the pre-
  // expansion use.
  Substitution *PreExpansionOf(Substitution *node);

  // Build an initial token info list. This contains all of the tokens that were
  // parsed, plus the file tokens that were macro uses. This does not contain
  // file tokens that were elided due to things like conditional macros, e.g.
  // `#if 0`.
  Substitution *BuildFromTokenList(
      const std::optional<pasta::TokenRange> &range,
      const pasta::PrintedTokenRange &printed_range,
      const std::vector<pasta::Decl> &top_level_decls,
      std::ostream &err);

  Substitution *BuildFromParsedTokenList(
      const pasta::TokenRange &range,
      const pasta::PrintedTokenRange &printed_range,
      const std::vector<pasta::Decl> &top_level_decls,
      std::ostream &err);

  Substitution *BuildFromPrintedTokenList(
      const pasta::PrintedTokenRange &printed_range,
      std::ostream &err);

  bool BuildFromMacro(
      Substitution *sub, Substitution::NodeList &nodes, pasta::Macro macro,
      std::ostream &err);

  Substitution *GetMacroBody(pasta::DefineMacroDirective def,
                             std::ostream &err);

  Substitution *MergeArguments(Substitution *orig, Substitution *pre_arg,
                               std::ostream &err);

  bool MergeArgPreExpansion(Substitution *sub, Substitution *pre_exp,
                            std::ostream &err);

  bool BuildMacroSubstitution(
      Substitution *sub, Substitution::NodeList &nodes,
      const pasta::MacroToken &node, std::ostream &err);

  bool BuildMacroSubstitution(
      Substitution *sub, Substitution::NodeList &nodes,
      const pasta::MacroArgument &node, std::ostream &err);

  bool BuildMacroSubstitution(
      Substitution *sub, Substitution::NodeList &nodes,
      const pasta::MacroVAOpt &node, std::ostream &err);

  bool BuildMacroSubstitution(
      Substitution *sub, Substitution::NodeList &nodes,
      const pasta::MacroVAOptArgument &node, std::ostream &err);

  bool BuildMacroSubstitution(
      Substitution *sub, Substitution::NodeList &nodes,
      const pasta::MacroParameter &node, std::ostream &err);

  bool BuildMacroSubstitution(
      Substitution *sub, Substitution::NodeList &nodes,
      const pasta::MacroSubstitution &node, std::ostream &err);

  bool BuildMacroSubstitution(
      Substitution *sub, Substitution::NodeList &nodes,
      const pasta::MacroExpansion &node, std::ostream &err);

  bool BuildMacroSubstitution(
      Substitution *sub, Substitution::NodeList &nodes,
      const pasta::MacroDirective &node, std::ostream &err);

  Substitution *CreateSubstitution(mx::MacroKind kind);
};

namespace {

[[gnu::noinline]]
static std::ostream &Error(void) {
  return std::cerr;
}

static void Die(const TokenTreeImpl *impl) {
  std::unique_lock<std::mutex> locker(gPrintDOTLock);
  Error().flush();
  auto &sub = impl->substitutions_alloc.front();
  Error() << "--------------------------------------------------------\n";
  Error() << "--------------------------------------------------------\n";
  for (const TokenInfo &tok : impl->tokens_alloc) {
    if (tok.parsed_tok) {
      const pasta::Token &ast_tok = tok.parsed_tok.value();
      pasta::AST ast = pasta::AST::From(ast_tok);
      Error() << ast.MainFile().Path().generic_string() << "\n\n";
      break;
    }
  }
  sub.Print(std::cerr);
  Error() << "\n\n";
  sub.PrintDOT(std::cerr);
  Error() << "\n\n";
  Error().flush();
  TT_ASSERT(false);
}

static pasta::TokenKind TokKind(const pasta::MacroToken &mt) {
  return mt.TokenKind();
}

template <typename T>
static pasta::TokenKind TokKind(const T &mt) {
  return mt.Kind();
}

template <typename T>
static std::string TokData(const T &tok) {
  switch (TokKind(tok)) {
    case pasta::TokenKind::kComment:
      return "/* */";
    case pasta::TokenKind::kUnknown:
      return " ";
    case pasta::TokenKind::kCharacterConstant:
    case pasta::TokenKind::kUtf8CharacterConstant:
    case pasta::TokenKind::kUtf16CharacterConstant:
    case pasta::TokenKind::kUtf32CharacterConstant:
    case pasta::TokenKind::kWideCharacterConstant:
    case pasta::TokenKind::kStringLiteral:
    case pasta::TokenKind::kUtf8StringLiteral:
    case pasta::TokenKind::kUtf16StringLiteral:
    case pasta::TokenKind::kUtf32StringLiteral:
    case pasta::TokenKind::kWideStringLiteral:
      return "&lt;str&gt;";
    default:
      break;
  }

  std::stringstream ss;
  for (auto ch : tok.Data()) {
    switch (ch) {
      case '<': ss << "&lt;"; break;
      case '>': ss << "&gt;"; break;
      case '"': ss << "&quot;"; break;
      case '\'': ss << "&apos;"; break;
      case '\n': ss << " "; break;
      case '&': ss << "&amp;"; break;
      case '\\': ss << '|'; break;
      default: ss << ch; break;
    }
  }
  return ss.str();
}

static void FixupNodeParents(Substitution *sub) {
  assert(!sub->parent || sub != sub->parent);

  for (Substitution::Node &node : sub->before) {
    if (std::holds_alternative<Substitution *>(node)) {
      Substitution *child_sub = std::get<Substitution *>(node);
      assert(child_sub != sub);
      child_sub->parent = sub;
    } else if (std::holds_alternative<TokenInfo *>(node)) {
      std::get<TokenInfo *>(node)->parent = sub;
    }
  }

  for (Substitution::Node &node : sub->body) {
    if (std::holds_alternative<Substitution *>(node)) {
      Substitution *child_sub = std::get<Substitution *>(node);
      assert(child_sub != sub);
      child_sub->parent = sub;
    } else if (std::holds_alternative<TokenInfo *>(node)) {
      std::get<TokenInfo *>(node)->parent = sub;
    }
  }

  for (Substitution::Node &node : sub->after) {
    if (std::holds_alternative<Substitution *>(node)) {
      Substitution *child_sub = std::get<Substitution *>(node);
      assert(child_sub != sub);
      child_sub->parent = sub;
    } else if (std::holds_alternative<TokenInfo *>(node)) {
      std::get<TokenInfo *>(node)->parent = sub;
    }
  }
}

static TokenInfo *LeftCornerOfExp(const Substitution::NodeList &nodes);
static TokenInfo *LeftCornerOfExp(const Substitution::Node &node) {
  if (std::holds_alternative<TokenInfo *>(node)) {
    return std::get<TokenInfo *>(node);
  } else if (auto sub = std::get<Substitution *>(node)) {
    return LeftCornerOfExp(sub->after);
  }
  return nullptr;
}

TokenInfo *LeftCornerOfExp(const Substitution::NodeList &nodes) {
  for (const Substitution::Node &node : nodes) {
    if (auto tok = LeftCornerOfExp(node)) {
      return tok;
    }
  }
  return nullptr;
}

static TokenInfo *RightCornerOfExp(const Substitution::NodeList &nodes);
static TokenInfo *RightCornerOfExp(const Substitution::Node &node) {
  if (std::holds_alternative<TokenInfo *>(node)) {
    return std::get<TokenInfo *>(node);
  } else if (auto sub = std::get<Substitution *>(node)) {
    return RightCornerOfExp(sub->after);
  }
  return nullptr;
}

TokenInfo *RightCornerOfExp(const Substitution::NodeList &nodes) {
  auto it = nodes.rbegin();
  auto end = nodes.rend();
  for (; it != end; ++it) {
    const Substitution::Node &node = *it;
    if (auto rc = RightCornerOfExp(node)) {
      return rc;
    }
  }
  return nullptr;
}

static TokenInfo *LeftCornerOfUse(const Substitution::NodeList &nodes);
static TokenInfo *LeftCornerOfUse(const Substitution::Node &node) {
  if (std::holds_alternative<TokenInfo *>(node)) {
    return std::get<TokenInfo *>(node);
  } else if (auto sub = std::get<Substitution *>(node)) {
    return LeftCornerOfUse(sub->before);
  }
  return nullptr;
}

TokenInfo *LeftCornerOfUse(const Substitution::NodeList &nodes) {
  for (const Substitution::Node &node : nodes) {
    if (auto tok = LeftCornerOfUse(node)) {
      return tok;
    }
  }
  return nullptr;
}

static TokenInfo *RightCornerOfUse(const Substitution::NodeList &nodes);
static TokenInfo *RightCornerOfUse(const Substitution::Node &node) {
  if (std::holds_alternative<TokenInfo *>(node)) {
    return std::get<TokenInfo *>(node);
  } else if (auto sub = std::get<Substitution *>(node)) {
    return RightCornerOfUse(sub->before);
  }
  return nullptr;
}

TokenInfo *RightCornerOfUse(const Substitution::NodeList &nodes) {
  auto it = nodes.rbegin();
  auto end = nodes.rend();
  for (; it != end; ++it) {
    if (auto rc = RightCornerOfUse(*it)) {
      return rc;
    }
  }
  return nullptr;
}

static TokenInfo *RightCornerOfExpansionOrUse(
    const Substitution::NodeList &nodes);

static TokenInfo *RightCornerOfExpansionOrUse(const Substitution::Node &node) {
  if (std::holds_alternative<TokenInfo *>(node)) {
    return std::get<TokenInfo *>(node);
  } else if (auto sub = std::get<Substitution *>(node)) {
    if (sub->HasExpansion()) {
      return RightCornerOfExpansionOrUse(sub->after);
    } else {
      return RightCornerOfExpansionOrUse(sub->before);
    }
  }
  return nullptr;
}

static TokenInfo *RightCornerOfExpansionOrUse(const Substitution::NodeList &nodes) {
  auto it = nodes.rbegin();
  auto end = nodes.rend();
  for (; it != end; ++it) {
    if (auto rc = RightCornerOfExpansionOrUse(*it)) {
      return rc;
    }
  }
  return nullptr;
}


static Substitution *MacroArgument(const Substitution::Node &node) {
  if (std::holds_alternative<Substitution *>(node)) {
    auto sub = std::get<Substitution *>(node);
    if (sub->kind == mx::MacroKind::ARGUMENT) {
      return sub;
    }
  }
  return nullptr;
}

#ifndef NDEBUG
static Substitution *MacroDirective(const Substitution::Node &node) {
  if (std::holds_alternative<Substitution *>(node)) {
    auto sub = std::get<Substitution *>(node);
    switch (sub->kind) {
      case mx::MacroKind::OTHER_DIRECTIVE:
      case mx::MacroKind::IF_DIRECTIVE:
      case mx::MacroKind::IF_DEFINED_DIRECTIVE:
      case mx::MacroKind::IF_NOT_DEFINED_DIRECTIVE:
      case mx::MacroKind::ELSE_IF_DIRECTIVE:
      case mx::MacroKind::ELSE_IF_DEFINED_DIRECTIVE:
      case mx::MacroKind::ELSE_IF_NOT_DEFINED_DIRECTIVE:
      case mx::MacroKind::ELSE_DIRECTIVE:
      case mx::MacroKind::END_IF_DIRECTIVE:
      case mx::MacroKind::DEFINE_DIRECTIVE:
      case mx::MacroKind::UNDEFINE_DIRECTIVE:
      case mx::MacroKind::PRAGMA_DIRECTIVE:
      case mx::MacroKind::INCLUDE_DIRECTIVE:
      case mx::MacroKind::INCLUDE_NEXT_DIRECTIVE:
      case mx::MacroKind::INCLUDE_MACROS_DIRECTIVE:
      case mx::MacroKind::IMPORT_DIRECTIVE:
        return sub;
      default:
        break;
    }
  }
  return nullptr;
}
#endif

static pasta::Macro RootNodeFrom(const pasta::Macro &node) {
  if (auto parent = node.Parent()) {
    return RootNodeFrom(parent.value());
  } else {
    return node;
  }
}

}  // namespace

bool Substitution::HasExpansion(void) const noexcept {
  switch (kind) {
    case mx::MacroKind::OTHER_DIRECTIVE:
    case mx::MacroKind::IF_DIRECTIVE:
    case mx::MacroKind::IF_DEFINED_DIRECTIVE:
    case mx::MacroKind::IF_NOT_DEFINED_DIRECTIVE:
    case mx::MacroKind::ELSE_IF_DIRECTIVE:
    case mx::MacroKind::ELSE_IF_DEFINED_DIRECTIVE:
    case mx::MacroKind::ELSE_IF_NOT_DEFINED_DIRECTIVE:
    case mx::MacroKind::ELSE_DIRECTIVE:
    case mx::MacroKind::END_IF_DIRECTIVE:
    case mx::MacroKind::DEFINE_DIRECTIVE:
    case mx::MacroKind::UNDEFINE_DIRECTIVE:
    case mx::MacroKind::PRAGMA_DIRECTIVE:
      return true;  // Empty expansion.

    case mx::MacroKind::INCLUDE_DIRECTIVE:
    case mx::MacroKind::INCLUDE_NEXT_DIRECTIVE:
    case mx::MacroKind::INCLUDE_MACROS_DIRECTIVE:
    case mx::MacroKind::IMPORT_DIRECTIVE:
      return !after.empty();

    case mx::MacroKind::EXPANSION:
    case mx::MacroKind::SUBSTITUTION:
    case mx::MacroKind::STRINGIFY:
    case mx::MacroKind::CONCATENATE:
    case mx::MacroKind::PARAMETER_SUBSTITUTION:
      return true;

    // Macro argument, parameter, etc.
    case mx::MacroKind::ARGUMENT:
    case mx::MacroKind::VA_OPT:
    case mx::MacroKind::VA_OPT_ARGUMENT:
    case mx::MacroKind::PARAMETER:
      return false;
  }

  return false;
}

// Collect a mapping of substitutions containing parsed tokens, along with
// those parsed tokens in the order that we see them.
void TokenTreeImpl::FindParsedTokens(
    Substitution *sub,
    std::unordered_map<Substitution *, std::vector<TokenInfo *>> &sub_tokens) {

  auto &nodes = sub->after.empty() ? sub->before : sub->after;

  for (auto node : nodes) {
    if (std::holds_alternative<TokenInfo *>(node)) {
      auto info = std::get<TokenInfo *>(node);
      if (info->parsed_tok) {
        sub_tokens[sub].push_back(info);
      }
    } else if (std::holds_alternative<Substitution *>(node)) {
      FindParsedTokens(std::get<Substitution *>(node), sub_tokens);
    }
  }
}

// Figure out if `node->after` looks like a macro argument pre-expansion of
// `node`, and if so, return `node->after.before.front()`, i.e. the pre-
// expansion use.
Substitution *TokenTreeImpl::PreExpansionOf(Substitution *node) {
  if (node->kind != mx::MacroKind::EXPANSION) {
    return nullptr;
  }

  auto exp = pasta::MacroExpansion::From(node->macro.value());
  if (!exp->ArgumentPreExpansion()) {
    return nullptr;
  }

  if (node->after.empty() ||
      !std::holds_alternative<Substitution *>(node->after.front())) {
    return nullptr;
  }

  auto sub_exp = std::get<Substitution *>(node->after.front());
  if (sub_exp->kind != mx::MacroKind::EXPANSION) {
    return nullptr;
  }

  exp = pasta::MacroExpansion::From(sub_exp->macro.value());
  if (!exp->IsArgumentPreExpansion()) {
    return nullptr;
  }

  return sub_exp;
}

void Substitution::Print(std::ostream &os) const {
  auto tok_data = [] (TokenInfo *info) -> std::string_view {
    std::string_view a, b, c;
    if (info->parsed_tok) {
      a = info->parsed_tok->Data();
    }
    if (info->macro_tok) {
      b = info->macro_tok->Data();
    }
    if (info->printed_tok) {
      c = info->printed_tok->Data();
    }

    TT_ASSERT((a.empty() || b.empty()) || a == b);
    TT_ASSERT((a.empty() || c.empty()) || a == c);
    TT_ASSERT((b.empty() || c.empty()) || b == c);

    if (!a.empty()) {
      return a;
    } else if (!b.empty()) {
      return b;
    } else if (!c.empty()) {
      return c;
    } else {
      return "\x1b[1;31m???\033[0m";
    }
  };

  for (const Substitution::Node &ent : before) {
    if (std::holds_alternative<TokenInfo *>(ent)) {
      std::cerr << tok_data(std::get<TokenInfo *>(ent));
    } else {
      Substitution *child = std::get<Substitution *>(ent);
      assert(child->parent == this);
      child->Print(os);
    }
  }
}

void Substitution::PrintDOT(std::ostream &os, bool first) const {
  const auto self = reinterpret_cast<const void *>(this);

  if (first) {
    os << "digraph {\n"
       << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";
  }

  auto has_any = false;
  auto dump_tok = [&](TokenInfo *info) {
    os << "<TD><TABLE cellpadding=\"0\" cellspacing=\"0\" border=\"0\"";
    os << ">";
    if (info->parsed_tok) {
      os << "<TR><TD>PK=" << info->parsed_tok->KindName() << "</TD></TR>";
      os << "<TR><TD>PI=" << info->parsed_tok->Index() << "</TD></TR>";
    }
    if (info->printed_tok) {
      os << "<TR><TD>GI=" << info->printed_tok->Index() << "</TD></TR>";
    }

    if (info->parsed_tok) {
      os << "<TR><TD><B>" << TokData(info->parsed_tok.value())
         << "</B></TD></TR>";
    } else if (info->macro_tok) {
      os << "<TR><TD><B>" << TokData(info->macro_tok.value())
         << "</B></TD></TR>";
    } else if (info->printed_tok) {
      os << "<TR><TD><B>" << TokData(info->printed_tok.value())
         << "</B></TD></TR>";
    } else {
      os << "<TR><TD><FONT COLOR=\"red\">? ? ?</FONT></TD></TR>";
    }
    os << "</TABLE></TD>";
    has_any = true;
  };

  auto dump_toks = [&](const Substitution::NodeList &nodes) {
    for (const Substitution::Node &ent : nodes) {
      if (std::holds_alternative<TokenInfo *>(ent)) {
        dump_tok(std::get<TokenInfo *>(ent));
      } else if (std::holds_alternative<Substitution *>(ent)) {
        Substitution *s = std::get<Substitution *>(ent);
        auto other = reinterpret_cast<const void *>(s);
        os << "<TD port=\"s" << other << "\"> </TD>";
        has_any = true;
      }
    }
  };

  auto link_subs = [&](const Substitution::NodeList &nodes,
                       const char *prefix) {
    for (const Substitution::Node &ent : nodes) {
      if (std::holds_alternative<Substitution *>(ent)) {
        Substitution *s = std::get<Substitution *>(ent);
        assert(s->parent == self || s->is_dead || s->before.has_error ||
               s->after.has_error);
        s->PrintDOT(os, false);
        auto other = reinterpret_cast<const void *>(s);
        os << prefix << self << ":s" << other << " -> s" << other << ";\n";
      }
    }
  };

  if (HasExpansion()) {
    os << "s" << reinterpret_cast<const void *>(this)
       << " [label=<<TABLE cellpadding=\"0\" cellspacing=\"0\" border=\"1\""
       << "><TR><TD colspan=\"" << (2 + int(!body.empty())) << "\">"
       << mx::EnumeratorName(kind) << "</TD></TR><TR><TD port=\"before\">before</TD>";

    if (body.size()) {
      os << "<TD port=\"body\">body</TD>";
    }

    os << "<TD port=\"after\">"
       << "after</TD></TR></TABLE>>];\n";

    if (before.size()) {
      os << "s" << self << ":before -> b" << self << ";\n"
         << "b" << self
         << " [label=<<TABLE cellpadding=\"0\" cellspacing=\"0\" border=\"1\"";
      if (before.has_error) {
        os << " bgcolor=\"red\"";
      }
      os << "><TR>";

      has_any = false;

      dump_toks(before);

      os << "</TR></TABLE>>];\n";

      link_subs(before, "b");
    }

    if (body.size()) {
      os << "s" << self << ":body -> d" << self << ";\n"
         << "d" << self
         << " [label=<<TABLE cellpadding=\"0\" cellspacing=\"0\" border=\"1\"";
      if (body.has_error) {
        os << " bgcolor=\"red\"";
      }
      os << "><TR>";

      has_any = false;

      dump_toks(body);

      os << "</TR></TABLE>>];\n";

      link_subs(body, "d");
    }

    if (after.size()) {
      os << "s" << self << ":after -> a" << self << ";\n"
         << "a" << self
         << " [label=<<TABLE cellpadding=\"0\" cellspacing=\"0\" border=\"1\"";
      if (after.has_error) {
        os << " bgcolor=\"red\"";
      }
      os << "><TR>";

      has_any = false;

      dump_toks(after);

      os << "</TR></TABLE>>];\n";

      link_subs(after, "a");
    }

  // No expansion.
  } else {
    auto num_cols = before.size();

    os << "s" << self
       << " [label=<<TABLE cellpadding=\"0\" cellspacing=\"0\" border=\"1\"";
    if (before.has_error) {
      os << " bgcolor=\"red\"";
    }
    os << "><TR><TD colspan=\"" << num_cols << "\">"
       << mx::EnumeratorName(kind) << "</TD></TR><TR>";

    dump_toks(before);

    if (!has_any && !num_cols) {
      os << "<TD> </TD>";
    }

    os << "</TR></TABLE>>];\n";

    link_subs(before, "s");
  }

  if (first) {
    os << "}\n\n";
  }
}

// Build an initial token info list. This contains all of the tokens that were
// parsed, plus the file tokens that were macro uses. This does not contain
// file tokens that were elided due to things like conditional macros, e.g.
// `#if 0`.
Substitution *TokenTreeImpl::BuildFromTokenList(
    const std::optional<pasta::TokenRange> &range,
    const pasta::PrintedTokenRange &printed_range,
    const std::vector<pasta::Decl> &top_level_decls,
    std::ostream &err) {

  if (range.has_value()) {
    return BuildFromParsedTokenList(
        range.value(), printed_range, top_level_decls, err);

  } else if (printed_range) {
    return BuildFromPrintedTokenList(printed_range, err);

  } else {
    err << "Empty parsed and printed token ranges";
    return nullptr;
  }
}

// It's possible that we have no parsed tokens. E.g. a 100% synthesized
// fragment, which happens when we have things like built-in types (e.g. for
// varargs), or built-in definitions.
Substitution *TokenTreeImpl::BuildFromPrintedTokenList(
    const pasta::PrintedTokenRange &range, std::ostream &err) {

  Substitution *sub = CreateSubstitution(mx::MacroKind::OTHER_DIRECTIVE);

  for (pasta::PrintedToken tok : range) {
    TokenInfo &info = tokens_alloc.emplace_back();
    info.printed_tok = tok;
    info.parsed_tok = tok.DerivedLocation();
    sub->before.emplace_back(&info);
  }

  return sub;
}

// Most of the time we have parsed tokens and printed tokens, where the printed
// tokens are a subset of the parsed tokens, and should reference them. The
// printed tokens being a subset is due to `pasta::PrintedTokenRange::Adopt` on
// `range`, then the indexer tries to align the adopted range with a 100%
// invented range (generated by pretty printing).
Substitution *TokenTreeImpl::BuildFromParsedTokenList(
    const pasta::TokenRange &range,
    const pasta::PrintedTokenRange &printed_range,
    const std::vector<pasta::Decl> &top_level_decls,
    std::ostream &err) {

  bool in_macro = false;
  std::optional<pasta::Macro> pending_macro;

  Substitution *root_sub = CreateSubstitution(mx::MacroKind::OTHER_DIRECTIVE);

  std::vector<std::pair<Substitution *, Substitution::NodeList *>> subs;
  subs.emplace_back(root_sub, &(root_sub->before));

  // Figure out a mapping between parsed tokens are printed tokens.
  std::unordered_map<const void *, pasta::PrintedToken> printed_tokens;
  for (auto pt : printed_range) {
    if (auto dt = pt.DerivedLocation()) {
      printed_tokens.emplace(RawEntity(dt.value()), std::move(pt));
    }
  }

  for (pasta::Token tok : range) {
    TokenInfo *info = nullptr;

    switch (tok.Role()) {

      // These will happen because of token splits in PASTA.
      case pasta::TokenRole::kInvalid:
        continue;

      case pasta::TokenRole::kBeginOfMacroExpansionMarker:
        assert(!in_macro);
        assert(!pending_macro.has_value());
        in_macro = true;
        pending_macro = pasta::Macro::FromMarkerToken(tok);
        if (pending_macro.has_value()) {
          pending_macro = RootNodeFrom(pending_macro.value());
        }
        continue;

      case pasta::TokenRole::kMacroDirectiveMarker:

        // We're in a floating fragment for a `#define` or `#pagma` directive.
        // It contains only the marker token for this directive.
        if (!pending_macro) {
          assert(!in_macro);
          assert(range.size() == 1u);
          pending_macro = pasta::Macro::FromMarkerToken(tok);
          
          assert(pending_macro.has_value());
          if (pending_macro.has_value() &&
              !BuildFromMacro(subs.back().first, *(subs.back().second),
                              std::move(pending_macro.value()), err)) {
            return nullptr;
          }
        }

        continue;

      case pasta::TokenRole::kEndOfMacroExpansionMarker:
        assert(in_macro);
        assert(pending_macro.has_value());
        in_macro = false;

        if (!pending_macro.has_value()) {
          assert(false);
          err << "Got to end-of-macro-expansion marker without a macro to process";
          return nullptr;
        }

        if (!BuildFromMacro(subs.back().first, *(subs.back().second),
                            std::move(pending_macro.value()), err)) {
          return nullptr;
        }
        pending_macro.reset();
        continue;

      case pasta::TokenRole::kIntermediateMacroExpansionToken:
      case pasta::TokenRole::kInitialMacroUseToken:
        assert(false);  // Makes no sense to see these tokens in the parsed list.
        assert(in_macro);
        continue;

      // TODO(pag): Maybe a stack of substitutions?
      case pasta::TokenRole::kBeginOfFileMarker: {
        assert(!in_macro);

        if (subs.empty()) {
          assert(false);
          has_error = true;
          err << "Unexpected begin-of-file marker with empty substitution stack";
          return nullptr;
        }

        if (subs.back().second->empty()) {
          assert(false);
          has_error = true;
          err << "Unexpected begin-of-file marker with empty parent node list";
          return nullptr;
        }

        if (!std::holds_alternative<Substitution *>(subs.back().second->back())) {
          assert(false);
          has_error = true;
          err << "Unexpected begin-of-file marker non-substitution on end of parent node list";
          return nullptr;
        }

        auto inc = std::get<Substitution *>(subs.back().second->back());
        switch (inc->kind) {
          case mx::MacroKind::INCLUDE_DIRECTIVE:
          case mx::MacroKind::INCLUDE_MACROS_DIRECTIVE:
          case mx::MacroKind::INCLUDE_NEXT_DIRECTIVE:
          case mx::MacroKind::IMPORT_DIRECTIVE:
            break;

          default:
            has_error = true;
            err << "Last substitution isn't an include directive";
            return nullptr;
        }

        // Create a substitution above the `#include` directive.
        auto inc_sub = CreateSubstitution(mx::MacroKind::SUBSTITUTION);
        inc_sub->before.emplace_back(inc);
        inc->parent = inc_sub;

        inc_sub->parent = subs.back().first;
        subs.back().second->back() = inc_sub;

        // Switch to the "after" of the include directive.
        subs.emplace_back(inc_sub, &(inc_sub->after));
        continue;
      }

      case pasta::TokenRole::kEndOfFileMarker:
        assert(!in_macro);

        if (subs.empty()) {
          assert(false);
          has_error = true;
          err << "Unexpected end-of-file marker with empty substitution stack";
          return nullptr;
        }

        // We're on the other side of an include.
        if (&(subs.back().first->after) == subs.back().second) {
          assert(subs.size() > 1u);
        }

        subs.pop_back();
        
        // We have an entity that crossed from the end of one file back into
        // its including file.
        //
        // This happens in the Linux kernel with `drbd_genl_cmd_to_str` that has
        // an attribute in one file but the rest of the function in another
        // file. This entity is produced by macro expansion of:
        //
        //        CONCAT_(GENL_MAGIC_FAMILY, _genl_cmd_to_str)
        //
        // in the x-macro file `include/linux/genl_magic_func.h`, where the
        // attribute is the last thing in a macro expansion of `GENL_struct` in
        // the same file.
        //
        // What happens is that we end up having unbalanced begin/end file marker
        // tokens and we accumulate into the top-level. In theory we should
        // accumulate an `#include` above `root_sub`, and do a kind of recursive
        // ascent constuction of the tree. In practice, we don't expect to hit
        // this situation, and we try to mitigate the issue of unbalanced `BOF`
        // and `EOF` tokens in `IndexCompileJob.cpp` by identifying when decls
        // include `EOF` markers, and then expanding their ranges to contain the
        // associated `#include` directive.
        //
        // XREF(pag): Issue 258.
        // https://github.com/trailofbits/multiplier/issues/258#issuecomment-1401170794
        if (subs.empty()) {
          subs.emplace_back(root_sub, &(root_sub->before));
        }
        continue;

      // Create token info for each final macro expansion token, but don't
      // actually link them into the substitution. This will happen as-needed
      // when we get to the end of the macro expansion region and visit all
      // of its nodes.
      case pasta::TokenRole::kFinalMacroExpansionToken:
        assert(in_macro);
        info = &(tokens_alloc.emplace_back());
        info->macro_tok = tok.MacroLocation();
        info->parsed_tok = std::move(tok);

        // They should match, but it could also be a split token case, e.g.
        // the parsed token is `>` or `=`, and the macro token is `>=`.
        assert(info->macro_tok->Data().starts_with(info->parsed_tok->Data()) ||
               info->macro_tok->Data().ends_with(info->parsed_tok->Data()));

        assert(info->macro_tok->TokenRole() ==
               pasta::TokenRole::kFinalMacroExpansionToken);
        final_toks.emplace(info->macro_tok->RawMacro(), info);
        break;

      case pasta::TokenRole::kFileToken:
        assert(!in_macro);
        assert(!tok.MacroLocation());
        info = &(tokens_alloc.emplace_back());
        info->parsed_tok = std::move(tok);
        subs.back().second->emplace_back(info);
        break;
    }

    if (auto it = printed_tokens.find(RawEntity(info->parsed_tok.value()));
        it != printed_tokens.end()) {
      info->printed_tok = it->second;
    }
  }

  if (in_macro) {
    err << "Reached end of token list while still in macro";
    return nullptr;
  }

  assert(root_sub->after.empty());
  assert(subs.size() == 1u);
  assert(subs.back().first == root_sub);

  // It's not a specialization of any kind, so we don't need to check if tokens
  // are contiguous or rebuild things.
  if (top_level_decls.size() != 1u ||
      !IsSpecializationOrTemplateInSpecialization(top_level_decls.front())) {
    return root_sub;
  }

  std::cerr << "\n-- REBUILDING TREE ----------\n";
  std::cerr << printed_range.Data() << "\n";

  return RebuildTree(root_sub, range, printed_range, top_level_decls.front(),
                     err);
}

// This code is pretty challenging. The situation we face is that we have
// a token tree constructed from parsed tokens. However, in the situations in
// which this function is called, the parsed tokens represent something like
// a class template declaration. What we really want is a token tree for
// `printed_range`, which isn't the usual printer-adopted parsed token range
// with aligned token contexts, but actually the pretty-printed specialization
// declaration. In the case of `printed_range`, there isn't a 1:1 mapping back
// to `range` -- some tokens in `range` may appear multiple times in
// `printed_range` (in terms of `.DerivedLocation()`), some tokens may be gone
// entirely (e.g. some `sizeof...(...)` replaced with a number), and some may
// be completely new and without any form of provenance (e.g. said number). This
// function attempts to maintain, as much as possible, the original "shape" of
// the macro expansion tree, but have all the final expansion leaves be based
// on `printed_range`.
Substitution *TokenTreeImpl::RebuildSubTree(
    Substitution *sub, Substitution::NodeList *injection_site,
    const pasta::TokenRange &range,
    const pasta::PrintedTokenRange &printed_range,
    const pasta::Decl &top_level_decl,
    const std::unordered_map<Substitution *, std::vector<TokenInfo *>> &parsed_tokens,
    TokenInfo *&prev_parsed_token,
    unsigned &next_printed_index,
    std::ostream &err) {

  auto it = parsed_tokens.find(sub);
  if (it == parsed_tokens.end()) {
    return sub;
  }

  auto &old_nodes = sub->after.empty() ? sub->before : sub->after;
  Substitution::NodeList new_nodes;

  if (!injection_site) {
    injection_site = &new_nodes;
  }

  // Inclusive indices on the min/max parsed indices that should have fit into
  // this area.
  auto min_parsed_index = it->second.front()->parsed_tok->Index();
  auto max_parsed_index = it->second.back()->parsed_tok->Index();
  assert(min_parsed_index <= max_parsed_index);

  auto spec_tok = printed_range.At(next_printed_index);
  
  // If this substitution starts at a specific spot, and we're not there yet,
  // then go and inject stuff to get us closer to there. This could inject
  // these prefix token nodes into our parent, or into ourself if this is the
  // root substitution node.
  auto injected_prefix = false;
  while (spec_tok) {
    auto spec_dtok = spec_tok->DerivedLocation();
    if (!spec_dtok) {
      break;
    }
    
    auto spec_dtok_index = spec_dtok->Index();
    if (spec_dtok_index >= min_parsed_index) {
      break;
    }

    auto new_tok = &(tokens_alloc.emplace_back());
    new_tok->macro_tok = spec_dtok->MacroLocation();
    new_tok->parsed_tok = std::move(spec_dtok);
    new_tok->printed_tok = std::move(spec_tok);
    injection_site->emplace_back(new_tok);

    prev_parsed_token = new_tok;

    spec_tok = printed_range.At(++next_printed_index);
    injected_prefix = true;
  }

  if (injected_prefix) {
    injection_site = &new_nodes;
  }

  // The last parsed token we injected comes immediately before this expansion.
  // If we've matched up someting like `[` before a `[SIZE` where `SIZE` is a
  // macro expansion, and all of the expanded tokens in `SIZE` are replaced in
  // the template specialization, then we want to make sure the injection site
  // is inside `sub`, rather than our parent.
  if (injection_site != &new_nodes &&
      prev_parsed_token &&
      prev_parsed_token->parsed_tok->Index() <= min_parsed_index) {
    auto offset = prev_parsed_token->parsed_tok->Index() -
                  range.Front()->Index();
  
    while (auto next_tok = range.At(++offset)) {
      auto nti = next_tok->Index();
      if (nti >= min_parsed_index) {
        injection_site = &new_nodes;
        goto process_old_nodes;
      }

      switch (next_tok->Role()) {
        case pasta::TokenRole::kFileToken:
        case pasta::TokenRole::kFinalMacroExpansionToken:
          goto process_old_nodes;
        default:
          continue;
      }
    }
  }

process_old_nodes:
  for (auto node : old_nodes) {

    if (std::holds_alternative<Substitution *>(node)) {
      auto old_prev_parsed_token = prev_parsed_token;
      auto old_next_printed_index = next_printed_index;
      auto new_sub = RebuildSubTree(
          std::get<Substitution *>(node), injection_site, range, printed_range,
          top_level_decl, parsed_tokens, prev_parsed_token, next_printed_index,
          err);
      
      if (!new_sub) {
        return nullptr;
      }

      if (prev_parsed_token != old_prev_parsed_token ||
          next_printed_index != old_next_printed_index) {
        injection_site = &new_nodes;
      }

      spec_tok = printed_range.At(next_printed_index);
      new_nodes.emplace_back(new_sub);
      continue;
    }

    if (!std::holds_alternative<TokenInfo *>(node)) {
      assert(false);
      return nullptr;
    }

    TokenInfo *old_tok = std::get<TokenInfo *>(node);
    if (!old_tok) {
      assert(false);
      return nullptr;
    }

    // We should only be seeing parsed tokens.
    if (!old_tok->parsed_tok.has_value()) {
      assert(false);
      return nullptr;
    }

    // Try to pull in a prefix of printed tokens that have no known/associated
    // parsed tokens.
    std::optional<pasta::Token> spec_dtok;
    while (spec_tok) {
      spec_dtok = spec_tok->DerivedLocation();
      if (spec_dtok) {
        break;
      }

      // No associated parsed location; inject it.
      auto new_tok = &(tokens_alloc.emplace_back());
      if (spec_dtok) {
        prev_parsed_token = new_tok;
      }
      new_tok->printed_tok = std::move(spec_tok);
      new_tok->parsed_tok = std::move(spec_dtok);
      injection_site->emplace_back(new_tok);
      spec_tok = printed_range.At(++next_printed_index);
    }

    // If there are no more tokens from the pretty-printed specialization that
    // we can import, and this token is associated with an original parsed token
    // from the template, then we have to skip this token, because it has no
    // place.
    if (!spec_tok || !spec_dtok) {
      continue;
    }

    auto old_tok_parsed_index = old_tok->parsed_tok->Index();
    auto spec_dtok_parsed_index = spec_dtok->Index();

    assert(min_parsed_index <= old_tok_parsed_index);
    assert(old_tok_parsed_index <= max_parsed_index);

    // The pretty-printed token from the specialization has a matching parsed
    // token. It is possible that we have a one-to-many relation between
    // parsed tokens and pretty printed tokens, for whatever reasons.

    // Best-case situation, we have alignment!
    if (old_tok_parsed_index == spec_dtok_parsed_index) {
      injection_site = &new_nodes;

      auto new_tok = &(tokens_alloc.emplace_back());
      new_tok->printed_tok = std::move(spec_tok);
      new_tok->parsed_tok = std::move(spec_dtok);
      new_tok->macro_tok = old_tok->macro_tok;
      injection_site->emplace_back(new_tok);

      spec_tok = printed_range.At(++next_printed_index);
      prev_parsed_token = new_tok;
      continue;
    }
    
    // Skip this token; it's now dead.
    if (old_tok_parsed_index < spec_dtok_parsed_index) {
      continue;
    }
    
    // Whitespace or comment, bring it in.
    auto stk = spec_tok->Kind();
    if (stk == pasta::TokenKind::kUnknown ||
        stk == pasta::TokenKind::kComment) {
      auto new_tok = &(tokens_alloc.emplace_back());
      if (spec_dtok) {
        prev_parsed_token = new_tok;
      }

      new_tok->printed_tok = std::move(spec_tok);
      new_tok->parsed_tok = std::move(spec_dtok);
      injection_site->emplace_back(new_tok);

      spec_tok = printed_range.At(++next_printed_index);
      continue;
    }

    // TODO(pag): Often this is the result of a bug in PASTA's pretty printer,
    //            or PASTA's token alignment procedure. In the case of the
    //            pretty printer, it could be related to over-aggressively
    //            assigning a derived source location to a printed token, and
    //            then that may cause other interferences within the token
    //            alignment algorithm. The way to diagnose this often involves
    //            turing on the token aligner debug information logging, and
    //            then printing out `spec_dtok->Index()`, and then looking at
    //            what tokens in the alignment dump have the same parsed token
    //            index. Then, look at nearby tokens, and compare the tokens
    //            with `spec_dtok->Data()` and `spec_tok->Data()`.
    //assert(false);
  }

  // Bring in a suffix of printed tokens with no corresponding parsed tokens.
  // In the case of something like `[SIZE]`, where the original parsed tokens
  // of `SIZE` are replaced, we want to get all those tokens before the `]`.
  //
  // TODO(pag): Use token contexts as an additional heuristic?
  while (injection_site == &new_nodes && spec_tok) {
    auto spec_dtok = spec_tok->DerivedLocation();
    if (spec_dtok || spec_dtok->Index() <= max_parsed_index) {
      break;
    }

    // No associated parsed location; inject it.
    auto new_tok = &(tokens_alloc.emplace_back());
    if (spec_dtok) {
      new_tok->macro_tok = spec_dtok->MacroLocation();
      prev_parsed_token = new_tok;
    }
    new_tok->printed_tok = std::move(spec_tok);
    new_tok->parsed_tok = std::move(spec_dtok);
    injection_site->emplace_back(new_tok);
    spec_tok = printed_range.At(++next_printed_index);
  }

  old_nodes = std::move(new_nodes);

  FixupNodeParents(sub);

  return sub;
}

// Possible rebuild the tree knowing that the `printed_range` tokens are the
// ones that we want to present. This happens when `printed_range` is derived
// from a template specialization.
Substitution *TokenTreeImpl::RebuildTree(
    Substitution *original_root, const pasta::TokenRange &range,
    const pasta::PrintedTokenRange &printed_range,
    const pasta::Decl &top_level_decl, std::ostream &err) {

  // Collect a mapping of substitutions containing parsed tokens, along with
  // those parsed tokens in the order that we see them.
  std::unordered_map<Substitution *, std::vector<TokenInfo *>> sub_tokens;
  FindParsedTokens(original_root, sub_tokens);
  if (sub_tokens.empty()) {
    return original_root;
  }

  TokenInfo *prev_parsed_token = nullptr;
  unsigned next_printed_index = 0u;
  auto new_root = RebuildSubTree(
      original_root, nullptr, range, printed_range,
      top_level_decl, sub_tokens, prev_parsed_token,
      next_printed_index, err);

  if (!new_root) {
    return nullptr;
  }

  // Suffix of unmatched/uninjected tokens.
  while (auto spec_tok = printed_range.At(next_printed_index++)) {
    auto spec_dtok = spec_tok->DerivedLocation();
    auto new_tok = &(tokens_alloc.emplace_back());
    new_tok->printed_tok = spec_tok;
    new_tok->parsed_tok = spec_dtok;

    // NOTE(pag): Ignore macro locations; it might mislead provenance.
    new_tok->parent = new_root;
    new_root->before.emplace_back(new_tok);
  }

  return new_root;

  // // - have to remove tokens
  // // - have to add tokens
  // // - find a node list in an expansion, and replace all of its children with
  // //   stuff from the printed tokens

  // size_t next_printed_tok = 1u;
  // std::optional<pasta::PrintedToken> npt = printed_range.At(0);

  // // Match up the parsed token with a printed token.
  
  // auto next_parsed_tok = first_tok;

  // for (auto printed_tok : printed_range) {

  // }

  // while (!info->printed_tok.has_value() && npt.has_value()) {
  //   if (auto npt_pt = npt->DerivedLocation()) {
  //     auto npt_pti = npt_pt->Index();
  //     if (npt_pti == pti) {
  //       info->printed_tok = std::move(npt);
  //       // Fall through to update `npt`.

  //     } else if (npt_pti > pti) {
  //       break;
  //     }
  //   }

  //   npt = printed_range.At(next_printed_tok++);
  // }
}

bool TokenTreeImpl::BuildFromMacro(
    Substitution *sub, Substitution::NodeList &nodes, pasta::Macro node,
    std::ostream &err) {
  switch (node.Kind()) {
    case pasta::MacroKind::kToken:
      return BuildMacroSubstitution(
          sub, nodes, reinterpret_cast<pasta::MacroToken &>(node), err);
    case pasta::MacroKind::kArgument:
      return BuildMacroSubstitution(
          sub, nodes, reinterpret_cast<pasta::MacroArgument &>(node), err);
    case pasta::MacroKind::kParameter:
      return BuildMacroSubstitution(
          sub, nodes, reinterpret_cast<pasta::MacroParameter &>(node), err);
    case pasta::MacroKind::kExpansion:
      return BuildMacroSubstitution(
          sub, nodes, reinterpret_cast<pasta::MacroExpansion &>(node), err);
    case pasta::MacroKind::kVAOpt:
      return BuildMacroSubstitution(
          sub, nodes, reinterpret_cast<pasta::MacroVAOpt &>(node), err);
    case pasta::MacroKind::kVAOptArgument:
      return BuildMacroSubstitution(
          sub, nodes, reinterpret_cast<pasta::MacroVAOptArgument &>(node), err);
    case pasta::MacroKind::kSubstitution:
    case pasta::MacroKind::kParameterSubstitution:
    case pasta::MacroKind::kStringify:
    case pasta::MacroKind::kConcatenate:
      return BuildMacroSubstitution(
          sub, nodes, reinterpret_cast<pasta::MacroSubstitution &>(node), err);
    case pasta::MacroKind::kOtherDirective:
    case pasta::MacroKind::kIfDirective:
    case pasta::MacroKind::kIfDefinedDirective:
    case pasta::MacroKind::kIfNotDefinedDirective:
    case pasta::MacroKind::kElseIfDirective:
    case pasta::MacroKind::kElseIfDefinedDirective:
    case pasta::MacroKind::kElseIfNotDefinedDirective:
    case pasta::MacroKind::kElseDirective:
    case pasta::MacroKind::kEndIfDirective:
    case pasta::MacroKind::kUndefineDirective:
    case pasta::MacroKind::kPragmaDirective:
    case pasta::MacroKind::kIncludeDirective:
    case pasta::MacroKind::kIncludeNextDirective:
    case pasta::MacroKind::kIncludeMacrosDirective:
    case pasta::MacroKind::kImportDirective:
    case pasta::MacroKind::kDefineDirective:
      return BuildMacroSubstitution(
          sub, nodes, reinterpret_cast<pasta::MacroDirective &>(node), err);
  }

  err << "Unexpected/unsupported substitution kind";
  return false;
}

Substitution *TokenTreeImpl::CreateSubstitution(mx::MacroKind kind_) {
  return &(substitutions_alloc.emplace_back(kind_));
}

// Merge an argument `orig` from the main expansion with the argument `pre_exp`
// from the pre argumetn expansion phase. E.g. in the following case:
//
//      macro(
//        "hello"
//        #if anotehr_macro
//        "world"
//        #endif
//        )
//
// Then things like `another_macro` and the `#if` will be present in `orig` but
// not in `pre_exp`.
Substitution *TokenTreeImpl::MergeArguments(
    Substitution *sub, Substitution *pre_exp, std::ostream &err) {

  assert(sub->after.empty());
  assert(pre_exp->after.empty());

  auto orig_arg = pasta::MacroArgument::From(sub->macro.value());
  auto pre_exp_arg = pasta::MacroArgument::From(sub->macro.value());

  if (orig_arg->Index() != pre_exp_arg->Index()) {
    sub->before.has_error = true;
    pre_exp->before.has_error = true;
    Die(this);
    err << "Can't merge arguments with non-matching indices";
    return nullptr;
  }

  D( std::cerr << indent << "Merge pre expansion argument "
               << orig_arg->Index() << '\n'; )

  if (pre_exp->before.empty()) {
    D( std::cerr << indent << "  Trivial merge\n"; )
    return sub;
  }

  // Check if all original argument nodes are tokens.
  bool orig_is_simple = true;
  for (Substitution::Node &orig_node : sub->before) {
    if (!std::holds_alternative<TokenInfo *>(orig_node)) {
      orig_is_simple = false;
      break;
    }
  }

  // If at least one of the original argument nodes is a substitution, then
  // create a before/after substitution.
  if (!orig_is_simple) {

    D( std::cerr << indent << "  Argument isn't simple, using substitution.\n"; )

    Substitution::NodeList new_nodes;

    Substitution *new_arg_sub = CreateSubstitution(mx::MacroKind::SUBSTITUTION);
    new_arg_sub->before = std::move(sub->before);
    new_arg_sub->after = std::move(pre_exp->before);
    new_arg_sub->parent = sub;
    FixupNodeParents(new_arg_sub);

    new_nodes.emplace_back(new_arg_sub);
    sub->before = std::move(new_nodes);

  // Use `pre_exp` because the original is simple, and so the pre-expansion
  // is either simple or not, so whatever it is is more desirable.
  } else {
    sub->before = std::move(pre_exp->before);
    sub->after = std::move(pre_exp->after);
    FixupNodeParents(sub);
  }

  pre_exp->before.clear();
  pre_exp->after.clear();
  pre_exp->macro.reset();
  pre_exp->parent = nullptr;
  pre_exp->is_dead = true;

  return sub;
}

// Tries to unify a macro use with its pre-expansion phase, so that we don't
// doubly count macro uses in the indexer, and so that pre-expansions aren't
// presented in a confusing way.
bool TokenTreeImpl::MergeArgPreExpansion(Substitution *sub,
                                         Substitution *pre_exp,
                                         std::ostream &err) {

  D( std::cerr << indent << "Merge pre expansion";
     if (sub->macro) {
       if (auto bt = sub->macro->BeginToken()) {
         std::cerr << ' ' << bt->Data();
       }
     }
     std::cerr << '\n';)
  D( indent += "  "; )

  // Make sure we calculate the pre-expansion correctly.
  assert(1u <= sub->after.size());
  assert(std::holds_alternative<Substitution *>(sub->after.front()));
  assert(std::get<Substitution *>(sub->after.front()) == pre_exp);
  assert(sub->kind == mx::MacroKind::EXPANSION);
  assert(pre_exp->kind == mx::MacroKind::EXPANSION);

  Substitution::NodeList new_nodes;

  auto orig_i = 0u;
  auto preexp_i = 0u;
  const auto orig_max = sub->before.size();
  const auto preexp_max = pre_exp->before.size();

  auto changed = true;

  TokenInfo *orig_rc = nullptr;
  TokenInfo *preexp_lc = nullptr;
  Substitution *orig_arg = nullptr;
  Substitution *preexp_arg = nullptr;

  while (orig_i < orig_max && preexp_i < preexp_max && changed) {
    changed = false;
    Substitution::Node orig_node = sub->before[orig_i];
    Substitution::Node preexp_node = pre_exp->before[preexp_i];

    const bool orig_is_tok = std::holds_alternative<TokenInfo *>(preexp_node);
    const bool preexp_is_tok = std::holds_alternative<TokenInfo *>(preexp_node);

    orig_rc = RightCornerOfExpansionOrUse(orig_node);
    preexp_lc = LeftCornerOfUse(preexp_node);

    orig_arg = MacroArgument(orig_node);
    preexp_arg = MacroArgument(preexp_node);

    D(
      std::cerr
          << indent << "orig_i=" << orig_i << " preexp_i=" << preexp_i
          << " preexp_is_tok=" << preexp_is_tok
          << " orig_arg=" << (!!orig_arg) << " preexp_arg=" << (!!preexp_arg)
          << " orig_rc=" << (!!orig_rc) << " preexp_lc=" << (!!preexp_lc);

      std::cerr << '\n';
    )

    // If we have two arguments, then try to merge them.
    if (orig_arg && preexp_arg) {
      if (auto new_arg = MergeArguments(orig_arg, preexp_arg, err)) {
        new_nodes.emplace_back(new_arg);
        changed = true;
        ++orig_i;
        ++preexp_i;
        continue;

      } else {
        return false;
      }

    // Move things to align on arguments.
    } else if (orig_arg) {
      new_nodes.push_back(preexp_node);
      ++preexp_i;
      changed = true;
      continue;

    // Move things to align on arguments.
    } else if (preexp_arg) {

      // If this is something that expands to nothing, e.g. a directive.
      if (!orig_rc) {
        new_nodes.push_back(orig_node);

      // Make a substitution that expands to nothing.
      } else {
        Substitution *empty_sub = CreateSubstitution(
            mx::MacroKind::SUBSTITUTION);
        new_nodes.emplace_back(empty_sub);

        empty_sub->parent = sub;
        empty_sub->before.emplace_back(orig_node);
        FixupNodeParents(empty_sub);
      }

      ++orig_i;
      changed = true;
      continue;
    }

    // If we have stuff with what looks like matching token data, then try to
    // merge them.
    if (orig_rc && preexp_lc &&
        orig_rc->macro_tok->Data() == preexp_lc->macro_tok->Data()) {

      // If the pre-expansion is a token, then the original is more interesting,
      // as it'll be a token or a node (that expands to a token), so keep the
      // original.
      if (preexp_is_tok) {
        new_nodes.push_back(orig_node);

      // If the original is a token, then the pre-expansion is more interesting.
      } else if (orig_is_tok) {
        new_nodes.push_back(preexp_node);

      // If the pre-expansion isn't a token, and regardless of what the original
      // is, then we'll want to show some kind of substitution.
      } else {
        Substitution *non_empty_sub = CreateSubstitution(
            mx::MacroKind::SUBSTITUTION);
        non_empty_sub->parent = sub;
        non_empty_sub->before.emplace_back(orig_node);
        non_empty_sub->after.emplace_back(preexp_node);
        FixupNodeParents(non_empty_sub);
        new_nodes.emplace_back(non_empty_sub);
      }

      changed = true;
      ++orig_i;
      ++preexp_i;
      continue;
    }

    // Something that expands to nothing.
    if (!orig_rc) {
      new_nodes.push_back(orig_node);
      changed = true;
      ++orig_i;
      continue;
    }

    // Should be implied by `!orig_rc`.
    assert(!MacroDirective(orig_node));

    // Something that expands to nothing.
    if (!RightCornerOfExpansionOrUse(preexp_node)) {
      new_nodes.push_back(preexp_node);
      changed = true;
      ++preexp_i;
      continue;
    }

    // Should be implied by `!RightCornerOfExpansionOrUse(preexp_node)`.
    assert(!MacroDirective(preexp_node));

    sub->before.has_error = true;
    pre_exp->before.has_error = true;
    Die(this);
    err << "Unable to merge pre-expansion entries at orig_i=" << orig_i
        << " and preexp_i=" << preexp_i;
    return false;
  }

  if (orig_i != orig_max || preexp_i != preexp_max) {
    sub->before.has_error = true;
    pre_exp->before.has_error = true;
    Die(this);
    err << "Failed to merge trailing entries with orig_i=" << orig_i
        << " orig_max=" << orig_max << " preexp_i=" << preexp_i
        << " preexp_max=" << preexp_max;
    return false;
  }

  // Wipe out the intermediate expansion.
  sub->before = std::move(new_nodes);
  sub->after = std::move(pre_exp->after);
  FixupNodeParents(sub);

  pre_exp->parent = nullptr;
  pre_exp->is_dead = true;
  pre_exp->before.clear();

  D( indent.resize(indent.size() - 2u); )
  return true;
}

// Get or create a substitution representing the body of the macro. Really, this
// is to get the beginning/ending tokens.
Substitution *TokenTreeImpl::GetMacroBody(pasta::DefineMacroDirective def,
                                          std::ostream &err) {

  auto maybe_name = def.Name();
  if (!maybe_name) {
    err << "Macro has no name";
    D( std::cerr << indent << "Failed to get body\n"; )
    return nullptr;
  }

  Substitution *&body = macro_body[def.RawMacro()];
  if (body) {
    D( std::cerr << indent << "Already have body for " << maybe_name->Data()
                 << '\n'; )
    return body;
  }

  D( std::cerr << indent << "Getting body for " << maybe_name->Data()
               << '\n'; )
  D( indent += "  "; )

  pasta::MacroToken name = std::move(maybe_name.value());
  body = CreateSubstitution(mx::MacroKind::DEFINE_DIRECTIVE);
  body->macro = def;

  for (pasta::Macro node : def.Body()) {
    std::optional<pasta::MacroToken> tok = pasta::MacroToken::From(node);
    if (!tok) {
      D( std::cerr << indent << "skipping non-token body node: "
                   << node.BeginToken()->Data() << '\n'; )
      continue;
    }

    D( std::cerr << indent << "body token: " << tok->Data() << '\n'; )

    pasta::TokenKind tok_kind = tok->TokenKind();
    TokenInfo &info = tokens_alloc.emplace_back();
    info.macro_tok = tok;

    switch (tok_kind) {
      case pasta::TokenKind::kEndOfFile:
      case pasta::TokenKind::kEndOfDirective:
        continue;
      default:
        body->before.emplace_back(&info);
        break;
    }
  }

  D( indent.resize(indent.size()  - 2u); )
  (void)err;
  return body;
}

bool TokenTreeImpl::BuildMacroSubstitution(
    Substitution *sub, Substitution::NodeList &nodes,
    const pasta::MacroToken &node, std::ostream &err) {

  TokenInfo *info = nullptr;
  auto it = final_toks.find(node.RawMacro());
  if (it != final_toks.end()) {
    assert(node.TokenRole() == pasta::TokenRole::kFinalMacroExpansionToken);
    info = it->second;

    // Shouldn't see the same parsed token twice in a row.
    if (info->parent) {
      assert(false);

      auto new_info = &(tokens_alloc.emplace_back());
      new_info->parsed_tok = info->parsed_tok;
      new_info->macro_tok = info->macro_tok;
      new_info->printed_tok = info->printed_tok;
      info = new_info;
    }

  } else {
    switch (node.TokenRole()) {
      case pasta::TokenRole::kInitialMacroUseToken:
      case pasta::TokenRole::kIntermediateMacroExpansionToken:
        break;
      default:
        assert(false);
        err << "Unexpected token role for macro token";
        nodes.has_error = true;
        return false;
    }
    info = &(tokens_alloc.emplace_back());
    info->macro_tok = node;
  }

  if (!node.Data().empty()) {
    info->parent = sub;
    nodes.emplace_back(info);
  }

  return true;
}

bool TokenTreeImpl::BuildMacroSubstitution(
    Substitution *sub, Substitution::NodeList &nodes,
    const pasta::MacroArgument &node, std::ostream &err) {

  assert(!nodes.empty());

  Substitution *arg_sub = CreateSubstitution(mx::FromPasta(node.Kind()));
  arg_sub->parent = sub;
  arg_sub->macro = node;
  nodes.emplace_back(arg_sub);

  for (pasta::Macro arg_node : node.Children()) {
    if (!BuildFromMacro(arg_sub, arg_sub->before, std::move(arg_node), err)) {
      return false;
    }
  }

  return true;
}

bool TokenTreeImpl::BuildMacroSubstitution(
    Substitution *sub, Substitution::NodeList &nodes,
    const pasta::MacroVAOpt &node, std::ostream &err) {

  Substitution *arg_sub = CreateSubstitution(mx::FromPasta(node.Kind()));
  assert(sub->kind == mx::MacroKind::EXPANSION ||
         sub->kind == mx::MacroKind::STRINGIFY);
  arg_sub->parent = sub;
  arg_sub->macro = node;
  nodes.emplace_back(arg_sub);

  for (pasta::Macro arg_node : node.Children()) {
    if (!BuildFromMacro(arg_sub, arg_sub->before, std::move(arg_node), err)) {
      return false;
    }
  }

  return true;
}

bool TokenTreeImpl::BuildMacroSubstitution(
    Substitution *sub, Substitution::NodeList &nodes,
    const pasta::MacroVAOptArgument &node, std::ostream &err) {

  Substitution *arg_sub = CreateSubstitution(mx::FromPasta(node.Kind()));
  assert(sub->kind == mx::MacroKind::VA_OPT);
  arg_sub->parent = sub;
  arg_sub->macro = node;
  nodes.emplace_back(arg_sub);

  for (pasta::Macro arg_node : node.Children()) {
    if (!BuildFromMacro(arg_sub, arg_sub->before, std::move(arg_node), err)) {
      return false;
    }
  }

  return true;
}

bool TokenTreeImpl::BuildMacroSubstitution(
    Substitution *sub, Substitution::NodeList &nodes,
    const pasta::MacroParameter &node, std::ostream &err) {

  Substitution *arg_sub = CreateSubstitution(mx::FromPasta(node.Kind()));
  assert(sub->kind == mx::MacroKind::DEFINE_DIRECTIVE);
  arg_sub->parent = sub;
  arg_sub->macro = node;
  nodes.emplace_back(arg_sub);

  for (pasta::Macro arg_node : node.Children()) {
    if (!BuildFromMacro(arg_sub, arg_sub->before, std::move(arg_node), err)) {
      return false;
    }
  }

  return true;
}

bool TokenTreeImpl::BuildMacroSubstitution(
    Substitution *sub, Substitution::NodeList &nodes,
    const pasta::MacroSubstitution &node, std::ostream &err) {

  Substitution *exp = CreateSubstitution(mx::FromPasta(node.Kind()));
  exp->parent = sub;
  exp->macro = node;
  nodes.emplace_back(exp);

  for (pasta::Macro use_node : node.Children()) {
    if (!BuildFromMacro(exp, exp->before, std::move(use_node), err)) {
      return false;
    }
  }

  for (pasta::Macro sub_node : node.ReplacementChildren()) {
    if (!BuildFromMacro(exp, exp->after, std::move(sub_node), err)) {
      return false;
    }
  }

  return true;
}

bool TokenTreeImpl::BuildMacroSubstitution(
    Substitution *sub, Substitution::NodeList &nodes,
    const pasta::MacroExpansion &node, std::ostream &err) {

  Substitution *exp = CreateSubstitution(mx::FromPasta(node.Kind()));
  assert(exp->kind == mx::MacroKind::EXPANSION);

  exp->parent = sub;
  exp->macro = node;
  nodes.emplace_back(exp);

  for (pasta::Macro use_node : node.Children()) {
    if (!BuildFromMacro(exp, exp->before, std::move(use_node), err)) {
      return false;
    }
  }

  for (pasta::Macro body_node : node.IntermediateChildren()) {
    auto body_node_parent = body_node.Parent();
    if (!body_node_parent || body_node_parent->RawMacro() != node.RawMacro()) {
      break;  // This is from the body of a macro definition.
    }

    if (!BuildFromMacro(exp, exp->body, std::move(body_node), err)) {
      return false;
    }
  }

  for (pasta::Macro sub_node : node.ReplacementChildren()) {
    if (!BuildFromMacro(exp, exp->after, std::move(sub_node), err)) {
      return false;
    }
  }

  std::optional<pasta::DefineMacroDirective> macro_def = node.Definition();
  if (!macro_def) {
    return true;
  }

  // We might have a kind of duplicate of this expansion inside of `after`,
  // as a result of macro argument pre-expansion.
  Substitution *pre_exp = PreExpansionOf(exp);

  // Try to find the real body.
  Substitution *macro_body_sub = GetMacroBody(macro_def.value(), err);
  if (!macro_body_sub) {
    exp->after.has_error = true;
    if (auto macro_name = macro_def->Name()) {
      err << "Unable to find macro body for macro with name '"
          << macro_name->Data() << "'";
    } else {
      assert(false);
      err << "Unable to find macro body for macro that was probably not defined";
    }
    return false;
  }

  // Inherit the `after` bounds from the macro body.
  if (pre_exp) {
    if (!MergeArgPreExpansion(exp, pre_exp, err)) {
      if (auto macro_name = macro_def->Name()) {
        err << "Unable to merge argument pre-expansion with use of macro "
            << macro_name->Data() << "'";
      } else {
        assert(false);
        err << "Unable to merge argument pre-expansion with use of macro "
               "that wasn't defined?";
      }
      return false;
    }

    assert(exp->body.empty());
    exp->body = std::move(pre_exp->body);
    assert(!PreExpansionOf(exp));

    FixupNodeParents(exp);
  }

  return sub;
}

bool TokenTreeImpl::BuildMacroSubstitution(
    Substitution *sub, Substitution::NodeList &nodes,
    const pasta::MacroDirective &node, std::ostream &err) {

  Substitution *dir = CreateSubstitution(mx::FromPasta(node.Kind()));
  nodes.emplace_back(dir);
  dir->parent = sub;
  dir->macro = node;

  for (pasta::Macro use_node : node.Children()) {
    if (!BuildFromMacro(dir, dir->before, std::move(use_node), err)) {
      return false;
    }
  }

  return true;
}

TokenTree::~TokenTree(void) {}

// Create a token tree from the tokens in the inclusive range
// `[begin_index, end_index]` from `range`.
std::optional<TokenTreeNodeRange> TokenTree::Create(
    const std::optional<pasta::TokenRange> &range,
    const pasta::PrintedTokenRange &printed_range,
    const std::vector<pasta::Decl> &top_level_decls,
    std::ostream &err) {

  auto impl = std::make_shared<TokenTreeImpl>();

  try {

    // Build and classify the initial list of tokens.
    auto sub = impl->BuildFromTokenList(
        range, printed_range, top_level_decls, err);
    if (!sub) {
      return std::nullopt;
    }

    if (impl->has_error) {
      Die(impl.get());
      return std::nullopt;
    }

    // std::cerr << "--------------------------------------------------------\n";
    // sub->Print(std::cerr);
    // std::cerr << "\n\n\n";
    // sub->PrintDOT(std::cerr);
    // std::cerr << "\n\n";

    std::shared_ptr<const SubstitutionNodeList> ret(
        std::move(impl), &(sub->before));
    return TokenTreeNodeRange(std::move(ret));

  } catch (const char *msg) {
    err << msg;
    return std::nullopt;
  }
}

std::optional<pasta::PrintedToken> TokenTreeNode::PrintedToken(void) const noexcept {
  if (const auto &ent = (*impl)[offset];
      std::holds_alternative<TokenInfo *>(ent)) {
    return std::get<TokenInfo *>(ent)->printed_tok;
  } else {
    return std::nullopt;
  }
}

std::optional<pasta::MacroToken> TokenTreeNode::MacroToken(void) const noexcept {
  if (const auto &ent = (*impl)[offset];
      std::holds_alternative<TokenInfo *>(ent)) {
    return std::get<TokenInfo *>(ent)->macro_tok;
  } else {
    return std::nullopt;
  }
}

std::optional<pasta::Token> TokenTreeNode::Token(void) const noexcept {
  if (const auto &ent = (*impl)[offset];
      std::holds_alternative<TokenInfo *>(ent)) {
    return std::get<TokenInfo *>(ent)->parsed_tok;
  } else {
    return std::nullopt;
  }
}

const void *TokenTreeNode::RawNode(void) const noexcept {
  const SubstitutionNode &ent = (*impl)[offset];
  return &ent;
}

std::optional<TokenTree> TokenTreeNode::SubTree(void) const noexcept {
  if (const auto &ent = (*impl)[offset];
      std::holds_alternative<Substitution *>(ent)) {
    std::shared_ptr<const Substitution> ptr(
        impl, std::get<Substitution *>(ent));
    return TokenTree(std::move(ptr));
  } else {
    return std::nullopt;
  }
}

bool TokenTreeNodeIterator::operator==(TokenTreeNodeIteratorEnd) const {
  return node.offset >= node.impl->size();
}

bool TokenTreeNodeIterator::operator!=(TokenTreeNodeIteratorEnd) const {
  return node.offset < node.impl->size();
}

// Dump.
void TokenTreeNodeRange::Dump(std::ostream &os) const {
  Substitution *root = nullptr;
  for (const SubstitutionNode &node : *(begin_.node.impl)) {
    if (!std::holds_alternative<Substitution *>(node)) {
      continue;
    }

    Substitution *sub = std::get<Substitution *>(node);
    while (sub) {
      root = sub;
      sub = sub->parent;
    }

    if (root) {
      break;
    }
  }

  if (root) {
    std::unique_lock<std::mutex> locker(gPrintDOTLock);
    root->PrintDOT(os);
    os.flush();
  }
}

unsigned TokenTreeNodeRange::Size(void) const noexcept {
  return static_cast<unsigned>(begin_.node.impl->size());
}

// Dump.
void TokenTree::Dump(std::ostream &os) const {
  impl->PrintDOT(os, true);
}

mx::MacroKind TokenTree::Kind(void) const noexcept {
  assert(!impl->macro || mx::FromPasta(impl->macro->Kind()) == impl->kind);
  return impl->kind;
}

std::optional<pasta::Macro> TokenTree::Macro(void) const noexcept {
  return impl->macro;
}

std::optional<TokenTree> TokenTree::Parent(void) const noexcept {
  if (!impl->parent) {
    assert(false);  // Should never call expose the root.
    return std::nullopt;
  }

  if (!impl->parent->parent) {
    return std::nullopt; // This is the root node.
  }

  std::shared_ptr<const Substitution> ptr(impl, impl->parent);
  return TokenTree(std::move(ptr));
}

TokenTreeNodeRange TokenTree::Children(void) const noexcept {
  std::shared_ptr<const SubstitutionNodeList> ptr(impl, &(impl->before));
  return TokenTreeNodeRange(std::move(ptr));
}

TokenTreeNodeRange TokenTree::IntermediateChildren(void) const noexcept {
  std::shared_ptr<const SubstitutionNodeList> ptr(impl, &(impl->body));
  return TokenTreeNodeRange(std::move(ptr));
}

TokenTreeNodeRange TokenTree::ReplacementChildren(void) const noexcept {
  std::shared_ptr<const SubstitutionNodeList> ptr(impl, &(impl->after));
  return TokenTreeNodeRange(std::move(ptr));
}

std::optional<pasta::MacroToken>
TokenTree::FirstFullySubstitutedToken(void) const noexcept {
  if (auto lc = LeftCornerOfExp(const_cast<Substitution *>(impl.get()))) {
    if (lc->macro_tok) {
      return lc->macro_tok;
    }
  }
  return std::nullopt;
}

std::optional<pasta::MacroToken>
TokenTree::LastFullySubstitutedToken(void) const noexcept {
  if (auto rc = RightCornerOfExp(const_cast<Substitution *>(impl.get()))) {
    if (rc->macro_tok) {
      return rc->macro_tok;
    }
  }
  return std::nullopt;
}

std::optional<pasta::MacroToken> TokenTree::NameOrOperator(void) const noexcept {
  if (impl->macro) {
    if (auto sub = pasta::MacroSubstitution::From(impl->macro.value())) {
      return sub->NameOrOperator();
    }
  }
  return std::nullopt;
}

// Return whether or not this node has intermediate children.
bool TokenTree::HasIntermediateChildren(void) const noexcept {
  return Kind() == mx::MacroKind::EXPANSION;
}

bool TokenTree::HasExpansion(void) const noexcept {
  return impl->HasExpansion();
}

// Return the number of nodes in this tree.
unsigned TokenTree::NumChildren(void) const noexcept {
  return static_cast<unsigned>(impl->before.size());
}

// Return the number of replacement nodes in this tree.
unsigned TokenTree::NumReplacementChildren(void) const noexcept {
  return static_cast<unsigned>(impl->after.size());
}

}  // namespace indexer
