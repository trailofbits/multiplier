// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CommentKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CommentKind e) {
  switch (e) {
    case CommentKind::INVALID: return "INVALID";
    case CommentKind::ORDINARY_BCPL: return "ORDINARY_BCPL";
    case CommentKind::ORDINARY_C: return "ORDINARY_C";
    case CommentKind::BCPL_SLASH: return "BCPL_SLASH";
    case CommentKind::BCPL_EXCL: return "BCPL_EXCL";
    case CommentKind::JAVA_DOC: return "JAVA_DOC";
    case CommentKind::QT: return "QT";
    case CommentKind::MERGED: return "MERGED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
