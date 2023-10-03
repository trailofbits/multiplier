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
#include <multiplier/Entities/MacroKind.h>
#include <multiplier/Types.h>
#include <mutex>
#include <optional>
#include <pasta/AST/AST.h>
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

//#define D(...) __VA_ARGS__
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
  enum Category : unsigned char {
    // A token, produced as a result of macro expansion, but somewhere between
    // use and parse, i.e. this is not parsed.
    //
    // NOTE(pag): This could represent an intermediate macro use.
    kMacroStepToken,

    // A parsed token, produced as a result of macro expansion.
    kMacroExpansionToken,

    // A file token, introduced because it was part of the file, and was
    // missing in the parse because it was a macro use.
    //
    // NOTE(pag): This is only for top-level uses of macros. Intermediate uses
    //            are represented as `kMacroStepToken`.
    kMacroUseToken,

    // A parsed token associated with a file token.
    kFileToken,

    // A token that wasn't parsed, e.g. due to being elided by an `#if 0`
    // conditional directive, and that we've injected back in to aid in
    // alignment with the original tokens.
    kMissingFileToken,

    // A marker token from PASTA, e.g. macro/file begin/end.
    kMarkerToken,
  };

  TokenInfo *next{nullptr};

  std::optional<pasta::Token> parsed_tok;
  std::optional<pasta::PrintedToken> printed_tok;
  std::optional<pasta::FileToken> file_tok;
  std::optional<pasta::MacroToken> macro_tok;
  Category category{kFileToken};

  // `, ## __VA_ARGS__`.
  bool is_va_args_concat{false};
};

using SubstitutionNode = std::variant<TokenInfo *, Substitution *>;

class SubstitutionNodeList : public std::vector<SubstitutionNode> {
 public:
  // Tokens that are logically before and after everything in this vector.
  TokenInfo *prev{nullptr};
  TokenInfo *next{nullptr};

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

  bool HasExpansion(void) const noexcept;

  bool is_va_args_concat{false};

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

  std::map<std::pair<const void *, size_t>, TokenInfo *> nth_file_token;
  std::unordered_map<const TokenInfo *, TokenInfo *> before_tokens;
  std::unordered_map<const TokenInfo *, TokenInfo *> after_tokens;

  // Backing storage for token info. Not necessarily all allocated tokens will
  // be used, but this is an upper bound on them. `deque` for pointer stability.
  std::deque<TokenInfo> tokens_alloc;

  // Backing storage for substitutions.
  std::deque<Substitution> substitutions_alloc;

  // Stack of substitutions associated with includes. When we exit a file, we
  // can set it as the `after` of the top substitution on this stack, then
  // pop it off.
  std::vector<Substitution *> includes;

  // Macro bodies.
  std::unordered_map<const void *, Substitution *> macro_body;

  D( std::string indent; )

  // Figure out if `node->after` looks like a macro argument pre-expansion of
  // `node`, and if so, return `node->after.before.front()`, i.e. the pre-
  // expansion use.
  Substitution *PreExpansionOf(Substitution *node);

  // Build an initial token info list. This contains all of the tokens that were
  // parsed, plus the file tokens that were macro uses. This does not contain
  // file tokens that were elided due to things like conditional macros, e.g.
  // `#if 0`.
  TokenInfo *BuildInitialTokenList(
      const std::optional<pasta::TokenRange> &range,
      const pasta::PrintedTokenRange &printed_range,
      std::ostream &err);

  TokenInfo *BuildParsedTokenList(
      const pasta::TokenRange &range,
      const pasta::PrintedTokenRange &printed_range,
      std::ostream &err);

  TokenInfo *BuildPrintedTokenList(
      const pasta::PrintedTokenRange &printed_range,
      std::ostream &err);

  Substitution *GetMacroBody(pasta::DefineMacroDirective def,
                             std::ostream &err);

  TokenInfo *NthTokenInFile(const pasta::File &file, size_t n);
  TokenInfo *TryGetBeforeToken(TokenInfo *curr);
  TokenInfo *TryGetAfterToken(TokenInfo *curr);
  void TryAddBeforeToken(Substitution *sub, TokenInfo *curr);
  void TryAddAfterToken(Substitution *sub, TokenInfo *prev);

  // Fill in the missing tokens from the token tree.
  void StripWhitespace(Substitution::NodeList &nodes);

  Substitution *MergeArguments(Substitution *orig, Substitution *pre_arg,
                               std::ostream &err);

  bool MergeArgPreExpansion(Substitution *sub, Substitution *pre_exp,
                            std::ostream &err);

  Substitution *BuildMacroSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      Substitution::NodeList &nodes, const pasta::MacroToken &node,
      std::ostream &err);

  Substitution *BuildMacroSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      Substitution::NodeList &nodes, const pasta::MacroArgument &node,
      std::ostream &err);

  Substitution *BuildMacroSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      Substitution::NodeList &nodes, const pasta::MacroVAOpt &node,
      std::ostream &err);

  Substitution *BuildMacroSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      Substitution::NodeList &nodes, const pasta::MacroVAOptArgument &node,
      std::ostream &err);

  Substitution *BuildMacroSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      Substitution::NodeList &nodes, const pasta::MacroParameter &node,
      std::ostream &err);

  Substitution *BuildMacroSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      Substitution::NodeList &nodes, const pasta::MacroSubstitution &node,
      std::ostream &err);

  Substitution *BuildMacroSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      Substitution::NodeList &nodes, const pasta::MacroExpansion &node,
      std::ostream &err);

  Substitution *BuildMacroSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      Substitution::NodeList &nodes, const pasta::MacroDirective &node,
      std::ostream &err);

  Substitution *BuildMacroSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      Substitution::NodeList &nodes,
      const pasta::Macro &node, std::ostream &err);

  Substitution *BuildMacroSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      std::ostream &err);

  Substitution *BuildFileSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      Substitution::NodeList &nodes, std::ostream &err);

  Substitution *BuildSubstitutions(TokenInfo *&prev, TokenInfo *&curr,
                                   Substitution *sub, std::ostream &err);

  Substitution *BuildSubstitutionsIter(TokenInfo *&prev, TokenInfo *&curr,
                                       std::ostream &err);

  Substitution *BuildSubstitutions(std::ostream &err);

  Substitution *CreateSubstitution(mx::MacroKind kind);
};

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

