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
class AlignValueAttr;
class Attr;
class Expr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AlignValueAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<AlignValueAttr> in(const Fragment &frag);
  static gap::generator<AlignValueAttr> in(const File &file);
  static gap::generator<AlignValueAttr> in(const Index &index);
  static gap::generator<AlignValueAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AlignValueAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ALIGN_VALUE;
  }

  static std::optional<AlignValueAttr> from(const Attr &parent);

  inline static std::optional<AlignValueAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AlignValueAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AlignValueAttr> from(const Reference &r);
  static std::optional<AlignValueAttr> from(const TokenContext &t);

  Expr alignment(void) const;
};

static_assert(sizeof(AlignValueAttr) == sizeof(Attr));

#endif
} // namespace mx
