// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Hash.h"

#include <cctype>
#include <multiplier/Frontend/TokenKind.h>
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
#include "TypeMapper.h"

namespace indexer {
namespace {

static void AccumulateTokenData(std::ostream &ss, mx::TokenKind kind,
                                pasta::TokenRole role, std::string_view data) {
  if (data.empty()) {
    return;
  }

  switch (kind) {
    case mx::TokenKind::UNKNOWN:
    case mx::TokenKind::WHITESPACE:
    case mx::TokenKind::COMMENT:
      return;
    default:
      break;
  }

  // Mix in generic token/structure/context information.
  switch (role) {
    case pasta::TokenRole::kIntermediateMacroExpansionToken:
      assert(false);
      return;
    case pasta::TokenRole::kInitialMacroUseToken:
      assert(false);
      return;

    case pasta::TokenRole::kFinalMacroExpansionToken:
      ss << " p" << int(kind);
      break;

    case pasta::TokenRole::kFileToken:
      ss << " f" << int(kind);
      break;

    default:
      return;
  }

  // Hashing could result in big numbers that could require many digits.
  if (data.size() > 18u) {
    ss << Hash64(data);

  // Don't include punctuation.
  } else if (data[0] != '_' && !isalpha(data[0])) {
    ss << data;

  // Keep short identifiers as is.
  } else if (isalpha(data[0])) {
    ss << data;
  }
}

static void AccumulateTokenData(
    std::ostream &ss, const pasta::PrintedTokenRange &tokens) {

  for (pasta::PrintedToken token : tokens) {
    AccumulateTokenData(ss, mx::FromPasta(token.Kind()),
                        pasta::TokenRole::kFileToken, token.Data());

    auto tc = token.Context();
    if (!tc) {
      continue;
    }

    // Only keep the most specialized token kind.
    switch (auto tc_kind = tc->Kind()) {
      case pasta::TokenContextKind::kDecl:
        ss << " d" << int(pasta::Decl::From(tc.value())->Kind());
        break;
      case pasta::TokenContextKind::kStmt:
        ss << " s" << int(pasta::Stmt::From(tc.value())->Kind());
        break;
      case pasta::TokenContextKind::kType:
        ss << " t" << int(pasta::Type::From(tc.value())->Kind());
        break;
      case pasta::TokenContextKind::kAttr:
        ss << " a" << int(pasta::Attr::From(tc.value())->Kind());
        break;
      default:
        ss << " k" << int(tc_kind);
        break;
    }
  }
}

static void OffsetFromDeclContext(
    std::ostream &ss, const EntityMapper &em, const pasta::DeclContext &dc,
    const pasta::Token &first_tok) {

  auto dc_decl = pasta::Decl::From(dc);
  if (dc_decl->Kind() == pasta::DeclKind::kTranslationUnit) {
    return;
  }

  auto dc_eid = em.EntityId(dc_decl);
  if (dc_eid != mx::kInvalidEntityId) {
    ss << " ^" << dc_eid;
  }

  auto dc_decl_loc = dc_decl->Tokens().Front();
  if (!dc_decl_loc) {
    return;
  }

  auto first = dc_decl_loc->Index();
  auto second = first_tok.Index();
  if (first < second) {
    ss << " -" << (second - first);
  }
}

// Relative position w.r.t. parent declaration context.
static void OffsetFromDeclContext(std::ostream &ss, const EntityMapper &em,
                                  const pasta::Decl &decl) {

  if (auto first_tok = decl.Tokens().Front()) {

    // NOTE(pag): Our Clang patches set the lambda lexical decl context to the
    //            translation unit.
    if (IsLambda(decl)) {
      if (auto sdc = decl.DeclarationContext()) {
        OffsetFromDeclContext(ss, em, sdc.value(), first_tok.value());
      }
    } else {
      if (auto ldc = decl.LexicalDeclarationContext()) {
        OffsetFromDeclContext(ss, em, ldc.value(), first_tok.value());
      }
    }
  }
}

class HashVisitor final : public pasta::DeclVisitor {
 private:
  std::ostream &ss;
  const EntityMapper &em;
  const bool nested;

 public:
  virtual ~HashVisitor(void) = default;

