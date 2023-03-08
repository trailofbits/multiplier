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

#include "FinalAttrSpelling.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class FinalAttr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class FinalAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<FinalAttr> in(const Fragment &frag);
  static gap::generator<FinalAttr> in(const File &file);
  static gap::generator<FinalAttr> in(const Index &index);
  static gap::generator<FinalAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<FinalAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::FINAL;
  }

  static std::optional<FinalAttr> from(const Attr &parent);

  inline static std::optional<FinalAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return FinalAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<FinalAttr> from(const Reference &r) {
    return FinalAttr::from(r.as_attribute());
  }

  inline static std::optional<FinalAttr> from(const TokenContext &t) {
    return FinalAttr::from(t.as_attribute());
  }

  FinalAttrSpelling semantic_spelling(void) const;
  bool is_spelled_as_sealed(void) const;
};

static_assert(sizeof(FinalAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
