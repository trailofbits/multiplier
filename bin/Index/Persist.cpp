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
#include <multiplier/Frontend.h>
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

#include "Codegen.h"
#include "EntityMapper.h"
#include "LabelEntitiesInFragment.h"
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
extern void BuildPendingFragment(const pasta::AST &ast, PendingFragment &pf);

// Label the parent entity ids.
extern void LabelParentsInPendingFragment(PendingFragment &pf);

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
extern void SerializePendingFragment(mx::rpc::Fragment::Builder &fb,
                                     mx::DatabaseWriter &database,
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
      mx::FileRecord{file_id.Pack(), GetSerializedData(message)});
}

namespace {

// Schedules the order of serialization of tokens derived from the token tree.
// The main goal is for all tokens in the final expansion, i.e. all parsed
// tokens, to be adjacent. The token tree code also tries to inject whitespace
// that was originall missing between those parsed tokens, so we want to see
// those too.
struct TokenTreeSerializationSchedule {
  struct Todo {
    const void *parent;
    mx::RawEntityId parent_id;
    bool is_part_of_define{false};
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
                                 bool &is_part_of_define,
                                 bool &is_part_of_fragment) {

    const void *raw_tt = tt.RawNode();
    const void *raw_locator = raw_tt;
    std::optional<pasta::Macro> macro = tt.Macro();
    if (macro) {
      CHECK(tt.Kind() == mx::FromPasta(macro->Kind()));
      if (!pf.parsed_tokens_are_printed) {
        raw_locator = macro->RawMacro();

      } else {
        CHECK(!pasta::MacroDirective::From(macro.value()));
      }
    }

    auto &entity_list = pf.EntityListFor(tt);
    mx::RawEntityId raw_id = em.EntityId(raw_locator);
    mx::MacroId id;

    // NOTE(pag): This is some collusion with `EntityLabeller::Label` in terms
    //            of labelling the top-level macros. This also happens with
    //            nested macro directives.
    if (raw_id != mx::kInvalidEntityId) {
      CHECK_NE(raw_tt, raw_locator);
      id = mx::EntityId(raw_id).Extract<mx::MacroId>().value();
      CHECK(id.kind == tt.Kind());

      // An example of a case where we come across a token tree node that
      // *isn't* in the current fragment is `tests/Macros/DefineInMacroUse.c`.
      // We hoist out `#define` directives into floating fragments, and so it
      // ends up being seen as logically not in the current fragment, even
      // though it is physically reachable from within the token tree. 
      is_part_of_fragment = id.fragment_id == pf.fragment_index;
      if (is_part_of_fragment) {
        CHECK_LT(id.offset, entity_list.size());
        CHECK(!entity_list[id.offset].has_value());
        entity_list[id.offset] = tt;
      }

    // We need to form a new macro id for something we discovered along the way.
    } else {
      id.fragment_id = pf.fragment_index;
      id.kind = tt.Kind();
      id.offset = static_cast<mx::EntityOffset>(entity_list.size());
      raw_id = mx::EntityId(id).Pack();
      CHECK_NE(raw_id, mx::kInvalidEntityId)
          << "Likely MacroId offset overflow: " << id.offset;

      // Add it to our to-serialize list.
      entity_list.push_back(tt);
    }

    // Update `is_part_of_define` by reference so that macro tokens and nodes
    // inside of a `#define` end up getting globally recorded for the sake
    // of provenance.
    if (id.kind == mx::MacroKind::DEFINE_DIRECTIVE) {
      is_part_of_define = true;
    }

    // Save the ID, mapped from both the token tree and the underlying
    // macro, if any.
    CHECK(em.token_tree_ids.emplace(raw_tt, raw_id).second);
    if (raw_tt != raw_locator) {
      (void) em.token_tree_ids.emplace(raw_locator, raw_id);
    }

    // If this is a `#define` or something in a `#define`, then make sure that
    // the entity ID becomes globally visible.
    if (is_part_of_define && is_part_of_fragment && raw_locator &&
        raw_tt != raw_locator) {
      (void) em.entity_ids.emplace(raw_locator, raw_id);
    }

    return raw_id;
  }

