// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Context.h"

#include <algorithm>
#include <capnp/common.h>
#include <capnp/message.h>
#include <capnp/serialize.h>
#include <fstream>
#include <glog/logging.h>
#include <iostream>
#include <kj/io.h>
#include <multiplier/AST.h>
#include <multiplier/AST.capnp.h>
#include <multiplier/RPC.capnp.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/File.h>
#include <sstream>
#include <utility>
#include <unordered_set>

// NOTE(pag): We use the UTF-8 functions from the `llvm::json` namespace.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wshadow"
#pragma clang diagnostic ignored "-Wcast-align"
#include <llvm/Support/JSON.h>
#pragma clang diagnostic pop

#ifndef MX_DISABLE_VAST
# include "Codegen.h"
#endif

#include "EntityMapper.h"
#include "PASTA.h"
#include "PendingFragment.h"
#include "Provenance.h"
#include "ProgressBar.h"
#include "Util.h"

namespace capnp {
class MallocMessageBuilder;
}  // namespace capnp
namespace mx {
namespace rpc {
class Fragment;
}  // namespace rpc
}  // namespace mx
namespace indexer {
class TokenTree;
class TokenTreeNode;
class TokenTreeNodeRange;

// Dispatch to the right macro serializer.
extern void DispatchSerializeMacro(const PendingFragment &pf,
                                   mx::ast::Macro::Builder builder,
                                   const pasta::Macro &entity,
                                   const TokenTree *tt);

// Build the fragment. This fills out the decls/stmts/types to serialize.
//
// NOTE(pag): Implemented in `BuildPendingFragment.cpp`.
extern void BuildPendingFragment(PendingFragment &pf);

// Label the parent entity ids.
extern void LabelParentsInPendingFragment(PendingFragment &pf);

// Label tokens and macros.
extern void LabelTokensAndMacrosInFragment(PendingFragment &pf);

// Store information persistently to enable linking of declarations across
// fragments.
extern void LinkEntitiesAcrossFragments(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    const NameMangler &mangler);

// Identify all unique entity IDs referenced by this fragment,
// and map them to the fragment ID in the data store.
extern void LinkExternalReferencesInFragment(
    const pasta::AST &ast, mx::DatabaseWriter &database,
    const PendingFragment &pf);

// Serialize all entities into the Cap'n Proto version of the fragment.
extern void SerializePendingFragment(mx::DatabaseWriter &database,
                                     const PendingFragment &pf);

// Save the symbolic names of all declarations into the database.
extern void LinkEntityNamesToFragment(
    mx::DatabaseWriter &db, const PendingFragment &pf);

extern void PersistTokenContexts(
    const EntityMapper &em, const pasta::PrintedTokenRange &parsed_tokens,
    mx::RawEntityId frag_index, mx::rpc::Fragment::Builder &fb);

namespace {

using MacroBuilder = mx::ast::Macro::Builder;

using MacroListBuilder =
    capnp::List<mx::ast::Macro, capnp::Kind::STRUCT>::Builder;

using TokenKindListBuilder =
    capnp::List<uint16_t, ::capnp::Kind::PRIMITIVE>::Builder;

using TokenOffsetListBuilder =
    capnp::List<uint32_t, ::capnp::Kind::PRIMITIVE>::Builder;

using TokenIdListBuilder =
    capnp::List<uint64_t, ::capnp::Kind::PRIMITIVE>::Builder;

}  // namespace


// Persist a file. Our representation includes stuff not in the file to enable
// us to improve performance of common operations, like search. That is, we
// could store a file as a list of tokens, where each token has its own data;
// however, we want to able to run regular expression searches over files, and
// so it's convenient to not have to reconstruct the file data from the tokens
// for every such query. Similarly, we often want to map from matches in files
// to matches in fragments, and so we create and persist a mapping of file
// offsets to line numbers here to help us with those translations later.
void GlobalIndexingState::PersistFile(
    mx::SpecificEntityId<mx::FileId> file_id, const pasta::File &file) {

  ProgressBarWork progress_tracker(file_progress);

  std::filesystem::path file_path = file.Path();
  auto maybe_file_data = file.Data();
  LOG_IF(FATAL, !maybe_file_data.Succeeded())
      << "No data for file " << file_path.generic_string()
      << ": " << maybe_file_data.TakeError();

  pasta::FileTokenRange file_tokens = file.Tokens();
  std::string_view file_data = maybe_file_data.TakeValue();
  capnp::MallocMessageBuilder message;
  mx::rpc::File::Builder fb = message.initRoot<mx::rpc::File>();

  std::string utf8_file_data;
  utf8_file_data.reserve(file_data.size());

  // Encode the token kinds and the offsets of token data. We can't be certain
  // that the file is in UTF-8, so we re-build the contents on a per-token
  // basis, because that's the only way to guarantee token offsets in the
  // presence of UTF-8 issues.
  auto num_tokens = static_cast<unsigned>(file_tokens.Size());
  auto tkb = fb.initTokenKinds(num_tokens);
  auto tob = fb.initTokenOffsets(num_tokens + 1u);
  auto i = 0u;
  for (pasta::FileToken ft : file_tokens) {
    tkb.set(i, static_cast<unsigned short>(TokenKindFromPasta(ft)));
    tob.set(i, static_cast<unsigned>(utf8_file_data.size()));
    AccumulateTokenData(utf8_file_data, ft);
    i += 1u;
  }
  tob.set(i, static_cast<unsigned>(utf8_file_data.size()));

  // Cap'n Proto requires that `Text`-typed data is UTF-8.
  fb.setData(utf8_file_data);

  // Build up and serialize a mapping of offsets of the last byte in a line to
  // line numbers. This mapping is used during regular expression matches over
  // file contents to help us map to fragments whose code is derived from those
  // files.
  std::map<unsigned, unsigned> eol_offset_to_line_num;
  auto line = 1u;
  auto offset = 0u;
  for (char ch : file_data) {
    ++offset;
    CHECK_NE(ch, '\r');
    if ('\n' == ch) {
      eol_offset_to_line_num.emplace(offset, line);
      ++line;
    }
  }

  i = 0u;
  auto ublb = fb.initEolOffsets(static_cast<unsigned>(
      eol_offset_to_line_num.size()));
  for (auto eol_offset_line_num : eol_offset_to_line_num) {
    mx::rpc::UpperBound::Builder ubb = ublb[i++];
    ubb.setOffset(eol_offset_line_num.first);
    ubb.setVal(eol_offset_line_num.second);
  }

  // Add it to the database.
  auto fp = file_path.lexically_normal().generic_string();
  database.AddAsync(
      mx::FilePathRecord{file_id, fp},
      mx::NamedEntityRecord{file_id.Pack(), fp},
      mx::EntityRecord{file_id.Pack(), GetSerializedData(message)});
}

namespace {

// Intermediate children include things like parameter-to argument
// substitutions, stringization, and uses of `__VA_OPT__`. They might point
// into the macro body itself, rather than the expansion, so make sure only
// to collect them if they are owned by the expansion.
static std::optional<pasta::MacroRange> IntermediateChildren(
    const pasta::Macro &macro) {
  if (auto exp = pasta::MacroExpansion::From(macro)) {
    pasta::MacroRange children = exp->IntermediateChildren();
    for (pasta::Macro child : children) {
      if (child.Parent()->RawMacro() == exp->RawMacro()) {
        return children;
      }
    }
  }
  return std::nullopt;
}

// Schedules the order of serialization of tokens derived from the token tree.
// The main goal is for all tokens in the final expansion, i.e. all parsed
// tokens, to be adjacent. The token tree code also tries to inject whitespace
// that was originall missing between those parsed tokens, so we want to see
// those too.
struct TokenTreeSerializationSchedule {
  struct Todo {
    const void *parent;
    mx::RawEntityId parent_id;
    TokenTreeNodeRange nodes;
  };

