// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/AutoType.h>

#include <multiplier/Entities/ConceptDecl.h>
#include <multiplier/Entities/DeducedType.h>
#include <multiplier/Entities/TemplateArgument.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<AutoType> AutoType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = AutoType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool AutoType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : AutoType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<AutoType> AutoType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return AutoType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kAutoTypeDerivedKinds[] = {
    AutoType::static_kind(),
};

std::optional<AutoType> AutoType::from(const Type &parent) {
  switch (parent.kind()) {
    case AutoType::static_kind():
      return reinterpret_cast<const AutoType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<AutoType> AutoType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kAutoTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<AutoType> e = AutoType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AutoType> AutoType::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kAutoTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<AutoType> e = AutoType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AutoType> AutoType::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kAutoTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<AutoType> e = AutoType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<AutoType> AutoType::from(const Reference &r) {
  return AutoType::from(r.as_type());
}

std::optional<AutoType> AutoType::from(const TokenContext &t) {
  return AutoType::from(t.as_type());
}

AutoTypeKeyword AutoType::keyword(void) const {
  return static_cast<AutoTypeKeyword>(impl->reader.getVal238());
}

unsigned AutoType::num_type_constraint_arguments(void) const {
  return impl->reader.getVal234().size();
}

std::optional<TemplateArgument> AutoType::nth_type_constraint_argument(unsigned n) const {
  auto list = impl->reader.getVal234();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TemplateArgumentFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return TemplateArgument(std::move(e));
}

gap::generator<TemplateArgument> AutoType::type_constraint_arguments(void) const & {
  auto list = impl->reader.getVal234();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d234 = ep->TemplateArgumentFor(ep, v)) {
      co_yield TemplateArgument(std::move(d234));
    }
  }
  co_return;
}

std::optional<ConceptDecl> AutoType::type_constraint_concept(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal236();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return ConceptDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

bool AutoType::is_constrained(void) const {
  return impl->reader.getVal233();
}

bool AutoType::is_decltype_auto(void) const {
  return impl->reader.getVal239();
}

bool AutoType::is_gnu_auto_type(void) const {
  return impl->reader.getVal240();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