  mx::RawEntityId RecordEntityId(const TokenTreeNode &node,
                                 mx::RawEntityId parent_id,
                                 bool &is_part_of_define,
                                 bool &is_part_of_fragment) {
    mx::RawEntityId raw_id = mx::kInvalidEntityId;
    const void *raw_pt = nullptr;

    if (std::optional<TokenTree> sub = node.SubTree()) {
      raw_id = RecordEntityId(sub.value(), is_part_of_define,
                              is_part_of_fragment);

    // Fill in IDs for derived tokens.
    } else {
      mx::MacroTokenId id;
      id.kind = mx::TokenKind::UNKNOWN;
      id.fragment_id = pf.fragment_index;
      id.offset = static_cast<unsigned>(tokens.size());

      std::optional<pasta::PrintedToken> gt = node.PrintedToken();
      std::optional<pasta::MacroToken> mt = node.MacroToken();
      std::optional<pasta::Token> pt = node.Token();

      if (gt) {
        id.kind = TokenKindFromPasta(gt.value());
        auto raw_gt = gt->RawToken();
        CHECK(em.token_tree_ids.contains(raw_gt));
        CHECK(parsed_token_index.emplace(raw_gt, id.offset).second);

        // NOTE(pag): Can't set `raw_gt` or `raw_tt` to `raw_pt` because this
        //            goes into the `EntityMapper::entity_ids`, which is global,
        //            but the lifetime of `raw_tt` and `raw_gt` are limited
        //            to fragment serialization.

        if (mt && !pf.parsed_tokens_are_printed) {
          raw_pt = RawEntity(mt.value());
        } else if (pt) {
          raw_pt = RawEntity(pt.value());
        }

        if (auto dt = gt->DerivedLocation()) {
          auto raw_dt = dt->RawToken();
          CHECK(pt.has_value());
          CHECK_EQ(raw_dt, pt->RawToken());
          CHECK(em.token_tree_ids.contains(raw_dt));
        
        } else {
          assert(!pt);
        }

      } else if (mt) {
        id.kind = TokenKindFromPasta(mt.value());
        raw_pt = mt->RawMacro();
      
      } else if (pt) {
        assert(false);  // Shouldn't get here.

        id.kind = TokenKindFromPasta(pt.value());
        raw_pt = pt->RawToken();
      }

      raw_id = mx::EntityId(id).Pack();
      CHECK_NE(raw_id, mx::kInvalidEntityId)
          << "Likely MacroTokenId offset overflow: " << id.offset;

      if (raw_pt) {
        em.token_tree_ids.emplace(raw_pt, raw_id);
      }

      containing_macro.push_back(parent_id);
      tokens.emplace_back(node);
    }

    auto raw_tt = RawEntity(node);
    CHECK(em.token_tree_ids.emplace(raw_tt, raw_id).second);

    // Make sure `#define` macro body tokens are globally visible to provenance,
    // e.g. parameter substitutions.
    if (is_part_of_define && is_part_of_fragment && raw_pt &&
        raw_tt != raw_pt) {
      em.entity_ids.emplace(raw_pt, raw_id);
    }

    return raw_id;
  }

  // Schedule the expansions so that all "afters" are properly nested. We want
  // this so that `fragment.parsed_tokens().data()` reflects the final result
  // of macro expansion.
  void Schedule(const void * /* parent */, mx::RawEntityId parent_id,
                bool is_part_of_define, const TokenTreeNodeRange &nodes) {

    for (TokenTreeNode node : nodes) {

      bool is_part_of_fragment = true;
      mx::RawEntityId child_id = RecordEntityId(
          node, parent_id, is_part_of_define, is_part_of_fragment);

      // If this is a macro directive that is nested inside of another fragment,
      // then assume that we've already extracted the directive from that other
      // fragment and persisted it.
      if (!is_part_of_fragment) {
        continue;
      }

      if (std::optional<TokenTree> sub = node.SubTree()) {

        const void *child = sub->RawNode();

        if (sub->HasExpansion()) {
          Schedule(child, child_id, is_part_of_define,
                   sub->ReplacementChildren());
          if (sub->HasIntermediateChildren()) {
            todo_list.emplace_back(Todo{
                child, child_id, is_part_of_define,
                sub->IntermediateChildren()});
          }
          todo_list.emplace_back(Todo{child, child_id, is_part_of_define,
                                 sub->Children()});
        } else {
          Schedule(child, child_id, is_part_of_define, sub->Children());
        }
      }
    }
  }

