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
class AcquireHandleAttr;
class Attr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AcquireHandleAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AcquireHandleAttr> in(const Index &index);
  static gap::generator<AcquireHandleAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AcquireHandleAttr> by_id(const Index &, EntityId);
  static gap::generator<AcquireHandleAttr> in(const Fragment &frag);
  static gap::generator<AcquireHandleAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ACQUIRE_HANDLE;
  }

  static std::optional<AcquireHandleAttr> from(const Attr &parent);

  inline static std::optional<AcquireHandleAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AcquireHandleAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AcquireHandleAttr> from(const Reference &r);
  static std::optional<AcquireHandleAttr> from(const TokenContext &t);

  std::string_view handle_type(void) const;
};

static_assert(sizeof(AcquireHandleAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
