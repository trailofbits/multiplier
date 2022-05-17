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
#include "Use.h"
#include "Weggli.h"
#include "../Re2.h"

namespace mx {
namespace {

static thread_local unsigned tClientIndex = 0;

static std::atomic<unsigned> gNextClientIndex;

}  // namespace

// NOTE(pag): Keep in sync with `../bin/Index/LinkRerencesInFragment.cpp`
//            version of the same function.
bool MayHaveRemoteRedeclarations(const mx::Decl &decl) {
  switch (decl.kind()) {
    // Functions.
    case mx::DeclKind::FUNCTION:
    case mx::DeclKind::CXX_METHOD:
    case mx::DeclKind::CXX_DESTRUCTOR:
    case mx::DeclKind::CXX_CONVERSION:
    case mx::DeclKind::CXX_CONSTRUCTOR:
    case mx::DeclKind::CXX_DEDUCTION_GUIDE:
      return true;

    // Variables.
    case mx::DeclKind::VAR:
    case mx::DeclKind::PARM_VAR:
    case mx::DeclKind::OMP_CAPTURED_EXPR:
    case mx::DeclKind::IMPLICIT_PARAM:
    case mx::DeclKind::DECOMPOSITION:
    case mx::DeclKind::VAR_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION:
      if (reinterpret_cast<const VarDecl &>(decl).is_local_variable_declaration()) {
        return false;
      } else {
        return true;
      }

    // Tags.
    case mx::DeclKind::TAG:
    case mx::DeclKind::RECORD:
    case mx::DeclKind::CXX_RECORD:
    case mx::DeclKind::CLASS_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION:
    case mx::DeclKind::ENUM:
      return true;

    // Redeclarable templates.
    case mx::DeclKind::REDECLARABLE_TEMPLATE:
    case mx::DeclKind::FUNCTION_TEMPLATE:
    case mx::DeclKind::CLASS_TEMPLATE:
    case mx::DeclKind::VAR_TEMPLATE:
    case mx::DeclKind::TYPE_ALIAS_TEMPLATE:
      return true;

    default:
      return false;
  }
}

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
    : host_port(host + ':' + port),
      version_number(0) {
  tls_connections.resize(1024);
}

// Cap'n Proto doesn't allow connections to be used in separate threads. This
// returns an `this`-specific, thread-local connection to be used.
RemoteEntityProvider::ClientConnection &RemoteEntityProvider::Connection(
    const Ptr &self) {
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

    capnp::Request<mx::rpc::Multiplier::HelloParams,
                   mx::rpc::Multiplier::HelloResults> hello_req =
        (*cc)->client.helloRequest();

    capnp::Response<mx::rpc::Multiplier::HelloResults> hello_resp =
        hello_req.send().wait((*cc)->connection.getWaitScope());

    MaybeUpdateVersionNumber(self, hello_resp.getVersionNumber());
  }

  return **cc;
}

bool RemoteEntityProvider::MaybeUpdateVersionNumber(
    const Ptr &self, unsigned new_version_number) {
  std::unique_lock<std::mutex> locker(version_number_lock);
  if (version_number < new_version_number) {
    version_number = new_version_number;
    self->VersionNumberChanged(new_version_number);
    return true;
  } else {
    return false;
  }
}

// Return the version number.
unsigned RemoteEntityProvider::VersionNumber(void) {
  std::unique_lock<std::mutex> locker(version_number_lock);
  return version_number;
}

// Update the version number. This is basically a signal to invalidate any
// caches.
void RemoteEntityProvider::VersionNumberChanged(unsigned) {}

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
FilePathList RemoteEntityProvider::ListFiles(const Ptr &self) try {
  ClientConnection &cc = Connection(self);
  capnp::Request<mx::rpc::Multiplier::DownloadFileListParams,
                 mx::rpc::Multiplier::DownloadFileListResults>
      request = cc.client.downloadFileListRequest();
  capnp::Response<mx::rpc::Multiplier::DownloadFileListResults> response =
      request.send().wait(cc.connection.getWaitScope());

  auto resp_version_number = response.getVersionNumber();
  MaybeUpdateVersionNumber(self, resp_version_number);

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

  self->CacheFileList(files, resp_version_number);
  return files;

// TODO(pag): Log something.
} catch (...) {
  return {};
}

