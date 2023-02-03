// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cassert>
#include <compare>
#include <cstdint>
#include <functional>
#include <iosfwd>
#include <multiplier/Entities/PseudoKind.h>
#include <utility>
#include <optional>
#include <variant>

namespace mx {
namespace rpc {
class FileInfo;
}  // namespace rpc

class Token;

enum class AttrKind : unsigned short;
enum class DeclKind : unsigned char;
enum class MacroKind : unsigned char;
enum class StmtKind : unsigned char;
enum class TokenKind : unsigned short;
enum class TypeKind : unsigned char;

#define MX_IGNORE_ENTITY_CATEGORY(type_name, lower_name, enum_name, category)
#define MX_FOR_EACH_ENTITY_CATEGORY(file_, token_, frag_, frag_offset) \
    frag_offset(Decl, declaration, DECLARATION, 1) \
    frag_offset(Stmt, statement, STATEMENT, 2) \
    frag_offset(Type, type, TYPE, 3) \
    frag_offset(Attr, attribute, ATTRIBUTE, 4) \
    frag_offset(Macro, macro, MACRO, 5) \
    frag_(Fragment, fragment, FRAGMENT, 6) \
    file_(File, file, FILE, 7) \
    token_(Token, token, TOKEN, 8) \
    frag_offset(TemplateArgument, template_argument, TEMPLATE_ARGUMENT, 9) \
    frag_offset(TemplateParameterList, template_parameter_list, TEMPLATE_PARAMETER_LIST, 10) \
    frag_offset(CXXBaseSpecifier, cxx_base_specifier, CXX_BASE_SPECIFIER, 11) \
    frag_offset(Designator, designator, DESIGNATOR, 12)

#define MX_DECLARE_ENTITY_CLASS(type, lower, enum_, val) \
    class type;\
    class type ## Impl;

MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_ENTITY_CLASS,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DECLARE_ENTITY_CLASS,
                            MX_DECLARE_ENTITY_CLASS)
#undef MX_DECLARE_ENTITY_CLASS

using NotAnEntity = std::monostate;

enum class EntityCategory {
  NOT_AN_ENTITY,
#define MX_DECLARE_ENTITY_CATEGORY_ENUM(type, lower, enum_, val) enum_ = val,
  MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_ENTITY_CATEGORY_ENUM,
                              MX_DECLARE_ENTITY_CATEGORY_ENUM,
                              MX_DECLARE_ENTITY_CATEGORY_ENUM,
                              MX_DECLARE_ENTITY_CATEGORY_ENUM)
#undef MX_DECLARE_ENTITY_CATEGORY_ENUM
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

struct AttrId;
struct DeclId;
struct StmtId;
struct TypeId;
struct FileTokenId;
struct MacroTokenId;
struct ParsedTokenId;
struct MacroId;

// Pseudo entities.
struct TemplateArgumentId;
struct TemplateParameterListId;
struct CXXBaseSpecifierId;
struct DesignatorId;

using EntityOffset = uint32_t;
using SignedEntityOffset = int32_t;

inline static constexpr unsigned NumEnumerators(EntityCategory) {
#define MX_COUNT_ENTITY_CATEGORIES(...) + 1u
  return 1 MX_FOR_EACH_ENTITY_CATEGORY(MX_COUNT_ENTITY_CATEGORIES,
                                       MX_COUNT_ENTITY_CATEGORIES,
                                       MX_COUNT_ENTITY_CATEGORIES,
                                       MX_COUNT_ENTITY_CATEGORIES);
#undef MX_COUNT_ENTITY_CATEGORIES
}

inline static constexpr const char *EnumerationName(EntityCategory) {
  return "EntityCategory";
}

const char *EnumeratorName(EntityCategory) noexcept;

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
struct DeclId {
  RawEntityId fragment_id;
  DeclKind kind;

  // Offset of where this declaration is stored inside of
  // `rpc::Fragment::declarations`.
  EntityOffset offset;

  // Is this declaration a definition?
  bool is_definition;

  auto operator<=>(const DeclId &) const noexcept = default;
};

