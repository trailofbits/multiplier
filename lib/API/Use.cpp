// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Use.h"

#include <type_traits>

#include "Fragment.h"

namespace mx {
namespace {

#define MX_VISIT_ENUM(cls, api_name, get_val, set_val, init_val, \
                      pasta_name, type, nth_list) \
    template <typename Reader> \
    inline static type Get_ ## cls ## _ ## pasta_name(const Reader &reader) { \
      return static_cast<type>(reader.get_val()); \
    }

#define MX_VISIT_PSEUDO_KIND(cls, get_val, set_val) \
    inline static PseudoKind Get_PseudoKind( \
        const mx::ast::Pseudo::Reader &reader, cls *) { \
      return static_cast<PseudoKind>(reader.get_val()); \
    }

#define DECLARE_FIND_READER_USES(reader_kind, name) \
    static void FindUses_ ## name ( \
        mx::RawEntityId eid, UseSelectorSet &selectors, \
        const mx::ast::reader_kind::Reader &, bool &found);

#define MX_BEGIN_VISIT_DECL(name) DECLARE_FIND_READER_USES(Decl, name)
#define MX_BEGIN_VISIT_STMT(name) DECLARE_FIND_READER_USES(Stmt, name)
#define MX_BEGIN_VISIT_TYPE(name) DECLARE_FIND_READER_USES(Type, name)
#define MX_BEGIN_VISIT_PSEUDO(name) DECLARE_FIND_READER_USES(Pseudo, name)

#include <multiplier/Visitor.inc.h>

#define DEFINE_FIND_READER_KIND_USES(reader_kind, name) \
    void FindUses_ ## name ( \
        mx::RawEntityId eid, UseSelectorSet &selectors, \
        const mx::ast::reader_kind::Reader &reader, bool &found) {

#define MX_VISIT_BASE(name, base_name) \
    FindUses_ ## base_name(eid, selectors, reader, found);

#define MX_VISIT_ENTITY(cls, api_name, get_val, set_val, init_val, \
                        pasta_name, type, nth_list, selector) \
    if (eid == reader.get_val()) { \
      found = true; \
      selectors.set(static_cast<unsigned>(selector)); \
    }

#define MX_VISIT_OPTIONAL_ENTITY MX_VISIT_ENTITY
#define MX_BEGIN_VISIT_DECL(name) DEFINE_FIND_READER_KIND_USES(Decl, name)
#define MX_BEGIN_VISIT_STMT(name) DEFINE_FIND_READER_KIND_USES(Stmt, name)
#define MX_BEGIN_VISIT_TYPE(name) DEFINE_FIND_READER_KIND_USES(Type, name)
#define MX_BEGIN_VISIT_PSEUDO(name) DEFINE_FIND_READER_KIND_USES(Pseudo, name)
#define MX_END_VISIT_DECL(name) }
#define MX_END_VISIT_STMT MX_END_VISIT_DECL
#define MX_END_VISIT_TYPE MX_END_VISIT_DECL
#define MX_END_VISIT_PSEUDO MX_END_VISIT_DECL
#include <multiplier/Visitor.inc.h>

}  // namespace

UseIteratorImpl::UseIteratorImpl(
    std::shared_ptr<EntityProvider> ep_, Decl &entity)
    : ep(std::move(ep_)) {
  ep->FillUses(ep, entity.id(), search_ids, fragment_ids);
}

UseIteratorImpl::UseIteratorImpl(
    std::shared_ptr<EntityProvider> ep_, Stmt &entity)
    : ep(std::move(ep_)),
      search_ids(1u),
      fragment_ids(1u),
      fragment(entity.fragment) {
  search_ids[0] = entity.id();
  fragment_ids[0] = entity.fragment->fragment_id;
}

