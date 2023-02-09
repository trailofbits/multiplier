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
#include "AttrKind.h"
#include "OpenCLAccessAttrSpelling.h"

namespace mx {
class Attr;
class OpenCLAccessAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OpenCLAccessAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<OpenCLAccessAttr> in(const Fragment &frag);
  static gap::generator<OpenCLAccessAttr> in(const Index &index);
  static gap::generator<OpenCLAccessAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<OpenCLAccessAttr> by(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OPEN_CL_ACCESS;
  }

  inline static std::optional<OpenCLAccessAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<OpenCLAccessAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<OpenCLAccessAttr> from(const Attr &parent);

  inline static std::optional<OpenCLAccessAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OpenCLAccessAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  OpenCLAccessAttrSpelling semantic_spelling(void) const;
  bool is_read_only(void) const;
  bool is_read_write(void) const;
  bool is_write_only(void) const;
};

static_assert(sizeof(OpenCLAccessAttr) == sizeof(Attr));

#endif
} // namespace mx