// Identifies a serialized version of a `clang::Stmt` or `pasta::Stmt`
// inside of a `Fragment`.
struct StmtId {
  RawEntityId fragment_id;
  StmtKind kind;

  // Offset of where this statement is stored inside of
  // `rpc::Fragment::statements`.
  EntityOffset offset;

  auto operator<=>(const StmtId &) const noexcept = default;
};

// Identifies a serialized version of a `clang::Type`, `clang::QualType`, or
// `pasta::Type` inside of a `Fragment`.
struct TypeId {
  RawEntityId fragment_id;
  TypeKind kind;

  // Offset of where this statement is stored inside of
  // `rpc::Fragment::types`.
  EntityOffset offset;

  auto operator<=>(const TypeId &) const noexcept = default;
};

// Identifies a serialized version of a `clang::Attr` or `pasta::Attr` inside
// of a `Fragment`.
struct AttrId {
  RawEntityId fragment_id;
  AttrKind kind;

  // Offset of where this attribute is stored inside of
  // `rpc::Fragment::attrs`.
  EntityOffset offset;

  auto operator<=>(const AttrId &) const noexcept = default;
};

// Identifies a parsed token inside of a `Fragment`.
struct ParsedTokenId {
  RawEntityId fragment_id;
  TokenKind kind;

  // Offset of where this token is stored inside of a serialized
  // `rpc::Fragment::tokenKinds` (and other token related lists).
  EntityOffset offset;

  auto operator<=>(const ParsedTokenId &) const noexcept = default;
};

// Identifies a token inside of a `File`.
struct FileTokenId {
  RawEntityId file_id;

  TokenKind kind;

  // Offset of this where this token is stored inside of a serialized
  // `rpc::File::tokens` list.
  EntityOffset offset;

  auto operator<=>(const FileTokenId &) const noexcept = default;
};

// Identifies a token inside of a `Fragment` that corresponds to a macro
// use or macro expansion.
struct MacroTokenId {
  RawEntityId fragment_id;
  TokenKind kind;

  // Offset of this where this token is stored inside of a serialized
  // `rpc::File::tokens` list.
  EntityOffset offset;

  auto operator<=>(const MacroTokenId &) const noexcept = default;
};

// The offset of a substitution inside of a fragment.
struct MacroId {
 public:
  RawEntityId fragment_id;

  MacroKind kind;

  // Offset of where this token substitution is stored inside of a
  // serialized `rpc::Fragment::tokenSubstitutions`.
  EntityOffset offset;

  auto operator<=>(const MacroId &) const noexcept = default;
};

struct TemplateArgumentId {
 public:
  RawEntityId fragment_id;

  // Offset of the argument inside of the fragment.
  EntityOffset offset;

  static constexpr PseudoKind kind = PseudoKind::TEMPLATE_ARGUMENT;

  auto operator<=>(const TemplateArgumentId &) const noexcept = default;
};

struct TemplateParameterListId {
 public:
  RawEntityId fragment_id;

  // Offset of the parameter list inside of the fragment.
  EntityOffset offset;

  static constexpr PseudoKind kind = PseudoKind::TEMPLATE_PARAMETER_LIST;

  auto operator<=>(const TemplateParameterListId &) const noexcept = default;
};

struct CXXBaseSpecifierId {
 public:
  RawEntityId fragment_id;

  // Offset of the base specifier inside of the fragment.
  EntityOffset offset;

  static constexpr PseudoKind kind = PseudoKind::CXX_BASE_SPECIFIER;

  auto operator<=>(const CXXBaseSpecifierId &) const noexcept = default;
};

struct DesignatorId {
 public:
  RawEntityId fragment_id;

  // Offset of the designator inside of the fragment.
  EntityOffset offset;

  static constexpr PseudoKind kind = PseudoKind::DESIGNATOR;

  auto operator<=>(const DesignatorId &) const noexcept = default;
};

// Identifies a serialized fragment.
struct FragmentId {
  RawEntityId fragment_id;

  auto operator<=>(const FragmentId &) const noexcept = default;

  inline explicit FragmentId(RawEntityId fragment_id_)
      : fragment_id(fragment_id_) {}

