// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <filesystem>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/InitLLVM.h>
#include <llvm/Support/JSON.h>
#include <llvm/Support/MemoryBuffer.h>
#include <memory>
#include <multiplier/Result.h>
#include <pasta/Util/FileManager.h>
#include <pasta/Util/Init.h>
#include <sstream>
#include <system_error>

#include "Context.h"
#include "Importer.h"
#include "Parser.h"

// Should we show a help message?
DECLARE_bool(help);

// Number of threads to use in the executors. These are mostly used for indexing
// jobs.
DEFINE_int32(num_workers, -1, "Number of worker threads to use for parallel jobs");

// Should we show progress bars when indexing?
DEFINE_bool(show_progress, false, "Show indexing progress bars");

// Directory where stuff SQLite database is stored.
DEFINE_string(db, "mx-index.db",
              "Path to the database file into which semi-permanent indexer data "
              "should be stored. Defaults mx-index.db in the current working directory.");

DEFINE_string(target, "", "Path to the binary or JSON (compile commands) file to import");

DEFINE_string(env, "", "Path to the file listing environment variables to import");

DEFINE_bool(generate_sourceir, false, "Generate SourceIR from the top-level declarations");

DEFINE_bool(attach, false, "Print out the process ID for attaching gdb/lldb.");

namespace {

std::unique_ptr<llvm::MemoryBuffer>
ReadFileBuffer(const std::string file_name) {
  if (!file_name.empty()) {
    auto maybe_envp = llvm::MemoryBuffer::getFileOrSTDIN(file_name, -1, false);
    if (maybe_envp) {
      return std::move(*maybe_envp);
    }
  }
  return nullptr;
}

indexer::EnvVariableMap ParseEnvVariablesFromFile(const std::string file_name) {
  indexer::EnvVariableMap envp;

  // Check if the file buffer is valid
  if (auto envp_buffer = ReadFileBuffer(file_name); envp_buffer) {
    auto ss = std::stringstream{envp_buffer->getBuffer().str()};
    for (std::string line; std::getline(ss, line, '\n');) {
      if (auto loc = line.find('='); loc != std::string::npos) {
        envp.emplace(line.substr(0, loc), line.substr(loc + 1, line.size()));
      }
    }
  }
  return envp;
}

// TODO(pag): Eventually patch PASTA to have an environment variable provider
//            so we don't need this.
static void ClearEnvironmentVars(char *envp[]) {
  std::vector<std::string> existing_env_vars;
  for (auto i = 0u; envp[i]; ++i) {
    if (auto eq = strchr(envp[i], '=')) {
      existing_env_vars.emplace_back(
          envp[i],
          static_cast<size_t>(eq - envp[i]));
    }
  }
  for (const std::string &var : existing_env_vars) {
    if (!unsetenv(var.c_str())) {
      DLOG(INFO)
          << "Cleared old environment variable '" << var << "'";
    }
  }
}

}  // namespace

extern "C" int main(int argc, char *argv[], char *envp[]) {
  pasta::InitPasta init_pasta;

  std::stringstream ss;
  ss << "Usage: " << argv[0]
     << " [--num_workers N]\n"
     << " [--env PATH_TO_COPIED_ENV_VARS]\n"
     << " [--show_progress]\n"
     << " [--generate_sourceir]\n"
     << " --db DATABASE\n"
     << " --target COMPILE_COMMANDS\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  if (FLAGS_db.empty()) {
    std::cerr
        << "Database path cannot be empty; specify it with --db";
    return EXIT_FAILURE;
  }

  if (FLAGS_target.empty()) {
    std::cerr
        << "Must specify a path to a target file to import with --target. "
           "Use - or /dev/stdin to read from stdin.";
    return EXIT_FAILURE;
  }

  indexer::Executor executor{{FLAGS_num_workers}};
  mx::DatabaseWriter database(FLAGS_db);
  auto ic = std::make_shared<indexer::GlobalIndexingState>(database, executor);
  auto fs = pasta::FileSystem::CreateNative();
  pasta::FileManager fm(fs);

  if (FLAGS_show_progress) {
    ic->InitializeProgressBars();
  }

  if (!FLAGS_generate_sourceir) {
    ic->codegen.Disable();
  }

  std::filesystem::path path(FLAGS_target);

  if (FLAGS_target == "/dev/stdin") {
    FLAGS_target = "-";
  
  } else if (FLAGS_target == "-") {
    path = "/dev/stdin";
  }

  auto maybe_buff = llvm::MemoryBuffer::getFileOrSTDIN(FLAGS_target, -1, false);
  if (!maybe_buff) {
    std::cerr
        << "Unable to open file " << FLAGS_target << ":"
        << maybe_buff.getError().message();
    return EXIT_FAILURE;
  }

  if (!FLAGS_env.empty()) {
    ClearEnvironmentVars(envp);
  }

  indexer::EnvVariableMap env = ParseEnvVariablesFromFile(FLAGS_env);
  for (const auto &[key, val] : env) {
    if (key == "=") {
      if (!setenv("=", argv[0], true)) {
        DLOG(INFO) << "Set environment variable '" << key << "' to: " << val;
      }
    } else if (!setenv(key.c_str(), val.c_str(), true)) {
      DLOG(INFO) << "Set environment variable '" << key << "' to: " << val;
    }
  }

  llvm::LLVMContext context;
  indexer::Importer importer(path.parent_path(), fm, ic);
  indexer::Parser parser(context, importer);
  if (!parser.Parse(*maybe_buff.get(), env)) {
    std::cerr
          << "An error occurred when trying to import " << FLAGS_target;
    return EXIT_FAILURE;
  }

  importer.Import(executor);

  // Sometimes bugs don't reproduce in debuggers, e.g. due to the environment
  // variables or something else being different. This gives us the possibility
  // to late-attach a debugger before anything interesting happens.
  if (FLAGS_attach) {
    std::cout << "Process ID: " << getpid() << "\nPress enter: \n";
    std::cout.flush();
    char x;
    read(0, &x, 1);
  }

  executor.Start();
  executor.Wait();

  return EXIT_SUCCESS;
}
