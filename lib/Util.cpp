// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/AST/StmtKind.h>

namespace mx {

// Returns `true` if it seems like we've hit something that can't possibly
// return a value. This is usually a good stopping point to say "this thing
// isn't a line of code".
bool IsNonValueStatement(StmtKind kind) {
  switch (kind) {
    case StmtKind::CASE_STMT:
    case StmtKind::DEFAULT_STMT:
    case StmtKind::LABEL_STMT:
    case StmtKind::COMPOUND_STMT:
    case StmtKind::SWITCH_STMT:
    case StmtKind::DO_STMT:
    case StmtKind::WHILE_STMT:
    case StmtKind::FOR_STMT:
    case StmtKind::IF_STMT:
    case StmtKind::CXX_TRY_STMT:
    case StmtKind::CXX_FOR_RANGE_STMT:
    case StmtKind::CXX_CATCH_STMT:
    case StmtKind::COROUTINE_BODY_STMT:  // Not sure what this is.
      return true;
    default:
      return false;
  }
}

}  // namespace mx
