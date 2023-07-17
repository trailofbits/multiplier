// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"
#include "ReturnTypestateAttrConsumedState.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class ReturnTypestateAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ReturnTypestateAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ReturnTypestateAttr> in(const Fragment &frag);
  static gap::generator<ReturnTypestateAttr> in(const File &file);
  static gap::generator<ReturnTypestateAttr> in(const Index &index);
  static gap::generator<ReturnTypestateAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ReturnTypestateAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::RETURN_TYPESTATE;
  }

  static std::optional<ReturnTypestateAttr> from(const Attr &parent);

  inline static std::optional<ReturnTypestateAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ReturnTypestateAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ReturnTypestateAttr> from(const Reference &r);
  static std::optional<ReturnTypestateAttr> from(const TokenContext &t);

  ReturnTypestateAttrConsumedState state(void) const;
};

static_assert(sizeof(ReturnTypestateAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
