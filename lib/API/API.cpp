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
#include <multiplier/AST.h>
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

EntityProvider::~EntityProvider(void) noexcept {}

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

gap::generator<Use<DeclUseSelector>> Decl::uses(void) const {
  UseIteratorImpl impl(fragment->ep, *this);
  for(auto use : impl.enumerate<DeclUseSelector>()) {
    co_yield use;
  }
}

gap::generator<StmtReference> Decl::references(void) const {
  ReferenceIteratorImpl it(fragment->ep, *this);
  for(auto ref : it.enumerate_stmts()) {
    co_yield ref;
  }
}

gap::generator<Decl> Decl::in_internal(const Fragment &fragment) {
  for(size_t i = 0; i < fragment.impl->num_decls; ++i) {
    co_yield Decl(fragment.impl, i);
  }
}

SpecificEntityId<StatementId> Stmt::id(void) const {
  StatementId eid;
  eid.fragment_id = fragment->fragment_id;
  eid.kind = kind();
  eid.offset = offset_;
  return eid;
}

gap::generator<Stmt> Stmt::in_internal(const Fragment &fragment) {
  for(size_t i = 0; i < fragment.impl->num_stmts; ++i) {
    co_yield Stmt(fragment.impl, i);
  }
}

gap::generator<Use<StmtUseSelector>> Stmt::uses(void) const {
  UseIteratorImpl impl(fragment->ep, *this);
  for(auto use : impl.enumerate<StmtUseSelector>()) {
    co_yield use;
  }
}

SpecificEntityId<TypeId> Type::id(void) const {
  TypeId eid;
  eid.fragment_id = fragment->fragment_id;
  eid.kind = kind();
  eid.offset = offset_;
  return eid;
}

gap::generator<Type> Type::in_internal(const Fragment &fragment) {
  for(size_t i = 0; i < fragment.impl->num_types; ++i) {
    co_yield Type(fragment.impl, i);
  }
}

gap::generator<Use<TypeUseSelector>> Type::uses(void) const {
  UseIteratorImpl impl(fragment->ep, *this);
  for(auto use : impl.enumerate<TypeUseSelector>()) {
    co_yield use;
  }
}

SpecificEntityId<AttributeId> Attr::id(void) const {
  AttributeId eid;
  eid.fragment_id = fragment->fragment_id;
  eid.kind = kind();
  eid.offset = offset_;
  return eid;
}

gap::generator<Attr> Attr::in_internal(const Fragment &fragment) {
  for(size_t i = 0; i < fragment.impl->num_attrs; ++i) {
    co_yield Attr(fragment.impl, i);
  }
}

gap::generator<Use<AttrUseSelector>> Attr::uses(void) const {
  UseIteratorImpl impl(fragment->ep, *this);
  for(auto use : impl.enumerate<AttrUseSelector>()) {
    co_yield use;
  }
}

SpecificEntityId<MacroId> Macro::id(void) const {
  MacroId eid;
  eid.fragment_id = fragment->fragment_id;
  eid.kind = kind();
  eid.offset = offset_;
  return eid;
}

gap::generator<Macro> Macro::in_internal(const Fragment &fragment) {
  for(size_t i = 0; i < fragment.impl->num_macros; ++i) {
    co_yield Macro(fragment.impl, i);
  }
}

gap::generator<Macro> Macro::containing_internal(const Token &token) {
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

  for(; macro; macro = macro->parent()) {
    co_yield *macro;
  }
}

gap::generator<Use<MacroUseSelector>> Macro::uses(void) const {
  UseIteratorImpl impl(fragment->ep, *this);
  for(auto use : impl.enumerate<MacroUseSelector>()) {
    co_yield use;
  }
}


gap::generator<MacroReference> DefineMacroDirective::references(void) const {
  ReferenceIteratorImpl it(fragment->ep, *this);
  for(auto ref : it.enumerate_macros()) {
    co_yield ref;
  }
}


}  // namespace mx
