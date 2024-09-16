// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/NoStackProtectorAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NoStackProtectorAttrSpelling e) {
  switch (e) {
    case NoStackProtectorAttrSpelling::GNU_NO_STACK_PROTECTOR: return "GNU_NO_STACK_PROTECTOR";
    case NoStackProtectorAttrSpelling::CXX11_CLANG_NO_STACK_PROTECTOR: return "CXX11_CLANG_NO_STACK_PROTECTOR";
    case NoStackProtectorAttrSpelling::C23_CLANG_NO_STACK_PROTECTOR: return "C23_CLANG_NO_STACK_PROTECTOR";
    case NoStackProtectorAttrSpelling::CXX11_GNU_NO_STACK_PROTECTOR: return "CXX11_GNU_NO_STACK_PROTECTOR";
    case NoStackProtectorAttrSpelling::C23_GNU_NO_STACK_PROTECTOR: return "C23_GNU_NO_STACK_PROTECTOR";
    case NoStackProtectorAttrSpelling::DECLSPEC_SAFEBUFFERS: return "DECLSPEC_SAFEBUFFERS";
    case NoStackProtectorAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
