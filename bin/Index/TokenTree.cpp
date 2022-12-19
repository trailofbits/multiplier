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
#include <optional>
#include <pasta/AST/AST.h>
#include <pasta/AST/Forward.h>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Token.h>
#include <pasta/Util/File.h>
#include <sstream>
#include <unordered_map>
#include <vector>

#include <iostream>

#include "PASTA.h"

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
  std::optional<pasta::FileToken> file_tok;
  std::optional<pasta::MacroToken> macro_tok;
  Category category{kFileToken};

  // `, ## __VA_ARGS__`.
  bool is_va_args_concat{false};

  // This is a metric of whether or not we can trust that some token is actually
  // part of its substitution. In a macro expansion, this tells us whether or
  // not the token is part of the macro definition itself. In a macro use, this
  // tells us if it's part of the use, rather than a substituted macro
  // parameter.
  bool is_part_of_sub{false};
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

  // Child node, after expansion or substitution. `HasExpansion()` tells us
  // if we should look in here.
  NodeList after;

  Substitution *parent{nullptr};

  bool HasExpansion(void) const noexcept;

  bool is_va_args_concat{false};

  // Sometimes we have a substitution where the bounds on `before` and
  // `after` should be treated as the same. This happens when merging
  // argument pre-expansion stuff.
  bool before_after_bounds_are_same{false};

  explicit Substitution(mx::MacroKind kind_)
      : kind(kind_) {}

  void Print(std::ostream &os) const;
  void PrintDOT(std::ostream &os, bool first=true) const;
};

class TokenTreeImpl {
 public:
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
  TokenInfo *BuildInitialTokenList(pasta::TokenRange range,
                                   uint64_t begin_index,
                                   uint64_t end_index,
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

  bool FindSubstitutionBoundsRec(Substitution::NodeList &nodes,
                                 TokenInfo *lower_bound,
                                 TokenInfo *upper_bound);

  bool FindSubstitutionBoundsRec(Substitution *sub, TokenInfo *lower_bound,
                                 TokenInfo *upper_bound);

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
                                   std::ostream &err);

  Substitution *BuildSubstitutions(std::ostream &err);

  Substitution *CreateSubstitution(mx::MacroKind kind);

  static bool BoundsAreSane(const Substitution::NodeList &nodes);
  static bool BoundsAreSane(const Substitution *sub);
  static bool BoundsAreSane(const TokenInfo *lb, const TokenInfo *ub);
  void AddOrClearInsaneBounds(Substitution::NodeList &nodes);
  void AddOrClearInsaneBounds(Substitution *sub);
};

static void Die(const TokenTreeImpl *impl) {
  std::unique_lock<std::mutex> locker(gPrintDOTLock);
  std::cerr.flush();
  auto &sub = impl->substitutions_alloc.front();
  std::cerr << "--------------------------------------------------------\n";
  std::cerr << "--------------------------------------------------------\n";
  for (const TokenInfo &tok : impl->tokens_alloc) {
    if (tok.parsed_tok) {
      const pasta::Token &ast_tok = tok.parsed_tok.value();
      pasta::AST ast = pasta::AST::From(ast_tok);
      std::cerr << ast.MainFile().Path().generic_string() << "\n\n";
      break;
    }
  }
  sub.Print(std::cerr);
  std::cerr << "\n\n";
  sub.PrintDOT(std::cerr);
  std::cerr << "\n\n";
  std::cerr.flush();
  TT_ASSERT(false);
}

bool TokenTreeImpl::BoundsAreSane(const TokenInfo *lb, const TokenInfo *ub) {
  if (!lb != !ub) {
    return false;
  }

  if (!lb || !ub) {
    return true;
  }

  if (!lb->file_tok != !ub->file_tok) {
    return false;
  }

  if (!lb->file_tok || !ub->file_tok) {
    return true;
  }

  // Make sure they're in the same file.
  if (lb->file_tok->RawFile() != ub->file_tok->RawFile()) {
    return false;
  }

  auto bi = lb->file_tok->Index();
  auto ai = ub->file_tok->Index();
  if (bi < ai) {
    return true;

  } else {
    return false;
  }
}

bool TokenTreeImpl::BoundsAreSane(const Substitution::NodeList &nodes) {
  return BoundsAreSane(nodes.prev, nodes.next);
}

