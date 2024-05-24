// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
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
class File;
class InheritableAttr;
class MSP430InterruptAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT MSP430InterruptAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<MSP430InterruptAttr> in(const Index &index);
  static gap::generator<MSP430InterruptAttr> in(const Fragment &frag);
  static gap::generator<MSP430InterruptAttr> in(const File &file);
  static gap::generator<MSP430InterruptAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MSP430_INTERRUPT;
  }

  static std::optional<MSP430InterruptAttr> by_id(const Index &, EntityId);

  static std::optional<MSP430InterruptAttr> from_base(const Attr &parent);
  inline static std::optional<MSP430InterruptAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<MSP430InterruptAttr> from(const std::optional<Attr> &parent);
  static std::optional<MSP430InterruptAttr> from(const Reference &r);
  static std::optional<MSP430InterruptAttr> from(const VariantEntity &e);
  static std::optional<MSP430InterruptAttr> from(const TokenContext &t);

};

static_assert(sizeof(MSP430InterruptAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