  void Schedule(const Todo &todo) {
    Schedule(todo.parent, todo.parent_id, todo.is_part_of_define, todo.nodes);
  }

  void Schedule(TokenTreeNodeRange nodes) {
    Schedule(nullptr, mx::kInvalidEntityId, false, std::move(nodes));
    for (auto i = 0u; i < todo_list.size(); ++i) {
      Schedule(todo_list[i]);
    }
  }

  TokenTreeSerializationSchedule(PendingFragment &pf_)
      : pf(pf_),
        em(pf_.em) {}
};

// Persist just the parsed tokens in the absence of a token tree.
//
// NOTE(pag): This is a *backup* approach when building a token tree fails.
static void PersistParsedTokens(
    PendingFragment &pf, mx::rpc::Fragment::Builder &fb,
    TokenProvenanceCalculator &provenance) {

  std::string utf8_fragment_data;

  provenance.Run(pf.fragment_index, pf.parsed_tokens);

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

  // Don't even try to save the macros.
  (void) fb.initMacros(0u);
  (void) fb.initTopLevelMacros(0u);
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
    PendingFragment &pf, mx::rpc::Fragment::Builder &fb,
    TokenTreeNodeRange nodes, TokenProvenanceCalculator &provenance) {

  const EntityMapper &em = pf.em;

  TokenTreeSerializationSchedule sched(pf);
  sched.Schedule(nodes);

  provenance.Run(pf.fragment_index, sched.tokens);

// #ifndef NDEBUG
//   provenance.Dump(std::cerr);
// #endif

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
    if (auto printed = tok_node.PrintedToken()) {
      data_reserve += printed->Data().size();
    
    } else if (auto parsed = tok_node.Token()) {
      data_reserve += parsed->Data().size();
    
    } else if (auto macro = tok_node.MacroToken()) {
      data_reserve += macro->Data().size();

    } else {
      LOG(FATAL)
          << "Missing parsed token for token node in source file "
          << MainSourceFile(pf) << " with parsed tokens "
          << pf.parsed_tokens.Data();
    }
  }

  std::string utf8_fragment_data;
  utf8_fragment_data.reserve(data_reserve);

  // Serialize the tokens.
  for (const TokenTreeNode &tok_node : sched.tokens) {
    to.set(i, static_cast<unsigned>(utf8_fragment_data.size()));

    std::optional<pasta::Token> pt = tok_node.Token();
    std::optional<pasta::PrintedToken> gt = tok_node.PrintedToken();
    std::optional<pasta::MacroToken> mt = tok_node.MacroToken();

    dt.set(i, provenance.DerivedTokenId(tok_node));
    re.set(i, provenance.RelatedEntityId(tok_node));
    
    if (gt) {
      AccumulateTokenData(utf8_fragment_data, gt.value());
      tk.set(i, static_cast<uint16_t>(TokenKindFromPasta(gt.value())));
    
    } else if (pt) {
      AccumulateTokenData(utf8_fragment_data, pt.value());
      tk.set(i, static_cast<uint16_t>(TokenKindFromPasta(pt.value())));

    } else if (mt) {
      AccumulateTokenData(utf8_fragment_data, mt.value());
      tk.set(i, static_cast<uint16_t>(TokenKindFromPasta(mt.value())));

    } else {
      assert(false);
    }

    // Associate this token node with a parsed token. Generally this can be
    // a one-to-many mapping, but we try to choose a reasonable one.
    mx::VariantId parsed_vid =
        mx::EntityId(provenance.ParsedTokenId(tok_node)).Unpack();

    // We might have a backup case if we're serializing a builtin, where
    // we serialized a buitlin or forward declaration in a declarator and
    // (intentionally) droppped provenance so that we wouldn't accidentally
    // bring in macros.
    if (std::holds_alternative<mx::InvalidId>(parsed_vid) && gt) {
      CHECK(pf.drop_token_provenance);
      parsed_vid = mx::EntityId(em.EntityId(gt.value())).Unpack();
    }

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
        auto err = PrefixedLocation(pf.top_level_decls.front(),
                                    "Token tree didn't cover code near ");
        LOG_IF(ERROR, !err.empty()) << err;
      }

