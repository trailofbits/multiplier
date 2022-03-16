// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <variant>

namespace mx {

using FileId = uint64_t;
using CodeId = uint64_t;

enum class DeclKind : unsigned short;
enum class StmtKind : unsigned short;
enum class TokenKind : unsigned short;

static constexpr uint64_t kInvalidEntityId = 0u;
static constexpr uint64_t kMinEntityIdIncrement = 1u;

// If we have more than 2^16 tokens in a given code chunk, then we consider
// this a "big code" chunk. We assume that we'll have few of these, i.e. less
// than 2^16 of them.
static constexpr unsigned kBigCodeIdNumBits = 16u;
static constexpr uint64_t kMaxBigCodeId = 1ul << kBigCodeIdNumBits;
static constexpr uint64_t kNumTokensInBigCode = 1ul << kBigCodeIdNumBits;

struct DeclarationId {
  CodeId code_id;
  DeclKind kind;
  uint32_t offset;

  bool operator==(const DeclarationId &) const noexcept = default;
  bool operator!=(const DeclarationId &) const noexcept = default;
};

struct StatementId {
  CodeId code_id;
  StmtKind kind;
  uint32_t offset;

  bool operator==(const StatementId &) const noexcept = default;
  bool operator!=(const StatementId &) const noexcept = default;
};

struct TokenId {
  CodeId code_id;
  TokenKind kind;
  uint32_t offset;

  bool operator==(const TokenId &) const noexcept = default;
  bool operator!=(const TokenId &) const noexcept = default;
};

// A tag type representing an invalid entity id.
struct InvalidId {};

using VariantId = std::variant<InvalidId, DeclarationId, StatementId, TokenId>;

// An opaque, compressed entity id.
class EntityId {
 private:
  uint64_t opaque{kInvalidEntityId};

 public:
  /* implicit */ inline EntityId(uint64_t opaque_)
      : opaque(opaque_) {}

  inline operator uint64_t(void) const noexcept {
    return opaque;
  }

  explicit EntityId(DeclarationId id);
  explicit EntityId(StatementId id);
  explicit EntityId(TokenId id);

  // Unpack this entity ID into a concrete type.
  VariantId Unpack(void) const noexcept;
};

}  // namespace mx
