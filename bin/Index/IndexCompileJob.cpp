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
#include "LabelEntitiesInFragment.h"
#include "NameMangler.h"
#include "PendingFragment.h"
#include "Provenance.h"
#include "TypeMapper.h"
#include "Util.h"

namespace indexer {
namespace {

using EntityOffsetMap = std::map<mx::EntityOffset, mx::EntityOffset>;
using EntityOffsetToDirectiveMap = std::map<mx::EntityOffset, pasta::MacroDirective>;

struct OrderedDecl {
  pasta::Decl decl;
  const void *parent;
  unsigned order;

  inline OrderedDecl(pasta::Decl decl_, const void *parent_, unsigned order_)
      : decl(std::move(decl_)),
        parent(parent_),
        order(order_) {
    assert(RawEntity(decl) != parent);        
  }
};

struct OrderedMacro {
  pasta::Macro macro;
  unsigned order;

  inline OrderedMacro(pasta::Macro macro_, unsigned order_)
      : macro(std::move(macro_)),
        order(order_) {}
};

// A declaration, the index of the first token to be saved associated with
// the decl, and the (inclusive) index of the last token associated with
// this token.
struct EntityRange {
  Entity entity;

  // `RawEntity(parent_entity)`. This will influence what the parent fragment
  // ID is.
  const void *parent;

  // Inclusive entity bounds.
  mx::EntityOffset begin_index;
  mx::EntityOffset end_index;

  inline EntityRange(Entity entity_, const void *parent_,
                     mx::EntityOffset begin_index_, mx::EntityOffset end_index_)
      : entity(std::move(entity_)),
        parent(parent_),
        begin_index(begin_index_),
        end_index(end_index_) {}
};

// A group of declarations with overlapping `EntityRange`s, along with the
// minimum and maximum (inclusive) indices of the tokens.
using EntityGroup = std::vector<EntityRange>;

struct EntityGroupRange {
  EntityGroup group;

  // Inclusive bounds for all entities in the group.
  mx::EntityOffset begin_index;
  mx::EntityOffset end_index;

  inline EntityGroupRange(EntityGroup group_, mx::EntityOffset begin_index_,
                          mx::EntityOffset end_index_)
      : group(std::move(group_)),
        begin_index(begin_index_),
        end_index(end_index_) {}
};

static bool IsProbablyABuiltinDecl(const pasta::Decl &decl);

// Find all top-level declarations.
class TLDFinder final : public pasta::DeclVisitor {
 private:
  std::vector<OrderedDecl> &tlds;

  EntityMapper &em;

  const void *parent_decl{nullptr};

  // Tracks declarations for which we've seen the specializations. This is
  // to prevent us from double-adding specializations.
  std::unordered_set<const void *> seen;

  // Depth of a decl context.
  std::unordered_map<const void *, unsigned> dc_depth;

  // If it doesn't look like a builtin declaration, then shift the order
  // by a fudge factor. Clang can invent a lot of builtins, though definitely
  // not more than 100,000.
  unsigned builtin_order{0u};
  unsigned order{100000u};

  unsigned depth{0u};

  void AddDeclAlways(const pasta::Decl &decl) {
    em.MarkAsTopLevel(decl);

    if (IsProbablyABuiltinDecl(decl)) {
      tlds.emplace_back(decl, parent_decl, builtin_order++);
    } else {
      tlds.emplace_back(decl, parent_decl, order++);
    }
  }

  // Clang will invent some builtins just-in-time, and "just-in-time" ends up
  // appearing logically after they're needed. E.g. when declaring
  // `operator new`, Clang will invent the `std` namespace, and then invent
  // things like `std::align_val_t` and the global `operator new`. These will
  // appear *after* any uses of these things in the translation unit. So we
  // need to arrange for them to be in the right order.
  void AddDecl(const pasta::Decl &decl) {
    if (seen.emplace(RawEntity(decl)).second) {
      AddDeclAlways(decl);
    }
  }

 public:
  virtual ~TLDFinder(void) = default;

  explicit TLDFinder(std::vector<OrderedDecl> &tlds_, EntityMapper &em_)
      : tlds(tlds_),
        em(em_) {}

  void VisitDeeperDeclContext(const pasta::Decl &dc_decl,
                              const pasta::DeclContext &dc) {
    ++depth;
    VisitDeclContext(dc_decl, dc);    
    --depth;
  }

  void VisitDeclContext(const pasta::Decl &dc_decl,
                        const pasta::DeclContext &dc,
                        bool track_parent = true) {

    // Prevent us from revisiting the same decl context twice. It can be the
    // case that we see a decl context nested inside itself. This is due to
    // injected class names in Clang (`C++ [class]p2`) where a class is injected
    // into itself to help with things like `friend` and argument-dependent
    // lookups. In those cases, we mark that injected class with
    // `Decl::RemappedDecl` back to its parent, and then PASTA follows the
    // `->RemappedDecl` links, thus hiding its uniqueness from us, and making
    // the resulting visit circular.
    if (!dc_depth.emplace(RawEntity(dc), depth).second) {
      return;  // Already visited.
    }

    std::optional<PrevValueTracker<const void *>> save_restore;
    if (track_parent) {
      save_restore.emplace(parent_decl, RawEntity(dc_decl));
    }

    for (const pasta::Decl &decl : dc.AlreadyLoadedDeclarations()) {
      if (!decl.IsInvalidDeclaration() && !ShouldHideFromIndexer(decl)) {
        Accept(decl);
      }
    }
  }

  void VisitTranslationUnitDecl(const pasta::TranslationUnitDecl &decl) final {
    VisitDeclContext(decl, decl, false  /* don't track parentage */);
  }

  void VisitNamespaceDecl(const pasta::NamespaceDecl &decl) final {
    VisitDeclContext(decl, decl, false  /* don't track parentage */);
  }

  void VisitExternCContextDecl(const pasta::ExternCContextDecl &decl) final {
    VisitDeclContext(decl, decl, false  /* don't track parentage */);
  }

  void VisitLinkageSpecDecl(const pasta::LinkageSpecDecl &decl) final {
    VisitDeclContext(decl, decl, false  /* don't track parentage */);
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
    auto raw_decl = RawEntity(decl);
    if (!seen.emplace(raw_decl).second) {
      return;
    }

    AddDeclAlways(decl);
    VisitDeeperDeclContext(decl, decl);
  }

  void VisitClassTemplateSpecializationDecl(
      const pasta::ClassTemplateSpecializationDecl &decl) final {

    if (!seen.emplace(RawEntity(decl)).second) {
      return;
    }

    // Note: If the specialization is explict and is in the redeclaration
    //       table, the canonical decl may not get added as one of the TLD
    //       and any reference of canonical reference will not get resolved

    AddDeclAlways(decl);
    VisitDeeperDeclContext(decl, decl);
  }

  // void VisitVarTemplatePartialSpecializationDecl(
  //     const pasta::VarTemplatePartialSpecializationDecl &) final {
  //   // Do nothing.
  // }

  template <typename T>
  std::optional<T> FindParentRedecl(T &tpl, pasta::Token loc) {
    for (const auto &redecl_ : tpl.Redeclarations()) {
      auto redecl = reinterpret_cast<const T &>(redecl_);
      if (redecl.Token() == loc) {
        return redecl;
      }
    }
    return std::nullopt;
  }

