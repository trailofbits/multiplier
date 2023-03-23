// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Types.h"

#include <cassert>
#include <multiplier/AST.h>
#include <multiplier/Entity.h>
#include <multiplier/File.h>
#include <multiplier/Fragment.h>

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
  kTemplateArgument,
  kTemplateParameterList,
  kCXXBaseSpecifier,
  kDesignator
};

static constexpr uint64_t kActualNumDeclKinds = NumEnumerators(DeclKind{});
static constexpr uint64_t kNumDeclKinds = kActualNumDeclKinds * 2u;
static constexpr uint64_t kNumStmtKinds = NumEnumerators(StmtKind{});
static constexpr uint64_t kNumTypeKinds = NumEnumerators(TypeKind{});
static constexpr uint64_t kNumAttrKinds = NumEnumerators(AttrKind{});
static constexpr uint64_t kNumTokenKinds = NumEnumerators(TokenKind{});
static constexpr uint64_t kNumMacroKinds = NumEnumerators(MacroKind{});
static constexpr uint64_t kNumPseudoKinds = 4u;
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
    uint64_t offset:kBigFragmentIdNumBits;

    // 35 bits for fragment id, i.e. 34 billion IDs.
    uint64_t fragment_id:(62u - (kSubKindNumBits + kBigFragmentIdNumBits));

    // For declarations, `sub_kind` also encodes if something is a definition,
    // so we want it to be significant for sorting, i.e. definition IDs come
    // before declaration IDs.
    //
    // We encode the `sub_kind` for definitions as a smaller number than
    // `sub_kind` for declarations, and so signed and unsigned 64-bit
    // interpretations of the entity ID will sort the definitions first.
    uint64_t sub_kind:kSubKindNumBits;

    uint64_t is_big:1u;
    uint64_t is_fragment_entity:1u;
  } __attribute__((packed)) small_entity;

  struct {
    // 35 bits for the offset, as we expect a lot of things in these fragments.
    //
    // NOTE(pag): Could eventually drop the bit count here, e.g. to 30.
    uint64_t offset:(62u - (kSubKindNumBits + kBigFragmentIdNumBits));

    // 16 bits for fragment id, i.e. we expect less than 2^16 really really
    // big fragments. For those fragments, we have more "stuff" in them, so
    // we have many more bits available for the `offset`.
    uint64_t fragment_id:kBigFragmentIdNumBits;

    uint64_t sub_kind:kSubKindNumBits;
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

const char *EnumeratorName(EntityCategory e) noexcept {
  switch (e) {
    case EntityCategory::NOT_AN_ENTITY: return "NOT_AN_ENTITY";
#define MX_ENTITY_CASE_NAME(type, lower, enum_name, val) \
    case EntityCategory::enum_name: return #enum_name;

    MX_FOR_EACH_ENTITY_CATEGORY(MX_ENTITY_CASE_NAME,
                                MX_ENTITY_CASE_NAME,
                                MX_ENTITY_CASE_NAME,
                                MX_ENTITY_CASE_NAME,
                                MX_ENTITY_CASE_NAME)
#undef MX_ENTITY_CASE_NAME
  }
  return "NOT_AN_ENTITY";
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"

EntityId::EntityId(DeclId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id >= kMaxBigFragmentId) {
      packed.small_entity.fragment_id = id.fragment_id - kMaxBigFragmentId;
      packed.small_entity.is_big = 0u;
      packed.small_entity.is_fragment_entity = 1u;

      // Definitions should sort less than declarations.
      if (id.is_definition) {
        packed.small_entity.sub_kind = static_cast<uint64_t>(id.kind);
      } else {
        packed.small_entity.sub_kind = static_cast<uint64_t>(id.kind) +
                                       kActualNumDeclKinds;
      }

      packed.small_entity.offset = id.offset;
      assert(packed.small_entity.offset == id.offset);

    } else {
      packed.big_entity.fragment_id = id.fragment_id;
      packed.big_entity.is_big = 1u;
      packed.big_entity.is_fragment_entity = 1u;

      // Definitions should sort less than declarations.
      if (id.is_definition) {
        packed.big_entity.sub_kind = static_cast<uint64_t>(id.kind);
      } else {
        packed.big_entity.sub_kind = static_cast<uint64_t>(id.kind) +
                                     kActualNumDeclKinds;
      }
      packed.big_entity.offset = id.offset;
      assert(packed.big_entity.offset == id.offset);
    }
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<DeclId>(unpacked));
    assert(std::get<DeclId>(unpacked) == id);
#endif
  }
}

