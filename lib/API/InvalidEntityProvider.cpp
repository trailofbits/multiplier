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

void InvalidEntityProvider::VersionNumberChanged(unsigned) {}

FilePathList InvalidEntityProvider::ListFiles(const Ptr &) {
  return {};
}

std::vector<FragmentId> InvalidEntityProvider::ListFragmentsInFile(
    const Ptr &, FileId) {
  return {};
}

FileImpl::Ptr InvalidEntityProvider::FileFor(const Ptr &, FileId) {
  return {};
}

FragmentImpl::Ptr InvalidEntityProvider::FragmentFor(const Ptr &, FragmentId) {
  return {};
}

WeggliQueryResultImpl::Ptr InvalidEntityProvider::Query(
    const Ptr &, const WeggliQuery &) {
  return {};
}

RegexQueryResultImpl::Ptr InvalidEntityProvider::Query(
    const Ptr &, const RegexQuery &) {
  return {};
}

std::vector<RawEntityId> InvalidEntityProvider::Redeclarations(
    const Ptr &, RawEntityId) {
  return {};
}

void InvalidEntityProvider::FillUses(
    const Ptr &, RawEntityId eid,
    std::vector<RawEntityId> &redecl_ids_out,
    std::vector<FragmentId> &fragment_ids_out) {
  redecl_ids_out.clear();
  fragment_ids_out.clear();
}

void InvalidEntityProvider::FillReferences(
    const Ptr &, RawEntityId eid,
    std::vector<RawEntityId> &redecl_ids_out,
    std::vector<FragmentId> &fragment_ids_out) {
  redecl_ids_out.clear();
  fragment_ids_out.clear();
}

void InvalidEntityProvider::FindSymbol(
    const Ptr &, std::string name,
    mx::DeclCategory category, std::vector<RawEntityId> &ids_out) {
  ids_out.clear();
}

Index::Index(void)
    : impl(std::make_shared<InvalidEntityProvider>()) {}

}  // namespace mx
