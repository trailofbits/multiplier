// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Fragment.h>
#include <multiplier/Types.h>

#include <cassert>
#include <multiplier/AST.h>

namespace mx {
namespace {

enum EntityKind : uint64_t {
  kFileFragmentOrInvalid,  // Can be either a FileId, FragmentId or invalid.
  kFileToken,
  kBigCodeEntity,  // Declarations, statements, types.
  kSmallCodeEntity,  // Declarations, statements, types.
};

enum FileFragmentKind : uint64_t {
  kInvalid,
  kFile,
  kFragment
};

// A code chunk with many tokens. This
static_assert(kNumTokensInBigFragment == (1u << kBigFragmentIdNumBits));

static constexpr unsigned kEntityKindNumBits = 2;
static constexpr unsigned kFileFragmentKindNumBits = 2;
static constexpr uint64_t kActualNumDeclKinds = NumEnumerators(DeclKind{});
static constexpr uint64_t kNumDeclKinds = kActualNumDeclKinds * 2u;
static constexpr uint64_t kNumStmtKinds = NumEnumerators(StmtKind{});
static constexpr uint64_t kNumTypeKinds = NumEnumerators(TypeKind{});
static constexpr uint64_t kNumTokenKinds = NumEnumerators(TokenKind{});
static constexpr uint64_t kNumTokenSubstitutionKinds = 3u;
static constexpr unsigned kSubKindNumBits = 10;
static_assert((kNumDeclKinds + kNumStmtKinds + kNumTypeKinds +
               kNumTokenKinds + kNumTokenSubstitutionKinds) <=
              (1u << kSubKindNumBits));

static constexpr unsigned kTokenKindNumBits = 9;
static_assert(NumEnumerators(TokenKind{}) <= (1u << kTokenKindNumBits));

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
    uint64_t entity_subkind:kFileFragmentKindNumBits;
    uint64_t code_id:(64 - (kEntityKindNumBits + kFileFragmentKindNumBits));
  } __attribute__((packed)) file_fragment;

  struct {
    uint64_t entity_kind:kEntityKindNumBits;
    uint64_t sub_kind:kSubKindNumBits;
    uint64_t offset:kBigFragmentIdNumBits;

    // 36 bits for fragment id, i.e. 68 billion ids.
    uint64_t code_id:(64 - (kEntityKindNumBits + kSubKindNumBits +
                            kBigFragmentIdNumBits));
  } __attribute__((packed)) small_entity;

  struct {
    uint64_t entity_kind:kEntityKindNumBits;
    uint64_t sub_kind:kSubKindNumBits;
    uint64_t code_id:kBigFragmentIdNumBits;
    uint64_t offset:(64 - (kEntityKindNumBits + kSubKindNumBits +
                           kBigFragmentIdNumBits));
  } __attribute__((packed)) big_entity;

  struct {
    uint64_t entity_kind:kEntityKindNumBits;
    uint64_t token_kind:kTokenKindNumBits;
    uint64_t file_id:kFileIdNumBits;
    uint64_t offset:(64 - (kEntityKindNumBits + kTokenKindNumBits +
                           kFileIdNumBits));
  } __attribute__((packed)) file_token;

} __attribute__((packed));

static_assert(sizeof(PackedEntityId) == sizeof(uint64_t));

}  // namespace

EntityId::EntityId(FileId id) {
  if(id) {
    PackedEntityId packed = {};
    packed.file_fragment.entity_kind = static_cast<uint64_t>(kFileFragmentOrInvalid);
    packed.file_fragment.entity_subkind = static_cast<uint64_t>(kFile);
    packed.file_fragment.code_id = id.value;
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<FragmentId>(unpacked));
    assert(std::get<FragmentId>(unpacked) == id);
#endif
  }
}

EntityId::EntityId(FragmentId id) {
  if(id) {
    PackedEntityId packed = {};
    packed.file_fragment.entity_kind = static_cast<uint64_t>(kFileFragmentOrInvalid);
    packed.file_fragment.entity_subkind = static_cast<uint64_t>(kFragment);
    packed.file_fragment.code_id = id.value;
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<FragmentId>(unpacked));
    assert(std::get<FragmentId>(unpacked) == id);
#endif
  }
}