std::optional<FragmentId> FragmentId::from(const EntityId &eid) {
  if (auto frag_id = FragmentIdFromEntityId(eid.Pack())) {
    return frag_id->Unpack();
  } else {
    return std::nullopt;
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

EntityId::EntityId(StmtId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id >= kMaxBigFragmentId) {
      packed.small_entity.fragment_id = id.fragment_id - kMaxBigFragmentId;
      packed.small_entity.is_big = 0u;
      packed.small_entity.is_fragment_entity = 1u;
      packed.small_entity.sub_kind = kNumDeclKinds +
                                     static_cast<uint64_t>(id.kind);
      packed.small_entity.offset = id.offset;
      assert(packed.small_entity.offset == id.offset);

    } else {
      packed.big_entity.fragment_id = id.fragment_id;
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
    assert(std::holds_alternative<StmtId>(unpacked));
    assert(std::get<StmtId>(unpacked) == id);
#endif
  }
}

EntityId::EntityId(TypeId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id >= kMaxBigFragmentId) {
      packed.small_entity.fragment_id = id.fragment_id - kMaxBigFragmentId;
      packed.small_entity.is_big = 0u;
      packed.small_entity.is_fragment_entity = 1u;
      packed.small_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                     static_cast<uint64_t>(id.kind);
      packed.small_entity.offset = id.offset;
      assert(packed.small_entity.offset == id.offset);

    } else {
      packed.big_entity.fragment_id = id.fragment_id;
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

EntityId::EntityId(AttrId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id >= kMaxBigFragmentId) {
      packed.small_entity.fragment_id = id.fragment_id - kMaxBigFragmentId;
      packed.small_entity.is_big = 0u;
      packed.small_entity.is_fragment_entity = 1u;
      packed.small_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                     kNumTypeKinds +
                                     static_cast<uint64_t>(id.kind);
      packed.small_entity.offset = id.offset;
      assert(packed.small_entity.offset == id.offset);

    } else {
      packed.big_entity.fragment_id = id.fragment_id;
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
    assert(std::holds_alternative<AttrId>(unpacked));
    assert(std::get<AttrId>(unpacked) == id);
#endif
  }
}

EntityId::EntityId(ParsedTokenId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id >= kMaxBigFragmentId) {
      packed.small_entity.fragment_id = id.fragment_id - kMaxBigFragmentId;
      packed.small_entity.is_big = 0u;
      packed.small_entity.is_fragment_entity = 1u;
      packed.small_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                     kNumTypeKinds + kNumAttrKinds +
                                     static_cast<uint64_t>(id.kind);
      packed.small_entity.offset = id.offset;
      assert(packed.small_entity.offset == id.offset);

    } else {
      packed.big_entity.fragment_id = id.fragment_id;
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
      packed.small_entity.fragment_id = id.fragment_id - kMaxBigFragmentId;
      packed.small_entity.is_big = 0u;
      packed.small_entity.is_fragment_entity = 1u;
      packed.small_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                     kNumTypeKinds + kNumAttrKinds +
                                     kNumTokenKinds +
                                     static_cast<uint64_t>(id.kind);
      packed.small_entity.offset = id.offset;
      assert(packed.small_entity.offset == id.offset);

    } else {
      packed.big_entity.fragment_id = id.fragment_id;
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
      packed.small_entity.fragment_id = id.fragment_id - kMaxBigFragmentId;
      packed.small_entity.is_big = 0u;
      packed.small_entity.is_fragment_entity = 1u;
      packed.small_entity.sub_kind = kNumDeclKinds + kNumStmtKinds +
                                     kNumTypeKinds + kNumAttrKinds +
                                     kNumTokenKinds + kNumTokenKinds +
                                     static_cast<uint64_t>(id.kind);
      packed.small_entity.offset = id.offset;
      assert(packed.small_entity.offset == id.offset);

    } else {
      packed.big_entity.fragment_id = id.fragment_id;
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

EntityId::EntityId(TemplateArgumentId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id >= kMaxBigFragmentId) {
      packed.small_entity.fragment_id = id.fragment_id - kMaxBigFragmentId;
      packed.small_entity.is_big = 0u;
      packed.small_entity.is_fragment_entity = 1u;
      packed.small_entity.sub_kind =
          kNumDeclKinds + kNumStmtKinds + kNumTypeKinds + kNumAttrKinds +
          kNumTokenKinds + kNumTokenKinds + kNumMacroKinds +
          static_cast<uint64_t>(IdentifiedPseudo::kTemplateArgument);
      packed.small_entity.offset = id.offset;
      assert(packed.small_entity.offset == id.offset);

    } else {
      packed.big_entity.fragment_id = id.fragment_id;
      packed.big_entity.is_big = 1u;
      packed.big_entity.is_fragment_entity = 1u;
      packed.big_entity.sub_kind =
          kNumDeclKinds + kNumStmtKinds + kNumTypeKinds + kNumAttrKinds +
          kNumTokenKinds + kNumTokenKinds + kNumMacroKinds +
          static_cast<uint64_t>(IdentifiedPseudo::kTemplateArgument);
      packed.big_entity.offset = id.offset;
      assert(packed.big_entity.offset == id.offset);
    }
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<TemplateArgumentId>(unpacked));
    assert(std::get<TemplateArgumentId>(unpacked) == id);
#endif
  }
}

