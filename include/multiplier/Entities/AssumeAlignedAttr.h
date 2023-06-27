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
class AssumeAlignedAttr;
class Attr;
class Expr;
class InheritableAttr;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AssumeAlignedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AssumeAlignedAttr> in(const Fragment &frag);
  static gap::generator<AssumeAlignedAttr> in(const File &file);
  static gap::generator<AssumeAlignedAttr> in(const Index &index);
  static gap::generator<AssumeAlignedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AssumeAlignedAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ASSUME_ALIGNED;
  }

  static std::optional<AssumeAlignedAttr> from(const Attr &parent);

  inline static std::optional<AssumeAlignedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AssumeAlignedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AssumeAlignedAttr> from(const Reference &r);
  static std::optional<AssumeAlignedAttr> from(const TokenContext &t);

  Expr alignment(void) const;
  std::optional<Expr> offset(void) const;
};

static_assert(sizeof(AssumeAlignedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
