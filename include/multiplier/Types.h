// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <limits>
#include <string>

namespace mx {
enum class CompilerName : uint8_t;
enum class IncludePathLocation : uint8_t;
enum class TargetLanguage : uint8_t;
}  // namespace mx
namespace pasta {
enum class CompilerName : unsigned;
enum class IncludePathLocation : unsigned;
enum class TargetLanguage : unsigned;
}  // namespace pasta
// This included file is auto-generated. Depending on when we're compiling this,
// we may be in the build dir where this auto-generated file is placed, or in
// or it may be publicly available through a target copied location, or in its
// installed location.
#ifndef __has_include
#  error "Missing __has_includex"
#elif __has_include(<multiplier/mx_generated.h>)
#  include <multiplier/mx_generated.h>
#elif __has_include("mx_generated.h")
#  include "mx_generated.h"
#else
#  error "Cannot locate mx_generated.h"
#endif

namespace mx {

inline static CompilerName FromPasta(pasta::CompilerName cn) {
  return static_cast<CompilerName>(cn);
}

inline static IncludePathLocation FromPasta(pasta::IncludePathLocation ipl) {
  return static_cast<IncludePathLocation>(ipl);
}

inline static TargetLanguage FromPasta(pasta::TargetLanguage tl) {
  return static_cast<TargetLanguage>(tl);
}

inline static pasta::CompilerName ToPasta(CompilerName cn) {
  return static_cast<pasta::CompilerName>(cn);
}

inline static pasta::IncludePathLocation ToPasta(IncludePathLocation ipl) {
  return static_cast<pasta::IncludePathLocation>(ipl);
}

inline static pasta::TargetLanguage ToPasta(TargetLanguage tl) {
  return static_cast<pasta::TargetLanguage>(tl);
}

}  // namespace mx
