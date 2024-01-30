// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/FunctionProtoType.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/FunctionDecl.h>
#include <multiplier/AST/FunctionType.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kFunctionProtoTypeDerivedKinds[] = {
    FunctionProtoType::static_kind(),
};
}  // namespace

gap::generator<FunctionProtoType> FunctionProtoType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = FunctionProtoType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool FunctionProtoType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : FunctionProtoType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<FunctionProtoType> FunctionProtoType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    if (auto base = index.type(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<FunctionProtoType> FunctionProtoType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<FunctionProtoType> FunctionProtoType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case FunctionProtoType::static_kind():
      return reinterpret_cast<const FunctionProtoType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<FunctionProtoType> FunctionProtoType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kFunctionProtoTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<FunctionProtoType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<FunctionProtoType> FunctionProtoType::from(const Reference &r) {
  return FunctionProtoType::from(r.as_type());
}

std::optional<FunctionProtoType> FunctionProtoType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<FunctionProtoType> FunctionProtoType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<CanThrowResult> FunctionProtoType::can_throw(void) const {
  if (!impl->reader.getVal32()) {
    return std::nullopt;
  } else {
    return static_cast<CanThrowResult>(impl->reader.getVal65());
  }
  return std::nullopt;
}

Type FunctionProtoType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal26();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Token FunctionProtoType::ellipsis_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal27());
}

std::optional<FunctionDecl> FunctionProtoType::exception_spec_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal60();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FunctionDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<FunctionDecl> FunctionProtoType::exception_spec_template(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal61();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FunctionDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

ExceptionSpecificationType FunctionProtoType::exception_spec_type(void) const {
  return static_cast<ExceptionSpecificationType>(impl->reader.getVal66());
}

std::optional<Expr> FunctionProtoType::noexcept_expression(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal63();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

unsigned FunctionProtoType::num_parameter_types(void) const {
  return impl->reader.getVal24().size();
}

std::optional<Type> FunctionProtoType::nth_parameter_type(unsigned n) const {
  auto list = impl->reader.getVal24();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TypeFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Type(std::move(e));
}

gap::generator<Type> FunctionProtoType::parameter_types(void) const & {
  auto list = impl->reader.getVal24();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d24 = ep->TypeFor(ep, v)) {
      co_yield Type(std::move(d24));
    }
  }
  co_return;
}

RefQualifierKind FunctionProtoType::reference_qualifier(void) const {
  return static_cast<RefQualifierKind>(impl->reader.getVal67());
}

bool FunctionProtoType::has_dependent_exception_spec(void) const {
  return impl->reader.getVal33();
}

bool FunctionProtoType::has_dynamic_exception_spec(void) const {
  return impl->reader.getVal34();
}

bool FunctionProtoType::has_exception_spec(void) const {
  return impl->reader.getVal35();
}

bool FunctionProtoType::has_ext_parameter_infos(void) const {
  return impl->reader.getVal36();
}

bool FunctionProtoType::has_instantiation_dependent_exception_spec(void) const {
  return impl->reader.getVal37();
}

bool FunctionProtoType::has_noexcept_exception_spec(void) const {
  return impl->reader.getVal38();
}

bool FunctionProtoType::has_trailing_return(void) const {
  return impl->reader.getVal39();
}

std::optional<bool> FunctionProtoType::is_nothrow(void) const {
  if (!impl->reader.getVal41()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal40());
  }
  return std::nullopt;
}

bool FunctionProtoType::is_sugared(void) const {
  return impl->reader.getVal42();
}

bool FunctionProtoType::is_template_variadic(void) const {
  return impl->reader.getVal43();
}

bool FunctionProtoType::is_variadic(void) const {
  return impl->reader.getVal44();
}

unsigned FunctionProtoType::num_exception_types(void) const {
  return impl->reader.getVal59().size();
}

std::optional<Type> FunctionProtoType::nth_exception_type(unsigned n) const {
  auto list = impl->reader.getVal59();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TypeFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Type(std::move(e));
}

gap::generator<Type> FunctionProtoType::exception_types(void) const & {
  auto list = impl->reader.getVal59();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d59 = ep->TypeFor(ep, v)) {
      co_yield Type(std::move(d59));
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
