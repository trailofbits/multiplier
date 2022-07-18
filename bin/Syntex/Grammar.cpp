// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Grammar.h"
#include "BloomFilter.h"

#include <cassert>
#include <fstream>
#include <iostream>
#include <unordered_set>

#include <gflags/gflags.h>
#include <multiplier/Index.h>
#include <multiplier/PersistentMap.h>

DECLARE_bool(print_asts);

namespace mx {

// Serialize token data without a leading size.
template <typename Reader, typename Writer>
struct Serializer<Reader, Writer, syntex::Terminal> {

  static constexpr bool kIsFixedSize = false;

  MX_FLATTEN static void Write(Writer &writer, const syntex::Terminal &tok) {
    const auto size = static_cast<uint32_t>(tok.data.size());
    assert(0 < size);
    writer.EnterVariableSizedComposite(size);

    // NOTE(pag): Induction variable based `for` loop so that a a byte counting
    //            writer can elide the `for` loop entirely and count `size`.
    for (auto ch : tok.data) {
      Serializer<NullReader, Writer, char>::Write(writer, ch);
    }

    writer.ExitComposite();
  }

  MX_FLATTEN static void Read(Reader &reader, syntex::Terminal &out) {
    const auto size = reader.SizeLeft();
    assert(0 < size);
    out.data.resize(size);
    for (auto i = 0u; i < size; ++i) {
      Serializer<Reader, NullWriter, char>::Read(reader, out.data[i]);
    }
  }

  static constexpr uint32_t SizeInBytes(void) noexcept {
    return 0;
  }
};

// Serialize a rule, without any leading entry count.
template <typename Reader, typename Writer>
struct Serializer<Reader, Writer, syntex::Rule> {

  static constexpr bool kIsFixedSize = false;

  MX_FLATTEN static void Write(Writer &writer, const syntex::Rule &rule) {
    const auto size = rule.non_terminals.size();
    assert(0 < size);

    writer.EnterVariableSizedComposite(size);
    for (auto& nt : rule.non_terminals) {
      Serializer<NullReader, Writer, unsigned short>::Write(writer, nt.Serialize());
    }
    writer.ExitComposite();
  }

  MX_FLATTEN static void Read(Reader &reader, syntex::Rule &out) {
    const auto size = reader.SizeLeft() / 2u;
    assert(0 < size);

    out.non_terminals.reserve(size);
    for (auto i = 0u; i < size; ++i) {
      unsigned short val;
      Serializer<Reader, NullWriter, unsigned short>::Read(reader, val);
      out.non_terminals.push_back(syntex::NonTerminal::Deserialize(val));
    }
  }

  static constexpr uint32_t SizeInBytes(void) noexcept {
    return 0;
  }
};

}  // namespace mx

namespace syntex {

std::ostream& operator<<(std::ostream& os, const NonTerminal& nt) {
  nt.Visit(Visitor {
    [&] (mx::DeclKind kind)  { os << "DeclKind::" << EnumeratorName(kind);   },
    [&] (mx::StmtKind kind)  { os << "StmtKind::" << EnumeratorName(kind);   },
    [&] (mx::TypeKind kind)  { os << "TypeKind::" << EnumeratorName(kind);   },
    [&] (mx::TokenKind kind) { os << "TokenKind::" << EnumeratorName(kind);  },
  });
  return os;
}

// This is the 64-bit variant FNV-1a by Glenn Fowler, et al
uint64_t Rule::Hash(void) const {
  uint64_t hash = 0xcbf29ce484222325ULL;
  for (const NonTerminal &nt : non_terminals) {
      hash ^= nt.Serialize();
      hash *= 0x100000001b3ULL;
  }
  return hash;
}

std::ostream& operator<<(std::ostream& os, const Rule& rule) {
  auto it = rule.non_terminals.begin();
  while (it < rule.non_terminals.end() - 1)
    os << *it++ << " ";
  os << "-> " << *it;
  return os;
}

class GrammarImpl {
 public:
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