  void VisitClassTemplateDecl(const pasta::ClassTemplateDecl &decl) final {
    auto raw_decl = RawEntity(decl);

    // Note: The canonical declaration of specialization always points to the
    //       base decl. Disable it temporarily.
    //
    // TODO(kumarak): Discuss with pag before finalizing the change. Should we
    //                check for canonical declaration to avoid redeclaration
    //                getting into a fragment? The missing redeclaration
    //                fragment causes assert during reference lookup in mx-api.
    if (!seen.emplace(raw_decl).second) {
      return;
    }

    // We want to visit the stuff in the pattern, but not add the pattern as a
    // top-level declaration. Also, clang tends to inject a class into itself
    // that our patched remap back to the class, so we want to prevent that from
    // being observed as a top-levelable thing.
    auto pattern = decl.TemplatedDeclaration();
    seen.insert(RawEntity(pattern));

    AddDeclAlways(decl);
    VisitDeeperDeclContext(pattern, pattern);

    if (decl.CanonicalDeclaration() != decl) {
      return;
    }

    auto specs = ExpandSpecializations(decl.Specializations());
    for (const pasta::ClassTemplateSpecializationDecl &spec : specs) {
      const void *spec_parent = nullptr;

      // Specializations of partial specializations are collected into the
      // template itself, but lexically "belong" to the partial specialization
      // itself.
      auto pattern = spec.SpecializedTemplateOrPartial();
      if (std::holds_alternative<pasta::ClassTemplatePartialSpecializationDecl>(pattern)) {
        const auto &partial = std::get<pasta::ClassTemplatePartialSpecializationDecl>(pattern);
        spec_parent = RawEntity(FindParentRedecl(partial, spec.Token()));
      
      } else {
        spec_parent = RawEntity(FindParentRedecl(decl, spec.Token()));
      }

      if (spec_parent) {
        PrevValueTracker<const void *> save_restore(parent_decl, spec_parent);
        Accept(spec);
      }
    }
  }

  void VisitVarTemplateDecl(const pasta::VarTemplateDecl &decl) final {
    auto raw_decl = RawEntity(decl);
    if (!seen.emplace(raw_decl).second) {
      return;
    }

    AddDeclAlways(decl);

    if (decl.CanonicalDeclaration() != decl) {
      return;
    }
  
    auto specs = ExpandSpecializations(decl.Specializations());
    for (const pasta::VarTemplateSpecializationDecl &spec : specs) {
      const void *spec_parent = nullptr;

      // Specializations of partial specializations are collected into the
      // template itself, but lexically "belong" to the partial specialization
      // itself.
      auto pattern = spec.SpecializedTemplateOrPartial();
      if (std::holds_alternative<pasta::VarTemplatePartialSpecializationDecl>(pattern)) {
        const auto &partial = std::get<pasta::VarTemplatePartialSpecializationDecl>(pattern);
        spec_parent = RawEntity(FindParentRedecl(partial, spec.Token()));
      
      } else {
        spec_parent = RawEntity(FindParentRedecl(decl, spec.Token()));
      }

      if (spec_parent) {
        PrevValueTracker<const void *> save_restore(parent_decl, spec_parent);
        Accept(spec);
      }
    }
  }

  void VisitVarTemplatePartialSpecializationDecl(
      const pasta::VarTemplatePartialSpecializationDecl &decl) final {
    auto raw_decl = RawEntity(decl);
    if (!seen.emplace(raw_decl).second) {
      return;
    }

    AddDeclAlways(decl);
  }

  void VisitVarTemplateSpecializationDecl(
      const pasta::VarTemplateSpecializationDecl &decl) {

    auto raw_decl = RawEntity(decl);
    if (!seen.emplace(raw_decl).second) {
      return;
    }

    AddDeclAlways(decl);
  }

  void VisitVarDecl(const pasta::VarDecl &decl) {

    // An out-of-line defined variable on a class template, but where the
    // variable itself is not a template. Make the parent fragment into the
    // out-of-line pattern.
    if (decl.IsOutOfLine()) {
      if (auto pattern = decl.TemplateInstantiationPattern()) {
        DCHECK(decl.Token() == pattern->Token());
        if (!pattern->DescribedVariableTemplate()) {
          PrevValueTracker<const void *> save_restore(parent_decl, RawEntity(pattern.value()));
          VisitDeclaratorDecl(decl);
          return;
        }
      }
    }

    VisitDeclaratorDecl(decl);
  }

  void VisitFriendTemplateDecl(const pasta::FriendTemplateDecl &decl) final {
    AddDecl(decl);
  }

