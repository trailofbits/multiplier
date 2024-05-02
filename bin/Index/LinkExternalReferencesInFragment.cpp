// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <multiplier/Database.h>
#include <multiplier/Frontend/MacroKind.h>
#include <multiplier/Types.h>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Stmt.h>
#include <pasta/Util/File.h>
#include <span>
#include <unordered_set>

#include "EntityMapper.h"
#include "PASTA.h"
#include "PendingFragment.h"
#include "References.h"
#include "TokenTree.h"
#include "Util.h"

#include <iostream>

namespace indexer {
namespace {

template <typename Entity>
static void AddDeclReferenceFrom(
    const pasta::AST &ast, mx::DatabaseWriter &database, const EntityMapper &em,
    const Entity &from_entity, mx::RawEntityId from_id,
    const pasta::Decl &to_entity, mx::BuiltinReferenceKind default_kind) {

  auto to_id = em.EntityId(to_entity);
  if (!mx::EntityId(to_id).Extract<mx::DeclId>()) {
    assert(false);
    return;
  }

  // The referer context id will be same as `from_id` by default. The
  // DeclReferenceKind function updates it based on the AST analysis
  // of the context in which declaration is referred.
  mx::ReferenceRecord record{from_id, to_id, from_id, default_kind};
  DeclReferenceKind(ast, em, from_entity, to_entity, record);
  // std::cerr << mx::EnumeratorName(record.kind) << " " << record.from_entity_id
  //           << " -> " << record.to_entity_id << '\n'; 
  database.AddAsync(record);
}

template <typename EntityId, typename EntityKindListMap,
          typename ReferenceEnumerator>
static void AddDeclReferencesFrom(
    const pasta::AST &ast, mx::DatabaseWriter &database,
    const PendingFragment &pf,
    const EntityKindListMap &entities,
    ReferenceEnumerator enumerate_records) {

  for (const auto &from_entity : Entities(entities)) {
    mx::RawEntityId from_id = pf.em.EntityId(from_entity);
    auto from_eid = mx::EntityId(from_id).Extract<EntityId>();
    if (!from_eid) {
      assert(false);
      continue;
    }

    if (from_eid->fragment_id != pf.fragment_index) {
      assert(false);
      continue;  // This is weird?
    }

    for (auto to_entity : DeclReferencesFrom(from_entity)) {
      for (auto record : enumerate_records(ast, &(pf.em), from_entity,
                                           to_entity)) {
        database.AddAsync(record);
      }
    }
  }
}

// Add C++ base specifier extension relationships to the database.
static void AddBaseSpecifierReferenceFrom(
    const EntityMapper &em, mx::DatabaseWriter &database,
    const pasta::CXXBaseSpecifier &spec) {
  
  auto raw_spec_id = em.EntityId(spec);

  auto raw_cls_id = em.ParentDeclId(spec);
  auto cls_id = mx::EntityId(raw_cls_id).Extract<mx::DeclId>();
  if (!cls_id) {
    return;
  }

  auto base_cls = spec.BaseType().AsCXXRecordDeclaration();
  if (!base_cls) {
    return;
  }

  auto raw_base_cls_id = em.EntityId(base_cls.value());
  auto base_cls_id = mx::EntityId(raw_base_cls_id).Extract<mx::DeclId>();
  if (!base_cls_id) {
    return;
  }

  // The referer context id will be same as `from_id` by default. The
  // DeclReferenceKind function updates it based on the AST analysis
  // of the context in which declaration is referred.
  mx::ReferenceRecord record{raw_cls_id, raw_base_cls_id, raw_spec_id,
                             mx::BuiltinReferenceKind::EXTENDS};
  database.AddAsync(record);
}

// Add C++ method override relationships to the database.
static void AddMethodOverrideReferences(
    const EntityMapper &em, mx::DatabaseWriter &database,
    const pasta::CXXMethodDecl &method) {

  auto raw_derived_id = em.EntityId(method);
  auto derived_id = mx::EntityId(raw_derived_id).Extract<mx::DeclId>();
  if (!derived_id) {
    return;
  }

  for (const auto &base_method : method.OverriddenMethods()) {
    auto raw_base_id = em.EntityId(base_method);
    auto base_id = mx::EntityId(raw_base_id).Extract<mx::DeclId>();
    if (!base_id) {
      return;
    }

    mx::ReferenceRecord record{raw_derived_id, raw_base_id, raw_derived_id,
                               mx::BuiltinReferenceKind::OVERRIDES};
    database.AddAsync(record);
  }
}

// Get a type cases list of a specific thing.
template <typename T>
static std::span<const T> SpecificDeclList(
    const PendingFragment &pf, mx::DeclKind kind) {
  auto decls_it = pf.decls_to_serialize.find(kind);
  if (decls_it == pf.decls_to_serialize.end() || decls_it->second.empty()) {
    return {};
  }

  auto first = reinterpret_cast<const T *>(decls_it->second.data());
  return std::span<const T>(first, decls_it->second.size());
}

static constexpr mx::DeclKind kMethodKinds[] = {
  mx::DeclKind::CXX_CONVERSION,
  mx::DeclKind::CXX_CONSTRUCTOR,
  mx::DeclKind::CXX_DEDUCTION_GUIDE,
  mx::DeclKind::CXX_DESTRUCTOR,
  mx::DeclKind::CXX_METHOD,
};

// Add C++ method override relationships to the database.
static void AddMethodOverrideReferences(
    const EntityMapper &em, mx::DatabaseWriter &database,
    const PendingFragment &pf) {

  for (auto kind : kMethodKinds) {
    for (const auto &decl : SpecificDeclList<pasta::CXXMethodDecl>(pf, kind)) {
      AddMethodOverrideReferences(em, database, decl);
    }
  }
}

// Go find the partial specialization ID, if any, and return it for use in the
// reference context. If we do find one, then also add a second specialization
// record.
template <typename Partial, typename Tpl, typename Spec>
static mx::RawEntityId PartialSpecializationContext(
  const EntityMapper &em, mx::DatabaseWriter &database,
  const Tpl &tpl, const Spec &spec) {

  auto pattern = spec.SpecializedTemplateOrPartial();
  auto partial = std::get_if<Partial>(&pattern);
  if (!partial) {
    return em.EntityId(tpl);
  }

  auto raw_partial_id = em.EntityId(*partial);
  auto partial_id = mx::EntityId(raw_partial_id).Extract<mx::DeclId>();
  if (!partial_id) {
    assert(false);
    return em.EntityId(tpl);
  }

  mx::ReferenceRecord record{em.EntityId(spec), raw_partial_id, raw_partial_id,
                             mx::BuiltinReferenceKind::SPECIALIZES};
  database.AddAsync(record);

  return raw_partial_id;
}

static mx::RawEntityId SpecializationContext(
    const EntityMapper &em, mx::DatabaseWriter &database,
    const pasta::ClassTemplateDecl &tpl,
    const pasta::ClassTemplateSpecializationDecl &spec) {
  return PartialSpecializationContext<pasta::ClassTemplatePartialSpecializationDecl>(
      em, database, tpl, spec);
}

static mx::RawEntityId SpecializationContext(
    const EntityMapper &em, mx::DatabaseWriter &database,
    const pasta::VarTemplateDecl &tpl,
    const pasta::VarTemplateSpecializationDecl &spec) {
  return PartialSpecializationContext<pasta::VarTemplatePartialSpecializationDecl>(
      em, database, tpl, spec);
}

static mx::RawEntityId SpecializationContext(
  const EntityMapper &em, mx::DatabaseWriter &database,
  const pasta::FunctionTemplateDecl &tpl, const pasta::FunctionDecl &) {
  return em.EntityId(tpl);
}

template <typename T>
static void AddTemplateSpecialization(
    const EntityMapper &em, mx::DatabaseWriter &database,
    const T &tpl) {

  auto raw_tpl_id = em.EntityId(tpl);
  auto tpl_id = mx::EntityId(raw_tpl_id).Extract<mx::DeclId>();
  if (!tpl_id) {
    return;
  }

  for (const auto &spec : tpl.Specializations()) {
    auto raw_spec_id = em.EntityId(spec);
    auto spec_id = mx::EntityId(raw_spec_id).Extract<mx::DeclId>();
    if (!spec_id) {
      return;
    }

    auto raw_context_id = SpecializationContext(em, database, tpl, spec);
    mx::ReferenceRecord record{raw_spec_id, raw_tpl_id, raw_context_id,
                               mx::BuiltinReferenceKind::SPECIALIZES};
    database.AddAsync(record);
  }
}

// Try to figure out how functions are specialized.
static void AddFunctionSpecialization(
    const EntityMapper &em, mx::DatabaseWriter &database,
    const pasta::FunctionDecl &func) {

  mx::RawEntityId raw_tpl_id = mx::kInvalidEntityId;

  if (auto meth_pattern = func.InstantiatedFromMemberFunction()) {
    if (auto tpl = meth_pattern->DescribedFunctionTemplate()) {
      raw_tpl_id = em.EntityId(tpl.value());
    } else {
      raw_tpl_id = em.EntityId(meth_pattern.value());
    }
  
  } else if (auto func_pattern = func.InstantiatedFromDeclaration()) {
    if (auto tpl = func_pattern->DescribedFunctionTemplate()) {
      raw_tpl_id = em.EntityId(tpl.value());
    } else {
      raw_tpl_id = em.EntityId(func_pattern.value());
    }
  
  } else if (auto tpl_pattern = TemplateInstantiationPattern(func)) {
    if (auto tpl = tpl_pattern->DescribedFunctionTemplate()) {
      raw_tpl_id = em.EntityId(tpl.value());
    } else {
      raw_tpl_id = em.EntityId(tpl_pattern.value());
    }
  }

  auto tpl_id = mx::EntityId(raw_tpl_id).Extract<mx::DeclId>();
  if (!tpl_id) {
    return;
  }

  auto raw_spec_id = em.EntityId(func);
  auto spec_id = mx::EntityId(raw_spec_id).Extract<mx::DeclId>();
  if (!spec_id) {
    return;
  }

  mx::ReferenceRecord record{raw_spec_id, raw_tpl_id, raw_tpl_id,
                             mx::BuiltinReferenceKind::SPECIALIZES};
  database.AddAsync(record);
}

static void AddVarSpecialization(
    const EntityMapper &em, mx::DatabaseWriter &database,
    const pasta::VarDecl &var) {

  mx::RawEntityId raw_tpl_id = mx::kInvalidEntityId;

  if (auto field_pattern = var.InstantiatedFromStaticDataMember()) {
    if (auto tpl = field_pattern->DescribedVariableTemplate()) {
      raw_tpl_id = em.EntityId(tpl.value());
    } else {
      raw_tpl_id = em.EntityId(field_pattern.value());
    }
  
  } else if (auto tpl_pattern = var.TemplateInstantiationPattern()) {
    if (auto tpl = tpl_pattern->DescribedVariableTemplate()) {
      raw_tpl_id = em.EntityId(tpl.value());
    } else {
      raw_tpl_id = em.EntityId(tpl_pattern.value());
    }
  }

  auto tpl_id = mx::EntityId(raw_tpl_id).Extract<mx::DeclId>();
  if (!tpl_id) {
    return;
  }

  auto raw_spec_id = em.EntityId(var);
  auto spec_id = mx::EntityId(raw_spec_id).Extract<mx::DeclId>();
  if (!spec_id) {
    return;
  }

  mx::ReferenceRecord record{raw_spec_id, raw_tpl_id, raw_tpl_id,
                             mx::BuiltinReferenceKind::SPECIALIZES};
  database.AddAsync(record);
}

static void AddEnumSpecialization(
    const EntityMapper &em, mx::DatabaseWriter &database,
    const pasta::EnumDecl &spec) {

  mx::RawEntityId raw_tpl_id = mx::kInvalidEntityId;
  if (auto enum_pattern = spec.TemplateInstantiationPattern()) {
    raw_tpl_id = em.EntityId(enum_pattern.value());
  } else if (auto inst_pattern = spec.InstantiatedFromMemberEnum()) {
    raw_tpl_id = em.EntityId(inst_pattern.value());
  }

  auto tpl_id = mx::EntityId(raw_tpl_id).Extract<mx::DeclId>();
  if (!tpl_id) {
    return;
  }

  auto raw_spec_id = em.EntityId(spec);
  auto spec_id = mx::EntityId(raw_spec_id).Extract<mx::DeclId>();
  if (!spec_id) {
    return;
  }

  mx::ReferenceRecord record{raw_spec_id, raw_tpl_id, raw_tpl_id,
                             mx::BuiltinReferenceKind::SPECIALIZES};
  database.AddAsync(record);
}

static constexpr mx::DeclKind kFunctionKinds[] = {
  mx::DeclKind::CXX_CONVERSION,
  mx::DeclKind::CXX_CONSTRUCTOR,
  mx::DeclKind::CXX_DEDUCTION_GUIDE,
  mx::DeclKind::CXX_DESTRUCTOR,
  mx::DeclKind::CXX_METHOD,
  mx::DeclKind::FUNCTION
};

// Add template specialization records.
static void AddTemplateSpecializations(
    const EntityMapper &em, mx::DatabaseWriter &database,
    const PendingFragment &pf) {

  for (const auto &tpl : SpecificDeclList<pasta::ClassTemplateDecl>(
           pf, mx::DeclKind::CLASS_TEMPLATE)) {
    AddTemplateSpecialization(em, database, tpl);
  }

  for (const auto &tpl : SpecificDeclList<pasta::VarTemplateDecl>(
           pf, mx::DeclKind::VAR_TEMPLATE)) {
    AddTemplateSpecialization(em, database, tpl);
  }

  for (const auto &tpl : SpecificDeclList<pasta::FunctionTemplateDecl>(
           pf, mx::DeclKind::FUNCTION_TEMPLATE)) {
    AddTemplateSpecialization(em, database, tpl);
  }

  for (auto kind : kFunctionKinds) {
    for (const auto &func : SpecificDeclList<pasta::FunctionDecl>(pf, kind)) {
      AddFunctionSpecialization(em, database, func);
    }
  }

  // NOTE(pag): We don't look at `VAR_TEMPLATE_SPECIALIZATION`, because we
  //            should have gotten those from the specialization loop on
  //            `VAR_TEMPLATE`.
  //
  // TODO(pag): Do `ParmVarDecl`s and such have specialization info from Clang?
  for (const auto &spec : SpecificDeclList<pasta::VarDecl>(pf, mx::DeclKind::VAR)) {
    AddVarSpecialization(em, database, spec);
  }

  for (const auto &spec : SpecificDeclList<pasta::EnumDecl>(pf, mx::DeclKind::ENUM)) {
    AddEnumSpecialization(em, database, spec);
  }
}

}  // namespace

// Identify all unique entity IDs referenced by this fragment,
// and map them to the fragment ID in the data store.
void LinkExternalReferencesInFragment(
    const pasta::AST &ast, mx::DatabaseWriter &database,
    const PendingFragment &pf) {

  const EntityMapper &em = pf.em;
  
  // XREF(pag): Issue #214. We want to record references to other decls that are
  //            expressed in types. In PASTA, we don't present Clang's
  //            `TypeLoc`s, so we need to instead go through the types to find
  //            which ones are explicitly referenced.
  AddDeclReferencesFrom<mx::DeclId>(ast, database, pf, pf.decls_to_serialize,
                                    EnumerateDeclToTypeReferences);

  AddDeclReferencesFrom<mx::StmtId>(ast, database, pf, pf.stmts_to_serialize,
                                    EnumerateStmtToDeclReferences);

  AddDeclReferencesFrom<mx::DesignatorId>(
      ast, database, pf, pf.designators_to_serialize,
      EnumerateDesignatorToDeclReferences);

  for (const auto &spec : pf.cxx_base_specifiers_to_serialize) {
    AddBaseSpecifierReferenceFrom(em, database, spec);
  }

  AddMethodOverrideReferences(em, database, pf);
  AddTemplateSpecializations(em, database, pf);

  for (auto maybe_tt : Entities(pf.macros_to_serialize)) {
    if (!maybe_tt) {

      // TODO(pag): Remove this assertion later; really it's a failure to
      //            construct a token tree, and we do have a backup path
      //            in `Persist.cpp`.
      assert(false);
      continue;
    }

    const TokenTree &tt = maybe_tt.value();
    std::optional<pasta::Macro> maybe_macro = tt.Macro();
    if (!maybe_macro) {
      continue;
    }

    const pasta::Macro &m = maybe_macro.value();
    mx::RawEntityId macro_id = em.EntityId(tt);
    auto from_eid = mx::EntityId(macro_id).Extract<mx::MacroId>();
    if (!from_eid) {
      assert(false);
      continue;
    }

    if (from_eid->fragment_id != pf.fragment_index) {
      assert(false);
      continue;  // This is weird?
    }

    switch (tt.Kind()) {
      default:
        break;

      // Have the expansion marked as a reference of the definition.
      case mx::MacroKind::EXPANSION:
        if (auto exp = pasta::MacroExpansion::From(m)) {
          std::optional<pasta::DefineMacroDirective> def = exp->Definition();
          if (!def) {
            continue;
          }

          mx::RawEntityId def_id = em.EntityId(def.value());
          if (!mx::EntityId(def_id).Extract<mx::MacroId>()) {
            auto macro_name = def->Name();
            if (!macro_name) {
              continue;  // Probably in a conditionally disabled region.
            }

            // Builtin or command-line specified macros have no location.
            //
            // NOTE(pag): The persistence for macros re-interprets macros with
            //            no definition site as substitutions instead of macro
            //            expansions.
            //
            // TODO(pag): Find a way to give these file locations. See related
            //            issue/condition in `FindTLMs` in file
            //            `bin/Index/IndexCompileJob.cpp`.
            if (!macro_name->FileLocation()) {
              continue;
            }

            assert(false);
            continue;
          }

          // The referrer context id will be same as `macro_id` by default
          // and assigned the same.
          database.AddAsync(mx::ReferenceRecord{
              macro_id, def_id, macro_id,
              mx::BuiltinReferenceKind::EXPANSION_OF});
        }
        break;

      // Files are always treated as references.
      case mx::MacroKind::INCLUDE_DIRECTIVE:
      case mx::MacroKind::INCLUDE_MACROS_DIRECTIVE:
      case mx::MacroKind::INCLUDE_NEXT_DIRECTIVE:
      case mx::MacroKind::IMPORT_DIRECTIVE:
        if (auto inc = pasta::IncludeLikeMacroDirective::From(m)) {
          std::optional<pasta::File> f = inc->IncludedFile();
          if (!f) {
            continue;
          }

          mx::RawEntityId file_id = em.EntityId(f.value());
          if (!mx::EntityId(file_id).Extract<mx::FileId>()) {
            assert(false);
            continue;
          }

          // The referrer context id will be same as `macro_id` by default
          // and assigned the same.
          database.AddAsync(mx::ReferenceRecord{
              macro_id, file_id, macro_id,
              mx::BuiltinReferenceKind::INCLUDES_FILE});
        }
        break;
    }
  }
}

}  // namespace indexer
