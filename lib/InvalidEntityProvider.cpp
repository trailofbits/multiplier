// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
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
                                         RawEntityId, RawEntityId) {
  return false;
}

gap::generator<RawEntityId> InvalidEntityProvider::Redeclarations(
    const Ptr &, RawEntityId) {
  co_return;
}

gap::generator<std::pair<RawEntityId, RawEntityId>>
InvalidEntityProvider::References(const Ptr &, RawEntityId) {
  co_return;
}

void InvalidEntityProvider::FindSymbol(
    const Ptr &, std::string, std::vector<RawEntityId> &ids_out) {
  ids_out.clear();
}

#define DEFINE_ENTITY_METHODS(type_name, lower_name, enum_name, category) \
    gap::generator<type_name ## ImplPtr> \
    InvalidEntityProvider::type_name ## sFor(const Ptr &, PackedFragmentId) { \
      co_return; \
    } \
    \
    type_name ## ImplPtr InvalidEntityProvider::type_name ## For( \
        const Ptr &, RawEntityId) { \
      return {}; \
    }

  MX_FOR_EACH_ENTITY_CATEGORY(DEFINE_ENTITY_METHODS,
                              MX_IGNORE_ENTITY_CATEGORY,
                              DEFINE_ENTITY_METHODS,
                              DEFINE_ENTITY_METHODS)
#undef DEFINE_ENTITY_METHODS

Index::Index(void)
    : impl(std::make_shared<InvalidEntityProvider>()) {}

}  // namespace mx
