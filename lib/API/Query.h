// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/NodeKind.h>
#include "Grammar.h"
#include <multiplier/Query.h>
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
struct std::hash<std::pair<mx::SyntexNodeKind, size_t>> {
  size_t operator()(const std::pair<mx::SyntexNodeKind, size_t> &self) const {
    size_t hash = 0;
    hash_combine(hash, self.first);
    hash_combine(hash, self.second);
    return hash;
  }
};

namespace mx {

struct Metavar {
  std::string_view m_name;
  std::optional<std::function<bool(const SyntexMetavarMatch&)>> m_predicate;

  explicit Metavar(std::string_view name,
                    std::optional<std::function<bool(SyntexMetavarMatch)>> predicate)
    : m_name(name), m_predicate(std::move(predicate)) {}
};

enum class Glob {
  NO,
  YES
};

struct SyntexParseMarker {

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
    std::vector<std::tuple<SyntexNodeKind, size_t, Glob>> m_children;
  };

  explicit SyntexParseMarker(Metavar *metavar)
    : m_kind(METAVAR), m_metavar(metavar) {}

  explicit SyntexParseMarker(std::string_view spelling)
    : m_kind(TERMINAL), m_spelling(spelling) {}

  explicit SyntexParseMarker(const std::vector<std::tuple<SyntexNodeKind, size_t, Glob>> &children)
    : m_kind(NONTERMINAL), m_children(children) {}

  SyntexParseMarker(SyntexParseMarker &&other)
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
      new (&m_children) std::vector<std::tuple<SyntexNodeKind, size_t, Glob>>(std::move(other.m_children));
      break;
    }
  }

  ~SyntexParseMarker() {
    switch (m_kind) {
    case METAVAR:
      break;
    case TERMINAL:
      m_spelling.std::string_view::~string_view();
      break;
    case NONTERMINAL:
      m_children.std::vector<std::tuple<SyntexNodeKind, size_t, Glob>>::~vector();
      break;
    }
  }

  bool operator==(const SyntexParseMarker &other) const {
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

}  // namespace mx

template<>
struct std::hash<mx::SyntexParseMarker> {
  size_t operator()(const mx::SyntexParseMarker &self) const {
    size_t hash = 0;
    hash_combine(hash, self.m_kind);
    switch (self.m_kind) {
      case mx::SyntexParseMarker::METAVAR:
        break;
      case mx::SyntexParseMarker::TERMINAL:
        hash_combine(hash, self.m_spelling);
        break;
      case mx::SyntexParseMarker::NONTERMINAL:
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

//
// Parser state (e.g. a pointer into the grammar trie)
//

struct Item {
  const SyntexGrammarLeaves *m_leaves;
  std::vector<std::tuple<SyntexNodeKind, size_t, Glob>> m_children;

  explicit Item(const SyntexGrammarLeaves *leaves)
    : m_leaves(leaves)
  {}

  template<typename F>
  void IterateShifts(SyntexNodeKind kind, size_t next, Glob glob, F cb) {
    if (kind == SyntexNodeKind::Any()) {
      const SyntexGrammarLeaves *old_leaves = m_leaves;
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
      const SyntexGrammarLeaves *old_leaves = m_leaves;
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

struct SyntexQueryImpl {
  std::shared_ptr<mx::EntityProvider> m_ep;

  // Input string
  std::string_view m_input;

  SyntexGrammarLeaves grammar_root;

  // Main DP parse table
  using TableEntry = std::unordered_map<std::pair<SyntexNodeKind, size_t>,
                                        std::unordered_set<SyntexParseMarker>>;

  std::unordered_map<size_t, TableEntry> m_parses;

  // Metavariables
  std::unordered_map<std::string_view, Metavar> m_metavars;

  // Globs
  std::unordered_map<size_t, size_t> m_globs;

  void MatchGlob(TableEntry &result, const std::unordered_set<SyntexNodeKind> &follow,
                  Item &item, size_t next);

  void MatchRule(TableEntry &result, Item &item, size_t next);

  void MatchPrefix(TableEntry &result, SyntexNodeKind kind, size_t next);

  const TableEntry &ParsesAtIndex(size_t index);

  explicit SyntexQueryImpl(std::shared_ptr<mx::EntityProvider> ep, std::string_view input);

  void DebugParseTable(std::ostream &os);

  std::pair<bool, std::vector<SyntexMetavarMatch>> MatchMarker(
    const TableEntry &entry, const SyntexParseMarker &marker, std::uint64_t node_id);
};

}  // namespace mx