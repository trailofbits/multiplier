// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/MSVCMajorVersion.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(MSVCMajorVersion e) {
  switch (e) {
    case MSVCMajorVersion::MSVC2010: return "MSVC2010";
    case MSVCMajorVersion::MSVC2012: return "MSVC2012";
    case MSVCMajorVersion::MSVC2013: return "MSVC2013";
    case MSVCMajorVersion::MSVC2015: return "MSVC2015";
    case MSVCMajorVersion::MSVC2017: return "MSVC2017";
    case MSVCMajorVersion::MSVC20175: return "MSVC20175";
    case MSVCMajorVersion::MSVC20177: return "MSVC20177";
    case MSVCMajorVersion::MSVC2019: return "MSVC2019";
    case MSVCMajorVersion::MSVC20195: return "MSVC20195";
    case MSVCMajorVersion::MSVC20198: return "MSVC20198";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