  PendingFragment &pf;
  EntityMapper &em;

  std::vector<Todo> todo_list;
  std::vector<TokenTreeNode> tokens;

  // Index of a parsed token in `replacement_tokens`.
  std::unordered_map<const void *, size_t> parsed_token_index;

  // Maps parsed tokens to the macro in which they are contained.
  std::vector<mx::RawEntityId> containing_macro;

  mx::RawEntityId RecordEntityId(const TokenTree &tt,
                                 bool &is_part_of_fragment) {

    const void *raw_tt = tt.RawNode();
    const void *raw_locator = raw_tt;
    std::optional<pasta::Macro> macro = tt.Macro();
    if (macro) {
      CHECK(tt.Kind() == mx::FromPasta(macro->Kind()));
      raw_locator = macro->RawMacro();
    }

    mx::RawEntityId raw_id = em.EntityId(raw_locator);

    // NOTE(pag): This is some collusion with `EntityLabeller::Label` in terms
    //            of labelling the top-level macros. This also happens with
    //            nested macro directives.
    if (raw_id != mx::kInvalidEntityId) {
      CHECK_NE(raw_tt, raw_locator);
      mx::MacroId id = std::get<mx::MacroId>(mx::EntityId(raw_id).Unpack());
      CHECK(id.kind == tt.Kind());

      is_part_of_fragment = id.fragment_id == pf.fragment_index;
      if (is_part_of_fragment) {
        CHECK_LT(id.offset, pf.macros_to_serialize.size());
        CHECK(!pf.macros_to_serialize[id.offset].has_value());
        pf.macros_to_serialize[id.offset] = tt;
      }

    // We need to form a new macro id for something we discovered along the way.
    } else {
      mx::MacroId id;
      id.fragment_id = pf.fragment_index;
      id.kind = tt.Kind();
      id.offset = static_cast<unsigned>(pf.macros_to_serialize.size());
      raw_id = mx::EntityId(id).Pack();

      // Add it to our to-serialize list.
      pf.macros_to_serialize.push_back(tt);
    }

    // Save the ID, mapped from both the token tree and the underlying
    // macro, if any.
    CHECK(em.token_tree_ids.emplace(raw_tt, raw_id).second);
    if (raw_tt != raw_locator) {
      (void) em.token_tree_ids.emplace(raw_locator, raw_id);
    }
    return raw_id;
  }

