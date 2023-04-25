// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "TypeFragment.h"

namespace indexer {

// TypeFragmentBuilder is duplication of FragmentBuilder and collects
// the decl/stmt/types/Attr used in the type fragment.

// TODO() : Do we need to collect the uses of decl/stmt/types/attr from
//          the printed token context. If not then TypeFragmentBuilder
//          is redundant and we should get rid of this.
//          The idea here is link them across the fragments.

class TypeFragmentBuilder final {
 public:
  PendingFragmentType &fragment;

  inline explicit TypeFragmentBuilder(PendingFragmentType &fragment_)
      : fragment(fragment_) {}

#define MX_VISIT_BASE(derived_type, base_type) \
    Visit ## base_type(entity);

#define MX_VISIT_ENTITY(cls, api_method, storage, apply, method, entity_type, \
                        get_storage_list) \
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

#define MX_BEGIN_VISIT_DECL(name) \
    void Visit ## name(const pasta::name &entity) { \
      (void) entity;

#define MX_END_VISIT_DECL(name) }

#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_END_VISIT_STMT MX_END_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#define MX_END_VISIT_TYPE MX_END_VISIT_DECL
#define MX_BEGIN_VISIT_ATTR MX_BEGIN_VISIT_DECL
#define MX_END_VISIT_ATTR MX_END_VISIT_DECL
#define MX_BEGIN_VISIT_PSEUDO MX_BEGIN_VISIT_DECL
#define MX_END_VISIT_PSEUDO MX_END_VISIT_DECL

// NOTE(pag): Macro visitors are never reached, so trick the compiler into
//            dead code elimination.
#define MX_BEGIN_VISIT_MACRO(name) MX_BEGIN_VISIT_DECL(name) if (1) return;
#define MX_END_VISIT_MACRO MX_END_VISIT_DECL

#include <multiplier/Visitor.inc.h>

  void Accept(const pasta::Decl &entity) {
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

  void Accept(const pasta::Stmt &entity) {
    switch (entity.Kind()) {
  #define MX_IGNORE_OPERATOR(...)
  #define MX_IGNORE_LITERAL(...)
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

  void Accept(const pasta::Type &entity) {
    switch (entity.Kind()) {
  #define MX_VISIT_TYPE(type) \
      case pasta::TypeKind::k ## type: { \
        Visit ## type ## Type( \
           reinterpret_cast<const pasta::type ## Type &>(entity)); \
        break; \
      }

      PASTA_FOR_EACH_TYPE_IMPL(MX_VISIT_TYPE, PASTA_IGNORE_ABSTRACT)

  #undef MX_VISIT_TYPE
    }
  }

  void Accept(const pasta::Attr &entity) {
    switch (entity.Kind()) {
  #define MX_VISIT_ATTR(type) \
      case pasta::AttrKind::k ## type: { \
        Visit ## type ## Attr( \
           reinterpret_cast<const pasta::type ## Attr &>(entity)); \
        break; \
      }

      PASTA_FOR_EACH_ATTR_IMPL(MX_VISIT_ATTR, PASTA_IGNORE_ABSTRACT)

  #undef MX_VISIT_ATTR
    }
  }

  void Accept(const pasta::Macro &) {}
  void Accept(const pasta::TemplateArgument &) {}
  void Accept(const pasta::CXXBaseSpecifier &) {}
  void Accept(const pasta::TemplateParameterList &) {}
  void Accept(const pasta::Designator &) {}

  void MaybeVisitNext(std::optional<pasta::MacroToken>) {}
  void MaybeVisitNext(std::optional<pasta::FileToken>) {}
  void MaybeVisitNext(std::optional<pasta::Token>) {}
  void MaybeVisitNext(const pasta::Token &) {}

  void MaybeVisitNext(const pasta::Decl &entity) {
    fragment.Uses(entity);
  }

  void MaybeVisitNext(const pasta::Stmt &entity) {
    fragment.Uses(entity);
  }

  void MaybeVisitNext(const pasta::Type &entity) {
    fragment.Uses(entity);
  }

  void MaybeVisitNext(const pasta::Attr &entity) {
    fragment.Uses(entity);
  }

  void MaybeVisitNext(const pasta::Macro &) {}

  void MaybeVisitNext(const pasta::File &) {}

  void MaybeVisitNext(const pasta::TemplateArgument &) {}

  void MaybeVisitNext(const pasta::CXXBaseSpecifier &) {}

  void MaybeVisitNext(const pasta::TemplateParameterList &) {}

  void MaybeVisitNext(const pasta::Designator &) {}
};

} // namespace indexer
