// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Hash.h"

#include <llvm/ADT/FoldingSet.h>
#include <llvm/ADT/StringRef.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>
#include <pasta/Util/File.h>
#include <pasta/Util/FileManager.h>
#include <sstream>

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
    ss << ':' << decl.ODRHash();
    VisitDeclContext(decl);
  }

  void VisitCXXRecordDecl(const pasta::CXXRecordDecl &decl) final {
    if (decl.HasDefinition()) {
      ss << ':' << decl.ODRHash();
      VisitDeclContext(decl);
    }
  }

  void VisitEnumDecl(const pasta::EnumDecl &decl) final {
    ss << ':' << decl.ODRHash();
  }

  // VisitDecl will add kind name of all decl to the folding set
  // node.
  void VisitDecl(const pasta::Decl &decl) final {}

 private:
  std::stringstream &ss;
};

}  // namespace

std::string ComputeHash(const std::vector<pasta::Decl> &tlds,
                        const pasta::TokenRange &toks,
                        uint64_t begin_index, uint64_t end_index) {
  llvm::FoldingSetNodeID fs;
  if (begin_index > end_index || end_index > toks.size()) {
    return std::string();
  }

  std::stringstream ss;
  auto seen_floc = false;

  for (auto i = begin_index; i < end_index; i++) {
    auto token = toks[i];

    // Try to find the first token in the range with a file location, as a kind
    // of anchor point.
    if (!seen_floc) {
      if (auto floc = token.FileLocation()) {
        ss << pasta::File::Containing(*floc).Path()
           << ':' << floc->Line() << ':' << floc->Column();
        seen_floc = true;
      }
    }

    // Mix in generic token/structure/context information.
    switch (token.Role()) {
      case pasta::TokenRole::kFileToken:
      case pasta::TokenRole::kMacroExpansionToken:
        for (auto context = token.Context(); context;
             context = context->Parent()) {
          switch (context->Kind()) {
            case pasta::TokenContextKind::kDecl:
              fs.AddInteger(static_cast<uint16_t>(
                  pasta::Decl::From(*context)->Kind()));
              break;
            case pasta::TokenContextKind::kStmt:
              fs.AddInteger(static_cast<uint16_t>(
                  pasta::Stmt::From(*context)->Kind()));
              break;
            case pasta::TokenContextKind::kType:
              fs.AddInteger(static_cast<uint16_t>(
                  pasta::Type::From(*context)->Kind()));
              break;
            default:
              fs.AddInteger(static_cast<uint16_t>(context->Kind()));
              break;
          }
        }

        fs.AddInteger(static_cast<uint16_t>(token.Kind()));
        fs.AddString(llvm::StringRef(token.Data()));
        break;

      default:
        break;
    }
  }

  ss << std::hex;

  // Mix in ODR hashes.
  for (auto &decl : tlds) {
    HashVisitor visitor(ss);
    visitor.Accept(decl);
  }

  // Mix in summarized generic info.
  ss << ':' << fs.ComputeHash();
  return ss.str();
}

}  // namespace indexer
