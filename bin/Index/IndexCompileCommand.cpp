// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "IndexCompileCommand.h"

#include <filesystem>
#include <glog/logging.h>
#include <multiplier/Result.h>
#include <multiplier/Types.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Util/ArgumentVector.h>
#include <string>
#include <vector>

#include "Context.h"
#include "IndexCompileJob.h"

namespace indexer {
namespace {

// Get the arguments from the compile command as an argument vector.
static pasta::ArgumentVector GetArguments(const CompileCommandPtr &command) {
  std::vector<std::string> args;
  args.emplace_back(command->CompilerPath()->str());
  if (auto args_vec = command->Arguments()) {
    for (auto arg : *args_vec) {
      args.emplace_back(arg->str());
    }
  }
  return args;
}

}  // namespace

IndexCompileCommandAction::~IndexCompileCommandAction(void) {}

IndexCompileCommandAction::IndexCompileCommandAction(
    std::shared_ptr<Context> context_, CompileCommandPtr command_)
    : context(std::move(context_)),
      progress(context->command_progress),
      command(std::move(command_)) {}

// Run the compile command, which should create a single compile job.
void IndexCompileCommandAction::Run(
    mx::Executor exe, mx::WorkerId worker_id) {

  auto maybe_host_cc = pasta::Compiler::CreateHostCompiler(
      context->file_manager, mx::ToPasta(command->Language()));
  if (!maybe_host_cc.Succeeded()) {
    LOG(ERROR)
        << "Could not create host compiler";
    return;
  }

  auto argv = GetArguments(command);
  auto maybe_cmd = pasta::CompileCommand::CreateFromArguments(
      argv, command->WorkingDirectory()->str());
  if (!maybe_cmd.Succeeded()) {
    LOG(ERROR)
        << "Could not create a compile command for arguments "
        << argv.Join();
    return;
  }

  pasta::CompileCommand cmd = maybe_cmd.TakeValue();
  auto maybe_jobs = maybe_host_cc.TakeValue().CreateJobsForCommand(cmd);
  if (!maybe_jobs.Succeeded()) {
    LOG(ERROR)
        << "Could not create one or more compile jobs from command "
        << cmd.Arguments().Join();
    return;
  }

  for (pasta::CompileJob job : maybe_jobs.TakeValue()) {
    exe.EmplaceAction<IndexCompileJobAction>(context, std::move(job));
  }
}

}  // namespace indexer
