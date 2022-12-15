// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Use.h"

#include <type_traits>

#include "Fragment.h"
#include <multiplier/AST.h>

namespace mx {
namespace {

#define MX_VISIT_ENUM(cls, api_name, storage, apply, \
                      pasta_name, type, nth_list) \
    template <typename Reader> \
    inline static type Get_ ## cls ## _ ## pasta_name(const Reader &reader) { \
      return static_cast<type>(reader.getVal ## storage()); \
    }

#define MX_VISIT_PSEUDO_KIND(cls, storage) \
    inline static PseudoKind Get_PseudoKind( \
        const mx::ast::Pseudo::Reader &reader, cls *) { \
      return static_cast<PseudoKind>(reader.getVal ## storage()); \
    }

#define DECLARE_FIND_READER_USES(reader_kind, name) \
    static void FindUses_ ## name ( \
        mx::RawEntityId eid, UseSelectorSet &selectors, \
        const mx::ast::reader_kind::Reader &, bool &found);

#define MX_BEGIN_VISIT_DECL(name) DECLARE_FIND_READER_USES(Decl, name)
#define MX_BEGIN_VISIT_STMT(name) DECLARE_FIND_READER_USES(Stmt, name)
#define MX_BEGIN_VISIT_TYPE(name) DECLARE_FIND_READER_USES(Type, name)
#define MX_BEGIN_VISIT_ATTR(name) DECLARE_FIND_READER_USES(Attr, name)
#define MX_BEGIN_VISIT_PSEUDO(name) DECLARE_FIND_READER_USES(Pseudo, name)

#include <multiplier/Visitor.inc.h>

#define DEFINE_FIND_READER_KIND_USES(reader_kind, name) \
    void FindUses_ ## name ( \
        mx::RawEntityId eid, UseSelectorSet &selectors, \
        const mx::ast::reader_kind::Reader &reader, bool &found) {

#define MX_VISIT_BASE(name, base_name) \
    FindUses_ ## base_name(eid, selectors, reader, found);

#define MX_VISIT_ENTITY(cls, api_name, storage, apply, \
                        pasta_name, type, nth_list, selector) \
    if (eid == reader.getVal ## storage()) { \
      found = true; \
      selectors.set(static_cast<unsigned>(selector)); \
    }

#define MX_VISIT_OPTIONAL_ENTITY MX_VISIT_ENTITY
#define MX_BEGIN_VISIT_DECL(name) DEFINE_FIND_READER_KIND_USES(Decl, name)
#define MX_BEGIN_VISIT_STMT(name) DEFINE_FIND_READER_KIND_USES(Stmt, name)
#define MX_BEGIN_VISIT_TYPE(name) DEFINE_FIND_READER_KIND_USES(Type, name)
#define MX_BEGIN_VISIT_ATTR(name) DEFINE_FIND_READER_KIND_USES(Attr, name)
#define MX_BEGIN_VISIT_PSEUDO(name) DEFINE_FIND_READER_KIND_USES(Pseudo, name)
#define MX_END_VISIT_DECL(name) }
#define MX_END_VISIT_STMT MX_END_VISIT_DECL
#define MX_END_VISIT_TYPE MX_END_VISIT_DECL
#define MX_END_VISIT_PSEUDO MX_END_VISIT_DECL
#define MX_END_VISIT_ATTR MX_END_VISIT_DECL
#include <multiplier/Visitor.inc.h>

}  // namespace

void UseIteratorImpl::FillAndUniqueFragmentIds(void) {
  if (fragment_ids.empty()) {
    for (auto eid : search_ids) {
      auto vid = EntityId(eid).Unpack();
      if (std::holds_alternative<DeclarationId>(vid)) {
        fragment_ids.push_back(std::get<DeclarationId>(vid).fragment_id);
      }
    }
  }

  std::sort(fragment_ids.begin(), fragment_ids.end());
  auto it = std::unique(fragment_ids.begin(), fragment_ids.end());
  fragment_ids.erase(it, fragment_ids.end());
}

UseIteratorImpl::UseIteratorImpl(EntityProvider::Ptr ep_, const Decl &entity)
    : ep(std::move(ep_)) {

  if (MayHaveRemoteUses(entity)) {
    ep->FillUses(ep, entity.id(), search_ids, fragment_ids);
  }

  if (search_ids.empty()) {
    for (const mx::Decl &redecl :
             entity.redeclarations_visible_in_translation_unit()) {
      search_ids.push_back(redecl.id());
      fragment_ids.push_back(redecl.fragment->fragment_id);
    }
  }

  FillAndUniqueFragmentIds();
}