// Cache a returned file list.
void RemoteEntityProvider::CacheFileList(const FilePathList &, unsigned) {}

// Download a file by its unique ID.
FileImpl::Ptr RemoteEntityProvider::FileFor(const Ptr &self, FileId id) try {
  ClientConnection &cc = Connection(self);
  capnp::Request<mx::rpc::Multiplier::DownloadFileParams,
                 mx::rpc::Multiplier::DownloadFileResults>
  request = cc.client.downloadFileRequest();
  request.setId(id);

  capnp::Response<mx::rpc::Multiplier::DownloadFileResults> response =
      request.send().wait(cc.connection.getWaitScope());

  auto resp_version_number = response.getVersionNumber();
  MaybeUpdateVersionNumber(self, resp_version_number);

  auto ret = std::make_shared<PackedFileImpl>(id, self, kj::mv(response));
  auto ret_ptr = ret.get();
  return FileImpl::Ptr(std::move(ret), ret_ptr);

// TODO(pag): Log something.
} catch (...) {
  return {};
}

// Download a fragment based off of an entity ID.
FragmentImpl::Ptr RemoteEntityProvider::FragmentFor(
    const Ptr &self, FragmentId id) try {

  ClientConnection &cc = Connection(self);
  capnp::Request<mx::rpc::Multiplier::DownloadFragmentParams,
                 mx::rpc::Multiplier::DownloadFragmentResults>
      request = cc.client.downloadFragmentRequest();
  request.setId(id);

  capnp::Response<mx::rpc::Multiplier::DownloadFragmentResults> response =
      request.send().wait(cc.connection.getWaitScope());

  auto resp_version_number = response.getVersionNumber();
  MaybeUpdateVersionNumber(self, resp_version_number);

  auto ret = std::make_shared<PackedFragmentImpl>(id, self, kj::mv(response));
  auto ret_ptr = ret.get();
  return FragmentImpl::Ptr(std::move(ret), ret_ptr);

// TODO(pag): Log something.
} catch (...) {
  return {};
}

// Run a Weggli query over all files.
WeggliQueryResultImpl::Ptr RemoteEntityProvider::Query(
    const Ptr &self, const WeggliQuery &query) try {

  if (!query.IsValid()) {
    return {};
  }

  ClientConnection &cc = Connection(self);
  capnp::Request<mx::rpc::Multiplier::WeggliQueryFragmentsParams,
                 mx::rpc::Multiplier::WeggliQueryFragmentsResults>
      request = cc.client.weggliQueryFragmentsRequest();
  request.setQuery(kj::heapString(query.Pattern().data(),
                                  query.Pattern().size()));
  request.setIsCpp(query.IsCPlusPlus());

  capnp::Response<mx::rpc::Multiplier::WeggliQueryFragmentsResults> response =
      request.send().wait(cc.connection.getWaitScope());

  auto resp_version_number = response.getVersionNumber();
  MaybeUpdateVersionNumber(self, resp_version_number);

  return std::make_shared<WeggliQueryResultImpl>(
      query, std::move(self), kj::mv(response));

// TODO(pag): Log something.
} catch (...) {
  return {};
}

