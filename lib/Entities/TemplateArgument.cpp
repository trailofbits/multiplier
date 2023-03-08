// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TemplateArgument.h>

#include <multiplier/Entities/Reference.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/ValueDecl.h>

#include "../API.h"
#include "../File.h"
#include "../Fragment.h"
#include "../TemplateArgument.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

std::shared_ptr<EntityProvider> TemplateArgument::entity_provider_of(const Index &index_) {
  return index_.impl;
}

std::shared_ptr<EntityProvider> TemplateArgument::entity_provider_of(const Fragment &frag_) {
  return frag_.impl->ep;
}

std::shared_ptr<EntityProvider> TemplateArgument::entity_provider_of(const File &file_) {
  return file_.impl->ep;
}

TemplateArgumentKind TemplateArgument::kind(void) const {
  return static_cast<TemplateArgumentKind>(impl->reader.getVal0());
}

bool TemplateArgument::is_null(void) const {
  return impl->reader.getVal1();
}

bool TemplateArgument::is_dependent(void) const {
  return impl->reader.getVal2();
}

bool TemplateArgument::is_instantiation_dependent(void) const {
  return impl->reader.getVal3();
}

bool TemplateArgument::contains_unexpanded_parameter_pack(void) const {
  return impl->reader.getVal4();
}

bool TemplateArgument::is_pack_expansion(void) const {
  return impl->reader.getVal5();
}

std::optional<ValueDecl> TemplateArgument::as_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal6();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return ValueDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

std::optional<Type> TemplateArgument::as_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal7();
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
    RawEntityId eid = impl->reader.getVal8();
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

#pragma GCC diagnostic pop
#endif
}  // namespace mx
