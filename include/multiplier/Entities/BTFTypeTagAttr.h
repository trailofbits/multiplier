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
#include "TypeAttr.h"

namespace mx {
class Attr;
class BTFTypeTagAttr;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class BTFTypeTagAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<BTFTypeTagAttr> in(const Fragment &frag);
  static gap::generator<BTFTypeTagAttr> in(const File &file);
  static gap::generator<BTFTypeTagAttr> in(const Index &index);
  static gap::generator<BTFTypeTagAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<BTFTypeTagAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::BTF_TYPE_TAG;
  }

  static std::optional<BTFTypeTagAttr> from(const Attr &parent);

  inline static std::optional<BTFTypeTagAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return BTFTypeTagAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<BTFTypeTagAttr> from(const Reference &r) {
    return BTFTypeTagAttr::from(r.as_attribute());
  }

  inline static std::optional<BTFTypeTagAttr> from(const TokenContext &t) {
    return BTFTypeTagAttr::from(t.as_attribute());
  }

  std::string_view btf_type_tag(void) const;
};

static_assert(sizeof(BTFTypeTagAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