  mx::RawEntityId RecordEntityId(const TokenTreeNode &node,
                                 mx::RawEntityId parent_id,
                                 bool &is_part_of_fragment) {
    mx::RawEntityId raw_id = mx::kInvalidEntityId;

    if (std::optional<TokenTree> sub = node.SubTree()) {
      raw_id = RecordEntityId(sub.value(), is_part_of_fragment);

    // Fill in IDs for derived tokens.
    } else {
      mx::MacroTokenId id;
      id.kind = mx::TokenKind::UNKNOWN;
      id.fragment_id = pf.fragment_index;
      id.offset = static_cast<unsigned>(tokens.size());

      const void *raw_pt = nullptr;

      if (std::optional<pasta::PrintedToken> pt = node.PrintedToken()) {
        id.kind = TokenKindFromPasta(pt.value());
        raw_pt = pt->RawToken();
        CHECK(em.token_tree_ids.contains(raw_pt));
        CHECK(parsed_token_index.emplace(raw_pt, id.offset).second);

      } else if (std::optional<pasta::Token> mt = node.Token()) {
        id.kind = TokenKindFromPasta(mt.value());
        raw_pt = mt->RawToken();
        DCHECK(!IsParsedToken(mt.value()) == !em.token_tree_ids.count(raw_pt));

      } else if (std::optional<pasta::FileToken> ft = node.FileToken()) {
        id.kind = TokenKindFromPasta(ft.value());
      }

      raw_id = mx::EntityId(id).Pack();
      if (raw_pt) {
        em.token_tree_ids.emplace(raw_pt, raw_id);
      }

      containing_macro.push_back(parent_id);
      tokens.emplace_back(node);
    }

    CHECK_NE(raw_id, mx::kInvalidEntityId);
    CHECK(em.token_tree_ids.emplace(node.RawNode(), raw_id).second);
    return raw_id;
  }

  // Schedule the expansions so that all "afters" are properly nested. We want
  // this so that `fragment.parsed_tokens().data()` reflects the final result
  // of macro expansion.
  void Schedule(const void * /* parent */, mx::RawEntityId parent_id,
                const TokenTreeNodeRange &nodes) {

    for (TokenTreeNode node : nodes) {

      bool is_part_of_fragment = true;
      mx::RawEntityId child_id = RecordEntityId(node, parent_id,
                                                is_part_of_fragment);

      // If this is a macro directive that is nested inside of another fragment,
      // then assume that we've already extracted the directive from that other
      // fragment and persisted it.
      if (!is_part_of_fragment) {
        continue;
      }

      if (std::optional<TokenTree> sub = node.SubTree()) {

        const void *child = sub->RawNode();
        if (sub->HasExpansion()) {
          Schedule(child, child_id, sub->ReplacementChildren());
          if (sub->HasIntermediateChildren()) {
            todo_list.emplace_back(
                Todo{child, child_id, sub->IntermediateChildren()});
          }
          todo_list.emplace_back(Todo{child, child_id, sub->Children()});
        } else {
          Schedule(child, child_id, sub->Children());
        }
      }
    }
  }

  void Schedule(const Todo &todo) {
    Schedule(todo.parent, todo.parent_id, todo.nodes);
  }

  void Schedule(TokenTreeNodeRange nodes) {
    Schedule(nullptr, mx::kInvalidEntityId, std::move(nodes));
    for (auto i = 0u; i < todo_list.size(); ++i) {
      Schedule(todo_list[i]);
    }
  }

