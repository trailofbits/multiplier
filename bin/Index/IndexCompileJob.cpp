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
#include <multiplier/Frontend/TokenKind.h>
#include <multiplier/Types.h>
#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Printer.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/File.h>
#include <set>
#include <tuple>
#include <unordered_set>
#include <vector>

#include "Context.h"
#include "EntityMapper.h"
#include "Hash.h"
#include "IdStore.h"
#include "NameMangler.h"
#include "PendingFragment.h"
#include "Provenance.h"
#include "TypeMapper.h"
#include "Util.h"

namespace indexer {

// Label the initial entities of this fragment. This focuses on finding the
// entities that syntactically belong to this fragment, and assigning them
// IDs. Labeling happens first for all fragments, then we run `Build` for
// new fragments that we want to serialize.
extern void LabelDeclsInFragment(PendingFragment &);

extern void LabelTokensAndMacrosInFragment(PendingFragment &);

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

static bool IsProbablyABuiltinDecl(const pasta::Decl &decl);

// Find all top-level declarations.
class TLDFinder final : public pasta::DeclVisitor {
 private:
  std::vector<OrderedDecl> &tlds;

  // Tracks declarations for which we've seen the specializations. This is
  // to prevent us from double-adding specializations.
  std::unordered_set<pasta::Decl> seen_specs;

  // Depth of a decl context.
  std::unordered_map<const void *, unsigned> dc_depth;

  // If it doesn't look like a builtin declaration, then shift the order
  // by a fudge factor. Clang can invent a lot of builtins, though definitely
  // not more than 100,000.
  unsigned builtin_order{0u};
  unsigned order{100000u};

  unsigned depth{0u};

  // Clang will invent some builtins just-in-time, and "just-in-time" ends up
  // appearing logically after they're needed. E.g. when declaring
  // `operator new`, Clang will invent the `std` namespace, and then invent
  // things like `std::align_val_t` and the global `operator new`. These will
  // appear *after* any uses of these things in the translation unit. So we
  // need to arrange for them to be in the right order.
  void AddDecl(const pasta::Decl &decl) {
    if (IsProbablyABuiltinDecl(decl)) {
      tlds.emplace_back(decl, builtin_order++);
    } else {
      tlds.emplace_back(decl, order++);
    }
  }

 public:
  virtual ~TLDFinder(void) = default;

  explicit TLDFinder(std::vector<OrderedDecl> &tlds_)
      : tlds(tlds_) {}

  void VisitDeeperDeclContext(const pasta::DeclContext &dc) {
    ++depth;
    VisitDeclContext(dc);    
    --depth;
  }

