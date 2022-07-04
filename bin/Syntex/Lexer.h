// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>
#include <multiplier/AST.h>
#include "Grammar.h"

namespace syntex {

class Grammar;

struct Token {
  size_t begin;
  size_t end;
  size_t next;
  mx::TokenKind kind;
  std::string_view spelling;
  Token(size_t b, size_t e, size_t n, mx::TokenKind k, std::string_view sv)
    : begin(b), end(e), next(n), kind(k), spelling(sv) {}
};

std::ostream& operator<<(std::ostream& os, const Token& tok);

std::vector<Token> Tokenize(const Grammar& grammar, std::string_view sv);

}  // namespace lexer
