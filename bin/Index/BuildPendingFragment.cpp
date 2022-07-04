// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "PendingFragment.h"

#include "Util.h"

namespace indexer {
namespace {

// Collects all entities that will be stored into the fragment in
// `PendingFragment`. This generally needs to follow all references in the
// same way that the serializer does, hence the use of `Visitor.inc.h`. It is
// also the case that types and pseudos are stored differently than decls and
// statements. Decls/stmts are lexically bound to a fragment, i.e. the decls/
// stmts in a fragment lexically "belong" to the range of code covered by that
// fragment. However, types and pseudos are different. Pseudos are generally
// "owned" by one decl, or one-or-more types. All types referenced by decls/
// stmts/types/pseudos in a fragment are also stored in the fragment, even if it
// ends up being redundant across fragments.
class FragmentBuilder {
 public:
  EntityIdMap &entity_ids;
  PendingFragment &fragment;

  inline explicit FragmentBuilder(EntityIdMap &entity_ids_,
                                  PendingFragment &fragment_)
      : entity_ids(entity_ids_),
        fragment(fragment_) {}

#define MX_BEGIN_VISIT_DECL(name) void Visit ## name (const pasta::name &);
#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_PSEUDO MX_BEGIN_VISIT_DECL
#include <multiplier/Visitor.inc.h>

  void Accept(const pasta::Decl &entity);
  void Accept(const pasta::Stmt &entity);
  void Accept(const pasta::Type &entity);
  void Accept(const pasta::TemplateArgument &entity);
  void Accept(const pasta::CXXBaseSpecifier &entity);
  void Accept(const pasta::TemplateParameterList &entity);
  void Accept(const pasta::Designator &entity);

  void MaybeVisitNext(const pasta::Token &) {}

  void MaybeVisitNext(const pasta::Decl &entity);
  void MaybeVisitNext(const pasta::Stmt &entity);
  void MaybeVisitNext(const pasta::Type &entity);

