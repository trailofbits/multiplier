// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Context.h"

#include <algorithm>
#include <capnp/common.h>
#include <capnp/message.h>
#include <fstream>
#include <glog/logging.h>
#include <iostream>
#include <llvm/Support/JSON.h>
#include <multiplier/AST.h>
#include <multiplier/AST.capnp.h>
#include <multiplier/RPC.capnp.h>
#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <pasta/Util/File.h>
#include <sstream>
#include <utility>
#include <unordered_set>

#include "Codegen.h"
#include "Compress.h"
#include "EntityMapper.h"
#include "PASTA.h"
#include "PendingFragment.h"
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
extern void DispatchSerializeMacro(const EntityMapper &em,
                                   mx::ast::Macro::Builder builder,
                                   const pasta::Macro &entity,
                                   const TokenTree *tt);

// Build the fragment. This fills out the decls/stmts/types to serialize.
//
// NOTE(pag): Implemented in `BuildPendingFragment.cpp`.
extern void BuildPendingFragment(
    PendingFragment &pf, EntityIdMap &entity_ids,
    TypeIdMap &type_ids, const pasta::TokenRange &tokens);

// Label the parent entity ids.
extern void LabelParentsInPendingFragment(PendingFragment &pf,
                                          EntityMapper &em);

// Store information persistently to enable linking of declarations across
// fragments.
extern void LinkEntitiesAcrossFragments(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    const EntityMapper &em, const NameMangler &mangler);

// Identify all unique entity IDs used by this fragment, and map them to the
// fragment ID in the data store.
extern void LinkExternalUsesInFragment(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    mx::rpc::Fragment::Builder &b);

// Identify all unique entity IDs referenced by this fragment,
// and map them to the fragment ID in the data store.
extern void LinkExternalReferencesInFragment(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    EntityMapper &em);

// Serialize all entities into the Cap'n Proto version of the fragment.
extern void SerializePendingFragment(const PendingFragment &pf,
                                     const EntityMapper &em,
                                     mx::rpc::Fragment::Builder &b);

// Save the symbolic names of all declarations into the database.
extern void LinkEntityNamesToFragment(
    mx::DatabaseWriter &db, const PendingFragment &pf, EntityMapper &em);

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

// Accumulate the token data, stripping out some unwanted characters in the
// process.
static void AccumulateUTF8Data(std::string &data, llvm::StringRef utf8_data) {
  data.reserve(data.size() + utf8_data.size());
  if (!utf8_data.contains('\r')) {
    data.insert(data.end(), utf8_data.begin(), utf8_data.end());

  } else {
    for (char ch : utf8_data) {
      if (ch != '\r') {
        data += ch;
      }
    }
  }
}

