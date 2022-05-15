// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/API.h>

#include <capnp/ez-rpc.h>
#include <capnp/message.h>
#include <capnp/serialize.h>
#include <capnp/serialize-packed.h>
#include <kj/async.h>
#include <kj/io.h>
#include <multiplier/Weggli.h>
#include <multiplier/Re2.h>
#include <mutex>
#include <optional>
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
using TypeReader = ast::Type::Reader;
using PseudoReader = ast::Pseudo::Reader;
using DeclListReader = capnp::List<ast::Decl, capnp::Kind::STRUCT>::Reader;
using StmtListReader = capnp::List<ast::Stmt, capnp::Kind::STRUCT>::Reader;
using TypeListReader = capnp::List<ast::Type, capnp::Kind::STRUCT>::Reader;
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

// Provides entities from a remote source, i.e. a remote
// server available via `host:port`, or another process
// available over a UNIX domain socket `unix:/path`.
class RemoteEntityProvider final : public EntityProvider {
 private:

  struct ClientConnection
      : public std::enable_shared_from_this<ClientConnection> {

    capnp::ReaderOptions options;
    capnp::EzRpcClient connection;
    rpc::Multiplier::Client client;

    ClientConnection(const std::string &host_port);
  };

  const std::string host_port;

  // Most recently observed version number.
  std::mutex version_number_lock;
  unsigned version_number;

  // Thread-local connections.
  std::deque<std::unique_ptr<ClientConnection>> tls_connections;
  std::mutex tls_connections_lock;

  // Cap'n Proto doesn't allow connections to be used in separate threads. This
  // returns an `this`-specific, thread-local connection to be used.
  ClientConnection &Connection(const Ptr &self);

  bool MaybeUpdateVersionNumber(const Ptr &self, unsigned new_version_number);

 public:
  RemoteEntityProvider(std::string host, std::string port);

  virtual ~RemoteEntityProvider(void) noexcept;

  // Return the version number.
  unsigned VersionNumber(void) final;

  // Update the version number. This is basically a signal to invalidate any
  // caches.
  void VersionNumberChanged(unsigned) final;

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  FilePathList ListFiles(const Ptr &) final;

  // Download a file by its unique ID.
  std::shared_ptr<const FileImpl> FileFor(const Ptr &, FileId id) final;

  // Download a fragment by its unique ID.
  std::shared_ptr<const FragmentImpl>
  FragmentFor(const Ptr &, FragmentId id) final;

  // Run a Weggli query over all files.
  std::shared_ptr<WeggliQueryResultImpl> Query(
      const Ptr &, const WeggliQuery &query) final;

  // Run a regular expression query over all files.
  std::shared_ptr<RegexQueryResultImpl> Query(
      const Ptr &, const RegexQuery &) final;

  // Return the redeclarations of a given declaration.
  std::vector<RawEntityId> Redeclarations(const Ptr &, RawEntityId) final;

  // Fill out `redecl_ids_out` and `fragmnet_ids_out` with the set of things
  // to analyze when looking for uses.
  void FillUses(const Ptr &, RawEntityId eid,
                std::vector<RawEntityId> &redecl_ids_out,
                std::vector<FragmentId> &fragment_ids_out) final;

  // Cache a returned file list.
  void CacheFileList(const FilePathList &, unsigned) final;

  // Cache a computed set of redeclarations for a given version number.
  void CacheRedeclarations(const std::vector<RawEntityId> &, unsigned) final;

  // Cache a returned set of uses for a given set of redeclarations.
  void CacheUses(
      const std::vector<RawEntityId> &, const std::vector<FragmentId> &,
      unsigned) final;
};

class InvalidEntityProvider final : public EntityProvider {
 public:
  virtual ~InvalidEntityProvider(void) noexcept;

  unsigned VersionNumber(void) final;

  void VersionNumberChanged(unsigned) final;

  FilePathList ListFiles(const Ptr &) final;

  std::shared_ptr<const FileImpl> FileFor(const Ptr &, FileId id) final;

  // Download a fragment by its unique ID.
  std::shared_ptr<const FragmentImpl>
  FragmentFor(const Ptr &, FragmentId id) final;

  std::shared_ptr<WeggliQueryResultImpl>
  Query(const Ptr &, const WeggliQuery &) final;

  std::shared_ptr<RegexQueryResultImpl> Query(
      const Ptr &, const RegexQuery &) final;

  std::vector<RawEntityId> Redeclarations(const Ptr &, RawEntityId) final;

  void FillUses(const Ptr &, RawEntityId eid,
                std::vector<RawEntityId> &redecl_ids_out,
                std::vector<FragmentId> &fragment_ids_out) final;

  void CacheFileList(const FilePathList &, unsigned) final;
  void CacheRedeclarations(const std::vector<RawEntityId> &, unsigned) final;
  void CacheUses(
      const std::vector<RawEntityId> &, const std::vector<FragmentId> &,
      unsigned) final;
};

class FileListImpl {
 public:
  const EntityProvider::Ptr ep;
  std::vector<std::pair<mx::FileId, std::weak_ptr<const FileImpl>>> files;

  explicit FileListImpl(EntityProvider::Ptr ep_);
};

}  // namespace mx
