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

#include "AST/Attr.h"
#include "AST/CXXBaseSpecifier.h"
#include "AST/CXXCtorInitializer.h"
#include "AST/Designator.h"
#include "AST/NamedDecl.h"
#include "AST/Stmt.h"
#include "AST/TemplateArgument.h"
#include "AST/TemplateParameterList.h"
#include "AST/Type.h"
#include "Frontend/Compilation.h"
#include "Frontend/File.h"
#include "Frontend/DefineMacroDirective.h"
#include "Frontend/Macro.h"
#include "Frontend/TokenKind.h"
#include "Frontend/TokenCategory.h"
#include "IR/Operation.h"
#include "Fragment.h"
#include "IR/Operation.h"
#include "Iterator.h"
#include "Reference.h"

namespace mx {
namespace ir {
class Operation;
}  // namespace ir

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

#define MX_DECLARE_ENTITY_VARIANT(ns_path, type_name, ...) \
    , ns_path type_name

using VariantEntity = std::variant<
    NotAnEntity MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_ENTITY_VARIANT,
                                            MX_DECLARE_ENTITY_VARIANT,
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

MX_EXPORT const char *EnumeratorName(IndexStatus);

// Access to the indexed code.
class MX_EXPORT Index final {
 private:
  friend class Reference;
  friend class ReferenceKind;

#define MX_FRIEND(ns_path, type_name, ...) \
    friend class ns_path type_name;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_FRIEND,
                              MX_FRIEND,
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

  // Create an in-memory caching index provider using the default timeout (1s).
  static Index in_memory_cache(Index next);

  // Create an in-memory caching index provider using a custom timeout in
  // seconds.
  static Index in_memory_cache(Index next, unsigned timeout_s);
  
  // Create an index that opens a database produced by Multiplier's indexer
  // by specifying the path to that database.
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

  static Index containing(const ir::Operation &entity);

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
#define MX_DECLARE_GETTER(ns_path, type_name, lower_name, enum_name, category) \
  std::optional<ns_path type_name> lower_name(RawEntityId id) const; \
  \
  inline std::optional<ns_path type_name> lower_name( \
      Packed ## type_name ## Id id) const { \
    return lower_name(id.Pack()); \
  }

  MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_GETTER, MX_IGNORE_ENTITY_CATEGORY,
                              MX_DECLARE_GETTER, MX_DECLARE_GETTER,
                              MX_DECLARE_GETTER, MX_DECLARE_GETTER,
                              MX_DECLARE_GETTER, MX_DECLARE_GETTER)
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

#define MX_REFERENCE_AS(ns_path, type_name, lower_name, enum_name, category) \
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
                            MX_REFERENCE_AS,
                            MX_REFERENCE_AS)
#undef MX_REFERENCE_AS
  } else {
    return std::nullopt;  // Unreachable.
  }
}
#endif  // __CDT_PARSER__

// User-definable token. See `TokenRange::create`.
class MX_EXPORT UserToken final {
 public:

  // The kind of this token.
  TokenKind kind{TokenKind::UNKNOWN};

  // The category of this token. Often used for syntax highlighting.
  TokenCategory category{TokenCategory::UNKNOWN};

  std::string data;

  // The entity related to this token.
  VariantEntity related_entity;

  ~UserToken(void) = default;
  UserToken(void) = default;
  UserToken(const UserToken &) noexcept = default;
  UserToken &operator=(const UserToken &) noexcept = default;

  inline UserToken(TokenKind kind_, TokenCategory category_, std::string data_,
                   VariantEntity related_entity_)
      : kind(kind_),
        category(category_),
        data(std::move(data_)),
        related_entity(std::move(related_entity_)) {}

  inline UserToken(UserToken &&that) noexcept
      : kind(that.kind),
        category(that.category),
        data(std::move(that.data)),
        related_entity(std::move(that.related_entity)) {
    that.related_entity = NotAnEntity{};  // Make sure to reset it.
  }

  inline UserToken &operator=(UserToken &&that_) noexcept {
    UserToken that(std::move(that_));
    kind = that.kind;
    category = that.category;
    data.swap(that.data);
    related_entity.swap(that.related_entity);
    return *this;
  }
};

// User configuration for rendering qualified names.
class MX_EXPORT QualifiedNameRenderOptions final {
 public:

  // Should the name be fully qualified, i.e. with all parent classes/namespaces?
  bool fully_qualified{true};

  // If the class is unnamed, then should we render out `(anonumous class)`?
  bool render_anonymous_classes{true};

  // If the struct is unnamed, then should we render out `(anonumous struct)`?
  bool render_anonymous_structs{true};

  // If the field is unnamed, then should we render out `(anonumous field)`?
  bool render_anonymous_fields{true};

  // If the union is unnamed, then should we render out `(anonymous union)`?
  bool render_anonymous_unions{true};
  
  // If the enum is unnamed, then should we render out `(anonymous enum)`?
  bool render_anonymous_enums{true};
  
  // If the namespace is anonymous, then should we render out
  // `(anonymous namespace)`?
  bool render_anonymous_namespaces{true};

  // If the parameter is unnamed, then should we render out
  // `(anonumous parameter)`?
  bool render_anonymous_parameters{true};

  // If the namespace is marked as inline, then should we render out the name
  // of the inline namespace, or skip it?
  bool render_inline_namespaces{true};

  // When rendering names of template declarations, should we render the
  // template paramters?
  bool render_template_parameters{true};

  // WHen rendering names of template specializations, should we render the
  // template arguments?
  bool render_template_arguments{true};

  // Some declarations might not have a name, e.g. a parameter might be unnamed
  // in a given place, but have a name elsewhere. This option tells us to try
  // to go and look for an alternative name in a redeclaration.
  bool find_name_in_redeclaration{true};
};

}  // namespace mx