static bool InNodeList(const Substitution::NodeList &nodes, const void *elem) {
  for (const Substitution::Node &node : nodes) {
    if (std::holds_alternative<Substitution *>(node)) {
      if (std::get<Substitution *>(node) == elem) {
        return true;
      }
    } else if (std::holds_alternative<TokenInfo *>(node)) {
      if (std::get<TokenInfo *>(node) == elem) {
        return true;
      }
    }
  }
  return false;
}

template <typename T>
static std::string TokData(const T &tok) {
  switch (tok.Kind()) {
    case pasta::TokenKind::kComment:
      return "&lt;comment&gt;";
    case pasta::TokenKind::kUnknown:
      return "&lt;unk&gt;";
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
    }
  }

  for (Substitution::Node &node : sub->body) {
    if (std::holds_alternative<Substitution *>(node)) {
      Substitution *child_sub = std::get<Substitution *>(node);
      assert(child_sub != sub);
      child_sub->parent = sub;
    }
  }

  for (Substitution::Node &node : sub->after) {
    if (std::holds_alternative<Substitution *>(node)) {
      Substitution *child_sub = std::get<Substitution *>(node);
      assert(child_sub != sub);
      child_sub->parent = sub;
    }
  }
}

static TokenInfo *LeftCornerOfExp(const Substitution::NodeList &nodes);
static TokenInfo *LeftCornerOfExp(const Substitution::Node &node) {
  if (std::holds_alternative<TokenInfo *>(node)) {
    auto tok = std::get<TokenInfo *>(node);
    if (tok->category != TokenInfo::kMarkerToken) {
      return tok;
    }
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
    auto tok = std::get<TokenInfo *>(node);
    if (tok->category != TokenInfo::kMarkerToken) {
      return tok;
    }
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
    auto tok = std::get<TokenInfo *>(node);
    if (tok->category != TokenInfo::kMarkerToken) {
      return tok;
    }
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
    auto tok = std::get<TokenInfo *>(node);
    if (tok->category != TokenInfo::kMarkerToken) {
      return tok;
    }
  } else if (auto sub = std::get<Substitution *>(node)) {
    return RightCornerOfUse(sub->before);
  }
  return nullptr;
}

TokenInfo *RightCornerOfUse(const Substitution::NodeList &nodes) {
  auto it = nodes.rbegin();
  auto end = nodes.rend();
  for (; it != end; ++it) {
    const Substitution::Node &node = *it;
    if (auto rc = RightCornerOfUse(node)) {
      return rc;
    }
  }
  return nullptr;
}

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
      assert(after.empty());
      return false;

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

static TokenInfo *RightCornerOfExpansionOrUse(
    const Substitution::NodeList &nodes);
