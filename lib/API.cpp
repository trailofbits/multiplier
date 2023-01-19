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
#include "Re2Impl.h"
#include "Token.h"
#include "Use.h"
#include "WeggliImpl.h"

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
  for (auto use : impl.Enumerate<DeclUseSelector>()) {
    co_yield use;
  }
}

gap::generator<StmtReference> Decl::references(void) const {
  ReferenceIteratorImpl it(fragment->ep, *this);
  for (auto ref : it.EnumerateStatements()) {
    co_yield ref;
  }
}

gap::generator<Decl> Decl::in_internal(const Fragment &fragment) {
  unsigned i = 0;
  for (auto reader : fragment.impl->Decls()) {
    co_yield Decl(std::move(reader), fragment.impl, i++);
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
  unsigned i = 0;
  for (auto reader : fragment.impl->Stmts()) {
    co_yield Stmt(std::move(reader), fragment.impl, i++);
  }
}

gap::generator<Use<StmtUseSelector>> Stmt::uses(void) const {
  UseIteratorImpl impl(fragment->ep, *this);
  for (auto use : impl.Enumerate<StmtUseSelector>()) {
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
  unsigned i = 0;
  for (auto reader : fragment.impl->Types()) {
    co_yield Type(std::move(reader), fragment.impl, i++);
  }
}

gap::generator<Use<TypeUseSelector>> Type::uses(void) const {
  UseIteratorImpl impl(fragment->ep, *this);
  for (auto use : impl.Enumerate<TypeUseSelector>()) {
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
  unsigned i = 0;
  for (auto reader : fragment.impl->Attrs()) {
    co_yield Attr(std::move(reader), fragment.impl, i++);
  }
}

gap::generator<Use<AttrUseSelector>> Attr::uses(void) const {
  UseIteratorImpl impl(fragment->ep, *this);
  for (auto use : impl.Enumerate<AttrUseSelector>()) {
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
  unsigned i = 0;
  for (auto reader : fragment.impl->Macros()) {
    co_yield Macro(std::move(reader), fragment.impl, i++);
  }
}

gap::generator<Macro> Macro::containing_internal(const Token &token) {
  std::optional<Macro> macro;
  if (auto frag = token.impl->OwningFragment()) {
    auto vid = token.impl->NthContainingMacroId(token.offset).Unpack();
    if (std::holds_alternative<MacroId>(vid)) {
      MacroId mid = std::get<MacroId>(vid);
      auto reader = frag->NthMacro(mid.offset);
      if (mid.fragment_id == frag->fragment_id && reader.has_value()) {
        macro.emplace(std::move(*reader), FragmentImpl::Ptr(token.impl, frag), mid.offset);
      }
    }
  }

  for (; macro; macro = macro->parent()) {
    co_yield *macro;
  }
}

gap::generator<Use<MacroUseSelector>> Macro::uses(void) const {
  UseIteratorImpl impl(fragment->ep, *this);
  for (auto use : impl.Enumerate<MacroUseSelector>()) {
    co_yield use;
  }
}


gap::generator<MacroReference> DefineMacroDirective::references(void) const {
  ReferenceIteratorImpl it(fragment->ep, *this);
  for (auto ref : it.EnumerateMacros()) {
    co_yield ref;
  }
}

}  // namespace mx
