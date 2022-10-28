// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdlib>
#include <filesystem>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <memory>
#include <multiplier/Result.h>
#include <pasta/Util/Init.h>
#include <sstream>
#include <system_error>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/InitLLVM.h>
#include <llvm/Support/JSON.h>
#include <llvm/Support/MemoryBuffer.h>

#include "Context.h"
#include "Parser.h"
#include "Importer.h"

// Should we show a help message?
DECLARE_bool(help);

// Number of threads to use in the executors. These are mostly used for indexing
// jobs.
DEFINE_int32(num_workers, -1, "Number of worker threads to use for parallel jobs");

// Should we show progress bars when indexing?
DEFINE_bool(show_progress, false, "Show indexing progress bars");

// Directory where stuff (RocksDB k/v stores, SQLite database) is stored.
DEFINE_string(db_path, "mx-index.db",
              "Path to the database file into which semi-permanent indexer data "
              "should be stored. Defaults mx-index.db.");

DEFINE_string(bin_path, "", "Path to the binary or JSON (compile commands) file to import");

DEFINE_bool(generate_sourceir, false, "Generate SourceIR from the top-level declarations");

extern "C" int main(int argc, char *argv[]) {
  pasta::InitPasta init_pasta;

  std::stringstream ss;
  ss << "Usage: " << argv[0]
     << " [--num_workers N] [--db-path DATABASE] [--bin-path COMPILE_COMMANDS]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  if (FLAGS_db_path.empty()) {
    std::cerr
        << "Database path cannot be empty; specify it with --db-path";
    return EXIT_FAILURE;
  }

  if (FLAGS_bin_path.empty()) {
    std::cerr
        << "Must specify a path to a file. Use - or /dev/stdin to read from stdin.";
    return EXIT_FAILURE;
  }

  mx::Executor executor{{FLAGS_num_workers}};
  auto ic = std::make_shared<indexer::IndexingContext>(FLAGS_db_path, executor);
  auto fs = pasta::FileSystem::CreateNative();
  pasta::FileManager fm(fs);

  if(FLAGS_show_progress) {
    ic->InitializeProgressBars();
  }

  if(!FLAGS_generate_sourceir) {
    ic->codegen.Disable();
  }

  std::filesystem::path path(FLAGS_bin_path);

  if (FLAGS_bin_path == "/dev/stdin") {
    FLAGS_bin_path = "-";
  
  } else if (FLAGS_bin_path == "-") {
    path = "/dev/stdin";
  }

  auto maybe_buff = llvm::MemoryBuffer::getFileOrSTDIN(FLAGS_bin_path, -1, false);
  if (!maybe_buff) {
    std::cerr
        << "Unable to open file " << FLAGS_bin_path << ":"
        << maybe_buff.getError().message();
    return EXIT_FAILURE;
  }

  llvm::LLVMContext context;
  indexer::Importer importer(path.parent_path(), fm, ic);
  indexer::Parser parser(context, importer);
  if (!parser.Parse(*maybe_buff.get())) {
    std::cerr
          << "An error occurred when trying to import " << FLAGS_bin_path;
    return EXIT_FAILURE;
  }

  importer.Import(executor);

  executor.Start();
  executor.Wait();

  return EXIT_SUCCESS;
}
