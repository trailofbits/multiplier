// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "InvalidEntityProvider.h"

#include <multiplier/NodeKind.h>
#include "Grammar.h"
#include <multiplier/IndexStorage.h>

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

FilePathList InvalidEntityProvider::ListFiles(const Ptr &) {
  return {};
}

std::vector<RawEntityId> InvalidEntityProvider::ListFragmentsInFile(
    const Ptr &, RawEntityId) {
  return {};
}

FileImpl::Ptr InvalidEntityProvider::FileFor(const Ptr &, RawEntityId) {
  return {};
}

FragmentImpl::Ptr InvalidEntityProvider::FragmentFor(const Ptr &, RawEntityId) {
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
    std::vector<RawEntityId> &fragment_ids_out) {
  redecl_ids_out.clear();
  fragment_ids_out.clear();
}

void InvalidEntityProvider::FillReferences(
    const Ptr &, RawEntityId eid,
    std::vector<RawEntityId> &redecl_ids_out,
    std::vector<RawEntityId> &fragment_ids_out) {
  redecl_ids_out.clear();
  fragment_ids_out.clear();
}

void InvalidEntityProvider::FindSymbol(
    const Ptr &, std::string name,
    mx::DeclCategory category, std::vector<RawEntityId> &ids_out) {
  ids_out.clear();
}

std::optional<mx::TokenKind>
InvalidEntityProvider::TokenKindOf(std::string_view spelling) {
  return {};
}

void InvalidEntityProvider::LoadGrammarRoot(SyntexGrammarLeaves &) {}

std::vector<RawEntityId> InvalidEntityProvider::GetFragmentsInAST(void) {
  return {};
}

ASTNode InvalidEntityProvider::GetASTNode(std::uint64_t id) {
  return {};
}

std::vector<std::uint64_t> InvalidEntityProvider::GetASTNodeChildren(std::uint64_t id) {
  return {};
}

std::vector<std::uint64_t> InvalidEntityProvider::GetASTNodesInFragment(RawEntityId frag) {
  return {};
}

std::optional<std::uint64_t> InvalidEntityProvider::GetASTNodeWithKind(RawEntityId frag, unsigned short kind) {
  return {};
}

Index::Index(void)
    : impl(std::make_shared<InvalidEntityProvider>()) {}

}  // namespace mx
