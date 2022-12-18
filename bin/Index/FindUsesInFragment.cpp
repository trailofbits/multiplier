// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.


#include <pasta/AST/Forward.h>
#include <type_traits>

#include "EntityMapper.h"
#include "NameMangler.h"
#include "PendingFragment.h"
#include "Pseudo.h"

namespace indexer {
namespace {

#define MX_VISIT_ENUM(cls, api_name, storage, apply, \
                      pasta_name, type, nth_list) \
    template <typename Reader> \
    inline static pasta::type Get_ ## cls ## _ ## pasta_name(const Reader &reader) { \
      return static_cast<pasta::type>(reader.getVal ## storage()); \
    }

#define MX_VISIT_PSEUDO_KIND(cls, storage) \
    inline static pasta::PseudoKind Get_PseudoKind( \
        const mx::ast::Pseudo::Reader &reader, pasta::cls *) { \
      return static_cast<pasta::PseudoKind>(reader.getVal ## storage()); \
    }

#define MX_BEGIN_VISIT_DECL(name) \
    static void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Decl::Reader &);

#define MX_BEGIN_VISIT_STMT(name) \
    static void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Stmt::Reader &);

#define MX_BEGIN_VISIT_TYPE(name) \
    static void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Type::Reader &);

#define MX_BEGIN_VISIT_ATTR(name) \
    static void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Attr::Reader &);

#define MX_BEGIN_VISIT_MACRO(name) \
    static void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Macro::Reader &);

#define MX_BEGIN_VISIT_PSEUDO(name) \
    static void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Pseudo::Reader &);

#include <multiplier/Visitor.inc.h>

#define MX_END_VISIT_DECL(name) }
#define MX_END_VISIT_STMT MX_END_VISIT_DECL
#define MX_END_VISIT_TYPE MX_END_VISIT_DECL
#define MX_END_VISIT_ATTR MX_END_VISIT_DECL
#define MX_END_VISIT_MACRO MX_END_VISIT_DECL
#define MX_END_VISIT_PSEUDO MX_END_VISIT_DECL

#define MX_BEGIN_VISIT_DECL(name) \
    void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Decl::Reader &reader) { \
      (void) entity_ids; \
      (void) reader;

#define MX_BEGIN_VISIT_STMT(name) \
    void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Stmt::Reader &reader) { \
      (void) entity_ids; \
      (void) reader;

#define MX_BEGIN_VISIT_TYPE(name) \
    void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Type::Reader &reader) { \
      (void) entity_ids; \
      (void) reader;

#define MX_BEGIN_VISIT_ATTR(name) \
    void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Attr::Reader &reader) { \
      (void) entity_ids; \
      (void) reader;

#define MX_BEGIN_VISIT_MACRO(name) \
    void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Macro::Reader &reader) { \
      (void) entity_ids; \
      (void) reader;

#define MX_BEGIN_VISIT_PSEUDO(name) \
    void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Pseudo::Reader &reader) { \
      (void) entity_ids; \
      (void) reader;

#define MX_VISIT_BASE(name, base_name) \
    FindReferences_ ## base_name (entity_ids, reader);

#define MX_VISIT_ENTITY(cls, api_name, storage, apply, \
                        pasta_name, type, nth_list, selector) \
    if constexpr (std::is_base_of_v<pasta::Decl, pasta::type>) { \
      entity_ids.insert(reader.getVal ## storage()); \
    }

#define MX_VISIT_OPTIONAL_ENTITY MX_VISIT_ENTITY

//#define MX_VISIT_ENTITY_LIST(cls, api_name, storage, apply,
//                             pasta_name, type, nth_list)
//    if constexpr (std::is_base_of_v<pasta::Decl, pasta::type>) {
//      for (auto eid : reader.get()) {
//        entity_ids.insert(eid);
//      }
//    }

#include <multiplier/Visitor.inc.h>


}  // namespace

