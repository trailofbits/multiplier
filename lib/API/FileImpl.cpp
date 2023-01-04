// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "File.h"
#include <multiplier/Entities/TokenKind.h>

namespace mx {

FileImpl::~FileImpl(void) noexcept {}

FileImpl::FileImpl(
    FileId id_, EntityProvider::Ptr ep_,
    const capnp::Data::Reader &reader_)
    : file_id(id_.file_id),
      ep(std::move(ep_)),
      package(reader_),
      reader(package.Reader<rpc::File>()),
      file_token_reader(this),
      num_tokens(reader.getTokenKinds().size()) {
  assert((num_tokens + 1u) == reader.getTokenOffsets().size());
}

// Return the data of the file.
std::string_view FileImpl::Data(void) const {
  auto data = reader.getData();
  return std::string_view(data.cStr(), data.size());
}

// Return the number of tokens in the file.
unsigned ReadFileTokensFromFile::NumTokens(void) const {
  return file->num_tokens;
}

// Return the kind of the Nth token.
TokenKind ReadFileTokensFromFile::NthTokenKind(unsigned token_index) const {
  if (token_index < file->num_tokens) {
    return static_cast<TokenKind>(file->reader.getTokenKinds()[token_index]);
  } else {
    return TokenKind::UNKNOWN;
  }
}

// Return the data of the Nth token.
std::string_view ReadFileTokensFromFile::NthTokenData(
    unsigned token_index) const {
  if (token_index < file->num_tokens) {
    auto tor = file->reader.getTokenOffsets();
    auto bo = tor[token_index];
    auto eo = tor[token_index + 1u];
    return std::string_view(&(file->reader.getData().cStr()[bo]), eo - bo);
  } else {
    return {};
  }
}

// Return the id of the token from which the Nth token is derived.
EntityId ReadFileTokensFromFile::NthDerivedTokenId(unsigned) const {
  return kInvalidEntityId;
}

// Return the id of the parsed token which is derived from the Nth token.
EntityId ReadFileTokensFromFile::NthParsedTokenId(unsigned) const {
  return kInvalidEntityId;
}

// Return the id of the macro containing the Nth token.
EntityId ReadFileTokensFromFile::NthContainingMacroId(unsigned) const {
  return kInvalidEntityId;
}

// Return the id of the Nth token.
EntityId ReadFileTokensFromFile::NthTokenId(unsigned token_index) const {
  if (token_index < file->num_tokens) {
    FileTokenId id;
    id.file_id = file->file_id;
    id.kind = static_cast<TokenKind>(file->reader.getTokenKinds()[token_index]);
    id.offset = token_index;
    return id;
  } else {
    return kInvalidEntityId;
  }
}

EntityId ReadFileTokensFromFile::NthFileTokenId(unsigned token_index) const {
  return NthTokenId(token_index);
}

// Return the token reader for another file/fragment.
TokenReader::Ptr ReadFileTokensFromFile::ReaderForToken(
    const TokenReader::Ptr &self, RawEntityId eid) const {
  return TokenReader::ReaderForToken(self, file->ep, eid);
}

// Returns `true` if `this` is logically equivalent to `that`.
bool ReadFileTokensFromFile::Equals(const class TokenReader *that_) const {
  if (!dynamic_cast<const ReadFileTokensFromFile *>(that_)) {
    return false;
  } else if (this == that_) {
    return true;
  }

  auto that = that_->OwningFile();
  if (file == that) {
    return true;
  }

  if (!that || that->file_id != file->file_id ||
      that->ep.get() != file->ep.get()) {
    return false;
  }

  return true;
}

const FileImpl *ReadFileTokensFromFile::OwningFile(void) const noexcept {
  return file;
}

}  // namespace mx
