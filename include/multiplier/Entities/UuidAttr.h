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
class MSGuidDecl;
class Token;
class UuidAttr;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UuidAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<UuidAttr> in(const Fragment &frag);
  static gap::generator<UuidAttr> in(const File &file);
  static gap::generator<UuidAttr> in(const Index &index);
  static gap::generator<UuidAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UuidAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::UUID;
  }

  static std::optional<UuidAttr> from(const Attr &parent);

  inline static std::optional<UuidAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return UuidAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UuidAttr> from(const Reference &r);
  static std::optional<UuidAttr> from(const TokenContext &t);

  std::string_view guid(void) const;
  MSGuidDecl guid_declaration(void) const;
};

static_assert(sizeof(UuidAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
