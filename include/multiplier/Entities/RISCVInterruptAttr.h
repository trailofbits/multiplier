// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"
#include "RISCVInterruptAttrInterruptType.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class RISCVInterruptAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class RISCVInterruptAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<RISCVInterruptAttr> in(const Index &index);
  static gap::generator<RISCVInterruptAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<RISCVInterruptAttr> by_id(const Index &, EntityId);
  static gap::generator<RISCVInterruptAttr> in(const Fragment &frag);
  static gap::generator<RISCVInterruptAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::RISCV_INTERRUPT;
  }

  static std::optional<RISCVInterruptAttr> from(const Attr &parent);

  inline static std::optional<RISCVInterruptAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return RISCVInterruptAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<RISCVInterruptAttr> from(const Reference &r);
  static std::optional<RISCVInterruptAttr> from(const TokenContext &t);

  RISCVInterruptAttrInterruptType interrupt(void) const;
};

static_assert(sizeof(RISCVInterruptAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
