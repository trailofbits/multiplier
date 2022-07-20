// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cassert>
#include <deque>
#include <string>
#include <vector>
#include <multiplier/AST.h>
#include <multiplier/Index.h>
#include <multiplier/PersistentMap.h>

namespace syntex {

class NodeKind {
private:
  unsigned short val;

  NodeKind(unsigned short val_) : val(val_) {}

public:
  NodeKind(mx::DeclKind kind)
      : val(static_cast<unsigned short>(kind)) {}

  NodeKind(mx::StmtKind kind)
      : val(static_cast<unsigned short>(kind)
            + mx::NumEnumerators(mx::DeclKind{})) {}

  NodeKind(mx::TypeKind kind)
      : val(static_cast<unsigned short>(kind)
            + mx::NumEnumerators(mx::DeclKind{})
            + mx::NumEnumerators(mx::StmtKind{})) {}

  NodeKind(mx::TokenKind kind)
      : val(static_cast<unsigned short>(kind)
            + mx::NumEnumerators(mx::DeclKind{})
            + mx::NumEnumerators(mx::StmtKind{})
            + mx::NumEnumerators(mx::TypeKind{})) {}

  template<typename T>
  void Visit(T visitor) const {
    if (val < mx::NumEnumerators(mx::DeclKind{})) {
      visitor(static_cast<mx::DeclKind>(val));
    } else if (val < mx::NumEnumerators(mx::DeclKind{})
                     + mx::NumEnumerators(mx::StmtKind{})) {
      visitor(static_cast<mx::StmtKind>(val
                                        - mx::NumEnumerators(mx::DeclKind{})));
    } else if (val < mx::NumEnumerators(mx::DeclKind{})
                     + mx::NumEnumerators(mx::StmtKind{})
                     + mx::NumEnumerators(mx::TypeKind{})) {
      visitor(static_cast<mx::TypeKind>(val
                                        - mx::NumEnumerators(mx::DeclKind{})
                                        - mx::NumEnumerators(mx::StmtKind{})));
    } else {
      visitor(static_cast<mx::TokenKind>(val
                                         - mx::NumEnumerators(mx::DeclKind{})
                                         - mx::NumEnumerators(mx::StmtKind{})
                                         - mx::NumEnumerators(mx::TypeKind{})));
    }
  }

  bool IsToken() const  {
    return val >= mx::NumEnumerators(mx::DeclKind{})
                  + mx::NumEnumerators(mx::StmtKind{})
                  + mx::NumEnumerators(mx::TypeKind{});
  }

  mx::TokenKind AsToken() const {
    assert(IsToken());
    return static_cast<mx::TokenKind>(val
                                      - mx::NumEnumerators(mx::DeclKind{})
                                      - mx::NumEnumerators(mx::StmtKind{})
                                      - mx::NumEnumerators(mx::TypeKind{}));
  }

  bool operator==(const NodeKind &other) const {
    return val == other.val;
  }

  static NodeKind Deserialize(unsigned short val) {
    return val;
  }

  unsigned short Serialize() const {
    return val;
  }
};

std::ostream& operator<<(std::ostream &, const NodeKind &);

template<typename ... F>
struct Visitor : F ... {
  using F::operator() ...;
};

template<class... F> Visitor(F...) -> Visitor<F...>;

class ASTNode {
public:
  friend class AST;

  // Next node sharing the same `kind` in the AST. This is
  // useful when unifying two parses, i.e. a fragment parse, created with
  // `AST::Build(fragment)`, and a parse of a syntax query. We can start with
  // nodes in the query, and then try to unify them top-down with nodes in the
  // fragment parse by jumping into the middle of the fragment parse to the
  // correct spot.
  const ASTNode *prev_of_kind{nullptr};

  ASTNode(NodeKind kind, std::vector<const ASTNode *> child_vector);
  ASTNode(mx::TokenKind kind, std::string spelling);

  ~ASTNode();

