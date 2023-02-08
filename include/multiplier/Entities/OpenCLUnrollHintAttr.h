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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "AttrKind.h"
#include "StmtAttr.h"

namespace mx {
class Attr;
class OpenCLUnrollHintAttr;
class StmtAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OpenCLUnrollHintAttr : public StmtAttr {
 private:
  friend class FragmentImpl;
  friend class StmtAttr;
  friend class Attr;
 public:
  static gap::generator<OpenCLUnrollHintAttr> in(const Fragment &frag);
  static gap::generator<OpenCLUnrollHintAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OPEN_CL_UNROLL_HINT;
  }

  static gap::generator<AttrKind> derived_kinds(void);
  inline static std::optional<OpenCLUnrollHintAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<OpenCLUnrollHintAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

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

};

static_assert(sizeof(OpenCLUnrollHintAttr) == sizeof(StmtAttr));

#endif
} // namespace mx
