// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Syntex.h"
#include "Private.h"

namespace mx {

// Serialize a small bloom filter.
template <typename Reader, typename Writer>
struct Serializer<Reader, Writer, syntex::SmallBloomFilter> {

  static constexpr bool kIsFixedSize = true;

  MX_FLATTEN static void Write(Writer &writer, const syntex::SmallBloomFilter &bf) {
    for (auto word : bf.words) {
      Serializer<NullReader, Writer, uint64_t>::Write(writer, word);
    }
  }

  MX_FLATTEN static void Read(Reader &reader, syntex::SmallBloomFilter &bf) {
    for (auto &word : bf.words) {
      Serializer<Reader, NullWriter, uint64_t>::Read(reader, word);
    }
  }

  static constexpr uint32_t SizeInBytes(void) noexcept {
    return sizeof(syntex::SmallBloomFilter);
  }
};

// Serialize token data without a leading size.
template <typename Reader, typename Writer>
struct Serializer<Reader, Writer, syntex::Terminal> {

  static constexpr bool kIsFixedSize = false;

  MX_FLATTEN static void Write(Writer &writer, const syntex::Terminal &tok) {
    const auto size = static_cast<uint32_t>(tok.data.size());
    assert(0 < size);
    writer.EnterVariableSizedComposite(size);

    // NOTE(pag): Induction variable based `for` loop so that a byte counting
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
      out.non_terminals.push_back(syntex::NodeKind::Deserialize(val));
    }
  }

  static constexpr uint32_t SizeInBytes(void) noexcept {
    return 0;
  }
};

}  // namespace mx

namespace syntex {

// This is the 64-bit variant FNV-1a by Glenn Fowler, et al
uint64_t Rule::Hash(void) const {
  uint64_t hash = 0xcbf29ce484222325ULL;
  for (const NodeKind &nt : non_terminals) {
      hash ^= nt.Serialize();
      hash *= 0x100000001b3ULL;
  }
  return hash;
}

std::ostream& operator<<(std::ostream& os, const Rule& rule) {
  auto it = rule.non_terminals.begin();
  while (it < rule.non_terminals.end() - 1) {
    os << *it++ << " ";
  }
  os << "-> " << *it;
  return os;
}

// Determine the kind of an identifier based on its spelling
std::optional<mx::TokenKind> GrammarImpl::ClassifyIdent(std::string_view spelling) const {
  auto kind = tokens.TryGet({ std::string(spelling) });
  if (kind.has_value() && *kind != mx::TokenKind::IDENTIFIER) {
    return kind.value();
  } else {
    return {};
  }
}

// Find all productions beginning with the specified non-terminal
std::vector<Rule> GrammarImpl::MatchProductions(const NodeKind& start_nt) const {
  std::vector<Rule> rules;
  productions.ScanPrefix(start_nt.Serialize(), [&] (Rule rule) -> bool {
    rules.push_back(std::move(rule));
    return true;
  });
  return rules;
}

// Find all fragments that likely contain a set of features
std::vector<mx::RawEntityId> GrammarImpl::LikelyFragments(const SmallBloomFilter &desired_features) const {
  std::vector<mx::RawEntityId> ids;
  features.ScanPrefix(mx::Empty(), [&] (mx::RawEntityId id, SmallBloomFilter bf) -> bool {
    if (bf.Contains(desired_features))
      ids.push_back(id);
    return true;
  });
  return ids;
}

// Import a fragment into the grammar.
void GrammarImpl::Import(const mx::Fragment &fragment) {
  auto ast = AST::Build(fragment);

/*
  // Debug graphs
  std::stringstream name;
  name << "dot/ast_" << fragment.id() << ".dot";
  std::fstream fs(name.str(), std::fstream::out | std::fstream::trunc);
  ast.PrintDOT(fs);
  fs.close();

*/

  std::vector<const ASTNode *> nodes(ast.Root());
  SmallBloomFilter fragment_features;

  // Make a production rule for every node and its children.
  while (!nodes.empty()) {
    const ASTNode *node = nodes.back();
    nodes.pop_back();

    // This is a token kind node, and represents a terminal. We want to map
    // the contents of the token to the actual kind of the token.
    if (node->Kind().IsToken()) {
      tokens.Set({ node->Spelling() }, node->Kind().AsToken());

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
      std::vector<NodeKind> non_terminals;
      non_terminals.reserve(num_children + 1);
      for (auto i = 0u; i < num_children; ++i) {    // Rule body
        non_terminals.push_back(children[i]->Kind());
      }
      non_terminals.push_back(node->Kind());        // Rule head

      // Avoid creating cyclic CFGs
      bool allow_production = true;
      if (num_children == 1) {
        std::vector<NodeKind> queue = { non_terminals.back() };
        while (!queue.empty()) {
          auto nt = queue.back();
          queue.pop_back();
          // Check for cycle
          if (nt == non_terminals.front()) {
            allow_production = false;
            break;
          }
          // Queue result of trivial productions
          for (auto& cur : MatchProductions(nt)) {
            if (cur.non_terminals.size() == 2) {
              queue.push_back(cur.non_terminals.back());
            }
          }
        }
      }

      if (allow_production) {
        Rule rule(non_terminals);
        // Add our rule feature to the fragment's feature set.
        fragment_features.Add(rule.Hash());
        // Persist, i.e. "learn" our grammar rule.
        productions.Insert(std::move(rule));
      }
    }
  }

  features.Set(fragment.id(), fragment_features);
}

Grammar::Grammar(std::filesystem::path grammar_dir)
  : impl(std::make_shared<GrammarImpl>(grammar_dir)) {}

void Grammar::Import(const mx::Fragment &fragment) {
  impl->Import(fragment);
}

}  // namespace syntex