  NodeKind Kind() const {
    return kind;
  }

  const std::vector<const ASTNode *> &ChildVector() const {
    assert(!kind.IsToken());
    return child_vector;
  };

  const std::string &Spelling() const {
    assert(kind.IsToken());
    return spelling;
  }

  bool operator==(const ASTNode &that) const noexcept;

private:
  NodeKind kind;

  union {
    mutable std::vector<const ASTNode *> child_vector;
    std::string spelling;
  };
};


// An AST.
class AST {
private:
  friend class ASTNode;
  friend class QueryImpl;

  std::deque<ASTNode> nodes;
  std::vector<const ASTNode *> index;
  std::vector<const ASTNode *> root;

  AST(void);

public:
  // Used to "hop into" the middle of the
  const ASTNode *LastNodeOfKind(NodeKind kind);

  const ASTNode *ConstructNode(NodeKind kind, std::vector<const ASTNode *> child_vector);
  const ASTNode *ConstructNode(mx::TokenKind k, std::string spelling);

  const std::vector<const ASTNode *> &Root(void) const {
    return root;
  }

  // Build an AST from a multiplier fragment
  static AST Build(const mx::Fragment &fragment);

#ifndef NDEBUG
  void PrintDOT(std::ostream &os) const;
#endif
};

// This is a very very small bloom filter that we'll use to track "features"
// of fragments, i.e. whether or not a fragment might have a match for a
// particular rule.
struct SmallBloomFilter {
  static constexpr auto kNumWords = 3u;

  uint64_t words[kNumWords];

  SmallBloomFilter(void) {
    _Pragma("unroll") for (auto i = 0u; i < kNumWords; ++i) {
      words[i] = 0;
    }
  }

  void Add(uint64_t hash) {
    _Pragma("unroll") for (auto i = 0u; i < kNumWords; ++i) {
      words[i] |= 1ull << (hash & 0x3Full);
      hash >>= 6u;
    }
  }

  void Add(const SmallBloomFilter &that) {
    for (auto i = 0u; i < kNumWords; ++i)
      words[i] |= that.words[i];
  }

  bool Contains(const SmallBloomFilter &that) const noexcept {
    _Pragma("unroll") for (auto i = 0u; i < kNumWords; ++i) {
      if ((words[i] & that.words[i]) != that.words[i]) {
        return false;
      }
    }
    return true;
  }
};

struct Terminal {
  std::string data;
};

// Right-hand side / body of a production rule in a grammar, followed by the
// head of the production. E.g. if a production is `A -> B C` then this stores
// `B C A`.

struct Rule {
  std::vector<NodeKind> non_terminals;

  // For serialization
  Rule() {}

  // Actual constructor
  Rule(std::vector<NodeKind> non_terminals_)
      : non_terminals(non_terminals_) {}

  uint64_t Hash(void) const;
};

std::ostream& operator<<(std::ostream& os, const Rule &rule);

class GrammarImpl {
private:

  // Maps terminals, e.g. identifier values, to their token kinds.
  mx::PersistentMap<0, Terminal, mx::TokenKind> tokens;

  // Set of all rules, in `body_0 ... body_n head` form. This allows for
  // easy left-corner scanning of rules. That is, if we have `body_0`, then
  // we can do a prefix scan for all production rules beginning with `body_0`.
  mx::PersistentSet<1, Rule> productions;

  // Tells us which fragments are likely to contain which syntax features.
  // The idea here is that as we import a fragment into the grammar, we build
  // up the grammar rules for all levels of the fragment AST. We can hash each
  // of these rules, and set bits in a fragment-specific Bloom filter. When
  // we want to do a search, e.g. "we want to find feature X and Y", we make the
  // bloom filter for X and we make it for Y, then compose them (bitwise OR) and
  // then exhaustively scan all fragment bloom filters to get a likely set of
  // fragments to do a deeper, tree-based match.
  mx::PersistentMap<2, mx::RawEntityId, SmallBloomFilter> features;

public:
  GrammarImpl(std::filesystem::path grammar_dir)
      : tokens(grammar_dir),
        productions(grammar_dir),
        features(grammar_dir) {}

