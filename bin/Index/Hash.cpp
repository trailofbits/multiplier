// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Hash.h"

#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Printer.h>
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

#include "EntityMapper.h"
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

  explicit HashVisitor(llvm::FoldingSetNodeID &fs_)
      : fs(fs_) {}

  void VisitDeclContext(const pasta::DeclContext &dc) {
    for (const pasta::Decl &decl : dc.AlreadyLoadedDeclarations()) {
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
        fs.AddInteger(hash.value());
      }
    }
    VisitDeclContext(decl);
  }

  void VisitCXXRecordDecl(const pasta::CXXRecordDecl &decl) final {
    if (IsDefinition(decl)) {
      if (auto hash = decl.ODRHash()) {
        D( std::cerr << "\t5 odr=" << hash.value() << '\n'; )
        fs.AddInteger(hash.value());
      }
      VisitDeclContext(decl);
    }
  }

  void VisitEnumDecl(const pasta::EnumDecl &decl) final {
    if (IsDefinition(decl)) {
      if (auto hash = decl.ODRHash()) {
        D( std::cerr << "\t6 odr=" << hash.value() << '\n'; )
        fs.AddInteger(hash.value());
      }
    }
  }

  // VisitDecl will add kind name of all decl to the folding set
  // node.
  void VisitDecl(const pasta::Decl &) final {}

 private:
  llvm::FoldingSetNodeID &fs;
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

// Hash the entire compilation.
std::string HashCompilation(const pasta::AST &ast, const EntityMapper &em) {
  llvm::SHA256 hash;

  // Hash all file ids.
  std::stringstream ss;
  for (const pasta::File &file : ast.ParsedFiles()) {
    ss << ':' << std::hex << em.EntityId(file);
  }
  hash.update(ss.str());

  // Hash the results of preprocessing.
  hash.update(ast.PreprocessedCode());

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
//
// TODO(pag): Integrate template parameter lists for specializations?
std::string HashFragment(
    const std::vector<pasta::Decl> &decls,
    const std::vector<pasta::Macro> &macros,
    const pasta::TokenRange *frag_tok_range,
    const pasta::PrintedTokenRange &decl_tok_range) {

  D( std::cerr
        << "begin_index=" << begin_index << " end_index=" << end_index
        << " entities.size()=" << entities.size() << '\n'; )

  llvm::FoldingSetNodeID fs;

  uint64_t end_index = 0u;

  auto mixin_token = [&fs] (mx::TokenKind kind, pasta::TokenRole role,
                            std::string_view data) {
    if (data.empty()) {
      return;
    }

    static constexpr std::hash<std::string_view> kHasher;

    // Mix in generic token/structure/context information.
    switch (role) {
      case pasta::TokenRole::kIntermediateMacroExpansionToken:
      case pasta::TokenRole::kInitialMacroUseToken:
        D( std::cerr << "\t1 kind=" << int(kind) << " data="
                     << token.Data() << '\n'; )
        fs.AddInteger(static_cast<uint16_t>(kind));
        fs.AddInteger(kHasher(data));
        break;

      case pasta::TokenRole::kFileToken:
      case pasta::TokenRole::kFinalMacroExpansionToken:
        D( std::cerr << "\t2 kind=" << int(kind) << " data="
                     << token.Data() << '\n'; )
        fs.AddInteger(static_cast<uint16_t>(kind));
        fs.AddInteger(kHasher(data));
        break;

      default:
        break;
    }
  };

  if (*frag_tok_range) {
    for (pasta::Token token : *frag_tok_range) {
      end_index = token.Index();
      mixin_token(mx::FromPasta(token.Kind()), token.Role(), token.Data());
    }
  }

  if (decl_tok_range) {
    for (pasta::PrintedToken token : decl_tok_range) {
      mixin_token(mx::FromPasta(token.Kind()), pasta::TokenRole::kFileToken,
                  token.Data());
    }
  }

  uint64_t base_hash = fs.ComputeHash();
  fs.clear();

  HashVisitor visitor(fs);

  // Mix in ODR hashes, decl kinds, and offsets of the decls. We need to mix
  // in decl kinds and offsets because not all decls have ODR hashes, and so
  // these extra bits of data add variability to help distinguish between things
  // that might only manifest as nested fragments.
  for (const pasta::Decl &decl : decls) {
    fs.AddInteger(static_cast<uint16_t>(decl.Kind()));

    pasta::Token decl_token = decl.Token();
    if (frag_tok_range && frag_tok_range->Contains(decl_token)) {
      fs.AddInteger(end_index - decl_token.Index());
    }

    visitor.Accept(decl);
  }

  // Mix in macro info. Note that any macro names and such are already
  // integrated from the token values themselves.
  //
  // TODO(pag): Should really have a `MacroVisitor` in pasta, then separately
  //            visit and hash each top-level macro entity. The saving factor
  //            for now is probably that the above token hashing operates on
  //            the parsed and intermediate tokens, which is a good enough
  //            proxy.
  for (const pasta::Macro &macro : macros) {
    D( std::cerr << "\t3 kind=" << int(macro.Kind()) << " num_children="
                 << macro.Children().Size() << '\n'; )
    fs.AddInteger(static_cast<uint16_t>(macro.Kind()));
    fs.AddInteger(macro.Children().Size());
  }

  base_hash <<= 32u;
  base_hash |= fs.ComputeHash();

  std::string hash_data;
  hash_data.resize(sizeof(base_hash));
  memcpy(hash_data.data(), &base_hash, sizeof(base_hash));

  return hash_data;
}

}  // namespace indexer