static TokenInfo *RightCornerOfExpansionOrUse(const Substitution::Node &node) {
  if (std::holds_alternative<TokenInfo *>(node)) {
    auto tok = std::get<TokenInfo *>(node);
    if (tok->category != TokenInfo::kMarkerToken) {
      return tok;
    }
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
    const Substitution::Node &node = *it;
    if (auto rc = RightCornerOfExpansionOrUse(node)) {
      return rc;
    }
  }
  return nullptr;
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
  if (before.empty()) {
//    TT_ASSERT(!after);
  }

  auto tok_data = [] (TokenInfo *info) -> std::string_view {
    std::string_view a, b, c;
    if (info->parsed_tok) {
      a = info->parsed_tok->Data();
    }
    if (info->macro_tok) {
      b = info->macro_tok->Data();
    }
    if (info->file_tok) {
      c = info->file_tok->Data();
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
      TT_ASSERT(false);
      return {};
    }
  };

  for (const Substitution::Node &ent : before) {
    if (std::holds_alternative<TokenInfo *>(ent)) {
      TokenInfo *info = std::get<TokenInfo *>(ent);
      switch (info->category) {
        case TokenInfo::kFileToken:
          std::cerr << tok_data(info);
          continue;
        case TokenInfo::kMacroUseToken:
        case TokenInfo::kMissingFileToken:
        case TokenInfo::kMacroStepToken:
        case TokenInfo::kMacroExpansionToken:
        case TokenInfo::kMarkerToken:
          std::cerr << "\033[4m" << tok_data(info) << "\033[0m";
          continue;
        default:
          continue;
      }
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
    if (info->file_tok) {
      os << "<TR><TD>FK=" << info->file_tok->KindName() << "</TD></TR>";
    }
    if (info->macro_tok) {
      os << "<TR><TD>MK=" << info->macro_tok->TokenKindName() << "</TD></TR>";
    }
    if (info->parsed_tok) {
      os << "<TR><TD>PK=" << info->parsed_tok->KindName() << "</TD></TR>";
      os << "<TR><TD>PI=" << info->parsed_tok->Index() << "</TD></TR>";
    }
    if (info->file_tok) {
      os << "<TR><TD>FI=" << info->file_tok->Index() << "</TD></TR>";
    }

    if (info->parsed_tok) {
      os << "<TR><TD><B>" << TokData(info->parsed_tok.value())
         << "</B></TD></TR>";
    } else if (info->file_tok) {
      os << "<TR><TD><B>" << TokData(info->file_tok.value())
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
        TokenInfo *info = std::get<TokenInfo *>(ent);
        switch (info->category) {
          case TokenInfo::kFileToken:
          case TokenInfo::kMacroUseToken:
          case TokenInfo::kMissingFileToken:
          case TokenInfo::kMacroStepToken:
          case TokenInfo::kMacroExpansionToken:
            dump_tok(info);
            continue;
          case TokenInfo::kMarkerToken:
          default:
            continue;
        }
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
       << "><TR><TD colspan=\"2\">" << mx::EnumeratorName(kind);

    if (is_va_args_concat) {
      os << " va_args";
    }

    os << "</TD></TR><TR><TD port=\"before\">before</TD><TD port=\"after\">"
       << "after</TD></TR></TABLE>>];\n";

    if (before.size()) {
      os << "s" << self << ":before -> b" << self << ";\n"
         << "b" << self
         << " [label=<<TABLE cellpadding=\"0\" cellspacing=\"0\" border=\"1\"";
      if (before.has_error) {
        os << " bgcolor=\"red\"";
      }
      os << "><TR>";
      if (before.prev && before.prev->file_tok) {
        os << "<TD>" << before.prev->file_tok->Index() << "</TD>";
      }

      has_any = false;

      dump_toks(before);

      if (before.next && before.next->file_tok) {
        os << "<TD>" << before.next->file_tok->Index() << "</TD>";
      }

      os << "</TR></TABLE>>];\n";

      link_subs(before, "b");
    }

    if (after.size()) {
      os << "s" << self << ":after -> a" << self << ";\n"
         << "a" << self
         << " [label=<<TABLE cellpadding=\"0\" cellspacing=\"0\" border=\"1\"";
      if (after.has_error) {
        os << " bgcolor=\"red\"";
      }
      os << "><TR>";
      if (after.prev && after.prev->file_tok) {
        os << "<TD>" << after.prev->file_tok->Index() << "</TD>";
      }

      has_any = false;

      dump_toks(after);

      if (after.next && after.next->file_tok) {
        os << "<TD>" << after.next->file_tok->Index() << "</TD>";
      }

      os << "</TR></TABLE>>];\n";

      link_subs(after, "a");
    }

  // No expansion.
  } else {
    auto num_cols = before.size();
    if (before.prev && before.prev->file_tok) {
      ++num_cols;
    }
    if (before.next && before.next->file_tok) {
      ++num_cols;
    }

    os << "s" << self
       << " [label=<<TABLE cellpadding=\"0\" cellspacing=\"0\" border=\"1\"";
    if (before.has_error) {
      os << " bgcolor=\"red\"";
    }
    os << "><TR><TD colspan=\"" << num_cols << "\">"
       << mx::EnumeratorName(kind);

    if (is_va_args_concat) {
      os << " va_args";
    }

    os << "</TD></TR><TR>";

    if (before.prev && before.prev->file_tok) {
      os << "<TD>" << before.prev->file_tok->Index() << "</TD>";
    }

    dump_toks(before);

    if (!has_any && !num_cols) {
      os << "<TD> </TD>";
    }

    if (before.next && before.next->file_tok) {
      os << "<TD>" << before.next->file_tok->Index() << "</TD>";
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
TokenInfo *TokenTreeImpl::BuildInitialTokenList(
    const std::optional<pasta::TokenRange> &range,
    const pasta::PrintedTokenRange &printed_range,
    std::ostream &err) {

  if (range.has_value()) {
    return BuildParsedTokenList(range.value(), printed_range, err);

  } else if (printed_range) {
    return BuildPrintedTokenList(printed_range, err);

  } else {
    err << "Empty parsed and printed token ranges.";
    return nullptr;
  }
}

TokenInfo *TokenTreeImpl::BuildPrintedTokenList(
    const pasta::PrintedTokenRange &range, std::ostream &err) {

  for (pasta::PrintedToken tok : range) {
    
    TokenInfo &info = tokens_alloc.emplace_back();
    info.printed_tok = tok;
    info.category = TokenInfo::kFileToken;
    info.parsed_tok = tok.DerivedLocation();

    if (info.parsed_tok) {
      info.file_tok = info.parsed_tok->FileLocation();

      if (info.file_tok) {
        nth_file_token.emplace(
            std::make_pair(info.file_tok->RawFile(), info.file_tok->Index()),
            &info);
      }
    }
  }

  // Link all of the tokens together.
  if (auto num_toks = tokens_alloc.size()) {
    for (auto i = 1ull, j = 0ull; i < num_toks; ++i, ++j) {
      tokens_alloc[j].next = &(tokens_alloc[i]);
    }

    return &(tokens_alloc.front());
  }

  err << "Cannot create token tree from empty token range";
  return nullptr;
}

TokenInfo *TokenTreeImpl::BuildParsedTokenList(
    const pasta::TokenRange &range,
    const pasta::PrintedTokenRange &printed_range,
    std::ostream &err) {

  TokenInfo *last_macro_use_token = nullptr;

  size_t next_printed_tok = 1u;
  std::optional<pasta::PrintedToken> npt = printed_range.At(0);

  for (pasta::Token tok : range) {
    TokenInfo &info = tokens_alloc.emplace_back();
    info.file_tok = tok.FileLocation();
    info.macro_tok = tok.MacroLocation();
    info.parsed_tok = tok;

    if (info.file_tok) {
      nth_file_token.emplace(
          std::make_pair(info.file_tok->RawFile(), info.file_tok->Index()),
          &info);
    }

    // Match up the parsed token with a printed token.
    const auto pti = tok.Index();
    const bool is_parsed_tok = IsParsedToken(tok);
    while (is_parsed_tok && !info.printed_tok.has_value() && npt.has_value()) {

      if (auto npt_pt = npt->DerivedLocation()) {
        auto npt_pti = npt_pt->Index();
        if (npt_pti == pti) {
          info.printed_tok = std::move(npt);

        } else if (npt_pti > pti) {
          break;
        }
      }

      npt.reset();
      npt = printed_range.At(next_printed_tok++);
    }

    switch (tok.Role()) {
      default:
      case pasta::TokenRole::kInvalid:
        err << "Invalid or unexpected token in range";
        return nullptr;

      case pasta::TokenRole::kBeginOfMacroExpansionMarker: {
        assert(!is_parsed_tok);
        assert(!last_macro_use_token);
        assert(tok.FileLocation().has_value());
        info.category = TokenInfo::kMarkerToken;
        last_macro_use_token = &info;
        break;
      }

      case pasta::TokenRole::kEndOfMacroExpansionMarker: {
        assert(!is_parsed_tok);
        assert(last_macro_use_token != nullptr);
        pasta::File file = pasta::File::Containing(
            last_macro_use_token->file_tok.value());
        info.file_tok = file.Tokens().At(
            last_macro_use_token->file_tok->Index() + 1u);
        info.category = TokenInfo::kMarkerToken;
        last_macro_use_token = nullptr;
        break;
      }

      case pasta::TokenRole::kInitialMacroUseToken: {
        assert(!is_parsed_tok);
        info.category = TokenInfo::kMacroUseToken;
        assert(info.file_tok.has_value());
        assert(info.macro_tok.has_value());
        last_macro_use_token = &info;
        break;
      }

      case pasta::TokenRole::kIntermediateMacroExpansionToken: {
        assert(!is_parsed_tok);
        assert(last_macro_use_token != nullptr);
        info.category = TokenInfo::kMacroStepToken;
        assert(info.macro_tok.has_value());
        break;
      }

      case pasta::TokenRole::kFinalMacroExpansionToken: {
        assert(last_macro_use_token != nullptr);
        assert(info.macro_tok.has_value());
        info.category = TokenInfo::kMacroExpansionToken;
        break;
      }

      case pasta::TokenRole::kBeginOfFileMarker:
      case pasta::TokenRole::kEndOfFileMarker: {
        assert(!last_macro_use_token);
        assert(tok.FileLocation().has_value());
        info.category = TokenInfo::kMarkerToken;
        break;
      }

      case pasta::TokenRole::kFileToken: {
        assert(!last_macro_use_token);
        assert(info.file_tok.has_value());
        assert(info.file_tok->Data() == tok.Data());
        info.category = TokenInfo::kFileToken;
        break;
      }

      case pasta::TokenRole::kEndOfInternalMacroEventMarker: {
        assert(!is_parsed_tok);
        assert(last_macro_use_token);
        info.category = TokenInfo::kMarkerToken;
        break;
      }
    }
  }

  // Link all of the tokens together.
  if (auto num_toks = tokens_alloc.size()) {
    for (auto i = 1ull, j = 0ull; i < num_toks; ++i, ++j) {
      tokens_alloc[j].next = &(tokens_alloc[i]);
    }

    return &(tokens_alloc.front());
  }

  err << "Cannot create token tree from empty token range";
  return nullptr;
}

Substitution *TokenTreeImpl::CreateSubstitution(mx::MacroKind kind_) {
  return &(substitutions_alloc.emplace_back(kind_));
}

static pasta::Macro RootNodeFrom(const pasta::Macro &node) {
  
  // NOTE(pag): We extract macro directives into their own (nested) fragments,
  //            even if they are logically nested within a macro use.
  if (ShouldGoInNestedFragment(node)) {
    return node;
  
  } else if (auto parent = node.Parent()) {
    return RootNodeFrom(parent.value());
  } else {
    return node;
  }
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
    new_nodes.prev = sub->before.prev;
    new_nodes.next = sub->before.next;

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

  D( std::cerr << indent << "Merge pre expansion\n"; )
  D( indent += "  "; )

  // Make sure we calculate the pre-expansion correctly.
  assert(1u <= sub->after.size());
  assert(std::holds_alternative<Substitution *>(sub->after.front()));
  assert(std::get<Substitution *>(sub->after.front()) == pre_exp);
  assert(sub->kind == mx::MacroKind::EXPANSION);
  assert(pre_exp->kind == mx::MacroKind::EXPANSION);

  Substitution::NodeList new_nodes;
  new_nodes.prev = sub->before.prev;
  new_nodes.next = sub->before.next;

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
          << " orig_arg=" << (!!orig_arg) << " preexp_arg=" << (!!preexp_arg);

      if (orig_rc && orig_rc->file_tok) {
        std::cerr << " orig_rc=" << orig_rc->file_tok->Data();
      }

      if (preexp_lc && preexp_lc->file_tok) {
        std::cerr << " preexp_lc=" << preexp_lc->file_tok->Data();
      }

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
        orig_rc->parsed_tok->Data() == preexp_lc->parsed_tok->Data()) {

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

  TokenInfo *prev = nullptr;
  Substitution *&body = macro_body[def.RawMacro()];
  if (body) {
    return body;
  }

  D( indent += "  "; )

  auto maybe_name = def.Name();
  if (!maybe_name) {
    err << "Macro has no name";
    return nullptr;
  }

  pasta::MacroToken name = std::move(maybe_name.value());
  body = CreateSubstitution(mx::MacroKind::DEFINE_DIRECTIVE);
  body->macro = def;

  for (pasta::Macro node : def.Body()) {
    std::optional<pasta::MacroToken> tok = pasta::MacroToken::From(node);
    if (!tok) {
      continue;
    }

    D( std::cerr << indent << "body token: " << tok->Data() << '\n'; )

    pasta::TokenKind tok_kind = tok->TokenKind();
    TokenInfo &info = tokens_alloc.emplace_back();
    info.file_tok = tok->FileLocation();
    info.parsed_tok = tok->ParsedLocation();
    info.macro_tok = std::move(tok);
    info.category = TokenInfo::kMissingFileToken;

    switch (tok_kind) {
      case pasta::TokenKind::kEndOfFile:
      case pasta::TokenKind::kEndOfDirective:
        continue;
      default:
        if (info.file_tok.has_value()) {
          if (prev) {
            prev->next = &info;
          }
          prev = &info;
          body->before.emplace_back(&info);
        }
        break;
    }
  }

  StripWhitespace(body->before);

  D( indent.resize(indent.size()  - 2u); )
  (void)err;
  return body;
}


TokenInfo *TokenTreeImpl::NthTokenInFile(const pasta::File &file, size_t n) {

  TokenInfo *&ti = nth_file_token[std::make_pair(file.RawFile(), n)];
  if (ti) {
    return ti;
  }

  std::optional<pasta::FileToken> tok = file.Tokens().At(n);
  if (!tok) {
    return nullptr;
  }

  ti = &(tokens_alloc.emplace_back());
  ti->file_tok = std::move(tok);
  ti->category = TokenInfo::kMissingFileToken;
  return ti;
}

TokenInfo *TokenTreeImpl::TryGetBeforeToken(TokenInfo *curr) {
  if (!curr || !curr->file_tok) {
    return nullptr;
  }

  TokenInfo *&before_tok = before_tokens[curr];
  if (before_tok) {
    return before_tok;
  }

  auto index = curr->file_tok->Index();
  if (!index) {
    before_tok = curr;
    return curr;  // Not exclusive, but there's nothing before it so oh well.
  }

  pasta::File file = pasta::File::Containing(curr->file_tok.value());
  before_tok = NthTokenInFile(file, index - 1u);
  return before_tok;
}

TokenInfo *TokenTreeImpl::TryGetAfterToken(TokenInfo *curr) {
  if (!curr || !curr->file_tok) {
    return nullptr;
  }

  TokenInfo *&after_tok = after_tokens[curr];
  if (after_tok) {
    return after_tok;
  }

  auto index = curr->file_tok->Index();
  pasta::File file = pasta::File::Containing(curr->file_tok.value());
  after_tok = NthTokenInFile(file, index + 1u);
  if (!after_tok) {
    after_tok = curr;
  }

  return after_tok;
}

void TokenTreeImpl::TryAddBeforeToken(Substitution *sub, TokenInfo *curr) {
  if (sub->before.prev) {
    return;
  } else {
    sub->before.prev = TryGetBeforeToken(curr);
  }
}

void TokenTreeImpl::TryAddAfterToken(Substitution *sub, TokenInfo *prev) {
  if (sub->before.next) {
    return;
  } else {
    sub->before.next = TryGetAfterToken(prev);
  }
}

// Get rid of leading and trailing whitespace in all internal nodes.
void TokenTreeImpl::StripWhitespace(Substitution::NodeList &nodes) {

  auto remove_ws = [&nodes D(, this)] (void) {
    while (!nodes.empty()) {
      if (!std::holds_alternative<TokenInfo *>(nodes.back())) {
        break;
      }

      auto tok = std::get<TokenInfo *>(nodes.back());
      pasta::TokenKind tk = pasta::TokenKind::kIdentifier;  // Anything.
      if (tok->macro_tok) {
        tk = tok->macro_tok->TokenKind();
      } else if (tok->file_tok) {
        tk = tok->file_tok->Kind();
      }

      if (tk == pasta::TokenKind::kUnknown ||
          tk == pasta::TokenKind::kEndOfDirective ||
          tk == pasta::TokenKind::kEndOfFile) {
        D( std::cerr << indent << "Stripping whitespace token\n"; )
        nodes.pop_back();
      } else {
        break;
      }
    }
  };

  remove_ws();
  std::reverse(nodes.begin(), nodes.end());
  remove_ws();
  std::reverse(nodes.begin(), nodes.end());
}

const void *ContainingMacroDef(Substitution *child) {
  for (auto parent = child->parent; parent;
       child = parent, parent = parent->parent) {
    if (parent->kind == mx::MacroKind::EXPANSION) {
      if (InNodeList(parent->after, child)) {
        auto exp = pasta::MacroExpansion::From(parent->macro.value());
        auto def = exp->Definition();
        if (def) {
          return def->RawMacro();
        } else {
          break;
        }
      }
    }
  }
  return nullptr;
}

const void *ContainingMacroUse(Substitution *child) {
  for (auto parent = child->parent; parent;
     child = parent, parent = parent->parent) {
    if (parent->kind == mx::MacroKind::EXPANSION) {
      if (InNodeList(parent->before, child)) {
        return parent->macro->RawMacro();
      }
    }
  }
  return nullptr;
}

Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    Substitution::NodeList &nodes, const pasta::MacroToken &node,
    std::ostream &err) {

  // We may have filled in missing file tokens between macro use tokens, which
  // have file location information.
  for (; curr; prev = curr, curr = curr->next) {
    if (curr->category == TokenInfo::kMissingFileToken) {
      nodes.emplace_back(curr);

    } else if (curr->category == TokenInfo::kMarkerToken &&
               (curr->parsed_tok->Role() ==
                   pasta::TokenRole::kEndOfInternalMacroEventMarker)) {
      prev = curr;
      curr = curr->next;
      return sub;

    } else if (curr->macro_tok) {
      break;

    } else {
      assert(false);
      err << "Found an unusual token";
      return nullptr;
    }
  }

  // Walked off the end of the list. Probably because the root macro is
  // actually a directive, and so we're dealing with a token range that
  // doesn't have our begin/end macro markers.
  if (!curr) {
    return sub;
  }

  if (!curr->macro_tok) {
    assert(false);
    err << "Failed to find the next macro token";
    return nullptr;
  }

  nodes.emplace_back(curr);

  // Can happen when trying to align an argument containing conditional
  // directives in the use with pre-expansion form that doesn't have the
  // conditional directives.
  if (curr->macro_tok->RawMacro() != node.RawMacro()) {
    assert(false);
    nodes.has_error = true;
    has_error = true;
  }

  // Skip to the next token for the caller.
  prev = curr;
  curr = curr->next;
  return sub;
}

Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    Substitution::NodeList &nodes, const pasta::MacroArgument &node,
    std::ostream &err) {

  Substitution *arg_sub = CreateSubstitution(mx::FromPasta(node.Kind()));
  arg_sub->parent = sub;
  arg_sub->macro = node;
  nodes.emplace_back(arg_sub);

  Substitution *sub_exp = arg_sub;
  for (const pasta::Macro &arg_node : node.Children()) {
    sub_exp = BuildMacroSubstitutions(
        prev, curr, arg_sub, arg_sub->before, arg_node, err);
    if (!arg_sub) {
      return nullptr;
    }
    assert(sub_exp == arg_sub);
  }
  (void) sub_exp;

  return sub;
}

Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    Substitution::NodeList &nodes, const pasta::MacroVAOpt &node,
    std::ostream &err) {

  Substitution *arg_sub = CreateSubstitution(mx::FromPasta(node.Kind()));
  assert(sub->kind == mx::MacroKind::EXPANSION ||
         sub->kind == mx::MacroKind::STRINGIFY);
  arg_sub->parent = sub;
  arg_sub->macro = node;
  nodes.emplace_back(arg_sub);

  Substitution *sub_exp = arg_sub;
  for (const pasta::Macro &arg_node : node.Children()) {
    sub_exp = BuildMacroSubstitutions(
        prev, curr, arg_sub, arg_sub->before, arg_node, err);
    if (!arg_sub) {
      return nullptr;
    }
    assert(sub_exp == arg_sub);
  }
  (void) sub_exp;
  return sub;
}

Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    Substitution::NodeList &nodes, const pasta::MacroVAOptArgument &node,
    std::ostream &err) {

  Substitution *arg_sub = CreateSubstitution(mx::FromPasta(node.Kind()));
  assert(sub->kind == mx::MacroKind::VA_OPT);
  arg_sub->parent = sub;
  arg_sub->macro = node;
  nodes.emplace_back(arg_sub);

  Substitution *sub_exp = arg_sub;
  for (const pasta::Macro &arg_node : node.Children()) {
    sub_exp = BuildMacroSubstitutions(
        prev, curr, arg_sub, arg_sub->before, arg_node, err);
    if (!arg_sub) {
      return nullptr;
    }
    assert(sub_exp == arg_sub);
  }
  (void) sub_exp;
  return sub;
}

Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    Substitution::NodeList &nodes, const pasta::MacroParameter &node,
    std::ostream &err) {

  Substitution *arg_sub = CreateSubstitution(mx::FromPasta(node.Kind()));
  assert(sub->kind == mx::MacroKind::DEFINE_DIRECTIVE);
  arg_sub->parent = sub;
  arg_sub->macro = node;
  nodes.emplace_back(arg_sub);

  Substitution *sub_exp = arg_sub;
  for (const pasta::Macro &arg_node : node.Children()) {
    sub_exp = BuildMacroSubstitutions(
        prev, curr, arg_sub, arg_sub->before, arg_node, err);
    if (!sub_exp) {
      return nullptr;
    }
    assert(sub_exp == arg_sub);
  }
  return sub;
}

Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    Substitution::NodeList &nodes, const pasta::MacroSubstitution &node,
    std::ostream &err) {

  Substitution *exp = CreateSubstitution(mx::FromPasta(node.Kind()));
  exp->parent = sub;
  exp->macro = node;
  nodes.emplace_back(exp);

  Substitution *sub_exp = exp;
  for (const pasta::Macro &use_node : node.Children()) {
    sub_exp = BuildMacroSubstitutions(
        prev, curr, exp, exp->before, use_node, err);
    if (!sub_exp) {
      return nullptr;
    }
    assert(sub_exp == exp);
  }

  for (const pasta::Macro &sub_node : node.ReplacementChildren()) {
    sub_exp = BuildMacroSubstitutions(
        prev, curr, exp, exp->after, sub_node, err);
    if (!sub_exp) {
      return nullptr;
    }
    assert(sub_exp == exp);
  }

  return sub;
}

Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    Substitution::NodeList &nodes, const pasta::MacroExpansion &node,
    std::ostream &err) {

  Substitution *exp = CreateSubstitution(mx::FromPasta(node.Kind()));
  assert(exp->kind == mx::MacroKind::EXPANSION);

  exp->parent = sub;
  exp->macro = node;
  nodes.emplace_back(exp);

  Substitution *sub_exp = exp;
  for (pasta::Macro use_node : node.Children()) {
    sub_exp = BuildMacroSubstitutions(
        prev, curr, exp, exp->before, use_node, err);
    if (!sub_exp) {
      return nullptr;
    }
    assert(sub_exp == exp);
  }

  for (pasta::Macro sub_node : node.IntermediateChildren()) {
    if (auto sub_node_parent = sub_node.Parent();
        !sub_node_parent ||
        sub_node_parent->RawMacro() != node.RawMacro()) {
      break;  // This is from the body of a macro definition.
    }

    auto sub_body = BuildMacroSubstitutions(
        prev, curr, exp, exp->body, sub_node, err);
    if (!sub_body) {
      return nullptr;
    }
    assert(sub_body == exp);
  }


  for (pasta::Macro sub_node : node.ReplacementChildren()) {
    sub_exp = BuildMacroSubstitutions(
        prev, curr, exp, exp->after, sub_node, err);
    if (!sub_exp) {
      return nullptr;
    }
    assert(sub_exp == exp);
  }

  std::optional<pasta::DefineMacroDirective> macro_def = node.Definition();
  if (!macro_def) {
    return sub;
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
    return nullptr;
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
      return nullptr;
    }

    assert(exp->body.empty());
    exp->body = std::move(pre_exp->body);
    assert(!PreExpansionOf(exp));

    FixupNodeParents(exp);
  }

  exp->after.prev = macro_body_sub->before.prev;
  exp->after.next = macro_body_sub->before.next;

  return sub;
}

Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    Substitution::NodeList &nodes, const pasta::MacroDirective &node,
    std::ostream &err) {

  Substitution *dir = CreateSubstitution(mx::FromPasta(node.Kind()));
  nodes.emplace_back(dir);
  dir->parent = sub;
  dir->macro = node;

  Substitution *sub_exp = dir;
  for (const pasta::Macro &use_node : node.Children()) {
    sub_exp = BuildMacroSubstitutions(
        prev, curr, dir, dir->before, use_node, err);
    if (!sub_exp) {
      return nullptr;
    }
    assert(sub_exp == dir);
  }

  return sub;
}

Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    Substitution::NodeList &nodes, const pasta::Macro &node,
    std::ostream &err) {
  switch (node.Kind()) {
    case pasta::MacroKind::kToken:
      return BuildMacroSubstitutions(
          prev, curr, sub, nodes, pasta::MacroToken::From(node).value(), err);
    case pasta::MacroKind::kArgument:
      return BuildMacroSubstitutions(
          prev, curr, sub, nodes, pasta::MacroArgument::From(node).value(),
          err);
    case pasta::MacroKind::kParameter:
      return BuildMacroSubstitutions(
          prev, curr, sub, nodes, pasta::MacroParameter::From(node).value(),
          err);
    case pasta::MacroKind::kExpansion:
      return BuildMacroSubstitutions(
          prev, curr, sub, nodes, pasta::MacroExpansion::From(node).value(),
          err);
    case pasta::MacroKind::kVAOpt:
      return BuildMacroSubstitutions(
          prev, curr, sub, nodes, pasta::MacroVAOpt::From(node).value(),
          err);
    case pasta::MacroKind::kVAOptArgument:
      return BuildMacroSubstitutions(
          prev, curr, sub, nodes, pasta::MacroVAOptArgument::From(node).value(),
          err);
    case pasta::MacroKind::kSubstitution:
    case pasta::MacroKind::kParameterSubstitution:
    case pasta::MacroKind::kStringify:
    case pasta::MacroKind::kConcatenate:
      return BuildMacroSubstitutions(
          prev, curr, sub, nodes, pasta::MacroSubstitution::From(node).value(),
          err);
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
      return BuildMacroSubstitutions(
          prev, curr, sub, nodes, pasta::MacroDirective::From(node).value(),
          err);
  }
  err << "Unexpected/unsupported substitution kind";
  return nullptr;
}

