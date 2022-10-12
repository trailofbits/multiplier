// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "NameMangler.h"

#include <glog/logging.h>

#include <clang/AST/Attr.h>
#include <clang/AST/Decl.h>
#include <clang/AST/DeclCXX.h>
#include <clang/AST/DeclObjC.h>
#include <clang/AST/DeclTemplate.h>
#include <clang/AST/Mangle.h>
#include <clang/AST/ODRHash.h>
#include <clang/AST/PrettyPrinter.h>

#include <clang/Frontend/ASTUnit.h>

#include <clang/Index/IndexSymbol.h>

#include <llvm/Support/Casting.h>
#include <llvm/Support/raw_ostream.h>

#include <llvm/ADT/SmallString.h>
#include <llvm/Support/Casting.h>

#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <pasta/Util/File.h>

#include "Util.h"

namespace indexer {
namespace {

static clang::FunctionDecl *WalkUpToFunction(const clang::Decl *decl);

static clang::FunctionDecl *WalkUpToFunction(const clang::DeclContext *dc) {
  while (dc) {
    auto dc_decl = clang::Decl::castFromDeclContext(dc);
    if (auto func = clang::dyn_cast<clang::FunctionDecl>(dc_decl)) {
      return func;
    } else if (clang::isa<clang::TagDecl>(dc_decl)) {
      return nullptr;
    } else {
      dc = dc->getParent();
    }
  }
  return nullptr;
}

clang::FunctionDecl *WalkUpToFunction(const clang::Decl *decl) {
  return WalkUpToFunction(decl->getDeclContext());
}

}  // namespace

// Convenience class for easily mangling named decls into `std::string`s.
class NameManglerImpl {
 public:
  const uint64_t tu;
  std::string mangled_name;
  llvm::raw_string_ostream mangled_name_os;
  std::unique_ptr<clang::MangleContext> mangle_context;
  bool is_precise{false};

  explicit NameManglerImpl(clang::ASTContext &ast_context_,
                           std::filesystem::path tu_);

  // Returns the mangled name of `decl`.
  //
  // NOTE(pag): The same string reference is returned upon each call.
  const std::string &GetMangledName(const clang::Decl *decl);

  const std::string &GetMangledNameRec(const clang::FunctionDecl *decl);
  const std::string &GetMangledNameRec(const clang::FieldDecl *decl);
  const std::string &GetMangledNameRec(const clang::ParmVarDecl *decl);
  const std::string &GetMangledNameRec(const clang::ImplicitParamDecl *decl);
  const std::string &GetMangledNameRec(const clang::VarDecl *decl);
  const std::string &GetMangledNameRec(const clang::EnumConstantDecl *decl);
  const std::string &GetMangledNameImpl(const clang::NamedDecl *decl);

