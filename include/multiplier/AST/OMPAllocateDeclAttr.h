// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/AST/OMPAllocateDeclAttrAllocatorTypeTy.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class Expr;
class File;
class InheritableAttr;
class OMPAllocateDeclAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPAllocateDeclAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<OMPAllocateDeclAttr> in(const Index &index);
  static gap::generator<OMPAllocateDeclAttr> in(const Fragment &frag);
  static gap::generator<OMPAllocateDeclAttr> in(const File &file);
  static gap::generator<OMPAllocateDeclAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OMP_ALLOCATE_DECL;
  }

  static std::optional<OMPAllocateDeclAttr> by_id(const Index &, EntityId);

  static std::optional<OMPAllocateDeclAttr> from_base(const Attr &parent);
  inline static std::optional<OMPAllocateDeclAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<OMPAllocateDeclAttr> from(const std::optional<Attr> &parent);
  static std::optional<OMPAllocateDeclAttr> from(const Reference &r);
  static std::optional<OMPAllocateDeclAttr> from(const VariantEntity &e);
  static std::optional<OMPAllocateDeclAttr> from(const TokenContext &t);

  Expr alignment(void) const;
  Expr allocator(void) const;
  OMPAllocateDeclAttrAllocatorTypeTy allocator_type(void) const;
};

static_assert(sizeof(OMPAllocateDeclAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