bool TokenTreeImpl::BoundsAreSane(const Substitution *sub) {
  return BoundsAreSane(sub->before);
}

void TokenTreeImpl::AddOrClearInsaneBounds(Substitution::NodeList &nodes) {
  if (!nodes.prev && !nodes.empty() &&
      std::holds_alternative<TokenInfo *>(nodes.front())) {
    TokenInfo *first = std::get<TokenInfo *>(nodes.front());
    if (first->is_part_of_sub) {
      nodes.prev = TryGetBeforeToken(first);
    }
  }

  if (!nodes.next && !nodes.empty() &&
      std::holds_alternative<TokenInfo *>(nodes.back())) {
    TokenInfo *last = std::get<TokenInfo *>(nodes.back());
    if (last->is_part_of_sub) {
      nodes.next = TryGetAfterToken(last);
    }
  }
}
void TokenTreeImpl::AddOrClearInsaneBounds(Substitution *sub) {
  AddOrClearInsaneBounds(sub->before);
  AddOrClearInsaneBounds(sub->after);
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

static bool InFileBody(const Substitution *sub) {
  if (!sub) {
    return false;
  }

  switch (sub->kind) {
    // These are all in the body of a macro.
    case mx::MacroKind::PARAMETER:
    case mx::MacroKind::STRINGIFY:
    case mx::MacroKind::CONCATENATE:
      return true;

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
    case mx::MacroKind::INCLUDE_DIRECTIVE:
    case mx::MacroKind::INCLUDE_NEXT_DIRECTIVE:
    case mx::MacroKind::INCLUDE_MACROS_DIRECTIVE:
    case mx::MacroKind::IMPORT_DIRECTIVE:
      return true;

    // Watch out for `_Pragma` -> `#pragma`. But distinguish from:
    // `MACRO(... #pragma ... )`.
    case mx::MacroKind::PRAGMA_DIRECTIVE:
      [[clang::fallthrough]];

    case mx::MacroKind::EXPANSION:
    case mx::MacroKind::SUBSTITUTION:
    case mx::MacroKind::ARGUMENT:
      if (!InFileBody(sub->parent)) {
        return false;
      } else {
        return InNodeList(sub->parent->before, sub);
      }

    default:
      return false;
  }
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

  for (Substitution::Node &node : sub->after) {
    if (std::holds_alternative<Substitution *>(node)) {
      Substitution *child_sub = std::get<Substitution *>(node);
      assert(child_sub != sub);
      child_sub->parent = sub;
    }
  }
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

    // Empty if we're dealing with a top-level directive, but non-empty
    // if we're dealing with a directive nested inside of a decl / larger
    // fragment.
    //
    // NOTE(pag): Have to handle the empty file case with `.prev` being non-
    //            nullptr.
    case mx::MacroKind::INCLUDE_DIRECTIVE:
    case mx::MacroKind::INCLUDE_NEXT_DIRECTIVE:
    case mx::MacroKind::INCLUDE_MACROS_DIRECTIVE:
    case mx::MacroKind::IMPORT_DIRECTIVE:
      return !after.empty() || after.prev != nullptr;

    case mx::MacroKind::EXPANSION:
    case mx::MacroKind::SUBSTITUTION:
    case mx::MacroKind::VA_OPT:
    case mx::MacroKind::STRINGIFY:
    case mx::MacroKind::CONCATENATE:
      return true;

    // Macro argument, parameter, etc.
    case mx::MacroKind::ARGUMENT:
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
      std::get<Substitution *>(ent)->Print(os);
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
    if (info->is_part_of_sub) {
      os << " bgcolor=\"antiquewhite\"";
    }
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
        assert(s->parent == self);
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

    if (before_after_bounds_are_same) {
      os << " same_bounds";
    }

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
TokenInfo *TokenTreeImpl::BuildInitialTokenList(pasta::TokenRange range,
                                                uint64_t begin_index,
                                                uint64_t end_index,
                                                std::ostream &err) {
  int macro_depth = 0;
  TokenInfo *last_macro_use_token = nullptr;

  for (auto i = begin_index; i <= end_index; ++i) {
    pasta::Token tok = range[i];

    TokenInfo &info = tokens_alloc.emplace_back();
    info.file_tok = tok.FileLocation();
    info.macro_tok = tok.MacroLocation();
    info.parsed_tok = tok;

    switch (tok.Role()) {
      default:
      case pasta::TokenRole::kInvalid:
        err << "Invalid or unexpected token in range";
        return nullptr;

      case pasta::TokenRole::kBeginOfMacroExpansionMarker: {
        assert(!last_macro_use_token);
        assert(tok.FileLocation().has_value());
        info.category = TokenInfo::kMarkerToken;
        last_macro_use_token = &info;
        ++macro_depth;
        break;
      }

      case pasta::TokenRole::kEndOfMacroExpansionMarker: {
        assert(last_macro_use_token != nullptr);
        pasta::File file = pasta::File::Containing(
            last_macro_use_token->file_tok.value());
        info.file_tok = file.Tokens().At(
            last_macro_use_token->file_tok->Index() + 1u);
        info.category = TokenInfo::kMarkerToken;
        last_macro_use_token = nullptr;
        --macro_depth;
        assert(0 <= macro_depth);
        break;
      }

      case pasta::TokenRole::kInitialMacroUseToken: {
        assert(0 < macro_depth);
        assert(last_macro_use_token != nullptr);
        info.category = TokenInfo::kMacroUseToken;
        info.is_part_of_sub = true;
        assert(info.macro_tok.has_value());
        last_macro_use_token = &info;
        break;
      }

      case pasta::TokenRole::kIntermediateMacroExpansionToken: {
        assert(0 < macro_depth);
        assert(last_macro_use_token != nullptr);
        info.category = TokenInfo::kMacroStepToken;
        assert(info.macro_tok.has_value());
        break;
      }

      case pasta::TokenRole::kFinalMacroExpansionToken: {
        assert(0 < macro_depth);
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
        assert(!macro_depth);
        assert(!last_macro_use_token);
        assert(info.file_tok.has_value());
        assert(info.file_tok->Data() == tok.Data());
        info.category = TokenInfo::kFileToken;
        info.is_part_of_sub = true;
        break;
      }

      case pasta::TokenRole::kEndOfInternalMacroEventMarker: {
        assert(macro_depth);
        assert(last_macro_use_token);
        info.category = TokenInfo::kMarkerToken;
        break;
      }
    }

    if (info.file_tok) {
      nth_file_token.emplace(
          std::make_pair(info.file_tok->RawFile(), info.file_tok->Index()),
          &info);
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
  if (auto parent = node.Parent()) {
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
    Substitution::NodeList new_nodes;
    new_nodes.prev = sub->before.prev;
    new_nodes.next = sub->before.next;

    Substitution *new_arg_sub = CreateSubstitution(mx::MacroKind::SUBSTITUTION);
    new_arg_sub->before_after_bounds_are_same = true;
    new_arg_sub->before = std::move(sub->before);
    new_arg_sub->after = std::move(pre_exp->before);
    new_arg_sub->parent = sub;
    FixupNodeParents(new_arg_sub);

    new_nodes.emplace_back(new_arg_sub);

    sub->before = std::move(new_nodes);
  }

  pre_exp->before.clear();
  pre_exp->after.clear();
  pre_exp->macro.reset();
  pre_exp->parent = nullptr;

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

  // If we merge the argument pre-expansions, then the before/after won't be
  // the same anymore.
  assert(!pre_exp->before_after_bounds_are_same);
  assert(sub->before_after_bounds_are_same);
  sub->before_after_bounds_are_same = false;

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
        preexp_lc->is_part_of_sub = orig_rc->is_part_of_sub;
        new_nodes.push_back(preexp_node);

      // If the pre-expansion isn't a token, and regardless of what the original
      // is, then we'll want to show some kind of substitution.
      } else {
        Substitution *non_empty_sub = CreateSubstitution(
            mx::MacroKind::SUBSTITUTION);
        non_empty_sub->before_after_bounds_are_same = true;
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

  pasta::MacroToken name = def.Name();
  body = CreateSubstitution(mx::MacroKind::DEFINE_DIRECTIVE);
  body->macro = def;

  for (auto &node : def.Body()) {
    std::optional<pasta::MacroToken> tok = pasta::MacroToken::From(node);
    if (!tok) {
      continue;
    }

    D( std::cerr << indent << "body token: " << tok->Data() << '\n'; )

    TokenInfo &info = tokens_alloc.emplace_back();
    info.file_tok = tok->FileLocation();
    info.parsed_tok = tok->ParsedLocation();
    info.macro_tok = std::move(tok);
    info.is_part_of_sub = info.file_tok.has_value();
    info.category = TokenInfo::kMissingFileToken;

    switch (tok->TokenKind()) {
      case pasta::TokenKind::kEndOfFile:
      case pasta::TokenKind::kEndOfDirective:
        continue;
      default:
        if (info.is_part_of_sub) {
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
  AddOrClearInsaneBounds(body);

  D( indent.resize(indent.size()  - 2u); )

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

static void LabelUseNodesIn(Substitution::NodeList &nodes,
                            bool is_top_level_use, const void *node) {
  for (Substitution::Node &n : nodes) {
    if (!std::holds_alternative<TokenInfo *>(n)) {
      continue;
    }

    TokenInfo *tok = std::get<TokenInfo *>(n);
    if (!tok->parsed_tok) {
      continue;
    }

    if (is_top_level_use) {
      tok->is_part_of_sub = true;
      continue;
    }

    assert(!tok->macro_tok ||
           (tok->macro_tok->ParsedLocation().RawToken() ==
               tok->parsed_tok->RawToken()));
    auto dt = tok->parsed_tok->DerivedLocation();
    if (!dt) {
      continue;
    }

    auto dm = dt->MacroLocation();
    if (!dm) {
      continue;
    }

    auto p = dm->Parent();
    if (!p) {
      continue;
    }

    if (p->RawMacro() == node) {
      tok->is_part_of_sub = true;
    }
  }
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

    // TODO(pag): If/when we get event markers for before/after parameter
    //            substitutions, then disable this, and allow these tokens
    //            through, and then update `lb_ub` propagation in
    //            `FindSubstitutionBoundsRec` to propagate lower/upper bounds
    //            through these markers.
    } else if (curr->category == TokenInfo::kMarkerToken &&
               (curr->parsed_tok->Role() ==
                   pasta::TokenRole::kEndOfInternalMacroEventMarker)) {
      prev = curr;
      curr = curr->next;
      return sub;

    } else if (curr->macro_tok) {
      break;

    } else {
      err << "Found an unusual token";
      return nullptr;
    }
  }

  if (!curr || !curr->macro_tok) {
    err << "Failed to find the next macro token";
    return nullptr;
  }

  nodes.emplace_back(curr);

  // Can happen when trying to align an argument containing conditional
  // directives in the use with pre-expansion form that doesn't have the
  // conditional directives.
  if (curr->macro_tok->RawMacro() != node.RawMacro()) {
    nodes.has_error = true;
    Die(this);
    return sub;
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

  LabelUseNodesIn(arg_sub->before, InFileBody(arg_sub),
                  ContainingMacroDef(arg_sub));

  return sub;
}

Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    Substitution::NodeList &nodes, const pasta::MacroParameter &node,
    std::ostream &err) {

  Substitution *arg_sub = CreateSubstitution(mx::FromPasta(node.Kind()));
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

  LabelUseNodesIn(arg_sub->before, InFileBody(arg_sub),
                  ContainingMacroDef(arg_sub));

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

  LabelUseNodesIn(exp->before, InFileBody(exp), ContainingMacroDef(exp));

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

  if (!node.IsArgumentPreExpansion()) {

    // Go mark the "trusted" tokens in the use.
    if (InFileBody(exp)) {
      LabelUseNodesIn(exp->before, true, nullptr);
      if (pre_exp) {
        LabelUseNodesIn(pre_exp->before, true, nullptr);
      }

    // If we're inside of some other macro body, then mark those tokens.
    } else if (auto cmd = ContainingMacroDef(sub)) {
      LabelUseNodesIn(exp->before, false, cmd);
      if (pre_exp) {
        LabelUseNodesIn(pre_exp->before, false, cmd);
      }
    }

    // Go mark the "trusted" tokens in the expansion. These are ones that are
    // located in the macro body.
    if (pre_exp) {
      LabelUseNodesIn(pre_exp->after, false, macro_def->RawMacro());
    } else {
      LabelUseNodesIn(exp->after, false, macro_def->RawMacro());
    }
  }

  // Try to find the real body.
  Substitution *macro_body = GetMacroBody(macro_def.value(), err);
  if (!macro_body) {
    exp->after.has_error = true;
    err << "Unable to find macro body for macro with name '"
        << macro_def->Name().Data() << "'";
    return nullptr;
  }

  // Inherit the `after` bounds from the macro body.
  if (pre_exp) {
    exp->before_after_bounds_are_same = true;
    if (!MergeArgPreExpansion(exp, pre_exp, err)) {
      err << "Unable to merge pre-argument expansion with use of macro "
          << macro_def->Name().Data();
      return nullptr;
    }

    assert(!PreExpansionOf(exp));
  }

  exp->after.prev = macro_body->before.prev;
  exp->after.next = macro_body->before.next;

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

  // Mark all as trusted.
  for (Substitution::Node &node : dir->before) {
    if (std::holds_alternative<TokenInfo *>(node)) {
      std::get<TokenInfo *>(node)->is_part_of_sub = true;
    }
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
    case pasta::MacroKind::kSubstitution:
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

  sub = BuildMacroSubstitutions(
      prev, curr, sub, sub->before, RootNodeFrom(use->macro_tok.value()), err);
  if (!sub) {
    return nullptr;
  }

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
  Substitution *file_sub = BuildSubstitutions(prev, curr, err);
  if (!file_sub) {
    return nullptr;
  }

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
      break;
    default:
      err << "The last thing in the current substitution "
             "should be an inclusion";
      return nullptr;
  }

  include_sub->after = std::move(file_sub->before);
  FixupNodeParents(include_sub);

  // Make sure that we're at the end of a file.
  if (!curr || curr->category != TokenInfo::kMarkerToken) {
    err << "Expected a marker token at the end of file";
    return nullptr;
  }

  if (curr->parsed_tok->Role() != pasta::TokenRole::kEndOfFileMarker) {
    err << "Expected a file ending marker token at the end of a file";
    return nullptr;
  }

  include_sub->after.prev = TryGetBeforeToken(first_tok);
  include_sub->after.next = TryGetAfterToken(prev);

  AddOrClearInsaneBounds(include_sub);

  // Skip the marker.
  prev = curr;
  curr = curr->next;

  return sub;
}

Substitution *TokenTreeImpl::BuildSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, std::ostream &err) {

  Substitution *sub = CreateSubstitution(mx::MacroKind::OTHER_DIRECTIVE);
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
      case TokenInfo::kMacroUseToken:
      case TokenInfo::kMacroStepToken:
      case TokenInfo::kMacroExpansionToken:
        sub->before.has_error = true;
        Die(this);
        err << "Macro tokens should not be seen here";
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
            continue;

          default:
            err << "Should not see this marker here";
            return nullptr;
        }
        break;
    }
  }

  LabelUseNodesIn(sub->before, true, nullptr);

  if (prev) {
    if (prev->category == TokenInfo::kMarkerToken) {
      sub->before.next = prev;
      AddOrClearInsaneBounds(sub);
    } else {
      TryAddAfterToken(sub, prev);
    }
  }

  return sub;
}

// Try to recursively find the bounds of a substitution. This is suprisingly
// subtle. It means dealing with some of the subtleties of both Clang's
// behavior, as well as PASTA's.
bool TokenTreeImpl::FindSubstitutionBoundsRec(
    Substitution *sub, TokenInfo *lower_bound,
    TokenInfo *upper_bound) {

  AddOrClearInsaneBounds(sub);
  auto ret = FindSubstitutionBoundsRec(sub->before, lower_bound, upper_bound);

  if (sub->HasExpansion()) {
    assert(!PreExpansionOf(sub));

    // E.g. for macro argument pre-expansions, when we merge arguments, or
    // introduce substitutions of like-for-like.
    if (sub->before_after_bounds_are_same) {
      FindSubstitutionBoundsRec(sub->after, sub->before.prev,
                                sub->before.next);

    } else {
      FindSubstitutionBoundsRec(sub->after, nullptr, nullptr);
    }
  } else {
    assert(sub->after.empty());
  }

  return ret;
}

// Try to recursively find the bounds of a substitution. This is suprisingly
// subtle. It means dealing with some of the subtleties of both Clang's
// behaviour, as well as PASTA's.
bool TokenTreeImpl::FindSubstitutionBoundsRec(
    Substitution::NodeList &nodes, TokenInfo *lower_bound,
    TokenInfo *upper_bound) {

//  // Clang special cases `_Pragma` expansions when they appear inside of
//  // other macro arguments. This is to prevent argument pre-expansion of
//  // `MACRO(_Pragma("..."))` into `MACRO(#pragma ...)`. In our tree form, this
//  // manifests as the `_Pragma` macro use appearing in the expansion of `MACRO`.
//  // At face value, this is fine, except that it means that the bounds taken
//  // from the definition of `MACRO` cannot be trusted as lower/upper bounds to
//  // the use of `_Pragma` at the substitution site, so we need to clear out
//  // `lower_bound` and `upper_bound`.
//  if (sub->kind == Substitution::kMacroUse && (lower_bound || upper_bound) &&
//      sub->parent && sub->parent->kind == Substitution::kMacroExpansion) {
//    TokenInfo *macro_name =
//        ::indexer::RightCornerOfExpansionOrUse(nodes.front());
//    assert(macro_name);
//    if (macro_name->parsed_tok->Data() != "_Pragma") {
//      goto normal_or_handled_pragma;
//    }
//
//    sub->has_error = true;
//    Die(this);
//  }
//
//normal_or_handled_pragma:

  auto changed_bounds = false;

  // Empty node.
  if (nodes.empty()) {
    return false;
  }

  if (!nodes.prev && lower_bound) {
    nodes.prev = lower_bound;
    changed_bounds = true;
  }

  if (!nodes.next && upper_bound) {
    nodes.next = upper_bound;
    changed_bounds = true;
  }

  // An empty node should have the same lower/upper bounds.
  if (!LeftCornerOfUse(nodes)) {
    if (nodes.prev && !nodes.next) {
      nodes.next = TryGetAfterToken(nodes.prev);
      changed_bounds = true;

    } else if (nodes.next && !nodes.prev) {
      nodes.prev = TryGetBeforeToken(nodes.next);
      changed_bounds = true;
    }
  }

  if (!BoundsAreSane(nodes)) {
    auto orig_bb = nodes.prev;
    auto orig_ab = nodes.next;

    nodes.prev = LeftCornerOfUse(nodes);
    nodes.next = RightCornerOfUse(nodes);

    if (!BoundsAreSane(nodes)) {
      nodes.has_error = true;
      nodes.prev = orig_bb;
      nodes.next = orig_ab;

      // TODO(pag): Re-enable this when we get back into whitespace injection
      //            and other things.
      // Die(this);
      return false;
    }
  }

  uint64_t bi = ~0u;
  uint64_t ai = 0u;

  if (nodes.prev) {
    bi = nodes.prev->file_tok->Index();
  }

  if (nodes.next) {
    ai = nodes.next->file_tok->Index();
  }

  const auto max_i = nodes.size();
  std::vector<std::pair<TokenInfo *, TokenInfo *>> lb_ub;
  std::vector<bool> checked_provenance;
  std::vector<bool> same_recursive;
  lb_ub.resize(max_i);
  checked_provenance.resize(max_i);
  same_recursive.resize(max_i);

  auto accept = +[] (TokenInfo *lb, TokenInfo *mid, TokenInfo *ub) {
    return BoundsAreSane(lb, mid) && BoundsAreSane(mid, ub);
  };

  auto changed = true;
  for (auto c = 0u; changed && c <= max_i; ++c) {
    changed = false;

    lower_bound = nodes.prev;
    upper_bound = nodes.next;

    // Forward pass, collect lower bounds.
    for (auto i = 0u; i < max_i; ++i) {
      const Substitution::Node &node = nodes[i];
      if (std::holds_alternative<TokenInfo *>(node)) {
        TokenInfo *tok_node = std::get<TokenInfo *>(node);

        lower_bound = nullptr;
        if (tok_node->is_part_of_sub) {
          lower_bound = tok_node;

        // Opportunistically try to calculate if this token actually belongs.
        // This mostly helps with pre-argument expansions.
        } else if (tok_node->file_tok) {
          auto fti = tok_node->file_tok->Index();
          if (bi < fti && fti < ai) {
            tok_node->is_part_of_sub = true;
            changed = true;
            changed_bounds = true;
            lower_bound = tok_node;
          }
        }

      } else if (std::holds_alternative<Substitution *>(node)) {
        if (lower_bound && lower_bound != lb_ub[i].first) {
          lb_ub[i].first = lower_bound;
          same_recursive[i] = false;
          changed = true;
        }

        Substitution *sub_node = std::get<Substitution *>(node);
        if (TokenInfo *next_lb = TryGetBeforeToken(sub_node->before.next);
            next_lb && accept(lower_bound, next_lb, upper_bound)) {
          lower_bound = next_lb;
          continue;
        }

        if (TokenInfo *rc = RightCornerOfUse(sub_node->before);
            rc && accept(lower_bound, rc, upper_bound)) {
          lower_bound = rc;
        } else {
          lower_bound = nullptr;
        }
      }
    }

    lower_bound = nodes.prev;
    upper_bound = nodes.next;

    // Backward pass, collect upper bounds.
    for (auto j = 1u; j <= max_i; ++j) {
      auto i = max_i - j;
      const Substitution::Node &node = nodes[i];
      if (std::holds_alternative<TokenInfo *>(node)) {
        TokenInfo *tok_node = std::get<TokenInfo *>(node);
        upper_bound = nullptr;
        if (tok_node->is_part_of_sub) {
          upper_bound = tok_node;
        }

      } else if (std::holds_alternative<Substitution *>(node)) {
        if (upper_bound && upper_bound != lb_ub[i].second) {
          lb_ub[i].second = upper_bound;
          same_recursive[i] = false;
          changed = true;
        }

        Substitution *sub_node = std::get<Substitution *>(node);
        if (TokenInfo *next_ub = TryGetAfterToken(sub_node->before.prev);
            next_ub && accept(lower_bound, next_ub, upper_bound)) {
          upper_bound = next_ub;
          continue;
        }

        if (TokenInfo *lc = LeftCornerOfUse(sub_node->before);
            lc && accept(lower_bound, lc, upper_bound)) {
          upper_bound = lc;
        } else {
          upper_bound = nullptr;
        }
      }
    }

    // Substitution pass
    for (auto i = 0u; i < max_i; ++i) {
      const Substitution::Node &node = nodes[i];
      if (!std::holds_alternative<Substitution *>(node)) {
        continue;
      }

      Substitution *sub_node = std::get<Substitution *>(node);

      // Special case: we don't have lower/upper bounds for around us that
      // come from this sub, but we are surrounded by tokens that share
      // a common provenance, so we can take their bounds.
      if (!checked_provenance[i] && 0u < i && (i + 1u) < max_i &&
          !lb_ub[i].first && !lb_ub[i].second &&
          std::holds_alternative<TokenInfo *>(nodes[i - 1u]) &&
          std::holds_alternative<TokenInfo *>(nodes[i + 1u])) {
        auto bt = std::get<TokenInfo *>(nodes[i - 1u]);
        auto at = std::get<TokenInfo *>(nodes[i + 1u]);
        if (!bt->parsed_tok || !at->parsed_tok) {
          goto keep_going;
        }

        auto btd = bt->parsed_tok->DerivedLocation();
        auto atd = at->parsed_tok->DerivedLocation();
        if (!btd || !atd) {
          goto keep_going;
        }

        auto btdm = btd->MacroLocation();
        auto atdm = atd->MacroLocation();
        if (!btdm || !atdm) {
          goto keep_going;
        }

        auto btdmp = btdm->Parent();
        auto atdmp = atdm->Parent();
        if (btdmp && atdmp && btdmp->RawMacro() == atdmp->RawMacro()) {
          lb_ub[i].first = bt;
          lb_ub[i].second = at;
        }
      }

    keep_going:
      if (!same_recursive[i] &&
          FindSubstitutionBoundsRec(sub_node, lb_ub[i].first,
                                    lb_ub[i].second)) {
        changed = true;
      }
      checked_provenance[i] = true;
      same_recursive[i] = true;
    }
  }

  return changed_bounds;
}

// Build the initial tree of substitutions.
Substitution *TokenTreeImpl::BuildSubstitutions(std::ostream &err) {
  std::vector<Substitution *> subs;

  TokenInfo *prev = nullptr;
  TokenInfo * const first = &(tokens_alloc.front());
  TokenInfo *curr = first;  // NOTE(pag): Updated by reference.
  auto sub = BuildSubstitutions(prev, curr, err);
  if (!sub) {
    return nullptr;
  }

  return sub;
}

TokenTree::~TokenTree(void) {}

// Create a token tree from the tokens in the inclusive range
// `[begin_index, end_index]` from `range`.
std::optional<TokenTreeNodeRange>
TokenTree::Create(pasta::TokenRange range, uint64_t begin_index,
                  uint64_t end_index, std::ostream &err) {

  if (begin_index > end_index) {
    err << "Cannot create token tree; begin index (" << begin_index
        << ") is greater than end index (" << end_index << ")";
    return std::nullopt;
  }

  if (auto range_size = range.Size(); end_index >= range_size) {
    err << "Cannot create token tree; end index (" << end_index
        << ") is greater than or equal to the range size ("
        << range_size << ")";
    return std::nullopt;
  }

  auto impl = std::make_shared<TokenTreeImpl>();

  try {

    // Build and classify the initial list of tokens.
    if (!impl->BuildInitialTokenList(std::move(range), begin_index,
                                     end_index, err)) {
      return std::nullopt;
    }

    Substitution *sub = impl->BuildSubstitutions(err);
    if (!sub) {
      return std::nullopt;
    }

//      impl->ProvenanceBasedParameterSubstitutionRec(sub);
    impl->FindSubstitutionBoundsRec(sub, nullptr, nullptr);


//      std::cerr << "----------------------------------------------------- " << begin_index << " to " << end_index << " ---\n";
//      std::cerr << "----------------------------------------------------- " << impl->tokens_alloc.size() << " ---\n";
//      sub->Print(std::cerr);
//      std::cerr << "\n\n\n";
//      sub->PrintDOT(std::cerr);
//      std::cerr << "\n\n";


//      std::shared_ptr<const Substitution> ret(std::move(impl), sub);
//      return TokenTree(std::move(ret));

//    if (!impl->MergeArgPreExpansions(err)) {
//      return std::nullopt;
//    }

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

unsigned TokenTreeNodeRange::Size(void) const noexcept {
  return static_cast<unsigned>(begin_.node.impl->size());
}

mx::MacroKind TokenTree::Kind(void) const noexcept {
  return impl->kind;
}

std::optional<pasta::Macro> TokenTree::Macro(void) const noexcept {
  return impl->macro;
}

std::optional<pasta::MacroDirective>
TokenTree::MacroDirective(void) const noexcept {
  if (!impl->macro) {
    return std::nullopt;
  }
  return pasta::MacroDirective::From(impl->macro.value());
}

std::optional<pasta::DefineMacroDirective>
TokenTree::MacroDefinition(void) const noexcept {
  if (!impl->macro) {
    return std::nullopt;
  }
  return pasta::DefineMacroDirective::From(impl->macro.value());
}

std::optional<pasta::MacroExpansion>
TokenTree::MacroExpansion(void) const noexcept {
  if (!impl->macro) {
    return std::nullopt;
  }
  return pasta::MacroExpansion::From(impl->macro.value());
}

std::optional<pasta::MacroArgument>
TokenTree::MacroArgument(void) const noexcept {
  if (!impl->macro) {
    return std::nullopt;
  }
  return pasta::MacroArgument::From(impl->macro.value());
}

TokenTreeNodeRange TokenTree::Children(void) const noexcept {
  std::shared_ptr<const SubstitutionNodeList> ptr(impl, &(impl->before));
  return TokenTreeNodeRange(std::move(ptr));
}

TokenTreeNodeRange TokenTree::ReplacementChildren(void) const noexcept {
  std::shared_ptr<const SubstitutionNodeList> ptr(impl, &(impl->after));
  return TokenTreeNodeRange(std::move(ptr));
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