  NameManglerImpl(void) = delete;
};

NameManglerImpl::NameManglerImpl(clang::ASTContext &ast_context_,
                                 std::filesystem::path tu_)
    : tu(std::hash<std::string>{}(tu_.generic_string())),
      mangled_name_os(mangled_name),
      mangle_context(ast_context_.createMangleContext()) {

  mangled_name.reserve(4096);
}

const std::string &NameManglerImpl::GetMangledNameRec(
    const clang::FunctionDecl *decl) {

  if (auto *alias_attr = decl->getAttr<clang::AliasAttr>()) {
    const auto alias_name = alias_attr->getAliasee();
    mangled_name.assign(alias_name.data(), alias_name.size());
    if (!mangled_name.empty()) {
      return mangled_name;
    }
  }

  (void) GetMangledNameImpl(decl);

  if (mangled_name.empty()) {
    if (auto ident_info = decl->getIdentifier()) {
      auto func_type = decl->getType()->castAs<clang::FunctionType>();
      if (func_type->getCallConv() == clang::CC_X86RegCall) {
        mangled_name_os << "__regcall3__";
      }
      mangled_name_os << ident_info->getName();
      mangled_name_os.flush();
    }
  }

  // Static functions, including inline static functions in headers,
  // should be uniqued.
  if (!decl->isExternallyVisible()) {
 
    auto func_def = decl->getDefinition();
    if (!func_def) {
      func_def = decl;
      is_precise = false;

    // TODO(pag): Ideally want this to be the file containing the declaration.
    } else {
      mangled_name_os << " tu:" << tu;
    }

    auto hash = const_cast<clang::FunctionDecl *>(func_def)->getODRHash();
    mangled_name_os << " odr:" << hash;
    mangled_name_os.flush();

  // Projects with multiple `main` functions should have each of them
  // distinguished.
  } else if (auto ident_info = decl->getIdentifier()) {
    auto is_main = llvm::StringSwitch<bool>(ident_info->getName())
        .Cases("main",     // an ANSI console app
               "wmain",    // a Unicode console App
               "WinMain",  // an ANSI GUI app
               "wWinMain", // a Unicode GUI app
               "DllMain",  // a DLL
               true)
        .Default(false);
    if (!mangled_name.empty() && is_main) {
      mangled_name_os << " tu:" << tu;
      mangled_name_os.flush();
    }
  }

  return mangled_name;
}

const std::string &NameManglerImpl::GetMangledNameRec(
    const clang::FieldDecl *decl) {
  if (!GetMangledNameImpl(decl->getParent()).empty()) {
    const auto name = decl->getName();
    if (name.empty()) {
      mangled_name_os
          << " field:" << decl->getFieldIndex();
    } else {
      mangled_name_os
          << " field:" << name;
    }
    mangled_name_os.flush();
  }
  return mangled_name;
}

const std::string &NameManglerImpl::GetMangledNameRec(
    const clang::ImplicitParamDecl *decl) {

  auto parent_decl = clang::Decl::castFromDeclContext(decl->getDeclContext());
  auto func_decl = clang::dyn_cast<clang::FunctionDecl>(parent_decl);
  if (!GetMangledNameRec(func_decl).empty()) {
    switch (decl->getParameterKind()) {
      case clang::ImplicitParamDecl::ObjCSelf:
        mangled_name_os << " implicit:self";
        break;
      case clang::ImplicitParamDecl::ObjCCmd:
        mangled_name_os << " implicit:_cmd";
        break;
      case clang::ImplicitParamDecl::CXXThis:
        mangled_name_os << " implicit:this";
        break;
      case clang::ImplicitParamDecl::CXXVTT:
        mangled_name_os << " implicit:vtt";
        break;

      case clang::ImplicitParamDecl::CapturedContext:
      case clang::ImplicitParamDecl::Other:
        mangled_name_os << " implicit:other";
        break;
    }
    mangled_name_os.flush();
  }
  return mangled_name;
}

const std::string &NameManglerImpl::GetMangledNameRec(
    const clang::ParmVarDecl *decl) {
  auto parent_decl = clang::Decl::castFromDeclContext(decl->getParentFunctionOrMethod());
  auto func_decl = clang::dyn_cast<clang::FunctionDecl>(parent_decl);
  if (!GetMangledNameRec(func_decl).empty()) {
    mangled_name_os
        << " param:" << decl->getFunctionScopeIndex();
    mangled_name_os.flush();
  }
  return mangled_name;
}

const std::string &NameManglerImpl::GetMangledNameRec(
    const clang::VarDecl *decl) {

  if (auto param_decl = clang::dyn_cast<clang::ParmVarDecl>(decl)) {
    return GetMangledNameRec(param_decl);

  } else if (auto impl_decl = clang::dyn_cast<clang::ImplicitParamDecl>(decl)) {
    return GetMangledNameRec(impl_decl);

  } else if (decl->isCXXClassMember()) {
    return GetMangledNameImpl(decl);

  } else {
    if (auto func_decl = WalkUpToFunction(decl)) {
      if (!GetMangledNameRec(func_decl).empty()) {
        mangled_name_os << " var:" << decl->getName();
        mangled_name_os.flush();
      }

      return mangled_name;

    } else {
      return GetMangledNameImpl(decl);
    }
  }
}

const std::string &NameManglerImpl::GetMangledNameRec(
    const clang::EnumConstantDecl *decl) {
  auto enum_decl = clang::dyn_cast<clang::EnumDecl>(
      clang::Decl::castFromDeclContext(decl->getDeclContext()));
  if (enum_decl && !GetMangledName(enum_decl).empty()) {
    mangled_name_os.flush();
    mangled_name_os << " ";
    mangled_name_os << "(enumerator " << decl->getName() << ", value "
                    << decl->getInitVal() << ")";
    mangled_name_os.flush();
  }
  return mangled_name;
}

const std::string &NameManglerImpl::GetMangledNameImpl(
    const clang::NamedDecl *decl) {

  // Sometimes C structures, compiled in C++ mode, show up as CXXRecordDecls,
  // and we don't want to mangle them, otherwise we might end up with one
  // unmangled version compiled in a C context, and another mangled version
  // compiled in a C++ context.
  if (clang::isa<clang::TagDecl>(decl)) {
    return mangled_name;
  }

  if (mangle_context->shouldMangleDeclName(decl)) {

    clang::index::SymbolInfo info = clang::index::getSymbolInfo(decl);
    bool is_cxx_name = info.Lang == clang::index::SymbolLanguage::CXX &&
                       clang::isa<clang::FunctionDecl, clang::VarDecl,
                                  clang::TemplateParamObjectDecl>(decl);

    if (auto type_decl = clang::dyn_cast<clang::TypeDecl>(decl)) {
      if (auto type = type_decl->getTypeForDecl()) {
        clang::QualType qual_type(type, 0);
        mangle_context->mangleTypeName(qual_type, mangled_name_os);

      } else if (is_cxx_name) {
        clang::GlobalDecl gd(decl);
        mangle_context->mangleCXXName(decl, mangled_name_os);

      } else {
        mangle_context->mangleName(decl, mangled_name_os);
      }

    // TODO(pag): Not sure how Clang actually derives the proper `CXXCtorType`
    //            and `CXXDtorType`.
    } else if (auto *cst = clang::dyn_cast<clang::CXXConstructorDecl>(decl)) {
      clang::GlobalDecl gd(cst, clang::Ctor_Complete);
      mangle_context->mangleCXXName(gd, mangled_name_os);

    } else if (auto *dst = clang::dyn_cast<clang::CXXDestructorDecl>(decl)) {
      clang::GlobalDecl gd(dst, clang::Dtor_Complete);
      mangle_context->mangleCXXName(gd, mangled_name_os);

    } else if (is_cxx_name) {
      clang::GlobalDecl gd(decl);
      mangle_context->mangleCXXName(decl, mangled_name_os);

    // TODO(pag): Handle CUDA-attributed function decls.

    } else {
      mangle_context->mangleName(decl, mangled_name_os);
    }
    mangled_name_os.flush();
  }

  return mangled_name;
}

// Returns the mangled name of `decl`.
//
// NOTE(pag): The same string reference is returned upon each call.
//
// XREF(pag): `getMangledNameImpl` in `clang/lib/CodeGen/CodeGenModule.cpp`.
const std::string &NameManglerImpl::GetMangledName(const clang::Decl *decl) {
  mangled_name.clear();
  is_precise = true;

  if (!decl) {
    is_precise = false;
    return mangled_name;

  // Mangle functions with an `__attribute__((alias("...")))` to use the
  // `...` as their mangled name, because that is really what gets called.
  } else if (auto func_decl = clang::dyn_cast<clang::FunctionDecl>(decl)) {
    return GetMangledNameRec(func_decl);

  // Handle fields in terms of the mangled name of their struct/union/class
  // whatever.
  } else if (auto field_decl = clang::dyn_cast<clang::FieldDecl>(decl)) {
    return GetMangledNameRec(field_decl);

  // Definition and declarations of the same function can have different
  // parameter names, so we really don't want the name itself to be significant.
  // Rather, we want the mangling of the parameter name to be the mangling of
  // the function, followed by something like `arg N`.
  } else if (auto var_decl = clang::dyn_cast<clang::VarDecl>(decl)) {

    // Parameters can be redeclared.
    if (auto parm_var_decl = clang::dyn_cast<clang::ParmVarDecl>(var_decl)) {
      return GetMangledNameRec(parm_var_decl);

    // Since function local variables can't be redeclared, we don't have to
    // worry about giving them a mangled name.
    } else if (var_decl->hasLocalStorage() || var_decl->isStaticLocal()) {
      return mangled_name;
    }

    if (!GetMangledNameRec(var_decl).empty() &&
        !var_decl->isExternallyVisible()) {
      mangled_name_os << " tu:" << tu;
      mangled_name_os.flush();
    }

    return mangled_name;

  } else if (auto enumerator_decl = \
                 clang::dyn_cast<clang::EnumConstantDecl>(decl)) {
    return GetMangledNameRec(enumerator_decl);

  } else if (auto using_decl = clang::dyn_cast<clang::UsingDecl>(decl)) {
    for (auto shadow : using_decl->shadows()) {
      if (auto used_decl = shadow->getTargetDecl()) {
        if (used_decl != using_decl) {
          (void) GetMangledName(used_decl);
          if (!mangled_name.empty()) {
            break;
          }
        }
      }
    }
    return mangled_name;

  } else if (auto using_shadow = clang::dyn_cast<clang::UsingShadowDecl>(decl)) {
    if (auto used_decl = using_shadow->getTargetDecl()) {
      if (used_decl != decl) {
        if (used_decl != using_decl) {
          (void) GetMangledName(used_decl);
        }
      }
    }
    return mangled_name;

  // TODO(pag): Maybe handle these specially.
  } else if (clang::isa<clang::TypedefNameDecl>(decl) ||
             clang::isa<clang::UsingDirectiveDecl>(decl) ||
             clang::isa<clang::UsingPackDecl>(decl)) {
    is_precise = false;
    return mangled_name;  // No mangled name.

  } else if (auto named_decl = clang::dyn_cast<clang::NamedDecl>(decl)) {
    return GetMangledNameImpl(named_decl);

  } else {
    is_precise = false;
    return mangled_name;  // No mangled name.
  }
}

NameMangler::~NameMangler(void) {}

NameMangler::NameMangler(const pasta::AST &ast)
    : impl(std::make_unique<NameManglerImpl>(ast.UnderlyingAST(),
                                             ast.MainFile().Path())) {}

const std::string &NameMangler::Mangle(const pasta::Decl &decl) {
  return impl->GetMangledName(decl.RawDecl());
}

// This is not a very good API, but basically says that the mangled name
// can probably be trusted.
bool NameMangler::MangledNameIsPrecise(void) const {
  return impl->is_precise;
}

}  // namespace indexer
