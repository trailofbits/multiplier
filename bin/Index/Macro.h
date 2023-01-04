// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <pasta/AST/Macro.h>

namespace pasta {

#define CUSTOM_MACRO_KINDS(m) \
    m(Stringify) \
    m(Concatenate) \
    m(VAOpt) \
    m(VAOptArgument)

class MacroStringify : public MacroSubstitution {};
class MacroConcatenate : public MacroSubstitution {};
class MacroVAOpt : public MacroSubstitution {};
class MacroVAOptArgument : public Macro {};

}  // namespace pasta
