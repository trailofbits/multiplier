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
class AnnotateTypeAttr;
class Attr;
class Token;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AnnotateTypeAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<AnnotateTypeAttr> in(const Fragment &frag);
  static gap::generator<AnnotateTypeAttr> in(const File &file);
  static gap::generator<AnnotateTypeAttr> in(const Index &index);
  static gap::generator<AnnotateTypeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AnnotateTypeAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ANNOTATE_TYPE;
  }

  static std::optional<AnnotateTypeAttr> from(const Attr &parent);

  inline static std::optional<AnnotateTypeAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AnnotateTypeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<AnnotateTypeAttr> from(const Reference &r) {
    return AnnotateTypeAttr::from(r.as_attribute());
  }

  inline static std::optional<AnnotateTypeAttr> from(const TokenContext &t) {
    return AnnotateTypeAttr::from(t.as_attribute());
  }

  std::string_view annotation(void) const;
};

static_assert(sizeof(AnnotateTypeAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
