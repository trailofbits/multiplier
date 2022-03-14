// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <capnp/ez-rpc.h>
#include <cstdlib>
#include <filesystem>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <kj/async-io.h>
#include <kj/debug.h>
#include <memory>
#include <multiplier/Result.h>
#include <pasta/Util/Init.h>
#include <sstream>
#include <system_error>

#include "Server.h"

// Should we show a help message?
DECLARE_bool(help);

// Host and port for this server.
DEFINE_string(host, "localhost", "Hostname of this server. Use 'unix' for a UNIX domain socket.");
DEFINE_string(port, "50051", "Port of this server. Use a path and 'unix' for the host for a UNIX domain socket.");

// Number of threads to use in the executors. These are mostly used for indexing
// jobs.
DEFINE_int32(num_workers, -1, "Number of worker threads to use for parallel jobs");

// Should we show progress bars when indexing?
DEFINE_bool(show_progress, false, "Show indexing progress bars");

// Directory where stuff (RocksDB k/v stores, SQLite database) is stored.
DEFINE_string(workspace_dir, "",
              "Path to the workspace into which semi-permanent indexer data "
              "should be stored. Defaults to the current working directory "
              "of `mx-index`.");

// Should we disable aynchronous insertions to the database? Where possible, we
// enqueue stuff to be bulk-inserted into the database in a single transaction.
DEFINE_bool(disable_async_inserts, false,
            "Disable asynchronous inserts into the SQLite database?");

// Should we disable asynchronous mode, and instead synchronize the SQLite
// engine with the underlying storage (typically the file system)?
DEFINE_bool(disable_async_writes, false,
            "Disable asynchronous writes to the underlying storage engine "
            "(e.g. the file system) containing the SQLite database?");

namespace {

// Try to get the workspace directory.
static mx::Result<std::filesystem::path, std::string> TryGetWorkspaceDir(
    std::filesystem::path path) {
  std::error_code ec;
  std::stringstream err;
  if (path.empty()) {
    path = std::filesystem::current_path(ec);
    if (ec) {
      err << "Unable to determine the current working directory: "
          << ec.message();
      return err.str();
    }
  }

  if (!std::filesystem::is_directory(path)) {
    if (!std::filesystem::create_directory(path, ec)) {
      err << "Unable to create directory '" << path.generic_string()
          << "' for workspace: " << ec.message();
      return err.str();
    }
  }

  std::filesystem::directory_iterator it(path, ec);
  if (ec) {
    err << "Specified directory '" << path.generic_string()
        << "' for workspace is not iterable: " << ec.message();
    return err.str();
  }
  // Make sure we can list the directory.
  for (auto entry : it) {
    if (ec) {
      err << "Specified directory '" << path.generic_string()
          << "' for workspace is not iterable: " << ec.message();
      return err.str();
    } else {
      break;
    }
  }

  return path;
}

}  // namespace

extern "C" int main(int argc, char *argv[]) {
  pasta::InitPasta init_pasta;

  std::stringstream ss;
  ss << "Usage: " << argv[0]
     << " [--host HOST] [--port PORT] [--num_workers N]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  if (FLAGS_host.empty()) {
    std::cerr
        << "Hostname of " << argv[0] << " cannot be empty; specify it with --host";
    return EXIT_FAILURE;
  }

  if (FLAGS_port.empty()) {
    std::cerr
        << "Port of " << argv[0] << " cannot be empty; specify it with --port";
    return EXIT_FAILURE;
  }

  auto workspace_dir = TryGetWorkspaceDir(FLAGS_workspace_dir);
  if (!workspace_dir.Succeeded()) {
    std::cerr << workspace_dir.TakeError();
    return EXIT_FAILURE;
  }

  indexer::ServerOptions options;
  options.workspace_dir = workspace_dir.TakeValue();
  options.show_progress_bars = FLAGS_show_progress;
  options.executor_options.num_workers = FLAGS_num_workers;

  // Set up a server.
  capnp::EzRpcServer server(kj::heap<indexer::Server>(options),
                            FLAGS_host + ':' + FLAGS_port);

  // Write the port number to stdout, in case it was chosen automatically.
  kj::WaitScope &wait_scope = server.getWaitScope();
  uint port = server.getPort().wait(wait_scope);
  if (port == 0) {
    // The address format "unix:/path/to/socket" opens a unix domain socket,
    // in which case the port will be zero.
    LOG(INFO) << "Listening on Unix socket " << FLAGS_port;
  } else {
    LOG(INFO) << "Listening on port " << FLAGS_port << " of " << FLAGS_host;
  }

  // Run forever, accepting connections and handling requests.
  kj::NEVER_DONE.wait(wait_scope);
  return EXIT_SUCCESS;
}