  inline /* implicit */ FragmentId(const DeclId &id_)
    : fragment_id(id_.fragment_id) {}
  inline /* implicit */ FragmentId(const StmtId &id_)
    : fragment_id(id_.fragment_id) {}
  inline /* implicit */ FragmentId(const TypeId &id_)
    : fragment_id(id_.fragment_id) {}
  inline /* implicit */ FragmentId(const AttrId &id_)
    : fragment_id(id_.fragment_id) {}
  inline /* implicit */ FragmentId(const ParsedTokenId &id_)
    : fragment_id(id_.fragment_id) {}
  inline /* implicit */ FragmentId(const MacroTokenId &id_)
    : fragment_id(id_.fragment_id) {}
  inline /* implicit */ FragmentId(const MacroId &id_)
    : fragment_id(id_.fragment_id) {}
  inline /* implicit */ FragmentId(const TemplateArgumentId &id_)
    : fragment_id(id_.fragment_id) {}
  inline /* implicit */ FragmentId(const TemplateParameterListId &id_)
    : fragment_id(id_.fragment_id) {}
  inline /* implicit */ FragmentId(const CXXBaseSpecifierId &id_)
    : fragment_id(id_.fragment_id) {}
  inline /* implicit */ FragmentId(const DesignatorId &id_)
    : fragment_id(id_.fragment_id) {}
};

inline FileId::FileId(const FileTokenId &id_)
    : file_id(id_.file_id) {}

// A tag type representing an invalid entity id.
using InvalidId = std::monostate;

// Different types of token IDs.
using TokenId = std::variant<ParsedTokenId, MacroTokenId, FileTokenId>;

// Possible types of entity ids represented by a packed
// `EntityId`.
#define MX_ENTITY_ID_VARIANT(type, lower, enum_, val) type ## Id,
using VariantId = std::variant<
    InvalidId,
    MX_FOR_EACH_ENTITY_CATEGORY(MX_ENTITY_ID_VARIANT,
                                MX_IGNORE_ENTITY_CATEGORY,
                                MX_ENTITY_ID_VARIANT,
                                MX_ENTITY_ID_VARIANT)
    ParsedTokenId, MacroTokenId, FileTokenId>;
#undef MX_ENTITY_ID_VARIANT

// An opaque, compressed entity id.
class EntityId final {
 protected:
  RawEntityId opaque{kInvalidEntityId};

 public:
  EntityId(void) = default;

  // TODO(pag): Deprecate this API. Would be a good idea to make all the
  //            various expanded versions of each type into private APIs.
  /* implicit */ inline EntityId(RawEntityId opaque_)
      : opaque(opaque_) {}

  // Pack an elaborated entity ID into an opaque entity ID.
  /* implicit */ EntityId(FileId id);
  /* implicit */ EntityId(FragmentId id);
  /* implicit */ EntityId(DeclId id);
  /* implicit */ EntityId(StmtId id);
  /* implicit */ EntityId(TypeId id);
  /* implicit */ EntityId(AttrId id);
  /* implicit */ EntityId(ParsedTokenId id);
  /* implicit */ EntityId(MacroTokenId id);
  /* implicit */ EntityId(MacroId id);
  /* implicit */ EntityId(FileTokenId id);
  /* implicit */ EntityId(TemplateArgumentId id);
  /* implicit */ EntityId(TemplateParameterListId id);
  /* implicit */ EntityId(CXXBaseSpecifierId id);
  /* implicit */ EntityId(DesignatorId id);

  inline EntityId &operator=(DeclId id) {
    EntityId self(id);
    opaque = self.opaque;
    return *this;
  }

  inline EntityId &operator=(StmtId id) {
    EntityId self(id);
    opaque = self.opaque;
    return *this;
  }

  inline EntityId &operator=(TypeId id) {
    EntityId self(id);
    opaque = self.opaque;
    return *this;
  }

  inline EntityId &operator=(ParsedTokenId id) {
    EntityId self(id);
    opaque = self.opaque;
    return *this;
  }

