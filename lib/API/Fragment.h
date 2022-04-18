// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Token.h"

namespace mx {

class FileImpl;

class FragmentImpl {
 public:
  using Ptr = std::shared_ptr<const FragmentImpl>;
  using WeakPtr = std::weak_ptr<const FragmentImpl>;

  const FragmentId id;

  // Needed for us to be able to look up the file containing this fragment,
  // or look up entities related to other fragments.
  const EntityProvider::Ptr ep;

  // The containing file, if we've computed it.
  //
  // TODO(pag): If we start using the client with multiple threads then we
  //            should guard this with a mutex.
  mutable std::shared_ptr<const FileImpl> containing_file;

  virtual ~FragmentImpl(void) noexcept;

  inline FragmentImpl(FragmentId id_, EntityProvider::Ptr ep_)
      : id(id_),
        ep(std::move(ep_)) {}

  // Return the ID of the file containing the first token.
  virtual FileId FileContaingFirstToken(void) const = 0;

  // Return a reader for the parsed tokens in the fragment. This doesn't
  // include all tokens, i.e. macro use tokens, comments, etc.
  virtual std::shared_ptr<const class TokenReader>
  TokenReader(const FragmentImpl::Ptr &) const = 0;

  // Return a reader for the whole fragment.
  virtual const FragmentReader &Fragment(void) const = 0;

  // Return a specific type of entity.
  virtual DeclReader NthDecl(unsigned offset) const = 0;
  virtual StmtReader NthStmt(unsigned offset) const = 0;
  virtual PseudoReader NthPseudo(unsigned offset) const = 0;

  virtual std::string_view SourceIR(void) const = 0;

  virtual std::string_view Data(void) const = 0;

  // Return the token associated with a specific entity ID.
  Token TokenFor(const FragmentImpl::Ptr &, EntityId id,
                 bool can_fail=false) const;

  // Return the inclusive token range associated with two entity IDs.
  TokenRange TokenRangeFor(const FragmentImpl::Ptr &, EntityId begin_id,
                           EntityId end_id) const;

  // Return the declaration associated with a specific entity ID.
  Decl DeclFor(const FragmentImpl::Ptr &, EntityId id) const;

  // Return the statement associated with a specific entity ID.
  Stmt StmtFor(const FragmentImpl::Ptr &, EntityId id) const;
};

// A packed fragment of code, i.e. a serialized fragment.
class PackedFragmentImpl final : public FragmentImpl, public TokenReader {
 public:
  using Ptr = std::shared_ptr<const PackedFragmentImpl>;
  using Response = capnp::Response<
      mx::rpc::Multiplier::DownloadFragmentResults>;

  PackedReaderState package;
  const rpc::Fragment::Reader reader;

  virtual ~PackedFragmentImpl(void) noexcept;

  PackedFragmentImpl(FragmentId id_, EntityProvider::Ptr ep_,
                     Response response_);

  // Return the ID of the file containing the first token.
  FileId FileContaingFirstToken(void) const final;

  // Return a reader for the parsed tokens in the fragment. This doesn't
  // include all tokens, i.e. macro use tokens, comments, etc.
  std::shared_ptr<const class TokenReader>
  TokenReader(const FragmentImpl::Ptr &) const final;

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

  // Return a reader for the whole fragment.
  const FragmentReader &Fragment(void) const final;

  // Return a specific type of entity.
  DeclReader NthDecl(unsigned offset) const final;
  StmtReader NthStmt(unsigned offset) const final;
  PseudoReader NthPseudo(unsigned offset) const final;

  std::string_view SourceIR(void) const final;

  std::string_view Data(void) const final;
};

}  // namespace mx
