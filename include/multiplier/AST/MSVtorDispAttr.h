// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"
#include "MSVtorDispMode.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class MSVtorDispAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MSVtorDispAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<MSVtorDispAttr> in(const Index &index);
  static gap::generator<MSVtorDispAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MSVtorDispAttr> by_id(const Index &, EntityId);
  static gap::generator<MSVtorDispAttr> in(const Fragment &frag);
  static gap::generator<MSVtorDispAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MS_VTOR_DISP;
  }

  static std::optional<MSVtorDispAttr> from_base(const Attr &parent);
  inline static std::optional<MSVtorDispAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<MSVtorDispAttr> from(const std::optional<Attr> &parent);
  static std::optional<MSVtorDispAttr> from(const Reference &r);
  static std::optional<MSVtorDispAttr> from(const VariantEntity &e);
  static std::optional<MSVtorDispAttr> from(const TokenContext &t);

  MSVtorDispMode vtor_disp_mode(void) const;
};

static_assert(sizeof(MSVtorDispAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
