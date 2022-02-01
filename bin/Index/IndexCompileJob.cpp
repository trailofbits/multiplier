// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "IndexCompileJob.h"

#include <glog/logging.h>
#include <map>
#include <pasta/AST/AST.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Token.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/File.h>

#include "Context.h"
#include "TokenizeFile.h"

#include <iostream>

namespace indexer {
namespace {

// Identify the indices in the token range that would tell us, via a
// `std::lower_bound`-type query, which file our given token is from.
// We need this so that we can figure out what file a top-level declaration
// belongs to.
static std::map<uint64_t, pasta::File> FindFileBounds(
    pasta::TokenRange token_range) {
  std::vector<pasta::File> file_stack;
  std::map<uint64_t, pasta::File> file_containing_lb;
  auto token_it = token_range.begin();
  auto token_end = token_range.end();
  for (; token_it != token_end; ++token_it) {
    pasta::Token token = *token_it;

    switch (token.Role()) {
      case pasta::TokenRole::kBeginOfFileMarker: {
        auto file_tok = token.FileLocation();
        CHECK(file_tok.has_value())
            << "Begin of file marker not associated with a file location";

        // If we're entering another file, then record this entry point as
        // an upper bound of the previous file.
        if (!file_stack.empty()) {
          file_containing_lb.emplace(token.Index(), file_stack.back());
        }

        file_stack.emplace_back(pasta::File::Containing(*file_tok));
        continue;
      }

      case pasta::TokenRole::kEndOfFileMarker: {
        auto file_tok = token.FileLocation();
        CHECK(file_tok.has_value())
            << "End of file marker not associated with a file location";
        CHECK(!file_stack.empty())
            << "Improper file stack nesting";
        CHECK(file_stack.back() == pasta::File::Containing(*file_tok))
            << "Improper file stack nesting";

        // If we're leaving a file, then record this entry point as
        // an upper bound of the previous file.
        file_containing_lb.emplace(token.Index(), file_stack.back());
        file_stack.pop_back();
        continue;
      }

      default:
        continue;
    }
  }

  return file_containing_lb;
}

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

static std::string DeclToString(const pasta::Decl &decl) {
  std::stringstream ss;
  auto sep = "";
  for (auto ptok : pasta::PrintedTokenRange::Create(decl)) {
    ss << sep << ptok.Data();
    sep = " ";
  }
  return ss.str();
}

// Find the range of tokens of this decl.
static std::pair<uint64_t, uint64_t> FindDeclRange(
    const pasta::TokenRange &range, pasta::Decl decl, pasta::Token tok,
    const std::map<uint64_t, pasta::File> &file_containing_lb) {

  auto decl_range = decl.TokenRange();
  auto begin_tok_index = tok.Index();
  auto end_tok_index = begin_tok_index;
  const auto max_tok_index = range.Size();
  if (decl_range.Size()) {
    begin_tok_index = decl_range.begin()->Index();
    end_tok_index = (--decl_range.end())->Index();
  }

  // Scan backwards to find more tokens in the context of this declaration.
  // We want to find the beginning of this declarations.
  while (begin_tok_index--) {
    tok = range[begin_tok_index];
    switch (tok.Role()) {
      case pasta::TokenRole::kBeginOfMacroExpansionMarker:
      case pasta::TokenRole::kMacroExpansionToken:
        continue;
      default:
        break;
    }

    if (!TokenIsInContextOfDecl(tok, decl)) {
      ++begin_tok_index;
      break;
    }
  }

  // Watch out for unsigned integer overflow on subtraction. This shouldn't
  // happen as we should hit a file begin token first, or perhaps a token
  // associated with a builtin type.
  CHECK_LT(begin_tok_index, max_tok_index);

  // Scan forwards to find more tokens in the context of this declaration. We
  // want to find the ending of this declarations.
  for (; end_tok_index < max_tok_index; ++end_tok_index) {
    tok = range[end_tok_index];
    switch (tok.Role()) {
      case pasta::TokenRole::kMacroExpansionToken:
      case pasta::TokenRole::kEndOfMacroExpansionMarker:
        continue;
      default:
        break;
    }

    if (mx::FromClang(tok.Kind()) == mx::TokenKind::TK_semi) {
      continue;
    } else if (!TokenIsInContextOfDecl(tok, decl)) {
      --end_tok_index;
      break;
    }
  }

  // We should always at least hit the end of file marker token first.
  CHECK_LT(end_tok_index, max_tok_index);

  // Now adjust for macros at the beginning and ending. If we find macro
  // expansion ranges, then the ranges returns
  tok = range[begin_tok_index];
  if (auto mr = tok.MacroExpandedTokens()) {
    begin_tok_index = mr.begin()->Index() - 1u;
  }

  // Now adjust for macros at the beginning and ending. If we find macro
  // expansion ranges, then the ranges returns
  tok = range[end_tok_index];
  if (auto mr = tok.MacroExpandedTokens()) {
    end_tok_index = mr.end()->Index();
  }

  if (begin_tok_index == end_tok_index) {
    // There should always be at least two tokens in any top-level decl.
    LOG(ERROR)
        << "Only found one token " << tok.Data() << " for: "
        << DeclToString(decl);
    return {begin_tok_index, end_tok_index};
  }

//    std::cerr
//        << "Looking for range of " << decl.KindName() << " token role "
//        << int(tok.Role()) << " data " << tok.Data() << '\n';
//
//    if (auto ft = tok.FileLocation()) {
//      auto f = pasta::File::Containing(*ft);
//      std::cerr
//          << '\t' << f.Path().generic_string() << ':' << ft->Line()
//          << ':' << ft->Column() << ": " << ft->Data() << '\n';
//    }
//
//    auto fi = file_containing_lb.lower_bound(begin_tok_index);
//    if (fi != file_containing_lb.end()) {
//      std::cerr
//          << '\t' << fi->second.Path().generic_string() << '\n';
//    }
//
//    for (auto rt : decl_range) {
//      std::cerr << "\trange tok: " << rt.Data() << '\n';
//    }
//
//    auto b = begin_tok_index;
//    auto e = begin_tok_index;
//    for (auto j = 0; b && j < 20; --b, ++j) { }
//    for (auto j = 0; e < max_tok_index && j < 20; ++e, ++j) { }
//
//    std::cerr << "\tFUDGE:\n";
//    for (auto i = b; i <= e; ++i) {
//      std::cerr << "\t\t" << range[i].Data() << " (" << TokenIsInContextOfDecl(range[i], decl) << ")\n";
//    }
//  }

  std::stringstream ss;
  auto ws = "";

  for (auto i = begin_tok_index; i <= end_tok_index; ++i) {
    tok = range[i];

    switch (tok.Role()) {
      case pasta::TokenRole::kInvalid:
      case pasta::TokenRole::kPrintedToken:
        LOG(FATAL)
            << "Invalid or unexpected tokens in range";
        break;

      case pasta::TokenRole::kBeginOfFileMarker:
      case pasta::TokenRole::kEndOfFileMarker:
      case pasta::TokenRole::kEndOfMacroExpansionMarker:
        continue;

      case pasta::TokenRole::kBeginOfMacroExpansionMarker: {
        auto macro_exp_toks = tok.MacroExpandedTokens();
        i = macro_exp_toks.end()->Index();
        for (auto ft : tok.MacroUseTokens()) {
          ss << ws << ft.Data();
          ws = " ";
        }
        continue;
      }

      case pasta::TokenRole::kFileToken: {
        ss << ws << tok.Data();
        ws = " ";
        break;
      }

      case pasta::TokenRole::kMacroExpansionToken:
        LOG(ERROR)
            << "Macro token " << tok.KindName() << ": " << tok.Data()
            << " not properly nested";
        break;
    }
  }

//  std::cerr
//      << "!!!------------------------------------------------------\n"
//      << ss.str() << "\n\n\n";

  return {begin_tok_index, end_tok_index};
}

}  // namespace

IndexCompileJobAction::~IndexCompileJobAction(void) {}

IndexCompileJobAction::IndexCompileJobAction(
    std::shared_ptr<UpdateContext> context_, pasta::CompileJob job_)
    : context(std::move(context_)),
      progress(context->ast_progress),
      job(std::move(job_)) {}

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

// Build and index the AST.
void IndexCompileJobAction::Run(mx::Executor exe, mx::WorkerId worker_id) {
  auto maybe_ast = job.Run();
  if (!maybe_ast.Succeeded()) {
    LOG(ERROR)
        << "Error building AST for command " << job.Arguments().Join()
        << "; error was: " << maybe_ast.TakeError();
    return;
  }

  auto ast = maybe_ast.TakeValue();
  for (pasta::File file : ast.ParsedFiles()) {
    MaybeTokenizeFile(exe, std::move(file));
  }

  // TODO(pag): Handle top-level statements, e.g. asm.
  auto tok_range = ast.Tokens();
  auto file_containing_lb = FindFileBounds(tok_range);
  auto tlds = FindTLDs(ast.TranslationUnit());
  for (pasta::Decl decl : tlds) {
    auto tok = decl.Token();

    // These are probably part of the preamble of compiler-provided builtin
    // declarations.
    if (!tok) {
      LOG(WARNING)
          << "Could not find location of: " << DeclToString(decl);

    } else if (!TokenIsInContextOfDecl(tok, decl)) {
      LOG(ERROR)
          << "Could not find location of: " << DeclToString(decl);

    } else {
      FindDeclRange(tok_range, decl, tok, file_containing_lb);
    }
  }
}

}  // namespace indexer