EntityId::EntityId(TemplateParameterListId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id >= kMaxBigFragmentId) {
      packed.small_entity.fragment_id = id.fragment_id - kMaxBigFragmentId;
      packed.small_entity.is_big = 0u;
      packed.small_entity.is_fragment_entity = 1u;
      packed.small_entity.sub_kind =
          kNumDeclKinds + kNumStmtKinds + kNumTypeKinds + kNumAttrKinds +
          kNumTokenKinds + kNumTokenKinds + kNumMacroKinds +
          static_cast<uint64_t>(IdentifiedPseudo::kTemplateParameterList);
      packed.small_entity.offset = id.offset;
      assert(packed.small_entity.offset == id.offset);

    } else {
      packed.big_entity.fragment_id = id.fragment_id;
      packed.big_entity.is_big = 1u;
      packed.big_entity.is_fragment_entity = 1u;
      packed.big_entity.sub_kind =
          kNumDeclKinds + kNumStmtKinds + kNumTypeKinds + kNumAttrKinds +
          kNumTokenKinds + kNumTokenKinds + kNumMacroKinds +
          static_cast<uint64_t>(IdentifiedPseudo::kTemplateParameterList);
      packed.big_entity.offset = id.offset;
      assert(packed.big_entity.offset == id.offset);
    }
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<TemplateParameterListId>(unpacked));
    assert(std::get<TemplateParameterListId>(unpacked) == id);
#endif
  }
}


EntityId::EntityId(CXXBaseSpecifierId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id >= kMaxBigFragmentId) {
      packed.small_entity.fragment_id = id.fragment_id - kMaxBigFragmentId;
      packed.small_entity.is_big = 0u;
      packed.small_entity.is_fragment_entity = 1u;
      packed.small_entity.sub_kind =
          kNumDeclKinds + kNumStmtKinds + kNumTypeKinds + kNumAttrKinds +
          kNumTokenKinds + kNumTokenKinds + kNumMacroKinds +
          static_cast<uint64_t>(IdentifiedPseudo::kTemplateParameterList);
      packed.small_entity.offset = id.offset;
      assert(packed.small_entity.offset == id.offset);

    } else {
      packed.big_entity.fragment_id = id.fragment_id;
      packed.big_entity.is_big = 1u;
      packed.big_entity.is_fragment_entity = 1u;
      packed.big_entity.sub_kind =
          kNumDeclKinds + kNumStmtKinds + kNumTypeKinds + kNumAttrKinds +
          kNumTokenKinds + kNumTokenKinds + kNumMacroKinds +
          static_cast<uint64_t>(IdentifiedPseudo::kCXXBaseSpecifier);
      packed.big_entity.offset = id.offset;
      assert(packed.big_entity.offset == id.offset);
    }
    opaque = packed.opaque;

