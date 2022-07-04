// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Grammar.h"

#include <cassert>
#include <iostream>
#include <unordered_set>

#include <gflags/gflags.h>
#include <multiplier/Index.h>
#include <multiplier/Endian.h>
#include <multiplier/PersistentMap.h>

DEFINE_bool(print_asts, false, "Should DOT digraphs of the ASTs be printed to CERR?");

namespace {

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

  bool Contains(SmallBloomFilter that) const noexcept {
    _Pragma("unroll") for (auto i = 0u; i < kNumWords; ++i) {
      if ((words[i] & that.words[i]) != that.words[i]) {
        return false;
      }
    }
    return true;
  }
};

}  // namespace
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

// Serialize a non-terminal. We need this for prefix (i.e. left corner) scans.
template <typename Reader, typename Writer>
struct Serializer<Reader, Writer, syntex::NonTerminal> {

  static constexpr bool kIsFixedSize = true;

  MX_FLATTEN static void Write(Writer &writer, syntex::NonTerminal nt) {
    Serializer<NullReader, Writer, unsigned short>::Write(writer, nt.val);
  }

  MX_FLATTEN static void Read(Reader &reader, syntex::NonTerminal &nt) {
    Serializer<Reader, NullWriter, unsigned short>::Read(reader, nt.val);
  }

  static constexpr uint32_t SizeInBytes(void) noexcept {
    return 2;
  }
};

// Serialize a rule, without any leading entry count.
template <typename Reader, typename Writer>
struct Serializer<Reader, Writer, syntex::Rule> {

  static constexpr bool kIsFixedSize = false;

  MX_FLATTEN static void Write(
      Writer &writer, const syntex::Rule &rule) {
    const auto size = static_cast<uint32_t>(rule.end - rule.begin);
    assert(0 < size);

    writer.EnterVariableSizedComposite(size);
    for (auto i = 0u; i < size; ++i) {
      Serializer<NullReader, Writer, unsigned short>::Write(
          writer, rule.begin[i].val);
    }
    writer.ExitComposite();
  }

  MX_FLATTEN static void Read(Reader &reader, syntex::Rule &out) {
    const auto size = reader.SizeLeft() / 2u;
    assert(0 < size);
    assert(!out.begin);

    out.begin = new syntex::NonTerminal[size];
    out.end = &(out.begin[size]);
    for (auto i = 0u; i < size; ++i) {
      Serializer<Reader, NullWriter, unsigned short>::Read(
          reader, out.begin[i].val);
    }
  }

  static constexpr uint32_t SizeInBytes(void) noexcept {
    return 0;
  }
};

// Serialize a small bloom filter.
template <typename Reader, typename Writer>
struct Serializer<Reader, Writer, SmallBloomFilter> {

  static constexpr bool kIsFixedSize = true;

  MX_FLATTEN static void Write(Writer &writer, const SmallBloomFilter &bf) {
    for (auto word : bf.words) {
      Serializer<NullReader, Writer, uint64_t>::Write(writer, word);
    }
  }

  MX_FLATTEN static void Read(Reader &reader, SmallBloomFilter &bf) {
    for (auto &word : bf.words) {
      Serializer<Reader, NullWriter, uint64_t>::Read(reader, word);
    }
  }

  static constexpr uint32_t SizeInBytes(void) noexcept {
    return sizeof(SmallBloomFilter);
  }
};

}  // namespace mx

