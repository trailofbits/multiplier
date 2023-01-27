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

FileImpl::Ptr InvalidEntityProvider::FileFor(
    const Ptr &, SpecificEntityId<FileId>) {
  return {};
}

FragmentImpl::Ptr InvalidEntityProvider::FragmentFor(
    const Ptr &, SpecificEntityId<FragmentId>) {
  return {};
}

// Return the list of fragments covering / overlapping some tokens in a file.
FragmentIdList InvalidEntityProvider::FragmentsCoveringTokens(
    const Ptr &, PackedFileId, std::vector<EntityOffset>) {
  return {};
}

RawEntityIdList InvalidEntityProvider::Redeclarations(
    const Ptr &, SpecificEntityId<DeclarationId>) {
  return {};
}

void InvalidEntityProvider::FillUses(
    const Ptr &, RawEntityId,
    RawEntityIdList &redecl_ids_out,
    FragmentIdList &fragment_ids_out) {
  redecl_ids_out.clear();
  fragment_ids_out.clear();
}

void InvalidEntityProvider::FillReferences(
    const Ptr &, RawEntityId,
    RawEntityIdList &redecl_ids_out,
    FragmentIdList &fragment_ids_out) {
  redecl_ids_out.clear();
  fragment_ids_out.clear();
}

void InvalidEntityProvider::FindSymbol(
    const Ptr &, std::string, std::vector<RawEntityId> &ids_out) {
  ids_out.clear();
}

gap::generator<ReaderPtr> InvalidEntityProvider::DeclsFor(
  const Ptr &, PackedFragmentId) { co_return; }
gap::generator<ReaderPtr> InvalidEntityProvider::TypesFor(
  const Ptr &, PackedFragmentId) { co_return; }
gap::generator<ReaderPtr> InvalidEntityProvider::StmtsFor(
  const Ptr &, PackedFragmentId) { co_return; }
gap::generator<ReaderPtr> InvalidEntityProvider::AttrsFor(
  const Ptr &, PackedFragmentId) { co_return; }
gap::generator<ReaderPtr> InvalidEntityProvider::MacrosFor(
  const Ptr &, PackedFragmentId) { co_return; }
gap::generator<ReaderPtr> InvalidEntityProvider::PseudosFor(
  const Ptr &, PackedFragmentId) { co_return; }
std::optional<ReaderPtr> InvalidEntityProvider::DeclFor(
  const Ptr &, PackedFragmentId, unsigned) { return std::nullopt; }
std::optional<ReaderPtr> InvalidEntityProvider::TypeFor(
  const Ptr &, PackedFragmentId, unsigned) { return std::nullopt; }
std::optional<ReaderPtr> InvalidEntityProvider::StmtFor(
  const Ptr &, PackedFragmentId, unsigned) { return std::nullopt; }
std::optional<ReaderPtr> InvalidEntityProvider::AttrFor(
  const Ptr &, PackedFragmentId, unsigned) { return std::nullopt; }
std::optional<ReaderPtr> InvalidEntityProvider::MacroFor(
  const Ptr &, PackedFragmentId, unsigned) { return std::nullopt; }
std::optional<ReaderPtr> InvalidEntityProvider::PseudoFor(
  const Ptr &, PackedFragmentId, unsigned) { return std::nullopt; }

Index::Index(void)
    : impl(std::make_shared<InvalidEntityProvider>()) {}

}  // namespace mx
