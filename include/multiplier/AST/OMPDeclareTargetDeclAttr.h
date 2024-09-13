// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/AST/OMPDeclareTargetDeclAttrDevTypeTy.h>
#include <multiplier/AST/OMPDeclareTargetDeclAttrMapTypeTy.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class Expr;
class File;
class InheritableAttr;
class OMPDeclareTargetDeclAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPDeclareTargetDeclAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<OMPDeclareTargetDeclAttr> in(const Index &index);
  static gap::generator<OMPDeclareTargetDeclAttr> in(const Fragment &frag);
  static gap::generator<OMPDeclareTargetDeclAttr> in(const File &file);
  static gap::generator<OMPDeclareTargetDeclAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OMP_DECLARE_TARGET_DECL;
  }

  static std::optional<OMPDeclareTargetDeclAttr> by_id(const Index &, EntityId);

  static std::optional<OMPDeclareTargetDeclAttr> from_base(const Attr &parent);
  inline static std::optional<OMPDeclareTargetDeclAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<OMPDeclareTargetDeclAttr> from(const std::optional<Attr> &parent);
  static std::optional<OMPDeclareTargetDeclAttr> from(const Reference &r);
  static std::optional<OMPDeclareTargetDeclAttr> from(const VariantEntity &e);
  static std::optional<OMPDeclareTargetDeclAttr> from(const TokenContext &t);

  OMPDeclareTargetDeclAttrDevTypeTy dev_type(void) const;
  bool indirect(void) const;
  Expr indirect_expression(void) const;
  uint32_t level(void) const;
  OMPDeclareTargetDeclAttrMapTypeTy map_type(void) const;
};

static_assert(sizeof(OMPDeclareTargetDeclAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
