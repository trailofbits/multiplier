// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Hash.h"

#include <pasta/AST/Decl.h>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>
#include <pasta/Util/File.h>
#include <pasta/Util/FileManager.h>
#include <sstream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wshadow"
#pragma clang diagnostic ignored "-Wcast-align"
#include <llvm/ADT/FoldingSet.h>
#include <llvm/ADT/StringRef.h>
#include <llvm/Support/SHA256.h>
#pragma clang diagnostic pop

#include "PASTA.h"
#include "Util.h"

//#define D(...) __VA_ARGS__
#ifndef D
# define D(...)
#else
# include <iostream>
#endif

namespace indexer {
namespace {

class HashVisitor final : public pasta::DeclVisitor {
 public:
  virtual ~HashVisitor(void) = default;

  explicit HashVisitor(std::stringstream &ss_)
      : ss(ss_) {}

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

    // XREF(pag): Issue #318. Only integrate the ODR hash when we have a
    //            definition.
    if (IsDefinition(decl)) {
      if (auto hash = decl.ODRHash()) {
        D( std::cerr << "\t4 odr=" << hash.value() << '\n'; )
        ss << hash.value() << ':';
      }
    }
    VisitDeclContext(decl);
  }

  void VisitCXXRecordDecl(const pasta::CXXRecordDecl &decl) final {
    if (IsDefinition(decl)) {
      if (auto hash = decl.ODRHash()) {
        D( std::cerr << "\t5 odr=" << hash.value() << '\n'; )
        ss << hash.value() << ':';
      }
      VisitDeclContext(decl);
    }
  }

  void VisitEnumDecl(const pasta::EnumDecl &decl) final {
    if (IsDefinition(decl)) {
      if (auto hash = decl.ODRHash()) {
        D( std::cerr << "\t6 odr=" << hash.value() << '\n'; )
        ss << hash.value() << ':';
      }
    }
  }

  // VisitDecl will add kind name of all decl to the folding set
  // node.
  void VisitDecl(const pasta::Decl &) final {}

 private:
  std::stringstream &ss;
};

}  // namespace

// Compute a SHA256 hash of some data.
std::string HashFile(std::string_view data) {
  llvm::SHA256 hash;
  hash.update(data);
  std::string result;
  result.reserve(32);
  auto final_ = hash.final();
  auto final_data = reinterpret_cast<const char *>(final_.data());
  result.insert(result.end(), final_data, &(final_data[final_.size()]));
  return result;
}

// Compute a hash of top-level declarations. This will produce a string of
// the form:
//
//    <file hash>:<line>:<column>:<tokens hash>:<odr hash 0>:...:<odr hash N>
//
// We use a hash of a file's contents instead of the file path so that we
// can identify the same logical code in different copies of the same file. The
// line and column represent a kind of anchor point within the file. The tokens
// and contents are all hashed together in a way that integrates the actual AST
// structure itself. Finally, the ODR hashes are there to help us to distinguish
// template instantiations, where the tokens and their contexts match, but the
// declarations in the AST do not.
//
// NOTE(pag): We want the hash to be very unique to this fragment. We never want
//            two different fragments to have the same hash, because their
//            ASTs might be different, and if their ASTs are different, then
//            our entity ID numbering scheme will fail horribly.
std::string HashFragment(
    const std::vector<Entity> &entities, const pasta::TokenRange &toks,
    uint64_t begin_index, uint64_t end_index) {

  D( std::cerr
        << "begin_index=" << begin_index << " end_index=" << end_index
        << " entities.size()=" << entities.size() << '\n'; )

  llvm::FoldingSetNodeID fs;
  if (begin_index > end_index || end_index > toks.size()) {
    return std::string();
  }

  std::stringstream ss;

  for (uint64_t i = begin_index; i <= end_index; i++) {
    pasta::Token token = toks[i];
    mx::TokenKind kind = mx::FromPasta(token.Kind());
    llvm::StringRef data(token.Data());

    if (data.empty()) {
      continue;
    }

    // Mix in generic token/structure/context information.
    switch (token.Role()) {
      case pasta::TokenRole::kIntermediateMacroExpansionToken:
      case pasta::TokenRole::kInitialMacroUseToken:
        D( std::cerr << "\t1 kind=" << int(kind) << " data="
                     << token.Data() << '\n'; )
        fs.AddInteger(static_cast<uint16_t>(kind));
        fs.AddString(data);
        break;

      case pasta::TokenRole::kFileToken:
      case pasta::TokenRole::kFinalMacroExpansionToken:
        D( std::cerr << "\t2 kind=" << int(kind) << " data="
                     << token.Data() << '\n'; )

       for (auto context = token.Context(); context;
             context = context->Parent()) {
          D( std::cerr << "\t\tcontext->kind=" << int(context->Kind()) << '\n'; )

          switch (context->Kind()) {
            case pasta::TokenContextKind::kDecl:
              fs.AddInteger(static_cast<uint16_t>(
                  mx::FromPasta(pasta::Decl::From(*context)->Kind())));
              break;
            case pasta::TokenContextKind::kStmt:
              fs.AddInteger(static_cast<uint16_t>(
                  mx::FromPasta(pasta::Stmt::From(*context)->Kind())));
              break;
            case pasta::TokenContextKind::kType:
              fs.AddInteger(static_cast<uint16_t>(
                  mx::FromPasta(pasta::Type::From(*context)->Kind())));
              break;
            case pasta::TokenContextKind::kAttr:
              fs.AddInteger(static_cast<uint16_t>(
                  mx::FromPasta(pasta::Attr::From(*context)->Kind())));
              break;
            case pasta::TokenContextKind::kAlias:
            case pasta::TokenContextKind::kString:
            case pasta::TokenContextKind::kAST:
              break;
            default:
              fs.AddInteger(static_cast<uint16_t>(context->Kind()));
              break;
          }
        }

        fs.AddInteger(static_cast<uint16_t>(kind));
        fs.AddString(data);
        break;

      default:
        break;
    }
  }

  ss << std::hex;

  HashVisitor visitor(ss);
  for (const Entity &entity : entities) {

    // Mix in ODR hashes.
    if (std::holds_alternative<pasta::Decl>(entity)) {
      visitor.Accept(std::get<pasta::Decl>(entity));

    // Mix in macro info. Note that any macro names and such are already
    // integrated from the token values themselves.
    //
    // TODO(pag): Should really have a `MacroVisitor` in pasta, then separately
    //            visit and hash each top-level macro entity. The saving factor
    //            for now is probably that the above token hashing operates on
    //            the parsed and intermediate tokens, which is a good enough
    //            proxy.
    } else if (std::holds_alternative<pasta::Macro>(entity)) {
      const pasta::Macro &macro = std::get<pasta::Macro>(entity);
      D( std::cerr << "\t3 kind=" << int(macro.Kind()) << " num_children="
                   << macro.Children().Size() << '\n'; )
      fs.AddInteger(static_cast<uint16_t>(macro.Kind()));
      fs.AddInteger(macro.Children().Size());
    }
  }

  // Mix in summarized generic info.
  ss << fs.ComputeHash();

  D( std::cerr << "hash=" << ss.str() << "\n\n"; )
  return ss.str();
}

}  // namespace indexer
