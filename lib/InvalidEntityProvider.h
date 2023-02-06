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

  // Return the list of fragments covering / overlapping some tokens in a file.
  FragmentIdList FragmentsCoveringTokens(
      const Ptr &, PackedFileId, std::vector<EntityOffset>) final;

  ReferenceKindImplPtr
  ReferenceKindFor(const Ptr &, RawEntityId kind_id) final;

  ReferenceKindImplPtr
  ReferenceKindFor(const Ptr &, std::string_view kind_data) final;

  gap::generator<RawEntityId> Redeclarations(const Ptr &, RawEntityId) final;

  bool AddReference(const Ptr &, RawEntityId, RawEntityId, RawEntityId) final;

  gap::generator<std::pair<RawEntityId, RawEntityId>>
  References(const Ptr &, RawEntityId eid) final;

  void FindSymbol(const Ptr &, std::string name,
                  std::vector<RawEntityId> &ids_out) final;

#define MX_DECLARE_ENTITY_METHODS(type_name, lower_name, enum_name, category) \
    gap::generator<type_name ## ImplPtr> type_name ## sFor( \
        const Ptr &, PackedFragmentId id) final; \
    \
    type_name ## ImplPtr type_name ## For( \
        const Ptr &ep, RawEntityId id) final;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_ENTITY_METHODS,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_DECLARE_ENTITY_METHODS,
                              MX_DECLARE_ENTITY_METHODS)
#undef MX_DECLARE_ENTITY_METHODS
};

}  // namespace mx
