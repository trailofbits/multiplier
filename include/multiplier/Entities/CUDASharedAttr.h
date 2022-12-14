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
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class CUDASharedAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CUDASharedAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, CUDASharedAttr>;
class CUDASharedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static gap::generator<CUDASharedAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static CUDASharedAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CUDASharedAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CUDA_SHARED;
  }

  static std::optional<CUDASharedAttr> from(const TokenContext &c);
  static std::optional<CUDASharedAttr> from(const InheritableAttr &parent);

  inline static std::optional<CUDASharedAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return CUDASharedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CUDASharedAttr> from(const Attr &parent);

  inline static std::optional<CUDASharedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CUDASharedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(CUDASharedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