UseIteratorImpl::UseIteratorImpl(EntityProvider::Ptr ep_, const Stmt &entity)
    : ep(std::move(ep_)) {
  search_ids.push_back(entity.id());
  fragment_ids.push_back(entity.fragment->fragment_id);
}

UseIteratorImpl::UseIteratorImpl(EntityProvider::Ptr ep_, const Type &entity)
    : ep(std::move(ep_)) {
  search_ids.push_back(entity.id());
  fragment_ids.push_back(entity.fragment->fragment_id);
}

UseIteratorImpl::UseIteratorImpl(EntityProvider::Ptr ep_, const Attr &entity)
    : ep(std::move(ep_)) {
  search_ids.push_back(entity.id());
  fragment_ids.push_back(entity.fragment->fragment_id);
}

UseIteratorImpl::UseIteratorImpl(FragmentImpl::Ptr frag, const Token &entity)
    : ep(frag->ep) {
  search_ids.push_back(entity.id());
  fragment_ids.push_back(frag->fragment_id);
}

bool UseIteratorImpl::FindNextDecl(UseBase &use) {
  while (list_offset < use.fragment->num_decls) {
    use.offset = list_offset++;
    mx::ast::Decl::Reader reader = use.fragment->NthDecl(use.offset);
    bool found = false;

    use.selectors.reset();

    for (auto eid : search_ids) {
      switch (Get_Decl_Kind(reader)) {

#define MX_BEGIN_VISIT_ABSTRACT_DECL(name)
#define MX_BEGIN_VISIT_DECL(name) \
    case name::static_kind(): \
      FindUses_ ## name (eid, use.selectors, reader, found); \
      break;

#include <multiplier/Visitor.inc.h>

      }
    }

    if (found) {
      return found;
    }
  }

  return false;
}

bool UseIteratorImpl::FindNextStmt(UseBase &use) {
  while (list_offset < use.fragment->num_stmts) {
    use.offset = list_offset++;
    mx::ast::Stmt::Reader reader = use.fragment->NthStmt(use.offset);
    bool found = false;

    use.selectors.reset();

    for (auto eid : search_ids) {
      switch (Get_Stmt_Kind(reader)) {

#define MX_BEGIN_VISIT_ABSTRACT_STMT(name)
#define MX_BEGIN_VISIT_STMT(name) \
    case name::static_kind(): \
      FindUses_ ## name (eid, use.selectors, reader, found); \
      break;

#include <multiplier/Visitor.inc.h>

      }
    }
    if (found) {
      return true;
    }
  }
  return false;
}

bool UseIteratorImpl::FindNextType(UseBase &use) {
  while (list_offset < use.fragment->num_types) {
    use.offset = list_offset++;
    mx::ast::Type::Reader reader = use.fragment->NthType(use.offset);
    bool found = false;

    use.selectors.reset();

    for (auto eid : search_ids) {
      switch (Get_Type_Kind(reader)) {

#define MX_BEGIN_VISIT_ABSTRACT_TYPE(name)
#define MX_BEGIN_VISIT_TYPE(name) \
    case name::static_kind(): \
      FindUses_ ## name (eid, use.selectors, reader, found); \
      break;

#include <multiplier/Visitor.inc.h>

      }
    }

    if (found) {
      return true;
    }
  }

  return false;
}

bool UseIteratorImpl::FindNextAttr(UseBase &use) {
  while (list_offset < use.fragment->num_attrs) {
    use.offset = list_offset++;
    mx::ast::Attr::Reader reader = use.fragment->NthAttr(use.offset);
    bool found = false;

    use.selectors.reset();

    for (auto eid : search_ids) {
      switch (Get_Attr_Kind(reader)) {

#define MX_BEGIN_VISIT_ABSTRACT_ATTR(name)
#define MX_BEGIN_VISIT_ATTR(name) \
    case name::static_kind(): \
      FindUses_ ## name (eid, use.selectors, reader, found); \
      break;

#include <multiplier/Visitor.inc.h>

      }
    }

    if (found) {
      return true;
    }
  }

  return false;
}


