// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TLSModel.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TLSModel e) {
  switch (e) {
    case TLSModel::GENERAL_DYNAMIC_TLS_MODEL: return "GENERAL_DYNAMIC_TLS_MODEL";
    case TLSModel::LOCAL_DYNAMIC_TLS_MODEL: return "LOCAL_DYNAMIC_TLS_MODEL";
    case TLSModel::INITIAL_EXEC_TLS_MODEL: return "INITIAL_EXEC_TLS_MODEL";
    case TLSModel::LOCAL_EXEC_TLS_MODEL: return "LOCAL_EXEC_TLS_MODEL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
