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
#include <multiplier/Entities/DefineMacroDirective.h>
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
#include "Re2Impl.h"
#include "Token.h"
#include "Use.h"
#include "WeggliImpl.h"

namespace mx {

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

SpecificEntityId<DeclarationId> Decl::id(void) const {
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
  std::vector<Decl> redecls;
  for (RawEntityId raw_id : fragment->ep->Redeclarations(fragment->ep, id())) {
    if (std::optional<Decl> redecl = fragment->DeclFor(fragment, raw_id)) {
      redecls.emplace_back(std::move(redecl.value()));
    }
  }

  return redecls;
}

UseRange<DeclUseSelector> Decl::uses(void) const {
  return std::make_shared<UseIteratorImpl>(fragment->ep, *this);
}

StmtReferenceRange Decl::references(void) const {
  return std::make_shared<ReferenceIteratorImpl>(fragment->ep, *this);
}

DeclIterator Decl::in_internal(const Fragment &fragment) {
  return DeclIterator(fragment.impl, 0u, fragment.impl->num_decls);
}

SpecificEntityId<StatementId> Stmt::id(void) const {
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

SpecificEntityId<TypeId> Type::id(void) const {
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

SpecificEntityId<AttributeId> Attr::id(void) const {
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

SpecificEntityId<MacroId> Macro::id(void) const {
  MacroId eid;
  eid.fragment_id = fragment->fragment_id;
  eid.kind = kind();
  eid.offset = offset_;
  return eid;
}

MacroIterator Macro::in_internal(const Fragment &fragment) {
  return MacroIterator(fragment.impl, 0u, fragment.impl->num_macros);
}

ParentMacroIteratorImpl<Macro> Macro::containing_internal(const Token &token) {
  std::optional<Macro> macro;
  if (auto frag = token.impl->OwningFragment()) {
    auto vid = EntityId(token.impl->NthContainingMacroId(token.offset)).Unpack();
    if (std::holds_alternative<MacroId>(vid)) {
      MacroId mid = std::get<MacroId>(vid);
      if (mid.fragment_id == frag->fragment_id) {
        macro.emplace(FragmentImpl::Ptr(token.impl, frag), mid.offset);
      }
    }
  }
  return ParentMacroIteratorImpl<Macro>(std::move(macro));
}

UseRange<MacroUseSelector> Macro::uses(void) const {
  return std::make_shared<UseIteratorImpl>(fragment->ep, *this);
}


MacroReferenceRange DefineMacroDirective::references(void) const {
  return std::make_shared<ReferenceIteratorImpl>(fragment->ep, *this);
}


}  // namespace mx
