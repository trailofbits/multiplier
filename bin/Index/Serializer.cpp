// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Serializer.h"

#include <cassert>
#include <glog/logging.h>
#include <pasta/AST/Token.h>

#include "Serialize.h"

namespace indexer {
namespace {

}  // namespace


void EntitySerializer::VisitDeclContext(const pasta::DeclContext &dc) {
  for (const auto &decl : dc.AlreadyLoadedDeclarations()) {
    this->DeclVisitor::Accept(decl);
  }
}

void EntitySerializer::VisitTranslationUnitDecl(
    const pasta::TranslationUnitDecl &decl) {
  assert(false);
  VisitDeclContext(decl);
}

void EntitySerializer::VisitNamespaceDecl(
    const pasta::NamespaceDecl &decl) {
  assert(false);
  VisitDeclContext(decl);
}

void EntitySerializer::VisitExternCContextDecl(
    const pasta::ExternCContextDecl &decl) {
  assert(false);
  VisitDeclContext(decl);
}

void EntitySerializer::VisitLinkageSpecDecl(
    const pasta::LinkageSpecDecl &decl) {
  assert(false);
  VisitDeclContext(decl);
}

void EntitySerializer::VisitClassTemplatePartialSpecializationDecl(
    const pasta::ClassTemplatePartialSpecializationDecl &) {}

void EntitySerializer::VisitVarTemplatePartialSpecializationDecl(
    const pasta::VarTemplatePartialSpecializationDecl &) {}

void EntitySerializer::VisitClassTemplateDecl(
    const pasta::ClassTemplateDecl &) {}

void EntitySerializer::VisitVarTemplateDecl(const pasta::VarTemplateDecl &) {}

void EntitySerializer::VisitFunctionTemplateDecl(
    const pasta::FunctionTemplateDecl &) {}

void EntitySerializer::VisitVarDecl(const pasta::VarDecl &decl) {
  if (Serialize(decl)) {
    if (auto init_expr = decl.Initializer()) {
      this->StmtVisitor::Accept(*init_expr);
    }
  }
}

void EntitySerializer::VisitParmVarDecl(const pasta::ParmVarDecl &decl) {
  if (Serialize(decl)) {
    if (!decl.HasUninstantiatedDefaultArgument() &&
        !decl.HasUnparsedDefaultArgument()) {
      if (auto init_expr = decl.DefaultArgument()) {
        this->StmtVisitor::Accept(*init_expr);
      }
    }
  }
}

void EntitySerializer::VisitFunctionDecl(const pasta::FunctionDecl &decl) {
  if (Serialize(decl)) {
    VisitDeclContext(decl);
    for (pasta::ParmVarDecl param : decl.Parameters()) {
      this->DeclVisitor::Accept(param);
    }
    if (decl.DoesThisDeclarationHaveABody()) {
      this->StmtVisitor::Accept(decl.Body());
    }
  }
}

void EntitySerializer::VisitFieldDecl(const pasta::FieldDecl &decl) {
  if (Serialize(decl)) {
    if (auto bit_width = decl.BitWidth()) {
      this->StmtVisitor::Accept(*bit_width);
    }
    if (auto init = decl.InClassInitializer()) {
      this->StmtVisitor::Accept(*init);
    }
  }
}

// Structs, unions, etc.
void EntitySerializer::VisitRecordDecl(const pasta::RecordDecl &decl) {
  if (Serialize(decl)) {
    VisitDeclContext(decl);
    for (pasta::FieldDecl field : decl.Fields()) {
      this->DeclVisitor::Accept(field);
    }
  }
}

void EntitySerializer::VisitEnumConstantDecl(const pasta::EnumConstantDecl &decl) {
  if (Serialize(decl)) {
    if (auto init = decl.InitializerExpression()) {
      this->StmtVisitor::Accept(*init);
    }
  }
}

// Enumerators.
void EntitySerializer::VisitEnumDecl(const pasta::EnumDecl &decl) {
  if (Serialize(decl)) {
    VisitDeclContext(decl);
    for (pasta::EnumConstantDecl enumerator : decl.Enumerators()) {
      this->DeclVisitor::Accept(enumerator);
    }
  }
}

void EntitySerializer::VisitGCCAsmStmt(const pasta::GCCAsmStmt &stmt) {
  if (Serialize(stmt)) {
    for (auto child : stmt.InputConstraintLiterals()) {
      this->StmtVisitor::Accept(child);
    }
    for (auto child : stmt.InputExpressions()) {
      this->StmtVisitor::Accept(child);
    }
    for (auto child : stmt.OutputConstraintLiterals()) {
      this->StmtVisitor::Accept(child);
    }
    for (auto child : stmt.OutputExpressions()) {
      this->StmtVisitor::Accept(child);
    }
    for (auto child : stmt.Children()) {
      this->StmtVisitor::Accept(child);
    }
  }
}

void EntitySerializer::VisitMSAsmStmt(const pasta::MSAsmStmt &stmt) {
  if (Serialize(stmt)) {
    for (auto child : stmt.AllExpressions()) {
      this->StmtVisitor::Accept(child);
    }
    for (auto child : stmt.InputExpressions()) {
      this->StmtVisitor::Accept(child);
    }
  }
}

void EntitySerializer::VisitBreakStmt(const pasta::BreakStmt &stmt) {
  if (Serialize(stmt)) {
    for (auto child : stmt.Children()) {
      this->StmtVisitor::Accept(child);
    }
  }
}

void EntitySerializer::VisitCompoundStmt(const pasta::CompoundStmt &stmt) {
  if (Serialize(stmt)) {
    for (pasta::Stmt child : stmt.Children()) {
      this->StmtVisitor::Accept(child);
    }
  }
}

void EntitySerializer::VisitTypedefNameDecl(const pasta::TypedefNameDecl &decl) {
  if (Serialize(decl)) {
    if (auto tag = decl.AnonymousDeclarationWithTypedefName()) {
      this->DeclVisitor::Accept(*tag);
    }
  }
}

// Backups.
void EntitySerializer::VisitDecl(const pasta::Decl &decl) {
  (void) Serialize(decl);
}

void EntitySerializer::VisitStmt(const pasta::Stmt &stmt) {
  if (Serialize(stmt)) {
    for (auto child : stmt.Children()) {
      Serialize(child);
    }
  }
}

uint64_t EntitySerializer::EntityId(const pasta::Decl &entity) const {
  if (auto it = entity_ids.find(entity.RawDecl()); it != entity_ids.end()) {
    return it->second;
  } else {
    return mx::kInvalidEntityId;
  }
}

uint64_t EntitySerializer::EntityId(const pasta::Stmt &entity) const {
  if (auto it = entity_ids.find(entity.RawStmt()); it != entity_ids.end()) {
    return it->second;
  } else {
    return mx::kInvalidEntityId;
  }
}

uint64_t EntitySerializer::EntityId(const pasta::Token &entity) const {
  if (auto it = entity_ids.find(entity.RawToken()); it != entity_ids.end()) {
    return it->second;
  } else {
    return mx::kInvalidEntityId;
  }
}

bool EntitySerializer::Serialize(const pasta::Decl &entity) {

  // Only serialize if we have a valid entity ID for this.
  const uint64_t id = EntityId(entity);
  if (!id) {
    return false;
  }

  // Don't re-serialize if we've done it already.
  if (!serialized_entities.emplace(id).second) {
    return false;
  }

  mx::EntityId ent_id(id);
  mx::VariantId unpacked_id = ent_id.Unpack();
  CHECK(std::holds_alternative<mx::DeclarationId>(unpacked_id));
  mx::DeclarationId decl_id = std::get<mx::DeclarationId>(unpacked_id);

  // This entity doesn't belong in this code chunk. Not sure if/when this will
  // happen.
  if (decl_id.code_id != code_id) {
    DLOG(ERROR)
        << "Attempting to serialize into wrong entity list";
    return false;
  }

  auto offset = decl_id.offset;
  switch (entity.Kind()) {
#define MX_SERIALIZE_DECL(decl) \
    case pasta::DeclKind::k ## decl: { \
      Serialize ## decl ## Decl(*this, decl ## Decl_builder[offset], pasta::decl ## Decl::From(entity).value()); \
      return true; \
    }

    PASTA_FOR_EACH_DECL_IMPL(MX_SERIALIZE_DECL, PASTA_IGNORE_ABSTRACT)

#undef MX_SERIALIZE_DECL
    default:
      return false;
  }
}

