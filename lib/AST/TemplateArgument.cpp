// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TemplateArgument.h>
#include "../Reference.h"
#include <multiplier/AST/Expr.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/ValueDecl.h>

#include "../EntityProvider.h"
#include "../File.h"
#include "../Fragment.h"
#include "../TemplateArgument.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

std::optional<Decl> TemplateArgument::parent_declaration(void) const {
  if (auto id = impl->reader.getVal0(); id != kInvalidEntityId) {
    if (auto eptr = impl->ep->DeclFor(impl->ep, id)) {
      return Decl(std::move(eptr));
    }
    assert(false);
  }
  return std::nullopt;
}

std::optional<Stmt> TemplateArgument::parent_statement(void) const {
  if (auto id = impl->reader.getVal1(); id != kInvalidEntityId) {
    if (auto eptr = impl->ep->StmtFor(impl->ep, id)) {
      return Stmt(std::move(eptr));
    }
    assert(false);
  }
  return std::nullopt;
}

std::shared_ptr<EntityProvider> TemplateArgument::entity_provider_of(const Index &index_) {
  return index_.impl;
}

std::shared_ptr<EntityProvider> TemplateArgument::entity_provider_of(const Fragment &frag_) {
  return frag_.impl->ep;
}

std::shared_ptr<EntityProvider> TemplateArgument::entity_provider_of(const File &file_) {
  return file_.impl->ep;
}

gap::generator<TemplateArgument> TemplateArgument::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TemplateArgumentImplPtr eptr : ep->TemplateArgumentsFor(ep)) {
    co_yield TemplateArgument(std::move(eptr));
  }
}

gap::generator<TemplateArgument> TemplateArgument::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TemplateArgumentImplPtr eptr : ep->TemplateArgumentsFor(ep, frag_id)) {
      co_yield TemplateArgument(std::move(eptr));
    }
  }
}

gap::generator<TemplateArgument> TemplateArgument::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TemplateArgumentImplPtr eptr : ep->TemplateArgumentsFor(ep, frag_id)) {
    co_yield TemplateArgument(std::move(eptr));
  }
}

gap::generator<TemplateArgument> TemplateArgument::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TemplateArgument::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TemplateArgument::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TemplateArgument::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<TemplateArgument> TemplateArgument::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TemplateArgumentId>(vid)) {
    return index.template_argument(eid.Pack());
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<TemplateArgument> TemplateArgument::from(const Reference &r) {
  return r.as_template_argument();
}

std::optional<TemplateArgument> TemplateArgument::from(const VariantEntity &e) {
  if (!std::holds_alternative<TemplateArgument>(e)) {
    return std::nullopt;
  }
  return std::get<TemplateArgument>(e);
}

std::optional<TemplateArgument> TemplateArgument::from(const TokenContext &t) {
  return t.as_template_argument();
}

TemplateArgumentKind TemplateArgument::kind(void) const {
  return static_cast<TemplateArgumentKind>(impl->reader.getVal2());
}

bool TemplateArgument::is_empty(void) const {
  return impl->reader.getVal3();
}

bool TemplateArgument::is_dependent(void) const {
  return impl->reader.getVal4();
}

bool TemplateArgument::is_instantiation_dependent(void) const {
  return impl->reader.getVal5();
}

bool TemplateArgument::contains_unexpanded_parameter_pack(void) const {
  return impl->reader.getVal6();
}

bool TemplateArgument::is_pack_expansion(void) const {
  return impl->reader.getVal7();
}

std::optional<ValueDecl> TemplateArgument::declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal8();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return ValueDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<Type> TemplateArgument::type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal9();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<Type> TemplateArgument::parameter_type_for_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal10();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<Type> TemplateArgument::null_pointer_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal11();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<Expr> TemplateArgument::expression(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal12();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

unsigned TemplateArgument::num_pack_arguments(void) const {
  return impl->reader.getVal13().size();
}

std::optional<TemplateArgument> TemplateArgument::nth_pack_argument(unsigned n) const {
  auto list = impl->reader.getVal13();
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

gap::generator<TemplateArgument> TemplateArgument::pack_arguments(void) const & {
  auto list = impl->reader.getVal13();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d13 = ep->TemplateArgumentFor(ep, v)) {
      co_yield TemplateArgument(std::move(d13));
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
