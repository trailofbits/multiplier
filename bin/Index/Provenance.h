// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cassert>
#include <deque>
#include <gap/coro/generator.hpp>
#include <iosfwd>
#include <multiplier/Types.h>
#include <pasta/AST/Token.h>
#include <string_view>
#include <vector>
#include <unordered_map>

#include "EntityMapper.h"
#include "Util.h"

namespace pasta {
class MacroToken;
class PrintedToken;
class PrintedTokenRange;
class Token;
}  // namespace pasta
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

    // A file token ID or a macro token ID.
    mx::RawEntityId derived_token_id{mx::kInvalidEntityId};

    // How many children does this node have, OR the address of the only child.
    uintptr_t child{0u};

    // Zero represents unintialized, then we use the maximum valued unsigned
    // number to represent the shallowest value.
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

    bool DeriveFrom(TokenProvenanceCalculator &self, TokenInfo *parent);
  };

  template <typename T>
  TokenInfo *InfoOrEmpty(const T &entity) {
    auto info_it = info_map.find(em.EntityId(entity));
    if (info_it != info_map.end()) {
      return info_it->second;
    } else {
      return &(empty.value());
    }
  }

 private:
  const EntityMapper &em;
  mx::RawEntityId fragment_index{mx::kInvalidEntityId};
  std::deque<TokenInfo> infos;
  std::unordered_map<mx::RawEntityId, TokenInfo *> info_map;
  std::unordered_map<const void *, pasta::Token> parsed_tokens;
  std::unordered_map<TokenInfo *, std::vector<TokenInfo *>> multiple_children;
  std::vector<TokenInfo *> ordered_tokens;
  std::vector<pasta::MacroToken> expansion_toks;
  std::optional<TokenInfo> empty;

  void Sort(void);
  bool Pull(const std::vector<TokenTreeNode> &tokens);
  bool Pull(void);
  bool Push(void);

  template <typename T>
  bool TryConnect(TokenInfo *, const T &tok);
  void ConnectToDerived(TokenInfo *, std::optional<pasta::MacroToken>);
  void Clear(void);

 public:
  TokenProvenanceCalculator(const EntityMapper &em);
  ~TokenProvenanceCalculator(void);

#ifndef NDEBUG
  void Dump(std::ostream &os);
#endif

  void Init(const pasta::PrintedTokenRange &printed_toks);

  void Run(mx::RawEntityId fragment_index_,
           const std::vector<TokenTreeNode> &tokens);

  void Run(mx::RawEntityId fragment_index_,
           const pasta::PrintedTokenRange &printed_toks);

  template <typename T>
  mx::RawEntityId RelatedEntityId(const T &tok) {
    return InfoOrEmpty(tok)->related_entity_id;
  }

  template <typename T>
  mx::RawEntityId DerivedTokenId(const T &tok) {
    return InfoOrEmpty(tok)->derived_token_id;
  }

  template <typename T>
  mx::RawEntityId ParsedTokenId(const T &tok) {
    return InfoOrEmpty(tok)->parsed_token_id;
  }
};

}  // namespace indexer
