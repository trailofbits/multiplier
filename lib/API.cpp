// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "API.h"

#include <sstream>
#include <thread>
#include <iostream>

namespace mx {

TokenReaderImpl::~TokenReaderImpl(void) noexcept {}
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
TokenReaderImpl::Ptr InvalidFileImpl::TokenReader(
    const FileImpl::Ptr &self) const {
  return TokenReaderImpl::Ptr(self, &empty_reader);
}

ResponseFileImpl::~ResponseFileImpl(void) noexcept {}

ResponseFileImpl::ResponseFileImpl(
    FileId id_, EntityProvider::Ptr ep_, Response response_)
    : FileImpl(id_, std::move(ep_)),
      response(kj::mv(response_)),
      reader(response.getFile()) {
  if (response.hasFragments()) {
    for (auto frag_id : response.getFragments()) {
      fragments.emplace_back().first = frag_id;
    }
  }
}

// Return a reader for the tokens in the file.
TokenReaderImpl::Ptr ResponseFileImpl::TokenReader(
    const FileImpl::Ptr &self) const {
  return TokenReaderImpl::Ptr(self, static_cast<const TokenReaderImpl *>(this));
}

// Return the number of tokens in the file.
unsigned ResponseFileImpl::NumTokens(void) const noexcept {
  if (!reader.hasTokens()) {
    return 0u;
  } else {
    return reader.getTokens().size();
  }
}

// Return the kind of the Nth token.
TokenKind ResponseFileImpl::NthTokenKind(unsigned index) const {
  auto tokens_list_reader = reader.getTokens();
  if (index < tokens_list_reader.size()) {
    ast::Token::Reader token_reader = tokens_list_reader[index];
    return static_cast<TokenKind>(token_reader.getKind());
  } else {
    return TokenKind::UNKNOWN;
  }
}

// Return the data of the Nth token.
std::string_view ResponseFileImpl::NthTokenData(unsigned index) const {
  auto tokens_list_reader = reader.getTokens();
  if (index < tokens_list_reader.size()) {
    ast::Token::Reader token_reader = tokens_list_reader[index];
    if (token_reader.hasData()) {
      capnp::Text::Reader data_reader = token_reader.getData();
      return std::string_view(data_reader.cStr(), data_reader.size());
    }
  }
  return {};
}

// Return the id of the Nth token.
EntityId ResponseFileImpl::NthTokenId(unsigned index) const {
  auto tokens_list_reader = reader.getTokens();
  if (index < tokens_list_reader.size()) {
    ast::Token::Reader token_reader = tokens_list_reader[index];
    if (token_reader.hasData()) {
      FileTokenId id;
      id.file_id = this->id;
      id.kind = static_cast<TokenKind>(token_reader.getKind());
      id.offset = index;
      return id;
    }
  }
  return kInvalidEntityId;
}

FragmentImpl::~FragmentImpl(void) noexcept {}

InvalidFragmentImpl::~InvalidFragmentImpl(void) noexcept {}

FileId InvalidFragmentImpl::FileContaingFirstToken(void) const {
  return kInvalidEntityId;
}

TokenReaderImpl::Ptr InvalidFragmentImpl::TokenReader(
    const FragmentImpl::Ptr &self) const {
  return TokenReaderImpl::Ptr(self, &empty_reader);
}

unsigned InvalidFragmentImpl::FirstLine(void) const {
  return ~0u;
}

unsigned InvalidFragmentImpl::LastLine(void) const {
  return 0u;
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
TokenReaderImpl::Ptr ResponseFragmentImpl::TokenReader(
    const FragmentImpl::Ptr &self) const {
  return TokenReaderImpl::Ptr(self, static_cast<const TokenReaderImpl *>(this));
}

// Return the number of tokens in the file.
unsigned ResponseFragmentImpl::NumTokens(void) const noexcept {
  if (!reader.hasEntities()) {
    return 0u;
  }

  ast::EntityList::Reader entities = reader.getEntities();
  if (!entities.hasToken()) {
    return 0u;
  }

  return entities.getToken().size();
}

// Return the kind of the Nth token.
TokenKind ResponseFragmentImpl::NthTokenKind(unsigned index) const {
  if (reader.hasEntities()) {
    ast::EntityList::Reader entities = reader.getEntities();
    if (entities.hasToken()) {
      auto tokens_list_reader = entities.getToken();
      if (index < tokens_list_reader.size()) {
        ast::Token::Reader token_reader = tokens_list_reader[index];
        return static_cast<TokenKind>(token_reader.getKind());
      }
    }
  }
  return TokenKind::UNKNOWN;
}

// Return the data of the Nth token.
std::string_view ResponseFragmentImpl::NthTokenData(unsigned index) const {
  if (reader.hasEntities()) {
    ast::EntityList::Reader entities = reader.getEntities();
    if (entities.hasToken()) {
      auto tokens_list_reader = entities.getToken();
      if (index < tokens_list_reader.size()) {
        ast::Token::Reader token_reader = tokens_list_reader[index];
        capnp::Text::Reader data_reader = token_reader.getData();
        return std::string_view(data_reader.cStr(), data_reader.size());
      }
    }
  }
  return {};
}

// Return the id of the Nth token.
EntityId ResponseFragmentImpl::NthTokenId(unsigned index) const {
  if (reader.hasEntities()) {
    ast::EntityList::Reader entities = reader.getEntities();
    if (entities.hasToken()) {
      auto tokens_list_reader = entities.getToken();
      if (index < tokens_list_reader.size()) {
        ast::Token::Reader token_reader = tokens_list_reader[index];
        FragmentTokenId id;
        id.fragment_id = this->id;
        id.offset = index;
        id.kind = static_cast<TokenKind>(token_reader.getKind());
        return id;
      }
    }
  }
  return kInvalidEntityId;
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
std::set<std::pair<std::filesystem::path, FileId>>
RemoteEntityProvider::list_files(void) noexcept {
  capnp::Request<mx::rpc::Multiplier::DownloadFileListParams,
                 mx::rpc::Multiplier::DownloadFileListResults>
      request = multiplier.downloadFileListRequest();
  capnp::Response<mx::rpc::Multiplier::DownloadFileListResults> response =
      request.send().wait(client.getWaitScope());

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

// Download a file by its unique ID.
File RemoteEntityProvider::file(FileId id) noexcept {
  EntityProvider::Ptr self = shared_from_this();

  capnp::Request<mx::rpc::Multiplier::DownloadFileParams,
                 mx::rpc::Multiplier::DownloadFileResults>
  request = multiplier.downloadFileRequest();
  request.setId(id);
  try {
    auto ret = std::make_shared<ResponseFileImpl>(
        id, std::move(self), request.send().wait(client.getWaitScope()));
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

  capnp::Request<mx::rpc::Multiplier::DownloadFragmentParams,
                 mx::rpc::Multiplier::DownloadFragmentResults>
      request = multiplier.downloadFragmentRequest();
  request.setId(id);
  try {
    auto ret = std::make_shared<ResponseFragmentImpl>(
        id, std::move(self), request.send().wait(client.getWaitScope()));
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

// Return the token at index `index`.
Token TokenList::operator[](size_t index) const noexcept {
  if (index >= num_tokens) {
    return Token(std::make_shared<InvalidTokenReaderImpl>(), index);
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

}

// Return the list of top-level declarations in this fragment.
std::vector<Decl> Fragment::declarations(void) const noexcept {
  return {};
}

}  // namespace mx
