// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <map>
#include <multiplier/AST.capnp.h>
#include <multiplier/Types.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Forward.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <unordered_map>
#include <unordered_set>

namespace indexer {

using EntityIdMap = std::unordered_map<const void *, mx::EntityId>;

// Summary information about a group of top-level declarations that are
// somehow lexically/syntactically "stuck together" and thus serialized
// together. For example, `int optind, opterr, optopt;` is one example of
// being syntactically stuck together. Another example would be a C macro
// that expands into two separate top-level declarations. We don't want to
// break this macro expansion into two, as in the original source file it
// represents a single logical thing.
struct CodeChunk {
  mx::CodeId code_id;
  std::vector<pasta::Decl> decls;
  uint64_t begin_index;
  uint64_t end_index;
  std::map<pasta::DeclKind, unsigned> num_decls_of_kind;
  std::map<pasta::StmtKind, unsigned> num_stmts_of_kind;
};

class EntitySerializer final : protected pasta::DeclVisitor,
                               protected pasta::StmtVisitor {
 private:
  const pasta::TokenRange range;
  const EntityIdMap entity_ids;
  mx::CodeId code_id;
  std::unordered_set<uint64_t> serialized_entities;
  mx::ast::EntityList::Builder *builder{nullptr};

#define MX_DECLARE_DECL_LIST_BUILDER(decl) \
    ::capnp::List<::mx::ast::decl ## Decl, ::capnp::Kind::STRUCT>::Builder decl ## _builder;

#define MX_DECLARE_STMT_LIST_BUILDER(stmt) \
    ::capnp::List<::mx::ast::stmt, ::capnp::Kind::STRUCT>::Builder stmt ## _builder;

  PASTA_FOR_EACH_DECL_IMPL(MX_DECLARE_DECL_LIST_BUILDER, PASTA_IGNORE_ABSTRACT)
  PASTA_FOR_EACH_STMT_IMPL(MX_DECLARE_STMT_LIST_BUILDER,
                           MX_DECLARE_STMT_LIST_BUILDER,
                           MX_DECLARE_STMT_LIST_BUILDER,
                           MX_DECLARE_STMT_LIST_BUILDER,
                           MX_DECLARE_STMT_LIST_BUILDER,
                           PASTA_IGNORE_ABSTRACT)

#undef MX_DECLARE_STMT_LIST_BUILDER
#undef MX_DECLARE_DECL_LIST_BUILDER

  void VisitDeclContext(const pasta::DeclContext &dc);
  void VisitTranslationUnitDecl(const pasta::TranslationUnitDecl &decl) final;
  void VisitNamespaceDecl(const pasta::NamespaceDecl &decl) final;
  void VisitExternCContextDecl(const pasta::ExternCContextDecl &decl) final;
  void VisitLinkageSpecDecl(const pasta::LinkageSpecDecl &decl) final;
  void VisitClassTemplatePartialSpecializationDecl(
      const pasta::ClassTemplatePartialSpecializationDecl &) final;
  void VisitVarTemplatePartialSpecializationDecl(
      const pasta::VarTemplatePartialSpecializationDecl &) final;
  void VisitClassTemplateDecl(const pasta::ClassTemplateDecl &) final;
  void VisitVarTemplateDecl(const pasta::VarTemplateDecl &) final;
  void VisitFunctionTemplateDecl(const pasta::FunctionTemplateDecl &) final;
  void VisitVarDecl(const pasta::VarDecl &decl) final;
  void VisitParmVarDecl(const pasta::ParmVarDecl &decl) final;
  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final;
  void VisitFieldDecl(const pasta::FieldDecl &decl) final;
  void VisitRecordDecl(const pasta::RecordDecl &decl) final;
  void VisitEnumConstantDecl(const pasta::EnumConstantDecl &decl) final;
  void VisitEnumDecl(const pasta::EnumDecl &decl) final;
  void VisitGCCAsmStmt(const pasta::GCCAsmStmt &stmt) final;
  void VisitMSAsmStmt(const pasta::MSAsmStmt &stmt) final;
  void VisitBreakStmt(const pasta::BreakStmt &stmt) final;
  void VisitCompoundStmt(const pasta::CompoundStmt &stmt) final;
  void VisitTypedefNameDecl(const pasta::TypedefNameDecl &decl) final;
  void VisitDecl(const pasta::Decl &decl) final;
  void VisitStmt(const pasta::Stmt &stmt) final;

 public:
  inline EntitySerializer(pasta::TokenRange range_, EntityIdMap entity_ids_)
      : range(std::move(range_)),
        entity_ids(std::move(entity_ids_)),
        code_id(mx::kInvalidEntityId) {}

  void SerializeCodeEntities(
      const CodeChunk &code, mx::ast::EntityList::Builder entities);

  uint64_t EntityId(const pasta::Decl &entity) const;
  uint64_t EntityId(const pasta::Stmt &entity) const;
  uint64_t EntityId(const pasta::Token &entity) const;

  bool Serialize(const pasta::Decl &entity);
  bool Serialize(const pasta::Stmt &entity);
  bool Serialize(const pasta::Token &entity);
};

}  // namespace indexer
