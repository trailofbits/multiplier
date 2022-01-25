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

#include <llvm/ADT/Triple.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/InitLLVM.h>
#include <llvm/Support/JSON.h>
#include <llvm/Support/MemoryBuffer.h>

#include <gflags/gflags.h>
#include <glog/logging.h>

#include <multiplier/Datalog.h>
#include <multiplier/Tool.h>
#include <multiplier/Types.h>

#include <pasta/Compile/Compiler.h>

#include "Importer.h"
#include "Log.h"
#include "Parser.h"

DECLARE_bool(help);
DEFINE_string(host, "localhost", "Hostname of irene-server");
DEFINE_uint32(port, 50051, "Port of irene-server");
DEFINE_string(path, "", "Path to the binary or JSON file to import");

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

  if (FLAGS_path == "/dev/stdin") {
    FLAGS_path = "-";
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
  importer::Importer importer;
  importer::Parser parser(context, importer);
  if (!parser.Parse(*maybe_buff.get())) {
    std::cerr
          << "An error occurred when trying to import " << FLAGS_path;
    return EXIT_FAILURE;
  }

  grpc::ChannelArguments args;
  args.SetMaxSendMessageSize(std::numeric_limits<int>::max());
  args.SetMaxReceiveMessageSize(std::numeric_limits<int>::max());

  std::stringstream hp;
  hp << FLAGS_host << ':' << FLAGS_port;
  auto channel = grpc::CreateCustomChannel(
      hp.str(), grpc::InsecureChannelCredentials(), args);

  if (!channel) {
    std::cerr << "Failed to connect to irene-sever at " << hp.str();
    return EXIT_FAILURE;
  }

  LOG(INFO)
      << "Publishing binary info to mx-server";

  mx::DatalogClient client(channel, channel, channel);

  importer.Build(client);

  return EXIT_SUCCESS;
}
