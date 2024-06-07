// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Codegen.h"

#define VAST_ENABLE_EXCEPTIONS
#include <vast/Util/Warnings.hpp>

VAST_RELAX_WARNINGS
#include <clang/AST/ASTContext.h>
#include <clang/Tooling/Tooling.h>
#include <llvm/Support/raw_ostream.h>
#include <mlir/Bytecode/BytecodeWriter.h>
#include <mlir/IR/Builders.h>
#include <mlir/IR/Dialect.h>
#include <mlir/IR/MLIRContext.h>
#include <mlir/IR/OperationSupport.h>
#include <mlir/IR/Verifier.h>
#include <mlir/InitAllDialects.h>
VAST_UNRELAX_WARNINGS

#include <exception>
#include <glog/logging.h>

#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>

#include <vast/CodeGen/CodeGenBuilder.hpp>
#include <vast/CodeGen/CodeGenDriver.hpp>
#include <vast/CodeGen/CodeGenMeta.hpp>
#include <vast/CodeGen/CodeGenOptions.hpp>
#include <vast/CodeGen/CodeGenVisitor.hpp>
#include <vast/CodeGen/DataLayout.hpp>
#include <vast/CodeGen/DefaultVisitor.hpp>
#include <vast/CodeGen/FallBackVisitor.hpp>
#include <vast/CodeGen/ScopeContext.hpp>
#include <vast/CodeGen/SymbolGenerator.hpp>
#include <vast/CodeGen/UnsupportedVisitor.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Frontend/Options.hpp>
#include <vast/Util/Common.hpp>
#include <vast/Util/DataLayout.hpp>

#include "EntityMapper.h"
#include "NameMangler.h"
#include "TypeMapper.h"
#include "Util.h"

namespace indexer {
namespace {

class CodeGeneratorError final : public std::runtime_error {
public:
  explicit CodeGeneratorError(const std::string &message)
      : std::runtime_error(message) {}

  CodeGeneratorError() : std::runtime_error("Code generation error occurred") {}
};

// Generate `mlir::Location`s for Clang decls/stmts/etc. The location isn't
// the typical `file:line:col`, but instead embeds the entity ID for the Clang
// object, so that we can then correlate VAST-produced MLIR entities saved
// by Multiplier to its database.
class MetaGenerator final : public vast::cg::meta_generator {
private:
  // Entity mapper; The entity id gets embedded as metadata
  const EntityMapper &em;

  // MLIR context for generating the MLIR location from source location
  mlir::MLIRContext *const mctx;

public:

  MetaGenerator(mlir::MLIRContext &mctx, const EntityMapper &em)
      : em(em), mctx(&mctx) {}

  mlir::Location location(const clang::Decl *data) const final {
    return location_impl(data);
  }

  mlir::Location location(const clang::Expr *data) const final {
    return location_impl(data);
  }

  mlir::Location location(const clang::Stmt *data) const final {
    return location_impl(data);
  }

private:
  template <typename T> mlir::Location location_impl(const T *data) const {
    auto raw_entity_id = em.EntityId(data);
    if (raw_entity_id == mx::kInvalidEntityId) {
      return mlir::UnknownLoc::get(mctx);
    }

    auto attr = vast::meta::IdentifierAttr::get(mctx, raw_entity_id);
    return mlir::FusedLoc::get({}, attr, mctx);
  }
};

// Produce mangled symbol names. We use Multiplier's name mangler, as it will
// embed translation unit IDs in certain places.
//
// TODO(pag): VAST's name mangler does some special stuff with respect to
//            `clang::CXXConstructorDecl`s. Evaluate porting that here.
class SymbolGenerator final : public vast::cg::symbol_generator {
private:
  const NameMangler &nm;

public:
  explicit SymbolGenerator(const NameMangler &nm) : nm(nm) {}

  std::optional<vast::cg::symbol_name>
  symbol(vast::cg::clang_global decl) final {
    const std::string &name = nm.Mangle(decl.getCanonicalDecl().getDecl());
    if (name.empty()) {
      return std::nullopt;
    }

    return name;
  }

