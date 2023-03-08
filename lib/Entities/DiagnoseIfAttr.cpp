// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DiagnoseIfAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<DiagnoseIfAttr> DiagnoseIfAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DiagnoseIfAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DiagnoseIfAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DiagnoseIfAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<DiagnoseIfAttr> DiagnoseIfAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return DiagnoseIfAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kDiagnoseIfAttrDerivedKinds[] = {
    DiagnoseIfAttr::static_kind(),
};

std::optional<DiagnoseIfAttr> DiagnoseIfAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case DiagnoseIfAttr::static_kind():
      return reinterpret_cast<const DiagnoseIfAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DiagnoseIfAttr> DiagnoseIfAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kDiagnoseIfAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<DiagnoseIfAttr> e = DiagnoseIfAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DiagnoseIfAttr> DiagnoseIfAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kDiagnoseIfAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<DiagnoseIfAttr> e = DiagnoseIfAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DiagnoseIfAttr> DiagnoseIfAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kDiagnoseIfAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<DiagnoseIfAttr> e = DiagnoseIfAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<DiagnoseIfAttr> DiagnoseIfAttr::from(const Reference &r) {
  return DiagnoseIfAttr::from(r.as_attribute());
}

std::optional<DiagnoseIfAttr> DiagnoseIfAttr::from(const TokenContext &t) {
  return DiagnoseIfAttr::from(t.as_attribute());
}

bool DiagnoseIfAttr::argument_dependent(void) const {
  return impl->reader.getVal12();
}

Expr DiagnoseIfAttr::condition(void) const {
  RawEntityId eid = impl->reader.getVal8();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

DiagnoseIfAttrDiagnosticType DiagnoseIfAttr::diagnostic_type(void) const {
  return static_cast<DiagnoseIfAttrDiagnosticType>(impl->reader.getVal10());
}

std::string_view DiagnoseIfAttr::message(void) const {
  capnp::Text::Reader data = impl->reader.getVal9();
  return std::string_view(data.cStr(), data.size());
}

NamedDecl DiagnoseIfAttr::parent(void) const {
  RawEntityId eid = impl->reader.getVal16();
  return NamedDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

bool DiagnoseIfAttr::is_error(void) const {
  return impl->reader.getVal13();
}

bool DiagnoseIfAttr::is_warning(void) const {
  return impl->reader.getVal18();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
