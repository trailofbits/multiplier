// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "API.h"

#include <atomic>
#include <cassert>
#include <iostream>
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
#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/VarDecl.h>
#include <multiplier/Entities/TokenKind.h>

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

gap::generator<Use<DeclUseSelector>> Decl::uses(void) const {
  UseIteratorImpl impl(fragment->ep, *this);
  for(auto use : impl.enumerate<DeclUseSelector>()) {
    co_yield use;
  }
}

gap::generator<Reference> Decl::references(void) const {
  std::vector<RawEntityId> search_ids;
  std::vector<RawEntityId> fragment_ids;
  auto &ep = fragment->ep;

  if (MayHaveRemoteUses(*this)) {
    ep->FillReferences(ep, id(), search_ids, fragment_ids);
  }

  if (search_ids.empty()) {
    for (const mx::Decl &redecl :
             redeclarations_visible_in_translation_unit()) {
      search_ids.push_back(redecl.id());
      fragment_ids.push_back(redecl.fragment->fragment_id);
    }
  }

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

  Reference user;
  unsigned fragment_offset = 0;

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
          for (auto search_id : search_ids) {
            if (referenced_id == search_id) {
              user.fragment = std::move(stmt.fragment);  // Take it back.
              co_yield user;  // Hit!
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

gap::generator<Decl> Decl::in_internal(const Fragment &fragment) {
  for(size_t i = 0; i < fragment.impl->num_decls; ++i) {
    co_yield Decl(fragment.impl, i);
  }
}

EntityId Stmt::id(void) const {
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

EntityId Type::id(void) const {
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

EntityId Attr::id(void) const {
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


}  // namespace mx
