// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "API.h"

#include "File.h"
#include "Fragment.h"
#include "Re2.h"
#include "Token.h"
#include "Use.h"
#include "Weggli.h"
#include <multiplier/SQLiteStore.h>
#include <filesystem>
#include <memory>
#include <shared_mutex>
#include <vector>

namespace mx {

class SQLiteEntityProvider final : public EntityProvider {
 private:
  class Context;

  std::filesystem::path db_path;
  std::shared_mutex contexts_lock;
  std::vector<std::unique_ptr<Context>> contexts;

  Context &ThreadLocalContext(void);

 public:
  virtual ~SQLiteEntityProvider(void) noexcept;
  SQLiteEntityProvider(std::filesystem::path path);

  void ClearCache(void) final;

  unsigned VersionNumber(void) final;
  unsigned VersionNumber(const Ptr &) final;

  void VersionNumberChanged(unsigned) final;

  FilePathList ListFiles(const Ptr &) final;

  std::vector<EntityId> ListFragmentsInFile(const Ptr &, RawEntityId id);

  std::shared_ptr<const FileImpl> FileFor(const Ptr &, RawEntityId id) final;

  // Download a fragment by its unique ID.
  std::shared_ptr<const FragmentImpl>
  FragmentFor(const Ptr &, RawEntityId id) final;

  std::shared_ptr<WeggliQueryResultImpl>
  Query(const Ptr &, const WeggliQuery &) final;

  std::shared_ptr<RegexQueryResultImpl> Query(
      const Ptr &, const RegexQuery &) final;

  std::vector<RawEntityId> Redeclarations(const Ptr &, RawEntityId) final;

  void FillUses(const Ptr &, RawEntityId eid,
                std::vector<RawEntityId> &redecl_ids_out,
                std::vector<RawEntityId> &fragment_ids_out) final;

  void FillReferences(const Ptr &, RawEntityId eid,
                      std::vector<RawEntityId> &redecl_ids_out,
                      std::vector<RawEntityId> &fragment_ids_out) final;

  void FindSymbol(const Ptr &, std::string name,
                  mx::DeclCategory category,
                  std::vector<RawEntityId> &ids_out) final;
};

}  // namespace mx
