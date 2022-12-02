// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Hash.h"

#include <llvm/ADT/FoldingSet.h>
#include <llvm/ADT/StringRef.h>
#include <llvm/Support/SHA256.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Macro.h>
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
    if (auto hash = decl.ODRHash()) {
      ss << ':' << hash.value();
    }
    VisitDeclContext(decl);
  }

  void VisitCXXRecordDecl(const pasta::CXXRecordDecl &decl) final {
    if (decl.HasDefinition()) {
      if (auto hash = decl.ODRHash()) {
        ss << ':' << hash.value();
      }
      VisitDeclContext(decl);
    }
  }

  void VisitEnumDecl(const pasta::EnumDecl &decl) final {
    if (auto hash = decl.ODRHash()) {
      ss << ':' << hash.value();
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
std::string FileHash(std::string_view data) {
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
std::string CodeHash(std::unordered_map<pasta::File, std::string> file_hashes,
                     const std::vector<Entity> &entities,
                     const pasta::TokenRange &toks,
                     uint64_t begin_index, uint64_t end_index) {
  llvm::FoldingSetNodeID fs;
  if (begin_index > end_index || end_index > toks.size()) {
    return std::string();
  }

  std::stringstream ss;
  bool seen_floc = false;

  std::vector<uint16_t> context_kinds;

  for (uint64_t i = begin_index; i < end_index; i++) {
    pasta::Token token = toks[i];

    // Try to find the first token in the range with a file location, as a kind
    // of anchor point.
    //
    // NOTE(pag): We use the hash of the contents of the file as a part of our
    //            key, rather than the absolute path. This is so that if we
    //            are indexing more than one project, then the local copy of a
    //            header file and the installed copy will resolve to the same
    //            hash, and so we'll do a better job of deduping top-level
    //            declarations in that case.
    if (!seen_floc) {
      if (auto floc = token.FileLocation()) {
        auto file = pasta::File::Containing(*floc);
        if (auto hash_it = file_hashes.find(file);
            hash_it != file_hashes.end()) {
          ss << hash_it->second << ':' << floc->Line() << ':' << floc->Column();
          seen_floc = true;
        }
      }
    }

    // Mix in generic token/structure/context information.
    switch (token.Role()) {
      case pasta::TokenRole::kIntermediateMacroExpansionToken:
      case pasta::TokenRole::kInitialMacroUseToken:
        fs.AddInteger(static_cast<uint16_t>(token.Kind()));
        fs.AddString(llvm::StringRef(token.Data()));
        break;

      case pasta::TokenRole::kFileToken:
      case pasta::TokenRole::kFinalMacroExpansionToken:
        context_kinds.clear();
        for (auto context = token.Context(); context;
             context = context->Parent()) {
          switch (context->Kind()) {
            case pasta::TokenContextKind::kDecl:
              context_kinds.push_back(static_cast<uint16_t>(
                  pasta::Decl::From(*context)->Kind()));
              break;
            case pasta::TokenContextKind::kStmt:
              context_kinds.push_back(static_cast<uint16_t>(
                  pasta::Stmt::From(*context)->Kind()));
              break;
            case pasta::TokenContextKind::kType:
              switch (auto type_kind = pasta::Type::From(*context)->Kind()) {

                // This is a bit subtle, and relates to issue #191. It's meant
                // to handle things like this:
                //
                //    typedef void *CURL;  // In public header.
                //    typedef struct Curl_easy *CURL;  // In private header.
                //
                //    void function(CURL curl);  // In both.
                //
                // The idea here is that the token contexts will look like this:
                //
                //    Type(void) -> Pointer -> Typedef(CURL) -> ...
                //    Type(struct Curl_Easy) -> Pointer -> Typedef(CURL) -> ...
                //
                // And so we want to cut off the prefix and represent them
                // both uniformly as:
                //
                //    Pointer -> Typedef(CURL) -> ...
                //
                // XREF: https://github.com/trailofbits/multiplier/issues/191
                case pasta::TypeKind::kPointer:
                  context_kinds.clear();
                  [[clang::fallthrough]];
                default:
                  context_kinds.push_back(static_cast<uint16_t>(type_kind));
                  break;
              }

              break;
            default:
              context_kinds.push_back(static_cast<uint16_t>(context->Kind()));
              break;
          }
        }

        context_kinds.push_back(static_cast<uint16_t>(token.Kind()));
        for (uint16_t kind : context_kinds) {
          fs.AddInteger(kind);
        }
        fs.AddString(llvm::StringRef(token.Data()));
        break;

      default:
        break;
    }
  }

  ss << std::hex;

  // Mix in ODR hashes.
  HashVisitor visitor(ss);
  for (const Entity &entity : entities) {
    if (std::holds_alternative<pasta::Decl>(entity)) {
      visitor.Accept(std::get<pasta::Decl>(entity));
    }
  }

  // Mix in summarized generic info.
  ss << ':' << fs.ComputeHash();
  return ss.str();
}

}  // namespace indexer
