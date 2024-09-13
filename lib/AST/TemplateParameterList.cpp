// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TemplateParameterList.h>
#include "../Reference.h"
#include <multiplier/AST/Expr.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/Frontend/Token.h>

#include "../EntityProvider.h"
#include "../File.h"
#include "../Fragment.h"
#include "../TemplateParameterList.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

std::optional<Decl> TemplateParameterList::parent_declaration(void) const {
  if (auto id = impl->reader.getVal0(); id != kInvalidEntityId) {
    if (auto eptr = impl->ep->DeclFor(impl->ep, id)) {
      return Decl(std::move(eptr));
    }
    assert(false);
  }
  return std::nullopt;
}

std::shared_ptr<EntityProvider> TemplateParameterList::entity_provider_of(const Index &index_) {
  return index_.impl;
}

std::shared_ptr<EntityProvider> TemplateParameterList::entity_provider_of(const Fragment &frag_) {
  return frag_.impl->ep;
}

std::shared_ptr<EntityProvider> TemplateParameterList::entity_provider_of(const File &file_) {
  return file_.impl->ep;
}

gap::generator<TemplateParameterList> TemplateParameterList::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TemplateParameterListImplPtr eptr : ep->TemplateParameterListsFor(ep)) {
    co_yield TemplateParameterList(std::move(eptr));
  }
}

gap::generator<TemplateParameterList> TemplateParameterList::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TemplateParameterListImplPtr eptr : ep->TemplateParameterListsFor(ep, frag_id)) {
      co_yield TemplateParameterList(std::move(eptr));
    }
  }
}

gap::generator<TemplateParameterList> TemplateParameterList::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TemplateParameterListImplPtr eptr : ep->TemplateParameterListsFor(ep, frag_id)) {
    co_yield TemplateParameterList(std::move(eptr));
  }
}

gap::generator<TemplateParameterList> TemplateParameterList::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TemplateParameterList::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TemplateParameterList::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TemplateParameterList::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<TemplateParameterList> TemplateParameterList::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TemplateParameterListId>(vid)) {
    return index.template_parameter_list(eid.Pack());
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<TemplateParameterList> TemplateParameterList::from(const Reference &r) {
  return r.as_template_parameter_list();
}

std::optional<TemplateParameterList> TemplateParameterList::from(const VariantEntity &e) {
  if (!std::holds_alternative<TemplateParameterList>(e)) {
    return std::nullopt;
  }
  return std::get<TemplateParameterList>(e);
}

std::optional<TemplateParameterList> TemplateParameterList::from(const TokenContext &t) {
  return t.as_template_parameter_list();
}

uint32_t TemplateParameterList::depth(void) const {
  return impl->reader.getVal1();
}

bool TemplateParameterList::has_unexpanded_parameter_pack(void) const {
  return impl->reader.getVal2();
}

bool TemplateParameterList::has_parameter_pack(void) const {
  return impl->reader.getVal3();
}

std::optional<Expr> TemplateParameterList::requires_clause(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal4();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token TemplateParameterList::template_keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal5());
}

Token TemplateParameterList::left_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal6());
}

Token TemplateParameterList::right_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal7());
}

TokenRange TemplateParameterList::tokens(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal8(), impl->reader.getVal9());
}

unsigned TemplateParameterList::num_parameters(void) const {
  return impl->reader.getVal10().size();
}

std::optional<NamedDecl> TemplateParameterList::nth_parameter(unsigned n) const {
  auto list = impl->reader.getVal10();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return NamedDecl::from_base(std::move(e));
}

gap::generator<NamedDecl> TemplateParameterList::parameters(void) const & {
  auto list = impl->reader.getVal10();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d10 = ep->DeclFor(ep, v)) {
      if (auto e = NamedDecl::from_base(std::move(d10))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
