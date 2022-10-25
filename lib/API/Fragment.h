// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Token.h"

namespace mx {

class FileImpl;

class FragmentListImpl {
 public:
  // Needed for us to be able to look up the file containing this fragment,
  // or look up entities related to other fragments.
  const EntityProvider::Ptr ep;

  // List of fragment IDs.
  std::vector<RawEntityId> fragment_ids;

  inline FragmentListImpl(EntityProvider::Ptr ep_,
                          std::vector<RawEntityId> fragment_ids_)
      : ep(std::move(ep_)),
        fragment_ids(std::move(fragment_ids_)) {}
};

class FragmentImpl {
 public:
  using Ptr = std::shared_ptr<const FragmentImpl>;
  using WeakPtr = std::weak_ptr<const FragmentImpl>;

  // NOTE(pag): This is the fragment identifier without adornment. That is,
  //            it is *NOT* a packed entity ID representation.
  const RawEntityId fragment_id;

  // Needed for us to be able to look up the file containing this fragment,
  // or look up entities related to other fragments.
  const EntityProvider::Ptr ep;

  // For bounds checking.
  //
  // NOTE(pag): Initialized by derived classes;
  unsigned num_decls{0u};
  unsigned num_stmts{0u};
  unsigned num_types{0u};
  unsigned num_attrs{0u};
  unsigned num_pseudos{0u};
  unsigned num_tokens{0u};

  virtual ~FragmentImpl(void) noexcept;

  inline FragmentImpl(RawEntityId id_, EntityProvider::Ptr ep_)
      : fragment_id(id_),
        ep(std::move(ep_)) {}

  // Return the ID of the file containing the first token.
  //
  // NOTE(pag): This returns the raw, unpacked file id.
  virtual RawEntityId FileContaingFirstToken(void) const = 0;

  // Return a reader for the parsed tokens in the fragment. This doesn't
  // include all tokens, i.e. macro use tokens, comments, etc.
  virtual std::shared_ptr<const class TokenReader>
  TokenReader(const FragmentImpl::Ptr &) const = 0;

  // Return a reader for the whole fragment.
  virtual const FragmentReader &Fragment(void) const = 0;

  // Return a specific type of entity.
  virtual DeclReader NthDecl(unsigned offset) const = 0;
  virtual StmtReader NthStmt(unsigned offset) const = 0;
  virtual TypeReader NthType(unsigned offset) const = 0;
  virtual AttrReader NthAttr(unsigned offset) const = 0;
  virtual PseudoReader NthPseudo(unsigned offset) const = 0;

  virtual std::string_view SourceIR(void) const = 0;

  virtual std::string_view Data(void) const = 0;

  // Return the token associated with a specific entity ID.
  std::optional<Token> TokenFor(const FragmentImpl::Ptr &, EntityId id,
                                bool can_fail=false) const;

  // Return the inclusive token range associated with two entity IDs.
  TokenRange TokenRangeFor(const FragmentImpl::Ptr &, EntityId begin_id,
                           EntityId end_id) const;

  // Return the declaration associated with a specific entity ID.
  std::optional<Decl> DeclFor(const FragmentImpl::Ptr &, EntityId id,
                              bool can_fail=true) const;

  // Return the statement associated with a specific entity ID.
  std::optional<Stmt> StmtFor(const FragmentImpl::Ptr &, EntityId id,
                              bool can_fail=true) const;

  // Return the type associated with a specific entity ID.
  std::optional<Type> TypeFor(const FragmentImpl::Ptr &, EntityId id,
                              bool can_fail=true) const;

  // Return the attribute associated with a specific entity ID.
  std::optional<Attr> AttrFor(const FragmentImpl::Ptr &, EntityId id,
                              bool can_fail=true) const;
};

// A packed fragment of code, i.e. a serialized fragment.
class PackedFragmentImpl final : public FragmentImpl, public TokenReader {
 public:
  using Ptr = std::shared_ptr<const PackedFragmentImpl>;
  using Response = capnp::Response<
      mx::rpc::Multiplier::DownloadFragmentResults>;

  PackedReaderState package;
  const rpc::Fragment::Reader reader;

  virtual ~PackedFragmentImpl(void) noexcept;

  PackedFragmentImpl(RawEntityId id_, EntityProvider::Ptr ep_,
                     Response response_);
  PackedFragmentImpl(RawEntityId id_, EntityProvider::Ptr ep_,
                     const capnp::Data::Reader& reader_);

  inline PackedFragmentImpl(FragmentId id_, EntityProvider::Ptr ep_,
                            Response response_)
      : PackedFragmentImpl(id_.fragment_id, std::move(ep_),
                           std::move(response_)) {}

  // Return the ID of the file containing the first token.
  //
  // NOTE(pag): This returns the raw, unpacked file id.
  RawEntityId FileContaingFirstToken(void) const final;

  // Return a reader for the parsed tokens in the fragment. This doesn't
  // include all tokens, i.e. macro use tokens, comments, etc.
  std::shared_ptr<const class TokenReader>
  TokenReader(const FragmentImpl::Ptr &) const final;

  // Return the number of tokens in the file.
  unsigned NumTokens(void) const final;

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(unsigned index) const final;

  // Return the data of the Nth token.
  std::string_view NthTokenData(unsigned index) const final;

  // Return the id of the Nth token.
  EntityId NthTokenId(unsigned token_index) const final;
  EntityId NthFileTokenId(unsigned token_index) const final;

  // Return the token reader for another file.
  TokenReader::Ptr ReaderForFile(const TokenReader::Ptr &self,
                                 RawEntityId id) const final;

  // Returns `true` if `this` is logically equivalent to `that`.
  bool Equals(const class TokenReader *that) const final;

  // Return a reader for the whole fragment.
  const FragmentReader &Fragment(void) const final;

  // Return a specific type of entity.
  DeclReader NthDecl(unsigned offset) const final;
  StmtReader NthStmt(unsigned offset) const final;
  TypeReader NthType(unsigned offset) const final;
  AttrReader NthAttr(unsigned offset) const final;
  PseudoReader NthPseudo(unsigned offset) const final;

  std::string_view SourceIR(void) const final;

  std::string_view Data(void) const final;
};

}  // namespace mx