  ~GrammarImpl(void) {}

  // Import a fragment into the grammar. This extends the persisted grammar with
  // the features from this fragment.
  void Import(const mx::Fragment &fragment);

  // Determine the kind of an identifier based on its spelling
  std::optional<mx::TokenKind> ClassifyIdent(std::string_view spelling) const;

  // Find all productions beginning with the specified non-terminal
  std::vector<Rule> MatchProductions(const NodeKind& start_nt) const;

  // Find all fragments that likely contain a set of features
  std::vector<mx::RawEntityId> LikelyFragments(const SmallBloomFilter &desired_features) const;
};

//
// Partial parse
//

struct PartialParse {
  SmallBloomFilter bf;
  const ASTNode *node;
  size_t next;

  PartialParse(const ASTNode *node_, size_t next_)
      : node(node_), next(next_) {}

  PartialParse(SmallBloomFilter bf_, const ASTNode *node_, size_t next_)
      : bf(bf_), node(node_), next(next_) {}

  const SmallBloomFilter &BloomFilter() const {
    return bf;
  }

  const ASTNode *Node() const {
    return node;
  }
};

//
// Parser state
//

class Item {
private:
  SmallBloomFilter bf;
  const NodeKind *cur, *end;
  std::vector<const ASTNode *> child_vector;

  Item(SmallBloomFilter bf_, const NodeKind *cur_, const NodeKind *end_)
      : bf(bf_),
        cur(cur_),
        end(end_) {}

public:

  Item(const Rule& rule)
      : cur(&rule.non_terminals.front()),
        end(&rule.non_terminals.back()) {
    // Item's bloom filter starts out with the results hash
    bf.Add(rule.Hash());
  }

  SmallBloomFilter BloomFilter() const {
    return bf;
  }

  bool AtEnd() const {
    return cur == end;
  }

  const NodeKind &Cur() const {
    return *cur;
  }

  Item Forward(const PartialParse &partial_parse) {
    assert(cur < end);
    Item new_item(bf, cur + 1, end);
    // Add the partial parse's bloom filter to the new item
    new_item.bf.Add(partial_parse.BloomFilter());
    // Add partial parse's result to the new item
    new_item.child_vector.insert(
        new_item.child_vector.end(),
        child_vector.begin(),
        child_vector.end());
    new_item.child_vector.push_back(partial_parse.Node());
    return new_item;
  }

  const ASTNode *ResultingNode(AST &ast) {
    const ASTNode *node;
    cur->Visit(Visitor {
        [&] (mx::DeclKind kind)  { node = ast.ConstructNode(kind, child_vector); },
        [&] (mx::StmtKind kind)  { node = ast.ConstructNode(kind, child_vector); },
        [&] (mx::TypeKind kind)  { node = ast.ConstructNode(kind, child_vector); },
        [&] (mx::TokenKind)      { assert(false); abort();                       },
    });
    return node;
  }
};

//
// Wrapper around parsing functions
//

class QueryImpl {
private:
  // GrammarImpl to be processed
  const GrammarImpl &m_grammar;

  // Input string
  std::string_view m_input;

  // Resulting AST
  AST m_ast;

  // Partial parses for each source location
  std::unordered_map<size_t, std::vector<PartialParse>> m_parses;

  void MatchRule(std::vector<PartialParse> &result, Item item, size_t position);

  void MatchPrefix(std::vector<PartialParse> &result, PartialParse partial_parse);

  const std::vector<PartialParse> &ParsesAtIndex(size_t index);

public:
  explicit QueryImpl(const GrammarImpl &grammar, std::string_view input);

  void Query(const mx::Index &index);
};

} // namespace syntex
