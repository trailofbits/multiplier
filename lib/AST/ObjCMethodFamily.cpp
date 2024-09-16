// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCMethodFamily.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCMethodFamily e) {
  switch (e) {
    case ObjCMethodFamily::NONE: return "NONE";
    case ObjCMethodFamily::ALLOC: return "ALLOC";
    case ObjCMethodFamily::COPY: return "COPY";
    case ObjCMethodFamily::INITIALIZER: return "INITIALIZER";
    case ObjCMethodFamily::MUTABLE_COPY: return "MUTABLE_COPY";
    case ObjCMethodFamily::NEW: return "NEW";
    case ObjCMethodFamily::AUTORELEASE: return "AUTORELEASE";
    case ObjCMethodFamily::DEALLOC: return "DEALLOC";
    case ObjCMethodFamily::FINALIZE: return "FINALIZE";
    case ObjCMethodFamily::RELEASE: return "RELEASE";
    case ObjCMethodFamily::RETAIN: return "RETAIN";
    case ObjCMethodFamily::RETAIN_COUNT: return "RETAIN_COUNT";
    case ObjCMethodFamily::SELF: return "SELF";
    case ObjCMethodFamily::INITIALIZE: return "INITIALIZE";
    case ObjCMethodFamily::PERFORM_SELECTOR: return "PERFORM_SELECTOR";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
