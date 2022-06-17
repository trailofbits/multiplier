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

class Fragment;
class FragmentImpl;

enum class DeclKind : unsigned char;
enum class StmtKind : unsigned char;
enum class TokenKind : unsigned short;
enum class TypeKind : unsigned char;

enum class TokenSubstitutionKind : unsigned char {
  MACRO_EXPANSION,
  FUNCTION_LIKE_MACRO_EXPANSION,
  INCLUDE_EXPANSION
};

using RawEntityId = uint64_t;

using RawFileId = uint64_t;
struct FileId {
  RawFileId value;

  inline constexpr bool operator==(const FileId &f) const noexcept { return value == f.value; }
  inline constexpr bool operator!=(const FileId &f) const noexcept { return value != f.value; }
  inline constexpr bool operator<(const FileId &f) const noexcept { return value < f.value; }
  inline constexpr bool operator<=(const FileId &f) const noexcept { return value <= f.value; }
  inline constexpr bool operator>(const FileId &f) const noexcept { return value > f.value; }
  inline constexpr bool operator>=(const FileId &f) const noexcept { return value >= f.value; }

  inline constexpr operator bool() { return value; }
};

using RawFragmentId = uint64_t;
struct FragmentId {
  RawFragmentId value;

  inline constexpr bool operator==(const FragmentId &f) const noexcept { return value == f.value; };
  inline constexpr bool operator!=(const FragmentId &f) const noexcept { return value != f.value; };
  inline constexpr bool operator<(const FragmentId &f) const noexcept { return value < f.value; }
  inline constexpr bool operator<=(const FragmentId &f) const noexcept { return value <= f.value; }
  inline constexpr bool operator>(const FragmentId &f) const noexcept { return value > f.value; }
  inline constexpr bool operator>=(const FragmentId &f) const noexcept { return value >= f.value; }

  inline constexpr operator bool() { return value; }
};

static constexpr FileId kInvalidFileId = {0};
static constexpr FragmentId kInvalidFragmentId = {0};
static constexpr RawEntityId kInvalidEntityId = 0ull;
static constexpr RawEntityId kMinEntityIdIncrement = 1ull;

// If we have more than 2^16 tokens in a given code chunk, then we consider
// this a "big code" chunk. We assume that we'll have few of these, i.e. less
// than 2^16 of them.
static constexpr unsigned kBigFragmentIdNumBits = 16u;
static constexpr uint64_t kMaxBigFragmentId = 1ull << kBigFragmentIdNumBits;
static constexpr uint64_t kNumTokensInBigFragment =
    1ull << kBigFragmentIdNumBits;

static constexpr unsigned kFileIdNumBits = 20u;
static constexpr uint64_t kMaxFileId = 1ull << kFileIdNumBits;

// Identifies a serialized version of a `clang::Decl` or `pasta::Decl`
// inside of a `Fragment`.
struct DeclarationId {
  FragmentId fragment_id;
  DeclKind kind;

  // Offset of this where this declaration is stored inside of
  // `rpc::Fragment::declarations`.
  uint32_t offset;

  // Is this declaration a definition?
  bool is_definition;

  bool operator==(const DeclarationId &) const noexcept = default;
  bool operator!=(const DeclarationId &) const noexcept = default;
};

// Identifies a serialized version of a `clang::Stmt` or `pasta::Stmt`
// inside of a `Fragment`.
struct StatementId {
  FragmentId fragment_id;
  StmtKind kind;

  // Offset of this where this statement is stored inside of
  // `rpc::Fragment::statements`.
  uint32_t offset;

  bool operator==(const StatementId &) const noexcept = default;
  bool operator!=(const StatementId &) const noexcept = default;
};

struct TypeId {
  FragmentId fragment_id;
  TypeKind kind;

  // Offset of this where this statement is stored inside of
  // `rpc::Fragment::types`.
  uint32_t offset;

  bool operator==(const TypeId &) const noexcept = default;
  bool operator!=(const TypeId &) const noexcept = default;
};

// Identifies a token inside of a `Fragment`.
struct FragmentTokenId {
  FragmentId fragment_id;
  TokenKind kind;

  // Offset of this where this token is stored inside of a serialized
  // `rpc::Fragment::tokenKinds` (and other token related lists).
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
using VariantId = std::variant<InvalidId, FileId, FragmentId, DeclarationId,
                               StatementId, TypeId, FragmentTokenId, FileTokenId,
                               TokenSubstitutionId>;

// An opaque, compressed entity id.
class EntityId {
 private:
  RawEntityId opaque{kInvalidEntityId};

 public:
  EntityId(void) = default;

  /* implicit */ inline EntityId(RawEntityId opaque_)
      : opaque(opaque_) {}

  // Pack an elaborated entity ID into an opaque entity ID.
  /* implicit */ EntityId(FileId id);
  /* implicit */ EntityId(FragmentId id);
  /* implicit */ EntityId(DeclarationId id);
  /* implicit */ EntityId(StatementId id);
  /* implicit */ EntityId(TypeId id);
  /* implicit */ EntityId(FragmentTokenId id);
  /* implicit */ EntityId(TokenSubstitutionId id);
  /* implicit */ EntityId(FileTokenId id);

  inline EntityId &operator=(DeclarationId id) {
    EntityId self(id);
    opaque = self.opaque;
    return *this;
  }

  inline EntityId &operator=(StatementId id) {
    EntityId self(id);
    opaque = self.opaque;
    return *this;
  }

  inline EntityId &operator=(TypeId id) {
    EntityId self(id);
    opaque = self.opaque;
    return *this;
  }

  inline EntityId &operator=(FragmentTokenId id) {
    EntityId self(id);
    opaque = self.opaque;
    return *this;
  }

  inline EntityId &operator=(TokenSubstitutionId id) {
    EntityId self(id);
    opaque = self.opaque;
    return *this;
  }

  inline EntityId &operator=(FileTokenId id) {
    EntityId self(id);
    opaque = self.opaque;
    return *this;
  }

  inline EntityId &operator=(RawEntityId id) {
    opaque = id;
    return *this;
  }

  inline operator RawEntityId(void) const noexcept {
    return opaque;
  }

  inline bool operator==(RawEntityId that) const noexcept {
    return opaque == that;
  }

  inline bool operator!=(RawEntityId that) const noexcept {
    return opaque != that;
  }

  inline bool operator==(EntityId that) const noexcept {
    return opaque == that.opaque;
  }

  inline bool operator!=(EntityId that) const noexcept {
    return opaque != that.opaque;
  }

  // Unpack this entity ID into a concrete type.
  VariantId Unpack(void) const noexcept;
};

}  // namespace mx

namespace std {
  template<>
  struct hash<mx::FileId> {
    std::size_t operator()(const mx::FileId& id) const noexcept {
      std::hash<uint64_t> h;
      return h(id.value);
    }
  };

  template<>
  struct hash<mx::FragmentId> {
    std::size_t operator()(const mx::FragmentId& id) const noexcept {
      std::hash<uint64_t> h;
      return h(id.value);
    }
  };
}
