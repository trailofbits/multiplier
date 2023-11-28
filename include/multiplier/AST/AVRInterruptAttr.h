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
class AVRInterruptAttr;
class Attr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AVRInterruptAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AVRInterruptAttr> in(const Index &index);
  static gap::generator<AVRInterruptAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AVRInterruptAttr> by_id(const Index &, EntityId);
  static gap::generator<AVRInterruptAttr> in(const Fragment &frag);
  static gap::generator<AVRInterruptAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::AVR_INTERRUPT;
  }

  static std::optional<AVRInterruptAttr> from_base(const Attr &parent);
  inline static std::optional<AVRInterruptAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<AVRInterruptAttr> from(const std::optional<Attr> &parent);
  static std::optional<AVRInterruptAttr> from(const Reference &r);
  static std::optional<AVRInterruptAttr> from(const VariantEntity &e);
  static std::optional<AVRInterruptAttr> from(const TokenContext &t);

};

static_assert(sizeof(AVRInterruptAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
