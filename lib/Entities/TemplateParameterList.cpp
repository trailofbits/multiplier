// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TemplateParameterList.h>

#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Reference.h>

#include "../API.h"
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

unsigned TemplateParameterList::num_parameters(void) const {
  return impl->reader.getVal0();
}

unsigned TemplateParameterList::num_required_parameters(void) const {
  return impl->reader.getVal1();
}

unsigned TemplateParameterList::depth(void) const {
  return impl->reader.getVal2();
}

bool TemplateParameterList::has_unexpanded_parameter_pack(void) const {
  return impl->reader.getVal3();
}

bool TemplateParameterList::has_parameter_pack(void) const {
  return impl->reader.getVal4();
}

std::optional<Expr> TemplateParameterList::requires_clause(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal5();
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
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal6());
}

Token TemplateParameterList::left_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal7());
}

Token TemplateParameterList::right_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal8());
}

TokenRange TemplateParameterList::tokens(void) const {
  auto &ep = impl->ep;
  auto fragment = ep->FragmentFor(ep, impl->fragment_id);
  return fragment->TokenRangeFor(fragment, impl->reader.getVal9(), impl->reader.getVal10());
}

std::optional<NamedDecl> TemplateParameterList::nth_parameter(unsigned n) const {
  auto list = impl->reader.getVal11();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return NamedDecl::from(Decl(std::move(e)));
}

gap::generator<NamedDecl> TemplateParameterList::parameters(void) const & {
  auto list = impl->reader.getVal11();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d11 = ep->DeclFor(ep, v)) {
      if (auto e = NamedDecl::from(Decl(std::move(d11)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
