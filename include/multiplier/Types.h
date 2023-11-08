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
#define MX_FOR_EACH_ENTITY_CATEGORY(file_, token_, type_, frag_, frag_offset_, pseudo_, tu_) \
    frag_(Fragment, fragment, FRAGMENT, 1) \
    frag_offset_(Decl, declaration, DECLARATION, 2) \
    frag_offset_(Stmt, statement, STATEMENT, 3) \
    frag_offset_(Attr, attribute, ATTRIBUTE, 4) \
    frag_offset_(Macro, macro, MACRO, 5) \
    type_(Type, type, TYPE, 6) \
    file_(File, file, FILE, 7) \
    token_(Token, token, TOKEN, 8) \
    pseudo_(TemplateArgument, template_argument, TEMPLATE_ARGUMENT, 9) \
    pseudo_(TemplateParameterList, template_parameter_list, TEMPLATE_PARAMETER_LIST, 10) \
    pseudo_(CXXBaseSpecifier, cxx_base_specifier, CXX_BASE_SPECIFIER, 11) \
    pseudo_(Designator, designator, DESIGNATOR, 12) \
    tu_(Compilation, compilation, COMPILATION, 13)

#define MX_DECLARE_ENTITY_CLASS(type, lower, enum_, val) \
    class type;\
    class type ## Impl;

MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_ENTITY_CLASS,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DECLARE_ENTITY_CLASS,
                            MX_DECLARE_ENTITY_CLASS,
                            MX_DECLARE_ENTITY_CLASS,
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
                              MX_DECLARE_ENTITY_CATEGORY_ENUM,
                              MX_DECLARE_ENTITY_CATEGORY_ENUM,
                              MX_DECLARE_ENTITY_CATEGORY_ENUM,
                              MX_DECLARE_ENTITY_CATEGORY_ENUM)
#undef MX_DECLARE_ENTITY_CATEGORY_ENUM
};

using RawEntityId = uint64_t;

static constexpr RawEntityId kInvalidEntityId = 0ull;

class EntityId;

struct AttrId;
struct DeclId;
struct StmtId;
struct TypeTokenId;
struct FileTokenId;
struct MacroTokenId;
struct ParsedTokenId;
struct MacroId;

// Pseudo entities.
struct TemplateArgumentId;
struct TemplateParameterListId;
struct CXXBaseSpecifierId;
struct DesignatorId;
struct CompilationId;

using EntityOffset = uint32_t;
using SignedEntityOffset = int32_t;

