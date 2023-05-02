// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/IncludeLikeMacroDirective.h>

#include <multiplier/Entities/File.h>
#include <multiplier/Entities/ImportMacroDirective.h>
#include <multiplier/Entities/IncludeMacroDirective.h>
#include <multiplier/Entities/IncludeMacrosMacroDirective.h>
#include <multiplier/Entities/IncludeNextMacroDirective.h>
#include <multiplier/Entities/Macro.h>
#include <multiplier/Entities/MacroDirective.h>

#include "../EntityProvider.h"
#include "../Macro.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<IncludeLikeMacroDirective> IncludeLikeMacroDirective::containing(const Macro &macro) {
  for (auto impl = macro.parent(); impl; impl = impl->parent()) {
    if (auto d = IncludeLikeMacroDirective::from(*impl)) {
      co_yield *d;
    }
  }
}

bool IncludeLikeMacroDirective::contains(const Macro &macro) {
  auto id_ = id();
  for (auto &parent : IncludeLikeMacroDirective::containing(macro)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

bool IncludeLikeMacroDirective::contains(const Token &token) {
  auto id_ = id();
  for (auto &parent : IncludeLikeMacroDirective::containing(token)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<IncludeLikeMacroDirective> IncludeLikeMacroDirective::containing(const Token &token) {
  for (auto m : Macro::containing_internal(token)) {
    if (auto d = IncludeLikeMacroDirective::from(m)) {
      co_yield *d;
    }
  }
}

std::optional<IncludeLikeMacroDirective> IncludeLikeMacroDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<MacroId>(vid)) {
    return IncludeLikeMacroDirective::from(index.macro(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const MacroKind kIncludeLikeMacroDirectiveDerivedKinds[] = {
    IncludeMacroDirective::static_kind(),
    IncludeNextMacroDirective::static_kind(),
    IncludeMacrosMacroDirective::static_kind(),
    ImportMacroDirective::static_kind(),
};

std::optional<IncludeLikeMacroDirective> IncludeLikeMacroDirective::from(const Macro &parent) {
  switch (parent.kind()) {
    case IncludeMacroDirective::static_kind():
    case IncludeNextMacroDirective::static_kind():
    case IncludeMacrosMacroDirective::static_kind():
    case ImportMacroDirective::static_kind():
      return reinterpret_cast<const IncludeLikeMacroDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<IncludeLikeMacroDirective> IncludeLikeMacroDirective::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (MacroKind k : kIncludeLikeMacroDirectiveDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k)) {
      if (std::optional<IncludeLikeMacroDirective> e = IncludeLikeMacroDirective::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<IncludeLikeMacroDirective> IncludeLikeMacroDirective::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (MacroKind k : kIncludeLikeMacroDirectiveDerivedKinds) {
    for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
      if (std::optional<IncludeLikeMacroDirective> e = IncludeLikeMacroDirective::from(Macro(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<IncludeLikeMacroDirective> IncludeLikeMacroDirective::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (MacroKind k : kIncludeLikeMacroDirectiveDerivedKinds) {
      for (MacroImplPtr eptr : ep->MacrosFor(ep, k, frag_id)) {
        if (std::optional<IncludeLikeMacroDirective> e = IncludeLikeMacroDirective::from(Macro(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<IncludeLikeMacroDirective> IncludeLikeMacroDirective::from(const Reference &r) {
  return IncludeLikeMacroDirective::from(r.as_macro());
}

std::optional<IncludeLikeMacroDirective> IncludeLikeMacroDirective::from(const TokenContext &t) {
  return IncludeLikeMacroDirective::from(t.as_macro());
}

std::optional<File> IncludeLikeMacroDirective::included_file(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal10();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->FileFor(impl->ep, eid)) {
      return File(std::move(eptr));
    }
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