  void VisitDeclContext(const pasta::DeclContext &dc) {
    dc_depth.emplace(dc.RawDeclContext(), depth);

    for (const pasta::Decl &decl : dc.AlreadyLoadedDeclarations()) {
      if (!decl.IsInvalidDeclaration()) {
        Accept(decl);
      }
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

  void VisitTypedefDecl(const pasta::TypedefDecl &decl) final {
    if (!decl.IsImplicit() || decl.Token()) {
      VisitTypedefNameDecl(decl);
      return;
    }

    assert(!depth);

    pasta::Type ut = decl.UnderlyingType();

    // It's probably a builtin typedef, e.g. `__NSConstantString`. This may
    // contain a reference to a builtin record type, e.g.
    // `__NSConstantString_tag`, that is technically part of the same
    // declaration context, but hasn't actually been added to the declaration
    // context.
    if (auto tag = ut.AsTagDeclaration()) {
      Accept(tag.value());

    // Builtin typedefs may be hiding top-level entities that are logically
    // only defined in the declarator of the typedef, e.g.
    // `__builtin_va_list_tag` within `__builtin_va_list`. Unlike when normal
    // code does this, Clang doesn't add these internal declarations to the
    // `TranslationUnitDecl`'s list of declararations, which "hides" it from
    // the top-level decl list, and what can be labelled. This matters
    // because the underlyng structure type might become directly externally
    // reachable by way of dayed types, e.g. `va_list` as a parameter to a
    // function.
    } else if (auto tp = ut.PointeeOrArrayElementType()) {
      if (tag = tp->AsTagDeclaration(); tag.has_value()) {
        Accept(tag.value());
      }
    }

    VisitTypedefNameDecl(decl);
  }

  // Specializations / instantiations of a partial template specialization end
  // up attaching to the `ClassTemplateDecl`, however, partial specializations
  // can contain their own `ClassTemplateDecl`s, which themselves can be
  // specialized, so we want to go find those.
  //
  // For example: https://gcc.godbolt.org/z/9Wjde1WYo
  //              https://gcc.godbolt.org/z/MGrMjxxvx

  // NOTE(kumarak): All class template specialization and partial specialization
  //                gets added to the top-level declarations.
  void VisitClassTemplatePartialSpecializationDecl(
      const pasta::ClassTemplatePartialSpecializationDecl &decl) final {
    VisitDeeperDeclContext(decl);
    AddDecl(decl);
  }

  void VisitClassTemplateSpecializationDecl(
      const pasta::ClassTemplateSpecializationDecl &decl) final {
    // Note: If the specialization is explict and is in the redeclaration
    //       table, the canonical decl may not get added as one of the TLD
    //       and any reference of canonical reference will not get resolved

    VisitDeeperDeclContext(decl);

    if(IsExplicitSpecialization(decl.TemplateSpecializationKind()) &&
       !decl.IsCanonicalDeclaration()) {
      Accept(decl.CanonicalDeclaration());
    }
    AddDecl(decl);
  }

  // void VisitVarTemplatePartialSpecializationDecl(
  //     const pasta::VarTemplatePartialSpecializationDecl &) final {
  //   // Do nothing.
  // }

  void VisitClassTemplateDecl(const pasta::ClassTemplateDecl &decl) final {
    // Note: The canonical declaration of specialization always points to the base
    //       decl. Disable it temporarily.
    // TODO(kumarak) : Discuss with pag before finalizing the change. Should we check for
    //                 canonical declaration to avoid redeclaration getting into a fragment?
    //                 The missing redeclaration fragment causes assert during reference
    //                 lookup in mx-api.
    if (!seen_specs.emplace(decl).second) {
      return;
    }

    for (const pasta::ClassTemplateSpecializationDecl &spec :
             decl.Specializations()) {

      // We should observe the explicit specializations and instantiations
      // separately.
      if(IsExplicitSpecialization(spec.TemplateSpecializationKind())) {
        continue;
      }
      Accept(spec);
    }

    VisitDeeperDeclContext(decl.TemplatedDeclaration());
    AddDecl(decl);
  }

  void VisitVarTemplateDecl(const pasta::VarTemplateDecl &decl) final {
    for (const pasta::VarTemplateSpecializationDecl &spec : decl.Specializations()) {
      Accept(spec);
    }
    AddDecl(decl);
  }

  void VisitVarTemplatePartialSpecializationDecl(
      const pasta::VarTemplatePartialSpecializationDecl &decl) final {
    AddDecl(decl);
  }

  void VisitVarTemplateSpecializationDecl(
      const pasta::VarTemplateSpecializationDecl &decl) {
    AddDecl(decl);
  }

  void VisitFunctionTemplateDecl(const pasta::FunctionTemplateDecl &decl) final {
    if (!seen_specs.emplace(decl).second) {
      return;
    }

    for (const pasta::FunctionDecl &spec : decl.Specializations()) {

      // We should observe the explicit specializations and instantiations
      // separately.
      // Note: In case of function template, an implicit specialization may
      //       appear out-of-line and a friend of class template. In that case
      //       the same node will be rechable from the class template specialization
      //       decl as well. The check for out-of-line instantiation avoid adding
      //       them immediately to the node and handle when it appears next.
      if(IsExplicitSpecialization(spec.TemplateSpecializationKind())
        || spec.IsOutOfLine()) {
        continue;
      }

      // TODO(kumarak): Not sure how to handle CXXDeductionGuide. Don't add them 
      //                to top-level declarations.
      if (spec.Kind() == pasta::DeclKind::kCXXDeductionGuide) {
        continue;
      }

      VisitDeeperDeclContext(spec);
    }

    // Note: A FunctionTemplateDecl node can be inline to a Record context and
    //       should not be added to the list of TLDs since Record is already
    //       a TLD. The check about the lexical context avoid this scenario.
    //
    //       It also avoid inconsistencies with tagging FunctionTemplateDecl as
    //       TLD where a decl can be beneath an Expr and not getting tagged as TLD.
    //       Only FunctionTemplateDecl that are top-level will be tagged as TLDs.
    if (auto lc = decl.LexicalDeclarationContext(); lc && lc->IsRecord()) {
      return;
    }
    VisitDecl(decl);
  }

  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final {
    for (const pasta::TemplateParameterList &params :
             decl.TemplateParameterLists()) {
      if (params.NumParameters() || params.HasUnexpandedParameterPack()) {
        return;
      }
    }

    // Go hunting for things like `std::align_val_t`.
    //
    // NOTE(pag): The parameters of an implicit `operator new` lack types?!
    if (IsProbablyABuiltinDecl(decl)) {
      for (pasta::ParmVarDecl p : decl.Parameters()) {
        if (!p.IsImplicit()) {
          continue;
        }
        if (auto tag = p.Type().AsTagDeclaration()) {
          if (IsProbablyABuiltinDecl(tag.value())) {
            Accept(tag.value());
          }
        }
      }
    }

    VisitDecl(decl);
  }

  void VisitRecordDecl(const pasta::RecordDecl &decl) final {

    // Forward declarations embedded in declarators within a record may have
    // a semantic decl context that is at the top level.
    VisitDeeperDeclContext(decl);

    VisitDecl(decl);
  }

  void VisitCXXMethodDecl(const pasta::CXXMethodDecl &decl) final {

    // If the CXXMethodDecl is implicit, don't need to visit
    // the declaration; return early.
    if (decl.IsImplicit()) {
      return;
    }

    VisitFunctionDecl(decl);

    // The method can be explicitly instantiated and out of line. If true
    // add them to the tld's if the decl is templated or the definition.
    // For out of line methods, the clang patches preserves the lexical
    // structure of the AST node and method definition does not get
    // merged with the declarations.
    // if (decl.IsOutOfLine() && (decl.IsTemplated() ||
    //    decl.IsThisDeclarationADefinition())) {
    //  AddDecl(decl);
    // }
  }

  void VisitUsingShadowDecl(const pasta::UsingShadowDecl &) final {

  }

  void VisitTypeAliasTemplateDecl(const pasta::TypeAliasTemplateDecl &decl) final {
    VisitDecl(decl);
  }

  void VisitFriendDecl(const pasta::FriendDecl &decl) final {
    // If there is a FriendDecl; visit the inner declaration
    // and add them to the top-level decl.
    if (auto fdl = decl.FriendDeclaration()) {
      if (auto td = pasta::TemplateDecl::From(fdl.value())) {
        Accept(td.value());
      }
    }
  }

  void VisitConceptDecl(const pasta::ConceptDecl &decl) {
    VisitDecl(decl);
  }

  void VisitDecl(const pasta::Decl &decl) final {
    if (!depth) {
      AddDecl(decl);

    // Check if we found something that is semantically at the top level.
    } else if (auto sema_dc = decl.DeclarationContext()) {
      if (!dc_depth[sema_dc->RawDeclContext()]) {
        AddDecl(decl);
      }
    }
  }
};

static uint64_t ParsedIndexOfMacroDirective(const pasta::Macro &macro) {
  return macro.BeginToken()->ParsedLocation().Index();
}

static bool IsOpeningConditionalDirective(const pasta::MacroDirective &macro) {
  switch (macro.Kind()) {
    case pasta::MacroKind::kIfDirective:
    case pasta::MacroKind::kIfDefinedDirective:
    case pasta::MacroKind::kIfNotDefinedDirective:
      return true;
    default:
      return false;
  }
}

static bool IsContinuingConditionalDirective(const pasta::Macro &macro) {
  switch (macro.Kind()) {
    case pasta::MacroKind::kElseIfDirective:
    case pasta::MacroKind::kElseIfDefinedDirective:
    case pasta::MacroKind::kElseIfNotDefinedDirective:
    case pasta::MacroKind::kElseDirective:
      return true;
    default:
      return false;
  }
}

static bool IsClosingConditionalDirective(const pasta::Macro &macro) {
  return macro.Kind() == pasta::MacroKind::kEndIfDirective;
}

static pasta::Macro RootMacroFrom(pasta::Macro node) {
  if (auto parent = node.Parent()) {
    return RootMacroFrom(parent.value());
  } else {
    return node;
  }
}

static std::optional<pasta::MacroToken> BeginToken(pasta::Macro macro) {
  auto tok = pasta::MacroToken::From(macro);
  if (tok) {
    return tok;
  }

  return macro.BeginToken();
}

static std::string MacroLocation(pasta::Macro macro) {
  if (auto tok = BeginToken(RootMacroFrom(macro))) {
    if (auto ftok = tok->ParsedLocation().FileLocation()) {
      auto file = pasta::File::Containing(ftok.value());
      std::stringstream ss;
      ss << file.Path().generic_string() << ':' << ftok->Line()
         << ':' << ftok->Column();
      return ss.str();
    }
  }

  return "<unknown-loc>";
}

// Generate all directives that may be nested inside some top-level thing.
// For example, the following are allowed.
//
//    MACRO(
//        ...
//    #define ...
//        ...
//        )
//
// And:
//    MACRO(
//        ...
//    #if ...
//        ...
//    #endif
//        ...
//        )
//
// If `mn` isn't already a macro directive, then we explore its use tree to
// find macro directives (e.g. `#define`, `#if`, and `#endif` above). These
// directives are always in the use sides rather than the intermediate/expansion
// sides as they are handled in an early phase of pre-processing.
static gap::generator<pasta::MacroDirective>
FindDirectivesInMacro(pasta::Macro mn) {
  switch (mn.Kind()) {
    case pasta::MacroKind::kArgument:
    case pasta::MacroKind::kExpansion:
    case pasta::MacroKind::kSubstitution:
      for (pasta::Macro child : mn.Children()) {
        for (auto def : FindDirectivesInMacro(child)) {
          co_yield def;
        }
      }
      break;

    default:
      if (auto dir = pasta::MacroDirective::From(mn)) {
        co_yield std::move(dir.value());
      }
      break;
  }
}

// Map `#if` to `#endif` or `#if` to `#else` and then `#else` to `#elif` or
// `#endif`, etc. This helps with Issue #457, where we have something like the
// following (found in cURL):
//
//    struct X {
//      ...
//    #ifdef CONFIG
//      ...
//    };
//    #else
//      ...
//    };
//    #endif
//
// Here, in different build configurations, we have different end points for
// `struct X`. This is hard to deal with in the mx-api `TokenTree` code, because
// if `CONFIG` evaluates to true-like, then `#else` is its own independent
// fragment, whereas in `CONFIG` evaluates to false-like, then `#else` is a top-
// level macro in the `struct X` fragment. Our goal is thus to use the
// `FindNextPrevConditionalMacros` to help us find chains to `#if`, `#else`, etc. so
// that if we have a fragment that contains something like the above, then we
// can extend its bounds, possibly as far as the `#endif`.
//
// XREF(pag): https://github.com/trailofbits/multiplier/issues/457
static std::map<uint64_t, pasta::Macro> FindNextPrevConditionalMacros(
    const pasta::AST &ast, std::string_view main_file_path) {

  std::vector<pasta::Macro> prev;
  std::map<uint64_t, pasta::Macro> next;

  auto add_to_prev = [&] (const pasta::Macro &macro, const char *what) {
    CHECK(!prev.empty())
        << "Failed to add " << what << " when indexing " << main_file_path
        << " near " << MacroLocation(macro);

    auto prev_index = ParsedIndexOfMacroDirective(prev.back());
    auto index = ParsedIndexOfMacroDirective(macro);
    next.emplace(prev_index, macro);
    next.emplace(~index, prev.back());
  };

  for (pasta::Macro macro : ast.Macros()) {
    for (auto dir : FindDirectivesInMacro(macro)) {
      if (IsOpeningConditionalDirective(dir)) {
        prev.emplace_back(std::move(dir));

      } else if (IsContinuingConditionalDirective(dir)) {
        add_to_prev(dir, "continuing conditional directive");
        prev.back() = std::move(dir);

      } else if (IsClosingConditionalDirective(dir)) {
        add_to_prev(dir, "closing conditional directive");
        prev.pop_back();
      }
    }
  }
  return next;
}

// Find all top-level declarations.
static std::vector<OrderedDecl> FindTLDs(const pasta::AST &ast) {

  std::vector<OrderedDecl> tlds;
  TLDFinder tld_finder(tlds);
  tld_finder.VisitTranslationUnitDecl(ast.TranslationUnit());

  auto decl_eq = +[] (const OrderedDecl &a, const OrderedDecl &b) {
    return a.first.RawDecl() == b.first.RawDecl();
  };

  auto decl_less = +[] (const OrderedDecl &a, const OrderedDecl &b) {
    return a.first.RawDecl() < b.first.RawDecl();
  };

  auto order_less = +[] (const OrderedDecl &a, const OrderedDecl &b) {
    return a.second < b.second;
  };

  std::sort(tlds.begin(), tlds.end(), decl_less);
  auto it = std::unique(tlds.begin(), tlds.end(), decl_eq);
  tlds.erase(it, tlds.end());

  // NOTE(pag): It is extremely important to retain the original ordering. You
  //            can't rely on `sort` (a quicksort) to behave like a stable sort,
  //            nor can you rely on ASTs of different translation units putting
  //            side-by-side declarations one-after-another in memory, thus
  //            getting the same sort order. This is why we keep the extra info
  //            in the `pair` of the original sort order.
  std::sort(tlds.begin(), tlds.end(), order_less);

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

static pasta::TokenRange BaselineEntityRange(const pasta::Macro &macro) {

  std::optional<pasta::MacroToken> begin_tok = macro.BeginToken();
  std::optional<pasta::MacroToken> end_tok = EndToken(macro);

  CHECK(begin_tok.has_value());
  CHECK(end_tok.has_value());

  std::optional<pasta::TokenRange> range = pasta::TokenRange::From(
      begin_tok->ParsedLocation(), end_tok->ParsedLocation());

  CHECK(range.has_value());
  return range.value();
}

static uint64_t PreviousConditionalIndex(
    const std::map<uint64_t, pasta::Macro> &dir_index_to_next_dir,
    const pasta::Macro &macro) {

  uint64_t macro_index = ParsedIndexOfMacroDirective(macro);
  auto it = dir_index_to_next_dir.find(~macro_index);
  if (it != dir_index_to_next_dir.end()) {
    return ParsedIndexOfMacroDirective(it->second);

  } else {
    return macro_index;
  }
}

static uint64_t EndOfConditionalSequence(
    const std::map<uint64_t, pasta::Macro> &dir_index_to_next_dir,
    const pasta::Macro &macro) {

  uint64_t macro_index = ParsedIndexOfMacroDirective(macro);
  auto it = dir_index_to_next_dir.find(macro_index);
  if (it != dir_index_to_next_dir.end()) {
    return EndOfConditionalSequence(dir_index_to_next_dir, it->second);

  } else {
    return macro_index;
  }
}

// In Issue #457, we want to expand the entity range to possibly go beyond and
// into other directives. This happens when the arms of an `#if` can possibly
// create other versions of our directive. For example:
//
//    struct X {
//      ...
//    #ifdef CONFIG
//      ...
//    };
//    #else
//      ...
//    };
//    #endif
//
// Here, we want all variants of the fragment to end at the `#endif`.
//
// NOTE(pag): `tests/Macros/FragmentWithMultipleBounds.c` covers this case.
static uint64_t ExpandToEndOfNextDirective(
    const std::map<uint64_t, pasta::Macro> &dir_index_to_next_dir,
    uint64_t begin_index, uint64_t end_index, uint64_t max_index) {

  for (auto bi = begin_index; bi <= end_index; ) {
    auto it = dir_index_to_next_dir.upper_bound(bi);
    if (it == dir_index_to_next_dir.end()) {
      return end_index;
    }

    // We've gone into the back-references.
    if (it->first >= max_index) {
      return end_index;
    }

    const pasta::Macro &dir = it->second;
    uint64_t dir_begin_index = 0u;
    uint64_t dir_end_index = 0u;

    if (IsClosingConditionalDirective(dir)) {
      dir_begin_index = PreviousConditionalIndex(dir_index_to_next_dir, dir);
      dir_end_index = ParsedIndexOfMacroDirective(dir);

    } else {
      dir_begin_index = it->first;
      dir_end_index = EndOfConditionalSequence(dir_index_to_next_dir, dir);
    }

    CHECK_LT(dir_begin_index, dir_end_index);

    if (dir_begin_index > begin_index && dir_begin_index < end_index &&
        dir_end_index > end_index) {
      return dir_end_index;
    }

    bi = dir_end_index;
  }

  return end_index;
}

// Expand an inclusive `[begin, end]` range to be as wide as necessary to
// include the full scope of macro expansion.
static std::pair<uint64_t, uint64_t> ExpandRange(
    const pasta::TokenRange &range,
    uint64_t begin_tok_index, uint64_t end_tok_index) {

  const auto max_tok_index = range.Size();

  // TODO(pag): The following code doesn't handle something like:
  //
  //            enum Foo
  //            #include "Foo_body.h"
  //
  //            Where `Foo`'s `;` is in `Foo_body.h`.

  // We should always at least hit the end of file marker token first.
  CHECK_LT(end_tok_index, max_tok_index);

  auto in_macro = false;
  auto seen_marker = false;

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
        seen_marker = true;
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
        in_macro = true;
        break;
    }
  }

  assert(!in_macro || seen_marker);
  in_macro = false;
  seen_marker = false;

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
        seen_marker = true;
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
        in_macro = true;
        break;
    }
  }

