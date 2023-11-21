// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/VectorLibrary.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(VectorLibrary e) {
  switch (e) {
    case VectorLibrary::NO_LIBRARY: return "NO_LIBRARY";
    case VectorLibrary::ACCELERATE: return "ACCELERATE";
    case VectorLibrary::LIBMVEC: return "LIBMVEC";
    case VectorLibrary::MASSV: return "MASSV";
    case VectorLibrary::SVML: return "SVML";
    case VectorLibrary::SLEEF: return "SLEEF";
    case VectorLibrary::DARWIN_LIBSYSTEM_M: return "DARWIN_LIBSYSTEM_M";
    case VectorLibrary::ARM_PL: return "ARM_PL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