namespace syntex {

namespace {

static NonTerminal NodeToNonTerminal(const ASTNode *node) {
  switch (node->kind) {
    default:
    case ASTNode::kFragment:
      assert(false);
      abort();
      break;
    case ASTNode::kDeclKind:
      return NonTerminal(static_cast<mx::DeclKind>(node->kind_val));
    case ASTNode::kStmtKind:
      return NonTerminal(static_cast<mx::StmtKind>(node->kind_val));
    case ASTNode::kTypeKind:
      return NonTerminal(static_cast<mx::TypeKind>(node->kind_val));
    case ASTNode::kTokenKind:
      return NonTerminal(static_cast<mx::TokenKind>(node->kind_val));
  }
}

static bool NodeIsComma(const ASTNode *node) {
  return node->kind == ASTNode::kTokenKind &&
         node->kind_val == static_cast<unsigned short>(mx::TokenKind::COMMA);
}

static bool NodeIsSemicolon(const ASTNode *node) {
  return node->kind == ASTNode::kTokenKind &&
         node->kind_val == static_cast<unsigned short>(mx::TokenKind::SEMI);
}

}  // namespace

NonTerminal::NonTerminal(mx::DeclKind k)
    : val(static_cast<unsigned short>(k)) {}

NonTerminal::NonTerminal(mx::StmtKind k)
    : val(static_cast<unsigned short>(k) +
          mx::NumEnumerators(mx::DeclKind{})) {}

NonTerminal::NonTerminal(mx::TypeKind k)
    : val(static_cast<unsigned short>(k) +
          mx::NumEnumerators(mx::DeclKind{}) +
          mx::NumEnumerators(mx::StmtKind{})) {}

NonTerminal::NonTerminal(mx::TokenKind k)
    : val(static_cast<unsigned short>(k) +
          mx::NumEnumerators(mx::DeclKind{}) +
          mx::NumEnumerators(mx::StmtKind{}) +
          mx::NumEnumerators(mx::TypeKind{})) {}

std::ostream& operator<<(std::ostream& os, const NonTerminal& nt) {
  if (nt.val < mx::NumEnumerators(mx::DeclKind{})) {
    os << "DeclKind::" << EnumeratorName(static_cast<mx::DeclKind>(nt.val));
  } else if (nt.val < mx::NumEnumerators(mx::DeclKind{})
                      + mx::NumEnumerators(mx::StmtKind{})) {
    os << "StmtKind::" << EnumeratorName(static_cast<mx::StmtKind>(nt.val
                                          - mx::NumEnumerators(mx::DeclKind{})));
  } else if (nt.val < mx::NumEnumerators(mx::DeclKind{})
                      + mx::NumEnumerators(mx::StmtKind{})
                      + mx::NumEnumerators(mx::TypeKind{})) {
    os << "TypeKind::" << EnumeratorName(static_cast<mx::TypeKind>(nt.val
                                          - mx::NumEnumerators(mx::DeclKind{})
                                          - mx::NumEnumerators(mx::StmtKind{})));
  } else {
    os << "TokenKind::" << EnumeratorName(static_cast<mx::TokenKind>(nt.val
                                          - mx::NumEnumerators(mx::DeclKind{})
                                          - mx::NumEnumerators(mx::StmtKind{})
                                          - mx::NumEnumerators(mx::TypeKind{})));
  }
  return os;
}

Rule::~Rule(void) {
  if (begin) {
    delete[] begin;
  }
}

// Hash a rule. This hash should be stable regardless of big/little endian.
uint64_t Rule::Hash(void) const {
  if MX_CONSTEXPR_ENDIAN (MX_LITTLE_ENDIAN) {
    std::string_view v(
        reinterpret_cast<const char *>(begin),
        static_cast<size_t>(end - begin) * sizeof(NonTerminal));
    return std::hash<std::string_view>{}(v);

  } else {
    abort();  // TODO(pag): Make an endian-independent hash.
  }
  return 0;
}

std::ostream& operator<<(std::ostream& os, const Rule& rule) {
  assert(rule.begin < rule.end);
  for (NonTerminal *cur = rule.begin; cur < rule.end - 1; ++cur) {
    os << *cur << " ";
  }
  os << "-> " << rule.end[-1];
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

mx::TokenKind Grammar::ClassifyIdent(std::string_view& spelling) const {
  // FIXME: this should really use some kind of heterogenous lookup instead of
  // constructing a temporary string
  Terminal terminal = { std::string(spelling) };
  auto kind = impl->tokens.TryGet(terminal);
  if (kind.has_value())
    return kind.value();
  else
    return mx::TokenKind::IDENTIFIER;
}

// Find all productions beginning with the specified non-terminal
std::vector<Rule> Grammar::MatchProductions(const NonTerminal& start_nt) const {
  std::vector<Rule> rules;
  impl->productions.ScanPrefix(start_nt, [&] (Rule rule) -> bool {
    rules.push_back(std::move(rule));
    return true;
  });
  return rules;
}

// Import a fragment into the grammar.
void Grammar::Import(const mx::Fragment &fragment) {
  auto ast = AST::Build(fragment);

  // TODO(pag): Eventually remove; nifty for debugging.
  if (FLAGS_print_asts) {
    ast.PrintDOT(std::cerr);
  }

  std::vector<const ASTNode *> nodes;
  nodes.emplace_back(ast.Root());

  SmallBloomFilter fragment_features;

  // Make a production rule for every node and its children.
  while (!nodes.empty()) {
    const ASTNode *node = nodes.back();
    nodes.pop_back();

    // This is a token kind node, and represents a terminal. We want to map
    // the contents of the token to the actual kind of the token.
    if (std::holds_alternative<std::string>(node->data)) {
      assert(node->kind == ASTNode::kTokenKind);
      Terminal term;
      term.data = std::get<std::string>(node->data);
      impl->tokens.Set(std::move(term),
                       static_cast<mx::TokenKind>(node->kind_val));

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
    } else if (std::holds_alternative<ASTNode::ChildVector>(node->data)) {
      assert(node->kind != ASTNode::kTokenKind);

      auto &children = std::get<ASTNode::ChildVector>(node->data);
      const auto num_children = children.size();

      // Add the child nodes to the work list.
      nodes.insert(nodes.end(), children.begin(), children.end());

      if (node->kind == ASTNode::kFragment) {
        continue;
      }

      Rule rule(num_children + 1u);
      for (auto i = 0u; i < num_children; ++i) {
        rule.begin[i] = NodeToNonTerminal(children[i]);
      }

      rule.begin[num_children] = NodeToNonTerminal(node);  // Rule head.

      // Avoid creating cyclic CFGs
      bool allow_production = true;
      if (num_children == 1) {
        std::vector<NonTerminal> queue = { rule.Result() };
        while (queue.size() > 0) {
          auto nt = queue.back();
          queue.pop_back();
          // Check for cycle
          if (nt == rule.begin[0]) {
            allow_production = false;
            break;
          }
          // Queue result of trivial productions
          for (auto& cur : MatchProductions(nt))
            if (cur.Count() == 1)
              queue.push_back(cur.Result());
        }
      }

      if (allow_production) {
        std::cout << rule << "\n";

        // Add our rule feature to the fragment's feature set.
        fragment_features.Add(rule.Hash());
        // Persist, i.e. "learn" our grammar rule.
        impl->productions.Insert(std::move(rule));
      }
    }
  }

  impl->features.Set(fragment.id(), fragment_features);
}

//
// Parser item
//

struct Item {
  NonTerminal *cur, *end;

  Item(const Rule& rule) : cur(rule.begin), end(rule.end - 1) {}
  Item(NonTerminal *c, NonTerminal* e) : cur(c), end(e) {}

  bool AtEnd() const {
    return cur == end;
  }

  const NonTerminal& Cur() const {
    return *cur;
  }

  Item Forward() {
    assert(cur < end);
    return Item(cur + 1, end);
  }
};

//
// Parsed fragment
//

struct Fragment {
  NonTerminal non_terminal;
  size_t next;

  Fragment(NonTerminal nt, size_t n) : non_terminal(nt), next(n) {}
};

//
// Wrapper around parsing functions
//

class Parser {
private:
  // Grammar to be processed
  const Grammar& m_grammar;

  // Input tokens
  std::unordered_map<size_t, std::vector<Token>> m_tokens;

  // Partial parses for each source location
  // std::unordered_map<size_t, std::vector<Fragment>> m_parses;

public:
  Parser(const Grammar& grammar, const std::vector<Token>& tokens)
    : m_grammar(grammar)
  {
    for (auto& token : tokens)
      m_tokens[token.begin].push_back(token);
  }

  std::vector<Fragment> MatchRule(Item item, size_t position) const {
    // Try to match the result as a new prefix
    if (item.AtEnd())
      return MatchPrefix(Fragment(item.Cur(), position));

    // Otherwise see if we can move forward with this rule
    std::vector<Fragment> result;
    for (auto& frag : ParsesAtIndex(position))
      if (frag.non_terminal == item.Cur()) {
        auto matches = MatchRule(item.Forward(), frag.next);
        result.insert(result.end(), matches.begin(), matches.end());
      }
    return result;
  }

  std::vector<Fragment> MatchPrefix(Fragment frag) const {
    std::vector<Fragment> result;

    for (auto& rule : m_grammar.MatchProductions(frag.non_terminal)) {
      // Find all possible ways we can match this grammar rule
      auto matches = MatchRule(Item(rule).Forward(), frag.next);
      result.insert(result.end(), matches.begin(), matches.end());
    }

    // Add the input fragment itself
    result.push_back(frag);

    return result;
  }

  std::vector<Fragment> ParsesAtIndex(size_t index) const {
    auto it = m_tokens.find(index);
    if (it == m_tokens.end())
      return {};

    std::vector<Fragment> result;

    for (auto& token : it->second) {
      auto matches = MatchPrefix(Fragment(NonTerminal(token.kind), token.next));
      result.insert(result.end(), matches.begin(), matches.end());
    }

    return result;
  }

  void Parse() {
    //
    // Start computing parses at index 0
    //
    auto fragments = ParsesAtIndex(0);

    //
    // Then print the result
    //
    std::cout << "-------------------\n";
    for (auto& frag : fragments)
      std::cout << "  " << frag.non_terminal << "\n";
    std::cout << "-------------------\n";
  }
};

void Parse(const Grammar& grammar, const std::vector<Token>& tokens) {
  Parser parser(grammar, tokens);
  parser.Parse();
}

}  // namespace syntex
