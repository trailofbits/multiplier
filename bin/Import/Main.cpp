// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include <capnp/ez-rpc.h>

#include <llvm/ADT/Triple.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/InitLLVM.h>
#include <llvm/Support/JSON.h>
#include <llvm/Support/MemoryBuffer.h>

#include <gflags/gflags.h>
#include <glog/logging.h>

#include <multiplier/RPC.capnp.h>

#include <pasta/Compile/Compiler.h>

#include "Importer.h"
#include "Log.h"
#include "Parser.h"

DECLARE_bool(help);
DEFINE_string(host, "localhost", "Hostname of mx-server. Use 'unix' for a UNIX domain socket.");
DEFINE_string(port, "50051", "Port of mx-server. Use a path and 'unix' for the host for a UNIX domain socket.");
DEFINE_string(path, "", "Path to the binary or JSON (compile commands) file to import");

#include <iostream>

namespace importer {
namespace {

}  // namespace
}  // namespace importer

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT]\n"
    << " --path PATH_TO_BINARY_OR_JSON";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  llvm::InitLLVM init(argc, argv);

  if (1 >= argc || FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }


  std::filesystem::path path(FLAGS_path);

  if (FLAGS_path == "/dev/stdin") {
    FLAGS_path = "-";
  
  } else if (FLAGS_path == "-") {
    path = "/dev/stdin";
  }

  if (FLAGS_path.empty()) {
    std::cerr
        << "Must specify a path to a file. Use - or /dev/stdin to read from stdin.";
    return EXIT_FAILURE;
  }

  auto maybe_buff = llvm::MemoryBuffer::getFileOrSTDIN(FLAGS_path, -1, false);
  if (!maybe_buff) {
    std::cerr
        << "Unable to open file " << FLAGS_path << ":"
        << maybe_buff.getError().message();
    return EXIT_FAILURE;
  }

  llvm::LLVMContext context;
  importer::Importer importer(path.parent_path());
  importer::Parser parser(context, importer);
  if (!parser.Parse(*maybe_buff.get())) {
    std::cerr
          << "An error occurred when trying to import " << FLAGS_path;
    return EXIT_FAILURE;
  }

  capnp::EzRpcClient client(FLAGS_host + ':' + FLAGS_port);
  mx::rpc::Multiplier::Client multiplier = client.getMain<mx::rpc::Multiplier>();

  importer.Build(client, multiplier).wait(client.getWaitScope());

  return EXIT_SUCCESS;
}
