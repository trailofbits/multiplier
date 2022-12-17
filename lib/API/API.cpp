// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "API.h"

#include <atomic>
#include <cassert>
#include <iostream>
#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/Macro.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/VarDecl.h>
#include <multiplier/Entities/TokenKind.h>
#include <multiplier/Compress.h>
#include <sstream>
#include <stdexcept>
#include <thread>
#include <set>

#include "File.h"
#include "Fragment.h"
#include "InvalidEntityProvider.h"
#include "Re2.h"
#include "Token.h"
#include "Use.h"
#include "Weggli.h"
#include "../Common/Re2.h"

namespace mx {

// NOTE(pag): Keep in sync with `../bin/Index/LinkRerencesInFragment.cpp`
//            version of the same function.
bool MayHaveRemoteRedeclarations(const mx::Decl &decl) {
  switch (decl.kind()) {
    // Functions.
    case mx::DeclKind::FUNCTION:
    case mx::DeclKind::CXX_METHOD:
    case mx::DeclKind::CXX_DESTRUCTOR:
    case mx::DeclKind::CXX_CONVERSION:
    case mx::DeclKind::CXX_CONSTRUCTOR:
    case mx::DeclKind::CXX_DEDUCTION_GUIDE:
      return true;

    // Variables.
    case mx::DeclKind::VAR:
    case mx::DeclKind::PARM_VAR:
    case mx::DeclKind::OMP_CAPTURED_EXPR:
    case mx::DeclKind::IMPLICIT_PARAM:
    case mx::DeclKind::DECOMPOSITION:
    case mx::DeclKind::VAR_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION:
      if (reinterpret_cast<const VarDecl &>(decl).is_local_variable_declaration()) {
        return false;
      } else {
        return true;
      }

    // Tags.
    case mx::DeclKind::TAG:
    case mx::DeclKind::RECORD:
    case mx::DeclKind::CXX_RECORD:
    case mx::DeclKind::CLASS_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION:
    case mx::DeclKind::ENUM:
      return true;

    // Redeclarable templates.
    case mx::DeclKind::REDECLARABLE_TEMPLATE:
    case mx::DeclKind::FUNCTION_TEMPLATE:
    case mx::DeclKind::CLASS_TEMPLATE:
    case mx::DeclKind::VAR_TEMPLATE:
    case mx::DeclKind::TYPE_ALIAS_TEMPLATE:
      return true;

    default:
      return false;
  }
}

// NOTE(pag): Keep in sync with `../bin/Index/LinkRerencesInFragment.cpp`
//            version of the same function.
bool MayHaveRemoteUses(const mx::Decl &decl) {
  switch (decl.kind()) {
    // Functions.
    case mx::DeclKind::FUNCTION:
    case mx::DeclKind::CXX_METHOD:
    case mx::DeclKind::CXX_DESTRUCTOR:
    case mx::DeclKind::CXX_CONVERSION:
    case mx::DeclKind::CXX_CONSTRUCTOR:
    case mx::DeclKind::CXX_DEDUCTION_GUIDE:
      return true;

    // Variables.
    case mx::DeclKind::VAR:
    case mx::DeclKind::PARM_VAR:
    case mx::DeclKind::OMP_CAPTURED_EXPR:
    case mx::DeclKind::IMPLICIT_PARAM:
    case mx::DeclKind::DECOMPOSITION:
    case mx::DeclKind::VAR_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION:
      if (reinterpret_cast<const VarDecl &>(decl).is_local_variable_declaration()) {
        return false;
      } else {
        return true;
      }

    // Tags.
    case mx::DeclKind::TAG:
    case mx::DeclKind::RECORD:
    case mx::DeclKind::CXX_RECORD:
    case mx::DeclKind::CLASS_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION:
    case mx::DeclKind::ENUM:
      return true;

    // Enumerators.
    case mx::DeclKind::ENUM_CONSTANT:

    // Redeclarable templates.
    case mx::DeclKind::REDECLARABLE_TEMPLATE:
    case mx::DeclKind::FUNCTION_TEMPLATE:
    case mx::DeclKind::CLASS_TEMPLATE:
    case mx::DeclKind::VAR_TEMPLATE:
    case mx::DeclKind::TYPE_ALIAS_TEMPLATE:
      return true;

    // Fields.
    case mx::DeclKind::FIELD:
    case mx::DeclKind::INDIRECT_FIELD:
      return true;

    // Types.
    case mx::DeclKind::TYPE_ALIAS:
    // case mx::DeclKind::TYPE_ALIAS_TEMPLATE:
    case mx::DeclKind::TYPE:
    case mx::DeclKind::TYPEDEF:
    case mx::DeclKind::TYPEDEF_NAME:
      return true;

    default:
      return false;
  }
}

EntityProvider::~EntityProvider(void) noexcept {}

Decl DeclIterator::operator*(void) && noexcept {
  return Decl(std::move(impl), index);
}

Decl DeclIterator::operator*(void) const & noexcept {
  return Decl(impl, index);
}

Stmt StmtIterator::operator*(void) && noexcept {
  return Stmt(std::move(impl), index);
}

Stmt StmtIterator::operator*(void) const & noexcept {
  return Stmt(impl, index);
}

Type TypeIterator::operator*(void) && noexcept {
  return Type(std::move(impl), index);
}

Type TypeIterator::operator*(void) const & noexcept {
  return Type(impl, index);
}

Attr AttrIterator::operator*(void) && noexcept {
  return Attr(std::move(impl), index);
}

Attr AttrIterator::operator*(void) const & noexcept {
  return Attr(impl, index);
}

Macro MacroIterator::operator*(void) && noexcept {
  return Macro(std::move(impl), index);
}

Macro MacroIterator::operator*(void) const & noexcept {
  return Macro(impl, index);
}

EntityId Decl::id(void) const {
  DeclarationId eid;
  eid.fragment_id = fragment->fragment_id;
  eid.is_definition = is_definition();
  eid.kind = kind();
  eid.offset = offset_;
  return eid;
}

std::optional<Decl> Decl::definition(void) const {
  for (const Decl &decl : redeclarations()) {
    if (decl.is_definition()) {
      return decl;
    }
  }
  return std::nullopt;
}

std::vector<Decl> Decl::redeclarations(void) const {
  if (!MayHaveRemoteRedeclarations(*this)) {
    return redeclarations_visible_in_translation_unit();
  }

  auto redecl_ids = fragment->ep->Redeclarations(fragment->ep, id());
  if (redecl_ids.empty()) {
    return redeclarations_visible_in_translation_unit();
  }

  std::vector<Decl> redecls;
  redecls.reserve(redecl_ids.size());

  for (mx::RawEntityId eid : redecl_ids) {
    if (auto redecl = fragment->DeclFor(fragment, eid)) {
      redecls.emplace_back(std::move(redecl.value()));
    }
  }

  return redecls;
}

UseRange<DeclUseSelector> Decl::uses(void) const {
  return std::make_shared<UseIteratorImpl>(fragment->ep, *this);
}

ReferenceRange Decl::references(void) const {
  return std::make_shared<ReferenceIteratorImpl>(fragment->ep, *this);
}

DeclIterator Decl::in_internal(const Fragment &fragment) {
  return DeclIterator(fragment.impl, 0u, fragment.impl->num_decls);
}

EntityId Stmt::id(void) const {
  StatementId eid;
  eid.fragment_id = fragment->fragment_id;
  eid.kind = kind();
  eid.offset = offset_;
  return eid;
}

StmtIterator Stmt::in_internal(const Fragment &fragment) {
  return StmtIterator(fragment.impl, 0u, fragment.impl->num_stmts);
}

UseRange<StmtUseSelector> Stmt::uses(void) const {
  return std::make_shared<UseIteratorImpl>(fragment->ep, *this);
}

EntityId Type::id(void) const {
  TypeId eid;
  eid.fragment_id = fragment->fragment_id;
  eid.kind = kind();
  eid.offset = offset_;
  return eid;
}

TypeIterator Type::in_internal(const Fragment &fragment) {
  return TypeIterator(fragment.impl, 0u, fragment.impl->num_types);
}

UseRange<TypeUseSelector> Type::uses(void) const {
  return std::make_shared<UseIteratorImpl>(fragment->ep, *this);
}

EntityId Attr::id(void) const {
  AttributeId eid;
  eid.fragment_id = fragment->fragment_id;
  eid.kind = kind();
  eid.offset = offset_;
  return eid;
}

AttrIterator Attr::in_internal(const Fragment &fragment) {
  return AttrIterator(fragment.impl, 0u, fragment.impl->num_attrs);
}

UseRange<AttrUseSelector> Attr::uses(void) const {
  return std::make_shared<UseIteratorImpl>(fragment->ep, *this);
}

EntityId Macro::id(void) const {
  MacroId eid;
  eid.fragment_id = fragment->fragment_id;
  eid.kind = kind();
  eid.offset = offset_;
  return eid;
}

}  // namespace mx
