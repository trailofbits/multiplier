// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cassert>
#include <deque>
#include <gap/core/generator.hpp>
#include <iosfwd>
#include <multiplier/Types.h>
#include <string_view>
#include <vector>
#include <unordered_map>

#include "Util.h"

namespace pasta {
class MacroToken;
class PrintedToken;
class PrintedTokenRange;
class Token;
}  // namespace mx
namespace indexer {

class EntityMapper;
class TokenTreeNode;

// Calculates related entities for tokens, relationships between tokens and
// parsed tokens, etc.
class TokenProvenanceCalculator {
 public:
  struct TokenInfo {

    // The entity ID of this token.
    const mx::RawEntityId entity_id;

    // Hash of the data.
    const uint64_t data_hash;

    // The directly related entity id to the corresponding token. This may be
    // an invalid entity id, or it may be overwritten as the analysis progresses.
    mx::RawEntityId related_entity_id{mx::kInvalidEntityId};

    // If `related_entity_id` is derived from a parsed token, then this is the
    // entity id of the parsed token, otherwise it is the leftmost parsed token.
    mx::RawEntityId parsed_token_id{mx::kInvalidEntityId};

    mx::RawEntityId derived_token_id{mx::kInvalidEntityId};

    // How many children does this node have, OR the address of the only child.
    uintptr_t child{0u};

    unsigned depth{0u};

#ifndef NDEBUG
    std::string_view data;
#endif

    inline TokenInfo(mx::RawEntityId entity_id_, uint64_t data_hash_,
                     mx::RawEntityId related_entity_id_,
                     mx::RawEntityId parsed_token_id_)
        : entity_id(entity_id_),
          data_hash(data_hash_),
          related_entity_id(related_entity_id_),
          parsed_token_id(parsed_token_id_) {}

    unsigned Depth(TokenProvenanceCalculator &self);

    gap::generator<TokenInfo *> Children(TokenProvenanceCalculator &self);

    void DeriveFrom(TokenProvenanceCalculator &self, TokenInfo *parent);
  };

 private:
  const EntityMapper &em;
  mx::RawEntityId fragment_index{mx::kInvalidEntityId};
  std::deque<TokenInfo> infos;
  std::unordered_map<const void *, TokenInfo *> info_map;
  std::unordered_map<TokenInfo *, std::vector<TokenInfo *>> multiple_children;
  std::vector<TokenInfo *> ordered_tokens;
  std::vector<pasta::MacroToken> expansion_toks;

  void Clear(void);
  void Sort(void);
  bool Pull(const std::vector<TokenTreeNode> &tokens);
  bool Pull(void);
  bool Push(void);
  bool TryConnect(TokenInfo *, std::optional<pasta::Token> tok);
  void Connect(TokenInfo *, const pasta::Token &);

 public:
  TokenProvenanceCalculator(const EntityMapper &em);
  ~TokenProvenanceCalculator(void);

#ifndef NDEBUG
  void Dump(std::ostream &os);
#endif

  void Init(mx::RawEntityId fragment_index_,
            const std::vector<TokenTreeNode> &tokens);

  void Init(mx::RawEntityId fragment_index_,
            const pasta::PrintedTokenRange &printed_toks);


  mx::RawEntityId RelatedEntityId(const pasta::PrintedToken &tok);
  mx::RawEntityId RelatedEntityId(const pasta::Token &tok);
  mx::RawEntityId RelatedEntityId(const TokenTreeNode &tok);

  mx::RawEntityId DerivedTokenId(const pasta::PrintedToken &tok);
  mx::RawEntityId DerivedTokenId(const pasta::Token &tok);
  mx::RawEntityId DerivedTokenId(const TokenTreeNode &tok);

  mx::RawEntityId ParsedTokenId(const pasta::PrintedToken &tok);
  mx::RawEntityId ParsedTokenId(const pasta::Token &tok);
  mx::RawEntityId ParsedTokenId(const TokenTreeNode &tok);
};

}  // namespace indexer