  inline EntityId &operator=(MacroId id) {
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

  // Unpack this entity ID into a concrete type.
  VariantId Unpack(void) const noexcept;

  // Test if an entity ID is valid-looking.
  inline operator bool(void) const noexcept {
    if (opaque == kInvalidEntityId) {
      return false;
    } else {
      assert(!std::holds_alternative<InvalidId>(Unpack()));
      return true;
    }
  }

  inline RawEntityId Pack(void) const noexcept {
    return opaque;
  }

  inline bool operator==(const EntityId &that) const noexcept {
    return opaque == that.opaque;
  }

  inline bool operator!=(const EntityId &that) const noexcept {
    return opaque != that.opaque;
  }

  inline auto operator<=>(const EntityId &that) const noexcept
      -> decltype(RawEntityId() <=> RawEntityId()) {
    return opaque <=> that.opaque;
  }

  template<typename T>
  std::optional<T> Extract() {
    auto unpacked = Unpack();
    if(!std::holds_alternative<T>(unpacked)) {
      return std::nullopt;
    }
    return std::get<T>(unpacked);
  }
};

// This contains an opaque representation of an entity ID, with the requirement
// that it always contains that particular kind of entity.
template <typename T>
class SpecificEntityId final {
 private:
  RawEntityId opaque;

  SpecificEntityId(void) = delete;

 public:

  inline SpecificEntityId(const T &id_)
      : opaque(EntityId(id_).Pack()) {}

  inline SpecificEntityId<T> &operator=(const T &id) {
    opaque = EntityId(id).Pack();
    return *this;
  }

  T Unpack(void) const noexcept {
    return std::get<T>(EntityId(opaque).Unpack());
  }

  inline RawEntityId Pack(void) const noexcept {
    return opaque;
  }

  inline bool operator==(const EntityId &that) const noexcept {
    return opaque == that.Pack();
  }

  inline bool operator!=(const EntityId &that) const noexcept {
    return opaque != that.Pack();
  }

  inline bool operator==(const SpecificEntityId<T> &that) const noexcept {
    return opaque == that.opaque;
  }

  inline bool operator!=(const SpecificEntityId<T> &that) const noexcept {
    return opaque != that.opaque;
  }

  inline auto operator<=>(const SpecificEntityId<T> &that) const noexcept
      -> decltype(RawEntityId() <=> RawEntityId()) {
    return opaque <=> that.opaque;
  }
};

using PackedFileTokenId = SpecificEntityId<FileTokenId>;
using PackedDeclId = SpecificEntityId<DeclId>;
using PackedStmtId = SpecificEntityId<StmtId>;
using PackedAttrId = SpecificEntityId<AttrId>;

template <typename T>
struct EntityTypeImpl;

#define MX_MAP_ENTITY_TYPE(type, lower, enum_, val) \
    using Packed ## type ## Id = SpecificEntityId<type ## Id>; \
    \
    template <> \
    struct EntityTypeImpl<type ## Id> { \
      using Entity = type; \
    };

MX_FOR_EACH_ENTITY_CATEGORY(MX_MAP_ENTITY_TYPE,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_MAP_ENTITY_TYPE,
                            MX_MAP_ENTITY_TYPE)
#undef MX_MAP_ENTITY_TYPE

#undef MX_MAP_ENTITY_TYPE

// Given an entity ID type, get us the entity type.
template <typename T>
using EntityType = typename EntityTypeImpl<T>::Entity;

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

template <>
struct hash<mx::EntityId> {
 public:
  inline uint64_t operator()(mx::EntityId id) const noexcept {
    return id.Pack();
  }
};

template <typename T>
struct hash<mx::SpecificEntityId<T>> {
 public:
  inline uint64_t operator()(mx::SpecificEntityId<T> id) const noexcept {
    return id.Pack();
  }
};

template<class _CharT, class _Traits>
inline basic_ostream<_CharT, _Traits> &operator<<(
    basic_ostream<_CharT, _Traits> &os, mx::EntityId id) {
  return os << id.Pack();
}

template<class _CharT, class _Traits, typename T>
inline basic_ostream<_CharT, _Traits> &operator<<(
    basic_ostream<_CharT, _Traits> &os, mx::SpecificEntityId<T> id) {
  return os << id.Pack();
}

}  // namespace std
