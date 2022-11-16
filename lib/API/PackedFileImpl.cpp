// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "File.h"
#include <multiplier/Entities/TokenKind.h>

namespace mx {

PackedFileImpl::~PackedFileImpl(void) noexcept {}

PackedFileImpl::PackedFileImpl(
    RawEntityId id_, EntityProvider::Ptr ep_, const capnp::Data::Reader &reader_)
    : FileImpl(id_, std::move(ep_)),
      package(reader_),
      reader(package.Reader<rpc::File>()),
      num_tokens(reader.getTokenKinds().size()) {}

// Return the data of the file.
std::string_view PackedFileImpl::Data(void) const {
  auto data = reader.getData();
  return std::string_view(data.cStr(), data.size());
}

// Return a reader for the tokens in the file.
TokenReader::Ptr PackedFileImpl::TokenReader(
    const FileImpl::Ptr &self) const {
  return TokenReader::Ptr(self, static_cast<const class TokenReader *>(this));
}

// Return the number of tokens in the file.
unsigned PackedFileImpl::NumTokens(void) const {
  return num_tokens;
}

// Return the kind of the Nth token.
TokenKind PackedFileImpl::NthTokenKind(unsigned token_index) const {
  if (token_index < num_tokens) {
    return static_cast<TokenKind>(reader.getTokenKinds()[token_index]);
  } else {
    return TokenKind::UNKNOWN;
  }
}

// Return the data of the Nth token.
std::string_view PackedFileImpl::NthTokenData(unsigned token_index) const {
  if (token_index < num_tokens) {
    auto tor = reader.getTokenOffsets();
    auto bo = tor[token_index];
    auto eo = tor[token_index + 1u];
    return std::string_view(&(reader.getData().cStr()[bo]), eo - bo);
  } else {
    return {};
  }
}

// Return the id of the Nth token.
EntityId PackedFileImpl::NthTokenId(unsigned token_index) const {
  if (token_index < num_tokens) {
    FileTokenId id;
    id.file_id = this->file_id;
    id.kind = static_cast<TokenKind>(reader.getTokenKinds()[token_index]);
    id.offset = token_index;
    return id;
  } else {
    return kInvalidEntityId;
  }
}

EntityId PackedFileImpl::NthFileTokenId(unsigned token_index) const {
  return NthTokenId(token_index);
}

// Return the token reader for another file.
TokenReader::Ptr PackedFileImpl::ReaderForFile(const TokenReader::Ptr &self,
                                               RawEntityId fid) const {
  if (fid == file_id) {
    return self;
  } else if (FileImpl::Ptr ptr = ep->FileFor(ep, fid)) {
    return ptr->TokenReader(ptr);
  } else {
    return {};
  }
}

// Returns `true` if `this` is logically equivalent to `that`.
bool PackedFileImpl::Equals(const class TokenReader *that_) const {
  if (!that_) {
    return false;
  } else if (this == that_) {
    return true;
  }

  auto that = dynamic_cast<const PackedFileImpl *>(that_);
  if (!that) {
    return false;
  }

  return that->file_id == file_id && that->ep.get() == ep.get();
}

}  // namespace mx
