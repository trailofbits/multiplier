// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "IndexCompileJob.h"

#include <algorithm>
#include <capnp/message.h>
#include <cassert>
#include <fstream>
#include <glog/logging.h>
#include <iostream>
#include <map>
#include <multiplier/Types.h>
#include <pasta/AST/AST.h>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Printer.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/File.h>
#include <set>
#include <tuple>
#include <unordered_set>
#include <vector>

#include "Context.h"
#include "Hash.h"
#include "NameMangler.h"
#include "PendingFragment.h"
#include "Util.h"

namespace indexer {

// Label the initial entities of this fragment. This focuses on finding the
// entities that syntactically belong to this fragment, and assigning them
// IDs. Labeling happens first for all fragments, then we run `Build` for
// new fragments that we want to serialize.
extern void LabelEntitiesInFragment(
    PendingFragment &pf, EntityIdMap &entity_ids,
    const pasta::TokenRange &tok_range);

namespace {

using OrderedDecl = std::pair<pasta::Decl, unsigned>;
using OrderedMacro = std::pair<pasta::Macro, unsigned>;

// A declaration, the index of the first token to be saved associated with
// the decl, and the (inclusive) index of the last token associated with
// this token.
using EntityRange = std::tuple<Entity, uint64_t, uint64_t>;
static constexpr unsigned kEntityIndex = 0u;
static constexpr unsigned kBeginIndex = 1u;
static constexpr unsigned kEndIndex = 2u;

// A group of declarations with overlapping `EntityRange`s, along with the
// minimum and maximum (inclusive) indices of the tokens.
using EntityGroup = std::vector<Entity>;
using EntityGroupRange = std::tuple<EntityGroup, uint64_t, uint64_t>;
static constexpr unsigned kGroupIndex = 0u;

// Find all top-level declarations.
class TLDFinder final : public pasta::DeclVisitor {
 private:
  std::vector<OrderedDecl> &tlds;

  // Tracks declarations for which we've seen the specializations. This is
  // to prevent us from double-adding specializations.
  std::unordered_set<pasta::Decl> seen_specs;

  unsigned order{0u};

 public:
  virtual ~TLDFinder(void) = default;

  explicit TLDFinder(std::vector<OrderedDecl> &tlds_)
      : tlds(tlds_) {}

  void VisitDeclContext(const pasta::DeclContext &dc) {;
    for (const pasta::Decl &decl : dc.AlreadyLoadedDeclarations()) {
      Accept(decl);
    }
  }

  void VisitTranslationUnitDecl(const pasta::TranslationUnitDecl &decl) final {
    VisitDeclContext(decl);
  }

  void VisitNamespaceDecl(const pasta::NamespaceDecl &decl) final {
    VisitDeclContext(decl);
  }

  void VisitExternCContextDecl(const pasta::ExternCContextDecl &decl) final {
    VisitDeclContext(decl);
  }

  void VisitLinkageSpecDecl(const pasta::LinkageSpecDecl &decl) final {
    VisitDeclContext(decl);
  }

  void VisitClassTemplatePartialSpecializationDecl(
      const pasta::ClassTemplatePartialSpecializationDecl &) final {
    // Do nothing.
  }

  void VisitVarTemplatePartialSpecializationDecl(
      const pasta::VarTemplatePartialSpecializationDecl &) final {
    // Do nothing.
  }

  void VisitClassTemplateDecl(const pasta::ClassTemplateDecl &decl) final {
    if (seen_specs.emplace(decl.CanonicalDeclaration()).second) {
      for (const pasta::ClassTemplateSpecializationDecl &spec :
               decl.Specializations()) {

        // We should observe the explicit specializations and instantiations
        // separately.
        switch (spec.TemplateSpecializationKind()) {
          case pasta::TemplateSpecializationKind::kExplicitSpecialization:
          case pasta::TemplateSpecializationKind::kExplicitInstantiationDeclaration:
          case pasta::TemplateSpecializationKind::kExplicitInstantiationDefinition:
            continue;
          default:
            Accept(spec);
        }
      }
    }
  }

  void VisitVarTemplateDecl(const pasta::VarTemplateDecl &) final {
    // Do nothing; we will see the specializations as top-level declarations.
  }

  void VisitFunctionTemplateDecl(const pasta::FunctionTemplateDecl &decl) final {
    if (seen_specs.emplace(decl.CanonicalDeclaration()).second) {
      for (const pasta::FunctionDecl &spec : decl.Specializations()) {

        // We should observe the explicit specializations and instantiations
        // separately.
        switch (spec.TemplateSpecializationKind()) {
          case pasta::TemplateSpecializationKind::kExplicitSpecialization:
          case pasta::TemplateSpecializationKind::kExplicitInstantiationDeclaration:
          case pasta::TemplateSpecializationKind::kExplicitInstantiationDefinition:
            continue;
          default:
            Accept(spec);
        }
      }
    }
  }

  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final {
    for (const pasta::TemplateParameterList &params :
             decl.TemplateParameterLists()) {
      if (params.NumParameters() || params.HasUnexpandedParameterPack()) {
        return;
      }
    }

    VisitDecl(decl);
  }

