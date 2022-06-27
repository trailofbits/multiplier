// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <cerrno>
#include <iostream>
#include <unordered_map>
#include "Lexer.h"

namespace lexer {

const char* EnumeratorName(TokenKind kind) {
  switch (kind) {
  case TokenKind::EndFile: return "EndFile";
  case TokenKind::Alignas: return "Alignas";
  case TokenKind::Alignof: return "Alignof";
  case TokenKind::Asm: return "Asm";
  case TokenKind::Auto: return "Auto";
  case TokenKind::Bool: return "Bool";
  case TokenKind::Break: return "Break";
  case TokenKind::Case: return "Case";
  case TokenKind::Catch: return "Catch";
  case TokenKind::Char: return "Char";
  case TokenKind::Char16T: return "Char16T";
  case TokenKind::Char32T: return "Char32T";
  case TokenKind::Class: return "Class";
  case TokenKind::Const: return "Const";
  case TokenKind::Constexpr: return "Constexpr";
  case TokenKind::ConstCast: return "ConstCast";
  case TokenKind::Continue: return "Continue";
  case TokenKind::Decltype: return "Decltype";
  case TokenKind::Default: return "Default";
  case TokenKind::Delete: return "Delete";
  case TokenKind::Do: return "Do";
  case TokenKind::Double: return "Double";
  case TokenKind::DynamicCast: return "DynamicCast";
  case TokenKind::Else: return "Else";
  case TokenKind::Enum: return "Enum";
  case TokenKind::Explicit: return "Explicit";
  case TokenKind::Export: return "Export";
  case TokenKind::Extern: return "Extern";
  case TokenKind::False: return "False";
  case TokenKind::Float: return "Float";
  case TokenKind::For: return "For";
  case TokenKind::Friend: return "Friend";
  case TokenKind::Goto: return "Goto";
  case TokenKind::If: return "If";
  case TokenKind::Inline: return "Inline";
  case TokenKind::Int: return "Int";
  case TokenKind::Long: return "Long";
  case TokenKind::Mutable: return "Mutable";
  case TokenKind::Namespace: return "Namespace";
  case TokenKind::New: return "New";
  case TokenKind::Noexcept: return "Noexcept";
  case TokenKind::Nullptr: return "Nullptr";
  case TokenKind::Operator: return "Operator";
  case TokenKind::Private: return "Private";
  case TokenKind::Protected: return "Protected";
  case TokenKind::Public: return "Public";
  case TokenKind::Register: return "Register";
  case TokenKind::ReinterpretCast: return "ReinterpretCast";
  case TokenKind::Return: return "Return";
  case TokenKind::Short: return "Short";
  case TokenKind::Signed: return "Signed";
  case TokenKind::Sizeof: return "Sizeof";
  case TokenKind::Static: return "Static";
  case TokenKind::StaticAssert: return "StaticAssert";
  case TokenKind::StaticCast: return "StaticCast";
  case TokenKind::Struct: return "Struct";
  case TokenKind::Switch: return "Switch";
  case TokenKind::Template: return "Template";
  case TokenKind::This: return "This";
  case TokenKind::ThreadLocal: return "ThreadLocal";
  case TokenKind::Throw: return "Throw";
  case TokenKind::True: return "True";
  case TokenKind::Try: return "Try";
  case TokenKind::Typedef: return "Typedef";
  case TokenKind::Typeid: return "Typeid";
  case TokenKind::Typename: return "Typename";
  case TokenKind::Union: return "Union";
  case TokenKind::Unsigned: return "Unsigned";
  case TokenKind::Using: return "Using";
  case TokenKind::Virtual: return "Virtual";
  case TokenKind::Void: return "Void";
  case TokenKind::Volatile: return "Volatile";
  case TokenKind::WcharT: return "WcharT";
  case TokenKind::While: return "While";
  case TokenKind::Ident: return "Ident";
  case TokenKind::IntegerConstant: return "IntegerConstant";
  case TokenKind::FloatingConstant: return "FloatingConstant";
  case TokenKind::CharConstant: return "CharConstant";
  case TokenKind::StringLiteral: return "StringLiteral";
  case TokenKind::LSq: return "LSq";
  case TokenKind::RSq: return "RSq";
  case TokenKind::LPar: return "LPar";
  case TokenKind::RPar: return "RPar";
  case TokenKind::LCur: return "LCur";
  case TokenKind::RCur: return "RCur";
  case TokenKind::Dot: return "Dot";
  case TokenKind::Arrow: return "Arrow";
  case TokenKind::Incr: return "Incr";
  case TokenKind::Decr: return "Decr";
  case TokenKind::Ampr: return "Ampr";
  case TokenKind::Star: return "Star";
  case TokenKind::Plus: return "Plus";
  case TokenKind::Minus: return "Minus";
  case TokenKind::Tilde: return "Tilde";
  case TokenKind::Excl: return "Excl";
  case TokenKind::Slash: return "Slash";
  case TokenKind::Perc: return "Perc";
  case TokenKind::LSh: return "LSh";
  case TokenKind::RSh: return "RSh";
  case TokenKind::LAngle: return "LAngle";
  case TokenKind::RAngle: return "RAngle";
  case TokenKind::LtEq: return "LtEq";
  case TokenKind::GtEq: return "GtEq";
  case TokenKind::EqEq: return "EqEq";
  case TokenKind::NotEq: return "NotEq";
  case TokenKind::Caret: return "Caret";
  case TokenKind::Pipe: return "Pipe";
  case TokenKind::LogAnd: return "LogAnd";
  case TokenKind::LogOr: return "LogOr";
  case TokenKind::Question: return "Question";
  case TokenKind::Colon: return "Colon";
  case TokenKind::Semi: return "Semi";
  case TokenKind::Ellipsis: return "Ellipsis";
  case TokenKind::Eq: return "Eq";
  case TokenKind::MulEq: return "MulEq";
  case TokenKind::DivEq: return "DivEq";
  case TokenKind::RemEq: return "RemEq";
  case TokenKind::AddEq: return "AddEq";
  case TokenKind::SubEq: return "SubEq";
  case TokenKind::LshEq: return "LshEq";
  case TokenKind::RshEq: return "RshEq";
  case TokenKind::AndEq: return "AndEq";
  case TokenKind::XorEq: return "XorEq";
  case TokenKind::OrEq: return "OrEq";
  case TokenKind::Comma: return "Comma";
  case TokenKind::Hash: return "Hash";
  case TokenKind::Glue: return "Glue";
  case TokenKind::Unk: return "Unk";
  default: assert(0);
  }
}

static const std::unordered_map<std::string_view, TokenKind> kKeywordTable = {
  { "alignas", TokenKind::Alignas },
  { "alignof", TokenKind::Alignof },
  { "asm", TokenKind::Asm },
  { "auto", TokenKind::Auto },
  { "bool", TokenKind::Bool },
  { "break", TokenKind::Break },
  { "case", TokenKind::Case },
  { "catch", TokenKind::Catch },
  { "char", TokenKind::Char },
  { "char16_t", TokenKind::Char16T },
  { "char32_t", TokenKind::Char32T },
  { "class", TokenKind::Class },
  { "const", TokenKind::Const },
  { "constexpr", TokenKind::Constexpr },
  { "const_cast", TokenKind::ConstCast },
  { "continue", TokenKind::Continue },
  { "decltype", TokenKind::Decltype },
  { "default", TokenKind::Default },
  { "delete", TokenKind::Delete },
  { "do", TokenKind::Do },
  { "double", TokenKind::Double },
  { "dynamic_cast", TokenKind::DynamicCast },
  { "else", TokenKind::Else },
  { "enum", TokenKind::Enum },
  { "explicit", TokenKind::Explicit },
  { "export", TokenKind::Export },
  { "extern", TokenKind::Extern },
  { "false", TokenKind::False },
  { "float", TokenKind::Float },
  { "for", TokenKind::For },
  { "friend", TokenKind::Friend },
  { "goto", TokenKind::Goto },
  { "if", TokenKind::If },
  { "inline", TokenKind::Inline },
  { "int", TokenKind::Int },
  { "long", TokenKind::Long },
  { "mutable", TokenKind::Mutable },
  { "namespace", TokenKind::Namespace },
  { "new", TokenKind::New },
  { "noexcept", TokenKind::Noexcept },
  { "nullptr", TokenKind::Nullptr },
  { "operator", TokenKind::Operator },
  { "private", TokenKind::Private },
  { "protected", TokenKind::Protected },
  { "public", TokenKind::Public },
  { "register", TokenKind::Register },
  { "reinterpret_cast", TokenKind::ReinterpretCast },
  { "return", TokenKind::Return },
  { "short", TokenKind::Short },
  { "signed", TokenKind::Signed },
  { "sizeof", TokenKind::Sizeof },
  { "static", TokenKind::Static },
  { "static_assert", TokenKind::StaticAssert },
  { "static_cast", TokenKind::StaticCast },
  { "struct", TokenKind::Struct },
  { "switch", TokenKind::Switch },
  { "template", TokenKind::Template },
  { "this", TokenKind::This },
  { "thread_local", TokenKind::ThreadLocal },
  { "throw", TokenKind::Throw },
  { "true", TokenKind::True },
  { "try", TokenKind::Try },
  { "typedef", TokenKind::Typedef },
  { "typeid", TokenKind::Typeid },
  { "typename", TokenKind::Typename },
  { "union", TokenKind::Union },
  { "unsigned", TokenKind::Unsigned },
  { "using", TokenKind::Using },
  { "virtual", TokenKind::Virtual },
  { "void", TokenKind::Void },
  { "volatile", TokenKind::Volatile },
  { "wchar_t", TokenKind::WcharT },
  { "while", TokenKind::While },
};

TokenKind ClassifyIdent(std::string& spelling) {
  auto iter = kKeywordTable.find(spelling);
  if (iter != kKeywordTable.end())
    return iter->second;
  return TokenKind::Ident;
}

Lexer::Lexer(std::istream& stream)
  : m_stream(stream) {}

CharOpt Lexer::Look(size_t i) {
  // Ensure we never look ahead further then we have buffer space available
  assert(i < BUF_SZ / 2);

  // We can bail if i is in bounds
  if (m_begin + i < m_end)
    return m_begin[i];

  // Otherwise copy buffer contents to the beginning
  char* prev_begin = m_begin;
  char* prev_end = m_end;
  m_begin = m_buf;
  m_end = m_buf;
  while (prev_begin < prev_end)
    *m_end++ = *prev_begin++;

  // Then fill buffer from input stream
  // m_begin points as many bytes after m_buf as we have unconsumed lookahead.
  // For this operation to be safe we need to make sure Look is never called
  // with i >= BUF_SZ / 2 otherwise this read *will* write out of bounds of
  // m_buf. The assertion at the start of this function ensures this never
  // happens.
  m_stream.read(m_begin, BUF_SZ / 2);
  m_end += m_stream.gcount();

  // If i is still not in bounds we now know it is outside the file
  if (m_begin + i < m_end)
    return m_begin[i];
  else
    return EndFile;
}

void Lexer::Eat(size_t cnt) {
  // Ensure that we never consume more lookahead then we have available
  assert(cnt <= m_end - m_begin);

  m_spelling.append(m_begin, m_begin + cnt);
  m_begin += cnt;
  m_pos += cnt;
}

bool Lexer::MatchDecimalExponent() {
  if (Match('e') || Match('E')) {
    Match('+') || Match('-');
    return true;
  }
  return false;
}

bool Lexer::MatchHexExponent() {
  if (Match('p') || Match('P')) {
    Match('+') || Match('-');
    return true;
  }
  return false;
}

void Lexer::MatchIntegerSuffix() {
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

void Lexer::MatchFloatingSuffix() {
  if (Match('f') || Match('F')) {           // f
    // float
  } else if (Match('l') || Match('L')) {    // l
    // long double
  } else {                                  // <nothing>
    // double
  }
}

bool IsDecimal(char ch) {
  switch (ch) {
  case '0' ... '9':
    return true;
  default:
    return false;
  }
}

bool IsHex(char ch) {
  switch (ch) {
  case '0' ... '9':
  case 'a' ... 'f':
  case 'A' ... 'F':
    return true;
  default:
    return false;
  }
}

Token Lexer::Next() {
  // Skip all whitespaces that might preceed the token
  while (MatchPred([] (char ch) {
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
  }));

  // Save starting position and clear spelling
  size_t begin = m_pos;
  m_spelling.clear();

  #define TOKEN(kind) \
    Token(Span(begin, m_pos), std::move(m_spelling), kind)

  TokenKind kind;

  switch (Get()) {
  case EndFile:
    return TOKEN(TokenKind::EndFile);
  case '_':
  case '$':
  case 'a' ... 'z':
  case 'A' ... 'Z':
    while (MatchPred([] (char ch) {
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
    }));
    // NOTE: this cannot be inlined on the line below because the evaluation
    // order of function arguments is undefined and the string might be moved
    // before it is classified
    kind = ClassifyIdent(m_spelling);
    return TOKEN(kind);
  case '.':
    if (MatchPred(IsDecimal)) {
      // Fractional floating point constant
      while (MatchPred(IsDecimal));
      if (MatchDecimalExponent())
        while (MatchPred(IsDecimal));
      MatchFloatingSuffix();
      return TOKEN(TokenKind::FloatingConstant);
    } else if (Look(0) == '.' && Look(1) == '.') {
      // Variable argumen marker (...)
      Eat(2);
      return TOKEN(TokenKind::Ellipsis);
    } else {
      // . Dot operator
      return TOKEN(TokenKind::Dot);
    }
  case '0':
    if (Match('.')) {
      // Fractional floating constant
      while (MatchPred(IsDecimal));
      if (MatchDecimalExponent())
        while (MatchPred(IsDecimal));
      MatchFloatingSuffix();
      return TOKEN(TokenKind::FloatingConstant);
    } else if (Match('x') || Match('X')) {
      while (MatchPred(IsHex));
      if (Match('.')) {
        // Hex fractional floating constant
        while (MatchPred(IsHex));
        if (MatchHexExponent())
          while(MatchPred(IsHex));
        MatchFloatingSuffix();
        return TOKEN(TokenKind::FloatingConstant);
      } else if (MatchHexExponent()) {
        // Hex floating constant with exponent
        while (MatchPred(IsHex));
        MatchFloatingSuffix();
        return TOKEN(TokenKind::FloatingConstant);
      } else {
        // Hex integer constnat
        MatchIntegerSuffix();
        return TOKEN(TokenKind::IntegerConstant);
      }
    } else {
      // Octal integer constant
      while (MatchPred([] (char ch) {
        switch (ch) {
        case '0' ... '7':
          return true;
        default:
          return false;
        }
      }));
      MatchIntegerSuffix();
      return TOKEN(TokenKind::IntegerConstant);
    }
  case '1' ... '9':
    while (MatchPred(IsDecimal));
    if (Match('.')) {
      // Fractional floating constant
      while (MatchPred(IsDecimal));
      if (MatchDecimalExponent())
        while (MatchPred(IsDecimal));
      MatchFloatingSuffix();
      return TOKEN(TokenKind::FloatingConstant);
    } else if (MatchDecimalExponent()) {
      // Floating constant with just exponent
      while (MatchPred(IsDecimal));
      MatchFloatingSuffix();
      return TOKEN(TokenKind::FloatingConstant);
    } else {
      // Decimal integer constant
      MatchIntegerSuffix();
      return TOKEN(TokenKind::IntegerConstant);
    }
  case '\'':
    for (;;) {
      auto ch = Get();
      if (ch == '\\')
        ch = Get();
      else if (ch == '\'')
        break;
    }
    return TOKEN(TokenKind::CharConstant);
  case '"':
    for (;;) {
      auto ch = Get();
      if (ch == '\\')
        ch = Get();
      else if (ch == '"')
        break;
    }
    return TOKEN(TokenKind::StringLiteral);
  case '[': return TOKEN(TokenKind::LSq);
  case ']': return TOKEN(TokenKind::RSq);
  case '(': return TOKEN(TokenKind::LPar);
  case ')': return TOKEN(TokenKind::RPar);
  case '{': return TOKEN(TokenKind::LCur);
  case '}': return TOKEN(TokenKind::RCur);
  case '~': return TOKEN(TokenKind::Tilde);
  case '?': return TOKEN(TokenKind::Question);
  case ':': return TOKEN(TokenKind::Colon);
  case ';': return TOKEN(TokenKind::Semi);
  case ',': return TOKEN(TokenKind::Comma);
  case '-':
    if (Match('>'))
      return TOKEN(TokenKind::Arrow);
    else if (Match('-'))
      return TOKEN(TokenKind::Decr);
    else if (Match('='))
      return TOKEN(TokenKind::SubEq);
    else
      return TOKEN(TokenKind::Minus);
  case '+':
    if (Match('+'))
      return TOKEN(TokenKind::Incr);
    else if (Match('='))
      return TOKEN(TokenKind::AddEq);
    else
      return TOKEN(TokenKind::Plus);
  case '&':
    if (Match('&'))
      return TOKEN(TokenKind::LogAnd);
    else if (Match('='))
      return TOKEN(TokenKind::AndEq);
    else
      return TOKEN(TokenKind::Ampr);
  case '*':
    if (Match('='))
      return TOKEN(TokenKind::MulEq);
    else
      return TOKEN(TokenKind::Star);
  case '!':
    if (Match('='))
      return TOKEN(TokenKind::NotEq);
    else
      return TOKEN(TokenKind::Tilde);
  case '/':
    if (Match('='))
      return TOKEN(TokenKind::DivEq);
    else
      return TOKEN(TokenKind::Slash);
  case '%':
    if (Match('='))
      return TOKEN(TokenKind::RemEq);
    else
      return TOKEN(TokenKind::Perc);
  case '<':
    if (Match('<')) {
      if (Match('='))
        return TOKEN(TokenKind::LshEq);
      else
        return TOKEN(TokenKind::LSh);
    } else if (Match('=')) {
      return TOKEN(TokenKind::LtEq);
    } else {
      return TOKEN(TokenKind::LAngle);
    }
  case '>':
    if (Match('>')) {
      if (Match('='))
        return TOKEN(TokenKind::RshEq);
      else
        return TOKEN(TokenKind::RSh);
    } else if (Match('=')) {
      return TOKEN(TokenKind::GtEq);
    } else {
      return TOKEN(TokenKind::RAngle);
    }
  case '=':
    if (Match('='))
      return TOKEN(TokenKind::EqEq);
    else
      return TOKEN(TokenKind::Eq);
  case '^':
    if (Match('='))
      return TOKEN(TokenKind::XorEq);
    else
      return TOKEN(TokenKind::Caret);
  case '|':
    if (Match('='))
      return TOKEN(TokenKind::OrEq);
    else
      return TOKEN(TokenKind::Pipe);
  case '#':
    if (Match('#'))
      return TOKEN(TokenKind::Glue);
    else
      return TOKEN(TokenKind::Hash);
  default:
    return TOKEN(TokenKind::Unk);
  }

  #undef TOKEN
}

}  // namespace lexer
