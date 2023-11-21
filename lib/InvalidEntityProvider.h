// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "EntityProvider.h"

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

  // Get the list of paths associated with a given file id.
  gap::generator<std::filesystem::path> ListPathsForFile(
      const Ptr &, PackedFileId) final;

  // Get the list nested fragments for a given fragment.
  FragmentIdList ListNestedFragmentIds(const Ptr &, PackedFragmentId) final;

  FragmentIdList ListFragmentsInFile(const Ptr &, PackedFileId);

  // Return the list of fragments covering / overlapping some tokens in a file.
  FragmentIdList FragmentsCoveringTokens(
      const Ptr &, PackedFileId, std::vector<EntityOffset>) final;

  ReferenceKindImplPtr
  ReferenceKindFor(const Ptr &, RawEntityId kind_id) final;

  ReferenceKindImplPtr
  ReferenceKindFor(const Ptr &, std::string_view kind_data) final;

  gap::generator<RawEntityId> Redeclarations(const Ptr &, RawEntityId) & final;

  bool AddReference(const Ptr &, RawEntityId, RawEntityId, RawEntityId,
                    RawEntityId) final;

  gap::generator<std::tuple<RawEntityId, RawEntityId, RawEntityId>>
  References(const Ptr &, RawEntityId eid, ReferenceDirection) & final;

  gap::generator<RawEntityId> FindSymbol(const Ptr &, std::string name) & final;

#define MX_DECLARE_ENTITY_GETTER(type_name, lower_name, enum_name, category) \
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
                              MX_DECLARE_ENTITY_GETTER)
#undef MX_DECLARE_ENTITY_GETTER

#define MX_DECLARE_ENTITY_LISTERS(type_name, lower_name, enum_name, category) \
    gap::generator<type_name ## ImplPtr> type_name ## sFor( \
        const Ptr &, type_name ## Kind) & final;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_DECLARE_ENTITY_LISTERS,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_DECLARE_ENTITY_LISTERS,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY)
#undef MX_DECLARE_ENTITY_LISTERS
};

}  // namespace mx
