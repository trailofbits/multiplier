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
class TLSModelAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TLSModelAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<TLSModelAttr> in(const Fragment &frag);
  static gap::generator<TLSModelAttr> in(const File &file);
  static gap::generator<TLSModelAttr> in(const Index &index);
  static gap::generator<TLSModelAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TLSModelAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::TLS_MODEL;
  }

  static std::optional<TLSModelAttr> from(const Attr &parent);

  inline static std::optional<TLSModelAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return TLSModelAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<TLSModelAttr> from(const Reference &r) {
    return TLSModelAttr::from(r.as_attribute());
  }

  inline static std::optional<TLSModelAttr> from(const TokenContext &t) {
    return TLSModelAttr::from(t.as_attribute());
  }

  std::string_view model(void) const;
};

static_assert(sizeof(TLSModelAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
