// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Fragment.h"

#include "File.h"

namespace mx {

PackedFragmentImpl::~PackedFragmentImpl(void) noexcept {}

PackedFragmentImpl::PackedFragmentImpl(FragmentId id_,
                                       EntityProvider::Ptr ep_,
                                       Response response)
    : FragmentImpl(id_, std::move(ep_)),
      package(response.getFragment()),
      reader(package.Reader<rpc::Fragment>()) {

  // For bounds checking.
  num_decls = reader.getDeclarations().size();
  num_stmts = reader.getStatements().size();
  num_types = reader.getTypes().size();
  num_pseudos = reader.getOthers().size();
}

// Return the ID of the file containing the first token.
FileId PackedFragmentImpl::FileContaingFirstToken(void) const {
  EntityId id(reader.getFirstFileTokenId());
  if (VariantId unpacked_id = id.Unpack();
      std::holds_alternative<FileTokenId>(unpacked_id)) {
    return std::get<FileTokenId>(unpacked_id).file_id;
  } else {
    return kInvalidEntityId;
  }
}

// Return a reader for the parsed tokens in the fragment. This doesn't
// include all tokens, i.e. macro use tokens, comments, etc.
TokenReader::Ptr PackedFragmentImpl::TokenReader(
    const FragmentImpl::Ptr &self) const {
  return TokenReader::Ptr(self, static_cast<const class TokenReader *>(this));
}

// Return the number of tokens in the file.
unsigned PackedFragmentImpl::NumTokens(void) const {
  return reader.getTokenKinds().size();
}

// Return the kind of the Nth token.
TokenKind PackedFragmentImpl::NthTokenKind(unsigned index) const {
  return static_cast<TokenKind>(reader.getTokenKinds()[index]);
}

// Return the data of the Nth token.
std::string_view PackedFragmentImpl::NthTokenData(unsigned index) const {
  auto tor = reader.getTokenOffsets();
  auto bo = tor[index];
  auto eo = tor[index + 1u];

  // NOTE(pag): Extra space is added after tokens in the indexer.
  return std::string_view(&(reader.getParsedTokenData().cStr()[bo]),
                          eo - bo - 1u);
}

// Return the id of the Nth token.
EntityId PackedFragmentImpl::NthTokenId(unsigned index) const {
  FragmentTokenId id;
  id.fragment_id = this->fragment_id;
  id.offset = index;
  id.kind = NthTokenKind(index);
  return id;
}

EntityId PackedFragmentImpl::NthFileTokenId(unsigned token_index) const {
  return reader.getFileTokenIds()[token_index];
}

// Return the token reader for another file.
TokenReader::Ptr PackedFragmentImpl::ReaderForFile(
    const TokenReader::Ptr &self, mx::FileId file_id) const {
  FileImpl::Ptr ptr = ep->FileFor(ep, file_id);
  return ptr->TokenReader(ptr);
}

// Return a reader for the whole fragment.
const FragmentReader &PackedFragmentImpl::Fragment(void) const {
  return reader;
}

// Return a specific type of entity.
DeclReader PackedFragmentImpl::NthDecl(unsigned offset) const {
  return reader.getDeclarations()[offset];
}

StmtReader PackedFragmentImpl::NthStmt(unsigned offset) const {
  return reader.getStatements()[offset];
}

TypeReader PackedFragmentImpl::NthType(unsigned offset) const {
  return reader.getTypes()[offset];
}

PseudoReader PackedFragmentImpl::NthPseudo(unsigned offset) const {
  return reader.getOthers()[offset];
}

std::string_view PackedFragmentImpl::SourceIR(void) const {
  if (reader.hasMlir()) {
    return std::string_view(reader.getMlir().cStr(), reader.getMlir().size());
  } else {
    return {};
  }
}

std::string_view PackedFragmentImpl::Data(void) const {
  if (reader.hasParsedTokenData()) {
    return std::string_view(reader.getParsedTokenData().cStr(),
                            reader.getParsedTokenData().size());
  } else {
    return {};
  }
}

}  // namespace mx
