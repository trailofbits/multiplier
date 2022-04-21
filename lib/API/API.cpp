// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "API.h"

#include <atomic>
#include <cassert>
#include <iostream>
#include <multiplier/Compress.h>
#include <sstream>
#include <stdexcept>
#include <thread>
#include <set>

#include "File.h"
#include "Fragment.h"
#include "Re2.h"
#include "Token.h"
#include "Weggli.h"

namespace mx {
namespace {

static thread_local unsigned tClientIndex = 0;

static std::atomic<unsigned> gNextClientIndex;

}  // namespace

PackedReaderState::PackedReaderState(capnp::Data::Reader data) {
  auto begin = reinterpret_cast<const char *>(data.begin());
  std::string_view untagged_data(begin, data.size() - 1u);

  if (!data.back()) {  // Not compressed, just packed.
    storage.insert(storage.end(), untagged_data.begin(), untagged_data.end());

  } else {  // Compressed and packed.
    auto maybe_uncompressed = TryUncompress(untagged_data);
    if (!maybe_uncompressed.Succeeded()) {
      throw kj::Exception(
          kj::Exception::Type::FAILED, __FILE__, __LINE__,
          kj::heapString(maybe_uncompressed.Error().message().c_str()));

    } else {
      maybe_uncompressed.TakeValue().swap(storage);
    }
  }

  capnp::ReaderOptions options;
  options.traversalLimitInWords = ~0ull;
  stream.emplace(kj::arrayPtr(
      reinterpret_cast<const kj::byte *>(&(storage[0])), storage.size()));
  packed_reader.emplace(stream.value(), options);
}

EntityProvider::~EntityProvider(void) noexcept {}

RemoteEntityProvider::ClientConnection::ClientConnection(const std::string &hp)
    : options{
        .traversalLimitInWords = ~0ull,
        .nestingLimit = 1024
      },
      connection(hp, 0, options),
      client(connection.getMain<mx::rpc::Multiplier>()) {}

RemoteEntityProvider::RemoteEntityProvider(std::string host, std::string port)
    : host_port(host + ':' + port) {
  tls_connections.resize(1024);
}

RemoteEntityProvider::ClientConnection &RemoteEntityProvider::Connection(void) {
  auto &id = tClientIndex;
  std::unique_ptr<ClientConnection> *cc = nullptr;
  {
    std::unique_lock<std::mutex> locker(tls_connections_lock);
    if (!id) {
      id = gNextClientIndex.fetch_add(1u);
      if (id >= tls_connections.size()) {
        tls_connections.resize(id + 1u);
      }
    }

    cc = &(tls_connections[id]);
  }

  if (!*cc) {
    *cc = std::make_unique<ClientConnection>(host_port);
  }

  return **cc;
}

RemoteEntityProvider::~RemoteEntityProvider(void) noexcept {}

// Returns an entity provider that gets entities from a remote host.
EntityProvider::Ptr EntityProvider::from_remote(
    std::string host, std::string port) {
  return std::make_shared<RemoteEntityProvider>(
      std::move(host), std::move(port));
}

// Returns an entity provider that gets entities from a UNIX domain socket.
EntityProvider::Ptr EntityProvider::from_socket(
    std::filesystem::path path) {
  return std::make_shared<RemoteEntityProvider>(
      "unix", path.lexically_normal().generic_string());
}

using FileListResults =
    capnp::Response<mx::rpc::Multiplier::DownloadFileListResults>;

// Get the current list of parsed files, where the minimum ID
// in the returned list of fetched files will be `start_at`.
FilePathList RemoteEntityProvider::ListFiles(void) {
  ClientConnection &cc = Connection();
  capnp::Request<mx::rpc::Multiplier::DownloadFileListParams,
                 mx::rpc::Multiplier::DownloadFileListResults>
      request = cc.client.downloadFileListRequest();
  capnp::Response<mx::rpc::Multiplier::DownloadFileListResults> response =
      request.send().wait(cc.connection.getWaitScope());

  FilePathList files;
  for (rpc::FileInfo::Reader entry : response.getFiles()) {
    const FileId file_id = entry.getId();
    assert(file_id != kInvalidEntityId);
    assert(entry.hasPath());
    capnp::Text::Reader path = entry.getPath();
    assert(0u < path.size());
    std::filesystem::path p(path.cStr());
    files.try_emplace(std::move(p), file_id);
  }

  return files;
}

// Download a file by its unique ID.
FileImpl::Ptr RemoteEntityProvider::FileFor(const Ptr &self, FileId id) {
  ClientConnection &cc = Connection();
  capnp::Request<mx::rpc::Multiplier::DownloadFileParams,
                 mx::rpc::Multiplier::DownloadFileResults>
  request = cc.client.downloadFileRequest();
  request.setId(id);
  try {
    auto ret = std::make_shared<PackedFileImpl>(
        id, self, request.send().wait(cc.connection.getWaitScope()));
    auto ret_ptr = ret.get();
    return FileImpl::Ptr(std::move(ret), ret_ptr);

  // TODO(pag): Log something.
  } catch (...) {
    return {};
  }
}

// Download a fragment based off of an entity ID.
FragmentImpl::Ptr RemoteEntityProvider::FragmentFor(
    const Ptr &self, FragmentId id) {
  ClientConnection &cc = Connection();
  capnp::Request<mx::rpc::Multiplier::DownloadFragmentParams,
                 mx::rpc::Multiplier::DownloadFragmentResults>
      request = cc.client.downloadFragmentRequest();
  request.setId(id);
  try {
    auto ret = std::make_shared<PackedFragmentImpl>(
        id, self, request.send().wait(cc.connection.getWaitScope()));
    auto ret_ptr = ret.get();
    return FragmentImpl::Ptr(std::move(ret), ret_ptr);

  // TODO(pag): Log something.
  } catch (...) {
    return {};
  }
}

WeggliQueryResultImpl::Ptr RemoteEntityProvider::WeggliQuery(
    const Ptr &self, std::string query, bool is_cpp) {
  ClientConnection &cc = Connection();
  capnp::Request<mx::rpc::Multiplier::WeggliQueryParams,
                 mx::rpc::Multiplier::WeggliQueryResults>
      request = cc.client.weggliQueryRequest();
  request.setQuery(query);
  request.setIsCpp(is_cpp);

  try {
    return std::make_shared<WeggliQueryResultImpl>(
        query,
        std::move(self),
        request.send().wait(cc.connection.getWaitScope()),
        is_cpp);

  } catch (...) {
    return {};
  }
}

RegexQueryResultImpl::Ptr RemoteEntityProvider::RegexQuery(
    const Ptr &self, std::string regex) {

  ClientConnection &cc = Connection();
  capnp::Request<mx::rpc::Multiplier::RegexQueryParams,
                 mx::rpc::Multiplier::RegexQueryResults>
      request = cc.client.regexQueryRequest();
  request.setRegex(regex);
  try {
    return std::make_shared<RegexQueryResultImpl>(
        regex,
        std::move(self),
        request.send().wait(cc.connection.getWaitScope()));
  } catch (...) {
    return {};
  }
}

InvalidEntityProvider::~InvalidEntityProvider(void) noexcept {}

// Get the current list of parsed files, where the minimum ID
// in the returned list of fetched files will be `start_at`.
FilePathList InvalidEntityProvider::ListFiles(void) {
  return {};
}

// Download a file by its unique ID.
FileImpl::Ptr InvalidEntityProvider::FileFor(const Ptr &, FileId) {
  return {};
}

// Download a fragment by its unique ID.
FragmentImpl::Ptr InvalidEntityProvider::FragmentFor(const Ptr &, FragmentId) {
  return {};
}

WeggliQueryResultImpl::Ptr InvalidEntityProvider::WeggliQuery(
    const Ptr &, std::string, bool is_cpp) {
  return {};
}

RegexQueryResultImpl::Ptr InvalidEntityProvider::RegexQuery(
    const Ptr &, std::string) {
  return {};
}

Decl DeclIterator::operator*(void) const noexcept {
  return Decl(impl, index);
}

Stmt StmtIterator::operator*(void) const noexcept {
  return Stmt(impl, index);
}

Type TypeIterator::operator*(void) const noexcept {
  return Type(impl, index);
}

DeclIterator Decl::in_internal(const Fragment &fragment) {
  return DeclIterator(
      fragment.impl, 0u, fragment.impl->Fragment().getDeclarations().size());
}

StmtIterator Stmt::in_internal(const Fragment &fragment) {
  return StmtIterator(
      fragment.impl, 0u, fragment.impl->Fragment().getStatements().size());
}

TypeIterator Type::in_internal(const Fragment &fragment) {
  return TypeIterator(
      fragment.impl, 0u, fragment.impl->Fragment().getTypes().size());
}

}  // namespace mx
