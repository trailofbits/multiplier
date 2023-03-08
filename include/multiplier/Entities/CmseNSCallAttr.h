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

#include "TypeAttr.h"

namespace mx {
class Attr;
class CmseNSCallAttr;
class Token;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CmseNSCallAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<CmseNSCallAttr> in(const Fragment &frag);
  static gap::generator<CmseNSCallAttr> in(const File &file);
  static gap::generator<CmseNSCallAttr> in(const Index &index);
  static gap::generator<CmseNSCallAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CmseNSCallAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CMSE_NS_CALL;
  }

  static std::optional<CmseNSCallAttr> from(const Attr &parent);

  inline static std::optional<CmseNSCallAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CmseNSCallAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<CmseNSCallAttr> from(const Reference &r) {
    return CmseNSCallAttr::from(r.as_attribute());
  }

  inline static std::optional<CmseNSCallAttr> from(const TokenContext &t) {
    return CmseNSCallAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(CmseNSCallAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
