// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/InitStorageKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(InitStorageKind e) {
  switch (e) {
    case InitStorageKind::NO_INITIALIZER: return "NO_INITIALIZER";
    case InitStorageKind::IN_CLASS_COPY_INITIALIZER: return "IN_CLASS_COPY_INITIALIZER";
    case InitStorageKind::IN_CLASS_LIST_INITIALIZER: return "IN_CLASS_LIST_INITIALIZER";
    case InitStorageKind::CAPTURED_VLA_TYPE: return "CAPTURED_VLA_TYPE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