  std::optional<vast::cg::symbol_name>
  symbol(const vast::cg::clang_decl_ref_expr *ref) {
    const std::string &name = nm.Mangle(ref->getDecl());
    if (name.empty()) {
      return std::nullopt;
    }

    return name;
  }
};

//
// VAST Driver Setup Functions
//

std::unique_ptr<mlir::MLIRContext> MakeMLIRContext() {
  return vast::cg::mk_mcontext();
}

std::unique_ptr<vast::cg::codegen_builder>
MakeCodeGenBuilder(mlir::MLIRContext *mctx) {
  return vast::cg::mk_codegen_builder(mctx);
}

std::unique_ptr<vast::cg::meta_generator>
MakeMetaGenerator(mlir::MLIRContext &mctx, const EntityMapper &em) {
  return std::make_unique<MetaGenerator>(mctx, em);
}

std::unique_ptr<vast::cg::symbol_generator>
MakeSymbolGenerator(const NameMangler &nm) {
  return std::make_unique<SymbolGenerator>(nm);
}

std::unique_ptr<vast::cg::driver> MakeCodeGenDriver(const pasta::AST &ast,
                                                    const EntityMapper &em,
                                                    const NameMangler &nm) {
  auto &actx = ast.UnderlyingAST();
  auto mctx  = MakeMLIRContext();
  auto bld   = MakeCodeGenBuilder(mctx.get());
  auto mg    = MakeMetaGenerator(*mctx, em);
  auto sg    = MakeSymbolGenerator(nm);

  vast::cg::options opts = {
    .lang = vast::cc::get_source_language(ast.UnderlyingAST().getLangOpts()),
    .optimization_level = 0u,
    // function emition options
    .has_strict_return = false,
    // visitor options
    .disable_unsupported = false,
    // vast options
    .disable_vast_verifier = false
  };

  return std::make_unique<vast::cg::driver>(
    actx, std::move(mctx),
    std::move(opts), std::move(bld),
    std::move(mg), std::move(sg)
  );
}

} // namespace

class CodeGeneratorImpl {
public:

  std::optional<vast::owning_module_ref> Process(const pasta::AST &ast);
  std::optional<std::string> DumpToString(vast::owning_module_ref &mod);

  std::unique_ptr<vast::cg::driver> driver;
};


std::optional<vast::owning_module_ref> CodeGeneratorImpl::Process(const pasta::AST &ast) {
  try {
    auto decls = GenerateDeclarationsInDeclContext(ast.TranslationUnit());

    for (const auto &decl : decls) {
      driver->emit(const_cast<clang::Decl *>(decl.RawDecl()));
    }

    driver->finalize();
    return std::make_optional(driver->freeze());

  } catch (const CodeGeneratorError &e) {
    LOG(ERROR) << "Error generating Source IR: " << e.what();
    return std::nullopt;
  } catch (const std::exception &e) {
    LOG(ERROR) << "Error verifying Source IR: " << e.what();
    return std::nullopt;
  }
}


CodeGenerator::CodeGenerator()
    : impl(std::make_unique<CodeGeneratorImpl>()) {}

void CodeGenerator::Disable() { enabled = false; }

bool CodeGenerator::IsEnabled() const { return enabled; }

CodeGenerator::~CodeGenerator() {
  if (impl) {
    impl.reset();
  }
}

std::optional<std::string> CodeGeneratorImpl::DumpToString(vast::owning_module_ref &mlir_module) {
  std::string result;
  llvm::raw_string_ostream os(result);
  mlir::BytecodeWriterConfig config("MX");

  if (mlir::failed(mlir::writeBytecodeToFile(mlir_module.get(), os, config))) {
    return std::nullopt;
  }

  return std::make_optional(result);
}

std::string CodeGenerator::GenerateSourceIR(const pasta::AST &ast,
                                            const EntityMapper &em,
                                            const NameMangler &nm) {
  if (!IsEnabled()) {
    return "";
  }

  impl->driver = MakeCodeGenDriver(ast, em, nm);
  if (auto mod = impl->Process(ast)) {
    if (auto result = impl->DumpToString(mod.value())) {
      return result.value();
    }

    LOG(ERROR) << "Could not serialize module to bytecode on main job file " << ast.MainFile().Path().generic_string();
  }

  return "";
}

} // namespace indexer
