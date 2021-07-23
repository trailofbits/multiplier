/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "astgenerator.h"

#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/FileSystem.h>
#include <pasta/Util/Init.h>

#include <cstdlib>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

namespace {

class ASTDumper final : public pasta::DeclVisitor {
public:
  virtual ~ASTDumper(void) = default;

  explicit ASTDumper(const pasta::AST &ast_, std::stringstream &output_)
      : ast(ast_), output(output_) {}

  pasta::AST ast;
  std::string indent;
  std::stringstream &output;

  void PushIndent(void) { indent += "  "; }

  void PopIndent(void) { indent.resize(indent.size() - 2); }

  void VisitDeclContext(const pasta::DeclContext &dc) {
    output << " {\n";
    PushIndent();
    for (const auto &decl : dc.AlreadyLoadedDecls()) {
      Accept(decl);
    }
    PopIndent();
    output << indent << "}\n";
  }

  void VisitTranslationUnitDecl(const pasta::TranslationUnitDecl &decl) final {
    output << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitNamespaceDecl(const pasta::NamespaceDecl &decl) final {
    output << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitExternCContextDecl(const pasta::ExternCContextDecl &decl) final {
    output << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitLinkageSpecDecl(const pasta::LinkageSpecDecl &decl) final {
    output << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final {
    output << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitTagDecl(const pasta::TagDecl &decl) final {
    output << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitTypedefDecl(const pasta::TypedefDecl &decl) final {
    output << indent << decl.KindName() << "\n";
  }

  void VisitDecl(const pasta::Decl &decl) final { output << indent << decl.KindName() << "\n"; }
};

void DumpAST(std::stringstream &output, pasta::AST ast) {
  ASTDumper dumper(ast, output);
  dumper.Accept(ast.TranslationUnit());
}

} // namespace

namespace multiplier {

// TODO: Use the expected class and return the error message
bool generateAST(std::stringstream &ast, const QString &working_directory,
                 const QString &compile_command) {
  ast = {};

  pasta::InitPasta initializer;

  const auto cwd = working_directory.toStdString();

  auto maybe_compiler = pasta::Compiler::CreateHostCompiler(pasta::TargetLanguage::kCXX);
  if (maybe_compiler.Failed()) {
    // std::cerr << maybe_compiler.TakeError() << std::endl;
    return false;
  }

  const pasta::ArgumentVector args(compile_command.toStdString());
  auto maybe_command =
      pasta::CompileCommand::CreateFromArguments(args, working_directory.toStdString());
  if (maybe_command.Failed()) {
    // std::cerr << maybe_command.TakeError() << std::endl;
    return false;
  }

  const auto command = std::move(*maybe_command);
  auto maybe_jobs = maybe_compiler->CreateJobsForCommand(command);
  if (maybe_jobs.Failed()) {
    // std::cerr << maybe_jobs.TakeError() << std::endl;
    return false;
  }

  for (const auto &job : *maybe_jobs) {
    auto maybe_ast = job.Run();
    if (maybe_ast.Failed()) {
      // std::cerr << maybe_ast.TakeError() << std::endl;
      return false;

    } else {
      DumpAST(ast, *maybe_ast);
    }
  }

  return true;
}

} // namespace multiplier