  TokenTreeSerializationSchedule(PendingFragment &pf_)
      : pf(pf_),
        em(pf_.em) {}
};

static void VisitMacros(
    PendingFragment &pf, const pasta::Macro &macro,
    std::vector<pasta::Macro> &macros_to_serialize);

static void VisitMacroRange(
    PendingFragment &pf, pasta::MacroRange range,
    std::vector<pasta::Macro> &macros_to_serialize) {
  for (pasta::Macro macro : range) {
    VisitMacros(pf, macro, macros_to_serialize);
  }
}

// Calculate the set of macros to serialize. The top-level macros identified
// by `IndexCompileJob` have already identified the top-level macro uses, and
// given those top-level macros IDs. We're in the backup, non-`TokenTree` case,
// so we need to recursively visit the macro tree and try to serialize all the
// macros as seen by PASTA.
void VisitMacros(
    PendingFragment &pf, const pasta::Macro &macro,
    std::vector<pasta::Macro> &macros_to_serialize) {

  EntityMapper &em = pf.em;

  if (auto tok = pasta::MacroToken::From(macro)) {
    pasta::Token pt = tok->ParsedLocation();
    if (IsParsedToken(pt)) {
      return;
    }

    // TODO(pag): Do this at some point.
    // TODO(pag): Don't remember what "this" is anymore...

  } else {

    // If this is our first time seeing this macro, then create an entity
    // ID for it for the sake of serialization.
    mx::RawEntityId raw_id = em.EntityId(macro);
    if (raw_id != mx::kInvalidEntityId) {
      mx::MacroId id;
      id.kind = mx::FromPasta(macro.Kind());
      id.offset = static_cast<unsigned>(macros_to_serialize.size());
      id.fragment_id = pf.fragment_index;
      raw_id = mx::EntityId(id).Pack();
      em.token_tree_ids.emplace(macro.RawMacro(), raw_id);
      macros_to_serialize.emplace_back(macro);
    
    // If we've seen this already, then only process it further if it's part
    // of this fragment. In the case of a macro directive, it may not be part
    // of this fragment.
    } else {
      mx::VariantId vid = mx::EntityId(raw_id).Unpack();
      CHECK(std::holds_alternative<mx::MacroId>(vid));
      if (std::get<mx::MacroId>(vid).fragment_id != pf.fragment_index) {
        return;
      }
    }

    // Recursive visit this macro.
    VisitMacroRange(pf, macro.Children(), macros_to_serialize);

    // Get the intermediae children. This live between the children and the
    // replacement children. Some substitutions happen here, but their trees
    // can't logically nest with those of the replacement children.
    if (auto intermediates = IntermediateChildren(macro)) {
      VisitMacroRange(pf, *intermediates, macros_to_serialize);
    }

    // Visit replacement children.
    if (auto sub = pasta::MacroSubstitution::From(macro)) {
      VisitMacroRange(pf, sub->ReplacementChildren(),
                      macros_to_serialize);
    }
  }
}

// Persist just the parsed tokens in the absence of a token tree.
//
// NOTE(pag): This is a *backup* approach when building a token tree fails.
static void PersistParsedTokens(
    mx::DatabaseWriter &database, PendingFragment &pf,
    mx::rpc::Fragment::Builder &fb, TokenProvenanceCalculator &provenance) {

  EntityMapper &em = pf.em;

  std::string utf8_fragment_data;

  // Find the set of macros to serialize.
  std::vector<pasta::Macro> macros_to_serialize = pf.top_level_macros;
  for (const pasta::Macro &tlm : pf.top_level_macros) {
    VisitMacros(pf, tlm, macros_to_serialize);
  }

  provenance.Run(pf.fragment_index, pf.parsed_tokens);

  unsigned num_macros = static_cast<unsigned>(macros_to_serialize.size());
  unsigned num_parsed_tokens = static_cast<unsigned>(pf.parsed_tokens.size());
  unsigned num_tokens = num_parsed_tokens;
  auto tk = fb.initTokenKinds(num_tokens);
  auto to = fb.initTokenOffsets(num_tokens + 1u);
  auto dt = fb.initDerivedTokenIds(num_tokens);
  auto re = fb.initRelatedEntityId(num_tokens);
  auto pto2i = fb.initParsedTokenOffsetToIndex(num_parsed_tokens);
  auto mti2po = fb.initMacroTokenIndexToParsedTokenOffset(num_tokens);
  auto mti2mi = fb.initMacroTokenIndexToMacroId(num_tokens);
  auto i = 0u;

  // Serialize the tokens.
  for (pasta::PrintedToken tok : pf.parsed_tokens) {
    pto2i.set(i, i);  // Parsed tokens to macro tokens.
    mti2po.set(i, i);  // Macro tokens to parsed tokens.
    mti2mi.set(i, mx::kInvalidEntityId);  // Mapping of token to containing macros.

    to.set(i, static_cast<unsigned>(utf8_fragment_data.size()));
    tk.set(i, static_cast<uint16_t>(TokenKindFromPasta(tok)));
    dt.set(i, provenance.DerivedTokenId(tok));
    re.set(i, provenance.RelatedEntityId(tok));

    AccumulateTokenData(utf8_fragment_data, tok);
    ++i;
  }

  to.set(i, static_cast<unsigned>(utf8_fragment_data.size()));
  fb.setTokenData(utf8_fragment_data);

  for (i = 0u; i < num_macros; ++i) {
    EntityBuilder<mx::ast::Macro> storage;
    DispatchSerializeMacro(pf, storage.builder, macros_to_serialize[i],
                           nullptr);

    mx::MacroId id;
    id.fragment_id = pf.fragment_index;
    id.offset = i;
    id.kind = mx::FromPasta(macros_to_serialize[i].Kind());
    database.AddAsync(
        mx::EntityRecord{
          mx::EntityId(id).Pack(), GetSerializedData(storage.message)});
  }

  auto tlms = fb.initTopLevelMacros(pf.num_top_level_macros);
  for (i = 0u; i < pf.num_top_level_macros; ++i) {
    mx::RawEntityId eid = em.EntityId(pf.top_level_macros[i]);
    CHECK_NE(eid, mx::kInvalidEntityId);
    tlms.set(i, eid);
  }
}

static std::string MainSourceFile(const pasta::AST &ast) {
  return ast.MainFile().Path().generic_string();
}

static std::string MainSourceFile(const PendingFragment &pf) {
  if (!pf.top_level_decls.empty()) {
    return MainSourceFile(pasta::AST::From(pf.top_level_decls.front()));

  } else if (!pf.top_level_macros.empty()) {
    return MainSourceFile(pasta::AST::From(pf.top_level_macros.front()));

  } else if (pf.original_tokens && !pf.original_tokens->empty()) {
    return MainSourceFile(pasta::AST::From(
        pf.original_tokens->Front().value()));
  
  } else {
    return "<unknown file>";
  }
}

// Persist the token tree, which is a tree of substitutions, i.e. before/after
// macro use/expansion, or x-macro file inclusion.
//
// The first N tokens are the original parsed tokens. After that, all tokens
// are macro tokens. The top-level substitution points to the macro code in
// before IDs, and the
static void PersistTokenTree(
    mx::DatabaseWriter &database, PendingFragment &pf,
    mx::rpc::Fragment::Builder &fb, TokenTreeNodeRange nodes,
    TokenProvenanceCalculator &provenance) {

  const EntityMapper &em = pf.em;

  TokenTreeSerializationSchedule sched(pf);
  sched.Schedule(nodes);

  provenance.Run(pf.fragment_index, sched.tokens);

//#ifndef NDEBUG
//  provenance.Dump(std::cerr);
//#endif

  unsigned num_macros = static_cast<unsigned>(pf.macros_to_serialize.size());
  unsigned num_parsed_tokens = static_cast<unsigned>(pf.parsed_tokens.size());
  unsigned num_tokens = static_cast<unsigned>(sched.tokens.size());
  auto tk = fb.initTokenKinds(num_tokens);
  auto to = fb.initTokenOffsets(num_tokens + 1u);
  auto dt = fb.initDerivedTokenIds(num_tokens);
  auto re = fb.initRelatedEntityId(num_tokens);
  auto mti2po = fb.initMacroTokenIndexToParsedTokenOffset(num_tokens);
  auto mti2mi = fb.initMacroTokenIndexToMacroId(num_tokens);
  auto i = 0u;

  size_t data_reserve = 128u;
  for (const TokenTreeNode &tok_node : sched.tokens) {
    if (auto pt = tok_node.PrintedToken()) {
      data_reserve += pt->Data().size();
    } else if (auto mt = tok_node.Token()) {
      data_reserve += mt->Data().size();
    } else if (auto ft = tok_node.FileToken()) {
      data_reserve += ft->Data().size();
    }
  }

  std::string utf8_fragment_data;
  utf8_fragment_data.reserve(data_reserve);

  // Serialize the tokens.
  for (const TokenTreeNode &tok_node : sched.tokens) {
    to.set(i, static_cast<unsigned>(utf8_fragment_data.size()));

    std::optional<pasta::Token> mt = tok_node.Token();
    std::optional<pasta::PrintedToken> pt = tok_node.PrintedToken();
    std::optional<pasta::FileToken> ft = tok_node.FileToken();

    dt.set(i, provenance.DerivedTokenId(tok_node));
    re.set(i, provenance.RelatedEntityId(tok_node));

    if (pt) {
      AccumulateTokenData(utf8_fragment_data, pt.value());
      tk.set(i, static_cast<uint16_t>(TokenKindFromPasta(pt.value())));

    } else if (mt) {
      AccumulateTokenData(utf8_fragment_data, mt.value());
      tk.set(i, static_cast<uint16_t>(TokenKindFromPasta(mt.value())));

    } else if (ft) {
      AccumulateTokenData(utf8_fragment_data, ft.value());
      tk.set(i, static_cast<uint16_t>(TokenKindFromPasta(ft.value())));

    } else {
      LOG(FATAL)
          << "Missing parsed/file token for token node in source file "
          << MainSourceFile(pf) << " with parsed tokens "
          << DiagnosePrintedTokens(pf.parsed_tokens);
    }

    // Associate this token node with a parsed token. Generally this can be
    // a one-to-many mapping, but we try to choose a reasonable one.
    mx::VariantId parsed_vid =
        mx::EntityId(provenance.ParsedTokenId(tok_node)).Unpack();
    
    // We might have a backup case if we're serializing a builtin, where
    // we serialized a buitlin or forward declaration in a declarator and
    // (intentionally) droppped provenance so that we wouldn't accidentally
    // bring in macros.
    if (std::holds_alternative<mx::InvalidId>(parsed_vid) && pt) {
      CHECK(pf.drop_token_provenance);
      parsed_vid = mx::EntityId(em.EntityId(pt.value())).Unpack();
    }

    if (std::holds_alternative<mx::ParsedTokenId>(parsed_vid)) {
      mti2po.set(i, std::get<mx::ParsedTokenId>(parsed_vid).offset);
    } else {
      CHECK(std::holds_alternative<mx::InvalidId>(parsed_vid));
      mti2po.set(i, num_parsed_tokens);
    }

    // Map the token to its containing macro.
    mx::EntityId macro_eid(sched.containing_macro[i]);
    mx::VariantId macro_vid = macro_eid.Unpack();
    if (std::holds_alternative<mx::MacroId>(macro_vid)) {
      mx::MacroId mid = std::get<mx::MacroId>(macro_vid);
      CHECK_EQ(mid.fragment_id, pf.fragment_index);
      mti2mi.set(i, macro_eid.Pack());
    } else {
      CHECK(std::holds_alternative<mx::InvalidId>(macro_vid));
    }

    ++i;
  }

  to.set(i, static_cast<unsigned>(utf8_fragment_data.size()));
  fb.setTokenData(utf8_fragment_data);

  // Map the parsed tokens to serialized tokens.
  //
  // `ParsedTokenId::offset` needs to go through a level of indirection to
  // get into the token kinds/data.
  auto pto2i = fb.initParsedTokenOffsetToIndex(num_parsed_tokens);
  i = 0u;
  for (pasta::PrintedToken parsed_tok : pf.parsed_tokens) {
    auto it = sched.parsed_token_index.find(parsed_tok.RawToken());
    if (it != sched.parsed_token_index.end()) {
      auto mi = static_cast<mx::EntityOffset>(it->second);
      pto2i.set(i, mi);
      CHECK_EQ(mti2po[mi], i);  // Should be set.

    } else {
      if (!pf.decls_to_serialize.empty()) {
        auto err = PrefixedLocation(pf.decls_to_serialize[0],
                                    "Token tree didn't cover code near ");
        LOG_IF(ERROR, !err.empty()) << err;
      }

      LOG(FATAL)
          << "TokenTree nodes didn't cover parsed token '" << parsed_tok.Data()
          << "' at index " << i << " (PTI " << parsed_tok.Index()
          << ") in parsed token list from source file "
          << MainSourceFile(pf) << " with parsed tokens "
          << DiagnosePrintedTokens(pf.parsed_tokens);
    }
    ++i;
  }

  // Serialize the token trees / macros.
  for (const std::optional<TokenTree> &tt : pf.macros_to_serialize) {
    CHECK(tt.has_value());

    const void *raw_tt = tt->RawNode();
    mx::RawEntityId eid = em.EntityId(raw_tt);
    mx::VariantId vid = mx::EntityId(eid).Unpack();
    CHECK(std::holds_alternative<mx::MacroId>(vid));

    mx::MacroId id = std::get<mx::MacroId>(vid);
    CHECK_EQ(id.fragment_id, pf.fragment_index);

    EntityBuilder<mx::ast::Macro> storage;
    CHECK_LT(id.offset, num_macros);
    if (std::optional<pasta::Macro> macro = tt->Macro()) {
      DispatchSerializeMacro(pf, storage.builder, macro.value(), &(tt.value()));

    // NOTE(pag): This is only reasonable on a case-by-case basis!! Right now,
    //            we only expect `SUBSITUTION`s to be invented by the
    //            `TokenTree` code, for connecting `#include` directives to
    //            included file contents for X-macros.
    } else {
      CHECK(tt->Kind() == mx::MacroKind::SUBSTITUTION);
      const pasta::Macro &invalid_macro =
          *reinterpret_cast<const pasta::Macro *>(0xdeadbeefull);
      DispatchSerializeMacro(pf, storage.builder, invalid_macro, &(tt.value()));
    }

    database.AddAsync(
        mx::EntityRecord{eid, GetSerializedData(storage.message)});
  }

  // Serialize the top-level list.
  auto tlms = fb.initTopLevelMacros(nodes.Size());
  i = 0u;
  for (TokenTreeNode node : nodes) {
    mx::RawEntityId eid = em.EntityId(node);
    mx::VariantId vid = mx::EntityId(eid).Unpack();
    
    CHECK(!std::holds_alternative<mx::InvalidId>(vid));
    
    if (std::holds_alternative<mx::MacroId>(vid)) {
      
      // A directive that's not hoisted into a different fragment.
      mx::MacroId mid = std::get<mx::MacroId>(vid);
      if (mid.fragment_id == pf.fragment_index) {
        CHECK_LT(mid.offset, pf.macros_to_serialize.size());
        CHECK(pf.macros_to_serialize[mid.offset].has_value());
        CHECK_EQ(em.EntityId(pf.macros_to_serialize[mid.offset].value()),
                 eid);
      }
    }

    tlms.set(i++, eid);
  }
}

}  // namespace

// Persist a fragment. A fragment is Multiplier's "unit of granularity" of
// de-duplication and indexing. It roughly corresponds to a sequence of one-or-
// more syntactically overlapping "top-level declarations." For us, a top-
// level declaration is one that only nested inside of a namespace, a linkage
// specifier, a translation unit, etc. Thus, things like global variables,
// functions, and classes are all top-level declarations. These things tend
// to contain lots of other declarations/statements, and those all get lumped
// into and persisted a TLD's fragment.
//
// Fragments separate out their lists of persistent entities. This enables
// some downstream benefits. For example, all declarations are persisted in a
// separate list from all statements. This allows us to more easily jump into
// the middle of the "sub-AST" persisted in a fragment. For example, if we
// want to find all `VarDecl`s, we can iterate the list of declarations, check
// the decl kinds, and then yield only the discovered `VarDecl`s. No recursive
// visitor needed!
//
// Fragments also store things like the macro substitution tree, and parsed
// tokens associated with the covered declarations/statements. This is
// partially because our serialized decls/stmts/etc. reference these tokens,
// and partially so that we can do things like print out fragments, or chunks
// thereof.
void GlobalIndexingState::PersistFragment(
    const pasta::AST &ast, NameMangler &mangler, EntityMapper &em,
    TokenProvenanceCalculator &provenance, PendingFragment &pf) {

  ProgressBarWork fragment_progress_tracker(fragment_progress);

  capnp::MallocMessageBuilder message;
  mx::rpc::Fragment::Builder fb = message.initRoot<mx::rpc::Fragment>();

  // Labels tokens and macros.
  LabelTokensAndMacrosInFragment(pf);

  // Drop the connections between `pasta::PrintedToken::DerivedLocation` and
  // `pasta::Token`.
  provenance.Init(pf.parsed_tokens);
  if (pf.drop_token_provenance) {
    pf.parsed_tokens.DumpProvenanceInformation();
  }

  // Identify all of the declarations, statements, types, and pseudo-entities,
  // and build lists of the entities to serialize.
  BuildPendingFragment(pf);

  // Figure out parentage/inheritance between the entities.
  LabelParentsInPendingFragment(pf);

  // Serialize all discovered entities.
  SerializePendingFragment(database, pf);

  // List of fragments IDs, where index `0` is this fragment's immediate parent.
  auto ids = fb.initParentIds(
      static_cast<unsigned>(pf.parent_fragment_ids.size()));
  auto i = 0u;
  for (mx::PackedFragmentId parent_id : pf.parent_fragment_ids) {
    ids.set(i++, parent_id.Pack());
  }

  // The compilation containing this fragment.
  fb.setCompilationId(pf.compilation_id.Pack());

  if (!pf.parent_fragment_ids.empty()) {
    database.AddAsync(
        mx::NestedFragmentRecord{
          pf.parent_fragment_ids.front(),
          pf.fragment_id});
  }

  if (pf.file_location) {
    fb.setFirstFileTokenId(pf.file_location->first_file_token_id.Pack());
    fb.setLastFileTokenId(pf.file_location->last_file_token_id.Pack());

    // Associate the fragment with the file.
    database.AddAsync(
        mx::FragmentFileRecord{pf.fragment_id, pf.file_location->file_id});

    // Associate the range of file tokens with the fragment. This helps with
    // implementing things like regular expression (via RE2) searches over code.
    database.AddAsync(
        mx::FragmentFileRangeRecord{
            pf.fragment_id,
            pf.file_location->first_file_token_id,
            pf.file_location->last_file_token_id});
  }

  auto tlds = fb.initTopLevelDeclarations(pf.num_top_level_declarations);
  for (i = 0u; i < pf.num_top_level_declarations; ++i) {
    tlds.set(i, em.EntityId(pf.top_level_decls[i]));
  }

  // Derive the macro substitution tree. Failing to build the tree is an error
  // condition, but we can't let it stop us from actually serializing the
  // fragment or its data.
  std::stringstream tok_tree_err;
  std::optional<TokenTreeNodeRange> maybe_tt = TokenTree::Create(
      pf.original_tokens, pf.parsed_tokens, tok_tree_err);

  if (maybe_tt) {
    PersistTokenTree(database, pf, fb, std::move(maybe_tt.value()), provenance);

  // If we don't have the normal or the backup token tree, then do a best
  // effort saving of macro tokens. Don't bother organizing them into
  // substitutions because that will just replicate logic from the token
  // tree.
  } else {
    if (!pf.top_level_decls.empty()) {
      const pasta::Decl &leader_decl = pf.top_level_decls.front();
      LOG(ERROR)
          << tok_tree_err.str() << " for top-level declaration "
          << DeclToString(leader_decl)
          << PrefixedLocation(leader_decl, " at or near ")
          << " on main job file " << MainSourceFile(ast);
    } else {
      LOG(ERROR)
          << tok_tree_err.str() << " for macros on main job file "
          << MainSourceFile(ast);
    }

    PersistParsedTokens(database, pf, fb, provenance);
  }

  PersistTokenContexts(em, pf.parsed_tokens, pf.fragment_index, fb);
  LinkEntitiesAcrossFragments(database, pf, mangler);
  LinkExternalReferencesInFragment(ast, database, pf);
  LinkEntityNamesToFragment(database, pf);

  // Add the fragment to the database.
  database.AddAsync(
      mx::EntityRecord{pf.fragment_id.Pack(), GetSerializedData(message)});
}

// Persist the compilation.
void GlobalIndexingState::PersistCompilation(
    const pasta::Compiler &compiler, const pasta::CompileJob &job,
    const pasta::AST &ast, const EntityMapper &em,
    mx::PackedCompilationId tu_id,
    std::vector<mx::PackedFragmentId> fragment_ids) {

  capnp::MallocMessageBuilder message;
  mx::rpc::Compilation::Builder cb = message.initRoot<mx::rpc::Compilation>();

  mx::rpc::CompileCommand::Builder cc = cb.initCommand();
  cc.setSourcePath(ast.MainFile().Path().generic_string());
  cc.setCompilerPath(compiler.ExecutablePath().generic_string());
  cc.setWorkingDirectory(job.WorkingDirectory().generic_string());
  cc.setSystemRootDirectory(job.SystemRootDirectory().generic_string());
  cc.setSystemRootIncludeDirectory(job.SystemRootIncludeDirectory().generic_string());
  cc.setResourceDirectory(job.ResourceDirectory().generic_string());
  cc.setInstallationDirectory(compiler.InstallationDirectory().generic_string());

  capnp::Text::Reader reader("", 0u);
  std::string_view triple = job.TargetTriple();
  if (!triple.empty()) {
    reader = capnp::Text::Reader(triple.data(), triple.size());
  }
  cc.setTargetTriple(reader);

  triple = job.AuxiliaryTargetTriple();
  reader = capnp::Text::Reader("", 0u);
  if (!triple.empty()) {
    reader = capnp::Text::Reader(triple.data(), triple.size());
  }
  cc.setAuxTargetTriple(reader);

  auto i = 0u;
  const pasta::ArgumentVector &args = job.Arguments();
  auto al = cc.initArguments(static_cast<unsigned>(args.Size()));
  for (const char *arg : args) {
    al.set(i++, arg);
  }

  i = 0u;
  std::vector<pasta::IncludePath> paths = compiler.SystemIncludeDirectories();
  auto ipl = cc.initSystemIncludePaths(static_cast<unsigned>(paths.size()));
  for (const pasta::IncludePath &path : paths) {
    mx::rpc::IncludePath::Builder ipb = ipl[i++];
    ipb.setDirectory(path.Path().generic_string());
    ipb.setLocation(static_cast<mx::rpc::IncludePathLocation>(path.Location()));
  }

  i = 0u;
  paths = compiler.UserIncludeDirectories();
  ipl = cc.initUserIncludePaths(static_cast<unsigned>(paths.size()));
  for (const pasta::IncludePath &path : paths) {
    mx::rpc::IncludePath::Builder ipb = ipl[i++];
    ipb.setDirectory(path.Path().generic_string());
    ipb.setLocation(static_cast<mx::rpc::IncludePathLocation>(path.Location()));
  }

  i = 0u;
  paths = compiler.FrameworkDirectories();
  ipl = cc.initFrameworkPaths(static_cast<unsigned>(paths.size()));
  for (const pasta::IncludePath &path : paths) {
    mx::rpc::IncludePath::Builder ipb = ipl[i++];
    ipb.setDirectory(path.Path().generic_string());
    ipb.setLocation(static_cast<mx::rpc::IncludePathLocation>(path.Location()));
  }

  i = 0u;
  const auto &files = ast.ParsedFiles();
  auto fl = cb.initFileIds(static_cast<unsigned>(files.size()));
  for (const pasta::File &file : files) {
    fl.set(i++, em.EntityId(file));
  }

  i = 0u;
  fl = cb.initFragmentIds(static_cast<unsigned>(fragment_ids.size()));
  for (mx::PackedFragmentId frag_id : fragment_ids) {
    fl.set(i++, frag_id.Pack());
  }

  if (sourceir_progress) {
    sourceir_progress->AddWork(1u);
  }

#ifndef MX_DISABLE_VAST
  if (std::string mlir = codegen.GenerateSourceIR(ast, em);
      !mlir.empty()) {
    cb.setMlir(mlir);
    if (sourceir_progress) {
      sourceir_progress->Advance();
    }
  } else {
    cb.initMlir(0u);
  }
#else
  cb.initMlir(0u);
#endif

  // Add the compilation to the database.
  database.AddAsync(
      mx::EntityRecord{tu_id.Pack(), GetSerializedData(message)});
}

}  // namespace indexer
