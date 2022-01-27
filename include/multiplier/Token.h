// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <memory>
#include <string_view>

#include "Result.h"
#include "Types.h"

namespace pasta {
class FileTokenRange;
class TokenRange;
class PrintedTokenRange;
}  // namespace pasta
namespace mx {

enum class TokenKind : uint16_t;  // Auto-generated from Datalog.
struct CompressedTokenList;  // Auto-generated from Datalog.

class TokenListImpl;
class TokenList {
 private:
  std::shared_ptr<TokenListImpl> impl;

  inline TokenList(std::shared_ptr<TokenListImpl> impl_)
      : impl(std::move(impl_)) {}

 public:

  TokenList(void);
  ~TokenList(void);

  // Return the token data as a single string.
  std::string_view Data(void) const noexcept;

  // Compress this token list into a Flatbuffers message.
  Result<flatbuffers::Offset<CompressedTokenList>, std::string> Compress(
      flatbuffers::FlatBufferBuilder &fbb);

  static TokenList Create(const pasta::FileTokenRange &toks);
  static TokenList Create(const pasta::PrintedTokenRange &toks);
  static TokenList Create(const pasta::TokenRange &toks);
  static Result<TokenList, std::string> Create(const CompressedTokenList &toks);

  inline static Result<TokenList, std::string>
  Create(const CompressedTokenList *toks) {
    if (toks) {
      return Create(*toks);
    } else {
      return TokenList();
    }
  }
};

}  // namespace mx
