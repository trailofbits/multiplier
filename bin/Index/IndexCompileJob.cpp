// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "IndexCompileJob.h"

#include <algorithm>
#include <glog/logging.h>
#include <multiplier/TokenTree.h>
#include <pasta/AST/AST.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Token.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/File.h>
#include <tuple>
#include <vector>

#include "Context.h"
#include "TokenizeFile.h"


namespace indexer {
namespace {

// Find all top-level declarations.
class TLDFinder final : public pasta::DeclVisitor {
 private:
  std::vector<pasta::Decl> &tlds;

 public:
  virtual ~TLDFinder(void) = default;

  explicit TLDFinder(std::vector<pasta::Decl> &tlds_)
      : tlds(tlds_) {}


  void VisitDeclContext(const pasta::DeclContext &dc) {;
    for (const auto &decl : dc.AlreadyLoadedDeclarations()) {
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

  void VisitDecl(const pasta::Decl &decl) final {
    tlds.emplace_back(decl);
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
  for (auto context = tok.Context(); context; context = context->Parent()) {
    if (auto maybe_decl = pasta::Decl::From(*context)) {
      if (maybe_decl->CanonicalDeclaration() ==
          decl.CanonicalDeclaration()) {
        return true;
      }
    }
  }
  return false;
}

// Print a declaration; useful for error reporting.
static std::string DeclToString(const pasta::Decl &decl) {
  std::stringstream ss;
  auto sep = "";
  for (auto ptok : pasta::PrintedTokenRange::Create(decl)) {
    ss << sep << ptok.Data();
    sep = " ";
  }
  return ss.str();
}

// Return the name of a declaration with a leading `prefix`, or nothing.
static std::string PrefixedName(const pasta::Decl &decl,
                                const char *prefix=" ") {
  if (auto nd = pasta::NamedDecl::From(decl)) {
    auto name = nd->Name();
    if (!name.empty()) {
      return prefix + name;
    }
  }
  return "";
}

// Return the location of a declaration with a leading `prefix`, or nothing.
static std::string PrefixedLocation(const pasta::Decl &decl,
                                    const char *prefix=" ") {
  auto ft = decl.Token().FileLocation();
  if (!ft) {
    for (auto tok : decl.TokenRange()) {
      ft = decl.Token().FileLocation();
      if (ft) {
        break;
      }
    }
  }
  if (ft) {
    auto file = pasta::File::Containing(*ft);
    std::stringstream ss;
    ss << prefix << file.Path().generic_string()
       << ':' << ft->Line() << ':' << ft->Column();
    return ss.str();
  }
  return "";
}

// Returns `true` if `data` contains only whitespace or is empty.
static bool IsWhitespaceOrEmpty(std::string_view data) {
  for (auto ch : data) {
    switch (ch) {
      case ' ': case '\t': case '\r': case '\n': case '\\':
        continue;
      default:
        return false;
    }
  }
  return true;
}

// Can we elide this token from the beginning or end of a top-level
// declaration's range of tokens?
static bool CanElidTokenFromTLD(pasta::Token tok) {
  switch (tok.Role()) {
    case pasta::TokenRole::kBeginOfFileMarker:
    case pasta::TokenRole::kEndOfFileMarker:
      return true;

    case pasta::TokenRole::kFileToken:
      switch (mx::FromClang(tok.Kind())) {
        case mx::TokenKind::TK_comment:
        case mx::TokenKind::TK_eof:
        case mx::TokenKind::TK_eod:
        case mx::TokenKind::TK_code_completion:
          return true;
        case mx::TokenKind::TK_whitespace:
        case mx::TokenKind::TK_unknown:
          return IsWhitespaceOrEmpty(tok.Data());
        default:
          return false;
      }
    default:
      return false;
  }
}

// Do some minor stuff to find begin/ending tokens.
static std::pair<uint64_t, uint64_t> BaselineDeclRange(
    const pasta::Decl &decl, pasta::Token tok) {
  auto decl_range = decl.TokenRange();
  auto begin_tok_index = tok.Index();
  auto end_tok_index = begin_tok_index;

  if (decl_range.Size()) {
    begin_tok_index = std::min(begin_tok_index, decl_range.begin()->Index());
    end_tok_index = std::max(end_tok_index, (--decl_range.end())->Index());
  }

  if (auto td = pasta::TagDecl::From(decl)) {
    if (auto tt = td->OuterTokenStart()) {
      begin_tok_index = std::min(begin_tok_index, tt.Index());
      end_tok_index = std::max(end_tok_index, tt.Index());
    }
    if (auto tt = td->InnerTokenStart()) {
      begin_tok_index = std::min(begin_tok_index, tt.Index());
      end_tok_index = std::max(end_tok_index, tt.Index());
    }
  }

  if (auto nd = pasta::NamedDecl::From(decl)) {
    if (auto tt = nd->BeginToken()) {
      begin_tok_index = std::min(begin_tok_index, tt.Index());
      end_tok_index = std::max(end_tok_index, tt.Index());
    }
    if (auto tt = nd->EndToken()) {
      begin_tok_index = std::min(begin_tok_index, tt.Index());
      end_tok_index = std::max(end_tok_index, tt.Index());
    }
  }

  return {begin_tok_index, end_tok_index};
}

// Find the range of tokens of this decl.
static std::pair<uint64_t, uint64_t> FindDeclRange(
    const pasta::TokenRange &range, pasta::Decl decl, pasta::Token tok) {

  auto [begin_tok_index, end_tok_index] = BaselineDeclRange(decl, tok);

  const auto max_tok_index = range.Size();

  // Scan backwards to find more tokens in the context of this declaration.
  // We want to find the beginning of this declarations.
  while (begin_tok_index--) {
    tok = range[begin_tok_index];
    switch (tok.Role()) {
      case pasta::TokenRole::kBeginOfMacroExpansionMarker:
      case pasta::TokenRole::kMacroExpansionToken:
        continue;
      case pasta::TokenRole::kBeginOfFileMarker:
        goto exclude_begin_tok;
      default:
        break;
    }

    if (TokenIsInContextOfDecl(tok, decl)) {
      continue;
    }

  exclude_begin_tok:
    ++begin_tok_index;
    break;
  }

  // Watch out for unsigned integer overflow on subtraction. This shouldn't
  // happen as we should hit a file begin token first, or perhaps a token
  // associated with a builtin type.
  CHECK_LT(begin_tok_index, max_tok_index);

  // Scan forwards to find more tokens in the context of this declaration. We
  // want to find the ending of this declarations.
  for (; (end_tok_index + 1u) < max_tok_index;) {
    tok = range[++end_tok_index];
    switch (tok.Role()) {
      case pasta::TokenRole::kMacroExpansionToken:
      case pasta::TokenRole::kEndOfMacroExpansionMarker:
        continue;
      case pasta::TokenRole::kEndOfFileMarker:
        goto exclude_end_tok;
      default:
        break;
    }

    if (mx::FromClang(tok.Kind()) == mx::TokenKind::TK_semi ||
        TokenIsInContextOfDecl(tok, decl)) {
      continue;
    }

  exclude_end_tok:
    --end_tok_index;
    break;
  }

  // We should always at least hit the end of file marker token first.
  CHECK_LT(end_tok_index, max_tok_index);

  // Now adjust for macros at the beginning and ending. If we find macro
  // expansion ranges, then the ranges returns
  tok = range[begin_tok_index];
  while (tok.Role() == pasta::TokenRole::kMacroExpansionToken) {
    tok = range[--begin_tok_index];
  }

  // Now adjust for macros at the beginning and ending. If we find macro
  // expansion ranges, then the ranges returns
  tok = range[end_tok_index];
  while (tok.Role() == pasta::TokenRole::kMacroExpansionToken) {
    tok = range[++end_tok_index];
  }

  // Strip leading whitespace and comments.
  while (begin_tok_index < end_tok_index &&
         CanElidTokenFromTLD(range[begin_tok_index])) {
    ++begin_tok_index;
  }

  // Strip trailing whitespace and comments.
  while (end_tok_index > begin_tok_index &&
         CanElidTokenFromTLD(range[end_tok_index])) {
    --end_tok_index;
  }

  // Add in trailing semicolons.
  if ((end_tok_index + 1u) < max_tok_index) {
    auto tok_after_end = range[end_tok_index + 1u];
    if(tok_after_end.Role() == pasta::TokenRole::kFileToken &&
       (mx::FromClang(tok_after_end.Kind()) == mx::TokenKind::TK_semi)) {
      ++end_tok_index;
    }
  }

  return {begin_tok_index, end_tok_index};
}

// Returns `true` if `decl` is probably a compiler-built-in declaration. It's
// not possible to get location information for these, unless we first printed
// out the compiler builtins to a file and then introduced those as a special
// preamble.
static bool IsProbablyABuiltinDecl(const pasta::Decl &decl) {
  if (auto nd = pasta::NamedDecl::From(decl)) {
    if (nd->Name().starts_with("__")) {
      return true;
    }
  }
  return false;
}

}  // namespace

IndexCompileJobAction::~IndexCompileJobAction(void) {}

IndexCompileJobAction::IndexCompileJobAction(
    std::shared_ptr<UpdateContext> context_, pasta::CompileJob job_)
    : context(std::move(context_)),
      progress(context->ast_progress),
      job(std::move(job_)) {}

// Look through all files referenced by the AST get their unique IDs. If this
// is the first time seeing a file, then tokenize the file.
void IndexCompileJobAction::MaybeTokenizeFile(
    const mx::Executor &exe, pasta::File file) {
  if (file.WasParsed()) {
    auto [file_id, is_new_file_id] = context->AddFileToSet(
        file.Path().generic_string());
    if (is_new_file_id) {
      exe.EmplaceAction<TokenizeFileAction>(context, file_id, std::move(file));
    }
    file_ids.emplace(file, file_id);
  }
}

//// Identify the indices in the token range that would tell us, via a
//// `std::lower_bound`-type query, which file our given token is from.
//// We need this so that we can figure out what file a top-level declaration
//// belongs to.
//void IndexCompileJobAction::FindFileBounds(pasta::TokenRange token_range) {
//  std::vector<pasta::File> file_stack;
//  auto token_it = token_range.begin();
//  auto token_end = token_range.end();
//  for (; token_it != token_end; ++token_it) {
//    pasta::Token token = *token_it;
//
//    switch (token.Role()) {
//      case pasta::TokenRole::kBeginOfFileMarker: {
//        auto file_tok = token.FileLocation();
//        CHECK(file_tok.has_value())
//            << "Begin of file marker not associated with a file location";
//
//        // If we're entering another file, then record this entry point as
//        // an upper bound of the previous file.
//        if (!file_stack.empty()) {
//          file_containing_lb.emplace(token.Index(), file_stack.back());
//        }
//
//        file_stack.emplace_back(pasta::File::Containing(*file_tok));
//        continue;
//      }
//
//      case pasta::TokenRole::kEndOfFileMarker: {
//        auto file_tok = token.FileLocation();
//        CHECK(file_tok.has_value())
//            << "End of file marker not associated with a file location";
//        CHECK(!file_stack.empty())
//            << "Improper file stack nesting";
//        CHECK(file_stack.back() == pasta::File::Containing(*file_tok))
//            << "Improper file stack nesting";
//
//        // If we're leaving a file, then record this entry point as
//        // an upper bound of the previous file.
//        file_containing_lb.emplace(token.Index(), file_stack.back());
//        file_stack.pop_back();
//        continue;
//      }
//
//      default:
//        continue;
//    }
//  }
//}

// Build and index the AST.
void IndexCompileJobAction::Run(mx::Executor exe, mx::WorkerId worker_id) {
  auto main_file_path = job.SourceFile().Path().generic_string();
  auto maybe_ast = job.Run();
  if (!maybe_ast.Succeeded()) {
    LOG(ERROR)
        << "Error building AST for command " << job.Arguments().Join()
        << " on main file " << main_file_path
        << "; error was: " << maybe_ast.TakeError();
    return;
  }

  auto ast = maybe_ast.TakeValue();
  for (pasta::File file : ast.ParsedFiles()) {
    MaybeTokenizeFile(exe, std::move(file));
  }

//  FindFileBounds(tok_range);

  using DeclRange = std::tuple<pasta::Decl, uint64_t, uint64_t>;
  std::vector<DeclRange> decl_ranges;

  // TODO(pag): Handle top-level statements, e.g. asm.
  pasta::TokenRange tok_range = ast.Tokens();
  auto tlds = FindTLDs(ast.TranslationUnit());
  for (pasta::Decl decl : tlds) {
    if (decl.Kind() == pasta::DeclKind::kEmpty) {
      continue;
    }

    auto tok = decl.Token();

    // These are probably part of the preamble of compiler-provided builtin
    // declarations.
    if (!tok) {
      LOG_IF(WARNING, !IsProbablyABuiltinDecl(decl))
          << "Could not find location of " << decl.KindName()
          << " declaration: " << DeclToString(decl)
          << PrefixedLocation(decl, " at or near ")
          << " on main job file " << main_file_path;

    } else if (!TokenIsInContextOfDecl(tok, decl)) {
      LOG_IF(ERROR, !IsProbablyABuiltinDecl(decl))
          << "Could not find location of " << decl.KindName()
          << " declaration: " << DeclToString(decl)
          << PrefixedLocation(decl, " at or near ")
          << " on main job file " << main_file_path;

    } else {
      auto [begin_index, end_index] = FindDeclRange(tok_range, decl, tok);

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

  std::vector<pasta::Decl> tlds_for_tree;
  for (size_t i = 0u, max_i = decl_ranges.size(); i < max_i; ) {
    auto [decl, begin_index, end_index] = std::move(decl_ranges[i++]);
    tlds_for_tree.clear();
    tlds_for_tree.push_back(decl);
    while (i < max_i) {
      if (std::get<1>(decl_ranges[i]) <= end_index) {
        auto next_decl = std::get<0>(decl_ranges[i]);

        if (next_decl == decl) {
          DLOG(WARNING)
              << "Declaration of " << decl.KindName()
              << PrefixedName(decl) << PrefixedLocation(decl, " at or near ")
              << " is repeated in top-level decl list for job on file "
              << " on main job file " << main_file_path;
        } else {
//          DLOG(INFO)
//              << "Declaration of " << decl.KindName()
//              << PrefixedName(decl) << PrefixedLocation(decl, " at or near ")
//              << " encloses over subsequent "
//              << next_decl.KindName() << PrefixedName(next_decl) << " declaration"
//              << PrefixedName(next_decl)
//              << PrefixedLocation(next_decl, " at or near ")
//              << " on main job file " << main_file_path;

          // Keep track of enclosed decls.
          tlds_for_tree.push_back(std::move(next_decl));
        }

        // Make sure we definitely enclose over the next decl.
        end_index = std::max(end_index, std::get<2>(decl_ranges[i]));

        // Consume the next decl.
        ++i;
        continue;

      // Doesn't close over.
      } else {
        break;
      }
    }

    mx::Result<mx::TokenTree, std::string> maybe_tt = mx::TokenTree::Create(
        tok_range, begin_index, end_index);
    if (maybe_tt.Succeeded()) {

    } else {
      LOG(ERROR)
          << maybe_tt.TakeError() << " for top-level declaration "
          << DeclToString(decl) << PrefixedLocation(decl, " at or near ")
          << " on main job file " << main_file_path;
    }
  }
}

}  // namespace indexer
