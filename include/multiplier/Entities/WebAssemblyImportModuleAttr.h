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

#include "InheritableAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class Token;
class WebAssemblyImportModuleAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class WebAssemblyImportModuleAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<WebAssemblyImportModuleAttr> in(const Fragment &frag);
  static gap::generator<WebAssemblyImportModuleAttr> in(const File &file);
  static gap::generator<WebAssemblyImportModuleAttr> in(const Index &index);
  static gap::generator<WebAssemblyImportModuleAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<WebAssemblyImportModuleAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::WEB_ASSEMBLY_IMPORT_MODULE;
  }

  static std::optional<WebAssemblyImportModuleAttr> from(const Attr &parent);

  inline static std::optional<WebAssemblyImportModuleAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return WebAssemblyImportModuleAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<WebAssemblyImportModuleAttr> from(const Reference &r) {
    return WebAssemblyImportModuleAttr::from(r.as_attribute());
  }

  inline static std::optional<WebAssemblyImportModuleAttr> from(const TokenContext &t) {
    return WebAssemblyImportModuleAttr::from(t.as_attribute());
  }

  std::string_view import_module(void) const;
};

static_assert(sizeof(WebAssemblyImportModuleAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