EntityId::EntityId(DeclarationId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id.value >= kMaxBigFragmentId) {
      packed.small_entity.code_id = id.fragment_id.value - kMaxBigFragmentId;
      packed.small_entity.entity_kind =
          static_cast<uint64_t>(kSmallCodeEntity);
      if (id.is_definition) {
        packed.small_entity.sub_kind = static_cast<uint64_t>(id.kind) +
                                       kActualNumDeclKinds;
      } else {
        packed.small_entity.sub_kind = static_cast<uint64_t>(id.kind);
      }
      packed.small_entity.offset = id.offset;
    } else {
      packed.big_entity.code_id = id.fragment_id;
      packed.big_entity.entity_kind = static_cast<uint64_t>(kBigCodeEntity);
      if (id.is_definition) {
        packed.big_entity.sub_kind = static_cast<uint64_t>(id.kind) +
                                     kActualNumDeclKinds;
      } else {
        packed.big_entity.sub_kind = static_cast<uint64_t>(id.kind);
      }
      packed.big_entity.offset = id.offset;
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
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id.value >= kMaxBigFragmentId) {
      packed.small_entity.code_id = id.fragment_id.value - kMaxBigFragmentId;
      packed.small_entity.entity_kind =
          static_cast<uint64_t>(kSmallCodeEntity);
      packed.small_entity.sub_kind = kNumDeclKinds +
                                     static_cast<uint64_t>(id.kind);
      packed.small_entity.offset = id.offset;
    } else {
      packed.big_entity.code_id = id.fragment_id;
      packed.big_entity.entity_kind = static_cast<uint64_t>(kBigCodeEntity);
      packed.big_entity.sub_kind = kNumDeclKinds +
                                   static_cast<uint64_t>(id.kind);
      packed.big_entity.offset = id.offset;
    }
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<StatementId>(unpacked));
    assert(std::get<StatementId>(unpacked) == id);
#endif
  }
}

EntityId::EntityId(TypeId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id.value >= kMaxBigFragmentId) {
      packed.small_entity.code_id = id.fragment_id.value - kMaxBigFragmentId;
      packed.small_entity.entity_kind =
          static_cast<uint64_t>(kSmallCodeEntity);
      packed.small_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                     static_cast<uint64_t>(id.kind);
      packed.small_entity.offset = id.offset;
    } else {
      packed.big_entity.code_id = id.fragment_id;
      packed.big_entity.entity_kind = static_cast<uint64_t>(kBigCodeEntity);
      packed.big_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                   static_cast<uint64_t>(id.kind);
      packed.big_entity.offset = id.offset;
    }
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<TypeId>(unpacked));
    assert(std::get<TypeId>(unpacked) == id);
#endif
  }
}
EntityId::EntityId(FragmentTokenId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id.value >= kMaxBigFragmentId) {
      packed.small_entity.code_id = id.fragment_id.value - kMaxBigFragmentId;
      packed.small_entity.entity_kind =
          static_cast<uint64_t>(kSmallCodeEntity);
      packed.small_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                     kNumTypeKinds +
                                     static_cast<uint64_t>(id.kind);
      packed.small_entity.offset = id.offset;
    } else {
      packed.big_entity.code_id = id.fragment_id;
      packed.big_entity.entity_kind = static_cast<uint64_t>(kBigCodeEntity);
      packed.big_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                   kNumTypeKinds +
                                   static_cast<uint64_t>(id.kind);
      packed.big_entity.offset = id.offset;
    }
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<FragmentTokenId>(unpacked));
    assert(std::get<FragmentTokenId>(unpacked) == id);
#endif
  }
}

// Token substitutions are packed in to use the remaining bit space above
// declaration kinds.
EntityId::EntityId(TokenSubstitutionId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id.value >= kMaxBigFragmentId) {
      packed.small_entity.code_id = id.fragment_id.value - kMaxBigFragmentId;
      packed.small_entity.entity_kind =
          static_cast<uint64_t>(kSmallCodeEntity);
      packed.small_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                     kNumTypeKinds + kNumTokenKinds +
                                     static_cast<uint64_t>(id.kind);
      packed.small_entity.offset = id.offset;
    } else {
      packed.big_entity.code_id = id.fragment_id;
      packed.big_entity.entity_kind = static_cast<uint64_t>(kBigCodeEntity);
      packed.big_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                   kNumTypeKinds + kNumTokenKinds +
                                   static_cast<uint64_t>(id.kind);
      packed.big_entity.offset = id.offset;
    }
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<TokenSubstitutionId>(unpacked));
    assert(std::get<TokenSubstitutionId>(unpacked) == id);
#endif
  }
}

EntityId::EntityId(FileTokenId id) {
  if (id.file_id) {
    PackedEntityId packed = {};
    packed.file_token.file_id = id.file_id.value;
    packed.file_token.entity_kind = static_cast<uint64_t>(kFileToken);
    packed.file_token.token_kind = static_cast<uint64_t>(id.kind);
    packed.file_token.offset = id.offset;
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<FileTokenId>(unpacked));
    assert(std::get<FileTokenId>(unpacked) == id);
#endif
  }
}

