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
#include "InheritableAttr.h"

namespace mx {
class Attr;
class ExternalSourceSymbolAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ExternalSourceSymbolAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ExternalSourceSymbolAttr> in(const Fragment &frag);
  static gap::generator<ExternalSourceSymbolAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::EXTERNAL_SOURCE_SYMBOL;
  }

  static gap::generator<AttrKind> derived_kinds(void);
  inline static std::optional<ExternalSourceSymbolAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<ExternalSourceSymbolAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<ExternalSourceSymbolAttr> from(const InheritableAttr &parent);

  inline static std::optional<ExternalSourceSymbolAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return ExternalSourceSymbolAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ExternalSourceSymbolAttr> from(const Attr &parent);

  inline static std::optional<ExternalSourceSymbolAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ExternalSourceSymbolAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view defined_in(void) const;
  bool generated_declaration(void) const;
  std::string_view language(void) const;
};

static_assert(sizeof(ExternalSourceSymbolAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
