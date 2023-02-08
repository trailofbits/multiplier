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
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Attr.h"
#include "AttrKind.h"

namespace mx {
class Attr;
class Expr;
class OMPReferencedVarAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPReferencedVarAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<OMPReferencedVarAttr> in(const Fragment &frag);
  static gap::generator<OMPReferencedVarAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OMP_REFERENCED_VAR;
  }

  static gap::generator<AttrKind> derived_kinds(void);
  inline static std::optional<OMPReferencedVarAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<OMPReferencedVarAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<OMPReferencedVarAttr> from(const Attr &parent);

  inline static std::optional<OMPReferencedVarAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OMPReferencedVarAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr reference(void) const;
};

static_assert(sizeof(OMPReferencedVarAttr) == sizeof(Attr));

#endif
} // namespace mx
