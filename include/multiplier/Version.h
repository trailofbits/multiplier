// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <string_view>

#include "Compiler.h"

namespace mx {

MX_EXPORT std::string_view revision(void) noexcept;

}  // namespace mx