// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class CUDALaunchBoundsAttr;
class Expr;
class File;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CUDALaunchBoundsAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CUDALaunchBoundsAttr> in(const Index &index);
  static gap::generator<CUDALaunchBoundsAttr> in(const Fragment &frag);
  static gap::generator<CUDALaunchBoundsAttr> in(const File &file);
  static gap::generator<CUDALaunchBoundsAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CUDA_LAUNCH_BOUNDS;
  }

  static std::optional<CUDALaunchBoundsAttr> by_id(const Index &, EntityId);

  static std::optional<CUDALaunchBoundsAttr> from_base(const Attr &parent);
  inline static std::optional<CUDALaunchBoundsAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<CUDALaunchBoundsAttr> from(const std::optional<Attr> &parent);
  static std::optional<CUDALaunchBoundsAttr> from(const Reference &r);
  static std::optional<CUDALaunchBoundsAttr> from(const VariantEntity &e);
  static std::optional<CUDALaunchBoundsAttr> from(const TokenContext &t);

  Expr max_blocks(void) const;
  Expr max_threads(void) const;
  Expr min_blocks(void) const;
};

static_assert(sizeof(CUDALaunchBoundsAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
