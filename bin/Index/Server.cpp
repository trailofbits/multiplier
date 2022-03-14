// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Server.h"

#include <capnp/message.h>
#include <kj/async-io.h>
#include <kj/debug.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/FileManager.h>
#include <pasta/Util/FileSystem.h>
#include <pasta/Util/Result.h>
#include <mutex>
#include <vector>

#include "Context.h"
#include "IndexCompileJob.h"

namespace indexer {
namespace {

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

struct Server::Impl final {
 public:
  // Worker pool for processing various commands and such.
  mx::Executor executor;

  // Workspace directory.
  std::filesystem::path workspace_dir;

  // Should we show progress bars?
  const bool show_progress_bars;

  std::mutex indexing_context_lock;
  std::weak_ptr<IndexingContext> indexing_context;

  inline Impl(ServerOptions &options)
      : executor(options.executor_options),
        workspace_dir(options.workspace_dir),
        show_progress_bars(options.show_progress_bars) {}

  // Get or create an indexing context. If there are concurrent indexing
  // jobs underway then they'll share the same context. When they're all done
  // the context will go away as well.
  std::shared_ptr<IndexingContext> GetOrCreateIndexingContext(void);
};

// Get or create an indexing context. If there are concurrent indexing
// jobs underway then they'll share the same context. When they're all done
// the context will go away as well.
std::shared_ptr<IndexingContext>
Server::Impl::GetOrCreateIndexingContext(void) {
  std::unique_lock<std::mutex> locker(indexing_context_lock);
  auto ic = indexing_context.lock();
  if (ic) {
    return ic;
  } else {
    ic = std::make_shared<IndexingContext>(workspace_dir);
    if (show_progress_bars) {
      ic->InitializeProgressBars(executor);
    }
    indexing_context = ic;
    return ic;
  }
}

Server::~Server(void) {
  d->executor.Wait();
}

// Initialize the server.
Server::Server(ServerOptions &options_)
    : d(std::make_unique<Impl>(options_)) {
  d->executor.Start();
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
  auto maybe_cc = pasta::Compiler::CreateHostCompiler(
      fm, pasta::TargetLanguage::kC);
  auto maybe_cxx = pasta::Compiler::CreateHostCompiler(
      fm, pasta::TargetLanguage::kCXX);

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

  auto ic = d->GetOrCreateIndexingContext();
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
      d->executor.EmplaceAction<IndexCompileJobAction>(ic, fm, std::move(job));
    }
  }

  results.setSuccess(true);
  return kj::READY_NOW;
}

}  // namespace indexer