bool UseIteratorImpl::FindNextPseudo(UseBase &use) {
  while (list_offset < use.fragment->num_pseudos) {
    TemplateArgument *dummy = nullptr;
    use.offset = list_offset++;
    use.selectors.reset();
    mx::ast::Pseudo::Reader reader =
        use.fragment->NthPseudo(use.offset);
    bool found = false;

    for (auto eid : search_ids) {
      switch (Get_PseudoKind(reader, dummy)) {
        case PseudoKind::CXX_BASE_SPECIFIER:
          use.kind = UseKind::CXX_BASE_SPECIFIER;
          FindUses_CXXBaseSpecifier(eid, use.selectors, reader, found);
          break;
        case PseudoKind::TEMPLATE_ARGUMENT:
          use.kind = UseKind::TEMPLATE_ARGUMENT;
          FindUses_TemplateArgument(eid, use.selectors, reader, found);
          break;
        case PseudoKind::TEMPLATE_PARAMETER_LIST:
          use.kind = UseKind::TEMPLATE_PARAMETER_LIST;
          FindUses_TemplateParameterList(eid, use.selectors, reader, found);
          break;
        case PseudoKind::DESIGNATOR:
          use.kind = UseKind::DESIGNATOR;
          FindUses_Designator(eid, use.selectors, reader, found);
          break;
      }
    }

    if (found) {
      return true;
    }
  }

  return false;
}

bool UseIteratorImpl::FindNext(UseBase &use) {
  for (;;) {
    if (!use.fragment) {
      if (fragment_offset >= fragment_ids.size()) {
        return false;

      } else {
        use.fragment = ep->FragmentFor(
            ep, fragment_ids[fragment_offset++]);
        if (!use.fragment) {
          continue;  // Skip to next; didn't find for some reason.
        }
      }
    }

    switch (use.kind) {
      case UseKind::DECLARATION:
        if (FindNextDecl(use)) {
          return true;

        } else {
          // Skip to next list; didn't find.
          use.kind = UseKind::STATEMENT;
          list_offset = 0u;
          continue;
        }
      case UseKind::STATEMENT:
        if (FindNextStmt(use)) {
          return true;
        } else {
          // Skip to next list; didn't find.
          use.kind = UseKind::TYPE;
          list_offset = 0u;
          continue;
        }
      case UseKind::TYPE:
        if (FindNextType(use)) {
          return true;
        } else {
          // Skip to next list; didn't find.
          use.kind = UseKind::ATTRIBUTE;
          list_offset = 0u;
          continue;
        }
      case UseKind::ATTRIBUTE:
        if (FindNextAttr(use)) {
          return true;
        } else {
          // Skip to next list; didn't find.
          use.kind = UseKind::CXX_BASE_SPECIFIER;
          list_offset = 0u;
          continue;
        }
      case UseKind::CXX_BASE_SPECIFIER:
      case UseKind::TEMPLATE_ARGUMENT:
      case UseKind::TEMPLATE_PARAMETER_LIST:
      case UseKind::DESIGNATOR:
        if (FindNextPseudo(use)) {
          return true;

        } else {
          // Skip to next fragment; didn't find.
          use.fragment.reset();
          list_offset = 0u;
          use.kind = UseKind::DECLARATION;
          continue;
        }
    }
  }

  return false;
}

UseBase::~UseBase(void) {}

UseBase::UseBase(Decl entity, UseSelectorSet selectors_)
    : selectors(std::move(selectors_)),
      fragment(std::move(entity.fragment)),
      offset(entity.offset_),
      kind(UseKind::DECLARATION) {}

UseBase::UseBase(Stmt entity, UseSelectorSet selectors_)
    : selectors(std::move(selectors_)),
      fragment(std::move(entity.fragment)),
      offset(entity.offset_),
      kind(UseKind::STATEMENT) {}

UseBase::UseBase(Type entity, UseSelectorSet selectors_)
    : selectors(std::move(selectors_)),
      fragment(std::move(entity.fragment)),
      offset(entity.offset_),
      kind(UseKind::TYPE) {}

UseBase::UseBase(Attr entity, UseSelectorSet selectors_)
    : selectors(std::move(selectors_)),
      fragment(std::move(entity.fragment)),
      offset(entity.offset_),
      kind(UseKind::ATTRIBUTE) {}

UseBase::UseBase(Designator entity, UseSelectorSet selectors_)
    : selectors(std::move(selectors_)),
      fragment(std::move(entity.fragment)),
      offset(entity.offset_),
      kind(UseKind::DESIGNATOR) {}

