// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Attr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class Expr;
class OMPReferencedVarAttr;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPReferencedVarAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<OMPReferencedVarAttr> in(const Fragment &frag);
  static gap::generator<OMPReferencedVarAttr> in(const File &file);
  static gap::generator<OMPReferencedVarAttr> in(const Index &index);
  static gap::generator<OMPReferencedVarAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPReferencedVarAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OMP_REFERENCED_VAR;
  }

  static std::optional<OMPReferencedVarAttr> from(const Attr &parent);

  inline static std::optional<OMPReferencedVarAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OMPReferencedVarAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPReferencedVarAttr> from(const Reference &r);
  static std::optional<OMPReferencedVarAttr> from(const TokenContext &t);

  Expr reference(void) const;
};

static_assert(sizeof(OMPReferencedVarAttr) == sizeof(Attr));

#endif
} // namespace mx
