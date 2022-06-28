// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <compare>
#include <cstdint>
#include <functional>
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

static constexpr RawEntityId kInvalidEntityId = 0ull;
static constexpr RawEntityId kMinEntityIdIncrement = 1ull;

// If we have more than 2^16 tokens in a given code chunk, then we consider
// this a "big code" chunk. We assume that we'll have few of these, i.e. less
// than 2^16 of them.
static constexpr unsigned kBigFragmentIdNumBits = 16u;
static constexpr RawEntityId kMaxBigFragmentId = 1ull << kBigFragmentIdNumBits;
static constexpr uint64_t kNumTokensInBigFragment =
    1ull << kBigFragmentIdNumBits;

static constexpr unsigned kFileIdNumBits = 20u;
static constexpr RawEntityId kMaxFileId = 1ull << kFileIdNumBits;

struct DeclarationId;
struct StatementId;
struct TypeId;
struct FileTokenId;
struct FragmentTokenId;
struct TokenSubstitutionId;
struct DesignatorId;

// Identifies a serialized fragment.
struct FragmentId {
  RawEntityId fragment_id;

  auto operator<=>(const FragmentId &) const noexcept = default;

  inline explicit FragmentId(RawEntityId fragment_id_)
      : fragment_id(fragment_id_) {}

  inline /* implicit */ FragmentId(const DeclarationId &);
  inline /* implicit */ FragmentId(const StatementId &);
  inline /* implicit */ FragmentId(const TypeId &);
  inline /* implicit */ FragmentId(const FragmentTokenId &);
  inline /* implicit */ FragmentId(const TokenSubstitutionId &);
  inline /* implicit */ FragmentId(const DesignatorId &);
};

// Identifies a serialized file.
struct FileId {
  RawEntityId file_id;
  
  auto operator<=>(const FileId &) const noexcept = default;

  inline explicit FileId(RawEntityId file_id_)
      : file_id(file_id_) {}

  inline /* implicit */ FileId(const FileTokenId &);
};

// Identifies a serialized version of a `clang::Decl` or `pasta::Decl`
// inside of a `Fragment`.
struct DeclarationId {
  RawEntityId fragment_id;
  DeclKind kind;

  // Offset of where this declaration is stored inside of
  // `rpc::Fragment::declarations`.
  uint32_t offset;

  // Is this declaration a definition?
  bool is_definition;

  auto operator<=>(const DeclarationId &) const noexcept = default;
};

// Identifies a serialized version of a `clang::Stmt` or `pasta::Stmt`
// inside of a `Fragment`.
struct StatementId {
  RawEntityId fragment_id;
  StmtKind kind;

  // Offset of where this statement is stored inside of
  // `rpc::Fragment::statements`.
  uint32_t offset;

  auto operator<=>(const StatementId &) const noexcept = default;
};

struct TypeId {
  RawEntityId fragment_id;
  TypeKind kind;

  // Offset of where this statement is stored inside of
  // `rpc::Fragment::types`.
  uint32_t offset;

  auto operator<=>(const TypeId &) const noexcept = default;
};

// Identifies a token inside of a `Fragment`.
struct FragmentTokenId {
  RawEntityId fragment_id;
  TokenKind kind;

  // Offset of where this token is stored inside of a serialized
  // `rpc::Fragment::tokenKinds` (and other token related lists).
  uint32_t offset;

  auto operator<=>(const FragmentTokenId &) const noexcept = default;
};

// The offset of a substitution inside of a fragment.
struct TokenSubstitutionId {
 public:
  RawEntityId fragment_id;

  TokenSubstitutionKind kind;

  // Offset of where this token substitution is stored inside of a
  // serialized `rpc::Fragment::tokenSubstitutions`.
  uint32_t offset;

  auto operator<=>(const TokenSubstitutionId &) const noexcept = default;
};

struct DesignatorId {
 public:
  RawEntityId fragment_id;

  // Offset of 
  uint32_t offset;

  auto operator<=>(const DesignatorId &) const noexcept = default;
};

// Identifies a token inside of a `File`.
struct FileTokenId {
  RawEntityId file_id;
  TokenKind kind;

  // Offset of this where this token is stored inside of a serialized
  // `rpc::File::tokens` list.
  uint32_t offset;

  auto operator<=>(const FileTokenId &) const noexcept = default;
};

inline FragmentId::FragmentId(const DeclarationId &id_)
    : fragment_id(id_.fragment_id) {}

inline FragmentId::FragmentId(const StatementId &id_)
    : fragment_id(id_.fragment_id) {}

inline FragmentId::FragmentId(const TypeId &id_)
    : fragment_id(id_.fragment_id) {}

inline FragmentId::FragmentId(const FragmentTokenId &id_)
    : fragment_id(id_.fragment_id) {}

inline FragmentId::FragmentId(const TokenSubstitutionId &id_)
    : fragment_id(id_.fragment_id) {}

inline FragmentId::FragmentId(const DesignatorId &id_)
    : fragment_id(id_.fragment_id) {}

inline FileId::FileId(const FileTokenId &id_)
    : file_id(id_.file_id) {}

// A tag type representing an invalid entity id.
struct InvalidId {};

// Possible types of entity ids represented by a packed
// `EntityId`.
using VariantId = std::variant<InvalidId, FileId, FragmentId,
                               DeclarationId, StatementId, TypeId,
                               FragmentTokenId, FileTokenId,
                               TokenSubstitutionId, DesignatorId>;

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
  /* implicit */ EntityId(DesignatorId id);
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

  inline EntityId &operator=(DesignatorId id) {
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

template <>
struct hash<mx::FileId> {
  inline mx::RawEntityId operator()(mx::FileId id) const noexcept {
    return id.file_id;
  }
};

template <>
struct less<mx::FileId> {
  inline bool operator()(mx::FileId a, mx::FileId b) const noexcept {
    return a.file_id < b.file_id;
  }
};

template <>
struct hash<mx::FragmentId> {
  inline mx::RawEntityId operator()(mx::FragmentId id) const noexcept {
    return id.fragment_id;
  }
};

template <>
struct less<mx::FragmentId> {
  inline bool operator()(mx::FragmentId a, mx::FragmentId b) const noexcept {
    return a.fragment_id < b.fragment_id;
  }
};

}  // namespace std
