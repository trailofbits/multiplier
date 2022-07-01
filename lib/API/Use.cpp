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
#define MX_BEGIN_VISIT_PSEUDO(name) DEFINE_FIND_READER_KIND_USES(Pseudo, name)
#define MX_END_VISIT_DECL(name) }
#define MX_END_VISIT_STMT MX_END_VISIT_DECL
#define MX_END_VISIT_TYPE MX_END_VISIT_DECL
#define MX_END_VISIT_PSEUDO MX_END_VISIT_DECL
#include <multiplier/Visitor.inc.h>

}  // namespace

void BaseUseIteratorImpl::FillAndUniqueFragmentIds(void) {

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
    : BaseUseIteratorImpl(std::move(ep_)) {

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
    : BaseUseIteratorImpl(std::move(ep_)) {
  search_ids.push_back(entity.id());
  fragment_ids.push_back(entity.fragment->fragment_id);
}

UseIteratorImpl::UseIteratorImpl(EntityProvider::Ptr ep_, const Type &entity)
    : BaseUseIteratorImpl(std::move(ep_)) {
  search_ids.push_back(entity.id());
  fragment_ids.push_back(entity.fragment->fragment_id);
}

UseIteratorImpl::UseIteratorImpl(FragmentImpl::Ptr frag, const Token &entity)
    : BaseUseIteratorImpl(frag->ep) {
  search_ids.push_back(entity.id());
  fragment_ids.push_back(frag->fragment_id);
}

bool UseIteratorImpl::FindNextDecl(UseIteratorBase &self) {
  while (self.list_offset < self.use.fragment->num_decls) {
    self.use.offset = self.list_offset++;
    mx::ast::Decl::Reader reader = self.use.fragment->NthDecl(self.use.offset);
    bool found = false;

    self.use.selectors.reset();

    for (auto eid : search_ids) {
      switch (Get_Decl_Kind(reader)) {

#define MX_BEGIN_VISIT_ABSTRACT_DECL(name)
#define MX_BEGIN_VISIT_DECL(name) \
    case name::static_kind(): \
      FindUses_ ## name (eid, self.use.selectors, reader, found); \
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

bool UseIteratorImpl::FindNextStmt(UseIteratorBase &self) {
  while (self.list_offset < self.use.fragment->num_stmts) {
    self.use.offset = self.list_offset++;
    mx::ast::Stmt::Reader reader = self.use.fragment->NthStmt(self.use.offset);
    bool found = false;

    self.use.selectors.reset();

    for (auto eid : search_ids) {
      switch (Get_Stmt_Kind(reader)) {

#define MX_BEGIN_VISIT_ABSTRACT_STMT(name)
#define MX_BEGIN_VISIT_STMT(name) \
    case name::static_kind(): \
      FindUses_ ## name (eid, self.use.selectors, reader, found); \
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

bool UseIteratorImpl::FindNextType(UseIteratorBase &self) {
  while (self.list_offset < self.use.fragment->num_types) {
    self.use.offset = self.list_offset++;
    mx::ast::Type::Reader reader = self.use.fragment->NthType(self.use.offset);
    bool found = false;

    self.use.selectors.reset();

    for (auto eid : search_ids) {
      switch (Get_Type_Kind(reader)) {

#define MX_BEGIN_VISIT_ABSTRACT_TYPE(name)
#define MX_BEGIN_VISIT_TYPE(name) \
    case name::static_kind(): \
      FindUses_ ## name (eid, self.use.selectors, reader, found); \
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

bool UseIteratorImpl::FindNextPseudo(UseIteratorBase &self) {
  while (self.list_offset < self.use.fragment->num_pseudos) {
    TemplateArgument *dummy = nullptr;
    self.use.offset = self.list_offset++;
    self.use.selectors.reset();
    mx::ast::Pseudo::Reader reader =
        self.use.fragment->NthPseudo(self.use.offset);
    bool found = false;

    for (auto eid : search_ids) {
      switch (Get_PseudoKind(reader, dummy)) {
        case PseudoKind::CXX_BASE_SPECIFIER:
          self.use.kind = UseKind::CXX_BASE_SPECIFIER;
          FindUses_CXXBaseSpecifier(eid, self.use.selectors, reader, found);
          break;
        case PseudoKind::TEMPLATE_ARGUMENT:
          self.use.kind = UseKind::TEMPLATE_ARGUMENT;
          FindUses_TemplateArgument(eid, self.use.selectors, reader, found);
          break;
        case PseudoKind::TEMPLATE_PARAMETER_LIST:
          self.use.kind = UseKind::TEMPLATE_PARAMETER_LIST;
          FindUses_TemplateParameterList(eid, self.use.selectors, reader, found);
          break;
        case PseudoKind::DESIGNATOR:
          self.use.kind = UseKind::DESIGNATOR;
          FindUses_Designator(eid, self.use.selectors, reader, found);
          break;
      }
    }

    if (found) {
      return true;
    }
  }

  return false;
}

bool UseIteratorImpl::FindNext(UseIteratorBase &self) {
  for (;;) {
    if (!self.use.fragment) {
      if (self.fragment_offset >= fragment_ids.size()) {
        return false;

      } else {
        self.use.fragment = ep->FragmentFor(
            ep, fragment_ids[self.fragment_offset++]);
        if (!self.use.fragment) {
          continue;  // Skip to next; didn't find for some reason.
        }
      }
    }

    switch (self.use.kind) {
      case UseKind::DECLARATION:
        if (FindNextDecl(self)) {
          return true;

        } else {
          // Skip to next list; didn't find.
          self.use.kind = UseKind::STATEMENT;
          self.list_offset = 0u;
          continue;
        }
      case UseKind::STATEMENT:
        if (FindNextStmt(self)) {
          return true;
        } else {
          // Skip to next list; didn't find.
          self.use.kind = UseKind::TYPE;
          self.list_offset = 0u;
          continue;
        }
      case UseKind::TYPE:
        if (FindNextType(self)) {
          return true;
        } else {
          // Skip to next list; didn't find.
          self.use.kind = UseKind::CXX_BASE_SPECIFIER;
          self.list_offset = 0u;
          continue;
        }
      case UseKind::CXX_BASE_SPECIFIER:
      case UseKind::TEMPLATE_ARGUMENT:
      case UseKind::TEMPLATE_PARAMETER_LIST:
      case UseKind::DESIGNATOR:
        if (FindNextPseudo(self)) {
          return true;

        } else {
          // Skip to next fragment; didn't find.
          self.use.fragment.reset();
          self.list_offset = 0u;
          self.use.kind = UseKind::DECLARATION;
          continue;
        }
    }
  }

  return false;
}

void UseIteratorBase::Advance(void) {
  if (!impl->FindNext(*this)) {
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

std::optional<Designator>
UseBase::as_designator(void) const {
  if (kind == UseKind::DESIGNATOR && fragment &&
      offset < fragment->num_pseudos) {
    return Designator(fragment, offset);
  } else {
    return std::nullopt;
  }
}

ReferenceIteratorImpl::ReferenceIteratorImpl(EntityProvider::Ptr ep_,
                                             const Decl &entity)
    : BaseUseIteratorImpl(std::move(ep_)) {

  if (MayHaveRemoteUses(entity)) {
    ep->FillReferences(ep, entity.id(), search_ids, fragment_ids);
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

ReferenceIterator::~ReferenceIterator(void) {}

void ReferenceIterator::Advance(void) {
  if (!impl) {
    return;
  }

  for (;;) {
    // Initialize to the first statement of the fragment.
    if (!user.fragment) {
      if (fragment_offset >= impl->fragment_ids.size()) {
        impl.reset();  // Done.
        return;
      }

      auto frag_id = impl->fragment_ids[fragment_offset++];
      user.fragment = impl->ep->FragmentFor(impl->ep, frag_id);
      if (!user.fragment) {
        continue;
      }

      user.offset = 0u;

    // Skip to the next statement.
    } else {
      ++user.offset;
    }

    // We've exhausted the statements in this fragment; skip to the next
    // fragment.
    if (user.offset >= user.fragment->num_stmts) {
      user.fragment.reset();
      user.offset = 0u;
      continue;
    }

    Stmt stmt(std::move(user.fragment), user.offset);
    switch (stmt.kind()) {
      case StmtKind::DECL_REF_EXPR:
      case StmtKind::MEMBER_EXPR:
      case StmtKind::CXX_CONSTRUCT_EXPR:
      case StmtKind::CXX_NEW_EXPR:
      case StmtKind::GOTO_STMT:
      case StmtKind::UNARY_EXPR_OR_TYPE_TRAIT_EXPR:
      case StmtKind::BUILTIN_BIT_CAST_EXPR:
      case StmtKind::C_STYLE_CAST_EXPR:
      case StmtKind::CXX_FUNCTIONAL_CAST_EXPR:
      case StmtKind::CXX_ADDRSPACE_CAST_EXPR:
      case StmtKind::CXX_CONST_CAST_EXPR:
      case StmtKind::CXX_DYNAMIC_CAST_EXPR:
      case StmtKind::CXX_REINTERPRET_CAST_EXPR:
      case StmtKind::CXX_STATIC_CAST_EXPR:
      case StmtKind::OBJ_C_BRIDGED_CAST_EXPR:
      //case StmtKind::IMPLICIT_CAST_EXPR:
        if (auto ref_decl = stmt.referenced_declaration()) {
          RawEntityId referenced_id = ref_decl->id();
          for (auto search_id : impl->search_ids) {
            if (referenced_id == search_id) {
              user.fragment = std::move(stmt.fragment);  // Take it back.
              return;  // Hit!
            }
          }
        }
        break;
      default:
        break;
    }

    user.fragment = std::move(stmt.fragment);  // Take it back.
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
