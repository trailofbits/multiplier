// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <map>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

#include "Compilation.h"
#include "Entities/Attr.h"
#include "Entities/CXXBaseSpecifier.h"
#include "Entities/DefineMacroDirective.h"
#include "Entities/Designator.h"
#include "Entities/Macro.h"
#include "Entities/NamedDecl.h"
#include "Entities/Stmt.h"
#include "Entities/TemplateArgument.h"
#include "Entities/TemplateParameterList.h"
#include "Entities/TokenKind.h"
#include "Entities/TokenCategory.h"
#include "Entities/Type.h"
#include "File.h"
#include "Fragment.h"
#include "Iterator.h"
#include "Query.h"
#include "Reference.h"

namespace mx {

class CachingEntityProvider;
class Compilation;
class CompilationImpl;
class EntityProvider;
class Fragment;
class IncludeLikeMacroDirective;
class Index;
class InvalidEntityProvider;
class ReadMacroTokensFromFragment;
class RemoteEntityProvider;
class RegexQuery;
class RegexQueryImpl;
class RegexQueryMatch;
class TokenReader;

using FilePathEntry = std::pair<std::filesystem::path, PackedFileId>;
using FilePathMap = std::map<std::filesystem::path, PackedFileId>;
using FragmentIdList = std::vector<PackedFragmentId>;
using DeclIdList = std::vector<PackedDeclId>;
using RawEntityIdList = std::vector<RawEntityId>;
using NamedEntityList = std::vector<NamedEntity>;
using EntityProviderPtr = std::shared_ptr<EntityProvider>;

#define MX_DECLARE_ENTITY_VARIANT(type_name, lower_name, enum_name, category) \
    , type_name

using VariantEntity = std::variant<
    NotAnEntity MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_ENTITY_VARIANT,
                                            MX_DECLARE_ENTITY_VARIANT,
                                            MX_DECLARE_ENTITY_VARIANT,
                                            MX_DECLARE_ENTITY_VARIANT,
                                            MX_DECLARE_ENTITY_VARIANT,
                                            MX_DECLARE_ENTITY_VARIANT,
                                            MX_DECLARE_ENTITY_VARIANT)>;
#undef MX_DECLARE_ENTITY_VARIANT

enum class IndexStatus : unsigned {
  UNINITIALIZED,
  INDEXING_IN_PROGRESS,
  INDEXED
};

inline static const char *EnumerationName(IndexStatus) {
  return "IndexStatus";
}

inline constexpr unsigned NumEnumerators(IndexStatus) {
  return 3u;
}

const char *EnumeratorName(IndexStatus);

// Access to the indexed code.
class Index {
 private:
  friend class Reference;
  friend class ReferenceKind;

#define MX_FRIEND(type_name, ln, e, c) \
    friend class type_name;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND)
#undef MX_FRIEND

  EntityProviderPtr impl;

 public:
  ~Index(void);
  Index(void);

  Index(const Index &) = default;
  Index(Index &&) noexcept = default;

  Index &operator=(const Index &) = default;
  Index &operator=(Index &&) noexcept = default;

  /* implicit */ inline Index(EntityProviderPtr impl_)
      : impl(std::move(impl_)) {}

  // Create an in-memory caching index provider.
  static Index in_memory_cache(Index next, unsigned timeout_s=1u);
  static Index from_database(std::filesystem::path path);

  static Index containing(const Fragment &entity);
  static Index containing(const File &entity);
  static Index containing(const Decl &entity);
  static Index containing(const Stmt &entity);
  static Index containing(const Type &entity);
  static Index containing(const Attr &entity);
  static Index containing(const Macro &entity);
  static Index containing(const Designator &entity);
  static std::optional<Index> containing(const Token &entity);
  static std::optional<Index> containing(const VariantEntity &entity);

  // Return the status of the index.
  IndexStatus status(bool block=false) const;

  // Clear any internal caches.
  void clear_caches(void) const;

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  FilePathMap file_paths(void) const;

  // Download a fragment based off of an entity ID.
  std::optional<Fragment> fragment_containing(EntityId) const;

#ifndef __CDT_PARSER__
#define MX_DECLARE_GETTER(type_name, lower_name, enum_name, category) \
  std::optional<type_name> lower_name(RawEntityId id) const; \
  \
  inline std::optional<type_name> lower_name( \
      Packed ## type_name ## Id id) const { \
    return lower_name(id.Pack()); \
  }

  MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_GETTER, MX_IGNORE_ENTITY_CATEGORY,
                              MX_DECLARE_GETTER, MX_DECLARE_GETTER,
                              MX_DECLARE_GETTER, MX_DECLARE_GETTER,
                              MX_DECLARE_GETTER)
#undef MX_DECLARE_GETTER

  template <typename T>
  inline std::optional<EntityType<T>> entity(T eid) const {
    VariantEntity vent = entity(eid.Pack());
    if (std::holds_alternative<EntityType<T>>(vent)) {
      return std::move(std::get<EntityType<T>>(vent));
    } else {
      return std::nullopt;
    }
  }

  template <typename T>
  inline std::optional<EntityType<T>> entity(SpecificEntityId<T> eid) const {
    VariantEntity vent = entity(eid.Pack());
    if (std::holds_alternative<EntityType<T>>(vent)) {
      return std::move(std::get<EntityType<T>>(vent));
    } else {
      return std::nullopt;
    }
  }
#endif  // __CDT_PARSER__

  // Return an entity given its ID.
  VariantEntity entity(EntityId eid) const;

  // Return an entity given its ID.
  template <typename T>
  inline auto
  entity(const std::optional<T> &id) const -> decltype(entity(T())) {
    if (id) {
      return entity(id.value());
    } else {
      return NotAnEntity{};
    }
  }

  // Generate all compilation units in the index.
  gap::generator<Compilation> compilations(void) const &;

  // Generate all files in the index.
  gap::generator<File> files(void) const &;

  // Search for entities by their name and category.
  //
  // NOTE(pag): This might return redeclarations.
  gap::generator<NamedEntity> query_entities(std::string name) const &;
};

#ifndef __CDT_PARSER__
template <typename T>
std::optional<T> Reference::as(void) const noexcept {
  constexpr EntityCategory c = T::static_category();
  auto category_ = category();
  if constexpr (EntityCategory::NOT_AN_ENTITY == c) {
    return std::nullopt;

#define MX_REFERENCE_AS(type_name, lower_name, enum_name, category) \
  } else if constexpr (EntityCategory::enum_name == c) { \
    if (category_ == c) { \
      return T::from(as_ ## lower_name()); \
    } else { \
      return std::nullopt; \
    }

MX_FOR_EACH_ENTITY_CATEGORY(MX_REFERENCE_AS,
                            MX_REFERENCE_AS,
                            MX_REFERENCE_AS,
                            MX_REFERENCE_AS,
                            MX_REFERENCE_AS,
                            MX_REFERENCE_AS,
                            MX_REFERENCE_AS)
#undef MX_REFERENCE_AS
  } else {
    return std::nullopt;  // Unreachable.
  }
}
#endif  // __CDT_PARSER__

class SimpleToken {
 public:
  // The kind of this token.
  TokenKind kind{TokenKind::UNKNOWN};

  // The category of this token. Often used for syntax highlighting.
  TokenCategory category{TokenCategory::UNKNOWN};

  std::string data;

  // The entity related to this token.
  VariantEntity related_entity;
};

}  // namespace mx