// Run a regular expression query over all files.
RegexQueryResultImpl::Ptr RemoteEntityProvider::Query(
    const Ptr &self, const RegexQuery &query) try {

  if (!query.IsValid()) {
    return {};
  }

  ClientConnection &cc = Connection(self);
  capnp::Request<mx::rpc::Multiplier::RegexQueryFragmentsParams,
                 mx::rpc::Multiplier::RegexQueryFragmentsResults>
      request = cc.client.regexQueryFragmentsRequest();
  request.setRegex(kj::heapString(query.Pattern().data(),
                                  query.Pattern().size()));

  capnp::Response<mx::rpc::Multiplier::RegexQueryFragmentsResults> response =
      request.send().wait(cc.connection.getWaitScope());

  auto resp_version_number = response.getVersionNumber();
  MaybeUpdateVersionNumber(self, resp_version_number);

  return std::make_shared<RegexQueryResultImpl>(
      query, std::move(self), kj::mv(response));

// TODO(pag): Log something.
} catch (...) {
  return {};
}

// Return the redeclarations of a given declaration.
std::vector<RawEntityId> RemoteEntityProvider::Redeclarations(
    const Ptr &self, RawEntityId eid) try {
  ClientConnection &cc = Connection(self);
  capnp::Request<mx::rpc::Multiplier::FindRedeclarationsParams,
                 mx::rpc::Multiplier::FindRedeclarationsResults>
      request = cc.client.findRedeclarationsRequest();

  request.setDeclId(eid);

  capnp::Response<mx::rpc::Multiplier::FindRedeclarationsResults> response =
      request.send().wait(cc.connection.getWaitScope());

  auto resp_version_number = response.getVersionNumber();
  MaybeUpdateVersionNumber(self, resp_version_number);

  auto redecl_ids_reader = response.getRedeclarationIds();

  std::vector<mx::RawEntityId> redecl_ids;
  redecl_ids.reserve(redecl_ids_reader.size());
  for (auto redecl_id : redecl_ids_reader) {
    redecl_ids.push_back(redecl_id);
  }

  self->CacheRedeclarations(redecl_ids, resp_version_number);
  return redecl_ids;

// TODO(pag): Log something.
} catch (...) {
  return {};
}

// Cache a computed set of redeclarations for a given version number.
void RemoteEntityProvider::CacheRedeclarations(
    const std::vector<RawEntityId> &, unsigned) {}

// Fill out `redecl_ids_out` and `fragmnet_ids_out` with the set of things
// to analyze when looking for uses.
void RemoteEntityProvider::FillUses(
    const Ptr &self, RawEntityId eid, std::vector<RawEntityId> &redecl_ids_out,
    std::vector<FragmentId> &fragment_ids_out) try {

  ClientConnection &cc = Connection(self);

  auto prev_version_number = self->VersionNumber();
  for (auto changed = true; changed; ) {
    changed = false;

    // Request the set of redeclarations for this entity.
    redecl_ids_out = self->Redeclarations(self, eid);

    capnp::Request<mx::rpc::Multiplier::FindUsesParams,
                   mx::rpc::Multiplier::FindUsesResults>
        request = cc.client.findUsesRequest();

    auto i = 0u;
    auto redecl_ids = request.initRedeclarationIds(
        static_cast<unsigned>(redecl_ids_out.size()));
    for (mx::RawEntityId eid : redecl_ids_out) {
      redecl_ids.set(i++, eid);
    }

    capnp::Response<mx::rpc::Multiplier::FindUsesResults> response =
        request.send().wait(cc.connection.getWaitScope());

    // Make sure that we re-try if the version number when we requested the
    // redeclaration IDs is now out-of-date.
    auto resp_version_number = response.getVersionNumber();
    if (MaybeUpdateVersionNumber(self, resp_version_number) ||
        prev_version_number < resp_version_number) {
      prev_version_number = resp_version_number;
      changed = true;
      continue;
    }

    auto fragment_ids_reader = response.getFragmentIds();
    fragment_ids_out.clear();
    fragment_ids_out.reserve(fragment_ids_reader.size());
    for (auto frag_id : fragment_ids_reader) {
      fragment_ids_out.push_back(frag_id);
    }

    self->CacheUses(redecl_ids_out, fragment_ids_out, resp_version_number);
    return;
  }

// TODO(pag): Log something.
} catch (...) {
  redecl_ids_out.clear();
  fragment_ids_out.clear();
}

