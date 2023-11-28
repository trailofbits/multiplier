// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/Bits.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(Bits e) {
  switch (e) {
    case Bits::NONE: return "NONE";
    case Bits::UNEXPANDED_PACK: return "UNEXPANDED_PACK";
    case Bits::INSTANTIATION: return "INSTANTIATION";
    case Bits::TYPE: return "TYPE";
    case Bits::VALUE: return "VALUE";
    case Bits::DEPENDENT: return "DEPENDENT";
    case Bits::ERROR: return "ERROR";
    case Bits::VARIABLY_MODIFIED: return "VARIABLY_MODIFIED";
    case Bits::SYNTACTIC: return "SYNTACTIC";
    case Bits::SEMANTIC: return "SEMANTIC";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
