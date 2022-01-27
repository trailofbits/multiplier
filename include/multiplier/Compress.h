// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <string>
#include <system_error>

#include "Result.h"

namespace mx {

// Try to compress `input`.
Result<std::string, std::error_code> TryCompress(std::string_view input);

// Try to uncompress `compressed_input`.
Result<std::string, std::error_code> TryUncompress(
    std::string_view compressed_input, size_t output_size=0);

}  // namespace mx
