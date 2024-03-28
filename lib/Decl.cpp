// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Decl.h"

#include <multiplier/AST/CXXMethodDecl.h>
#include <multiplier/AST/CXXRecordDecl.h>
#include <multiplier/Index.h>

#include "Fragment.h"
#include "Reference.h"
#include "Types.h"
#include "Util.h"

namespace mx {
namespace {

static thread_local RawEntityIdList tIgnoredRedecls;

}  // namespace

DeclImpl::DeclImpl(FragmentImplPtr frag_,
                   ast::Decl::Reader reader_,
                   RawEntityId id_)
    : FragmentEntityImpl<ast::Decl>(std::move(frag_), kj::mv(reader_)),
      fragment_id(FragmentIdFromEntityId(id_).value()),
      offset(FragmentOffsetFromEntityId(id_).value()),
      definition_id(kInvalidEntityId),
      canonical_id(kInvalidEntityId) {}

SpecificEntityId<DeclId> Decl::id(void) const {
  DeclId eid;
  eid.fragment_id = impl->fragment_id.Unpack().fragment_id;
  eid.is_definition = is_definition();
  eid.kind = kind();
  eid.offset = impl->offset;
  return eid;
}

std::optional<Decl> Decl::definition(void) const {
  const EntityProviderPtr &ep = impl->ep;

  // If we've stored the canonical ID already, then we've also computed the
  // definition ID, if any.
  RawEntityId min_id = impl->canonical_id.load(std::memory_order_acquire);
  if (min_id != kInvalidEntityId) {
    RawEntityId definition_id =
        impl->definition_id.load(std::memory_order_acquire);
    if (DeclImplPtr def = ep->DeclFor(ep, definition_id)) {
      return Decl(std::move(def));
    } else {
      return std::nullopt;
    }
  }

  min_id = std::numeric_limits<RawEntityId>::max();
  RawEntityId definition_id = min_id;
  RawEntityId this_id = id().Pack();
  bool found_def = false;

#ifndef NDEBUG
  bool seen_this_id = false;
#endif

  for (RawEntityId raw_id : ep->Redeclarations(ep, this_id)) {
    VariantId vid = EntityId(raw_id).Unpack();
    if (!std::holds_alternative<DeclId>(vid)) {
      assert(false);
      continue;
    }

    DeclId did = std::get<DeclId>(vid);
    if (did.is_definition) {
      definition_id = std::min(definition_id, raw_id);
      found_def = true;
    }
    min_id = std::min(min_id, raw_id);

#ifndef NDEBUG
    if (raw_id == this_id) {
      seen_this_id = true;
    }
#endif
  }

  assert(seen_this_id);

  if (found_def) {
    if (DeclImplPtr def = ep->DeclFor(ep, definition_id)) {
      impl->canonical_id.store(definition_id, std::memory_order_release);
      impl->definition_id.store(definition_id, std::memory_order_release);
      return Decl(std::move(def));
    }
  }

  min_id = std::min(min_id, this_id);
  impl->canonical_id.store(min_id, std::memory_order_release);
  return std::nullopt;
}

Decl Decl::canonical_declaration(void) const {
  const EntityProviderPtr &ep = impl->ep;

  RawEntityId min_id = impl->canonical_id.load(std::memory_order_acquire);
  if (min_id != kInvalidEntityId) {
    if (DeclImplPtr redecl = ep->DeclFor(ep, min_id)) {
      return Decl(std::move(redecl));
    }
  }

  min_id = std::numeric_limits<RawEntityId>::max();
  RawEntityId definition_id = min_id;
  RawEntityId this_id = id().Pack();
  bool found_def = false;

#ifndef NDEBUG
  bool seen_this_id = false;
#endif

  for (RawEntityId raw_id : ep->Redeclarations(ep, this_id)) {
    VariantId vid = EntityId(raw_id).Unpack();
    if (!std::holds_alternative<DeclId>(vid)) {
      assert(false);
      continue;
    }

    DeclId did = std::get<DeclId>(vid);
    if (did.is_definition) {
      definition_id = std::min(definition_id, raw_id);
      found_def = true;
    }
    min_id = std::min(min_id, raw_id);

#ifndef NDEBUG
    if (raw_id == this_id) {
      seen_this_id = true;
    }
#endif
  }

  assert(seen_this_id);

  if (found_def) {
    if (DeclImplPtr def = ep->DeclFor(ep, definition_id)) {
      impl->canonical_id.store(definition_id, std::memory_order_release);
      impl->definition_id.store(definition_id, std::memory_order_release);
      return Decl(std::move(def));
    }
  }

  min_id = std::min(min_id, this_id);
  if (DeclImplPtr decl = ep->DeclFor(ep, min_id)) {
    impl->canonical_id.store(min_id, std::memory_order_release);
    return Decl(std::move(decl));

  } else {
    assert(false);
    impl->canonical_id.store(this_id, std::memory_order_release);
    return *this;
  }
}

gap::generator<Decl> Decl::redeclarations(void) const & {
  auto any = false;
  EntityProviderPtr ep = impl->ep;
  for (RawEntityId raw_id : ep->Redeclarations(ep, id().Pack())) {
    if (DeclImplPtr redecl = ep->DeclFor(ep, raw_id)) {
      any = true;
      co_yield Decl(std::move(redecl));
    }
  }
  if (!any) {
    assert(false);
    co_yield Decl(impl);
  }
}

// Grab all callers of this function. These are `CallExpr` or
// `CxxConstructExpr`s.
//
// TODO(pag): Handle `CXXNewExpr` that doesn't contain a `CxxConstructExpr`.
gap::generator<Stmt> FunctionDecl::callers() const & {
  static constexpr auto kCallerKindId =
      static_cast<RawEntityId>(BuiltinReferenceKind::CALLS);

  auto ep = impl->ep;
  auto is_constructor = kind() == DeclKind::CXX_CONSTRUCTOR;

  for (auto [from_id, context_id, kind_id] :
        ep->References(ep, id().Pack(), EntityProvider::kReferenceTo)) {

    if (kCallerKindId != kind_id) {
      continue;
    }

    // The `context_id` should point to a `CallExpr`.
    if (auto context_stmt_id = EntityId(context_id).Extract<StmtId>()) {
      if (context_stmt_id->kind == StmtKind::CALL_EXPR ||
          context_stmt_id->kind == StmtKind::CXX_NEW_EXPR ||
          context_stmt_id->kind == StmtKind::CXX_DELETE_EXPR) {
        if (auto eptr = ep->StmtFor(ep, context_id)) {
          co_yield Stmt(std::move(eptr));
          continue;
        }
      }

      if (context_stmt_id->kind == StmtKind::CXX_CONSTRUCT_EXPR &&
          is_constructor) {
        if (auto eptr = ep->StmtFor(ep, context_id)) {
          co_yield Stmt(std::move(eptr));
          continue;
        } 
      }
    }

    // If it doesn't, then `from_id` is probably pointing to a `DeclRefExpr`,
    // so go and search for a `CallExpr` containing the `DeclRefExpr`.
    auto stmt_id = EntityId(from_id).Extract<StmtId>();
    if (!stmt_id) {
      continue;
    }

    auto eptr = ep->StmtFor(ep, from_id);
    if (!eptr) {
      assert(false);
      continue;
    }

    Stmt func_ref(std::move(eptr));
    for (auto call : Stmt::containing(func_ref)) {
      auto ck = call.kind();

      if (ck == StmtKind::CXX_CONSTRUCT_EXPR) {
        if (is_constructor) {
          co_yield std::move(call);
        }
        break;
      }

      if (ck == StmtKind::CALL_EXPR) {
        co_yield std::move(call);
        break;
      }

      if (IsNonValueStatement(ck)) {
        break;
      }
    }
  }
}

gap::generator<CXXRecordDecl> CXXRecordDecl::base_classes(void) const & {
  static constexpr auto kExtendsKindId =
      static_cast<RawEntityId>(BuiltinReferenceKind::EXTENDS);

  auto ep = impl->ep;
  for (auto [to_id, context_id, kind_id] :
        ep->References(ep, id().Pack(), EntityProvider::kReferenceFrom)) {

    if (kExtendsKindId != kind_id) {
      continue;
    }

    auto decl_id = EntityId(to_id).Extract<DeclId>();
    if (!decl_id) {
      continue;
    }

    auto eptr = ep->DeclFor(ep, to_id);
    if (!eptr) {
      assert(false);
      continue;
    }

    Decl cls_ref(std::move(eptr));
    if (auto record = CXXRecordDecl::from(cls_ref)) {
      co_yield std::move(record.value());
    }
  }
}

gap::generator<CXXRecordDecl> CXXRecordDecl::derived_classes(void) const & {
  static constexpr auto kExtendsKindId =
      static_cast<RawEntityId>(BuiltinReferenceKind::EXTENDS);

  auto ep = impl->ep;
  for (auto [from_id, context_id, kind_id] :
        ep->References(ep, id().Pack(), EntityProvider::kReferenceTo)) {

    if (kExtendsKindId != kind_id) {
      continue;
    }

    auto decl_id = EntityId(from_id).Extract<DeclId>();
    if (!decl_id) {
      continue;
    }

    auto eptr = ep->DeclFor(ep, from_id);
    if (!eptr) {
      assert(false);
      continue;
    }

    Decl cls_ref(std::move(eptr));
    if (auto record = CXXRecordDecl::from(cls_ref)) {
      co_yield std::move(record.value());
    }
  }
}

gap::generator<CXXMethodDecl>
CXXMethodDecl::overridden_by_methods(void) const & {
  static constexpr auto kOverridesKindId =
      static_cast<RawEntityId>(BuiltinReferenceKind::OVERRIDES);

  auto ep = impl->ep;
  for (auto [from_id, context_id, kind_id] :
        ep->References(ep, id().Pack(), EntityProvider::kReferenceTo)) {

    if (kOverridesKindId != kind_id) {
      continue;
    }

    auto decl_id = EntityId(from_id).Extract<DeclId>();
    if (!decl_id) {
      continue;
    }

    auto eptr = ep->DeclFor(ep, from_id);
    if (!eptr) {
      assert(false);
      continue;
    }

    Decl method_ref(std::move(eptr));
    switch (method_ref.kind()) {
      case mx::DeclKind::CXX_CONVERSION:
      case mx::DeclKind::CXX_CONSTRUCTOR:
      case mx::DeclKind::CXX_DEDUCTION_GUIDE:
      case mx::DeclKind::CXX_DESTRUCTOR:
      case mx::DeclKind::CXX_METHOD:
        co_yield std::move(reinterpret_cast<CXXMethodDecl &>(method_ref));
        break;
      default:
        continue;
    }
  }
}

}  // namespace mx
