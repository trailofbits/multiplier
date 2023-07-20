// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class CUDAHostAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CUDAHostAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CUDAHostAttr> in(const Index &index);
  static gap::generator<CUDAHostAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CUDAHostAttr> by_id(const Index &, EntityId);
  static gap::generator<CUDAHostAttr> in(const Fragment &frag);
  static gap::generator<CUDAHostAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CUDA_HOST;
  }

  static std::optional<CUDAHostAttr> from(const Attr &parent);

  inline static std::optional<CUDAHostAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CUDAHostAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CUDAHostAttr> from(const Reference &r);
  static std::optional<CUDAHostAttr> from(const TokenContext &t);

};

static_assert(sizeof(CUDAHostAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