// Starting with the left corner of the macro substitutions, build the macro
// uses bottom-up, working our way up to the root node.
Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    std::ostream &err) {

  TokenInfo *old_curr = curr;

  // Skip the marker token.
  DCHECK(curr->parsed_tok->Role() ==
         pasta::TokenRole::kBeginOfMacroExpansionMarker);
  prev = curr;
  curr = curr->next;

  TT_ASSERT(old_curr->file_tok.has_value());
  TT_ASSERT(curr != nullptr);

  // NOTE(pag): In cURL, there is a `#` as the first token of a file, so we
  //            can't rely on `prev` being a file token, as in that case it
  //            would be a marker token.

  // Go find the first macro use token, which will be the left corner of our
  // macro expansion tree, and this will lead us to the root of the macro node.
  TokenInfo *use = curr;
  for (; use && use->category != TokenInfo::kMacroUseToken; use = use->next) {
    DCHECK(!use->parsed_tok);
    DCHECK(!use->parsed_tok->MacroLocation());
  }

  if (!use) {
    err << "Could not find first macro use token";
    return nullptr;
  }

  if (!use->macro_tok) {
    err << "First macro use token does not have a macro location";
    return nullptr;
  }

  Substitution *sub_exp = sub;
  sub = BuildMacroSubstitutions(
      prev, curr, sub, sub->before, RootNodeFrom(use->macro_tok.value()), err);
  if (!sub) {
    return nullptr;
  }

  assert(sub == sub_exp);
  (void) sub_exp;

  if (!curr || curr->category != TokenInfo::kMarkerToken) {
    sub->before.has_error = true;
    Die(this);
    err << "Expected a marker token at the end of macro expansion";
    return nullptr;
  }

  if (curr->parsed_tok->Role() !=
          pasta::TokenRole::kEndOfMacroExpansionMarker) {
    err << "Expected a macro expansion ending marker token at the end "
           "of macro expansion";
    return nullptr;
  }

  // Skip the marker.
  prev = curr;
  curr = curr->next;
  return sub;
}

