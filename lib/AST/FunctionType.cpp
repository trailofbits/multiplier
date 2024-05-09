// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/FunctionType.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/FunctionNoProtoType.h>
#include <multiplier/AST/FunctionProtoType.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kFunctionTypeDerivedKinds[] = {
    FunctionNoProtoType::static_kind(),
    FunctionProtoType::static_kind(),
};
}  // namespace

gap::generator<FunctionType> FunctionType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = FunctionType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool FunctionType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : FunctionType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<FunctionType> FunctionType::by_id(const Index &index, EntityId eid) {
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

std::optional<FunctionType> FunctionType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<FunctionType> FunctionType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case FunctionNoProtoType::static_kind():
    case FunctionProtoType::static_kind():
      return reinterpret_cast<const FunctionType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<FunctionType> FunctionType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kFunctionTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<FunctionType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<FunctionType> FunctionType::from(const Reference &r) {
  return FunctionType::from(r.as_type());
}

std::optional<FunctionType> FunctionType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<FunctionType> FunctionType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

CallingConv FunctionType::call_conv(void) const {
  return static_cast<CallingConv>(impl->reader.getVal27());
}

Type FunctionType::call_result_type(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool FunctionType::cmse_ns_call_attribute(void) const {
  return impl->reader.getVal20();
}

bool FunctionType::has_reg_parm(void) const {
  return impl->reader.getVal21();
}

bool FunctionType::no_return_attribute(void) const {
  return impl->reader.getVal22();
}

Type FunctionType::return_type(void) const {
  RawEntityId eid = impl->reader.getVal25();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool FunctionType::is_const(void) const {
  return impl->reader.getVal28();
}

bool FunctionType::is_restrict(void) const {
  return impl->reader.getVal29();
}

bool FunctionType::is_volatile(void) const {
  return impl->reader.getVal30();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
