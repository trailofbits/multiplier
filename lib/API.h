// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/API.h>
#include <multiplier/Weggli.h>

#include <capnp/ez-rpc.h>
#include <capnp/message.h>
#include <capnp/serialize.h>
#include <capnp/serialize-packed.h>
#include <kj/async.h>
#include <kj/io.h>
#include <optional>
#include <map>
#include <string>

#include "AST.capnp.h"
#include "RPC.capnp.h"

namespace mx {

using NodeReader = capnp::List<uint64_t, capnp::Kind::PRIMITIVE>::Reader;
using TokenSubstitutionsReader = capnp::List<rpc::TokenSubstitution,
				     capnp::Kind::STRUCT>::Reader;
using FragmentReader = rpc::Fragment::Reader;
using DeclReader = ast::Decl::Reader;
using StmtReader = ast::Stmt::Reader;
using PseudoReader = ast::Pseudo::Reader;
using DeclListReader = capnp::List<ast::Decl, capnp::Kind::STRUCT>::Reader;
using StmtListReader = capnp::List<ast::Stmt, capnp::Kind::STRUCT>::Reader;
using PseudoListReader = capnp::List<ast::Pseudo, capnp::Kind::STRUCT>::Reader;
using TopLevelDeclListReader = capnp::List<uint64_t, capnp::Kind::PRIMITIVE>::Reader;

struct PackedReaderState {
 private:
  std::string storage;
  std::optional<kj::ArrayInputStream> stream;
  std::optional<capnp::PackedMessageReader> packed_reader;

  PackedReaderState(void) = delete;

 public:
  explicit PackedReaderState(capnp::Data::Reader data);

  template <typename T>
  auto Reader(void) -> typename T::Reader {
    return packed_reader->getRoot<T>();
  }
};

class TokenReader {
public:
using Ptr = std::shared_ptr<const TokenReader>;

virtual ~TokenReader(void) noexcept;

// Return the number of tokens accessible to this reader.
virtual unsigned NumTokens(void) const = 0;

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
class InvalidTokenReader final : public TokenReader {
public:
virtual ~InvalidTokenReader(void) noexcept;

// Return the number of tokens accessible to this reader.
unsigned NumTokens(void) const final;

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
using WeakPtr = std::weak_ptr<const FileImpl>;

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

// A file downloaded as a result of a making an RPC.
class PackedFileImpl final : public FileImpl, public TokenReader {
 public:
  using Response = capnp::Response<mx::rpc::Multiplier::DownloadFileResults>;

  PackedReaderState package;
  const rpc::File::Reader reader;

  virtual ~PackedFileImpl(void) noexcept;

  PackedFileImpl(FileId id_, EntityProvider::Ptr ep_, Response response_);

  // Return a reader for the tokens in the file.
  TokenReader::Ptr TokenReader(const FileImpl::Ptr &) const final;

  // Return the number of tokens in the file.
  unsigned NumTokens(void) const final;

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

  // Return a reader for the whole fragment.
  virtual const FragmentReader &Fragment(void) const = 0;

  // Return a specific type of entity.
  virtual DeclReader NthDecl(unsigned offset) const = 0;
  virtual StmtReader NthStmt(unsigned offset) const = 0;
  virtual PseudoReader NthPseudo(unsigned offset) const = 0;

  virtual std::string_view SourceIR(void) const = 0;

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

// A packed fragment of code.
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
  TokenReader::Ptr TokenReader(const FragmentImpl::Ptr &) const final;

  // Return the number of tokens in the file.
  unsigned NumTokens(void) const final;

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(unsigned index) const final;

  // Return the data of the Nth token.
  std::string_view NthTokenData(unsigned index) const final;

  // Return the id of the Nth token.
  EntityId NthTokenId(unsigned token_index) const final;

  // Return a reader for the whole fragment.
  const FragmentReader &Fragment(void) const final;

  // Return a specific type of entity.
  DeclReader NthDecl(unsigned offset) const final;
  StmtReader NthStmt(unsigned offset) const final;
  PseudoReader NthPseudo(unsigned offset) const final;

  std::string_view SourceIR(void) const final;
};

class SyntaxQueryResultImpl {
 public:
  using Response = capnp::Response<mx::rpc::Multiplier::SyntaxQueryResults>;

  using Ptr = std::shared_ptr<const SyntaxQueryResultImpl>;

  virtual ~SyntaxQueryResultImpl(void) noexcept;

  SyntaxQueryResultImpl(std::string syntax_, EntityProvider::Ptr ep_,
                        Response response_, bool is_cpp);

  const std::string syntax;

  // Needed for us to be able to look up the file containing this fragment,
  // or look up entities related to other fragments.
  const EntityProvider::Ptr ep;

  // Client-local version of the query to be run on each fragment.
  const WeggliQuery query;

  // Buffer of fragment data.
  mutable std::string fragment_buffer;
  mutable std::map<unsigned, EntityId> offset_to_token;
  mutable mx::FragmentId fragment_buffer_id{kInvalidEntityId};
  mutable std::vector<WeggliMatchData> weggli_matches;
  mutable unsigned next_weggli_match{0};

  // List of fragments in this file.
  mutable std::vector<std::pair<mx::FragmentId,
                      std::weak_ptr<const FragmentImpl>>> fragments;

  FragmentImpl::Ptr GetFragmentAtIndex(unsigned index) const;

  EntityId EntityContainingOffset(unsigned offset) const;

  void GetUnparsedTokens(TokenSubstitutionList nodes) const;
};

// Provides entities from a remote source, i.e. a remote
// server available via `host:port`, or another process
// available over a UNIX domain socket `unix:/path`.
class RemoteEntityProvider final : public EntityProvider {
 private:

  struct ClientConnection
      : public std::enable_shared_from_this<ClientConnection> {

    capnp::ReaderOptions options;
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
  FilePathList ListFiles(void) final;

  // Download a file by its unique ID.
  FileImpl::Ptr FileFor(const Ptr &, FileId id) final;

  // Download a fragment by its unique ID.
  FragmentImpl::Ptr FragmentFor(const Ptr &, FragmentId id) final;

  SyntaxQueryResultImpl::Ptr SyntaxQuery(
      const Ptr &, std::string query, bool is_cpp) final;
};

class InvalidEntityProvider final : public EntityProvider {
 public:
  virtual ~InvalidEntityProvider(void) noexcept;

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  FilePathList ListFiles(void) final;

  // Download a file by its unique ID.
  FileImpl::Ptr FileFor(const Ptr &, FileId id) final;

  // Download a fragment by its unique ID.
  FragmentImpl::Ptr FragmentFor(const Ptr &, FragmentId id) final;

  SyntaxQueryResultImpl::Ptr SyntaxQuery(const Ptr &, std::string query,
                                         bool is_cpp) final;
};

class FileListImpl {
 public:
  const EntityProvider::Ptr ep;
  std::vector<std::pair<mx::FileId, FileImpl::WeakPtr>> files;

  explicit FileListImpl(EntityProvider::Ptr ep_);
};

}  // namespace mx