// Unpack this entity ID into a concrete type.
VariantId EntityId::Unpack(void) const noexcept {
  PackedEntityId packed = {};
  packed.opaque = opaque;
  switch (static_cast<EntityKind>(packed.sel.entity_kind)) {
    case EntityKind::kFileFragmentOrInvalid: {
      switch(static_cast<FileFragmentKind>(packed.file_fragment.entity_subkind)) {
        case FileFragmentKind::kInvalid:
          break;
        case FileFragmentKind::kFile: {
          return FileId{ packed.file_fragment.code_id };
        }
        case FileFragmentKind::kFragment: {
          return FragmentId{ packed.file_fragment.code_id };
        }
      }
      break;
    }

    case EntityKind::kFileToken: {
      FileTokenId id;
      id.file_id.value = packed.file_token.file_id;
      id.kind = static_cast<TokenKind>(packed.file_token.token_kind);
      id.offset = packed.file_token.offset;
      return id;
    }

    // A "big code entity" is an entity belonging to a fragment that has a lot
    // of tokens in it, and thus likely to have a lot of types/decls/stmts in
    // it. "A lot" is defined as more than 2^16 tokens. We reserve the low
    // 2^16 fragment ids for such big code entities, on the assumption that
    // there aren't going to be *that* many huge fragments of code.
    case EntityKind::kBigCodeEntity: {
      auto sub_kind = packed.big_entity.sub_kind;
      if (sub_kind < kNumDeclKinds) {
        DeclarationId id;
        id.fragment_id.value = packed.big_entity.code_id;
        if (sub_kind < kActualNumDeclKinds) {
          id.kind = static_cast<DeclKind>(sub_kind);
          id.is_definition = false;
        } else {
          id.kind = static_cast<DeclKind>(sub_kind - kActualNumDeclKinds);
          id.is_definition = true;
        }
        id.offset = packed.big_entity.offset;
        return id;
      }

      sub_kind -= kNumDeclKinds;
      if (sub_kind < kNumStmtKinds) {
        StatementId id;
        id.fragment_id.value = packed.big_entity.code_id;
        id.kind = static_cast<StmtKind>(sub_kind);
        id.offset = packed.big_entity.offset;
        return id;
      }

      sub_kind -= kNumStmtKinds;
      if (sub_kind < kNumTypeKinds) {
        TypeId id;
        id.fragment_id.value = packed.big_entity.code_id;
        id.kind = static_cast<TypeKind>(sub_kind);
        id.offset = packed.big_entity.offset;
        return id;
      }

      sub_kind -= kNumTypeKinds;
      if (sub_kind < kNumTokenKinds) {
        FragmentTokenId id;
        id.fragment_id.value = packed.big_entity.code_id;
        id.kind = static_cast<TokenKind>(sub_kind);
        id.offset = packed.big_entity.offset;
        return id;
      }

      sub_kind -= kNumTokenKinds;
      if (sub_kind < kNumTokenSubstitutionKinds) {
        TokenSubstitutionId id;
        id.fragment_id.value = packed.big_entity.code_id;
        id.kind = static_cast<TokenSubstitutionKind>(sub_kind);
        id.offset = packed.big_entity.offset;
        return id;
      }

      // Not valid.
      break;
    }

    // A "small code entity" is an entity belonging to a fragment that has less
    // than 2^16 tokens. These entities all belong to fragments whose IDs are
    // greater-than-or-equal to `kMaxBigFragmentId`.
    case EntityKind::kSmallCodeEntity: {
      auto sub_kind = packed.small_entity.sub_kind;
      if (sub_kind < kNumDeclKinds) {
        DeclarationId id;
        id.fragment_id.value = packed.small_entity.code_id + kMaxBigFragmentId;
        if (sub_kind < kActualNumDeclKinds) {
          id.kind = static_cast<DeclKind>(sub_kind);
          id.is_definition = false;
        } else {
          id.kind = static_cast<DeclKind>(sub_kind - kActualNumDeclKinds);
          id.is_definition = true;
        }
        id.offset = packed.small_entity.offset;
        return id;
      }

      sub_kind -= kNumDeclKinds;
      if (sub_kind < kNumStmtKinds) {
        StatementId id;
        id.fragment_id.value = packed.small_entity.code_id + kMaxBigFragmentId;
        id.kind = static_cast<StmtKind>(sub_kind);
        id.offset = packed.small_entity.offset;
        return id;
      }

      sub_kind -= kNumStmtKinds;
      if (sub_kind < kNumTypeKinds) {
        TypeId id;
        id.fragment_id.value = packed.small_entity.code_id + kMaxBigFragmentId;
        id.kind = static_cast<TypeKind>(sub_kind);
        id.offset = packed.small_entity.offset;
        return id;
      }

      sub_kind -= kNumTypeKinds;
      if (sub_kind < kNumTokenKinds) {
        FragmentTokenId id;
        id.fragment_id.value = packed.small_entity.code_id + kMaxBigFragmentId;
        id.kind = static_cast<TokenKind>(sub_kind);
        id.offset = packed.small_entity.offset;
        return id;
      }

      sub_kind -= kNumTokenKinds;
      if (sub_kind < kNumTokenSubstitutionKinds) {
        TokenSubstitutionId id;
        id.fragment_id.value = packed.small_entity.code_id + kMaxBigFragmentId;
        id.kind = static_cast<TokenSubstitutionKind>(sub_kind);
        id.offset = packed.small_entity.offset;
        return id;
      }

      // Not valid.
      break;
    }

    default:
      break;
  }
  return InvalidId{};
}

}  // namespace mx