  explicit HashVisitor(std::ostream &ss_, const EntityMapper &em_, bool nested_)
      : ss(ss_),
        em(em_),
        nested(nested_) {}

  void VisitDeclContext(const pasta::Decl &dc_decl) {
    if (nested) {
      return;
    }

    auto dc = pasta::DeclContext::From(dc_decl);
    if (!dc) {
      return;
    }

    auto decls = GenerateDeclarationsInDeclContext(dc.value());
    for (const pasta::Decl &decl : decls) {
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

  // XREF(pag): Issue #318. Only integrate the ODR hash when we have a
  //            definition.
  template <typename T>
  void VisitODRHashable(const T &entity) {
    if (!nested && IsDefinition(entity)) {
      if (auto hash = entity.ODRHash()) {
        ss << " o" << hash.value();
      }
    }
  }

  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final {
    VisitODRHashable(decl);
    VisitNamedDecl(decl);
  }

  void VisitFriendTemplateDecl(const pasta::FriendTemplateDecl &decl) {
    ss << " FTD";
    Accept(decl.FriendDeclaration());
  }

  void VisitClassTemplateDecl(const pasta::ClassTemplateDecl &decl) {
    ss << " CTD";
    Accept(decl.TemplatedDeclaration());
  }

  void VisitFunctionTemplateDecl(const pasta::FunctionTemplateDecl &decl) {
    ss << " FTD";
    Accept(decl.TemplatedDeclaration());
  }

  void VisitVarTemplateDecl(const pasta::VarTemplateDecl &decl) {
    ss << " VTD";
    Accept(decl.TemplatedDeclaration());
  }

  void VisitTypeAliasTemplateDecl(const pasta::TypeAliasTemplateDecl &decl) {
    ss << " TATD";
    Accept(decl.TemplatedDeclaration());
  }

  void VisitCXXRecordDecl(const pasta::CXXRecordDecl &decl) final {
    VisitODRHashable(decl);
    VisitNamedDecl(decl);
    if (!nested && IsDefinition(decl)) {
      VisitDeclContext(decl);
    }
  }

  void VisitEnumDecl(const pasta::EnumDecl &decl) final {
    VisitODRHashable(decl);
    VisitNamedDecl(decl);
  }

  void VisitVarTemplatePartialSpecializationDecl(
      const pasta::VarTemplatePartialSpecializationDecl &decl) {
    VisitVarDecl(decl);
  }

  void VisitVarTemplateSpecializationDecl(
      const pasta::VarTemplateSpecializationDecl &decl) {
    if (nested) {
      VisitVarDecl(decl);
    }
  }

  void VisitClassTemplatePartialSpecializationDecl(
      const pasta::ClassTemplatePartialSpecializationDecl &decl) {
    VisitCXXRecordDecl(decl);
  }

  void VisitClassTemplateSpecializationDecl(
      const pasta::ClassTemplateSpecializationDecl &decl) {
    if (nested) {
      VisitCXXRecordDecl(decl);
    }
  }

  void VisitNamedDecl(const pasta::NamedDecl &decl) final;
  void VisitDecl(const pasta::Decl &decl) final;
};

class TemplateArgumentVisitor final : public EntityVisitor {
 public:
  std::ostream &ss;
  unsigned i{0u};

  inline TemplateArgumentVisitor(std::ostream &ss_)
      : ss(ss_) {}

  virtual ~TemplateArgumentVisitor(void) = default;

  void VisitDeclContext(const pasta::Decl &) final {}

  // NOTE(pag): This prevents infinite recursion.
  void VisitFriendDecl(const pasta::FriendDecl &) final {}

  bool Enter(const pasta::Attr &entity) final {
    return false;
  }
  bool Enter(const pasta::Decl &entity) final {
    return true;
  }
  bool Enter(const pasta::Stmt &entity) final {
    return false;
  }
  bool Enter(const pasta::Type &entity) final {
    return false;
  }

  using EntityVisitor::Accept;

  void Accept(const pasta::TemplateArgument &entity) final {
    ss << " A" << (i++);
    if (auto ty = entity.Type()) {
      TypePrintingPolicy pp;
      AccumulateTokenData(ss, pasta::PrintedTokenRange::Create(ty.value(), pp));
    }
  }
};

void HashVisitor::VisitNamedDecl(const pasta::NamedDecl &decl) {
  ss << " N" << decl.Name();
  VisitDecl(decl);
}

void HashVisitor::VisitDecl(const pasta::Decl &decl) {
  ss << " K" << int(decl.Kind())
     << " S" << decl.Tokens().size();

  if (decl.IsImplicit()) {
    ss << " I";
  }

  OffsetFromDeclContext(ss, em, decl);

  TypePrintingPolicy pp;

  // When hashing functions, don't include their return types. The return type
  // of a method in a class template specialization may be `auto` or similar,
  // (e.g. `decltype(auto)`), and only resolved if/when the method is used. If
  // the method isn't used, then the body won't be substituted, and thus the
  // return type won't be substituted. This largely corresponds to the name
  // mangling rules of C++: they don't encode the return type.
  if (auto fd = pasta::FunctionDecl::From(decl)) {

    // The pattern should have been indexed already.
    auto pattern_decl = TemplateInstantiationPattern(fd.value());
    if (pattern_decl) {
      ss << " T" << em.EntityId(pattern_decl.value());
    }

    unsigned p = 0u;
    for (const auto &param : fd->Parameters()) {
      ss << " P" << (p++);
      AccumulateTokenData(ss, pasta::PrintedTokenRange::Create(param.Type(), pp));
    }

  // Type, e.g. of a var, enum, etc. This allows us to ignore the body, which
  // may not have been substituted.
  } else if (auto vd = pasta::ValueDecl::From(decl)) {
    AccumulateTokenData(ss, pasta::PrintedTokenRange::Create(vd->Type(), pp));

  } else if (auto td = pasta::TypeDecl::From(decl)) {
    if (auto ty = td->TypeForDeclaration()) {
      AccumulateTokenData(ss, pasta::PrintedTokenRange::Create(ty.value(), pp));
    }
  }

  // Visit the template arguments.
  TemplateArgumentVisitor tav(ss);
  tav.Accept(decl);
}

static std::string HashNestedFragment(
    const EntityMapper &em, const pasta::Decl &decl,
    mx::RawEntityId location_eid, mx::RawEntityId parent_eid) {

  std::stringstream ss;
  ss << "P" << parent_eid;

  if (location_eid != mx::kInvalidEntityId) {
    ss << " L" << location_eid;
  }

  HashVisitor visitor(ss, em, true);
  visitor.Accept(decl);

  // std::cerr << "\n-----------------\n";
  // std::cerr << ss.str() << '\n';
  // Dump(decl);

  return ss.str();
}

static std::string HashTopLevelFragment(
    const EntityMapper &em,
    const std::vector<pasta::Decl> &decls,
    const std::vector<pasta::Macro> &macros,
    const pasta::TokenRange *frag_tok_range,
    mx::RawEntityId location_eid) {

  std::stringstream ss;

  if (location_eid != mx::kInvalidEntityId) {
    ss << "L" << location_eid;
  }

  // Original tokens visible to the parser.
  if (frag_tok_range && *frag_tok_range) {
    for (pasta::Token token : *frag_tok_range) {
      AccumulateTokenData(ss, mx::FromPasta(token.Kind()), token.Role(),
                          token.Data());
    }
  }

  HashVisitor visitor(ss, em, false);

  // Mix in ODR hashes, decl kinds, and offsets of the decls. We need to mix
  // in decl kinds and offsets because not all decls have ODR hashes, and so
  // these extra bits of data add variability to help distinguish between things
  // that might only manifest as nested fragments.
  for (const pasta::Decl &decl : decls) {
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
    const EntityMapper &em,
    mx::RawEntityId location_eid,
    const void *parent_entity,
    const std::vector<pasta::Decl> &decls,
    const std::vector<pasta::Macro> &macros,
    const pasta::TokenRange *frag_tok_range) {

  auto parent_eid = em.EntityId(parent_entity);
  if (parent_eid != mx::kInvalidEntityId && decls.size() == 1u) {
    return HashNestedFragment(em, decls.front(), location_eid, parent_eid);
  }

  return HashTopLevelFragment(em, decls, macros, frag_tok_range, location_eid);
}

}  // namespace indexer
