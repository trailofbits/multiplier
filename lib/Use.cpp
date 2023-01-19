// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Use.h"

#include <cassert>
#include <multiplier/AST.h>
#include <type_traits>

#include "API.h"
#include "Fragment.h"

namespace mx {
namespace {

static thread_local RawEntityIdList tIgnoredRedecls;

#define MX_VISIT_ENUM(cls, api_name, storage, apply, \
                      pasta_name, type, nth_list) \
    template <typename Reader> \
    inline static type Get_ ## cls ## _ ## pasta_name(const Reader &reader) { \
      return static_cast<type>(reader.getVal ## storage()); \
    }

#define MX_VISIT_PSEUDO_KIND(cls, storage) \
    inline static PseudoKind Get_Pseudo_Kind( \
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
#define MX_BEGIN_VISIT_MACRO(name) DECLARE_FIND_READER_USES(Macro, name)
#define MX_BEGIN_VISIT_PSEUDO(name) DECLARE_FIND_READER_USES(Pseudo, name)

#include <multiplier/Visitor.inc.h>

#define DEFINE_FIND_READER_KIND_USES(reader_kind, name) \
    void FindUses_ ## name ( \
        mx::RawEntityId eid, UseSelectorSet &selectors, \
        const mx::ast::reader_kind::Reader &reader, bool &found) { \
        (void) eid; \
        (void) selectors; \
        (void) reader; \
        (void) found;

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
#define MX_BEGIN_VISIT_MACRO(name) DEFINE_FIND_READER_KIND_USES(Macro, name)
#define MX_BEGIN_VISIT_PSEUDO(name) DEFINE_FIND_READER_KIND_USES(Pseudo, name)
#define MX_END_VISIT_DECL(name) }
#define MX_END_VISIT_STMT MX_END_VISIT_DECL
#define MX_END_VISIT_TYPE MX_END_VISIT_DECL
#define MX_END_VISIT_PSEUDO MX_END_VISIT_DECL
#define MX_END_VISIT_ATTR MX_END_VISIT_DECL
#define MX_END_VISIT_MACRO MX_END_VISIT_DECL
#include <multiplier/Visitor.inc.h>

template <typename Reader>
static DeclKind Get_Decl_Kind(const Reader &);

template <typename Reader>
static StmtKind Get_Stmt_Kind(const Reader &);

template <typename Reader>
static TypeKind Get_Type_Kind(const Reader &);

template <typename Reader>
static AttrKind Get_Attr_Kind(const Reader &);

template <typename Reader>
static MacroKind Get_Macro_Kind(const Reader &);

}  // namespace

const char *EnumeratorName(UseKind kind) {
  switch (kind) {
    case UseKind::DECLARATION: return "DECLARATION";
    case UseKind::STATEMENT: return "STATEMENT";
    case UseKind::TYPE: return "TYPE";
    case UseKind::CXX_BASE_SPECIFIER: return "CXX_BASE_SPECIFIER";
    case UseKind::TEMPLATE_ARGUMENT: return "TEMPLATE_ARGUMENT";
    case UseKind::TEMPLATE_PARAMETER_LIST: return "TEMPLATE_PARAMETER_LIST";
    case UseKind::DESIGNATOR: return "DESIGNATOR";
    case UseKind::ATTRIBUTE: return "ATTRIBUTE";
    case UseKind::MACRO: return "MACRO";
  }
  return "<invalid>";
}

UseIteratorImpl::UseIteratorImpl(EntityProvider::Ptr ep_, const Decl &entity)
    : BaseUseIteratorImpl(std::move(ep_)) {
  PackedDeclarationId sid = entity.id();

  ep->FillUses(ep, sid.Pack(), search_ids, fragment_ids);

  // Make sure all fragments containing each redeclaration is present in
  // the output fragment ID list.
  for (RawEntityId search_id : search_ids) {
    DeclarationId id = std::get<DeclarationId>(EntityId(search_id).Unpack());
    fragment_ids.emplace_back(FragmentId(id.fragment_id));
  }

  std::sort(search_ids.begin(), search_ids.end());
  auto it = std::unique(search_ids.begin(), search_ids.end());
  search_ids.erase(it, search_ids.end());

  std::sort(fragment_ids.begin(), fragment_ids.end());
  auto it2 = std::unique(fragment_ids.begin(), fragment_ids.end());
  fragment_ids.erase(it2, fragment_ids.end());
}

UseIteratorImpl::UseIteratorImpl(EntityProvider::Ptr ep_, const Stmt &entity)
    : BaseUseIteratorImpl(std::move(ep_)) {
  PackedStatementId id = entity.id();
  search_ids.push_back(entity.id().Pack());
  fragment_ids.emplace_back(FragmentId(id.Unpack().fragment_id));
}

UseIteratorImpl::UseIteratorImpl(EntityProvider::Ptr ep_, const Type &entity)
    : BaseUseIteratorImpl(std::move(ep_)) {
  PackedTypeId id = entity.id();
  search_ids.push_back(entity.id().Pack());
  fragment_ids.emplace_back(FragmentId(id.Unpack().fragment_id));
}

UseIteratorImpl::UseIteratorImpl(EntityProvider::Ptr ep_, const Attr &entity)
    : BaseUseIteratorImpl(std::move(ep_)) {
  PackedAttributeId id = entity.id();
  search_ids.push_back(entity.id().Pack());
  fragment_ids.emplace_back(FragmentId(id.Unpack().fragment_id));
}

UseIteratorImpl::UseIteratorImpl(EntityProvider::Ptr ep_, const Macro &entity)
    : BaseUseIteratorImpl(std::move(ep_)) {

  PackedMacroId id = entity.id();
  RawEntityId raw_id = id.Pack();
  search_ids.push_back(raw_id);

  // TODO(pag): Support redeclarations of macros.
  ep->FillUses(ep, raw_id, tIgnoredRedecls, fragment_ids);
  assert(tIgnoredRedecls.empty());

  fragment_ids.emplace_back(FragmentId(id.Unpack().fragment_id));

  std::sort(fragment_ids.begin(), fragment_ids.end());
  auto it = std::unique(fragment_ids.begin(), fragment_ids.end());
  fragment_ids.erase(it, fragment_ids.end());
}

UseIteratorImpl::UseIteratorImpl(EntityProvider::Ptr ep_, const File &entity)
    : BaseUseIteratorImpl(std::move(ep_)) {

  RawEntityId raw_id = entity.id().Pack();
  search_ids.push_back(raw_id);

  ep->FillUses(ep, raw_id, tIgnoredRedecls, fragment_ids);
  assert(tIgnoredRedecls.empty());
}

UseIteratorImpl::UseIteratorImpl(FragmentImpl::Ptr frag, const Token &entity)
    : BaseUseIteratorImpl(frag->ep) {

  EntityId eid = entity.id();
  RawEntityId raw_id = eid.Pack();
  search_ids.push_back(raw_id);

  ep->FillUses(ep, raw_id, tIgnoredRedecls, fragment_ids);
  assert(tIgnoredRedecls.empty());

  // This token might be part of a fragment.
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<ParsedTokenId>(vid)) {
    ParsedTokenId tid = std::get<ParsedTokenId>(vid);
    fragment_ids.emplace_back(FragmentId(tid.fragment_id));

  } else if (std::holds_alternative<MacroTokenId>(vid)) {
    MacroTokenId tid = std::get<MacroTokenId>(vid);
    fragment_ids.emplace_back(FragmentId(tid.fragment_id));
  }

