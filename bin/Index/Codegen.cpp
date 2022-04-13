// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Codegen.h"

#ifndef MX_DISABLE_SOURCEIR
#include <clang/AST/ASTContext.h>
#include <clang/Tooling/Tooling.h>
#include <mlir/IR/Builders.h>

#include <vast/Translation/CodeGen.hpp>

#include <glog/logging.h>
#endif  // MX_DISABLE_SOURCEIR

#include "Context.h"

namespace indexer {

#ifndef MX_DISABLE_SOURCEIR
class CodeGenVisitor final : public pasta::DeclVisitor {
 public:
  virtual ~CodeGenVisitor(void) = default;

  explicit CodeGenVisitor(vast::hl::module_owning_ref &mod_,
                          vast::hl::high_level_codegen *gen_)
      : mod(mod_), gen(gen_) {}

  void VisitDeclContext(const pasta::DeclContext &dc) {
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

  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final {
    gen->emit_module(mod, const_cast<clang::FunctionDecl*>(decl.RawDecl()));

  }

  void VisitCXXRecordDecl(const pasta::CXXRecordDecl &decl) final {
    VisitDeclContext(decl);
  }

  void VisitTagDecl(const pasta::TagDecl &decl) final {
    VisitDeclContext(decl);
  }

 private:
  vast::hl::module_owning_ref &mod;
  vast::hl::high_level_codegen *gen;
};

class CodeGenerator::Impl {
 public:
  Impl(void) {
    registry.insert<vast::hl::HighLevelDialect,
                    mlir::StandardOpsDialect,
                    mlir::DLTIDialect >();
    ctx = std::make_unique<mlir::MLIRContext>(registry);
    hl_codegen =  std::make_unique<vast::hl::high_level_codegen>(ctx.get());
  }

  virtual ~Impl(void){}

  void SourceIRFromTLDs(
      std::string mod_id, const std::vector<pasta::Decl> &decls,
      std::string &ir_string) {

    llvm::raw_string_ostream os(ir_string);
    mlir::Builder bld(ctx.get());
    auto loc = bld.getUnknownLoc();
    vast::hl::module_owning_ref mod = vast::hl::module_t::create(
        loc, llvm::StringRef(mod_id));

    for (auto decl : decls) {
      if (decl.Kind() == pasta::DeclKind::kFunction) {
        hl_codegen->emit_module(mod, const_cast<clang::Decl*>(decl.RawDecl()));
        if (mod.get()) mod->print(os);
        continue;
      }

      // if top-level declaration is not function; there could
      // be `FunctionDecl` inside top-level decl. Visit AST node
      // and lower the function decl found;
      CodeGenVisitor visitor(mod, hl_codegen.get());
      visitor.Accept(decl);
      if (mod.get()) mod->print(os);
    }
  }

 private:
  mlir::DialectRegistry registry;
  std::unique_ptr<mlir::MLIRContext> ctx;
  std::unique_ptr<vast::hl::high_level_codegen> hl_codegen;
};

CodeGenerator::CodeGenerator(void) {
  impl = new Impl;
}

CodeGenerator::~CodeGenerator(void) {
  delete impl;
}

void CodeGenerator::GenerateSourceIRFromTLDs(
    std::string mod_id, const std::vector<pasta::Decl> &decls,
    std::string &ir_string) {
  impl->SourceIRFromTLDs(mod_id, decls, ir_string);
}

// Generate source IR from the TLDs
std::string ConvertToSourceIR(
    std::shared_ptr<IndexingContext> context,
    mx::FragmentId code_id, const std::vector<pasta::Decl> &decls) {

  // Get the instance of code generator
  if (auto codegen = context->codegen.get(); codegen) {
    std::string ir_string;

    // Generate module id from the code id
    std::stringstream ss;
    ss << code_id;

    try {
      codegen->GenerateSourceIRFromTLDs(ss.str(), decls, ir_string);
      if (!ir_string.empty()) {
        IndexingCounterRes ir_counter(context->stat, kStatSourceIRFragment);
        // Add source IR string to the persistent storage
        context->PutSourceIRs(code_id, ir_string);
      }
      return ir_string;

    } catch (const std::exception &e) {
      LOG(ERROR) << "Failed to generate Source IR from the "
                 << "top-level declaration with code id "
                 << code_id << "\nerror " << e.what();
    }
  }

  return {};
}

#else

CodeGenerator::CodeGenerator(void) {}

CodeGenerator::~CodeGenerator(void) {}

void CodeGenerator::GenerateSourceIRFromTLDs(
    std::string, const std::vector<pasta::Decl> &,
    std::string &) {}

// Generate source IR from the TLDs
std::string ConvertToSourceIR(
    std::shared_ptr<IndexingContext>,
    mx::FragmentId, const std::vector<pasta::Decl> &) {
  return {};
}
#endif  // MX_DISABLE_SOURCEIR

} // namespace indexer