// Fill out `redecl_ids_out` and `fragmnet_ids_out` with the set of things
// to analyze when looking for references.
void RemoteEntityProvider::FillReferences(
    const Ptr &self, RawEntityId eid, std::vector<RawEntityId> &redecl_ids_out,
    std::vector<FragmentId> &fragment_ids_out) try {

  ClientConnection &cc = Connection(self);

  auto prev_version_number = self->VersionNumber();
  for (auto changed = true; changed; ) {
    changed = false;

    // Request the set of redeclarations for this entity.
    redecl_ids_out = self->Redeclarations(self, eid);

    capnp::Request<mx::rpc::Multiplier::FindReferencesParams,
                   mx::rpc::Multiplier::FindReferencesResults>
        request = cc.client.findReferencesRequest();

    auto i = 0u;
    auto redecl_ids = request.initRedeclarationIds(
        static_cast<unsigned>(redecl_ids_out.size()));
    for (mx::RawEntityId eid : redecl_ids_out) {
      redecl_ids.set(i++, eid);
    }

    capnp::Response<mx::rpc::Multiplier::FindReferencesResults> response =
        request.send().wait(cc.connection.getWaitScope());

    // Make sure that we re-try if the version number when we requested the
    // redeclaration IDs is now out-of-date.
    auto resp_version_number = response.getVersionNumber();
    if (MaybeUpdateVersionNumber(self, resp_version_number) ||
        prev_version_number < resp_version_number) {
      prev_version_number = resp_version_number;
      changed = true;
      continue;
    }

    auto fragment_ids_reader = response.getFragmentIds();
    fragment_ids_out.clear();
    fragment_ids_out.reserve(fragment_ids_reader.size());
    for (auto frag_id : fragment_ids_reader) {
      fragment_ids_out.push_back(frag_id);
    }

    self->CacheReferences(redecl_ids_out, fragment_ids_out, resp_version_number);
    return;
  }

// TODO(pag): Log something.
} catch (...) {
  redecl_ids_out.clear();
  fragment_ids_out.clear();
}

// Cache a returned set of uses for a given set of redeclarations.
void RemoteEntityProvider::CacheUses(
    const std::vector<RawEntityId> &, const std::vector<FragmentId> &,
    unsigned) {}

// Cache a returned set of references for a given set of redeclarations.
void RemoteEntityProvider::CacheReferences(
    const std::vector<RawEntityId> &, const std::vector<FragmentId> &,
    unsigned) {}

InvalidEntityProvider::~InvalidEntityProvider(void) noexcept {}

unsigned InvalidEntityProvider::VersionNumber(void) {
  return 0u;
}

void InvalidEntityProvider::VersionNumberChanged(unsigned) {}

FilePathList InvalidEntityProvider::ListFiles(const Ptr &) {
  return {};
}

void InvalidEntityProvider::CacheFileList(const FilePathList &, unsigned) {}

FileImpl::Ptr InvalidEntityProvider::FileFor(const Ptr &, FileId) {
  return {};
}

FragmentImpl::Ptr InvalidEntityProvider::FragmentFor(const Ptr &, FragmentId) {
  return {};
}

WeggliQueryResultImpl::Ptr InvalidEntityProvider::Query(
    const Ptr &, const WeggliQuery &) {
  return {};
}

RegexQueryResultImpl::Ptr InvalidEntityProvider::Query(
    const Ptr &, const RegexQuery &) {
  return {};
}

std::vector<RawEntityId> InvalidEntityProvider::Redeclarations(
    const Ptr &, RawEntityId) {
  return {};
}

void InvalidEntityProvider::CacheRedeclarations(
    const std::vector<RawEntityId> &, unsigned) {}

void InvalidEntityProvider::CacheUses(
    const std::vector<RawEntityId> &, const std::vector<FragmentId> &,
    unsigned) {}