bool UseIteratorImpl::FindNextDecl(std::optional<UseBase> &use) {
  if (list_offset >= fragment->num_decls) {
    return false;
  }

  const unsigned offset = list_offset++;
  mx::ast::Decl::Reader reader = fragment->NthDecl(offset);
  bool found = false;
  UseSelectorSet selectors;

  for (auto eid : search_ids) {
    switch (Get_Decl_Kind(reader)) {

#define MX_BEGIN_VISIT_ABSTRACT_DECL(name)
#define MX_BEGIN_VISIT_DECL(name) \
    case name::static_kind(): \
      FindUses_ ## name (eid, selectors, reader, found); \
      break;

#include <multiplier/Visitor.inc.h>

    }
  }

  if (!found) {
    return false;
  }

  use.emplace(Decl(fragment, offset), std::move(selectors));

  return true;
}

bool UseIteratorImpl::FindNextStmt(std::optional<UseBase> &use) {
  if (list_offset >= fragment->num_stmts) {
    return false;
  }

  const unsigned offset = list_offset++;
  mx::ast::Stmt::Reader reader = fragment->NthStmt(offset);
  bool found = false;
  UseSelectorSet selectors;

  for (auto eid : search_ids) {
    switch (Get_Stmt_Kind(reader)) {

#define MX_BEGIN_VISIT_ABSTRACT_STMT(name)
#define MX_BEGIN_VISIT_STMT(name) \
    case name::static_kind(): \
      FindUses_ ## name (eid, selectors, reader, found); \
      break;

#include <multiplier/Visitor.inc.h>

    }
  }

  if (!found) {
    return false;
  }

  use.emplace(Stmt(fragment, offset), std::move(selectors));

  return true;
}

bool UseIteratorImpl::FindNextType(std::optional<UseBase> &use) {
  if (list_offset >= fragment->num_types) {
    return false;
  }

  const unsigned offset = list_offset++;
  mx::ast::Type::Reader reader = fragment->NthType(offset);
  bool found = false;
  UseSelectorSet selectors;

  for (auto eid : search_ids) {
    switch (Get_Type_Kind(reader)) {

#define MX_BEGIN_VISIT_ABSTRACT_TYPE(name)
#define MX_BEGIN_VISIT_TYPE(name) \
    case name::static_kind(): \
      FindUses_ ## name (eid, selectors, reader, found); \
      break;

#include <multiplier/Visitor.inc.h>

    }
  }

  if (!found) {
    return false;
  }

  use.emplace(Type(fragment, offset), std::move(selectors));

  return true;
}

bool UseIteratorImpl::FindNextPseudo(std::optional<UseBase> &use) {
  if (list_offset >= fragment->num_pseudos) {
    return false;
  }

  TemplateArgument *dummy = nullptr;
  const unsigned offset = list_offset++;
  mx::ast::Pseudo::Reader reader = fragment->NthPseudo(offset);
  bool found = false;
  UseSelectorSet selectors;

  for (auto eid : search_ids) {
    switch (Get_PseudoKind(reader, dummy)) {
      case PseudoKind::CXX_BASE_SPECIFIER:
        FindUses_CXXBaseSpecifier(eid, selectors, reader, found);
        break;
      case PseudoKind::TEMPLATE_ARGUMENT:
        FindUses_TemplateArgument(eid, selectors, reader, found);
        break;
      case PseudoKind::TEMPLATE_PARAMETER_LIST:
        FindUses_TemplateParameterList(eid, selectors, reader, found);
        break;
    }
  }

  if (!found) {
    return false;
  }

  switch (Get_PseudoKind(reader, dummy)) {
    case PseudoKind::CXX_BASE_SPECIFIER:
      use.emplace(CXXBaseSpecifier(fragment, offset), std::move(selectors));
      return true;
    case PseudoKind::TEMPLATE_ARGUMENT:
      use.emplace(TemplateArgument(fragment, offset), std::move(selectors));
      return true;
    case PseudoKind::TEMPLATE_PARAMETER_LIST:
      use.emplace(TemplateParameterList(fragment, offset), std::move(selectors));
      return true;
  }

  return false;
}

