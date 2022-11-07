// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "NodeKind.h"
#include "Grammar.h"
#include <multiplier/Syntex.h>
#include <deque>
#include <unordered_map>
#include <unordered_set>

template <class T>
inline void hash_combine(size_t &h, const T& v)
{
  std::hash<T> hasher;
  h ^= hasher(v) + 0x9e3779b9 + (h << 6) + (h >> 2);
}

template<>
struct std::hash<std::pair<mx::syntex::NodeKind, size_t>> {
  size_t operator()(const std::pair<mx::syntex::NodeKind, size_t> &self) const {
    size_t hash = 0;
    hash_combine(hash, self.first);
    hash_combine(hash, self.second);
    return hash;
  }
};

namespace mx {
namespace syntex {
//
// Result of parsing a query
//

class ParsedQuery {
 private:
  std::shared_ptr<ParsedQueryImpl> impl;
  ParsedQuery(void) = delete;

 public:
  explicit ParsedQuery(std::shared_ptr<mx::EntityProvider> ep, std::string_view query);

  bool IsValid() const;

  bool AddMetavarPredicate(const std::string_view &name,
                           std::function<bool(const MetavarMatch&)> predicate);

  void ForEachMatch(mx::RawEntityId frag_id,
                    std::function<bool(Match)> pred) const;
  void ForEachMatch(std::function<bool(Match)> pred) const;

  std::vector<Match> Find(mx::RawEntityId frag_id) const;
  std::vector<Match> Find(void) const;
};

struct Metavar {
  std::string_view m_name;
  std::optional<std::function<bool(const MetavarMatch&)>> m_predicate;

  explicit Metavar(std::string_view name,
                    std::optional<std::function<bool(MetavarMatch)>> predicate)
    : m_name(name), m_predicate(std::move(predicate)) {}
};

enum class Glob {
  NO,
  YES
};

struct ParseMarker {

  // Node category
  enum {
    METAVAR,
    TERMINAL,
    NONTERMINAL,
  } m_kind;

  // Associated data
  union {
    Metavar *m_metavar;
    std::string_view m_spelling;
    std::vector<std::tuple<NodeKind, size_t, Glob>> m_children;
  };

  explicit ParseMarker(Metavar *metavar)
    : m_kind(METAVAR), m_metavar(metavar) {}

  explicit ParseMarker(std::string_view spelling)
    : m_kind(TERMINAL), m_spelling(spelling) {}

  explicit ParseMarker(const std::vector<std::tuple<NodeKind, size_t, Glob>> &children)
    : m_kind(NONTERMINAL), m_children(children) {}

  ParseMarker(ParseMarker &&other)
    : m_kind(other.m_kind)
  {
    switch (m_kind) {
    case METAVAR:
      m_metavar = other.m_metavar;
      break;
    case TERMINAL:
      new (&m_spelling) std::string_view(other.m_spelling);
      break;
    case NONTERMINAL:
      new (&m_children) std::vector<std::tuple<NodeKind, size_t, Glob>>(std::move(other.m_children));
      break;
    }
  }

  ~ParseMarker() {
    switch (m_kind) {
    case METAVAR:
      break;
    case TERMINAL:
      m_spelling.std::string_view::~string_view();
      break;
    case NONTERMINAL:
      m_children.std::vector<std::tuple<NodeKind, size_t, Glob>>::~vector();
      break;
    }
  }

  bool operator==(const ParseMarker &other) const {
    if (m_kind != other.m_kind) {
      return false;
    }

    switch (m_kind) {
    case METAVAR:
      // NOTE: it's impossible to have two metavariables
      //        at the same input location, thus this is never called
      assert(false);
      abort();
    case TERMINAL:
      return m_spelling == other.m_spelling;
    case NONTERMINAL:
      return m_children == other.m_children;
    }
  }
};

}  // namespace syntex
}  // namespace mx

template<>
struct std::hash<mx::syntex::ParseMarker> {
  size_t operator()(const mx::syntex::ParseMarker &self) const {
    size_t hash = 0;
    hash_combine(hash, self.m_kind);
    switch (self.m_kind) {
      case mx::syntex::ParseMarker::METAVAR:
        break;
      case mx::syntex::ParseMarker::TERMINAL:
        hash_combine(hash, self.m_spelling);
        break;
      case mx::syntex::ParseMarker::NONTERMINAL:
        for (auto &[kind, next, glob] : self.m_children) {
          hash_combine(hash, kind);
          hash_combine(hash, next);
          hash_combine(hash, glob);
        }
        break;
    }
    return hash;
  }
};

namespace mx {
namespace syntex {

//
// Parser state (e.g. a pointer into the grammar trie)
//

struct Item {
  const GrammarLeaves *m_leaves;
  std::vector<std::tuple<NodeKind, size_t, Glob>> m_children;

  explicit Item(const GrammarLeaves *leaves)
    : m_leaves(leaves)
  {}

  template<typename F>
  void IterateShifts(NodeKind kind, size_t next, Glob glob, F cb) {
    if (kind == NodeKind::Any()) {
      const GrammarLeaves *old_leaves = m_leaves;
      m_children.emplace_back(kind, next, glob);

      for (auto &[kind, rest] : *m_leaves) {
        if (rest.leaves.empty()) {
          continue;
        }

        m_leaves = &rest.leaves;
        cb(*this);
      }

      m_leaves = old_leaves;
      m_children.pop_back();
    } else {
      auto it = m_leaves->find(kind);
      if (it == m_leaves->end() || it->second.leaves.empty()) {
        return;
      }

      // Morph ourselves into the shifted state
      const GrammarLeaves *old_leaves = m_leaves;
      m_leaves = &it->second.leaves;
      m_children.emplace_back(kind, next, glob);

      // Fire callback with morphed item
      cb(*this);

      // Restore item
      m_leaves = old_leaves;
      m_children.pop_back();
    }
  }

  template<typename F>
  void IterateReductions(F cb) const {
    for (auto &[left, rest] : *m_leaves) {
      if (rest.is_production) {
        cb(left, m_children);
      }
    }
  }
};

//
// Wrapper around parsing functions
//

struct ParsedQueryImpl {
  std::shared_ptr<mx::EntityProvider> m_ep;

  // Input string
  std::string_view m_input;

  GrammarLeaves grammar_root;

  // Main DP parse table
  using TableEntry = std::unordered_map<std::pair<NodeKind, size_t>,
                                        std::unordered_set<ParseMarker>>;

  std::unordered_map<size_t, TableEntry> m_parses;

  // Metavariables
  std::unordered_map<std::string_view, Metavar> m_metavars;

  // Globs
  std::unordered_map<size_t, size_t> m_globs;

  void MatchGlob(TableEntry &result, const std::unordered_set<NodeKind> &follow,
                  Item &item, size_t next);

  void MatchRule(TableEntry &result, Item &item, size_t next);

  void MatchPrefix(TableEntry &result, NodeKind kind, size_t next);

  const TableEntry &ParsesAtIndex(size_t index);

  explicit ParsedQueryImpl(std::shared_ptr<mx::EntityProvider> ep, std::string_view input);

  void DebugParseTable(std::ostream &os);

  std::pair<bool, std::vector<MetavarMatch>> MatchMarker(
    const TableEntry &entry, const ParseMarker &marker, std::uint64_t node_id);
};

}  // namespace syntex
}  // namespace mx