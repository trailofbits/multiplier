// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "API.h"

#include <atomic>
#include <cassert>
#include <sstream>
#include <thread>
#include <iostream>

namespace mx {
namespace {

static thread_local unsigned tClientIndex = 0;

static std::atomic<unsigned> gNextClientIndex;

}  // namespace

TokenReader::~TokenReader(void) noexcept {}
InvalidTokenReaderImpl::~InvalidTokenReaderImpl(void) noexcept {}

// Return the number of tokens accessible to this reader.
unsigned InvalidTokenReaderImpl::NumTokens(void) const noexcept {
  return 0u;
}

// Return the kind of the Nth token.
TokenKind InvalidTokenReaderImpl::NthTokenKind(unsigned) const {
  return TokenKind::UNKNOWN;
}

// Return the data of the Nth token.
std::string_view InvalidTokenReaderImpl::NthTokenData(unsigned) const {
  return {};
}

// Return the id of the Nth token.
EntityId InvalidTokenReaderImpl::NthTokenId(unsigned) const {
  return kInvalidEntityId;
}

FileImpl::~FileImpl(void) noexcept {}

// Return a reader for the tokens in the file.
TokenReader::Ptr InvalidFileImpl::TokenReader(
    const FileImpl::Ptr &self) const {
  return TokenReader::Ptr(self, &empty_reader);
}

ResponseFileImpl::~ResponseFileImpl(void) noexcept {}

ResponseFileImpl::ResponseFileImpl(
    FileId id_, EntityProvider::Ptr ep_, Response response_)
    : FileImpl(id_, std::move(ep_)),
      response(kj::mv(response_)),
      reader(response.getFile()) {

  for (auto frag_id : response.getFragments()) {
    fragments.emplace_back().first = frag_id;
  }
}

// Return a reader for the tokens in the file.
TokenReader::Ptr ResponseFileImpl::TokenReader(
    const FileImpl::Ptr &self) const {
  return TokenReader::Ptr(self, static_cast<const class TokenReader *>(this));
}

// Return the number of tokens in the file.
unsigned ResponseFileImpl::NumTokens(void) const noexcept {
  return reader.getTokens().size();
}

// Return the kind of the Nth token.
TokenKind ResponseFileImpl::NthTokenKind(unsigned index) const {
  auto tokens_list_reader = reader.getTokens();
  ast::Token::Reader token_reader = tokens_list_reader[index];
  return static_cast<TokenKind>(token_reader.getKind());
}

// Return the data of the Nth token.
std::string_view ResponseFileImpl::NthTokenData(unsigned index) const {
  auto tokens_list_reader = reader.getTokens();
  ast::Token::Reader token_reader = tokens_list_reader[index];
  capnp::Text::Reader data_reader = token_reader.getData();
  return std::string_view(data_reader.cStr(), data_reader.size());
}

// Return the id of the Nth token.
EntityId ResponseFileImpl::NthTokenId(unsigned index) const {
  auto tokens_list_reader = reader.getTokens();
  ast::Token::Reader token_reader = tokens_list_reader[index];
  FileTokenId id;
  id.file_id = this->id;
  id.kind = static_cast<TokenKind>(token_reader.getKind());
  id.offset = index;
  return id;
}

FragmentImpl::~FragmentImpl(void) noexcept {}

InvalidFragmentImpl::~InvalidFragmentImpl(void) noexcept {}

FileId InvalidFragmentImpl::FileContaingFirstToken(void) const {
  return kInvalidEntityId;
}

TokenReader::Ptr InvalidFragmentImpl::TokenReader(
    const FragmentImpl::Ptr &self) const {
  return TokenReader::Ptr(self, &empty_reader);
}

unsigned InvalidFragmentImpl::FirstLine(void) const {
  return ~0u;
}

unsigned InvalidFragmentImpl::LastLine(void) const {
  return 0u;
}

NodeReader InvalidFragmentImpl::Nodes(void) const {
  return {};
}

TokenSubstitutionsReader InvalidFragmentImpl::Substitutions(void) const {
  return {};
}

EntityListReader InvalidFragmentImpl::Entities(void) const {
  return {};
}

ResponseFragmentImpl::~ResponseFragmentImpl(void) noexcept {}

ResponseFragmentImpl::ResponseFragmentImpl(FragmentId id_,
                                           EntityProvider::Ptr ep_,
                                           Response response_)
    : FragmentImpl(id_, std::move(ep_)),
      response(kj::mv(response_)),
      reader(response.getFragment()) {}

// Return the ID of the file containing the first token.
FileId ResponseFragmentImpl::FileContaingFirstToken(void) const {
  EntityId id(reader.getFileTokenId());
  if (VariantId unpacked_id = id.Unpack();
      std::holds_alternative<FileTokenId>(unpacked_id)) {
    return std::get<FileTokenId>(unpacked_id).file_id;
  } else {
    return kInvalidEntityId;
  }
}

unsigned ResponseFragmentImpl::FirstLine(void) const {
  return reader.getFirstLine();
}

unsigned ResponseFragmentImpl::LastLine(void) const {
  return reader.getLastLine();
}

// Return a reader for the parsed tokens in the fragment. This doesn't
// include all tokens, i.e. macro use tokens, comments, etc.
TokenReader::Ptr ResponseFragmentImpl::TokenReader(
    const FragmentImpl::Ptr &self) const {
  return TokenReader::Ptr(self, static_cast<const class TokenReader *>(this));
}

// Return the number of tokens in the file.
unsigned ResponseFragmentImpl::NumTokens(void) const noexcept {
  ast::EntityList::Reader entities = reader.getEntities();
  return entities.getToken().size();
}

// Return the kind of the Nth token.
TokenKind ResponseFragmentImpl::NthTokenKind(unsigned index) const {
  ast::EntityList::Reader entities = reader.getEntities();
  auto tokens_list_reader = entities.getToken();
  ast::Token::Reader token_reader = tokens_list_reader[index];
  return static_cast<TokenKind>(token_reader.getKind());
}

// Return the data of the Nth token.
std::string_view ResponseFragmentImpl::NthTokenData(unsigned index) const {
  ast::EntityList::Reader entities = reader.getEntities();
  auto tokens_list_reader = entities.getToken();
  ast::Token::Reader token_reader = tokens_list_reader[index];
  capnp::Text::Reader data_reader = token_reader.getData();
  return std::string_view(data_reader.cStr(), data_reader.size());
}

// Return the id of the Nth token.
EntityId ResponseFragmentImpl::NthTokenId(unsigned index) const {
  ast::EntityList::Reader entities = reader.getEntities();
  auto tokens_list_reader = entities.getToken();
  ast::Token::Reader token_reader = tokens_list_reader[index];
  FragmentTokenId id;
  id.fragment_id = this->id;
  id.offset = index;
  id.kind = static_cast<TokenKind>(token_reader.getKind());
  return id;
}

// Return a reader for token nodes.
NodeReader ResponseFragmentImpl::Nodes(void) const {
  return reader.getTokens();
}

// Return a reader for token substitutions.
TokenSubstitutionsReader ResponseFragmentImpl::Substitutions(void) const {
  return reader.getTokenSubstitutions();
}

// Return a reader for the entities in this fragment.
EntityListReader ResponseFragmentImpl::Entities(void) const {
  return reader.getEntities();
}

EntityProvider::~EntityProvider(void) noexcept {}

// Download a fragment based off of an entity ID.
Fragment EntityProvider::fragment_containing(EntityId id) noexcept {
  mx::VariantId opt_id = id.Unpack();
  if (std::holds_alternative<mx::DeclarationId>(opt_id)) {
    return this->fragment(
        std::get<mx::DeclarationId>(opt_id).fragment_id);

  } else if (std::holds_alternative<mx::StatementId>(opt_id)) {
    return this->fragment(
        std::get<mx::StatementId>(opt_id).fragment_id);

  } else if (std::holds_alternative<mx::FragmentTokenId>(opt_id)) {
    return this->fragment(
        std::get<mx::FragmentTokenId>(opt_id).fragment_id);

  } else {
    auto ret = std::make_shared<InvalidFragmentImpl>(id, shared_from_this());
    auto ret_ptr = ret.get();
    return Fragment(FragmentImpl::Ptr(std::move(ret), ret_ptr));
  }
}

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
FileList RemoteEntityProvider::list_files(void) noexcept {
  ClientConnection &cc = Connection();
  capnp::Request<mx::rpc::Multiplier::DownloadFileListParams,
                 mx::rpc::Multiplier::DownloadFileListResults>
      request = cc.client.downloadFileListRequest();
  capnp::Response<mx::rpc::Multiplier::DownloadFileListResults> response =
      request.send().wait(cc.connection.getWaitScope());

  FileList files;
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
File RemoteEntityProvider::file(FileId id) noexcept {
  EntityProvider::Ptr self = shared_from_this();

  ClientConnection &cc = Connection();
  capnp::Request<mx::rpc::Multiplier::DownloadFileParams,
                 mx::rpc::Multiplier::DownloadFileResults>
  request = cc.client.downloadFileRequest();
  request.setId(id);
  try {
    auto ret = std::make_shared<ResponseFileImpl>(
        id, std::move(self), request.send().wait(cc.connection.getWaitScope()));
    auto ret_ptr = ret.get();
    return File(FileImpl::Ptr(std::move(ret), ret_ptr));

  // TODO(pag): Log something.
  } catch (...) {
    auto ret = std::make_shared<InvalidFileImpl>(id, std::move(self));
    auto ret_ptr = ret.get();
    return File(FileImpl::Ptr(std::move(ret), ret_ptr));
  }
}

// Download a fragment based off of an entity ID.
Fragment RemoteEntityProvider::fragment(FragmentId id) noexcept {
  EntityProvider::Ptr self = shared_from_this();

  ClientConnection &cc = Connection();
  capnp::Request<mx::rpc::Multiplier::DownloadFragmentParams,
                 mx::rpc::Multiplier::DownloadFragmentResults>
      request = cc.client.downloadFragmentRequest();
  request.setId(id);
  try {
    auto ret = std::make_shared<ResponseFragmentImpl>(
        id, std::move(self), request.send().wait(cc.connection.getWaitScope()));
    auto ret_ptr = ret.get();
    return Fragment(FragmentImpl::Ptr(std::move(ret), ret_ptr));

  // TODO(pag): Log something.
  } catch (...) {
    auto ret = std::make_shared<InvalidFragmentImpl>(id, std::move(self));
    auto ret_ptr = ret.get();
    return Fragment(FragmentImpl::Ptr(std::move(ret), ret_ptr));
  }
}

// Return `true` if this is a valid token.
Token::operator bool(void) const noexcept {
  return !!dynamic_cast<const InvalidTokenReaderImpl *>(impl.get());
}

// Kind of this token.
TokenKind Token::kind(void) const noexcept {
  return impl->NthTokenKind(index);
}

// Return the data of this token.
std::string_view Token::data(void) const noexcept {
  return impl->NthTokenData(index);
}

// Return the ID of this token.
EntityId Token::id(void) const noexcept {
  return impl->NthTokenId(index);
}

// Return the token list containing a particular token.
TokenList TokenList::containing(Token tok) noexcept {
  auto num_tokens = tok.impl->NumTokens();
  return TokenList(std::move(tok.impl), num_tokens);
}

// Return an invalid token.
Token Token::invalid(void) noexcept {
  return Token(std::make_shared<InvalidTokenReaderImpl>(), 0);
}

// Return the token at index `index`.
Token TokenList::operator[](size_t index) const noexcept {
  if (index >= num_tokens) {
    return Token::invalid();
  } else {
    return Token(impl, index);
  }
}

Fragment FileFragmentListIterator::operator*(void) const noexcept {
  auto &wf = impl->fragments[index].second;
  if (auto frag = wf.lock()) {
    frag->containing_file = impl;
    return Fragment(std::move(frag));
  }

  Fragment ret = impl->ep->fragment(impl->fragments[index].first);
  wf = ret.impl;
  ret.impl->containing_file = impl;  // Save the file <-> fragment mapping.
  return ret;
}

// Return the file containing a specific fragment.
File File::containing(const Fragment &fragment) {
  auto &fp = fragment.impl->containing_file;
  if (fp) {
    return File(fp);
  }

  const auto frag_id = fragment.impl->id;
  auto ret = fragment.impl->ep->file(fragment.impl->FileContaingFirstToken());

  // Save the file <-> fragment mapping.
  fp = ret.impl;
  for (auto &[file_frag_id, frag_wp] : fp->fragments) {
    if (frag_id == file_frag_id) {
      frag_wp = fragment.impl;
      break;
    }
  }

  return ret;
}

// Return `true` if this is a valid file.
File::operator bool(void) const noexcept {
  return !dynamic_cast<const InvalidFileImpl *>(impl.get());
}

// Return the ID of this file.
FileId File::id(void) const noexcept {
  return impl->id;
}

// Return the list of tokens in this file.
TokenList File::tokens(void) const noexcept {
  auto tokens = impl->TokenReader(impl);
  auto num_tokens = tokens->NumTokens();
  return TokenList(std::move(tokens), num_tokens);
}

// Return the list of fragments in this file.
FileFragmentList File::fragments(void) const noexcept {
  return FileFragmentList(impl, static_cast<unsigned>(impl->fragments.size()));
}

// Return `true` if this is a valid fragment.
Fragment::operator bool(void) const noexcept {
  return !dynamic_cast<const InvalidFragmentImpl *>(impl.get());
}

// Return the ID of this fragment.
FragmentId Fragment::id(void) const noexcept {
  return impl->id;
}

// The smallest line of the file for which one of the tokens from this
// fragment resides.
unsigned Fragment::first_line(void) const noexcept {
  return impl->FirstLine();
}

// The largest line of the file for which one of the tokens from this
// fragment resides.
unsigned Fragment::last_line(void) const noexcept {
  return impl->LastLine();
}

// Return the list of parsed tokens in the fragment. This doesn't
// include all tokens, i.e. macro use tokens, comments, etc.
TokenList Fragment::tokens(void) const noexcept {
  auto tokens = impl->TokenReader(impl);
  auto num_tokens = tokens->NumTokens();
  return TokenList(std::move(tokens), num_tokens);
}

// Return the list of token substitutions.
TokenSubstitutionList Fragment::unparsed_tokens(void) const noexcept {
  auto ret = std::make_shared<const TokenSubstitutionListImpl>(impl);
  auto num_nodes = ret->nodes.size();
  return TokenSubstitutionList(std::move(ret), num_nodes);
}

// Return the list of top-level declarations in this fragment.
std::vector<Decl> Fragment::declarations(void) const noexcept {
  return {};
}

std::variant<Token, TokenSubstitution>
TokenSubstitutionListIterator::operator*(void) const noexcept {
  VariantId id = EntityId(impl->nodes[index]).Unpack();

  if (std::holds_alternative<FragmentTokenId>(id)) {
    auto tok = std::get<FragmentTokenId>(id);
    return Token(impl->fragment->TokenReader(impl->fragment), tok.offset);

  } else if (std::holds_alternative<FileTokenId>(id)) {
    auto tok = std::get<FileTokenId>(id);
    auto file = File::containing(impl->fragment);
    return Token(file.impl->TokenReader(file.impl), tok.offset);

  } else if (std::holds_alternative<TokenSubstitutionId>(id)) {
    auto sub = std::get<TokenSubstitutionId>(id);
    assert(sub.fragment_id == impl->fragment->id);
    return TokenSubstitution(impl->fragment, sub.offset, sub.kind);

  } else {
    assert(false);
    __builtin_unreachable();
  }
}

TokenSubstitutionListImpl::TokenSubstitutionListImpl(
    std::shared_ptr<const FragmentImpl> fragment_)
    : fragment(std::move(fragment_)),
      nodes(fragment->Nodes()) {}

TokenSubstitutionListImpl::TokenSubstitutionListImpl(
    std::shared_ptr<const FragmentImpl> fragment_, unsigned offset, BeforeTag)
    : fragment(std::move(fragment_)),
      nodes(fragment->Substitutions()[offset].getBeforeTokens()) {}

TokenSubstitutionListImpl::TokenSubstitutionListImpl(
    std::shared_ptr<const FragmentImpl> fragment_, unsigned offset, AfterTag)
    : fragment(std::move(fragment_)),
      nodes(fragment->Substitutions()[offset].getAfterTokens()) {}

TokenSubstitutionList TokenSubstitution::before(void) const noexcept {
  auto ret = std::make_shared<const TokenSubstitutionListImpl>(
      impl, offset, BeforeTag{});
  auto num_nodes = ret->nodes.size();
  return TokenSubstitutionList(std::move(ret), num_nodes);
}

TokenSubstitutionList TokenSubstitution::after(void) const noexcept {
  auto ret = std::make_shared<const TokenSubstitutionListImpl>(
      impl, offset, AfterTag{});
  auto num_nodes = ret->nodes.size();
  return TokenSubstitutionList(std::move(ret), num_nodes);
}

}  // namespace mx
