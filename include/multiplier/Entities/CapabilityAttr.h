// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "CapabilityAttrSpelling.h"
#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class CapabilityAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CapabilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CapabilityAttr> in(const Index &index);
  static gap::generator<CapabilityAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CapabilityAttr> by_id(const Index &, EntityId);
  static gap::generator<CapabilityAttr> in(const Fragment &frag);
  static gap::generator<CapabilityAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CAPABILITY;
  }

  static std::optional<CapabilityAttr> from(const Attr &parent);

  inline static std::optional<CapabilityAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CapabilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CapabilityAttr> from(const Reference &r);
  static std::optional<CapabilityAttr> from(const TokenContext &t);

  std::string_view name(void) const;
  CapabilityAttrSpelling semantic_spelling(void) const;
  bool is_shared(void) const;
};

static_assert(sizeof(CapabilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