void InvalidEntityProvider::CacheReferences(
    const std::vector<RawEntityId> &, const std::vector<FragmentId> &,
    unsigned) {}

void InvalidEntityProvider::FillUses(
    const Ptr &, RawEntityId eid,
    std::vector<RawEntityId> &redecl_ids_out,
    std::vector<FragmentId> &fragment_ids_out) {
  redecl_ids_out.clear();
  fragment_ids_out.clear();
}

void InvalidEntityProvider::FillReferences(
    const Ptr &, RawEntityId eid,
    std::vector<RawEntityId> &redecl_ids_out,
    std::vector<FragmentId> &fragment_ids_out) {
  redecl_ids_out.clear();
  fragment_ids_out.clear();
}

Decl DeclIterator::operator*(void) && noexcept {
  return Decl(std::move(impl), index);
}

Decl DeclIterator::operator*(void) const & noexcept {
  return Decl(impl, index);
}

Stmt StmtIterator::operator*(void) && noexcept {
  return Stmt(std::move(impl), index);
}

Stmt StmtIterator::operator*(void) const & noexcept {
  return Stmt(impl, index);
}

Type TypeIterator::operator*(void) && noexcept {
  return Type(std::move(impl), index);
}

Type TypeIterator::operator*(void) const & noexcept {
  return Type(impl, index);
}

EntityId Decl::id(void) const {
  DeclarationId eid;
  eid.fragment_id = fragment->fragment_id;
  eid.is_definition = is_definition();
  eid.kind = kind();
  eid.offset = offset;
  return eid;
}

std::optional<Decl> Decl::definition(void) const {
  for (const Decl &decl : redeclarations()) {
    if (decl.is_definition()) {
      return decl;
    }
  }
  return std::nullopt;
}

std::vector<Decl> Decl::redeclarations(void) const {
  if (!MayHaveRemoteRedeclarations(*this)) {
    return redeclarations_visible_in_translation_unit();
  }

  auto redecl_ids = fragment->ep->Redeclarations(fragment->ep, id());
  if (redecl_ids.empty()) {
    return redeclarations_visible_in_translation_unit();
  }

  std::vector<Decl> redecls;
  redecls.reserve(redecl_ids.size());

  for (mx::RawEntityId eid : redecl_ids) {
    if (auto redecl = fragment->DeclFor(fragment, eid)) {
      redecls.emplace_back(std::move(redecl.value()));
    }
  }

  return redecls;
}

UseRange<DeclUseSelector> Decl::uses(void) const {
  return std::make_shared<UseIteratorImpl>(fragment->ep, *this);
}

ReferenceRange Decl::references(void) const {
  return std::make_shared<ReferenceIteratorImpl>(fragment->ep, *this);
}

DeclIterator Decl::in_internal(const Fragment &fragment) {
  return DeclIterator(
      fragment.impl, 0u, fragment.impl->Fragment().getDeclarations().size());
}

EntityId Stmt::id(void) const {
  StatementId eid;
  eid.fragment_id = fragment->fragment_id;
  eid.kind = kind();
  eid.offset = offset;
  return eid;
}

StmtIterator Stmt::in_internal(const Fragment &fragment) {
  return StmtIterator(
      fragment.impl, 0u, fragment.impl->Fragment().getStatements().size());
}

UseRange<StmtUseSelector> Stmt::uses(void) const {
  return std::make_shared<UseIteratorImpl>(fragment->ep, *this);
}

EntityId Type::id(void) const {
  TypeId eid;
  eid.fragment_id = fragment->fragment_id;
  eid.kind = kind();
  eid.offset = offset;
  return eid;
}

TypeIterator Type::in_internal(const Fragment &fragment) {
  return TypeIterator(
      fragment.impl, 0u, fragment.impl->Fragment().getTypes().size());
}

UseRange<TypeUseSelector> Type::uses(void) const {
  return std::make_shared<UseIteratorImpl>(fragment->ep, *this);
}

}  // namespace mx