Substitution *TokenTreeImpl::BuildFileSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    Substitution::NodeList &nodes, std::ostream &err) {

  TokenInfo * const first_tok = curr;

  // Skip the beginning marker.
  DCHECK(curr->parsed_tok->Role() == pasta::TokenRole::kBeginOfFileMarker);
  prev = curr;
  curr = curr->next;

  // Recursively call the top-level builder starting with the first token
  // in the included file.

  Substitution *file_sub = CreateSubstitution(mx::MacroKind::OTHER_DIRECTIVE);
  Substitution *file_sub_exp = BuildSubstitutions(prev, curr, file_sub, err);
  if (!file_sub) {
    return nullptr;
  }

  assert(file_sub == file_sub_exp);
  (void) file_sub_exp;

  // Go add this file substitution to the previous inclusion directive.
  if (sub->before.empty() ||
      !std::holds_alternative<Substitution *>(nodes.back())) {
    err << "The last thing in the current substitution "
           "should be a substitution";
    return nullptr;
  }

  Substitution *include_sub = std::get<Substitution *>(nodes.back());
  switch (include_sub->kind) {
    case mx::MacroKind::INCLUDE_DIRECTIVE:
    case mx::MacroKind::INCLUDE_MACROS_DIRECTIVE:
    case mx::MacroKind::INCLUDE_NEXT_DIRECTIVE:
    case mx::MacroKind::IMPORT_DIRECTIVE:
      assert(include_sub->after.empty());
      break;
    default:
      err << "The last thing in the current substitution "
             "should be an inclusion";
      return nullptr;
  }

  nodes.pop_back();
  nodes.emplace_back(file_sub);
  file_sub->parent = include_sub->parent;
  file_sub->kind = mx::MacroKind::SUBSTITUTION;
  file_sub->after = std::move(file_sub->before);

  file_sub->before.emplace_back(include_sub);
  file_sub->before.prev = include_sub->before.prev;
  file_sub->before.next = include_sub->before.next;

  include_sub->parent = file_sub;
  FixupNodeParents(file_sub);

  // Make sure that we're at the end of a file.
  if (!curr || curr->category != TokenInfo::kMarkerToken) {
    err << "Expected a marker token at the end of file";
    if (curr) {
      err << " (PTI " << curr->parsed_tok->Index() << ')';
    } else if (prev) {
      err << " (prev PTI " << prev->parsed_tok->Index() << ')';
    }
    return nullptr;
  }

  if (curr->parsed_tok->Role() != pasta::TokenRole::kEndOfFileMarker) {
    err << "Expected a file ending marker token at the end of a file (PTI "
        << curr->parsed_tok->Index() << ')';
    return nullptr;
  }

  file_sub->after.prev = TryGetBeforeToken(first_tok);
  file_sub->after.next = TryGetAfterToken(prev);

  // Skip the marker.
  prev = curr;
  curr = curr->next;

  return sub;
}

