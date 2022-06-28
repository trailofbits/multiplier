// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include "Grammar.h"
#include "Lexer.h"

namespace lexer {

std::ostream& operator<<(std::ostream& os, const Token& tok) {
  return os << "Token(" << tok.begin << ", " << tok.end << ", "
      << EnumeratorName(tok.kind) << ", " << tok.spelling << ")";
}

static const int EndFile = -1;

bool IsSpace(int ch) {
  switch (ch) {
  case ' ':
  case '\f':
  case '\n':
  case '\r':
  case '\t':
  case '\v':
    return true;
  default:
    return false;
  }
}

bool IsIdent(int ch) {
  switch (ch) {
  case '_':
  case '$':
  case 'a' ... 'z':
  case 'A' ... 'Z':
  case '0' ... '9':
    return true;
  default:
    return false;
  }
}

bool IsDecimal(int ch) {
  switch (ch) {
  case '0' ... '9':
    return true;
  default:
    return false;
  }
}

bool IsHex(int ch) {
  switch (ch) {
  case '0' ... '9':
  case 'a' ... 'f':
  case 'A' ... 'F':
    return true;
  default:
    return false;
  }
}

bool IsOct(int ch) {
  switch (ch) {
  case '0' ... '7':
    return true;
  default:
    return false;
  }
}

class Lexer {
private:
  std::vector<Token> m_tokens;
  const syntex::Grammar& m_grammar;
  std::string_view m_sv;
  size_t m_begin;
  size_t m_end;

private:
  int Look(size_t i) {
    if (m_end + i < m_sv.size())
      return m_sv[m_end + i];
    else
      return -1;
  }

  void Eat(size_t cnt) {
    m_end += cnt;
  }

  int Get() {
    int ch = Look(0);
    if (ch != EndFile)
      Eat(1);
    return ch;
  }

  bool Match(char ch) {
    if (Look(0) == ch) {
      Eat(1);
      return true;
    }
    return false;
  }

  template<typename F>
  bool MatchPred(F pred) {
    if (pred(Look(0))) {
      Eat(1);
      return true;
    }
    return false;
  }

  bool MatchDecimalExponent() {
    if (Match('e') || Match('E')) {
      Match('+') || Match('-');
      return true;
    }
    return false;
  }

  bool MatchHexExponent() {
    if (Match('p') || Match('P')) {
      Match('+') || Match('-');
      return true;
    }
    return false;
  }

  void MatchIntegerSuffix() {
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
  }

  void MatchFloatingSuffix() {
    if (Match('f') || Match('F')) {           // f
      // float
    } else if (Match('l') || Match('L')) {    // l
      // long double
    } else {                                  // <nothing>
      // double
    }
  }

  void AddIdent() {
    auto spelling = m_sv.substr(m_begin, m_end - m_begin);
    auto kind = m_grammar.ClassifyIdent(spelling);
    m_tokens.emplace_back(m_begin, m_end, kind, spelling);
  }

  void AddToken(size_t len, mx::TokenKind kind) {
    m_tokens.emplace_back(
      m_begin,
      m_begin + len,
      kind,
      m_sv.substr(m_begin, len));
  }

public:
  Lexer(const syntex::Grammar& grammar, std::string_view sv)
    : m_grammar(grammar), m_sv(sv), m_begin(0), m_end(0) {}

  std::vector<Token> Tokenize() {
    for (;;) {
      // Skip all whitespaces that might preceed the token
      while (MatchPred(IsSpace))
        ;

      // Save starting index of the token
      m_begin = m_end;

      switch (Get()) {
      // End of input
      case EndFile:
        return std::move(m_tokens);

      //
      // For identifiers and constants, the longest match is always consumed
      //

      // Identifiers
      case '_':
      case '$':
      case 'a' ... 'z':
      case 'A' ... 'Z':
        while (MatchPred(IsIdent))
          ;

        AddIdent();
        break;

      // Numeric constants
      case '0':
        if (Match('.')) {
          while (MatchPred(IsDecimal))
            ;

          if (MatchDecimalExponent()) {
            while (MatchPred(IsDecimal))
              ;
          }

          MatchFloatingSuffix();
        } else if (Match('x') || Match('X')) {
          while (MatchPred(IsHex))
            ;

          if (Match('.')) {
            while (MatchPred(IsHex))
              ;

            if (MatchHexExponent()) {
              while(MatchPred(IsHex))
                ;
            }
            MatchFloatingSuffix();
          } else if (MatchHexExponent()) {
            while (MatchPred(IsHex))
              ;

            MatchFloatingSuffix();
          } else {
            MatchIntegerSuffix();
          }
        } else {
          while (MatchPred(IsOct))
            ;

          MatchIntegerSuffix();
        }

        AddToken(m_end - m_begin, mx::TokenKind::NUMERIC_CONSTANT);
        break;

      case '1' ... '9':
        while (MatchPred(IsDecimal))
          ;

        if (Match('.')) {
FractionalConstant:
          while (MatchPred(IsDecimal))
            ;

          if (MatchDecimalExponent()) {
            while (MatchPred(IsDecimal))
              ;
          }

          MatchFloatingSuffix();
        } else if (MatchDecimalExponent()) {
          while (MatchPred(IsDecimal))
            ;
          MatchFloatingSuffix();
        } else {
          MatchIntegerSuffix();
        }

        AddToken(m_end - m_begin, mx::TokenKind::NUMERIC_CONSTANT);
        break;

      // Character constants
      case '\'':
        for (;;) {
          auto ch = Get();
          if (ch == '\\')
            Get();
          else if (ch == EndFile || ch == '\'')
            break;
        }

        AddToken(m_end - m_begin, mx::TokenKind::CHARACTER_CONSTANT);
        break;

      // String literals
      case '"':
        for (;;) {
          auto ch = Get();
          if (ch == '\\')
            Get();
          else if (ch == EndFile || ch == '"')
            break;
        }
        AddToken(m_end - m_begin, mx::TokenKind::STRING_LITERAL);
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
        if (MatchPred(IsDecimal)) {
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
  }
};

std::vector<Token> Tokenize(const syntex::Grammar& grammar, std::string_view sv) {
  Lexer lexer(grammar, sv);
  return lexer.Tokenize();
}

}  // namespace lexer
