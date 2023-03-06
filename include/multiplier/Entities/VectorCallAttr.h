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
class VectorCallAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class VectorCallAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<VectorCallAttr> in(const Fragment &frag);
  static gap::generator<VectorCallAttr> in(const File &file);
  static gap::generator<VectorCallAttr> in(const Index &index);
  static gap::generator<VectorCallAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<VectorCallAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::VECTOR_CALL;
  }

  static std::optional<VectorCallAttr> from(const Attr &parent);

  inline static std::optional<VectorCallAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return VectorCallAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<VectorCallAttr> from(const Reference &r) {
    return VectorCallAttr::from(r.as_attribute());
  }

  inline static std::optional<VectorCallAttr> from(const TokenContext &t) {
    return VectorCallAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(VectorCallAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