  std::sort(fragment_ids.begin(), fragment_ids.end());
  auto it = std::unique(fragment_ids.begin(), fragment_ids.end());
  fragment_ids.erase(it, fragment_ids.end());
}

bool UseIteratorImpl::FindNextDecl(UseBase &use) {
  while (auto decl_reader = use.fragment->NthDecl(list_offset)) {
    use.offset = list_offset++;
    mx::ast::Decl::Reader reader = (*decl_reader)->Reader<mx::ast::Decl>();
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
  while (auto stmt_reader = use.fragment->NthStmt(list_offset)) {
    use.offset = list_offset++;
    mx::ast::Stmt::Reader reader = (*stmt_reader)->Reader<mx::ast::Stmt>();
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
  while (auto type_reader = use.fragment->NthType(list_offset)) {
    use.offset = list_offset++;
    mx::ast::Type::Reader reader = (*type_reader)->Reader<mx::ast::Type>();
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
  while (auto decl_reader = use.fragment->NthAttr(list_offset)) {
    use.offset = list_offset++;
    mx::ast::Attr::Reader reader = (*decl_reader)->Reader<mx::ast::Attr>();
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

bool UseIteratorImpl::FindNextMacro(UseBase& use) {
  while (auto macro_reader = use.fragment->NthMacro(list_offset)) {
    use.offset = list_offset++;
    mx::ast::Macro::Reader reader = (*macro_reader)->Reader<mx::ast::Macro>();
    bool found = false;

    use.selectors.reset();

    for (auto eid : search_ids) {
      switch (Get_Macro_Kind(reader)) {

#define MX_BEGIN_VISIT_ABSTRACT_MACRO(name)
#define MX_BEGIN_VISIT_MACRO(name) \
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
  while (auto pseudo_reader = use.fragment->NthPseudo(list_offset)) {
    TemplateArgument *dummy = nullptr;
    use.offset = list_offset++;
    use.selectors.reset();
    mx::ast::Pseudo::Reader reader =
        (*pseudo_reader)->Reader<mx::ast::Pseudo>();
    bool found = false;

    for (auto eid : search_ids) {
      switch (Get_Pseudo_Kind(reader, dummy)) {
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
          use.kind = UseKind::MACRO;
          list_offset = 0u;
          continue;
        }
      case UseKind::MACRO:
        if (FindNextMacro(use)) {
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

UseBase::UseBase(Macro entity, UseSelectorSet selectors_)
    : selectors(std::move(selectors_)),
      fragment(std::move(entity.fragment)),
      offset(entity.offset_),
      kind(UseKind::MACRO) {}

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
    : selectors(std::move(selectors_)),
      fragment(std::move(entity.fragment)),
      offset(entity.offset_),
      kind(UseKind::TEMPLATE_PARAMETER_LIST) {}

VariantUse UseBase::entity(void) const {
  if (!fragment) {
    return NotAnEntity{};
  }

  FragmentId fid(fragment->fragment_id);

  switch (kind) {
    case UseKind::DECLARATION:
      if (auto decl_reader = fragment->NthDecl(offset)) {
        return Decl(std::move(*decl_reader), fragment, offset);
      } else {
        return NotAnEntity{};
      }
    case UseKind::STATEMENT:
      if (auto stmt_reader = fragment->NthStmt(offset)) {
        return Stmt(std::move(*stmt_reader), fragment, offset);
      } else {
        return NotAnEntity{};
      }
    case UseKind::TYPE:
      if (auto type_reader = fragment->NthType(offset)) {
        return Type(std::move(*type_reader), fragment, offset);
      } else {
        return NotAnEntity{};
      }
    case UseKind::MACRO:
      if (auto macro_reader = fragment->NthMacro(offset)) {
        return Macro(std::move(*macro_reader), fragment, offset);
      } else {
        return NotAnEntity{};
      }
    case UseKind::CXX_BASE_SPECIFIER:
      if (auto pseudo_reader = fragment->NthPseudo(offset)) {
        return CXXBaseSpecifier(std::move(*pseudo_reader), fragment, offset);
      } else {
        return NotAnEntity{};
      }
    case UseKind::TEMPLATE_ARGUMENT:
      if (auto pseudo_reader = fragment->NthPseudo(offset)) {
        return TemplateArgument(std::move(*pseudo_reader), fragment, offset);
      } else {
        return NotAnEntity{};
      }
    case UseKind::TEMPLATE_PARAMETER_LIST:
      if (auto pseudo_reader = fragment->NthPseudo(offset)) {
        return TemplateParameterList(std::move(*pseudo_reader), fragment, offset);
      } else {
        return NotAnEntity{};
      }
    case UseKind::DESIGNATOR:
      if (auto pseudo_reader = fragment->NthPseudo(offset)) {
        return Designator(std::move(*pseudo_reader), fragment, offset);
      } else {
        return NotAnEntity{};
      }
    case UseKind::ATTRIBUTE:
      if (auto attr_reader = fragment->NthAttr(offset)) {
        return Attr(std::move(*attr_reader), fragment, offset);
      } else {
        return NotAnEntity{};
      }
  }

  return NotAnEntity{};
}

std::optional<Decl> UseBase::as_declaration(void) const {
  auto decl_reader = fragment->NthDecl(offset);
  if (kind == UseKind::DECLARATION && fragment && decl_reader.has_value()) {
    return Decl(std::move(*decl_reader), fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<Stmt> UseBase::as_statement(void) const {
  auto stmt_reader = fragment->NthStmt(offset);
  if (kind == UseKind::STATEMENT && fragment && stmt_reader.has_value()) {
    return Stmt(std::move(*stmt_reader), fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<Type> UseBase::as_type(void) const {
  auto type_reader = fragment->NthType(offset);
  if (kind == UseKind::TYPE && fragment && type_reader.has_value()) {
    return Type(std::move(*type_reader), fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<Attr> UseBase::as_attribute(void) const {
  auto attr_reader = fragment->NthAttr(offset);
  if (kind == UseKind::ATTRIBUTE && fragment && attr_reader.has_value()) {
    return Attr(std::move(*attr_reader), fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<Macro> UseBase::as_macro(void) const {
  auto macro_reader = fragment->NthMacro(offset);
  if (kind == UseKind::MACRO && fragment && macro_reader.has_value()) {
    return Macro(std::move(*macro_reader), fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXBaseSpecifier> UseBase::as_cxx_base_specifier(void) const {
  auto pseudo_reader = fragment->NthPseudo(offset);
  if (kind == UseKind::CXX_BASE_SPECIFIER && fragment &&
      pseudo_reader.has_value()) {
    return CXXBaseSpecifier(std::move(*pseudo_reader), fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<TemplateArgument> UseBase::as_template_argument(void) const {
  auto pseudo_reader = fragment->NthPseudo(offset);
  if (kind == UseKind::TEMPLATE_ARGUMENT && fragment &&
      pseudo_reader.has_value()) {
    return TemplateArgument(std::move(*pseudo_reader), fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<TemplateParameterList>
UseBase::as_template_parameter_list(void) const {
  auto pseudo_reader = fragment->NthPseudo(offset);
  if (kind == UseKind::TEMPLATE_PARAMETER_LIST && fragment &&
      pseudo_reader.has_value()) {
    return TemplateParameterList(std::move(*pseudo_reader), fragment, offset);
  } else {
    return std::nullopt;
  }
}

std::optional<Designator> UseBase::as_designator(void) const {
  auto pseudo_reader = fragment->NthPseudo(offset);
  if (kind == UseKind::DESIGNATOR && fragment &&
      pseudo_reader.has_value()) {
    return Designator(std::move(*pseudo_reader), fragment, offset);
  } else {
    return std::nullopt;
  }
}

ReferenceIteratorImpl::ReferenceIteratorImpl(EntityProvider::Ptr ep_,
                                             const Decl &entity)
    : BaseUseIteratorImpl(std::move(ep_)) {
  PackedDeclarationId sid = entity.id();

  ep->FillReferences(ep, sid.Pack(), search_ids, fragment_ids);

  // Make sure all fragments containing each redeclaration is present in
  // the output fragment ID list.
  for (RawEntityId search_id : search_ids) {
    DeclarationId id = std::get<DeclarationId>(EntityId(search_id).Unpack());
    fragment_ids.emplace_back(FragmentId(id.fragment_id));
  }

  std::sort(search_ids.begin(), search_ids.end());
  auto it = std::unique(search_ids.begin(), search_ids.end());
  search_ids.erase(it, search_ids.end());

  std::sort(fragment_ids.begin(), fragment_ids.end());
  auto it2 = std::unique(fragment_ids.begin(), fragment_ids.end());
  fragment_ids.erase(it2, fragment_ids.end());
}

ReferenceIteratorImpl::ReferenceIteratorImpl(EntityProvider::Ptr ep_,
                                             const Macro &entity)
    : BaseUseIteratorImpl(std::move(ep_)) {
  SpecificEntityId<MacroId> sid = entity.id();
  ep->FillReferences(ep, sid.Pack(), tIgnoredRedecls, fragment_ids);
  assert(tIgnoredRedecls.empty());

  // Make sure the fragments containing the macro is present in
  // the output fragment ID list.
  search_ids.emplace_back(sid.Pack());
  fragment_ids.emplace_back(FragmentId(sid.Unpack().fragment_id));

  std::sort(fragment_ids.begin(), fragment_ids.end());
  auto it2 = std::unique(fragment_ids.begin(), fragment_ids.end());
  fragment_ids.erase(it2, fragment_ids.end());
}

ReferenceIteratorImpl::ReferenceIteratorImpl(EntityProvider::Ptr ep_,
                                             const File &entity)
    : BaseUseIteratorImpl(std::move(ep_)) {

  SpecificEntityId<FileId> sid = entity.id();
  ep->FillReferences(ep, sid.Pack(), tIgnoredRedecls, fragment_ids);
  assert(tIgnoredRedecls.empty());

  search_ids.emplace_back(sid.Pack());

  std::sort(fragment_ids.begin(), fragment_ids.end());
  auto it2 = std::unique(fragment_ids.begin(), fragment_ids.end());
  fragment_ids.erase(it2, fragment_ids.end());

  // NOTE(pag): Not all files will have uses, as some are the main source
  //            files of the compiler itself.
}

gap::generator<MacroReference> ReferenceIteratorImpl::enumerate_macros(void) {
  if (search_ids.empty() || fragment_ids.empty()) {
    co_return;
  }

  assert(search_ids.size() == 1u);
  RawEntityId search_id = search_ids[0];
  unsigned fragment_offset = 0u;
  MacroReference user;

  for (;;) {
    // Initialize to the first macro of the fragment.
    if (!user.fragment) {
      if (fragment_offset >= fragment_ids.size()) {
        co_return;
      }

      auto frag_id = fragment_ids[fragment_offset++];
      user.fragment = ep->FragmentFor(ep, frag_id);
      if (!user.fragment) {
        continue;
      }

      user.offset = 0u;

    // Skip to the next macro.
    } else {
      ++user.offset;
    }

    // We've exhausted the macros in this fragment; skip to the next
    // fragment.
    auto macro_reader = user.fragment->NthMacro(user.offset);
    if (!macro_reader.has_value()) {
      user.fragment.reset();
      user.offset = 0u;
      continue;
    }

    Macro macro(std::move(*macro_reader), std::move(user.fragment), user.offset);

    // Needs to match what is in `LinkExternalReferencesInFragment` in
    // `bin/Index/LinkExternalReferencesInFragment.cpp`.
    switch (macro.kind()) {
      case mx::MacroKind::EXPANSION: {
        auto &exp = reinterpret_cast<const MacroExpansion &>(macro);
        if (auto def = exp.definition()) {
          SpecificEntityId<MacroId> referenced_id = def->id();
          if (referenced_id.Pack() == search_id) {
            user.fragment = std::move(macro.fragment);  // Take it back.
            co_yield user;  // Hit!
          }
        }
        break;
      }
      case mx::MacroKind::INCLUDE_DIRECTIVE:
      case mx::MacroKind::INCLUDE_NEXT_DIRECTIVE:
      case mx::MacroKind::INCLUDE_MACROS_DIRECTIVE:
      case mx::MacroKind::IMPORT_DIRECTIVE: {
        auto &inc = reinterpret_cast<const IncludeLikeMacroDirective &>(macro);
        if (auto file = inc.included_file()) {
          SpecificEntityId<FileId> referenced_id = file->id();
          if (referenced_id.Pack() == search_id) {
            user.fragment = std::move(macro.fragment);  // Take it back.
            co_yield user;  // Hit!
          }
        }
        break;
      }

      default:
        break;
    }

    user.fragment = std::move(macro.fragment);  // Take it back.
  }
}

gap::generator<StmtReference> ReferenceIteratorImpl::enumerate_stmts(void) {
  if (search_ids.empty() || fragment_ids.empty()) {
    co_return;
  }

  unsigned fragment_offset = 0;
  StmtReference user;
  for (;;) {
    // Initialize to the first statement of the fragment.
    if (!user.fragment) {
      if (fragment_offset >= fragment_ids.size()) {
        co_return;
      }

      auto frag_id = fragment_ids[fragment_offset++];
      user.fragment = ep->FragmentFor(ep, frag_id);
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
    auto stmt_reader = user.fragment->NthStmt(user.offset);
    if (!stmt_reader.has_value()) {
      user.fragment.reset();
      user.offset = 0u;
      continue;
    }

    Stmt stmt(std::move(*stmt_reader), std::move(user.fragment), user.offset);
    switch (stmt.kind()) {
      // Has to match with what is supported by `ReferencedDecl` in
      // `bin/Index/Util.cpp`.
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

      // TODO(pag): Do we want implicit casts? They end up being quite "verbose"
      //            in terms of quantities of outputs. If so, make sure to
      //            update `ReferencedDecl`.
      // case StmtKind::IMPLICIT_CAST_EXPR:

        if (std::optional<Decl> ref_decl = stmt.referenced_declaration()) {
          PackedDeclarationId referenced_id = ref_decl->id();
          for (RawEntityId search_id : search_ids) {
            if (referenced_id == search_id) {
              user.fragment = std::move(stmt.fragment);  // Take it back.
              co_yield user;
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

Stmt StmtReference::statement(void) && noexcept {
  auto reader = fragment->NthStmt(offset);
  return Stmt(std::move(*reader), std::move(fragment), offset);
}

Stmt StmtReference::statement(void) const & noexcept {
  auto reader = fragment->NthStmt(offset);
  return Stmt(std::move(*reader), fragment, offset);
}

StmtReference::operator Stmt(void) && noexcept {
  auto reader = fragment->NthStmt(offset);
  return Stmt(std::move(*reader), std::move(fragment), offset);
}

StmtReference::operator Stmt(void) const & noexcept {
  auto reader = fragment->NthStmt(offset);
  return Stmt(std::move(*reader), fragment, offset);
}

Macro MacroReference::macro(void) && noexcept {
  auto reader = fragment->NthMacro(offset);
  return Macro(std::move(*reader), std::move(fragment), offset);
}

Macro MacroReference::macro(void) const & noexcept {
  auto reader = fragment->NthMacro(offset);
  return Macro(std::move(*reader), fragment, offset);
}

MacroReference::operator Macro(void) && noexcept {
  auto reader = fragment->NthMacro(offset);
  return Macro(std::move(*reader), std::move(fragment), offset);
}

MacroReference::operator Macro(void) const & noexcept {
  auto reader = fragment->NthMacro(offset);
  return Macro(std::move(*reader), fragment, offset);
}

}  // namespace mx
