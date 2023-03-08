// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DefineMacroDirective.h>

#include <multiplier/Entities/Macro.h>
#include <multiplier/Entities/MacroDirective.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<DefineMacroDirective> DefineMacroDirective::containing(const Macro &macro) {
  for (auto impl = macro.parent(); impl; impl = impl->parent()) {
    if (auto d = DefineMacroDirective::from(*impl)) {
      co_yield *d;
    }
  }
}

bool DefineMacroDirective::contains(const Macro &macro) {
  auto id_ = id();
  for (auto &parent : DefineMacroDirective::containing(macro)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

bool DefineMacroDirective::contains(const Token &token) {
  auto id_ = id();
  for (auto &parent : DefineMacroDirective::containing(token)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<DefineMacroDirective> DefineMacroDirective::containing(const Token &token) {
  for (auto m : Macro::containing_internal(token)) {
    if (auto d = DefineMacroDirective::from(m)) {
      co_yield *d;
    }
  }
}

std::optional<DefineMacroDirective> DefineMacroDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<MacroId>(vid)) {
    return DefineMacroDirective::from(index.macro(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const MacroKind kDefineMacroDirectiveDerivedKinds[] = {
    DefineMacroDirective::static_kind(),
};

std::optional<DefineMacroDirective> DefineMacroDirective::from(const Macro &parent) {
  switch (parent.kind()) {
    case DefineMacroDirective::static_kind():
      return reinterpret_cast<const DefineMacroDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DefineMacroDirective> DefineMacroDirective::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (MacroKind k : kDefineMacroDirectiveDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      if (std::optional<DefineMacroDirective> e = DefineMacroDirective::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DefineMacroDirective> DefineMacroDirective::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kDefineMacroDirectiveDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      if (std::optional<DefineMacroDirective> e = DefineMacroDirective::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DefineMacroDirective> DefineMacroDirective::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (MacroKind k : kDefineMacroDirectiveDerivedKinds) {
      for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
        if (std::optional<DefineMacroDirective> e = DefineMacroDirective::from(Macro(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Token DefineMacroDirective::name(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal9();
    if (eid == kInvalidEntityId) {
      return Token();
    }
    return impl->ep->TokenFor(impl->ep, eid);
  }
  return Token();
}

gap::generator<MacroOrToken> DefineMacroDirective::body(void) const & {
  Index index(impl->ep);
  auto list = impl->reader.getVal3();
  for (auto v : list) {
    VariantEntity e = index.entity(EntityId(v));
    if (std::holds_alternative<Macro>(e)) {
      co_yield std::move(std::get<Macro>(e));
    } else if (std::holds_alternative<Token>(e)) {
      co_yield std::move(std::get<Token>(e));
    } else {
      assert(false);
    }
  }
}

bool DefineMacroDirective::is_variadic(void) const {
  return impl->reader.getVal6();
}

bool DefineMacroDirective::is_function_like(void) const {
  return impl->reader.getVal10();
}

gap::generator<MacroOrToken> DefineMacroDirective::parameters(void) const & {
  Index index(impl->ep);
  auto list = impl->reader.getVal5();
  for (auto v : list) {
    VariantEntity e = index.entity(EntityId(v));
    if (std::holds_alternative<Macro>(e)) {
      co_yield std::move(std::get<Macro>(e));
    } else if (std::holds_alternative<Token>(e)) {
      co_yield std::move(std::get<Token>(e));
    } else {
      assert(false);
    }
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx