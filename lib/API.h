// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/API.h>

#include <capnp/ez-rpc.h>
#include <kj/async.h>

#include "AST.capnp.h"
#include "RPC.capnp.h"

namespace mx {

class TokenReaderImpl {
 public:
  using Ptr = std::shared_ptr<const TokenReaderImpl>;

  virtual ~TokenReaderImpl(void) noexcept;

  // Returns whether or not this token reader is valid.
  virtual bool IsValid(void) const noexcept;

  // Return the number of tokens accessible to this reader.
  virtual unsigned NumTokens(void) const noexcept = 0;

  // Return the kind of the Nth token.
  virtual TokenKind NthTokenKind(unsigned token_index) const = 0;

  // Return the data of the Nth token.
  virtual std::string_view NthTokenData(unsigned token_index) const = 0;
};

// Used for invalid tokens.
class InvalidTokenReaderImpl final : public TokenReaderImpl {
 public:

  // Returns whether or not this token reader is valid.
  bool IsValid(void) const noexcept final;

  // Return the number of tokens accessible to this reader.
  unsigned NumTokens(void) const noexcept final;

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(unsigned) const final;

  // Return the data of the Nth token.
  std::string_view NthTokenData(unsigned) const final;
};

// Interface for accessing the tokens of a file.
class FileImpl {
 public:
  using Ptr = std::shared_ptr<const FileImpl>;

  const FileId id;

  virtual ~FileImpl(void) noexcept;

  inline FileImpl(FileId id_)
      : id(id_) {}

  // Return a reader for the tokens in the file.
  virtual TokenReaderImpl::Ptr TokenReader(const FileImpl::Ptr &) const = 0;
};

// An invalid file. This exists to handle some failure somewhere, e.g. a failure
// to get a response from the database.
class InvalidFileImpl final : public FileImpl {
 private:
  InvalidTokenReaderImpl empty_reader;

 public:
  using FileImpl::FileImpl;

  // Return a reader for the tokens in the file.
  TokenReaderImpl::Ptr TokenReader(const FileImpl::Ptr &) const final;
};

// A file downloaded as a result of a making an RPC.
class ResponseFileImpl final : public FileImpl, public TokenReaderImpl {
 public:
  capnp::Response<mx::rpc::Multiplier::DownloadFileResults> response;
  rpc::File::Reader reader;

  virtual ~ResponseFileImpl(void) noexcept;

  ResponseFileImpl(
      FileId id_,
      capnp::Response<mx::rpc::Multiplier::DownloadFileResults> response_);

  // Return a reader for the tokens in the file.
  TokenReaderImpl::Ptr TokenReader(const FileImpl::Ptr &) const final;

  // Return the number of tokens in the file.
  unsigned NumTokens(void) const noexcept final;

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(unsigned index) const final;

  // Return the data of the Nth token.
  std::string_view NthTokenData(unsigned index) const final;
};

}  // namespace mx
