// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "File.h"
#include "Fragment.h"

namespace mx {

Index::~Index(void) {}

Index::Index(void)
    : impl(std::make_shared<InvalidEntityProvider>()) {}

FilePathList Index::file_paths(void) const {
  return impl->ListFiles();
}

std::optional<File> Index::file(FileId id) const {
  if (auto ptr = impl->FileFor(impl, id)) {
    return File(std::move(ptr));
  } else {
    return std::nullopt;
  }
}

std::optional<Fragment> Index::fragment(FragmentId id) const {
  if (auto ptr = impl->FragmentFor(impl, id)) {
    return Fragment(std::move(ptr));
  } else {
    return std::nullopt;
  }
}

// Download a fragment based off of an entity ID.
std::optional<Fragment> Index::fragment_containing(EntityId id) const {
  mx::VariantId opt_id = id.Unpack();
  FragmentImpl::Ptr ptr;
  if (std::holds_alternative<mx::DeclarationId>(opt_id)) {
    ptr = impl->FragmentFor(
        impl, std::get<mx::DeclarationId>(opt_id).fragment_id);

  } else if (std::holds_alternative<mx::StatementId>(opt_id)) {
    ptr = impl->FragmentFor(
        impl, std::get<mx::StatementId>(opt_id).fragment_id);

  } else if (std::holds_alternative<mx::FragmentTokenId>(opt_id)) {
    ptr = impl->FragmentFor(
        impl, std::get<mx::FragmentTokenId>(opt_id).fragment_id);
  }

  if (ptr) {
    return Fragment(std::move(ptr));
  } else {
    return std::nullopt;
  }
}

WeggliQueryResult Index::weggli_query(std::string query, bool is_cpp) const {
  return WeggliQueryResult(impl->WeggliQuery(impl, std::move(query), is_cpp));
}

RegexQueryResult Index::regex_query(std::string pattern) const {
  return RegexQueryResult(impl->RegexQuery(impl, std::move(pattern)));
}

}  // namespace mx
