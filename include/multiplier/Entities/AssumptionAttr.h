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
class AssumptionAttr;
class Attr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AssumptionAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AssumptionAttr> in(const Index &index);
  static gap::generator<AssumptionAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AssumptionAttr> by_id(const Index &, EntityId);
  static gap::generator<AssumptionAttr> in(const Fragment &frag);
  static gap::generator<AssumptionAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ASSUMPTION;
  }

  static std::optional<AssumptionAttr> from(const Attr &parent);

  inline static std::optional<AssumptionAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AssumptionAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AssumptionAttr> from(const Reference &r);
  static std::optional<AssumptionAttr> from(const TokenContext &t);

  std::string_view assumption(void) const;
};

static_assert(sizeof(AssumptionAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
