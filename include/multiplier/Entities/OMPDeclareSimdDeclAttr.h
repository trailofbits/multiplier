// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Attr.h"
#include "OMPDeclareSimdDeclAttrBranchStateTy.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class Expr;
class OMPDeclareSimdDeclAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPDeclareSimdDeclAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<OMPDeclareSimdDeclAttr> in(const Fragment &frag);
  static gap::generator<OMPDeclareSimdDeclAttr> in(const File &file);
  static gap::generator<OMPDeclareSimdDeclAttr> in(const Index &index);
  static gap::generator<OMPDeclareSimdDeclAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPDeclareSimdDeclAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OMP_DECLARE_SIMD_DECL;
  }

  static std::optional<OMPDeclareSimdDeclAttr> from(const Attr &parent);

  inline static std::optional<OMPDeclareSimdDeclAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OMPDeclareSimdDeclAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPDeclareSimdDeclAttr> from(const Reference &r);
  static std::optional<OMPDeclareSimdDeclAttr> from(const TokenContext &t);

  OMPDeclareSimdDeclAttrBranchStateTy branch_state(void) const;
  Expr simdlen(void) const;
};

static_assert(sizeof(OMPDeclareSimdDeclAttr) == sizeof(Attr));

#endif
} // namespace mx
