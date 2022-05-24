// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "File.h"

namespace mx {

PackedFileImpl::~PackedFileImpl(void) noexcept {}

PackedFileImpl::PackedFileImpl(
    FileId id_, EntityProvider::Ptr ep_, Response response)
    : FileImpl(id_, std::move(ep_)),
      package(response.getFile()),
      reader(package.Reader<rpc::File>()) {}

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
  return reader.getTokenKinds().size();
}

// Return the kind of the Nth token.
TokenKind PackedFileImpl::NthTokenKind(unsigned index) const {
  return static_cast<TokenKind>(reader.getTokenKinds()[index]);
}

// Return the data of the Nth token.
std::string_view PackedFileImpl::NthTokenData(unsigned index) const {
  auto tor = reader.getTokenOffsets();
  auto bo = tor[index];
  auto eo = tor[index + 1u];
  return std::string_view(&(reader.getData().cStr()[bo]), eo - bo);
}

// Return the id of the Nth token.
EntityId PackedFileImpl::NthTokenId(unsigned index) const {
  FileTokenId id;
  id.file_id = this->file_id;
  id.kind = NthTokenKind(index);
  id.offset = index;
  return id;
}

EntityId PackedFileImpl::NthFileTokenId(unsigned token_index) const {
  return NthTokenId(token_index);
}

// Return the token reader for another file.
TokenReader::Ptr PackedFileImpl::ReaderForFile(const TokenReader::Ptr &self,
                                               mx::FileId fid) const {
  if (fid == file_id) {
    return self;
  } else {
    FileImpl::Ptr ptr = ep->FileFor(ep, fid);
    return ptr->TokenReader(ptr);
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
