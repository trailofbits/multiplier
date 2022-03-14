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

  // Enqueue actions to index zero or more compile commands / jobs.
  kj::Promise<void> indexCompileCommands(
      IndexCompileCommandsContext context) final;
};

}  // namespace indexer
