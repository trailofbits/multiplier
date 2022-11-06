// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "NodeKind.h"

#include <absl/container/flat_hash_map.h>
#include <absl/container/flat_hash_set.h>
#include <multiplier/SQLiteStore.h>
#include <filesystem>
#include <optional>
#include <ostream>
#include <string>

namespace mx {

class Index;

namespace syntex {

class AST;

struct GrammarNode;

//
// One set of grammar leaves
// FIXME(frabert): Deserialization crashes if this is turned into
//   an `absl::flat_hash_map`
//
using GrammarLeaves = std::unordered_map<NodeKind, GrammarNode>;

//
// Node in the grammar tree
//

struct GrammarNode {
  // Does this node correspond to the head of a production
  bool is_production;
  // Further leaves
  GrammarLeaves leaves;
};

//
// Persistent CFG synthesized from a set of multiplier fragments
//

class GrammarImpl {
private:
  friend class Item;
  friend class ParsedQuery;
  friend class ParsedQueryImpl;

  // Multiplier index corresponding to this grammar
  const mx::Index &index;

  // Grammar storage directory
  std::filesystem::path db_path;

  // Mapping of spellings to token kinds
  absl::flat_hash_map<std::string, mx::TokenKind> tokens;

  // Root of the grammar tree
  GrammarLeaves root;

public:
  GrammarImpl(const mx::Index &index, std::filesystem::path db_path);

  ~GrammarImpl(void);

  // Import a fragment into the grammar. This extends the persisted grammar with
  // the features from this fragment.
  void Import(mx::RawEntityId fragment_id);

  void Import(const AST &ast);

  // Determine the kind of an identifier based on its spelling
  std::optional<mx::TokenKind> TokenKindOf(std::string_view spelling) const;

  // Pretty print rules for debugging
  void DebugRules(std::ostream &os);

  // Database grammar serialization
  void SerializeRules(sqlite::Connection& db);
  void DeserializeRules(sqlite::Connection& db);

  void SerializeTokens(sqlite::Connection& db);
  void DeserializeTokens(sqlite::Connection& db);
};

}  // namespace syntex
}  // namespace mx