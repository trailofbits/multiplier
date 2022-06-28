// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Fragment.h"

#include <cassert>

#include "File.h"
#include "Re2.h"
#include "Weggli.h"

namespace mx {

// Advance to the next valid fragment.
void FileFragmentListIterator::Advance(void) {
  for (; index < num_fragments; ++index) {
    frag = impl->ep->FragmentFor(impl->ep, impl->fragment_ids[index]);
    if (frag) {
      return;
    }
  }
}

// Return the list of fragments in a file.
FragmentList Fragment::in(const File &file) {
  auto &ep = file.impl->ep;
  auto list = std::make_shared<FragmentListImpl>(
      ep, ep->ListFragmentsInFile(ep, file.impl->file_id));
  auto num_fragments = list->fragment_ids.size();
  return FragmentList(std::move(list), static_cast<unsigned>(num_fragments));
}

// Return the fragment containing a query match.
Fragment Fragment::containing(const WeggliQueryMatch &match) {
  return Fragment(match.frag);
}

// Return the fragment containing a query match.
Fragment Fragment::containing(const RegexQueryMatch &match) {
  return Fragment(match.frag);
}

Fragment Fragment::containing(const Decl &entity) {
  return Fragment(entity.fragment);
}

Fragment Fragment::containing(const Stmt &entity) {
  return Fragment(entity.fragment);
}

Fragment Fragment::containing(const Type &entity) {
  return Fragment(entity.fragment);
}

std::optional<Fragment> Fragment::containing(const Token &entity) {
  if (auto frag = dynamic_cast<const PackedFragmentImpl *>(entity.impl.get())) {
    std::shared_ptr<const FragmentImpl> ptr(entity.impl, frag);
    return Fragment(std::move(ptr));
  } else {
    return std::nullopt;
  }
}

Fragment Fragment::containing(const TokenSubstitution &entity) {
  return Fragment(entity.impl);
}

Fragment Fragment::containing(const UseBase &use) {
  return Fragment(use.fragment);
}

Fragment Fragment::containing(const Reference &ref) {
  return Fragment(ref.fragment);
}

// Return the ID of this fragment.
RawEntityId Fragment::id(void) const noexcept {
  return EntityId(FragmentId{impl->fragment_id});
}

// The range of file tokens in this fragment.
TokenRange Fragment::file_tokens(void) const {
  auto fr = impl->Fragment();
  VariantId first_vid = EntityId(fr.getFirstFileTokenId()).Unpack();
  VariantId last_vid = EntityId(fr.getLastFileTokenId()).Unpack();
  if (!std::holds_alternative<FileTokenId>(first_vid) ||
      !std::holds_alternative<FileTokenId>(last_vid)) {
    return TokenRange();
  }

  FileTokenId first_fid = std::get<FileTokenId>(first_vid);
  FileTokenId last_fid = std::get<FileTokenId>(last_vid);
  if (first_fid.file_id != last_fid.file_id ||
      first_fid.offset > last_fid.offset) {
    return TokenRange();
  }

  auto file = impl->ep->FileFor(impl->ep, first_fid.file_id);
  auto raw_file = file.get();
  return TokenRange(
      raw_file->TokenReader(std::move(file)),
      first_fid.offset, last_fid.offset + 1u);
}

// The range of parsed tokens in this fragment. This is equivalent to
// `Token::in(fragment)`.
TokenList Fragment::parsed_tokens(void) const {
  return TokenList(impl->TokenReader(impl), impl->num_tokens);
}

// Return the list of token substitutions.
TokenSubstitutionList Fragment::substitutions(void) const {
  auto ret = std::make_shared<const TokenSubstitutionListImpl>(impl);
  auto num_nodes = ret->nodes.size();
  return TokenSubstitutionList(std::move(ret), num_nodes);
}

// Return the list of top-level declarations in this fragment.
std::vector<Decl> Fragment::top_level_declarations(void) const {
  std::vector<Decl> decls;
  TopLevelDeclListReader decl_ids = impl->Fragment().getTopLevelDeclarations();
  decls.reserve(decl_ids.size());
  for (auto eid_ : decl_ids) {
    EntityId eid(eid_);
    VariantId vid = eid.Unpack();
    if (std::holds_alternative<DeclarationId>(vid)) {
      auto decl_id = std::get<DeclarationId>(vid);
      if (decl_id.fragment_id == impl->fragment_id) {
        decls.emplace_back(impl, decl_id.offset);
      } else {
        assert(false);
      }
    } else {
      assert(false);
    }
  }
  return decls;
}

// Returns source IR for the fragment.
std::optional<std::string_view> Fragment::source_ir(void) const noexcept {
  auto mlir = impl->SourceIR();
  if (!mlir.empty()) {
    return mlir;
  }
  return std::nullopt;
}

// Run a Weggli search over this fragment.
WeggliQueryResult Fragment::query(const WeggliQuery &query) const {
  return WeggliQueryResult(
      std::make_shared<WeggliQueryResultImpl>(query, impl));
}

// Run a regular expression search over this fragment.
RegexQueryResult Fragment::query(const RegexQuery &query) const {
  return RegexQueryResult(std::make_shared<RegexQueryResultImpl>(query, impl));
}

}  // namespace mx
