// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <variant>

namespace mx {
namespace rpc {
class FileInfo;
}  // namespace rpc

using FileId = uint64_t;
using FragmentId = uint64_t;

class Fragment;
class FragmentImpl;

enum class DeclKind : unsigned short;
enum class StmtKind : unsigned short;
enum class TokenKind : unsigned short;

enum class TokenSubstitutionKind : unsigned short {
  MACRO_EXPANSION,
  FUNCTION_LIKE_MACRO_EXPANSION,
  INCLUDE_EXPANSION
};

static constexpr uint64_t kInvalidEntityId = 0ull;
static constexpr uint64_t kMinEntityIdIncrement = 1ull;

// If we have more than 2^16 tokens in a given code chunk, then we consider
// this a "big code" chunk. We assume that we'll have few of these, i.e. less
// than 2^16 of them.
static constexpr unsigned kBigFragmentIdNumBits = 16u;
static constexpr FragmentId kMaxBigFragmentId = 1ull << kBigFragmentIdNumBits;
static constexpr uint64_t kNumTokensInBigFragment =
    1ull << kBigFragmentIdNumBits;

static constexpr unsigned kFileIdNumBits = 20u;
static constexpr FileId kMaxFileId = 1ull << kFileIdNumBits;

// Identifies a serialized version of a `clang::Decl` or `pasta::Decl`
// inside of a `Fragment`.
struct DeclarationId {
  FragmentId fragment_id;
  DeclKind kind;

  // Offset of this where this declaration is stored inside of
  // `rpc::Fragment::entities`.
  uint32_t offset;

  bool operator==(const DeclarationId &) const noexcept = default;
  bool operator!=(const DeclarationId &) const noexcept = default;
};

// Identifies a serialized version of a `clang::Stmt` or `pasta::Stmt`
// inside of a `Fragment`.
struct StatementId {
  FragmentId fragment_id;
  StmtKind kind;

  // Offset of this where this statement is stored inside of
  // `rpc::Fragment::entities`.
  uint32_t offset;

  bool operator==(const StatementId &) const noexcept = default;
  bool operator!=(const StatementId &) const noexcept = default;
};

// Identifies a token inside of a `Fragment`.
struct FragmentTokenId {
  FragmentId fragment_id;
  TokenKind kind;

  // Offset of this where this token is stored inside of a serialized
  // `rpc::Fragment::tokens`.
  uint32_t offset;

  bool operator==(const FragmentTokenId &) const noexcept = default;
  bool operator!=(const FragmentTokenId &) const noexcept = default;
};

// The offset of a substitution inside of a fragment.
struct TokenSubstitutionId {
 public:
  FragmentId fragment_id;

  TokenSubstitutionKind kind;

  // Offset of this where this token substitution is stored inside of a
  // serialized `rpc::Fragment::tokenSubstitutions`.
  uint32_t offset;

  bool operator==(const TokenSubstitutionId &) const noexcept = default;
  bool operator!=(const TokenSubstitutionId &) const noexcept = default;
};

// Identifies a token inside of a `File`.
struct FileTokenId {
  FileId file_id;
  TokenKind kind;

  // Offset of this where this token is stored inside of a serialized
  // `rpc::File::tokens` list.
  uint32_t offset;

  bool operator==(const FileTokenId &) const noexcept = default;
  bool operator!=(const FileTokenId &) const noexcept = default;
};

// A tag type representing an invalid entity id.
struct InvalidId {};

// Possible types of entity ids represented by a packed
// `EntityId`.
using VariantId = std::variant<InvalidId, DeclarationId,
                               StatementId, FragmentTokenId,
                               TokenSubstitutionId, FileTokenId>;

// An opaque, compressed entity id.
class EntityId {
 private:
  uint64_t opaque{kInvalidEntityId};

 public:
  /* implicit */ inline EntityId(uint64_t opaque_)
      : opaque(opaque_) {}

  // Pack an elaborated entity ID into an opaque entity ID.
  /* implicit */ EntityId(DeclarationId id);
  /* implicit */ EntityId(StatementId id);
  /* implicit */ EntityId(FragmentTokenId id);
  /* implicit */ EntityId(TokenSubstitutionId id);
  /* implicit */ EntityId(FileTokenId id);

  inline operator uint64_t(void) const noexcept {
    return opaque;
  }

  // Unpack this entity ID into a concrete type.
  VariantId Unpack(void) const noexcept;
};

}  // namespace mx
