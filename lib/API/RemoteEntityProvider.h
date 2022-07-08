// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "API.h"

#include <capnp/ez-rpc.h>
#include <deque>
#include <kj/async.h>

#include "File.h"
#include "Fragment.h"
#include "Re2.h"
#include "Token.h"
#include "Use.h"
#include "Weggli.h"

namespace mx {

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

  // Clear any caches.
  void ClearCache(void) final;

  // Return the version number.
  unsigned VersionNumber(void) final;
  unsigned VersionNumber(const Ptr &) final;

  // Update the version number. This is basically a signal to invalidate any
  // caches.
  void VersionNumberChanged(unsigned) final;

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  FilePathList ListFiles(const Ptr &) final;

  // Get the current list of fragment IDs associated with a file.
  std::vector<RawEntityId> ListFragmentsInFile(
      const Ptr &, RawEntityId id) final;

  // Download a file by its unique ID.
  std::shared_ptr<const FileImpl> FileFor(const Ptr &, RawEntityId id) final;

  // Download a fragment by its unique ID.
  std::shared_ptr<const FragmentImpl>
  FragmentFor(const Ptr &, RawEntityId id) final;

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
                std::vector<RawEntityId> &fragment_ids_out) final;

  // Fill out `redecl_ids_out` and `fragmnet_ids_out` with the set of things
  // to analyze when looking for references.
  void FillReferences(const Ptr &, RawEntityId eid,
                      std::vector<RawEntityId> &redecl_ids_out,
                      std::vector<RawEntityId> &fragment_ids_out) final;

  void FindSymbol(const Ptr &, std::string name,
                  mx::DeclCategory category,
                  std::vector<RawEntityId> &ids_out) final;
};

}  // namespace mx
