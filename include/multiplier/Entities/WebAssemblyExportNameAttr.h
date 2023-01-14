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
#include "InheritableAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class WebAssemblyExportNameAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using WebAssemblyExportNameAttrRange = DerivedEntityRange<AttrIterator, WebAssemblyExportNameAttr>;
using WebAssemblyExportNameAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, WebAssemblyExportNameAttr>;
class WebAssemblyExportNameAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static WebAssemblyExportNameAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static WebAssemblyExportNameAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : WebAssemblyExportNameAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::WEB_ASSEMBLY_EXPORT_NAME;
  }

  static std::optional<WebAssemblyExportNameAttr> from(const TokenContext &c);
  static std::optional<WebAssemblyExportNameAttr> from(const InheritableAttr &parent);

  inline static std::optional<WebAssemblyExportNameAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return WebAssemblyExportNameAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<WebAssemblyExportNameAttr> from(const Attr &parent);

  inline static std::optional<WebAssemblyExportNameAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return WebAssemblyExportNameAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view export_name(void) const;
};

static_assert(sizeof(WebAssemblyExportNameAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
