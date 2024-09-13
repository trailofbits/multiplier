// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "InvalidEntityProvider.h"

namespace mx {

InvalidEntityProvider::~InvalidEntityProvider(void) noexcept {}

void InvalidEntityProvider::ClearCache(void) {}

unsigned InvalidEntityProvider::VersionNumber(void) {
  return 0u;
}

unsigned InvalidEntityProvider::VersionNumber(const Ptr &) {
  return 0u;
}

void InvalidEntityProvider::VersionNumberChanged(unsigned) {}

FilePathMap InvalidEntityProvider::ListFiles(const Ptr &) {
  return {};
}

// Get the list of paths associated with a given file id.
gap::generator<std::filesystem::path> InvalidEntityProvider::ListPathsForFile(
    const Ptr &, PackedFileId) {
  co_return;
}

// Get the list nested fragments for a given fragment.
FragmentIdList InvalidEntityProvider::ListNestedFragmentIds(
    const Ptr &, PackedFragmentId) {
  return {};
}

FragmentIdList InvalidEntityProvider::ListFragmentsInFile(
    const Ptr &, SpecificEntityId<FileId>) {
  return {};
}

// Return the list of fragments covering / overlapping some tokens in a file.
FragmentIdList InvalidEntityProvider::FragmentsCoveringTokens(
    const Ptr &, PackedFileId, std::vector<EntityOffset>) {
  return {};
}

ReferenceKindImplPtr
InvalidEntityProvider::ReferenceKindFor(const Ptr &, RawEntityId) {
  return {};
}

ReferenceKindImplPtr
InvalidEntityProvider::ReferenceKindFor(const Ptr &, std::string_view) {
  return {};
}

bool InvalidEntityProvider::AddReference(const Ptr &, RawEntityId,
                                         RawEntityId, RawEntityId,
                                         RawEntityId) {
  return false;
}

gap::generator<RawEntityId> InvalidEntityProvider::Redeclarations(
    const Ptr &, RawEntityId) & {
  co_return;
}

gap::generator<std::tuple<RawEntityId, RawEntityId, RawEntityId>>
InvalidEntityProvider::References(const Ptr &, RawEntityId,
                                  EntityProvider::ReferenceDirection, bool) & {
  co_return;
}

gap::generator<std::pair<RawEntityId, RawEntityId>>
InvalidEntityProvider::SpecificReferences(
    const Ptr &, RawEntityId, RawEntityId,
    EntityProvider::ReferenceDirection, bool) & {
  co_return;
}

gap::generator<RawEntityId> InvalidEntityProvider::FindSymbol(
    const Ptr &, std::string) & {
  co_return;
}

#define MX_DECLARE_ENTITY_GETTER(ns_path, type_name, lower_name, enum_name, category) \
    type_name ## ImplPtr InvalidEntityProvider::type_name ## For( \
        const Ptr &, RawEntityId) { return {}; } \
    \
    gap::generator<type_name ## ImplPtr> InvalidEntityProvider::type_name ## sFor( \
        const Ptr &) & { co_return; }

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
  gap::generator<type_name ## ImplPtr> InvalidEntityProvider::type_name ## sFor( \
      const Ptr &, type_name ## Kind) & { co_return; }

MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DECLARE_ENTITY_LISTERS,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DECLARE_ENTITY_LISTERS,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY)
#undef MX_DECLARE_ENTITY_LISTERS

Index::Index(void)
    : impl(std::make_shared<InvalidEntityProvider>()) {}

}  // namespace mx
