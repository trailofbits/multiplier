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
  return impl->ListFiles(impl);
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

// Return an entity given its ID.
std::variant<Decl, Stmt, Type, Token, TokenSubstitution, NotAnEntity>
Index::entity(EntityId eid) const {

  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclarationId>(vid)) {
    DeclarationId id = std::get<DeclarationId>(vid);
    if (auto frag = fragment(id.fragment_id)) {
      return Decl(frag->impl, id.offset);
    }

  } else if (std::holds_alternative<StatementId>(vid)) {
    StatementId id = std::get<StatementId>(vid);
    if (auto frag = fragment(id.fragment_id)) {
      return Stmt(frag->impl, id.offset);
    }
  } else if (std::holds_alternative<TypeId>(vid)) {
    TypeId id = std::get<TypeId>(vid);
    if (auto frag = fragment(id.fragment_id)) {
      return Type(frag->impl, id.offset);
    }

  } else if (std::holds_alternative<FragmentTokenId>(vid)) {
    FragmentTokenId id = std::get<FragmentTokenId>(vid);
    if (auto frag = fragment(id.fragment_id)) {
      return frag->impl->TokenFor(frag->impl, eid);
    }

  } else if (std::holds_alternative<TokenSubstitutionId>(vid)) {
    TokenSubstitutionId id = std::get<TokenSubstitutionId>(vid);
    if (auto frag = fragment(id.fragment_id)) {
      return TokenSubstitution(frag->impl, id.offset, id.kind);
    }

  } else if (std::holds_alternative<FileTokenId>(vid)) {
    FileTokenId id = std::get<FileTokenId>(vid);
  }
  return NotAnEntity{};
}

WeggliQueryResult Index::query_fragments(const WeggliQuery &query) const {
  return WeggliQueryResult(impl->Query(impl, query));
}

RegexQueryResult Index::query_fragments(const RegexQuery &query) const {
  return RegexQueryResult(impl->Query(impl, query));
}

}  // namespace mx
