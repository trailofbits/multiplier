// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "TokenContext.h"
#include "TokenTree.h"

namespace mx {
namespace ir {
class SourceIRImpl;
}  // namespace ir

class FileImpl;

using FragmentIdList = std::vector<PackedFragmentId>;

class FragmentListImpl {
 public:
  // Needed for us to be able to look up the file containing this fragment,
  // or look up entities related to other fragments.
  const EntityProviderPtr ep;

  // List of fragment IDs.
  FragmentIdList fragment_ids;

  inline FragmentListImpl(EntityProviderPtr ep_,
                          FragmentIdList fragment_ids_)
      : ep(std::move(ep_)),
        fragment_ids(std::move(fragment_ids_)) {}
};

class ReadMacroTokensFromFragment : public TokenReader {
 public:
  FragmentImpl * const fragment;

  inline ReadMacroTokensFromFragment(FragmentImpl *fragment_)
      : fragment(fragment_) {}

  // Return the number of tokens in the fragment.
  EntityOffset NumTokens(void) const override;

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(EntityOffset index) const override;

  // Return the data of the Nth token.
  std::string_view NthTokenData(EntityOffset index) const override;

  // Return the id of the token from which the Nth token is derived.
  EntityId NthDerivedTokenId(EntityOffset token_index) const override;

  // Return the id of the parsed token which is derived from the Nth token.
  EntityId NthParsedTokenId(EntityOffset) const override;

  // Return the id of the macro containing the Nth token.
  EntityId NthContainingMacroId(EntityOffset) const override;

  // Return an entity id associated with the Nth token.
  EntityId NthRelatedEntityId(EntityOffset) const override;

  // Return the entity associated with the Nth token.
  VariantEntity NthRelatedEntity(EntityOffset) const final;

  // Return the id of the Nth token.
  EntityId NthTokenId(EntityOffset token_index) const override;
  EntityId NthFileTokenId(EntityOffset token_index) const override;

  // Returns `true` if `this` is logically equivalent to `that`.
  bool Equals(const class TokenReader *that) const override;

  const FragmentImpl *OwningFragment(void) const noexcept final;
};

class ReadParsedTokensFromFragment final
    : public ReadMacroTokensFromFragment {
 public:
  using ReadMacroTokensFromFragment::ReadMacroTokensFromFragment;

  // Return the number of tokens in the fragment.
  EntityOffset NumTokens(void) const final;

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(EntityOffset index) const final;

  // Return the data of the Nth token.
  std::string_view NthTokenData(EntityOffset index) const final;

  // Return the id of the token from which the Nth token is derived.
  EntityId NthDerivedTokenId(EntityOffset token_index) const final;

  // Return the id of the parsed token which is derived from the Nth token.
  EntityId NthParsedTokenId(EntityOffset token_index) const final;

  // Return the id of the macro containing the Nth token.
  EntityId NthContainingMacroId(EntityOffset) const final;

  // Return an entity id associated with the Nth token.
  EntityId NthRelatedEntityId(EntityOffset) const override;

  // Return the id of the Nth token.
  EntityId NthTokenId(EntityOffset token_index) const final;
  EntityId NthFileTokenId(EntityOffset token_index) const final;

  // Returns `true` if `this` is logically equivalent to `that`.
  bool Equals(const class TokenReader *that) const final;
};

class FragmentImpl final : public EntityImpl<rpc::Fragment> {
 public:
  using Ptr = std::shared_ptr<const FragmentImpl>;
  using WeakPtr = std::weak_ptr<const FragmentImpl>;

  // NOTE(pag): This is the fragment identifier without adornment. That is,
  //            it is *NOT* a packed entity ID representation.
  //
  // TODO(pag): Rename to `fragment_index`.
  const RawEntityId fragment_id;

  // Immediate parent fragment ID. This is `kInvalidEntityId` if this is a top-
  // level or floating fragment. This is packed entity ID.
  const RawEntityId parent_fragment_id;

 private:
  friend class ReadParsedTokensFromFragment;
  friend class ReadMacroTokensFromFragment;
  friend class FragmentTokenContextReader;

  // Token readers for this fragment.
  const ReadParsedTokensFromFragment parsed_token_reader;
  const ReadMacroTokensFromFragment macro_token_reader;
  const FragmentTokenContextReader token_context_reader;

 public:

  // For bounds checking.
  const EntityOffset num_parsed_tokens;
  const EntityOffset num_tokens;
  const EntityOffset num_nested_fragments;

  // Cached token tree.
  //
  // TODO(pag): Add method to entity provider, so we can add it to the GC-based
  //            cache.
  TokenTreeImplCache cached_token_tree;

  explicit FragmentImpl(EntityProviderPtr ep_, kj::Array<capnp::word> data_,
                        RawEntityId id_);

  // Return the ID of the file containing the first token.
  //
  // NOTE(pag): This returns the raw, unpacked file id.
  RawEntityId FileContaingFirstToken(void) const;

  // Return a reader for the macro tokens in the fragment. This doesn't
  // include all tokens, i.e. macro use tokens, comments, etc.
  std::shared_ptr<const class TokenReader>
  MacroTokenReader(const FragmentImplPtr &) const;

  // Return a reader for the parsed tokens in the fragment. This doesn't
  // include all tokens, i.e. macro use tokens, comments, etc.
  TokenReaderPtr
  ParsedTokenReader(const FragmentImplPtr &) const;

  TokenContextReader::Ptr
  TokenContextReader(const TokenReaderPtr &) const;

  std::string_view Data(void) const & noexcept;

  // Return the token associated with a specific entity ID.
  std::optional<Token> TokenFor(const FragmentImplPtr &, EntityId id,
                                bool can_fail=false) const;

  // Return the inclusive token range associated with two entity IDs.
  TokenRange TokenRangeFor(const FragmentImplPtr &, EntityId begin_id,
                           EntityId end_id) const;
};

}  // namespace mx
