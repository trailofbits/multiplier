// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ID.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ID e) {
  switch (e) {
    case ID::WORK_GROUP: return "WORK_GROUP";
    case ID::DEVICE: return "DEVICE";
    case ID::ALL_SVM_DEVICES: return "ALL_SVM_DEVICES";
    case ID::SUB_GROUP: return "SUB_GROUP";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