inline static constexpr unsigned NumEnumerators(EntityCategory) {
#define MX_COUNT_ENTITY_CATEGORIES(...) + 1u
  return 1 MX_FOR_EACH_ENTITY_CATEGORY(MX_COUNT_ENTITY_CATEGORIES,
                                       MX_COUNT_ENTITY_CATEGORIES,
                                       MX_COUNT_ENTITY_CATEGORIES,
                                       MX_COUNT_ENTITY_CATEGORIES,
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
struct FileId final {
  RawEntityId file_id;
  
  bool operator==(const FileId &) const noexcept = default;
  auto operator<=>(const FileId &) const noexcept = default;

  inline explicit FileId(RawEntityId file_id_)
      : file_id(file_id_) {}

  inline /* implicit */ FileId(const FileTokenId &);
  inline /* implicit */ FileId(const CompilationId &);
};

// Identifies a serialized version of a `clang::Decl` or `pasta::Decl`
// inside of a `Fragment`.
struct DeclId final {
  RawEntityId fragment_id;
  DeclKind kind;

  // Offset of where this declaration is stored inside of
  // `rpc::Fragment::declarations`.
  EntityOffset offset;

  // Is this declaration a definition?
  bool is_definition;

  bool operator==(const DeclId &) const noexcept = default;
  auto operator<=>(const DeclId &) const noexcept = default;
};

// Identifies a serialized version of a `clang::Stmt` or `pasta::Stmt`
// inside of a `Fragment`.
struct StmtId final {
  RawEntityId fragment_id;
  StmtKind kind;

  // Offset of where this statement is stored inside of
  // `rpc::Fragment::statements`.
  EntityOffset offset;

  bool operator==(const StmtId &) const noexcept = default;
  auto operator<=>(const StmtId &) const noexcept = default;
};

// Identifies a serialized type
struct TypeId final {
  RawEntityId type_id;
  TypeKind kind;

  bool operator==(const TypeId &) const noexcept = default;
  auto operator<=>(const TypeId &) const noexcept = default;

  inline /* implicit */ TypeId(RawEntityId type_id_, TypeKind kind_)
      : type_id(type_id_), kind(kind_) {}

  inline /* implicit */ TypeId(const TypeTokenId &id);
};

// Identifies a serialized tokens of a `clang::Type`, `clang::QualType`, or
// `pasta::Type`
struct TypeTokenId final {
  RawEntityId type_id;

  // Type kind
  TypeKind type_kind;

  // Token kind
  TokenKind kind;

  // Offset of where this token is stored inside of
  EntityOffset offset;

  bool operator==(const TypeTokenId &) const noexcept = default;
  auto operator<=>(const TypeTokenId &) const noexcept = default;
};

// Identifies a serialized version of a `clang::Attr` or `pasta::Attr` inside
// of a `Fragment`.
struct AttrId final {
  RawEntityId fragment_id;
  AttrKind kind;

  // Offset of where this attribute is stored inside of
  // `rpc::Fragment::attrs`.
  EntityOffset offset;

  bool operator==(const AttrId &) const noexcept = default;
  auto operator<=>(const AttrId &) const noexcept = default;
};

// Identifies a parsed token inside of a `Fragment`.
struct ParsedTokenId final {
  RawEntityId fragment_id;
  TokenKind kind;

  // Offset of where this token is stored inside of a serialized
  // `rpc::Fragment::tokenKinds` (and other token related lists).
  EntityOffset offset;

  bool operator==(const ParsedTokenId &) const noexcept = default;
  auto operator<=>(const ParsedTokenId &) const noexcept = default;
};

// Identifies a token inside of a `File`.
struct FileTokenId final {
  RawEntityId file_id;

  TokenKind kind;

  // Offset of this where this token is stored inside of a serialized
  // `rpc::File::tokens` list.
  EntityOffset offset;

  bool operator==(const FileTokenId &) const noexcept = default;
  auto operator<=>(const FileTokenId &) const noexcept = default;
};

// Identifies a token inside of a `Fragment` that corresponds to a macro
// use or macro expansion.
struct MacroTokenId final {
  RawEntityId fragment_id;
  TokenKind kind;

  // Offset of this where this token is stored inside of a serialized
  // `rpc::File::tokens` list.
  EntityOffset offset;

  bool operator==(const MacroTokenId &) const noexcept = default;
  auto operator<=>(const MacroTokenId &) const noexcept = default;
};

// The offset of a substitution inside of a fragment.
struct MacroId final {
 public:
  RawEntityId fragment_id;

  MacroKind kind;

  // Offset of where this token substitution is stored inside of a
  // serialized `rpc::Fragment::tokenSubstitutions`.
  EntityOffset offset;

  bool operator==(const MacroId &) const noexcept = default;
  auto operator<=>(const MacroId &) const noexcept = default;
};

// A template argument is
struct TemplateArgumentId final {
 public:
  RawEntityId fragment_id;

  // Offset of the argument inside of the fragment.
  EntityOffset offset;

  static constexpr PseudoKind kind = PseudoKind::TEMPLATE_ARGUMENT;

  bool operator==(const TemplateArgumentId &) const noexcept = default;
  auto operator<=>(const TemplateArgumentId &) const noexcept = default;
};

// A template parameter list is used by a template declaration to describe
// the list of template parameter declarations.
struct TemplateParameterListId final {
 public:
  RawEntityId fragment_id;

  // Offset of the parameter list inside of the fragment.
  EntityOffset offset;

  // TODO(pag): Have a Boolean to allow representing argument lists as well?

  static constexpr PseudoKind kind = PseudoKind::TEMPLATE_PARAMETER_LIST;

  bool operator==(const TemplateParameterListId &) const noexcept = default;
  auto operator<=>(const TemplateParameterListId &) const noexcept = default;
};

// A base specifier is used by a `CXXRecordDecl` (or derived class) to
// specify base classes.
struct CXXBaseSpecifierId final {
 public:
  RawEntityId fragment_id;

  // Offset of the base specifier inside of the fragment.
  EntityOffset offset;

  static constexpr PseudoKind kind = PseudoKind::CXX_BASE_SPECIFIER;

  bool operator==(const CXXBaseSpecifierId &) const noexcept = default;
  auto operator<=>(const CXXBaseSpecifierId &) const noexcept = default;
};

// A designator is used by a designated initializer expression.
struct DesignatorId final {
 public:
  RawEntityId fragment_id;

  // Offset of the designator inside of the fragment.
  EntityOffset offset;

  static constexpr PseudoKind kind = PseudoKind::DESIGNATOR;

  bool operator==(const DesignatorId &) const noexcept = default;
  auto operator<=>(const DesignatorId &) const noexcept = default;
};

// Translation units represent a compilation. From a translation unit we can
// get the compile command, the MLIR, etc.
struct CompilationId {
  // The ID of the compilation/translation unit.
  RawEntityId compilation_id;

  // The ID (FileId::file_id) of the main source file of the compilation.
  RawEntityId file_id;

  inline explicit CompilationId(RawEntityId compilation_id_,
                                RawEntityId file_id_)
      : compilation_id(compilation_id_),
        file_id(file_id_) {}

  bool operator==(const CompilationId &) const noexcept = default;
  auto operator<=>(const CompilationId &) const noexcept = default;
};

// Identifies a serialized fragment.
struct FragmentId final {
  RawEntityId fragment_id;

  bool operator==(const FragmentId &) const noexcept = default;
  auto operator<=>(const FragmentId &) const noexcept = default;

  inline explicit FragmentId(RawEntityId fragment_id_)
      : fragment_id(fragment_id_) {}

  inline /* implicit */ FragmentId(const DeclId &id_)
      : fragment_id(id_.fragment_id) {}
  inline /* implicit */ FragmentId(const StmtId &id_)
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

  static std::optional<FragmentId> from(const EntityId &);
};

inline FileId::FileId(const FileTokenId &id_)
    : file_id(id_.file_id) {}

inline FileId::FileId(const CompilationId &id_)
    : file_id(id_.file_id) {}

inline TypeId::TypeId(const TypeTokenId &id_)
    : type_id(id_.type_id), kind(id_.type_kind) {}

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
                                MX_ENTITY_ID_VARIANT,
                                MX_ENTITY_ID_VARIANT,
                                MX_ENTITY_ID_VARIANT,
                                MX_ENTITY_ID_VARIANT)
    ParsedTokenId, MacroTokenId, FileTokenId, TypeTokenId>;
#undef MX_ENTITY_ID_VARIANT

template <typename T>
class SpecificEntityId;

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
  /* implicit */ EntityId(TypeTokenId id);
  /* implicit */ EntityId(AttrId id);
  /* implicit */ EntityId(ParsedTokenId id);
  /* implicit */ EntityId(MacroTokenId id);
  /* implicit */ EntityId(MacroId id);
  /* implicit */ EntityId(FileTokenId id);
  /* implicit */ EntityId(TemplateArgumentId id);
  /* implicit */ EntityId(TemplateParameterListId id);
  /* implicit */ EntityId(CXXBaseSpecifierId id);
  /* implicit */ EntityId(DesignatorId id);
  /* implicit */ EntityId(CompilationId id);

  template <typename T>
  /* implicit */ inline EntityId(SpecificEntityId<T>);

  template <typename... Types>
  /* implicit */ EntityId(const std::variant<Types...> &) = delete;

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

  inline EntityId &operator=(TypeTokenId id) {
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

  inline RawEntityId Pack(void) const noexcept {
    return opaque;
  }

  inline bool operator!(void) const noexcept {
    return opaque == kInvalidEntityId;
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

template <typename T>
EntityId::EntityId(SpecificEntityId<T> id_)
    : EntityId(id_.Pack()) {}

using PackedFileTokenId = SpecificEntityId<FileTokenId>;

template <typename T>
struct EntityTypeImpl;

#define MX_MAP_ENTITY_TYPE(type_name, lower_name, enum_name, val) \
    using Packed ## type_name ## Id = SpecificEntityId<type_name ## Id>; \
    \
    template <> \
    struct EntityTypeImpl<type_name ## Id> { \
      using Entity = type_name; \
    };

MX_FOR_EACH_ENTITY_CATEGORY(MX_MAP_ENTITY_TYPE,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_MAP_ENTITY_TYPE,
                            MX_MAP_ENTITY_TYPE,
                            MX_MAP_ENTITY_TYPE,
                            MX_MAP_ENTITY_TYPE,
                            MX_MAP_ENTITY_TYPE)
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
struct hash<mx::TypeId> {
  inline bool operator()(mx::TypeId id) const noexcept {
    return id.type_id;
  }
};

template <>
struct less<mx::TypeId> {
  inline bool operator()(mx::TypeId a, mx::TypeId b) const noexcept {
    return a.type_id < b.type_id;
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
