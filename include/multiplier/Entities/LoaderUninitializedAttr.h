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
class LoaderUninitializedAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class LoaderUninitializedAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<LoaderUninitializedAttr> in(const Fragment &frag);
  static gap::generator<LoaderUninitializedAttr> in(const File &file);
  static gap::generator<LoaderUninitializedAttr> in(const Index &index);
  static gap::generator<LoaderUninitializedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<LoaderUninitializedAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::LOADER_UNINITIALIZED;
  }

  static std::optional<LoaderUninitializedAttr> from(const Attr &parent);

  inline static std::optional<LoaderUninitializedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return LoaderUninitializedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<LoaderUninitializedAttr> from(const Reference &r) {
    return LoaderUninitializedAttr::from(r.as_attribute());
  }

  inline static std::optional<LoaderUninitializedAttr> from(const TokenContext &t) {
    return LoaderUninitializedAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(LoaderUninitializedAttr) == sizeof(Attr));

#endif
} // namespace mx