  void MaybeVisitNext(const pasta::TemplateArgument &pseudo);
  void MaybeVisitNext(const pasta::CXXBaseSpecifier &pseudo);
  void MaybeVisitNext(const pasta::TemplateParameterList &pseudo);
  void MaybeVisitNext(const pasta::Designator &pseudo);
};

void FragmentBuilder::MaybeVisitNext(const pasta::Decl &entity) {
  auto kind = entity.Kind();
  switch (kind) {
    case pasta::DeclKind::kTranslationUnit:
    case pasta::DeclKind::kNamespace:
    case pasta::DeclKind::kExternCContext:
    case pasta::DeclKind::kLinkageSpec:
      return;

    // TODO(pag): Think about this a bit more. It's possible that we end up
    //            internalizing class templates and partial specializations
    //            into the fragments using their complete specializations.
    default:
      break;
  }

  mx::DeclarationId id;
  id.fragment_id = fragment.fragment_id;
  id.offset = static_cast<uint32_t>(fragment.decls_to_serialize.size());
  id.kind = mx::FromPasta(kind);
  id.is_definition = IsDefinition(entity);

  auto [it, added] = entity_ids.emplace(entity.RawDecl(), id);
  if (added) {
    fragment.decls_to_serialize.emplace_back(entity);  // New decl found.

  // NOTE(pag): An interesting side-effect of this approach is that builtin/
  //            implicit declarations become internalized into the fragments.
  //            E.g. we might have a `CallExpr` that calls a compiler intrinsic,
  //            and that intrinsic will turn into a declaration embedded in this
  //            fragment.
  } else if (entity.IsImplicit()) {
    mx::VariantId vid = it->second.Unpack();
    if (std::holds_alternative<mx::DeclarationId>(vid)) {
      auto prev_id = std::get<mx::DeclarationId>(vid);
      if (prev_id.fragment_id != fragment.fragment_id) {
        entity_ids[entity.RawDecl()] = id;  // Overwrite and force it in.
        fragment.decls_to_serialize.emplace_back(entity);
      }
    } else {
      assert(false);
    }
  }
}

void FragmentBuilder::MaybeVisitNext(const pasta::Stmt &entity) {
  auto kind = entity.Kind();
  mx::StatementId id;
  id.fragment_id = fragment.fragment_id;
  id.offset = static_cast<uint32_t>(fragment.stmts_to_serialize.size());
  id.kind = mx::FromPasta(kind);

  if (entity_ids.emplace(entity.RawStmt(), id).second) {
    fragment.stmts_to_serialize.emplace_back(entity);  // New stmt found.
  }
}

void FragmentBuilder::MaybeVisitNext(const pasta::Type &entity) {
  auto kind = entity.Kind();
  mx::TypeId id;
  id.fragment_id = fragment.fragment_id;
  id.offset = static_cast<uint32_t>(fragment.types_to_serialize.size());
  id.kind = mx::FromPasta(kind);

  TypeKey type_key(entity.RawType(), entity.RawQualifiers());
  if (fragment.type_ids.emplace(type_key, id).second) {
    fragment.types_to_serialize.emplace_back(entity);  // New type found.
  }
}

void FragmentBuilder::MaybeVisitNext(const pasta::TemplateArgument &pseudo) {
  auto offset = static_cast<uint32_t>(fragment.pseudos_to_serialize.size());
  if (fragment.pseudo_offsets.emplace(
          pseudo.RawTemplateArgument(), offset).second) {
    fragment.pseudos_to_serialize.emplace_back(pseudo);
  }
}

void FragmentBuilder::MaybeVisitNext(const pasta::CXXBaseSpecifier &pseudo) {
  auto offset = static_cast<uint32_t>(fragment.pseudos_to_serialize.size());
  if (fragment.pseudo_offsets.emplace(
          pseudo.RawCXXBaseSpecifier(), offset).second) {
    fragment.pseudos_to_serialize.emplace_back(pseudo);
  }
}

void FragmentBuilder::MaybeVisitNext(
    const pasta::TemplateParameterList &pseudo) {
  auto offset = static_cast<uint32_t>(fragment.pseudos_to_serialize.size());
  if (fragment.pseudo_offsets.emplace(
          pseudo.RawTemplateParameterList(), offset).second) {
    fragment.pseudos_to_serialize.emplace_back(pseudo);
  }
}

void FragmentBuilder::MaybeVisitNext(
    const pasta::Designator &pseudo) {
  auto offset = static_cast<uint32_t>(fragment.pseudos_to_serialize.size());
  if (fragment.pseudo_offsets.emplace(
          pseudo.RawDesignator(), offset).second) {
    fragment.pseudos_to_serialize.emplace_back(pseudo);
  }
}

#define MX_VISIT_BASE(derived_type, base_type) \
    Visit ## base_type(entity);

#define MX_VISIT_ENTITY(cls, api_method, storage, apply, method, entity_type, \
                        get_storage_list, selector) \
    MaybeVisitNext(apply(entity, method));


#define MX_VISIT_ENTITY_LIST(cls, api_method, storage, apply, method, \
                             entity_type, get_storage_list) \
    for (auto sub_entity : apply(entity, method)) { \
      MaybeVisitNext(sub_entity); \
    }

#define MX_VISIT_OPTIONAL_ENTITY(cls, api_method, storage, apply, method, \
                                 entity_type, ...) \
    if (auto sub_entity = apply(entity, method); sub_entity.has_value()) { \
      MaybeVisitNext(sub_entity.value()); \
    }

#define MX_VISIT_OPTIONAL_ENTITY_LIST(cls, api_method, storage, apply, method, \
                                      entity_type, get_storage_list) \
    if (auto sub_entities = apply(entity, method); sub_entities.has_value()) { \
      for (const auto &sub_entity : sub_entities.value()) { \
        MaybeVisitNext(sub_entity); \
      } \
    }

#define MX_VISIT_PSEUDO MX_VISIT_ENTITY
#define MX_VISIT_PSEUDO_LIST MX_VISIT_ENTITY_LIST
#define MX_VISIT_OPTIONAL_PSEUDO MX_VISIT_OPTIONAL_ENTITY
#define MX_VISIT_OPTIONAL_PSEUDO_LIST MX_VISIT_OPTIONAL_ENTITY_LIST

#define MX_BEGIN_VISIT_DECL(name) \
    void FragmentBuilder::Visit ## name(const pasta::name &entity) { \
      (void) entity;

#define MX_END_VISIT_DECL(name) }

#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_END_VISIT_STMT MX_END_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#define MX_END_VISIT_TYPE MX_END_VISIT_DECL
#define MX_BEGIN_VISIT_PSEUDO MX_BEGIN_VISIT_DECL
#define MX_END_VISIT_PSEUDO MX_END_VISIT_DECL

#include <multiplier/Visitor.inc.h>

