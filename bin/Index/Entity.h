// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#define FOR_EACH_ENTITY_CATEGORY(m) \
    m(Decl, declaration) \
    m(Stmt, statement) \
    m(Type, type) \
    m(Attr, attribute) \
    m(Macro, macro) \
    m(TemplateArgument, template_argument) \
    m(TemplateParameterList, template_parameter_list)\
    m(CXXBaseSpecifier, cxx_base_specifier) \
    m(Designator, designator) \
    m(CXXCtorInitializer, cxx_ctor_initializer)

#define FOR_EACH_PSEUDO_ENTITY_TYPE(p) \
    p(TemplateArgument) \
    p(TemplateParameterList) \
    p(CXXBaseSpecifier) \
    p(Designator) \
    p(CXXCtorInitializer)

#define PSEUDO_ENTITY_TYPE_ENUMERATOR(n) k ## n ,

namespace pasta {

// Define this here, in the PASTA namespace, so it ends up getting codegen'd
// into the output.
//
// NOTE(pag): Keep this in sync with `bin/Index/Util.h`.
enum class PseudoKind : unsigned char {
  FOR_EACH_PSEUDO_ENTITY_TYPE(PSEUDO_ENTITY_TYPE_ENUMERATOR)
};

}  // namespace pasta
