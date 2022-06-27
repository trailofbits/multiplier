// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <exception>
#include <istream>
#include <memory>
#include <vector>

namespace lexer {

enum class TokenKind {
  // End of file
  EndFile,

  // Keywords
  Alignas,
  Alignof,
  Asm,
  Auto,
  Bool,
  Break,
  Case,
  Catch,
  Char,
  Char16T,
  Char32T,
  Class,
  Const,
  Constexpr,
  ConstCast,
  Continue,
  Decltype,
  Default,
  Delete,
  Do,
  Double,
  DynamicCast,
  Else,
  Enum,
  Explicit,
  Export,
  Extern,
  False,
  Float,
  For,
  Friend,
  Goto,
  If,
  Inline,
  Int,
  Long,
  Mutable,
  Namespace,
  New,
  Noexcept,
  Nullptr,
  Operator,
  Private,
  Protected,
  Public,
  Register,
  ReinterpretCast,
  Return,
  Short,
  Signed,
  Sizeof,
  Static,
  StaticAssert,
  StaticCast,
  Struct,
  Switch,
  Template,
  This,
  ThreadLocal,
  Throw,
  True,
  Try,
  Typedef,
  Typeid,
  Typename,
  Union,
  Unsigned,
  Using,
  Virtual,
  Void,
  Volatile,
  WcharT,
  While,

  // Identifiers
  Ident,

  // Constants
  IntegerConstant,
  FloatingConstant,
  CharConstant,
  StringLiteral,

  // Punctuators
  LSq,      // [
  RSq,      // ]
  LPar,     // (
  RPar,     // )
  LCur,     // {
  RCur,     // }
  Dot,      // .
  Arrow,    // ->
  Incr,     // ++
  Decr,     // --
  Ampr,     // &
  Star,     // *
  Plus,     // +
  Minus,    // -
  Tilde,    // ~
  Excl,     // !
  Slash,    // /
  Perc,     // %
  LSh,      // <<
  RSh,      // >>
  LAngle,   // <
  RAngle,   // >
  LtEq,     // <=
  GtEq,     // >=
  EqEq,     // ==
  NotEq,    // !=
  Caret,    // ^
  Pipe,     // |
  LogAnd,   // &&
  LogOr,    // ||
  Question, // ?
  Colon,    // :
  Semi,     // ;
  Ellipsis, // ...
  Eq,       // =
  MulEq,    // *=
  DivEq,    // /=
  RemEq,    // %=
  AddEq,    // +=
  SubEq,    // -=
  LshEq,    // <<=
  RshEq,    // >>=
  AndEq,    // &=
  XorEq,    // ^=
  OrEq,     // |=
  Comma,    // ,
  Hash,     // #
  Glue,     // ##

  // Unknown character
  Unk,
};

const char* EnumeratorName(TokenKind);

// Position of a token in a file
struct Span {
  size_t begin;
  size_t end;
  Span(size_t b, size_t e) : begin(b), end(e) {}
};

struct Token {
  Span span;
  std::string spelling;
  TokenKind kind;
  Token(Span spn, std::string spl, TokenKind k)
    : span(spn), spelling(std::move(spl)), kind(k) {}
};

// Character or EOF
using CharOpt = int;
// End of file marker
static const CharOpt EndFile = -1;

// Lexical analyzer
class Lexer {
private:
  static const size_t BUF_SZ = 8192;

  // Input stream and buffer
  std::istream& m_stream;
  char m_buf[BUF_SZ];
  char* m_begin{m_buf};
  char* m_end{m_buf};

  // Position in the input file
  size_t m_pos{0};
  // Spelling of the current token
  std::string m_spelling;

  // Look at the i-th character from the start
  CharOpt Look(size_t i);

  // Consume cnt characters of lookahead
  void Eat(size_t cnt);

  // Consume the next char if it's equal to wanted
  bool Match(char wanted) {
    if (Look(0) == wanted) {
      Eat(1);
      return true;
    }
    return false;
  }

  // Consume next char if it matches the predicate
  template<typename F>
  bool MatchPred(F pred) {
    if (pred(Look(0))) {
      Eat(1);
      return true;
    }
    return false;
  }

  // Read the next character
  CharOpt Get() {
    auto val = Look(0);
    if (val != EndFile)
      Eat(1);
    return val;
  }

  // Match a decimal exponent
  bool MatchDecimalExponent();
  // Match a hex exponent
  bool MatchHexExponent();
  // Match an integer suffix
  void MatchIntegerSuffix();
  // Match a floating point suffix
  void MatchFloatingSuffix();

public:
  explicit Lexer(std::istream& stream);

  // FIXME: add copy and move constructor that fixes up m_begin and m_end
  Lexer(Lexer&&) = delete;
  Lexer(const Lexer&) = delete;

  // Return the next token
  Token Next();
};

}  // namespace lexer
