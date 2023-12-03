// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "TokenTree.h"

#include <mutex>
#include <unordered_map>

namespace mx {

class TokenReader;

using FileLocationVector = std::vector<std::pair<unsigned, unsigned>>;
using FileIdList = std::vector<SpecificEntityId<FileId>>;

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

class ReadFileTokensFromFile final : public TokenReader {
 public:
  const FileImpl * const file;

  inline ReadFileTokensFromFile(FileImpl *file_)
      : file(file_) {}

  // Return the number of tokens in the fragment.
  unsigned NumTokens(void) const override;

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(unsigned index) const override;

  // Return the data of the Nth token.
  std::string_view NthTokenData(unsigned index) const override;

  // Return the id of the token from which the Nth token is derived.
  EntityId NthDerivedTokenId(unsigned token_index) const override;

  // Return the id of the parsed token which is derived from the Nth token.
  EntityId NthParsedTokenId(unsigned) const override;

  // Return the id of the macro containing the Nth token.
  EntityId NthContainingMacroId(unsigned) const override;

  // Return an entity id associated with the Nth token.
  EntityId NthRelatedEntityId(unsigned) const override;

  // Return the entity associated with the Nth token.
  VariantEntity NthRelatedEntity(EntityOffset) const override;

  // Return the id of the Nth token.
  EntityId NthTokenId(unsigned token_index) const override;
  EntityId NthFileTokenId(unsigned token_index) const override;

  // Returns `true` if `this` is logically equivalent to `that`.
  bool Equals(const class TokenReader *that) const override;

  const FileImpl *OwningFile(void) const noexcept final;
};

// Interface for accessing the tokens of a file.
class FileImpl final : public EntityImpl<rpc::File> {
 public:
  using Ptr = FileImplPtr;
  using WeakPtr = WeakFileImplPtr;

 private:
  friend class ReadFileTokensFromFile;

  // Reads the tokens from `reader`.
  const ReadFileTokensFromFile file_token_reader;

 public:

  // NOTE(pag): This is *NOT* a packed file id / entity ID representation, it
  //            is the raw ID that would go into a `FileId`.
  const RawEntityId file_id;

  // Number of tokens in this file.
  const unsigned num_tokens;

  // Cached token tree.
  //
  // TODO(pag): Add method to entity provider, so we can add it to the GC-based
  //            cache.
  TokenTreeImplCache cached_token_tree;

  ~FileImpl(void) noexcept;

  explicit FileImpl(EntityProviderPtr ep_, kj::Array<capnp::word> data_,
                    RawEntityId id_);

  // Return a reader for the tokens in the file.
  inline std::shared_ptr<const class TokenReader> TokenReader(
      const FileImplPtr &self) const {
    return TokenReaderPtr(self, &file_token_reader);
  }

  // Return the data of the file.
  std::string_view Data(void) const & noexcept;
};

}  // namespace mx
