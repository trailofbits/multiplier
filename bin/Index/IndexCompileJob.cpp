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
#include <multiplier/AST.h>
#include <multiplier/AST.capnp.h>
#include <multiplier/RPC.capnp.h>
#include <multiplier/Types.h>
#include <pasta/AST/AST.h>
#include <pasta/AST/Printer.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/File.h>
#include <tuple>
#include <unordered_set>
#include <vector>

#include "Context.h"
#include "Database.h"
#include "Hash.h"
#include "NameMangler.h"
#include "PrintTokenGraph.h"
#include "PendingFragment.h"
#include "Persist.h"
#include "Util.h"

namespace indexer {

struct EntityIdMap;
struct FileIdMap;
struct TypeIdMap;
class PendingFragment;
struct PseudoOffsetMap;

namespace {

// A declaration, the index of the first token to be saved associated with
// the decl, and the (inclusive) index of the last token associated with
// this token.
using DeclRange = std::tuple<pasta::Decl, uint64_t, uint64_t>;

// A group of declarations with overlapping `DeclRange`s, along with the
// minimum and maximum (inclusive) indices of the tokens.
using DeclGroupRange = std::tuple<std::vector<pasta::Decl>, uint64_t, uint64_t>;

// Find all top-level declarations.
class TLDFinder final : public pasta::DeclVisitor {
 private:
  std::vector<pasta::Decl> &tlds;

  // Tracks declarations for which we've seen the specializations. This is
  // to prevent us from double-adding specializations.
  std::unordered_set<pasta::Decl> seen_specs;

 public:
  virtual ~TLDFinder(void) = default;

  explicit TLDFinder(std::vector<pasta::Decl> &tlds_)
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
    if (!decl.IsImplicit()) {
      tlds.emplace_back(decl);
    }
  }
};

// Find all top-level declarations.
static std::vector<pasta::Decl> FindTLDs(pasta::TranslationUnitDecl tu) {
  std::vector<pasta::Decl> tlds;
  TLDFinder tld_finder(tlds);
  tld_finder.VisitTranslationUnitDecl(tu);
  return tlds;
}

// Return `true` of `tok` is in the context of `decl`.
static bool TokenIsInContextOfDecl(const pasta::Token &tok,
                                   const pasta::Decl &decl) {
  auto cdecl = decl.CanonicalDeclaration();
  for (auto context = tok.Context(); context; context = context->Parent()) {
    if (auto maybe_decl = pasta::Decl::From(*context)) {
      if (*maybe_decl == cdecl) {
        return true;
      } else if (pasta::ClassTemplateSpecializationDecl::From(*maybe_decl) ||
                 pasta::VarTemplateSpecializationDecl::From(*maybe_decl) ||
                 pasta::ClassScopeFunctionSpecializationDecl::From(*maybe_decl)) {
        return true;
      }
    } else if (auto maybe_type = pasta::Type::From(*context)) {
      if (pasta::TemplateSpecializationType::From(*maybe_type) ||
          pasta::ElaboratedType::From(*maybe_type)) {
        return true;
      }
    } else if (context->Kind() == pasta::TokenContextKind::kTemplateArgument ||
               context->Kind() == pasta::TokenContextKind::kTemplateParameterList) {
      return true;
    }
  }
  return false;
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
    case pasta::TokenRole::kIntermediateMacroExpansionToken:
    case pasta::TokenRole::kFinalMacroExpansionToken:
      return false;
  }
  return false;
}

