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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Attr.h"

namespace mx {
class Attr;
class RenderScriptKernelAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class RenderScriptKernelAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<RenderScriptKernelAttr> in(const Fragment &frag);
  static gap::generator<RenderScriptKernelAttr> in(const File &file);
  static gap::generator<RenderScriptKernelAttr> in(const Index &index);
  static gap::generator<RenderScriptKernelAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<RenderScriptKernelAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::RENDER_SCRIPT_KERNEL;
  }

  static std::optional<RenderScriptKernelAttr> from(const Attr &parent);

  inline static std::optional<RenderScriptKernelAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return RenderScriptKernelAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<RenderScriptKernelAttr> from(const Reference &r) {
    return RenderScriptKernelAttr::from(r.as_attribute());
  }

  inline static std::optional<RenderScriptKernelAttr> from(const TokenContext &t) {
    return RenderScriptKernelAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(RenderScriptKernelAttr) == sizeof(Attr));

#endif
} // namespace mx
