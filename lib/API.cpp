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
#include <thread>

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
unsigned InvalidTokenReader::NumTokens(void) const noexcept {
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

// Return a reader for the tokens in the file.
TokenReader::Ptr InvalidFileImpl::TokenReader(
    const FileImpl::Ptr &self) const {
  return TokenReader::Ptr(self, &empty_reader);
}

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
unsigned PackedFileImpl::NumTokens(void) const noexcept {
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
    const FragmentImpl::Ptr &self, EntityId id) const {
  VariantId vid = id.Unpack();

  // It's a fragment token.
  if (std::holds_alternative<FragmentTokenId>(vid)) {
    auto fid = std::get<FragmentTokenId>(vid);

    // It's a token inside of the current fragment.
    if (fid.fragment_id == id) {
      return Token(this->TokenReader(self), fid.offset);

    // It's a token inside of another fragment, go get the other fragment.
    } else {
      auto other_frag = ep->fragment(fid.fragment_id);
      auto reader = other_frag.impl->TokenReader(other_frag.impl);
      return Token(std::move(reader), fid.offset);
    }

  // It's a file token; go get the file.
  } else if (std::holds_alternative<FileTokenId>(vid)) {
    auto fid = std::get<FileTokenId>(vid);
    FileImpl::Ptr file;
    if (containing_file && containing_file->id == fid.file_id) {
      file = containing_file;  // Try to use the containing file if it matches.
    } else {
      file = ep->file(fid.file_id).impl;
    }

    auto reader = file->TokenReader(file);
    return Token(std::move(reader), fid.offset);

  // An invalid ID.
  } else if (std::holds_alternative<InvalidId>(vid)) {
    return Token::invalid();

  // A non-token ID.
  } else {
    assert(false);
    return Token::invalid();
  }
}

// Return the inclusive token range associated with two entity IDs.
TokenRange FragmentImpl::TokenRangeFor(
    const FragmentImpl::Ptr &self, EntityId begin_id, EntityId end_id) const {
  auto begin_tok = TokenFor(self, begin_id);

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

    auto range_size = static_cast<unsigned>((efid.offset - bfid.offset) + 1u);

    // It's a token inside of the current fragment.
    if (bfid.fragment_id == id) {
      return TokenRange(this->TokenReader(self), bfid.offset, range_size);

    // It's a token inside of another fragment, go get the other fragment.
    } else {
      auto other_frag = ep->fragment(bfid.fragment_id);
      auto reader = other_frag.impl->TokenReader(other_frag.impl);
      return TokenRange(std::move(reader), bfid.offset, range_size);
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

    auto range_size = static_cast<unsigned>((efid.offset - bfid.offset) + 1u);

    FileImpl::Ptr file;
    if (containing_file && containing_file->id == bfid.file_id) {
      file = containing_file;  // Try to use the containing file if it matches.
    } else {
      file = ep->file(bfid.file_id).impl;
    }

    auto reader = file->TokenReader(file);
    return TokenRange(std::move(reader), bfid.offset, range_size);

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
    return Decl(std::move(ep->fragment(decl_id.fragment_id).impl),
                decl_id.offset);
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
  ast::Entity::Reader x;
  StatementId stmt_id = std::get<StatementId>(vid);

  // It's a token inside of the current fragment.
  if (stmt_id.fragment_id == id) {
    return Stmt(self, stmt_id.offset);

  // It's a token inside of another fragment, go get the other fragment.
  } else {
    return Stmt(std::move(ep->fragment(stmt_id.fragment_id).impl),
                stmt_id.offset);
  }
}

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

TopLevelDeclListReader InvalidFragmentImpl::TopLevelDeclarations(void) const {
  return {};
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

unsigned PackedFragmentImpl::FirstLine(void) const {
  return reader.getFirstLine();
}

unsigned PackedFragmentImpl::LastLine(void) const {
  return reader.getLastLine();
}

// Return a reader for the parsed tokens in the fragment. This doesn't
// include all tokens, i.e. macro use tokens, comments, etc.
TokenReader::Ptr PackedFragmentImpl::TokenReader(
    const FragmentImpl::Ptr &self) const {
  return TokenReader::Ptr(self, static_cast<const class TokenReader *>(this));
}

// Return the number of tokens in the file.
unsigned PackedFragmentImpl::NumTokens(void) const noexcept {
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

// Return a reader for token nodes.
NodeReader PackedFragmentImpl::Nodes(void) const {
  return reader.getUnparsedTokens();
}

// Return a reader for token substitutions.
TokenSubstitutionsReader PackedFragmentImpl::Substitutions(void) const {
  return reader.getTokenSubstitutions();
}

// Return a reader for the entities in this fragment.
EntityListReader PackedFragmentImpl::Entities(void) const {
  return reader.getEntities();
}

// Return a reader for the top-level declarations of this fragment.
TopLevelDeclListReader PackedFragmentImpl::TopLevelDeclarations(void) const {
  return reader.getTopLevelDeclarations();
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
    auto ret = std::make_shared<PackedFileImpl>(
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
    auto ret = std::make_shared<PackedFragmentImpl>(
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
  return !!dynamic_cast<const InvalidTokenReader *>(impl.get());
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
  return Token(kInvalidTokenReader, 0);
}

TokenRange::TokenRange(void)
    : index(0),
      num_tokens(0) {}

// Return the token at index `index`.
Token TokenRange::operator[](size_t relative_index) const noexcept {
  auto effective_index = (index + relative_index);
  if (effective_index >= num_tokens) {
    return Token::invalid();
  } else {
    return Token(impl, effective_index);
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
  std::vector<Decl> decls;
  TopLevelDeclListReader decl_ids = impl->TopLevelDeclarations();
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