  inline GrammarImpl(std::filesystem::path grammar_dir)
      : tokens(grammar_dir),
        productions(grammar_dir),
        features(grammar_dir) {}
};

Grammar::~Grammar(void) {}

Grammar::Grammar(std::filesystem::path grammar_dir)
    : impl(std::make_shared<GrammarImpl>(std::move(grammar_dir))) {}

// Determine the kind of an identifier based on its spelling
std::optional<mx::TokenKind> Grammar::ClassifyIdent(std::string_view spelling) const {
  auto kind = impl->tokens.TryGet({ std::string(spelling) });
  if (kind.has_value() && *kind != mx::TokenKind::IDENTIFIER)
    return kind.value();
  else
    return {};
}

// Find all productions beginning with the specified non-terminal
std::vector<Rule> Grammar::MatchProductions(const NonTerminal& start_nt) const {
  std::vector<Rule> rules;
  impl->productions.ScanPrefix(start_nt.Serialize(), [&] (Rule rule) -> bool {
    rules.push_back(std::move(rule));
    return true;
  });
  return rules;
}

// Find all fragments that likely contain a set of features
std::vector<mx::RawEntityId> Grammar::LikelyFragments(const SmallBloomFilter &desired_features) const {
  std::vector<mx::RawEntityId> ids;
  impl->features.ScanPrefix(mx::Empty(), [&] (mx::RawEntityId id, SmallBloomFilter bf) -> bool {
    if (bf.Contains(desired_features))
      ids.push_back(id);
    return true;
  });
  return ids;
}

// Import a fragment into the grammar.
void Grammar::Import(const mx::Fragment &fragment) {
/*
  std::cout << "Importing fragment " << fragment.id() << "\n";
*/

  auto ast = AST::Build(fragment);

/*
  // Debug graphs
  std::stringstream name;
  name << "dot/ast_" << fragment.id() << ".dot";
  std::fstream fs(name.str(), std::fstream::out | std::fstream::trunc);
  ast.PrintDOT(fs);
  fs.close();

*/

  // TODO(pag): Eventually remove; nifty for debugging.
  if (FLAGS_print_asts) {
    ast.PrintDOT(std::cerr);
  }

  std::vector<const ASTNode *> nodes(ast.Root());
  SmallBloomFilter fragment_features;

  // Make a production rule for every node and its children.
  while (!nodes.empty()) {
    const ASTNode *node = nodes.back();
    nodes.pop_back();

    // This is a token kind node, and represents a terminal. We want to map
    // the contents of the token to the actual kind of the token.
    if (node->Kind().IsToken()) {
      impl->tokens.Set({ node->Spelling() }, node->Kind().AsToken());

    // This is an internal or root node. E.g. given the following:
    //
    //                A
    //              / | \
    //             B  C  D
    //
    // We want to make a rule of the form `B C D A`, i.e. if you match `B C D`
    // then you have matched an `A`. This "backward" syntax enables us to prefix
    // scan for left corners (`B` in this case) and find all rules starting with
    // `B`.
    } else {
      auto &children = node->ChildVector();
      size_t num_children = children.size();
      assert(num_children >= 1);

      // Add the child nodes to the work list.
      nodes.insert(nodes.end(), children.begin(), children.end());

      // Create list of non-terminals for the rule
      std::vector<NonTerminal> non_terminals;
      non_terminals.reserve(num_children + 1);
      for (auto i = 0u; i < num_children; ++i)      // Rule body
        non_terminals.push_back(children[i]->Kind());
      non_terminals.push_back(node->Kind());        // Rule head

      // Avoid creating cyclic CFGs
      bool allow_production = true;
      if (num_children == 1) {
        std::vector<NonTerminal> queue = { non_terminals.back() };
        while (queue.size() > 0) {
          auto nt = queue.back();
          queue.pop_back();
          // Check for cycle
          if (nt == non_terminals.front()) {
            allow_production = false;
            break;
          }
          // Queue result of trivial productions
          for (auto& cur : MatchProductions(nt))
            if (cur.non_terminals.size() == 2)
              queue.push_back(cur.non_terminals.back());
        }
      }

      if (allow_production) {
        Rule rule(non_terminals);
        // Add our rule feature to the fragment's feature set.
        fragment_features.Add(rule.Hash());
        // Persist, i.e. "learn" our grammar rule.
        impl->productions.Insert(std::move(rule));
      }
    }
  }

  impl->features.Set(fragment.id(), fragment_features);
}

}  // namespace syntex
