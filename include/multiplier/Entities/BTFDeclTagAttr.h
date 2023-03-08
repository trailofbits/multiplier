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
class BTFDeclTagAttr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class BTFDeclTagAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<BTFDeclTagAttr> in(const Fragment &frag);
  static gap::generator<BTFDeclTagAttr> in(const File &file);
  static gap::generator<BTFDeclTagAttr> in(const Index &index);
  static gap::generator<BTFDeclTagAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<BTFDeclTagAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::BTF_DECL_TAG;
  }

  static std::optional<BTFDeclTagAttr> from(const Attr &parent);

  inline static std::optional<BTFDeclTagAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return BTFDeclTagAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<BTFDeclTagAttr> from(const Reference &r) {
    return BTFDeclTagAttr::from(r.as_attribute());
  }

  inline static std::optional<BTFDeclTagAttr> from(const TokenContext &t) {
    return BTFDeclTagAttr::from(t.as_attribute());
  }

  std::string_view btf_decl_tag(void) const;
};

static_assert(sizeof(BTFDeclTagAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