bool EntitySerializer::Serialize(const pasta::Stmt &entity) {

  // Only serialize if we have a valid entity ID for this.
  const uint64_t id = EntityId(entity);
  if (!id) {
    return false;
  }

  // Don't re-serialize if we've done it already.
  if (!serialized_entities.emplace(id).second) {
    return false;
  }

  mx::EntityId ent_id(id);
  mx::VariantId unpacked_id = ent_id.Unpack();
  CHECK(std::holds_alternative<mx::StatementId>(unpacked_id));
  mx::StatementId stmt_id = std::get<mx::StatementId>(unpacked_id);

  // This entity doesn't belong in this code chunk. Not sure if/when this will
  // happen.
  if (stmt_id.code_id != code_id) {
    DLOG(ERROR)
        << "Attempting to serialize into wrong entity list";
    return false;
  }

  auto offset = stmt_id.offset;
  switch (entity.Kind()) {
#define MX_SERIALIZE_STMT(stmt) \
    case pasta::StmtKind::k ## stmt: { \
      Serialize ## stmt(*this, stmt ## _builder[offset], pasta::stmt::From(entity).value()); \
      return true; \
    }
    PASTA_FOR_EACH_STMT_IMPL(MX_SERIALIZE_STMT,
                             MX_SERIALIZE_STMT,
                             MX_SERIALIZE_STMT,
                             MX_SERIALIZE_STMT,
                             MX_SERIALIZE_STMT,
                             PASTA_IGNORE_ABSTRACT)
#undef MX_SERIALIZE_STMT
    default:
      return false;
  }
}

void EntitySerializer::Serialize(mx::ast::Token::Builder token,
                                 const pasta::Token &entity) {
  std::string data(entity.Data().data(), entity.Data().size());
  token.setKind(static_cast<mx::ast::TokenKind>(mx::FromPasta(entity.Kind())));
  token.setData(data);
}

}  // namespace indexer
