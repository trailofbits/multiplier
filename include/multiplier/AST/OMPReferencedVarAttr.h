// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Attr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class Expr;
class OMPReferencedVarAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPReferencedVarAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<OMPReferencedVarAttr> in(const Index &index);
  static gap::generator<OMPReferencedVarAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPReferencedVarAttr> by_id(const Index &, EntityId);
  static gap::generator<OMPReferencedVarAttr> in(const Fragment &frag);
  static gap::generator<OMPReferencedVarAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OMP_REFERENCED_VAR;
  }

  static std::optional<OMPReferencedVarAttr> from_base(const Attr &parent);
  inline static std::optional<OMPReferencedVarAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<OMPReferencedVarAttr> from(const std::optional<Attr> &parent);
  static std::optional<OMPReferencedVarAttr> from(const Reference &r);
  static std::optional<OMPReferencedVarAttr> from(const VariantEntity &e);
  static std::optional<OMPReferencedVarAttr> from(const TokenContext &t);

  Expr reference(void) const;
};

static_assert(sizeof(OMPReferencedVarAttr) == sizeof(Attr));

#endif
} // namespace mx