// Accumulate the token data, encoded as UTF-8, into `data`.
template <typename Tok>
static void AccumulateTokenData(std::string &data, const Tok &tok) {
  llvm::StringRef tok_data = tok.Data();
  if (llvm::json::isUTF8(tok_data)) {
    AccumulateUTF8Data(data, tok_data);

  } else {
    AccumulateUTF8Data(data, llvm::json::fixUTF8(tok_data));
  }
}

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

  std::filesystem::path file_path = file.Path();
  auto maybe_file_data = file.Data();
  LOG_IF(FATAL, !maybe_file_data.Succeeded())
      << "No data for file " << file_path.generic_string()
      << ": " << maybe_file_data.TakeError();

  pasta::FileTokenRange file_tokens = file.Tokens();
  std::string_view file_data = maybe_file_data.TakeValue();
  capnp::MallocMessageBuilder message;
  mx::rpc::File::Builder fb = message.initRoot<mx::rpc::File>();
  fb.setId(file_id.Unpack().file_id);

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
  // line numbers. This mapping is used during regular expression matches and
  // Weggli matches over file contents to help us map to fragments whose code
  // is derived from those files.
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

  database.AddAsync(
      mx::FilePathRecord{file_id, std::move(file_path)},
      mx::SerializedFileRecord{file_id, CompressedMessage(message)});
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

  mx::RawEntityId RecordEntityId(const TokenTree &tt) {
    const void *raw_tt = tt.RawNode();
    const void *raw_locator = raw_tt;
    std::optional<pasta::Macro> macro = tt.Macro();
    if (macro) {
      CHECK(tt.Kind() == mx::FromPasta(macro->Kind()));
      raw_locator = macro->RawMacro();
    }

    mx::RawEntityId raw_id = em.EntityId(raw_locator);

    // NOTE(pag): This is some collusion with `EntityLabeller::Label` in terms
    //            of labelling the top-level macros.
    if (raw_id != mx::kInvalidEntityId) {
      CHECK_NE(raw_tt, raw_locator);
      mx::MacroId id = std::get<mx::MacroId>(mx::EntityId(raw_id).Unpack());
      CHECK(id.kind == tt.Kind());
      CHECK_LT(id.offset, pf.top_level_macros.size());
      CHECK_LT(id.offset, pf.macros_to_serialize.size());
      CHECK(!pf.macros_to_serialize[id.offset].has_value());
      pf.macros_to_serialize[id.offset] = tt;

    // We need to form a new macro id for something we discovered along the way.
    } else {
      mx::MacroId id;
      id.fragment_id = em.fragment.fragment_index;
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
      (void) em.entity_ids.emplace(raw_locator, raw_id);
    }
    return raw_id;
  }

  mx::RawEntityId RecordEntityId(const TokenTreeNode &node,
                                 mx::RawEntityId parent_id) {
    mx::RawEntityId raw_id = mx::kInvalidEntityId;
    if (std::optional<TokenTree> sub = node.SubTree()) {
      raw_id = RecordEntityId(sub.value());

    // Fill in IDs for derived tokens.
    } else {
      mx::MacroTokenId id;
      id.kind = mx::TokenKind::UNKNOWN;
      id.fragment_id = em.fragment.fragment_index;
      id.offset = static_cast<unsigned>(tokens.size());

      const void *raw_pt = nullptr;
      if (std::optional<pasta::Token> pt = node.Token()) {
        id.kind = TokenKindFromPasta(pt.value());
        raw_pt = pt->RawToken();
        DCHECK(!IsParsedToken(pt.value()) == !em.entity_ids.count(raw_pt));
        CHECK(parsed_token_index.emplace(pt->RawToken(), id.offset).second);

      } else if (std::optional<pasta::FileToken> ft = node.FileToken()) {
        id.kind = TokenKindFromPasta(ft.value());
      }

      raw_id = mx::EntityId(id).Pack();
      if (raw_pt) {
        em.entity_ids.emplace(raw_pt, raw_id);
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
      mx::RawEntityId child_id = RecordEntityId(node, parent_id);
      if (std::optional<TokenTree> sub = node.SubTree()) {

        const void *child = sub->RawNode();
        if (sub->HasExpansion()) {
          Schedule(child, child_id, sub->ReplacementChildren());
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

  TokenTreeSerializationSchedule(PendingFragment &pf_, EntityMapper &em_)
      : pf(pf_),
        em(em_) {}
};

static mx::RawEntityId DerivedTokenId(
    EntityMapper &em, const pasta::FileToken &tok) {
  return em.EntityId(tok);
}

static mx::RawEntityId DerivedTokenId(
    EntityMapper &em, const pasta::Token &tok) {
  if (std::optional<pasta::Token> derived_tok = tok.DerivedLocation()) {
    return em.EntityId(derived_tok.value());
  }

  if (std::optional<pasta::FileToken> file_tok = tok.FileLocation()) {
    return DerivedTokenId(em, file_tok.value());
  }

  return mx::kInvalidEntityId;
}

// Get the list of parsed tokens.
static std::vector<pasta::Token> FindParsedTokens(
    const pasta::TokenRange &tokens, uint64_t min_index, uint64_t max_index) {
  std::vector<pasta::Token> parsed_toks;
  for (auto i = min_index; i <= max_index; ++i) {
    pasta::Token tok = tokens[i];
    if (IsParsedToken(tok)) {
      parsed_toks.emplace_back(std::move(tok));
    }
  }
  return parsed_toks;
}

static void VisitMacros(
    PendingFragment &pf, EntityMapper &em, const pasta::Macro &macro,
    std::vector<pasta::Macro> &macros_to_serialize);

static void VisitMacroRange(
    PendingFragment &pf, EntityMapper &em, pasta::MacroRange range,
    std::vector<pasta::Macro> &macros_to_serialize) {
  for (pasta::Macro macro : range) {
    VisitMacros(pf, em, macro, macros_to_serialize);
  }
}

// Calculate the set of macros to serialize. The top-level macros identified
// by `IndexCompileJob` have already identified the top-level macro uses, and
// given those top-level macros IDs. We're in the backup, non-`TokenTree` case,
// so we need to recursively visit the macro tree and try to serialize all the
// macros as seen by PASTA.
void VisitMacros(
    PendingFragment &pf, EntityMapper &em, const pasta::Macro &macro,
    std::vector<pasta::Macro> &macros_to_serialize) {

  if (auto tok = pasta::MacroToken::From(macro)) {
    pasta::Token pt = tok->ParsedLocation();
    if (IsParsedToken(pt)) {
      return;
    }

    // TODO(pag): Do this at some point.

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
      em.entity_ids.emplace(macro.RawMacro(), raw_id);
      macros_to_serialize.emplace_back(macro);
    }

    // Recursive visit this macro.
    VisitMacroRange(pf, em, macro.Children(), macros_to_serialize);

    if (auto sub = pasta::MacroSubstitution::From(macro)) {
      VisitMacroRange(pf, em, sub->ReplacementChildren(),
                      macros_to_serialize);
    }
  }
}

// Persist just the parsed tokens in the absence of a token tree.
//
// NOTE(pag): This is a *backup* approach when building a token tree fails.
static void PersistParsedTokens(
    PendingFragment &pf, EntityMapper &em, mx::rpc::Fragment::Builder &fb,
    const std::vector<pasta::Token> &parsed_tokens) {

  RelatedEntityIds tok_related_entities;
  std::string utf8_fragment_data;

  // Find the set of macros to serialize.
  std::vector<pasta::Macro> macros_to_serialize = pf.top_level_macros;
  for (const pasta::Macro &tlm : pf.top_level_macros) {
    VisitMacros(pf, em, tlm, macros_to_serialize);
  }

  unsigned num_macros = static_cast<unsigned>(macros_to_serialize.size());
  unsigned num_parsed_tokens = static_cast<unsigned>(parsed_tokens.size());
  unsigned num_tokens = num_parsed_tokens;
  auto tk = fb.initTokenKinds(num_tokens);
  auto to = fb.initTokenOffsets(num_tokens + 1u);
  auto dt = fb.initDerivedTokenIds(num_tokens);
  auto re = fb.initRelatedEntityId(num_tokens);
  auto pto2i = fb.initParsedTokenOffsetToIndex(num_parsed_tokens);
  auto mti2po = fb.initMacroTokenIndexToParsedTokenOffset(num_tokens);
  auto mti2mo = fb.initMacroTokenIndexToMacroOffset(num_tokens);
  auto i = 0u;

  // Serialize the tokens.
  for (const pasta::Token &tok : parsed_tokens) {
    pto2i.set(i, i);  // Parsed tokens to macro tokens.
    mti2po.set(i, i);  // Macro tokens to parsed tokens.
    mti2mo.set(i, num_macros);  // Mapping of token to containing macros.

    if (std::optional<pasta::MacroToken> mt = tok.MacroLocation()) {
      if (auto pm = mt->Parent()) {
        mx::VariantId vid = mx::EntityId(em.EntityId(pm.value())).Unpack();
        if (std::holds_alternative<mx::MacroId>(vid)) {
          mx::MacroId mid = std::get<mx::MacroId>(vid);
          if (mid.fragment_id == pf.fragment_index) {
            mti2mo.set(i, mid.offset);
          }
        }
      }
    }

    to.set(i, static_cast<unsigned>(utf8_fragment_data.size()));
    tk.set(i, static_cast<uint16_t>(TokenKindFromPasta(tok)));
    dt.set(i, DerivedTokenId(em, tok));
    re.set(i, RelatedEntityId(em, tok, tok_related_entities));

    AccumulateTokenData(utf8_fragment_data, tok);
    ++i;
  }

  to.set(i, static_cast<unsigned>(utf8_fragment_data.size()));
  fb.setTokenData(utf8_fragment_data);

  auto ms = fb.initMacros(num_macros);
  for (i = 0u; i < num_macros; ++i) {
    mx::ast::Macro::Builder mb = ms[i];
    DispatchSerializeMacro(em, mb, macros_to_serialize[i], nullptr);
  }

  auto tlms = fb.initTopLevelMacros(pf.num_top_level_macros);
  for (i = 0u; i < pf.num_top_level_macros; ++i) {
    tlms.set(i, em.EntityId(pf.top_level_macros[i]));
  }
}

// Combine all parsed tokens into a string for diagnostic purposes.
static std::string DiagnoseParsedTokens(
    const std::vector<pasta::Token> &parsed_tokens) {
  std::stringstream ss;
  auto sep = "";
  for (const pasta::Token &tok : parsed_tokens) {
    ss << sep << tok.Data();
    sep = " ";
  }
  return ss.str();
}

// Persist the token tree, which is a tree of substitutions, i.e. before/after
// macro use/expansion, or x-macro file inclusion.
//
// The first N tokens are the original parsed tokens. After that, all tokens
// are macro tokens. The top-level substitution points to the macro code in
// before IDs, and the
static void PersistTokenTree(
    PendingFragment &pf, EntityMapper &em, mx::rpc::Fragment::Builder &fb,
    TokenTreeNodeRange nodes, const std::vector<pasta::Token> &parsed_tokens) {

  RelatedEntityIds tok_related_entities;
  TokenTreeSerializationSchedule sched(pf, em);
  sched.Schedule(nodes);

  std::string utf8_fragment_data;

  unsigned num_macros = static_cast<unsigned>(pf.macros_to_serialize.size());
  unsigned num_parsed_tokens = static_cast<unsigned>(parsed_tokens.size());
  unsigned num_tokens = static_cast<unsigned>(sched.tokens.size());
  auto tk = fb.initTokenKinds(num_tokens);
  auto to = fb.initTokenOffsets(num_tokens + 1u);
  auto dt = fb.initDerivedTokenIds(num_tokens);
  auto re = fb.initRelatedEntityId(num_tokens);
  auto i = 0u;

  // Pre-fill the related entity IDs for the parsed tokens.
  for (const pasta::Token &tok : parsed_tokens) {
    (void) RelatedEntityId(em, tok, tok_related_entities);
  }

  // Serialize the tokens.
  for (const TokenTreeNode &tok_node : sched.tokens) {
    to.set(i, static_cast<unsigned>(utf8_fragment_data.size()));

    std::optional<pasta::Token> pt = tok_node.Token();
    std::optional<pasta::FileToken> ft = tok_node.FileToken();
    if (pt) {
      AccumulateTokenData(utf8_fragment_data, pt.value());
      tk.set(i, static_cast<uint16_t>(TokenKindFromPasta(pt.value())));
      dt.set(i, DerivedTokenId(em, pt.value()));
      re.set(i, RelatedEntityId(em, pt.value(), tok_related_entities));

    } else if (ft) {
      AccumulateTokenData(utf8_fragment_data, ft.value());
      tk.set(i, static_cast<uint16_t>(TokenKindFromPasta(ft.value())));
      dt.set(i, DerivedTokenId(em, ft.value()));
      re.set(i, mx::kInvalidEntityId);

    } else {
      auto ast = pasta::AST::From(parsed_tokens.front());
      LOG(FATAL)
          << "Missing parsed/file token for token node in source file "
          << ast.MainFile().Path().generic_string() << " with parsed tokens "
          << DiagnoseParsedTokens(parsed_tokens);
    }

    ++i;
  }

  to.set(i, static_cast<unsigned>(utf8_fragment_data.size()));
  fb.setTokenData(utf8_fragment_data);

  // Map the serialized tokens to the parsed tokens.
  i = 0u;
  auto mti2po = fb.initMacroTokenIndexToParsedTokenOffset(num_tokens);
  auto mti2mo = fb.initMacroTokenIndexToMacroOffset(num_tokens);
  for (; i < num_tokens; ++i) {
    mti2po.set(i, num_parsed_tokens);
    mti2mo.set(i, num_macros);

    // Map the token to its containing macro.
    mx::VariantId vid = mx::EntityId(sched.containing_macro[i]).Unpack();
    if (std::holds_alternative<mx::MacroId>(vid)) {
      mx::MacroId mid = std::get<mx::MacroId>(vid);
      CHECK_EQ(mid.fragment_id, pf.fragment_index);
      mti2mo.set(i, mid.offset);
    } else {
      CHECK(std::holds_alternative<mx::InvalidId>(vid));
    }
  }

  // Map the parsed tokens to serialized tokens.
  //
  // `ParsedTokenId::offset` needs to go through a level of indirection to
  // get into the token kinds/data.
  auto pto2i = fb.initParsedTokenOffsetToIndex(num_parsed_tokens);
  i = 0u;
  for (const pasta::Token &parsed_tok : parsed_tokens) {
    auto it = sched.parsed_token_index.find(parsed_tok.RawToken());
    if (it != sched.parsed_token_index.end()) {
      auto mi = static_cast<unsigned>(it->second);
      pto2i.set(i, mi);
      mti2po.set(mi, i);
    } else {
      auto ast = pasta::AST::From(parsed_tokens.front());
      if (!pf.decls_to_serialize.empty()) {
        auto err = PrefixedLocation(pf.decls_to_serialize[0],
                                    "Token tree didn't cover code near ");
        LOG_IF(ERROR, !err.empty()) << err;
      }

      LOG(FATAL)
          << "TokenTree nodes didn't cover parsed token '" << parsed_tok.Data()
          << "' at index " << i << " (PTI " << parsed_tok.Index()
          << ") in parsed token list from source file "
          << ast.MainFile().Path().generic_string() << " with parsed tokens "
          << DiagnoseParsedTokens(parsed_tokens);
    }

    // Introduce a mapping of macro tokens back to parsed tokens.
    for (auto dloc = parsed_tok.DerivedLocation(); dloc;
         dloc = dloc->DerivedLocation()) {
      mx::VariantId vid = mx::EntityId(em.EntityId(dloc.value())).Unpack();
      if (!std::holds_alternative<mx::MacroTokenId>(vid)) {
        CHECK(!std::holds_alternative<mx::ParsedTokenId>(vid));
        continue;
      }

      mx::MacroTokenId mtid = std::get<mx::MacroTokenId>(vid);

      if (mtid.fragment_id == pf.fragment_index) {

        // This macro token hasn't yet been related to any single parsed
        // token, so relate it to the first one.
        if (mti2po[mtid.offset] == num_parsed_tokens) {
          mti2po.set(mtid.offset, i);

        // This macro token ended up being related to multiple parsed tokens.
        } else {
          mti2po.set(mtid.offset, num_parsed_tokens + 1u);
        }
      }
    }

    ++i;
  }

  // Serialize the token trees / macros.
  auto ms = fb.initMacros(num_macros);
  for (const std::optional<TokenTree> &tt : pf.macros_to_serialize) {
    const void *raw_tt = tt->RawNode();

    mx::MacroId id = std::get<mx::MacroId>(
        mx::EntityId(em.EntityId(raw_tt)).Unpack());

    CHECK_LT(id.offset, num_macros);
    mx::ast::Macro::Builder mb = ms[id.offset];
    if (std::optional<pasta::Macro> macro = tt->Macro()) {
      DispatchSerializeMacro(em, mb, macro.value(), &(tt.value()));
    }
  }

  // Serialize the top-level list.
  auto tlms = fb.initTopLevelMacros(nodes.Size());
  i = 0u;
  for (TokenTreeNode node : nodes) {
    tlms.set(i++, em.EntityId(node.RawNode()));
  }
}

// Find the entity id of `canon_decl` that resides in the current fragment
// on which the serializer is operating. Token contexts from PASTA store the
// canonical (typically first) declaration, but we generally want the version
// of the declaration that is inside of the fragment itself, so here we go from
// canonical back to specific.
//
// TODO(pag): Eventually, we should change the serialized representation of
//            token contexts to store full 64-bit entity IDs. Right now, they
//            store offsets of things in the fragments, hence the actual need
//            to go canonical->specific in the first place, and why a failure to
//            do so results in `kInvalidEntityId` instead of just falling back
//            on the ID of the canonical decl.
static mx::RawEntityId IdOfRedeclInFragment(
    const EntityMapper &em, mx::RawEntityId frag_index, pasta::Decl canon_decl) {
  for (pasta::Decl redecl : canon_decl.Redeclarations()) {
    mx::RawEntityId eid = em.EntityId(redecl);
    if (eid == mx::kInvalidEntityId) {
      continue;
    }
    mx::VariantId vid = mx::EntityId(eid).Unpack();
    CHECK(std::holds_alternative<mx::DeclarationId>(vid));
    mx::DeclarationId id = std::get<mx::DeclarationId>(vid);
    if (id.fragment_id == frag_index) {
      return eid;
    }
  }

  return em.EntityId(canon_decl);
}

// Persist the token contexts. The token contexts are a kind of inverted tree,
// e.g.
//
//        int       foo       =         0       ;
//         |         |        |         |       |
//     BuiltinType   |        |     IntLiteral  /
//          \  .--<--'  .--<--' .---<---' .----'
//           \ | .--<---' .--<--'  .--<---'
//            \|/  .---<--'  .--<--'
//           VarDecl <---<---'
//
// They tell us the provenance or relation of a particular token to the AST that
// represents the code containing that token. You can, in theory, follow a
// linked list from a token all the way up to the root of an AST. We want to
// serialize these because they allow us to make queries in our API, e.g. "give
// me the SwitchStmt containing this token." Token contexts aren't pure linked
// lists, though; there are special "alias" nodes that tend to link you further
// down the lists, and so that takes some special handling.
static void PersistTokenContexts(
    EntityMapper &em, const std::vector<pasta::Token> &parsed_tokens,
    mx::RawEntityId frag_index, mx::rpc::Fragment::Builder &fb) {

  using DeclContextSet = std::unordered_set<pasta::TokenContext>;
  std::map<mx::RawEntityId, DeclContextSet> contexts;

  // First, collect only the relevant contexts for this fragment. Group them by
  // entity ID, as we store the context list inline inside of the entities.
  unsigned num_tokens = 0u;
  for (const pasta::Token &tok : parsed_tokens) {
    ++num_tokens;

    for (auto context = tok.Context(); context; context = context->Parent()) {

      pasta::TokenContext c = context.value();
      if (auto alias_context = c.Aliasee()) {
        c = std::move(alias_context.value());
      }

      // NOTE(pag): PASTA stored the canonical decl in the decl context, so
      //            it's not likely to be in the current fragment.
      if (auto decl = pasta::Decl::From(c)) {
        const mx::RawEntityId eid = IdOfRedeclInFragment(em, frag_index, *decl);
        if (eid != mx::kInvalidEntityId) {
          contexts[eid].insert(context.value());
        }

      } else if (auto stmt = pasta::Stmt::From(c)) {
        const mx::RawEntityId eid = em.EntityId(*stmt);
        if (eid != mx::kInvalidEntityId) {
          contexts[eid].insert(context.value());
        }

      } else if (auto type = pasta::Type::From(c)) {
        const mx::RawEntityId eid = em.EntityId(*type);
        if (eid != mx::kInvalidEntityId) {
          contexts[eid].insert(context.value());
        }

      } else if (auto attr = pasta::Attr::From(c)) {
        const mx::RawEntityId eid = em.EntityId(*attr);
        if (eid != mx::kInvalidEntityId) {
          contexts[eid].insert(context.value());
        }
      
      } else if (auto designator = pasta::Designator::From(c)) {
        const uint32_t offset = em.PseudoId(*designator);
        mx::DesignatorId did;
        did.fragment_id = frag_index;
        did.offset = offset;
        const mx::RawEntityId eid = mx::EntityId(did).Pack();
        if (eid != mx::kInvalidEntityId) {
          contexts[eid].insert(context.value());
        }
      }
    }
  }

  struct PendingTokenContext {
    mx::RawEntityId entity_id{mx::kInvalidEntityId};
    bool is_alias{false};
    unsigned offset{0};
    unsigned alias_offset{0};
  };

  std::unordered_map<pasta::TokenContext, PendingTokenContext>
      pending_contexts;

  unsigned num_contexts = 0;

  // Figure out the kinds of the contexts (stmt, decl, type), the index into the
  // respective entity list in the serialized fragment where the contexts will
  // be placed, the offset at which each context will reside within an entity-
  // specific list, etc.
  for (const auto &entry : contexts) {
    const DeclContextSet &entity_contexts = entry.second;

    // First, make a "template" of the context info, based on the entity kind
    // and fragment info.
    PendingTokenContext tpl;
    tpl.entity_id = entry.first;

    // Then, specialize this template for each context we encounter.
    for (const pasta::TokenContext &context : entity_contexts) {
      PendingTokenContext &info = pending_contexts[context];
      info = tpl;  // Copy the template.

      // Adjust the kind to be an aliasee.
      if (context.Aliasee()) {
        info.is_alias = true;
      }

      info.offset = num_contexts++;
    }
  }

  // Now resolve the aliasee targets, if any. Token contexts and their aliases
  // will end up in the same entity-specific lists. This is because the entity
  // in which the context resides will tell us its type.
  for (const auto &entry : contexts) {
    for (const pasta::TokenContext &context : entry.second) {
      auto pc_it = pending_contexts.find(context);
      if (pc_it == pending_contexts.end()) {
        continue;  // E.g. translation unit contexts.
      }

      PendingTokenContext &info = pc_it->second;
      CHECK_NE(info.entity_id, mx::kInvalidEntityId);

      if (!info.is_alias) {
        DCHECK(!context.Aliasee());
        continue;
      }

      auto alias_context = context.Aliasee();
      CHECK(alias_context.has_value());

      PendingTokenContext &alias_info = pending_contexts[alias_context.value()];
      CHECK_EQ(info.entity_id, alias_info.entity_id);
      CHECK_NE(info.offset, alias_info.offset);
      CHECK_LT(alias_info.offset, num_contexts);
      info.alias_offset = alias_info.offset;
    }
  }

  // Allocate as many token contexts as there are parsed tokens.
  auto tcb_list = fb.initParsedTokenContexts(num_contexts);
  auto tco_list = fb.initParsedTokenContextOffsets(num_tokens);

  // Finally, serialize the contexts.
  num_tokens = 0u;
  for (const pasta::Token &tok : parsed_tokens) {
    tco_list.set(num_tokens, 0u);

    std::optional<mx::rpc::TokenContext::Builder> tcb;
    for (auto context = tok.Context(); context; context = context->Parent()) {

      pasta::TokenContext c = *context;
      auto pc_it = pending_contexts.find(c);
      if (pc_it == pending_contexts.end()) {
        continue;  // E.g. translation unit contexts, attributes.
      }

      const PendingTokenContext &info = pc_it->second;

      CHECK_LT(info.offset, num_contexts);
      if (!tcb) {
        tco_list.set(num_tokens, (info.offset << 1u) | 1u);
      } else {
        tcb->setParentIndex((info.offset << 1u) | 1u);
      }

      CHECK_NE(info.entity_id, mx::kInvalidEntityId);

      tcb.reset();
      tcb.emplace(tcb_list[info.offset]);
      tcb->setEntityId(info.entity_id);
      tcb->setParentIndex(0u);

      if (info.is_alias) {
        CHECK_LT(info.alias_offset, num_contexts);
        tcb->setAliasIndex((info.alias_offset << 1u) | 1u);
      } else {
        tcb->setAliasIndex(0u);
      }
    }

    ++num_tokens;
  }

  DCHECK_GT(fb.getTokenKinds().size(), 0u);
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
    const pasta::AST &ast, const pasta::TokenRange &tokens,
    NameMangler &mangler, EntityIdMap &entity_ids,
    PendingFragment &pf) {

  TypeIdMap type_ids;
  const mx::SpecificEntityId<mx::FragmentId> fragment_id = pf.fragment_id;
  const uint64_t begin_index = pf.begin_index;
  const uint64_t end_index = pf.end_index;

  capnp::MallocMessageBuilder message;
  mx::rpc::Fragment::Builder fb = message.initRoot<mx::rpc::Fragment>();

  // Identify all of the declarations, statements, types, and pseudo-entities,
  // and build lists of the entities to serialize.
  BuildPendingFragment(pf, entity_ids, type_ids, tokens);

  EntityMapper em(entity_ids, type_ids, pf);

  // Figure out parentage/inheritance between the entities.
  LabelParentsInPendingFragment(pf, em);

  // Serialize all discovered entities.
  SerializePendingFragment(pf, em, fb);

  std::vector<pasta::Token> parsed_tokens = FindParsedTokens(
      tokens, begin_index, end_index);

  fb.setId(pf.fragment_id.Pack());
  if (pf.file_location) {
    fb.setFirstFileTokenId(pf.file_location->first_file_token_id.Pack());
    fb.setLastFileTokenId(pf.file_location->last_file_token_id.Pack());
    database.AddAsync(
        mx::FragmentLineCoverageRecord{
            pf.fragment_id, pf.file_location->file_id,
            pf.file_location->first_line_number,
            pf.file_location->last_line_number});
  }

  // Generate source IR before saving the fragments to the persistent
  // storage.
  fb.setMlir(codegen.GenerateSourceIRFromTLDs(
      fragment_id.Pack(), em, pf.top_level_decls,
      pf.num_top_level_declarations));

  auto tlds = fb.initTopLevelDeclarations(pf.num_top_level_declarations);
  for (auto i = 0u; i < pf.num_top_level_declarations; ++i) {
    tlds.set(i, em.EntityId(pf.top_level_decls[i]));
  }

  // Derive the macro substitution tree. Failing to build the tree is an error
  // condition, but we can't let it stop us from actually serializing the
  // fragment or its data.
  std::stringstream tok_tree_err;
  std::optional<TokenTreeNodeRange> maybe_tt = TokenTree::Create(
      tokens, begin_index, end_index, tok_tree_err);

  if (maybe_tt) {
    PersistTokenTree(pf, em, fb, std::move(maybe_tt.value()), parsed_tokens);

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
          << " on main job file "
          << ast.MainFile().Path().generic_string();
    } else {
      LOG(ERROR)
          << tok_tree_err.str() << " for macros on main job file "
          << ast.MainFile().Path().generic_string();
    }

    PersistParsedTokens(pf, em, fb, parsed_tokens);
  }

  PersistTokenContexts(em, parsed_tokens, pf.fragment_index, fb);
  database.AddAsync(
      mx::SerializedFragmentRecord{
          pf.fragment_id, CompressedMessage(message)});

  LinkEntitiesAcrossFragments(database, pf, em, mangler);
  LinkExternalUsesInFragment(database, pf, fb);
  LinkExternalReferencesInFragment(database, pf, em);
  LinkEntityNamesToFragment(database, pf, em);
}

}  // namespace indexer