// Iteratively build out substitutions. We might cross file boundaries here.
//
// This happens in the Linux kernel with `drbd_genl_cmd_to_str` that has
// an attribute in one file but the rest of the function in another file. This
// entity is produced by macro expansion of
//
//        CONCAT_(GENL_MAGIC_FAMILY, _genl_cmd_to_str)
//
// in the x-macro file `include/linux/genl_magic_func.h`, where the attribute
// is the last thing in a macro expansion of `GENL_struct` in the same file.
//
// What happens is that we end up having unbalanced begin/end file marker
// tokens.
//
// XREF(pag):
// https://github.com/trailofbits/multiplier/issues/258#issuecomment-1401170794
Substitution *TokenTreeImpl::BuildSubstitutionsIter(
    TokenInfo *&prev, TokenInfo *&curr, std::ostream &err) {

  Substitution *sub = CreateSubstitution(mx::MacroKind::OTHER_DIRECTIVE);
  for (;;) {
    Substitution *sub_exp = BuildSubstitutions(prev, curr, sub, err);
    if (!sub_exp) {
      return nullptr;
    }

    assert(sub_exp == sub);
    if (!curr) {
      return sub;
    }

    // An end of file that doesn't have any matching begin of file; accumulate
    // into the top-level. In theory we should accumulate an `#include` above
    // `sub`, and do a kind of recursive ascent constuction of the tree. In
    // practice, we don't expect to hit this situation, and we try to mitigate
    // the issue of unbalanced BOF/EOF tokens in `IndexCompileJob.cpp` by
    // identifying when decls include `EOF` markers, and then expanding their
    // ranges to contain the associated `#include` directive.
    if (curr->parsed_tok &&
        curr->parsed_tok->Role() == pasta::TokenRole::kEndOfFileMarker) {
      prev = curr;
      curr = curr->next;
      continue;
    }

    err << "Unexpected top-level token could not be contained by token tree";
    return nullptr;
  }

  return sub;
}

