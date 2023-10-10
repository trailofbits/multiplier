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
class AvailabilityAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AvailabilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AvailabilityAttr> in(const Index &index);
  static gap::generator<AvailabilityAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AvailabilityAttr> by_id(const Index &, EntityId);
  static gap::generator<AvailabilityAttr> in(const Fragment &frag);
  static gap::generator<AvailabilityAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::AVAILABILITY;
  }

  static std::optional<AvailabilityAttr> from(const Attr &parent);

  inline static std::optional<AvailabilityAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AvailabilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AvailabilityAttr> from(const Reference &r);
  static std::optional<AvailabilityAttr> from(const TokenContext &t);

  std::string_view message(void) const;
  std::string_view replacement(void) const;
  bool strict(void) const;
  bool unavailable(void) const;
};

static_assert(sizeof(AvailabilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