  void VisitDecl(const pasta::Decl &decl) final {
    if (!decl.IsInvalidDeclaration()) {
      tlds.emplace_back(decl, order++);
    }
  }
};

// Find all top-level declarations.
static std::vector<OrderedDecl> FindTLDs(const pasta::AST &ast) {

  std::vector<OrderedDecl> tlds;
  TLDFinder tld_finder(tlds);
  tld_finder.VisitTranslationUnitDecl(ast.TranslationUnit());

  auto eq = +[] (const OrderedDecl &a, const OrderedDecl &b) {
    return a.first.RawDecl() == b.first.RawDecl();
  };

  auto less = +[] (const OrderedDecl &a, const OrderedDecl &b) {
    auto a_id = a.first.RawDecl();
    auto b_id = b.first.RawDecl();
    if (a_id < b_id) {
      return true;
    } else if (a_id > b_id) {
      return false;
    } else {
      return a.second < b.second;
    }
  };

  auto orig_less = +[] (const OrderedDecl &a, const OrderedDecl &b) {
    return a.second < b.second;
  };

  std::sort(tlds.begin(), tlds.end(), less);
  auto it = std::unique(tlds.begin(), tlds.end(), eq);
  tlds.erase(it, tlds.end());

  // NOTE(pag): It is extremely important to retain the original ordering. You
  //            can't rely on `sort` (a quicksort) to behave like a stable sort,
  //            nor can you rely on ASTs of different translation units putting
  //            side-by-side declarations one-after-another in memory, thus
  //            getting the same sort order. This is why we keep the extra info
  //            in the `pair` of the original sort order.
  std::sort(tlds.begin(), tlds.end(), orig_less);

  return tlds;
}

// Can we elide this token from the beginning or end of a top-level
// declaration's range of tokens?
static bool CanElideTokenFromTLD(const pasta::Token &tok) {
  switch (tok.Role()) {
    case pasta::TokenRole::kInvalid:
    case pasta::TokenRole::kBeginOfFileMarker:
    case pasta::TokenRole::kEndOfFileMarker:
    case pasta::TokenRole::kEndOfMacroExpansionMarker:
      return true;

    case pasta::TokenRole::kFileToken:
      switch (tok.Kind()) {
        case pasta::TokenKind::kComment:
        case pasta::TokenKind::kEndOfFile:
        case pasta::TokenKind::kEndOfDirective:
        case pasta::TokenKind::kCodeCompletion:
          return true;
        case pasta::TokenKind::kUnknown:
          return IsWhitespaceOrEmpty(tok.Data());
        default:
          return false;
      }
    case pasta::TokenRole::kBeginOfMacroExpansionMarker:
    case pasta::TokenRole::kInitialMacroUseToken:
    case pasta::TokenRole::kIntermediateMacroExpansionToken:
    case pasta::TokenRole::kFinalMacroExpansionToken:
    case pasta::TokenRole::kEndOfInternalMacroEventMarker:
      return false;
  }
  return false;
}

// Do some minor stuff to find begin/ending tokens.
static std::pair<uint64_t, uint64_t> BaselineEntityRange(
    const pasta::Decl &decl, pasta::Token tok,
    std::string_view main_file_path) {

  DCHECK(tok);  // Make sure we're dealing with a valid token.

  auto decl_range = decl.Tokens();
  const auto tok_index = tok.Index();
  auto begin_tok_index = tok_index;
  auto end_tok_index = tok_index;

  if (decl_range.Size()) {
    begin_tok_index = decl_range.begin()->Index();
    end_tok_index = (--decl_range.end())->Index();

    // NOTE(pag): This is more of an indication that we probably need to fix
    //            something in PASTA.
    if (!(begin_tok_index <= tok_index && tok_index <= end_tok_index)) {
      DLOG(ERROR)
          << "Location of " << decl.KindName()
          << " declaration: " << DeclToString(decl)
          << PrefixedLocation(decl, " at or near ")
          << " on main job file " << main_file_path
          << " is not within declaration bounds";
    }
  }

  return {begin_tok_index, end_tok_index};
}

//static bool ShouldEndInSemiColon(const pasta::Decl &decl) {
//  switch (decl.Kind()) {
//    case pasta::DeclKind::kVar:
//      if (auto var = pasta::VarDecl::From(decl)) {
//
//      }
//      break;
//    case pasta::DeclKind::kFriend:
//    case pasta::DeclKind::kRecord:
//    case pasta::DeclKind::kCXXRecord:
//    case pasta::DeclKind::kEnum:
//    case pasta::DeclKind::kUsing:
//    case pasta::DeclKind::kUsingDirective:
//    case pasta::DeclKind::kUsingEnum:
//    case pasta::DeclKind::kClassTemplate:
//    case pasta::DeclKind::kClassTemplatePartialSpecialization:
//    case pasta::DeclKind::kClassTemplateSpecialization:
//    case pasta::DeclKind::kCXXDeductionGuide:
//      return true;
//    case pasta::DeclKind::kFunction:
//      break;
//
//    case pasta::DeclKind::kCXXConstructor:
//    case pasta::DeclKind::kCXXDestructor:
//    case pasta::DeclKind::kCXXConversion:
//    case pasta::DeclKind::kCXXMethod:
//    case pasta::DeclKind::kCXXConversion:
//      if () {
//
//      }
//  }
//  return false;
//}

// Expand an inclusive `[begin, end]` range to be as wide as necessary to
// include the full scope of macro expansion.
static std::pair<uint64_t, uint64_t> ExpandRange(
    const pasta::TokenRange &range, uint64_t begin_tok_index,
    uint64_t end_tok_index) {

  const auto max_tok_index = range.Size();

  // TODO(pag): The following code doesn't handle something like:
  //
  //            enum Foo
  //            #include "Foo_body.h"
  //
  //            Where `Foo`'s `;` is in `Foo_body.h`.

  // We should always at least hit the end of file marker token first.
  CHECK_LT(end_tok_index, max_tok_index);

  // Now adjust for macros at the beginning and ending. If we find macro
  // expansion ranges, then the expand until we find the beginning of the
  // range.
  bool done = false;
  while (!done && 0u < begin_tok_index && begin_tok_index <= end_tok_index) {
    pasta::Token tok = range[begin_tok_index];
    switch (tok.Role()) {
      default:
      case pasta::TokenRole::kInvalid:
        assert(false);
        done = true;
        break;
      case pasta::TokenRole::kFileToken:
        if (CanElideTokenFromTLD(tok)) {
          ++begin_tok_index;  // Don't include it.
        } else {
          done = true;
        }
        break;
      case pasta::TokenRole::kBeginOfMacroExpansionMarker:
        done = true;
        break;
      case pasta::TokenRole::kBeginOfFileMarker:
      case pasta::TokenRole::kEndOfFileMarker:
      case pasta::TokenRole::kEndOfMacroExpansionMarker:
        ++begin_tok_index;  // Don't include it.
        done = true;
        break;
      case pasta::TokenRole::kInitialMacroUseToken:
      case pasta::TokenRole::kIntermediateMacroExpansionToken:
      case pasta::TokenRole::kFinalMacroExpansionToken:
      case pasta::TokenRole::kEndOfInternalMacroEventMarker:
        --begin_tok_index;  // Include it.
        break;
    }
  }

  done = false;
  while (!done && 0u < end_tok_index && end_tok_index < max_tok_index) {
    pasta::Token tok = range[end_tok_index];
    switch (tok.Role()) {
      default:
      case pasta::TokenRole::kInvalid:
        assert(false);
        --end_tok_index;
        break;
      case pasta::TokenRole::kFileToken:
        if (CanElideTokenFromTLD(tok)) {
          --end_tok_index;  // Don't include it.
        } else {
          done = true;
        }
        break;
      case pasta::TokenRole::kEndOfMacroExpansionMarker:
        done = true;
        break;
      case pasta::TokenRole::kBeginOfFileMarker:
      case pasta::TokenRole::kEndOfFileMarker:
      case pasta::TokenRole::kBeginOfMacroExpansionMarker:
        --end_tok_index;  // Don't include it.
        done = true;
        break;
      case pasta::TokenRole::kInitialMacroUseToken:
      case pasta::TokenRole::kIntermediateMacroExpansionToken:
      case pasta::TokenRole::kFinalMacroExpansionToken:
      case pasta::TokenRole::kEndOfInternalMacroEventMarker:
        ++end_tok_index;  // Include it.
        break;
    }
  }

  // Expand to trailing semicolon.
  if ((end_tok_index + 1u) < max_tok_index) {
    pasta::Token last_tok = range[end_tok_index + 1u];
    if (last_tok.Kind() == pasta::TokenKind::kSemi &&
        last_tok.Role() == pasta::TokenRole::kFileToken) {
      ++end_tok_index;
    }
  }

#ifndef NDEBUG
  // Try to detect these types of issues early, as they'd otherwise manifest
  // downstream in `TokenTree::Create`'s internal function
  // `TokenTreeImpl::BuildInitialTokenList`. If these assertions trigger, then
  // it might suggest a bug in PASTA, where PASTA isn't properly wrapping the
  // ranges of macro tokens in a begin and an end expansion marker.
  // Alternatively, it could suggest some kind of initial bad bounds
  // computation.
  switch (range[begin_tok_index].Role()) {
    case pasta::TokenRole::kInitialMacroUseToken:
    case pasta::TokenRole::kIntermediateMacroExpansionToken:
    case pasta::TokenRole::kFinalMacroExpansionToken:
    case pasta::TokenRole::kEndOfInternalMacroEventMarker:
    case pasta::TokenRole::kEndOfMacroExpansionMarker:
      assert(false);
      break;
    default:
      break;
  }

  switch (range[end_tok_index].Role()) {
    case pasta::TokenRole::kInitialMacroUseToken:
    case pasta::TokenRole::kIntermediateMacroExpansionToken:
    case pasta::TokenRole::kFinalMacroExpansionToken:
    case pasta::TokenRole::kEndOfInternalMacroEventMarker:
    case pasta::TokenRole::kBeginOfMacroExpansionMarker:
      assert(false);
      break;
    default:
      break;
  }
#endif

  return {begin_tok_index, end_tok_index};
}

// Find the range of tokens of this decl. The range is returned as an inclusive
// [begin_index, end_index]` pair, and is expanded to cover leading/trailing
// macro expansions, and contracted to try to elide leading/trailing whitespace.
static std::pair<uint64_t, uint64_t> FindDeclRange(
    const pasta::TokenRange &range, pasta::Decl decl, pasta::Token tok,
    std::string_view main_file_path) {

  auto [begin_tok_index, end_tok_index] = BaselineEntityRange(
      decl, tok, main_file_path);

  return ExpandRange(range, begin_tok_index, end_tok_index);
}

// Returns `true` if `decl` is probably a compiler-built-in declaration. It's
// not possible to get location information for these, unless we first printed
// out the compiler builtins to a file and then introduced those as a special
// preamble.
static bool IsProbablyABuiltinDecl(const pasta::Decl &decl) {

  // NOTE(pag): Not all implicit declarations are builtin, but in general, most
  //            top-level implicit declarations are builtins. An example of a
  //            nested implicit decl is the implicit field decl for the `union`:
  //
  //                    struct Blah {
  //                      union {
  //                        int foo;
  //                        float bar;
  //                      } /* implicit field here */ ;
  //                    };
  if (decl.IsImplicit()) {
    return true;

  // Technically we should look for `__builtin_*` but there are other things
  // that are likely to be `__`-prefixed.
  } else if (auto nd = pasta::NamedDecl::From(decl)) {
    if (nd->Name().starts_with("__")) {
      return true;
    }
  }
  return false;
}

// Should we even expect to find this declaration in the token contexts? There
// are cases where we shouldn't, e.g. with template instantiations, because the
// token contexts will just end up being associated with the templates
// themselves.
static bool ShouldFindDeclInTokenContexts(const pasta::Decl &decl) {
  auto tsk = pasta::TemplateSpecializationKind::kUndeclared;
  bool has_partial_or_tpl = true;

  if (auto csd = pasta::ClassTemplateSpecializationDecl::From(decl)) {
    tsk = csd->TemplateSpecializationKind();
    has_partial_or_tpl = !csd->SpecializedTemplateOrPartial().index();

  } else if (auto vsd = pasta::VarTemplateSpecializationDecl::From(decl)) {
    tsk = vsd->TemplateSpecializationKind();
    has_partial_or_tpl = !vsd->SpecializedTemplateOrPartial().index();

  } else if (auto fd = pasta::FunctionDecl::From(decl)) {
    tsk = fd->TemplateSpecializationKind();

  } else if (auto vd = pasta::VarDecl::From(decl)) {
    tsk = vd->TemplateSpecializationKind();

  } else if (auto ta = pasta::TypeAliasDecl::From(decl)) {
    if (ta->DescribedAliasTemplate()) {
      tsk = pasta::TemplateSpecializationKind::kImplicitInstantiation;  // Fake.
    }
  } else if (auto td = pasta::TagDecl::From(decl)) {
    if (td->Name().empty()) {
      return false;
    }
  }

  if (tsk == pasta::TemplateSpecializationKind::kExplicitSpecialization) {
    return true;

  // NOTE(pag): Have observed situations where `ClassTemplateSpecialization`
  //            will report `kUndeclared`.
  } else if (tsk == pasta::TemplateSpecializationKind::kUndeclared) {
    return has_partial_or_tpl;

  } else {
    return false;
  }
}

static void AddDeclRangeToEntityList(
    const pasta::TokenRange &tokens, std::string_view main_file_path,
    const std::map<uint64_t, uint64_t> &eof_to_include,
    const std::map<uint64_t, uint64_t> &eof_indices, pasta::Decl decl,
    std::vector<EntityRange> &entity_ranges) {

  if (decl.Kind() == pasta::DeclKind::kEmpty) {
    return;
  }

  pasta::Token tok = decl.Token();

  // These are probably part of the preamble of compiler-provided builtin
  // declarations.
  if (!tok) {
    LOG_IF(WARNING, !IsProbablyABuiltinDecl(decl))
        << "Could not find location of " << decl.KindName()
        << " declaration: " << DeclToString(decl)
        << PrefixedLocation(decl, " at or near ")
        << " on main job file " << main_file_path;
    return;
  }

  // This suggests an error in PASTA, usually related to token alignment
  // against printed tokens. That process tries to "align" pretty-printed
  // decl tokens, which are full of contextual information, with parsed
  // tokens, which have no contextual information. We do this so that we
  // can get the contextual information from parsed tokens, which is often
  // more useful.
  LOG_IF(FATAL, ShouldFindDeclInTokenContexts(decl) &&
                !TokenIsInContextOfDecl(tok, decl) &&
                !IsProbablyABuiltinDecl(decl))
      << "Could not find location of " << decl.KindName()
      << " declaration: " << DeclToString(decl)
      << PrefixedLocation(decl, " at or near ")
      << " on main job file " << main_file_path;

  auto [begin_index, end_index] = FindDeclRange(tokens, decl, tok,
                                                main_file_path);

  // If we find an EOF marker nested inside the range (hence the exclusive
  // bounds on this loop, rather than inclusive), then extend the decl range
  // to also include the include directive itself. We observe issues in the
  // Linux kernel with unbalanced begin/end file markers.
  //
  // NOTE(pag): It's not safe to use `ExpandRange` as that will try to
  //            contract the range to *exclude* begin- and end-of-file markers
  //            where possible.
  //
  // XREF(pag): Issue 258#issuecomment-1401170794
  for (uint64_t i = begin_index + 1u; i < end_index; ++i) {
    switch (tokens[i].Role()) {

      // If we find an enclosed begin-of-file marker, then expand to the
      // end-of-file marker. This will jump `end_index` to the end-of-file
      // marker.
      case pasta::TokenRole::kBeginOfFileMarker:
        if (auto it = eof_indices.find(i);
            it != eof_indices.end() && it->second > end_index) {
          end_index = it->second;
        }
        break;

      // If we find an enclosed end-of-file marker, then expand to the
      // `#include` directive preceding the begin-of-file marker. This will
      // jump `begin_index` to the begin-of-macro marker.
      case pasta::TokenRole::kEndOfFileMarker:
        if (auto it = eof_to_include.find(i);
            it != eof_to_include.end() && it->second < begin_index) {
          begin_index = it->second;
          i = begin_index + 1u;
        }
        break;
      default:
        break;
    }
  }

  // There should always be at least two tokens in any top-level decl.
  LOG_IF(ERROR, begin_index == end_index && !IsProbablyABuiltinDecl(decl))
      << "Only found one token " << tok.Data() << " for: "
      << DeclToString(decl) << PrefixedLocation(decl, " at or near ")
      << " on main job file " << main_file_path;

  entity_ranges.emplace_back(std::move(decl), begin_index, end_index);
}

static pasta::Macro RootMacroFrom(pasta::Macro node) {
  if (auto parent = node.Parent()) {
    return RootMacroFrom(parent.value());
  } else {
    return node;
  }
}

// Go find the macro definitions, and for each definition, find the uses, then
// find the "root" of that use.
static std::vector<OrderedMacro> FindTLMs(
    const pasta::AST &ast, const pasta::TokenRange &tokens,
    const std::map<uint64_t, uint64_t> &bof_to_eof,
    std::map<uint64_t, uint64_t> &eof_to_include) {

  std::vector<OrderedMacro> tlms;
  std::vector<pasta::DefineMacroDirective> defs;
  const uint64_t num_tokens = tokens.Size();

  auto order = 0u;
  for (pasta::Macro mn : ast.Macros()) {

    // Include all uses macros, and only those `#define`s for which the
    // macro is used at least once.
    if (auto md = pasta::DefineMacroDirective::From(mn)) {

      // If this macro definition doesn't have a name, then it's in a
      // conditionally disabled region.
      auto name = md->Name();
      if (!name) {
        continue;
      }

      // Builtin or command-line specified macros have no location.
      //
      // NOTE(pag): The persistence for macros re-interprets macros with no
      //            definition site as substitutions instead of macro
      //            expansions.
      //
      // TODO(pag): Find a way to give these file locations.
      if (!name->FileLocation()) {
        continue;
      }

      for (pasta::Macro use : md->Uses()) {
        tlms.emplace_back(std::move(mn), order++);
        defs.push_back(std::move(md.value()));
        break;
      }

    // Include all `#include`s, `#pragma`s, `#if`s, etc.
    } else if (auto dir = pasta::MacroDirective::From(mn)) {
      if (!dir->Hash().FileLocation()) {
        continue;
      }

      tlms.emplace_back(mn, order++);

      // If it's an include-like directive, then we want to be able to associate
      // begin- and end-of-file markers with this directive. Here we'll find
      // the relevant begin-of-file markers.
      auto ild = pasta::IncludeLikeMacroDirective::From(mn);
      if (!ild) {
        continue;
      }

      // Find the end token of the `#include`.
      auto ild_et = ild->EndToken();
      if (!ild_et) {
        continue;
      }

      // Scan backward looking for the beginning of macro marker.
      uint64_t i = ild_et->ParsedLocation().Index();
      uint64_t j = i;
      for (; j; --j) {
        if (tokens[j].Role() == pasta::TokenRole::kBeginOfMacroExpansionMarker) {
          break;
        }
      }

      assert(0u < j);

      // Scan forward beyond the end token of the `#include` by a fudge factor
      // and try to find a beginning of file marker.
      for (auto max_i = std::min(num_tokens, i + 8u); i < max_i; ++i) {
        if (tokens[i].Role() != pasta::TokenRole::kBeginOfFileMarker) {
          continue;
        }

        auto it = bof_to_eof.find(i);
        if (it == bof_to_eof.end()) {
          continue;
        }

        // Map the EOF marker to the BOM marker token for the `#include`.
        eof_to_include.emplace(it->second, j);
        break;
      }
    }
  }

  for (pasta::DefineMacroDirective def : defs) {
    for (pasta::Macro use : def.Uses()) {
      tlms.emplace_back(RootMacroFrom(std::move(use)), order++);
    }
  }

  auto eq = +[] (const OrderedMacro &a, const OrderedMacro &b) {
    return a.first.RawMacro() == b.first.RawMacro();
  };

  auto less = +[] (const OrderedMacro &a, const OrderedMacro &b) {
    auto a_id = a.first.RawMacro();
    auto b_id = b.first.RawMacro();
    if (a_id < b_id) {
      return true;
    } else if (a_id > b_id) {
      return false;
    } else {
      return a.second < b.second;
    }
  };

  auto orig_less = +[] (const OrderedMacro &a, const OrderedMacro &b) {
    return a.second < b.second;
  };

  std::sort(tlms.begin(), tlms.end(), less);
  auto it = std::unique(tlms.begin(), tlms.end(), eq);
  tlms.erase(it, tlms.end());

  // NOTE(pag): It is extremely important to retain the original ordering. You
  //            can't rely on `sort` (a quicksort) to behave like a stable sort,
  //            nor can you rely on ASTs of different translation units putting
  //            side-by-side declarations one-after-another in memory, thus
  //            getting the same sort order. This is why we keep the extra info
  //            in the `pair` of the original sort order.
  std::sort(tlms.begin(), tlms.end(), orig_less);

  return tlms;
}

// Add a macro to our entity range list. The first token in a macro is usually
// the first usage token, and the last one is the last expansion token.
static void AddMacroRangeToEntityList(
    const pasta::TokenRange &tok_range, std::string_view main_file_path,
    std::vector<EntityRange> &entity_ranges, pasta::Macro node) {

  std::optional<pasta::MacroToken> bt = node.BeginToken();
  std::optional<pasta::MacroToken> et = node.EndToken();

  LOG_IF(FATAL, !bt && !et)
      << "Unable to find either the beginning or ending of macro node in "
         "translation unit of main source file "
      << main_file_path;

  std::optional<pasta::Token> pbt;
  std::optional<pasta::Token> pet;

  if (bt) {
    pbt = bt->ParsedLocation();
  }

  if (et) {
    pet = et->ParsedLocation();
  }

  if (!pbt) {
    pbt = pet;
  }

  if (!pet) {
    pet = pbt;
  }

  if (!pbt || !pet) {
    LOG(ERROR)
        << "Unable to find beginning/ending of macro node in translation unit "
           "of main source file "
        << main_file_path;
    return;
  }

  auto [begin_index, end_index] = ExpandRange(
      tok_range, pbt->Index(), pet->Index());

  entity_ranges.emplace_back(std::move(node), begin_index, end_index);
}

// Sort the top-level declarations so that syntactically overlapping
// declarations are in the correct order, and are side-by-side in the output
// vector.
static std::vector<EntityRange> SortEntities(const pasta::AST &ast,
                                             std::string_view main_file_path) {

  pasta::TokenRange tokens = ast.Tokens();
  std::vector<EntityRange> entity_ranges;
  entity_ranges.reserve(8192u);

  std::map<uint64_t, uint64_t> eof_index_to_include;
  std::map<uint64_t, uint64_t> bof_to_eof;

  // Find end-of-file indices. Sometimes we need to expand declaration ranges
  // out to include an end of file if they include the beginning of the file.
  // This helps keep later `TokenTree` stuff balanced, and relates to Issue
  // #258.
  std::vector<uint64_t> open_indexes;
  open_indexes.reserve(64u);
  for (const pasta::Token &tok : tokens) {
    switch (tok.Role()) {
      case pasta::TokenRole::kBeginOfFileMarker:
        open_indexes.push_back(tok.Index());
        break;
      case pasta::TokenRole::kEndOfFileMarker:
        if (open_indexes.empty()) {  // Unbalanced EOF marker.
          assert((tok.Index() + 1u) == tokens.Size());
        } else {
          bof_to_eof.emplace(open_indexes.back(), tok.Index());
          open_indexes.pop_back();
        }
        break;
      case pasta::TokenRole::kFileToken:
        if (open_indexes.empty()) {
          open_indexes.push_back(tok.Index());
        }
        break;
      default:
        break;
    }
  }

  for (OrderedMacro ordered_entry : FindTLMs(ast, tokens, bof_to_eof,
                                             eof_index_to_include)) {
    AddMacroRangeToEntityList(tokens, main_file_path, entity_ranges,
                              std::move(ordered_entry.first));
  }

  for (OrderedDecl ordered_entry : FindTLDs(ast)) {
    AddDeclRangeToEntityList(tokens, main_file_path, eof_index_to_include,
                             bof_to_eof, std::move(ordered_entry.first),
                             entity_ranges);
  }

  // It's possible that we have two-or-more things that appear to be top-level
  // decls, but really we're only dealing with one top-level decl. This happens
  // with things like `typedef`s in Clang when the referenced type of a typedef
  // is defined within the typedef (e.g. a union/struct/enum type). In these
  // cases, Clang places the definition of the referenced type before the
  // typedef inside of the `DeclContext`, and so the referenced type appears
  // as its own top-level declaration, despite it being logically nested inside
  // of another top-level declaration.

  std::stable_sort(entity_ranges.begin(), entity_ranges.end(),
                   [] (const EntityRange &a, const EntityRange &b) {
                     auto a_begin = std::get<kBeginIndex>(a);
                     auto b_begin = std::get<kBeginIndex>(b);
                     if (a_begin < b_begin) {
                       return true;
                     } else if (a_begin > b_begin) {
                       return false;
                     } else {
                       return std::get<kEndIndex>(a) < std::get<kEndIndex>(b);
                     }
                   });

  return entity_ranges;
}

// TODO(pag,kumarak): Add support for detecting that some of the containing
//                    statements have errors.
//
//                    Need to use `Stmt::ContainsErrors`.
static bool StatementsHaveErrors(const pasta::Decl &) {
  return false;
}

// Try to accumulate the nearby top-level declarations whose token ranges
// overlap with `decl` into `decls_for_chunk`. For example, this process
// will accumulate three `VarDecl`s into `decls_for_chunk` in the following
// case:
//
//      int optind, opterr, optopt;
//
// This also happens when multiplier declarations are defined by macros,
// as well as for template specializations.
//
// TODO(pag): Handle top-level statements, e.g. `asm`, `static_assert`, etc.
static std::vector<EntityGroupRange> PartitionEntities(
    GlobalIndexingState &context, const pasta::AST &ast) {

  std::string main_file_path = ast.MainFile().Path().generic_string();

  ProgressBarWork partitioning_progress_tracker(context.partitioning_progress);

  std::vector<EntityRange> entity_ranges = SortEntities(ast, main_file_path);
  std::vector<EntityGroupRange> entity_group_ranges;
  entity_group_ranges.reserve(entity_ranges.size());

  for (size_t i = 0u, max_i = entity_ranges.size(); i < max_i; ) {
    EntityGroup entities_for_group;
    const EntityRange &entity_range = entity_ranges[i];
    uint64_t begin_index = std::get<kBeginIndex>(entity_range);
    uint64_t end_index = std::get<kEndIndex>(entity_range);

    for (; i < max_i; ++i) {

      const EntityRange &next_entity_range = entity_ranges[i];
      const Entity &next_entity = std::get<kEntityIndex>(next_entity_range);
      uint64_t next_begin = std::get<kBeginIndex>(next_entity_range);
      uint64_t next_end = std::get<kEndIndex>(next_entity_range);

      // Doesn't close over.
      if (next_begin > end_index) {
        break;
      }

      if (std::holds_alternative<pasta::Decl>(next_entity)) {
        CHECK_EQ(StatementsHaveErrors(std::get<pasta::Decl>(next_entity)), 0u);
      }

      // Make sure we definitely enclose over the next decl.
      begin_index = std::min(begin_index, next_begin);
      end_index = std::max(end_index, next_end);
      entities_for_group.push_back(next_entity);
    }

    CHECK(!entities_for_group.empty());
    entity_group_ranges.emplace_back(
        std::move(entities_for_group), begin_index, end_index);
  }

  return entity_group_ranges;
}

// Try to find the first and last tokens in the range with a file location,
// as a kind of anchor point of where this fragment is located in its main
// source file. These begin/end locations also help with search.
//
// NOTE(pag): We use the hash of the contents of the file as a part of our
//            key, rather than the absolute path. This is so that if we
//            are indexing more than one project, then the local copy of a
//            header file and the installed copy will resolve to the same
//            hash, and so we'll do a better job of deduping top-level
//            declarations in that case.
static std::optional<FileLocationOfFragment> FindFileLocationOfFragment(
    const EntityIdMap &entity_ids, const pasta::TokenRange &toks,
    uint64_t begin_index, uint64_t end_index) {

  mx::RawEntityId file_index = 0u;
  std::optional<pasta::FileToken> begin_tok;
  std::optional<pasta::FileToken> end_tok;

  // Find the first one.
  uint64_t i = begin_index;
  for (; i <= end_index; ++i) {
    begin_tok = AsTopLevelFileToken(toks[i]);
    if (!begin_tok) {
      continue;
    }

    auto id_it = entity_ids.find(begin_tok->RawFile());
    if (id_it == entity_ids.end()) {
      continue;
    }

    mx::VariantId vid = mx::EntityId(id_it->second).Unpack();
    if (!std::holds_alternative<mx::FileId>(vid)) {
      continue;
    }

    file_index = std::get<mx::FileId>(vid).file_id;
    goto find_last_token;
  }

  return std::nullopt;

find_last_token:

  // Find the last one.
  for (uint64_t j = end_index; j >= i; --j) {
    end_tok = AsTopLevelFileToken(toks[j]);
    if (!end_tok) {
      continue;
    }

    auto id_it = entity_ids.find(end_tok->RawFile());
    if (id_it == entity_ids.end()) {
      continue;
    }

    mx::VariantId vid = mx::EntityId(id_it->second).Unpack();
    if (!std::holds_alternative<mx::FileId>(vid)) {
      continue;
    }

    mx::FileId fid = std::get<mx::FileId>(vid);
    if (fid.file_id != file_index) {
      continue;
    }

    goto found_tokens;
  }

  return std::nullopt;

found_tokens:

  mx::FileId fid(file_index);

  mx::FileTokenId btid;
  btid.file_id = file_index;
  btid.kind = TokenKindFromPasta(begin_tok.value());
  btid.offset = static_cast<mx::EntityOffset>(begin_tok->Index());

  mx::FileTokenId etid;
  etid.file_id = file_index;
  etid.kind = TokenKindFromPasta(end_tok.value());
  etid.offset = static_cast<mx::EntityOffset>(end_tok->Index());

  return FileLocationOfFragment(fid, btid, etid);
}

static void CreatePendingFragment(
    mx::DatabaseWriter &database, EntityIdMap &entity_ids,
    const pasta::TokenRange &tok_range, const EntityGroupRange &group_range,
    std::vector<PendingFragment> &pending_fragments) {

  const EntityGroup &entities = std::get<kGroupIndex>(group_range);
  uint64_t begin_index = std::get<kBeginIndex>(group_range);
  uint64_t end_index = std::get<kEndIndex>(group_range);

  // Locate where this fragment is in its file.
  std::optional<FileLocationOfFragment> floc = FindFileLocationOfFragment(
      entity_ids, tok_range, begin_index, end_index);

  // Don't create token `decls_for_chunk` if the decl is already seen. This
  // means it's already been indexed.
  bool is_new_fragment_id = false;

  PendingFragment pf(
      database.GetOrCreateFragmentIdForHash(
          (floc ? floc->first_file_token_id.Pack() : mx::kInvalidEntityId),
          HashFragment(entities, tok_range, begin_index, end_index),
          (end_index - begin_index + 1ul)  /* num_tokens */,
          is_new_fragment_id  /* mutated by reference */));

  pf.file_location = std::move(floc);
  pf.begin_index = begin_index;
  pf.end_index = end_index;

  for (const Entity &entity : entities) {
    if (std::holds_alternative<pasta::Decl>(entity)) {
      pf.top_level_decls.push_back(std::get<pasta::Decl>(entity));
      pf.num_top_level_declarations++;

    } else if (std::holds_alternative<pasta::Macro>(entity)) {
      pf.top_level_macros.push_back(std::get<pasta::Macro>(entity));
      pf.num_top_level_macros++;

    } else {
      LOG(FATAL)
          << "TODO: Unsupported top-level entity kind";
    }
  }

  CHECK_NE((pf.num_top_level_declarations + pf.num_top_level_macros), 0u);

  // We always need to label the entities inside of a fragment, regardless of
  // if fragment is new. This is because each fragment might have arbitrary
  // references to other declarations. We need to be able to form cross-
  // fragment references when serializing things, so we use the labeller to
  // assign IDs to entities (decls, statements, etc.) in a uniform and
  // deterministic way so that other threads doing similar indexing will form
  // identically labelled chunks for the same logical entities.
  //
  // Unfortunately, the labeller needs to be manually written as opposed to
  // auto-generated, as our auto-generation has no concept of which AST
  // methods descend vs. cross the tree (into other fragments).
  LabelEntitiesInFragment(pf, entity_ids, tok_range);

  if (!is_new_fragment_id) {
    return;
  }

  pending_fragments.emplace_back(std::move(pf));
}

// Create fragments in reverse order that we see them in the AST. The hope
// is that this will reduce contention in trying to create fragment IDs for
// the redundant declarations that are likely to appear early in ASTs, i.e.
// in `#include`d headers.
static std::vector<PendingFragment> CreatePendingFragments(
    GlobalIndexingState &context, EntityIdMap &entity_ids,
    const pasta::AST &ast, std::vector<EntityGroupRange> decl_group_ranges) {

  ProgressBarWork identification_progress_tracker(
      context.identification_progress);

  std::vector<PendingFragment> pending_fragments;
  pending_fragments.reserve(decl_group_ranges.size());

  DLOG(INFO)
      << "Main source file " << ast.MainFile().Path().generic_string()
      << " has " << decl_group_ranges.size() << " possible fragments";

  pasta::TokenRange tok_range = ast.Tokens();

  // Visit decl range groups in reverse order, so that we're more likely to
  // see the definitely unique fragments first, as they'll appear in the main
  // source file of this translation unit.
  for (std::vector<EntityGroupRange>::reverse_iterator
       it = decl_group_ranges.rbegin(), end = decl_group_ranges.rend();
       it != end; ++it) {

    const EntityGroupRange &entities_in_fragment = *it;
    CreatePendingFragment(context.database, entity_ids, tok_range,
                          entities_in_fragment, pending_fragments);
  }

  return pending_fragments;
}

// Serialize the parsed fragments that were identified as new and/or "won"
// the race to assign a fragment ID in this thread of execution.
static void PersistParsedFragments(
    GlobalIndexingState &context, const pasta::AST &ast,
    EntityIdMap &entity_ids, std::vector<PendingFragment> pending_fragments) {

  pasta::TokenRange tok_range = ast.Tokens();
  NameMangler mangler(ast);

  DLOG(INFO)
      << "Main source file " << ast.MainFile().Path().generic_string()
      << " has " << pending_fragments.size() << " unique fragments";

  for (PendingFragment &pf : pending_fragments) {
    ProgressBarWork fragment_progress_tracker(context.serialization_progress);
    context.PersistFragment(ast, tok_range, mangler, entity_ids, pf);
  }
}

// Look through all files referenced by the AST get their unique IDs. If this
// is the first time seeing a file, then tokenize the file.
static void MaybePersistParsedFile(
    GlobalIndexingState &context, const pasta::File &file,
    EntityIdMap &entity_ids) {

  if (!file.WasParsed()) {
    return;
  }

  pasta::Result<std::string_view, std::error_code> maybe_data = file.Data();
  std::filesystem::path file_path = file.Path();
  if (!maybe_data.Succeeded()) {
    LOG(ERROR)
        << "Unable to get data for file '" << file_path.generic_string()
        << ": " << maybe_data.TakeError().message();
  }

  bool is_new_file_id = false;
  mx::DatabaseWriter &database = context.database;
  mx::SpecificEntityId<mx::FileId> file_id = database.GetOrCreateFileIdForHash(
      HashFile(maybe_data.TakeValue()), is_new_file_id);

  if (is_new_file_id) {
    context.PersistFile(file_id, file);
  }

  entity_ids.emplace(file.RawFile(), file_id.Pack());
}

// This persists any not-yet-seen files and their tokens. It also creates the
// file IDs for those files, so this always must happen.
static void PersistParsedFiles(
    GlobalIndexingState &context, const pasta::AST &ast,
    EntityIdMap &entity_ids) {
  ProgressBarWork progress_tracker(context.file_progress);
  auto parsed_files = ast.ParsedFiles();
  for (auto it = parsed_files.rbegin(), end = parsed_files.rend();
       it != end; ++it) {
    const pasta::File &parsed_file = *it;
    MaybePersistParsedFile(context, parsed_file, entity_ids);
  }
}

// Create an AST from a compile job.
static std::optional<pasta::AST> CompileJobToAST(
    const std::shared_ptr<GlobalIndexingState> &context,
    const pasta::CompileJob &job) {

  DLOG(INFO)
      << "Running compile job: " << job.Arguments().Join();

  ProgressBarWork parsing_progress_tracker(context->ast_progress);
  pasta::Result<pasta::AST, std::string> maybe_ast = job.Run();
  if (!maybe_ast.Succeeded()) {
    LOG(ERROR)
        << "Error building AST for command " << job.Arguments().Join()
        << " on main file " << job.SourceFile().Path().generic_string()
        << "; error was: " << maybe_ast.TakeError();
    return std::nullopt;
  }

  return maybe_ast.TakeValue();
}

}  // namespace

IndexCompileJobAction::~IndexCompileJobAction(void) {}

IndexCompileJobAction::IndexCompileJobAction(
    std::shared_ptr<GlobalIndexingState> context_,
    pasta::FileManager file_manager_,
    pasta::CompileJob job_)
    : context(std::move(context_)),
      file_manager(std::move(file_manager_)),
      job(std::move(job_)) {}

// Build and index the AST.
void IndexCompileJobAction::Run(void) {

  std::optional<pasta::AST> maybe_ast = CompileJobToAST(context, job);
  if (!maybe_ast) {
    return;
  }

  EntityIdMap entity_ids;
  pasta::AST ast = std::move(maybe_ast.value());

  DLOG(INFO)
      << "Built AST for main source file "
      << ast.MainFile().Path().generic_string();

  PersistParsedFiles(*context, ast, entity_ids);
  PersistParsedFragments(
      *context, ast, entity_ids,
      CreatePendingFragments(
          *context, entity_ids, ast,
          PartitionEntities(*context, ast)));
}

}  // namespace indexer