UseBase::UseBase(CXXBaseSpecifier entity, UseSelectorSet selectors_)
    : selectors(std::move(selectors_)),
      fragment(std::move(entity.fragment)),
      offset(entity.offset_),
      kind(UseKind::CXX_BASE_SPECIFIER) {}

UseBase::UseBase(TemplateArgument entity, UseSelectorSet selectors_)
    : selectors(std::move(selectors_)),
      fragment(std::move(entity.fragment)),
      offset(entity.offset_),
      kind(UseKind::TEMPLATE_ARGUMENT) {}

UseBase::UseBase(TemplateParameterList entity, UseSelectorSet selectors_)
    : fragment(std::move(entity.fragment)),
      offset(entity.offset_),
      kind(UseKind::TEMPLATE_PARAMETER_LIST) {}

VariantUse UseBase::entity(void) const {
  if (!fragment) {
    return NotAnEntity{};
  }

  switch (kind) {
    case UseKind::DECLARATION:
      if (offset < fragment->num_decls) {
        return Decl(fragment, offset);
      } else {
        return NotAnEntity{};
      }
    case UseKind::STATEMENT:
      if (offset < fragment->num_stmts) {
        return Stmt(fragment, offset);
      } else {
        return NotAnEntity{};
      }
    case UseKind::TYPE:
      if (offset < fragment->num_types) {
        return Type(fragment, offset);
      } else {
        return NotAnEntity{};
      }
    case UseKind::CXX_BASE_SPECIFIER:
      if (offset < fragment->num_pseudos) {
        return CXXBaseSpecifier(fragment, offset);
      } else {
        return NotAnEntity{};
      }
    case UseKind::TEMPLATE_ARGUMENT:
      if (offset < fragment->num_pseudos) {
        return TemplateArgument(fragment, offset);
      } else {
        return NotAnEntity{};
      }
    case UseKind::TEMPLATE_PARAMETER_LIST:
      if (offset < fragment->num_pseudos) {
        return TemplateParameterList(fragment, offset);
      } else {
        return NotAnEntity{};
      }
    case UseKind::DESIGNATOR:
      if (offset < fragment->num_pseudos) {
        return Designator(fragment, offset);
      } else {
        return NotAnEntity{};
      }
    case UseKind::ATTRIBUTE:
      if (offset < fragment->num_attrs) {
        return Attr(fragment, offset);
      } else {
        return NotAnEntity{};
      }
  }

  return NotAnEntity{};
}

std::optional<Decl> UseBase::as_declaration(void) const {
  if (kind == UseKind::DECLARATION && fragment && offset < fragment->num_decls) {
    return Decl(fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<Stmt> UseBase::as_statement(void) const {
  if (kind == UseKind::STATEMENT && fragment && offset < fragment->num_stmts) {
    return Stmt(fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<Type> UseBase::as_type(void) const {
  if (kind == UseKind::TYPE && fragment && offset < fragment->num_types) {
    return Type(fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<Attr> UseBase::as_attribute(void) const {
  if (kind == UseKind::ATTRIBUTE && fragment && offset < fragment->num_attrs) {
    return Attr(fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXBaseSpecifier> UseBase::as_cxx_base_specifier(void) const {
  if (kind == UseKind::CXX_BASE_SPECIFIER && fragment &&
      offset < fragment->num_pseudos) {
    return CXXBaseSpecifier(fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<TemplateArgument> UseBase::as_template_argument(void) const {
  if (kind == UseKind::TEMPLATE_ARGUMENT && fragment &&
      offset < fragment->num_pseudos) {
    return TemplateArgument(fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<TemplateParameterList>
UseBase::as_template_parameter_list(void) const {
  if (kind == UseKind::TEMPLATE_PARAMETER_LIST && fragment &&
      offset < fragment->num_pseudos) {
    return TemplateParameterList(fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<Designator> UseBase::as_designator(void) const {
  if (kind == UseKind::DESIGNATOR && fragment &&
      offset < fragment->num_pseudos) {
    return Designator(fragment, offset);
  } else {
    return std::nullopt;
  }
}

Stmt Reference::statement(void) && noexcept {
  return Stmt(std::move(fragment), offset);
}

Stmt Reference::statement(void) const & noexcept {
  return Stmt(fragment, offset);
}

Reference::operator Stmt(void) && noexcept {
  return Stmt(std::move(fragment), offset);
}

Reference::operator Stmt(void) const & noexcept {
  return Stmt(fragment, offset);
}

}  // namespace mx
