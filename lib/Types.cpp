// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Types.h"

#include <cassert>
#include <multiplier/AST.h>

namespace mx {
namespace {

enum OtherKind : uint64_t {
  kInvalid,  // Zero.
  kFile,
  kFragment,
  kFileEntity,  // E.g. file token, macro directive.
};

// NOTE(pag): Keep in sync with `kOtherSubKindBits`.
enum OtherSubKind : uint64_t {
  kFileToken,
  kDirective,
};

// A code chunk with many tokens. This
static_assert(kNumTokensInBigFragment == (1u << kBigFragmentIdNumBits));

enum IdentifiedPseudo : uint64_t {
  kDesignator
};

static constexpr uint64_t kActualNumDeclKinds = NumEnumerators(DeclKind{});
static constexpr uint64_t kNumDeclKinds = kActualNumDeclKinds * 2u;
static constexpr uint64_t kNumStmtKinds = NumEnumerators(StmtKind{});
static constexpr uint64_t kNumTypeKinds = NumEnumerators(TypeKind{});
static constexpr uint64_t kNumAttrKinds = NumEnumerators(AttrKind{});
static constexpr uint64_t kNumTokenKinds = NumEnumerators(TokenKind{});
static constexpr uint64_t kNumMacroKinds = NumEnumerators(MacroKind{});
static constexpr uint64_t kNumPseudoKinds = 1u;
static constexpr unsigned kSubKindNumBits = 11u;
static_assert((kNumDeclKinds + kNumStmtKinds + kNumTypeKinds + kNumAttrKinds +
               kNumTokenKinds /* fragment tokens */ +
               kNumTokenKinds /* macro tokens */ +
               kNumMacroKinds +
               kNumPseudoKinds) <=
              (1u << kSubKindNumBits));

static constexpr unsigned kOtherSubKindBits = 1u;
static constexpr unsigned kTokenKindNumBits = 9u;
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
    uint64_t opaque:63u;
    uint64_t is_fragment_entity:1u;
  } __attribute__((packed)) entity_or_other;

  struct {
    uint64_t opaque:(61u - kOtherSubKindBits);
    uint64_t sub_kind:kOtherSubKindBits;
    uint64_t kind:2u;
    uint64_t is_fragment_entity:1u;
  } __attribute__((packed)) other;

  struct {
    uint64_t opaque:62u;
    uint64_t is_big:1u;
    uint64_t is_fragment_entity:1u;
  } __attribute__((packed)) small_or_big;

  struct {
    //  First so that `sub_kind` isn't significant in sorting.
    uint64_t sub_kind:kSubKindNumBits;

    uint64_t offset:kBigFragmentIdNumBits;

    // 35 bits for fragment id, i.e. 34 billion IDs.
    uint64_t code_id:(62u - (kSubKindNumBits + kBigFragmentIdNumBits));
    uint64_t is_big:1u;
    uint64_t is_fragment_entity:1u;
  } __attribute__((packed)) small_entity;

  struct {
    //  First so that `sub_kind` isn't significant in sorting.
    uint64_t sub_kind:kSubKindNumBits;

    uint64_t offset:(62u - (kSubKindNumBits + kBigFragmentIdNumBits));

    uint64_t code_id:kBigFragmentIdNumBits;
    uint64_t is_big:1u;
    uint64_t is_fragment_entity:1u;
  } __attribute__((packed)) big_entity;

  struct {
    //  First so that `token_kind` isn't significant in sorting.
    uint64_t token_kind:kTokenKindNumBits;
    uint64_t offset:(61u - (kTokenKindNumBits + kFileIdNumBits +
                            kOtherSubKindBits));
    uint64_t file_id:kFileIdNumBits;
    uint64_t sub_kind:kOtherSubKindBits;
    uint64_t kind:2u;
    uint64_t is_fragment_entity:1u;
  } __attribute__((packed)) file_token;

} __attribute__((packed));

static_assert(sizeof(PackedEntityId) == sizeof(uint64_t));

}  // namespace

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"

