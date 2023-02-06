// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <array>
#include <filesystem>
#include <memory>
#include <multiplier/Index.h>
#include <vector>

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
class WeggliQueryResultImpl;

class SQLiteEntityProviderImpl;
class SQLiteDecompressionDictionary;

class SQLiteEntityProvider final : public EntityProvider {
 private:
  friend class SQLiteEntityProviderImpl;

  using ImplPtr = std::shared_ptr<SQLiteEntityProviderImpl>;

  const std::filesystem::path db_path;

  std::unique_ptr<SQLiteDecompressionDictionary> dict;
  ThreadLocal<SQLiteEntityProviderImpl> impl;

  RawEntityIdList ReadRedeclarations(SQLiteEntityProviderImpl &context,
                                     EntityCategory category);

 public:
  virtual ~SQLiteEntityProvider(void) noexcept;
  SQLiteEntityProvider(std::filesystem::path path);

  void ClearCache(void) final;

  unsigned VersionNumber(void) final;
  unsigned VersionNumber(const Ptr &) final;

  void VersionNumberChanged(unsigned) final;

  FilePathMap ListFiles(const Ptr &) final;

  FragmentIdList ListFragmentsInFile(const Ptr &, PackedFileId id);

  // Return the list of fragments covering / overlapping some tokens in a file.
  FragmentIdList FragmentsCoveringTokens(
      const Ptr &, PackedFileId, std::vector<EntityOffset> tokens) final;

  ReferenceKindImplPtr
  ReferenceKindFor(const Ptr &, RawEntityId kind_id) final;

  ReferenceKindImplPtr
  ReferenceKindFor(const Ptr &, std::string_view kind_data) final;

  bool AddReference(const Ptr &ep, RawEntityId kind_id,
                              RawEntityId from_id, RawEntityId to_id) final;

  gap::generator<RawEntityId> Redeclarations(const Ptr &, RawEntityId) final;

  gap::generator<std::pair<RawEntityId, RawEntityId>>
  References(const Ptr &, RawEntityId eid) final;

  void FindSymbol(const Ptr &, std::string name,
                  std::vector<RawEntityId> &ids_out) final;

#define DECLARE_ENTITY_METHODS(type_name, lower_name, enum_name, category) \
    gap::generator<type_name ## ImplPtr> \
    type_name ## sFor(const Ptr &, PackedFragmentId id) final; \
    \
    type_name ## ImplPtr type_name ## For(const Ptr &ep, RawEntityId id) final;

  MX_FOR_EACH_ENTITY_CATEGORY(DECLARE_ENTITY_METHODS,
                              MX_IGNORE_ENTITY_CATEGORY,
                              DECLARE_ENTITY_METHODS,
                              DECLARE_ENTITY_METHODS)
#undef DECLARE_ENTITY_METHODS
};

}  // namespace mx
