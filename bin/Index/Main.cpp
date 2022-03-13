// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <atomic>
#include <cstdlib>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

#include <capnp/ez-rpc.h>
#include <capnp/message.h>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <kj/async-io.h>
#include <kj/debug.h>
#include <multiplier/Action.h>
#include <multiplier/Executor.h>
#include <multiplier/RPC.capnp.h>
#include <multiplier/Signal.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/Init.h>
#include <pasta/Util/FileManager.h>
#include <pasta/Util/FileSystem.h>
#include <pasta/Util/Result.h>

#include "Context.h"
#include "IndexCompileJob.h"

DECLARE_bool(help);
DEFINE_string(host, "localhost", "Hostname of mx-server. Use 'unix' for a UNIX domain socket.");
DEFINE_string(port, "50051", "Port of mx-server. Use a path and 'unix' for the host for a UNIX domain socket.");
DEFINE_int32(num_workers, -1, "Number of worker threads to use for parallel jobs");

namespace indexer {
namespace {

static mx::ExecutorOptions ExecutorOptions(void) {
  mx::ExecutorOptions options;
  options.num_workers = FLAGS_num_workers;
  return options;
}

// Get the arguments from the compile command as an argument vector.
static pasta::ArgumentVector GetArguments(
    const mx::rpc::CompileCommand::Reader &command) {

  std::vector<std::string> args;
  args.emplace_back(command.getCompilerPath());
  for (auto arg : command.getArguments()) {
    args.emplace_back(arg);
  }
  return args;
}

}  // namespace

class Server final : public mx::rpc::Multiplier::Server {
 private:
  // Worker pool for processing various commands and such.
  mx::Executor executor;

  std::mutex indexing_context_lock;
  std::weak_ptr<IndexingContext> indexing_context;

  // Get or create an indexing context. If there are concurrent indexing
  // jobs underway then they'll share the same context. When they're all done
  // the context will go away as well.
  std::shared_ptr<IndexingContext> GetOrCreateIndexingContext(void);

 public:
  virtual ~Server(void);

  Server(void);

  // Enqueue actions to index zero or more compile commands / jobs.
  kj::Promise<void> indexCompileCommands(
      IndexCompileCommandsContext context) final;
};

Server::~Server(void) {}

Server::Server(void)
    : executor(ExecutorOptions()) {
  executor.Start();
}

// Get or create an indexing context. If there are concurrent indexing
// jobs underway then they'll share the same context. When they're all done
// the context will go away as well.
std::shared_ptr<IndexingContext> Server::GetOrCreateIndexingContext(void) {
  std::unique_lock<std::mutex> locker(indexing_context_lock);
  auto ic = indexing_context.lock();
  if (ic) {
    return ic;
  } else {
    ic = std::make_shared<IndexingContext>(executor);
    indexing_context = ic;
    return ic;
  }
}

// Enqueue actions to index zero or more compile commands / jobs.
kj::Promise<void> Server::indexCompileCommands(
    IndexCompileCommandsContext context) {

  mx::rpc::Multiplier::IndexCompileCommandsParams::Reader params =
      context.getParams();

  mx::rpc::Multiplier::IndexCompileCommandsResults::Builder results =
      context.getResults();

  if (!params.hasCommands()) {
    LOG(WARNING)
        << "Got request to index with no commands";
    context.setResults(results);
    results.setSuccess(true);
    return kj::READY_NOW;
  }

  auto fs = pasta::FileSystem::CreateNative();
  pasta::FileManager fm(fs);
  auto maybe_cc = pasta::Compiler::CreateHostCompiler(fm, pasta::TargetLanguage::kC);
  auto maybe_cxx = pasta::Compiler::CreateHostCompiler(fm, pasta::TargetLanguage::kCXX);

  if (!maybe_cc.Succeeded()) {
    LOG(ERROR)
        << "Unable to create host C compiler: "
        << maybe_cc.TakeError();

    results.setSuccess(false);
    return kj::READY_NOW;

  } else if (!maybe_cxx.Succeeded()) {
    LOG(ERROR)
        << "Unable to create host C++ compiler: "
        << maybe_cxx.TakeError();

    results.setSuccess(false);
    return kj::READY_NOW;
  }

  auto cc = maybe_cc.TakeValue();
  auto cxx = maybe_cxx.TakeValue();
  auto which_cc = [&cc, &cxx] (mx::ast::TargetLanguage tl) {
    switch (tl) {
      case mx::ast::TargetLanguage::C: return cc;
      case mx::ast::TargetLanguage::CXX: return cxx;
    }
  };

  auto ic = GetOrCreateIndexingContext();
  for (mx::rpc::CompileCommand::Reader command : params.getCommands()) {
    mx::ProgressBarWork command_progress(ic->command_progress.get());

    auto argv = GetArguments(command);

    // NOTE(pag): The command arguments are for a `-cc1` command, and contain
    //            hard-coded
    auto maybe_cmd = pasta::CompileCommand::CreateFromArguments(
        argv, command.getWorkingDirectory());
    if (!maybe_cmd.Succeeded()) {
      LOG(ERROR)
          << "Could not create a compile command for arguments "
          << argv.Join() << ": " << maybe_cmd.TakeError();
      continue;
    }

    auto cmd = maybe_cmd.TakeValue();
    auto maybe_jobs = which_cc(command.getLanguage()).CreateJobsForCommand(cmd);
    if (!maybe_jobs.Succeeded()) {
      LOG(ERROR)
          << "Could not create one or more compile jobs from command "
          << cmd.Arguments().Join() << ": " << maybe_jobs.TakeError();
      continue;
    }

    for (pasta::CompileJob job : maybe_jobs.TakeValue()) {
      DLOG(INFO)
          << "Enqueuing indexing job for main source file "
          << job.SourceFile().Path().generic_string();
      executor.EmplaceAction<IndexCompileJobAction>(ic, fm, std::move(job));
    }
  }

  results.setSuccess(true);
  return kj::READY_NOW;
}

}  // namespace indexer

extern "C" int main(int argc, char *argv[]) {
  pasta::InitPasta init_pasta;

  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
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
        << "Hostname of mx-server cannot be empty; specify it with --host";
    return EXIT_FAILURE;
  }

  if (FLAGS_port.empty()) {
    std::cerr
        << "Port of mx-server cannot be empty; specify it with --port";
    return EXIT_FAILURE;
  }

  mx::ExecutorOptions options;
  options.num_workers = FLAGS_num_workers;
  mx::Executor executor(options);
  executor.Start();


  // Set up a server.
  capnp::EzRpcServer server(kj::heap<indexer::Server>(),
                            FLAGS_host + ':' + FLAGS_port);

  // Write the port number to stdout, in case it was chosen automatically.
  auto& waitScope = server.getWaitScope();
  uint port = server.getPort().wait(waitScope);
  if (port == 0) {
    // The address format "unix:/path/to/socket" opens a unix domain socket,
    // in which case the port will be zero.
    LOG(INFO) << "Listening on Unix socket " << FLAGS_port;
  } else {
    LOG(INFO) << "Listening on port " << FLAGS_port << " of " << FLAGS_host;
  }

  // Run forever, accepting connections and handling requests.
  kj::NEVER_DONE.wait(waitScope);
  return EXIT_SUCCESS;
}