EntityId::EntityId(DeclarationId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id >= kMaxBigFragmentId) {
      packed.small_entity.code_id = id.fragment_id - kMaxBigFragmentId;
      packed.small_entity.is_big = 0u;
      packed.small_entity.is_fragment_entity = 1u;
      if (id.is_definition) {
        packed.small_entity.sub_kind = static_cast<uint64_t>(id.kind) +
                                       kActualNumDeclKinds;
      } else {
        packed.small_entity.sub_kind = static_cast<uint64_t>(id.kind);
      }
      packed.small_entity.offset = id.offset;
      assert(packed.small_entity.offset == id.offset);

    } else {
      packed.big_entity.code_id = id.fragment_id;
      packed.big_entity.is_big = 1u;
      packed.big_entity.is_fragment_entity = 1u;
      if (id.is_definition) {
        packed.big_entity.sub_kind = static_cast<uint64_t>(id.kind) +
                                     kActualNumDeclKinds;
      } else {
        packed.big_entity.sub_kind = static_cast<uint64_t>(id.kind);
      }
      packed.big_entity.offset = id.offset;
      assert(packed.big_entity.offset == id.offset);
    }
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<DeclarationId>(unpacked));
    assert(std::get<DeclarationId>(unpacked) == id);
#endif
  }
}

EntityId::EntityId(FileId id) {
  if (id.file_id) {
    PackedEntityId packed = {};
    packed.other.is_fragment_entity = 0u;
    packed.other.kind = static_cast<uint64_t>(OtherKind::kFile);
    packed.other.opaque = id.file_id;
    assert(packed.other.opaque == id.file_id);
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<FileId>(unpacked));
    assert(std::get<FileId>(unpacked) == id);
#endif
  }
}

EntityId::EntityId(FragmentId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    packed.other.is_fragment_entity = 0u;
    packed.other.kind = static_cast<uint64_t>(OtherKind::kFragment);
    packed.other.sub_kind = 0;
    packed.other.opaque = id.fragment_id;
    assert(packed.other.opaque == id.fragment_id);
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<FragmentId>(unpacked));
    assert(std::get<FragmentId>(unpacked) == id);
#endif
  }
}

EntityId::EntityId(StatementId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id >= kMaxBigFragmentId) {
      packed.small_entity.code_id = id.fragment_id - kMaxBigFragmentId;
      packed.small_entity.is_big = 0u;
      packed.small_entity.is_fragment_entity = 1u;
      packed.small_entity.sub_kind = kNumDeclKinds +
                                     static_cast<uint64_t>(id.kind);
      packed.small_entity.offset = id.offset;
      assert(packed.small_entity.offset == id.offset);

    } else {
      packed.big_entity.code_id = id.fragment_id;
      packed.big_entity.is_big = 1u;
      packed.big_entity.is_fragment_entity = 1u;
      packed.big_entity.sub_kind = kNumDeclKinds +
                                   static_cast<uint64_t>(id.kind);
      packed.big_entity.offset = id.offset;
      assert(packed.big_entity.offset == id.offset);
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
    if (id.fragment_id >= kMaxBigFragmentId) {
      packed.small_entity.code_id = id.fragment_id - kMaxBigFragmentId;
      packed.small_entity.is_big = 0u;
      packed.small_entity.is_fragment_entity = 1u;
      packed.small_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                     static_cast<uint64_t>(id.kind);
      packed.small_entity.offset = id.offset;
      assert(packed.small_entity.offset == id.offset);

    } else {
      packed.big_entity.code_id = id.fragment_id;
      packed.big_entity.is_big = 1u;
      packed.big_entity.is_fragment_entity = 1u;
      packed.big_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                   static_cast<uint64_t>(id.kind);
      packed.big_entity.offset = id.offset;
      assert(packed.big_entity.offset == id.offset);
    }
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<TypeId>(unpacked));
    assert(std::get<TypeId>(unpacked) == id);
#endif
  }
}

EntityId::EntityId(AttributeId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id >= kMaxBigFragmentId) {
      packed.small_entity.code_id = id.fragment_id - kMaxBigFragmentId;
      packed.small_entity.is_big = 0u;
      packed.small_entity.is_fragment_entity = 1u;
      packed.small_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                     kNumTypeKinds +
                                     static_cast<uint64_t>(id.kind);
      packed.small_entity.offset = id.offset;
      assert(packed.small_entity.offset == id.offset);

    } else {
      packed.big_entity.code_id = id.fragment_id;
      packed.big_entity.is_big = 1u;
      packed.big_entity.is_fragment_entity = 1u;
      packed.big_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                   kNumTypeKinds +
                                   static_cast<uint64_t>(id.kind);
      packed.big_entity.offset = id.offset;
      assert(packed.big_entity.offset == id.offset);
    }
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<AttributeId>(unpacked));
    assert(std::get<AttributeId>(unpacked) == id);
#endif
  }
}

