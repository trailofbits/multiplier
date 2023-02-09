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
#include "AttrKind.h"
#include "OMPDeclareSimdDeclAttrBranchStateTy.h"

namespace mx {
class Attr;
class Expr;
class OMPDeclareSimdDeclAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPDeclareSimdDeclAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<OMPDeclareSimdDeclAttr> in(const Fragment &frag);
  static gap::generator<OMPDeclareSimdDeclAttr> in(const Index &index);
  static gap::generator<OMPDeclareSimdDeclAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPDeclareSimdDeclAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OMP_DECLARE_SIMD_DECL;
  }

  inline static std::optional<OMPDeclareSimdDeclAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<OMPDeclareSimdDeclAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<OMPDeclareSimdDeclAttr> from(const Attr &parent);

  inline static std::optional<OMPDeclareSimdDeclAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OMPDeclareSimdDeclAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  OMPDeclareSimdDeclAttrBranchStateTy branch_state(void) const;
  Expr simdlen(void) const;
};

static_assert(sizeof(OMPDeclareSimdDeclAttr) == sizeof(Attr));

#endif
} // namespace mx
