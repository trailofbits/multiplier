// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <atomic>
#include <cstdlib>
#include <thread>
#include <vector>

#include <gflags/gflags.h>
#include <glog/logging.h>

#include <multiplier/Action.h>
#include <multiplier/Executor.h>
#include <multiplier/Datalog.h>
#include <multiplier/Signal.h>
#include <multiplier/Tool.h>

#include <pasta/Util/Init.h>

DECLARE_bool(help);
DEFINE_string(host, "localhost", "Hostname of mx-server");
DEFINE_uint32(port, 50051, "Port of mx-server");
DEFINE_int32(num_workers, -1, "Number of worker threads to use for parallel jobs");

namespace mx {
namespace {

static hyde::rt::ClientResultStream<DatalogClientMessage> *gUpdates{nullptr};

}  // namespace

namespace {

std::atomic<bool> gShouldStop{false};

static void StopFromSignal(int) {
  if (!gShouldStop.exchange(true)) {
    LOG(INFO) << "Received signal to stop";
    if (gUpdates) {
      gUpdates->Kill();
    }
  }
}

}  // namespace

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
    LOG(ERROR)
        << "Hostname of mx-server cannot be empty; specify it with --host";
    return EXIT_FAILURE;
  }

  if (!FLAGS_port) {
    LOG(ERROR)
        << "Port of mx-server cannot be zero; specify it with --port";
    return EXIT_FAILURE;
  }

  std::stringstream hp;
  hp << FLAGS_host << ':' << FLAGS_port;
  const auto host_port = hp.str();
  const auto creds = grpc::InsecureChannelCredentials();
  grpc::ChannelArguments args;
  args.SetMaxSendMessageSize(std::numeric_limits<int>::max());
  args.SetMaxReceiveMessageSize(std::numeric_limits<int>::max());
  args.SetCompressionAlgorithm(GRPC_COMPRESS_STREAM_GZIP);

  // Make three separate channels; we expect very different access patterns for
  // incoming updates, outgoing updates, and for general usage.
  auto send_channel = grpc::CreateCustomChannel(host_port, creds, args);
  auto recv_channel = grpc::CreateCustomChannel(host_port, creds, args);
  auto query_channel = grpc::CreateCustomChannel(host_port, creds, args);

  if (!recv_channel || !recv_channel || !query_channel) {
    LOG(ERROR)
        << "Failed to connect to mx-sever at " << host_port;
    return EXIT_FAILURE;
  }

  CHECK_NE(send_channel.get(), recv_channel.get());
  CHECK_NE(send_channel.get(), query_channel.get());
  CHECK_NE(recv_channel.get(), query_channel.get());

  DatalogClient client(std::move(send_channel),
                       std::move(recv_channel),
                       std::move(query_channel));

  mx::Signal::AddAsyncObserver(SIGINT, StopFromSignal);
  mx::Signal::AddAsyncObserver(SIGQUIT, StopFromSignal);
  mx::Signal::AddAsyncObserver(SIGTERM, StopFromSignal);

  ExecutorOptions options;
  options.num_workers = FLAGS_num_workers;
  Executor executor(options);
  executor.Start();

  LOG(INFO) << "Connecting to mx-server";

  // NOTE(pag): It is critical to open the request for updates prior to
  //            starting any tools. The key point being that some tools
  //            may make queries or publish information when started, and so
  //            by opening this request now, we prevent a sort of lost update
  //            problem, because we know that after all the tools have started,
  //            we will possibly have pending updates buffered.
  hyde::rt::ClientResultStream<DatalogClientMessage> updates =
      client.Subscribe(argv[0]);

  LOG(INFO) << "Connected to mx-server";

  gUpdates = &updates;

  LOG(INFO) << "Starting tools";
  Tool::StartAll(executor, client);

  uint64_t iteration = 0;
  LOG(INFO) << "Starting iteration";
  for (const std::shared_ptr<DatalogClientMessage> &message : updates) {

    LOG(INFO) << "Iteration " << iteration << " started";
    Tool::UpdateAll(message);
    LOG(INFO) << "Iteration " << iteration << " done";

    ++iteration;

    if (gShouldStop.load()) {
      LOG(INFO)
          << "Signal to stop was received while processing updates";
      break;
    }
  }

  LOG(INFO) << "Stopping tools";

  Tool::StopAll();

  executor.Wait();

  Signal::ClearAllObservers();

  Tool::DestroyAll();

  return EXIT_SUCCESS;
}

}  // namespace mx
