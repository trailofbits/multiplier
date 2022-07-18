// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <iostream>
#include <multiplier/AST.h>
#include <multiplier/Fragment.h>

#include "BloomFilter.h"
#include "Parser.h"

namespace syntex {

template<typename F>
void Tokenize(F callback, std::string_view input, size_t index) {
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
    case '$':
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
        callback(kind, input.substr(begin, len), next);
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

  // Identifiers
  case '_':
  case '$':
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

Parser::Parser(const Grammar &grammar, std::string_view input)
  : m_grammar(grammar), m_input(input) {}

void Parser::MatchRule(std::vector<Fragment> &result, Item item, size_t position) {
  if (item.AtEnd()) {
    // Try to match the result as a new prefix
    MatchPrefix(result, Fragment(item.BloomFilter(),
                                    item.ResultingNode(m_ast), position));
  } else {
    // Otherwise see if we can move forward with this rule
    for (auto& frag : ParsesAtIndex(position)) {
      if (frag.node->Kind() == item.Cur()) {
        MatchRule(result, item.Forward(frag), frag.next);
      }
    }
  }
}

void Parser::MatchPrefix(std::vector<Fragment> &result, Fragment frag) {
  for (auto &rule : m_grammar.MatchProductions(frag.node->Kind())) {
    // Find all possible ways we can match this grammar rule
    MatchRule(result, Item(rule).Forward(frag), frag.next);
  }

  // Add the input fragment itself
  result.push_back(frag);
}

const std::vector<Fragment> &Parser::ParsesAtIndex(size_t index) {
  // Lookup memoized parses at this index
  auto parse = m_parses.find(index);
  if (parse != m_parses.end())
    return parse->second;

  // And only do computation if the lookup found nothing
  std::vector<Fragment> &result = m_parses[index];

  // Match a prefix for all tokens
  Tokenize([&] (mx::TokenKind kind, std::string_view spelling, size_t next) {
    // First match as the default token kind
    MatchPrefix(result, Fragment(
      m_ast.ConstructNode(kind, std::string(spelling)), next));

    // Then try checking for keywords
    if (kind == mx::TokenKind::IDENTIFIER) {
      auto kw = m_grammar.ClassifyIdent(spelling);
      if (kw.has_value())
        MatchPrefix(result, Fragment(
          m_ast.ConstructNode(*kw, std::string(spelling)), next));
    }
  }, m_input, index);

  return result;
}

void Parser::Query(const mx::Index &index) {
  // Iterate parses at index 0
  for (auto &frag : ParsesAtIndex(0)) {
    // Skip partial fragments
    if (frag.next != m_input.size())
      continue;

    // We don't care about partial fragments (for now)
    if (frag.next != m_input.size())
      continue;

    size_t likely_count = 0, actual_count = 0;

    // Find all mx fragments that might match this query fragment
    for (auto mx_frag_id : m_grammar.LikelyFragments(frag.BloomFilter())) {
      ++likely_count;

      // Find mx fragment object for it
      auto mx_frag = index.fragment(mx_frag_id).value();

      // Create syntex AST for fragment
      auto mx_frag_ast = AST::Build(mx_frag);

      // Find likely matching AST node
      const ASTNode *likely_node = mx_frag_ast.LastNodeOfKind(frag.node->Kind());

      bool in_mx_frag = false;
      for (; likely_node; likely_node = likely_node->prev_of_kind) {
        if (*likely_node == *frag.node) {
          in_mx_frag = true;
          break;
        }
      }

      if (in_mx_frag) {
        std::cout << "Found in fragment " << mx_frag_id << "\n";
        ++actual_count;
      }
    }

    std::cout << "Bloom filter ratio " << (double) actual_count / likely_count << "\n";
  }
}

} // namespace syntex
