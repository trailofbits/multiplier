// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"
#include "PcsAttrPCSType.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class PcsAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class PcsAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<PcsAttr> in(const Index &index);
  static gap::generator<PcsAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PcsAttr> by_id(const Index &, EntityId);
  static gap::generator<PcsAttr> in(const Fragment &frag);
  static gap::generator<PcsAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PCS;
  }

  static std::optional<PcsAttr> from(const Attr &parent);

  inline static std::optional<PcsAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return PcsAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<PcsAttr> from(const Reference &r);
  static std::optional<PcsAttr> from(const TokenContext &t);

  PcsAttrPCSType pcs(void) const;
};

static_assert(sizeof(PcsAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