// Identify all unique entity IDs used by this fragment, and map them to the
// fragment ID in the data store.
void PendingFragment::FindDeclarationUses(
    WorkerId worker_id, GlobalIndexingState &context,
    mx::rpc::Fragment::Builder &b) {

  std::unordered_set<mx::RawEntityId> entity_ids;

  // Look for declaration methods with a return value of the corresponding
  // entity ID.
  for (mx::ast::Decl::Reader entity : b.getDeclarations().asReader()) {
#define MX_VISIT_DECL(decl) \
    case pasta::DeclKind::k ## decl: \
      FindReferences_ ## decl ## Decl(entity_ids, entity); \
      break;

    switch (Get_Decl_Kind(entity)) {
    PASTA_FOR_EACH_DECL_IMPL(MX_VISIT_DECL, PASTA_IGNORE_ABSTRACT)
    }
#undef MX_VISIT_DECL
  }

  // Look for statement methods with a return value of the corresponding
  // entity ID.
  for (mx::ast::Stmt::Reader entity : b.getStatements().asReader()) {
#define MX_VISIT_STMT(stmt) \
    case pasta::StmtKind::k ## stmt: \
      FindReferences_ ## stmt(entity_ids, entity); \
      break;

    switch (Get_Stmt_Kind(entity)) {
    PASTA_FOR_EACH_STMT_IMPL(MX_VISIT_STMT,
                             MX_VISIT_STMT,
                             MX_VISIT_STMT,
                             MX_VISIT_STMT,
                             MX_VISIT_STMT,
                             PASTA_IGNORE_ABSTRACT)
    }

#undef MX_VISIT_STMT
  }

  // Look for type methods with a return value of the corresponding
  // entity ID.
  for (mx::ast::Type::Reader entity : b.getTypes().asReader()) {
#define MX_VISIT_TYPE(type) \
    case pasta::TypeKind::k ## type: \
      FindReferences_ ## type ## Type(entity_ids, entity); \
      break;

    switch (Get_Type_Kind(entity)) {
    PASTA_FOR_EACH_TYPE_IMPL(MX_VISIT_TYPE, PASTA_IGNORE_ABSTRACT)
    }

#undef MX_VISIT_TYPE
  }

  // Look for type methods with a return value of the corresponding
  // entity ID.
  for (mx::ast::Attr::Reader entity : b.getAttributes().asReader()) {
#define MX_VISIT_ATTR(type) \
    case pasta::AttrKind::k ## type: \
      FindReferences_ ## type ## Attr(entity_ids, entity); \
      break;

    switch (Get_Attr_Kind(entity)) {
    PASTA_FOR_EACH_ATTR_IMPL(MX_VISIT_ATTR, PASTA_IGNORE_ABSTRACT)
    }

#undef MX_VISIT_ATTR
  }

  // Look for macro methods with a return value of the corresponding
  // entity ID.
  for (mx::ast::Macro::Reader entity : b.getMacros().asReader()) {
#define MX_VISIT_MACRO(type) \
    case pasta::MacroKind::k ## type: \
      FindReferences_Macro ## type(entity_ids, entity); \
      break;

#define MX_VISIT_DIRECTIVE(type) \
    case pasta::MacroKind::k ## type ## Directive: \
      FindReferences_ ## type ## MacroDirective(entity_ids, entity); \
      break;

    switch (Get_Macro_Kind(entity)) {

      // We turn `pasta::MacroToken` into `mx::Token`, as there's a one-to-one
      // correspondence between a `pasta::MacroToken` and a `pasta::Token`.
      case pasta::MacroKind::kToken:
        break;

    PASTA_FOR_EACH_MACRO_IMPL(MX_VISIT_MACRO, PASTA_IGNORE_ABSTRACT,
                              MX_VISIT_DIRECTIVE, MX_VISIT_DIRECTIVE,
                              MX_VISIT_DIRECTIVE, MX_VISIT_DIRECTIVE,
                              PASTA_IGNORE_ABSTRACT)
    }

#undef MX_VISIT_DIRECTIVE
#undef MX_VISIT_MACRO
  }

  // Look for pseudo-entity methods with a return value of the corresponding
  // entity ID.
  pasta::TemplateArgument *tag = nullptr;
  for (mx::ast::Pseudo::Reader entity : b.getOthers().asReader()) {
#define MX_VISIT_PSEUDO(pseudo) \
    case pasta::PseudoKind::k ## pseudo: \
      FindReferences_ ## pseudo(entity_ids, entity); \
      break;

    switch (Get_PseudoKind(entity, tag)) {
      PSEUDO_ENTITY_TYPES(MX_VISIT_PSEUDO)
    }

#undef MX_VISIT_PSEUDO
  }

  for (mx::RawEntityId eid : entity_ids) {
    mx::VariantId vid = mx::EntityId(eid).Unpack();
    if (std::holds_alternative<mx::DeclarationId>(vid)) {
      context.LinkUseInFragment(worker_id, eid, fragment_id);
    }
  }
}

}  // namespace indexer
