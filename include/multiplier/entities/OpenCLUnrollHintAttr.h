// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "AttrKind.h"
#include "StmtAttr.h"

namespace mx {
class Attr;
class OpenCLUnrollHintAttr;
class StmtAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OpenCLUnrollHintAttrRange = DerivedEntityRange<AttrIterator, OpenCLUnrollHintAttr>;
using OpenCLUnrollHintAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, OpenCLUnrollHintAttr>;
class OpenCLUnrollHintAttr : public StmtAttr {
 private:
  friend class FragmentImpl;
  friend class StmtAttr;
  friend class Attr;
 public:
  inline static OpenCLUnrollHintAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OpenCLUnrollHintAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OpenCLUnrollHintAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OPEN_CL_UNROLL_HINT;
  }

  static std::optional<OpenCLUnrollHintAttr> from(const TokenContext &c);
  static std::optional<OpenCLUnrollHintAttr> from(const StmtAttr &parent);

  inline static std::optional<OpenCLUnrollHintAttr> from(const std::optional<StmtAttr> &parent) {
    if (parent) {
      return OpenCLUnrollHintAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OpenCLUnrollHintAttr> from(const Attr &parent);

  inline static std::optional<OpenCLUnrollHintAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OpenCLUnrollHintAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(OpenCLUnrollHintAttr) == sizeof(StmtAttr));

#endif
} // namespace mx
