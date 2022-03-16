// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Types.h>

#include <cassert>
#include <multiplier/AST.h>

namespace mx {
namespace {

enum EntityKind : uint64_t {
  kInvalid,

  kBigCodeDeclaration,
  kBigCodeStatement,
  kBigCodeToken,

  kSmallCodeDeclaration,
  kSmallCodeStatement,
  kSmallCodeToken,

  kNumEnumerators
};

// A code chunk with many tokens. This
static_assert(kNumTokensInBigCode == (1u << kBigCodeIdNumBits));

static constexpr unsigned kEntityKindNumBits = 3;
static_assert(static_cast<uint64_t>(EntityKind::kNumEnumerators) <=
              (1u << kEntityKindNumBits));

static constexpr unsigned kDeclKindNumBits = 7;
static_assert(static_cast<uint64_t>(DeclKind::NUM_ENUMERATORS) <=
              (1u << kDeclKindNumBits));

static constexpr unsigned kStmtKindNumBits = 8;
static_assert(static_cast<uint64_t>(StmtKind::NUM_ENUMERATORS) <=
              (1u << kStmtKindNumBits));

static constexpr unsigned kTokenKindNumBits = 9;
static_assert(static_cast<uint64_t>(TokenKind::NUM_ENUMERATORS) <=
              (1u << kTokenKindNumBits));

// A small X is a token in a code with less than `kNumTokensInBigCode`
// tokens, and so we only need `kBigCodeIdNumBits` bits to represent the
// maximum token offset.
//
// A big X is a token in a code with at least `kNumTokensInBigCode`
// tokens, and so we need at least `kBigCodeIdNumBits` bits to represent
// a token offset, and we've reserved the first `kMaxBigCodeId` code
// IDs for "big codes" so that we don't need more than `kBigCodeIdNumBits`
// bits to represent the code ID.
union PackedEntityId {
  uint64_t opaque{0};

  struct {
    uint64_t entity_kind:kEntityKindNumBits;
    uint64_t opaque:(64 - kEntityKindNumBits);
  } __attribute__((packed)) sel;

  struct {
    uint64_t entity_kind:kEntityKindNumBits;
    uint64_t decl_kind:kDeclKindNumBits;
    uint64_t offset:kBigCodeIdNumBits;
    uint64_t code_id:(64 - (kEntityKindNumBits + kDeclKindNumBits +
                            kBigCodeIdNumBits));
  } __attribute__((packed)) small_decl;

  struct {
    uint64_t entity_kind:kEntityKindNumBits;
    uint64_t decl_kind:kDeclKindNumBits;
    uint64_t code_id:kBigCodeIdNumBits;
    uint64_t offset:(64 - (kEntityKindNumBits + kDeclKindNumBits +
                           kBigCodeIdNumBits));
  } __attribute__((packed)) big_decl;

  struct {
    uint64_t entity_kind:kEntityKindNumBits;
    uint64_t stmt_kind:kStmtKindNumBits;
    uint64_t offset:kBigCodeIdNumBits;
    uint64_t code_id:(64 - (kEntityKindNumBits + kStmtKindNumBits +
                            kBigCodeIdNumBits));
  } __attribute__((packed)) small_stmt;

  struct {
    uint64_t entity_kind:kEntityKindNumBits;
    uint64_t stmt_kind:kStmtKindNumBits;
    uint64_t code_id:kBigCodeIdNumBits;
    uint64_t offset:(64 - (kEntityKindNumBits + kStmtKindNumBits +
                           kBigCodeIdNumBits));
  } __attribute__((packed)) big_stmt;

  struct {
    uint64_t entity_kind:kEntityKindNumBits;
    uint64_t token_kind:kTokenKindNumBits;
    uint64_t offset:kBigCodeIdNumBits;
    uint64_t code_id:(64 - (kEntityKindNumBits + kTokenKindNumBits +
                            kBigCodeIdNumBits));
  } __attribute__((packed)) small_token;

