// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/API.h>
#include <capnp/ez-rpc.h>
#include <kj/async.h>
#include <sstream>
#include <thread>
#include <iostream>

#include <multiplier/RPC.capnp.h>

namespace mx {

EntityProvider::~EntityProvider(void) {}

RemoteEntityProvider::RemoteEntityProvider(RemoteEntityProviderImpl *impl_)
      : impl(impl_) {}

RemoteEntityProvider::~RemoteEntityProvider(void) {}

class RemoteEntityProviderImpl {
 public:
  capnp::EzRpcClient client;
  mx::rpc::Multiplier::Client multiplier;

  RemoteEntityProviderImpl(std::string host, std::string port)
      : client(host + ':' + port),
        multiplier(client.getMain<mx::rpc::Multiplier>()) {}
};

std::shared_ptr<EntityProvider> RemoteEntityProvider::Create(
      std::string host, std::string port) {
  return std::make_shared<RemoteEntityProvider>(
      new RemoteEntityProviderImpl(std::move(host), std::move(port)));
}

using FileListResults =
    capnp::Response<mx::rpc::Multiplier::DownloadFileListResults>;

// Get the current list of parsed files, where the minimum ID
// in the returned list of fetched files will be `start_at`.
std::set<std::pair<std::filesystem::path, FileId>>
RemoteEntityProvider::list_files(void) const {
  auto self = impl.get();
  
  capnp::Request<mx::rpc::Multiplier::DownloadFileListParams,
                 mx::rpc::Multiplier::DownloadFileListResults>
      request = self->multiplier.downloadFileListRequest();
  capnp::Response<mx::rpc::Multiplier::DownloadFileListResults> response =
      request.send().wait(impl->client.getWaitScope());

  std::set<std::pair<std::filesystem::path, FileId>> files;
  if (!response.hasFiles()) {
    return files;
  }

  auto files_reader = response.getFiles();
  for (rpc::FileInfo::Reader entry : files_reader) {
    const FileId file_id = entry.getId();
    if (!file_id || !entry.hasPath()) {
      continue;
    }

    capnp::Text::Reader path = entry.getPath();
    if (!path.size()) {
      continue;
    }

    files.emplace(path.cStr(), file_id);
  }

  return files;
}

}  // namespace mx
