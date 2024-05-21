// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXCtorInitializer.h>
#include "../Reference.h"
#include <multiplier/AST/FieldDecl.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/IndirectFieldDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>

#include "../EntityProvider.h"
#include "../File.h"
#include "../Fragment.h"
#include "../CXXCtorInitializer.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

std::shared_ptr<EntityProvider> CXXCtorInitializer::entity_provider_of(const Index &index_) {
  return index_.impl;
}

std::shared_ptr<EntityProvider> CXXCtorInitializer::entity_provider_of(const Fragment &frag_) {
  return frag_.impl->ep;
}

std::shared_ptr<EntityProvider> CXXCtorInitializer::entity_provider_of(const File &file_) {
  return file_.impl->ep;
}

std::optional<CXXCtorInitializer> CXXCtorInitializer::from(const Reference &r) {
  return r.as_cxx_ctor_initializer();
}

std::optional<CXXCtorInitializer> CXXCtorInitializer::from(const VariantEntity &e) {
  if (!std::holds_alternative<CXXCtorInitializer>(e)) {
    return std::nullopt;
  }
  return std::get<CXXCtorInitializer>(e);
}

std::optional<CXXCtorInitializer> CXXCtorInitializer::from(const TokenContext &t) {
  return t.as_cxx_ctor_initializer();
}

bool CXXCtorInitializer::is_base_initializer(void) const {
  return impl->reader.getVal0();
}

bool CXXCtorInitializer::is_member_initializer(void) const {
  return impl->reader.getVal1();
}

bool CXXCtorInitializer::is_any_member_initializer(void) const {
  return impl->reader.getVal2();
}

bool CXXCtorInitializer::is_indirect_member_initializer(void) const {
  return impl->reader.getVal3();
}

bool CXXCtorInitializer::is_in_class_member_initializer(void) const {
  return impl->reader.getVal4();
}

bool CXXCtorInitializer::is_delegating_initializer(void) const {
  return impl->reader.getVal5();
}

bool CXXCtorInitializer::is_pack_expansion(void) const {
  return impl->reader.getVal6();
}

std::optional<bool> CXXCtorInitializer::is_base_virtual(void) const {
  if (!impl->reader.getVal8()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal7());
  }
  return std::nullopt;
}

std::optional<FieldDecl> CXXCtorInitializer::member(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal9();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FieldDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<FieldDecl> CXXCtorInitializer::any_member(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal10();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FieldDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<IndirectFieldDecl> CXXCtorInitializer::indirect_member(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal11();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return IndirectFieldDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<Stmt> CXXCtorInitializer::initializer(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal12();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Stmt(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token CXXCtorInitializer::ellipsis_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal13());
}

Token CXXCtorInitializer::member_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal14());
}

Token CXXCtorInitializer::left_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal15());
}

Token CXXCtorInitializer::right_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal16());
}

TokenRange CXXCtorInitializer::tokens(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal17(), impl->reader.getVal18());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
