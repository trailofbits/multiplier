// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableParamAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class InheritableParamAttr;
class ReleaseHandleAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ReleaseHandleAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ReleaseHandleAttr> in(const Fragment &frag);
  static gap::generator<ReleaseHandleAttr> in(const File &file);
  static gap::generator<ReleaseHandleAttr> in(const Index &index);
  static gap::generator<ReleaseHandleAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ReleaseHandleAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::RELEASE_HANDLE;
  }

  static std::optional<ReleaseHandleAttr> from(const Attr &parent);

  inline static std::optional<ReleaseHandleAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ReleaseHandleAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ReleaseHandleAttr> from(const Reference &r);
  static std::optional<ReleaseHandleAttr> from(const TokenContext &t);

  std::string_view handle_type(void) const;
};

static_assert(sizeof(ReleaseHandleAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
