// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TemplateParameterList.h>

#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/File.h>
#include <multiplier/Entities/Fragment.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Reference.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../File.h"
#include "../Fragment.h"
#include "../TemplateParameterList.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

std::shared_ptr<EntityProvider> TemplateParameterList::entity_provider_of(const Index &index_) {
  return index_.impl;
}

std::shared_ptr<EntityProvider> TemplateParameterList::entity_provider_of(const Fragment &frag_) {
  return frag_.impl->ep;
}

std::shared_ptr<EntityProvider> TemplateParameterList::entity_provider_of(const File &file_) {
  return file_.impl->ep;
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
  return impl->reader.getVal0();
}

bool TemplateParameterList::has_unexpanded_parameter_pack(void) const {
  return impl->reader.getVal1();
}

bool TemplateParameterList::has_parameter_pack(void) const {
  return impl->reader.getVal2();
}

std::optional<Expr> TemplateParameterList::requires_clause(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal3();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

Token TemplateParameterList::template_keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal4());
}

Token TemplateParameterList::left_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal5());
}

Token TemplateParameterList::right_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal6());
}

TokenRange TemplateParameterList::tokens(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal7(), impl->reader.getVal8());
}

unsigned TemplateParameterList::num_parameters(void) const {
  return impl->reader.getVal9().size();
}

std::optional<NamedDecl> TemplateParameterList::nth_parameter(unsigned n) const {
  auto list = impl->reader.getVal9();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return NamedDecl::from(Decl(std::move(e)));
}

gap::generator<NamedDecl> TemplateParameterList::parameters(void) const & {
  auto list = impl->reader.getVal9();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d9 = ep->DeclFor(ep, v)) {
      if (auto e = NamedDecl::from(Decl(std::move(d9)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
