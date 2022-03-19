// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <filesystem>
#include <memory>
#include <multiplier/Executor.h>
#include <multiplier/RPC.capnp.h>

//#include "Storage.h"

namespace indexer {

struct ServerOptions {
  // Options for the worker pool.
  mx::ExecutorOptions executor_options;

  // Options for SQLite.
  //indexer::StorageOptions storage_options;

  // Directory where data is stored.
  std::filesystem::path workspace_dir;

  // Whether or not to show progress bars.
  bool show_progress_bars;
};

class ServerImpl;

class Server final : public mx::rpc::Multiplier::Server {
 private:
  std::unique_ptr<ServerImpl> d;

 public:
  virtual ~Server(void);

  // Initialize the server.
  Server(ServerOptions &options_);

  // Download a list of file info (file id, paths) where the file IDs
  // are greater-than-or-equal to some minimum ID.
  kj::Promise<void> downloadFileList(
      DownloadFileListContext context) final;

  // Enqueue actions to index zero or more compile commands / jobs.
  kj::Promise<void> indexCompileCommands(
      IndexCompileCommandsContext context) final;

  // Download a file associated with a specific file ID.
  kj::Promise<void> downloadFile(DownloadFileContext context) final;

  // Download a file containing a token with a specific ID.
  kj::Promise<void> downloadFileContainingEntity(
      DownloadFileContainingEntityContext context) final;

  // Download some indexed code containing an entity with a specific ID.
  kj::Promise<void> downloadIndexedCodeContainingEntity(
      DownloadIndexedCodeContainingEntityContext context) final;

};

}  // namespace indexer