  assert(!in_macro || seen_marker);
  (void) in_macro;
  (void) seen_marker;

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
    const pasta::TokenRange &range,
    const std::map<uint64_t, pasta::Macro> &dir_index_to_next_dir,
    pasta::Decl decl, pasta::Token tok, std::string_view main_file_path) {

  auto [begin_tok_index, end_tok_index] = BaselineEntityRange(
      decl, tok, main_file_path);

  // Issue #457: Detect when the baseline range includes an unclosed `#if` or
  //             `#else`, then expand to the `#endif`.
  end_tok_index = ExpandToEndOfNextDirective(
      dir_index_to_next_dir, begin_tok_index, end_tok_index, range.Size());

  return ExpandRange(range, begin_tok_index, end_tok_index);
}

// Returns `true` if `decl` is probably a compiler-built-in declaration. It's
// not possible to get location information for these, unless we first printed
// out the compiler builtins to a file and then introduced those as a special
// preamble.
bool IsProbablyABuiltinDecl(const pasta::Decl &decl) {

  // The compiler knows how to recognize builtin functions.
  //
  // NOTE(pag): Clang will sometimes "upgrade" user-defined functions into
  //            builtins, hence the prior check on not having a location.
  if (auto fd = pasta::FunctionDecl::From(decl)) {
    if (fd->BuiltinID() != 0u) {
      return true;
    }
  }

  if (decl.Token()) {
    return false;
  }

  if (!decl.IsImplicit()) {
    return false;
  }

  auto dc = decl.DeclarationContext();
  if (!dc) {
    assert(false);
    return false;
  }

  if (auto dc_decl = pasta::Decl::From(dc.value())) {
    if (dc_decl->Kind() == pasta::DeclKind::kTranslationUnit) {
      return true;
    }

    // Things like `std::align_val_t`, as well as an implicit `std` namespace,
    // are injected into the TU if one declares an overloaded `operator new`.
    if (dc_decl->IsImplicit() && decl.IsInStdNamespace()) {
      return true;
    }

    assert(!dc_decl->IsImplicit());
    return false;
  }

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
  //
  // Likely/common builtin typedef names:
  //    __builtin_ms_va_list
  //    __builtin_va_list
  //    __va_list
  //    __int128_t
  //    __uint128_t
  //    __NSConstantString
  if (auto td = pasta::TypedefDecl::From(decl)) {
    return td->Name().starts_with("__");

  // E.g. `__NSConstantString_tag`, `__va_list_tag`.
  } else if (auto rd = pasta::RecordDecl::From(decl)) {
    std::string name = rd->Name();
    return name.starts_with("__") && name.ends_with("_tag");
  }

  return false;
}