#ifndef NDEBUG
    auto unpacked = Unpack();
    assert(std::holds_alternative<CXXBaseSpecifierId>(unpacked));
    assert(std::get<CXXBaseSpecifierId>(unpacked) == id);
#endif
  }
}

EntityId::EntityId(DesignatorId id) {
  if (id.fragment_id) {
    PackedEntityId packed = {};
    if (id.fragment_id >= kMaxBigFragmentId) {
      packed.small_entity.fragment_id = id.fragment_id - kMaxBigFragmentId;
      packed.small_entity.is_big = 0u;
      packed.small_entity.is_fragment_entity = 1u;
      packed.small_entity.sub_kind =
          kNumDeclKinds + kNumStmtKinds + kNumTypeKinds + kNumAttrKinds +
          kNumTokenKinds + kNumTokenKinds + kNumMacroKinds +
          static_cast<uint64_t>(IdentifiedPseudo::kDesignator);
      packed.small_entity.offset = id.offset;
      assert(packed.small_entity.offset == id.offset);

    } else {
      packed.big_entity.fragment_id = id.fragment_id;
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

// Return the fragment offset from an entity ID. Returns `~0u` if it's not
// a fragment-specific entity ID.
std::optional<EntityOffset> FragmentOffsetFromEntityId(RawEntityId id) {
  PackedEntityId packed = {};
  packed.opaque = id;
  if (!packed.entity_or_other.is_fragment_entity) {
    return std::nullopt;
  }

  if (packed.small_or_big.is_big) {
    return static_cast<EntityOffset>(packed.big_entity.offset);
  } else {
    return static_cast<EntityOffset>(packed.small_entity.offset);
  }
}

// Returns the fragment ID corresponding with a fragment-specific entity ID.
std::optional<PackedFragmentId> FragmentIdFromEntityId(RawEntityId id) {
  PackedEntityId packed = {};
  packed.opaque = id;

  if (!packed.entity_or_other.is_fragment_entity) {
    if (packed.other.kind == static_cast<uint64_t>(OtherKind::kFragment) &&
        !packed.other.sub_kind && packed.other.opaque) {
      return FragmentId(packed.other.opaque);
    }

    return std::nullopt;
  }

  if (packed.small_or_big.is_big) {
    return FragmentId(packed.big_entity.fragment_id);
  } else {
    return FragmentId(packed.small_entity.fragment_id + kMaxBigFragmentId);
  }
}

namespace {

struct IDKind {
  inline int operator()(InvalidId) const noexcept { return -1; }
  inline int operator()(FileId) const noexcept { return -1; }
  inline int operator()(FragmentId) const noexcept { return -1; }
  inline int operator()(DesignatorId) const noexcept { return -1; }
  template <typename T>
  inline int operator()(T t) const noexcept {
    return static_cast<int>(t.kind);
  }
};

struct IDCategory {
  inline EntityCategory operator()(InvalidId) const noexcept {
    return EntityCategory::NOT_AN_ENTITY;
  }
  inline EntityCategory operator()(DeclId) const noexcept {
    return EntityCategory::DECLARATION;
  }
  inline EntityCategory operator()(StmtId) const noexcept {
    return EntityCategory::STATEMENT;
  }
  inline EntityCategory operator()(TypeId) const noexcept {
    return EntityCategory::TYPE;
  }
  inline EntityCategory operator()(AttrId) const noexcept {
    return EntityCategory::ATTRIBUTE;
  }
  inline EntityCategory operator()(MacroId) const noexcept {
    return EntityCategory::MACRO;
  }
  inline EntityCategory operator()(FragmentId) const noexcept {
    return EntityCategory::FRAGMENT;
  }
  inline EntityCategory operator()(FileId) const noexcept {
    return EntityCategory::FILE;
  }
  inline EntityCategory operator()(ParsedTokenId) const noexcept {
    return EntityCategory::TOKEN;
  }
  inline EntityCategory operator()(FileTokenId) const noexcept {
    return EntityCategory::TOKEN;
  }
  inline EntityCategory operator()(MacroTokenId) const noexcept {
    return EntityCategory::TOKEN;
  }
  inline EntityCategory operator()(DesignatorId) const noexcept {
    return EntityCategory::DESIGNATOR;
  }
  template <typename T>
  inline EntityCategory operator()(T) const noexcept {
    assert(false);
    return EntityCategory::NOT_AN_ENTITY;
  }
};

}  // namespace

// Returns the kind of an entity as an undifferentiated integer.
int KindFromEntityId(RawEntityId id) {
  return std::visit<int>(IDKind{}, EntityId(id).Unpack());
}

// Returns the category of entity as an enum.
EntityCategory CategoryFromEntityId(RawEntityId id) {
  return std::visit<EntityCategory>(IDCategory{}, EntityId(id).Unpack());
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
        DeclId id;
        id.fragment_id = packed.big_entity.fragment_id;
        if (sub_kind < kActualNumDeclKinds) {
          id.kind = static_cast<DeclKind>(sub_kind);
          id.is_definition = true;
        } else {
          id.kind = static_cast<DeclKind>(sub_kind - kActualNumDeclKinds);
          id.is_definition = false;
        }
        id.offset = static_cast<EntityOffset>(packed.big_entity.offset);
        return id;
      }

      sub_kind -= kNumDeclKinds;
      if (sub_kind < kNumStmtKinds) {
        StmtId id;
        id.fragment_id = packed.big_entity.fragment_id;
        id.kind = static_cast<StmtKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.big_entity.offset);
        return id;
      }

      sub_kind -= kNumStmtKinds;
      if (sub_kind < kNumTypeKinds) {
        TypeId id;
        id.fragment_id = packed.big_entity.fragment_id;
        id.kind = static_cast<TypeKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.big_entity.offset);
        return id;
      }

      sub_kind -= kNumTypeKinds;
      if (sub_kind < kNumAttrKinds) {
        AttrId id;
        id.fragment_id = packed.big_entity.fragment_id;
        id.kind = static_cast<AttrKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.big_entity.offset);
        return id;
      }

      sub_kind -= kNumAttrKinds;
      if (sub_kind < kNumTokenKinds) {
        ParsedTokenId id;
        id.fragment_id = packed.big_entity.fragment_id;
        id.kind = static_cast<TokenKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.big_entity.offset);
        return id;
      }

      sub_kind -= kNumTokenKinds;
      if (sub_kind < kNumTokenKinds) {
        MacroTokenId id;
        id.fragment_id = packed.big_entity.fragment_id;
        id.kind = static_cast<TokenKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.big_entity.offset);
        return id;
      }

      sub_kind -= kNumTokenKinds;
      if (sub_kind < kNumMacroKinds) {
        MacroId id;
        id.fragment_id = packed.big_entity.fragment_id;
        id.kind = static_cast<MacroKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.big_entity.offset);
        return id;
      }

      sub_kind -= kNumMacroKinds;
      if (sub_kind < kNumPseudoKinds) {
        switch (static_cast<IdentifiedPseudo>(sub_kind)) {
          case IdentifiedPseudo::kTemplateArgument: {
            TemplateArgumentId id;
            id.fragment_id = packed.big_entity.fragment_id;
            id.offset = static_cast<EntityOffset>(packed.big_entity.offset);
            return id;
          }
          case IdentifiedPseudo::kTemplateParameterList: {
            TemplateParameterListId id;
            id.fragment_id = packed.big_entity.fragment_id;
            id.offset = static_cast<EntityOffset>(packed.big_entity.offset);
            return id;
          }
          case IdentifiedPseudo::kCXXBaseSpecifier: {
            CXXBaseSpecifierId id;
            id.fragment_id = packed.big_entity.fragment_id;
            id.offset = static_cast<EntityOffset>(packed.big_entity.offset);
            return id;
          }
          case IdentifiedPseudo::kDesignator: {
            DesignatorId id;
            id.fragment_id = packed.big_entity.fragment_id;
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
        DeclId id;
        id.fragment_id = packed.small_entity.fragment_id + kMaxBigFragmentId;
        if (sub_kind < kActualNumDeclKinds) {
          id.kind = static_cast<DeclKind>(sub_kind);
          id.is_definition = true;
        } else {
          id.kind = static_cast<DeclKind>(sub_kind - kActualNumDeclKinds);
          id.is_definition = false;
        }
        id.offset = static_cast<EntityOffset>(packed.small_entity.offset);
        return id;
      }

      sub_kind -= kNumDeclKinds;
      if (sub_kind < kNumStmtKinds) {
        StmtId id;
        id.fragment_id = packed.small_entity.fragment_id + kMaxBigFragmentId;
        id.kind = static_cast<StmtKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.small_entity.offset);
        return id;
      }

      sub_kind -= kNumStmtKinds;
      if (sub_kind < kNumTypeKinds) {
        TypeId id;
        id.fragment_id = packed.small_entity.fragment_id + kMaxBigFragmentId;
        id.kind = static_cast<TypeKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.small_entity.offset);
        return id;
      }

      sub_kind -= kNumTypeKinds;
      if (sub_kind < kNumAttrKinds) {
        AttrId id;
        id.fragment_id = packed.small_entity.fragment_id + kMaxBigFragmentId;
        id.kind = static_cast<AttrKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.small_entity.offset);
        return id;
      }

      sub_kind -= kNumAttrKinds;
      if (sub_kind < kNumTokenKinds) {
        ParsedTokenId id;
        id.fragment_id = packed.small_entity.fragment_id + kMaxBigFragmentId;
        id.kind = static_cast<TokenKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.small_entity.offset);
        return id;
      }

      sub_kind -= kNumTokenKinds;
      if (sub_kind < kNumTokenKinds) {
        MacroTokenId id;
        id.fragment_id = packed.small_entity.fragment_id + kMaxBigFragmentId;
        id.kind = static_cast<TokenKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.small_entity.offset);
        return id;
      }

      sub_kind -= kNumTokenKinds;
      if (sub_kind < kNumMacroKinds) {
        MacroId id;
        id.fragment_id = packed.small_entity.fragment_id + kMaxBigFragmentId;
        id.kind = static_cast<MacroKind>(sub_kind);
        id.offset = static_cast<EntityOffset>(packed.small_entity.offset);
        return id;
      }

      sub_kind -= kNumMacroKinds;
      if (sub_kind < kNumPseudoKinds) {
        switch (static_cast<IdentifiedPseudo>(sub_kind)) {
          case IdentifiedPseudo::kTemplateArgument: {
            TemplateArgumentId id;
            id.fragment_id = packed.small_entity.fragment_id + kMaxBigFragmentId;
            id.offset = static_cast<EntityOffset>(packed.small_entity.offset);
            return id;
          }
          case IdentifiedPseudo::kTemplateParameterList: {
            TemplateParameterListId id;
            id.fragment_id = packed.small_entity.fragment_id + kMaxBigFragmentId;
            id.offset = static_cast<EntityOffset>(packed.small_entity.offset);
            return id;
          }
          case IdentifiedPseudo::kCXXBaseSpecifier: {
            CXXBaseSpecifierId id;
            id.fragment_id = packed.small_entity.fragment_id + kMaxBigFragmentId;
            id.offset = static_cast<EntityOffset>(packed.small_entity.offset);
            return id;
          }
          case IdentifiedPseudo::kDesignator: {
            DesignatorId id;
            id.fragment_id = packed.small_entity.fragment_id + kMaxBigFragmentId;
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

struct IdVisitor {
  inline RawEntityId operator()(const NotAnEntity &) const noexcept {
    return kInvalidEntityId;
  }
  template <typename T>
  inline RawEntityId operator()(const T &e) const noexcept {
    return e.id().Pack();
  }
};

// Explicit specialization to get the entity id.
template <>
EntityId::EntityId(const VariantEntity &ent)
    : opaque(std::visit<RawEntityId>(IdVisitor{}, ent)) {}

}  // namespace mx
