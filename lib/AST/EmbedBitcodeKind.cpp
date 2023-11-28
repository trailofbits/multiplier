// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/EmbedBitcodeKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(EmbedBitcodeKind e) {
  switch (e) {
    case EmbedBitcodeKind::EMBED_OFF: return "EMBED_OFF";
    case EmbedBitcodeKind::EMBED_ALL: return "EMBED_ALL";
    case EmbedBitcodeKind::EMBED_BITCODE: return "EMBED_BITCODE";
    case EmbedBitcodeKind::EMBED_MARKER: return "EMBED_MARKER";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
