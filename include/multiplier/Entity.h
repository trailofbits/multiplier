// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Types.h"

namespace mx {

class DefineMacroDirective;
class NamedDecl;
class Token;
class TokenReader;

using TokenImplPtr = std::shared_ptr<const TokenReader>;

#define MX_FORWARD_DECLARE(type_name, lower_name, enum_name, category) \
    class type_name; \
    class type_name ## Impl; \
    using type_name ## ImplPtr = std::shared_ptr<const type_name ## Impl>; \
    using Weak ## type_name ## ImplPtr = std::weak_ptr<const type_name ## Impl>;

MX_FOR_EACH_ENTITY_CATEGORY(MX_FORWARD_DECLARE,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_FORWARD_DECLARE,
                            MX_FORWARD_DECLARE,
                            MX_FORWARD_DECLARE,
                            MX_FORWARD_DECLARE,
                            MX_FORWARD_DECLARE)
#undef MX_FORWARD_DECLARE

#define MX_DECLARE_ENTITY_VARIANT(type_name, lower_name, enum_name, category) \
    , type_name

using NotAnEntity = std::monostate;
using VariantEntity = std::variant<
    NotAnEntity MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_ENTITY_VARIANT,
                                            MX_DECLARE_ENTITY_VARIANT,
                                            MX_DECLARE_ENTITY_VARIANT,
                                            MX_DECLARE_ENTITY_VARIANT,
                                            MX_DECLARE_ENTITY_VARIANT,
                                            MX_DECLARE_ENTITY_VARIANT,
                                            MX_DECLARE_ENTITY_VARIANT)>;
#undef MX_DECLARE_ENTITY_VARIANT

using NamedEntity = std::variant<NamedDecl, DefineMacroDirective, File>;

// Explicit specialization to get the entity id.
template <>
EntityId::EntityId(const VariantEntity &);

}  // namespace mx
