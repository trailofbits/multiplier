// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Grammar.h"

#include <cassert>

#include <gflags/gflags.h>
#include <multiplier/API.h>
#include <multiplier/Endian.h>
#include <multiplier/PersistentMap.h>

#include "AST.h"

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
    case ASTNode::kFragment:
      assert(false);
      abort();
      break;
    case ASTNode::kDeclKind:
      return NonTerminal(static_cast<mx::DeclKind>(node->kind_val));
    case ASTNode::kStmtKind:
      return NonTerminal(static_cast<mx::StmtKind>(node->kind_val));
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
          static_cast<unsigned short>(mx::DeclKind::NUM_ENUMERATORS)) {}

NonTerminal::NonTerminal(mx::TokenKind k)
    : val(static_cast<unsigned short>(k) +
          static_cast<unsigned short>(mx::DeclKind::NUM_ENUMERATORS) +
          static_cast<unsigned short>(mx::StmtKind::NUM_ENUMERATORS)) {}

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
  mx::PersistentMap<2, mx::FragmentId, SmallBloomFilter> features;

  inline GrammarImpl(std::filesystem::path grammar_dir)
      : tokens(grammar_dir),
        productions(grammar_dir),
        features(grammar_dir) {}
};

Grammar::~Grammar(void) {}

Grammar::Grammar(std::filesystem::path grammar_dir)
    : impl(std::make_shared<GrammarImpl>(std::move(grammar_dir))) {}

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

      // Process the children of this node. We want to do some kind of pre-
      // processing of semicolon and comma-separated things here. A basic
      // treatment of this AST node and it's children would take the following:
      //
      //        .-- A --.
      //       /\  /\  /|\
      //      ( B , C , D )
      //
      // And convert it into a rule of the form:
      //
      //      ( B , C , D ) A
      //
      // But what we'd like is something more along the lines of:
      //
      //      ( A_comma ) A
      //
      //      B A_comma
      //      C A_comma
      //      D A_comma
      //
      // Where an `A_comma` is a special "comma" type that allows us to know
      // in a search procedure that we can have more than one of them besides
      // each-other.
      //
      // This is all a bit tricky, as it means finding reasonable "stop" nodes
      // or tokens at boundaries (e.g. parens, brackets, braces). This is really
      // a kind of rule summarization / compression procedure.
      for (auto i = 0u; i < num_children; ++i) {
        const ASTNode *child = children[i];
        nodes.push_back(child);

//        if (NodeIsComma(child) || NodeIsSemicolon(child)) {
//          continue;
//        }
//
//        bool is_comma = false;
//        bool is_semi = false;
//        if (i) {
//          const ASTNode *prev_child = children[i - 1u];
//          is_comma = NodeIsComma(prev_child);
//          is_semi = NodeIsSemicolon(prev_child);
//        }
//
//        if ((i + 1u) < num_children) {
//          const ASTNode *next_child = children[i + 1u];
//          is_comma = is_comma || NodeIsComma(next_child);
//          is_semi = is_semi || NodeIsSemicolon(next_child);
//        }
//
//        // E.g. `B` in `A, B;`.
//        if (is_comma && is_semi) {
//
//        // E.g. either `A` or `B` in `(A, B)`.
//        } else if (is_comma) {
//
//        // E.g. `B` in `A = B;`.
//        } else if (is_semi) {
//
//        } else {
//          nodes_for_rule.push_back(node);
//        }

        ++i;
      }

      if (node->kind == ASTNode::kFragment) {
        continue;
      }

      Rule rule(num_children + 1u);
      for (auto i = 0u; i < num_children; ++i) {
        rule.begin[i] = NodeToNonTerminal(children[i]);
      }

      rule.begin[num_children] = NodeToNonTerminal(node);  // Rule head.

      // Add our rule feature to the fragment's feature set.
      fragment_features.Add(rule.Hash());

      // Persist, i.e. "learn" our grammar rule.
      impl->productions.Insert(std::move(rule));
    }
  }

  impl->features.Set(fragment.id(), fragment_features);
}

}  // namespace syntex