      LOG(FATAL)
          << "TokenTree nodes didn't cover parsed token '" << parsed_tok.Data()
          << "' at index " << i << " (PTI " << parsed_tok.Index()
          << ") in parsed token list from source file "
          << MainSourceFile(pf) << " with parsed tokens "
          << pf.parsed_tokens.Data();
    }
    ++i;
  }

  auto macros_list = fb.initMacros(
      SerializationListSize(pf.macros_to_serialize));

  // Serialize the token trees / macros.
  for (const auto &[kind, entities] : pf.macros_to_serialize) {
    auto mb = macros_list.init(
        static_cast<unsigned>(kind), NumEntities(entities));

    for (const std::optional<TokenTree> &tt : entities) {
      CHECK(tt.has_value())
          << "Missing token tree for " << mx::EnumeratorName(kind)
          << "; rebuild was " << (pf.parsed_tokens_are_printed ? "" : "not ")
          << "forced";

      const void *raw_tt = tt->RawNode();
      mx::RawEntityId eid = em.EntityId(raw_tt);
      auto id = mx::EntityId(eid).Extract<mx::MacroId>();
      CHECK(id.has_value());
      CHECK_EQ(id->fragment_id, pf.fragment_index);
      CHECK_LT(id->offset, entities.size());
      CHECK(id->kind == kind);

      if (std::optional<pasta::Macro> macro = tt->Macro()) {
        DispatchSerializeMacro(pf, mb[id->offset], macro.value(), &(tt.value()));

      // NOTE(pag): This is only reasonable on a case-by-case basis!! Right now,
      //            we only expect `SUBSITUTION`s to be invented by the
      //            `TokenTree` code, for connecting `#include` directives to
      //            included file contents for X-macros.
      } else {
        CHECK(tt->Kind() == mx::MacroKind::SUBSTITUTION);
        const pasta::Macro &invalid_macro =
            *reinterpret_cast<const pasta::Macro *>(0xdeadbeefull);
        DispatchSerializeMacro(pf, mb[id->offset], invalid_macro, &(tt.value()));
      }
    }
  }

  // Serialize the top-level list. This should be a mix of macro tokens, top-
  // level macro uses, and sometimes macros that are technically part of hoisted
  // fragments, but lexically inside this fragment, and so they show up here.
  auto tlms = fb.initTopLevelMacros(nodes.Size());
  i = 0u;
  for (TokenTreeNode node : nodes) {
    mx::RawEntityId raw_id = em.EntityId(node);
    if (raw_id == mx::kInvalidEntityId) {
      assert(false);
      continue;
    }

    mx::EntityId eid(raw_id);

    // A directive that's not hoisted into a different fragment.
    if (auto mid = eid.Extract<mx::MacroId>()) {
      if (mid->fragment_id == pf.fragment_index) {
        auto &macros = pf.macros_to_serialize[mid->kind];
        CHECK_LT(mid->offset, macros.size());
        CHECK(macros[mid->offset].has_value());
        CHECK_EQ(em.EntityId(macros[mid->offset].value()), raw_id);
      }

    // Everything else should be a macro token.
    } else {
      assert(eid.Extract<mx::MacroTokenId>());

      // This will seem confusing, but really, we shadow all the top-level
      // parsed token ids with corresponding macro token ids, representing
      // the fact that the pre-processor does a single pass over everything.
      // However, if we're not looking at a macro use/directive, then we
      // should never see a top-level macro token backing a top-level node, as
      // those should only ever be nested inside of some other kind of macro
      // entity.
      assert(!node.MacroToken());
    }

    tlms.set(i++, raw_id);
  }
}

