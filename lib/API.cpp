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

namespace mx {
namespace {

static thread_local unsigned tClientIndex = 0;

static std::atomic<unsigned> gNextClientIndex;

static const std::shared_ptr<InvalidTokenReader> kInvalidTokenReader =
    std::make_shared<InvalidTokenReader>();

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

TokenReader::~TokenReader(void) noexcept {}
InvalidTokenReader::~InvalidTokenReader(void) noexcept {}

// Return the number of tokens accessible to this reader.
unsigned InvalidTokenReader::NumTokens(void) const {
  return 0u;
}

// Return the kind of the Nth token.
TokenKind InvalidTokenReader::NthTokenKind(unsigned) const {
  return TokenKind::UNKNOWN;
}

// Return the data of the Nth token.
std::string_view InvalidTokenReader::NthTokenData(unsigned) const {
  return {};
}

// Return the id of the Nth token.
EntityId InvalidTokenReader::NthTokenId(unsigned) const {
  return kInvalidEntityId;
}

FileImpl::~FileImpl(void) noexcept {}

PackedFileImpl::~PackedFileImpl(void) noexcept {}

PackedFileImpl::PackedFileImpl(
    FileId id_, EntityProvider::Ptr ep_, Response response)
    : FileImpl(id_, std::move(ep_)),
      package(response.getFile()),
      reader(package.Reader<rpc::File>()) {

  for (auto frag_id : response.getFragments()) {
    fragments.emplace_back().first = frag_id;
  }
}

// Return a reader for the tokens in the file.
TokenReader::Ptr PackedFileImpl::TokenReader(
    const FileImpl::Ptr &self) const {
  return TokenReader::Ptr(self, static_cast<const class TokenReader *>(this));
}

// Return the number of tokens in the file.
unsigned PackedFileImpl::NumTokens(void) const {
  return reader.getTokens().size();
}

// Return the kind of the Nth token.
TokenKind PackedFileImpl::NthTokenKind(unsigned index) const {
  auto tokens_list_reader = reader.getTokens();
  rpc::Token::Reader token_reader = tokens_list_reader[index];
  return static_cast<TokenKind>(token_reader.getKind());
}

// Return the data of the Nth token.
std::string_view PackedFileImpl::NthTokenData(unsigned index) const {
  auto tokens_list_reader = reader.getTokens();
  rpc::Token::Reader token_reader = tokens_list_reader[index];
  capnp::Text::Reader data_reader = token_reader.getData();
  return std::string_view(data_reader.cStr(), data_reader.size());
}

// Return the id of the Nth token.
EntityId PackedFileImpl::NthTokenId(unsigned index) const {
  auto tokens_list_reader = reader.getTokens();
  rpc::Token::Reader token_reader = tokens_list_reader[index];
  FileTokenId id;
  id.file_id = this->id;
  id.kind = static_cast<TokenKind>(token_reader.getKind());
  id.offset = index;
  return id;
}

FragmentImpl::~FragmentImpl(void) noexcept {}

// Return the token associated with a specific entity ID.
Token FragmentImpl::TokenFor(
    const FragmentImpl::Ptr &self, EntityId id, bool can_fail) const {
  VariantId vid = id.Unpack();

  // It's a fragment token.
  if (std::holds_alternative<FragmentTokenId>(vid)) {
    auto fid = std::get<FragmentTokenId>(vid);

    // It's a token inside of the current fragment.
    if (fid.fragment_id == id) {
      return Token(this->TokenReader(self), fid.offset);

    // It's a token inside of another fragment, go get the other fragment.
    } else {
      auto other_frag = ep->FragmentFor(ep, fid.fragment_id);
      auto reader = other_frag->TokenReader(other_frag);
      return Token(std::move(reader), fid.offset);
    }

  // It's a file token; go get the file.
  } else if (std::holds_alternative<FileTokenId>(vid)) {
    auto fid = std::get<FileTokenId>(vid);
    FileImpl::Ptr file;
    if (containing_file && containing_file->id == fid.file_id) {
      file = containing_file;  // Try to use the containing file if it matches.
    } else {
      file = ep->FileFor(ep, fid.file_id);
    }

    auto reader = file->TokenReader(file);
    return Token(std::move(reader), fid.offset);

  // An invalid ID.
  } else if (std::holds_alternative<InvalidId>(vid)) {
    if (can_fail) {
      return {};
    } else {
      throw std::domain_error(
          "Invalid entity ID passed to FragmentImpl::TokenFor");
    }

  // A non-token ID.
  } else {
    throw std::domain_error(
        "Non-token entity ID passed to FragmentImpl::TokenFor");
  }
}

// Return the inclusive token range associated with two entity IDs.
TokenRange FragmentImpl::TokenRangeFor(
    const FragmentImpl::Ptr &self, EntityId begin_id, EntityId end_id) const {
  VariantId bvid = begin_id.Unpack();
  VariantId evid = end_id.Unpack();

  // It's a fragment token.
  if (std::holds_alternative<FragmentTokenId>(bvid)) {
    if (!std::holds_alternative<FragmentTokenId>(evid)) {
      return TokenRange();
    }

    auto bfid = std::get<FragmentTokenId>(bvid);
    auto efid = std::get<FragmentTokenId>(evid);
    if (bfid.fragment_id != efid.fragment_id ||
        bfid.offset > efid.offset) {
      return TokenRange();
    }

    // It's a token inside of the current fragment.
    if (bfid.fragment_id == id) {
      return TokenRange(this->TokenReader(self), bfid.offset, efid.offset + 1u);

    // It's a token inside of another fragment, go get the other fragment.
    } else {
      auto other_frag = ep->FragmentFor(ep, bfid.fragment_id);
      auto reader = other_frag->TokenReader(other_frag);
      return TokenRange(std::move(reader), bfid.offset, efid.offset + 1u);
    }

  // It's a file token; go get the file.
  } else if (std::holds_alternative<FileTokenId>(bvid)) {
    if (!std::holds_alternative<FileTokenId>(evid)) {
      return TokenRange();
    }

    auto bfid = std::get<FileTokenId>(bvid);
    auto efid = std::get<FileTokenId>(evid);
    if (bfid.file_id != efid.file_id ||
        bfid.offset > efid.offset) {
      return TokenRange();
    }

    FileImpl::Ptr file;
    if (containing_file && containing_file->id == bfid.file_id) {
      file = containing_file;  // Try to use the containing file if it matches.
    } else {
      file = ep->FileFor(ep, bfid.file_id);
    }

    auto reader = file->TokenReader(file);
    return TokenRange(std::move(reader), bfid.offset, efid.offset + 1u);

  // An invalid ID.
  } else if (std::holds_alternative<InvalidId>(bvid) &&
             std::holds_alternative<InvalidId>(evid)) {
    return TokenRange();

  // A non-token ID.
  } else {
    assert(false);
    return TokenRange();
  }
}

// Return the declaration associated with a specific entity ID.
Decl FragmentImpl::DeclFor(const FragmentImpl::Ptr &self, EntityId id) const {
  VariantId vid = id.Unpack();

  // It's a fragment token.
  if (!std::holds_alternative<DeclarationId>(vid)) {
    assert(false);
    abort();
  }

  DeclarationId decl_id = std::get<DeclarationId>(vid);

  // It's a token inside of the current fragment.
  if (decl_id.fragment_id == id) {
    return Decl(self, decl_id.offset);

  // It's a token inside of another fragment, go get the other fragment.
  } else {
    return Decl(ep->FragmentFor(ep, decl_id.fragment_id), decl_id.offset);
  }
}

// Return the statement associated with a specific entity ID.
Stmt FragmentImpl::StmtFor(const FragmentImpl::Ptr &self, EntityId id) const {
  VariantId vid = id.Unpack();

  // It's a fragment token.
  if (!std::holds_alternative<StatementId>(vid)) {
    assert(false);
    abort();
  }

  StatementId stmt_id = std::get<StatementId>(vid);

  // It's a token inside of the current fragment.
  if (stmt_id.fragment_id == id) {
    return Stmt(self, stmt_id.offset);

  // It's a token inside of another fragment, go get the other fragment.
  } else {
    return Stmt(ep->FragmentFor(ep, stmt_id.fragment_id), stmt_id.offset);
  }
}

PackedFragmentImpl::~PackedFragmentImpl(void) noexcept {}

PackedFragmentImpl::PackedFragmentImpl(FragmentId id_,
                                       EntityProvider::Ptr ep_,
                                       Response response)
    : FragmentImpl(id_, std::move(ep_)),
      package(response.getFragment()),
      reader(package.Reader<rpc::Fragment>()) {}

// Return the ID of the file containing the first token.
FileId PackedFragmentImpl::FileContaingFirstToken(void) const {
  EntityId id(reader.getFileTokenId());
  if (VariantId unpacked_id = id.Unpack();
      std::holds_alternative<FileTokenId>(unpacked_id)) {
    return std::get<FileTokenId>(unpacked_id).file_id;
  } else {
    return kInvalidEntityId;
  }
}

// Return a reader for the parsed tokens in the fragment. This doesn't
// include all tokens, i.e. macro use tokens, comments, etc.
TokenReader::Ptr PackedFragmentImpl::TokenReader(
    const FragmentImpl::Ptr &self) const {
  return TokenReader::Ptr(self, static_cast<const class TokenReader *>(this));
}

// Return the number of tokens in the file.
unsigned PackedFragmentImpl::NumTokens(void) const {
  return reader.getTokens().size();
}

// Return the kind of the Nth token.
TokenKind PackedFragmentImpl::NthTokenKind(unsigned index) const {
  auto tokens_list_reader = reader.getTokens();
  rpc::Token::Reader token_reader = tokens_list_reader[index];
  return static_cast<TokenKind>(token_reader.getKind());
}

// Return the data of the Nth token.
std::string_view PackedFragmentImpl::NthTokenData(unsigned index) const {
  auto tokens_list_reader = reader.getTokens();
  rpc::Token::Reader token_reader = tokens_list_reader[index];
  capnp::Text::Reader data_reader = token_reader.getData();
  return std::string_view(data_reader.cStr(), data_reader.size());
}

// Return the id of the Nth token.
EntityId PackedFragmentImpl::NthTokenId(unsigned index) const {
  auto tokens_list_reader = reader.getTokens();
  rpc::Token::Reader token_reader = tokens_list_reader[index];
  FragmentTokenId id;
  id.fragment_id = this->id;
  id.offset = index;
  id.kind = static_cast<TokenKind>(token_reader.getKind());
  return id;
}

// Return a reader for the whole fragment.
const FragmentReader &PackedFragmentImpl::Fragment(void) const {
  return reader;
}

// Return a specific type of entity.
DeclReader PackedFragmentImpl::NthDecl(unsigned offset) const {
  return reader.getDeclarations()[offset];
}

StmtReader PackedFragmentImpl::NthStmt(unsigned offset) const {
  return reader.getStatements()[offset];
}

PseudoReader PackedFragmentImpl::NthPseudo(unsigned offset) const {
  return reader.getOthers()[offset];
}

std::string_view PackedFragmentImpl::SourceIR(void) const {
  if (reader.hasMlir()) {
    return std::string_view(reader.getMlir().cStr(), reader.getMlir().size());
  }
  return {};
}

SyntaxQueryResultImpl::~SyntaxQueryResultImpl(void) noexcept {}

SyntaxQueryResultImpl::SyntaxQueryResultImpl(
    std::string syntax_, EntityProvider::Ptr ep_, Response response,
    bool is_cpp)
    : syntax(syntax_),
      ep(ep_),
      query(syntax_, is_cpp) {
  for (auto frag_id : response.getFragments()) {
    fragments.emplace_back().first = frag_id;
  }
}

FragmentImpl::Ptr SyntaxQueryResultImpl::GetFragmentAtIndex(unsigned index) const {
  auto &entry = fragments[index];
  auto frag = entry.second.lock();
  if (!frag) {
    frag = ep->FragmentFor(ep, entry.first);
    entry.second = frag;
  }
  return frag;
}

EntityId SyntaxQueryResultImpl::EntityContainingOffset(unsigned offset) const {
  auto it = offset_to_token.upper_bound(offset);
  if (it != offset_to_token.end()) {
    return it->second;
  } else {
    return kInvalidEntityId;
  }
}

void SyntaxQueryResultImpl::GetUnparsedTokens(TokenSubstitutionList nodes) const {
  for (auto node : nodes) {
    if (std::holds_alternative<Token>(node)) {
      auto tok = std::get<Token>(node);
      auto tok_data = tok.data();

      // Skip empty tokens and whitespace.
      if (tok_data.empty() || tok.kind() == TokenKind::WHITESPACE) {
        continue;
      }

      fragment_buffer.insert(fragment_buffer.end(),
                             tok_data.begin(), tok_data.end());
      offset_to_token.emplace(
          static_cast<unsigned>(fragment_buffer.size()),
          tok.id());
      fragment_buffer.push_back(' ');

    } else {
      auto sub = std::get<mx::TokenSubstitution>(node);
      GetUnparsedTokens(sub.before());
    }
  }
}

RegexQueryResultImpl::~RegexQueryResultImpl(void) noexcept {}

RegexQueryResultImpl::RegexQueryResultImpl(
    std::string syntax_, EntityProvider::Ptr ep_, Response response)
    : pattern(syntax_),
      ep(ep_),
      re(syntax_) {
  for (rpc::RegexMatch::Reader entry : response.getMatches()) {
    const FileId file_id = entry.getFileId();
    files.emplace_back().first = file_id;
    const FragmentId frag_id = entry.getFragmentId();
    fragments.emplace_back().first = frag_id;
    matches.emplace_back(file_id, frag_id);
  }
}

FragmentImpl::Ptr RegexQueryResultImpl::GetFragmentAtIndex(unsigned index) const {
  auto &entry = fragments[index];
  auto frag = entry.second.lock();
  if (!frag) {
    frag = ep->FragmentFor(ep, entry.first);
    entry.second = frag;
  }
  return frag;
}

FileImpl::Ptr RegexQueryResultImpl::GetFileAtIndex(unsigned index) const {
    auto &entry = files[index];
    auto file = entry.second.lock();
    if (!file) {
        file = ep->FileFor(ep, entry.first);
        entry.second = file;
    }
    return file;
}

EntityId RegexQueryResultImpl::EntityContainingOffset(unsigned offset) const {
  auto it = offset_to_token.upper_bound(offset);
  if (it != offset_to_token.end()) {
    return it->second;
  } else {
    return kInvalidEntityId;
  }
}

void RegexQueryResultImpl::GetUnparsedTokens(TokenSubstitutionList nodes) const {
  for (auto node : nodes) {
    if (std::holds_alternative<Token>(node)) {
      auto tok = std::get<Token>(node);
      auto tok_data = tok.data();

      // Skip empty tokens and whitespace.
      if (tok_data.empty() || tok.kind() == TokenKind::WHITESPACE) {
        continue;
      }

      fragment_buffer.insert(fragment_buffer.end(),
                             tok_data.begin(), tok_data.end());
      offset_to_token.emplace(
          static_cast<unsigned>(fragment_buffer.size()),
          tok.id());
      fragment_buffer.push_back(' ');

    } else {
      auto sub = std::get<mx::TokenSubstitution>(node);
      GetUnparsedTokens(sub.before());
    }
  }
}

void RegexQueryResultImpl::GetFileContents(File file) const {
  offset_to_token.clear();
  for (auto &tok : Token::in(file)) {
    auto tok_data = tok.data();
    file_buffer.insert(file_buffer.end(),
                       tok_data.begin(), tok_data.end());
    offset_to_token.emplace(
        static_cast<unsigned>(file_buffer.size()),
        tok.id());
  }
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

SyntaxQueryResultImpl::Ptr RemoteEntityProvider::SyntaxQuery(
    const Ptr &self, std::string query, bool is_cpp) {
  ClientConnection &cc = Connection();
  capnp::Request<mx::rpc::Multiplier::SyntaxQueryParams,
                 mx::rpc::Multiplier::SyntaxQueryResults>
      request = cc.client.syntaxQueryRequest();
  request.setQuery(query);
  request.setIsCpp(is_cpp);

  try {
    return std::make_shared<SyntaxQueryResultImpl>(
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

SyntaxQueryResultImpl::Ptr InvalidEntityProvider::SyntaxQuery(
    const Ptr &, std::string, bool is_cpp) {
  return {};
}

RegexQueryResultImpl::Ptr InvalidEntityProvider::RegexQuery(
    const Ptr &, std::string) {
  return {};
}


Token::Token(void)
    : impl(kInvalidTokenReader),
      index(0) {}

// Return `true` if this is a valid token.
Token::operator bool(void) const {
  return !dynamic_cast<const InvalidTokenReader *>(impl.get());
}

// Kind of this token.
TokenKind Token::kind(void) const {
  return impl->NthTokenKind(index);
}

// Return the data of this token.
std::string_view Token::data(void) const {
  return impl->NthTokenData(index);
}

// Return the ID of this token.
EntityId Token::id(void) const {
  return impl->NthTokenId(index);
}

// Return the token list containing a particular token.
TokenList TokenList::containing(Token tok) {
  if (tok) {
    auto num_tokens = tok.impl->NumTokens();
    return TokenList(std::move(tok.impl), num_tokens);
  } else {
    return TokenList();
  }
}

// Return the token list containing a particular token range.
TokenList TokenList::containing(const TokenRange &range) {
  if (range.impl) {
    return TokenList(range.impl, range.impl->NumTokens());
  } else {
    return TokenList();
  }
}

TokenRange::TokenRange(void)
    : index(0),
      num_tokens(0) {}

// Return the token at index `index`.
Token TokenRange::operator[](size_t relative_index) const {
  auto effective_index = (index + relative_index);
  if (effective_index >= num_tokens) {
    throw std::out_of_range(
        "Index " + std::to_string(relative_index) +
        " is out of range on mx::TokenRange");
  } else {
    return Token(impl, effective_index);
  }
}

// Advance to the next valid fragment.
void FileFragmentListIterator::Advance(void) {
  for (; index < num_fragments; ++index) {
    auto &wf = impl->fragments[index].second;
    frag = wf.lock();
    if (frag) {
      frag->containing_file = impl;
      return;
    }

    frag = impl->ep->FragmentFor(impl->ep, impl->fragments[index].first);
    if (!frag) {
      continue;  // Failed to get the fragment, skip over it.
    }

    wf = frag;
    frag->containing_file = impl;  // Save the file <-> fragment mapping.
    return;
  }
}

// Return the file containing a specific fragment.
File File::containing(const Fragment &fragment) {
  auto &fp = fragment.impl->containing_file;
  if (fp) {
    return File(fp);
  }

  const auto frag_id = fragment.impl->id;
  const auto &ep = fragment.impl->ep;
  fp = ep->FileFor(ep, fragment.impl->FileContaingFirstToken());

  // Save the file <-> fragment mapping.
  for (auto &[file_frag_id, frag_wp] : fp->fragments) {
    if (frag_id == file_frag_id) {
      frag_wp = fragment.impl;
      break;
    }
  }

  return fp;
}

// Return all files in a given index.
FileList File::in(const Index &index) {
  return FileList(std::make_shared<FileListImpl>(index.impl));
}

// Return the ID of this file.
FileId File::id(void) const noexcept {
  return impl->id;
}

// Return the list of tokens in this file.
TokenList Token::in(const File &file) {
  auto tokens = file.impl->TokenReader(file.impl);
  auto num_tokens = tokens->NumTokens();
  return TokenList(std::move(tokens), num_tokens);
}

// Return the list of fragments in a file.
FragmentList Fragment::in(const File &file) {
  return FragmentList(
      file.impl, static_cast<unsigned>(file.impl->fragments.size()));
}

// Return the fragment containing a query match.
Fragment Fragment::containing(const SyntaxQueryMatch &match) {
  return Fragment(match.frag);
}

// Return the fragment containing a query match.
Fragment Fragment::containing(const RegexMatch &match) {
  return Fragment(match.frag);
}

// Return the ID of this fragment.
FragmentId Fragment::id(void) const noexcept {
  return impl->id;
}

// The smallest line of the file for which one of the tokens from this
// fragment resides.
unsigned Fragment::first_line(void) const {
  return impl->Fragment().getFirstLine();
}

// The largest line of the file for which one of the tokens from this
// fragment resides.
unsigned Fragment::last_line(void) const {
  return impl->Fragment().getLastLine();
}

// Return the list of parsed tokens in the fragment. This doesn't
// include all tokens, i.e. macro use tokens, comments, etc.
TokenList Token::in(const Fragment &frag) {
  auto tokens = frag.impl->TokenReader(frag.impl);
  auto num_tokens = tokens->NumTokens();
  return TokenList(std::move(tokens), num_tokens);
}

// Return the list of token substitutions.
TokenSubstitutionList Fragment::unparsed_tokens(void) const {
  auto ret = std::make_shared<const TokenSubstitutionListImpl>(impl);
  auto num_nodes = ret->nodes.size();
  return TokenSubstitutionList(std::move(ret), num_nodes);
}

// Return the list of top-level declarations in this fragment.
std::vector<Decl> Fragment::top_level_declarations(void) const {
  std::vector<Decl> decls;
  TopLevelDeclListReader decl_ids = impl->Fragment().getTopLevelDeclarations();
  decls.reserve(decl_ids.size());
  for (auto id_ : decl_ids) {
    EntityId id(id_);
    VariantId vid = id.Unpack();
    if (std::holds_alternative<DeclarationId>(vid)) {
      auto decl_id = std::get<DeclarationId>(vid);
      if (decl_id.fragment_id == impl->id) {
        decls.emplace_back(impl, decl_id.offset);
      } else {
        assert(false);
      }
    } else {
      assert(false);
    }
  }
  return decls;
}

std::variant<Token, TokenSubstitution>
TokenSubstitutionListIterator::operator*(void) const {
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
      nodes(fragment->Fragment().getUnparsedTokens()) {}

TokenSubstitutionListImpl::TokenSubstitutionListImpl(
    std::shared_ptr<const FragmentImpl> fragment_, unsigned offset, BeforeTag)
    : fragment(std::move(fragment_)),
      nodes(fragment->Fragment().getTokenSubstitutions()[offset].getBeforeTokens()) {}

TokenSubstitutionListImpl::TokenSubstitutionListImpl(
    std::shared_ptr<const FragmentImpl> fragment_, unsigned offset, AfterTag)
    : fragment(std::move(fragment_)),
      nodes(fragment->Fragment().getTokenSubstitutions()[offset].getAfterTokens()) {}

TokenSubstitutionList TokenSubstitution::before(void) const {
  auto ret = std::make_shared<const TokenSubstitutionListImpl>(
      impl, offset, BeforeTag{});
  auto num_nodes = ret->nodes.size();
  return TokenSubstitutionList(std::move(ret), num_nodes);
}

TokenSubstitutionList TokenSubstitution::after(void) const {
  auto ret = std::make_shared<const TokenSubstitutionListImpl>(
      impl, offset, AfterTag{});
  auto num_nodes = ret->nodes.size();
  return TokenSubstitutionList(std::move(ret), num_nodes);
}

Index::~Index(void) {}

Index::Index(void)
    : impl(std::make_shared<InvalidEntityProvider>()) {}

FilePathList Index::file_paths(void) const {
  return impl->ListFiles();
}

std::optional<File> Index::file(FileId id) const {
  if (auto ptr = impl->FileFor(impl, id)) {
    return File(std::move(ptr));
  } else {
    return std::nullopt;
  }
}

std::optional<Fragment> Index::fragment(FragmentId id) const {
  if (auto ptr = impl->FragmentFor(impl, id)) {
    return Fragment(std::move(ptr));
  } else {
    return std::nullopt;
  }
}

// Download a fragment based off of an entity ID.
std::optional<Fragment> Index::fragment_containing(EntityId id) const {
  mx::VariantId opt_id = id.Unpack();
  FragmentImpl::Ptr ptr;
  if (std::holds_alternative<mx::DeclarationId>(opt_id)) {
    ptr = impl->FragmentFor(
        impl, std::get<mx::DeclarationId>(opt_id).fragment_id);

  } else if (std::holds_alternative<mx::StatementId>(opt_id)) {
    ptr = impl->FragmentFor(
        impl, std::get<mx::StatementId>(opt_id).fragment_id);

  } else if (std::holds_alternative<mx::FragmentTokenId>(opt_id)) {
    ptr = impl->FragmentFor(
        impl, std::get<mx::FragmentTokenId>(opt_id).fragment_id);
  }

  if (ptr) {
    return Fragment(std::move(ptr));
  } else {
    return std::nullopt;
  }
}

SyntaxQueryResult Index::syntax_query(std::string query, bool is_cpp) const {
  return SyntaxQueryResult(impl->SyntaxQuery(impl, std::move(query), is_cpp));
}

RegexQueryResult Index::regex_query(std::string pattern) const {
  return RegexQueryResult(impl->RegexQuery(impl, std::move(pattern)));
}

FileListImpl::FileListImpl(EntityProvider::Ptr ep_)
    : ep(std::move(ep_)) {

  auto list = ep->ListFiles();
  files.reserve(list.size());
  for (const auto &[path, fid] : list) {
    files.emplace_back(fid, FileImpl::WeakPtr());
  }
}

// Advance to the next valid file.
void FileListIterator::Advance(void) {
  for (; index < num_files; ++index) {
    auto &wf = impl->files[index].second;
    file = wf.lock();
    if (file) {
      return;
    }

    file = impl->ep->FileFor(impl->ep, impl->files[index].first);
    if (!file) {
      continue;  // Failed to get the file, skip over it.
    }

    wf = file;
    return;
  }
}

FileListIterator FileList::begin(void) const {
  return FileListIterator(impl, 0, impl->files.size());
}

Decl DeclIterator::operator*(void) const noexcept {
  return Decl(impl, index);
}

Stmt StmtIterator::operator*(void) const noexcept {
  return Stmt(impl, index);
}

DeclIterator Decl::in_internal(const Fragment &fragment) {
  return DeclIterator(
      fragment.impl, 0u, fragment.impl->Fragment().getDeclarations().size());
}

StmtIterator Stmt::in_internal(const Fragment &fragment) {
  return StmtIterator(
      fragment.impl, 0u, fragment.impl->Fragment().getStatements().size());
}

// Return the token context associated with a token.
//
// NOTE(pag): This only works with parsed tokens, and not all parsed tokens
//            are guaranteed to have a context.
std::optional<TokenContext> TokenContext::of(const Token &tok) {
  if (!tok.impl) {
    return std::nullopt;
  }

  auto frag = dynamic_cast<const PackedFragmentImpl *>(tok.impl.get());
  if (!frag) {
    return std::nullopt;
  }

  auto tc = frag->Fragment().getTokenContexts()[tok.index];
  auto index_kind = tc.getParentIndexAndKind();
  if (!index_kind) {
    return std::nullopt;
  }

  index_kind >>= 1u;

  std::shared_ptr<const FragmentImpl> frag_ptr(tok.impl, frag);

  // NOTE(pag): +1 to skip `kInvalid`.
  TokenContext ret(std::move(frag_ptr));
  ret.kind = static_cast<Kind>((index_kind & 0x3) + 1);
  ret.index = index_kind >> 2u;
  ret.offset = tc.getParentOffset();
  return ret;
}

std::optional<Decl> TokenContext::as_decl(void) const {
  if (kind != kDecl && kind != kDeclAlias) {
    return std::nullopt;
  } else if (!impl) {
    return std::nullopt;
  } else {
    return Decl(impl, index);
  }
}

std::optional<Stmt> TokenContext::as_stmt(void) const {
  if (kind != kStmt && kind != kStmtAlias) {
    return std::nullopt;
  } else if (!impl) {
    return std::nullopt;
  } else {
    return Stmt(impl, index);
  }
}

// Return the aliased context.
std::optional<TokenContext> TokenContext::aliasee(void) const {
  if (!impl) {
    return std::nullopt;

  } else if (kind == kDeclAlias) {
    auto tc = impl->Fragment().getTokenContexts()[offset];
    TokenContext ret(impl);
    ret.kind = kDecl;
    ret.index = index;
    ret.offset = tc.getAliasOffset();
    return ret;

  } else if (kind == kStmtAlias) {
    auto tc = impl->Fragment().getTokenContexts()[offset];
    TokenContext ret(impl);
    ret.kind = kStmt;
    ret.index = index;
    ret.offset = tc.getAliasOffset();
    return ret;

  } else {
    return std::nullopt;
  }
}

// Return the parent context.
std::optional<TokenContext> TokenContext::parent(void) const {
  if (!impl) {
    return std::nullopt;

  } else if (kind == kDecl || kind == kDeclAlias ||
             kind == kStmt || kind == kStmtAlias) {
    auto tc = impl->Fragment().getTokenContexts()[offset];
    auto index_kind = tc.getParentIndexAndKind();
    if (!index_kind) {
      return std::nullopt;
    }

    index_kind >>= 1u;

    // NOTE(pag): `+1` to skip `kInvalid`.
    TokenContext ret(impl);
    ret.kind = static_cast<Kind>((index_kind & 0x3) + 1);
    ret.index = index_kind >> 2u;
    ret.offset = tc.getParentOffset();
    return ret;
  } else {
    return std::nullopt;
  }
}

std::optional<std::string_view> Fragment::source_ir(void) const noexcept {
  auto mlir = impl->SourceIR();
  if (!mlir.empty()) {
    return mlir;
  }
  return std::nullopt;
}

SyntaxQueryMatch::SyntaxQueryMatch(
    std::shared_ptr<const FragmentImpl> frag_,
    std::shared_ptr<const TokenReader> impl_,
    unsigned index_, unsigned num_tokens_,
    std::unordered_map<std::string, TokenRange> var_matches_)
    : TokenRange(std::move(impl_), index_, num_tokens_),
      frag(std::move(frag_)),
      var_matches(std::move(var_matches_)) {}

std::optional<TokenRange> SyntaxQueryMatch::MatchFor(const std::string &var) const {
  auto it = var_matches.find(var);
  if (it != var_matches.end()) {
    return it->second;
  } else {
    return std::nullopt;
  }
}

// Return a list of matched variables.
std::vector<std::string> SyntaxQueryMatch::MatchedVariables(void) const {
  std::vector<std::string> ret;
  for (const auto &[var, _] : var_matches) {
    ret.emplace_back(var);
  }
  return ret;
}

SyntaxQueryResult::SyntaxQueryResult(
    std::shared_ptr<const SyntaxQueryResultImpl> impl_)
    : impl(std::move(impl_)),
      num_fragments(impl->fragments.size()) {}

// Try to advance to the next result. There can be multiple results per
// fragment.
void SyntaxQueryResultIterator::Advance(void) {
  while (index < num_fragments) {
      auto frag = impl->GetFragmentAtIndex(index);
      if (!frag) {
        ++index;
        continue;
      }

      // Reset the caches of data in the fragment, and the mapping of offsets
      // to token ids.
      if (impl->fragment_buffer_id != frag->id) {
        impl->next_weggli_match = 0u;
        impl->weggli_matches.clear();
        impl->fragment_buffer.clear();
        impl->fragment_buffer_id = frag->id;
        impl->GetUnparsedTokens(Fragment(frag).unparsed_tokens());

        impl->query.ForEachMatch(
            impl->fragment_buffer,
            [impl = impl.get()] (const WeggliMatchData &match) {
          impl->weggli_matches.emplace_back(match);
          return true;
        });
      }

      auto match_index = impl->next_weggli_match++;
      if (match_index >= impl->weggli_matches.size()) {
        ++index;  // Skip to next fragment.
        continue;
      }

      const WeggliMatchData &match = impl->weggli_matches[match_index];

      TokenRange range = frag->TokenRangeFor(
          frag,
          impl->EntityContainingOffset(match.begin_offset),
          impl->EntityContainingOffset(match.end_offset));

      std::unordered_map<std::string, TokenRange> var_matches;
      for (const auto &[var, range] : match.variables) {
        var_matches.emplace(
            var,
            frag->TokenRangeFor(
                frag,
                impl->EntityContainingOffset(range.first),
                impl->EntityContainingOffset(range.second)));
      }

      result.reset();
      result.emplace(frag, std::move(range.impl), range.index,
                     range.num_tokens, std::move(var_matches));
      return;
    }
}

void RegexMatchIterator::Advance(void) {
  while (index < num_matches) {
    auto frag = impl->GetFragmentAtIndex(index);
    auto file = impl->GetFileAtIndex(index);
    // if the match is neither a fragment or file, continue
    // to next index.
    // TODO(kumarak) : file should never be null. Should avoid check??
    if (frag == nullptr || file == nullptr) {
      ++index;
      continue;
    }

    // Do the regex search on fragments token first. Only move looking
    // to file if there is no fragment match. It means the match is in
    // comments that are not part of fragments.
    if (frag) {
      if (impl->fragment_buffer_id != frag->id) {
        impl->next_regex_match = 0u;
        impl->regex_matches.clear();
        impl->fragment_buffer.clear();
        impl->fragment_buffer_id = frag->id;
        impl->GetUnparsedTokens(Fragment(frag).unparsed_tokens());
        impl->re.ForEachMatch(
            impl->fragment_buffer,
            [impl = impl.get()] (const std::string &match,
                unsigned begin, unsigned end) {
          impl->regex_matches.emplace_back(match, begin, end);
          return true;
        });
      }

    } else if (file) {
      // We fallback to file only if there are no fragments match

      if (impl->file_buffer_id != file->id) {
        impl->next_regex_match = 0u;
        impl->regex_matches.clear();
        impl->offset_to_token.clear();
        impl->file_buffer.clear();
        impl->file_buffer_id = file->id;
        impl->GetFileContents(File(file));
        impl->re.ForEachMatch(
            impl->file_buffer,
            [impl = impl.get()] (const std::string &match,
                unsigned begin, unsigned end) {
          impl->regex_matches.emplace_back(match, begin, end);
          return true;
        });
      }
    }

    auto next_match = impl->next_regex_match++;
    if (next_match >= impl->regex_matches.size()) {
      ++index;
      continue;
    }

    auto [match, begin_offset, end_offset] = impl->regex_matches[next_match];
    if (frag) {
      // If the regex match happens with the unparsed token of the fragment,
      // It will have the token offset in fragments. Get the token range
      // TODO (kumarak): Is it possible to get the token range from file id
      TokenRange range = frag->TokenRangeFor(frag,
                                  impl->EntityContainingOffset(begin_offset),
                                  impl->EntityContainingOffset(end_offset));

      std::unordered_map<std::string, TokenRange> pattern_matches;
      for (const auto &[match, begin, end] : impl->regex_matches) {
        pattern_matches.emplace(
            match,
            frag->TokenRangeFor(
                frag,
                impl->EntityContainingOffset(begin),
                impl->EntityContainingOffset(end)));
      }

      result.reset();
      result.emplace(frag, file, std::move(range.impl),
                     range.index, range.num_tokens, pattern_matches);

    } else if (file) {
      // Get the token range if the matches are only in file
      auto reader = file->TokenReader(file);
      auto range = TokenRange(reader, begin_offset, end_offset);

      std::unordered_map<std::string, TokenRange> pattern_matches;
      for (const auto &[match, begin, end] : impl->regex_matches) {
        pattern_matches.emplace(
            match, TokenRange(reader, begin, end));
      }

      result.reset();
      result.emplace(frag, file, std::move(range.impl),
                     range.index, range.num_tokens, pattern_matches);

    }
    return;
  }
}

RegexMatch::RegexMatch(
    std::shared_ptr<const FragmentImpl> frag_,
    std::shared_ptr<const FileImpl> file_,
    std::shared_ptr<const TokenReader> impl_,
    unsigned index_, unsigned num_tokens_,
    std::unordered_map<std::string, TokenRange> variable_matches_)
    : TokenRange(std::move(impl_), index_, num_tokens_),
      frag(std::move(frag_)), file(std::move(file_)),
      variable_matches(std::move(variable_matches_)) {}

std::optional<TokenRange> RegexMatch::MatchFor(const std::string &var) const {
  auto it = variable_matches.find(var);
  if (it != variable_matches.end()) {
    return it->second;
  } else {
    return std::nullopt;
  }
}

// Return a list of matched variables.
std::vector<std::string> RegexMatch::MatchedVariables(void) const {
  std::vector<std::string> ret;
  for (const auto &[var, _] : variable_matches) {
    ret.emplace_back(var);
  }
  return ret;
}

RegexQueryResult::RegexQueryResult(
    std::shared_ptr<const RegexQueryResultImpl> impl_)
    : impl(std::move(impl_)),
      num_fragments(impl->fragments.size()) {}

}  // namespace mx
