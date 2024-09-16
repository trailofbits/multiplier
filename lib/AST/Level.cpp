// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/Level.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(Level e) {
  switch (e) {
    case Level::IGNORED: return "IGNORED";
    case Level::NOTE: return "NOTE";
    case Level::REMARK: return "REMARK";
    case Level::WARNING: return "WARNING";
    case Level::ERROR: return "ERROR";
    case Level::FATAL: return "FATAL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
