// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Hash.h"

#include <cctype>
#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>
#include <pasta/Util/File.h>
#include <pasta/Util/FileManager.h>
#include <sstream>
#include <iostream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wshadow"
#pragma clang diagnostic ignored "-Wcast-align"
#include <llvm/ADT/StringRef.h>
#include <llvm/Support/SHA256.h>
#pragma clang diagnostic pop

#include "EntityMapper.h"
#include "NameMangler.h"
#include "PASTA.h"
#include "Util.h"

namespace indexer {
namespace {

class HashVisitor final : public pasta::DeclVisitor {
 public:
  virtual ~HashVisitor(void) = default;

  explicit HashVisitor(std::stringstream &ss_)
      : ss(ss_) {}

  void VisitDeclContext(const pasta::Decl &dc_decl) {
    auto dc = pasta::DeclContext::From(dc_decl);
    if (!dc) {
      return;
    }

    for (const pasta::Decl &decl : dc->AlreadyLoadedDeclarations()) {
      if (dc_decl != decl) {
        Accept(decl);
      }
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

  // XREF(pag): Issue #318. Only integrate the ODR hash when we have a
  //            definition.
  template <typename T>
  void VisitODRHashable(const T &entity) {
    if (IsDefinition(entity)) {
      if (auto hash = entity.ODRHash()) {
        ss << " o" << hash.value();
      }
    }
  }

  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final {
    VisitODRHashable(decl);
  }

  void VisitClassTemplateDecl(const pasta::ClassTemplateDecl &decl) {
    Accept(decl.TemplatedDeclaration());
  }

  void VisitFunctionTemplateDecl(const pasta::FunctionTemplateDecl &decl) {
    Accept(decl.TemplatedDeclaration());
  }

  void VisitCXXRecordDecl(const pasta::CXXRecordDecl &decl) final {
    VisitODRHashable(decl);
    if (IsDefinition(decl)) {
      VisitDeclContext(decl);
    }
  }

  void VisitEnumDecl(const pasta::EnumDecl &decl) final {
    VisitODRHashable(decl);
  }

  void VisitDecl(const pasta::Decl &) final {}

  void VisitClassTemplatePartialSpecializationDecl(
      const pasta::ClassTemplatePartialSpecializationDecl &decl) {
    VisitCXXRecordDecl(decl);
  }

  void VisitClassTemplateSpecializationDecl(
      const pasta::ClassTemplateSpecializationDecl &) {}

 private:
  std::stringstream &ss;
};

static void AccumulateTokenData(std::stringstream &ss,
                                mx::TokenKind kind, pasta::TokenRole role,
                                std::string_view data) {
  if (data.empty()) {
    return;
  }

  // Mix in generic token/structure/context information.
  switch (role) {
    case pasta::TokenRole::kIntermediateMacroExpansionToken:
      ss << " e" << int(kind);
      break;
    case pasta::TokenRole::kInitialMacroUseToken:
      ss << " u" << int(kind);
      break;

    case pasta::TokenRole::kFileToken:
      ss << " f" << int(kind);
      break;
    case pasta::TokenRole::kFinalMacroExpansionToken:
      ss << " p" << int(kind);
      break;

    default:
      return;
  }

  if (data.size() >= 8u) {
    ss << Hash64(data);
  } else if (data[0] != '_' && !isalpha(data[0])) {
    ss << data;
  } else if (isalpha(data[0])) {
    ss << data;
  }
}

static void AccumulateTokenData(
    std::stringstream &ss, const pasta::PrintedTokenRange &tokens) {

  for (pasta::PrintedToken token : tokens) {
    AccumulateTokenData(ss, mx::FromPasta(token.Kind()),
                        pasta::TokenRole::kFileToken, token.Data());

    std::stringstream tc;
    for (pasta::TokenContext context : TokenContexts(token)) {
      switch (context.Kind()) {
        case pasta::TokenContextKind::kDecl:
          tc << " d" << int(pasta::Decl::From(context)->Kind());
          break;
        case pasta::TokenContextKind::kStmt:
          tc << " s" << int(pasta::Stmt::From(context)->Kind());
          break;
        case pasta::TokenContextKind::kType:
          tc << " t" << int(pasta::Type::From(context)->Kind());
          break;
        case pasta::TokenContextKind::kAttr:
          tc << " a" << int(pasta::Attr::From(context)->Kind());
          break;
        default:
          break;
      }
    }

    ss << " c" << Hash64(tc.str());
  }
}

static std::string HashTopLevelFragment(
    const EntityMapper &em,
    const std::vector<pasta::Decl> &decls,
    const std::vector<pasta::Macro> &macros,
    const pasta::TokenRange *frag_tok_range,
    const pasta::PrintedTokenRange &decl_tok_range) {

  std::stringstream ss;

  uint64_t end_index = 0u;

  // Original tokens visible to the parser.
  if (frag_tok_range && *frag_tok_range) {
    for (pasta::Token token : *frag_tok_range) {
      end_index = token.Index();
      AccumulateTokenData(ss, mx::FromPasta(token.Kind()), token.Role(),
                          token.Data());
    }
  }

  // Pretty-printed tokens. These include token contexts. These may or may
  // not correspond to original tokens.
  if (decl_tok_range) {
    AccumulateTokenData(ss, decl_tok_range);
  }

  HashVisitor visitor(ss);

  // Mix in ODR hashes, decl kinds, and offsets of the decls. We need to mix
  // in decl kinds and offsets because not all decls have ODR hashes, and so
  // these extra bits of data add variability to help distinguish between things
  // that might only manifest as nested fragments.
  for (const pasta::Decl &decl : decls) {
    ss << " D" << int(decl.Kind());

    pasta::Token decl_token = decl.Token();
    if (frag_tok_range && frag_tok_range->Contains(decl_token)) {
      ss << " o" << (end_index - decl_token.Index());
    }

    visitor.Accept(decl);
  }

  // Mix in macro info. Note that macro uses are not integrated from the token
  // values themselves, as those aren't represented in PASTA's parsed token
  // list, so we integrate the top-level macro IDs manually.
  //
  // TODO(pag): Should really have a `MacroVisitor` in pasta, then separately
  //            visit and hash each top-level macro entity. The saving factor
  //            for now is probably that the above token hashing operates on
  //            the parsed and intermediate tokens, which is a good enough
  //            proxy.
  for (const pasta::Macro &macro : macros) {

    ss << " M" << int(macro.Kind());
    if (macro.Kind() == pasta::MacroKind::kExpansion) {
      const auto &exp = reinterpret_cast<const pasta::MacroExpansion &>(macro);
      if (auto def = exp.Definition()) {
        auto def_id = em.EntityId(def.value());
        if (def_id != mx::kInvalidEntityId) {
          ss << " E" << def_id;
          continue;
        }
      }
    }

    // NOTE(pag): We don't need to use the location of anything here because
    //            `GetOrCreateFragmentIdForHash` integrates a file token ID
    //            at a higher level.
    //
    // // Bound to the top-level macro use location in the file.
    // if (auto bt = macro.BeginToken()) {
    //   auto dl = bt->DerivedLocation();
    //   assert(!std::holds_alternative<pasta::MacroToken>(dl));
    //   if (std::holds_alternative<pasta::FileToken>(dl)) {
    //     ss << " @" << em.EntityId(std::get<pasta::FileToken>(dl));
    //   }
    // }
  }

  return ss.str();
}

static std::string HashNestedFragment(
    const EntityMapper &em, const NameMangler &,
    mx::RawEntityId parent_fid, const pasta::Decl &decl) {

  auto dk = decl.Kind();

  std::stringstream ss;
  ss << "F" << parent_fid << " d" << int(dk);

  if (auto nd = pasta::NamedDecl::From(decl)) {
    ss << " N" << nd->Name();
  }

  if (auto td = pasta::TypeDecl::From(decl)) {
    if (auto ty = td->TypeForDeclaration()) {
      AccumulateTokenData(ss, pasta::PrintedTokenRange::Create(ty.value()));
    } else {
      assert(false);
    }

  } else if (auto vd = pasta::ValueDecl::From(decl)) {
    AccumulateTokenData(ss, pasta::PrintedTokenRange::Create(vd->Type()));

  } else {
    assert(false);
  }

  return ss.str();
}

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
    const EntityMapper &em, const NameMangler &nm, const void *parent_entity,
    const std::vector<pasta::Decl> &decls,
    const std::vector<pasta::Macro> &macros,
    const pasta::TokenRange *frag_tok_range,
    const pasta::PrintedTokenRange &decl_tok_range) {

  auto parent_fid = em.ParentFragmentId(parent_entity);
  if (parent_fid != mx::kInvalidEntityId && decls.size() == 1u &&
      !pasta::TemplateDecl::From(decls.front())) {
    return HashNestedFragment(em, nm, parent_fid, decls.front());
  }

  return HashTopLevelFragment(em, decls, macros, frag_tok_range, decl_tok_range);
}

}  // namespace indexer