bool UseIteratorImpl::FindNext(std::optional<UseBase> &use) {
  for (;;) {
    if (!fragment) {
      if (fragment_offset >= fragment_ids.size()) {
        return false;

      } else {
        fragment = ep->FragmentFor(ep, fragment_ids[fragment_offset++]);
        if (!fragment) {
          continue;  // Skip to next; didn't find for some reason.
        }
      }
    }

    switch (list) {
      case kDecl:
        if (FindNextDecl(use)) {
          return true;

        } else {
          // Skip to next list; didn't find.
          list = kStmt;
          list_offset = 0u;
          continue;
        }
      case kStmt:
        if (FindNextStmt(use)) {
          return true;
        } else {
          // Skip to next list; didn't find.
          list = kType;
          list_offset = 0u;
          continue;
        }
      case kType:
        if (FindNextType(use)) {
          return true;
        } else {
          // Skip to next list; didn't find.
          list = kPseudo;
          list_offset = 0u;
          continue;
        }
      case kPseudo:
        if (FindNextPseudo(use)) {
          return true;

        } else {
          // Skip to next fragment; didn't find.
          fragment.reset();
          list_offset = 0u;
          list = kDecl;
          continue;
        }
    }
  }

  return false;
}

void UseIteratorBase::Advance(void) {
  use.reset();
  if (!impl->FindNext(use)) {
    impl.reset();
  }
}

UseBase::~UseBase(void) {}

UseBase::UseBase(Decl entity, UseSelectorSet selectors_)
    : selectors(std::move(selectors_)),
      fragment(std::move(entity.fragment)),
      offset(entity.offset),
      kind(UseKind::DECLARATION) {}

UseBase::UseBase(Stmt entity, UseSelectorSet selectors_)
    : selectors(std::move(selectors_)),
      fragment(std::move(entity.fragment)),
      offset(entity.offset),
      kind(UseKind::STATEMENT) {}

UseBase::UseBase(Type entity, UseSelectorSet selectors_)
    : selectors(std::move(selectors_)),
      fragment(std::move(entity.fragment)),
      offset(entity.offset),
      kind(UseKind::TYPE) {}

UseBase::UseBase(CXXBaseSpecifier entity, UseSelectorSet selectors_)
    : selectors(std::move(selectors_)),
      fragment(std::move(entity.fragment)),
      offset(entity.offset),
      kind(UseKind::CXX_BASE_SPECIFIER) {}

UseBase::UseBase(TemplateArgument entity, UseSelectorSet selectors_)
    : selectors(std::move(selectors_)),
      fragment(std::move(entity.fragment)),
      offset(entity.offset),
      kind(UseKind::TEMPLATE_ARGUMENT) {}

UseBase::UseBase(TemplateParameterList entity, UseSelectorSet selectors_)
    : fragment(std::move(entity.fragment)),
      offset(entity.offset),
      kind(UseKind::TEMPLATE_PARAMETER_LIST) {}

std::optional<Decl> UseBase::as_declaration(void) const {
  if (kind == UseKind::DECLARATION) {
    return Decl(fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<Stmt> UseBase::as_statement(void) const {
  if (kind == UseKind::STATEMENT) {
    return Stmt(fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<Type> UseBase::as_type(void) const {
  if (kind == UseKind::TYPE) {
    return Type(fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXBaseSpecifier> UseBase::as_cxx_base_specifier(void) const {
  if (kind == UseKind::CXX_BASE_SPECIFIER) {
    return CXXBaseSpecifier(fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<TemplateArgument> UseBase::as_template_argument(void) const {
  if (kind == UseKind::TEMPLATE_ARGUMENT) {
    return TemplateArgument(fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<TemplateParameterList> UseBase::as_template_parameter_list(void) const {
  if (kind == UseKind::TEMPLATE_PARAMETER_LIST) {
    return TemplateParameterList(fragment, offset);
  } else {
    return std::nullopt;
  }
}

}  // namespace mx
