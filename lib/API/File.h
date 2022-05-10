// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Token.h"

namespace mx {

class TokenReader;

// Interface for accessing the tokens of a file.
class FileImpl {
 public:
  using Ptr = std::shared_ptr<const FileImpl>;
  using WeakPtr = std::weak_ptr<const FileImpl>;

  const FileId file_id;

  // Needed for us to be able to look up the file containing this fragment,
  // or look up entities related to other fragments.
  const EntityProvider::Ptr ep;

  // List of fragments in this file.
  mutable std::vector<std::pair<mx::FragmentId,
        std::weak_ptr<const FragmentImpl>>>
      fragments;

  virtual ~FileImpl(void) noexcept;

  inline FileImpl(FileId id_, EntityProvider::Ptr ep_)
      : file_id(id_),
        ep(std::move(ep_)) {}

  // Return a reader for the tokens in the file.
  virtual std::shared_ptr<const class TokenReader> TokenReader(
      const FileImpl::Ptr &) const = 0;

  // Return the data of the file.
  virtual std::string_view Data(void) const = 0;
};

// A file downloaded as a result of a making an RPC.
class PackedFileImpl final : public FileImpl, public TokenReader {
 public:
  using Response = capnp::Response<mx::rpc::Multiplier::DownloadFileResults>;

  PackedReaderState package;
  const rpc::File::Reader reader;

  virtual ~PackedFileImpl(void) noexcept;

  PackedFileImpl(FileId id_, EntityProvider::Ptr ep_, Response response_);

  // Return the data of the file.
  std::string_view Data(void) const final;

  // Return a reader for the tokens in the file.
  std::shared_ptr<const class TokenReader>
  TokenReader(const FileImpl::Ptr &) const final;

  // Return the number of tokens in the file.
  unsigned NumTokens(void) const final;

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(unsigned index) const final;

  // Return the data of the Nth token.
  std::string_view NthTokenData(unsigned index) const final;

  // Return the id of the Nth token.
  EntityId NthTokenId(unsigned token_index) const final;
  EntityId NthFileTokenId(unsigned token_index) const final;

  // Return the token reader for another file.
  TokenReader::Ptr ReaderForFile(const TokenReader::Ptr &self,
                                 mx::FileId id) const final;
};

}  // namespace mx