void FragmentBuilder::Accept(const pasta::Decl &entity) {
  switch (entity.Kind()) {
#define MX_VISIT_DECL(decl) \
    case pasta::DeclKind::k ## decl: { \
      Visit ## decl ## Decl( \
         reinterpret_cast<const pasta::decl ## Decl &>(entity)); \
      return; \
    }

    PASTA_FOR_EACH_DECL_IMPL(MX_VISIT_DECL, PASTA_IGNORE_ABSTRACT)

#undef MX_VISIT_DECL
  }
}

void FragmentBuilder::Accept(const pasta::Stmt &entity) {
  switch (entity.Kind()) {
#define MX_VISIT_STMT(stmt) \
    case pasta::StmtKind::k ## stmt: { \
      Visit ## stmt( \
         reinterpret_cast<const pasta::stmt &>(entity)); \
      break; \
    }

    PASTA_FOR_EACH_STMT_IMPL(MX_VISIT_STMT,
                             MX_VISIT_STMT,
                             MX_VISIT_STMT,
                             MX_VISIT_STMT,
                             MX_VISIT_STMT,
                             PASTA_IGNORE_ABSTRACT)

#undef MX_VISIT_STMT
  }
}

void FragmentBuilder::Accept(const pasta::Type &entity) {
  switch (entity.Kind()) {
#define MX_VISIT_TYPE(type) \
    case pasta::TypeKind::k ## type: { \
      Visit ## type ## Type( \
         reinterpret_cast<const pasta::type ## Type &>(entity)); \
      break; \
    }

    PASTA_FOR_EACH_TYPE_IMPL(MX_VISIT_TYPE,
                             PASTA_IGNORE_ABSTRACT)

#undef MX_VISIT_TYPE
  }
}

}  // namespace

void PendingFragment::Build(EntityIdMap &entity_ids,
                            const pasta::TokenRange &tokens) {
  size_t prev_num_decls = 0ul;
  size_t prev_num_stmts = 0ul;
  size_t prev_num_types = 0ul;
  size_t prev_num_pseudos = 0ul;

  FragmentBuilder builder(entity_ids, *this);

  // Make sure to collect everything reachable from token contexts.
  for (auto i = begin_index; i <= end_index; ++i) {
    for (auto context = tokens[i].Context(); context;
         context = context->Parent()) {
      if (auto decl = pasta::Decl::From(*context)) {
        builder.MaybeVisitNext(*decl);

      } else if (auto stmt = pasta::Stmt::From(*context)) {
        builder.MaybeVisitNext(*stmt);

      } else if (auto type = pasta::Type::From(*context)) {
        builder.MaybeVisitNext(*type);
      }
    }
  }

  for (auto changed = true; changed; ) {
    changed = false;

    size_t num_decls = decls_to_serialize.size();
    size_t num_stmts = stmts_to_serialize.size();
    size_t num_types = types_to_serialize.size();
    size_t num_pseudos = pseudos_to_serialize.size();

    for (size_t i = prev_num_decls; i < num_decls; ++i) {
      changed = true;
      pasta::Decl entity = decls_to_serialize[i];
      builder.Accept(entity);
    }

    for (size_t i = prev_num_stmts; i < num_stmts; ++i) {
      changed = true;
      pasta::Stmt entity = stmts_to_serialize[i];
      builder.Accept(entity);
    }

    for (size_t i = prev_num_types; i < num_types; ++i) {
      changed = true;
      pasta::Type entity = types_to_serialize[i];
      builder.Accept(entity);
    }

    for (size_t i = prev_num_pseudos; i < num_pseudos; ++i) {
      changed = true;
      Pseudo pseudo = pseudos_to_serialize[i];
      if (std::holds_alternative<pasta::TemplateArgument>(pseudo)) {
        builder.VisitTemplateArgument(std::get<pasta::TemplateArgument>(pseudo));
      } else if (std::holds_alternative<pasta::CXXBaseSpecifier>(pseudo)) {
        builder.VisitCXXBaseSpecifier(std::get<pasta::CXXBaseSpecifier>(pseudo));
      } else if (std::holds_alternative<pasta::TemplateParameterList>(pseudo)) {
        builder.VisitTemplateParameterList(std::get<pasta::TemplateParameterList>(pseudo));
      } else if (std::holds_alternative<pasta::Designator>(pseudo)) {
        builder.VisitDesignator(std::get<pasta::Designator>(pseudo));
      } else {
        assert(false);
      }
    }

    prev_num_decls = num_decls;
    prev_num_stmts = num_stmts;
    prev_num_types = num_types;
    prev_num_pseudos = num_pseudos;
  }
}

}  // namespace indexer