  void VisitFunctionTemplateDecl(const pasta::FunctionTemplateDecl &decl) final {
    auto raw_decl = RawEntity(decl);
    if (!seen.emplace(raw_decl).second) {
      return;
    }

    auto pattern = decl.TemplatedDeclaration();
    if (ShouldHideFromIndexer(pattern)) {
      return;
    }

    AddDeclAlways(decl);

    if (decl.CanonicalDeclaration() != decl) {
      return;
    }

    auto specs = ExpandSpecializations(decl.Specializations());
    for (const pasta::FunctionDecl &spec : specs) {
      const void *spec_parent = nullptr;

      // Specializations of partial specializations are collected into the
      // template itself, but lexically "belong" to the partial specialization
      // itself.
      if (auto pattern = spec.TemplateInstantiationPattern()) {
        if (auto tpl = pattern->DescribedFunctionTemplate()) {
          spec_parent = RawEntity(FindParentRedecl(tpl.value(), spec.Token()));
        } else {
          assert(false);
        }
      }

      // NOTE(pag): We might not have `spec_parent` if this is an explicit
      //            declaration that turns into an implicit instantion of
      //            a function template.
      if (spec_parent) {
        PrevValueTracker<const void *> save_restore(parent_decl, spec_parent);
        seen.emplace(RawEntity(spec));
        AddDeclAlways(spec);
      }
    }
  }

  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final {
    if (ShouldHideFromIndexer(decl)) {
      return;
    }

    if (seen.count(RawEntity(decl))) {
      return;
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

    // This is a function template specialization.
    if (IsSpecialization(decl)) {
      AddDeclAlways(decl);
      return;
    }

    // An out-of-line line method defined on a class template.
    if (decl.NumTemplateParameterLists()) {
#ifndef NDEBUG
    auto dc = decl.LexicalDeclarationContext();
#endif
      assert(dc && !dc->IsRecord() && decl.IsOutOfLine() &&
             pasta::CXXMethodDecl::From(decl).has_value());
      AddDeclAlways(decl);
      return;
    }

    // This is an specialization of a non-template method.
    if (decl.IsTemplateInstantiation() && decl.IsOutOfLine()) {
      if (auto from = decl.InstantiatedFromMemberFunction()) {
        PrevValueTracker<const void *> save_restore(
            parent_decl, RawEntity(from.value()));
        AddDeclAlways(decl);
        return;
      }
    }

    // Methods (static or member) inside of class template specializations are
    // always nested fragments. This is because their bodies may not be fully
    // instantiated, and so we don't want them screwing up the fragment
    // deduplication.
    if (IsMethodLexicallyInSpecialization(decl)) {
      AddDeclAlways(decl);
      return;
    }

    VisitDeclaratorDecl(decl);
  }

  void VisitRecordDecl(const pasta::RecordDecl &decl) final {
    if (seen.count(RawEntity(decl))) {
      return;
    }

    VisitTagDecl(decl);

    // Forward declarations embedded in declarators within a record may have
    // a semantic decl context that is at the top level.
    VisitDeeperDeclContext(decl, decl);
  }

  void VisitCXXMethodDecl(const pasta::CXXMethodDecl &decl) final {
    // If the CXXMethodDecl is implicit, don't need to visit the declaration;
    // return early. We'll internalize these into the parent class fragment.
    if (decl.IsImplicit()) {
      return;
    }

    VisitFunctionDecl(decl);
  }

  void VisitUsingShadowDecl(const pasta::UsingShadowDecl &) final {}

  void VisitTypeAliasTemplateDecl(
      const pasta::TypeAliasTemplateDecl &decl) final {
    AddDecl(decl);
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

  // void VisitConceptDecl(const pasta::ConceptDecl &decl) {
  //   VisitTemplateDecl(decl);
  // }

  void VisitDecl(const pasta::Decl &decl) final {
    if (!depth) {
      AddDecl(decl);
      return;
    }

    // Check if we found something that is semantically at the top level.
    if (auto sema_dc = decl.DeclarationContext()) {
      if (!dc_depth[RawEntity(sema_dc.value())]) {
        AddDecl(decl);
        return;
      }
    }
  }
};

static mx::EntityOffset ParsedIndexOfMacroDirective(
    const pasta::MacroDirective &macro) {
  return macro.ParsedLocation().Index();
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

static bool IsContinuingConditionalDirective(
    const pasta::MacroDirective &macro) {
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

static bool IsClosingConditionalDirective(const pasta::MacroDirective &macro) {
  return macro.Kind() == pasta::MacroKind::kEndIfDirective;
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
    if (auto ftok = tok->FileLocation()) {
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
static EntityOffsetToDirectiveMap
FindNextPrevConditionalMacros(const pasta::AST &ast,
                              std::string_view main_file_path) {

  std::vector<pasta::MacroDirective> prev;
  EntityOffsetToDirectiveMap next;

  auto add_to_prev = [&] (const pasta::MacroDirective &macro, const char *what) {
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
static std::vector<OrderedDecl> FindTLDs(const pasta::AST &ast,
                                         EntityMapper &em) {

  std::vector<OrderedDecl> tlds;
  TLDFinder tld_finder(tlds, em);
  tld_finder.VisitTranslationUnitDecl(ast.TranslationUnit());

  auto decl_eq = +[] (const OrderedDecl &a, const OrderedDecl &b) {
    return RawEntity(a.decl) == RawEntity(b.decl);
  };

  auto decl_less = +[] (const OrderedDecl &a, const OrderedDecl &b) {
    return RawEntity(a.decl) < RawEntity(b.decl);
  };

  auto order_less = +[] (const OrderedDecl &a, const OrderedDecl &b) {
    return a.order < b.order;
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
      return false;

    case pasta::TokenRole::kBeginOfFileMarker:
    case pasta::TokenRole::kEndOfFileMarker:
    case pasta::TokenRole::kEndOfMacroExpansionMarker:
      return true;

    case pasta::TokenRole::kBeginOfMacroExpansionMarker:
    case pasta::TokenRole::kInitialMacroUseToken:
    case pasta::TokenRole::kIntermediateMacroExpansionToken:
    case pasta::TokenRole::kFinalMacroExpansionToken:
    case pasta::TokenRole::kMacroDirectiveMarker:
      return false;

    case pasta::TokenRole::kFileToken:
      break;
  }

  switch (tok.Kind()) {
    case pasta::TokenKind::kComment:
    case pasta::TokenKind::kEndOfFile:
    case pasta::TokenKind::kEndOfDirective:
    case pasta::TokenKind::kCodeCompletion:
    case pasta::TokenKind::kUnknown:
      return IsWhitespaceOrEmpty(tok.Data());
    default:
      return false;
  }
}

// Do some minor stuff to find begin/ending tokens.
static std::pair<mx::EntityOffset, mx::EntityOffset> BaselineEntityRange(
    const pasta::Decl &decl, const pasta::Token &tok,
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

static mx::EntityOffset PreviousConditionalIndex(
    const EntityOffsetToDirectiveMap &dir_index_to_next_dir,
    const pasta::MacroDirective &macro) {

  auto macro_index = ParsedIndexOfMacroDirective(macro);
  auto it = dir_index_to_next_dir.find(~macro_index);
  if (it != dir_index_to_next_dir.end()) {
    return ParsedIndexOfMacroDirective(it->second);

  } else {
    return macro_index;
  }
}

static mx::EntityOffset EndOfConditionalSequence(
    const EntityOffsetToDirectiveMap &dir_index_to_next_dir,
    const pasta::MacroDirective &macro) {

  auto macro_index = ParsedIndexOfMacroDirective(macro);
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
static mx::EntityOffset ExpandToEndOfNextDirective(
    const EntityOffsetToDirectiveMap &dir_index_to_next_dir,
    mx::EntityOffset begin_index, mx::EntityOffset end_index,
    mx::EntityOffset max_index) {

  for (auto bi = begin_index; bi <= end_index; ) {
    auto it = dir_index_to_next_dir.upper_bound(bi);
    if (it == dir_index_to_next_dir.end()) {
      return end_index;
    }

    // We've gone into the back-references.
    if (it->first >= max_index) {
      return end_index;
    }

    const pasta::MacroDirective &dir = it->second;
    mx::EntityOffset dir_begin_index = 0u;
    mx::EntityOffset dir_end_index = 0u;

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

// Expand the range for a declaration. This doesn't widen to the complete
// expansion range, and instead focuses on trailing semicolons, leading
// indentation, empty macros, and comments.
static std::pair<mx::EntityOffset, mx::EntityOffset> ExpandDeclRange(
    const pasta::TokenRange &range,
    mx::EntityOffset begin_tok_index, mx::EntityOffset end_tok_index) {

  const auto max_tok_index = range.Size();

  // Expand to trailing semicolon.
  if ((end_tok_index + 1u) < max_tok_index) {
    pasta::Token last_tok = range[end_tok_index + 1u];
    if (last_tok.Kind() == pasta::TokenKind::kSemi &&
        last_tok.Role() == pasta::TokenRole::kFileToken) {
      ++end_tok_index;
    }
  }

  // Expand to leading empty macro, followed by whitespace containing no more
  // than one new line.
  while (3u <= begin_tok_index &&
         range[begin_tok_index - 3u].Role() == pasta::TokenRole::kBeginOfMacroExpansionMarker &&
         range[begin_tok_index - 2u].Role() == pasta::TokenRole::kEndOfMacroExpansionMarker) {
    
    auto pt = range[begin_tok_index - 1u];
    auto td = pt.Data();
    if (pt.Kind() == pasta::TokenKind::kUnknown &&
        pt.Role() == pasta::TokenRole::kFileToken &&
        IsWhitespaceOrEmpty(td) &&
        std::count(td.begin(), td.end(), '\n') <= 1u) {
      begin_tok_index -= 3u;
    } else {
      break;
    }
  }

  // Expand to leading comment followed by whitespace containing no more than
  // one new line.
  while (2u <= begin_tok_index &&
         range[begin_tok_index - 2u].Kind() == pasta::TokenKind::kComment) {
    auto pt = range[begin_tok_index - 1u];
    auto td = pt.Data();
    if (pt.Kind() == pasta::TokenKind::kUnknown &&
        pt.Role() == pasta::TokenRole::kFileToken &&
        IsWhitespaceOrEmpty(td) &&
        std::count(td.begin(), td.end(), '\n') <= 1u) {
      begin_tok_index -= 2u;
    } else {
      break;
    }
  }

  // Expand to leading indentation.
  if (begin_tok_index) {
    auto prev_tok = range[begin_tok_index - 1u];
    auto prev_tok_data = prev_tok.Data();
    if (prev_tok.Kind() == pasta::TokenKind::kUnknown &&
        (prev_tok_data.ends_with(' ') || prev_tok_data.ends_with('\t'))) {
      begin_tok_index -= 1u;
    }
  }

  return {begin_tok_index, end_tok_index};
}

// Expand an inclusive `[begin, end]` range to be as wide as necessary to
// include the full scope of macro expansion.
static std::pair<mx::EntityOffset, mx::EntityOffset> ExpandRange(
    const pasta::TokenRange &range,
    mx::EntityOffset begin_tok_index, mx::EntityOffset end_tok_index) {

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

  // Now adjust for macros at the beginning and ending. If we find macro
  // expansion ranges, then the expand until we find the beginning of the
  // range.
  bool done = false;
  while (!done && 0u < begin_tok_index && begin_tok_index <= end_tok_index) {
    pasta::Token tok = range[begin_tok_index];
    switch (tok.Role()) {
      case pasta::TokenRole::kInvalid:
        --begin_tok_index;  // Split token; include it.
        break;
      case pasta::TokenRole::kFileToken:
        if (CanElideTokenFromTLD(tok)) {
          ++begin_tok_index;  // Don't include it.
        } else {
          done = true;
        }
        break;
      case pasta::TokenRole::kBeginOfMacroExpansionMarker:
        in_macro = false;
        done = true;
        break;

      case pasta::TokenRole::kBeginOfFileMarker:
      case pasta::TokenRole::kEndOfFileMarker:
      case pasta::TokenRole::kEndOfMacroExpansionMarker:
        assert(!in_macro);
        ++begin_tok_index;  // Don't include it.
        done = true;
        break;

      // These don't exist in the parsed token list.
      case pasta::TokenRole::kInitialMacroUseToken:
      case pasta::TokenRole::kIntermediateMacroExpansionToken:
        assert(false);
        [[fallthrough]];

      case pasta::TokenRole::kFinalMacroExpansionToken:
      case pasta::TokenRole::kMacroDirectiveMarker:
        --begin_tok_index;  // Include it.
        in_macro = true;
        break;
    }
  }

  assert(!in_macro);
  in_macro = false;

  done = false;
  while (!done && 0u < end_tok_index && end_tok_index < max_tok_index) {
    pasta::Token tok = range[end_tok_index];
    switch (tok.Role()) {
      case pasta::TokenRole::kInvalid:
        ++end_tok_index;  // Split token; include it.
        break;
      case pasta::TokenRole::kFileToken:
        if (CanElideTokenFromTLD(tok)) {
          --end_tok_index;  // Don't include it.
        } else {
          done = true;
        }
        break;
      case pasta::TokenRole::kEndOfMacroExpansionMarker:
        in_macro = false;
        done = true;
        break;
      case pasta::TokenRole::kBeginOfFileMarker:
      case pasta::TokenRole::kEndOfFileMarker:
      case pasta::TokenRole::kBeginOfMacroExpansionMarker:
        assert(!in_macro);
        --end_tok_index;  // Don't include it.
        done = true;
        break;

      // These don't exist in the parsed token list.
      case pasta::TokenRole::kInitialMacroUseToken:
      case pasta::TokenRole::kIntermediateMacroExpansionToken:
        assert(false);
        [[fallthrough]];

      case pasta::TokenRole::kFinalMacroExpansionToken:
      case pasta::TokenRole::kMacroDirectiveMarker:
        ++end_tok_index;  // Include it.
        in_macro = true;
        break;
    }
  }

  assert(!in_macro);
  (void) in_macro;

  std::tie(begin_tok_index, end_tok_index) = ExpandDeclRange(
      range, begin_tok_index, end_tok_index);

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
    case pasta::TokenRole::kMacroDirectiveMarker:
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
    case pasta::TokenRole::kMacroDirectiveMarker:
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
static std::pair<mx::EntityOffset, mx::EntityOffset> FindDeclRange(
    const pasta::TokenRange &range,
    const EntityOffsetToDirectiveMap &dir_index_to_next_dir,
    const pasta::Decl &decl, const pasta::Token &tok,
    std::string_view main_file_path) {

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

  switch (tsk) {
    case pasta::TemplateSpecializationKind::kExplicitSpecialization:
    case pasta::TemplateSpecializationKind::kExplicitInstantiationDeclaration:
    case pasta::TemplateSpecializationKind::kExplicitInstantiationDefinition:
      return true;

    // NOTE(pag): Have observed situations where `ClassTemplateSpecialization`
    //            will report `kUndeclared`.
    //
    // NOTE(pag): Clang patches for `Decl::RemappedDecl` should help with this?
    //
    // NOTE(pag): This will also trigger for basicall all non-template things,
    //            e.g. all C code.
    case pasta::TemplateSpecializationKind::kUndeclared:
      return has_partial_or_tpl_or_dg;

    default:
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

  entity_ranges.emplace_back(std::move(decl), nullptr  /* no parent */, 0u, 0u);
}

static bool LooksLikeFunctionTemplateOfLambda(const pasta::Token &tok,
                                              const pasta::Decl &decl) {
  return tok.Kind() == pasta::TokenKind::kLSquare &&
         decl.IsImplicit() &&
         decl.Kind() == pasta::DeclKind::kFunctionTemplate;
}

// Figure out the inclusive token index bounds of `decl` and add it to
// `entity_ranges`.
static void AddDeclRangeToEntityListFor(
    const pasta::TokenRange &tokens,
    const EntityOffsetMap &eof_to_include,
    const EntityOffsetMap &eof_indices,
    const EntityOffsetToDirectiveMap &dir_index_to_next_dir,
    std::string_view main_file_path, pasta::Decl decl, const void *parent,
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
  LOG_IF(ERROR, ShouldFindDeclInTokenContexts(decl) &&
                decl.Kind() != pasta::DeclKind::kBlock &&
                !TokenIsInContextOfDecl(tok, decl) &&
                !IsProbablyABuiltinDecl(decl) &&
                !LooksLikeFunctionTemplateOfLambda(tok, decl))
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
  for (mx::EntityOffset i = begin_index + 1u; i < end_index; ++i) {
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

  entity_ranges.emplace_back(std::move(decl), parent, begin_index, end_index);
}

// Go find the top-level macros to be indexed. These are basically directives
// and macro expansions. We find the top-level macro expansions by locating
// the macro roots of the expansions associated with macro definitions. There
// are a few ways of going about this. PASTA's `TokenRange` will include marker
// tokens telling us when a macro expansion area begins and ends. If there's
// an empty expansion then there will be nothing between these two marker
// tokens. We can get at some kind of expansion node (likely but not guaranteed
// to be the root node from the begin/end markers). Alternatively, we can get at
// all directives via directive marker tokens. This is the most reliable
// approach, as some directives can be embedded inside of the argument list of
// some expansions, and so we'd like to treat those separately (as floating
// fragments). Then we can get the root expansions from looking at just the
// uses of `#define` directives.
static std::vector<OrderedMacro> FindTLMs(
    const pasta::AST &ast, const pasta::TokenRange &tokens,
    const EntityOffsetMap &bof_to_eof, EntityOffsetMap &eof_to_include) {

  std::vector<OrderedMacro> tlms;
  std::vector<pasta::DefineMacroDirective> defs;
  const mx::EntityOffset num_tokens = tokens.Size();

  auto order = 0u;
  for (pasta::Token tok : tokens) {

    // All macro directives have a corresponding marker token.
    if (tok.Role() != pasta::TokenRole::kMacroDirectiveMarker) {
      continue;
    }

    auto dir = tok.Directive();
    if (!dir) {
      assert(false);
      continue;
    }

    auto md = std::move(dir.value());
    tlms.emplace_back(md, order++);

    // If this is a macro definition, then keep track of it for later so that
    // we can find all expansions.
    if (auto dmd = pasta::DefineMacroDirective::From(md)) {
      defs.push_back(std::move(dmd.value()));
      continue;
    }
    
    // If it's an include-like directive, then we want to be able to associate
    // begin- and end-of-file markers with this directive. Here we'll find
    // the relevant begin-of-file markers.
    auto ild = pasta::IncludeLikeMacroDirective::From(md);
    if (!ild) {
      continue;
    }

    // All directives have a designated parsed location. Directives exist
    // inside of macro expansions, bounded by markers in the parsed token
    // lists. Go and find the ending macro expansion marker following the
    // directive marker corresponding to this `#include`.
    auto ild_index = ild->ParsedLocation().Index();
    auto bom_index = ild_index;
    auto eom_index = ild_index;
    auto found = false;
    for (; eom_index < (num_tokens - 1); ++eom_index) {
      auto tok = tokens[eom_index];
      if (tok.Role() == pasta::TokenRole::kEndOfMacroExpansionMarker) {
        bom_index = tok.BalancedLocation()->Index();
        assert(bom_index != eom_index);
        found = true;
        break;
      }
    }

    if (!found) {
      assert(false);
      continue;
    }

    assert(bom_index < eom_index);
    assert(bom_index < ild_index);

    // The next token immediately following an end-of-expansion marker
    // containing an include should be the beginning of file marker.
    //
    // We may not find it if the file has been heuristically skipped, e.g.
    // due to a `#pragma once`. The purpose of this code is really to find
    // the case of files embedded within fragments, e.g. for handling the
    // x-macro pattern. We don't anticipate include guards/pragmas preventing
    // redundant inclusion in those cases.
    auto bof_index = eom_index + 1u;
    if (tokens[bof_index].Role() != pasta::TokenRole::kBeginOfFileMarker) {
      continue;
    }

    auto it = bof_to_eof.find(bof_index);
    if (it == bof_to_eof.end()) {
      assert(false);
      continue;
    }

    // Map the EOF marker to the BOM marker token for the `#include`. We'll
    // use this to help expand decl/fragment ranges.
    eof_to_include.emplace(it->second, bom_index);
  }

  // Go find all expansions
  for (pasta::DefineMacroDirective def : defs) {
    for (pasta::Macro use : def.Uses()) {
      tlms.emplace_back(RootMacroFrom(std::move(use)), order++);
    }
  }

  auto eq = +[] (const OrderedMacro &a, const OrderedMacro &b) {
    return RawEntity(a.macro) == RawEntity(b.macro);
  };

  auto less = +[] (const OrderedMacro &a, const OrderedMacro &b) {
    auto a_id = RawEntity(a.macro);
    auto b_id = RawEntity(b.macro);
    if (a_id < b_id) {
      return true;
    } else if (a_id > b_id) {
      return false;
    } else {
      return a.order < b.order;
    }
  };

  auto orig_less = +[] (const OrderedMacro &a, const OrderedMacro &b) {
    return a.order < b.order;
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

  if (pasta::TokenRange range = pasta::Macro::CompleteExpansionRange(node)) {
    entity_ranges.emplace_back(
        std::move(node), nullptr, range.Front()->Index(),
        range.Back()->Index());

  } else {
    LOG(ERROR)
        << "Empty parsed token range for macro "
        << MacroLocation(node);
  }
}

// Sort the top-level declarations so that syntactically overlapping
// declarations are in the correct order, and are side-by-side in the output
// vector.
static std::vector<EntityRange> SortEntities(const pasta::AST &ast,
                                             std::string_view main_file_path,
                                             EntityMapper &em) {

  pasta::TokenRange tokens = ast.Tokens();
  std::vector<EntityRange> entity_ranges;
  entity_ranges.reserve(8192u);

  EntityOffsetMap eof_index_to_include;
  EntityOffsetMap bof_to_eof;

  // Find end-of-file indices. Sometimes we need to expand declaration ranges
  // out to include an end of file if they include the beginning of the file.
  // This helps keep later `TokenTree` stuff balanced, and relates to Issue
  // #258.
  std::vector<mx::EntityOffset> open_indexes;
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
                                 std::move(ordered_entry.macro), entity_ranges);
  }

  auto dir_index_to_next_dir = FindNextPrevConditionalMacros(
      ast, main_file_path);

  for (OrderedDecl ordered_entry : FindTLDs(ast, em)) {
    AddDeclRangeToEntityListFor(tokens, eof_index_to_include, bof_to_eof,
                                dir_index_to_next_dir, main_file_path, 
                                std::move(ordered_entry.decl),
                                ordered_entry.parent, entity_ranges);
  }

  // It's possible that we have two-or-more things that appear to be top-level
  // decls, but really we're only dealing with one top-level decl. This happens
  // with things like `typedef`s in Clang when the referenced type of a typedef
  // is defined within the typedef (e.g. a union/struct/enum type). In these
  // cases, Clang places the definition of the referenced type before the
  // typedef inside of the `DeclContext`, and so the referenced type appears
  // as its own top-level declaration, despite it being logically nested inside
  // of another top-level declaration.

  std::stable_sort(
      entity_ranges.begin(), entity_ranges.end(),
      [] (const EntityRange &a, const EntityRange &b) {
        if (a.begin_index < b.begin_index) {
          return true;
        } else if (a.begin_index > b.begin_index) {
          return false;
        } else if (a.end_index < b.end_index) {
          return true;
        } else if (a.end_index > b.end_index) {
          return false;
        } else {
          return int(!!a.parent) < int(!!b.parent);
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

// Should we merge a leading macro with the next entity? We have to deal with
// one corner case, observed in cURL:
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
static bool MergeLeadingMacroWithNextEntity(
    const pasta::TokenRange &tokens, mx::EntityOffset begin_index,
    mx::EntityOffset end_index, mx::EntityOffset next_begin_index) {

  // Make sure there are no parsed tokens inside of the leading macro expansion.
  // If there were then we should have discovered them as leading keywords (e.g.
  // storage specifiers) or attributes.
  for (auto i = begin_index; i <= end_index; ++i) {
    auto tok = tokens[i];
    switch (tok.Role()) {
      case pasta::TokenRole::kFinalMacroExpansionToken:
      case pasta::TokenRole::kMacroDirectiveMarker:
      case pasta::TokenRole::kBeginOfFileMarker:
      case pasta::TokenRole::kEndOfFileMarker:
        return false;
      case pasta::TokenRole::kFileToken:
        if (IsParsedTokenExcludingWhitespaceAndComments(tok)) {
          return false;
        }
        continue;
      case pasta::TokenRole::kBeginOfMacroExpansionMarker:
      case pasta::TokenRole::kEndOfMacroExpansionMarker:
      case pasta::TokenRole::kInvalid:
        continue;
      case pasta::TokenRole::kInitialMacroUseToken:
      case pasta::TokenRole::kIntermediateMacroExpansionToken:
        assert(false);
        continue;
    }
  }

  // Nothing between.
  if ((end_index + 1u) == next_begin_index) {
    return true;
  }

  // More than one token between.
  if ((end_index + 2u) != next_begin_index) {
    return false;
  }

  auto bt = tokens[end_index + 1u];
  auto btk = bt.Kind();
  if (btk == pasta::TokenKind::kComment) {
    return true;
  }

  if (btk != pasta::TokenKind::kUnknown) {
    return false;
  }

  auto btd = bt.Data();
  return std::count(btd.begin(), btd.end(), '\n') <= 1u;
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
    GlobalIndexingState &context, const pasta::AST &ast,
    EntityMapper &em) {

  pasta::TokenRange tokens = ast.Tokens();
  std::string main_file_path = ast.MainFile().Path().generic_string();

  ProgressBarWork partitioning_progress_tracker(context.partitioning_progress);

  std::vector<EntityRange> entity_ranges = SortEntities(
      ast, main_file_path, em);
  std::vector<EntityGroupRange> entity_group_ranges;
  entity_group_ranges.reserve(entity_ranges.size());

  for (size_t i = 0u, max_i = entity_ranges.size(); i < max_i; ) {
    EntityGroup entities_for_group;
    Entity prev_entity;

    auto begin_index = entity_ranges[i].begin_index;
    auto end_index = entity_ranges[i].end_index;
    auto prev_begin_index = begin_index;
    auto prev_end_index = end_index;

    for (; i < max_i; ++i) {

      Entity next_entity = entity_ranges[i].entity;
      auto next_begin = entity_ranges[i].begin_index;
      auto next_end = entity_ranges[i].end_index;

      // XREF: Issue 412 (https://github.com/trailofbits/multiplier/issues/412).
      //       We can have leading empty macros in cURL and the Linux kernel,
      //       depending on the configuration, that logically should belong to
      //       the entity. It's possible we have a sequence of such macros.
      if (std::holds_alternative<pasta::Macro>(prev_entity) &&
          MergeLeadingMacroWithNextEntity(tokens, prev_begin_index,
                                          prev_end_index, next_begin)) {

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
      prev_entity = std::move(next_entity);
      prev_begin_index = next_begin;
      prev_end_index = next_end;

      entities_for_group.emplace_back(std::move(entity_ranges[i]));
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
  for (const EntityRange &er : entities) {
    if (std::holds_alternative<pasta::Macro>(er.entity)) {
      FindMacroFileBounds(std::get<pasta::Macro>(er.entity), begin_tok, end_tok);
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

// Estimate the number of tokens in the macro range.
static unsigned MacroRangeSize(const std::vector<pasta::Macro> &macros) {
  if (macros.empty()) {
    return 0u;
  }

  auto max = 0u;
  auto min = ~0u;
  auto any = false;

  for (const auto &macro : macros) {
    if (auto bt = macro.BeginToken()) {
      auto index = bt->Index();
      min = std::min(min, index);
      max = std::max(max, index);
      any = true;
    }

    auto range = pasta::Macro::CompleteExpansionRange(macro);
    for (auto size = range.Size(); size--; ) {
      if (auto et = range[size].MacroLocation()) {
        auto index = et->Index();
        min = std::min(min, index);
        max = std::max(max, index);
        any = true;
        break;
      }
    }
  }

  return any ? (max - min + 1u) : 0u;
}

static PendingFragmentPtr CreatePendingFragment(
    IdStore &id_store, EntityMapper &em, NameMangler &nm,
    const pasta::TokenRange *original_tokens,
    pasta::PrintedTokenRange parsed_tokens,
    std::optional<FileLocationOfFragment> floc,
    mx::PackedCompilationId tu_id,
    mx::EntityOffset begin_index,
    mx::EntityOffset end_index,
    std::vector<pasta::Decl> decls,
    std::vector<pasta::Macro> macros,
    const void *parent_entity,
    bool parsed_are_printed) {

  // The number of tokens is used to estimate the "size" of this fragment.
  // Mostly, it's a proxy of the complexity of the macro expansions as well.
  // The size of the fragment affects which encoding format we use: the "big"
  // fragment ID encoding scheme (i.e. has lots of stuff, but we can't encode
  // as many of them), or the small one (i.e. doesn't have as much stuff, and
  // we can encode substantially more of them).
  mx::EntityOffset num_tokens = 0u;
  if (original_tokens) {
    num_tokens = original_tokens->Size();
  }

  num_tokens = std::max(num_tokens, parsed_tokens.Size()) +
               MacroRangeSize(macros);

  // Compute the fragment ID, and in doing so, figure out if this is actually
  // a new fragment.
  auto [fid, is_new_fragment_id] = id_store.GetOrCreateFragmentIdForHash(
      (floc ? floc->first_file_token_id.Pack() : mx::kInvalidEntityId),
      HashFragment(em, nm, parent_entity, decls, macros, original_tokens,
                   parsed_tokens),
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
      std::move(floc)  /* file_location */,
      parsed_are_printed));

  pf->num_top_level_declarations = static_cast<unsigned>(decls.size());
  pf->num_top_level_macros = static_cast<unsigned>(macros.size());
  pf->raw_parent_entity = parent_entity;

  // Steal the TLDs and TLMs. If we have child fragments, then we want the
  // root fragment to own the macros.
  pf->top_level_decls = std::move(decls);
  pf->top_level_macros = std::move(macros);

  InitializeEntityLabeller(*pf);

  return pf;
}

// Create a printed token range for a sequence of declarations, and make it
// represent the parsed tokens.
static pasta::PrintedTokenRange CreateParsedTokenRange(
    pasta::PrintedTokenRange parsed_tokens,
    const std::vector<pasta::Decl> &decls, const pasta::PrintingPolicy &pp,
    std::string_view main_job_file, bool &parsed_are_printed) {

  CHECK(!decls.empty());

  // We don't want to concatenate the printed output of declarations that are
  // embedded in the declarators of other declarations, because we'll capture
  // those decls when printing those declarators.
  std::vector<pasta::Decl> decls_to_print;
  for (const pasta::Decl &decl : decls) {
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
    CHECK_EQ(decls.size(), 1u);
    decls_to_print = decls;
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

  // If any of the decls to be printed are actually specializations, then we
  // don't want to return the parsed tokens, as those will likely represent
  // things like 
  for (const auto &decl : decls_to_print) {
    if (IsSpecializationOrInSpecialization(decl)) {
      parsed_are_printed = true;
      parsed_tokens = pasta::PrintedTokenRange::AdoptWhitespace(
          printed_tokens, parsed_tokens);
      break;
    }
  }

  if (!err.has_value()) {
    return parsed_tokens;
  }

  // Report the error and try to recover.
  LOG(WARNING)
      << "Unable to align tokens in main job file " << main_job_file
      << PrefixedLocation(decls.front(), " at or near ") << ": "
      << err.value();

  err = pasta::PrintedTokenRange::Align(parsed_tokens, printed_tokens,
                                        true  /* recovery mode */);

  LOG_IF(ERROR, err.has_value())
      << "Unable to align tokens in recovery mode in main job file "
      << main_job_file << PrefixedLocation(decls.front(), " at or near ")
      << ": " << err.value();

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
    NameMangler &nm,
    std::optional<FileLocationOfFragment> floc,
    mx::PackedCompilationId tu_id,
    mx::EntityOffset begin_index,
    mx::EntityOffset end_index,
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
    if (IsSpecializationOrInSpecialization(decl)) {
      parsed_tokens = pasta::PrintedTokenRange::AdoptWhitespace(
          printed_tokens, parsed_tokens);
    }

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
      nm,
      nullptr  /* original_tokens */,
      std::move(printed_tokens)  /* parsed_tokens */,
      std::move(floc),
      tu_id,
      begin_index,
      end_index,
      std::move(decls),
      {}  /* empty macros */,
      nullptr  /* no parent entity */,
      false  /* Using printed tokens. A bit of a lie, but we don't want to
              * trigger token tree rebuilding. */);

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

  pending_fragments.emplace_back(std::move(pf));
}

// Create a floating fragment for the top-level directives.
static void CreateFloatingDirectiveFragment(
    IdStore &id_store,
    EntityMapper &em,
    NameMangler &nm,
    mx::PackedCompilationId tu_id,
    const pasta::Macro &macro,
    std::vector<PendingFragmentPtr> &pending_fragments) {

  auto dir = pasta::MacroDirective::From(macro);
  CHECK(dir.has_value());

  auto root_macro = RootMacroFrom(macro);

  auto marker_tok = dir->ParsedLocation();

  auto directive_range = pasta::TokenRange::From(marker_tok, marker_tok);
  CHECK(directive_range.has_value());
  CHECK(!directive_range->empty());
  auto begin_index = directive_range->Front()->Index();
  auto end_index = directive_range->Back()->Index();

  // TODO(pag): Eventually allow floating macro define directives from
  //            compilation commands.
  EntityGroup entities;
  entities.emplace_back(macro, nullptr, begin_index, end_index);
  auto floc = FindFileLocationOfFragment(
      em.entity_ids, entities, directive_range.value());

  std::vector<pasta::Macro> macros;
  macros.push_back(macro);

  auto pf = CreatePendingFragment(
      id_store,
      em,
      nm,
      &(directive_range.value())  /* original_tokens */,
      pasta::PrintedTokenRange::CreateEmpty(
          pasta::AST::From(macro))  /* parsed_tokens */,
      std::move(floc),
      tu_id,
      begin_index,
      end_index,
      {}  /* empty decls */,
      std::move(macros),
      nullptr  /* parent entity */,
      false  /* using parsed tokens */);

  // NOTE(pag): This will not persist token ids, because there are no tokens
  //            in the empty range, but it will persist  some macros globally.
  //            When the `EntityMapper` is reset for a fragment prior to
  //            persisting, those macros ids will persist.
  // LabelTokensAndMacrosInFragment(*pf);

  pending_fragments.emplace_back(std::move(pf));
}

static void CreatePendingFragments(
    IdStore &id_store, EntityMapper &em, NameMangler &nm,
    const pasta::TokenRange &tok_range, mx::PackedCompilationId tu_id,
    EntityGroupRange group_range, std::string_view main_file_path,
    std::vector<PendingFragmentPtr> &pending_fragments) {

  EntityGroup &entities = group_range.group;
  if (!DebugIndexOnlyThisFragment(entities)) {
    return;
  }

  auto begin_index = group_range.begin_index;
  auto end_index = group_range.end_index;

  std::optional<pasta::TokenRange> sub_tok_range = pasta::TokenRange::From(
      tok_range[begin_index], tok_range[end_index]);

  if (!sub_tok_range) {
    LOG(FATAL)
        << "Invalid parsed token range for pending fragment in "
        << main_file_path;
    return;
  }

  // Directives, especially `#define` directives, are treated as floating
  // root fragments, as they are kind of "free standing" w.r.t. expansion, and
  // define directives in particular can be referenced from other locations,
  // and so we need special handling of their tokens/entities w.r.t. the
  // entity mapper. We process these first, as they can end up being used
  // lexically inside of other top-level entities.
  for (const EntityRange &er : entities) {
    if (std::holds_alternative<pasta::Macro>(er.entity)) {
      const pasta::Macro &macro = std::get<pasta::Macro>(er.entity);
      if (ShouldGoInFloatingFragment(macro)) {
        CreateFloatingDirectiveFragment(
            id_store, em, nm, tu_id, macro, pending_fragments);
      }
    }
  }

  const pasta::TokenRange &frag_tok_range = sub_tok_range.value();

  // Locate where this fragment is in its file.
  std::optional<FileLocationOfFragment> floc = FindFileLocationOfFragment(
      em.entity_ids, entities, frag_tok_range);

  std::vector<pasta::Decl> root_decls;
  std::vector<EntityRange> nested_decls;
  std::vector<pasta::Macro> top_level_macros;

  // Partition the top-level declarations so that ones that definitely won't
  // need to go in a nested fragment show up first. This acts as a minor
  // mitigation to #396 (https://github.com/trailofbits/multiplier/issues/396).
  for (EntityRange &er : entities) {
    if (std::holds_alternative<pasta::Decl>(er.entity)) {
      auto &decl = std::get<pasta::Decl>(er.entity);

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
                 !floc || decl.IsImplicit()) {

        CreateFreestandingDeclFragment(
            id_store, em, nm, floc, tu_id, begin_index, end_index,
            decl, pending_fragments, main_file_path);

      // These are generally template instantiations.
      } else if (er.parent) {
        nested_decls.emplace_back(std::move(er));

      // E.g. `int a, b;` will produce two `VarDecl`s that we want to merge into
      // a single root decl.
      } else {
        root_decls.emplace_back(std::move(decl));
      }

    // Find our top-level macro uses.
    } else if (std::holds_alternative<pasta::Macro>(er.entity)) {
      const pasta::Macro &macro = std::get<pasta::Macro>(er.entity);
      if (!ShouldGoInFloatingFragment(macro)) {
        top_level_macros.emplace_back(macro);
      }

    } else {
      LOG(ERROR)
          << "TODO: Unsupported top-level entity kind in " << main_file_path;
      return;
    }
  }

  pasta::PrintingPolicy pp;

  auto root_decls_copy = root_decls;
  auto top_level_macros_copy = top_level_macros;

  // Top-level expansion or `#include`. 
  if (root_decls.empty() && !top_level_macros.empty()) {
    auto pf = CreatePendingFragment(
        id_store,
        em,
        nm,
        &frag_tok_range  /* original_tokens */,
        pasta::PrintedTokenRange::Adopt(frag_tok_range)  /* parsed_tokens */,
        floc  /* copied */,
        tu_id,
        begin_index,
        end_index,
        std::move(root_decls),
        top_level_macros  /* copied */,
        nullptr  /* parent entity */,
        false  /* not using printed tokens */);

    pending_fragments.emplace_back(std::move(pf));

  // Top-level declarations, possibly with macro expansions.
  } else if (!root_decls.empty()) {
    bool parsed_are_printed = false;
    pasta::PrintedTokenRange aligned_tokens =
        CreateParsedTokenRange(
            pasta::PrintedTokenRange::Adopt(frag_tok_range),
            root_decls, pp, main_file_path, parsed_are_printed);

    CHECK(!aligned_tokens.empty() || !top_level_macros.empty());

    auto pf = CreatePendingFragment(
        id_store,
        em,
        nm,
        &frag_tok_range  /* original_tokens */,
        std::move(aligned_tokens)  /* parsed_tokens */,
        floc  /* copied */,
        tu_id,
        begin_index,
        end_index,
        std::move(root_decls),
        top_level_macros  /* copied */,
        nullptr  /* parent entity */,
        parsed_are_printed);

    pending_fragments.emplace_back(std::move(pf));
  }

  // Create the nested fragments for the root fragment. These correspond to
  // things like template specializations/instantiations.
  for (EntityRange &er : nested_decls) {
    std::vector<pasta::Decl> decls;
    decls.emplace_back(std::move(std::get<pasta::Decl>(er.entity)));

    auto decl_range = decls.front().Tokens();
    if (decl_range) {
      std::tie(begin_index, end_index) = ExpandDeclRange(
          tok_range, decl_range.Front()->Index(), decl_range.Back()->Index());

    } else {
      LOG(ERROR)
          << "Nested fragment" << PrefixedLocation(decls.front(), " at or near ")
          << " on main job file " << main_file_path << " has no parsed tokens";
      begin_index = er.begin_index;
      end_index = er.end_index;
    }

    std::optional<pasta::TokenRange> sub_tok_range = pasta::TokenRange::From(
        tok_range[begin_index], tok_range[end_index]);

    CHECK(sub_tok_range.has_value());

    bool parsed_are_printed = false;
    pasta::PrintedTokenRange aligned_tokens = CreateParsedTokenRange(
        pasta::PrintedTokenRange::Adopt(sub_tok_range.value()),
        decls, pp, main_file_path, parsed_are_printed);

    CHECK(!aligned_tokens.empty());

    auto pf = CreatePendingFragment(
        id_store,
        em,
        nm,
        &(sub_tok_range.value())  /* original_tokens */,
        std::move(aligned_tokens)  /* parsed_tokens */,
        floc  /* copied */,
        tu_id,
        begin_index,
        end_index,
        std::move(decls),
        top_level_macros  /* copied */,
        er.parent,
        parsed_are_printed);

    pending_fragments.emplace_back(std::move(pf));
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
    GlobalIndexingState &context, EntityMapper &em, NameMangler &nm,
    const pasta::AST &ast, mx::PackedCompilationId tu_id,
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
      CreatePendingFragments(context.id_store, em, nm, tok_range, tu_id,
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
    const pasta::AST &ast,
    EntityMapper &em,
    NameMangler &nm,
    mx::PackedCompilationId tu_id,
    std::vector<PendingFragmentPtr> pending_fragments) {

  TokenProvenanceCalculator provenance(em);

  std::string main_source_file = ast.MainFile().Path().generic_string();
  std::vector<mx::PackedFragmentId> fragment_ids;
  std::vector<FragmentBounds> nested_fragment_bounds;

  auto num_new = 0u;
  for (PendingFragmentPtr &pf : pending_fragments) {

    // Record the bounds of nested fragments. These will represent "holes" in
    // the token trees that we create.
    if (pf->first_parsed_token_index < pf->last_parsed_token_index &&
        pf->raw_parent_entity &&
        pf->num_top_level_declarations == 1u) {
      
      const auto &tld = pf->top_level_decls.front();
      if (IsTemplateOrPattern(tld) ||
          IsMethodLexicallyInSpecialization(tld)) {
        nested_fragment_bounds.emplace_back(pf->Bounds());
      }
    }

    if (pf->is_new) {
      ++num_new;
    } else {
      pf.reset();  // We don't need it anymore.
    }
  }

  // Create an interval tree of the fragment bounds so that we can identify
  // what tokens belong to what nested fragments, so that we can exclude them
  // from token trees.
  em.nested_fragment_bounds = NestedFragmentIntervals(
      std::move(nested_fragment_bounds));

  DCHECK(em.nested_fragment_bounds.is_valid().first);
  CHECK(em.token_tree_ids.empty());

  DLOG(INFO)
      << "Main source file " << main_source_file
      << " has " << num_new << " / " << pending_fragments.size()
      << " unique fragments";

  fragment_ids.reserve(num_new);

  for (PendingFragmentPtr &pf : pending_fragments) {
    if (!pf) {
      continue;
    }

    auto start_time = std::chrono::system_clock::now();
    try {
      context.PersistFragment(ast, nm, provenance, *pf);
      context.PersistTypes(ast, nm, em, *pf);
      fragment_ids.push_back(pf->fragment_id);

    // NOTE(pag): To debug these, you should set a breakpoint on `__cxa_throw`.
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
          << "Fragment with ID " << pf->fragment_id.Pack()
          << PrefixedLocation(leader_decl, " at or near ")
          << " on main job file " << main_source_file
          << " took " << static_cast<uint64_t>(elapsed_time_s)
          << " seconds to persist";
    }

    pf.reset();  // Don't need it anymore.
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

  em.entity_ids.emplace(RawEntity(file), file_id.Pack());
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

  pasta::AST ast = std::move(maybe_ast.value());
  pasta::File main_file = ast.MainFile();
  std::string main_file_path = main_file.Path().generic_string();
  DLOG(INFO)
      << "Built AST for main source file " << main_file_path;

  TypeMapper tm(ast, context.id_store);
  EntityMapper em(tm, context.codegen.IsEnabled());

  PersistParsedFiles(context, ast, em);

  // Detect if this is a new compilation.
  auto [tu_id, is_new_tu_id] = context.id_store.GetOrCreateCompilationId(
      em.EntityId(main_file), HashCompilation(ast, em));

  if (!is_new_tu_id) {
    DLOG(INFO)
        << "Skipping redundant AST for main source file " << main_file_path;
    return;
  }

  NameMangler nm(ast, tu_id);

  PersistParsedFragments(
      context, compiler, job, ast, em, nm, tu_id,
      CreatePendingFragments(
          context, em, nm, ast, tu_id,
          PartitionEntities(context, ast, em)));
}

}  // namespace indexer