Substitution *TokenTreeImpl::BuildSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub, std::ostream &err) {

  Substitution * const sub_exp = sub;
  while (curr) {
    switch (curr->category) {
      // Basic case: just add the token in.
      case TokenInfo::kFileToken:
      case TokenInfo::kMissingFileToken:
        TryAddBeforeToken(sub, curr);
        sub->before.emplace_back(curr);
        prev = curr;
        curr = curr->next;
        continue;

      // Inside of a macro expansion region; this shoudln't happen.
      case TokenInfo::kMacroStepToken:
      case TokenInfo::kMacroExpansionToken:
        sub->before.has_error = true;
        Die(this);
        err << "Macro step/expansion tokens should not be seen here";
        return nullptr;

      // If we're here then it means we're probably in a directive that's been
      // pulled out of its (parent) fragment.
      case TokenInfo::kMacroUseToken:
        if (substitutions_alloc.size() == 1u && curr->macro_tok) {
          pasta::Macro root_macro = RootNodeFrom(curr->macro_tok.value());
          if (auto dir = pasta::MacroDirective::From(root_macro)) {
            TryAddBeforeToken(sub, curr);
            return BuildMacroSubstitutions(
                prev, curr, sub, sub->before, dir.value(), err);
          }
        }
        sub->before.has_error = true;
        Die(this);
        err << "Macro use tokens should not be seen here";
        return nullptr;

      // At a marker token.
      case TokenInfo::kMarkerToken:
        TryAddBeforeToken(sub, curr);

        switch (curr->parsed_tok->Role()) {
          case pasta::TokenRole::kBeginOfFileMarker:
            sub = BuildFileSubstitutions(prev, curr, sub, sub->before, err);
            if (!sub) {
              return nullptr;
            }

            assert(sub_exp == sub);
            (void) sub_exp;
            continue;

          // Return to our caller, don't adjust the bounds. This is the end of
          // the recursive case of us seeing a begin/end of file marker after
          // seeing an include-like macro directive.
          case pasta::TokenRole::kEndOfFileMarker:
            return sub;

          case pasta::TokenRole::kBeginOfMacroExpansionMarker:
            sub = BuildMacroSubstitutions(prev, curr, sub, err);
            if (!sub) {
              return nullptr;
            }

            assert(sub_exp == sub);
            (void) sub_exp;

            continue;

          default:
            err << "Should not see this marker here";
            return nullptr;
        }
        break;
    }
  }

  if (prev) {
    if (prev->category != TokenInfo::kMarkerToken) {
      TryAddAfterToken(sub, prev);
    }
  }

  return sub;
}

