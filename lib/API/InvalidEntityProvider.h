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

  // Return the list of fragments covering / overlapping some lines in a file.
  FragmentIdList FragmentsCoveringLines(
      const Ptr &, PackedFileId file, std::vector<unsigned> lines) final;

  RawEntityIdList Redeclarations(
      const Ptr &, SpecificEntityId<DeclarationId>) final;

  void FillUses(const Ptr &, RawEntityId eid,
                RawEntityIdList &redecl_ids_out,
                FragmentIdList &fragment_ids_out) final;

  void FillReferences(const Ptr &, RawEntityId eid,
                      RawEntityIdList &redecl_ids_out,
                      FragmentIdList &fragment_ids_out) final;

  void FindSymbol(const Ptr &, std::string name,
                  std::vector<RawEntityId> &ids_out) final;
};

}  // namespace mx