EntityId::EntityId(ParsedTokenId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id >= kMaxBigFragmentId) {
      packed.small_entity.code_id = id.fragment_id - kMaxBigFragmentId;
      packed.small_entity.is_big = 0u;
      packed.small_entity.is_fragment_entity = 1u;
      packed.small_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                     kNumTypeKinds + kNumAttrKinds +
                                     static_cast<uint64_t>(id.kind);
      packed.small_entity.offset = id.offset;
      assert(packed.small_entity.offset == id.offset);

    } else {
      packed.big_entity.code_id = id.fragment_id;
      packed.big_entity.is_big = 1u;
      packed.big_entity.is_fragment_entity = 1u;
      packed.big_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                   kNumTypeKinds + kNumAttrKinds +
                                   static_cast<uint64_t>(id.kind);
      packed.big_entity.offset = id.offset;
      assert(packed.big_entity.offset == id.offset);
    }
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<ParsedTokenId>(unpacked));
    assert(std::get<ParsedTokenId>(unpacked) == id);
#endif
  }
}

EntityId::EntityId(MacroTokenId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id >= kMaxBigFragmentId) {
      packed.small_entity.code_id = id.fragment_id - kMaxBigFragmentId;
      packed.small_entity.is_big = 0u;
      packed.small_entity.is_fragment_entity = 1u;
      packed.small_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                     kNumTypeKinds + kNumAttrKinds +
                                     kNumTokenKinds +
                                     static_cast<uint64_t>(id.kind);
      packed.small_entity.offset = id.offset;
      assert(packed.small_entity.offset == id.offset);

    } else {
      packed.big_entity.code_id = id.fragment_id;
      packed.big_entity.is_big = 1u;
      packed.big_entity.is_fragment_entity = 1u;
      packed.big_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                   kNumTypeKinds + kNumAttrKinds +
                                   kNumTokenKinds +
                                   static_cast<uint64_t>(id.kind);
      packed.big_entity.offset = id.offset;
      assert(packed.big_entity.offset == id.offset);
    }
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<MacroTokenId>(unpacked));
    assert(std::get<MacroTokenId>(unpacked) == id);
#endif
  }
}

// Token substitutions are packed in to use the remaining bit space above
// declaration kinds.
EntityId::EntityId(MacroId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id >= kMaxBigFragmentId) {
      packed.small_entity.code_id = id.fragment_id - kMaxBigFragmentId;
      packed.small_entity.is_big = 0u;
      packed.small_entity.is_fragment_entity = 1u;
      packed.small_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                     kNumTypeKinds + kNumAttrKinds +
                                     kNumTokenKinds + kNumTokenKinds +
                                     static_cast<uint64_t>(id.kind);
      packed.small_entity.offset = id.offset;
      assert(packed.small_entity.offset == id.offset);

    } else {
      packed.big_entity.code_id = id.fragment_id;
      packed.big_entity.is_big = 1u;
      packed.big_entity.is_fragment_entity = 1u;
      packed.big_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                   kNumTypeKinds + kNumAttrKinds +
                                   kNumTokenKinds + kNumTokenKinds +
                                   static_cast<uint64_t>(id.kind);
      packed.big_entity.offset = id.offset;
      assert(packed.big_entity.offset == id.offset);
    }
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<MacroId>(unpacked));
    assert(std::get<MacroId>(unpacked) == id);
#endif
  }
}

// Token substitutions are packed in to use the remaining bit space above
// declaration kinds.
EntityId::EntityId(DesignatorId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id >= kMaxBigFragmentId) {
      packed.small_entity.code_id = id.fragment_id - kMaxBigFragmentId;
      packed.small_entity.is_big = 0u;
      packed.small_entity.is_fragment_entity = 1u;
      packed.small_entity.sub_kind =
          kNumDeclKinds + kNumStmtKinds + kNumTypeKinds + kNumAttrKinds +
          kNumTokenKinds + kNumTokenKinds + kNumMacroKinds +
          static_cast<uint64_t>(IdentifiedPseudo::kDesignator);
      packed.small_entity.offset = id.offset;
      assert(packed.small_entity.offset == id.offset);

    } else {
      packed.big_entity.code_id = id.fragment_id;
      packed.big_entity.is_big = 1u;
      packed.big_entity.is_fragment_entity = 1u;
      packed.big_entity.sub_kind =
          kNumDeclKinds + kNumStmtKinds + kNumTypeKinds + kNumAttrKinds +
          kNumTokenKinds + kNumTokenKinds + kNumMacroKinds +
          static_cast<uint64_t>(IdentifiedPseudo::kDesignator);
      packed.big_entity.offset = id.offset;
      assert(packed.big_entity.offset == id.offset);
    }
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<DesignatorId>(unpacked));
    assert(std::get<DesignatorId>(unpacked) == id);
#endif
  }
}

