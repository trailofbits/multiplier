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
class CallbackAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CallbackAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CallbackAttr> in(const Index &index);
  static gap::generator<CallbackAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CallbackAttr> by_id(const Index &, EntityId);
  static gap::generator<CallbackAttr> in(const Fragment &frag);
  static gap::generator<CallbackAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CALLBACK;
  }

  static std::optional<CallbackAttr> from_base(const Attr &parent);
  inline static std::optional<CallbackAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<CallbackAttr> from(const std::optional<Attr> &parent);
  static std::optional<CallbackAttr> from(const Reference &r);
  static std::optional<CallbackAttr> from(const VariantEntity &e);
  static std::optional<CallbackAttr> from(const TokenContext &t);

};

static_assert(sizeof(CallbackAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
