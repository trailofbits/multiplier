// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AvailableOnlyInDefaultEvalMethodAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AvailableOnlyInDefaultEvalMethodAttrSpelling e) {
  switch (e) {
    case AvailableOnlyInDefaultEvalMethodAttrSpelling::GNU_AVAILABLE_ONLY_IN_DEFAULT_EVAL_METHOD: return "GNU_AVAILABLE_ONLY_IN_DEFAULT_EVAL_METHOD";
    case AvailableOnlyInDefaultEvalMethodAttrSpelling::CXX11_CLANG_AVAILABLE_ONLY_IN_DEFAULT_EVAL_METHOD: return "CXX11_CLANG_AVAILABLE_ONLY_IN_DEFAULT_EVAL_METHOD";
    case AvailableOnlyInDefaultEvalMethodAttrSpelling::C23_CLANG_AVAILABLE_ONLY_IN_DEFAULT_EVAL_METHOD: return "C23_CLANG_AVAILABLE_ONLY_IN_DEFAULT_EVAL_METHOD";
    case AvailableOnlyInDefaultEvalMethodAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