EntityId::EntityId(FileTokenId id) {
  if (id.file_id) {
    PackedEntityId packed = {};
    packed.file_token.is_fragment_entity = 0u;
    packed.file_token.kind = static_cast<uint64_t>(OtherKind::kFileEntity);
    packed.file_token.sub_kind =
        static_cast<uint64_t>(OtherSubKind::kFileToken);

    packed.file_token.file_id = id.file_id;
    assert(packed.file_token.file_id == id.file_id);

    packed.file_token.token_kind = static_cast<uint64_t>(id.kind);
    packed.file_token.offset = id.offset;
    assert(packed.file_token.offset == id.offset);
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<FileTokenId>(unpacked));
    assert(std::get<FileTokenId>(unpacked) == id);
#endif
  }
}

#pragma GCC diagnostic pop

EntityOffset FragmentOffsetFromEntityId(RawEntityId id) {
  PackedEntityId packed = {};
  packed.opaque = id;
  if (!packed.entity_or_other.is_fragment_entity) {
    return ~0u;
  }

  if (packed.small_or_big.is_big) {
    return static_cast<EntityOffset>(packed.big_entity.offset);
  } else {
    return static_cast<EntityOffset>(packed.small_entity.offset);
  }
}

RawEntityId FragmentIdFromEntityId(RawEntityId id) {
  PackedEntityId packed = {};
  packed.opaque = id;
  if (!packed.entity_or_other.is_fragment_entity) {
    return kInvalidEntityId;
  }

  if (packed.small_or_big.is_big) {
    FragmentId fid(packed.big_entity.code_id);
    return EntityId(fid).Pack();
  } else {
    FragmentId fid(packed.small_entity.code_id + kMaxBigFragmentId);
    return EntityId(fid).Pack();
  }
}