// Should we even expect to find this declaration in the token contexts? There
// are cases where we shouldn't, e.g. with template instantiations, because the
// token contexts will just end up being associated with the templates
// themselves.
static bool ShouldFindDeclInTokenContexts(const pasta::Decl &decl) {
  auto tsk = pasta::TemplateSpecializationKind::kUndeclared;
  bool has_partial_or_tpl_or_dg = true;

  if (auto csd = pasta::ClassTemplateSpecializationDecl::From(decl)) {
    tsk = csd->TemplateSpecializationKind();
    has_partial_or_tpl_or_dg = !csd->SpecializedTemplateOrPartial().index();

  } else if (auto vsd = pasta::VarTemplateSpecializationDecl::From(decl)) {
    tsk = vsd->TemplateSpecializationKind();
    has_partial_or_tpl_or_dg = !vsd->SpecializedTemplateOrPartial().index();

  } else if (auto ftd = pasta::FunctionTemplateDecl::From(decl)) {
    auto td = ftd->TemplatedDeclaration();
    tsk = td.TemplateSpecializationKind();
    has_partial_or_tpl_or_dg = !(td.Kind() == pasta::DeclKind::kCXXDeductionGuide);

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

  if ((tsk == pasta::TemplateSpecializationKind::kExplicitSpecialization) ||
      (tsk == pasta::TemplateSpecializationKind::kExplicitInstantiationDeclaration) ||
      (tsk == pasta::TemplateSpecializationKind::kExplicitInstantiationDefinition)) {
    return true;

  // NOTE(pag): Have observed situations where `ClassTemplateSpecialization`
  //            will report `kUndeclared`.
  } else if (tsk == pasta::TemplateSpecializationKind::kUndeclared) {
    return has_partial_or_tpl_or_dg;

  } else {
    return false;
  }
}

// Clang's ASTContext code adds builtins, but they don't behave like user-
// written code, in that Clang doesn't always add the nested decls into
// the `DeclContext`.
static void AddBuiltinDeclRangeToEntityListFor(
    std::string_view main_file_path, pasta::Decl decl,
    std::vector<EntityRange> &entity_ranges) {

  LOG_IF(ERROR, !IsProbablyABuiltinDecl(decl))
      << "Could not find location of " << decl.KindName()
      << " declaration: " << DeclToString(decl)
      << PrefixedLocation(decl, " at or near ")
      << " on main job file " << main_file_path;

  entity_ranges.emplace_back(std::move(decl), 0u, 0u);
}

// Figure out the inclusive token index bounds of `decl` and add it to
// `entity_ranges`.
static void AddDeclRangeToEntityListFor(
    const pasta::TokenRange &tokens,
    const std::map<uint64_t, uint64_t> &eof_to_include,
    const std::map<uint64_t, uint64_t> &eof_indices,
    const std::map<uint64_t, pasta::Macro> &dir_index_to_next_dir,
    std::string_view main_file_path, pasta::Decl decl,
    std::vector<EntityRange> &entity_ranges) {

  pasta::Token tok = decl.Token();

  // These are probably part of the preamble of compiler-provided builtin
  // declarations.
  if (!tok) {
    AddBuiltinDeclRangeToEntityListFor(main_file_path, std::move(decl),
                                    entity_ranges);
    return;
  }

  // This suggests an error in PASTA, usually related to token alignment
  // against printed tokens. That process tries to "align" pretty-printed
  // decl tokens, which are full of contextual information, with parsed
  // tokens, which have no contextual information. We do this so that we
  // can get the contextual information from parsed tokens, which is often
  // more useful.
  LOG_IF(FATAL, ShouldFindDeclInTokenContexts(decl) &&
                decl.Kind() != pasta::DeclKind::kBlock &&
                !TokenIsInContextOfDecl(tok, decl) &&
                !IsProbablyABuiltinDecl(decl))
      << "Could not find location of " << decl.KindName()
      << " declaration: " << DeclToString(decl)
      << PrefixedLocation(decl, " at or near ")
      << " on main job file " << main_file_path;

  auto [begin_index, end_index] = FindDeclRange(
      tokens, dir_index_to_next_dir, decl, tok, main_file_path);

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
  if (begin_index == end_index && decl.Kind() != pasta::DeclKind::kEmpty) {

    // Clang is able to convert some uses of library functions into uses of
    // builtin functions. This also happens at the usage site of builtin
    // functions themselves.
    if (IsProbablyABuiltinDecl(decl)) {
      AddBuiltinDeclRangeToEntityListFor(main_file_path, std::move(decl),
                                      entity_ranges);
      return;

    } else {
      // If the decl is implicit the token range will be empty causing
      // both `begin_index` and `end_index` to be same and equal to the
      // token index.
      LOG_IF(ERROR, !(decl.IsImplicit() && tok.Index() == begin_index))
          << "Only found one token " << tok.Data() << " for: "
          << DeclToString(decl) << PrefixedLocation(decl, " at or near ")
          << " on main job file " << main_file_path;
    }
  }

  entity_ranges.emplace_back(std::move(decl), begin_index, end_index);
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

    // Include all `#include`s, `#pragma`s, `#if`s, etc.
    if (auto dir = pasta::MacroDirective::From(mn);
        dir && dir->Kind() != pasta::MacroKind::kDefineDirective) {
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
    } else {
      for (pasta::MacroDirective md : FindDirectivesInMacro(mn)) {
        tlms.emplace_back(md, order++);

        auto dmd = pasta::DefineMacroDirective::From(md);
        if (!dmd) {
          continue;
        }

        // If this macro definition doesn't have a name, then it's in a
        // conditionally disabled region.
        std::optional<pasta::MacroToken> name = dmd->Name();
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

        defs.push_back(std::move(dmd.value()));
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

  std::stable_sort(tlms.begin(), tlms.end(), less);
  auto it = std::unique(tlms.begin(), tlms.end(), eq);
  tlms.erase(it, tlms.end());

  // NOTE(pag): It is extremely important to retain the original ordering. You
  //            can't rely on `sort` (a quicksort) to behave like a stable sort,
  //            nor can you rely on ASTs of different translation units putting
  //            side-by-side declarations one-after-another in memory, thus
  //            getting the same sort order. This is why we keep the extra info
  //            in the `pair` of the original sort order.
  std::stable_sort(tlms.begin(), tlms.end(), orig_less);

  return tlms;
}

// Add a macro to our entity range list. The first token in a macro is usually
// the first usage token, and the last one is the last expansion token.
static void AddMacroRangeToEntityListFor(
    const pasta::TokenRange &tok_range,
    std::string_view main_file_path, pasta::Macro node,
    std::vector<EntityRange> &entity_ranges) {

  // NOTE(pag): It's possible we're dealing with a `define` inside of a
  //            macro expansion.
  pasta::Macro root_node = RootMacroFrom(node);

  std::optional<pasta::MacroToken> bt = root_node.BeginToken();
  std::optional<pasta::MacroToken> et = root_node.EndToken();

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
    AddMacroRangeToEntityListFor(tokens, main_file_path,
                                 std::move(ordered_entry.first), entity_ranges);
  }

  auto dir_index_to_next_dir = FindNextPrevConditionalMacros(
      ast, main_file_path);

  for (OrderedDecl ordered_entry : FindTLDs(ast)) {
    AddDeclRangeToEntityListFor(tokens, eof_index_to_include, bof_to_eof,
                                dir_index_to_next_dir, main_file_path, 
                                std::move(ordered_entry.first),
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

// Count the number of parsed tokens in some macro range.
static unsigned NumParsedTokens(const pasta::Macro &macro,
                                const pasta::TokenRange &tokens) {
  std::optional<pasta::MacroToken> bt = macro.BeginToken();
  if (!bt) {
    return 0u;
  }

  std::optional<pasta::MacroToken> et = macro.EndToken();
  if (!et) {
    return 0u;
  }

  uint64_t bi = bt->ParsedLocation().Index();
  uint64_t ei = et->ParsedLocation().Index();
  unsigned count = 0u;
  for (uint64_t i = bi; i < ei; ++i) {
    if (IsParsedToken(tokens[i])) {
      ++count;
    }
  }

  return count;
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

  pasta::TokenRange tokens = ast.Tokens();
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
    Entity prev_entity;
    uint64_t prev_end_index = end_index;

    for (; i < max_i; ++i) {

      const EntityRange &next_entity_range = entity_ranges[i];
      const Entity &next_entity = std::get<kEntityIndex>(next_entity_range);
      uint64_t next_begin = std::get<kBeginIndex>(next_entity_range);
      uint64_t next_end = std::get<kEndIndex>(next_entity_range);

      // We have to deal with one corner case, observed in cURL:
      //
      //    CURL_EXTERN CURLcode curl_easy_pause(...);
      //
      // Here, depending on the configuration, the macro `CURL_EXTERN` either
      // expands to a `__declspec` or attribute, and is thus part of the
      // function declaration, or it expands to nothing, and so looks disjoint
      // from the function declaration. We want to make it logically part of
      // the declaration, fusing the two.
      //
      // XREF: Issue 412 (https://github.com/trailofbits/multiplier/issues/412).
      if (std::holds_alternative<pasta::Macro>(prev_entity) &&
          std::holds_alternative<pasta::Decl>(next_entity) &&
          (prev_end_index + 1u) == next_begin &&
          tokens[prev_end_index].MacroLocation() &&
          tokens[prev_end_index].Kind() != pasta::TokenKind::kSemi &&
          (std::get<pasta::Macro>(prev_entity).Kind() ==
              pasta::MacroKind::kExpansion) &&
          !NumParsedTokens(std::get<pasta::Macro>(prev_entity), tokens)) {

      // Doesn't close over.
      } else if (next_begin > end_index) {
        break;
      }

      if (std::holds_alternative<pasta::Decl>(next_entity)) {
        CHECK_EQ(StatementsHaveErrors(std::get<pasta::Decl>(next_entity)), 0u);
      }

      // Make sure we definitely enclose over the next decl.
      begin_index = std::min(begin_index, next_begin);
      end_index = std::max(end_index, next_end);
      entities_for_group.push_back(next_entity);

      prev_entity = next_entity;
      prev_end_index = next_end;
    }

    CHECK(!entities_for_group.empty());
    entity_group_ranges.emplace_back(
        std::move(entities_for_group), begin_index, end_index);
  }

  return entity_group_ranges;
}

static void FindTokenFileBounds(const pasta::FileToken &tok,
                                std::optional<pasta::FileToken> &begin_tok,
                                std::optional<pasta::FileToken> &end_tok) {

  // NOTE(pag): `tests/Macros/WhitespaceAfterPragma.c` revealed that whitespace
  //            would sometimes be included as the beginning or ending token of
  //            a macro. Here we try to account for that by excluding them.
  auto bt = tok;
  auto et = tok;
  if (TokenKindFromPasta(tok) == mx::TokenKind::WHITESPACE) {
    auto file_tokens = pasta::File::Containing(tok).Tokens();
    auto index = static_cast<unsigned>(tok.Index());
    if ((index + 1u) < file_tokens.Size()) {
      bt = file_tokens[index + 1u];
    }
    if (index) {
      et = file_tokens[index - 1u];
    }
  }

  // Try to widen the bounds.
  if (!begin_tok ||
      (begin_tok->RawFile() == bt.RawFile() &&
       begin_tok->Index() > bt.Index())) {
    begin_tok = bt;
  }

  if (!end_tok ||
      (end_tok->RawFile() == et.RawFile() &&
       end_tok->Index() < et.Index())) {
    end_tok = et;
  }
}

static void FindMacroFileBounds(const pasta::Macro &macro,
                                std::optional<pasta::FileToken> &begin_tok,
                                std::optional<pasta::FileToken> &end_tok) {

  if (std::optional<pasta::MacroToken> mtok = pasta::MacroToken::From(macro)) {
    if (std::optional<pasta::FileToken> ftok = mtok->FileLocation()) {
      FindTokenFileBounds(*ftok, begin_tok, end_tok);
    }
  } else {
    for (pasta::Macro child : macro.Children()) {
      FindMacroFileBounds(child, begin_tok, end_tok);
    }
  }
}

static bool FindTokenFileBounds(const pasta::Token &ptok,
                                std::optional<pasta::FileToken> &begin_tok,
                                std::optional<pasta::FileToken> &end_tok) {
  switch (ptok.Role()) {
    default:
      break;
    case pasta::TokenRole::kFileToken:
      if (std::optional<pasta::FileToken> ftok = ptok.FileLocation()) {
        FindTokenFileBounds(*ftok, begin_tok, end_tok);
        return true;
      }
      break;
    case pasta::TokenRole::kFinalMacroExpansionToken:
      if (std::optional<pasta::MacroToken> mtok = ptok.MacroLocation()) {
        FindMacroFileBounds(RootMacroFrom(*mtok), begin_tok, end_tok);
        return true;
      }
      break;
  }
  return false;
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
    const EntityIdMap &entity_ids, const EntityGroup &entities,
    const pasta::TokenRange &tokens) {

  std::optional<pasta::FileToken> begin_tok;
  std::optional<pasta::FileToken> end_tok;

  auto range_size = tokens.size();

  // Find a good begin index candidate.
  for (pasta::Token tok : tokens) {
    if (FindTokenFileBounds(tok, begin_tok, end_tok)) {
      break;
    }
  }

  // Find a good end index candidate.
  //
  // NOTE(pag): `end_index` is inclusive.
  for (auto i = 1u; i <= range_size; ++i) {
    if (FindTokenFileBounds(tokens[range_size - i], begin_tok, end_tok)) {
      break;
    }
  }

  // We might have only directives with no parsed tokens in the expansion, so
  // we need to go looking more.
  for (const Entity &entity : entities) {
    if (std::holds_alternative<pasta::Macro>(entity)) {
      FindMacroFileBounds(std::get<pasta::Macro>(entity), begin_tok, end_tok);
    }
  }

  if (!begin_tok || !end_tok) {
    return std::nullopt;
  }

  auto id_it = entity_ids.find(begin_tok->RawFile());
  if (id_it == entity_ids.end()) {
    return std::nullopt;
  }
  
  mx::VariantId vid = mx::EntityId(id_it->second).Unpack();
  if (!std::holds_alternative<mx::FileId>(vid)) {
    return std::nullopt;
  }

  mx::FileId fid = std::get<mx::FileId>(vid);

  mx::FileTokenId btid;
  btid.file_id = fid.file_id;
  btid.kind = TokenKindFromPasta(begin_tok.value());
  btid.offset = static_cast<mx::EntityOffset>(begin_tok->Index());

  mx::FileTokenId etid;
  etid.file_id = fid.file_id;
  etid.kind = TokenKindFromPasta(end_tok.value());
  etid.offset = static_cast<mx::EntityOffset>(end_tok->Index());

  return FileLocationOfFragment(fid, btid, etid);
}

static PendingFragmentPtr CreatePendingFragment(
    IdStore &id_store, EntityMapper &em,
    const pasta::TokenRange *original_tokens,
    pasta::PrintedTokenRange parsed_tokens,
    std::optional<FileLocationOfFragment> floc,
    mx::PackedCompilationId tu_id,
    uint64_t begin_index,
    uint64_t end_index,
    std::vector<pasta::Decl> decls,
    std::vector<pasta::Macro> macros,
    const std::optional<mx::PackedFragmentId> &root_fragment_id) {

  // The number of tokens is used to estimate the "size" of this fragment.
  // Mostly, it's a proxy of the complexity of the macro expansions as well.
  // The size of the fragment affects which encoding format we use: the "big"
  // fragment ID encoding scheme (i.e. has lots of stuff, but we can't encode
  // as many of them), or the small one (i.e. doesn't have as much stuff, and
  // we can encode substantially more of them).
  size_t num_tokens = 0u;
  if (original_tokens && *original_tokens) {
    num_tokens = original_tokens->Size();

  } else {
    num_tokens = parsed_tokens.Size();
  }

  // Compute the fragment ID, and in doing so, figure out if this is actually
  // a new fragment.
  auto [fid, is_new_fragment_id] = id_store.GetOrCreateFragmentIdForHash(
      (floc ? floc->first_file_token_id.Pack() : mx::kInvalidEntityId),
      HashFragment(decls, macros, original_tokens, parsed_tokens),
      num_tokens  /* for fragment id packing format */);

  PendingFragmentPtr pf(new PendingFragment(
      fid,
      is_new_fragment_id  /* is_new */,
      tu_id,
      begin_index,
      end_index,
      em,
      original_tokens,
      std::move(parsed_tokens),
      std::move(floc)  /* file_location */));

  pf->num_top_level_declarations = static_cast<unsigned>(decls.size());
  pf->num_top_level_macros = static_cast<unsigned>(macros.size());

  if (root_fragment_id.has_value()) {
    CHECK_NE(pf->fragment_id.Pack(), root_fragment_id.value().Pack());
    pf->parent_fragment_ids.push_back(root_fragment_id.value());
  }

  // Steal the TLDs and TLMs. If we have child fragments, then we want the
  // root fragment to own the macros.
  pf->top_level_decls = std::move(decls);
  pf->top_level_macros = std::move(macros);

  return pf;
}

// Create a printed token range for a sequence of declarations, and make it
// represent the parsed tokens.
static pasta::PrintedTokenRange CreateParsedTokenRange(
    pasta::PrintedTokenRange parsed_tokens,
    const std::vector<pasta::Decl> &root_decls,
    const std::vector<pasta::Decl> &child_decls,
    const pasta::PrintingPolicy &pp) {

  if (root_decls.empty()) {
    if (child_decls.empty()) {
      return parsed_tokens;
    } else {
      return CreateParsedTokenRange(std::move(parsed_tokens), child_decls,
                                    root_decls, pp);
    }
  }

  CHECK(!root_decls.empty());

  // We don't want to concatenate the printed output of declarations that are
  // embedded in the declarators of other declarations, because we'll capture
  // those decls when printing those declarators.
  std::vector<pasta::Decl> decls_to_print;
  for (const pasta::Decl &decl : root_decls) {
    if (std::optional<pasta::TagDecl> td = pasta::TagDecl::From(decl)) {
      if (!td->IsEmbeddedInDeclarator()) {
        decls_to_print.emplace_back(decl);
      }
    } else {
      decls_to_print.emplace_back(decl);
    }
  }

  // We've hoisted the decls embedded in declarators out into their own
  // independent fragments.
  if (decls_to_print.empty()) {
    CHECK_EQ(root_decls.size(), 1u);
    decls_to_print = root_decls;
  }

  // Print the root declarations one after the other, and then try to apply the
  // alignment algorithm.
  pasta::PrintedTokenRange printed_tokens =
      pasta::PrintedTokenRange::Create(decls_to_print.front());
  for (auto i = 1u; i < decls_to_print.size(); ++i) {
    auto concat = pasta::PrintedTokenRange::Concatenate(
        printed_tokens,
        pasta::PrintedTokenRange::Create(decls_to_print[i]));
    CHECK(concat.has_value());
    printed_tokens = std::move(concat.value());
  }

  // If the alignment algorithm succeeds, then we will have token contexts
  // for each of the parsed tokens.
  auto err = pasta::PrintedTokenRange::Align(parsed_tokens, printed_tokens);

  // It's not fatal if we can't match them here, because this is really a
  // kind of implicit fragment anyway.
  LOG_IF(ERROR, err.has_value())
      << "Unable to align tokens: " << err.value();

  return parsed_tokens;
}

// NOTE(pag): Left here for niftiness of debugging issues, e.g. where some
//            top-level decl doesn't have all of its tokens properly
//            identified. Usually this would be a bug in PASTA's
//            `lib/AST/Bounds.cpp` file, but having a restriction here also
//            helps the end-to-end debugging process.
//
// NOTE(pag): Likely, an `assert(false)` in `TrackRedeclarations` in
//            `LinkEntitiesAcrossFragments.cpp` needs to be commented out
//            when using this debugging technique.
static bool DebugIndexOnlyThisFragment(const EntityGroup &entities) {
  // bool found = false;
  // for (const Entity &entity : entities) {
  //   if (!std::holds_alternative<pasta::Decl>(entity)) {
  //     continue;
  //   }

  //   auto nd = pasta::FunctionDecl::From(std::get<pasta::Decl>(entity));
  //   if (!nd) {
  //     continue;
  //   }

  //   if (nd->Name() == "function name here") {
  //     found = true;
  //     break;
  //   }
  // }

  // return found;
  (void) entities;
  return true;
}

// Create a freestanding fragment. This is generally for builtin types, e.g.
// `__builtin_va_list`, or for forward declarations that are embedded within
// the declarators of other declarations. We need to specially handle these
// forward declarations to prevent Issue #396.
//
// XREF(pag): https://github.com/trailofbits/multiplier/issues/396
static void CreateFreestandingDeclFragment(
    IdStore &id_store,
    EntityMapper &em,
    std::optional<FileLocationOfFragment> floc,
    mx::PackedCompilationId tu_id,
    uint64_t begin_index,
    uint64_t end_index,
    const pasta::Decl &decl,
    std::vector<PendingFragmentPtr> &pending_fragments,
    std::string_view main_file_path) {

  // NOTE(pag): For builtin declaration, this will be empty.
  const pasta::PrintingPolicy pp;

  pasta::PrintedTokenRange parsed_tokens =
      pasta::PrintedTokenRange::Adopt(decl.Tokens());

  pasta::PrintedTokenRange printed_tokens =
      pasta::PrintedTokenRange::Create(decl, pp);

  // If this is a builtin declaration, then we want the fragment hash to be
  // generic across the whole program, not specific to this file. For example,
  // we don't want *every* use of `__builtin_bswap32` to show up as a distinct
  // re-declaration.
  auto is_builtin = IsProbablyABuiltinDecl(decl);
  if (is_builtin) {
    floc.reset();
  }

  // Align against the parsed tokens, if we can.
  //
  // NOTE(pag): Alignment mutates both `parsed_tokens` and `printed_tokens`
  //            in place, making `printed_tokens` have source locations from
  //            `parsed_tokens`, and `parsed_tokens` have contexts from
  //            `printed_tokens`.
  if (parsed_tokens) {
    (void) pasta::PrintedTokenRange::Align(parsed_tokens, printed_tokens);

  } else {

    // If the decl is implicit, the parsed_tokens can be empty and it will
    // fallback to the error path. Example: CXXDeductionGuide in some cases
    // will not have parsed token and it will fallback here.
    LOG_IF(ERROR, !(is_builtin || decl.IsImplicit()))
        << "Could not find tokens of " << decl.KindName()
        << " declaration: " << DeclToString(decl)
        << PrefixedLocation(decl, " at or near ")
        << " on main job file " << main_file_path;
  }

  std::vector<pasta::Decl> decls;
  decls.push_back(decl);

  // NOTE(pag): We pass `nullptr` as the parsed tokens, because we can't
  //            guarantee that the parsed tokens aren't the result of
  //            macro expansions.
  auto pf = CreatePendingFragment(
      id_store,
      em,
      nullptr  /* original_tokens */,
      std::move(printed_tokens)  /* parsed_tokens */,
      std::move(floc),
      tu_id,
      begin_index,
      end_index,
      std::move(decls),
      {}  /* empty macros */,
      std::nullopt  /* root_fragment_id */);

  // We move `floc` into `CreatePendingFragment` so that it affects our
  // hashing/deduplicating, but beyond that, we don't want to associate this
  // freestanding declaration with this file location, so if it's set, we clear
  // it.
  pf->file_location.reset();

  // `printed_toks` above may contain derived locations that the decls
  // themselves will reference, and so we need to make sure that we'll
  // be able to find those tokens when serializing those decls. However,
  // when persisting the fragment and building the token tree, we don't
  // want to retain the connections back to the parsed tokens as they
  // may be related to macros.
  //
  // NOTE(pag): This is a bit ugly, because we're "scheduling" to drop
  //            provenance later after labelling. The crux of the issue
  //            is that labelling is per-fragment, and if we did it now,
  //            then that info would be dropped when we reset the
  //            `EntityMapper` for the fragment.
  pf->drop_token_provenance = true;

  LabelDeclsInFragment(*pf);

  if (pf->is_new) {
    pending_fragments.emplace_back(std::move(pf));
  }
}

// Create a floating fragment for the top-level directives.
static void CreateFloatingDirectiveFragment(
    IdStore &id_store,
    EntityMapper &em,
    mx::PackedCompilationId tu_id,
    const pasta::Macro &macro,
    std::vector<PendingFragmentPtr> &pending_fragments) {

  pasta::TokenRange directive_range = BaselineEntityRange(macro);
  CHECK(!directive_range.empty());

  // TODO(pag): Eventually allow floating macro define directives from
  //            compilation commands.
  EntityGroup entities;
  entities.emplace_back(macro);
  auto floc = FindFileLocationOfFragment(
      em.entity_ids, entities, directive_range);

  pasta::PrintedTokenRange parsed_tokens_in_directive_range =
      pasta::PrintedTokenRange::Adopt(directive_range);
  CHECK(parsed_tokens_in_directive_range.empty());

  std::vector<pasta::Macro> macros;
  macros.push_back(macro);

  auto pf = CreatePendingFragment(
      id_store,
      em,
      &directive_range  /* original_tokens */,
      std::move(parsed_tokens_in_directive_range)  /* parsed_tokens */,
      std::move(floc),
      tu_id,
      directive_range.Front()->Index(),
      directive_range.Back()->Index(),
      {}  /* empty decls */,
      std::move(macros),
      std::nullopt  /* root_fragment_id */);

  // NOTE(pag): This will not persist token ids, because there are no tokens
  //            in `parsed_tokens_in_directive_range`, but it will persist
  //            some macros globally. When the `EntityMapper` is reset for
  //            a fragment prior to persisting, those macros ids will persist.
  LabelTokensAndMacrosInFragment(*pf);

  if (pf->is_new) {
    pending_fragments.emplace_back(std::move(pf));
  }
}

static void CreatePendingFragments(
    IdStore &id_store, EntityMapper &em,
    const pasta::TokenRange &tok_range, mx::PackedCompilationId tu_id,
    EntityGroupRange group_range, std::string_view main_file_path,
    std::vector<PendingFragmentPtr> &pending_fragments) {

  const EntityGroup &entities = std::get<kGroupIndex>(group_range);
  if (!DebugIndexOnlyThisFragment(entities)) {
    return;
  }

  uint64_t begin_index = std::get<kBeginIndex>(group_range);
  uint64_t end_index = std::get<kEndIndex>(group_range);

  std::optional<pasta::TokenRange> sub_tok_range = pasta::TokenRange::From(
      tok_range[begin_index], tok_range[end_index]);

  if (!sub_tok_range) {
    LOG(FATAL)
        << "Invalid parsed token range for pending fragment";
    return;
  }

  // Directives, especially `#define` directives, are treated as floating
  // root fragments, as they are kind of "free standing" w.r.t. expansion, and
  // define directives in particular can be referenced from other locations,
  // and so we need special handling of their tokens/entities w.r.t. the
  // entity mapper. We process these first, as they can end up being used
  // lexically inside of other top-level entities.
  for (const Entity &entity : entities) {
    if (std::holds_alternative<pasta::Macro>(entity)) {
      const pasta::Macro &macro = std::get<pasta::Macro>(entity);
      if (ShouldGoInFloatingFragment(macro)) {
        CreateFloatingDirectiveFragment(
            id_store, em, tu_id, macro, pending_fragments);
      }
    }
  }

  const pasta::TokenRange &frag_tok_range = sub_tok_range.value();

  // Locate where this fragment is in its file.
  std::optional<FileLocationOfFragment> floc = FindFileLocationOfFragment(
      em.entity_ids, entities, frag_tok_range);

  std::vector<pasta::Decl> root_decls;
  std::vector<std::vector<pasta::Decl>> nested_decls;
  std::vector<pasta::Macro> top_level_macros;

  std::vector<pasta::Decl> forward_decls;
  std::optional<mx::PackedFragmentId> root_fragment_id;

  // Partition the top-level declarations so that ones that definitely won't
  // need to go in a nested fragment show up first. This acts as a minor
  // mitigation to #396 (https://github.com/trailofbits/multiplier/issues/396).
  for (const Entity &entity : entities) {
    if (std::holds_alternative<pasta::Decl>(entity)) {
      const pasta::Decl &decl = std::get<pasta::Decl>(entity);

      // Things like C++ templates (but not their full specializations) are
      // hidden from the indexer. Nonetheless, we do want to inherit the bounds
      // from the templates themselves, and use those bounds for overlap/nesting
      // calculation, hence why we don't omit them earlier in the process.
      if (ShouldHideFromIndexer(decl)) {
        continue;

      // E.g. if there's something like: `typedef struct page *pgtable_t;`,
      // and if there is no prior declaration of `struct page`, then the
      // `struct page` declaration will show up on the same level as the
      // `typedef`.
      } else if (IsInjectedForwardDeclaration(decl) ||
                 ShouldGoInFloatingFragment(decl) ||
                 !floc || decl.IsImplicit()) {

        CreateFreestandingDeclFragment(
            id_store, em, floc, tu_id, begin_index, end_index,
            decl, pending_fragments, main_file_path);

      // These are generally template instantiations.
      } else if (ShouldGoInNestedFragment(decl)) {
        nested_decls.emplace_back().push_back(decl);

      // E.g. `int a, b;` will produce two `VarDecl`s that we want to merge into
      // a single root decl.
      } else {
        root_decls.push_back(decl);
      }

    // Find our top-level macro uses.
    } else if (std::holds_alternative<pasta::Macro>(entity)) {
      const pasta::Macro &macro = std::get<pasta::Macro>(entity);
      if (!ShouldGoInFloatingFragment(macro)) {
        top_level_macros.emplace_back(macro);
      }

    } else {
      LOG(ERROR)
          << "TODO: Unsupported top-level entity kind";
      return;
    }
  }

  pasta::PrintingPolicy pp;

  // Create the root fragment. We do this if we have any top-level declarations,
  // or any top-level non-directive macro uses.
  if (!root_decls.empty() || !top_level_macros.empty()) {

    pasta::PrintedTokenRange aligned_tokens =
        CreateParsedTokenRange(
            pasta::PrintedTokenRange::Adopt(frag_tok_range),
            root_decls, {}  /* empty decls */, pp);

    CHECK(!aligned_tokens.empty() || !top_level_macros.empty());

    auto pf = CreatePendingFragment(
        id_store,
        em,
        &frag_tok_range  /* original_tokens */,
        std::move(aligned_tokens)  /* parsed_tokens */,
        floc  /* copied */,
        tu_id,
        begin_index,
        end_index,
        std::move(root_decls),
        top_level_macros  /* copied */,
        root_fragment_id);

    root_fragment_id = pf->fragment_id;

    LabelDeclsInFragment(*pf);

    if (pf->is_new) {
      pending_fragments.emplace_back(std::move(pf));
    }
  }

  // Create the nested fragments for the root fragment. These correspond to
  // things like template specializations/instantiations.
  for (std::vector<pasta::Decl> &decls : nested_decls) {
    CHECK_EQ(decls.size(), 1ul);
    CHECK(root_fragment_id.has_value());

    pasta::PrintedTokenRange aligned_tokens = CreateParsedTokenRange(
        pasta::PrintedTokenRange::Adopt(frag_tok_range), root_decls, decls, pp);

    CHECK(!aligned_tokens.empty());

    auto pf = CreatePendingFragment(
        id_store,
        em,
        &frag_tok_range  /* original_tokens */,
        std::move(aligned_tokens)  /* parsed_tokens */,
        floc  /* copied */,
        tu_id,
        begin_index,
        end_index,
        std::move(decls),
        top_level_macros  /* copied */,
        root_fragment_id);

    LabelDeclsInFragment(*pf);

    if (pf->is_new) {
      pending_fragments.emplace_back(std::move(pf));
    }
  }
}

// Create fragments in the *same* order that we see them in the AST. On the one
// hand, a reverse order may defer contention across indexing threads early on
// in indexing, however, the downside of doing things in a different order than
// things appear in the AST is that we may see tokens/expressions (e.g.
// associated with constant expressions in constant-sized array types) end up
// belonging to the "wrong" fragments, because those fragments end up finding
// those expressions/tokens (e.g. through type desugaring methods). The best
// way to avoid things being placed in the wrong fragments ends up being to
// process the fragments in order. A downside of this overall effect is that
// it precludes sub-translation unit-granularity indexing (e.g. by having
// other indexer threads do work stealing on the pending fragments).
static std::vector<PendingFragmentPtr> CreatePendingFragments(
    GlobalIndexingState &context, EntityMapper &em, const pasta::AST &ast,
    mx::PackedCompilationId tu_id,
    std::vector<EntityGroupRange> decl_group_ranges) {

  std::vector<PendingFragmentPtr> pending_fragments;
  pending_fragments.reserve(decl_group_ranges.size());

  std::string main_job_file = ast.MainFile().Path().generic_string();
  DLOG(INFO)
      << "Main source file " << main_job_file
      << " has " << decl_group_ranges.size() << " possible fragments";

  pasta::TokenRange tok_range = ast.Tokens();

  // Visit decl range groups in their natural order, so that we're more likely
  // to associate tokens/expressions indirectly reachable through types with
  // the fragments logically containing those tokens/expressions.
  for (EntityGroupRange &entities_in_fragment : decl_group_ranges) {
    try {
      CreatePendingFragments(context.id_store, em, tok_range, tu_id,
                             std::move(entities_in_fragment), main_job_file,
                             pending_fragments);
    } catch (...) {
      LOG(ERROR)
          << "Caught exception in main job file " << main_job_file
          << " when trying to create pending fragment";
    }
  }

  return pending_fragments;
}

// Serialize the parsed fragments that were identified as new and/or "won"
// the race to assign a fragment ID in this thread of execution.
static void PersistParsedFragments(
    GlobalIndexingState &context,
    const pasta::Compiler &compiler,
    const pasta::CompileJob &job,
    const pasta::AST &ast, EntityMapper &em,
    mx::PackedCompilationId tu_id,
    std::vector<PendingFragmentPtr> pending_fragments) {

  NameMangler mangler(ast, tu_id);
  TokenProvenanceCalculator provenance(em);

  std::string main_source_file = ast.MainFile().Path().generic_string();
  DLOG(INFO)
      << "Main source file " << main_source_file
      << " has " << pending_fragments.size() << " unique fragments";

  std::vector<mx::PackedFragmentId> fragment_ids;
  fragment_ids.reserve(pending_fragments.size());

  for (PendingFragmentPtr &pf : pending_fragments) {
    auto start_time = std::chrono::system_clock::now();
    try {
      em.ResetForFragment();
      context.PersistFragment(ast, mangler, em, provenance, *pf);
      context.PersistTypes(ast, mangler, em, *pf);
      fragment_ids.push_back(pf->fragment_id);

    } catch (...) {
      pf->has_error = true;

      if (!pf->top_level_decls.empty()) {
        const pasta::Decl &leader_decl = pf->top_level_decls.front();
        LOG(ERROR)
            << "Persisting fragment"
            << PrefixedLocation(leader_decl, " at or near ")
            << " on main job file " << main_source_file
            << " triggered exception";
      } else {
        LOG(ERROR)
            << "Persisting fragment on main job file " << main_source_file
            << " triggered exception";
      }
      continue;
    }

    // Warn if it takes really long to persist a fragment.
    //
    // NOTE(pag): It could take very long if we block on a queue.
    auto end_time = std::chrono::system_clock::now();
    auto elapsed_time_s = std::chrono::duration_cast<std::chrono::seconds>(
        end_time - start_time).count();
    if (elapsed_time_s >= 30 && !pf->top_level_decls.empty()) {
      const pasta::Decl &leader_decl = pf->top_level_decls.front();
      LOG(WARNING)
          << "Fragment" << PrefixedLocation(leader_decl, " at or near ")
          << " on main job file " << main_source_file
          << " took " << static_cast<uint64_t>(elapsed_time_s)
          << " seconds to persist";
    }
  }

  context.PersistCompilation(compiler, job, ast, em, tu_id,
                             std::move(fragment_ids));
}

// Look through all files referenced by the AST get their unique IDs. If this
// is the first time seeing a file, then tokenize the file.
static void MaybePersistParsedFile(
    GlobalIndexingState &context, const pasta::File &file, EntityMapper &em) {

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

  auto [file_id, is_new_file_id] = context.id_store.GetOrCreateFileIdForHash(
      HashFile(maybe_data.TakeValue()));

  if (is_new_file_id) {
    context.PersistFile(file_id, file);
  }

  em.entity_ids.emplace(file.RawFile(), file_id.Pack());
}

// This persists any not-yet-seen files and their tokens. It also creates the
// file IDs for those files, so this always must happen.
static void PersistParsedFiles(
    GlobalIndexingState &context, const pasta::AST &ast, EntityMapper &em) {
  auto parsed_files = ast.ParsedFiles();
  for (auto it = parsed_files.rbegin(), end = parsed_files.rend();
       it != end; ++it) {
    const pasta::File &parsed_file = *it;
    MaybePersistParsedFile(context, parsed_file, em);
  }
}

// Create an AST from a compile job.
static std::optional<pasta::AST> CompileJobToAST(
    const GlobalIndexingState &context,
    const pasta::CompileJob &job) {

  DLOG(INFO)
      << "Running compile job: " << job.Arguments().Join();

  ProgressBarWork parsing_progress_tracker(context.ast_progress);
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
    GlobalIndexingState &context_,
    pasta::FileManager file_manager_,
    pasta::Compiler compiler_, pasta::CompileJob job_)
    : context(context_),
      file_manager(std::move(file_manager_)),
      compiler(std::move(compiler_)),
      job(std::move(job_)) {}

// Build and index the AST.
void IndexCompileJobAction::Run(void) {

  std::optional<pasta::AST> maybe_ast = CompileJobToAST(context, job);
  if (!maybe_ast) {
    return;
  }

  TypeMapper tm(context.id_store);
  EntityMapper em(tm, context.codegen.IsEnabled());

  pasta::AST ast = std::move(maybe_ast.value());
  pasta::File main_file = ast.MainFile();
  std::string main_file_path = main_file.Path().generic_string();
  DLOG(INFO)
      << "Built AST for main source file " << main_file_path;

  PersistParsedFiles(context, ast, em);

  // Detect if this is a new compilation.
  auto [tu_id, is_new_tu_id] = context.id_store.GetOrCreateCompilationId(
      em.EntityId(main_file), HashCompilation(ast, em));

  if (!is_new_tu_id) {
    DLOG(INFO)
        << "Skipping redundant AST for main source file " << main_file_path;
    return;
  }

  PersistParsedFragments(
      context, compiler, job, ast, em, tu_id,
      CreatePendingFragments(
          context, em, ast, tu_id,
          PartitionEntities(context, ast)));
}

}  // namespace indexer
