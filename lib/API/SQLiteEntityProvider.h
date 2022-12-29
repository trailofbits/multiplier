// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <filesystem>
#include <memory>
#include <multiplier/Index.h>
#include <vector>

#include "../Common/ThreadLocal.h"

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

class SQLiteEntityProvider final : public EntityProvider {
 private:
  class Context;

  const std::filesystem::path db_path;
  ThreadLocal<Context> thread_context;

  DeclarationIdList ReadRedeclarations(Context &context);

  void FillFragments(Context &context, sqlite::Statement &get_fragments,
                     RawEntityId eid, DeclarationIdList &redecl_ids_out,
                     FragmentIdList &fragment_ids_out);

 public:
  virtual ~SQLiteEntityProvider(void) noexcept;
  SQLiteEntityProvider(std::filesystem::path path);

  void ClearCache(void) final;

  unsigned VersionNumber(void) final;
  unsigned VersionNumber(const Ptr &) final;

  void VersionNumberChanged(unsigned) final;

  FilePathMap ListFiles(const Ptr &) final;

  FragmentIdList ListFragmentsInFile(const Ptr &, SpecificEntityId<FileId> id);

  std::shared_ptr<const FileImpl> FileFor(
      const Ptr &, SpecificEntityId<FileId> id) final;

  // Download a fragment by its unique ID.
  std::shared_ptr<const FragmentImpl>
  FragmentFor(const Ptr &, SpecificEntityId<FragmentId> id) final;

  std::shared_ptr<WeggliQueryResultImpl>
  Query(const Ptr &, const WeggliQuery &) final;

  std::shared_ptr<RegexQueryResultImpl> Query(
      const Ptr &, const RegexQuery &) final;

  DeclarationIdList Redeclarations(
      const Ptr &, SpecificEntityId<DeclarationId>) final;

  void FillUses(const Ptr &, RawEntityId eid,
                DeclarationIdList &redecl_ids_out,
                FragmentIdList &fragment_ids_out) final;

  void FillReferences(const Ptr &, RawEntityId eid,
                      DeclarationIdList &redecl_ids_out,
                      FragmentIdList &fragment_ids_out) final;

  void FindSymbol(const Ptr &, std::string name,
                  std::vector<RawEntityId> &ids_out) final;
};

}  // namespace mx