  struct {
    uint64_t entity_kind:kEntityKindNumBits;
    uint64_t token_kind:kTokenKindNumBits;
    uint64_t code_id:kBigCodeIdNumBits;
    uint64_t offset:(64 - (kEntityKindNumBits + kTokenKindNumBits +
                           kBigCodeIdNumBits));
  } __attribute__((packed)) big_token;

} __attribute__((packed));

static_assert(sizeof(PackedEntityId) == sizeof(uint64_t));

}  // namespace

EntityId::EntityId(DeclarationId id) {
  if (id.code_id) {
    PackedEntityId packed = {};
    if (id.code_id >= kMaxBigCodeId) {
      packed.small_decl.code_id = id.code_id;
      packed.small_decl.entity_kind = static_cast<uint64_t>(kSmallCodeDeclaration);
      packed.small_decl.decl_kind = static_cast<uint64_t>(id.kind);
      packed.small_decl.offset = id.offset;
    } else {
      packed.big_decl.code_id = id.code_id;
      packed.big_decl.entity_kind = static_cast<uint64_t>(kBigCodeDeclaration);
      packed.big_decl.decl_kind = static_cast<uint64_t>(id.kind);
      packed.big_decl.offset = id.offset;
    }
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<DeclarationId>(unpacked));
    assert(std::get<DeclarationId>(unpacked) == id);
#endif
  }
}
EntityId::EntityId(StatementId id) {
  if (id.code_id) {
    PackedEntityId packed = {};
    if (id.code_id >= kMaxBigCodeId) {
      packed.small_stmt.code_id = id.code_id;
      packed.small_stmt.entity_kind = static_cast<uint64_t>(kSmallCodeStatement);
      packed.small_stmt.stmt_kind = static_cast<uint64_t>(id.kind);
      packed.small_stmt.offset = id.offset;
    } else {
      packed.big_stmt.code_id = id.code_id;
      packed.big_stmt.entity_kind = static_cast<uint64_t>(kBigCodeStatement);
      packed.big_stmt.stmt_kind = static_cast<uint64_t>(id.kind);
      packed.big_stmt.offset = id.offset;
    }
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<StatementId>(unpacked));
    assert(std::get<StatementId>(unpacked) == id);
#endif
  }
}

EntityId::EntityId(TokenId id) {
  if (id.code_id) {
    PackedEntityId packed = {};
    if (id.code_id >= kMaxBigCodeId) {
      packed.small_token.code_id = id.code_id;
      packed.small_token.entity_kind = static_cast<uint64_t>(kSmallCodeStatement);
      packed.small_token.token_kind = static_cast<uint64_t>(id.kind);
      packed.small_token.offset = id.offset;
    } else {
      packed.big_token.code_id = id.code_id;
      packed.big_token.entity_kind = static_cast<uint64_t>(kBigCodeStatement);
      packed.big_token.token_kind = static_cast<uint64_t>(id.kind);
      packed.big_token.offset = id.offset;
    }
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<TokenId>(unpacked));
    assert(std::get<TokenId>(unpacked) == id);
#endif
  }
}

// Unpack this entity ID into a concrete type.
VariantId EntityId::Unpack(void) const noexcept {
  PackedEntityId packed = {};
  packed.opaque = opaque;
  switch (static_cast<EntityKind>(packed.sel.entity_kind)) {
    case EntityKind::kBigCodeDeclaration: {
      DeclarationId id;
      id.code_id = packed.big_decl.code_id;
      id.kind = static_cast<DeclKind>(packed.big_decl.decl_kind);
      id.offset = packed.big_decl.offset;
      return id;
    }
    case EntityKind::kSmallCodeDeclaration: {
      DeclarationId id;
      id.code_id = packed.small_decl.code_id;
      id.kind = static_cast<DeclKind>(packed.small_decl.decl_kind);
      id.offset = packed.small_decl.offset;
      return id;
    }
    case EntityKind::kBigCodeStatement: {
      StatementId id;
      id.code_id = packed.big_stmt.code_id;
      id.kind = static_cast<StmtKind>(packed.big_stmt.stmt_kind);
      id.offset = packed.big_stmt.offset;
      return id;
    }
    case EntityKind::kSmallCodeStatement: {
      StatementId id;
      id.code_id = packed.small_stmt.code_id;
      id.kind = static_cast<StmtKind>(packed.small_stmt.stmt_kind);
      id.offset = packed.small_stmt.offset;
      return id;
    }
    case EntityKind::kBigCodeToken: {
      TokenId id;
      id.code_id = packed.big_token.code_id;
      id.kind = static_cast<TokenKind>(packed.big_token.token_kind);
      id.offset = packed.big_token.offset;
      return id;
    }
    case EntityKind::kSmallCodeToken: {
      TokenId id;
      id.code_id = packed.small_token.code_id;
      id.kind = static_cast<TokenKind>(packed.small_token.token_kind);
      id.offset = packed.small_token.offset;
      return id;
    }
    default:
      return InvalidId{};
  }
}

}  // namespace mx
