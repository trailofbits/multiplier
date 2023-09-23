// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OpenMPDoacrossClauseModifier.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenMPDoacrossClauseModifier e) {
  switch (e) {
    case OpenMPDoacrossClauseModifier::DOACROSS_SOURCE: return "DOACROSS_SOURCE";
    case OpenMPDoacrossClauseModifier::DOACROSS_SINK: return "DOACROSS_SINK";
    case OpenMPDoacrossClauseModifier::DOACROSS_SINK_OMP_CUR_ITERATION: return "DOACROSS_SINK_OMP_CUR_ITERATION";
    case OpenMPDoacrossClauseModifier::DOACROSS_SOURCE_OMP_CUR_ITERATION: return "DOACROSS_SOURCE_OMP_CUR_ITERATION";
    case OpenMPDoacrossClauseModifier::DOACROSS_UNKNOWN: return "DOACROSS_UNKNOWN";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
