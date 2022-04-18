// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Fragment.h"

#include "File.h"

namespace mx {

// Return the list of fragments in a file.
FragmentList Fragment::in(const File &file) {
  return FragmentList(
      file.impl, static_cast<unsigned>(file.impl->fragments.size()));
}

// Return the fragment containing a query match.
Fragment Fragment::containing(const WeggliQueryMatch &match) {
  return Fragment(match.frag);
}

// Return the fragment containing a query match.
Fragment Fragment::containing(const RegexMatch &match) {
  return Fragment(match.frag);
}

// Return the ID of this fragment.
FragmentId Fragment::id(void) const noexcept {
  return impl->id;
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
      first_fid.offset,
      (last_fid.offset - first_fid.offset) + 1u);
}

// The range of parsed tokens in this fragment. This is equivalent to
// `Token::in(fragment)`.
TokenRange Fragment::parsed_tokens(void) const {
  auto reader = impl->TokenReader(impl);
  auto num_tokens = reader->NumTokens();
  return TokenRange(std::move(reader), 0, num_tokens);
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
  for (auto id_ : decl_ids) {
    EntityId id(id_);
    VariantId vid = id.Unpack();
    if (std::holds_alternative<DeclarationId>(vid)) {
      auto decl_id = std::get<DeclarationId>(vid);
      if (decl_id.fragment_id == impl->id) {
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

}  // namespace mx
