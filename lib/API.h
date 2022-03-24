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

using NodeReader = capnp::List<uint64_t, capnp::Kind::PRIMITIVE>::Reader;
using TokenSubstitutionsReader = capnp::List<rpc::TokenSubstitution,
                                            capnp::Kind::STRUCT>::Reader;
using EntityListReader = ast::EntityList::Reader;

class TokenReader {
 public:
  using Ptr = std::shared_ptr<const TokenReader>;

  virtual ~TokenReader(void) noexcept;

  // Return the number of tokens accessible to this reader.
  virtual unsigned NumTokens(void) const noexcept = 0;

  // Return the kind of the Nth token.
  virtual TokenKind NthTokenKind(unsigned token_index) const = 0;

  // Return the data of the Nth token.
  virtual std::string_view NthTokenData(unsigned token_index) const = 0;

  // Return the id of the Nth token.
  virtual EntityId NthTokenId(unsigned token_index) const = 0;
};

struct BeforeTag {};
struct AfterTag {};

class TokenSubstitutionListImpl {
 public:
  const std::shared_ptr<const FragmentImpl> fragment;
  const NodeReader nodes;

  TokenSubstitutionListImpl(std::shared_ptr<const FragmentImpl> fragment_);

  TokenSubstitutionListImpl(std::shared_ptr<const FragmentImpl> fragment_,
                            unsigned offset, BeforeTag);

  TokenSubstitutionListImpl(std::shared_ptr<const FragmentImpl> fragment_,
                            unsigned offset, AfterTag);
};

// Used for invalid tokens.
class InvalidTokenReaderImpl final : public TokenReader {
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
  virtual TokenReader::Ptr TokenReader(const FileImpl::Ptr &) const = 0;
};

// An invalid file. This exists to handle some failure somewhere, e.g. a failure
// to get a response from the database.
class InvalidFileImpl final : public FileImpl {
 private:
  InvalidTokenReaderImpl empty_reader;

 public:
  using FileImpl::FileImpl;

  // Return a reader for the tokens in the file.
  TokenReader::Ptr TokenReader(const FileImpl::Ptr &) const final;
};

// A file downloaded as a result of a making an RPC.
class ResponseFileImpl final : public FileImpl, public TokenReader {
 public:
  using Response = capnp::Response<mx::rpc::Multiplier::DownloadFileResults>;
  const Response response;
  const rpc::File::Reader reader;

  virtual ~ResponseFileImpl(void) noexcept;

  ResponseFileImpl(FileId id_, EntityProvider::Ptr ep_, Response response_);

  // Return a reader for the tokens in the file.
  TokenReader::Ptr TokenReader(const FileImpl::Ptr &) const final;

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
  virtual TokenReader::Ptr TokenReader(const FragmentImpl::Ptr &) const = 0;

  virtual unsigned FirstLine(void) const = 0;
  virtual unsigned LastLine(void) const = 0;

  // Return a reader for token nodes.
  virtual NodeReader Nodes(void) const = 0;

  // Return a reader for token substitutions.
  virtual TokenSubstitutionsReader Substitutions(void) const = 0;

  // Return a reader for the entities in this fragment.
  virtual EntityListReader Entities(void) const = 0;
};

class InvalidFragmentImpl : public FragmentImpl {
 private:
  InvalidTokenReaderImpl empty_reader;

 public:
  using FragmentImpl::FragmentImpl;

  virtual ~InvalidFragmentImpl(void) noexcept;

  FileId FileContaingFirstToken(void) const final;
  TokenReader::Ptr TokenReader(const FragmentImpl::Ptr &) const final;
  unsigned FirstLine(void) const final;
  unsigned LastLine(void) const final;
  NodeReader Nodes(void) const final;
  TokenSubstitutionsReader Substitutions(void) const final;
  EntityListReader Entities(void) const final;
};

// A fragment of code downloaded from the server.
class ResponseFragmentImpl final : public FragmentImpl, public TokenReader {
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
  TokenReader::Ptr TokenReader(const FragmentImpl::Ptr &) const final;

  // Return the number of tokens in the file.
  unsigned NumTokens(void) const noexcept final;

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(unsigned index) const final;

  // Return the data of the Nth token.
  std::string_view NthTokenData(unsigned index) const final;

  // Return the id of the Nth token.
  EntityId NthTokenId(unsigned token_index) const final;

  // Return a reader for token nodes.
  NodeReader Nodes(void) const final;

  // Return a reader for token substitutions.
  TokenSubstitutionsReader Substitutions(void) const final;

  // Return a reader for the entities in this fragment.
  EntityListReader Entities(void) const final;
};

// Provides entities from a remote source, i.e. a remote
// server available via `host:port`, or another process
// available over a UNIX domain socket `unix:/path`.
class RemoteEntityProvider final : public EntityProvider {
 private:

  struct ClientConnection
      : public std::enable_shared_from_this<ClientConnection> {
    capnp::EzRpcClient connection;
    mx::rpc::Multiplier::Client client;

    ClientConnection(const std::string &host_port);
  };

  const std::string host_port;

  // Thread-local connections.
  std::deque<std::unique_ptr<ClientConnection>> tls_connections;
  std::mutex tls_connections_lock;

  ClientConnection &Connection(void);

 public:
  RemoteEntityProvider(std::string host, std::string port);

  virtual ~RemoteEntityProvider(void) noexcept;

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  FileList list_files(void) noexcept final;

  // Download a file by its unique ID.
  File file(FileId id) noexcept final;

  // Download a fragment by its unique ID.
  Fragment fragment(FragmentId id) noexcept final;
};

}  // namespace mx
