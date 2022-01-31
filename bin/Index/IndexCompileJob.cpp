// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "IndexCompileJob.h"

#include <glog/logging.h>
#include <pasta/AST/AST.h>
#include <pasta/AST/Token.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/File.h>

#include "Context.h"
#include "TokenizeFile.h"

namespace indexer {

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

  std::vector<pasta::File> file_stack;

  auto token_range = ast.Tokens();
  auto token_it = token_range.begin();
  auto token_end = token_range.end();
  for (; token_it != token_end; ++token_it) {
    pasta::Token token = *token_it;

    switch (token.Role()) {
      case pasta::TokenRole::kInvalid:
      case pasta::TokenRole::kPrintedToken:
        LOG(FATAL)
            << "Invalid or unexpected tokens in range";
        break;

      case pasta::TokenRole::kBeginOfFileMarker: {
        auto file_tok = token.FileLocation();
        LOG_IF(FATAL, !file_tok)
            << "Begin of file marker not associated with a file location";
        file_stack.emplace_back(pasta::File::Containing(*file_tok));
        continue;
      }

      case pasta::TokenRole::kEndOfFileMarker: {
        auto file_tok = token.FileLocation();
        LOG_IF(FATAL, !file_tok)
            << "End of file marker not associated with a file location";
        LOG_IF(FATAL, file_stack.empty())
            << "Improper file stack nesting";
        CHECK(file_stack.back() == pasta::File::Containing(*file_tok))
            << "Improper file stack nesting";
        file_stack.pop_back();
        continue;
      }

      case pasta::TokenRole::kEndOfMacroExpansionMarker:
        continue;

      case pasta::TokenRole::kBeginOfMacroExpansionMarker: {
        auto macro_exp_toks = token.MacroExpandedTokens();
        auto macro_use_toks = token.MacroUseTokens();
        CHECK_LE(1u, macro_use_toks.Size())
            << "??? " << macro_use_toks.end()->Data();
        token_it = macro_exp_toks.end();  // Skip over it.

//        std::stringstream ss;
//        for (auto ft : macro_use_toks) {
//          ss << ft.Data();
//        }
//
//        ss << "   >>>>>   ";
//        for (auto et : macro_exp_toks) {
//          ss << et.Data();
//        }
//
//        LOG(ERROR) << "!!! " << ss.str();

        break;
      }

      case pasta::TokenRole::kFileToken: {
        auto file_tok = token.FileLocation();
        LOG_IF(FATAL, !file_tok)
            << "Token with file token role not associated with parsed file";
        break;
      }

      case pasta::TokenRole::kMacroExpansionToken:
        LOG(ERROR)
            << "Macro token " << token.KindName() << ": " << token.Data()
            << " not properly nested; top-level file is "
            << file_stack.front().Path().generic_string();
        break;
    }
  }
}

}  // namespace indexer