// Record the parent fragment relationship.
//
// XREF(pag): `TokenTreeImpl::BuildFromTokenList` in `bin/Index/TokenTree.cpp`.
static void RecordParentFragment(
    mx::rpc::Fragment::Builder &fb, mx::DatabaseWriter &database,
    PendingFragment &pf) {

  if (!pf.raw_parent_entity) {
    fb.setParentFragmentId(mx::kInvalidEntityId);
    return;
  }

  const EntityMapper &em = pf.em;
  mx::VariantId vid = mx::EntityId(em.EntityId(pf.raw_parent_entity)).Unpack();
  mx::RawEntityId parent_frag_index = mx::kInvalidEntityId;

  if (std::holds_alternative<mx::DeclId>(vid)) {
    parent_frag_index = std::get<mx::DeclId>(vid).fragment_id;

  } else if (std::holds_alternative<mx::MacroId>(vid)) {
    parent_frag_index = std::get<mx::MacroId>(vid).fragment_id;

  } else if (std::holds_alternative<mx::FragmentId>(vid)) {
    parent_frag_index = std::get<mx::FragmentId>(vid).fragment_id;

  } else {
    assert(false);
    fb.setParentFragmentId(mx::kInvalidEntityId);
    return;
  }

  mx::PackedFragmentId parent_fid = mx::FragmentId(parent_frag_index);

  fb.setParentFragmentId(parent_fid.Pack());
  database.AddAsync(mx::NestedFragmentRecord{parent_fid, pf.fragment_id});
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
    const pasta::AST &ast, NameMangler &mangler,
    TokenProvenanceCalculator &provenance, PendingFragment &pf) {

  EntityMapper &em = pf.em;
  em.ResetForFragment();

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
  BuildPendingFragment(ast, pf);

  // Figure out parentage/inheritance between the entities.
  LabelParentsInPendingFragment(pf);

  // Serialize all discovered entities.
  SerializePendingFragment(fb, database, pf);

  // Serialize the parent fragment id(s), if any.
  RecordParentFragment(fb, database, pf);

  // The compilation containing this fragment.
  fb.setCompilationId(pf.compilation_id.Pack());

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
  for (auto i = 0u; i < pf.num_top_level_declarations; ++i) {
    tlds.set(i, em.EntityId(pf.top_level_decls[i]));
  }

  if (pf.parsed_tokens_are_printed) {
    pf.macros_to_serialize.clear();
  }

  // Derive the macro substitution tree. Failing to build the tree is an error
  // condition, but we can't let it stop us from actually serializing the
  // fragment or its data.
  std::stringstream tok_tree_err;
  if (auto maybe_tt = TokenTree::Create(pf, tok_tree_err)) {
    PersistTokenTree(pf, fb, std::move(maybe_tt.value()), provenance);

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

    pf.macros_to_serialize.clear();
    pf.top_level_macros.clear();
    PersistParsedTokens(pf, fb, provenance);
  }

  PersistTokenContexts(em, pf.parsed_tokens, pf.fragment_index, fb);
  LinkEntitiesAcrossFragments(database, pf, mangler);
  LinkExternalReferencesInFragment(ast, database, pf);
  LinkEntityNamesToFragment(database, pf);

  // Add the fragment to the database.
  database.AddAsync(
      mx::FragmentRecord{pf.fragment_id.Pack(), GetSerializedData(message)});
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

  cb.setMainFileId(em.EntityId(ast.MainFile()));

  if (sourceir_progress) {
    sourceir_progress->AddWork(1u);
  }

  if (std::string mlir = codegen.GenerateSourceIR(ast, em);
      !mlir.empty()) {
    cb.setMlir(mlir);
    if (sourceir_progress) {
      sourceir_progress->Advance();
    }
  } else {
    cb.initMlir(0u);
  }

  // Add the compilation to the database.
  database.AddAsync(
      mx::CompilationRecord{tu_id.Pack(), GetSerializedData(message)});
}

}  // namespace indexer
