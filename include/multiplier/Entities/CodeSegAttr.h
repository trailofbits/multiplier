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
class CodeSegAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CodeSegAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CodeSegAttr> in(const Fragment &frag);
  static gap::generator<CodeSegAttr> in(const Index &index);
  static gap::generator<CodeSegAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<CodeSegAttr> by(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CODE_SEG;
  }

  inline static std::optional<CodeSegAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<CodeSegAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<CodeSegAttr> from(const InheritableAttr &parent);

  inline static std::optional<CodeSegAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return CodeSegAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CodeSegAttr> from(const Attr &parent);

  inline static std::optional<CodeSegAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CodeSegAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view name(void) const;
};

static_assert(sizeof(CodeSegAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
