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

#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class WebAssemblyExportNameAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class WebAssemblyExportNameAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<WebAssemblyExportNameAttr> in(const Fragment &frag);
  static gap::generator<WebAssemblyExportNameAttr> in(const File &file);
  static gap::generator<WebAssemblyExportNameAttr> in(const Index &index);
  static gap::generator<WebAssemblyExportNameAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<WebAssemblyExportNameAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::WEB_ASSEMBLY_EXPORT_NAME;
  }

  static std::optional<WebAssemblyExportNameAttr> from(const Attr &parent);

  inline static std::optional<WebAssemblyExportNameAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return WebAssemblyExportNameAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<WebAssemblyExportNameAttr> from(const Reference &r) {
    return WebAssemblyExportNameAttr::from(r.as_attribute());
  }

  inline static std::optional<WebAssemblyExportNameAttr> from(const TokenContext &t) {
    return WebAssemblyExportNameAttr::from(t.as_attribute());
  }

  std::string_view export_name(void) const;
};

static_assert(sizeof(WebAssemblyExportNameAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
