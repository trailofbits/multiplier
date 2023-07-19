// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableParamAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class CFConsumedAttr;
class InheritableAttr;
class InheritableParamAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CFConsumedAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CFConsumedAttr> in(const Index &index);
  static gap::generator<CFConsumedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CFConsumedAttr> by_id(const Index &, EntityId);
  static gap::generator<CFConsumedAttr> in(const Fragment &frag);
  static gap::generator<CFConsumedAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CF_CONSUMED;
  }

  static std::optional<CFConsumedAttr> from(const Attr &parent);

  inline static std::optional<CFConsumedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CFConsumedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CFConsumedAttr> from(const Reference &r);
  static std::optional<CFConsumedAttr> from(const TokenContext &t);

};

static_assert(sizeof(CFConsumedAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