// Build the initial tree of substitutions.
Substitution *TokenTreeImpl::BuildSubstitutions(std::ostream &err) {
  std::vector<Substitution *> subs;

  TokenInfo *prev = nullptr;
  TokenInfo * const first = &(tokens_alloc.front());
  TokenInfo *curr = first;  // NOTE(pag): Updated by reference.
  auto sub = BuildSubstitutionsIter(prev, curr, err);
  if (!sub) {
    return nullptr;
  }

  return sub;
}

TokenTree::~TokenTree(void) {}

// Create a token tree from the tokens in the inclusive range
// `[begin_index, end_index]` from `range`.
std::optional<TokenTreeNodeRange> TokenTree::Create(
    const std::optional<pasta::TokenRange> &range,
    const pasta::PrintedTokenRange &printed_range,
    std::ostream &err) {

  auto impl = std::make_shared<TokenTreeImpl>();

  try {

    // Build and classify the initial list of tokens.
    if (!impl->BuildInitialTokenList(range, printed_range, err)) {
      return std::nullopt;
    }

    Substitution *sub = impl->BuildSubstitutions(err);
    if (!sub) {
      return std::nullopt;
    }

    if (impl->has_error) {
      Die(impl.get());
      return std::nullopt;
    }


//    std::cerr << "----------------------------------------------------- " << begin_index << " to " << end_index << " ---\n";
//    std::cerr << "----------------------------------------------------- " << impl->tokens_alloc.size() << " ---\n";
//    sub->Print(std::cerr);
//    std::cerr << "\n\n\n";
//    sub->PrintDOT(std::cerr);
//    std::cerr << "\n\n";


//        std::cerr << "----------------------------------------------------- " << begin_index << " to " << end_index << " ---\n";
//        std::cerr << "----------------------------------------------------- " << impl->tokens_alloc.size() << " ---\n";
//        sub->Print(std::cerr);
//        std::cerr << "\n\n\n";
//        sub->PrintDOT(std::cerr);
//        std::cerr << "\n\n\n";
//        return std::string();

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

std::optional<pasta::FileToken> TokenTreeNode::FileToken(void) const noexcept {
  if (const auto &ent = (*impl)[offset];
      std::holds_alternative<TokenInfo *>(ent)) {
    return std::get<TokenInfo *>(ent)->file_tok;
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

std::optional<pasta::Token>
TokenTree::FirstFullySubstitutedToken(void) const noexcept {
  if (auto lc = LeftCornerOfExp(const_cast<Substitution *>(impl.get()))) {
    if (lc->parsed_tok) {
      return lc->parsed_tok;
    } else if (lc->macro_tok) {
      return lc->macro_tok->ParsedLocation();
    }
  }
  return std::nullopt;
}

std::optional<pasta::Token>
TokenTree::LastFullySubstitutedToken(void) const noexcept {
  if (auto rc = RightCornerOfExp(const_cast<Substitution *>(impl.get()))) {
    if (rc->parsed_tok) {
      return rc->parsed_tok;
    } else if (rc->macro_tok) {
      return rc->macro_tok->ParsedLocation();
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
