// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <pasta/Util/Result.h>

namespace mx {

template <typename ValueType, typename ErrorType>
using Result = pasta::Result<ValueType, ErrorType>;

}  // namespace mx
