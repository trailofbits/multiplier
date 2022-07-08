// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <iostream>
#include <multiplier/AST.h>

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
  if (item.AtEnd())
    // Try to match the result as a new prefix
    MatchPrefix(result, Fragment(item.ResultingNode(m_ast), position));
  else
    // Otherwise see if we can move forward with this rule
    for (auto& frag : ParsesAtIndex(position))
      if (NodeToNonTerminal(frag.node) == item.Cur())
        MatchRule(result, item.Forward(frag.node), frag.next);
}

void Parser::MatchPrefix(std::vector<Fragment> &result, Fragment frag) {
  for (auto &rule : m_grammar.MatchProductions(NodeToNonTerminal(frag.node))) {
    // Find all possible ways we can match this grammar rule
    MatchRule(result, Item(rule).Forward(frag.node), frag.next);
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
  std::vector<Fragment>& result = m_parses[index];

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

void Parser::Parse() {
  // Start computing parses at index 0
  auto fragments = ParsesAtIndex(0);

  // Print fragments at index 0
  std::cout << "-------------------\n";
  for (auto& frag : fragments)
    std::cout << "  " << NodeToNonTerminal(frag.node) << "\n";
  std::cout << "-------------------\n";

  // Print AST to cerr
  m_ast.PrintDOT(std::cerr);
}

void Parse(const Grammar &grammar, std::string_view query) {
  Parser parser(grammar, query);
  parser.Parse();
}

} // namespace syntex
