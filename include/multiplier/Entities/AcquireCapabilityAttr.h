// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "AcquireCapabilityAttrSpelling.h"
#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class AcquireCapabilityAttr;
class Attr;
class InheritableAttr;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AcquireCapabilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AcquireCapabilityAttr> in(const Fragment &frag);
  static gap::generator<AcquireCapabilityAttr> in(const File &file);
  static gap::generator<AcquireCapabilityAttr> in(const Index &index);
  static gap::generator<AcquireCapabilityAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AcquireCapabilityAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ACQUIRE_CAPABILITY;
  }

  static std::optional<AcquireCapabilityAttr> from(const Attr &parent);

  inline static std::optional<AcquireCapabilityAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AcquireCapabilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AcquireCapabilityAttr> from(const Reference &r);
  static std::optional<AcquireCapabilityAttr> from(const TokenContext &t);

  AcquireCapabilityAttrSpelling semantic_spelling(void) const;
  bool is_shared(void) const;
};

static_assert(sizeof(AcquireCapabilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
