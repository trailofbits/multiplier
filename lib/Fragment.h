// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Token.h"

namespace mx {

class FileImpl;

using FragmentIdList = std::vector<PackedFragmentId>;

class FragmentListImpl {
 public:
  // Needed for us to be able to look up the file containing this fragment,
  // or look up entities related to other fragments.
  const EntityProvider::Ptr ep;

  // List of fragment IDs.
  FragmentIdList fragment_ids;

  inline FragmentListImpl(EntityProvider::Ptr ep_,
                          FragmentIdList fragment_ids_)
      : ep(std::move(ep_)),
        fragment_ids(std::move(fragment_ids_)) {}
};

class ReadMacroTokensFromFragment : public TokenReader {
 public:
  const FragmentImpl * const fragment;

  inline ReadMacroTokensFromFragment(FragmentImpl *fragment_)
      : fragment(fragment_) {}

  // Return the number of tokens in the fragment.
  unsigned NumTokens(void) const override;

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(unsigned index) const override;

  // Return the data of the Nth token.
  std::string_view NthTokenData(unsigned index) const override;

  // Return the id of the token from which the Nth token is derived.
  EntityId NthDerivedTokenId(unsigned token_index) const override;

  // Return the id of the parsed token which is derived from the Nth token.
  EntityId NthParsedTokenId(unsigned) const override;

  // Return the id of the macro containing the Nth token.
  EntityId NthContainingMacroId(unsigned) const override;

  // Return the id of the Nth token.
  EntityId NthTokenId(unsigned token_index) const override;
  EntityId NthFileTokenId(unsigned token_index) const override;

  // Return the token reader for another file.
  TokenReader::Ptr ReaderForToken(const TokenReader::Ptr &self,
                                  RawEntityId id) const final;

  // Returns `true` if `this` is logically equivalent to `that`.
  bool Equals(const class TokenReader *that) const override;

  const FragmentImpl *OwningFragment(void) const noexcept final;
};

class ReadParsedTokensFromFragment final
    : public ReadMacroTokensFromFragment {
 public:
  using ReadMacroTokensFromFragment::ReadMacroTokensFromFragment;

  // Return the number of tokens in the fragment.
  unsigned NumTokens(void) const final;

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(unsigned index) const final;

  // Return the data of the Nth token.
  std::string_view NthTokenData(unsigned index) const final;

  // Return the id of the token from which the Nth token is derived.
  EntityId NthDerivedTokenId(unsigned token_index) const final;

  // Return the id of the parsed token which is derived from the Nth token.
  EntityId NthParsedTokenId(unsigned token_index) const final;

  // Return the id of the macro containing the Nth token.
  EntityId NthContainingMacroId(unsigned) const final;

  // Return the id of the Nth token.
  EntityId NthTokenId(unsigned token_index) const final;
  EntityId NthFileTokenId(unsigned token_index) const final;

  // Returns `true` if `this` is logically equivalent to `that`.
  bool Equals(const class TokenReader *that) const final;
};

class FragmentImpl final {
 public:
  using Ptr = std::shared_ptr<const FragmentImpl>;
  using WeakPtr = std::weak_ptr<const FragmentImpl>;

  // NOTE(pag): This is the fragment identifier without adornment. That is,
  //            it is *NOT* a packed entity ID representation.
  //
  // TODO(pag): Rename to `fragment_index`.
  const RawEntityId fragment_id;

  // Needed for us to be able to look up the file containing this fragment,
  // or look up entities related to other fragments.
  const EntityProvider::Ptr ep;

 private:
  friend class ReadParsedTokensFromFragment;
  friend class ReadMacroTokensFromFragment;

  // Stores the Cap'n-Proto serialized data.
  PackedReaderState package;

  // Reader for `package`.
  const rpc::Fragment::Reader reader;

  // Token readers for this fragment.
  const ReadParsedTokensFromFragment parsed_token_reader;
  const ReadMacroTokensFromFragment macro_token_reader;

 public:

  // For bounds checking.
  const unsigned num_decls;
  const unsigned num_stmts;
  const unsigned num_types;
  const unsigned num_attrs;
  const unsigned num_macros;
  const unsigned num_pseudos;
  const unsigned num_parsed_tokens;
  const unsigned num_tokens;

  ~FragmentImpl(void) noexcept;

  explicit FragmentImpl(FragmentId id_, EntityProvider::Ptr ep_,
                        const capnp::Data::Reader &reader_);

  // Return the ID of the file containing the first token.
  //
  // NOTE(pag): This returns the raw, unpacked file id.
  RawEntityId FileContaingFirstToken(void) const;

  // Return a reader for the macro tokens in the fragment. This doesn't
  // include all tokens, i.e. macro use tokens, comments, etc.
  std::shared_ptr<const class TokenReader>
  MacroTokenReader(const FragmentImpl::Ptr &) const;

  // Return a reader for the parsed tokens in the fragment. This doesn't
  // include all tokens, i.e. macro use tokens, comments, etc.
  std::shared_ptr<const class TokenReader>
  ParsedTokenReader(const FragmentImpl::Ptr &) const;

  // Return a reader for the whole fragment.
  inline const FragmentReader &Fragment(void) const noexcept {
    return reader;
  }

  // Return a specific type of entity.
  DeclReader NthDecl(unsigned offset) const;
  StmtReader NthStmt(unsigned offset) const;
  TypeReader NthType(unsigned offset) const;
  AttrReader NthAttr(unsigned offset) const;
  MacroReader NthMacro(unsigned offset) const;
  PseudoReader NthPseudo(unsigned offset) const;

  std::string_view SourceIR(void) const;

  std::string_view Data(void) const;

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
  std::optional<Macro> MacroFor(const FragmentImpl::Ptr &, EntityId id,
                                bool can_fail=true) const;

  // Return the attribute associated with a specific entity ID.
  std::optional<Attr> AttrFor(const FragmentImpl::Ptr &, EntityId id,
                              bool can_fail=true) const;
};

}  // namespace mx
