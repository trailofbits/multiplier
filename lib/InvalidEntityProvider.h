// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "API.h"

#include "File.h"
#include "Fragment.h"
#include "Token.h"
#include "Use.h"

namespace mx {

class InvalidEntityProvider final : public EntityProvider {
 public:
  virtual ~InvalidEntityProvider(void) noexcept;

  void ClearCache(void) final;

  unsigned VersionNumber(void) final;
  unsigned VersionNumber(const Ptr &) final;

  void VersionNumberChanged(unsigned) final;

  FilePathMap ListFiles(const Ptr &) final;

  FragmentIdList ListFragmentsInFile(
      const Ptr &, SpecificEntityId<FileId> id);

  std::shared_ptr<const FileImpl> FileFor(
      const Ptr &, SpecificEntityId<FileId> id) final;

  // Download a fragment by its unique ID.
  std::shared_ptr<const FragmentImpl>
  FragmentFor(const Ptr &, SpecificEntityId<FragmentId> id) final;

  // Return the list of fragments covering / overlapping some tokens in a file.
  FragmentIdList FragmentsCoveringTokens(
      const Ptr &, PackedFileId, std::vector<EntityOffset>) final;

  RawEntityIdList Redeclarations(
      const Ptr &, SpecificEntityId<DeclarationId>) final;

  void FillUses(const Ptr &, RawEntityId eid,
                RawEntityIdList &redecl_ids_out,
                FragmentIdList &fragment_ids_out) final;

  void FillReferences(const Ptr &, RawEntityId eid,
                      RawEntityIdList &redecl_ids_out,
                      RawEntityIdList &references_ids_out) final;

  void FindSymbol(const Ptr &, std::string name,
                  std::vector<RawEntityId> &ids_out) final;

#define DECLARE_ENTITY_METHODS(name, lower_name) \
    gap::generator<EntityImplPtr> \
    name ## sFor(const Ptr &, PackedFragmentId) final; \
    std::optional<EntityImplPtr> \
    name ## For(const Ptr &, PackedFragmentId, EntityOffset) final; \
    std::optional<EntityImplPtr> \
    name ## For(const Ptr &, RawEntityId) final;

  MX_FOR_EACH_ENTITY_RECORD(DECLARE_ENTITY_METHODS)
#undef DECLARE_ENTITY_METHODS
};

}  // namespace mx
