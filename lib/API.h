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

  // Return the number of tokens accessible to this reader.
  virtual unsigned NumTokens(void) const noexcept = 0;

  // Return the kind of the Nth token.
  virtual TokenKind NthTokenKind(unsigned token_index) const = 0;

  // Return the data of the Nth token.
  virtual std::string_view NthTokenData(unsigned token_index) const = 0;

  // Return the id of the Nth token.
  virtual EntityId NthTokenId(unsigned token_index) const = 0;
};

// Used for invalid tokens.
class InvalidTokenReaderImpl final : public TokenReaderImpl {
 public:
  virtual ~InvalidTokenReaderImpl(void) noexcept;

  // Return the number of tokens accessible to this reader.
  unsigned NumTokens(void) const noexcept final;

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(unsigned) const final;

  // Return the data of the Nth token.
  std::string_view NthTokenData(unsigned) const final;

  // Return the id of the Nth token.
  EntityId NthTokenId(unsigned token_index) const final;
};

// Interface for accessing the tokens of a file.
class FileImpl {
 public:
  using Ptr = std::shared_ptr<const FileImpl>;

  const FileId id;

  // Needed for us to be able to look up the file containing this fragment,
  // or look up entities related to other fragments.
  const EntityProvider::Ptr ep;

  // List of fragments in this file.
  mutable std::vector<std::pair<mx::FragmentId,
                                std::weak_ptr<const FragmentImpl>>>
      fragments;

  virtual ~FileImpl(void) noexcept;

  inline FileImpl(FileId id_, EntityProvider::Ptr ep_)
      : id(id_),
        ep(std::move(ep_)) {}

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
  using Response = capnp::Response<mx::rpc::Multiplier::DownloadFileResults>;
  const Response response;
  const rpc::File::Reader reader;

  virtual ~ResponseFileImpl(void) noexcept;

  ResponseFileImpl(FileId id_, EntityProvider::Ptr ep_, Response response_);

  // Return a reader for the tokens in the file.
  TokenReaderImpl::Ptr TokenReader(const FileImpl::Ptr &) const final;

  // Return the number of tokens in the file.
  unsigned NumTokens(void) const noexcept final;

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(unsigned index) const final;

  // Return the data of the Nth token.
  std::string_view NthTokenData(unsigned index) const final;

  // Return the id of the Nth token.
  EntityId NthTokenId(unsigned token_index) const final;
};

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
  mutable FileImpl::Ptr containing_file;

  virtual ~FragmentImpl(void) noexcept;

  inline FragmentImpl(FragmentId id_, EntityProvider::Ptr ep_)
      : id(id_),
        ep(std::move(ep_)) {}

  // Return the ID of the file containing the first token.
  virtual FileId FileContaingFirstToken(void) const = 0;

  // Return a reader for the parsed tokens in the fragment. This doesn't
  // include all tokens, i.e. macro use tokens, comments, etc.
  virtual TokenReaderImpl::Ptr TokenReader(const FragmentImpl::Ptr &) const = 0;

  virtual unsigned FirstLine(void) const = 0;
  virtual unsigned LastLine(void) const = 0;
};

class InvalidFragmentImpl : public FragmentImpl {
 private:
  InvalidTokenReaderImpl empty_reader;

 public:
  using FragmentImpl::FragmentImpl;

  virtual ~InvalidFragmentImpl(void) noexcept;

  FileId FileContaingFirstToken(void) const final;
  TokenReaderImpl::Ptr TokenReader(const FragmentImpl::Ptr &) const final;
  unsigned FirstLine(void) const final;
  unsigned LastLine(void) const final;
};

// A fragment of code downloaded from the server.
class ResponseFragmentImpl final : public FragmentImpl, public TokenReaderImpl {
 public:
  using Response = capnp::Response<
      mx::rpc::Multiplier::DownloadFragmentResults>;

  const Response response;
  const rpc::Fragment::Reader reader;

  virtual ~ResponseFragmentImpl(void) noexcept;

  ResponseFragmentImpl(FragmentId id_, EntityProvider::Ptr ep_,
                       Response response_);

  // Return the ID of the file containing the first token.
  FileId FileContaingFirstToken(void) const final;

  unsigned FirstLine(void) const final;
  unsigned LastLine(void) const final;

  // Return a reader for the parsed tokens in the fragment. This doesn't
  // include all tokens, i.e. macro use tokens, comments, etc.
  TokenReaderImpl::Ptr TokenReader(const FragmentImpl::Ptr &) const final;

  // Return the number of tokens in the file.
  unsigned NumTokens(void) const noexcept final;

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(unsigned index) const final;

  // Return the data of the Nth token.
  std::string_view NthTokenData(unsigned index) const final;

  // Return the id of the Nth token.
  EntityId NthTokenId(unsigned token_index) const final;
};

// Provides entities from a remote source, i.e. a remote
// server available via `host:port`, or another process
// available over a UNIX domain socket `unix:/path`.
class RemoteEntityProvider final : public EntityProvider {
 private:
  // TODO(pag): Consider eventually running the client on a separate thread,
  //            and talking to it via `kj::Executor::executeSync`. Performance-
  //            wise this won't be great; however, it means that client/server
  //            stuff would happen on a single (background) thread, rather than
  //            from whatever thread the user of the API has to be on. It's not
  //            clear if the current API is thread-safe.
  capnp::EzRpcClient client;
  mx::rpc::Multiplier::Client multiplier;

 public:
  RemoteEntityProvider(std::string host, std::string port)
      : client(host + ':' + port),
        multiplier(client.getMain<mx::rpc::Multiplier>()) {}

  virtual ~RemoteEntityProvider(void) noexcept;

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  std::set<std::pair<std::filesystem::path, FileId>>
  list_files(void) noexcept final;

  // Download a file by its unique ID.
  File file(FileId id) noexcept final;

  // Download a fragment by its unique ID.
  Fragment fragment(FragmentId id) noexcept final;
};

}  // namespace mx
