// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#ifndef PSEUDO_ENTITY_TYPES

#define PSEUDO_ENTITY_TYPES(p) \
    p(TemplateArgument) \
    p(TemplateParameterList) \
    p(CXXBaseSpecifier)

#define PSEUDO_ENTITY_TYPE_ENUMERATOR(n) k ## n ,

namespace pasta {

// Define this here, in the PASTA namespace, so it ends up getting codegen'd
// into the output.
//
// NOTE(pag): Keep this in sync with `bin/Index/Util.h`.
enum class PseudoEntityKind : unsigned char {
  PSEUDO_ENTITY_TYPES(PSEUDO_ENTITY_TYPE_ENUMERATOR)
};

}  // namespace pasta

#endif  // PSEUDO_ENTITY_TYPES