// Unpack this entity ID into a concrete type.
VariantId EntityId::Unpack(void) const noexcept {
  PackedEntityId packed = {};
  packed.opaque = opaque;

  // Decl, Statement, Type, Designator, FragmentToken, MacroToken, etc.
  if (packed.entity_or_other.is_fragment_entity) {

    // A "big code entity" is an entity belonging to a fragment that has a lot
    // of tokens in it, and thus likely to have a lot of types/decls/stmts in
    // it. "A lot" is defined as more than 2^16 tokens. We reserve the low
    // 2^16 fragment ids for such big code entities, on the assumption that
    // there aren't going to be *that* many huge fragments of code.
    if (packed.small_or_big.is_big) {
      auto sub_kind = packed.big_entity.sub_kind;
      if (sub_kind < kNumDeclKinds) {
        DeclarationId id;
        id.fragment_id = packed.big_entity.code_id;
        if (sub_kind < kActualNumDeclKinds) {
          id.kind = static_cast<DeclKind>(sub_kind);
          id.is_definition = false;
        } else {
          id.kind = static_cast<DeclKind>(sub_kind - kActualNumDeclKinds);
          id.is_definition = true;
        }
        id.offset = static_cast<EntityOffset>(packed.big_entity.offset);
        return id;
      }

      sub_kind -= kNumDeclKinds;
      if (sub_kind < kNumStmtKinds) {
        StatementId id;
        id.fragment_id = packed.big_entity.code_id;
        id.kind = static_cast<StmtKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.big_entity.offset);
        return id;
      }

      sub_kind -= kNumStmtKinds;
      if (sub_kind < kNumTypeKinds) {
        TypeId id;
        id.fragment_id = packed.big_entity.code_id;
        id.kind = static_cast<TypeKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.big_entity.offset);
        return id;
      }

      sub_kind -= kNumTypeKinds;
      if (sub_kind < kNumAttrKinds) {
        AttributeId id;
        id.fragment_id = packed.big_entity.code_id;
        id.kind = static_cast<AttrKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.big_entity.offset);
        return id;
      }

      sub_kind -= kNumAttrKinds;
      if (sub_kind < kNumTokenKinds) {
        ParsedTokenId id;
        id.fragment_id = packed.big_entity.code_id;
        id.kind = static_cast<TokenKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.big_entity.offset);
        return id;
      }

      sub_kind -= kNumTokenKinds;
      if (sub_kind < kNumTokenKinds) {
        MacroTokenId id;
        id.fragment_id = packed.big_entity.code_id;
        id.kind = static_cast<TokenKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.big_entity.offset);
        return id;
      }

      sub_kind -= kNumTokenKinds;
      if (sub_kind < kNumMacroKinds) {
        MacroId id;
        id.fragment_id = packed.big_entity.code_id;
        id.kind = static_cast<MacroKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.big_entity.offset);
        return id;
      }

      sub_kind -= kNumMacroKinds;
      if (sub_kind < kNumPseudoKinds) {
        switch (static_cast<IdentifiedPseudo>(sub_kind)) {
          case IdentifiedPseudo::kDesignator: {
            DesignatorId id;
            id.fragment_id = packed.big_entity.code_id;
            id.offset = static_cast<EntityOffset>(packed.big_entity.offset);
            return id;
          }
        } 
      }

      return InvalidId{};

    // A "small code entity" is an entity belonging to a fragment that has less
    // than 2^16 tokens. These entities all belong to fragments whose IDs are
    // greater-than-or-equal to `kMaxBigFragmentId`.
    } else {
      auto sub_kind = packed.small_entity.sub_kind;
      if (sub_kind < kNumDeclKinds) {
        DeclarationId id;
        id.fragment_id = packed.small_entity.code_id + kMaxBigFragmentId;
        if (sub_kind < kActualNumDeclKinds) {
          id.kind = static_cast<DeclKind>(sub_kind);
          id.is_definition = false;
        } else {
          id.kind = static_cast<DeclKind>(sub_kind - kActualNumDeclKinds);
          id.is_definition = true;
        }
        id.offset = static_cast<EntityOffset>(packed.small_entity.offset);
        return id;
      }

      sub_kind -= kNumDeclKinds;
      if (sub_kind < kNumStmtKinds) {
        StatementId id;
        id.fragment_id = packed.small_entity.code_id + kMaxBigFragmentId;
        id.kind = static_cast<StmtKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.small_entity.offset);
        return id;
      }

      sub_kind -= kNumStmtKinds;
      if (sub_kind < kNumTypeKinds) {
        TypeId id;
        id.fragment_id = packed.small_entity.code_id + kMaxBigFragmentId;
        id.kind = static_cast<TypeKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.small_entity.offset);
        return id;
      }

      sub_kind -= kNumTypeKinds;
      if (sub_kind < kNumAttrKinds) {
        AttributeId id;
        id.fragment_id = packed.small_entity.code_id + kMaxBigFragmentId;
        id.kind = static_cast<AttrKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.small_entity.offset);
        return id;
      }

      sub_kind -= kNumAttrKinds;
      if (sub_kind < kNumTokenKinds) {
        ParsedTokenId id;
        id.fragment_id = packed.small_entity.code_id + kMaxBigFragmentId;
        id.kind = static_cast<TokenKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.small_entity.offset);
        return id;
      }

      sub_kind -= kNumTokenKinds;
      if (sub_kind < kNumTokenKinds) {
        MacroTokenId id;
        id.fragment_id = packed.small_entity.code_id + kMaxBigFragmentId;
        id.kind = static_cast<TokenKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.small_entity.offset);
        return id;
      }

      sub_kind -= kNumTokenKinds;
      if (sub_kind < kNumMacroKinds) {
        MacroId id;
        id.fragment_id = packed.small_entity.code_id + kMaxBigFragmentId;
        id.kind = static_cast<MacroKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.small_entity.offset);
        return id;
      }

      sub_kind -= kNumMacroKinds;
      if (sub_kind < kNumPseudoKinds) {
        switch (static_cast<IdentifiedPseudo>(sub_kind)) {
          case IdentifiedPseudo::kDesignator: {
            DesignatorId id;
            id.fragment_id = packed.small_entity.code_id + kMaxBigFragmentId;
            id.offset = static_cast<EntityOffset>(packed.small_entity.offset);
            return id;
          }
        } 
      }

      return InvalidId{};
    }

  // Fragment, File, FileToken, Directive, etc.
  } else {
    switch (static_cast<OtherKind>(packed.other.kind)) {
      case OtherKind::kInvalid:
        return InvalidId{};

      case OtherKind::kFile: {
        return mx::FileId(packed.other.opaque);
      }
      case OtherKind::kFragment: {
        return mx::FragmentId(packed.other.opaque);
      }
      case OtherKind::kFileEntity:
        switch (static_cast<OtherSubKind>(packed.other.sub_kind)) {
          case OtherSubKind::kDirective: {
            return InvalidId{};
          }
          case OtherSubKind::kFileToken: {
            FileTokenId id;
            id.file_id = packed.file_token.file_id;
            id.kind = static_cast<TokenKind>(packed.file_token.token_kind);
            id.offset = static_cast<EntityOffset>(packed.file_token.offset);
            return id;
          }
        }
    }
  }

  return InvalidId{};
}

}  // namespace mx
