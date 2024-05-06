// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <array>
#include <filesystem>
#include <memory>
#include <vector>

#include "EntityProvider.h"
#include "ThreadLocal.h"
#include "Types.h"

namespace sqlite {
class Statement;
}  // namespace sqlite
namespace mx {

enum class DeclCategory : unsigned char;

class File;
class FileImpl;
class FragmentImpl;
class RegexQuery;
class RegexQueryResultImpl;
class SQLiteEntityProviderImpl;
class SQLiteDecompressionDictionary;

class SQLiteEntityProvider final : public EntityProvider {
 public:
  friend class SQLiteEntityProviderImpl;

  using ImplPtr = std::shared_ptr<SQLiteEntityProviderImpl>;

  const std::filesystem::path db_path;

  std::unique_ptr<SQLiteDecompressionDictionary> dict;
  ThreadLocal<SQLiteEntityProviderImpl> impl;

  RawEntityIdList ReadRedeclarations(SQLiteEntityProviderImpl &context,
                                     EntityCategory category);

  virtual ~SQLiteEntityProvider(void) noexcept;
  SQLiteEntityProvider(std::filesystem::path path);

  void ClearCache(void) final;

  unsigned VersionNumber(void) final;
  unsigned VersionNumber(const Ptr &) final;

  void VersionNumberChanged(unsigned) final;

  FilePathMap ListFiles(const Ptr &) final;

  // Get the list of paths associated with a given file id.
  gap::generator<std::filesystem::path> ListPathsForFile(
      const Ptr &, PackedFileId) final;

  // Get the list nested fragments for a given fragment.
  FragmentIdList ListNestedFragmentIds(const Ptr &, PackedFragmentId) final;

  FragmentIdList ListFragmentsInFile(const Ptr &, PackedFileId id);

  // Return the list of fragments covering / overlapping some tokens in a file.
  FragmentIdList FragmentsCoveringTokens(
      const Ptr &, PackedFileId, std::vector<EntityOffset> tokens) final;

  ReferenceKindImplPtr
  ReferenceKindFor(const Ptr &, RawEntityId kind_id) final;

  ReferenceKindImplPtr
  ReferenceKindFor(const Ptr &, std::string_view kind_data) final;

  bool AddReference(const Ptr &ep, RawEntityId kind_id,
                    RawEntityId from_id, RawEntityId to_id,
                    RawEntityId context_id) final;

  gap::generator<RawEntityId> Redeclarations(const Ptr &, RawEntityId) & final;

  gap::generator<std::tuple<RawEntityId, RawEntityId, RawEntityId>>
  References(const Ptr &, RawEntityId eid, ReferenceDirection) & final;

  gap::generator<std::pair<RawEntityId, RawEntityId>>
  SpecificReferences(const Ptr &, RawEntityId eid, RawEntityId kind_id,
                     ReferenceDirection direction) & final;

  gap::generator<RawEntityId> FindSymbol(const Ptr &, std::string name) & final;

#define MX_DECLARE_ENTITY_GETTER(ns_path, type_name, lower_name, enum_name, category) \
    friend class type_name ## Impl; \
    \
    type_name ## ImplPtr type_name ## For( \
        const Ptr &ep, RawEntityId id) final; \
    \
    gap::generator<type_name ## ImplPtr> type_name ## sFor( \
        const Ptr &ep) & final;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_ENTITY_GETTER,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_DECLARE_ENTITY_GETTER,
                              MX_DECLARE_ENTITY_GETTER,
                              MX_DECLARE_ENTITY_GETTER,
                              MX_DECLARE_ENTITY_GETTER,
                              MX_DECLARE_ENTITY_GETTER,
                              MX_IGNORE_ENTITY_CATEGORY)
#undef MX_DECLARE_ENTITY_GETTER

#define MX_DECLARE_ENTITY_LISTERS(ns_path, type_name, lower_name, enum_name, category) \
    gap::generator<type_name ## ImplPtr> type_name ## sFor( \
        const Ptr &, type_name ## Kind) & final;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_DECLARE_ENTITY_LISTERS,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_DECLARE_ENTITY_LISTERS,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY)
#undef MX_DECLARE_ENTITY_LISTERS
};

}  // namespace mx
