// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Query.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <multiplier/IndexStorage.h>

namespace mx {
namespace syntex {

template<typename TokenCallback, typename MetavarCallback, typename VarargCallback>
void Tokenize(TokenCallback token_callback, MetavarCallback metavar_callback,
                VarargCallback vararg_callback, std::string_view input, size_t index) {
  size_t end = index;

  auto Look = [&] (size_t i) -> int {
    if (end + i < input.size())
      return input[end + i];
    else
      return -1;
  };

  auto Eat = [&] (size_t cnt) {
    end += cnt;
  };

  auto Get = [&] () {
    int ch = Look(0);
    if (ch != -1)
      Eat(1);
    return ch;
  };

  auto Match = [&] (char ch) {
    if (Look(0) == ch) {
      Eat(1);
      return true;
    }
    return false;
  };

  auto MatchSpace = [&] () {
    switch (Look(0)) {
    case ' ':
    case '\f':
    case '\n':
    case '\r':
    case '\t':
    case '\v':
      Eat(1);
      return true;
    default:
      return false;
    }
  };

  auto MatchIdent = [&] () {
    switch (Look(0)) {
    case '_':
    case 'a' ... 'z':
    case 'A' ... 'Z':
    case '0' ... '9':
      Eat(1);
      return true;
    default:
      return false;
    }
  };

  auto MatchDecimal = [&] () {
    switch (Look(0)) {
    case '0' ... '9':
      Eat(1);
      return true;
    default:
      return false;
    }
  };

  auto MatchHex = [&] () {
    switch (Look(0)) {
      case '0' ... '9':
    case 'a' ... 'f':
    case 'A' ... 'F':
      Eat(1);
      return true;
    default:
      return false;
    }
  };

  auto MatchOct = [&] () {
    switch (Look(0)) {
    case '0' ... '7':
      Eat(1);
      return true;
    default:
      return false;
    }
  };

  auto MatchDecimalExponent = [&] () {
    if (Match('e') || Match('E')) {
      Match('+') || Match('-');
      return true;
    }
    return false;
  };

  auto MatchHexExponent = [&] () {
    if (Match('p') || Match('P')) {
      Match('+') || Match('-');
      return true;
    }
    return false;
  };

  auto MatchIntegerSuffix = [&] () {
    if (Match('l') || Match('L')) {
      if (Match('l') || Match('L')) {
        if (Match('u') || Match('U')) {       // llu
          // unsigned long long
        } else {                              // ll
          // long long
        }
      } else if (Match('u') || Match('U')) {  // lu
        // unsigned long
      } else {                                // l
        // long
      }
    } else if (Match('u') || Match('U')) {
      if (Match('l') || Match('L')) {
        if (Match('l') || Match('L')) {       // ull
          // unsigned long long
        } else {                              // ul
          // unsigned long
        }
      } else {                                // u
        // unsigned int
      }
    } else {                                  // <nothing>
      // int
    }
  };

  auto MatchFloatingSuffix = [&] () {
    if (Match('f') || Match('F')) {           // f
      // float
    } else if (Match('l') || Match('L')) {    // l
      // long double
    } else {                                  // <nothing>
      // double
    }
  };

  // Skip all whitespaces that might preceed the token
  while (MatchSpace())
    ;

  // The spelling starts after skipping preceding whitespaces
  size_t begin = end;

  // Add a token to the output
  auto AddToken = [&] (size_t len, mx::TokenKind kind) {
    size_t next = begin + len;
    for (;;)
      switch (Look(next - end)) {
      case ' ':
      case '\f':
      case '\n':
      case '\r':
      case '\t':
      case '\v':
        ++next;
        break;
      default:
        token_callback(kind, input.substr(begin, len), next);
        return;
      }
  };

  auto AddMetavar = [&] (std::string_view name, NodeKind filter) {
    size_t next = end;
    for (;;)
      switch (Look(next - end)) {
      case ' ':
      case '\f':
      case '\n':
      case '\r':
      case '\t':
      case '\v':
        ++next;
        break;
      default:
        metavar_callback(name, filter, next);
        return;
      }
  };

  auto AddVararg = [&] () {
    size_t next = end;
    for (;;)
      switch (Look(next - end)) {
      case ' ':
      case '\f':
      case '\n':
      case '\r':
      case '\t':
      case '\v':
        ++next;
        break;
      default:
        vararg_callback(next);
        return;
      }
  };

  switch (Get()) {
  // End of input
  case -1:
    break;

  //
  // For identifiers and constants, the longest match is always consumed
  //

  // Metavariable
  case '$':
  {
    // Check for variable argument
    if (Look(0) == '.' && Look(1) == '.' && Look(2) == '.') {
      Eat(3);
      AddVararg();
      break;
    }

    // Skip over the name
    while (MatchIdent())
      ;

    auto name = input.substr(begin + 1, end - begin - 1);
    NodeKind filter = NodeKind::Any();

    // Skip over filter if present
    if (Match(':')) {
      size_t filter_begin = end;
      while (MatchIdent())
        ;

      auto filter_str = input.substr(filter_begin, end - filter_begin);

      // Try to parse it as a DeclKind
      // FIXME: this should probably be done with some kind of LUT over this
      // slow mess
      for (int i = 0; i < NumEnumerators(mx::DeclKind::TYPE); ++i) {
        auto kind = static_cast<mx::DeclKind>(i);
        if (EnumeratorName(kind) == filter_str) {
          filter = NodeKind(kind);
          goto done_filters;
        }
      }
      for (int i = 0; i < NumEnumerators(mx::StmtKind::NULL_STMT); ++i) {
        auto kind = static_cast<mx::StmtKind>(i);
        if (EnumeratorName(kind) == filter_str) {
          filter = NodeKind(kind);
          goto done_filters;
        }
      }
      for (int i = 0; i < NumEnumerators(mx::TokenKind::UNKNOWN); ++i) {
        auto kind = static_cast<mx::TokenKind>(i);
        if (EnumeratorName(kind) == filter_str) {
          filter = NodeKind(kind);
          goto done_filters;
        }
      }

      assert("FIXME: return proper error for invalid filter" && false);

done_filters:;
    }

    AddMetavar(name, filter);
    break;
  }

  // Identifiers
  case '_':
  case 'a' ... 'z':
  case 'A' ... 'Z':
    while (MatchIdent())
      ;

    AddToken(end - begin, mx::TokenKind::IDENTIFIER);
    break;

  // Numeric constants
  case '0':
    if (Match('.')) {
      while (MatchDecimal())
        ;

      if (MatchDecimalExponent()) {
        while (MatchDecimal())
          ;
      }

      MatchFloatingSuffix();
    } else if (Match('x') || Match('X')) {
      while (MatchHex())
        ;

      if (Match('.')) {
        while (MatchHex())
          ;

        if (MatchHexExponent()) {
          while(MatchHex())
            ;
        }
        MatchFloatingSuffix();
      } else if (MatchHexExponent()) {
        while (MatchHex())
          ;

        MatchFloatingSuffix();
      } else {
        MatchIntegerSuffix();
      }
    } else {
      while (MatchOct())
        ;

      MatchIntegerSuffix();
    }

    AddToken(end - begin, mx::TokenKind::NUMERIC_CONSTANT);
    break;

  case '1' ... '9':
    while (MatchDecimal())
      ;

    if (Match('.')) {
FractionalConstant:
      while (MatchDecimal())
        ;

      if (MatchDecimalExponent()) {
        while (MatchDecimal())
          ;
      }

      MatchFloatingSuffix();
    } else if (MatchDecimalExponent()) {
      while (MatchDecimal())
        ;
      MatchFloatingSuffix();
    } else {
      MatchIntegerSuffix();
    }

    AddToken(end - begin, mx::TokenKind::NUMERIC_CONSTANT);
    break;

  // Character constants
  case '\'':
    for (;;) {
      auto ch = Get();
      if (ch == '\\')
        Get();
      else if (ch == -1 || ch == '\'')
        break;
    }

    AddToken(end - begin, mx::TokenKind::CHARACTER_CONSTANT);
    break;

  // String literals
  case '"':
    for (;;) {
      auto ch = Get();
      if (ch == '\\')
        Get();
      else if (ch == -1 || ch == '"')
        break;
    }
    AddToken(end - begin, mx::TokenKind::STRING_LITERAL);
    break;

  //
  // For punctuators only the first character is consumed, and all possible
  // matches at the current position are added
  //

  case '[':
    AddToken(1, mx::TokenKind::L_SQUARE);
    break;
  case ']':
    AddToken(1, mx::TokenKind::R_SQUARE);
    break;
  case '(':
    AddToken(1, mx::TokenKind::L_PARENTHESIS);
    break;
  case ')':
    AddToken(1, mx::TokenKind::R_PARENTHESIS);
    break;
  case '{':
    AddToken(1, mx::TokenKind::L_BRACE_TOKEN);
    break;
  case '}':
    AddToken(1, mx::TokenKind::R_BRACE_TOKEN);
    break;
  case '~':
    AddToken(1, mx::TokenKind::TILDE);
    break;
  case '?':
    AddToken(1, mx::TokenKind::QUESTION);
    break;
  case ':':
    AddToken(1, mx::TokenKind::COLON);
    break;
  case ';':
    AddToken(1, mx::TokenKind::SEMI);
    break;
  case ',':
    AddToken(1, mx::TokenKind::COMMA);
    break;
  case '.':
    if (MatchDecimal()) {
      goto FractionalConstant;
    } else if (Look(0) == '.' && Look(1) == '.') {
      AddToken(3, mx::TokenKind::ELLIPSIS);
    } else {
      AddToken(1, mx::TokenKind::PERIOD);
    }
    break;
  case '-':
    AddToken(1, mx::TokenKind::MINUS);
    if (Look(0) == '>')
      AddToken(2, mx::TokenKind::ARROW);
    else if (Look(0) == '-')
      AddToken(2, mx::TokenKind::MINUS_MINUS);
    else if (Look(0) == '=')
      AddToken(2, mx::TokenKind::MINUS_EQUAL);
    break;
  case '+':
    AddToken(1, mx::TokenKind::PLUS);
    if (Look(0) == '+')
      AddToken(2, mx::TokenKind::PLUS_PLUS);
    if (Look(0) == '=')
      AddToken(2, mx::TokenKind::PLUS_EQUAL);
    break;
  case '&':
    AddToken(1, mx::TokenKind::AMP);
    if (Look(0) == '&')
      AddToken(2, mx::TokenKind::AMP_AMP);
    else if (Look(0) == '=')
      AddToken(2, mx::TokenKind::AMP_EQUAL);
    break;
  case '*':
    AddToken(1, mx::TokenKind::STAR);
    if (Look(0) == '=')
      AddToken(2, mx::TokenKind::STAR_EQUAL);
    break;
  case '!':
    AddToken(1, mx::TokenKind::EXCLAIM);
    if (Look(0) == '=')
      AddToken(2, mx::TokenKind::EXCLAIM_EQUAL);
    break;
  case '/':
    AddToken(1, mx::TokenKind::SLASH);
    if (Look(0) == '=')
      AddToken(2, mx::TokenKind::SLASH_EQUAL);
    break;
  case '%':
    AddToken(1, mx::TokenKind::PERCENT);
    if (Look(0) == '=')
      AddToken(2, mx::TokenKind::PERCENT_EQUAL);
    break;
  case '<':
    AddToken(1, mx::TokenKind::LESS);
    if (Look(0) == '<') {
      AddToken(2, mx::TokenKind::LESS_LESS);
      if (Look(1) == '=')
        AddToken(3, mx::TokenKind::LESS_LESS_EQUAL);
    } else if (Look(0) == '=') {
      AddToken(1, mx::TokenKind::LESS_EQUAL);
    }
    break;
  case '>':
    AddToken(1, mx::TokenKind::GREATER);
    if (Look(0) == '>') {
      AddToken(2, mx::TokenKind::GREATER_GREATER);
      if (Look(1) == '=')
        AddToken(3, mx::TokenKind::GREATER_GREATER_EQUAL);
    } else if (Look(0) == '=') {
      AddToken(2, mx::TokenKind::GREATER_EQUAL);
    }
    break;
  case '=':
    AddToken(1, mx::TokenKind::EQUAL);
    if (Look(0) == '=')
      AddToken(2, mx::TokenKind::EQUAL_EQUAL);
    break;
  case '^':
    AddToken(1, mx::TokenKind::CARET);
    if (Look(0) == '=')
      AddToken(2, mx::TokenKind::CARET_EQUAL);
    break;
  case '|':
    AddToken(1, mx::TokenKind::PIPE);
    if (Look(0) == '|')
      AddToken(2, mx::TokenKind::PIPE_PIPE);
    else if (Look(0) == '=')
      AddToken(2, mx::TokenKind::PIPE_EQUAL);
    break;
  case '#':
    AddToken(1, mx::TokenKind::HASH);
    if (Look(0) == '#')
      AddToken(2, mx::TokenKind::HASH_HASH);
    break;
  default:
    AddToken(1, mx::TokenKind::UNKNOWN);
  }
}

ParsedQueryImpl::ParsedQueryImpl(std::shared_ptr<mx::EntityProvider> ep, std::string_view input)
  : m_ep(ep), m_input(input) {
  ep->LoadGrammarRoot(grammar_root);
}

void ParsedQueryImpl::MatchGlob(TableEntry &result,
                                  const std::unordered_set<NodeKind> &follow,
                                  Item &item,
                                  size_t next) {

  for (auto &[left, rest] : *item.m_leaves) {
    // If:
    //   a) we reach the end of a production and have an empty follow set
    //   b) or the next non-terminal is contained in the follow set
    // we should continue parsing normally.
    if ((rest.is_production && follow.empty()) || follow.contains(left)) {
      MatchRule(result, item, next);
    }

    // If the next entry is a terminator, we don't need to glob further
    // NOTE: for most usecases of $... this makes sense and improves performance
    // but if some weird case doesn't match it might be necessary to remove this
    if (left == mx::TokenKind::R_PARENTHESIS ||
        left == mx::TokenKind::R_BRACE_TOKEN) {
      continue;
    }

    // Otherwise the rest of the grammar rule is a candiate for more globbing
    if (rest.leaves.size() > 0) {
      const GrammarLeaves *old_leaves = item.m_leaves;
      item.m_leaves = &rest.leaves;
      item.m_children.emplace_back(NodeKind::Any(), next, Glob::YES);
      MatchGlob(result, follow, item, next);
      item.m_leaves = old_leaves;
      item.m_children.pop_back();
    }
  }
}

void ParsedQueryImpl::MatchRule(TableEntry &result, Item &item, size_t next) {
  // Iterate shifts
  for (auto &[key, _] : ParsesAtIndex(next)) {
    NodeKind kind = key.first;
    size_t next = key.second;
    item.IterateShifts(kind, next, Glob::NO, [&] (Item &item) {
      MatchRule(result, item, next);
    });
  }

  // Iterate glob shifts
  if (auto it = m_globs.find(next); it != m_globs.end()) {
    // Compute set of node kinds that can follow $...
    std::unordered_set<NodeKind> follow;
    for (auto &[key, _] : ParsesAtIndex(it->second)) {
      follow.insert(key.first);
    }
    MatchGlob(result, follow, item, it->second);
  }

  // Iterate reductions
  item.IterateReductions([&] (NodeKind kind, const auto &children) {
    result[{kind, next}].emplace(children);
    MatchPrefix(result, kind, next);
  });
}

void ParsedQueryImpl::MatchPrefix(TableEntry &result, NodeKind kind, size_t next) {
  Item(&grammar_root).IterateShifts(kind, next, Glob::NO, [&] (Item &item) {
    MatchRule(result, item, next);
  });
}

const ParsedQueryImpl::TableEntry &ParsedQueryImpl::ParsesAtIndex(size_t index) {
  // Lookup memoized parses at this index
  auto it = m_parses.find(index);
  if (it != m_parses.end()) {
    return it->second;
  }

  // And only do computation if the lookup found nothing
  auto &result = m_parses[index];

  auto TokenCallback = [&] (mx::TokenKind lex_kind, std::string_view spelling, size_t next) {
    if (auto grm_kind = m_ep->TokenKindOf(spelling)) {
      result[{*grm_kind, next}].emplace(spelling);
      MatchPrefix(result, *grm_kind, next);
    } else {
      std::cerr << "Warning: token `" << spelling << "` not present in grammar\n";
    }
  };

  auto MetavarCallback = [&] (std::string_view name, NodeKind filter, size_t next) {
    if (name == "") {
      result[{filter, next}].emplace(nullptr);
    } else {
      auto [it, added] = m_metavars.emplace(name, Metavar(name, {}));
      if (!added) {
        std::cerr << "Error: duplicate metavariable name `" << name << "`\n";
        abort();
      }
      result[{filter, next}].emplace(&it->second);
    }
    MatchPrefix(result, filter, next);
  };

  auto VarargCallback = [&] (size_t next) {
    m_globs[index] = next;
  };

  Tokenize(TokenCallback, MetavarCallback, VarargCallback, m_input, index);

  return result;
}

std::pair<bool, std::vector<MetavarMatch>> ParsedQueryImpl::MatchMarker(
    const TableEntry &entry, const ParseMarker &marker, std::uint64_t node_id) {

  std::vector<MetavarMatch> metavar_matches;
  auto node = m_ep->GetASTNode(node_id);
  auto kind = NodeKind::Deserialize(node.kind);
  auto children = m_ep->GetASTNodeChildren(node_id);

  switch (marker.m_kind) {
    case ParseMarker::METAVAR:
      if (marker.m_metavar) {
        MetavarMatch mv_match(
          {marker.m_metavar->m_name.data(), marker.m_metavar->m_name.size()},
          node.entity);
        if (auto &predicate = marker.m_metavar->m_predicate) {
          if (!(*predicate)(mv_match)) {
            return {false, {}};
          }
        }
        metavar_matches.push_back(std::move(mv_match));
      }
      return {true, metavar_matches};
    case ParseMarker::TERMINAL:
      return {kind.IsToken() && node.spelling == marker.m_spelling, {}};
    case ParseMarker::NONTERMINAL:
      if (kind.IsToken() ||
            children.size() != marker.m_children.size())  {
        return {false, {}};
      }

      auto child_entry = &entry;
      auto child_it = marker.m_children.begin();

      for (std::uint64_t child_node_id : children) {
        auto &[kind, next, glob] = *child_it;
        auto child_node = m_ep->GetASTNode(child_node_id);
        auto child_node_kind = NodeKind::Deserialize(child_node.kind);

        if (kind != NodeKind::Any() && kind != child_node_kind) {
          return {false, {}};
        }

        if (glob == Glob::NO) {
          auto markers = child_entry->find({ kind, next });
          if (markers == child_entry->end()) {
            return {false, metavar_matches};
          }
          for (auto &marker : markers->second) {
            auto [child_ok, child_metavar_matches] =
              MatchMarker(*child_entry, marker, child_node_id);
            if (child_ok) {
              metavar_matches.insert(
                metavar_matches.end(),
                child_metavar_matches.begin(),
                child_metavar_matches.end());
              goto ok;
            }
          }
          return {false, {}};
        }
      ok:
        child_entry = &ParsesAtIndex(std::get<1>(*child_it));
        ++child_it;
      }
      return {true, metavar_matches};
  }
}

void ParsedQueryImpl::DebugParseTable(std::ostream &os) {
  // Make sure the DP table was actually filled in
  ParsesAtIndex(0);

  // Find all possible indices then sort them
  std::vector<size_t> indices;
  for (auto &[index, _] : m_parses) {
    indices.push_back(index);
  }
  std::sort(indices.begin(), indices.end());

  // Then print all the parses at every index in the table
  for (size_t index : indices) {
    os << "Parses at " << index << ":\n";
    for (auto &[key, markers] : m_parses.at(index)) {
      for (auto &marker : markers) {
        // Print head
        std::stringstream ss;
        ss << "  (" << key.first << ", " << key.second << ")";

        std::cout << std::left << std::setw(40) << std::setfill(' ')
                  << ss.str() << " <- ";

        // Print body
        switch (marker.m_kind) {
        case ParseMarker::METAVAR:
          std::cout << "$" << (marker.m_metavar ? marker.m_metavar->m_name : "");
          break;
        case ParseMarker::TERMINAL:
          std::cout << "`" << marker.m_spelling << "`";
          break;
        case ParseMarker::NONTERMINAL:
          for (auto &[kind, next, glob] : marker.m_children) {
            if (glob == Glob::YES) {
              std::cout << "(" << kind << ", " << next << ", ..." << ") ";
            } else {
              std::cout << "(" << kind << ", " << next << ") ";
            }
          }
          break;
        }

        std::cout << "\n";
      }
    }
  }
}

ParsedQuery::ParsedQuery(std::shared_ptr<mx::EntityProvider> ep, std::string_view query)
  : impl(std::make_shared<ParsedQueryImpl>(ep, query)) {}

bool ParsedQuery::IsValid(void) const {
  for (auto &[key, markers] : impl->ParsesAtIndex(0)) {
    if (key.second == impl->m_input.size()) {
      return true;
    }
  }
  return false;
}

bool ParsedQuery::AddMetavarPredicate(
    const std::string_view &name,
    std::function<bool(const MetavarMatch&)> predicate) {

  // Find metavariable name
  auto it = impl->m_metavars.find(name);
  if (it == impl->m_metavars.end()) {
    return false;
  }

  // Overwrite predicate
  if (it->second.m_predicate) {
    it->second.m_predicate =
        [old_pred = std::move(it->second.m_predicate.value()),
         new_pred = std::move(predicate)] (const MetavarMatch &mvm) -> bool {
      return old_pred(mvm) && new_pred(mvm);
    };

  } else {
    it->second.m_predicate = std::move(predicate);
  }

  return true;
}

void ParsedQuery::ForEachMatch(std::function<bool(Match)> pred) const {
  bool done = false;
  auto real_pred = [sub_pred = std::move(pred), &done] (Match m) -> bool {
    if (sub_pred(std::move(m))) {
      return true;
    } else {
      done = true;
      return false;
    }
  };
  for(auto frag_id : impl->m_ep->GetFragmentsInAST()) {
    ForEachMatch(frag_id, real_pred);
    if (done) {
      break;
    }
  }
}

std::vector<Match> ParsedQuery::Find(mx::RawEntityId frag) const {
  std::vector<Match> ret;
  ForEachMatch(frag, [&ret] (Match m) -> bool {
    ret.emplace_back(std::move(m));
    return true;
  });
  return ret;
}

std::vector<Match> ParsedQuery::Find(void) const {
  std::vector<Match> ret;
  for (auto frag_id : impl->m_ep->GetFragmentsInAST()) {
    ForEachMatch(frag_id, [&ret] (Match m) -> bool {
      ret.emplace_back(std::move(m));
      return true;
    });
  }
  return ret;
}

void ParsedQuery::ForEachMatch(mx::RawEntityId frag_id,
                               std::function<bool(Match)> pred) const {
  auto frag = impl->m_ep->FragmentFor(impl->m_ep, frag_id);

  // Find matching AST node
  auto &entry = impl->ParsesAtIndex(0);
  for (auto &[key, markers] : entry) {
    if (key.second != impl->m_input.size()) {
      continue;
    }
    if (key.first == NodeKind::Any()) {
      for (auto ast_node_id : impl->m_ep->GetASTNodesInFragment(frag_id)) {
        auto ast_node = impl->m_ep->GetASTNode(ast_node_id);
        for (auto &marker : markers) {
          auto [ok, metavar_matches] = impl->MatchMarker(
              entry, marker, ast_node_id);
          if (ok && !pred(Match(ast_node.entity, metavar_matches))) {
            return;
          }
        }
      }
    } else {
      auto ast_node_id = impl->m_ep->GetASTNodeWithKind(frag_id, key.first.Serialize());
      while (ast_node_id.has_value()) {
        auto ast_node = impl->m_ep->GetASTNode(*ast_node_id);
        for (auto &marker : markers) {
          auto [ok, metavar_matches] = impl->MatchMarker(entry, marker, *ast_node_id);
          if (ok && !pred(Match(ast_node.entity, metavar_matches))) {
            return;
          }
        }
        ast_node_id = ast_node.prev;
      }
    }
  }
}

}  // namespace syntex
}  // namespace mx
