// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Token.h"

#include <mutex>

namespace mx {

class TokenReader;

using FileLocationVector = std::vector<std::pair<unsigned, unsigned>>;

class FileLocationCacheImpl {
 public:
  std::mutex lock;
  const FileLocationConfiguration config;
  std::unordered_map<RawEntityId, FileLocationVector> cache;

  inline FileLocationCacheImpl(const FileLocationConfiguration &config_)
      : config(config_) {}

  // Add a file to the cache.
  const FileLocationVector &Add(File file);
};

class FileListImpl {
 public:
  const EntityProvider::Ptr ep;

  // NOTE(pag): These are `EntityId`-packed file ids.
  std::vector<RawEntityId> file_ids;

  explicit FileListImpl(EntityProvider::Ptr ep_);
};

// Interface for accessing the tokens of a file.
class FileImpl {
 public:
  using Ptr = std::shared_ptr<const FileImpl>;
  using WeakPtr = std::weak_ptr<const FileImpl>;

  // NOTE(pag): This is *NOT* a packed file id / entity ID representation, it
  //            is the raw ID that would go into a `FileId`.
  const RawEntityId file_id;

  // Needed for us to be able to look up the file containing this fragment,
  // or look up entities related to other fragments.
  const EntityProvider::Ptr ep;

  virtual ~FileImpl(void) noexcept;

  inline FileImpl(RawEntityId id_, EntityProvider::Ptr ep_)
      : file_id(id_),
        ep(std::move(ep_)) {}

  inline FileImpl(FileId id_, EntityProvider::Ptr ep_)
      : FileImpl(id_.file_id, std::move(ep_)) {}

  // Return a reader for the tokens in the file.
  virtual std::shared_ptr<const class TokenReader> TokenReader(
      const FileImpl::Ptr &) const = 0;

  // Return the data of the file.
  virtual std::string_view Data(void) const = 0;
};

// A file downloaded as a result of a making an RPC.
class PackedFileImpl final : public FileImpl, public TokenReader {
 public:
  PackedReaderState package;
  const rpc::File::Reader reader;
  const unsigned num_tokens;

  virtual ~PackedFileImpl(void) noexcept;

  PackedFileImpl(RawEntityId id_, EntityProvider::Ptr ep_,
                 const capnp::Data::Reader &reader_);

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
                                 RawEntityId id) const final;

  // Returns `true` if `this` is logically equivalent to `that`.
  bool Equals(const class TokenReader *that) const final;
};

}  // namespace mx
