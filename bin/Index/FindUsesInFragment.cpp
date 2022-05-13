// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.


#include <pasta/AST/Forward.h>
#include <type_traits>

#include "Context.h"
#include "EntityMapper.h"
#include "NameMangler.h"
#include "PendingFragment.h"
#include "Pseudo.h"

namespace indexer {
namespace {

#define MX_SERIALIZE_ENUM(cls, api_name, get, set, init, \
                          pasta_name, type, nth_list) \
    template <typename Reader> \
    inline static pasta::type Get_ ## cls ## _ ## pasta_name(const Reader &reader) { \
      return static_cast<pasta::type>(reader.get()); \
    }

#define MX_SERIALIZE_PSEUDO_KIND(cls, get, set) \
    inline static pasta::PseudoEntityKind Get_PseudoEntityKind( \
        const mx::ast::Pseudo::Reader &reader, pasta::cls *) { \
      return static_cast<pasta::PseudoEntityKind>(reader.get()); \
    }

#define MX_BEGIN_SERIALIZE_DECL(name) \
    static void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Decl::Reader &);

#define MX_BEGIN_SERIALIZE_STMT(name) \
    static void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Stmt::Reader &);

#define MX_BEGIN_SERIALIZE_TYPE(name) \
    static void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Type::Reader &);

#define MX_BEGIN_SERIALIZE_PSEUDO(name) \
    static void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Pseudo::Reader &);

#include "Visitor.inc.h"

#define MX_END_SERIALIZE_DECL(name) }
#define MX_END_SERIALIZE_STMT MX_END_SERIALIZE_DECL
#define MX_END_SERIALIZE_TYPE MX_END_SERIALIZE_DECL
#define MX_END_SERIALIZE_PSEUDO MX_END_SERIALIZE_DECL

#define MX_BEGIN_SERIALIZE_DECL(name) \
    void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Decl::Reader &reader) {

#define MX_BEGIN_SERIALIZE_STMT(name) \
    void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Stmt::Reader &reader) {

#define MX_BEGIN_SERIALIZE_TYPE(name) \
    void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Type::Reader &reader) {

#define MX_BEGIN_SERIALIZE_PSEUDO(name) \
    void FindReferences_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Pseudo::Reader &reader) {

#define MX_SERIALIZE_BASE(name, base_name) \
    FindReferences_ ## base_name (entity_ids, reader);

#define MX_SERIALIZE_ENTITY(cls, api_name, get, set, init, \
                            pasta_name, type, nth_list) \
    if constexpr (std::is_base_of_v<pasta::Decl, pasta::type>) { \
      entity_ids.insert(reader.get()); \
    }

#define MX_SERIALIZE_OPTIONAL_ENTITY MX_SERIALIZE_ENTITY

#define MX_SERIALIZE_ENTITY_LIST(cls, api_name, get, set, init, \
                                 pasta_name, type, nth_list) \
    if constexpr (std::is_base_of_v<pasta::Decl, pasta::type>) { \
      for (auto eid : reader.get()) { \
        entity_ids.insert(eid); \
      } \
    }

#include "Visitor.inc.h"


}  // namespace

// Identify all unique entity IDs used by this fragment, and map them to the
// fragment ID in the data store.
void PendingFragment::FindDeclarationUses(
    IndexingContext &context, mx::FragmentId fragment_id,
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

  // Look for pseudo-entity methods with a return value of the corresponding
  // entity ID.
  pasta::TemplateArgument *tag = nullptr;
  for (mx::ast::Pseudo::Reader entity : b.getOthers().asReader()) {
#define MX_VISIT_PSEUDO(pseudo) \
    case pasta::PseudoEntityKind::k ## pseudo: \
      FindReferences_ ## pseudo(entity_ids, entity); \
      break;

    switch (Get_PseudoEntityKind(entity, tag)) {
      PSEUDO_ENTITY_TYPES(MX_VISIT_PSEUDO)
    }

#undef MX_VISIT_PSEUDO
  }

  for (mx::RawEntityId eid : entity_ids) {
    mx::VariantId vid = mx::EntityId(eid).Unpack();
    if (std::holds_alternative<mx::DeclarationId>(vid)) {
      context.LinkUseInFragment(eid, fragment_id);
    }
  }
}

}  // namespace indexer
