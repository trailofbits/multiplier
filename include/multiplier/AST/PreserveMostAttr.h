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
class InheritableAttr;
class PreserveMostAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class PreserveMostAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<PreserveMostAttr> in(const Index &index);
  static gap::generator<PreserveMostAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PreserveMostAttr> by_id(const Index &, EntityId);
  static gap::generator<PreserveMostAttr> in(const Fragment &frag);
  static gap::generator<PreserveMostAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PRESERVE_MOST;
  }

  static std::optional<PreserveMostAttr> from_base(const Attr &parent);
  inline static std::optional<PreserveMostAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<PreserveMostAttr> from(const std::optional<Attr> &parent);
  static std::optional<PreserveMostAttr> from(const Reference &r);
  static std::optional<PreserveMostAttr> from(const VariantEntity &e);
  static std::optional<PreserveMostAttr> from(const TokenContext &t);

};

static_assert(sizeof(PreserveMostAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
