// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.


#include <multiplier/AST.capnp.h>
#include <multiplier/Database.h>
#include <multiplier/Entities/MacroKind.h>
#include <multiplier/RPC.capnp.h>
#include <multiplier/Types.h>
#include <pasta/AST/Forward.h>
#include <pasta/AST/Macro.h>
#include <type_traits>
#include <unordered_set>
#include <deque>

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
    inline static pasta::PseudoKind Get_Pseudo_Kind( \
        const mx::ast::Pseudo::Reader &reader, pasta::cls *) { \
      return static_cast<pasta::PseudoKind>(reader.getVal ## storage()); \
    }

#define MX_BEGIN_VISIT_DECL(name) \
    static void FindUses_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Decl::Reader &);

#define MX_BEGIN_VISIT_STMT(name) \
    static void FindUses_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Stmt::Reader &);

#define MX_BEGIN_VISIT_TYPE(name) \
    static void FindUses_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Type::Reader &);

#define MX_BEGIN_VISIT_ATTR(name) \
    static void FindUses_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Attr::Reader &);

#define MX_BEGIN_VISIT_MACRO(name) \
    static void FindUses_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Macro::Reader &);

#define MX_BEGIN_VISIT_PSEUDO(name) \
    static void FindUses_ ## name ( \
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
    void FindUses_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Decl::Reader &reader) { \
      (void) entity_ids; \
      (void) reader;

#define MX_BEGIN_VISIT_STMT(name) \
    void FindUses_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Stmt::Reader &reader) { \
      (void) entity_ids; \
      (void) reader;

#define MX_BEGIN_VISIT_TYPE(name) \
    void FindUses_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Type::Reader &reader) { \
      (void) entity_ids; \
      (void) reader;

#define MX_BEGIN_VISIT_ATTR(name) \
    void FindUses_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Attr::Reader &reader) { \
      (void) entity_ids; \
      (void) reader;

#define MX_BEGIN_VISIT_MACRO(name) \
    void FindUses_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Macro::Reader &reader) { \
      (void) entity_ids; \
      (void) reader;

#define MX_BEGIN_VISIT_PSEUDO(name) \
    void FindUses_ ## name ( \
        std::unordered_set<mx::RawEntityId> &entity_ids, \
        const mx::ast::Pseudo::Reader &reader) { \
      (void) entity_ids; \
      (void) reader;

#define MX_VISIT_BASE(name, base_name) \
    FindUses_ ## base_name (entity_ids, reader);

#define MX_VISIT_ENTITY(cls, api_name, storage, apply, \
                        pasta_name, type, nth_list, selector) \
    if constexpr (std::is_base_of_v<pasta::Decl, pasta::type>) { \
      entity_ids.insert(reader.getVal ## storage()); \
    } else if constexpr (std::is_base_of_v<pasta::File, pasta::type>) { \
      entity_ids.insert(reader.getVal ## storage()); \
    } else if constexpr (std::is_base_of_v<pasta::FileToken, pasta::type>) { \
      entity_ids.insert(reader.getVal ## storage()); \
    } else if constexpr (std::is_base_of_v<pasta::Macro, pasta::type>) { \
      entity_ids.insert(reader.getVal ## storage()); \
    } else if constexpr (std::is_base_of_v<pasta::Token, pasta::type>) { \
      entity_ids.insert(reader.getVal ## storage()); \
    } else if constexpr (std::is_base_of_v<pasta::Stmt, pasta::type>) { \
      entity_ids.insert(reader.getVal ## storage()); \
    } else if constexpr (std::is_base_of_v<pasta::Type, pasta::type>) { \
      entity_ids.insert(reader.getVal ## storage()); \
    } else if constexpr (std::is_base_of_v<pasta::Attr, pasta::type>) { \
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

template <typename Reader>
pasta::DeclKind Get_Decl_Kind(const Reader &);

template <typename Reader>
pasta::StmtKind Get_Stmt_Kind(const Reader &);

template <typename Reader>
pasta::TypeKind Get_Type_Kind(const Reader &);

template <typename Reader>
pasta::AttrKind Get_Attr_Kind(const Reader &);

template <typename Reader>
pasta::MacroKind Get_Macro_Kind(const Reader &);

template <typename Reader>
pasta::PseudoKind Get_Pseudo_Kind(const Reader &);

static void LinkExternalUses(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    std::unordered_set<mx::RawEntityId> entity_ids) {

  mx::SpecificEntityId<mx::FragmentId> fid = pf.fragment_id;
  for (mx::RawEntityId eid : entity_ids) {
    mx::VariantId vid = mx::EntityId(eid).Unpack();

    // Filter out uses of entities that are themselves located inside this
    // fragment. We always assume an entity is used within its fragment.
    if (std::holds_alternative<mx::DeclarationId>(vid)) {
      auto id = std::get<mx::DeclarationId>(vid);
      if (id.fragment_id == pf.fragment_index) {
        continue;  // Skip if same fragment.
      }
    } else if (std::holds_alternative<mx::TypeId>(vid)) {
      auto id = std::get<mx::TypeId>(vid);
      if (id.fragment_id == pf.fragment_index) {
        continue;  // Skip if same fragment.
      }
    } else if (std::holds_alternative<mx::StatementId>(vid)) {
      auto id = std::get<mx::StatementId>(vid);
      if (id.fragment_id == pf.fragment_index) {
        continue;  // Skip if same fragment.
      }
    } else if (std::holds_alternative<mx::AttributeId>(vid)) {
      auto id = std::get<mx::AttributeId>(vid);
      if (id.fragment_id == pf.fragment_index) {
        continue;  // Skip if same fragment.
      }
    } else if (std::holds_alternative<mx::MacroId>(vid)) {
      auto id = std::get<mx::MacroId>(vid);
      if (id.fragment_id == pf.fragment_index) {
        continue;  // Skip if same fragment.
      }
    } else if (std::holds_alternative<mx::FileId>(vid)) {
      // Always allow.

    } else {
      continue; // Skip the rest.
    }

    database.AddAsync(mx::UseRecord{fid, eid});
  }
}

}  // namespace

// Identify all unique entity IDs used by this fragment, and map them to the
// fragment ID in the data store.
void LinkExternalUsesInFragment(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    EntityBuilder<mx::ast::Decl> &d) {

  std::unordered_set<mx::RawEntityId> entity_ids;

  auto entity = d.builder.asReader();
#define MX_VISIT_DECL(decl) \
  case pasta::DeclKind::k ## decl: \
    FindUses_ ## decl ## Decl(entity_ids, entity); \
    break;

  // Look for declaration methods with a return value of the corresponding
  // entity ID.
  switch (Get_Decl_Kind(entity)) {
  PASTA_FOR_EACH_DECL_IMPL(MX_VISIT_DECL, PASTA_IGNORE_ABSTRACT)
  }
#undef MX_VISIT_DECL

  LinkExternalUses(database, pf, std::move(entity_ids));
}

// Identify all unique entity IDs used by this fragment, and map them to the
// fragment ID in the data store.
void LinkExternalUsesInFragment(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    EntityBuilder<mx::ast::Stmt> &s) {

  std::unordered_set<mx::RawEntityId> entity_ids;

  auto entity = s.builder.asReader();
#define MX_VISIT_STMT(stmt) \
  case pasta::StmtKind::k ## stmt: \
    FindUses_ ## stmt(entity_ids, entity); \
    break;

  // Look for statement methods with a return value of the corresponding
  // entity ID.
  switch (Get_Stmt_Kind(entity)) {
  PASTA_FOR_EACH_STMT_IMPL(MX_VISIT_STMT,
                           MX_VISIT_STMT,
                           MX_VISIT_STMT,
                           MX_VISIT_STMT,
                           MX_VISIT_STMT,
                           PASTA_IGNORE_ABSTRACT)
  }

#undef MX_VISIT_STMT

  LinkExternalUses(database, pf, std::move(entity_ids));
}

// Identify all unique entity IDs used by this fragment, and map them to the
// fragment ID in the data store.
void LinkExternalUsesInFragment(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    EntityBuilder<mx::ast::Type> &t) {

  std::unordered_set<mx::RawEntityId> entity_ids;

  auto entity = t.builder.asReader();
#define MX_VISIT_TYPE(type) \
  case pasta::TypeKind::k ## type: \
    FindUses_ ## type ## Type(entity_ids, entity); \
    break;

  // Look for type methods with a return value of the corresponding
  // entity ID.
  switch (Get_Type_Kind(entity)) {
  PASTA_FOR_EACH_TYPE_IMPL(MX_VISIT_TYPE, PASTA_IGNORE_ABSTRACT)
  }

#undef MX_VISIT_TYPE

  LinkExternalUses(database, pf, std::move(entity_ids));
}

// Identify all unique entity IDs used by this fragment, and map them to the
// fragment ID in the data store.
void LinkExternalUsesInFragment(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    EntityBuilder<mx::ast::Attr> &a) {

  std::unordered_set<mx::RawEntityId> entity_ids;

  auto entity = a.builder.asReader();
#define MX_VISIT_ATTR(type) \
  case pasta::AttrKind::k ## type: \
    FindUses_ ## type ## Attr(entity_ids, entity); \
    break;

  // Look for type methods with a return value of the corresponding
  // attribute ID.
  switch (Get_Attr_Kind(entity)) {
  PASTA_FOR_EACH_ATTR_IMPL(MX_VISIT_ATTR, PASTA_IGNORE_ABSTRACT)
  }

#undef MX_VISIT_ATTR

  LinkExternalUses(database, pf, std::move(entity_ids));
}

// Identify all unique entity IDs used by this fragment, and map them to the
// fragment ID in the data store.
void LinkExternalUsesInFragment(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    EntityBuilder<mx::ast::Macro> &m) {

  std::unordered_set<mx::RawEntityId> entity_ids;

  // Look for macro methods with a return value of the corresponding
  // entity ID.
  auto entity = m.builder.asReader();

  // We need to manually do these because some of the macro kinds are invented
  // inside of Multiplier, and not present in PASTA.
  switch (static_cast<mx::MacroKind>(Get_Macro_Kind(entity))) {
    case mx::MacroKind::SUBSTITUTION:
      FindUses_MacroSubstitution(entity_ids, entity);
      break;
    case mx::MacroKind::EXPANSION:
      FindUses_MacroExpansion(entity_ids, entity);
      break;
    case mx::MacroKind::ARGUMENT:
      FindUses_MacroArgument(entity_ids, entity);
      break;
    case mx::MacroKind::PARAMETER:
      FindUses_MacroParameter(entity_ids, entity);
      break;
    case mx::MacroKind::OTHER_DIRECTIVE:
      FindUses_OtherMacroDirective(entity_ids, entity);
      break;
    case mx::MacroKind::IF_DIRECTIVE:
      FindUses_IfMacroDirective(entity_ids, entity);
      break;
    case mx::MacroKind::IF_DEFINED_DIRECTIVE:
      FindUses_IfDefinedMacroDirective(entity_ids, entity);
      break;
    case mx::MacroKind::IF_NOT_DEFINED_DIRECTIVE:
      FindUses_IfNotDefinedMacroDirective(entity_ids, entity);
      break;
    case mx::MacroKind::ELSE_IF_DIRECTIVE:
      FindUses_ElseIfMacroDirective(entity_ids, entity);
      break;
    case mx::MacroKind::ELSE_IF_DEFINED_DIRECTIVE:
      FindUses_ElseIfDefinedMacroDirective(entity_ids, entity);
      break;
    case mx::MacroKind::ELSE_IF_NOT_DEFINED_DIRECTIVE:
      FindUses_ElseIfNotDefinedMacroDirective(entity_ids, entity);
      break;
    case mx::MacroKind::ELSE_DIRECTIVE:
      FindUses_ElseMacroDirective(entity_ids, entity);
      break;
    case mx::MacroKind::END_IF_DIRECTIVE:
      FindUses_EndIfMacroDirective(entity_ids, entity);
      break;
    case mx::MacroKind::DEFINE_DIRECTIVE:
      FindUses_DefineMacroDirective(entity_ids, entity);
      break;
    case mx::MacroKind::UNDEFINE_DIRECTIVE:
      FindUses_UndefineMacroDirective(entity_ids, entity);
      break;
    case mx::MacroKind::PRAGMA_DIRECTIVE:
      FindUses_PragmaMacroDirective(entity_ids, entity);
      break;
    case mx::MacroKind::INCLUDE_DIRECTIVE:
      FindUses_IncludeMacroDirective(entity_ids, entity);
      break;
    case mx::MacroKind::INCLUDE_NEXT_DIRECTIVE:
      FindUses_IncludeNextMacroDirective(entity_ids, entity);
      break;
    case mx::MacroKind::INCLUDE_MACROS_DIRECTIVE:
      FindUses_IncludeMacrosMacroDirective(entity_ids, entity);
      break;
    case mx::MacroKind::IMPORT_DIRECTIVE:
      FindUses_ImportMacroDirective(entity_ids, entity);
      break;
    case mx::MacroKind::STRINGIFY:
      FindUses_MacroStringify(entity_ids, entity);
      break;
    case mx::MacroKind::CONCATENATE:
      FindUses_MacroConcatenate(entity_ids, entity);
      break;
    case mx::MacroKind::VA_OPT:
      FindUses_MacroVAOpt(entity_ids, entity);
      break;
    case mx::MacroKind::VA_OPT_ARGUMENT:
      FindUses_MacroVAOptArgument(entity_ids, entity);
      break;
  }

  LinkExternalUses(database, pf, std::move(entity_ids));
}

// Identify all unique entity IDs used by this fragment, and map them to the
// fragment ID in the data store.
void LinkExternalUsesInFragment(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    EntityBuilder<mx::ast::Pseudo> &p) {

  std::unordered_set<mx::RawEntityId> entity_ids;

  pasta::TemplateArgument *tag = nullptr;
  auto entity = p.builder.asReader();
#define MX_VISIT_PSEUDO(pseudo) \
  case pasta::PseudoKind::k ## pseudo: \
    FindUses_ ## pseudo(entity_ids, entity); \
    break;

  // Look for pseudo-entity methods with a return value of the corresponding
  // entity ID.
  switch (Get_Pseudo_Kind(entity, tag)) {
    PSEUDO_ENTITY_TYPES(MX_VISIT_PSEUDO)
  }

#undef MX_VISIT_PSEUDO

  LinkExternalUses(database, pf, std::move(entity_ids));
}

}  // namespace indexer