// Do some minor stuff to find begin/ending tokens.
static std::pair<uint64_t, uint64_t> BaselineDeclRange(
    const pasta::Decl &decl, pasta::Token tok, std::string_view main_file_path) {
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

// Find the range of tokens of this decl. The range is returned as an inclusive
// [begin_index, end_index]` pair, and is expanded to cover leading/trailing
// macro expansions, and contracted to try to elide leading/trailing whitespace.
static std::pair<uint64_t, uint64_t> FindDeclRange(
    const pasta::TokenRange &range, pasta::Decl decl, pasta::Token tok,
    std::string_view main_file_path) {

  auto [begin_tok_index, end_tok_index] = BaselineDeclRange(decl, tok,
                                                            main_file_path);

  const auto max_tok_index = range.Size();

  // We should always at least hit the end of file marker token first.
  CHECK_LT(end_tok_index, max_tok_index);

  // Now adjust for macros at the beginning and ending. If we find macro
  // expansion ranges, then the expand until we find the beginning of the
  // range.
  bool done = false;
  while (!done && 0u < begin_tok_index && begin_tok_index < end_tok_index) {
    tok = range[begin_tok_index];
    switch (tok.Role()) {
      case pasta::TokenRole::kInvalid:
        assert(false);
        done = true;
        break;
      case pasta::TokenRole::kFileToken:
        if (CanElideTokenFromTLD(tok)) {
          ++begin_tok_index;
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
        ++begin_tok_index;
        break;
      case pasta::TokenRole::kIntermediateMacroExpansionToken:
      case pasta::TokenRole::kFinalMacroExpansionToken:
        --begin_tok_index;
        break;
    }
  }

  done = false;
  while (!done && 0u < end_tok_index && end_tok_index < max_tok_index) {
    tok = range[end_tok_index];
    switch (tok.Role()) {
      case pasta::TokenRole::kInvalid:
        assert(false);
        --end_tok_index;
        break;
      case pasta::TokenRole::kFileToken:
        if (CanElideTokenFromTLD(tok)) {
          --end_tok_index;
        } else {
          done = true;
        }
        break;
      case pasta::TokenRole::kEndOfMacroExpansionMarker:
        done = true;
        break;
      case pasta::TokenRole::kBeginOfMacroExpansionMarker:
      case pasta::TokenRole::kBeginOfFileMarker:
      case pasta::TokenRole::kEndOfFileMarker:
        --end_tok_index;
        break;
      case pasta::TokenRole::kIntermediateMacroExpansionToken:
      case pasta::TokenRole::kFinalMacroExpansionToken:
        ++end_tok_index;
        break;
    }
  }

  return {begin_tok_index, end_tok_index};
}

// Returns `true` if `decl` is probably a compiler-built-in declaration. It's
// not possible to get location information for these, unless we first printed
// out the compiler builtins to a file and then introduced those as a special
// preamble.
static bool IsProbablyABuiltinDecl(const pasta::Decl &decl) {
  if (decl.IsImplicit()) {
    return true;
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

// Sort the top-level declarations so that syntactically overlapping
// declarations are in the correct order, and are side-by-side in the output
// vector.
static std::vector<DeclRange> SortTLDs(pasta::TokenRange tok_range,
                                       std::string_view main_file_path,
                                       std::vector<pasta::Decl> tlds) {
  std::vector<DeclRange> decl_ranges;
  decl_ranges.reserve(8192u);

  for (pasta::Decl decl : tlds) {
    if (decl.Kind() == pasta::DeclKind::kEmpty) {
      continue;
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

    } else {

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

      auto [begin_index, end_index] = FindDeclRange(tok_range, decl, tok,
                                                    main_file_path);

      // There should always be at least two tokens in any top-level decl.
      LOG_IF(ERROR, begin_index == end_index)
          << "Only found one token " << tok.Data() << " for: "
          << DeclToString(decl) << PrefixedLocation(decl, " at or near ")
          << " on main job file " << main_file_path;

      decl_ranges.emplace_back(decl, begin_index, end_index);
    }
  }

  // It's possible that we have two-or-more things that appear to be top-level
  // decls, but really we're only dealing with one top-level decl. This happens
  // with things like `typedef`s in Clang when the referenced type of a typedef
  // is defined within the typedef (e.g. a union/struct/enum type). In these
  // cases, Clang places the definition of the referenced type before the
  // typedef inside of the `DeclContext`, and so the referenced type appears
  // as its own top-level declaration, despite it being logically nested inside
  // of another top-level declaration.

  std::stable_sort(decl_ranges.begin(), decl_ranges.end(),
                   [] (const DeclRange &a, const DeclRange &b) {
                     auto a_begin = std::get<1>(a);
                     auto b_begin = std::get<1>(b);
                     if (a_begin < b_begin) {
                       return true;
                     } else if (a_begin > b_begin) {
                       return false;
                     } else {
                       return std::get<2>(a) < std::get<2>(b);
                     }
                   });

  return decl_ranges;
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
static std::vector<DeclGroupRange> PartitionTLDs(
    mx::ProgressBar *partition_progress_bar, std::string_view main_file_path,
    const pasta::AST &ast) {

  mx::ProgressBarWork partitioning_progress_tracker(partition_progress_bar);

  std::vector<DeclRange> decl_ranges = SortTLDs(
      ast.Tokens(), main_file_path, FindTLDs(ast.TranslationUnit()));

  std::vector<DeclGroupRange> decl_group_ranges;
  decl_group_ranges.reserve(decl_ranges.size());

  for (size_t i = 0u, max_i = decl_ranges.size(); i < max_i; ) {
    DeclRange range = std::move(decl_ranges[i++]);
    pasta::Decl decl = std::move(std::get<0u>(range));
    uint64_t begin_index = std::get<1u>(range);
    uint64_t end_index = std::get<2u>(range);
    size_t num_errors = StatementsHaveErrors(decl);

    std::vector<pasta::Decl> decls_for_group;
    decls_for_group.push_back(decl);

    for (; i < max_i; ++i) {
      if (std::get<1>(decl_ranges[i]) <= end_index) {
        auto next_decl = std::get<0>(decl_ranges[i]);
        auto next_end = std::get<2>(decl_ranges[i]);

        if (next_decl == decl) {
          DLOG(FATAL)
              << "Declaration of " << decl.KindName()
              << PrefixedName(decl) << PrefixedLocation(decl, " at or near ")
              << " is repeated in top-level decl list for job on file "
              << " on main job file " << main_file_path;
        } else {
          num_errors += StatementsHaveErrors(next_decl);
          decls_for_group.push_back(std::move(next_decl));
        }

        // Make sure we definitely enclose over the next decl.
        end_index = std::max(end_index, next_end);

      // Doesn't close over.
      } else {
        break;
      }
    }

    CHECK_EQ(num_errors, 0u);

    decl_group_ranges.emplace_back(
        std::move(decls_for_group), begin_index, end_index);
  }

  return decl_group_ranges;
}

// Create fragments in reverse order that we see them in the AST. The hope
// is that this will reduce contention in trying to create fragment IDs for
// the redundant declarations that are likely to appear early in ASTs, i.e.
// in `#include`d headers.
static std::vector<PendingFragment> CreatePendingFragments(
    mx::ProgressBar *identification_progress_bar, mx::WorkerId worker_id,
    IndexingContext &context, EntityIdMap &entity_ids, FileHashMap &file_hashes,
    const pasta::TokenRange &tok_range,
    std::vector<DeclGroupRange> decl_group_ranges) {

  mx::ProgressBarWork identification_progress_tracker(
      identification_progress_bar);

  std::vector<PendingFragment> pending_fragments;
  pending_fragments.reserve(decl_group_ranges.size());

  for (std::vector<DeclGroupRange>::reverse_iterator
		  it = decl_group_ranges.rbegin(), end = decl_group_ranges.rend();
       it != end; ++it) {

	DeclGroupRange &group = *it;
    std::vector<pasta::Decl> decls_for_group = std::move(std::get<0u>(group));
    uint64_t begin_index = std::get<1u>(group);
    uint64_t end_index = std::get<2u>(group);

    IndexingCounterRes chunk_counter(context.stat, kStatCodeFragment);

    // Don't create token `decls_for_chunk` if the decl is already seen. This
    // means it's already been indexed.
    auto [code_id, is_new] = context.GetOrCreateFragmentId(
        worker_id,
        CodeHash(file_hashes, decls_for_group, tok_range,
                 begin_index, end_index),
        end_index - begin_index + 1u);

    PendingFragment pending_fragment;
    pending_fragment.fragment_id = code_id;
    pending_fragment.decls = std::move(decls_for_group);
    pending_fragment.begin_index = begin_index;
    pending_fragment.end_index = end_index;

    // We always need to label the entities inside of a fragment, regardless of
    // if fragment `is_new`. This is because each fragment might have arbitrary
    // references to other declarations. We need to be able to form cross-
    // fragment references when serializing things, so we use the labeller to
    // assign IDs to entities (decls, statements, etc.) in a uniform and
    // deterministic way so that other threads doing similar indexing will form
    // identically labelled chunks for the same logical entities.
    //
    // Unfortunately, the labeller needs to be manually written as opposed to
    // auto-generated, as our auto-generation has no concept of which AST
    // methods descend vs. cross the tree (into other fragments).
    pending_fragment.Label(entity_ids, tok_range);
    if (is_new) {
      pending_fragments.emplace_back(std::move(pending_fragment));
    }
  }

  return pending_fragments;
}

}  // namespace

IndexCompileJobAction::~IndexCompileJobAction(void) {}

IndexCompileJobAction::IndexCompileJobAction(
    std::shared_ptr<IndexingContext> context_,
    pasta::FileManager file_manager_,
    pasta::CompileJob job_)
    : context(std::move(context_)),
      file_manager(std::move(file_manager_)),
      job(std::move(job_)) {}

// Look through all files referenced by the AST get their unique IDs. If this
// is the first time seeing a file, then tokenize the file.
void IndexCompileJobAction::MaybePersistFile(
    mx::WorkerId worker_id, pasta::File file) {
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

  std::string file_hash = FileHash(maybe_data.TakeValue());
  auto [file_id, is_new_file_id] = context->GetOrCreateFileId(
      worker_id, file_path, file_hash);
  if (is_new_file_id) {
    PersistFile(*context, file_id, file_hash, file);
  }

  file_ids.emplace(file, file_id);
  file_hashes.emplace(std::move(file), std::move(file_hash));
}

void IndexCompileJobAction::PersistParsedFiles(const pasta::AST &ast,
                                               mx::WorkerId worker_id) {
  mx::ProgressBarWork progress_tracker(context->file_progress.get());
  auto parsed_files = ast.ParsedFiles();
  for (auto it = parsed_files.rbegin(), end = parsed_files.rend();
       it != end; ++it) {
    const pasta::File &parsed_file = *it;
    MaybePersistFile(worker_id, parsed_file);
  }
}

// Build and index the AST.
void IndexCompileJobAction::Run(mx::Executor, mx::WorkerId worker_id) {
  std::optional<mx::ProgressBarWork> parsing_progress_tracker(
      context->ast_progress.get());
  IndexingCounterRes cj_counter(context->stat, kStatCompileJob);

  std::string main_file_path =
      job.SourceFile().Path().lexically_normal().generic_string();
  pasta::Result<pasta::AST, std::string> maybe_ast = job.Run();
  if (!maybe_ast.Succeeded()) {
    LOG(ERROR)
        << "Error building AST for command " << job.Arguments().Join()
        << " on main file " << main_file_path
        << "; error was: " << maybe_ast.TakeError();
    return;
  }

  IndexingCounterRes ast_counter(context->stat, kStatAST);
  pasta::AST ast = maybe_ast.TakeValue();
  parsing_progress_tracker.reset();
  PersistParsedFiles(ast, worker_id);

  std::vector<DeclGroupRange> decl_group_ranges = PartitionTLDs(
      context->partitioning_progress.get(), main_file_path, ast);

  pasta::TokenRange tok_range = ast.Tokens();

  EntityIdMap entity_ids;

  std::vector<PendingFragment> pending_fragments = CreatePendingFragments(
      context->identification_progress.get(), worker_id, *context,
      entity_ids, file_hashes, tok_range, std::move(decl_group_ranges));

  // Serialize the new code chunks.
  mx::ProgressBarWork fragment_progress_tracker(
      context->serialization_progress.get());

  NameMangler mangler(ast);

  for (PendingFragment &pending_fragment : pending_fragments) {
    PersistFragment(*context, ast, mangler, entity_ids, file_ids, tok_range,
                    std::move(pending_fragment));
  }
}

}  // namespace indexer
